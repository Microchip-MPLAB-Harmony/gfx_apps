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

leScheme BlackBackground;
leScheme BlackTextScheme;
leScheme Button1Scheme;
leScheme Button2Scheme;
leScheme Button3Scheme;
leScheme Button4Scheme;
leScheme DarkGrayScheme;
leScheme InactiveBackgroundScheme;
leScheme LabelBannerScheme;
leScheme ListWheelScheme;
leScheme ListWheelScheme2;
leScheme OffWhiteTextScheme;
leScheme ProgressBarRemainScheme;
leScheme ProgressBarScheme;
leScheme RightPanelScheme;
leScheme SquareButtonScheme;
leScheme UnselectedItemTextScheme;
leScheme VeryDarkGrayScheme;
leScheme WhiteBackgroundScheme;
leScheme WhiteTextScheme;

void legato_initialize_schemes(void)
{
    leScheme_Initialize(&BlackBackground, LE_COLOR_MODE_RGB_565);
    BlackBackground.base = 0x0000;
    BlackBackground.highlight = 0xC67A;
    BlackBackground.highlightLight = 0xFFFF;
    BlackBackground.shadow = 0x8410;
    BlackBackground.shadowDark = 0x4208;
    BlackBackground.foreground = 0x0000;
    BlackBackground.foregroundInactive = 0xD71C;
    BlackBackground.foregroundDisabled = 0x8410;
    BlackBackground.background = 0xFFFF;
    BlackBackground.backgroundInactive = 0xD71C;
    BlackBackground.backgroundDisabled = 0xC67A;
    BlackBackground.text = 0xFFFF;
    BlackBackground.textHighlight = 0x001F;
    BlackBackground.textHighlightText = 0xFFFF;
    BlackBackground.textInactive = 0xD71C;
    BlackBackground.textDisabled = 0x8C92;

    leScheme_Initialize(&BlackTextScheme, LE_COLOR_MODE_RGB_565);
    BlackTextScheme.base = 0xBDF7;
    BlackTextScheme.highlight = 0xC67A;
    BlackTextScheme.highlightLight = 0xFFFF;
    BlackTextScheme.shadow = 0x8410;
    BlackTextScheme.shadowDark = 0x4208;
    BlackTextScheme.foreground = 0x0000;
    BlackTextScheme.foregroundInactive = 0xD71C;
    BlackTextScheme.foregroundDisabled = 0x8410;
    BlackTextScheme.background = 0xFFFF;
    BlackTextScheme.backgroundInactive = 0xD71C;
    BlackTextScheme.backgroundDisabled = 0xC67A;
    BlackTextScheme.text = 0x0000;
    BlackTextScheme.textHighlight = 0x001F;
    BlackTextScheme.textHighlightText = 0xFFFF;
    BlackTextScheme.textInactive = 0xD71C;
    BlackTextScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&Button1Scheme, LE_COLOR_MODE_RGB_565);
    Button1Scheme.base = 0x0400;
    Button1Scheme.highlight = 0xC67A;
    Button1Scheme.highlightLight = 0xFFFF;
    Button1Scheme.shadow = 0x8410;
    Button1Scheme.shadowDark = 0x4208;
    Button1Scheme.foreground = 0x0000;
    Button1Scheme.foregroundInactive = 0xD71C;
    Button1Scheme.foregroundDisabled = 0x8410;
    Button1Scheme.background = 0xFFFF;
    Button1Scheme.backgroundInactive = 0xD71C;
    Button1Scheme.backgroundDisabled = 0xC67A;
    Button1Scheme.text = 0x0000;
    Button1Scheme.textHighlight = 0x001F;
    Button1Scheme.textHighlightText = 0xFFFF;
    Button1Scheme.textInactive = 0xD71C;
    Button1Scheme.textDisabled = 0x8C92;

    leScheme_Initialize(&Button2Scheme, LE_COLOR_MODE_RGB_565);
    Button2Scheme.base = 0x0410;
    Button2Scheme.highlight = 0xC67A;
    Button2Scheme.highlightLight = 0xFFFF;
    Button2Scheme.shadow = 0x8410;
    Button2Scheme.shadowDark = 0x4208;
    Button2Scheme.foreground = 0x0000;
    Button2Scheme.foregroundInactive = 0xD71C;
    Button2Scheme.foregroundDisabled = 0x8410;
    Button2Scheme.background = 0xFFFF;
    Button2Scheme.backgroundInactive = 0xD71C;
    Button2Scheme.backgroundDisabled = 0xC67A;
    Button2Scheme.text = 0x0000;
    Button2Scheme.textHighlight = 0x001F;
    Button2Scheme.textHighlightText = 0xFFFF;
    Button2Scheme.textInactive = 0xD71C;
    Button2Scheme.textDisabled = 0x8C92;

    leScheme_Initialize(&Button3Scheme, LE_COLOR_MODE_RGB_565);
    Button3Scheme.base = 0x8000;
    Button3Scheme.highlight = 0xC67A;
    Button3Scheme.highlightLight = 0xFFFF;
    Button3Scheme.shadow = 0x8410;
    Button3Scheme.shadowDark = 0x4208;
    Button3Scheme.foreground = 0x0000;
    Button3Scheme.foregroundInactive = 0xD71C;
    Button3Scheme.foregroundDisabled = 0x8410;
    Button3Scheme.background = 0xFFFF;
    Button3Scheme.backgroundInactive = 0xD71C;
    Button3Scheme.backgroundDisabled = 0xC67A;
    Button3Scheme.text = 0x0000;
    Button3Scheme.textHighlight = 0x001F;
    Button3Scheme.textHighlightText = 0xFFFF;
    Button3Scheme.textInactive = 0xD71C;
    Button3Scheme.textDisabled = 0x8C92;

    leScheme_Initialize(&Button4Scheme, LE_COLOR_MODE_RGB_565);
    Button4Scheme.base = 0x8010;
    Button4Scheme.highlight = 0xC67A;
    Button4Scheme.highlightLight = 0xFFFF;
    Button4Scheme.shadow = 0x8410;
    Button4Scheme.shadowDark = 0x4208;
    Button4Scheme.foreground = 0x0000;
    Button4Scheme.foregroundInactive = 0xD71C;
    Button4Scheme.foregroundDisabled = 0x8410;
    Button4Scheme.background = 0xFFFF;
    Button4Scheme.backgroundInactive = 0xD71C;
    Button4Scheme.backgroundDisabled = 0xC67A;
    Button4Scheme.text = 0x0000;
    Button4Scheme.textHighlight = 0x001F;
    Button4Scheme.textHighlightText = 0xFFFF;
    Button4Scheme.textInactive = 0xD71C;
    Button4Scheme.textDisabled = 0x8C92;

    leScheme_Initialize(&DarkGrayScheme, LE_COLOR_MODE_RGB_565);
    DarkGrayScheme.base = 0x4208;
    DarkGrayScheme.highlight = 0xC67A;
    DarkGrayScheme.highlightLight = 0xFFFF;
    DarkGrayScheme.shadow = 0x8410;
    DarkGrayScheme.shadowDark = 0x4208;
    DarkGrayScheme.foreground = 0x0000;
    DarkGrayScheme.foregroundInactive = 0xD71C;
    DarkGrayScheme.foregroundDisabled = 0x8410;
    DarkGrayScheme.background = 0xFFFF;
    DarkGrayScheme.backgroundInactive = 0xD71C;
    DarkGrayScheme.backgroundDisabled = 0xC67A;
    DarkGrayScheme.text = 0x0000;
    DarkGrayScheme.textHighlight = 0x001F;
    DarkGrayScheme.textHighlightText = 0xFFFF;
    DarkGrayScheme.textInactive = 0xD71C;
    DarkGrayScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&InactiveBackgroundScheme, LE_COLOR_MODE_RGB_565);
    InactiveBackgroundScheme.base = 0x4208;
    InactiveBackgroundScheme.highlight = 0xC67A;
    InactiveBackgroundScheme.highlightLight = 0xFFFF;
    InactiveBackgroundScheme.shadow = 0x8410;
    InactiveBackgroundScheme.shadowDark = 0x4208;
    InactiveBackgroundScheme.foreground = 0x0000;
    InactiveBackgroundScheme.foregroundInactive = 0xD71C;
    InactiveBackgroundScheme.foregroundDisabled = 0x8410;
    InactiveBackgroundScheme.background = 0xFFFF;
    InactiveBackgroundScheme.backgroundInactive = 0xD71C;
    InactiveBackgroundScheme.backgroundDisabled = 0xC67A;
    InactiveBackgroundScheme.text = 0x0000;
    InactiveBackgroundScheme.textHighlight = 0x001F;
    InactiveBackgroundScheme.textHighlightText = 0xFFFF;
    InactiveBackgroundScheme.textInactive = 0xD71C;
    InactiveBackgroundScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&LabelBannerScheme, LE_COLOR_MODE_RGB_565);
    LabelBannerScheme.base = 0xFDF0;
    LabelBannerScheme.highlight = 0xC67A;
    LabelBannerScheme.highlightLight = 0xFFFF;
    LabelBannerScheme.shadow = 0x8410;
    LabelBannerScheme.shadowDark = 0x4208;
    LabelBannerScheme.foreground = 0x0000;
    LabelBannerScheme.foregroundInactive = 0xD71C;
    LabelBannerScheme.foregroundDisabled = 0x8410;
    LabelBannerScheme.background = 0xFFFF;
    LabelBannerScheme.backgroundInactive = 0xD71C;
    LabelBannerScheme.backgroundDisabled = 0xC67A;
    LabelBannerScheme.text = 0x0000;
    LabelBannerScheme.textHighlight = 0x001F;
    LabelBannerScheme.textHighlightText = 0xFFFF;
    LabelBannerScheme.textInactive = 0xD71C;
    LabelBannerScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&ListWheelScheme, LE_COLOR_MODE_RGB_565);
    ListWheelScheme.base = 0x18E3;
    ListWheelScheme.highlight = 0xC67A;
    ListWheelScheme.highlightLight = 0xFFFF;
    ListWheelScheme.shadow = 0x4208;
    ListWheelScheme.shadowDark = 0x4208;
    ListWheelScheme.foreground = 0xBDF7;
    ListWheelScheme.foregroundInactive = 0x18E3;
    ListWheelScheme.foregroundDisabled = 0x18E3;
    ListWheelScheme.background = 0x0000;
    ListWheelScheme.backgroundInactive = 0x0000;
    ListWheelScheme.backgroundDisabled = 0x0000;
    ListWheelScheme.text = 0x4208;
    ListWheelScheme.textHighlight = 0x001F;
    ListWheelScheme.textHighlightText = 0xFFFF;
    ListWheelScheme.textInactive = 0xD71C;
    ListWheelScheme.textDisabled = 0x4208;

    leScheme_Initialize(&ListWheelScheme2, LE_COLOR_MODE_RGB_565);
    ListWheelScheme2.base = 0xC67A;
    ListWheelScheme2.highlight = 0xC67A;
    ListWheelScheme2.highlightLight = 0xFFFF;
    ListWheelScheme2.shadow = 0xFFFF;
    ListWheelScheme2.shadowDark = 0xFFFF;
    ListWheelScheme2.foreground = 0xFFFF;
    ListWheelScheme2.foregroundInactive = 0x58C4;
    ListWheelScheme2.foregroundDisabled = 0x4208;
    ListWheelScheme2.background = 0xFFFF;
    ListWheelScheme2.backgroundInactive = 0xD71C;
    ListWheelScheme2.backgroundDisabled = 0xC67A;
    ListWheelScheme2.text = 0x4208;
    ListWheelScheme2.textHighlight = 0x001F;
    ListWheelScheme2.textHighlightText = 0xFFF7;
    ListWheelScheme2.textInactive = 0xD71C;
    ListWheelScheme2.textDisabled = 0x4208;

    leScheme_Initialize(&OffWhiteTextScheme, LE_COLOR_MODE_RGB_565);
    OffWhiteTextScheme.base = 0x4208;
    OffWhiteTextScheme.highlight = 0xC67A;
    OffWhiteTextScheme.highlightLight = 0xFFFF;
    OffWhiteTextScheme.shadow = 0x8410;
    OffWhiteTextScheme.shadowDark = 0x4208;
    OffWhiteTextScheme.foreground = 0x0000;
    OffWhiteTextScheme.foregroundInactive = 0xD71C;
    OffWhiteTextScheme.foregroundDisabled = 0x8410;
    OffWhiteTextScheme.background = 0xFFFF;
    OffWhiteTextScheme.backgroundInactive = 0xD71C;
    OffWhiteTextScheme.backgroundDisabled = 0xC67A;
    OffWhiteTextScheme.text = 0x4208;
    OffWhiteTextScheme.textHighlight = 0x001F;
    OffWhiteTextScheme.textHighlightText = 0xFFFF;
    OffWhiteTextScheme.textInactive = 0xD71C;
    OffWhiteTextScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&ProgressBarRemainScheme, LE_COLOR_MODE_RGB_565);
    ProgressBarRemainScheme.base = 0x8410;
    ProgressBarRemainScheme.highlight = 0xC67A;
    ProgressBarRemainScheme.highlightLight = 0xFFFF;
    ProgressBarRemainScheme.shadow = 0x8410;
    ProgressBarRemainScheme.shadowDark = 0x4208;
    ProgressBarRemainScheme.foreground = 0x0000;
    ProgressBarRemainScheme.foregroundInactive = 0xD71C;
    ProgressBarRemainScheme.foregroundDisabled = 0x8410;
    ProgressBarRemainScheme.background = 0xFFFF;
    ProgressBarRemainScheme.backgroundInactive = 0xD71C;
    ProgressBarRemainScheme.backgroundDisabled = 0xC67A;
    ProgressBarRemainScheme.text = 0x0000;
    ProgressBarRemainScheme.textHighlight = 0x001F;
    ProgressBarRemainScheme.textHighlightText = 0xFFFF;
    ProgressBarRemainScheme.textInactive = 0xD71C;
    ProgressBarRemainScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&ProgressBarScheme, LE_COLOR_MODE_RGB_565);
    ProgressBarScheme.base = 0x8410;
    ProgressBarScheme.highlight = 0xC67A;
    ProgressBarScheme.highlightLight = 0xFFFF;
    ProgressBarScheme.shadow = 0x8410;
    ProgressBarScheme.shadowDark = 0x4208;
    ProgressBarScheme.foreground = 0x0000;
    ProgressBarScheme.foregroundInactive = 0xD71C;
    ProgressBarScheme.foregroundDisabled = 0x8410;
    ProgressBarScheme.background = 0x8000;
    ProgressBarScheme.backgroundInactive = 0xD71C;
    ProgressBarScheme.backgroundDisabled = 0xC67A;
    ProgressBarScheme.text = 0x0000;
    ProgressBarScheme.textHighlight = 0x8000;
    ProgressBarScheme.textHighlightText = 0xFFFF;
    ProgressBarScheme.textInactive = 0xD71C;
    ProgressBarScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&RightPanelScheme, LE_COLOR_MODE_RGB_565);
    RightPanelScheme.base = 0x0841;
    RightPanelScheme.highlight = 0xC67A;
    RightPanelScheme.highlightLight = 0xFFFF;
    RightPanelScheme.shadow = 0x8410;
    RightPanelScheme.shadowDark = 0x4208;
    RightPanelScheme.foreground = 0x0000;
    RightPanelScheme.foregroundInactive = 0xD71C;
    RightPanelScheme.foregroundDisabled = 0x8410;
    RightPanelScheme.background = 0x000B;
    RightPanelScheme.backgroundInactive = 0xD71C;
    RightPanelScheme.backgroundDisabled = 0xC67A;
    RightPanelScheme.text = 0x0000;
    RightPanelScheme.textHighlight = 0x001F;
    RightPanelScheme.textHighlightText = 0xFFFF;
    RightPanelScheme.textInactive = 0xD71C;
    RightPanelScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&SquareButtonScheme, LE_COLOR_MODE_RGB_565);
    SquareButtonScheme.base = 0xC67A;
    SquareButtonScheme.highlight = 0xC67A;
    SquareButtonScheme.highlightLight = 0xFFFF;
    SquareButtonScheme.shadow = 0xFFFF;
    SquareButtonScheme.shadowDark = 0xFFFF;
    SquareButtonScheme.foreground = 0x0000;
    SquareButtonScheme.foregroundInactive = 0xD71C;
    SquareButtonScheme.foregroundDisabled = 0x8410;
    SquareButtonScheme.background = 0xFFFF;
    SquareButtonScheme.backgroundInactive = 0xD71C;
    SquareButtonScheme.backgroundDisabled = 0xC67A;
    SquareButtonScheme.text = 0xFFFF;
    SquareButtonScheme.textHighlight = 0x001F;
    SquareButtonScheme.textHighlightText = 0xFFFF;
    SquareButtonScheme.textInactive = 0xD71C;
    SquareButtonScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&UnselectedItemTextScheme, LE_COLOR_MODE_RGB_565);
    UnselectedItemTextScheme.base = 0xC67A;
    UnselectedItemTextScheme.highlight = 0xC67A;
    UnselectedItemTextScheme.highlightLight = 0xFFFF;
    UnselectedItemTextScheme.shadow = 0x8410;
    UnselectedItemTextScheme.shadowDark = 0x4208;
    UnselectedItemTextScheme.foreground = 0x0000;
    UnselectedItemTextScheme.foregroundInactive = 0xD71C;
    UnselectedItemTextScheme.foregroundDisabled = 0x8410;
    UnselectedItemTextScheme.background = 0xFFFF;
    UnselectedItemTextScheme.backgroundInactive = 0xD71C;
    UnselectedItemTextScheme.backgroundDisabled = 0xC67A;
    UnselectedItemTextScheme.text = 0x4208;
    UnselectedItemTextScheme.textHighlight = 0x001F;
    UnselectedItemTextScheme.textHighlightText = 0xFFFF;
    UnselectedItemTextScheme.textInactive = 0xD71C;
    UnselectedItemTextScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&VeryDarkGrayScheme, LE_COLOR_MODE_RGB_565);
    VeryDarkGrayScheme.base = 0x2945;
    VeryDarkGrayScheme.highlight = 0xC67A;
    VeryDarkGrayScheme.highlightLight = 0xFFFF;
    VeryDarkGrayScheme.shadow = 0x8410;
    VeryDarkGrayScheme.shadowDark = 0x4208;
    VeryDarkGrayScheme.foreground = 0x0000;
    VeryDarkGrayScheme.foregroundInactive = 0xD71C;
    VeryDarkGrayScheme.foregroundDisabled = 0x8410;
    VeryDarkGrayScheme.background = 0xFFFF;
    VeryDarkGrayScheme.backgroundInactive = 0xD71C;
    VeryDarkGrayScheme.backgroundDisabled = 0xC67A;
    VeryDarkGrayScheme.text = 0x0000;
    VeryDarkGrayScheme.textHighlight = 0x001F;
    VeryDarkGrayScheme.textHighlightText = 0xFFFF;
    VeryDarkGrayScheme.textInactive = 0xD71C;
    VeryDarkGrayScheme.textDisabled = 0x8C92;

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

    leScheme_Initialize(&WhiteTextScheme, LE_COLOR_MODE_RGB_565);
    WhiteTextScheme.base = 0x0000;
    WhiteTextScheme.highlight = 0xC67A;
    WhiteTextScheme.highlightLight = 0xFFFF;
    WhiteTextScheme.shadow = 0x8410;
    WhiteTextScheme.shadowDark = 0x4208;
    WhiteTextScheme.foreground = 0x0000;
    WhiteTextScheme.foregroundInactive = 0xD71C;
    WhiteTextScheme.foregroundDisabled = 0x8410;
    WhiteTextScheme.background = 0xFFFF;
    WhiteTextScheme.backgroundInactive = 0xD71C;
    WhiteTextScheme.backgroundDisabled = 0xC67A;
    WhiteTextScheme.text = 0xFFFF;
    WhiteTextScheme.textHighlight = 0x001F;
    WhiteTextScheme.textHighlightText = 0xFFFF;
    WhiteTextScheme.textInactive = 0xD71C;
    WhiteTextScheme.textDisabled = 0x8C92;

}
