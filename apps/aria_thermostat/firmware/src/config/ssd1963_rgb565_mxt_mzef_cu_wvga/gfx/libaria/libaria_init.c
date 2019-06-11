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
laScheme whiteScheme;
laScheme mainScheme;
laImageWidget* Pic32Logo;
laImageWidget* HarmonyLogoWidget;
laImageWidget* SplashBar;
laImageWidget* SplashBarLogo;
laImageWidget* ImageWidget_Backplate;
laImageWidget* ImageWidget_FrontTopLeft;
laImageWidget* ImageWidget_FrontTopMiddle;
laImageWidget* ImageWidget_FrontTopRight;
laImageWidget* ImageWidget_FrontMiddleLeft;
laImageWidget* ImageWidget_FrontMiddle;
laImageWidget* ImageWidget_FrontMiddleRight;
laImageWidget* ImageWidget_FrontBottomLeft;
laImageWidget* ImageWidget_BottomMiddle;
laImageWidget* ImageWidget_BottomRight;
laArcWidget* ArcWidget_Indicator;
laCircularSliderWidget* CircularSlider_TouchTrack;


static void ScreenCreate_SplashScreen(laScreen* screen);
static void ScreenCreate_MainScreen(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&defaultScheme, GFX_COLOR_MODE_RGB_565);
    defaultScheme.base = 0xC67A;
    defaultScheme.highlight = 0xC67A;
    defaultScheme.highlightLight = 0xFFFF;
    defaultScheme.shadow = 0x8410;
    defaultScheme.shadowDark = 0x4208;
    defaultScheme.foreground = 0x0;
    defaultScheme.foregroundInactive = 0xD71C;
    defaultScheme.foregroundDisabled = 0x8410;
    defaultScheme.background = 0xFFFF;
    defaultScheme.backgroundInactive = 0xD71C;
    defaultScheme.backgroundDisabled = 0xC67A;
    defaultScheme.text = 0x0;
    defaultScheme.textHighlight = 0x1F;
    defaultScheme.textHighlightText = 0xFFFF;
    defaultScheme.textInactive = 0xD71C;
    defaultScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&whiteScheme, GFX_COLOR_MODE_RGB_565);
    whiteScheme.base = 0xFFFF;
    whiteScheme.highlight = 0xC67A;
    whiteScheme.highlightLight = 0xFFFF;
    whiteScheme.shadow = 0x8410;
    whiteScheme.shadowDark = 0x4208;
    whiteScheme.foreground = 0xFFFF;
    whiteScheme.foregroundInactive = 0xD71C;
    whiteScheme.foregroundDisabled = 0x8410;
    whiteScheme.background = 0xFFFF;
    whiteScheme.backgroundInactive = 0xD71C;
    whiteScheme.backgroundDisabled = 0xC67A;
    whiteScheme.text = 0x0;
    whiteScheme.textHighlight = 0x1F;
    whiteScheme.textHighlightText = 0xFFFF;
    whiteScheme.textInactive = 0xD71C;
    whiteScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&mainScheme, GFX_COLOR_MODE_RGB_565);
    mainScheme.base = 0x1F;
    mainScheme.highlight = 0xC67A;
    mainScheme.highlightLight = 0xFFFF;
    mainScheme.shadow = 0x8410;
    mainScheme.shadowDark = 0x4208;
    mainScheme.foreground = 0x0;
    mainScheme.foregroundInactive = 0x1F;
    mainScheme.foregroundDisabled = 0x8410;
    mainScheme.background = 0xFFFF;
    mainScheme.backgroundInactive = 0xD71C;
    mainScheme.backgroundDisabled = 0xC67A;
    mainScheme.text = 0x0;
    mainScheme.textHighlight = 0x1F;
    mainScheme.textHighlightText = 0xFFFF;
    mainScheme.textInactive = 0xD71C;
    mainScheme.textDisabled = 0x8C92;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_SplashScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_MainScreen);
    laContext_AddScreen(screen);

    laContext_SetActiveScreen(0);

	return 0;
}

static void ScreenCreate_SplashScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 800, 480);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    Pic32Logo = laImageWidget_New();
    laWidget_SetPosition((laWidget*)Pic32Logo, 221, 94);
    laWidget_SetSize((laWidget*)Pic32Logo, 372, 210);
    laWidget_SetOptimizationFlags((laWidget*)Pic32Logo, LA_WIDGET_OPT_OPAQUE);
    laWidget_SetBackgroundType((laWidget*)Pic32Logo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)Pic32Logo, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(Pic32Logo, &PIC32Logo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)Pic32Logo);

    HarmonyLogoWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)HarmonyLogoWidget, 221, 94);
    laWidget_SetSize((laWidget*)HarmonyLogoWidget, 372, 210);
    laWidget_SetEnabled((laWidget*)HarmonyLogoWidget, LA_FALSE);
    laWidget_SetVisible((laWidget*)HarmonyLogoWidget, LA_FALSE);
    laWidget_SetOptimizationFlags((laWidget*)HarmonyLogoWidget, LA_WIDGET_OPT_OPAQUE);
    laWidget_SetScheme((laWidget*)HarmonyLogoWidget, &whiteScheme);
    laWidget_SetBackgroundType((laWidget*)HarmonyLogoWidget, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)HarmonyLogoWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(HarmonyLogoWidget, &MHGSLogo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)HarmonyLogoWidget);

    SplashBar = laImageWidget_New();
    laWidget_SetPosition((laWidget*)SplashBar, 800, 391);
    laWidget_SetSize((laWidget*)SplashBar, 800, 91);
    laWidget_SetOptimizationFlags((laWidget*)SplashBar, LA_WIDGET_OPT_OPAQUE);
    laWidget_SetBackgroundType((laWidget*)SplashBar, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SplashBar, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(SplashBar, &Bar);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)SplashBar);

    SplashBarLogo = laImageWidget_New();
    laWidget_SetPosition((laWidget*)SplashBarLogo, 18, 413);
    laWidget_SetSize((laWidget*)SplashBarLogo, 202, 55);
    laWidget_SetEnabled((laWidget*)SplashBarLogo, LA_FALSE);
    laWidget_SetVisible((laWidget*)SplashBarLogo, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)SplashBarLogo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SplashBarLogo, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(SplashBarLogo, &MicrochipLogo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)SplashBarLogo);

}

static void ScreenCreate_MainScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 800, 480);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget_Backplate = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget_Backplate, 160, 0);
    laWidget_SetSize((laWidget*)ImageWidget_Backplate, 480, 480);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget_Backplate, LA_WIDGET_OPT_DRAW_ONCE | LA_WIDGET_OPT_OPAQUE);
    laWidget_SetBackgroundType((laWidget*)ImageWidget_Backplate, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget_Backplate, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget_Backplate, &Backplate);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget_Backplate);

    ImageWidget_FrontTopLeft = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget_FrontTopLeft, 251, 90);
    laWidget_SetSize((laWidget*)ImageWidget_FrontTopLeft, 100, 100);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget_FrontTopLeft, LA_WIDGET_OPT_LOCAL_REDRAW | LA_WIDGET_OPT_OPAQUE);
    laWidget_SetBackgroundType((laWidget*)ImageWidget_FrontTopLeft, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget_FrontTopLeft, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget_FrontTopLeft, &Front_TopLeft);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget_FrontTopLeft);

    ImageWidget_FrontTopMiddle = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget_FrontTopMiddle, 351, 90);
    laWidget_SetSize((laWidget*)ImageWidget_FrontTopMiddle, 100, 100);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget_FrontTopMiddle, LA_WIDGET_OPT_LOCAL_REDRAW | LA_WIDGET_OPT_OPAQUE);
    laWidget_SetBackgroundType((laWidget*)ImageWidget_FrontTopMiddle, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget_FrontTopMiddle, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget_FrontTopMiddle, &Front_TopMiddle);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget_FrontTopMiddle);

    ImageWidget_FrontTopRight = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget_FrontTopRight, 451, 90);
    laWidget_SetSize((laWidget*)ImageWidget_FrontTopRight, 100, 100);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget_FrontTopRight, LA_WIDGET_OPT_LOCAL_REDRAW | LA_WIDGET_OPT_OPAQUE);
    laWidget_SetBackgroundType((laWidget*)ImageWidget_FrontTopRight, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget_FrontTopRight, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget_FrontTopRight, &Front_TopRight);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget_FrontTopRight);

    ImageWidget_FrontMiddleLeft = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget_FrontMiddleLeft, 251, 190);
    laWidget_SetSize((laWidget*)ImageWidget_FrontMiddleLeft, 100, 100);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget_FrontMiddleLeft, LA_WIDGET_OPT_LOCAL_REDRAW | LA_WIDGET_OPT_OPAQUE);
    laWidget_SetBackgroundType((laWidget*)ImageWidget_FrontMiddleLeft, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget_FrontMiddleLeft, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget_FrontMiddleLeft, &Front_MiddleLeft);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget_FrontMiddleLeft);

    ImageWidget_FrontMiddle = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget_FrontMiddle, 351, 190);
    laWidget_SetSize((laWidget*)ImageWidget_FrontMiddle, 100, 100);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget_FrontMiddle, LA_WIDGET_OPT_LOCAL_REDRAW | LA_WIDGET_OPT_OPAQUE);
    laWidget_SetBackgroundType((laWidget*)ImageWidget_FrontMiddle, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget_FrontMiddle, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget_FrontMiddle, &Front_Middle);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget_FrontMiddle);

    ImageWidget_FrontMiddleRight = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget_FrontMiddleRight, 451, 190);
    laWidget_SetSize((laWidget*)ImageWidget_FrontMiddleRight, 100, 100);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget_FrontMiddleRight, LA_WIDGET_OPT_LOCAL_REDRAW | LA_WIDGET_OPT_OPAQUE);
    laWidget_SetBackgroundType((laWidget*)ImageWidget_FrontMiddleRight, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget_FrontMiddleRight, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget_FrontMiddleRight, &Front_MiddleRight);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget_FrontMiddleRight);

    ImageWidget_FrontBottomLeft = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget_FrontBottomLeft, 251, 290);
    laWidget_SetSize((laWidget*)ImageWidget_FrontBottomLeft, 100, 100);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget_FrontBottomLeft, LA_WIDGET_OPT_LOCAL_REDRAW | LA_WIDGET_OPT_OPAQUE);
    laWidget_SetBackgroundType((laWidget*)ImageWidget_FrontBottomLeft, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget_FrontBottomLeft, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget_FrontBottomLeft, &Front_BottomLeft);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget_FrontBottomLeft);

    ImageWidget_BottomMiddle = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget_BottomMiddle, 351, 290);
    laWidget_SetSize((laWidget*)ImageWidget_BottomMiddle, 100, 100);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget_BottomMiddle, LA_WIDGET_OPT_LOCAL_REDRAW | LA_WIDGET_OPT_OPAQUE);
    laWidget_SetBackgroundType((laWidget*)ImageWidget_BottomMiddle, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget_BottomMiddle, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget_BottomMiddle, &Front_BottomMiddle);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget_BottomMiddle);

    ImageWidget_BottomRight = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget_BottomRight, 451, 290);
    laWidget_SetSize((laWidget*)ImageWidget_BottomRight, 100, 100);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget_BottomRight, LA_WIDGET_OPT_LOCAL_REDRAW | LA_WIDGET_OPT_OPAQUE);
    laWidget_SetBackgroundType((laWidget*)ImageWidget_BottomRight, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget_BottomRight, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget_BottomRight, &Front_BottomRight);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget_BottomRight);

    ArcWidget_Indicator = laArcWidget_New();
    laWidget_SetPosition((laWidget*)ArcWidget_Indicator, 260, 114);
    laWidget_SetSize((laWidget*)ArcWidget_Indicator, 282, 282);
    laWidget_SetOptimizationFlags((laWidget*)ArcWidget_Indicator, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)ArcWidget_Indicator, &whiteScheme);
    laWidget_SetBackgroundType((laWidget*)ArcWidget_Indicator, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ArcWidget_Indicator, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(ArcWidget_Indicator, 138);
    laArcWidget_SetStartAngle(ArcWidget_Indicator, 88);
    laArcWidget_SetCenterAngle(ArcWidget_Indicator, 3);
    laArcWidget_SetThickness(ArcWidget_Indicator, 50);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ArcWidget_Indicator);

    CircularSlider_TouchTrack = laCircularSliderWidget_New();
    laWidget_SetSize((laWidget*)CircularSlider_TouchTrack, 282, 282);
    laWidget_SetOptimizationFlags((laWidget*)CircularSlider_TouchTrack, LA_WIDGET_OPT_LOCAL_REDRAW | LA_WIDGET_OPT_DRAW_ONCE);
    laWidget_SetBackgroundType((laWidget*)CircularSlider_TouchTrack, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CircularSlider_TouchTrack, LA_WIDGET_BORDER_NONE);
    laCircularSliderWidget_SetRadius(CircularSlider_TouchTrack, 140);
    laCircularSliderWidget_SetValue(CircularSlider_TouchTrack, 88);
    laCircularSliderWidget_SetEndValue(CircularSlider_TouchTrack, 360);
    laCircularSliderWidget_SetRoundEdges(CircularSlider_TouchTrack, LA_FALSE);
    laCircularSliderWidget_SetStickyButton(CircularSlider_TouchTrack, LA_FALSE);
    laCircularSliderWidget_SetTouchOnButtonOnly(CircularSlider_TouchTrack, LA_FALSE);
    laCircularSliderWidget_SetArcVisible(CircularSlider_TouchTrack, OUTSIDE_CIRCLE_BORDER, LA_FALSE);
    laCircularSliderWidget_SetArcThickness(CircularSlider_TouchTrack, OUTSIDE_CIRCLE_BORDER, 0);
    laCircularSliderWidget_SetArcVisible(CircularSlider_TouchTrack, INSIDE_CIRCLE_BORDER, LA_FALSE);
    laCircularSliderWidget_SetArcThickness(CircularSlider_TouchTrack, INSIDE_CIRCLE_BORDER, 0);
    laCircularSliderWidget_SetArcVisible(CircularSlider_TouchTrack, ACTIVE_AREA, LA_FALSE);
    laCircularSliderWidget_SetArcThickness(CircularSlider_TouchTrack, ACTIVE_AREA, 45);
    laCircularSliderWidget_SetArcVisible(CircularSlider_TouchTrack, INACTIVE_AREA, LA_FALSE);
    laCircularSliderWidget_SetArcVisible(CircularSlider_TouchTrack, CIRCLE_BUTTON, LA_FALSE);
    laCircularSliderWidget_SetArcRadius(CircularSlider_TouchTrack, CIRCLE_BUTTON, 25);
    laCircularSliderWidget_SetArcThickness(CircularSlider_TouchTrack, CIRCLE_BUTTON, 0);
    laCircularSliderWidget_SetValueChangedEventCallback(CircularSlider_TouchTrack, &CircularSlider_TouchTrack_ValueChangedEvent);
    laCircularSliderWidget_SetPressedEventCallback(CircularSlider_TouchTrack, &CircularSlider_TouchTrack_PressedEvent);
    laCircularSliderWidget_SetReleasedEventCallback(CircularSlider_TouchTrack, &CircularSlider_TouchTrack_ReleasedEvent);
    laWidget_AddChild((laWidget*)ArcWidget_Indicator, (laWidget*)CircularSlider_TouchTrack);

}




