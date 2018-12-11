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
laScheme defaultPaletteScheme;
laImageWidget* ImageWidget1;
laImageWidget* ImageWidget2;
laWidget* PanelWidget3;
laImageWidget* ImageWidget3;
laImageWidget* ImageWidget4;
laWidget* PanelItem0;
laButtonWidget* ButtonItem0;
laLabelWidget* LabelItem0;
laWidget* PanelItem1;
laButtonWidget* ButtonItem1;
laLabelWidget* LabelItem1;
laWidget* PanelItem2;
laButtonWidget* ButtonItem2;
laLabelWidget* LabelItem2;
laWidget* PanelItem3;
laButtonWidget* ButtonItem3;
laLabelWidget* LabelItem3;
laWidget* PanelItem4;
laButtonWidget* ButtonItem4;
laLabelWidget* LabelItem4;
laWidget* PanelItem5;
laButtonWidget* ButtonItem5;
laLabelWidget* LabelItem5;
laButtonWidget* ButtonUp;
laButtonWidget* ButtonDown;
laButtonWidget* ButtonInfo;
laButtonWidget* ButtonLanguage_Main;
laImageSequenceWidget* ImageSequence_LoadingIcon;
laLabelWidget* LabelLoading;


static void ScreenCreate_SplashScreen(laScreen* screen);
static void ScreenCreate_MainScreen(laScreen* screen);
static void ScreenCreate_LoadScreen(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&TextOrange, GFX_COLOR_MODE_RGB_565);
    TextOrange.base = 0xCF;
    TextOrange.highlight = 0xFC;
    TextOrange.highlightLight = 0xF;
    TextOrange.shadow = 0x8;
    TextOrange.shadowDark = 0xED;
    TextOrange.foreground = 0xFF;
    TextOrange.foregroundInactive = 0xCF;
    TextOrange.foregroundDisabled = 0x8;
    TextOrange.background = 0xCF;
    TextOrange.backgroundInactive = 0xFC;
    TextOrange.backgroundDisabled = 0xFC;
    TextOrange.text = 0xF;
    TextOrange.textHighlight = 0xC;
    TextOrange.textHighlightText = 0xF;
    TextOrange.textInactive = 0xFC;
    TextOrange.textDisabled = 0xFC;

    laScheme_Initialize(&MyScheme, GFX_COLOR_MODE_RGB_565);
    MyScheme.base = 0xFC;
    MyScheme.highlight = 0xFC;
    MyScheme.highlightLight = 0xF;
    MyScheme.shadow = 0x8;
    MyScheme.shadowDark = 0xED;
    MyScheme.foreground = 0xA9;
    MyScheme.foregroundInactive = 0x8;
    MyScheme.foregroundDisabled = 0x8;
    MyScheme.background = 0xF;
    MyScheme.backgroundInactive = 0xFC;
    MyScheme.backgroundDisabled = 0xFC;
    MyScheme.text = 0x0;
    MyScheme.textHighlight = 0xC;
    MyScheme.textHighlightText = 0xF;
    MyScheme.textInactive = 0xFC;
    MyScheme.textDisabled = 0xFC;

    laScheme_Initialize(&TempActualScheme, GFX_COLOR_MODE_RGB_565);
    TempActualScheme.base = 0xCF;
    TempActualScheme.highlight = 0xFC;
    TempActualScheme.highlightLight = 0xF;
    TempActualScheme.shadow = 0x8;
    TempActualScheme.shadowDark = 0xED;
    TempActualScheme.foreground = 0xCF;
    TempActualScheme.foregroundInactive = 0xFE;
    TempActualScheme.foregroundDisabled = 0x8;
    TempActualScheme.background = 0xF;
    TempActualScheme.backgroundInactive = 0xFE;
    TempActualScheme.backgroundDisabled = 0xFC;
    TempActualScheme.text = 0x0;
    TempActualScheme.textHighlight = 0xC;
    TempActualScheme.textHighlightText = 0xF;
    TempActualScheme.textInactive = 0xFE;
    TempActualScheme.textDisabled = 0xF6;

    laScheme_Initialize(&Blue, GFX_COLOR_MODE_RGB_565);
    Blue.base = 0x10;
    Blue.highlight = 0xFC;
    Blue.highlightLight = 0xF;
    Blue.shadow = 0x8;
    Blue.shadowDark = 0xED;
    Blue.foreground = 0x6;
    Blue.foregroundInactive = 0x8;
    Blue.foregroundDisabled = 0x8;
    Blue.background = 0xF;
    Blue.backgroundInactive = 0xFC;
    Blue.backgroundDisabled = 0xFC;
    Blue.text = 0x0;
    Blue.textHighlight = 0xC;
    Blue.textHighlightText = 0xF;
    Blue.textInactive = 0xFC;
    Blue.textDisabled = 0xFC;

    laScheme_Initialize(&GrayScheme, GFX_COLOR_MODE_RGB_565);
    GrayScheme.base = 0xFD;
    GrayScheme.highlight = 0xFD;
    GrayScheme.highlightLight = 0xF;
    GrayScheme.shadow = 0x8;
    GrayScheme.shadowDark = 0xED;
    GrayScheme.foreground = 0xFD;
    GrayScheme.foregroundInactive = 0x8;
    GrayScheme.foregroundDisabled = 0x8;
    GrayScheme.background = 0xFD;
    GrayScheme.backgroundInactive = 0xFC;
    GrayScheme.backgroundDisabled = 0xFC;
    GrayScheme.text = 0xF3;
    GrayScheme.textHighlight = 0xC;
    GrayScheme.textHighlightText = 0xF;
    GrayScheme.textInactive = 0xFC;
    GrayScheme.textDisabled = 0xFC;

    laScheme_Initialize(&WhiteScheme, GFX_COLOR_MODE_RGB_565);
    WhiteScheme.base = 0xF;
    WhiteScheme.highlight = 0xFC;
    WhiteScheme.highlightLight = 0xF;
    WhiteScheme.shadow = 0x8;
    WhiteScheme.shadowDark = 0xED;
    WhiteScheme.foreground = 0x0;
    WhiteScheme.foregroundInactive = 0x8;
    WhiteScheme.foregroundDisabled = 0x8;
    WhiteScheme.background = 0xF;
    WhiteScheme.backgroundInactive = 0xFC;
    WhiteScheme.backgroundDisabled = 0xFC;
    WhiteScheme.text = 0xF3;
    WhiteScheme.textHighlight = 0xC;
    WhiteScheme.textHighlightText = 0xF;
    WhiteScheme.textInactive = 0xFC;
    WhiteScheme.textDisabled = 0xFC;

    laScheme_Initialize(&TempRealFeelScheme, GFX_COLOR_MODE_RGB_565);
    TempRealFeelScheme.base = 0x6;
    TempRealFeelScheme.highlight = 0xFC;
    TempRealFeelScheme.highlightLight = 0xF;
    TempRealFeelScheme.shadow = 0x8;
    TempRealFeelScheme.shadowDark = 0xED;
    TempRealFeelScheme.foreground = 0x6;
    TempRealFeelScheme.foregroundInactive = 0xFE;
    TempRealFeelScheme.foregroundDisabled = 0x8;
    TempRealFeelScheme.background = 0xF;
    TempRealFeelScheme.backgroundInactive = 0xFE;
    TempRealFeelScheme.backgroundDisabled = 0xFC;
    TempRealFeelScheme.text = 0x0;
    TempRealFeelScheme.textHighlight = 0xC;
    TempRealFeelScheme.textHighlightText = 0xF;
    TempRealFeelScheme.textInactive = 0xFE;
    TempRealFeelScheme.textDisabled = 0xF6;

    laScheme_Initialize(&TextGrey, GFX_COLOR_MODE_RGB_565);
    TextGrey.base = 0xFF;
    TextGrey.highlight = 0xFC;
    TextGrey.highlightLight = 0xF;
    TextGrey.shadow = 0x8;
    TextGrey.shadowDark = 0xED;
    TextGrey.foreground = 0xFF;
    TextGrey.foregroundInactive = 0xFD;
    TextGrey.foregroundDisabled = 0x8;
    TextGrey.background = 0xF;
    TextGrey.backgroundInactive = 0xFC;
    TextGrey.backgroundDisabled = 0xFC;
    TextGrey.text = 0xED;
    TextGrey.textHighlight = 0xC;
    TextGrey.textHighlightText = 0xF;
    TextGrey.textInactive = 0xFC;
    TextGrey.textDisabled = 0xFC;

    laScheme_Initialize(&GradientScheme, GFX_COLOR_MODE_RGB_565);
    GradientScheme.base = 0xFC;
    GradientScheme.highlight = 0xFC;
    GradientScheme.highlightLight = 0xF;
    GradientScheme.shadow = 0x8;
    GradientScheme.shadowDark = 0xED;
    GradientScheme.foreground = 0x0;
    GradientScheme.foregroundInactive = 0x8;
    GradientScheme.foregroundDisabled = 0x8;
    GradientScheme.background = 0xF;
    GradientScheme.backgroundInactive = 0xFC;
    GradientScheme.backgroundDisabled = 0xFC;
    GradientScheme.text = 0x0;
    GradientScheme.textHighlight = 0xC;
    GradientScheme.textHighlightText = 0xF;
    GradientScheme.textInactive = 0xFC;
    GradientScheme.textDisabled = 0xFC;

    laScheme_Initialize(&Red, GFX_COLOR_MODE_RGB_565);
    Red.base = 0x3E;
    Red.highlight = 0xFC;
    Red.highlightLight = 0xF;
    Red.shadow = 0x8;
    Red.shadowDark = 0xED;
    Red.foreground = 0x0;
    Red.foregroundInactive = 0x8;
    Red.foregroundDisabled = 0x8;
    Red.background = 0xF;
    Red.backgroundInactive = 0xFC;
    Red.backgroundDisabled = 0xFC;
    Red.text = 0x0;
    Red.textHighlight = 0xC;
    Red.textHighlightText = 0xF;
    Red.textInactive = 0xFC;
    Red.textDisabled = 0xFC;

    laScheme_Initialize(&TextGreen, GFX_COLOR_MODE_RGB_565);
    TextGreen.base = 0x6;
    TextGreen.highlight = 0xFC;
    TextGreen.highlightLight = 0xF;
    TextGreen.shadow = 0x8;
    TextGreen.shadowDark = 0xED;
    TextGreen.foreground = 0xFF;
    TextGreen.foregroundInactive = 0x6;
    TextGreen.foregroundDisabled = 0x8;
    TextGreen.background = 0x6;
    TextGreen.backgroundInactive = 0xFC;
    TextGreen.backgroundDisabled = 0xFC;
    TextGreen.text = 0xF;
    TextGreen.textHighlight = 0xC;
    TextGreen.textHighlightText = 0xF;
    TextGreen.textInactive = 0xFC;
    TextGreen.textDisabled = 0xFC;

    laScheme_Initialize(&TempDailyGraphScheme, GFX_COLOR_MODE_RGB_565);
    TempDailyGraphScheme.base = 0xFD;
    TempDailyGraphScheme.highlight = 0xFC;
    TempDailyGraphScheme.highlightLight = 0xF;
    TempDailyGraphScheme.shadow = 0x8;
    TempDailyGraphScheme.shadowDark = 0xED;
    TempDailyGraphScheme.foreground = 0xF;
    TempDailyGraphScheme.foregroundInactive = 0xFE;
    TempDailyGraphScheme.foregroundDisabled = 0x8;
    TempDailyGraphScheme.background = 0xF;
    TempDailyGraphScheme.backgroundInactive = 0xFE;
    TempDailyGraphScheme.backgroundDisabled = 0xFC;
    TempDailyGraphScheme.text = 0xFD;
    TempDailyGraphScheme.textHighlight = 0xC;
    TempDailyGraphScheme.textHighlightText = 0xF;
    TempDailyGraphScheme.textInactive = 0xFE;
    TempDailyGraphScheme.textDisabled = 0xF6;

    laScheme_Initialize(&Yellow, GFX_COLOR_MODE_RGB_565);
    Yellow.base = 0xB;
    Yellow.highlight = 0xFC;
    Yellow.highlightLight = 0xF;
    Yellow.shadow = 0x8;
    Yellow.shadowDark = 0xED;
    Yellow.foreground = 0x0;
    Yellow.foregroundInactive = 0x8;
    Yellow.foregroundDisabled = 0x8;
    Yellow.background = 0xF;
    Yellow.backgroundInactive = 0xFC;
    Yellow.backgroundDisabled = 0xFC;
    Yellow.text = 0x0;
    Yellow.textHighlight = 0xC;
    Yellow.textHighlightText = 0xF;
    Yellow.textInactive = 0xFC;
    Yellow.textDisabled = 0xFC;

    laScheme_Initialize(&Purple, GFX_COLOR_MODE_RGB_565);
    Purple.base = 0xFC;
    Purple.highlight = 0xFC;
    Purple.highlightLight = 0xF;
    Purple.shadow = 0x8;
    Purple.shadowDark = 0xED;
    Purple.foreground = 0x9;
    Purple.foregroundInactive = 0xC;
    Purple.foregroundDisabled = 0x8;
    Purple.background = 0xA;
    Purple.backgroundInactive = 0xB;
    Purple.backgroundDisabled = 0xFC;
    Purple.text = 0x0;
    Purple.textHighlight = 0xC;
    Purple.textHighlightText = 0xF;
    Purple.textInactive = 0xFC;
    Purple.textDisabled = 0xFC;

    laScheme_Initialize(&TempHourlyGraphScheme, GFX_COLOR_MODE_RGB_565);
    TempHourlyGraphScheme.base = 0xFD;
    TempHourlyGraphScheme.highlight = 0xFC;
    TempHourlyGraphScheme.highlightLight = 0xF;
    TempHourlyGraphScheme.shadow = 0x8;
    TempHourlyGraphScheme.shadowDark = 0xED;
    TempHourlyGraphScheme.foreground = 0xFD;
    TempHourlyGraphScheme.foregroundInactive = 0xFE;
    TempHourlyGraphScheme.foregroundDisabled = 0x8;
    TempHourlyGraphScheme.background = 0xF;
    TempHourlyGraphScheme.backgroundInactive = 0xFE;
    TempHourlyGraphScheme.backgroundDisabled = 0xFC;
    TempHourlyGraphScheme.text = 0xFD;
    TempHourlyGraphScheme.textHighlight = 0xC;
    TempHourlyGraphScheme.textHighlightText = 0xF;
    TempHourlyGraphScheme.textInactive = 0xFE;
    TempHourlyGraphScheme.textDisabled = 0xF6;

    laScheme_Initialize(&TitleBarScheme, GFX_COLOR_MODE_RGB_565);
    TitleBarScheme.base = 0xF;
    TitleBarScheme.highlight = 0xFC;
    TitleBarScheme.highlightLight = 0xF;
    TitleBarScheme.shadow = 0x8;
    TitleBarScheme.shadowDark = 0xED;
    TitleBarScheme.foreground = 0x0;
    TitleBarScheme.foregroundInactive = 0x8;
    TitleBarScheme.foregroundDisabled = 0x8;
    TitleBarScheme.background = 0xF;
    TitleBarScheme.backgroundInactive = 0xFC;
    TitleBarScheme.backgroundDisabled = 0xFC;
    TitleBarScheme.text = 0x0;
    TitleBarScheme.textHighlight = 0xC;
    TitleBarScheme.textHighlightText = 0xF;
    TitleBarScheme.textInactive = 0xFC;
    TitleBarScheme.textDisabled = 0xFC;

    laScheme_Initialize(&Green, GFX_COLOR_MODE_RGB_565);
    Green.base = 0xD8;
    Green.highlight = 0xFC;
    Green.highlightLight = 0xF;
    Green.shadow = 0x8;
    Green.shadowDark = 0xED;
    Green.foreground = 0x0;
    Green.foregroundInactive = 0x8;
    Green.foregroundDisabled = 0x8;
    Green.background = 0xF;
    Green.backgroundInactive = 0xFC;
    Green.backgroundDisabled = 0xFC;
    Green.text = 0x42;
    Green.textHighlight = 0xC;
    Green.textHighlightText = 0xF;
    Green.textInactive = 0xFC;
    Green.textDisabled = 0xFC;

    laScheme_Initialize(&TextWhite, GFX_COLOR_MODE_RGB_565);
    TextWhite.base = 0xFC;
    TextWhite.highlight = 0xFC;
    TextWhite.highlightLight = 0xF;
    TextWhite.shadow = 0x8;
    TextWhite.shadowDark = 0xED;
    TextWhite.foreground = 0x0;
    TextWhite.foregroundInactive = 0x8;
    TextWhite.foregroundDisabled = 0x8;
    TextWhite.background = 0xF;
    TextWhite.backgroundInactive = 0xFC;
    TextWhite.backgroundDisabled = 0xFC;
    TextWhite.text = 0xF;
    TextWhite.textHighlight = 0xC;
    TextWhite.textHighlightText = 0xF;
    TextWhite.textInactive = 0xFC;
    TextWhite.textDisabled = 0xFC;

    laScheme_Initialize(&defaultPaletteScheme, GFX_COLOR_MODE_RGB_565);
    defaultPaletteScheme.base = 0xFC;
    defaultPaletteScheme.highlight = 0xFC;
    defaultPaletteScheme.highlightLight = 0xF;
    defaultPaletteScheme.shadow = 0x8;
    defaultPaletteScheme.shadowDark = 0xED;
    defaultPaletteScheme.foreground = 0x0;
    defaultPaletteScheme.foregroundInactive = 0xFE;
    defaultPaletteScheme.foregroundDisabled = 0x8;
    defaultPaletteScheme.background = 0xF;
    defaultPaletteScheme.backgroundInactive = 0xFE;
    defaultPaletteScheme.backgroundDisabled = 0xFC;
    defaultPaletteScheme.text = 0x0;
    defaultPaletteScheme.textHighlight = 0xC;
    defaultPaletteScheme.textHighlightText = 0xF;
    defaultPaletteScheme.textInactive = 0xFE;
    defaultPaletteScheme.textDisabled = 0xF6;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    GFX_Set(GFXF_GLOBAL_PALETTE, globalColorPalette);
    laContext_SetStringTable(&stringTable);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_SplashScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_MainScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_LoadScreen);
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
    laWidget_SetScheme((laWidget*)ImageWidget3, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget3, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget3, &Bar);
    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)ImageWidget3);

    ImageWidget4 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget4, 10, 15);
    laWidget_SetSize((laWidget*)ImageWidget4, 144, 39);
    laWidget_SetVisible((laWidget*)ImageWidget4, LA_FALSE);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget4, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)ImageWidget4, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget4, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget4, &MicrochipLogo);
    laWidget_AddChild((laWidget*)ImageWidget3, (laWidget*)ImageWidget4);

}

static void ScreenCreate_MainScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &WhiteScheme);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    PanelItem0 = laWidget_New();
    laWidget_SetSize((laWidget*)PanelItem0, 120, 136);
    laWidget_SetScheme((laWidget*)PanelItem0, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)PanelItem0, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PanelItem0, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelItem0);

    ButtonItem0 = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonItem0, 120, 120);
    laWidget_SetScheme((laWidget*)ButtonItem0, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonItem0, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonItem0, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonItem0, &Brewery_Icons_01);
    laButtonWidget_SetReleasedImage(ButtonItem0, &Brewery_Icons_01);
    laWidget_AddChild((laWidget*)PanelItem0, (laWidget*)ButtonItem0);

    LabelItem0 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelItem0, 0, 120);
    laWidget_SetSize((laWidget*)LabelItem0, 120, 16);
    laWidget_SetScheme((laWidget*)LabelItem0, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelItem0, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelItem0, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetHAlignment(LabelItem0, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelItem0, (laWidget*)LabelItem0);

    PanelItem1 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelItem1, 120, 0);
    laWidget_SetSize((laWidget*)PanelItem1, 120, 136);
    laWidget_SetScheme((laWidget*)PanelItem1, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)PanelItem1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PanelItem1, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelItem1);

    ButtonItem1 = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonItem1, 120, 120);
    laWidget_SetScheme((laWidget*)ButtonItem1, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonItem1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonItem1, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonItem1, &Brewery_Icons_02);
    laButtonWidget_SetReleasedImage(ButtonItem1, &Brewery_Icons_02);
    laWidget_AddChild((laWidget*)PanelItem1, (laWidget*)ButtonItem1);

    LabelItem1 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelItem1, 0, 120);
    laWidget_SetSize((laWidget*)LabelItem1, 120, 16);
    laWidget_SetScheme((laWidget*)LabelItem1, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelItem1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelItem1, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetHAlignment(LabelItem1, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelItem1, (laWidget*)LabelItem1);

    PanelItem2 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelItem2, 240, 0);
    laWidget_SetSize((laWidget*)PanelItem2, 120, 136);
    laWidget_SetScheme((laWidget*)PanelItem2, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)PanelItem2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PanelItem2, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelItem2);

    ButtonItem2 = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonItem2, 120, 120);
    laWidget_SetScheme((laWidget*)ButtonItem2, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonItem2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonItem2, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonItem2, &Brewery_Icons_03);
    laButtonWidget_SetReleasedImage(ButtonItem2, &Brewery_Icons_03);
    laWidget_AddChild((laWidget*)PanelItem2, (laWidget*)ButtonItem2);

    LabelItem2 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelItem2, 0, 120);
    laWidget_SetSize((laWidget*)LabelItem2, 120, 16);
    laWidget_SetScheme((laWidget*)LabelItem2, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelItem2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelItem2, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetHAlignment(LabelItem2, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelItem2, (laWidget*)LabelItem2);

    PanelItem3 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelItem3, 0, 136);
    laWidget_SetSize((laWidget*)PanelItem3, 120, 136);
    laWidget_SetScheme((laWidget*)PanelItem3, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)PanelItem3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PanelItem3, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelItem3);

    ButtonItem3 = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonItem3, 120, 120);
    laWidget_SetScheme((laWidget*)ButtonItem3, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonItem3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonItem3, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonItem3, &Brewery_Icons_04);
    laButtonWidget_SetReleasedImage(ButtonItem3, &Brewery_Icons_04);
    laWidget_AddChild((laWidget*)PanelItem3, (laWidget*)ButtonItem3);

    LabelItem3 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelItem3, 0, 120);
    laWidget_SetSize((laWidget*)LabelItem3, 120, 16);
    laWidget_SetScheme((laWidget*)LabelItem3, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelItem3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelItem3, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetHAlignment(LabelItem3, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelItem3, (laWidget*)LabelItem3);

    PanelItem4 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelItem4, 120, 136);
    laWidget_SetSize((laWidget*)PanelItem4, 120, 136);
    laWidget_SetScheme((laWidget*)PanelItem4, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)PanelItem4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PanelItem4, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelItem4);

    ButtonItem4 = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonItem4, 120, 120);
    laWidget_SetScheme((laWidget*)ButtonItem4, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonItem4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonItem4, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonItem4, &Brewery_Icons_05);
    laButtonWidget_SetReleasedImage(ButtonItem4, &Brewery_Icons_05);
    laWidget_AddChild((laWidget*)PanelItem4, (laWidget*)ButtonItem4);

    LabelItem4 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelItem4, 0, 120);
    laWidget_SetSize((laWidget*)LabelItem4, 120, 16);
    laWidget_SetScheme((laWidget*)LabelItem4, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelItem4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelItem4, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetHAlignment(LabelItem4, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelItem4, (laWidget*)LabelItem4);

    PanelItem5 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelItem5, 240, 136);
    laWidget_SetSize((laWidget*)PanelItem5, 120, 136);
    laWidget_SetScheme((laWidget*)PanelItem5, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)PanelItem5, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PanelItem5, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelItem5);

    ButtonItem5 = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonItem5, 120, 120);
    laWidget_SetScheme((laWidget*)ButtonItem5, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonItem5, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonItem5, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonItem5, &Brewery_Icons_06);
    laButtonWidget_SetReleasedImage(ButtonItem5, &Brewery_Icons_06);
    laWidget_AddChild((laWidget*)PanelItem5, (laWidget*)ButtonItem5);

    LabelItem5 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelItem5, 0, 120);
    laWidget_SetSize((laWidget*)LabelItem5, 120, 16);
    laWidget_SetScheme((laWidget*)LabelItem5, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelItem5, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelItem5, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetHAlignment(LabelItem5, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelItem5, (laWidget*)LabelItem5);

    ButtonUp = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonUp, 360, 40);
    laWidget_SetSize((laWidget*)ButtonUp, 120, 80);
    laWidget_SetScheme((laWidget*)ButtonUp, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonUp, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonUp, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetVAlignment(ButtonUp, LA_VALIGN_BOTTOM);
    laButtonWidget_SetPressedImage(ButtonUp, &Up_Press);
    laButtonWidget_SetReleasedImage(ButtonUp, &Up);
    laButtonWidget_SetPressedOffset(ButtonUp, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonUp);

    ButtonDown = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonDown, 360, 140);
    laWidget_SetSize((laWidget*)ButtonDown, 120, 80);
    laWidget_SetScheme((laWidget*)ButtonDown, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonDown, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonDown, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetVAlignment(ButtonDown, LA_VALIGN_TOP);
    laButtonWidget_SetPressedImage(ButtonDown, &Down_Press);
    laButtonWidget_SetReleasedImage(ButtonDown, &Down);
    laButtonWidget_SetPressedOffset(ButtonDown, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonDown);

    ButtonInfo = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonInfo, 360, 0);
    laWidget_SetSize((laWidget*)ButtonInfo, 120, 40);
    laWidget_SetScheme((laWidget*)ButtonInfo, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonInfo, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonInfo, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetHAlignment(ButtonInfo, LA_HALIGN_RIGHT);
    laButtonWidget_SetVAlignment(ButtonInfo, LA_VALIGN_TOP);
    laButtonWidget_SetPressedImage(ButtonInfo, &Info_Press);
    laButtonWidget_SetReleasedImage(ButtonInfo, &Info);
    laButtonWidget_SetPressedOffset(ButtonInfo, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonInfo);

    ButtonLanguage_Main = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonLanguage_Main, 360, 220);
    laWidget_SetSize((laWidget*)ButtonLanguage_Main, 120, 52);
    laWidget_SetScheme((laWidget*)ButtonLanguage_Main, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonLanguage_Main, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonLanguage_Main, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetHAlignment(ButtonLanguage_Main, LA_HALIGN_RIGHT);
    laButtonWidget_SetVAlignment(ButtonLanguage_Main, LA_VALIGN_BOTTOM);
    laButtonWidget_SetPressedImage(ButtonLanguage_Main, &Language_Change_Press);
    laButtonWidget_SetReleasedImage(ButtonLanguage_Main, &Language_Change);
    laButtonWidget_SetPressedOffset(ButtonLanguage_Main, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonLanguage_Main);

}

static void ScreenCreate_LoadScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    ImageSequence_LoadingIcon = laImageSequenceWidget_New();
    laWidget_SetPosition((laWidget*)ImageSequence_LoadingIcon, 165, 50);
    laWidget_SetSize((laWidget*)ImageSequence_LoadingIcon, 143, 143);
    laWidget_SetScheme((laWidget*)ImageSequence_LoadingIcon, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageSequence_LoadingIcon, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageSequence_LoadingIcon, LA_WIDGET_BORDER_NONE);
    laImageSequenceWidget_SetImageCount(ImageSequence_LoadingIcon, 12);
    laImageSequenceWidget_SetImage(ImageSequence_LoadingIcon, 0, &Loading0);
    laImageSequenceWidget_SetImage(ImageSequence_LoadingIcon, 1, &Loading1);
    laImageSequenceWidget_SetImage(ImageSequence_LoadingIcon, 2, &Loading2);
    laImageSequenceWidget_SetImage(ImageSequence_LoadingIcon, 3, &Loading3);
    laImageSequenceWidget_SetImage(ImageSequence_LoadingIcon, 4, &Loading4);
    laImageSequenceWidget_SetImage(ImageSequence_LoadingIcon, 5, &Loading5);
    laImageSequenceWidget_SetImage(ImageSequence_LoadingIcon, 6, &Loading6);
    laImageSequenceWidget_SetImage(ImageSequence_LoadingIcon, 7, &Loading7);
    laImageSequenceWidget_SetImage(ImageSequence_LoadingIcon, 8, &Loading8);
    laImageSequenceWidget_SetImage(ImageSequence_LoadingIcon, 9, &Loading9);
    laImageSequenceWidget_SetImage(ImageSequence_LoadingIcon, 10, &Loading10);
    laImageSequenceWidget_SetImage(ImageSequence_LoadingIcon, 11, &Loading11);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageSequence_LoadingIcon);

    LabelLoading = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelLoading, 160, 206);
    laWidget_SetSize((laWidget*)LabelLoading, 160, 30);
    laWidget_SetScheme((laWidget*)LabelLoading, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelLoading, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelLoading, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelLoading);

}



