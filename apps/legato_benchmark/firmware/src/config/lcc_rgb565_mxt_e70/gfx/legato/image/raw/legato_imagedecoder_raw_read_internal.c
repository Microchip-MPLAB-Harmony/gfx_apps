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

#include "gfx/legato/image/legato_image_utils.h"
#include "gfx/legato/renderer/legato_renderer.h"

static struct InternalReadStage
{
    leRawDecodeStage base;
    void (*decode)(void);
    uint32_t lastBlock;
    uint32_t lastOffset;

    uint32_t dataSize;
    uint32_t imgBPP;
} internalReadStage;

static void colorDecode()
{
    // get a pixel from the sourced image
    internalReadStage.base.state->sourceColor = lePixelBufferGet_Unsafe(&internalReadStage.base.state->source->buffer,
                                                                        internalReadStage.base.state->sourceX,
                                                                        internalReadStage.base.state->sourceY);
}

static void indexDecode()
{
    internalReadStage.base.state->sourceColor = lePixelBufferGetIndex_Unsafe(&internalReadStage.base.state->source->buffer,
                                                                             internalReadStage.base.state->bufferIdx);
}

static void rleDecode()
{
    internalReadStage.base.state->sourceColor = leGetRLEDataAtIndex(internalReadStage.base.state->source->buffer.pixels,
                                                                    internalReadStage.base.state->source->buffer.pixel_count,
                                                                    internalReadStage.base.state->bufferIdx,
                                                                    &internalReadStage.lastBlock,
                                                                    &internalReadStage.lastOffset);
}

static void indexRLEDecode()
{
    uint32_t srcClr;

    // get the offset into the index table
    srcClr = leGetOffsetFromIndexAndBPP(internalReadStage.base.state->bufferIdx,
                                        internalReadStage.imgBPP);

    // perform RLE lookup
    srcClr = leGetRLEDataAtIndex(internalReadStage.base.state->source->buffer.pixels,
                                 internalReadStage.base.state->source->buffer.pixel_count,
                                 srcClr,
                                 &internalReadStage.lastBlock,
                                 &internalReadStage.lastOffset);

    // get the value from the RLE block
    srcClr = leGetDiscreteValueAtIndex(internalReadStage.base.state->bufferIdx,
                                       srcClr,
                                       internalReadStage.base.state->source->buffer.mode);

    internalReadStage.base.state->sourceColor = srcClr;
}

static leResult stage_decode(struct InternalReadStage* stage)
{
    leRawDecodeState* state = stage->base.state;

    if(state->imageRow >= (uint32_t)state->sourceRect.height)
    {
        state->currentStage = NULL;

        return LE_SUCCESS;
    }

    // calculate dest offset
    state->drawY = state->renderY + state->imageRow;
    state->sourceY = state->sourceRect.y + state->imageRow;

    state->drawX = state->renderX + state->imageCol;
    state->sourceX = state->sourceRect.x + state->imageCol;

    // calculate buffer index
    internalReadStage.base.state->bufferIdx = internalReadStage.base.state->sourceX +
                                              (internalReadStage.base.state->sourceY *
                                               internalReadStage.base.state->source->buffer.size.width);

    internalReadStage.decode();

    state->currentStage = state->maskStage;

    if(state->imageCol < (uint32_t)state->sourceRect.width - 1)
    {
        state->imageCol += 1;
    }
    else
    {
        state->imageCol = 0;
        state->imageRow += 1;
    }

    return LE_SUCCESS;
}

void _leRawImageDecoder_ReadStreamInit(leRawDecodeState* state);
void _leRawImageDecoder_PaletteInternalInit(leRawDecodeState* state);

void _leRawImageDecoder_ReadInternalInit(leRawDecodeState* state)
{
#if LE_STREAMING_ENABLED == 1
    if(state->source->header.location == LE_STREAM_LOCATION_ID_INTERNAL)
    {
#endif
        memset(&internalReadStage, 0, sizeof(internalReadStage));

        state->imageRow = 0;
        state->imageCol = 0;
        internalReadStage.dataSize = leColorInfoTable[state->source->buffer.mode].size;
        internalReadStage.imgBPP = leColorInfoTable[state->source->buffer.mode].bppOrdinal;

        internalReadStage.base.state = state;

        if(LE_COLOR_MODE_IS_INDEX(state->source->buffer.mode) == LE_TRUE)
        {
            if(state->source->format == LE_IMAGE_FORMAT_RAW)
            {
                internalReadStage.decode = indexDecode;
            }
            else
            {
                internalReadStage.decode = indexRLEDecode;
            }
        }
        else
        {
            if(state->source->format == LE_IMAGE_FORMAT_RAW)
            {
                internalReadStage.decode = colorDecode;
            }
            else
            {
                internalReadStage.decode = rleDecode;
            }
        }

        internalReadStage.base.exec = (void *) stage_decode;

        state->readStage = (leRawDecodeStage*)&internalReadStage;
#if LE_STREAMING_ENABLED == 1
    }
    else
    {
        return _leRawImageDecoder_ReadStreamInit(state);
    }
#endif
}