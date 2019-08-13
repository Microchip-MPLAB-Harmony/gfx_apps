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

#include "gfx/legato/common/legato_pixelbuffer.h"
#include "gfx/legato/image/legato_palette.h"
#include "gfx/legato/renderer/legato_renderer.h"

static struct InternalPaletteStage
{
    leRawDecodeStage base;

    uint32_t paletteSize;
} paletteStage;

static leResult stage_lookup(struct InternalPaletteStage* stage)
{
    // look up the actual color from the palette
    memcpy(&stage->base.state->sourceColor,
           (void*)((uint8_t*)stage->base.state->source->palette->header.address + (stage->base.state->sourceColor * paletteStage.paletteSize)),
           paletteStage.paletteSize);

    stage->base.state->currentStage = stage->base.state->convertStage;

    return LE_SUCCESS;
}

uint32_t _leRawImageDecoder_PaletteStreamInit(leRawDecodeState* state);

void _leRawImageDecoder_PaletteInternalInit(leRawDecodeState* state)
{
    memset(&paletteStage, 0, sizeof(paletteStage));

    paletteStage.base.state = state;

    if(LE_COLOR_MODE_IS_INDEX(state->source->buffer.mode) == LE_FALSE ||
       state->source->palette == NULL)
    {
        return;
    }

#if LE_STREAMING_ENABLED == 1
    if(state->source->palette->header.location != LE_STREAM_LOCATION_ID_INTERNAL)
    {
        _leRawImageDecoder_PaletteStreamInit(state);

        return;
    }
#endif

    paletteStage.base.exec = (void*)stage_lookup;
    paletteStage.paletteSize = leColorInfoTable[state->source->palette->colorMode].size;

    state->paletteStage = (void*)&paletteStage;

    if(state->maskStage == NULL)
    {
        state->maskStage = state->paletteStage;
    }
}