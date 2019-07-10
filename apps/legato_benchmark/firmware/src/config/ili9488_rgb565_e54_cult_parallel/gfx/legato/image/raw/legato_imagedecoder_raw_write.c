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

#include "gfx/legato/renderer/legato_renderer.h"

static struct WriteStage
{
    leRawDecodeStage base;
} writeStage;

static void stage_WriteNonAlpha(leRawDecodeStage* stage)
{
    // write color
    leRenderer_PutPixel(stage->state->drawX,
                        stage->state->drawY,
                        stage->state->sourceColor);
}

static void stage_WriteRGBA5551(leRawDecodeStage* stage)
{
    // mask out based on alpha binary value
    if(leColorChannelAlpha(stage->state->sourceColor,
                           stage->state->source->buffer.mode) == 0)
    {
        return;
    }

    // write color
    leRenderer_PutPixel(stage->state->drawX,
                        stage->state->drawY,
                        stage->state->sourceColor);
}

static void stage_WriteAlpha(leRawDecodeStage* stage)
{
    // write color
    leRenderer_BlendPixel(stage->state->drawX,
                          stage->state->drawY,
                          stage->state->sourceColor,
                          stage->state->globalAlpha);
}

void _leRawImageDecoder_WriteInit(leRawDecodeState* state,
                                  leBool ignoreAlpha)
{
    memset(&writeStage, 0, sizeof(writeStage));

    writeStage.base.state = state;

    if(ignoreAlpha == LE_FALSE &&
       LE_COLOR_MODE_IS_ALPHA(state->source->buffer.mode) == LE_TRUE)
    {
        if(state->source->buffer.mode == LE_COLOR_MODE_RGBA_5551)
        {
            writeStage.base.exec = (void*)stage_WriteRGBA5551;
        }
        else
        {
            writeStage.base.exec = (void*)stage_WriteAlpha;
        }
    }
    else
    {
        writeStage.base.exec = (void*)stage_WriteNonAlpha;
    }

    state->writeStage = (void*)&writeStage;

    if(state->maskStage == NULL)
    {
        state->maskStage = (void*)&writeStage;
    }

    if(state->paletteStage == NULL)
    {
        state->paletteStage = (void*)&writeStage;
    }

    if(state->convertStage == NULL)
    {
        state->convertStage = (leRawDecodeStage*)&writeStage;
    }

    if(state->blendStage == NULL)
    {
        state->blendStage = (void*)&writeStage;
    }
}