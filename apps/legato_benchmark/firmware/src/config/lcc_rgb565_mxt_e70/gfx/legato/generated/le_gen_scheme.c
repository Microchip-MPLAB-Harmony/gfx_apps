// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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
// DOM-IGNORE-END

#include "gfx/legato/generated/le_gen_scheme.h"

leScheme BlackFillScheme;
leScheme BlueFillScheme;
leScheme BrownFillScheme;
leScheme defaultScheme;
leScheme LightBlueBackgroundScheme;
leScheme LightBlueFillScheme;
leScheme LightGreenBackgroundScheme;
leScheme LightPinkFillScheme;
leScheme LightRedBackgroundScheme;
leScheme OrangeFillScheme;
leScheme PinkFillScheme;
leScheme PurpleFillScheme;
leScheme RedFillScheme;
leScheme WhiteBackgroundScheme;
leScheme WhiteFillScheme;
leScheme YellowFillScheme;

void legato_initialize_schemes(void)
{
    leScheme_Initialize(&BlackFillScheme, LE_COLOR_MODE_RGB_565);
    BlackFillScheme.base = 0x0000;
    BlackFillScheme.highlight = 0xC67A;
    BlackFillScheme.highlightLight = 0xFFFF;
    BlackFillScheme.shadow = 0x8410;
    BlackFillScheme.shadowDark = 0x4208;
    BlackFillScheme.foreground = 0x0000;
    BlackFillScheme.foregroundInactive = 0xD71C;
    BlackFillScheme.foregroundDisabled = 0x8410;
    BlackFillScheme.background = 0xFFFF;
    BlackFillScheme.backgroundInactive = 0xD71C;
    BlackFillScheme.backgroundDisabled = 0xC67A;
    BlackFillScheme.text = 0x0000;
    BlackFillScheme.textHighlight = 0x001F;
    BlackFillScheme.textHighlightText = 0xFFFF;
    BlackFillScheme.textInactive = 0xD71C;
    BlackFillScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&BlueFillScheme, LE_COLOR_MODE_RGB_565);
    BlueFillScheme.base = 0x001F;
    BlueFillScheme.highlight = 0xC67A;
    BlueFillScheme.highlightLight = 0xFFFF;
    BlueFillScheme.shadow = 0x8410;
    BlueFillScheme.shadowDark = 0x4208;
    BlueFillScheme.foreground = 0x0000;
    BlueFillScheme.foregroundInactive = 0xD71C;
    BlueFillScheme.foregroundDisabled = 0x8410;
    BlueFillScheme.background = 0xFFFF;
    BlueFillScheme.backgroundInactive = 0xD71C;
    BlueFillScheme.backgroundDisabled = 0xC67A;
    BlueFillScheme.text = 0x0000;
    BlueFillScheme.textHighlight = 0x001F;
    BlueFillScheme.textHighlightText = 0xFFFF;
    BlueFillScheme.textInactive = 0xD71C;
    BlueFillScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&BrownFillScheme, LE_COLOR_MODE_RGB_565);
    BrownFillScheme.base = 0xD487;
    BrownFillScheme.highlight = 0xC67A;
    BrownFillScheme.highlightLight = 0xFFFF;
    BrownFillScheme.shadow = 0x8410;
    BrownFillScheme.shadowDark = 0x4208;
    BrownFillScheme.foreground = 0x0000;
    BrownFillScheme.foregroundInactive = 0xD71C;
    BrownFillScheme.foregroundDisabled = 0x8410;
    BrownFillScheme.background = 0xFFFF;
    BrownFillScheme.backgroundInactive = 0xD71C;
    BrownFillScheme.backgroundDisabled = 0xC67A;
    BrownFillScheme.text = 0x0000;
    BrownFillScheme.textHighlight = 0x001F;
    BrownFillScheme.textHighlightText = 0xFFFF;
    BrownFillScheme.textInactive = 0xD71C;
    BrownFillScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&defaultScheme, LE_COLOR_MODE_RGB_565);
    defaultScheme.base = 0xC67A;
    defaultScheme.highlight = 0xC67A;
    defaultScheme.highlightLight = 0xFFFF;
    defaultScheme.shadow = 0x8410;
    defaultScheme.shadowDark = 0x4208;
    defaultScheme.foreground = 0x0000;
    defaultScheme.foregroundInactive = 0xD71C;
    defaultScheme.foregroundDisabled = 0x8410;
    defaultScheme.background = 0xFFFF;
    defaultScheme.backgroundInactive = 0xD71C;
    defaultScheme.backgroundDisabled = 0xC67A;
    defaultScheme.text = 0x0000;
    defaultScheme.textHighlight = 0x001F;
    defaultScheme.textHighlightText = 0xFFFF;
    defaultScheme.textInactive = 0xD71C;
    defaultScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&LightBlueBackgroundScheme, LE_COLOR_MODE_RGB_565);
    LightBlueBackgroundScheme.base = 0xB6BF;
    LightBlueBackgroundScheme.highlight = 0xC67A;
    LightBlueBackgroundScheme.highlightLight = 0xFFFF;
    LightBlueBackgroundScheme.shadow = 0x8410;
    LightBlueBackgroundScheme.shadowDark = 0x4208;
    LightBlueBackgroundScheme.foreground = 0x0000;
    LightBlueBackgroundScheme.foregroundInactive = 0xD71C;
    LightBlueBackgroundScheme.foregroundDisabled = 0x8410;
    LightBlueBackgroundScheme.background = 0xB6BF;
    LightBlueBackgroundScheme.backgroundInactive = 0xD71C;
    LightBlueBackgroundScheme.backgroundDisabled = 0xC67A;
    LightBlueBackgroundScheme.text = 0x0000;
    LightBlueBackgroundScheme.textHighlight = 0x001F;
    LightBlueBackgroundScheme.textHighlightText = 0xFFFF;
    LightBlueBackgroundScheme.textInactive = 0xD71C;
    LightBlueBackgroundScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&LightBlueFillScheme, LE_COLOR_MODE_RGB_565);
    LightBlueFillScheme.base = 0x87FF;
    LightBlueFillScheme.highlight = 0xC67A;
    LightBlueFillScheme.highlightLight = 0xFFFF;
    LightBlueFillScheme.shadow = 0x8410;
    LightBlueFillScheme.shadowDark = 0x4208;
    LightBlueFillScheme.foreground = 0x0000;
    LightBlueFillScheme.foregroundInactive = 0xD71C;
    LightBlueFillScheme.foregroundDisabled = 0x8410;
    LightBlueFillScheme.background = 0xFFFF;
    LightBlueFillScheme.backgroundInactive = 0xD71C;
    LightBlueFillScheme.backgroundDisabled = 0xC67A;
    LightBlueFillScheme.text = 0x0000;
    LightBlueFillScheme.textHighlight = 0x001F;
    LightBlueFillScheme.textHighlightText = 0xFFFF;
    LightBlueFillScheme.textInactive = 0xD71C;
    LightBlueFillScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&LightGreenBackgroundScheme, LE_COLOR_MODE_RGB_565);
    LightGreenBackgroundScheme.base = 0xA693;
    LightGreenBackgroundScheme.highlight = 0xC67A;
    LightGreenBackgroundScheme.highlightLight = 0xFFFF;
    LightGreenBackgroundScheme.shadow = 0x8410;
    LightGreenBackgroundScheme.shadowDark = 0x4208;
    LightGreenBackgroundScheme.foreground = 0x0000;
    LightGreenBackgroundScheme.foregroundInactive = 0xD71C;
    LightGreenBackgroundScheme.foregroundDisabled = 0x8410;
    LightGreenBackgroundScheme.background = 0xA693;
    LightGreenBackgroundScheme.backgroundInactive = 0xD71C;
    LightGreenBackgroundScheme.backgroundDisabled = 0xC67A;
    LightGreenBackgroundScheme.text = 0x0000;
    LightGreenBackgroundScheme.textHighlight = 0x001F;
    LightGreenBackgroundScheme.textHighlightText = 0xFFFF;
    LightGreenBackgroundScheme.textInactive = 0xD71C;
    LightGreenBackgroundScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&LightPinkFillScheme, LE_COLOR_MODE_RGB_565);
    LightPinkFillScheme.base = 0xFDFF;
    LightPinkFillScheme.highlight = 0xC67A;
    LightPinkFillScheme.highlightLight = 0xFFFF;
    LightPinkFillScheme.shadow = 0x8410;
    LightPinkFillScheme.shadowDark = 0x4208;
    LightPinkFillScheme.foreground = 0x0000;
    LightPinkFillScheme.foregroundInactive = 0xD71C;
    LightPinkFillScheme.foregroundDisabled = 0x8410;
    LightPinkFillScheme.background = 0xFFFF;
    LightPinkFillScheme.backgroundInactive = 0xD71C;
    LightPinkFillScheme.backgroundDisabled = 0xC67A;
    LightPinkFillScheme.text = 0x0000;
    LightPinkFillScheme.textHighlight = 0x001F;
    LightPinkFillScheme.textHighlightText = 0xFFFF;
    LightPinkFillScheme.textInactive = 0xD71C;
    LightPinkFillScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&LightRedBackgroundScheme, LE_COLOR_MODE_RGB_565);
    LightRedBackgroundScheme.base = 0xC67A;
    LightRedBackgroundScheme.highlight = 0xC67A;
    LightRedBackgroundScheme.highlightLight = 0xFFFF;
    LightRedBackgroundScheme.shadow = 0x8410;
    LightRedBackgroundScheme.shadowDark = 0x4208;
    LightRedBackgroundScheme.foreground = 0x0000;
    LightRedBackgroundScheme.foregroundInactive = 0xD71C;
    LightRedBackgroundScheme.foregroundDisabled = 0x8410;
    LightRedBackgroundScheme.background = 0xFDF7;
    LightRedBackgroundScheme.backgroundInactive = 0xD71C;
    LightRedBackgroundScheme.backgroundDisabled = 0xC67A;
    LightRedBackgroundScheme.text = 0x0000;
    LightRedBackgroundScheme.textHighlight = 0x001F;
    LightRedBackgroundScheme.textHighlightText = 0xFFFF;
    LightRedBackgroundScheme.textInactive = 0xD71C;
    LightRedBackgroundScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&OrangeFillScheme, LE_COLOR_MODE_RGB_565);
    OrangeFillScheme.base = 0xFC00;
    OrangeFillScheme.highlight = 0xC67A;
    OrangeFillScheme.highlightLight = 0xFFFF;
    OrangeFillScheme.shadow = 0x8410;
    OrangeFillScheme.shadowDark = 0x4208;
    OrangeFillScheme.foreground = 0x0000;
    OrangeFillScheme.foregroundInactive = 0xD71C;
    OrangeFillScheme.foregroundDisabled = 0x8410;
    OrangeFillScheme.background = 0xFC00;
    OrangeFillScheme.backgroundInactive = 0xD71C;
    OrangeFillScheme.backgroundDisabled = 0xC67A;
    OrangeFillScheme.text = 0x0000;
    OrangeFillScheme.textHighlight = 0x001F;
    OrangeFillScheme.textHighlightText = 0xFFFF;
    OrangeFillScheme.textInactive = 0xD71C;
    OrangeFillScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&PinkFillScheme, LE_COLOR_MODE_RGB_565);
    PinkFillScheme.base = 0xD018;
    PinkFillScheme.highlight = 0xC67A;
    PinkFillScheme.highlightLight = 0xFFFF;
    PinkFillScheme.shadow = 0x8410;
    PinkFillScheme.shadowDark = 0x4208;
    PinkFillScheme.foreground = 0x0000;
    PinkFillScheme.foregroundInactive = 0xD71C;
    PinkFillScheme.foregroundDisabled = 0x8410;
    PinkFillScheme.background = 0xFFFF;
    PinkFillScheme.backgroundInactive = 0xD71C;
    PinkFillScheme.backgroundDisabled = 0xC67A;
    PinkFillScheme.text = 0x0000;
    PinkFillScheme.textHighlight = 0x001F;
    PinkFillScheme.textHighlightText = 0xFFFF;
    PinkFillScheme.textInactive = 0xD71C;
    PinkFillScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&PurpleFillScheme, LE_COLOR_MODE_RGB_565);
    PurpleFillScheme.base = 0xBDFF;
    PurpleFillScheme.highlight = 0xC67A;
    PurpleFillScheme.highlightLight = 0xFFFF;
    PurpleFillScheme.shadow = 0x8410;
    PurpleFillScheme.shadowDark = 0x4208;
    PurpleFillScheme.foreground = 0x0000;
    PurpleFillScheme.foregroundInactive = 0xD71C;
    PurpleFillScheme.foregroundDisabled = 0x8410;
    PurpleFillScheme.background = 0xFFFF;
    PurpleFillScheme.backgroundInactive = 0xD71C;
    PurpleFillScheme.backgroundDisabled = 0xC67A;
    PurpleFillScheme.text = 0x0000;
    PurpleFillScheme.textHighlight = 0x001F;
    PurpleFillScheme.textHighlightText = 0xFFFF;
    PurpleFillScheme.textInactive = 0xD71C;
    PurpleFillScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&RedFillScheme, LE_COLOR_MODE_RGB_565);
    RedFillScheme.base = 0xF800;
    RedFillScheme.highlight = 0xC67A;
    RedFillScheme.highlightLight = 0xFFFF;
    RedFillScheme.shadow = 0x8410;
    RedFillScheme.shadowDark = 0x4208;
    RedFillScheme.foreground = 0x0000;
    RedFillScheme.foregroundInactive = 0xD71C;
    RedFillScheme.foregroundDisabled = 0x8410;
    RedFillScheme.background = 0xFFFF;
    RedFillScheme.backgroundInactive = 0xD71C;
    RedFillScheme.backgroundDisabled = 0xC67A;
    RedFillScheme.text = 0x0000;
    RedFillScheme.textHighlight = 0x001F;
    RedFillScheme.textHighlightText = 0xFFFF;
    RedFillScheme.textInactive = 0xD71C;
    RedFillScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&WhiteBackgroundScheme, LE_COLOR_MODE_RGB_565);
    WhiteBackgroundScheme.base = 0xFFFF;
    WhiteBackgroundScheme.highlight = 0xC67A;
    WhiteBackgroundScheme.highlightLight = 0xFFFF;
    WhiteBackgroundScheme.shadow = 0x8410;
    WhiteBackgroundScheme.shadowDark = 0x4208;
    WhiteBackgroundScheme.foreground = 0x0000;
    WhiteBackgroundScheme.foregroundInactive = 0xD71C;
    WhiteBackgroundScheme.foregroundDisabled = 0x8410;
    WhiteBackgroundScheme.background = 0xFFFF;
    WhiteBackgroundScheme.backgroundInactive = 0xD71C;
    WhiteBackgroundScheme.backgroundDisabled = 0xC67A;
    WhiteBackgroundScheme.text = 0x0000;
    WhiteBackgroundScheme.textHighlight = 0x001F;
    WhiteBackgroundScheme.textHighlightText = 0xFFFF;
    WhiteBackgroundScheme.textInactive = 0xD71C;
    WhiteBackgroundScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&WhiteFillScheme, LE_COLOR_MODE_RGB_565);
    WhiteFillScheme.base = 0xFFFF;
    WhiteFillScheme.highlight = 0xC67A;
    WhiteFillScheme.highlightLight = 0xFFFF;
    WhiteFillScheme.shadow = 0x8410;
    WhiteFillScheme.shadowDark = 0x4208;
    WhiteFillScheme.foreground = 0x0000;
    WhiteFillScheme.foregroundInactive = 0xD71C;
    WhiteFillScheme.foregroundDisabled = 0x8410;
    WhiteFillScheme.background = 0xFFFF;
    WhiteFillScheme.backgroundInactive = 0xD71C;
    WhiteFillScheme.backgroundDisabled = 0xC67A;
    WhiteFillScheme.text = 0x0000;
    WhiteFillScheme.textHighlight = 0x001F;
    WhiteFillScheme.textHighlightText = 0xFFFF;
    WhiteFillScheme.textInactive = 0xD71C;
    WhiteFillScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&YellowFillScheme, LE_COLOR_MODE_RGB_565);
    YellowFillScheme.base = 0xFFE0;
    YellowFillScheme.highlight = 0xC67A;
    YellowFillScheme.highlightLight = 0xFFFF;
    YellowFillScheme.shadow = 0x8410;
    YellowFillScheme.shadowDark = 0x4208;
    YellowFillScheme.foreground = 0x0000;
    YellowFillScheme.foregroundInactive = 0xD71C;
    YellowFillScheme.foregroundDisabled = 0x8410;
    YellowFillScheme.background = 0xFFFF;
    YellowFillScheme.backgroundInactive = 0xD71C;
    YellowFillScheme.backgroundDisabled = 0xC67A;
    YellowFillScheme.text = 0x0000;
    YellowFillScheme.textHighlight = 0x001F;
    YellowFillScheme.textHighlightText = 0xFFFF;
    YellowFillScheme.textInactive = 0xD71C;
    YellowFillScheme.textDisabled = 0x8C92;

}
