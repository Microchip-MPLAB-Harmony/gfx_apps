#ifndef LE_IMAGEDECODER_RAW_H
#define LE_IMAGEDECODER_RAW_H

#include "gfx/legato/image/legato_image.h"
#include "gfx/legato/common/legato_pixelbuffer.h"



#if LE_STREAMING_ENABLED == 1
#ifndef LE_ASSET_DECODER_CACHE_SIZE
#define LE_ASSET_DECODER_CACHE_SIZE 128
#endif

#if LE_ASSET_DECODER_USE_PIXEL_CACHE == 1
// the cache used for streaming image source data
extern uint8_t leRawImageDecoderScratchBuffer[LE_ASSET_DECODER_CACHE_SIZE];
#endif

#if LE_ASSET_DECODER_USE_MASK_CACHE == 1
// the cache used for streaming mask lookup data
extern uint8_t leRawImageDecoderMaskScratchBuffer[LE_ASSET_DECODER_CACHE_SIZE];
#endif

#if LE_ASSET_DECODER_USE_PALETTE_CACHE == 1
// the cache used for streaming palette lookup data
extern uint8_t leRawImageDecoderPaletteScratchBuffer[LE_ASSET_DECODER_CACHE_SIZE];
#endif

#if LE_ASSET_DECODER_USE_BLEND_CACHE == 1
// the cache used for streaming blend mask lookup data
extern uint8_t leRawImageDecoderBlendBuffer[LE_ASSET_DECODER_CACHE_SIZE];
#endif

#endif

// *****************************************************************************
/* Enumeration:
    enum leRawDecoderMode

  Summary:
    Indicates the current mode of the raw image decoder
*/
enum leRawDecoderMode
{
    LE_RAW_MODE_NONE,
    LE_RAW_MODE_DRAW,
    LE_RAW_MODE_COPY,
};

struct leRawDecodeState;

// *****************************************************************************
/* Structure:
    struct leRawDecodeStage

  Summary:
    Structure defining an individual raw image decoding stage

    struct leRawDecodeState* state - pointer to the decoder state

    exec - function that runs this stage
    cleanup - function that cleans up this stage
*/
typedef struct leRawDecodeStage
{
    struct leRawDecodeState* state;

    leResult (*exec)(struct leRawDecodeStage* stage);
    void (*cleanup)(struct leRawDecodeStage* stage);
} leRawDecodeStage;

// *****************************************************************************
/* Structure:
    struct leRawDecodeState

  Summary:
    Structure defining the state of the raw image decoder
*/
typedef struct leRawDecodeState
{
#if LE_STREAMING_ENABLED == 1
    leStreamManager manager; // so this decoder can act as a streaming manager
                             // if necessary
#endif

    const leImage* source; // the source image
    leImage* newImg; // destination image for copy/decompress mode

    enum leRawDecoderMode mode; // the current mode of the decoder

    leRect sourceRect; // the image source rectangle

    int32_t renderX; // the target screen X position in pixels
    int32_t renderY; // the target screen Y position in pixels

    int32_t sourceX; // the sub X position of the image source
    int32_t sourceY; // the sub Y position of the image source

    int32_t drawX; // the current draw X position in screen space
    int32_t drawY; // the current draw Y position in screen space

    uint32_t imageRow; // the current source image row offset
    uint32_t imageCol; // the current source image column offset

    leColor sourceColor; // the current color that is being referenced
    uint32_t bufferIdx; // the index of the destination buffer that is being drawn to

    uint32_t globalAlpha; // a global alpha state
    uint32_t pixelAlpha; // a pixel alpha state (not used yet)

    const lePixelBuffer* palette; // pointer to a lookup table if needed

    leRawDecodeStage* readStage; // pointer to the image decoder read stage
    leRawDecodeStage* maskStage; // pointer to the image decoder mask stage
    leRawDecodeStage* paletteStage; // pointer to the image decoder lookup stage
    leRawDecodeStage* blendStage; // pointer to the image decoder blend stage
    leRawDecodeStage* convertStage; // pointer to the image decoder convert stage
    leRawDecodeStage* writeStage; // pointer to the image decoder write stage

    leRawDecodeStage* currentStage; // the current decoder stage
} leRawDecodeState;

#endif /* LE_IMAGEDECODER_RAW_H */