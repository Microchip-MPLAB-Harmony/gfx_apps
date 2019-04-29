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
#include "gfx/libaria/inc/libaria_utils.h"

laScheme defaultScheme;
laScheme GreenScheme;
laScheme ClearScheme;
laScheme OrangeFillScheme;
laScheme RedFillScheme;
laScheme WhiteScheme;
laScheme YellowScheme;
laScheme BlackBackWhiteTextScheme;
laScheme WhiteFillScheme;
laImageWidget* ImageWidget1;
laImageWidget* ImageWidget4;
laImageWidget* ImageWidget3;
laImageWidget* BackgroundImageWidget;
laLabelWidget* ClimateControlUnitLabelWidget;
laLabelWidget* MPHLabelWidget;
laLabelWidget* OdoMilesLabelWidget;
laDrawSurfaceWidget* TachoDrawSurface;
laLabelWidget* SpeedoLabelWidget;
laRectangleWidget* GasGauge100Rect;
laRectangleWidget* GasGauge90Rect;
laRectangleWidget* GasGauge80Rect;
laRectangleWidget* GasGauge70Rect;
laRectangleWidget* GasGauge60Rect;
laRectangleWidget* GasGauge50Rect;
laRectangleWidget* GasGauge40Rect;
laRectangleWidget* GasGauge30Rect;
laRectangleWidget* GasGauge20Rect;
laRectangleWidget* GasGauge10Rect;
laRectangleWidget* GasGauge0Rect;
laLabelWidget* ClimateControlLabelWidget;
laLabelWidget* TripBLabelWidget;
laLabelWidget* OdometerLabelWidget;
laLabelWidget* TripALabelWidget;
laLabelWidget* MPGLabelWidget;
laLabelWidget* MPGUnitLabelWidget;
laImageWidget* TurnLeftImageWidget;
laImageWidget* TurnRightImageWidget;
laImageWidget* GPSBaseImageWidget;
laImageWidget* IndicatorLightsOnImageWidget;
laImageWidget* DriveModeImageWidget;
laLabelWidget* GearLabelWidget;
laCircleWidget* NeedleCenter;
laButtonWidget* CenterButtonWidget;
laButtonWidget* EngineOnButton;


static void ScreenCreate_Splash(laScreen* screen);
static void ScreenCreate_Main(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&defaultScheme, GFX_COLOR_MODE_RGBA_8888);
    defaultScheme.base = 0xC8D0D4FF;
    defaultScheme.highlight = 0xC8D0D4FF;
    defaultScheme.highlightLight = 0xFFFFFFFF;
    defaultScheme.shadow = 0x808080FF;
    defaultScheme.shadowDark = 0x404040FF;
    defaultScheme.foreground = 0xFF;
    defaultScheme.foregroundInactive = 0xD6E3E7FF;
    defaultScheme.foregroundDisabled = 0x808080FF;
    defaultScheme.background = 0xFFFFFFFF;
    defaultScheme.backgroundInactive = 0xD6E3E7FF;
    defaultScheme.backgroundDisabled = 0xC8D0D4FF;
    defaultScheme.text = 0xFF;
    defaultScheme.textHighlight = 0xFFFF;
    defaultScheme.textHighlightText = 0xFFFFFFFF;
    defaultScheme.textInactive = 0xD6E3E7FF;
    defaultScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&GreenScheme, GFX_COLOR_MODE_RGBA_8888);
    GreenScheme.base = 0xFF00FF;
    GreenScheme.highlight = 0xC8D0D4FF;
    GreenScheme.highlightLight = 0xFFFFFFFF;
    GreenScheme.shadow = 0x808080FF;
    GreenScheme.shadowDark = 0x404040FF;
    GreenScheme.foreground = 0xFF00FF;
    GreenScheme.foregroundInactive = 0xD6E3E7FF;
    GreenScheme.foregroundDisabled = 0x808080FF;
    GreenScheme.background = 0xFF00FF;
    GreenScheme.backgroundInactive = 0xD6E3E7FF;
    GreenScheme.backgroundDisabled = 0xC8D0D4FF;
    GreenScheme.text = 0xFF;
    GreenScheme.textHighlight = 0xFFFF;
    GreenScheme.textHighlightText = 0xFFFFFFFF;
    GreenScheme.textInactive = 0xD6E3E7FF;
    GreenScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&ClearScheme, GFX_COLOR_MODE_RGBA_8888);
    ClearScheme.base = 0xC8D0D4FF;
    ClearScheme.highlight = 0xC8D0D4FF;
    ClearScheme.highlightLight = 0xFFFFFFFF;
    ClearScheme.shadow = 0x808080FF;
    ClearScheme.shadowDark = 0x404040FF;
    ClearScheme.foreground = 0xFF;
    ClearScheme.foregroundInactive = 0xD6E3E7FF;
    ClearScheme.foregroundDisabled = 0x808080FF;
    ClearScheme.background = 0x0;
    ClearScheme.backgroundInactive = 0xD6E3E7FF;
    ClearScheme.backgroundDisabled = 0xC8D0D4FF;
    ClearScheme.text = 0xFF;
    ClearScheme.textHighlight = 0xFFFF;
    ClearScheme.textHighlightText = 0xFFFFFFFF;
    ClearScheme.textInactive = 0xD6E3E7FF;
    ClearScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&OrangeFillScheme, GFX_COLOR_MODE_RGBA_8888);
    OrangeFillScheme.base = 0xFF8000FF;
    OrangeFillScheme.highlight = 0xC8D0D4FF;
    OrangeFillScheme.highlightLight = 0xFFFFFFFF;
    OrangeFillScheme.shadow = 0x808080FF;
    OrangeFillScheme.shadowDark = 0x404040FF;
    OrangeFillScheme.foreground = 0xFF8000FF;
    OrangeFillScheme.foregroundInactive = 0xD6E3E7FF;
    OrangeFillScheme.foregroundDisabled = 0x808080FF;
    OrangeFillScheme.background = 0xFFFFFFFF;
    OrangeFillScheme.backgroundInactive = 0xD6E3E7FF;
    OrangeFillScheme.backgroundDisabled = 0xC8D0D4FF;
    OrangeFillScheme.text = 0xFF;
    OrangeFillScheme.textHighlight = 0xFFFF;
    OrangeFillScheme.textHighlightText = 0xFFFFFFFF;
    OrangeFillScheme.textInactive = 0xD6E3E7FF;
    OrangeFillScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&RedFillScheme, GFX_COLOR_MODE_RGBA_8888);
    RedFillScheme.base = 0xFF0000FF;
    RedFillScheme.highlight = 0xC8D0D4FF;
    RedFillScheme.highlightLight = 0xFFFFFFFF;
    RedFillScheme.shadow = 0x808080FF;
    RedFillScheme.shadowDark = 0x404040FF;
    RedFillScheme.foreground = 0xFF0000FF;
    RedFillScheme.foregroundInactive = 0xD6E3E7FF;
    RedFillScheme.foregroundDisabled = 0x808080FF;
    RedFillScheme.background = 0xFFFFFFFF;
    RedFillScheme.backgroundInactive = 0xD6E3E7FF;
    RedFillScheme.backgroundDisabled = 0xC8D0D4FF;
    RedFillScheme.text = 0xFF;
    RedFillScheme.textHighlight = 0xFFFF;
    RedFillScheme.textHighlightText = 0xFFFFFFFF;
    RedFillScheme.textInactive = 0xD6E3E7FF;
    RedFillScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&WhiteScheme, GFX_COLOR_MODE_RGBA_8888);
    WhiteScheme.base = 0xFFFFFFFF;
    WhiteScheme.highlight = 0xC8D0D4FF;
    WhiteScheme.highlightLight = 0xFFFFFFFF;
    WhiteScheme.shadow = 0x808080FF;
    WhiteScheme.shadowDark = 0x404040FF;
    WhiteScheme.foreground = 0xFFFFFFFF;
    WhiteScheme.foregroundInactive = 0xD6E3E7FF;
    WhiteScheme.foregroundDisabled = 0x808080FF;
    WhiteScheme.background = 0xFFFFFFFF;
    WhiteScheme.backgroundInactive = 0xD6E3E7FF;
    WhiteScheme.backgroundDisabled = 0xC8D0D4FF;
    WhiteScheme.text = 0xFF;
    WhiteScheme.textHighlight = 0xFFFF;
    WhiteScheme.textHighlightText = 0xFFFFFFFF;
    WhiteScheme.textInactive = 0xD6E3E7FF;
    WhiteScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&YellowScheme, GFX_COLOR_MODE_RGBA_8888);
    YellowScheme.base = 0xFFFF00FF;
    YellowScheme.highlight = 0xC8D0D4FF;
    YellowScheme.highlightLight = 0xFFFFFFFF;
    YellowScheme.shadow = 0x808080FF;
    YellowScheme.shadowDark = 0x404040FF;
    YellowScheme.foreground = 0xFFFF00FF;
    YellowScheme.foregroundInactive = 0xD6E3E7FF;
    YellowScheme.foregroundDisabled = 0x808080FF;
    YellowScheme.background = 0xFFFFFFFF;
    YellowScheme.backgroundInactive = 0xD6E3E7FF;
    YellowScheme.backgroundDisabled = 0xC8D0D4FF;
    YellowScheme.text = 0xFF;
    YellowScheme.textHighlight = 0xFFFF;
    YellowScheme.textHighlightText = 0xFFFFFFFF;
    YellowScheme.textInactive = 0xD6E3E7FF;
    YellowScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&BlackBackWhiteTextScheme, GFX_COLOR_MODE_RGBA_8888);
    BlackBackWhiteTextScheme.base = 0xFF;
    BlackBackWhiteTextScheme.highlight = 0xC8D0D4FF;
    BlackBackWhiteTextScheme.highlightLight = 0xFFFFFFFF;
    BlackBackWhiteTextScheme.shadow = 0x808080FF;
    BlackBackWhiteTextScheme.shadowDark = 0x404040FF;
    BlackBackWhiteTextScheme.foreground = 0xFF;
    BlackBackWhiteTextScheme.foregroundInactive = 0xD6E3E7FF;
    BlackBackWhiteTextScheme.foregroundDisabled = 0x808080FF;
    BlackBackWhiteTextScheme.background = 0xFF;
    BlackBackWhiteTextScheme.backgroundInactive = 0xD6E3E7FF;
    BlackBackWhiteTextScheme.backgroundDisabled = 0xC8D0D4FF;
    BlackBackWhiteTextScheme.text = 0xFFFFFFFF;
    BlackBackWhiteTextScheme.textHighlight = 0xFFFF;
    BlackBackWhiteTextScheme.textHighlightText = 0xFFFFFFFF;
    BlackBackWhiteTextScheme.textInactive = 0xD6E3E7FF;
    BlackBackWhiteTextScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&WhiteFillScheme, GFX_COLOR_MODE_RGBA_8888);
    WhiteFillScheme.base = 0xC8D0D4FF;
    WhiteFillScheme.highlight = 0xC8D0D4FF;
    WhiteFillScheme.highlightLight = 0xFFFFFFFF;
    WhiteFillScheme.shadow = 0x808080FF;
    WhiteFillScheme.shadowDark = 0x404040FF;
    WhiteFillScheme.foreground = 0xFFFFFFFF;
    WhiteFillScheme.foregroundInactive = 0xD6E3E7FF;
    WhiteFillScheme.foregroundDisabled = 0x808080FF;
    WhiteFillScheme.background = 0xFF0000FF;
    WhiteFillScheme.backgroundInactive = 0xD6E3E7FF;
    WhiteFillScheme.backgroundDisabled = 0xC8D0D4FF;
    WhiteFillScheme.text = 0xFF;
    WhiteFillScheme.textHighlight = 0xFFFF;
    WhiteFillScheme.textHighlightText = 0xFFFFFFFF;
    WhiteFillScheme.textInactive = 0xD6E3E7FF;
    WhiteFillScheme.textDisabled = 0x8C9294FF;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    laContext_SetStringTable(&stringTable);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_Splash);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_Main);
    laContext_AddScreen(screen);

    laContext_SetActiveScreen(0);

	return 0;
}

static void ScreenCreate_Splash(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 800, 480);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &defaultScheme);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget1 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget1, 214, 92);
    laWidget_SetSize((laWidget*)ImageWidget1, 372, 214);
    laWidget_SetScheme((laWidget*)ImageWidget1, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageWidget1, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget1, &PIC100MPLAB0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget1);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 800, 480);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);

    laScreen_SetLayer(screen, 1, layer1);

    ImageWidget4 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget4, 11, 417);
    laWidget_SetSize((laWidget*)ImageWidget4, 202, 55);
    laWidget_SetVisible((laWidget*)ImageWidget4, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)ImageWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget4, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget4, &MicrochipLogo);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)ImageWidget4);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 800, 480);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);

    laScreen_SetLayer(screen, 2, layer2);

    ImageWidget3 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget3, 801, 389);
    laWidget_SetSize((laWidget*)ImageWidget3, 800, 91);
    laWidget_SetBackgroundType((laWidget*)ImageWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget3, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget3, &Bar);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)ImageWidget3);

}

static void ScreenCreate_Main(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 800, 480);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetScheme((laWidget*)layer0, &BlackBackWhiteTextScheme);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    BackgroundImageWidget = laImageWidget_New();
    laWidget_SetSize((laWidget*)BackgroundImageWidget, 800, 480);
    laWidget_SetScheme((laWidget*)BackgroundImageWidget, &BlackBackWhiteTextScheme);
    laWidget_SetBackgroundType((laWidget*)BackgroundImageWidget, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)BackgroundImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(BackgroundImageWidget, &BackGroundWVGA);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)BackgroundImageWidget);

    ClimateControlUnitLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)ClimateControlUnitLabelWidget, 178, 396);
    laWidget_SetSize((laWidget*)ClimateControlUnitLabelWidget, 23, 25);
    laWidget_SetScheme((laWidget*)ClimateControlUnitLabelWidget, &BlackBackWhiteTextScheme);
    laWidget_SetBackgroundType((laWidget*)ClimateControlUnitLabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ClimateControlUnitLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(ClimateControlUnitLabelWidget, laString_CreateFromID(string_ClimateControlUnitStringDefault));
    laLabelWidget_SetHAlignment(ClimateControlUnitLabelWidget, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ClimateControlUnitLabelWidget);

    MPHLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)MPHLabelWidget, 741, 400);
    laWidget_SetSize((laWidget*)MPHLabelWidget, 50, 25);
    laWidget_SetScheme((laWidget*)MPHLabelWidget, &BlackBackWhiteTextScheme);
    laWidget_SetBackgroundType((laWidget*)MPHLabelWidget, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)MPHLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(MPHLabelWidget, laString_CreateFromID(string_MPHLabelString));
    laLabelWidget_SetHAlignment(MPHLabelWidget, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)MPHLabelWidget);

    OdoMilesLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)OdoMilesLabelWidget, 145, 254);
    laWidget_SetSize((laWidget*)OdoMilesLabelWidget, 26, 13);
    laWidget_SetScheme((laWidget*)OdoMilesLabelWidget, &BlackBackWhiteTextScheme);
    laWidget_SetBackgroundType((laWidget*)OdoMilesLabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)OdoMilesLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(OdoMilesLabelWidget, laString_CreateFromID(string_OdoMilesLabelString));
    laLabelWidget_SetHAlignment(OdoMilesLabelWidget, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)OdoMilesLabelWidget);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 800, 480);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);

    laScreen_SetLayer(screen, 1, layer1);

    TachoDrawSurface = laDrawSurfaceWidget_New();
    laWidget_SetPosition((laWidget*)TachoDrawSurface, 240, 80);
    laWidget_SetSize((laWidget*)TachoDrawSurface, 320, 320);
    laWidget_SetBackgroundType((laWidget*)TachoDrawSurface, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TachoDrawSurface, LA_WIDGET_BORDER_NONE);
    laDrawSurfaceWidget_SetDrawCallback(TachoDrawSurface, &TachoDrawSurface_DrawNotificationEvent);

    laWidget_AddChild((laWidget*)layer1, (laWidget*)TachoDrawSurface);

    SpeedoLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)SpeedoLabelWidget, 570, 350);
    laWidget_SetSize((laWidget*)SpeedoLabelWidget, 170, 81);
    laWidget_SetVisible((laWidget*)SpeedoLabelWidget, LA_FALSE);
    laWidget_SetScheme((laWidget*)SpeedoLabelWidget, &BlackBackWhiteTextScheme);
    laWidget_SetBackgroundType((laWidget*)SpeedoLabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SpeedoLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(SpeedoLabelWidget, laString_CreateFromID(string_SpeedoLabelStringDefault));
    laLabelWidget_SetHAlignment(SpeedoLabelWidget, LA_HALIGN_RIGHT);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)SpeedoLabelWidget);

    GasGauge100Rect = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)GasGauge100Rect, 172, 267);
    laWidget_SetSize((laWidget*)GasGauge100Rect, 25, 8);
    laWidget_SetVisible((laWidget*)GasGauge100Rect, LA_FALSE);
    laWidget_SetScheme((laWidget*)GasGauge100Rect, &GreenScheme);
    laWidget_SetBackgroundType((laWidget*)GasGauge100Rect, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GasGauge100Rect, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(GasGauge100Rect, 0);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)GasGauge100Rect);

    GasGauge90Rect = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)GasGauge90Rect, 175, 277);
    laWidget_SetSize((laWidget*)GasGauge90Rect, 23, 8);
    laWidget_SetVisible((laWidget*)GasGauge90Rect, LA_FALSE);
    laWidget_SetScheme((laWidget*)GasGauge90Rect, &GreenScheme);
    laWidget_SetBackgroundType((laWidget*)GasGauge90Rect, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GasGauge90Rect, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(GasGauge90Rect, 0);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)GasGauge90Rect);

    GasGauge80Rect = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)GasGauge80Rect, 179, 287);
    laWidget_SetSize((laWidget*)GasGauge80Rect, 21, 8);
    laWidget_SetVisible((laWidget*)GasGauge80Rect, LA_FALSE);
    laWidget_SetScheme((laWidget*)GasGauge80Rect, &GreenScheme);
    laWidget_SetBackgroundType((laWidget*)GasGauge80Rect, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GasGauge80Rect, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(GasGauge80Rect, 0);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)GasGauge80Rect);

    GasGauge70Rect = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)GasGauge70Rect, 183, 297);
    laWidget_SetSize((laWidget*)GasGauge70Rect, 19, 8);
    laWidget_SetVisible((laWidget*)GasGauge70Rect, LA_FALSE);
    laWidget_SetScheme((laWidget*)GasGauge70Rect, &GreenScheme);
    laWidget_SetBackgroundType((laWidget*)GasGauge70Rect, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GasGauge70Rect, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(GasGauge70Rect, 0);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)GasGauge70Rect);

    GasGauge60Rect = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)GasGauge60Rect, 189, 307);
    laWidget_SetSize((laWidget*)GasGauge60Rect, 17, 8);
    laWidget_SetVisible((laWidget*)GasGauge60Rect, LA_FALSE);
    laWidget_SetScheme((laWidget*)GasGauge60Rect, &YellowScheme);
    laWidget_SetBackgroundType((laWidget*)GasGauge60Rect, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GasGauge60Rect, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(GasGauge60Rect, 0);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)GasGauge60Rect);

    GasGauge50Rect = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)GasGauge50Rect, 195, 317);
    laWidget_SetSize((laWidget*)GasGauge50Rect, 15, 8);
    laWidget_SetVisible((laWidget*)GasGauge50Rect, LA_FALSE);
    laWidget_SetScheme((laWidget*)GasGauge50Rect, &YellowScheme);
    laWidget_SetBackgroundType((laWidget*)GasGauge50Rect, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GasGauge50Rect, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(GasGauge50Rect, 0);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)GasGauge50Rect);

    GasGauge40Rect = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)GasGauge40Rect, 202, 327);
    laWidget_SetSize((laWidget*)GasGauge40Rect, 13, 8);
    laWidget_SetVisible((laWidget*)GasGauge40Rect, LA_FALSE);
    laWidget_SetScheme((laWidget*)GasGauge40Rect, &YellowScheme);
    laWidget_SetBackgroundType((laWidget*)GasGauge40Rect, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GasGauge40Rect, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(GasGauge40Rect, 0);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)GasGauge40Rect);

    GasGauge30Rect = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)GasGauge30Rect, 210, 337);
    laWidget_SetSize((laWidget*)GasGauge30Rect, 11, 8);
    laWidget_SetVisible((laWidget*)GasGauge30Rect, LA_FALSE);
    laWidget_SetScheme((laWidget*)GasGauge30Rect, &YellowScheme);
    laWidget_SetBackgroundType((laWidget*)GasGauge30Rect, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GasGauge30Rect, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(GasGauge30Rect, 0);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)GasGauge30Rect);

    GasGauge20Rect = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)GasGauge20Rect, 219, 347);
    laWidget_SetSize((laWidget*)GasGauge20Rect, 9, 8);
    laWidget_SetVisible((laWidget*)GasGauge20Rect, LA_FALSE);
    laWidget_SetScheme((laWidget*)GasGauge20Rect, &OrangeFillScheme);
    laWidget_SetBackgroundType((laWidget*)GasGauge20Rect, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GasGauge20Rect, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(GasGauge20Rect, 0);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)GasGauge20Rect);

    GasGauge10Rect = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)GasGauge10Rect, 227, 357);
    laWidget_SetSize((laWidget*)GasGauge10Rect, 7, 8);
    laWidget_SetVisible((laWidget*)GasGauge10Rect, LA_FALSE);
    laWidget_SetScheme((laWidget*)GasGauge10Rect, &OrangeFillScheme);
    laWidget_SetBackgroundType((laWidget*)GasGauge10Rect, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GasGauge10Rect, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(GasGauge10Rect, 0);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)GasGauge10Rect);

    GasGauge0Rect = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)GasGauge0Rect, 235, 367);
    laWidget_SetSize((laWidget*)GasGauge0Rect, 5, 8);
    laWidget_SetScheme((laWidget*)GasGauge0Rect, &RedFillScheme);
    laWidget_SetBackgroundType((laWidget*)GasGauge0Rect, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GasGauge0Rect, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(GasGauge0Rect, 0);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)GasGauge0Rect);

    ClimateControlLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)ClimateControlLabelWidget, 112, 390);
    laWidget_SetSize((laWidget*)ClimateControlLabelWidget, 59, 50);
    laWidget_SetVisible((laWidget*)ClimateControlLabelWidget, LA_FALSE);
    laWidget_SetScheme((laWidget*)ClimateControlLabelWidget, &BlackBackWhiteTextScheme);
    laWidget_SetBackgroundType((laWidget*)ClimateControlLabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ClimateControlLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(ClimateControlLabelWidget, laString_CreateFromID(string_ClimateControlStringDefault));
    laLabelWidget_SetHAlignment(ClimateControlLabelWidget, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)ClimateControlLabelWidget);

    TripBLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)TripBLabelWidget, 76, 302);
    laWidget_SetSize((laWidget*)TripBLabelWidget, 45, 14);
    laWidget_SetVisible((laWidget*)TripBLabelWidget, LA_FALSE);
    laWidget_SetScheme((laWidget*)TripBLabelWidget, &BlackBackWhiteTextScheme);
    laWidget_SetBackgroundType((laWidget*)TripBLabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TripBLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(TripBLabelWidget, laString_CreateFromID(string_TripBStringDefault));
    laLabelWidget_SetHAlignment(TripBLabelWidget, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)TripBLabelWidget);

    OdometerLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)OdometerLabelWidget, 44, 250);
    laWidget_SetSize((laWidget*)OdometerLabelWidget, 96, 20);
    laWidget_SetVisible((laWidget*)OdometerLabelWidget, LA_FALSE);
    laWidget_SetScheme((laWidget*)OdometerLabelWidget, &BlackBackWhiteTextScheme);
    laWidget_SetBackgroundType((laWidget*)OdometerLabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)OdometerLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(OdometerLabelWidget, laString_CreateFromID(string_OdoLabelStringDefault));
    laLabelWidget_SetHAlignment(OdometerLabelWidget, LA_HALIGN_RIGHT);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)OdometerLabelWidget);

    TripALabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)TripALabelWidget, 76, 283);
    laWidget_SetSize((laWidget*)TripALabelWidget, 58, 14);
    laWidget_SetVisible((laWidget*)TripALabelWidget, LA_FALSE);
    laWidget_SetScheme((laWidget*)TripALabelWidget, &BlackBackWhiteTextScheme);
    laWidget_SetBackgroundType((laWidget*)TripALabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TripALabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(TripALabelWidget, laString_CreateFromID(string_TripAStringDefault));
    laLabelWidget_SetHAlignment(TripALabelWidget, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)TripALabelWidget);

    MPGLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)MPGLabelWidget, 73, 328);
    laWidget_SetSize((laWidget*)MPGLabelWidget, 44, 25);
    laWidget_SetVisible((laWidget*)MPGLabelWidget, LA_FALSE);
    laWidget_SetScheme((laWidget*)MPGLabelWidget, &BlackBackWhiteTextScheme);
    laWidget_SetBackgroundType((laWidget*)MPGLabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)MPGLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(MPGLabelWidget, laString_CreateFromID(string_MPGValueString));
    laLabelWidget_SetHAlignment(MPGLabelWidget, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)MPGLabelWidget);

    MPGUnitLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)MPGUnitLabelWidget, 120, 332);
    laWidget_SetSize((laWidget*)MPGUnitLabelWidget, 33, 20);
    laWidget_SetScheme((laWidget*)MPGUnitLabelWidget, &BlackBackWhiteTextScheme);
    laWidget_SetBackgroundType((laWidget*)MPGUnitLabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)MPGUnitLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(MPGUnitLabelWidget, laString_CreateFromID(string_MPGUnitString));
    laLabelWidget_SetHAlignment(MPGUnitLabelWidget, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)MPGUnitLabelWidget);

    TurnLeftImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)TurnLeftImageWidget, 274, 37);
    laWidget_SetSize((laWidget*)TurnLeftImageWidget, 31, 31);
    laWidget_SetVisible((laWidget*)TurnLeftImageWidget, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)TurnLeftImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TurnLeftImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(TurnLeftImageWidget, &TurnLeft);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)TurnLeftImageWidget);

    TurnRightImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)TurnRightImageWidget, 498, 38);
    laWidget_SetSize((laWidget*)TurnRightImageWidget, 31, 31);
    laWidget_SetVisible((laWidget*)TurnRightImageWidget, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)TurnRightImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TurnRightImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(TurnRightImageWidget, &TurnRight);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)TurnRightImageWidget);

    GPSBaseImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)GPSBaseImageWidget, 16, 92);
    laWidget_SetSize((laWidget*)GPSBaseImageWidget, 182, 150);
    laWidget_SetVisible((laWidget*)GPSBaseImageWidget, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)GPSBaseImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)GPSBaseImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(GPSBaseImageWidget, &Globe);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)GPSBaseImageWidget);

    IndicatorLightsOnImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)IndicatorLightsOnImageWidget, 580, 92);
    laWidget_SetSize((laWidget*)IndicatorLightsOnImageWidget, 206, 61);
    laWidget_SetVisible((laWidget*)IndicatorLightsOnImageWidget, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)IndicatorLightsOnImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)IndicatorLightsOnImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(IndicatorLightsOnImageWidget, &IndicatorLights);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)IndicatorLightsOnImageWidget);

    DriveModeImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)DriveModeImageWidget, 552, 62);
    laWidget_SetSize((laWidget*)DriveModeImageWidget, 243, 23);
    laWidget_SetVisible((laWidget*)DriveModeImageWidget, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)DriveModeImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)DriveModeImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(DriveModeImageWidget, &DriveModeSport);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)DriveModeImageWidget);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 800, 480);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);

    laScreen_SetLayer(screen, 2, layer2);

    GearLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)GearLabelWidget, 369, 290);
    laWidget_SetSize((laWidget*)GearLabelWidget, 60, 70);
    laWidget_SetScheme((laWidget*)GearLabelWidget, &BlackBackWhiteTextScheme);
    laWidget_SetBackgroundType((laWidget*)GearLabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)GearLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(GearLabelWidget, laString_CreateFromID(string_GearLabelStringDefault));
    laWidget_AddChild((laWidget*)layer2, (laWidget*)GearLabelWidget);

    NeedleCenter = laCircleWidget_New();
    laWidget_SetPosition((laWidget*)NeedleCenter, 390, 230);
    laWidget_SetSize((laWidget*)NeedleCenter, 20, 20);
    laWidget_SetScheme((laWidget*)NeedleCenter, &WhiteFillScheme);
    laWidget_SetBackgroundType((laWidget*)NeedleCenter, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)NeedleCenter, LA_WIDGET_BORDER_NONE);
    laCircleWidget_SetOrigin(NeedleCenter, 10, 10);
    laCircleWidget_SetRadius(NeedleCenter, 10);
    laCircleWidget_SetThickness(NeedleCenter, 1);
    laCircleWidget_SetFilled(NeedleCenter, true);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)NeedleCenter);

    CenterButtonWidget = laButtonWidget_New();
    laWidget_SetSize((laWidget*)CenterButtonWidget, 799, 480);
    laWidget_SetBackgroundType((laWidget*)CenterButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CenterButtonWidget, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)CenterButtonWidget);

    EngineOnButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)EngineOnButton, 329, 365);
    laWidget_SetSize((laWidget*)EngineOnButton, 150, 119);
    laWidget_SetBackgroundType((laWidget*)EngineOnButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)EngineOnButton, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)EngineOnButton, 4, 0, 4, 4);
    laButtonWidget_SetToggleable(EngineOnButton, LA_TRUE);
    laButtonWidget_SetVAlignment(EngineOnButton, LA_VALIGN_BOTTOM);
    laButtonWidget_SetPressedImage(EngineOnButton, &enginestartstop120on);
    laButtonWidget_SetReleasedImage(EngineOnButton, &enginestartstop120);
    laButtonWidget_SetPressedEventCallback(EngineOnButton, &EngineOnButton_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(EngineOnButton, &EngineOnButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)EngineOnButton);

}




