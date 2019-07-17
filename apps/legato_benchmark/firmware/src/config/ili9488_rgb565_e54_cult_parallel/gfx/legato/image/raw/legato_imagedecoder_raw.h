#ifndef LE_IMAGEDECODER_RAW_H
#define LE_IMAGEDECODER_RAW_H

#include "gfx/legato/image/legato_image.h"
#include "gfx/legato/common/legato_pixelbuffer.h"



#if LE_STREAMING_ENABLED == 1
#ifndef LE_ASSET_DECODER_CACHE_SIZE
#define LE_ASSET_DECODER_CACHE_SIZE 128
#endif

#if LE_ASSET_DECODER_USE_PIXEL_CACHE == 1
extern uint8_t leRawImageDecoderScratchBuffer[LE_ASSET_DECODER_CACHE_SIZE];
#endif

#if LE_ASSET_DECODER_USE_MASK_CACHE == 1
extern uint8_t leRawImageDecoderPaletteScratchBuffer[LE_ASSET_DECODER_CACHE_SIZE];
#endif

#if LE_ASSET_DECODER_USE_PALETTE_CACHE == 1
extern uint8_t leRawImageDecoderPaletteScratchBuffer[LE_ASSET_DECODER_CACHE_SIZE];
#endif

#if LE_ASSET_DECODER_USE_BLEND_CACHE == 1
extern uint8_t leRawImageDecoderBlendBuffer[LE_ASSET_DECODER_CACHE_SIZE];
#endif

#endif

enum leRawDecoderMode
{
    LE_RAW_MODE_NONE,
    LE_RAW_MODE_DRAW,
    LE_RAW_MODE_COPY,
};

struct leRawDecodeState;

typedef struct leRawDecodeStage
{
    struct leRawDecodeState* state;

    leResult (*exec)(struct leRawDecodeStage* stage);
    void (*cleanup)(struct leRawDecodeStage* stage);
} leRawDecodeStage;

typedef void (*ImageDecodeFn)(uint32_t stage, struct leRawDecodeState* state);

typedef struct leRawDecodeState
{
#if LE_STREAMING_ENABLED == 1
    leStreamManager manager;
#endif

    const leImage* source;
    leImage* newImg;

    enum leRawDecoderMode mode;

    leRect sourceRect;

    int32_t renderX;
    int32_t renderY;

    int32_t sourceX;
    int32_t sourceY;

    int32_t drawX;
    int32_t drawY;

    uint32_t imageRow;
    uint32_t imageCol;

    leColor sourceColor;
    uint32_t bufferIdx;

    uint32_t globalAlpha;
    uint32_t pixelAlpha;

    const lePixelBuffer* palette;

    leRawDecodeStage* readStage;
    leRawDecodeStage* maskStage;
    leRawDecodeStage* paletteStage;
    leRawDecodeStage* blendStage;
    leRawDecodeStage* convertStage;
    leRawDecodeStage* writeStage;

    leRawDecodeStage* currentStage;
} leRawDecodeState;

#endif /* LE_IMAGEDECODER_RAW_H */