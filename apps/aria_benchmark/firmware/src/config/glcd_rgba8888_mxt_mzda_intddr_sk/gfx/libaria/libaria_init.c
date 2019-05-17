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

laScheme LightGreenBackgroundScheme;
laScheme LightPinkFillScheme;
laScheme LightBlueFillScheme;
laScheme ClearScheme;
laScheme LightBlueBackgroundScheme;
laScheme PurpleFillScheme;
laScheme RedFillScheme;
laScheme BlueFillScheme;
laScheme defaultScheme;
laScheme LightRedBackgroundScheme;
laScheme BrownFillScheme;
laScheme WhiteBackgroundScheme;
laScheme BlackFillScheme;
laScheme OrangeFillScheme;
laScheme PinkFillScheme;
laScheme YellowFillScheme;
laScheme WhiteFillScheme;
laImageWidget* Pic32Logo;
laImageWidget* SplashBar;
laImageWidget* HarmonyLogoWidget;
laImageWidget* SplashBarLogo;
laLabelWidget* Counter1LabelWidget;
laWidget* PanelWidget3;
laLabelWidget* LabelWidget4;
laLabelWidget* RefreshRateLabelWidget;
laLabelWidget* RefreshRateCountLabelWidget;
laButtonWidget* CounterSizeDownButton;
laButtonWidget* CounterSizeUpButton;
laLabelWidget* LabelWidget1;
laButtonWidget* NextButton;
laLabelWidget* StringSizeIdxLabel;
laLabelWidget* LabelWidget32;
laButtonWidget* ButtonWidget1;
laButtonWidget* FPSButtonCounter;
laRectangleWidget* RectMotionWidget10;
laRectangleWidget* RectMotionWidget9;
laRectangleWidget* RectMotionWidget8;
laRectangleWidget* RectMotionWidget7;
laRectangleWidget* RectMotionWidget6;
laRectangleWidget* RectMotionWidget5;
laRectangleWidget* RectMotionWidget4;
laRectangleWidget* RectMotionWidget3;
laRectangleWidget* RectMotionWidget2;
laRectangleWidget* RectMotionWidget1;
laWidget* PanelWidget2;
laLabelWidget* LabelWidget3;
laLabelWidget* LabelWidget5;
laLabelWidget* RefreshRateMotionLabelWidget;
laLabelWidget* LabelWidget10;
laButtonWidget* MotionMenuNextButton;
laButtonWidget* MotionMenuPlusButton;
laButtonWidget* MotionMenuMinusButton;
laLabelWidget* LabelWidget33;
laLabelWidget* NumRectCountLabel;
laLabelWidget* LabelWidget11;
laLabelWidget* SquareSizeLabel;
laButtonWidget* RectSizeDownButtonWidget;
laButtonWidget* RectSizeUpButtonWidget;
laButtonWidget* ButtonWidget2;
laButtonWidget* FPSButtonMotion;
laImageWidget* ImageRenderWidget;
laWidget* PanelWidget48;
laLabelWidget* LabelWidget49;
laLabelWidget* LabelWidget51;
laLabelWidget* ImageRefRateCountLabel;
laLabelWidget* LabelWidget53;
laButtonWidget* ImageNextButtonWidget;
laButtonWidget* ImageSizeDownButtonWidget;
laButtonWidget* ImageSizeUpButtonWidget;
laLabelWidget* LabelWidget57;
laLabelWidget* ImageSizeLabel;
laLabelWidget* LabelWidget;
laLabelWidget* ImageTypeLabel;
laButtonWidget* ImageTypePrevButtonWidget;
laButtonWidget* ImageTypeNextButtonWidget;
laButtonWidget* ButtonWidget3;
laButtonWidget* FPSButtonImages;


static void ScreenCreate_SplashScreen(laScreen* screen);
static void ScreenCreate_FPSCounters(laScreen* screen);
static void ScreenCreate_FPSMotion(laScreen* screen);
static void ScreenCreate_FPSImages(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&LightGreenBackgroundScheme, GFX_COLOR_MODE_RGBA_8888);
    LightGreenBackgroundScheme.base = 0xA5D29CFF;
    LightGreenBackgroundScheme.highlight = 0xC8D0D4FF;
    LightGreenBackgroundScheme.highlightLight = 0xFFFFFFFF;
    LightGreenBackgroundScheme.shadow = 0x808080FF;
    LightGreenBackgroundScheme.shadowDark = 0x404040FF;
    LightGreenBackgroundScheme.foreground = 0xFF;
    LightGreenBackgroundScheme.foregroundInactive = 0xD6E3E7FF;
    LightGreenBackgroundScheme.foregroundDisabled = 0x808080FF;
    LightGreenBackgroundScheme.background = 0xA5D29CFF;
    LightGreenBackgroundScheme.backgroundInactive = 0xD6E3E7FF;
    LightGreenBackgroundScheme.backgroundDisabled = 0xC8D0D4FF;
    LightGreenBackgroundScheme.text = 0xFF;
    LightGreenBackgroundScheme.textHighlight = 0xFFFF;
    LightGreenBackgroundScheme.textHighlightText = 0xFFFFFFFF;
    LightGreenBackgroundScheme.textInactive = 0xD6E3E7FF;
    LightGreenBackgroundScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&LightPinkFillScheme, GFX_COLOR_MODE_RGBA_8888);
    LightPinkFillScheme.base = 0xFFBEFFFF;
    LightPinkFillScheme.highlight = 0xC8D0D4FF;
    LightPinkFillScheme.highlightLight = 0xFFFFFFFF;
    LightPinkFillScheme.shadow = 0x808080FF;
    LightPinkFillScheme.shadowDark = 0x404040FF;
    LightPinkFillScheme.foreground = 0xFF;
    LightPinkFillScheme.foregroundInactive = 0xD6E3E7FF;
    LightPinkFillScheme.foregroundDisabled = 0x808080FF;
    LightPinkFillScheme.background = 0xFFFFFFFF;
    LightPinkFillScheme.backgroundInactive = 0xD6E3E7FF;
    LightPinkFillScheme.backgroundDisabled = 0xC8D0D4FF;
    LightPinkFillScheme.text = 0xFF;
    LightPinkFillScheme.textHighlight = 0xFFFF;
    LightPinkFillScheme.textHighlightText = 0xFFFFFFFF;
    LightPinkFillScheme.textInactive = 0xD6E3E7FF;
    LightPinkFillScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&LightBlueFillScheme, GFX_COLOR_MODE_RGBA_8888);
    LightBlueFillScheme.base = 0x84FFFFFF;
    LightBlueFillScheme.highlight = 0xC8D0D4FF;
    LightBlueFillScheme.highlightLight = 0xFFFFFFFF;
    LightBlueFillScheme.shadow = 0x808080FF;
    LightBlueFillScheme.shadowDark = 0x404040FF;
    LightBlueFillScheme.foreground = 0xFF;
    LightBlueFillScheme.foregroundInactive = 0xD6E3E7FF;
    LightBlueFillScheme.foregroundDisabled = 0x808080FF;
    LightBlueFillScheme.background = 0xFFFFFFFF;
    LightBlueFillScheme.backgroundInactive = 0xD6E3E7FF;
    LightBlueFillScheme.backgroundDisabled = 0xC8D0D4FF;
    LightBlueFillScheme.text = 0xFF;
    LightBlueFillScheme.textHighlight = 0xFFFF;
    LightBlueFillScheme.textHighlightText = 0xFFFFFFFF;
    LightBlueFillScheme.textInactive = 0xD6E3E7FF;
    LightBlueFillScheme.textDisabled = 0x8C9294FF;

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

    laScheme_Initialize(&LightBlueBackgroundScheme, GFX_COLOR_MODE_RGBA_8888);
    LightBlueBackgroundScheme.base = 0xB5D7FFFF;
    LightBlueBackgroundScheme.highlight = 0xC8D0D4FF;
    LightBlueBackgroundScheme.highlightLight = 0xFFFFFFFF;
    LightBlueBackgroundScheme.shadow = 0x808080FF;
    LightBlueBackgroundScheme.shadowDark = 0x404040FF;
    LightBlueBackgroundScheme.foreground = 0xFF;
    LightBlueBackgroundScheme.foregroundInactive = 0xD6E3E7FF;
    LightBlueBackgroundScheme.foregroundDisabled = 0x808080FF;
    LightBlueBackgroundScheme.background = 0xB5D7FFFF;
    LightBlueBackgroundScheme.backgroundInactive = 0xD6E3E7FF;
    LightBlueBackgroundScheme.backgroundDisabled = 0xC8D0D4FF;
    LightBlueBackgroundScheme.text = 0xFF;
    LightBlueBackgroundScheme.textHighlight = 0xFFFF;
    LightBlueBackgroundScheme.textHighlightText = 0xFFFFFFFF;
    LightBlueBackgroundScheme.textInactive = 0xD6E3E7FF;
    LightBlueBackgroundScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&PurpleFillScheme, GFX_COLOR_MODE_RGBA_8888);
    PurpleFillScheme.base = 0xBDBEFFFF;
    PurpleFillScheme.highlight = 0xC8D0D4FF;
    PurpleFillScheme.highlightLight = 0xFFFFFFFF;
    PurpleFillScheme.shadow = 0x808080FF;
    PurpleFillScheme.shadowDark = 0x404040FF;
    PurpleFillScheme.foreground = 0xFF;
    PurpleFillScheme.foregroundInactive = 0xD6E3E7FF;
    PurpleFillScheme.foregroundDisabled = 0x808080FF;
    PurpleFillScheme.background = 0xFFFFFFFF;
    PurpleFillScheme.backgroundInactive = 0xD6E3E7FF;
    PurpleFillScheme.backgroundDisabled = 0xC8D0D4FF;
    PurpleFillScheme.text = 0xFF;
    PurpleFillScheme.textHighlight = 0xFFFF;
    PurpleFillScheme.textHighlightText = 0xFFFFFFFF;
    PurpleFillScheme.textInactive = 0xD6E3E7FF;
    PurpleFillScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&RedFillScheme, GFX_COLOR_MODE_RGBA_8888);
    RedFillScheme.base = 0xFF0000FF;
    RedFillScheme.highlight = 0xC8D0D4FF;
    RedFillScheme.highlightLight = 0xFFFFFFFF;
    RedFillScheme.shadow = 0x808080FF;
    RedFillScheme.shadowDark = 0x404040FF;
    RedFillScheme.foreground = 0xFF;
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

    laScheme_Initialize(&BlueFillScheme, GFX_COLOR_MODE_RGBA_8888);
    BlueFillScheme.base = 0xFFFF;
    BlueFillScheme.highlight = 0xC8D0D4FF;
    BlueFillScheme.highlightLight = 0xFFFFFFFF;
    BlueFillScheme.shadow = 0x808080FF;
    BlueFillScheme.shadowDark = 0x404040FF;
    BlueFillScheme.foreground = 0xFF;
    BlueFillScheme.foregroundInactive = 0xD6E3E7FF;
    BlueFillScheme.foregroundDisabled = 0x808080FF;
    BlueFillScheme.background = 0xFFFFFFFF;
    BlueFillScheme.backgroundInactive = 0xD6E3E7FF;
    BlueFillScheme.backgroundDisabled = 0xC8D0D4FF;
    BlueFillScheme.text = 0xFF;
    BlueFillScheme.textHighlight = 0xFFFF;
    BlueFillScheme.textHighlightText = 0xFFFFFFFF;
    BlueFillScheme.textInactive = 0xD6E3E7FF;
    BlueFillScheme.textDisabled = 0x8C9294FF;

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

    laScheme_Initialize(&LightRedBackgroundScheme, GFX_COLOR_MODE_RGBA_8888);
    LightRedBackgroundScheme.base = 0xC8D0D4FF;
    LightRedBackgroundScheme.highlight = 0xC8D0D4FF;
    LightRedBackgroundScheme.highlightLight = 0xFFFFFFFF;
    LightRedBackgroundScheme.shadow = 0x808080FF;
    LightRedBackgroundScheme.shadowDark = 0x404040FF;
    LightRedBackgroundScheme.foreground = 0xFF;
    LightRedBackgroundScheme.foregroundInactive = 0xD6E3E7FF;
    LightRedBackgroundScheme.foregroundDisabled = 0x808080FF;
    LightRedBackgroundScheme.background = 0xFFBEBDFF;
    LightRedBackgroundScheme.backgroundInactive = 0xD6E3E7FF;
    LightRedBackgroundScheme.backgroundDisabled = 0xC8D0D4FF;
    LightRedBackgroundScheme.text = 0xFF;
    LightRedBackgroundScheme.textHighlight = 0xFFFF;
    LightRedBackgroundScheme.textHighlightText = 0xFFFFFFFF;
    LightRedBackgroundScheme.textInactive = 0xD6E3E7FF;
    LightRedBackgroundScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&BrownFillScheme, GFX_COLOR_MODE_RGBA_8888);
    BrownFillScheme.base = 0xD6923AFF;
    BrownFillScheme.highlight = 0xC8D0D4FF;
    BrownFillScheme.highlightLight = 0xFFFFFFFF;
    BrownFillScheme.shadow = 0x808080FF;
    BrownFillScheme.shadowDark = 0x404040FF;
    BrownFillScheme.foreground = 0xFF;
    BrownFillScheme.foregroundInactive = 0xD6E3E7FF;
    BrownFillScheme.foregroundDisabled = 0x808080FF;
    BrownFillScheme.background = 0xFFFFFFFF;
    BrownFillScheme.backgroundInactive = 0xD6E3E7FF;
    BrownFillScheme.backgroundDisabled = 0xC8D0D4FF;
    BrownFillScheme.text = 0xFF;
    BrownFillScheme.textHighlight = 0xFFFF;
    BrownFillScheme.textHighlightText = 0xFFFFFFFF;
    BrownFillScheme.textInactive = 0xD6E3E7FF;
    BrownFillScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&WhiteBackgroundScheme, GFX_COLOR_MODE_RGBA_8888);
    WhiteBackgroundScheme.base = 0xFFFFFFFF;
    WhiteBackgroundScheme.highlight = 0xC8D0D4FF;
    WhiteBackgroundScheme.highlightLight = 0xFFFFFFFF;
    WhiteBackgroundScheme.shadow = 0x808080FF;
    WhiteBackgroundScheme.shadowDark = 0x404040FF;
    WhiteBackgroundScheme.foreground = 0xFF;
    WhiteBackgroundScheme.foregroundInactive = 0xD6E3E7FF;
    WhiteBackgroundScheme.foregroundDisabled = 0x808080FF;
    WhiteBackgroundScheme.background = 0xFFFFFFFF;
    WhiteBackgroundScheme.backgroundInactive = 0xD6E3E7FF;
    WhiteBackgroundScheme.backgroundDisabled = 0xC8D0D4FF;
    WhiteBackgroundScheme.text = 0xFF;
    WhiteBackgroundScheme.textHighlight = 0xFFFF;
    WhiteBackgroundScheme.textHighlightText = 0xFFFFFFFF;
    WhiteBackgroundScheme.textInactive = 0xD6E3E7FF;
    WhiteBackgroundScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&BlackFillScheme, GFX_COLOR_MODE_RGBA_8888);
    BlackFillScheme.base = 0xFF;
    BlackFillScheme.highlight = 0xC8D0D4FF;
    BlackFillScheme.highlightLight = 0xFFFFFFFF;
    BlackFillScheme.shadow = 0x808080FF;
    BlackFillScheme.shadowDark = 0x404040FF;
    BlackFillScheme.foreground = 0xFF;
    BlackFillScheme.foregroundInactive = 0xD6E3E7FF;
    BlackFillScheme.foregroundDisabled = 0x808080FF;
    BlackFillScheme.background = 0xFFFFFFFF;
    BlackFillScheme.backgroundInactive = 0xD6E3E7FF;
    BlackFillScheme.backgroundDisabled = 0xC8D0D4FF;
    BlackFillScheme.text = 0xFF;
    BlackFillScheme.textHighlight = 0xFFFF;
    BlackFillScheme.textHighlightText = 0xFFFFFFFF;
    BlackFillScheme.textInactive = 0xD6E3E7FF;
    BlackFillScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&OrangeFillScheme, GFX_COLOR_MODE_RGBA_8888);
    OrangeFillScheme.base = 0xFF8200FF;
    OrangeFillScheme.highlight = 0xC8D0D4FF;
    OrangeFillScheme.highlightLight = 0xFFFFFFFF;
    OrangeFillScheme.shadow = 0x808080FF;
    OrangeFillScheme.shadowDark = 0x404040FF;
    OrangeFillScheme.foreground = 0xFF;
    OrangeFillScheme.foregroundInactive = 0xD6E3E7FF;
    OrangeFillScheme.foregroundDisabled = 0x808080FF;
    OrangeFillScheme.background = 0xFF8200FF;
    OrangeFillScheme.backgroundInactive = 0xD6E3E7FF;
    OrangeFillScheme.backgroundDisabled = 0xC8D0D4FF;
    OrangeFillScheme.text = 0xFF;
    OrangeFillScheme.textHighlight = 0xFFFF;
    OrangeFillScheme.textHighlightText = 0xFFFFFFFF;
    OrangeFillScheme.textInactive = 0xD6E3E7FF;
    OrangeFillScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&PinkFillScheme, GFX_COLOR_MODE_RGBA_8888);
    PinkFillScheme.base = 0xD600C5FF;
    PinkFillScheme.highlight = 0xC8D0D4FF;
    PinkFillScheme.highlightLight = 0xFFFFFFFF;
    PinkFillScheme.shadow = 0x808080FF;
    PinkFillScheme.shadowDark = 0x404040FF;
    PinkFillScheme.foreground = 0xFF;
    PinkFillScheme.foregroundInactive = 0xD6E3E7FF;
    PinkFillScheme.foregroundDisabled = 0x808080FF;
    PinkFillScheme.background = 0xFFFFFFFF;
    PinkFillScheme.backgroundInactive = 0xD6E3E7FF;
    PinkFillScheme.backgroundDisabled = 0xC8D0D4FF;
    PinkFillScheme.text = 0xFF;
    PinkFillScheme.textHighlight = 0xFFFF;
    PinkFillScheme.textHighlightText = 0xFFFFFFFF;
    PinkFillScheme.textInactive = 0xD6E3E7FF;
    PinkFillScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&YellowFillScheme, GFX_COLOR_MODE_RGBA_8888);
    YellowFillScheme.base = 0xFFFF00FF;
    YellowFillScheme.highlight = 0xC8D0D4FF;
    YellowFillScheme.highlightLight = 0xFFFFFFFF;
    YellowFillScheme.shadow = 0x808080FF;
    YellowFillScheme.shadowDark = 0x404040FF;
    YellowFillScheme.foreground = 0xFF;
    YellowFillScheme.foregroundInactive = 0xD6E3E7FF;
    YellowFillScheme.foregroundDisabled = 0x808080FF;
    YellowFillScheme.background = 0xFFFFFFFF;
    YellowFillScheme.backgroundInactive = 0xD6E3E7FF;
    YellowFillScheme.backgroundDisabled = 0xC8D0D4FF;
    YellowFillScheme.text = 0xFF;
    YellowFillScheme.textHighlight = 0xFFFF;
    YellowFillScheme.textHighlightText = 0xFFFFFFFF;
    YellowFillScheme.textInactive = 0xD6E3E7FF;
    YellowFillScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&WhiteFillScheme, GFX_COLOR_MODE_RGBA_8888);
    WhiteFillScheme.base = 0xFFFFFFFF;
    WhiteFillScheme.highlight = 0xC8D0D4FF;
    WhiteFillScheme.highlightLight = 0xFFFFFFFF;
    WhiteFillScheme.shadow = 0x808080FF;
    WhiteFillScheme.shadowDark = 0x404040FF;
    WhiteFillScheme.foreground = 0xFF;
    WhiteFillScheme.foregroundInactive = 0xD6E3E7FF;
    WhiteFillScheme.foregroundDisabled = 0x808080FF;
    WhiteFillScheme.background = 0xFFFFFFFF;
    WhiteFillScheme.backgroundInactive = 0xD6E3E7FF;
    WhiteFillScheme.backgroundDisabled = 0xC8D0D4FF;
    WhiteFillScheme.text = 0xFF;
    WhiteFillScheme.textHighlight = 0xFFFF;
    WhiteFillScheme.textHighlightText = 0xFFFFFFFF;
    WhiteFillScheme.textInactive = 0xD6E3E7FF;
    WhiteFillScheme.textDisabled = 0x8C9294FF;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    laContext_SetStringTable(&stringTable);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_SplashScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_FPSCounters);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_FPSMotion);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_FPSImages);
    laContext_AddScreen(screen);

    laContext_SetActiveScreen(0);

	return 0;
}

static void ScreenCreate_SplashScreen(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &WhiteBackgroundScheme);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetAlphaEnable(layer0, LA_TRUE);
    laLayer_SetAlphaAmount(layer0, 0xFF);

    laScreen_SetLayer(screen, 0, layer0);

    Pic32Logo = laImageWidget_New();
    laWidget_SetPosition((laWidget*)Pic32Logo, 123, 71);
    laWidget_SetSize((laWidget*)Pic32Logo, 240, 66);
    laWidget_SetScheme((laWidget*)Pic32Logo, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)Pic32Logo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)Pic32Logo, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(Pic32Logo, &PIC32Logo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)Pic32Logo);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 1);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0xFF);

    laScreen_SetLayer(screen, 1, layer1);

    SplashBar = laImageWidget_New();
    laWidget_SetPosition((laWidget*)SplashBar, 480, 207);
    laWidget_SetSize((laWidget*)SplashBar, 480, 65);
    laWidget_SetScheme((laWidget*)SplashBar, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)SplashBar, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SplashBar, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(SplashBar, &Bar);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)SplashBar);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 1);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x0);

    laScreen_SetLayer(screen, 2, layer2);

    HarmonyLogoWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)HarmonyLogoWidget, 144, 42);
    laWidget_SetSize((laWidget*)HarmonyLogoWidget, 197, 139);
    laWidget_SetScheme((laWidget*)HarmonyLogoWidget, &WhiteBackgroundScheme);
    laWidget_SetBackgroundType((laWidget*)HarmonyLogoWidget, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)HarmonyLogoWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(HarmonyLogoWidget, &HarmonyLogo);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)HarmonyLogoWidget);

    SplashBarLogo = laImageWidget_New();
    laWidget_SetPosition((laWidget*)SplashBarLogo, 17, 230);
    laWidget_SetSize((laWidget*)SplashBarLogo, 144, 39);
    laWidget_SetOptimizationFlags((laWidget*)SplashBarLogo, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)SplashBarLogo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SplashBarLogo, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(SplashBarLogo, &MicrochipLogo);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)SplashBarLogo);

}

static void ScreenCreate_FPSCounters(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &LightRedBackgroundScheme);
    laLayer_SetBufferCount(layer0, 1);

    laScreen_SetLayer(screen, 0, layer0);

    Counter1LabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)Counter1LabelWidget, 0, 70);
    laWidget_SetSize((laWidget*)Counter1LabelWidget, 353, 134);
    laWidget_SetBackgroundType((laWidget*)Counter1LabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)Counter1LabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(Counter1LabelWidget, laString_CreateFromID(string_NumsLarge));
    laWidget_AddChild((laWidget*)layer0, (laWidget*)Counter1LabelWidget);

    PanelWidget3 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget3, 359, 8);
    laWidget_SetSize((laWidget*)PanelWidget3, 113, 260);
    laWidget_SetScheme((laWidget*)PanelWidget3, &WhiteBackgroundScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PanelWidget3, LA_WIDGET_BORDER_LINE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget3);

    LabelWidget4 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget4, 1, 22);
    laWidget_SetSize((laWidget*)LabelWidget4, 99, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget4, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget4, laString_CreateFromID(string_FPS));
    laLabelWidget_SetHAlignment(LabelWidget4, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)LabelWidget4);

    RefreshRateLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)RefreshRateLabelWidget, 1, 72);
    laWidget_SetSize((laWidget*)RefreshRateLabelWidget, 109, 23);
    laWidget_SetBackgroundType((laWidget*)RefreshRateLabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)RefreshRateLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(RefreshRateLabelWidget, laString_CreateFromID(string_RefreshRate));
    laLabelWidget_SetHAlignment(RefreshRateLabelWidget, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)RefreshRateLabelWidget);

    RefreshRateCountLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)RefreshRateCountLabelWidget, 4, 94);
    laWidget_SetSize((laWidget*)RefreshRateCountLabelWidget, 101, 28);
    laWidget_SetBackgroundType((laWidget*)RefreshRateCountLabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)RefreshRateCountLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(RefreshRateCountLabelWidget, laString_CreateFromID(string_NumsLittle));
    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)RefreshRateCountLabelWidget);

    CounterSizeDownButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)CounterSizeDownButton, 1, 148);
    laWidget_SetSize((laWidget*)CounterSizeDownButton, 55, 30);
    laWidget_SetBackgroundType((laWidget*)CounterSizeDownButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CounterSizeDownButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(CounterSizeDownButton, laString_CreateFromID(string_Minus));
    laButtonWidget_SetPressedEventCallback(CounterSizeDownButton, &CounterSizeDownButton_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)CounterSizeDownButton);

    CounterSizeUpButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)CounterSizeUpButton, 57, 148);
    laWidget_SetSize((laWidget*)CounterSizeUpButton, 55, 30);
    laWidget_SetBackgroundType((laWidget*)CounterSizeUpButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CounterSizeUpButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(CounterSizeUpButton, laString_CreateFromID(string_Plus));
    laButtonWidget_SetPressedEventCallback(CounterSizeUpButton, &CounterSizeUpButton_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)CounterSizeUpButton);

    LabelWidget1 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget1, 2, 2);
    laWidget_SetSize((laWidget*)LabelWidget1, 109, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget1, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget1, laString_CreateFromID(string_DynamicString));
    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)LabelWidget1);

    NextButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)NextButton, 57, 229);
    laWidget_SetSize((laWidget*)NextButton, 55, 30);
    laWidget_SetBackgroundType((laWidget*)NextButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)NextButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(NextButton, laString_CreateFromID(string_Next));
    laButtonWidget_SetPressedEventCallback(NextButton, &NextButton_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)NextButton);

    StringSizeIdxLabel = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)StringSizeIdxLabel, 68, 123);
    laWidget_SetSize((laWidget*)StringSizeIdxLabel, 24, 25);
    laWidget_SetBackgroundType((laWidget*)StringSizeIdxLabel, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)StringSizeIdxLabel, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(StringSizeIdxLabel, laString_CreateFromID(string_NumsLittle));
    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)StringSizeIdxLabel);

    LabelWidget32 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget32, 2, 121);
    laWidget_SetSize((laWidget*)LabelWidget32, 64, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget32, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget32, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget32, laString_CreateFromID(string_StringSize));
    laLabelWidget_SetHAlignment(LabelWidget32, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)LabelWidget32);

    ButtonWidget1 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget1, 1, 229);
    laWidget_SetSize((laWidget*)ButtonWidget1, 55, 30);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget1, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetToggleable(ButtonWidget1, LA_TRUE);
    laButtonWidget_SetPressed(ButtonWidget1, LA_TRUE);
    laButtonWidget_SetText(ButtonWidget1, laString_CreateFromID(string_GPUOn));
    laButtonWidget_SetPressedEventCallback(ButtonWidget1, &ButtonWidget1_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget1, &ButtonWidget1_ReleasedEvent);

    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)ButtonWidget1);

    FPSButtonCounter = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)FPSButtonCounter, 362, 53);
    laWidget_SetSize((laWidget*)FPSButtonCounter, 107, 29);
    laWidget_SetBackgroundType((laWidget*)FPSButtonCounter, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)FPSButtonCounter, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetToggleable(FPSButtonCounter, LA_TRUE);
    laButtonWidget_SetText(FPSButtonCounter, laString_CreateFromID(string_NumsLittle));
    laButtonWidget_SetPressedEventCallback(FPSButtonCounter, &FPSButtonCounter_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(FPSButtonCounter, &FPSButtonCounter_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)FPSButtonCounter);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 1);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0x0);

    laScreen_SetLayer(screen, 1, layer1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 1);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x0);

    laScreen_SetLayer(screen, 2, layer2);

}

static void ScreenCreate_FPSMotion(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &LightGreenBackgroundScheme);
    laLayer_SetBufferCount(layer0, 1);

    laScreen_SetLayer(screen, 0, layer0);

    RectMotionWidget10 = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)RectMotionWidget10, 314, 131);
    laWidget_SetSize((laWidget*)RectMotionWidget10, 40, 40);
    laWidget_SetScheme((laWidget*)RectMotionWidget10, &BrownFillScheme);
    laWidget_SetBackgroundType((laWidget*)RectMotionWidget10, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RectMotionWidget10, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(RectMotionWidget10, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)RectMotionWidget10);

    RectMotionWidget9 = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)RectMotionWidget9, 178, 169);
    laWidget_SetSize((laWidget*)RectMotionWidget9, 40, 40);
    laWidget_SetScheme((laWidget*)RectMotionWidget9, &LightBlueFillScheme);
    laWidget_SetBackgroundType((laWidget*)RectMotionWidget9, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RectMotionWidget9, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(RectMotionWidget9, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)RectMotionWidget9);

    RectMotionWidget8 = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)RectMotionWidget8, 193, 3);
    laWidget_SetSize((laWidget*)RectMotionWidget8, 40, 40);
    laWidget_SetScheme((laWidget*)RectMotionWidget8, &PurpleFillScheme);
    laWidget_SetBackgroundType((laWidget*)RectMotionWidget8, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RectMotionWidget8, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(RectMotionWidget8, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)RectMotionWidget8);

    RectMotionWidget7 = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)RectMotionWidget7, 155, 70);
    laWidget_SetSize((laWidget*)RectMotionWidget7, 40, 40);
    laWidget_SetScheme((laWidget*)RectMotionWidget7, &PinkFillScheme);
    laWidget_SetBackgroundType((laWidget*)RectMotionWidget7, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RectMotionWidget7, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(RectMotionWidget7, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)RectMotionWidget7);

    RectMotionWidget6 = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)RectMotionWidget6, 98, 24);
    laWidget_SetSize((laWidget*)RectMotionWidget6, 40, 40);
    laWidget_SetScheme((laWidget*)RectMotionWidget6, &OrangeFillScheme);
    laWidget_SetBackgroundType((laWidget*)RectMotionWidget6, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RectMotionWidget6, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(RectMotionWidget6, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)RectMotionWidget6);

    RectMotionWidget5 = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)RectMotionWidget5, 197, 101);
    laWidget_SetSize((laWidget*)RectMotionWidget5, 40, 40);
    laWidget_SetScheme((laWidget*)RectMotionWidget5, &BlueFillScheme);
    laWidget_SetBackgroundType((laWidget*)RectMotionWidget5, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RectMotionWidget5, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(RectMotionWidget5, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)RectMotionWidget5);

    RectMotionWidget4 = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)RectMotionWidget4, 264, 79);
    laWidget_SetSize((laWidget*)RectMotionWidget4, 40, 40);
    laWidget_SetScheme((laWidget*)RectMotionWidget4, &YellowFillScheme);
    laWidget_SetBackgroundType((laWidget*)RectMotionWidget4, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RectMotionWidget4, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(RectMotionWidget4, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)RectMotionWidget4);

    RectMotionWidget3 = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)RectMotionWidget3, 84, 185);
    laWidget_SetSize((laWidget*)RectMotionWidget3, 40, 40);
    laWidget_SetScheme((laWidget*)RectMotionWidget3, &WhiteFillScheme);
    laWidget_SetBackgroundType((laWidget*)RectMotionWidget3, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RectMotionWidget3, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(RectMotionWidget3, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)RectMotionWidget3);

    RectMotionWidget2 = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)RectMotionWidget2, 286, 206);
    laWidget_SetSize((laWidget*)RectMotionWidget2, 40, 40);
    laWidget_SetScheme((laWidget*)RectMotionWidget2, &RedFillScheme);
    laWidget_SetBackgroundType((laWidget*)RectMotionWidget2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RectMotionWidget2, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(RectMotionWidget2, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)RectMotionWidget2);

    RectMotionWidget1 = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)RectMotionWidget1, 9, 118);
    laWidget_SetSize((laWidget*)RectMotionWidget1, 40, 40);
    laWidget_SetScheme((laWidget*)RectMotionWidget1, &LightPinkFillScheme);
    laWidget_SetBackgroundType((laWidget*)RectMotionWidget1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RectMotionWidget1, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(RectMotionWidget1, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)RectMotionWidget1);

    PanelWidget2 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget2, 359, 8);
    laWidget_SetSize((laWidget*)PanelWidget2, 113, 260);
    laWidget_SetScheme((laWidget*)PanelWidget2, &WhiteBackgroundScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PanelWidget2, LA_WIDGET_BORDER_LINE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget2);

    LabelWidget3 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget3, 1, 22);
    laWidget_SetSize((laWidget*)LabelWidget3, 108, 18);
    laWidget_SetBackgroundType((laWidget*)LabelWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget3, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget3, laString_CreateFromID(string_FPS));
    laLabelWidget_SetHAlignment(LabelWidget3, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)LabelWidget3);

    LabelWidget5 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget5, 1, 69);
    laWidget_SetSize((laWidget*)LabelWidget5, 108, 18);
    laWidget_SetBackgroundType((laWidget*)LabelWidget5, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget5, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget5, laString_CreateFromID(string_RefreshRate));
    laLabelWidget_SetHAlignment(LabelWidget5, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)LabelWidget5);

    RefreshRateMotionLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)RefreshRateMotionLabelWidget, 6, 88);
    laWidget_SetSize((laWidget*)RefreshRateMotionLabelWidget, 101, 27);
    laWidget_SetBackgroundType((laWidget*)RefreshRateMotionLabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)RefreshRateMotionLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(RefreshRateMotionLabelWidget, laString_CreateFromID(string_NumsLittle));
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)RefreshRateMotionLabelWidget);

    LabelWidget10 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget10, 5, 1);
    laWidget_SetSize((laWidget*)LabelWidget10, 103, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget10, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget10, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget10, laString_CreateFromID(string_MotionUpdates));
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)LabelWidget10);

    MotionMenuNextButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)MotionMenuNextButton, 57, 229);
    laWidget_SetSize((laWidget*)MotionMenuNextButton, 55, 30);
    laWidget_SetBackgroundType((laWidget*)MotionMenuNextButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)MotionMenuNextButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(MotionMenuNextButton, laString_CreateFromID(string_Next));
    laButtonWidget_SetPressedEventCallback(MotionMenuNextButton, &MotionMenuNextButton_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)MotionMenuNextButton);

    MotionMenuPlusButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)MotionMenuPlusButton, 1, 133);
    laWidget_SetSize((laWidget*)MotionMenuPlusButton, 55, 30);
    laWidget_SetBackgroundType((laWidget*)MotionMenuPlusButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)MotionMenuPlusButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(MotionMenuPlusButton, laString_CreateFromID(string_Minus));
    laButtonWidget_SetPressedEventCallback(MotionMenuPlusButton, &MotionMenuPlusButton_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)MotionMenuPlusButton);

    MotionMenuMinusButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)MotionMenuMinusButton, 57, 133);
    laWidget_SetSize((laWidget*)MotionMenuMinusButton, 55, 30);
    laWidget_SetBackgroundType((laWidget*)MotionMenuMinusButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)MotionMenuMinusButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(MotionMenuMinusButton, laString_CreateFromID(string_Plus));
    laButtonWidget_SetPressedEventCallback(MotionMenuMinusButton, &MotionMenuMinusButton_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)MotionMenuMinusButton);

    LabelWidget33 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget33, 2, 112);
    laWidget_SetSize((laWidget*)LabelWidget33, 38, 19);
    laWidget_SetBackgroundType((laWidget*)LabelWidget33, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget33, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget33, laString_CreateFromID(string_RectanglesNum));
    laLabelWidget_SetHAlignment(LabelWidget33, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)LabelWidget33);

    NumRectCountLabel = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)NumRectCountLabel, 44, 114);
    laWidget_SetSize((laWidget*)NumRectCountLabel, 24, 16);
    laWidget_SetBackgroundType((laWidget*)NumRectCountLabel, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)NumRectCountLabel, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(NumRectCountLabel, laString_CreateFromID(string_NumsTiny));
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)NumRectCountLabel);

    LabelWidget11 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget11, 2, 162);
    laWidget_SetSize((laWidget*)LabelWidget11, 38, 22);
    laWidget_SetBackgroundType((laWidget*)LabelWidget11, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget11, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget11, laString_CreateFromID(string_Size));
    laLabelWidget_SetHAlignment(LabelWidget11, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)LabelWidget11);

    SquareSizeLabel = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)SquareSizeLabel, 44, 167);
    laWidget_SetSize((laWidget*)SquareSizeLabel, 61, 16);
    laWidget_SetBackgroundType((laWidget*)SquareSizeLabel, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SquareSizeLabel, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(SquareSizeLabel, laString_CreateFromID(string_NumsTiny));
    laLabelWidget_SetHAlignment(SquareSizeLabel, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)SquareSizeLabel);

    RectSizeDownButtonWidget = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)RectSizeDownButtonWidget, 1, 184);
    laWidget_SetSize((laWidget*)RectSizeDownButtonWidget, 55, 30);
    laWidget_SetBackgroundType((laWidget*)RectSizeDownButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)RectSizeDownButtonWidget, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(RectSizeDownButtonWidget, laString_CreateFromID(string_Minus));
    laButtonWidget_SetPressedEventCallback(RectSizeDownButtonWidget, &RectSizeDownButtonWidget_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)RectSizeDownButtonWidget);

    RectSizeUpButtonWidget = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)RectSizeUpButtonWidget, 57, 184);
    laWidget_SetSize((laWidget*)RectSizeUpButtonWidget, 55, 30);
    laWidget_SetBackgroundType((laWidget*)RectSizeUpButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)RectSizeUpButtonWidget, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(RectSizeUpButtonWidget, laString_CreateFromID(string_Plus));
    laButtonWidget_SetPressedEventCallback(RectSizeUpButtonWidget, &RectSizeUpButtonWidget_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)RectSizeUpButtonWidget);

    ButtonWidget2 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget2, 360, 237);
    laWidget_SetSize((laWidget*)ButtonWidget2, 55, 30);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget2, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetToggleable(ButtonWidget2, LA_TRUE);
    laButtonWidget_SetPressed(ButtonWidget2, LA_TRUE);
    laButtonWidget_SetText(ButtonWidget2, laString_CreateFromID(string_GPUOn));
    laButtonWidget_SetPressedEventCallback(ButtonWidget2, &ButtonWidget2_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget2, &ButtonWidget2_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget2);

    FPSButtonMotion = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)FPSButtonMotion, 362, 47);
    laWidget_SetSize((laWidget*)FPSButtonMotion, 107, 30);
    laWidget_SetBackgroundType((laWidget*)FPSButtonMotion, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)FPSButtonMotion, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetToggleable(FPSButtonMotion, LA_TRUE);
    laButtonWidget_SetText(FPSButtonMotion, laString_CreateFromID(string_NumsLittle));
    laButtonWidget_SetPressedEventCallback(FPSButtonMotion, &FPSButtonMotion_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(FPSButtonMotion, &FPSButtonMotion_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)FPSButtonMotion);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 1);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0x0);

    laScreen_SetLayer(screen, 1, layer1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 1);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x0);

    laScreen_SetLayer(screen, 2, layer2);

}

static void ScreenCreate_FPSImages(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &WhiteBackgroundScheme);
    laLayer_SetBufferCount(layer0, 1);

    laScreen_SetLayer(screen, 0, layer0);

    ImageRenderWidget = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageRenderWidget, 480, 272);
    laWidget_SetBackgroundType((laWidget*)ImageRenderWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageRenderWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetHAlignment(ImageRenderWidget, LA_HALIGN_LEFT);
    laImageWidget_SetVAlignment(ImageRenderWidget, LA_VALIGN_TOP);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageRenderWidget);

    PanelWidget48 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget48, 359, 8);
    laWidget_SetSize((laWidget*)PanelWidget48, 113, 260);
    laWidget_SetScheme((laWidget*)PanelWidget48, &WhiteBackgroundScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget48, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PanelWidget48, LA_WIDGET_BORDER_LINE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget48);

    LabelWidget49 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget49, 1, 22);
    laWidget_SetSize((laWidget*)LabelWidget49, 110, 19);
    laWidget_SetBackgroundType((laWidget*)LabelWidget49, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget49, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget49, laString_CreateFromID(string_FPS));
    laLabelWidget_SetHAlignment(LabelWidget49, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget48, (laWidget*)LabelWidget49);

    LabelWidget51 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget51, 1, 68);
    laWidget_SetSize((laWidget*)LabelWidget51, 109, 18);
    laWidget_SetBackgroundType((laWidget*)LabelWidget51, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget51, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget51, laString_CreateFromID(string_RefreshRate));
    laLabelWidget_SetHAlignment(LabelWidget51, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget48, (laWidget*)LabelWidget51);

    ImageRefRateCountLabel = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)ImageRefRateCountLabel, 7, 89);
    laWidget_SetSize((laWidget*)ImageRefRateCountLabel, 101, 24);
    laWidget_SetBackgroundType((laWidget*)ImageRefRateCountLabel, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageRefRateCountLabel, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(ImageRefRateCountLabel, laString_CreateFromID(string_NumsLittle));
    laWidget_AddChild((laWidget*)PanelWidget48, (laWidget*)ImageRefRateCountLabel);

    LabelWidget53 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget53, 0, 2);
    laWidget_SetSize((laWidget*)LabelWidget53, 111, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget53, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget53, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget53, laString_CreateFromID(string_ImageRendering));
    laWidget_AddChild((laWidget*)PanelWidget48, (laWidget*)LabelWidget53);

    ImageNextButtonWidget = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ImageNextButtonWidget, 57, 226);
    laWidget_SetSize((laWidget*)ImageNextButtonWidget, 55, 30);
    laWidget_SetBackgroundType((laWidget*)ImageNextButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageNextButtonWidget, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(ImageNextButtonWidget, laString_CreateFromID(string_Next));
    laButtonWidget_SetPressedEventCallback(ImageNextButtonWidget, &ImageNextButtonWidget_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget48, (laWidget*)ImageNextButtonWidget);

    ImageSizeDownButtonWidget = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ImageSizeDownButtonWidget, 1, 136);
    laWidget_SetSize((laWidget*)ImageSizeDownButtonWidget, 55, 30);
    laWidget_SetBackgroundType((laWidget*)ImageSizeDownButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageSizeDownButtonWidget, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(ImageSizeDownButtonWidget, laString_CreateFromID(string_Minus));
    laButtonWidget_SetPressedEventCallback(ImageSizeDownButtonWidget, &ImageSizeDownButtonWidget_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget48, (laWidget*)ImageSizeDownButtonWidget);

    ImageSizeUpButtonWidget = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ImageSizeUpButtonWidget, 57, 136);
    laWidget_SetSize((laWidget*)ImageSizeUpButtonWidget, 55, 30);
    laWidget_SetBackgroundType((laWidget*)ImageSizeUpButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageSizeUpButtonWidget, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(ImageSizeUpButtonWidget, laString_CreateFromID(string_Plus));
    laButtonWidget_SetPressedEventCallback(ImageSizeUpButtonWidget, &ImageSizeUpButtonWidget_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget48, (laWidget*)ImageSizeUpButtonWidget);

    LabelWidget57 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget57, 4, 113);
    laWidget_SetSize((laWidget*)LabelWidget57, 33, 19);
    laWidget_SetBackgroundType((laWidget*)LabelWidget57, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget57, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget57, laString_CreateFromID(string_Size));
    laLabelWidget_SetHAlignment(LabelWidget57, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget48, (laWidget*)LabelWidget57);

    ImageSizeLabel = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)ImageSizeLabel, 35, 112);
    laWidget_SetSize((laWidget*)ImageSizeLabel, 75, 23);
    laWidget_SetBackgroundType((laWidget*)ImageSizeLabel, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageSizeLabel, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(ImageSizeLabel, laString_CreateFromID(string_NumsTiny));
    laLabelWidget_SetHAlignment(ImageSizeLabel, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget48, (laWidget*)ImageSizeLabel);

    LabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget, 4, 168);
    laWidget_SetSize((laWidget*)LabelWidget, 39, 19);
    laWidget_SetBackgroundType((laWidget*)LabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget, laString_CreateFromID(string_ImageType));
    laLabelWidget_SetHAlignment(LabelWidget, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget48, (laWidget*)LabelWidget);

    ImageTypeLabel = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)ImageTypeLabel, 38, 168);
    laWidget_SetSize((laWidget*)ImageTypeLabel, 74, 23);
    laWidget_SetBackgroundType((laWidget*)ImageTypeLabel, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageTypeLabel, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(ImageTypeLabel, laString_CreateFromID(string_NumsTiny));
    laLabelWidget_SetHAlignment(ImageTypeLabel, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget48, (laWidget*)ImageTypeLabel);

    ImageTypePrevButtonWidget = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ImageTypePrevButtonWidget, 1, 192);
    laWidget_SetSize((laWidget*)ImageTypePrevButtonWidget, 55, 30);
    laWidget_SetBackgroundType((laWidget*)ImageTypePrevButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageTypePrevButtonWidget, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(ImageTypePrevButtonWidget, laString_CreateFromID(string_Previous));
    laButtonWidget_SetPressedEventCallback(ImageTypePrevButtonWidget, &ImageTypePrevButtonWidget_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget48, (laWidget*)ImageTypePrevButtonWidget);

    ImageTypeNextButtonWidget = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ImageTypeNextButtonWidget, 57, 192);
    laWidget_SetSize((laWidget*)ImageTypeNextButtonWidget, 55, 30);
    laWidget_SetBackgroundType((laWidget*)ImageTypeNextButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageTypeNextButtonWidget, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(ImageTypeNextButtonWidget, laString_CreateFromID(string_NextSymbol));
    laButtonWidget_SetPressedEventCallback(ImageTypeNextButtonWidget, &ImageTypeNextButtonWidget_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget48, (laWidget*)ImageTypeNextButtonWidget);

    ButtonWidget3 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget3, 1, 226);
    laWidget_SetSize((laWidget*)ButtonWidget3, 55, 30);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget3, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetToggleable(ButtonWidget3, LA_TRUE);
    laButtonWidget_SetPressed(ButtonWidget3, LA_TRUE);
    laButtonWidget_SetText(ButtonWidget3, laString_CreateFromID(string_GPUOn));
    laButtonWidget_SetPressedEventCallback(ButtonWidget3, &ButtonWidget3_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget3, &ButtonWidget3_ReleasedEvent);

    laWidget_AddChild((laWidget*)PanelWidget48, (laWidget*)ButtonWidget3);

    FPSButtonImages = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)FPSButtonImages, 362, 48);
    laWidget_SetSize((laWidget*)FPSButtonImages, 107, 28);
    laWidget_SetBackgroundType((laWidget*)FPSButtonImages, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)FPSButtonImages, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetToggleable(FPSButtonImages, LA_TRUE);
    laButtonWidget_SetText(FPSButtonImages, laString_CreateFromID(string_NumsLittle));
    laButtonWidget_SetPressedEventCallback(FPSButtonImages, &FPSButtonImages_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(FPSButtonImages, &FPSButtonImages_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)FPSButtonImages);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 1);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0x0);

    laScreen_SetLayer(screen, 1, layer1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 1);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x0);

    laScreen_SetLayer(screen, 2, layer2);

}




