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
Copyright (c) 2018 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
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
laImageWidget* WeatherImage;
laImageWidget* ImageWidget_MCHPLogo;
laLabelWidget* LabelWidget_City;
laLabelWidget* LabelWidget_Temp;
laButtonWidget* ButtonWidget_SwitchCity;
laWidget* PanelWidget1;
laLineGraphWidget* TempLineGraph;
laLabelWidget* LabelWidget_FeelLike;
laLabelWidget* LabelWidget_ActualTemp;
laLabelWidget* LabelWidget_HundredTemp;
laLabelWidget* LabelWidget_LowTemp;
laButtonWidget* ButtonWidget_SwitchTemp;
laWidget* PanelWidget2;
laBarGraphWidget* TempPrecipitaionGraph;
laLabelWidget* LabelWidget_Precipitation;
laLabelWidget* LabelWidget_Humidity;
laLabelWidget* LabelWidget_ZeroPercent;
laLabelWidget* LabelWidget_FiftyPercent;
laLabelWidget* LabelWidget_HundredPercent;
laButtonWidget* ButtonWidget_SwitchHumidity;
laWidget* ButtonPanel;
laButtonWidget* ButtonWidget_Hourly;
laButtonWidget* ButtonWidget_Daily;
laButtonWidget* ButtonWidget_City;
laLabelWidget* LabelWidget_Press;
laWidget* PanelWidget_Hourly;
laLabelWidget* LabelWidget_Midnight;
laLabelWidget* LabelWidget_ThreeAM;
laLabelWidget* LabelWidget_SixAM;
laLabelWidget* LabelWidget_NineAM;
laLabelWidget* LabelWidget_Noon;
laLabelWidget* LabelWidget_ThreePM;
laLabelWidget* LabelWidget_SixPM;
laWidget* PanelWidget_Daily;
laLabelWidget* LabelWidget_Sunday;
laLabelWidget* LabelWidget_Monday;
laLabelWidget* LabelWidget_Tuesday;
laLabelWidget* LabelWidget_Wednesday;
laLabelWidget* LabelWidget_Thursday;
laLabelWidget* LabelWidget_Friday;
laLabelWidget* LabelWidget_Saturday;


static void ScreenCreate_SplashScreen(laScreen* screen);
static void ScreenCreate_MainScreen(laScreen* screen);


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

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_MainScreen);
    laScreen_SetOrientation(screen, LA_SCREEN_ORIENTATION_270);
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

static void ScreenCreate_MainScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 272, 480);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetScheme((laWidget*)layer0, &WhiteScheme);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    WeatherImage = laImageWidget_New();
    laWidget_SetSize((laWidget*)WeatherImage, 272, 100);
    laWidget_SetScheme((laWidget*)WeatherImage, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)WeatherImage, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)WeatherImage, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(WeatherImage, &windy);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)WeatherImage);

    ImageWidget_MCHPLogo = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget_MCHPLogo, 144, 39);
    laWidget_SetBackgroundType((laWidget*)ImageWidget_MCHPLogo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget_MCHPLogo, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget_MCHPLogo, &MicrochipLogo);
    laWidget_AddChild((laWidget*)WeatherImage, (laWidget*)ImageWidget_MCHPLogo);

    LabelWidget_City = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_City, 0, 54);
    laWidget_SetSize((laWidget*)LabelWidget_City, 167, 47);
    laWidget_SetScheme((laWidget*)LabelWidget_City, &TextWhite);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_City, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_City, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_City, laString_CreateFromID(string_City));
    laLabelWidget_SetHAlignment(LabelWidget_City, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)WeatherImage, (laWidget*)LabelWidget_City);

    LabelWidget_Temp = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_Temp, 182, 0);
    laWidget_SetSize((laWidget*)LabelWidget_Temp, 80, 38);
    laWidget_SetScheme((laWidget*)LabelWidget_Temp, &TextWhite);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_Temp, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_Temp, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_Temp, laString_CreateFromID(string_degrees));
    laLabelWidget_SetHAlignment(LabelWidget_Temp, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)WeatherImage, (laWidget*)LabelWidget_Temp);

    ButtonWidget_SwitchCity = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonWidget_SwitchCity, 272, 100);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget_SwitchCity, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget_SwitchCity, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget_SwitchCity, &ButtonWidget_SwitchCity_ReleasedEvent);

    laWidget_AddChild((laWidget*)WeatherImage, (laWidget*)ButtonWidget_SwitchCity);

    PanelWidget1 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget1, 0, 130);
    laWidget_SetSize((laWidget*)PanelWidget1, 272, 150);
    laWidget_SetScheme((laWidget*)PanelWidget1, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget1, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget1);

    TempLineGraph = laLineGraphWidget_New();
    laWidget_SetPosition((laWidget*)TempLineGraph, 25, 0);
    laWidget_SetSize((laWidget*)TempLineGraph, 247, 150);
    laWidget_SetScheme((laWidget*)TempLineGraph, &TempHourlyGraphScheme);
    laWidget_SetBackgroundType((laWidget*)TempLineGraph, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TempLineGraph, LA_WIDGET_BORDER_NONE);
    laLineGraphWidget_SetTickLength(TempLineGraph, 1);
    laLineGraphWidget_SetFillGraphArea(TempLineGraph, LA_FALSE);
    laLineGraphWidget_SetFillSeriesArea(TempLineGraph, LA_FALSE);
    laLineGraphWidget_SetMaxValue(TempLineGraph, 0, 50);
    laLineGraphWidget_SetCategoryAxisTicksPosition(TempLineGraph, LINE_GRAPH_TICK_IN);
    laLineGraphWidget_AddCategory(TempLineGraph, NULL);
    laLineGraphWidget_AddCategory(TempLineGraph, NULL);
    laLineGraphWidget_AddCategory(TempLineGraph, NULL);
    laLineGraphWidget_AddCategory(TempLineGraph, NULL);
    laLineGraphWidget_AddCategory(TempLineGraph, NULL);
    laLineGraphWidget_AddCategory(TempLineGraph, NULL);
    laLineGraphWidget_AddCategory(TempLineGraph, NULL);
    laLineGraphWidget_AddSeries(TempLineGraph, NULL);
    laLineGraphWidget_SetSeriesScheme(TempLineGraph, 0, &TempActualScheme);
    laLineGraphWidget_SetSeriesPointType(TempLineGraph, 0, LINE_GRAPH_DATA_POINT_SQUARE);
    laLineGraphWidget_AddDataToSeries(TempLineGraph, 0, 30, NULL);
    laLineGraphWidget_AddDataToSeries(TempLineGraph, 0, 36, NULL);
    laLineGraphWidget_AddDataToSeries(TempLineGraph, 0, 43, NULL);
    laLineGraphWidget_AddDataToSeries(TempLineGraph, 0, 45, NULL);
    laLineGraphWidget_AddDataToSeries(TempLineGraph, 0, 46, NULL);
    laLineGraphWidget_AddDataToSeries(TempLineGraph, 0, 46, NULL);
    laLineGraphWidget_AddDataToSeries(TempLineGraph, 0, 44, NULL);
    laLineGraphWidget_AddSeries(TempLineGraph, NULL);
    laLineGraphWidget_SetSeriesScheme(TempLineGraph, 1, &TempRealFeelScheme);
    laLineGraphWidget_SetSeriesPointType(TempLineGraph, 1, LINE_GRAPH_DATA_POINT_CIRCLE);
    laLineGraphWidget_AddDataToSeries(TempLineGraph, 1, 22, NULL);
    laLineGraphWidget_AddDataToSeries(TempLineGraph, 1, 34, NULL);
    laLineGraphWidget_AddDataToSeries(TempLineGraph, 1, 42, NULL);
    laLineGraphWidget_AddDataToSeries(TempLineGraph, 1, 43, NULL);
    laLineGraphWidget_AddDataToSeries(TempLineGraph, 1, 43, NULL);
    laLineGraphWidget_AddDataToSeries(TempLineGraph, 1, 44, NULL);
    laLineGraphWidget_AddDataToSeries(TempLineGraph, 1, 41, NULL);
    laWidget_AddChild((laWidget*)PanelWidget1, (laWidget*)TempLineGraph);

    LabelWidget_FeelLike = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_FeelLike, 116, 117);
    laWidget_SetSize((laWidget*)LabelWidget_FeelLike, 123, 14);
    laWidget_SetScheme((laWidget*)LabelWidget_FeelLike, &TextGreen);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_FeelLike, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelWidget_FeelLike, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_FeelLike, laString_CreateFromID(string_String_FeelTemp));
    laWidget_AddChild((laWidget*)TempLineGraph, (laWidget*)LabelWidget_FeelLike);

    LabelWidget_ActualTemp = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_ActualTemp, 116, 130);
    laWidget_SetSize((laWidget*)LabelWidget_ActualTemp, 123, 14);
    laWidget_SetScheme((laWidget*)LabelWidget_ActualTemp, &TextOrange);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_ActualTemp, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelWidget_ActualTemp, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_ActualTemp, laString_CreateFromID(string_String_ActualTemp));
    laWidget_AddChild((laWidget*)TempLineGraph, (laWidget*)LabelWidget_ActualTemp);

    LabelWidget_HundredTemp = laLabelWidget_New();
    laWidget_SetSize((laWidget*)LabelWidget_HundredTemp, 26, 20);
    laWidget_SetScheme((laWidget*)LabelWidget_HundredTemp, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_HundredTemp, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_HundredTemp, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_HundredTemp, laString_CreateFromID(string_String_100Temp));
    laLabelWidget_SetHAlignment(LabelWidget_HundredTemp, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget1, (laWidget*)LabelWidget_HundredTemp);

    LabelWidget_LowTemp = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_LowTemp, 0, 130);
    laWidget_SetSize((laWidget*)LabelWidget_LowTemp, 26, 20);
    laWidget_SetScheme((laWidget*)LabelWidget_LowTemp, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_LowTemp, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_LowTemp, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_LowTemp, laString_CreateFromID(string_String_0Temp));
    laLabelWidget_SetHAlignment(LabelWidget_LowTemp, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget1, (laWidget*)LabelWidget_LowTemp);

    ButtonWidget_SwitchTemp = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonWidget_SwitchTemp, 272, 150);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget_SwitchTemp, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget_SwitchTemp, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget_SwitchTemp, &ButtonWidget_SwitchTemp_ReleasedEvent);

    laWidget_AddChild((laWidget*)PanelWidget1, (laWidget*)ButtonWidget_SwitchTemp);

    PanelWidget2 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget2, 0, 280);
    laWidget_SetSize((laWidget*)PanelWidget2, 272, 150);
    laWidget_SetScheme((laWidget*)PanelWidget2, &GrayScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget2, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget2);

    TempPrecipitaionGraph = laBarGraphWidget_New();
    laWidget_SetPosition((laWidget*)TempPrecipitaionGraph, 26, 0);
    laWidget_SetSize((laWidget*)TempPrecipitaionGraph, 240, 150);
    laWidget_SetScheme((laWidget*)TempPrecipitaionGraph, &TempDailyGraphScheme);
    laWidget_SetBackgroundType((laWidget*)TempPrecipitaionGraph, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TempPrecipitaionGraph, LA_WIDGET_BORDER_NONE);
    laBarGraphWidget_SetFillGraphArea(TempPrecipitaionGraph, false);
    laBarGraphWidget_SetValueAxisTickInterval(TempPrecipitaionGraph, 0, 25);
    laBarGraphWidget_SetValueAxisLabelsVisible(TempPrecipitaionGraph, 0, LA_FALSE);
    laBarGraphWidget_SetValueAxisTicksVisible(TempPrecipitaionGraph, 0, LA_FALSE);
    laBarGraphWidget_SetValueAxisSubticksVisible(TempPrecipitaionGraph, 0, LA_FALSE);
    laBarGraphWidget_SetCategoryAxisLabelsVisible(TempPrecipitaionGraph, LA_FALSE);
    laBarGraphWidget_SetCategoryAxisTicksVisible(TempPrecipitaionGraph, LA_FALSE);
    laBarGraphWidget_AddCategory(TempPrecipitaionGraph, NULL);
    laBarGraphWidget_AddCategory(TempPrecipitaionGraph, NULL);
    laBarGraphWidget_AddCategory(TempPrecipitaionGraph, NULL);
    laBarGraphWidget_AddCategory(TempPrecipitaionGraph, NULL);
    laBarGraphWidget_AddCategory(TempPrecipitaionGraph, NULL);
    laBarGraphWidget_AddCategory(TempPrecipitaionGraph, NULL);
    laBarGraphWidget_AddCategory(TempPrecipitaionGraph, NULL);
    laBarGraphWidget_AddSeries(TempPrecipitaionGraph, NULL);
    laBarGraphWidget_SetSeriesScheme(TempPrecipitaionGraph, 0, &Blue);
    laBarGraphWidget_AddDataToSeries(TempPrecipitaionGraph, 0, 25, NULL);
    laBarGraphWidget_AddDataToSeries(TempPrecipitaionGraph, 0, 25, NULL);
    laBarGraphWidget_AddDataToSeries(TempPrecipitaionGraph, 0, 33, NULL);
    laBarGraphWidget_AddDataToSeries(TempPrecipitaionGraph, 0, 50, NULL);
    laBarGraphWidget_AddDataToSeries(TempPrecipitaionGraph, 0, 50, NULL);
    laBarGraphWidget_AddDataToSeries(TempPrecipitaionGraph, 0, 50, NULL);
    laBarGraphWidget_AddDataToSeries(TempPrecipitaionGraph, 0, 80, NULL);
    laBarGraphWidget_AddSeries(TempPrecipitaionGraph, NULL);
    laBarGraphWidget_SetSeriesScheme(TempPrecipitaionGraph, 1, &TempActualScheme);
    laBarGraphWidget_AddDataToSeries(TempPrecipitaionGraph, 1, 70, NULL);
    laBarGraphWidget_AddDataToSeries(TempPrecipitaionGraph, 1, 72, NULL);
    laBarGraphWidget_AddDataToSeries(TempPrecipitaionGraph, 1, 68, NULL);
    laBarGraphWidget_AddDataToSeries(TempPrecipitaionGraph, 1, 80, NULL);
    laBarGraphWidget_AddDataToSeries(TempPrecipitaionGraph, 1, 76, NULL);
    laBarGraphWidget_AddDataToSeries(TempPrecipitaionGraph, 1, 88, NULL);
    laBarGraphWidget_AddDataToSeries(TempPrecipitaionGraph, 1, 70, NULL);
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)TempPrecipitaionGraph);

    LabelWidget_Precipitation = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_Precipitation, 6, 5);
    laWidget_SetSize((laWidget*)LabelWidget_Precipitation, 123, 14);
    laWidget_SetScheme((laWidget*)LabelWidget_Precipitation, &TextGreen);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_Precipitation, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelWidget_Precipitation, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_Precipitation, laString_CreateFromID(string_String_Precepitation));
    laLabelWidget_SetHAlignment(LabelWidget_Precipitation, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)TempPrecipitaionGraph, (laWidget*)LabelWidget_Precipitation);

    LabelWidget_Humidity = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_Humidity, 176, 5);
    laWidget_SetSize((laWidget*)LabelWidget_Humidity, 60, 14);
    laWidget_SetScheme((laWidget*)LabelWidget_Humidity, &TextOrange);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_Humidity, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelWidget_Humidity, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_Humidity, laString_CreateFromID(string_String_Humidity));
    laLabelWidget_SetHAlignment(LabelWidget_Humidity, LA_HALIGN_RIGHT);
    laWidget_AddChild((laWidget*)TempPrecipitaionGraph, (laWidget*)LabelWidget_Humidity);

    LabelWidget_ZeroPercent = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_ZeroPercent, 0, 128);
    laWidget_SetSize((laWidget*)LabelWidget_ZeroPercent, 26, 20);
    laWidget_SetScheme((laWidget*)LabelWidget_ZeroPercent, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_ZeroPercent, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_ZeroPercent, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_ZeroPercent, laString_CreateFromID(string_String_0Percent));
    laLabelWidget_SetHAlignment(LabelWidget_ZeroPercent, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)LabelWidget_ZeroPercent);

    LabelWidget_FiftyPercent = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_FiftyPercent, 0, 62);
    laWidget_SetSize((laWidget*)LabelWidget_FiftyPercent, 26, 20);
    laWidget_SetScheme((laWidget*)LabelWidget_FiftyPercent, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_FiftyPercent, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_FiftyPercent, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_FiftyPercent, laString_CreateFromID(string_String_50Percent));
    laLabelWidget_SetHAlignment(LabelWidget_FiftyPercent, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)LabelWidget_FiftyPercent);

    LabelWidget_HundredPercent = laLabelWidget_New();
    laWidget_SetSize((laWidget*)LabelWidget_HundredPercent, 30, 20);
    laWidget_SetScheme((laWidget*)LabelWidget_HundredPercent, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_HundredPercent, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_HundredPercent, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_HundredPercent, laString_CreateFromID(string_String_100Percent));
    laLabelWidget_SetHAlignment(LabelWidget_HundredPercent, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)LabelWidget_HundredPercent);

    ButtonWidget_SwitchHumidity = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonWidget_SwitchHumidity, 272, 150);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget_SwitchHumidity, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget_SwitchHumidity, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget_SwitchHumidity, &ButtonWidget_SwitchHumidity_ReleasedEvent);

    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)ButtonWidget_SwitchHumidity);

    ButtonPanel = laWidget_New();
    laWidget_SetPosition((laWidget*)ButtonPanel, 0, 430);
    laWidget_SetSize((laWidget*)ButtonPanel, 272, 50);
    laWidget_SetScheme((laWidget*)ButtonPanel, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonPanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, ButtonPanel);

    ButtonWidget_Hourly = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonWidget_Hourly, 90, 50);
    laWidget_SetScheme((laWidget*)ButtonWidget_Hourly, &GrayScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget_Hourly, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget_Hourly, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetText(ButtonWidget_Hourly, laString_CreateFromID(string_lbl_Hourly));
    laButtonWidget_SetPressedOffset(ButtonWidget_Hourly, 0);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget_Hourly, &ButtonWidget_Hourly_ReleasedEvent);

    laWidget_AddChild((laWidget*)ButtonPanel, (laWidget*)ButtonWidget_Hourly);

    ButtonWidget_Daily = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget_Daily, 91, 0);
    laWidget_SetSize((laWidget*)ButtonWidget_Daily, 90, 50);
    laWidget_SetScheme((laWidget*)ButtonWidget_Daily, &GrayScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget_Daily, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget_Daily, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetText(ButtonWidget_Daily, laString_CreateFromID(string_lbl_Daily));
    laButtonWidget_SetPressedOffset(ButtonWidget_Daily, 0);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget_Daily, &ButtonWidget_Daily_ReleasedEvent);

    laWidget_AddChild((laWidget*)ButtonPanel, (laWidget*)ButtonWidget_Daily);

    ButtonWidget_City = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget_City, 182, 0);
    laWidget_SetSize((laWidget*)ButtonWidget_City, 90, 50);
    laWidget_SetScheme((laWidget*)ButtonWidget_City, &GrayScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget_City, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget_City, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget_City, &citySkyline);
    laButtonWidget_SetReleasedImage(ButtonWidget_City, &citySkyline);
    laButtonWidget_SetPressedOffset(ButtonWidget_City, 0);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget_City, &ButtonWidget_City_ReleasedEvent);

    laWidget_AddChild((laWidget*)ButtonPanel, (laWidget*)ButtonWidget_City);

    LabelWidget_Press = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_Press, 62, 0);
    laWidget_SetSize((laWidget*)LabelWidget_Press, 150, 13);
    laWidget_SetScheme((laWidget*)LabelWidget_Press, &GrayScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_Press, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_Press, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_Press, laString_CreateFromID(string_PressToChange));
    laWidget_AddChild((laWidget*)ButtonPanel, (laWidget*)LabelWidget_Press);

    PanelWidget_Hourly = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget_Hourly, 0, 100);
    laWidget_SetSize((laWidget*)PanelWidget_Hourly, 272, 30);
    laWidget_SetScheme((laWidget*)PanelWidget_Hourly, &GrayScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget_Hourly, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget_Hourly, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget_Hourly);

    LabelWidget_Midnight = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_Midnight, 38, 0);
    laWidget_SetSize((laWidget*)LabelWidget_Midnight, 38, 30);
    laWidget_SetScheme((laWidget*)LabelWidget_Midnight, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_Midnight, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_Midnight, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_Midnight, laString_CreateFromID(string_String_Midnight));
    laWidget_AddChild((laWidget*)PanelWidget_Hourly, (laWidget*)LabelWidget_Midnight);

    LabelWidget_ThreeAM = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_ThreeAM, 70, 0);
    laWidget_SetSize((laWidget*)LabelWidget_ThreeAM, 38, 30);
    laWidget_SetScheme((laWidget*)LabelWidget_ThreeAM, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_ThreeAM, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_ThreeAM, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_ThreeAM, laString_CreateFromID(string_String_ThreeAM));
    laWidget_AddChild((laWidget*)PanelWidget_Hourly, (laWidget*)LabelWidget_ThreeAM);

    LabelWidget_SixAM = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_SixAM, 100, 0);
    laWidget_SetSize((laWidget*)LabelWidget_SixAM, 38, 30);
    laWidget_SetScheme((laWidget*)LabelWidget_SixAM, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_SixAM, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_SixAM, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_SixAM, laString_CreateFromID(string_String_SixAM));
    laWidget_AddChild((laWidget*)PanelWidget_Hourly, (laWidget*)LabelWidget_SixAM);

    LabelWidget_NineAM = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_NineAM, 128, 0);
    laWidget_SetSize((laWidget*)LabelWidget_NineAM, 38, 30);
    laWidget_SetScheme((laWidget*)LabelWidget_NineAM, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_NineAM, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_NineAM, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_NineAM, laString_CreateFromID(string_String_NineAM));
    laWidget_AddChild((laWidget*)PanelWidget_Hourly, (laWidget*)LabelWidget_NineAM);

    LabelWidget_Noon = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_Noon, 158, 0);
    laWidget_SetSize((laWidget*)LabelWidget_Noon, 38, 30);
    laWidget_SetScheme((laWidget*)LabelWidget_Noon, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_Noon, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_Noon, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_Noon, laString_CreateFromID(string_String_Noon));
    laWidget_AddChild((laWidget*)PanelWidget_Hourly, (laWidget*)LabelWidget_Noon);

    LabelWidget_ThreePM = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_ThreePM, 188, 0);
    laWidget_SetSize((laWidget*)LabelWidget_ThreePM, 38, 30);
    laWidget_SetScheme((laWidget*)LabelWidget_ThreePM, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_ThreePM, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_ThreePM, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_ThreePM, laString_CreateFromID(string_String_ThreePM));
    laWidget_AddChild((laWidget*)PanelWidget_Hourly, (laWidget*)LabelWidget_ThreePM);

    LabelWidget_SixPM = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_SixPM, 220, 0);
    laWidget_SetSize((laWidget*)LabelWidget_SixPM, 38, 30);
    laWidget_SetScheme((laWidget*)LabelWidget_SixPM, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_SixPM, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_SixPM, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_SixPM, laString_CreateFromID(string_String_SixPM));
    laWidget_AddChild((laWidget*)PanelWidget_Hourly, (laWidget*)LabelWidget_SixPM);

    PanelWidget_Daily = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget_Daily, 0, 100);
    laWidget_SetSize((laWidget*)PanelWidget_Daily, 272, 30);
    laWidget_SetScheme((laWidget*)PanelWidget_Daily, &GrayScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget_Daily, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget_Daily, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget_Daily);

    LabelWidget_Sunday = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_Sunday, 38, 0);
    laWidget_SetSize((laWidget*)LabelWidget_Sunday, 38, 30);
    laWidget_SetScheme((laWidget*)LabelWidget_Sunday, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_Sunday, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_Sunday, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_Sunday, laString_CreateFromID(string_String_Sunday));
    laWidget_AddChild((laWidget*)PanelWidget_Daily, (laWidget*)LabelWidget_Sunday);

    LabelWidget_Monday = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_Monday, 70, 0);
    laWidget_SetSize((laWidget*)LabelWidget_Monday, 38, 30);
    laWidget_SetScheme((laWidget*)LabelWidget_Monday, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_Monday, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_Monday, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_Monday, laString_CreateFromID(string_String_Monday));
    laWidget_AddChild((laWidget*)PanelWidget_Daily, (laWidget*)LabelWidget_Monday);

    LabelWidget_Tuesday = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_Tuesday, 100, 0);
    laWidget_SetSize((laWidget*)LabelWidget_Tuesday, 38, 30);
    laWidget_SetScheme((laWidget*)LabelWidget_Tuesday, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_Tuesday, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_Tuesday, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_Tuesday, laString_CreateFromID(string_String_Tuesday));
    laWidget_AddChild((laWidget*)PanelWidget_Daily, (laWidget*)LabelWidget_Tuesday);

    LabelWidget_Wednesday = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_Wednesday, 128, 0);
    laWidget_SetSize((laWidget*)LabelWidget_Wednesday, 38, 30);
    laWidget_SetScheme((laWidget*)LabelWidget_Wednesday, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_Wednesday, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_Wednesday, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_Wednesday, laString_CreateFromID(string_String_Wednesday));
    laWidget_AddChild((laWidget*)PanelWidget_Daily, (laWidget*)LabelWidget_Wednesday);

    LabelWidget_Thursday = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_Thursday, 158, 0);
    laWidget_SetSize((laWidget*)LabelWidget_Thursday, 38, 30);
    laWidget_SetScheme((laWidget*)LabelWidget_Thursday, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_Thursday, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_Thursday, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_Thursday, laString_CreateFromID(string_String_Thursday));
    laWidget_AddChild((laWidget*)PanelWidget_Daily, (laWidget*)LabelWidget_Thursday);

    LabelWidget_Friday = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_Friday, 188, 0);
    laWidget_SetSize((laWidget*)LabelWidget_Friday, 38, 30);
    laWidget_SetScheme((laWidget*)LabelWidget_Friday, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_Friday, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_Friday, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_Friday, laString_CreateFromID(string_String_Friday));
    laWidget_AddChild((laWidget*)PanelWidget_Daily, (laWidget*)LabelWidget_Friday);

    LabelWidget_Saturday = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget_Saturday, 220, 0);
    laWidget_SetSize((laWidget*)LabelWidget_Saturday, 38, 30);
    laWidget_SetScheme((laWidget*)LabelWidget_Saturday, &TextGrey);
    laWidget_SetBackgroundType((laWidget*)LabelWidget_Saturday, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget_Saturday, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget_Saturday, laString_CreateFromID(string_String_Saturday));
    laWidget_AddChild((laWidget*)PanelWidget_Daily, (laWidget*)LabelWidget_Saturday);

}



