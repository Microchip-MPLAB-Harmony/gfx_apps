/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Implementation File

  File Name:
    libaria_init.c

  Summary:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/
// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#include "gfx/libaria/libaria_init.h"

laScheme TextOrange;
laScheme MyScheme;
laScheme TempActualScheme;
laScheme Blue;
laScheme GrayScheme;
laScheme WhiteScheme;
laScheme TempRealFeelScheme;
laScheme TextGrey;
laScheme GradientScheme;
laScheme Red;
laScheme TextGreen;
laScheme TempDailyGraphScheme;
laScheme Yellow;
laScheme Purple;
laScheme TempHourlyGraphScheme;
laScheme TitleBarScheme;
laScheme Green;
laScheme TextWhite;
laImageWidget* ImageWidget1;
laImageWidget* ImageWidget2;
laWidget* PanelWidget3;
laImageWidget* ImageWidget3;
laImageWidget* ImageWidget4;


static void ScreenCreate_SplashScreen(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&TextOrange, GFX_COLOR_MODE_RGB_565);
    TextOrange.base = 0xFC00;
    TextOrange.highlight = 0xC67A;
    TextOrange.highlightLight = 0xFFFF;
    TextOrange.shadow = 0x8410;
    TextOrange.shadowDark = 0x4208;
    TextOrange.foreground = 0xEF7D;
    TextOrange.foregroundInactive = 0xFC00;
    TextOrange.foregroundDisabled = 0x8410;
    TextOrange.background = 0xFC00;
    TextOrange.backgroundInactive = 0xC67A;
    TextOrange.backgroundDisabled = 0xC67A;
    TextOrange.text = 0xFFFF;
    TextOrange.textHighlight = 0x1F;
    TextOrange.textHighlightText = 0xFFFF;
    TextOrange.textInactive = 0xC67A;
    TextOrange.textDisabled = 0xC67A;

    laScheme_Initialize(&MyScheme, GFX_COLOR_MODE_RGB_565);
    MyScheme.base = 0xC67A;
    MyScheme.highlight = 0xC67A;
    MyScheme.highlightLight = 0xFFFF;
    MyScheme.shadow = 0x8410;
    MyScheme.shadowDark = 0x4208;
    MyScheme.foreground = 0xD1F9;
    MyScheme.foregroundInactive = 0x8410;
    MyScheme.foregroundDisabled = 0x8410;
    MyScheme.background = 0xFFFF;
    MyScheme.backgroundInactive = 0xC67A;
    MyScheme.backgroundDisabled = 0xC67A;
    MyScheme.text = 0x0;
    MyScheme.textHighlight = 0x1F;
    MyScheme.textHighlightText = 0xFFFF;
    MyScheme.textInactive = 0xC67A;
    MyScheme.textDisabled = 0xC67A;

    laScheme_Initialize(&TempActualScheme, GFX_COLOR_MODE_RGB_565);
    TempActualScheme.base = 0xFC00;
    TempActualScheme.highlight = 0xC67A;
    TempActualScheme.highlightLight = 0xFFFF;
    TempActualScheme.shadow = 0x8410;
    TempActualScheme.shadowDark = 0x4208;
    TempActualScheme.foreground = 0xFC00;
    TempActualScheme.foregroundInactive = 0xD71C;
    TempActualScheme.foregroundDisabled = 0x8410;
    TempActualScheme.background = 0xFFFF;
    TempActualScheme.backgroundInactive = 0xD71C;
    TempActualScheme.backgroundDisabled = 0xC67A;
    TempActualScheme.text = 0x0;
    TempActualScheme.textHighlight = 0x1F;
    TempActualScheme.textHighlightText = 0xFFFF;
    TempActualScheme.textInactive = 0xD71C;
    TempActualScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&Blue, GFX_COLOR_MODE_RGB_565);
    Blue.base = 0x8;
    Blue.highlight = 0xC67A;
    Blue.highlightLight = 0xFFFF;
    Blue.shadow = 0x8410;
    Blue.shadowDark = 0x4208;
    Blue.foreground = 0x410;
    Blue.foregroundInactive = 0x8410;
    Blue.foregroundDisabled = 0x8410;
    Blue.background = 0xFFFF;
    Blue.backgroundInactive = 0xC67A;
    Blue.backgroundDisabled = 0xC67A;
    Blue.text = 0x0;
    Blue.textHighlight = 0x1F;
    Blue.textHighlightText = 0xFFFF;
    Blue.textInactive = 0xC67A;
    Blue.textDisabled = 0xC67A;

    laScheme_Initialize(&GrayScheme, GFX_COLOR_MODE_RGB_565);
    GrayScheme.base = 0xDEFB;
    GrayScheme.highlight = 0xDEFB;
    GrayScheme.highlightLight = 0xFFFF;
    GrayScheme.shadow = 0x8410;
    GrayScheme.shadowDark = 0x4208;
    GrayScheme.foreground = 0xDEFB;
    GrayScheme.foregroundInactive = 0x8410;
    GrayScheme.foregroundDisabled = 0x8410;
    GrayScheme.background = 0xDEFB;
    GrayScheme.backgroundInactive = 0xC67A;
    GrayScheme.backgroundDisabled = 0xC67A;
    GrayScheme.text = 0x736E;
    GrayScheme.textHighlight = 0x1F;
    GrayScheme.textHighlightText = 0xFFFF;
    GrayScheme.textInactive = 0xC67A;
    GrayScheme.textDisabled = 0xC67A;

    laScheme_Initialize(&WhiteScheme, GFX_COLOR_MODE_RGB_565);
    WhiteScheme.base = 0xFFFF;
    WhiteScheme.highlight = 0xC67A;
    WhiteScheme.highlightLight = 0xFFFF;
    WhiteScheme.shadow = 0x8410;
    WhiteScheme.shadowDark = 0x4208;
    WhiteScheme.foreground = 0x0;
    WhiteScheme.foregroundInactive = 0x8410;
    WhiteScheme.foregroundDisabled = 0x8410;
    WhiteScheme.background = 0xFFFF;
    WhiteScheme.backgroundInactive = 0xC67A;
    WhiteScheme.backgroundDisabled = 0xC67A;
    WhiteScheme.text = 0x736E;
    WhiteScheme.textHighlight = 0x1F;
    WhiteScheme.textHighlightText = 0xFFFF;
    WhiteScheme.textInactive = 0xC67A;
    WhiteScheme.textDisabled = 0xC67A;

    laScheme_Initialize(&TempRealFeelScheme, GFX_COLOR_MODE_RGB_565);
    TempRealFeelScheme.base = 0x410;
    TempRealFeelScheme.highlight = 0xC67A;
    TempRealFeelScheme.highlightLight = 0xFFFF;
    TempRealFeelScheme.shadow = 0x8410;
    TempRealFeelScheme.shadowDark = 0x4208;
    TempRealFeelScheme.foreground = 0x410;
    TempRealFeelScheme.foregroundInactive = 0xD71C;
    TempRealFeelScheme.foregroundDisabled = 0x8410;
    TempRealFeelScheme.background = 0xFFFF;
    TempRealFeelScheme.backgroundInactive = 0xD71C;
    TempRealFeelScheme.backgroundDisabled = 0xC67A;
    TempRealFeelScheme.text = 0x0;
    TempRealFeelScheme.textHighlight = 0x1F;
    TempRealFeelScheme.textHighlightText = 0xFFFF;
    TempRealFeelScheme.textInactive = 0xD71C;
    TempRealFeelScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&TextGrey, GFX_COLOR_MODE_RGB_565);
    TextGrey.base = 0xEF7D;
    TextGrey.highlight = 0xC67A;
    TextGrey.highlightLight = 0xFFFF;
    TextGrey.shadow = 0x8410;
    TextGrey.shadowDark = 0x4208;
    TextGrey.foreground = 0xEF7D;
    TextGrey.foregroundInactive = 0xDEFB;
    TextGrey.foregroundDisabled = 0x8410;
    TextGrey.background = 0xFFFF;
    TextGrey.backgroundInactive = 0xC67A;
    TextGrey.backgroundDisabled = 0xC67A;
    TextGrey.text = 0x4208;
    TextGrey.textHighlight = 0x1F;
    TextGrey.textHighlightText = 0xFFFF;
    TextGrey.textInactive = 0xC67A;
    TextGrey.textDisabled = 0xC67A;

    laScheme_Initialize(&GradientScheme, GFX_COLOR_MODE_RGB_565);
    GradientScheme.base = 0xC67A;
    GradientScheme.highlight = 0xC67A;
    GradientScheme.highlightLight = 0xFFFF;
    GradientScheme.shadow = 0x8410;
    GradientScheme.shadowDark = 0x4208;
    GradientScheme.foreground = 0x0;
    GradientScheme.foregroundInactive = 0x8410;
    GradientScheme.foregroundDisabled = 0x8410;
    GradientScheme.background = 0xFFFF;
    GradientScheme.backgroundInactive = 0xC67A;
    GradientScheme.backgroundDisabled = 0xC67A;
    GradientScheme.text = 0x0;
    GradientScheme.textHighlight = 0x1F;
    GradientScheme.textHighlightText = 0xFFFF;
    GradientScheme.textInactive = 0xC67A;
    GradientScheme.textDisabled = 0xC67A;

    laScheme_Initialize(&Red, GFX_COLOR_MODE_RGB_565);
    Red.base = 0x331F;
    Red.highlight = 0xC67A;
    Red.highlightLight = 0xFFFF;
    Red.shadow = 0x8410;
    Red.shadowDark = 0x4208;
    Red.foreground = 0x0;
    Red.foregroundInactive = 0x8410;
    Red.foregroundDisabled = 0x8410;
    Red.background = 0xFFFF;
    Red.backgroundInactive = 0xC67A;
    Red.backgroundDisabled = 0xC67A;
    Red.text = 0x0;
    Red.textHighlight = 0x1F;
    Red.textHighlightText = 0xFFFF;
    Red.textInactive = 0xC67A;
    Red.textDisabled = 0xC67A;

    laScheme_Initialize(&TextGreen, GFX_COLOR_MODE_RGB_565);
    TextGreen.base = 0x410;
    TextGreen.highlight = 0xC67A;
    TextGreen.highlightLight = 0xFFFF;
    TextGreen.shadow = 0x8410;
    TextGreen.shadowDark = 0x4208;
    TextGreen.foreground = 0xEF7D;
    TextGreen.foregroundInactive = 0x410;
    TextGreen.foregroundDisabled = 0x8410;
    TextGreen.background = 0x410;
    TextGreen.backgroundInactive = 0xC67A;
    TextGreen.backgroundDisabled = 0xC67A;
    TextGreen.text = 0xFFFF;
    TextGreen.textHighlight = 0x1F;
    TextGreen.textHighlightText = 0xFFFF;
    TextGreen.textInactive = 0xC67A;
    TextGreen.textDisabled = 0xC67A;

    laScheme_Initialize(&TempDailyGraphScheme, GFX_COLOR_MODE_RGB_565);
    TempDailyGraphScheme.base = 0xDEFB;
    TempDailyGraphScheme.highlight = 0xC67A;
    TempDailyGraphScheme.highlightLight = 0xFFFF;
    TempDailyGraphScheme.shadow = 0x8410;
    TempDailyGraphScheme.shadowDark = 0x4208;
    TempDailyGraphScheme.foreground = 0xFFFF;
    TempDailyGraphScheme.foregroundInactive = 0xD71C;
    TempDailyGraphScheme.foregroundDisabled = 0x8410;
    TempDailyGraphScheme.background = 0xFFFF;
    TempDailyGraphScheme.backgroundInactive = 0xD71C;
    TempDailyGraphScheme.backgroundDisabled = 0xC67A;
    TempDailyGraphScheme.text = 0xDEFB;
    TempDailyGraphScheme.textHighlight = 0x1F;
    TempDailyGraphScheme.textHighlightText = 0xFFFF;
    TempDailyGraphScheme.textInactive = 0xD71C;
    TempDailyGraphScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&Yellow, GFX_COLOR_MODE_RGB_565);
    Yellow.base = 0xFFE0;
    Yellow.highlight = 0xC67A;
    Yellow.highlightLight = 0xFFFF;
    Yellow.shadow = 0x8410;
    Yellow.shadowDark = 0x4208;
    Yellow.foreground = 0x0;
    Yellow.foregroundInactive = 0x8410;
    Yellow.foregroundDisabled = 0x8410;
    Yellow.background = 0xFFFF;
    Yellow.backgroundInactive = 0xC67A;
    Yellow.backgroundDisabled = 0xC67A;
    Yellow.text = 0x0;
    Yellow.textHighlight = 0x1F;
    Yellow.textHighlightText = 0xFFFF;
    Yellow.textInactive = 0xC67A;
    Yellow.textDisabled = 0xC67A;

    laScheme_Initialize(&Purple, GFX_COLOR_MODE_RGB_565);
    Purple.base = 0xC67A;
    Purple.highlight = 0xC67A;
    Purple.highlightLight = 0xFFFF;
    Purple.shadow = 0x8410;
    Purple.shadowDark = 0x4208;
    Purple.foreground = 0xF800;
    Purple.foregroundInactive = 0x1F;
    Purple.foregroundDisabled = 0x8410;
    Purple.background = 0x7E0;
    Purple.backgroundInactive = 0xFFE0;
    Purple.backgroundDisabled = 0xC67A;
    Purple.text = 0x0;
    Purple.textHighlight = 0x1F;
    Purple.textHighlightText = 0xFFFF;
    Purple.textInactive = 0xC67A;
    Purple.textDisabled = 0xC67A;

    laScheme_Initialize(&TempHourlyGraphScheme, GFX_COLOR_MODE_RGB_565);
    TempHourlyGraphScheme.base = 0xDEFB;
    TempHourlyGraphScheme.highlight = 0xC67A;
    TempHourlyGraphScheme.highlightLight = 0xFFFF;
    TempHourlyGraphScheme.shadow = 0x8410;
    TempHourlyGraphScheme.shadowDark = 0x4208;
    TempHourlyGraphScheme.foreground = 0xDEFB;
    TempHourlyGraphScheme.foregroundInactive = 0xD71C;
    TempHourlyGraphScheme.foregroundDisabled = 0x8410;
    TempHourlyGraphScheme.background = 0xFFFF;
    TempHourlyGraphScheme.backgroundInactive = 0xD71C;
    TempHourlyGraphScheme.backgroundDisabled = 0xC67A;
    TempHourlyGraphScheme.text = 0xDEFB;
    TempHourlyGraphScheme.textHighlight = 0x1F;
    TempHourlyGraphScheme.textHighlightText = 0xFFFF;
    TempHourlyGraphScheme.textInactive = 0xD71C;
    TempHourlyGraphScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&TitleBarScheme, GFX_COLOR_MODE_RGB_565);
    TitleBarScheme.base = 0xEFBF;
    TitleBarScheme.highlight = 0xC67A;
    TitleBarScheme.highlightLight = 0xFFFF;
    TitleBarScheme.shadow = 0x8410;
    TitleBarScheme.shadowDark = 0x4208;
    TitleBarScheme.foreground = 0x0;
    TitleBarScheme.foregroundInactive = 0x8410;
    TitleBarScheme.foregroundDisabled = 0x8410;
    TitleBarScheme.background = 0xFFFF;
    TitleBarScheme.backgroundInactive = 0xC67A;
    TitleBarScheme.backgroundDisabled = 0xC67A;
    TitleBarScheme.text = 0x0;
    TitleBarScheme.textHighlight = 0x1F;
    TitleBarScheme.textHighlightText = 0xFFFF;
    TitleBarScheme.textInactive = 0xC67A;
    TitleBarScheme.textDisabled = 0xC67A;

    laScheme_Initialize(&Green, GFX_COLOR_MODE_RGB_565);
    Green.base = 0xFDF7;
    Green.highlight = 0xC67A;
    Green.highlightLight = 0xFFFF;
    Green.shadow = 0x8410;
    Green.shadowDark = 0x4208;
    Green.foreground = 0x0;
    Green.foregroundInactive = 0x8410;
    Green.foregroundDisabled = 0x8410;
    Green.background = 0xFFFF;
    Green.backgroundInactive = 0xC67A;
    Green.backgroundDisabled = 0xC67A;
    Green.text = 0x54B4;
    Green.textHighlight = 0x1F;
    Green.textHighlightText = 0xFFFF;
    Green.textInactive = 0xC67A;
    Green.textDisabled = 0xC67A;

    laScheme_Initialize(&TextWhite, GFX_COLOR_MODE_RGB_565);
    TextWhite.base = 0xC67A;
    TextWhite.highlight = 0xC67A;
    TextWhite.highlightLight = 0xFFFF;
    TextWhite.shadow = 0x8410;
    TextWhite.shadowDark = 0x4208;
    TextWhite.foreground = 0x0;
    TextWhite.foregroundInactive = 0x8410;
    TextWhite.foregroundDisabled = 0x8410;
    TextWhite.background = 0xFFFF;
    TextWhite.backgroundInactive = 0xC67A;
    TextWhite.backgroundDisabled = 0xC67A;
    TextWhite.text = 0xFFFF;
    TextWhite.textHighlight = 0x1F;
    TextWhite.textHighlightText = 0xFFFF;
    TextWhite.textInactive = 0xC67A;
    TextWhite.textDisabled = 0xC67A;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    laContext_SetStringTable(&stringTable);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_SplashScreen);
    laContext_AddScreen(screen);

    laContext_SetActiveScreen(0);

	return 0;
}

static void ScreenCreate_SplashScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &WhiteScheme);
    laLayer_SetBufferCount(layer0, 2);
    laWidget_SetOptimizationFlags((laWidget*)layer0, LA_WIDGET_OPT_DRAW_ONCE);
    laLayer_SetAlphaEnable(layer0, LA_TRUE);
    laLayer_SetAlphaAmount(layer0, 0xFF);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget1 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget1, 124, 69);
    laWidget_SetSize((laWidget*)ImageWidget1, 240, 139);
    laWidget_SetScheme((laWidget*)ImageWidget1, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget1, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget1, &PIC32Logo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget1);

    ImageWidget2 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget2, 124, 69);
    laWidget_SetSize((laWidget*)ImageWidget2, 240, 139);
    laWidget_SetVisible((laWidget*)ImageWidget2, LA_FALSE);
    laWidget_SetScheme((laWidget*)ImageWidget2, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget2, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget2, &HarmonyLogo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget2);

    PanelWidget3 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget3, 0, 215);
    laWidget_SetSize((laWidget*)PanelWidget3, 480, 65);
    laWidget_SetOptimizationFlags((laWidget*)PanelWidget3, LA_WIDGET_OPT_DRAW_ONCE);
    laWidget_SetScheme((laWidget*)PanelWidget3, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget3, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget3, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget3);

    ImageWidget3 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget3, 272, 0);
    laWidget_SetSize((laWidget*)ImageWidget3, 480, 65);
    laWidget_SetBackgroundType((laWidget*)ImageWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget3, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget3, &Bar);
    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)ImageWidget3);

    ImageWidget4 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget4, 10, 15);
    laWidget_SetSize((laWidget*)ImageWidget4, 144, 39);
    laWidget_SetVisible((laWidget*)ImageWidget4, LA_FALSE);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget4, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ImageWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget4, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget4, &MicrochipLogo);
    laWidget_AddChild((laWidget*)ImageWidget3, (laWidget*)ImageWidget4);

}



