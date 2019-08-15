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

static struct InternalMaskStage
{
    leRawDecodeStage base;
} maskStage;

static leResult stage_rejectMaskedColor(leRawDecodeStage* stage)
{
    // compare color to mask
    if(stage->state->sourceColor == stage->state->source->mask.color)
    {
        stage->state->currentStage = stage->state->readStage;
    }
    else
    {
        stage->state->currentStage = stage->state->paletteStage;
    }

    return LE_SUCCESS;
}

void _leRawImageDecoder_MaskInternalInit(leRawDecodeState* state)
{
    memset(&maskStage, 0, sizeof(maskStage));

    maskStage.base.state = state;

    if((state->source->flags & LE_IMAGE_USE_MASK_COLOR) > 0)
    {
        maskStage.base.exec = (void*)stage_rejectMaskedColor;

        state->maskStage = (leRawDecodeStage*)&maskStage;
    }
}