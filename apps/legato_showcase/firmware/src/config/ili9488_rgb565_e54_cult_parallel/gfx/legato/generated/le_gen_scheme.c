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

leScheme AlternateGradientScheme;
leScheme BackgroundGradientScheme;
leScheme BlackBackground;
leScheme defaultScheme;
leScheme GradientScheme;
leScheme ListWheelScheme;
leScheme MainMenuGradientScheme;
leScheme RadioButtonsOnDarkScheme;
leScheme TouchTestScheme;
leScheme whiteScheme;

void legato_initialize_schemes(void)
{
    leScheme_Initialize(&AlternateGradientScheme, LE_COLOR_MODE_RGB_565);
    AlternateGradientScheme.base = 0xF800;
    AlternateGradientScheme.highlight = 0xC67A;
    AlternateGradientScheme.highlightLight = 0xFFFF;
    AlternateGradientScheme.shadow = 0x8410;
    AlternateGradientScheme.shadowDark = 0x4208;
    AlternateGradientScheme.foreground = 0xF800;
    AlternateGradientScheme.foregroundInactive = 0x001F;
    AlternateGradientScheme.foregroundDisabled = 0x8410;
    AlternateGradientScheme.background = 0x0017;
    AlternateGradientScheme.backgroundInactive = 0xD71C;
    AlternateGradientScheme.backgroundDisabled = 0xC67A;
    AlternateGradientScheme.text = 0x0000;
    AlternateGradientScheme.textHighlight = 0x001F;
    AlternateGradientScheme.textHighlightText = 0xFFFF;
    AlternateGradientScheme.textInactive = 0xD71C;
    AlternateGradientScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&BackgroundGradientScheme, LE_COLOR_MODE_RGB_565);
    BackgroundGradientScheme.base = 0x0000;
    BackgroundGradientScheme.highlight = 0xC67A;
    BackgroundGradientScheme.highlightLight = 0xFFFF;
    BackgroundGradientScheme.shadow = 0x8410;
    BackgroundGradientScheme.shadowDark = 0x4208;
    BackgroundGradientScheme.foreground = 0xB61F;
    BackgroundGradientScheme.foregroundInactive = 0x0008;
    BackgroundGradientScheme.foregroundDisabled = 0x8410;
    BackgroundGradientScheme.background = 0x000A;
    BackgroundGradientScheme.backgroundInactive = 0xD71C;
    BackgroundGradientScheme.backgroundDisabled = 0xC67A;
    BackgroundGradientScheme.text = 0x0000;
    BackgroundGradientScheme.textHighlight = 0x001F;
    BackgroundGradientScheme.textHighlightText = 0xFFFF;
    BackgroundGradientScheme.textInactive = 0xD71C;
    BackgroundGradientScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&BlackBackground, LE_COLOR_MODE_RGB_565);
    BlackBackground.base = 0xC67A;
    BlackBackground.highlight = 0xC67A;
    BlackBackground.highlightLight = 0xFFFF;
    BlackBackground.shadow = 0x8410;
    BlackBackground.shadowDark = 0x4208;
    BlackBackground.foreground = 0x0000;
    BlackBackground.foregroundInactive = 0xD71C;
    BlackBackground.foregroundDisabled = 0x8410;
    BlackBackground.background = 0x0000;
    BlackBackground.backgroundInactive = 0xD71C;
    BlackBackground.backgroundDisabled = 0xC67A;
    BlackBackground.text = 0xCF3D;
    BlackBackground.textHighlight = 0x001F;
    BlackBackground.textHighlightText = 0xFFFF;
    BlackBackground.textInactive = 0xD71C;
    BlackBackground.textDisabled = 0x8C92;

    leScheme_Initialize(&defaultScheme, LE_COLOR_MODE_RGB_565);
    defaultScheme.base = 0xFFFF;
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

    leScheme_Initialize(&GradientScheme, LE_COLOR_MODE_RGB_565);
    GradientScheme.base = 0xF800;
    GradientScheme.highlight = 0xC67A;
    GradientScheme.highlightLight = 0xFFFF;
    GradientScheme.shadow = 0x8410;
    GradientScheme.shadowDark = 0x4208;
    GradientScheme.foreground = 0x07E0;
    GradientScheme.foregroundInactive = 0xFFE0;
    GradientScheme.foregroundDisabled = 0x8410;
    GradientScheme.background = 0x0017;
    GradientScheme.backgroundInactive = 0xD71C;
    GradientScheme.backgroundDisabled = 0xC67A;
    GradientScheme.text = 0x0000;
    GradientScheme.textHighlight = 0x001F;
    GradientScheme.textHighlightText = 0x87FF;
    GradientScheme.textInactive = 0xD71C;
    GradientScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&ListWheelScheme, LE_COLOR_MODE_RGB_565);
    ListWheelScheme.base = 0xFFFF;
    ListWheelScheme.highlight = 0xFFFF;
    ListWheelScheme.highlightLight = 0xFFFF;
    ListWheelScheme.shadow = 0xFFFF;
    ListWheelScheme.shadowDark = 0x4208;
    ListWheelScheme.foreground = 0x0000;
    ListWheelScheme.foregroundInactive = 0x841F;
    ListWheelScheme.foregroundDisabled = 0x0000;
    ListWheelScheme.background = 0xFFFF;
    ListWheelScheme.backgroundInactive = 0xFFDF;
    ListWheelScheme.backgroundDisabled = 0x6B4D;
    ListWheelScheme.text = 0x0000;
    ListWheelScheme.textHighlight = 0x4208;
    ListWheelScheme.textHighlightText = 0xFFFF;
    ListWheelScheme.textInactive = 0x2104;
    ListWheelScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&MainMenuGradientScheme, LE_COLOR_MODE_RGB_565);
    MainMenuGradientScheme.base = 0xFFFF;
    MainMenuGradientScheme.highlight = 0xC67A;
    MainMenuGradientScheme.highlightLight = 0xFFFF;
    MainMenuGradientScheme.shadow = 0x8410;
    MainMenuGradientScheme.shadowDark = 0x4208;
    MainMenuGradientScheme.foreground = 0x8410;
    MainMenuGradientScheme.foregroundInactive = 0xD71C;
    MainMenuGradientScheme.foregroundDisabled = 0x8410;
    MainMenuGradientScheme.background = 0xFFFF;
    MainMenuGradientScheme.backgroundInactive = 0xD71C;
    MainMenuGradientScheme.backgroundDisabled = 0xC67A;
    MainMenuGradientScheme.text = 0x0000;
    MainMenuGradientScheme.textHighlight = 0x001F;
    MainMenuGradientScheme.textHighlightText = 0xFFFF;
    MainMenuGradientScheme.textInactive = 0xD71C;
    MainMenuGradientScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&RadioButtonsOnDarkScheme, LE_COLOR_MODE_RGB_565);
    RadioButtonsOnDarkScheme.base = 0xC67A;
    RadioButtonsOnDarkScheme.highlight = 0xC67A;
    RadioButtonsOnDarkScheme.highlightLight = 0xFFFF;
    RadioButtonsOnDarkScheme.shadow = 0x8410;
    RadioButtonsOnDarkScheme.shadowDark = 0x4208;
    RadioButtonsOnDarkScheme.foreground = 0x0000;
    RadioButtonsOnDarkScheme.foregroundInactive = 0xD71C;
    RadioButtonsOnDarkScheme.foregroundDisabled = 0x8410;
    RadioButtonsOnDarkScheme.background = 0xFFFF;
    RadioButtonsOnDarkScheme.backgroundInactive = 0xD71C;
    RadioButtonsOnDarkScheme.backgroundDisabled = 0xC67A;
    RadioButtonsOnDarkScheme.text = 0xFFFF;
    RadioButtonsOnDarkScheme.textHighlight = 0x001F;
    RadioButtonsOnDarkScheme.textHighlightText = 0xFFFF;
    RadioButtonsOnDarkScheme.textInactive = 0xD71C;
    RadioButtonsOnDarkScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&TouchTestScheme, LE_COLOR_MODE_RGB_565);
    TouchTestScheme.base = 0xFFFF;
    TouchTestScheme.highlight = 0xC67A;
    TouchTestScheme.highlightLight = 0xFFFF;
    TouchTestScheme.shadow = 0x8410;
    TouchTestScheme.shadowDark = 0x4208;
    TouchTestScheme.foreground = 0xF81F;
    TouchTestScheme.foregroundInactive = 0x07FF;
    TouchTestScheme.foregroundDisabled = 0x8410;
    TouchTestScheme.background = 0x0017;
    TouchTestScheme.backgroundInactive = 0xD71C;
    TouchTestScheme.backgroundDisabled = 0xC67A;
    TouchTestScheme.text = 0x07FF;
    TouchTestScheme.textHighlight = 0xF81F;
    TouchTestScheme.textHighlightText = 0xFFFF;
    TouchTestScheme.textInactive = 0xD71C;
    TouchTestScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&whiteScheme, LE_COLOR_MODE_RGB_565);
    whiteScheme.base = 0xFFFF;
    whiteScheme.highlight = 0xC67A;
    whiteScheme.highlightLight = 0xFFFF;
    whiteScheme.shadow = 0x8410;
    whiteScheme.shadowDark = 0x4208;
    whiteScheme.foreground = 0x0000;
    whiteScheme.foregroundInactive = 0xD71C;
    whiteScheme.foregroundDisabled = 0x8410;
    whiteScheme.background = 0xFFFF;
    whiteScheme.backgroundInactive = 0xD71C;
    whiteScheme.backgroundDisabled = 0xC67A;
    whiteScheme.text = 0x0000;
    whiteScheme.textHighlight = 0x001F;
    whiteScheme.textHighlightText = 0xFFFF;
    whiteScheme.textInactive = 0xD71C;
    whiteScheme.textDisabled = 0x8C92;

}
