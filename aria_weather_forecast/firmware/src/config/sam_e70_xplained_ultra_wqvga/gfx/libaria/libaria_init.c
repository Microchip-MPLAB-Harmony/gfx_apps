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

laScheme Red;
laScheme MyScheme;
laScheme Blue;
laScheme Yellow;
laScheme Purple;
laScheme GrayScheme;
laScheme TitleBarScheme;
laScheme WhiteScheme;
laScheme TextBoxScheme;
laScheme Green;
laScheme TextWhite;
laScheme GradientScheme;
laImageWidget* ImageWidget1;
laImageWidget* ImageWidget2;
laWidget* PanelWidget3;
laImageWidget* ImageWidget3;
laImageWidget* ImageWidget4;
laImageWidget* ImageWidget9;
laLabelWidget* TimeLabel;
laLabelWidget* LabelWidget2;
laImageSequenceWidget* ImageSequenceWidget1;
laLabelWidget* MinuteLabel;
laButtonWidget* ButtonWidget2;
laLabelWidget* LabelWidget5;
laWidget* PanelWidget2;
laWidget* PanelWidget6;
laWidget* PanelWidget1;
laWidget* PanelWidget5;
laButtonWidget* ButtonWidget1;
laImageWidget* CloudIcon;
laImageWidget* ImageWidget10;
laLabelWidget* LabelWidget1;
laLabelWidget* LabelWidget3;
laLabelWidget* LabelWidget11;
laLabelWidget* LabelWidget12;
laImageWidget* ImageWidget5;
laLabelWidget* LabelWidget6;
laLabelWidget* LabelWidget8;
laLabelWidget* LabelWidget9;
laLabelWidget* LabelWidget10;


static void ScreenCreate_SplashScreen(laScreen* screen);
static void ScreenCreate_MainScreen(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

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

    laScheme_Initialize(&Blue, GFX_COLOR_MODE_RGB_565);
    Blue.base = 0xBFFF;
    Blue.highlight = 0xC67A;
    Blue.highlightLight = 0xFFFF;
    Blue.shadow = 0x8410;
    Blue.shadowDark = 0x4208;
    Blue.foreground = 0x0;
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

    laScheme_Initialize(&GrayScheme, GFX_COLOR_MODE_RGB_565);
    GrayScheme.base = 0xD6FC;
    GrayScheme.highlight = 0xC67A;
    GrayScheme.highlightLight = 0xFFFF;
    GrayScheme.shadow = 0x8410;
    GrayScheme.shadowDark = 0x4208;
    GrayScheme.foreground = 0x0;
    GrayScheme.foregroundInactive = 0x8410;
    GrayScheme.foregroundDisabled = 0x8410;
    GrayScheme.background = 0xFFFF;
    GrayScheme.backgroundInactive = 0xC67A;
    GrayScheme.backgroundDisabled = 0xC67A;
    GrayScheme.text = 0x736E;
    GrayScheme.textHighlight = 0x1F;
    GrayScheme.textHighlightText = 0xFFFF;
    GrayScheme.textInactive = 0xC67A;
    GrayScheme.textDisabled = 0xC67A;

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

    laScheme_Initialize(&TextBoxScheme, GFX_COLOR_MODE_RGB_565);
    TextBoxScheme.base = 0xEF7D;
    TextBoxScheme.highlight = 0xC67A;
    TextBoxScheme.highlightLight = 0xFFFF;
    TextBoxScheme.shadow = 0x8410;
    TextBoxScheme.shadowDark = 0x4208;
    TextBoxScheme.foreground = 0xEF7D;
    TextBoxScheme.foregroundInactive = 0xDEFB;
    TextBoxScheme.foregroundDisabled = 0x8410;
    TextBoxScheme.background = 0xFFFF;
    TextBoxScheme.backgroundInactive = 0xC67A;
    TextBoxScheme.backgroundDisabled = 0xC67A;
    TextBoxScheme.text = 0x0;
    TextBoxScheme.textHighlight = 0x1F;
    TextBoxScheme.textHighlightText = 0xFFFF;
    TextBoxScheme.textInactive = 0xC67A;
    TextBoxScheme.textDisabled = 0xC67A;

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

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    laContext_SetStringTable(&stringTable);

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
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);
    laWidget_SetOptimizationFlags((laWidget*)layer0, LA_WIDGET_OPT_DRAW_ONCE);
    laLayer_SetAlphaEnable(layer0, LA_TRUE);
    laLayer_SetAlphaAmount(layer0, 0xFF);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget1 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget1, 120, 40);
    laWidget_SetSize((laWidget*)ImageWidget1, 240, 139);
    laWidget_SetScheme((laWidget*)ImageWidget1, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget1, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget1, &PIC32Logo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget1);

    ImageWidget2 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget2, 120, 40);
    laWidget_SetSize((laWidget*)ImageWidget2, 240, 139);
    laWidget_SetVisible((laWidget*)ImageWidget2, LA_FALSE);
    laWidget_SetScheme((laWidget*)ImageWidget2, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageWidget2, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget2, &HarmonyLogo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget2);

    PanelWidget3 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget3, 0, 207);
    laWidget_SetSize((laWidget*)PanelWidget3, 480, 65);
    laWidget_SetOptimizationFlags((laWidget*)PanelWidget3, LA_WIDGET_OPT_DRAW_ONCE);
    laWidget_SetScheme((laWidget*)PanelWidget3, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget3, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget3, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget3);

    ImageWidget3 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget3, 480, 0);
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
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &MyScheme);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget9 = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget9, 480, 104);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget9, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ImageWidget9, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget9, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)ImageWidget9, 0, 0, 4, 0);
    laImageWidget_SetImage(ImageWidget9, &clouds3);
    laImageWidget_SetHAlignment(ImageWidget9, LA_HALIGN_LEFT);
    laImageWidget_SetVAlignment(ImageWidget9, LA_VALIGN_TOP);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget9);

    TimeLabel = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)TimeLabel, 240, 10);
    laWidget_SetSize((laWidget*)TimeLabel, 21, 25);
    laWidget_SetScheme((laWidget*)TimeLabel, &TextWhite);
    laWidget_SetBackgroundType((laWidget*)TimeLabel, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)TimeLabel, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(TimeLabel, laString_CreateFromID(string_TimeHour));
    laLabelWidget_SetHAlignment(TimeLabel, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)ImageWidget9, (laWidget*)TimeLabel);

    LabelWidget2 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget2, 15, 7);
    laWidget_SetSize((laWidget*)LabelWidget2, 105, 36);
    laWidget_SetScheme((laWidget*)LabelWidget2, &TextWhite);
    laWidget_SetBackgroundType((laWidget*)LabelWidget2, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)LabelWidget2, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget2, laString_CreateFromID(string_Chandler));
    laLabelWidget_SetHAlignment(LabelWidget2, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)ImageWidget9, (laWidget*)LabelWidget2);

    ImageSequenceWidget1 = laImageSequenceWidget_New();
    laWidget_SetPosition((laWidget*)ImageSequenceWidget1, 253, 10);
    laWidget_SetSize((laWidget*)ImageSequenceWidget1, 18, 25);
    laWidget_SetBackgroundType((laWidget*)ImageSequenceWidget1, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)ImageSequenceWidget1, LA_WIDGET_BORDER_NONE);
    laImageSequenceWidget_SetImageCount(ImageSequenceWidget1, 2);
    laImageSequenceWidget_SetImage(ImageSequenceWidget1, 0, &colon);
    laImageSequenceWidget_SetRepeat(ImageSequenceWidget1, LA_TRUE);
    laWidget_AddChild((laWidget*)ImageWidget9, (laWidget*)ImageSequenceWidget1);

    MinuteLabel = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)MinuteLabel, 267, 10);
    laWidget_SetSize((laWidget*)MinuteLabel, 163, 25);
    laWidget_SetScheme((laWidget*)MinuteLabel, &TextWhite);
    laWidget_SetBackgroundType((laWidget*)MinuteLabel, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)MinuteLabel, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(MinuteLabel, laString_CreateFromID(string_TimeMinute));
    laLabelWidget_SetHAlignment(MinuteLabel, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)ImageWidget9, (laWidget*)MinuteLabel);

    ButtonWidget2 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget2, 435, 5);
    laWidget_SetSize((laWidget*)ButtonWidget2, 42, 36);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget2, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget2, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedImage(ButtonWidget2, &mchpLogo);
    laButtonWidget_SetImagePosition(ButtonWidget2, LA_RELATIVE_POSITION_BEHIND);
    laButtonWidget_SetPressedOffset(ButtonWidget2, 0);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget2, &ButtonWidget2_ReleasedEvent);

    laWidget_AddChild((laWidget*)ImageWidget9, (laWidget*)ButtonWidget2);

    LabelWidget5 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget5, 20, 43);
    laWidget_SetSize((laWidget*)LabelWidget5, 124, 54);
    laWidget_SetOptimizationFlags((laWidget*)LabelWidget5, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)LabelWidget5, &TextWhite);
    laWidget_SetBackgroundType((laWidget*)LabelWidget5, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)LabelWidget5, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget5, laString_CreateFromID(string_degrees));
    laLabelWidget_SetHAlignment(LabelWidget5, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)ImageWidget9, (laWidget*)LabelWidget5);

    PanelWidget2 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget2, 0, 104);
    laWidget_SetSize((laWidget*)PanelWidget2, 480, 168);
    laWidget_SetScheme((laWidget*)PanelWidget2, &GrayScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget2, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget2);

    PanelWidget6 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget6, 472, 11);
    laWidget_SetSize((laWidget*)PanelWidget6, 6, 152);
    laWidget_SetBackgroundType((laWidget*)PanelWidget6, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget6, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)PanelWidget2, PanelWidget6);

    PanelWidget1 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget1, 9, 159);
    laWidget_SetSize((laWidget*)PanelWidget1, 468, 4);
    laWidget_SetBackgroundType((laWidget*)PanelWidget1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget1, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)PanelWidget2, PanelWidget1);

    PanelWidget5 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget5, 352, 8);
    laWidget_SetSize((laWidget*)PanelWidget5, 120, 152);
    laWidget_SetScheme((laWidget*)PanelWidget5, &TextBoxScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget5, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget5, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)PanelWidget2, PanelWidget5);

    ButtonWidget1 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget1, 16, 7);
    laWidget_SetSize((laWidget*)ButtonWidget1, 100, 74);
    laWidget_SetScheme((laWidget*)ButtonWidget1, &TextBoxScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget1, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetImagePosition(ButtonWidget1, LA_RELATIVE_POSITION_BEHIND);
    laButtonWidget_SetPressedOffset(ButtonWidget1, 0);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget1, &ButtonWidget1_ReleasedEvent);

    laWidget_AddChild((laWidget*)PanelWidget5, (laWidget*)ButtonWidget1);

    CloudIcon = laImageWidget_New();
    laWidget_SetPosition((laWidget*)CloudIcon, 18, 8);
    laWidget_SetSize((laWidget*)CloudIcon, 64, 64);
    laWidget_SetScheme((laWidget*)CloudIcon, &TextBoxScheme);
    laWidget_SetBackgroundType((laWidget*)CloudIcon, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CloudIcon, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(CloudIcon, &cloud_icon);
    laWidget_AddChild((laWidget*)ButtonWidget1, (laWidget*)CloudIcon);

    ImageWidget10 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget10, 6, 8);
    laWidget_SetSize((laWidget*)ImageWidget10, 346, 76);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget10, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ImageWidget10, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget10, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget10, &gradient2);
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)ImageWidget10);

    LabelWidget1 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget1, 10, 10);
    laWidget_SetSize((laWidget*)LabelWidget1, 100, 25);
    laWidget_SetScheme((laWidget*)LabelWidget1, &Green);
    laWidget_SetBackgroundType((laWidget*)LabelWidget1, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)LabelWidget1, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget1, laString_CreateFromID(string_Current));
    laLabelWidget_SetHAlignment(LabelWidget1, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)ImageWidget10, (laWidget*)LabelWidget1);

    LabelWidget3 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget3, 225, 10);
    laWidget_SetSize((laWidget*)LabelWidget3, 84, 30);
    laWidget_SetScheme((laWidget*)LabelWidget3, &TextBoxScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget3, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)LabelWidget3, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget3, laString_CreateFromID(string_Cloudy));
    laLabelWidget_SetHAlignment(LabelWidget3, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)ImageWidget10, (laWidget*)LabelWidget3);

    LabelWidget11 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget11, 17, 48);
    laWidget_SetSize((laWidget*)LabelWidget11, 124, 25);
    laWidget_SetScheme((laWidget*)LabelWidget11, &TextBoxScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget11, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)LabelWidget11, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget11, laString_CreateFromID(string_humidity));
    laLabelWidget_SetHAlignment(LabelWidget11, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)ImageWidget10, (laWidget*)LabelWidget11);

    LabelWidget12 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget12, 225, 48);
    laWidget_SetSize((laWidget*)LabelWidget12, 100, 25);
    laWidget_SetScheme((laWidget*)LabelWidget12, &TextBoxScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget12, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)LabelWidget12, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget12, laString_CreateFromID(string_thirteenpercent));
    laLabelWidget_SetHAlignment(LabelWidget12, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)ImageWidget10, (laWidget*)LabelWidget12);

    ImageWidget5 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget5, 6, 84);
    laWidget_SetSize((laWidget*)ImageWidget5, 346, 76);
    laWidget_SetOptimizationFlags((laWidget*)ImageWidget5, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ImageWidget5, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget5, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget5, &gradient2);
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)ImageWidget5);

    LabelWidget6 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget6, 18, 4);
    laWidget_SetSize((laWidget*)LabelWidget6, 100, 25);
    laWidget_SetScheme((laWidget*)LabelWidget6, &TextBoxScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget6, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)LabelWidget6, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget6, laString_CreateFromID(string_uvindex));
    laLabelWidget_SetHAlignment(LabelWidget6, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)ImageWidget5, (laWidget*)LabelWidget6);

    LabelWidget8 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget8, 225, 1);
    laWidget_SetSize((laWidget*)LabelWidget8, 100, 25);
    laWidget_SetScheme((laWidget*)LabelWidget8, &TextBoxScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget8, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)LabelWidget8, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget8, laString_CreateFromID(string_uvlow));
    laLabelWidget_SetHAlignment(LabelWidget8, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)ImageWidget5, (laWidget*)LabelWidget8);

    LabelWidget9 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget9, 18, 36);
    laWidget_SetSize((laWidget*)LabelWidget9, 187, 25);
    laWidget_SetScheme((laWidget*)LabelWidget9, &TextBoxScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget9, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)LabelWidget9, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget9, laString_CreateFromID(string_windspeed));
    laLabelWidget_SetHAlignment(LabelWidget9, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)ImageWidget5, (laWidget*)LabelWidget9);

    LabelWidget10 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget10, 225, 36);
    laWidget_SetSize((laWidget*)LabelWidget10, 83, 25);
    laWidget_SetScheme((laWidget*)LabelWidget10, &TextBoxScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget10, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)LabelWidget10, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget10, laString_CreateFromID(string_ninemph));
    laLabelWidget_SetHAlignment(LabelWidget10, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)ImageWidget5, (laWidget*)LabelWidget10);

}



