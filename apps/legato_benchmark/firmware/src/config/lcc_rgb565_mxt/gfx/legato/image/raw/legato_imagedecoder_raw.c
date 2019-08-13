#include "gfx/legato/image/raw/legato_imagedecoder_raw.h"

#include "gfx/legato/core/legato_state.h"
#include "gfx/legato/image/legato_palette.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/renderer/legato_renderer.h"

#if LE_STREAMING_ENABLED == 1

#if LE_ASSET_DECODER_USE_PIXEL_CACHE == 1
uint8_t leRawImageDecoderScratchBuffer[LE_ASSET_DECODER_CACHE_SIZE];
#endif

#if LE_ASSET_DECODER_USE_MASK_CACHE == 1
uint8_t leRawImageDecoderPaletteScratchBuffer[LE_ASSET_DECODER_CACHE_SIZE];
#endif

#if LE_ASSET_DECODER_USE_PALETTE_CACHE == 1
uint8_t leRawImageDecoderPaletteScratchBuffer[LE_ASSET_DECODER_CACHE_SIZE];
#endif

#if LE_ASSET_DECODER_USE_BLEND_CACHE == 1
uint8_t leRawImageDecoderBlendBuffer[LE_ASSET_DECODER_CACHE_SIZE];
#endif

#endif

static leImageDecoder decoder;
static leRawDecodeState state;

leResult _leRawImageDecoder_ReadInternalInit(leRawDecodeState* state);
leResult _leRawImageDecoder_MaskInternalInit(leRawDecodeState* state);
leResult _leRawImageDecoder_PaletteInternalInit(leRawDecodeState* state);
leResult _leRawImageDecoder_ConvertInit(leRawDecodeState* state);
leResult _leRawImageDecoder_BlendInternalInit(leRawDecodeState* state);
leResult _leRawImageDecoder_WriteInit(leRawDecodeState* state, leBool ignoreAlpha);

static leBool _supportsImage(const leImage* img)
{
    return img->format == LE_IMAGE_FORMAT_RAW ||
           img->format == LE_IMAGE_FORMAT_RLE;
}

static leResult _draw(const leImage* img,
                      const leRect* srcRect,
                      int32_t x,
                      int32_t y,
                      uint32_t a)
{
    lePixelBuffer paletteBuffer;

#if LE_STREAMING_ENABLED == 1
    if(state.mode != LE_RAW_MODE_NONE)
        return LE_FAILURE;
#endif

    memset(&state, 0, sizeof(leRawDecodeState));

    state.mode = LE_RAW_MODE_DRAW;

    state.source = img;
    state.sourceRect = *srcRect;
    state.renderX = x;
    state.renderY = y;
    state.globalAlpha = a;

    // init the palette buffer
    if(LE_COLOR_MODE_IS_INDEX(state.source->buffer.mode) == LE_TRUE &&
       state.source->palette != NULL &&
       state.source->palette->header.address != NULL)
    {
        lePixelBufferCreate(state.source->palette->colorCount,
                            1,
                            state.source->palette->colorMode,
                            state.source->palette->header.address,
                            &paletteBuffer);
    }

    if(_leRawImageDecoder_ReadInternalInit(&state) == LE_FAILURE ||
       _leRawImageDecoder_MaskInternalInit(&state) == LE_FAILURE ||
       _leRawImageDecoder_PaletteInternalInit(&state) == LE_FAILURE ||
       _leRawImageDecoder_BlendInternalInit(&state) == LE_FAILURE ||
       _leRawImageDecoder_ConvertInit(&state) == LE_FAILURE ||
       _leRawImageDecoder_WriteInit(&state, LE_FALSE) == LE_FAILURE)
    {
        return LE_FAILURE;
    }

    state.currentStage = state.readStage;

    return LE_SUCCESS;
}

#if 0
static void stage_copy(uint32_t stage)
{
    // copy old buffer attributes
    state.newImg->buffer.pixels = state.tempBuffer;

    // copy old data to new address
    memcpy(state.newImg->buffer.pixels,
           ((leImage*)state.reader.asset)->buffer.pixels,
           ((leImage*)state.reader.asset)->buffer.buffer_length);
}

static leResult _copy(const leImage* src,
                      leImage* dst,
                      const leRect* sourceRect)
{
#if 0
    uint32_t idx = 0;

    if(state.mode != MODE_NONE)
        return LE_FAILURE;

    // allocate a new buffer
    state.tempBuffer = LE_MALLOC(src->buffer.buffer_length);

    if(state.tempBuffer == NULL)
        return LE_FAILURE;

    state.newImg = newImg;
    state.mode = MODE_COPY;

    decodePipeline[idx++] = copyStage;
#endif

    return LE_SUCCESS;
}

static leResult _render(const leImage* img,
                        leImage* dst,
                        const leRect* sourceRect,
                        leBool applyAlpha)
{
    return LE_SUCCESS;
}

static leResult _resize(const leImage* src,
                        leImage* dst,
                        const leRect* sourceRect,
                        uint32_t width,
                        uint32_t height,
                        leImageFilterMode mode)
{
    return LE_SUCCESS;
}
#endif

static void _free(void)
{
    if(state.mode != LE_RAW_MODE_NONE)
    {
        state.mode = LE_RAW_MODE_NONE;

        if(state.readStage->cleanup != NULL)
        {
            state.readStage->cleanup(state.readStage);
        }

        if(state.maskStage->cleanup != NULL)
        {
            state.readStage->cleanup(state.maskStage);
        }

        if(state.paletteStage->cleanup != NULL)
        {
            state.readStage->cleanup(state.paletteStage);
        }

        if(state.blendStage->cleanup != NULL)
        {
            state.readStage->cleanup(state.blendStage);
        }

        if(state.convertStage->cleanup != NULL)
        {
            state.readStage->cleanup(state.convertStage);
        }

        if(state.writeStage->cleanup != NULL)
        {
            state.readStage->cleanup(state.writeStage);
        }

#if LE_STREAMING_ENABLED == 1
        if(leGetState()->activeStream == (leStreamManager*)&state)
        {
            leGetState()->activeStream = NULL;
        }
#endif
    }
}

static void _exec(void)
{
    if(state.mode == LE_RAW_MODE_NONE)
        return;

#if LE_STREAMING_ENABLED == 1
    if(leGetActiveStream() != NULL)
        return;

    leGetState()->activeStream = (leStreamManager*)&state;
#endif

    while(state.currentStage != NULL)
    {
        if(state.currentStage->exec(state.currentStage) == LE_FAILURE)
        {
            return;
        }
    }

    _free();
}

static leBool _isDone(void)
{
    return state.currentStage == NULL;
}

leImageDecoder* _leRawImageDecoder_Init(void)
{
    memset(&state, 0, sizeof(leImageDecoder));

    decoder.supportsImage = _supportsImage;
    decoder.draw = _draw;
    //rawImgDecoder.copy = _copy;
    //rawImgDecoder.render = _render;
    decoder.exec = _exec;
    decoder.isDone = _isDone;
    decoder.free = _free;

    return &decoder;
}

