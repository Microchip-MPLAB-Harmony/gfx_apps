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

#include "gfx/legato/core/legato_scheme.h"

void leScheme_Initialize(leScheme* scheme, leColorMode mode)
{
    if(scheme == NULL)
        return;

    scheme->base = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0xC8D0D4);
    scheme->highlight = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0xC8D0D4);
    scheme->highlightLight = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0xFFFFFF);
    scheme->shadow = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0x808080);
    scheme->shadowDark = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0x404040);
    scheme->foreground = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0x000000);
    scheme->foregroundInactive = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0xD6E3F5);
    scheme->foregroundDisabled = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0x808080);
    scheme->background = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0xFFFFFF);
    scheme->backgroundInactive = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0xD6E3F5);
    scheme->backgroundDisabled = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0xC8D0D4);
    scheme->text = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0x000000);
    scheme->textHighlight = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0x0000FF);
    scheme->textHighlightText = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0xFFFFFF);
    scheme->textInactive = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0xD6E3F5);
    scheme->textDisabled = leColorConvert(LE_COLOR_MODE_RGB_888, mode, 0x8C9294);
}