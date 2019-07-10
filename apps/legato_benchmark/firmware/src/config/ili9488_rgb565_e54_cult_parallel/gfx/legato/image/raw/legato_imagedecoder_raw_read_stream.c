/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#include "gfx/legato/image/raw/legato_imagedecoder_raw.h"

#if LE_ASSET_STREAMING_ENABLED == 1

#include "gfx/legato/renderer/legato_renderer.h"
#include "gfx/legato/image/legato_image_utils.h"

#if LE_ASSET_DECODER_USE_PIXEL_CACHE == 1
#define cache leRawImageDecoderScratchBuffer
#endif

static struct StreamReadStage
{
    leRawDecodeStage base;

#if LE_ASSET_DECODER_USE_PIXEL_CACHE == 1
    uint32_t cacheSize;
    uint32_t cacheIndexStart;
    uint32_t cacheIndexEnd;
#else
    uint32_t sourceColor;
#endif
    void (*decode)(void);

    uint32_t mod;

    lePixelBuffer readBuffer;

    leBool mediaOpen;

    leAssetStreamReader reader;
} streamReadStage;

#if LE_ASSET_DECODER_USE_PIXEL_CACHE == 1
static leResult requestImageData(leRawDecodeState* state)
{
    uint32_t index;
    uint32_t offs;
    void* address;
    uint32_t modeSize;
    uint32_t remaining;

    streamReadStage.cacheIndexStart = state->sourceRect.x + state->imageCol +
                      ((state->sourceRect.y + state->imageRow) * state->source->buffer.size.width);

    offs = leGetOffsetFromIndexAndBPP(streamReadStage.cacheIndexStart,
                                      leColorModeInfoGet(state->source->buffer.mode).bppOrdinal);

    address = state->source->header.dataAddress;
    address = (void*)(((uint8_t*)address) + offs);

    modeSize = leColorModeInfoGet(state->source->buffer.mode).size;

    // calculate how much data is left in the image
    remaining = state->source->header.dataSize - offs;

    // make sure we stay within the width of the cache, aligned to the mode pixel size in bytes
    streamReadStage.cacheSize = (LE_ASSET_DECODER_CACHE_SIZE / modeSize);
    streamReadStage.cacheSize *= modeSize;

    // prevent buffer overrun
    if(streamReadStage.cacheSize >= remaining)
    {
        streamReadStage.cacheSize = remaining / modeSize;
        streamReadStage.cacheSize *= modeSize;
    }

    streamReadStage.cacheIndexEnd = streamReadStage.cacheIndexStart + (streamReadStage.cacheSize / modeSize) - 1;

    streamReadStage.reader.state = LE_STREAM_WAITING;

    return leApplication_MediaReadRequest(&streamReadStage.reader,
                                          address,
                                          streamReadStage.cacheSize,
                                          cache);
}
#endif

#if LE_ASSET_DECODER_USE_PIXEL_CACHE == 1
static void colorDecode()
{
    if(streamReadStage.cacheIndexStart == streamReadStage.cacheIndexEnd ||
       (streamReadStage.base.state->bufferIdx < streamReadStage.cacheIndexStart ||
       streamReadStage.base.state->bufferIdx > streamReadStage.cacheIndexEnd))
    {
        requestImageData(streamReadStage.base.state);

        if(streamReadStage.reader.state == LE_STREAM_WAITING)
        {
            return;
        }
    }

    // get a pixel from the cache
    streamReadStage.base.state->sourceColor = lePixelBufferGet_Unsafe(&streamReadStage.readBuffer,
                                                                      streamReadStage.base.state->bufferIdx - streamReadStage.cacheIndexStart,
                                                                      0);
}
#else
static void colorDecode()
{
    streamReadStage.base.state->sourceColor = 0;

    leApplication_MediaReadRequest(&streamReadStage.reader,
                                   (void*)((uint32_t)streamReadStage.base.state->source->header.dataAddress +
                                   streamReadStage.base.state->bufferIdx * leColorModeInfoGet(streamReadStage.base.state->source->buffer.mode).size),
                                   leColorModeInfoGet(streamReadStage.base.state->source->buffer.mode).size,
                                   (uint8_t*)&streamReadStage.base.state->sourceColor);
}
#endif

static void rleDecode()
{
}

#if LE_ASSET_DECODER_USE_PIXEL_CACHE == 1
static void indexDecode()
{
    if(streamReadStage.cacheIndexStart == streamReadStage.cacheIndexEnd ||
        (streamReadStage.base.state->bufferIdx < streamReadStage.cacheIndexStart ||
         streamReadStage.base.state->bufferIdx > streamReadStage.cacheIndexEnd))
    {
        requestImageData(streamReadStage.base.state);

        if(streamReadStage.reader.state == LE_STREAM_WAITING)
        {
            return;
        }
    }

    // get a pixel from the cache
    streamReadStage.base.state->sourceColor = lePixelBufferGetIndex_Unsafe(&streamReadStage.readBuffer,
                                                                           streamReadStage.base.state->bufferIdx -
                                                                           streamReadStage.cacheIndexStart);
}
#else
static void indexDecode()
{
    uint32_t offs;

    offs = leGetOffsetFromIndexAndBPP(streamReadStage.base.state->bufferIdx,
                                      leColorModeInfoGet(streamReadStage.base.state->source->buffer.mode).bppOrdinal);

    leApplication_MediaReadRequest((leAssetStreamReader*)&streamReadStage.reader,
                                   (void*)((uint32_t)streamReadStage.base.state->source->header.dataAddress + offs),
                                   leColorModeInfoGet(streamReadStage.base.state->source->buffer.mode).size,
                                   (uint8_t*)&streamReadStage.sourceColor);

    // get a pixel from the buffer
    streamReadStage.base.state->sourceColor = lePixelBufferGetIndex_Unsafe(&streamReadStage.readBuffer,
                                                                           streamReadStage.base.state->bufferIdx % streamReadStage.mod);
}
#endif

static void indexRLEDecode()
{
}

static void decode(struct StreamReadStage* stage)
{
    leRawDecodeState* state = stage->base.state;

    if(streamReadStage.reader.state == LE_STREAM_WAITING)
        return;

    for(state->imageRow = 0; state->imageRow < state->sourceRect.height; state->imageRow++)
    {
        state->drawY = state->renderY + state->imageRow;
        state->sourceY = state->sourceRect.y + state->imageRow;

        for(state->imageCol = 0; state->imageCol < state->sourceRect.width; state->imageCol++)
        {
            // calculate dest offset
            state->drawX = state->renderX + state->imageCol;
            state->sourceX = state->sourceRect.x + state->imageCol;

            streamReadStage.base.state->bufferIdx = state->sourceX +
                                                    (state->sourceY *
                                                     state->source->buffer.size.width);

            streamReadStage.decode();

            state->maskStage->exec(state->maskStage);
        }
    }
}

static void exec(struct StreamReadStage* stage)
{
    if(leApplication_MediaOpenRequest((leAssetStreamReader*)stage->base.state) == LE_FAILURE)
        return;

    streamReadStage.mediaOpen = LE_TRUE;

    if(LE_COLOR_MODE_IS_INDEX(streamReadStage.base.state->source->buffer.mode) == LE_TRUE)
    {
        stage->base.exec = (void*)indexDecode;
    }
    else
    {

    }

    stage->base.exec = (void*)decode;

    if(LE_COLOR_MODE_IS_INDEX(streamReadStage.base.state->source->buffer.mode) == LE_TRUE)
    {
        if(streamReadStage.base.state->source->format == LE_IMAGE_FORMAT_RAW)
        {
            streamReadStage.decode = indexDecode;
        }
        else
        {
            streamReadStage.decode = indexRLEDecode;
        }
    }
    else
    {
        if(streamReadStage.base.state->source->format == LE_IMAGE_FORMAT_RAW)
        {
            streamReadStage.decode = colorDecode;
        }
        else
        {
            streamReadStage.decode = rleDecode;
        }
    }

    stage->base.exec((void*)stage);
}

static void cleanup(struct StreamReadStage* stage)
{
    if(streamReadStage.mediaOpen == LE_TRUE)
    {
        leApplication_MediaCloseRequest((leAssetStreamReader *) stage->base.state);
    }
}

#if LE_ASSET_STREAMING_ENABLED == 1
static void readerExec(leAssetStreamReader* reader)
{
    if(streamReadStage.reader.state == LE_STREAM_READY ||
        streamReadStage.reader.state == LE_STREAM_WAITING)
    {
        streamReadStage.base.exec((void*)&streamReadStage);
    }
}

static void readerDataReady(leAssetStreamReader* reader)
{
    if(streamReadStage.reader.state == LE_STREAM_WAITING)
    {
        streamReadStage.reader.state = LE_STREAM_DATAREADY;
    }
}

static void readerAbort(leAssetStreamReader* reader)
{
    streamReadStage.reader.state = LE_STREAM_ABORT;
}
#endif

void _leRawImageDecoder_ReadStreamInit(leRawDecodeState* state)
{
    memset(&streamReadStage, 0, sizeof(streamReadStage));

#if LE_ASSET_DECODER_USE_PIXEL_CACHE == 0
    if(state->source->buffer.mode == LE_COLOR_MODE_INDEX_1)
    {
        streamReadStage.mod = 8;
    }
    else if(state->source->buffer.mode == LE_COLOR_MODE_INDEX_4)
    {
        streamReadStage.mod = 2;
    }
    else
    {
        streamReadStage.mod = 1;
    }
#endif

    streamReadStage.reader.asset = (leAssetHeader*)state->source;
    streamReadStage.reader.exec = (void*)readerExec;
    streamReadStage.reader.dataReady = (void*)readerDataReady;
    streamReadStage.reader.abort = (void*)readerAbort;
    streamReadStage.reader.status = LE_READER_STATUS_READY;
    streamReadStage.reader.state = LE_STREAM_READY;
    streamReadStage.reader.result = 0;
    streamReadStage.reader.userData = NULL;
    streamReadStage.reader.onFinished = NULL;

    streamReadStage.base.state = state;
    streamReadStage.base.exec = (void*)exec;
    streamReadStage.base.cleanup = (void*)cleanup;

#if LE_ASSET_DECODER_USE_PIXEL_CACHE == 1
    lePixelBufferCreate(LE_ASSET_DECODER_CACHE_SIZE / leColorModeInfoGet(state->source->buffer.mode).size,
                        1,
                        state->source->buffer.mode,
                        cache,
                        &streamReadStage.readBuffer);
#else
    lePixelBufferCreate(leColorModeInfoGet(state->source->buffer.mode).size,
                        1,
                        state->source->buffer.mode,
                        &streamReadStage.sourceColor,
                        &streamReadStage.readBuffer);
#endif

    state->readStage = (void*)&streamReadStage;
}

#endif