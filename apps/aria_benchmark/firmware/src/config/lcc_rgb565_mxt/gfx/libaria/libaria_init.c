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

laScheme LightGreenBackgroundScheme;
laScheme LightPinkFillScheme;
laScheme LightBlueFillScheme;
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
laImageWidget* ImageWidget1;
laImageWidget* ImageWidget2;
laWidget* PanelWidget;
laImageWidget* ImageWidget3;
laImageWidget* ImageWidget4;
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
laButtonWidget* FPSButtonImages;


static void ScreenCreate_SplashScreen(laScreen* screen);
static void ScreenCreate_FPSCounters(laScreen* screen);
static void ScreenCreate_FPSMotion(laScreen* screen);
static void ScreenCreate_FPSImages(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&LightGreenBackgroundScheme, GFX_COLOR_MODE_RGB_565);
    LightGreenBackgroundScheme.base = 0xA693;
    LightGreenBackgroundScheme.highlight = 0xC67A;
    LightGreenBackgroundScheme.highlightLight = 0xFFFF;
    LightGreenBackgroundScheme.shadow = 0x8410;
    LightGreenBackgroundScheme.shadowDark = 0x4208;
    LightGreenBackgroundScheme.foreground = 0x0;
    LightGreenBackgroundScheme.foregroundInactive = 0xD71C;
    LightGreenBackgroundScheme.foregroundDisabled = 0x8410;
    LightGreenBackgroundScheme.background = 0xA693;
    LightGreenBackgroundScheme.backgroundInactive = 0xD71C;
    LightGreenBackgroundScheme.backgroundDisabled = 0xC67A;
    LightGreenBackgroundScheme.text = 0x0;
    LightGreenBackgroundScheme.textHighlight = 0x1F;
    LightGreenBackgroundScheme.textHighlightText = 0xFFFF;
    LightGreenBackgroundScheme.textInactive = 0xD71C;
    LightGreenBackgroundScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&LightPinkFillScheme, GFX_COLOR_MODE_RGB_565);
    LightPinkFillScheme.base = 0xFDFF;
    LightPinkFillScheme.highlight = 0xC67A;
    LightPinkFillScheme.highlightLight = 0xFFFF;
    LightPinkFillScheme.shadow = 0x8410;
    LightPinkFillScheme.shadowDark = 0x4208;
    LightPinkFillScheme.foreground = 0x0;
    LightPinkFillScheme.foregroundInactive = 0xD71C;
    LightPinkFillScheme.foregroundDisabled = 0x8410;
    LightPinkFillScheme.background = 0xFFFF;
    LightPinkFillScheme.backgroundInactive = 0xD71C;
    LightPinkFillScheme.backgroundDisabled = 0xC67A;
    LightPinkFillScheme.text = 0x0;
    LightPinkFillScheme.textHighlight = 0x1F;
    LightPinkFillScheme.textHighlightText = 0xFFFF;
    LightPinkFillScheme.textInactive = 0xD71C;
    LightPinkFillScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&LightBlueFillScheme, GFX_COLOR_MODE_RGB_565);
    LightBlueFillScheme.base = 0x87FF;
    LightBlueFillScheme.highlight = 0xC67A;
    LightBlueFillScheme.highlightLight = 0xFFFF;
    LightBlueFillScheme.shadow = 0x8410;
    LightBlueFillScheme.shadowDark = 0x4208;
    LightBlueFillScheme.foreground = 0x0;
    LightBlueFillScheme.foregroundInactive = 0xD71C;
    LightBlueFillScheme.foregroundDisabled = 0x8410;
    LightBlueFillScheme.background = 0xFFFF;
    LightBlueFillScheme.backgroundInactive = 0xD71C;
    LightBlueFillScheme.backgroundDisabled = 0xC67A;
    LightBlueFillScheme.text = 0x0;
    LightBlueFillScheme.textHighlight = 0x1F;
    LightBlueFillScheme.textHighlightText = 0xFFFF;
    LightBlueFillScheme.textInactive = 0xD71C;
    LightBlueFillScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&LightBlueBackgroundScheme, GFX_COLOR_MODE_RGB_565);
    LightBlueBackgroundScheme.base = 0xB6BF;
    LightBlueBackgroundScheme.highlight = 0xC67A;
    LightBlueBackgroundScheme.highlightLight = 0xFFFF;
    LightBlueBackgroundScheme.shadow = 0x8410;
    LightBlueBackgroundScheme.shadowDark = 0x4208;
    LightBlueBackgroundScheme.foreground = 0x0;
    LightBlueBackgroundScheme.foregroundInactive = 0xD71C;
    LightBlueBackgroundScheme.foregroundDisabled = 0x8410;
    LightBlueBackgroundScheme.background = 0xB6BF;
    LightBlueBackgroundScheme.backgroundInactive = 0xD71C;
    LightBlueBackgroundScheme.backgroundDisabled = 0xC67A;
    LightBlueBackgroundScheme.text = 0x0;
    LightBlueBackgroundScheme.textHighlight = 0x1F;
    LightBlueBackgroundScheme.textHighlightText = 0xFFFF;
    LightBlueBackgroundScheme.textInactive = 0xD71C;
    LightBlueBackgroundScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&PurpleFillScheme, GFX_COLOR_MODE_RGB_565);
    PurpleFillScheme.base = 0xBDFF;
    PurpleFillScheme.highlight = 0xC67A;
    PurpleFillScheme.highlightLight = 0xFFFF;
    PurpleFillScheme.shadow = 0x8410;
    PurpleFillScheme.shadowDark = 0x4208;
    PurpleFillScheme.foreground = 0x0;
    PurpleFillScheme.foregroundInactive = 0xD71C;
    PurpleFillScheme.foregroundDisabled = 0x8410;
    PurpleFillScheme.background = 0xFFFF;
    PurpleFillScheme.backgroundInactive = 0xD71C;
    PurpleFillScheme.backgroundDisabled = 0xC67A;
    PurpleFillScheme.text = 0x0;
    PurpleFillScheme.textHighlight = 0x1F;
    PurpleFillScheme.textHighlightText = 0xFFFF;
    PurpleFillScheme.textInactive = 0xD71C;
    PurpleFillScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&RedFillScheme, GFX_COLOR_MODE_RGB_565);
    RedFillScheme.base = 0xF800;
    RedFillScheme.highlight = 0xC67A;
    RedFillScheme.highlightLight = 0xFFFF;
    RedFillScheme.shadow = 0x8410;
    RedFillScheme.shadowDark = 0x4208;
    RedFillScheme.foreground = 0x0;
    RedFillScheme.foregroundInactive = 0xD71C;
    RedFillScheme.foregroundDisabled = 0x8410;
    RedFillScheme.background = 0xFFFF;
    RedFillScheme.backgroundInactive = 0xD71C;
    RedFillScheme.backgroundDisabled = 0xC67A;
    RedFillScheme.text = 0x0;
    RedFillScheme.textHighlight = 0x1F;
    RedFillScheme.textHighlightText = 0xFFFF;
    RedFillScheme.textInactive = 0xD71C;
    RedFillScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&BlueFillScheme, GFX_COLOR_MODE_RGB_565);
    BlueFillScheme.base = 0x1F;
    BlueFillScheme.highlight = 0xC67A;
    BlueFillScheme.highlightLight = 0xFFFF;
    BlueFillScheme.shadow = 0x8410;
    BlueFillScheme.shadowDark = 0x4208;
    BlueFillScheme.foreground = 0x0;
    BlueFillScheme.foregroundInactive = 0xD71C;
    BlueFillScheme.foregroundDisabled = 0x8410;
    BlueFillScheme.background = 0xFFFF;
    BlueFillScheme.backgroundInactive = 0xD71C;
    BlueFillScheme.backgroundDisabled = 0xC67A;
    BlueFillScheme.text = 0x0;
    BlueFillScheme.textHighlight = 0x1F;
    BlueFillScheme.textHighlightText = 0xFFFF;
    BlueFillScheme.textInactive = 0xD71C;
    BlueFillScheme.textDisabled = 0x8C92;

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

    laScheme_Initialize(&LightRedBackgroundScheme, GFX_COLOR_MODE_RGB_565);
    LightRedBackgroundScheme.base = 0xC67A;
    LightRedBackgroundScheme.highlight = 0xC67A;
    LightRedBackgroundScheme.highlightLight = 0xFFFF;
    LightRedBackgroundScheme.shadow = 0x8410;
    LightRedBackgroundScheme.shadowDark = 0x4208;
    LightRedBackgroundScheme.foreground = 0x0;
    LightRedBackgroundScheme.foregroundInactive = 0xD71C;
    LightRedBackgroundScheme.foregroundDisabled = 0x8410;
    LightRedBackgroundScheme.background = 0xFDF7;
    LightRedBackgroundScheme.backgroundInactive = 0xD71C;
    LightRedBackgroundScheme.backgroundDisabled = 0xC67A;
    LightRedBackgroundScheme.text = 0x0;
    LightRedBackgroundScheme.textHighlight = 0x1F;
    LightRedBackgroundScheme.textHighlightText = 0xFFFF;
    LightRedBackgroundScheme.textInactive = 0xD71C;
    LightRedBackgroundScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&BrownFillScheme, GFX_COLOR_MODE_RGB_565);
    BrownFillScheme.base = 0xD487;
    BrownFillScheme.highlight = 0xC67A;
    BrownFillScheme.highlightLight = 0xFFFF;
    BrownFillScheme.shadow = 0x8410;
    BrownFillScheme.shadowDark = 0x4208;
    BrownFillScheme.foreground = 0x0;
    BrownFillScheme.foregroundInactive = 0xD71C;
    BrownFillScheme.foregroundDisabled = 0x8410;
    BrownFillScheme.background = 0xFFFF;
    BrownFillScheme.backgroundInactive = 0xD71C;
    BrownFillScheme.backgroundDisabled = 0xC67A;
    BrownFillScheme.text = 0x0;
    BrownFillScheme.textHighlight = 0x1F;
    BrownFillScheme.textHighlightText = 0xFFFF;
    BrownFillScheme.textInactive = 0xD71C;
    BrownFillScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&WhiteBackgroundScheme, GFX_COLOR_MODE_RGB_565);
    WhiteBackgroundScheme.base = 0xFFFF;
    WhiteBackgroundScheme.highlight = 0xC67A;
    WhiteBackgroundScheme.highlightLight = 0xFFFF;
    WhiteBackgroundScheme.shadow = 0x8410;
    WhiteBackgroundScheme.shadowDark = 0x4208;
    WhiteBackgroundScheme.foreground = 0x0;
    WhiteBackgroundScheme.foregroundInactive = 0xD71C;
    WhiteBackgroundScheme.foregroundDisabled = 0x8410;
    WhiteBackgroundScheme.background = 0xFFFF;
    WhiteBackgroundScheme.backgroundInactive = 0xD71C;
    WhiteBackgroundScheme.backgroundDisabled = 0xC67A;
    WhiteBackgroundScheme.text = 0x0;
    WhiteBackgroundScheme.textHighlight = 0x1F;
    WhiteBackgroundScheme.textHighlightText = 0xFFFF;
    WhiteBackgroundScheme.textInactive = 0xD71C;
    WhiteBackgroundScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&BlackFillScheme, GFX_COLOR_MODE_RGB_565);
    BlackFillScheme.base = 0x0;
    BlackFillScheme.highlight = 0xC67A;
    BlackFillScheme.highlightLight = 0xFFFF;
    BlackFillScheme.shadow = 0x8410;
    BlackFillScheme.shadowDark = 0x4208;
    BlackFillScheme.foreground = 0x0;
    BlackFillScheme.foregroundInactive = 0xD71C;
    BlackFillScheme.foregroundDisabled = 0x8410;
    BlackFillScheme.background = 0xFFFF;
    BlackFillScheme.backgroundInactive = 0xD71C;
    BlackFillScheme.backgroundDisabled = 0xC67A;
    BlackFillScheme.text = 0x0;
    BlackFillScheme.textHighlight = 0x1F;
    BlackFillScheme.textHighlightText = 0xFFFF;
    BlackFillScheme.textInactive = 0xD71C;
    BlackFillScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&OrangeFillScheme, GFX_COLOR_MODE_RGB_565);
    OrangeFillScheme.base = 0xFC00;
    OrangeFillScheme.highlight = 0xC67A;
    OrangeFillScheme.highlightLight = 0xFFFF;
    OrangeFillScheme.shadow = 0x8410;
    OrangeFillScheme.shadowDark = 0x4208;
    OrangeFillScheme.foreground = 0x0;
    OrangeFillScheme.foregroundInactive = 0xD71C;
    OrangeFillScheme.foregroundDisabled = 0x8410;
    OrangeFillScheme.background = 0xFC00;
    OrangeFillScheme.backgroundInactive = 0xD71C;
    OrangeFillScheme.backgroundDisabled = 0xC67A;
    OrangeFillScheme.text = 0x0;
    OrangeFillScheme.textHighlight = 0x1F;
    OrangeFillScheme.textHighlightText = 0xFFFF;
    OrangeFillScheme.textInactive = 0xD71C;
    OrangeFillScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&PinkFillScheme, GFX_COLOR_MODE_RGB_565);
    PinkFillScheme.base = 0xD018;
    PinkFillScheme.highlight = 0xC67A;
    PinkFillScheme.highlightLight = 0xFFFF;
    PinkFillScheme.shadow = 0x8410;
    PinkFillScheme.shadowDark = 0x4208;
    PinkFillScheme.foreground = 0x0;
    PinkFillScheme.foregroundInactive = 0xD71C;
    PinkFillScheme.foregroundDisabled = 0x8410;
    PinkFillScheme.background = 0xFFFF;
    PinkFillScheme.backgroundInactive = 0xD71C;
    PinkFillScheme.backgroundDisabled = 0xC67A;
    PinkFillScheme.text = 0x0;
    PinkFillScheme.textHighlight = 0x1F;
    PinkFillScheme.textHighlightText = 0xFFFF;
    PinkFillScheme.textInactive = 0xD71C;
    PinkFillScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&YellowFillScheme, GFX_COLOR_MODE_RGB_565);
    YellowFillScheme.base = 0xFFE0;
    YellowFillScheme.highlight = 0xC67A;
    YellowFillScheme.highlightLight = 0xFFFF;
    YellowFillScheme.shadow = 0x8410;
    YellowFillScheme.shadowDark = 0x4208;
    YellowFillScheme.foreground = 0x0;
    YellowFillScheme.foregroundInactive = 0xD71C;
    YellowFillScheme.foregroundDisabled = 0x8410;
    YellowFillScheme.background = 0xFFFF;
    YellowFillScheme.backgroundInactive = 0xD71C;
    YellowFillScheme.backgroundDisabled = 0xC67A;
    YellowFillScheme.text = 0x0;
    YellowFillScheme.textHighlight = 0x1F;
    YellowFillScheme.textHighlightText = 0xFFFF;
    YellowFillScheme.textInactive = 0xD71C;
    YellowFillScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&WhiteFillScheme, GFX_COLOR_MODE_RGB_565);
    WhiteFillScheme.base = 0xFFFF;
    WhiteFillScheme.highlight = 0xC67A;
    WhiteFillScheme.highlightLight = 0xFFFF;
    WhiteFillScheme.shadow = 0x8410;
    WhiteFillScheme.shadowDark = 0x4208;
    WhiteFillScheme.foreground = 0x0;
    WhiteFillScheme.foregroundInactive = 0xD71C;
    WhiteFillScheme.foregroundDisabled = 0x8410;
    WhiteFillScheme.background = 0xFFFF;
    WhiteFillScheme.backgroundInactive = 0xD71C;
    WhiteFillScheme.backgroundDisabled = 0xC67A;
    WhiteFillScheme.text = 0x0;
    WhiteFillScheme.textHighlight = 0x1F;
    WhiteFillScheme.textHighlightText = 0xFFFF;
    WhiteFillScheme.textInactive = 0xD71C;
    WhiteFillScheme.textDisabled = 0x8C92;

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

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget1 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget1, 120, 40);
    laWidget_SetSize((laWidget*)ImageWidget1, 240, 139);
    laWidget_SetBackgroundType((laWidget*)ImageWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget1, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget1, &PIC32Logo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget1);

    ImageWidget2 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget2, 120, 40);
    laWidget_SetSize((laWidget*)ImageWidget2, 240, 139);
    laWidget_SetVisible((laWidget*)ImageWidget2, LA_FALSE);
    laWidget_SetScheme((laWidget*)ImageWidget2, &WhiteBackgroundScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageWidget2, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget2, &HarmonyLogo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget2);

    PanelWidget = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget, 0, 207);
    laWidget_SetSize((laWidget*)PanelWidget, 480, 65);
    laWidget_SetOptimizationFlags((laWidget*)PanelWidget, LA_WIDGET_OPT_DRAW_ONCE);
    laWidget_SetScheme((laWidget*)PanelWidget, &WhiteFillScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget);

    ImageWidget3 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget3, 480, 0);
    laWidget_SetSize((laWidget*)ImageWidget3, 480, 65);
    laWidget_SetBackgroundType((laWidget*)ImageWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget3, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget3, &Bar);
    laWidget_AddChild((laWidget*)PanelWidget, (laWidget*)ImageWidget3);

    ImageWidget4 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget4, 17, 23);
    laWidget_SetSize((laWidget*)ImageWidget4, 144, 39);
    laWidget_SetVisible((laWidget*)ImageWidget4, LA_FALSE);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget4, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ImageWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget4, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget4, &MicrochipLogo);
    laWidget_AddChild((laWidget*)PanelWidget, (laWidget*)ImageWidget4);

}

static void ScreenCreate_FPSCounters(laScreen* screen)
{
    laLayer* layer0;

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

    FPSButtonCounter = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)FPSButtonCounter, 362, 50);
    laWidget_SetSize((laWidget*)FPSButtonCounter, 107, 30);
    laWidget_SetBackgroundType((laWidget*)FPSButtonCounter, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)FPSButtonCounter, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetToggleable(FPSButtonCounter, LA_TRUE);
    laButtonWidget_SetText(FPSButtonCounter, laString_CreateFromID(string_NumsLittle));
    laWidget_AddChild((laWidget*)layer0, (laWidget*)FPSButtonCounter);

}

static void ScreenCreate_FPSMotion(laScreen* screen)
{
    laLayer* layer0;

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
    laLabelWidget_SetHAlignment(NumRectCountLabel, LA_HALIGN_LEFT);
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
    laWidget_SetSize((laWidget*)SquareSizeLabel, 62, 16);
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

    FPSButtonMotion = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)FPSButtonMotion, 363, 47);
    laWidget_SetSize((laWidget*)FPSButtonMotion, 105, 30);
    laWidget_SetBackgroundType((laWidget*)FPSButtonMotion, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)FPSButtonMotion, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetToggleable(FPSButtonMotion, LA_TRUE);
    laButtonWidget_SetText(FPSButtonMotion, laString_CreateFromID(string_NumsLittle));
    laWidget_AddChild((laWidget*)layer0, (laWidget*)FPSButtonMotion);

}

static void ScreenCreate_FPSImages(laScreen* screen)
{
    laLayer* layer0;

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

    FPSButtonImages = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)FPSButtonImages, 362, 46);
    laWidget_SetSize((laWidget*)FPSButtonImages, 107, 31);
    laWidget_SetBackgroundType((laWidget*)FPSButtonImages, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)FPSButtonImages, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetToggleable(FPSButtonImages, LA_TRUE);
    laButtonWidget_SetText(FPSButtonImages, laString_CreateFromID(string_NumsLittle));
    laWidget_AddChild((laWidget*)layer0, (laWidget*)FPSButtonImages);

}



