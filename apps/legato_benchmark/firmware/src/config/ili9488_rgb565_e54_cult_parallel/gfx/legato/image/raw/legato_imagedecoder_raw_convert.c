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

#include "gfx/legato/asset/legato_palette.h"
#include "gfx/legato/renderer/legato_renderer.h"


static struct ConvertStage
{
    leRawDecodeStage base;

    leColorMode sourceMode;
} convertStage;

static void stage_convertColor(leRawDecodeStage* stage)
{
    // convert the pixel to the destination format if necessary
    stage->state->sourceColor = leRenderer_ConvertColor(stage->state->sourceColor,
                                                        convertStage.sourceMode);

    stage->state->blendStage->exec(stage->state->blendStage);
}

void _leRawImageDecoder_ConvertInit(leRawDecodeState* state)
{
    if((state->source->palette != NULL && state->source->palette->colorMode == leGetRenderState()->colorMode) ||
        (state->source->buffer.mode == leGetRenderState()->colorMode))
    {
        return;
    }

    memset(&convertStage, 0, sizeof(convertStage));

    if(state->source->palette != NULL)
    {
        convertStage.sourceMode = state->source->palette->colorMode;
    }
    else
    {
        convertStage.sourceMode = state->source->buffer.mode;
    }

    convertStage.base.state = state;

    convertStage.base.exec = (void*)stage_convertColor;

    state->convertStage = (leRawDecodeStage*)&convertStage;

    if(state->maskStage == NULL)
    {
        state->maskStage = (leRawDecodeStage*)&convertStage;
    }

    if(state->paletteStage == NULL)
    {
        state->paletteStage = (leRawDecodeStage*)&convertStage;
    }

    if(state->blendStage == NULL)
    {
        state->blendStage = (leRawDecodeStage*)&convertStage;
    }
}