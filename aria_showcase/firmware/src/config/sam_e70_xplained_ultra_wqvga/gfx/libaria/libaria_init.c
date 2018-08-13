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

laScheme defaultScheme;
laScheme ListWheelScheme;
laScheme AlternateGradientScheme;
laScheme RadioButtonsOnDarkScheme;
laScheme whiteScheme;
laScheme BlackBackground;
laScheme BackgroundGradientScheme;
laScheme MainMenuGradientScheme;
laScheme TouchTestScheme;
laScheme GradientScheme;
laImageWidget* Pic32Logo;
laImageWidget* HarmonyLogoWidget;
laWidget* PanelWidget;
laImageWidget* SplashBar;
laImageWidget* SplashBarLogo;
laGradientWidget* GradientWidget1;
laButtonWidget* ButtonWidget13;
laButtonWidget* ButtonWidget14;
laButtonWidget* ButtonWidget15;
laButtonWidget* ButtonWidget16;
laButtonWidget* ButtonWidget17;
laButtonWidget* ButtonWidget18;
laLabelWidget* LabelWidget1;
laLabelWidget* LabelWidget2;
laImageWidget* ImageWidget3;
laImageWidget* ImageWidget4;
laButtonWidget* ButtonWidget19;
laButtonWidget* ButtonWidget29;
laGradientWidget* GradientWidget3;
laButtonWidget* ButtonWidget1;
laButtonWidget* ButtonWidget7;
laRectangleWidget* RectangleWidget2;
laLabelWidget* LabelWidget3;
laListWheelWidget* ListWheel2;
laListWheelWidget* ListWheel4;
laListWheelWidget* ListWheel5;
laListWheelWidget* ListWheel1;
laLabelWidget* LabelWidget4;
laLabelWidget* LabelWidget5;
laButtonWidget* ButtonWidget30;
laGradientWidget* GradientWidget2;
laTouchTestWidget* TouchTestWidget1;
laLabelWidget* LabelWidget6;
laImageWidget* ImageWidget5;
laButtonWidget* ButtonWidget2;
laButtonWidget* ButtonWidget3;
laLabelWidget* LabelWidget7;
laButtonWidget* ButtonWidget31;
laGradientWidget* GradientWidget4;
laKeyPadWidget* KeyPadWidget1;
laTextFieldWidget* TextFieldWidget1;
laButtonWidget* ButtonWidget5;
laButtonWidget* ButtonWidget6;
laLabelWidget* LabelWidget8;
laButtonWidget* ButtonWidget32;
laGradientWidget* GradientWidget5;
laWidget* PanelWidget1;
laSliderWidget* SliderWidget1;
laLabelWidget* SliderValueLabelWidget;
laWidget* PanelWidget2;
laImageWidget* ImageWidget1;
laImageWidget* ImageWidget2;
laButtonWidget* ButtonWidget4;
laButtonWidget* ButtonWidget8;
laLabelWidget* LabelWidget9;
laButtonWidget* ButtonWidget33;
laButtonWidget* SliderUpButtonWidget;
laButtonWidget* SliderDownButtonWidget;
laGradientWidget* GradientWidget6;
laImageSequenceWidget* ImageSequenceWidget1;
laButtonWidget* ButtonWidget9;
laButtonWidget* ButtonWidget11;
laLabelWidget* LabelWidget10;
laButtonWidget* ButtonWidget10;
laButtonWidget* ButtonWidget20;
laButtonWidget* ButtonWidget21;
laButtonWidget* ButtonWidget22;
laImageWidget* SSStatusImageWidget;
laGradientWidget* GradientWidget7;
laButtonWidget* ButtonWidget12;
laWidget* PanelWidget3;
laLabelWidget* LabelWidget11;
laRadioButtonWidget* RadioButtonChinese;
laRadioButtonWidget* RadioButtonEnglish;
laButtonWidget* ButtonWidgetChinese;
laButtonWidget* ButtonWidgetEnglish;
laButtonWidget* ButtonWidget23;
laImageWidget* ImageWidget6;
laLabelWidget* LabelWidget12;
laLabelWidget* LabelWidget13;
laLabelWidget* LabelWidget14;
laLabelWidget* LabelWidget15;
laLabelWidget* LabelWidget16;
laLabelWidget* LabelWidget17;
laLabelWidget* LabelWidget18;
laLabelWidget* LabelWidget19;
laLabelWidget* LabelWidget20;
laImageWidget* ImageWidget7;
laImageWidget* ImageWidget8;
laImageWidget* ImageWidget9;
laImageWidget* ImageWidget10;
laImageWidget* ImageWidget11;
laImageWidget* ImageWidget12;
laImageWidget* ImageWidget13;
laImageWidget* ImageWidget14;
laLabelWidget* LabelWidget21;
laButtonWidget* ButtonWidget24;
laLabelWidget* LabelWidget22;
laLabelWidget* LabelWidget24;
laImageWidget* ImageWidget16;
laImageWidget* ImageWidget17;
laButtonWidget* ButtonWidget25;
laLabelWidget* LabelWidget25;
laLabelWidget* LabelWidget26;
laLabelWidget* LabelWidget28;
laImageWidget* ImageWidget19;
laImageWidget* ImageWidget20;
laButtonWidget* ButtonWidget26;
laLabelWidget* LabelWidget29;
laLabelWidget* LabelWidget30;
laLabelWidget* LabelWidget32;
laImageWidget* ImageWidget22;
laButtonWidget* ButtonWidget27;
laImageWidget* ImageWidget23;
laLabelWidget* LabelWidget33;
laLabelWidget* LabelWidget34;
laLabelWidget* LabelWidget35;
laLabelWidget* LabelWidget23;
laImageWidget* ImageWidget15;
laButtonWidget* ButtonWidget28;
laImageWidget* ImageWidget18;
laLabelWidget* LabelWidget27;
laLabelWidget* LabelWidget31;
laLabelWidget* LabelWidget36;
laLabelWidget* LabelWidget37;
laLabelWidget* LabelWidget38;
laLabelWidget* LabelWidget39;
laImageWidget* ImageWidget21;
laImageWidget* ImageWidget24;
laImageWidget* ImageWidget25;
laImageWidget* ImageWidget26;


static void ScreenCreate_SplashScreen(laScreen* screen);
static void ScreenCreate_MainMenu(laScreen* screen);
static void ScreenCreate_FirstScreen(laScreen* screen);
static void ScreenCreate_SecondScreen(laScreen* screen);
static void ScreenCreate_ThirdScreen(laScreen* screen);
static void ScreenCreate_FourthScreen(laScreen* screen);
static void ScreenCreate_FifthScreen(laScreen* screen);
static void ScreenCreate_SettingsScreen(laScreen* screen);
static void ScreenCreate_MainMenuHelp(laScreen* screen);
static void ScreenCreate_ListWheelHelpScreen(laScreen* screen);
static void ScreenCreate_TouchTestHelpScreen(laScreen* screen);
static void ScreenCreate_KeypadHelpScreen(laScreen* screen);
static void ScreenCreate_AlphaBlendingHelpScreen(laScreen* screen);
static void ScreenCreate_SlideshowHelpScreen(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&defaultScheme, GFX_COLOR_MODE_RGB_565);
    defaultScheme.base = 0xFFFF;
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

    laScheme_Initialize(&ListWheelScheme, GFX_COLOR_MODE_RGB_565);
    ListWheelScheme.base = 0xFFFF;
    ListWheelScheme.highlight = 0xFFFF;
    ListWheelScheme.highlightLight = 0xFFFF;
    ListWheelScheme.shadow = 0xFFFF;
    ListWheelScheme.shadowDark = 0x4208;
    ListWheelScheme.foreground = 0x0;
    ListWheelScheme.foregroundInactive = 0x841F;
    ListWheelScheme.foregroundDisabled = 0x0;
    ListWheelScheme.background = 0xFFFF;
    ListWheelScheme.backgroundInactive = 0xFFDF;
    ListWheelScheme.backgroundDisabled = 0x6B4D;
    ListWheelScheme.text = 0x0;
    ListWheelScheme.textHighlight = 0x4208;
    ListWheelScheme.textHighlightText = 0xFFFF;
    ListWheelScheme.textInactive = 0x2104;
    ListWheelScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&AlternateGradientScheme, GFX_COLOR_MODE_RGB_565);
    AlternateGradientScheme.base = 0xF800;
    AlternateGradientScheme.highlight = 0xC67A;
    AlternateGradientScheme.highlightLight = 0xFFFF;
    AlternateGradientScheme.shadow = 0x8410;
    AlternateGradientScheme.shadowDark = 0x4208;
    AlternateGradientScheme.foreground = 0xF800;
    AlternateGradientScheme.foregroundInactive = 0x1F;
    AlternateGradientScheme.foregroundDisabled = 0x8410;
    AlternateGradientScheme.background = 0x17;
    AlternateGradientScheme.backgroundInactive = 0xD71C;
    AlternateGradientScheme.backgroundDisabled = 0xC67A;
    AlternateGradientScheme.text = 0x0;
    AlternateGradientScheme.textHighlight = 0x1F;
    AlternateGradientScheme.textHighlightText = 0xFFFF;
    AlternateGradientScheme.textInactive = 0xD71C;
    AlternateGradientScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&RadioButtonsOnDarkScheme, GFX_COLOR_MODE_RGB_565);
    RadioButtonsOnDarkScheme.base = 0xC67A;
    RadioButtonsOnDarkScheme.highlight = 0xC67A;
    RadioButtonsOnDarkScheme.highlightLight = 0xFFFF;
    RadioButtonsOnDarkScheme.shadow = 0x8410;
    RadioButtonsOnDarkScheme.shadowDark = 0x4208;
    RadioButtonsOnDarkScheme.foreground = 0x0;
    RadioButtonsOnDarkScheme.foregroundInactive = 0xD71C;
    RadioButtonsOnDarkScheme.foregroundDisabled = 0x8410;
    RadioButtonsOnDarkScheme.background = 0xFFFF;
    RadioButtonsOnDarkScheme.backgroundInactive = 0xD71C;
    RadioButtonsOnDarkScheme.backgroundDisabled = 0xC67A;
    RadioButtonsOnDarkScheme.text = 0xFFFF;
    RadioButtonsOnDarkScheme.textHighlight = 0x1F;
    RadioButtonsOnDarkScheme.textHighlightText = 0xFFFF;
    RadioButtonsOnDarkScheme.textInactive = 0xD71C;
    RadioButtonsOnDarkScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&whiteScheme, GFX_COLOR_MODE_RGB_565);
    whiteScheme.base = 0xFFFF;
    whiteScheme.highlight = 0xC67A;
    whiteScheme.highlightLight = 0xFFFF;
    whiteScheme.shadow = 0x8410;
    whiteScheme.shadowDark = 0x4208;
    whiteScheme.foreground = 0x0;
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

    laScheme_Initialize(&BlackBackground, GFX_COLOR_MODE_RGB_565);
    BlackBackground.base = 0xC67A;
    BlackBackground.highlight = 0xC67A;
    BlackBackground.highlightLight = 0xFFFF;
    BlackBackground.shadow = 0x8410;
    BlackBackground.shadowDark = 0x4208;
    BlackBackground.foreground = 0x0;
    BlackBackground.foregroundInactive = 0xD71C;
    BlackBackground.foregroundDisabled = 0x8410;
    BlackBackground.background = 0x0;
    BlackBackground.backgroundInactive = 0xD71C;
    BlackBackground.backgroundDisabled = 0xC67A;
    BlackBackground.text = 0xCF3D;
    BlackBackground.textHighlight = 0x1F;
    BlackBackground.textHighlightText = 0xFFFF;
    BlackBackground.textInactive = 0xD71C;
    BlackBackground.textDisabled = 0x8C92;

    laScheme_Initialize(&BackgroundGradientScheme, GFX_COLOR_MODE_RGB_565);
    BackgroundGradientScheme.base = 0x0;
    BackgroundGradientScheme.highlight = 0xC67A;
    BackgroundGradientScheme.highlightLight = 0xFFFF;
    BackgroundGradientScheme.shadow = 0x8410;
    BackgroundGradientScheme.shadowDark = 0x4208;
    BackgroundGradientScheme.foreground = 0xB61F;
    BackgroundGradientScheme.foregroundInactive = 0x8;
    BackgroundGradientScheme.foregroundDisabled = 0x8410;
    BackgroundGradientScheme.background = 0xA;
    BackgroundGradientScheme.backgroundInactive = 0xD71C;
    BackgroundGradientScheme.backgroundDisabled = 0xC67A;
    BackgroundGradientScheme.text = 0x0;
    BackgroundGradientScheme.textHighlight = 0x1F;
    BackgroundGradientScheme.textHighlightText = 0xFFFF;
    BackgroundGradientScheme.textInactive = 0xD71C;
    BackgroundGradientScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&MainMenuGradientScheme, GFX_COLOR_MODE_RGB_565);
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
    MainMenuGradientScheme.text = 0x0;
    MainMenuGradientScheme.textHighlight = 0x1F;
    MainMenuGradientScheme.textHighlightText = 0xFFFF;
    MainMenuGradientScheme.textInactive = 0xD71C;
    MainMenuGradientScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&TouchTestScheme, GFX_COLOR_MODE_RGB_565);
    TouchTestScheme.base = 0xFFFF;
    TouchTestScheme.highlight = 0xC67A;
    TouchTestScheme.highlightLight = 0xFFFF;
    TouchTestScheme.shadow = 0x8410;
    TouchTestScheme.shadowDark = 0x4208;
    TouchTestScheme.foreground = 0xF81F;
    TouchTestScheme.foregroundInactive = 0x7FF;
    TouchTestScheme.foregroundDisabled = 0x8410;
    TouchTestScheme.background = 0x17;
    TouchTestScheme.backgroundInactive = 0xD71C;
    TouchTestScheme.backgroundDisabled = 0xC67A;
    TouchTestScheme.text = 0x7FF;
    TouchTestScheme.textHighlight = 0xF81F;
    TouchTestScheme.textHighlightText = 0xFFFF;
    TouchTestScheme.textInactive = 0xD71C;
    TouchTestScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&GradientScheme, GFX_COLOR_MODE_RGB_565);
    GradientScheme.base = 0xF800;
    GradientScheme.highlight = 0xC67A;
    GradientScheme.highlightLight = 0xFFFF;
    GradientScheme.shadow = 0x8410;
    GradientScheme.shadowDark = 0x4208;
    GradientScheme.foreground = 0x7E0;
    GradientScheme.foregroundInactive = 0xFFE0;
    GradientScheme.foregroundDisabled = 0x8410;
    GradientScheme.background = 0x17;
    GradientScheme.backgroundInactive = 0xD71C;
    GradientScheme.backgroundDisabled = 0xC67A;
    GradientScheme.text = 0x0;
    GradientScheme.textHighlight = 0x1F;
    GradientScheme.textHighlightText = 0x87FF;
    GradientScheme.textInactive = 0xD71C;
    GradientScheme.textDisabled = 0x8C92;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    laContext_SetStringTable(&stringTable);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_SplashScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_MainMenu);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_FirstScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_SecondScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_ThirdScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_FourthScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_FifthScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_SettingsScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_MainMenuHelp);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_ListWheelHelpScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_TouchTestHelpScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_KeypadHelpScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_AlphaBlendingHelpScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_SlideshowHelpScreen);
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

    Pic32Logo = laImageWidget_New();
    laWidget_SetPosition((laWidget*)Pic32Logo, 120, 40);
    laWidget_SetSize((laWidget*)Pic32Logo, 240, 139);
    laWidget_SetBackgroundType((laWidget*)Pic32Logo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)Pic32Logo, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(Pic32Logo, &PIC32Logo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)Pic32Logo);

    HarmonyLogoWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)HarmonyLogoWidget, 120, 40);
    laWidget_SetSize((laWidget*)HarmonyLogoWidget, 240, 139);
    laWidget_SetVisible((laWidget*)HarmonyLogoWidget, LA_FALSE);
    laWidget_SetScheme((laWidget*)HarmonyLogoWidget, &whiteScheme);
    laWidget_SetBackgroundType((laWidget*)HarmonyLogoWidget, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)HarmonyLogoWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(HarmonyLogoWidget, &HarmonyLogo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)HarmonyLogoWidget);

    PanelWidget = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget, 0, 207);
    laWidget_SetSize((laWidget*)PanelWidget, 480, 65);
    laWidget_SetOptimizationFlags((laWidget*)PanelWidget, LA_WIDGET_OPT_DRAW_ONCE);
    laWidget_SetScheme((laWidget*)PanelWidget, &whiteScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget);

    SplashBar = laImageWidget_New();
    laWidget_SetPosition((laWidget*)SplashBar, 480, 0);
    laWidget_SetSize((laWidget*)SplashBar, 480, 65);
    laWidget_SetBackgroundType((laWidget*)SplashBar, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SplashBar, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(SplashBar, &Bar);
    laWidget_AddChild((laWidget*)PanelWidget, (laWidget*)SplashBar);

    SplashBarLogo = laImageWidget_New();
    laWidget_SetPosition((laWidget*)SplashBarLogo, 17, 23);
    laWidget_SetSize((laWidget*)SplashBarLogo, 144, 39);
    laWidget_SetVisible((laWidget*)SplashBarLogo, LA_FALSE);
    laWidget_SetOptimizationFlags((laWidget*)SplashBarLogo, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)SplashBarLogo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SplashBarLogo, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(SplashBarLogo, &MicrochipLogo_1);
    laWidget_AddChild((laWidget*)PanelWidget, (laWidget*)SplashBarLogo);

}

static void ScreenCreate_MainMenu(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_NONE);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    GradientWidget1 = laGradientWidget_New();
    laWidget_SetSize((laWidget*)GradientWidget1, 480, 272);
    laWidget_SetScheme((laWidget*)GradientWidget1, &BackgroundGradientScheme);
    laWidget_SetBackgroundType((laWidget*)GradientWidget1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GradientWidget1, LA_WIDGET_BORDER_NONE);
    laGradientWidget_SetDirection((laGradientWidget*)GradientWidget1, LA_GRADIENT_DIRECTION_DOWN);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)GradientWidget1);

    ButtonWidget13 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget13, 10, 83);
    laWidget_SetSize((laWidget*)ButtonWidget13, 85, 78);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget13, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget13, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget13, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget13, &GFX_Slide_80_drop);
    laButtonWidget_SetReleasedImage(ButtonWidget13, &GFX_Slide_80_drop);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget13, &ButtonWidget13_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget13);

    ButtonWidget14 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget14, 296, 87);
    laWidget_SetSize((laWidget*)ButtonWidget14, 83, 74);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget14, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget14, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget14, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget14, &GFX_alpha_80x80_drop);
    laButtonWidget_SetReleasedImage(ButtonWidget14, &GFX_alpha_80x80_drop);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget14, &ButtonWidget14_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget14);

    ButtonWidget15 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget15, 386, 83);
    laWidget_SetSize((laWidget*)ButtonWidget15, 84, 80);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget15, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget15, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget15, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget15, &GFX_SlideShow_80_drop);
    laButtonWidget_SetReleasedImage(ButtonWidget15, &GFX_SlideShow_80_drop);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget15, &ButtonWidget15_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget15);

    ButtonWidget16 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget16, 103, 83);
    laWidget_SetSize((laWidget*)ButtonWidget16, 86, 81);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget16, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget16, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget16, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget16, &GFX_Touch_80_drop);
    laButtonWidget_SetReleasedImage(ButtonWidget16, &GFX_Touch_80_drop);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget16, &ButtonWidget16_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget16);

    ButtonWidget17 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget17, 200, 84);
    laWidget_SetSize((laWidget*)ButtonWidget17, 84, 77);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget17, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget17, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget17, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget17, &GFX_Keyboard_80_drop);
    laButtonWidget_SetReleasedImage(ButtonWidget17, &GFX_Keyboard_80_drop);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget17, &ButtonWidget17_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget17);

    ButtonWidget18 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget18, -9, 225);
    laWidget_SetSize((laWidget*)ButtonWidget18, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget18, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget18, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget18, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget18, &GFX_Help_60);
    laButtonWidget_SetReleasedImage(ButtonWidget18, &GFX_Help_60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget18, &ButtonWidget18_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget18);

    LabelWidget1 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget1, 73, 179);
    laWidget_SetSize((laWidget*)LabelWidget1, 168, 32);
    laWidget_SetScheme((laWidget*)LabelWidget1, &BlackBackground);
    laWidget_SetBackgroundType((laWidget*)LabelWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget1, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget1, laString_CreateFromID(string_Harmony));
    laLabelWidget_SetHAlignment(LabelWidget1, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget1);

    LabelWidget2 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget2, 233, 180);
    laWidget_SetSize((laWidget*)LabelWidget2, 190, 31);
    laWidget_SetScheme((laWidget*)LabelWidget2, &BlackBackground);
    laWidget_SetBackgroundType((laWidget*)LabelWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget2, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget2, laString_CreateFromID(string_Title));
    laLabelWidget_SetHAlignment(LabelWidget2, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget2);

    ImageWidget3 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget3, 2, 13);
    laWidget_SetSize((laWidget*)ImageWidget3, 153, 37);
    laWidget_SetBackgroundType((laWidget*)ImageWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget3, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget3, &GFX_Microchip_logo_150x30);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget3);

    ImageWidget4 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget4, 386, 0);
    laWidget_SetSize((laWidget*)ImageWidget4, 94, 56);
    laWidget_SetBackgroundType((laWidget*)ImageWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget4, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget4, &GFX_mplab_logo_80x80);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget4);

    ButtonWidget19 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget19, 430, 225);
    laWidget_SetSize((laWidget*)ButtonWidget19, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget19, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget19, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget19, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget19, &GFX_Settings_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidget19, &GFX_Settings_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget19, &ButtonWidget19_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget19);

    ButtonWidget29 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget29, 370, 225);
    laWidget_SetSize((laWidget*)ButtonWidget29, 60, 60);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget29, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget29, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget29, &GFX_NextScreen_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidget29, &GFX_NextScreen_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget29, &ButtonWidget29_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget29);

}

static void ScreenCreate_FirstScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_NONE);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    GradientWidget3 = laGradientWidget_New();
    laWidget_SetSize((laWidget*)GradientWidget3, 480, 272);
    laWidget_SetScheme((laWidget*)GradientWidget3, &BackgroundGradientScheme);
    laWidget_SetBackgroundType((laWidget*)GradientWidget3, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GradientWidget3, LA_WIDGET_BORDER_NONE);
    laGradientWidget_SetDirection((laGradientWidget*)GradientWidget3, LA_GRADIENT_DIRECTION_DOWN);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)GradientWidget3);

    ButtonWidget1 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget1, -9, 225);
    laWidget_SetSize((laWidget*)ButtonWidget1, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget1, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget1, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget1, &GFX_Help_60);
    laButtonWidget_SetReleasedImage(ButtonWidget1, &GFX_Help_60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget1, &ButtonWidget1_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget1);

    ButtonWidget7 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget7, 430, 225);
    laWidget_SetSize((laWidget*)ButtonWidget7, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget7, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget7, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget7, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget7, &GFX_Home_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidget7, &GFX_Home_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget7, &ButtonWidget7_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget7);

    RectangleWidget2 = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)RectangleWidget2, 98, 61);
    laWidget_SetSize((laWidget*)RectangleWidget2, 272, 141);
    laWidget_SetScheme((laWidget*)RectangleWidget2, &defaultScheme);
    laWidget_SetBackgroundType((laWidget*)RectangleWidget2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RectangleWidget2, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(RectangleWidget2, 4);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)RectangleWidget2);

    LabelWidget3 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget3, 60, 54);
    laWidget_SetSize((laWidget*)LabelWidget3, 11, 36);
    laWidget_SetEnabled((laWidget*)LabelWidget3, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)LabelWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget3, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget3, laString_CreateFromID(string_colon));
    laLabelWidget_SetHAlignment(LabelWidget3, LA_HALIGN_LEFT);
    laLabelWidget_SetVAlignment(LabelWidget3, LA_VALIGN_TOP);
    laWidget_AddChild((laWidget*)RectangleWidget2, (laWidget*)LabelWidget3);

    ListWheel2 = laListWheelWidget_New();
    laWidget_SetPosition((laWidget*)ListWheel2, 4, 4);
    laWidget_SetSize((laWidget*)ListWheel2, 57, 133);
    laWidget_SetOptimizationFlags((laWidget*)ListWheel2, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)ListWheel2, &ListWheelScheme);
    laWidget_SetBackgroundType((laWidget*)ListWheel2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ListWheel2, LA_WIDGET_BORDER_LINE);
    laListWheelWidget_SetFlickInitSpeed(ListWheel2, 5);
    laListWheelWidget_SetMaxMomentum(ListWheel2, 30000);
    laListWheelWidget_SetRotationUpdateRate(ListWheel2, 50);
    laListWheelWidget_AppendItem(ListWheel2);
    laListWheelWidget_SetItemText(ListWheel2, 0, laString_CreateFromID(string_num12));
    laListWheelWidget_AppendItem(ListWheel2);
    laListWheelWidget_SetItemText(ListWheel2, 1, laString_CreateFromID(string_num1));
    laListWheelWidget_AppendItem(ListWheel2);
    laListWheelWidget_SetItemText(ListWheel2, 2, laString_CreateFromID(string_num2));
    laListWheelWidget_AppendItem(ListWheel2);
    laListWheelWidget_SetItemText(ListWheel2, 3, laString_CreateFromID(string_num3));
    laListWheelWidget_AppendItem(ListWheel2);
    laListWheelWidget_SetItemText(ListWheel2, 4, laString_CreateFromID(string_num4));
    laListWheelWidget_AppendItem(ListWheel2);
    laListWheelWidget_SetItemText(ListWheel2, 5, laString_CreateFromID(string_num5));
    laListWheelWidget_AppendItem(ListWheel2);
    laListWheelWidget_SetItemText(ListWheel2, 6, laString_CreateFromID(string_num6));
    laListWheelWidget_AppendItem(ListWheel2);
    laListWheelWidget_SetItemText(ListWheel2, 7, laString_CreateFromID(string_num7));
    laListWheelWidget_AppendItem(ListWheel2);
    laListWheelWidget_SetItemText(ListWheel2, 8, laString_CreateFromID(string_num8));
    laListWheelWidget_AppendItem(ListWheel2);
    laListWheelWidget_SetItemText(ListWheel2, 9, laString_CreateFromID(string_num9));
    laListWheelWidget_AppendItem(ListWheel2);
    laListWheelWidget_SetItemText(ListWheel2, 10, laString_CreateFromID(string_num10));
    laListWheelWidget_AppendItem(ListWheel2);
    laListWheelWidget_SetItemText(ListWheel2, 11, laString_CreateFromID(string_num11));
    laWidget_AddChild((laWidget*)RectangleWidget2, (laWidget*)ListWheel2);

    ListWheel4 = laListWheelWidget_New();
    laWidget_SetPosition((laWidget*)ListWheel4, 70, 4);
    laWidget_SetSize((laWidget*)ListWheel4, 56, 133);
    laWidget_SetOptimizationFlags((laWidget*)ListWheel4, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)ListWheel4, &ListWheelScheme);
    laWidget_SetBackgroundType((laWidget*)ListWheel4, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ListWheel4, LA_WIDGET_BORDER_LINE);
    laListWheelWidget_SetFlickInitSpeed(ListWheel4, 5);
    laListWheelWidget_SetMaxMomentum(ListWheel4, 30000);
    laListWheelWidget_SetRotationUpdateRate(ListWheel4, 50);
    laListWheelWidget_AppendItem(ListWheel4);
    laListWheelWidget_SetItemText(ListWheel4, 0, laString_CreateFromID(string_num0));
    laListWheelWidget_AppendItem(ListWheel4);
    laListWheelWidget_SetItemText(ListWheel4, 1, laString_CreateFromID(string_num1));
    laListWheelWidget_AppendItem(ListWheel4);
    laListWheelWidget_SetItemText(ListWheel4, 2, laString_CreateFromID(string_num2));
    laListWheelWidget_AppendItem(ListWheel4);
    laListWheelWidget_SetItemText(ListWheel4, 3, laString_CreateFromID(string_num3));
    laListWheelWidget_AppendItem(ListWheel4);
    laListWheelWidget_SetItemText(ListWheel4, 4, laString_CreateFromID(string_num4));
    laListWheelWidget_AppendItem(ListWheel4);
    laListWheelWidget_SetItemText(ListWheel4, 5, laString_CreateFromID(string_num5));
    laWidget_AddChild((laWidget*)RectangleWidget2, (laWidget*)ListWheel4);

    ListWheel5 = laListWheelWidget_New();
    laWidget_SetPosition((laWidget*)ListWheel5, 129, 4);
    laWidget_SetSize((laWidget*)ListWheel5, 57, 133);
    laWidget_SetOptimizationFlags((laWidget*)ListWheel5, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)ListWheel5, &ListWheelScheme);
    laWidget_SetBackgroundType((laWidget*)ListWheel5, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ListWheel5, LA_WIDGET_BORDER_LINE);
    laListWheelWidget_SetFlickInitSpeed(ListWheel5, 5);
    laListWheelWidget_SetMaxMomentum(ListWheel5, 30000);
    laListWheelWidget_SetRotationUpdateRate(ListWheel5, 50);
    laListWheelWidget_AppendItem(ListWheel5);
    laListWheelWidget_SetItemText(ListWheel5, 0, laString_CreateFromID(string_num0));
    laListWheelWidget_AppendItem(ListWheel5);
    laListWheelWidget_SetItemText(ListWheel5, 1, laString_CreateFromID(string_num1));
    laListWheelWidget_AppendItem(ListWheel5);
    laListWheelWidget_SetItemText(ListWheel5, 2, laString_CreateFromID(string_num2));
    laListWheelWidget_AppendItem(ListWheel5);
    laListWheelWidget_SetItemText(ListWheel5, 3, laString_CreateFromID(string_num3));
    laListWheelWidget_AppendItem(ListWheel5);
    laListWheelWidget_SetItemText(ListWheel5, 4, laString_CreateFromID(string_num4));
    laListWheelWidget_AppendItem(ListWheel5);
    laListWheelWidget_SetItemText(ListWheel5, 5, laString_CreateFromID(string_num5));
    laListWheelWidget_AppendItem(ListWheel5);
    laListWheelWidget_SetItemText(ListWheel5, 6, laString_CreateFromID(string_num6));
    laListWheelWidget_AppendItem(ListWheel5);
    laListWheelWidget_SetItemText(ListWheel5, 7, laString_CreateFromID(string_num7));
    laListWheelWidget_AppendItem(ListWheel5);
    laListWheelWidget_SetItemText(ListWheel5, 8, laString_CreateFromID(string_num8));
    laListWheelWidget_AppendItem(ListWheel5);
    laListWheelWidget_SetItemText(ListWheel5, 9, laString_CreateFromID(string_num9));
    laWidget_AddChild((laWidget*)RectangleWidget2, (laWidget*)ListWheel5);

    ListWheel1 = laListWheelWidget_New();
    laWidget_SetPosition((laWidget*)ListWheel1, 189, 4);
    laWidget_SetSize((laWidget*)ListWheel1, 80, 133);
    laWidget_SetOptimizationFlags((laWidget*)ListWheel1, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)ListWheel1, &ListWheelScheme);
    laWidget_SetBackgroundType((laWidget*)ListWheel1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ListWheel1, LA_WIDGET_BORDER_LINE);
    laListWheelWidget_SetFlickInitSpeed(ListWheel1, 5);
    laListWheelWidget_SetMaxMomentum(ListWheel1, 500);
    laListWheelWidget_AppendItem(ListWheel1);
    laListWheelWidget_SetItemText(ListWheel1, 0, laString_CreateFromID(string_AM));
    laListWheelWidget_AppendItem(ListWheel1);
    laListWheelWidget_SetItemText(ListWheel1, 1, laString_CreateFromID(string_PM));
    laListWheelWidget_AppendItem(ListWheel1);
    laListWheelWidget_AppendItem(ListWheel1);
    laListWheelWidget_AppendItem(ListWheel1);
    laListWheelWidget_AppendItem(ListWheel1);
    laListWheelWidget_SetSelectedItemChangedEventCallback(ListWheel1, &ListWheel1_SelectedItemChangedEvent);
    laWidget_AddChild((laWidget*)RectangleWidget2, (laWidget*)ListWheel1);

    LabelWidget4 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget4, 98, 35);
    laWidget_SetSize((laWidget*)LabelWidget4, 100, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget4, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget4, laString_CreateFromID(string_SetTime));
    laLabelWidget_SetHAlignment(LabelWidget4, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget4);

    LabelWidget5 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget5, 10, 5);
    laWidget_SetSize((laWidget*)LabelWidget5, 305, 25);
    laWidget_SetScheme((laWidget*)LabelWidget5, &BlackBackground);
    laWidget_SetBackgroundType((laWidget*)LabelWidget5, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget5, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget5, laString_CreateFromID(string_ListWheelDemo));
    laLabelWidget_SetHAlignment(LabelWidget5, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget5);

    ButtonWidget30 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget30, 370, 225);
    laWidget_SetSize((laWidget*)ButtonWidget30, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget30, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget30, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget30, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget30, &GFX_NextScreen_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidget30, &GFX_NextScreen_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget30, &ButtonWidget30_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget30);

}

static void ScreenCreate_SecondScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 1);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_NONE);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    GradientWidget2 = laGradientWidget_New();
    laWidget_SetSize((laWidget*)GradientWidget2, 480, 272);
    laWidget_SetScheme((laWidget*)GradientWidget2, &BackgroundGradientScheme);
    laWidget_SetBackgroundType((laWidget*)GradientWidget2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GradientWidget2, LA_WIDGET_BORDER_NONE);
    laGradientWidget_SetDirection((laGradientWidget*)GradientWidget2, LA_GRADIENT_DIRECTION_DOWN);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)GradientWidget2);

    TouchTestWidget1 = laTouchTestWidget_New();
    laWidget_SetPosition((laWidget*)TouchTestWidget1, 130, 42);
    laWidget_SetSize((laWidget*)TouchTestWidget1, 297, 169);
    laWidget_SetOptimizationFlags((laWidget*)TouchTestWidget1, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)TouchTestWidget1, &TouchTestScheme);
    laWidget_SetBackgroundType((laWidget*)TouchTestWidget1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)TouchTestWidget1, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)TouchTestWidget1);

    LabelWidget6 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget6, 125, 215);
    laWidget_SetSize((laWidget*)LabelWidget6, 228, 25);
    laWidget_SetOptimizationFlags((laWidget*)LabelWidget6, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)LabelWidget6, &BlackBackground);
    laWidget_SetBackgroundType((laWidget*)LabelWidget6, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget6, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget6, laString_CreateFromID(string_TouchMe));
    laLabelWidget_SetHAlignment(LabelWidget6, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget6);

    ImageWidget5 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget5, 45, 151);
    laWidget_SetSize((laWidget*)ImageWidget5, 81, 100);
    laWidget_SetBackgroundType((laWidget*)ImageWidget5, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget5, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget5, &GFX_Touch_80);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget5);

    ButtonWidget2 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget2, -9, 225);
    laWidget_SetSize((laWidget*)ButtonWidget2, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget2, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget2, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget2, &GFX_Help_60);
    laButtonWidget_SetReleasedImage(ButtonWidget2, &GFX_Help_60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget2, &ButtonWidget2_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget2);

    ButtonWidget3 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget3, 430, 225);
    laWidget_SetSize((laWidget*)ButtonWidget3, 60, 60);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget3, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget3, &GFX_Home_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidget3, &GFX_Home_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget3, &ButtonWidget3_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget3);

    LabelWidget7 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget7, 10, 5);
    laWidget_SetSize((laWidget*)LabelWidget7, 293, 25);
    laWidget_SetScheme((laWidget*)LabelWidget7, &BlackBackground);
    laWidget_SetBackgroundType((laWidget*)LabelWidget7, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget7, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget7, laString_CreateFromID(string_TouchTestWidgetDemo));
    laLabelWidget_SetHAlignment(LabelWidget7, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget7);

    ButtonWidget31 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget31, 370, 225);
    laWidget_SetSize((laWidget*)ButtonWidget31, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget31, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget31, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget31, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget31, &GFX_NextScreen_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidget31, &GFX_NextScreen_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget31, &ButtonWidget31_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget31);

}

static void ScreenCreate_ThirdScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_NONE);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    GradientWidget4 = laGradientWidget_New();
    laWidget_SetSize((laWidget*)GradientWidget4, 480, 272);
    laWidget_SetScheme((laWidget*)GradientWidget4, &BackgroundGradientScheme);
    laWidget_SetBackgroundType((laWidget*)GradientWidget4, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GradientWidget4, LA_WIDGET_BORDER_NONE);
    laGradientWidget_SetDirection((laGradientWidget*)GradientWidget4, LA_GRADIENT_DIRECTION_DOWN);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)GradientWidget4);

    KeyPadWidget1 = laKeyPadWidget_New(4, 10);
    laWidget_SetPosition((laWidget*)KeyPadWidget1, 15, 81);
    laWidget_SetSize((laWidget*)KeyPadWidget1, 450, 130);
    laWidget_SetOptimizationFlags((laWidget*)KeyPadWidget1, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)KeyPadWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)KeyPadWidget1, LA_WIDGET_BORDER_BEVEL);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 0, 0, laString_CreateFromID(string_Keypad_1));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 0, 0, laString_CreateFromID(string_Keypad_1));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 0, 0, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 0, 0, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 0, 1, laString_CreateFromID(string_Keypad_2));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 0, 1, laString_CreateFromID(string_Keypad_2));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 0, 1, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 0, 1, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 0, 2, laString_CreateFromID(string_Keypad_3));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 0, 2, laString_CreateFromID(string_Keypad_3));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 0, 2, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 0, 2, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 0, 3, laString_CreateFromID(string_Keypad_4));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 0, 3, laString_CreateFromID(string_Keypad_4));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 0, 3, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 0, 3, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 0, 4, laString_CreateFromID(string_Keypad_5));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 0, 4, laString_CreateFromID(string_Keypad_5));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 0, 4, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 0, 4, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 0, 5, laString_CreateFromID(string_Keypad_6));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 0, 5, laString_CreateFromID(string_Keypad_6));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 0, 5, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 0, 5, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 0, 6, laString_CreateFromID(string_Keypad_7));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 0, 6, laString_CreateFromID(string_Keypad_7));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 0, 6, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 0, 6, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 0, 7, laString_CreateFromID(string_Keypad_8));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 0, 7, laString_CreateFromID(string_Keypad_8));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 0, 7, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 0, 7, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 0, 8, laString_CreateFromID(string_Keypad_9));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 0, 8, laString_CreateFromID(string_Keypad_9));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 0, 8, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 0, 8, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 0, 9, laString_CreateFromID(string_Keypad_0));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 0, 9, laString_CreateFromID(string_Keypad_0));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 0, 9, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 0, 9, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 1, 0, laString_CreateFromID(string_Keypad_q));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 1, 0, laString_CreateFromID(string_Keypad_q));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 1, 0, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 1, 0, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 1, 1, laString_CreateFromID(string_Keypad_w));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 1, 1, laString_CreateFromID(string_Keypad_w));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 1, 1, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 1, 1, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 1, 2, laString_CreateFromID(string_Keypad_e));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 1, 2, laString_CreateFromID(string_Keypad_e));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 1, 2, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 1, 2, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 1, 3, laString_CreateFromID(string_Keypad_r));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 1, 3, laString_CreateFromID(string_Keypad_r));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 1, 3, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 1, 3, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 1, 4, laString_CreateFromID(string_Keypad_t));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 1, 4, laString_CreateFromID(string_Keypad_t));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 1, 4, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 1, 4, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 1, 5, laString_CreateFromID(string_Keypad_y));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 1, 5, laString_CreateFromID(string_Keypad_y));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 1, 5, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 1, 5, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 1, 6, laString_CreateFromID(string_Keypad_u));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 1, 6, laString_CreateFromID(string_Keypad_u));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 1, 6, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 1, 6, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 1, 7, laString_CreateFromID(string_Keypad_i));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 1, 7, laString_CreateFromID(string_Keypad_i));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 1, 7, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 1, 7, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 1, 8, laString_CreateFromID(string_Keypad_o));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 1, 8, laString_CreateFromID(string_Keypad_o));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 1, 8, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 1, 8, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 1, 9, laString_CreateFromID(string_Keypad_p));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 1, 9, laString_CreateFromID(string_Keypad_p));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 1, 9, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 1, 9, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 2, 0, laString_CreateFromID(string_Keypad_a));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 2, 0, laString_CreateFromID(string_Keypad_a));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 2, 0, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 2, 0, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 2, 1, laString_CreateFromID(string_Keypad_s));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 2, 1, laString_CreateFromID(string_Keypad_s));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 2, 1, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 2, 1, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 2, 2, laString_CreateFromID(string_Keypad_d));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 2, 2, laString_CreateFromID(string_Keypad_d));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 2, 2, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 2, 2, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 2, 3, laString_CreateFromID(string_Keypad_f));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 2, 3, laString_CreateFromID(string_Keypad_f));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 2, 3, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 2, 3, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 2, 4, laString_CreateFromID(string_Keypad_g));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 2, 4, laString_CreateFromID(string_Keypad_g));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 2, 4, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 2, 4, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 2, 5, laString_CreateFromID(string_Keypad_h));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 2, 5, laString_CreateFromID(string_Keypad_h));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 2, 5, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 2, 5, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 2, 6, laString_CreateFromID(string_Keypad_j));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 2, 6, laString_CreateFromID(string_Keypad_j));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 2, 6, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 2, 6, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 2, 7, laString_CreateFromID(string_Keypad_k));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 2, 7, laString_CreateFromID(string_Keypad_k));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 2, 7, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 2, 7, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 2, 8, laString_CreateFromID(string_Keypad_l));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 2, 8, laString_CreateFromID(string_Keypad_l));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 2, 8, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 2, 8, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 2, 9, laString_CreateFromID(string_Backspace));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 2, 9, LA_KEYPAD_CELL_ACTION_BACKSPACE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 2, 9, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 3, 0, laString_CreateFromID(string_Keypad_z));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 3, 0, laString_CreateFromID(string_Keypad_z));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 3, 0, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 3, 0, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 3, 1, laString_CreateFromID(string_Keypad_x));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 3, 1, laString_CreateFromID(string_Keypad_x));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 3, 1, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 3, 1, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 3, 2, laString_CreateFromID(string_Keypad_c));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 3, 2, laString_CreateFromID(string_Keypad_c));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 3, 2, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 3, 2, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 3, 3, laString_CreateFromID(string_Keypad_v));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 3, 3, laString_CreateFromID(string_Keypad_v));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 3, 3, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 3, 3, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 3, 4, laString_CreateFromID(string_Keypad_b));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 3, 4, laString_CreateFromID(string_Keypad_b));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 3, 4, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 3, 4, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 3, 5, laString_CreateFromID(string_Keypad_n));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 3, 5, laString_CreateFromID(string_Keypad_n));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 3, 5, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 3, 5, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 3, 6, laString_CreateFromID(string_Keypad_m));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 3, 6, laString_CreateFromID(string_Keypad_m));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 3, 6, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 3, 6, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 3, 7, laString_CreateFromID(string_spacebar));
    laKeyPadWidget_SetKeyValue(KeyPadWidget1, 3, 7, laString_CreateFromID(string_spaceChar));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 3, 7, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 3, 7, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyEnabled(KeyPadWidget1, 3, 8, LA_FALSE);
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 3, 8, LA_KEYPAD_CELL_ACTION_APPEND);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 3, 8, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyText(KeyPadWidget1, 3, 9, laString_CreateFromID(string_clear));
    laKeyPadWidget_SetKeyAction(KeyPadWidget1, 3, 9, LA_KEYPAD_CELL_ACTION_CLEAR);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget1, 3, 9, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyClickEventCallback(KeyPadWidget1, &KeyPadWidget1_KeyClickEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)KeyPadWidget1);

    TextFieldWidget1 = laTextFieldWidget_New();
    laWidget_SetPosition((laWidget*)TextFieldWidget1, 15, 38);
    laWidget_SetSize((laWidget*)TextFieldWidget1, 450, 40);
    laWidget_SetOptimizationFlags((laWidget*)TextFieldWidget1, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)TextFieldWidget1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)TextFieldWidget1, LA_WIDGET_BORDER_BEVEL);
    laTextFieldWidget_SetText(TextFieldWidget1, laString_CreateFromID(string_textField_Instruction));
    laTextFieldWidget_SetCursorEnabled(TextFieldWidget1, LA_TRUE);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)TextFieldWidget1);

    ButtonWidget5 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget5, -9, 225);
    laWidget_SetSize((laWidget*)ButtonWidget5, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget5, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget5, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget5, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget5, &GFX_Help_60);
    laButtonWidget_SetReleasedImage(ButtonWidget5, &GFX_Help_60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget5, &ButtonWidget5_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget5);

    ButtonWidget6 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget6, 430, 225);
    laWidget_SetSize((laWidget*)ButtonWidget6, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget6, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget6, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget6, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget6, &GFX_Home_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidget6, &GFX_Home_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget6, &ButtonWidget6_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget6);

    LabelWidget8 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget8, 10, 5);
    laWidget_SetSize((laWidget*)LabelWidget8, 281, 25);
    laWidget_SetScheme((laWidget*)LabelWidget8, &BlackBackground);
    laWidget_SetBackgroundType((laWidget*)LabelWidget8, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget8, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget8, laString_CreateFromID(string_KeypadWidgetDemo));
    laLabelWidget_SetHAlignment(LabelWidget8, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget8);

    ButtonWidget32 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget32, 370, 225);
    laWidget_SetSize((laWidget*)ButtonWidget32, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget32, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget32, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget32, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget32, &GFX_NextScreen_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidget32, &GFX_NextScreen_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget32, &ButtonWidget32_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget32);

}

static void ScreenCreate_FourthScreen(laScreen* screen)
{
    laLayer* layer0;

    laScreen_SetShowEventCallback(screen, &FourthScreen_ShowEvent);
    laScreen_SetHideEventCallback(screen, &FourthScreen_HideEvent);

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_NONE);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    GradientWidget5 = laGradientWidget_New();
    laWidget_SetSize((laWidget*)GradientWidget5, 480, 272);
    laWidget_SetScheme((laWidget*)GradientWidget5, &BackgroundGradientScheme);
    laWidget_SetBackgroundType((laWidget*)GradientWidget5, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GradientWidget5, LA_WIDGET_BORDER_NONE);
    laGradientWidget_SetDirection((laGradientWidget*)GradientWidget5, LA_GRADIENT_DIRECTION_DOWN);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)GradientWidget5);

    PanelWidget1 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget1, 370, 29);
    laWidget_SetSize((laWidget*)PanelWidget1, 119, 187);
    laWidget_SetBackgroundType((laWidget*)PanelWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PanelWidget1, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget1);

    SliderWidget1 = laSliderWidget_New();
    laWidget_SetPosition((laWidget*)SliderWidget1, 1, 42);
    laWidget_SetSize((laWidget*)SliderWidget1, 48, 106);
    laWidget_SetOptimizationFlags((laWidget*)SliderWidget1, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)SliderWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SliderWidget1, LA_WIDGET_BORDER_BEVEL);
    laSliderWidget_SetMaximumValue(SliderWidget1, 255);
    laSliderWidget_SetSliderValue(SliderWidget1, 127);
    laSliderWidget_SetGripSize(SliderWidget1, 15);
    laSliderWidget_SetValueChangedEventCallback(SliderWidget1, &SliderWidget1_ValueChangedEvent);

    laWidget_AddChild((laWidget*)PanelWidget1, (laWidget*)SliderWidget1);

    SliderValueLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)SliderValueLabelWidget, 58, 78);
    laWidget_SetSize((laWidget*)SliderValueLabelWidget, 50, 32);
    laWidget_SetBackgroundType((laWidget*)SliderValueLabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SliderValueLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetHAlignment(SliderValueLabelWidget, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget1, (laWidget*)SliderValueLabelWidget);

    PanelWidget2 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget2, 61, 36);
    laWidget_SetSize((laWidget*)PanelWidget2, 299, 180);
    laWidget_SetBackgroundType((laWidget*)PanelWidget2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget2, LA_WIDGET_BORDER_LINE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget2);

    ImageWidget1 = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget1, 305, 180);
    laWidget_SetBackgroundType((laWidget*)ImageWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget1, LA_WIDGET_BORDER_LINE);
    laWidget_SetAlphaEnable((laWidget*)ImageWidget1, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)ImageWidget1, 127);
    laImageWidget_SetImage(ImageWidget1, &NewHarmonyLogo);
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)ImageWidget1);

    ImageWidget2 = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget2, 304, 180);
    laWidget_SetBackgroundType((laWidget*)ImageWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget2, LA_WIDGET_BORDER_LINE);
    laWidget_SetAlphaEnable((laWidget*)ImageWidget2, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)ImageWidget2, 127);
    laImageWidget_SetImage(ImageWidget2, &MicrochipLogo);
    laWidget_AddChild((laWidget*)PanelWidget2, (laWidget*)ImageWidget2);

    ButtonWidget4 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget4, -9, 225);
    laWidget_SetSize((laWidget*)ButtonWidget4, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget4, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget4, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget4, &GFX_Help_60);
    laButtonWidget_SetReleasedImage(ButtonWidget4, &GFX_Help_60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget4, &ButtonWidget4_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget4);

    ButtonWidget8 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget8, 430, 225);
    laWidget_SetSize((laWidget*)ButtonWidget8, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget8, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget8, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget8, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget8, &GFX_Home_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidget8, &GFX_Home_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget8, &ButtonWidget8_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget8);

    LabelWidget9 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget9, 10, 5);
    laWidget_SetSize((laWidget*)LabelWidget9, 297, 25);
    laWidget_SetScheme((laWidget*)LabelWidget9, &BlackBackground);
    laWidget_SetBackgroundType((laWidget*)LabelWidget9, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget9, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget9, laString_CreateFromID(string_AlphaBlendingDemo));
    laLabelWidget_SetHAlignment(LabelWidget9, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget9);

    ButtonWidget33 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget33, 370, 225);
    laWidget_SetSize((laWidget*)ButtonWidget33, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget33, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget33, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget33, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget33, &GFX_NextScreen_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidget33, &GFX_NextScreen_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget33, &ButtonWidget33_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget33);

    SliderUpButtonWidget = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)SliderUpButtonWidget, 370, 31);
    laWidget_SetSize((laWidget*)SliderUpButtonWidget, 50, 36);
    laWidget_SetOptimizationFlags((laWidget*)SliderUpButtonWidget, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)SliderUpButtonWidget, &BlackBackground);
    laWidget_SetBackgroundType((laWidget*)SliderUpButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SliderUpButtonWidget, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(SliderUpButtonWidget, laString_CreateFromID(string_UpRight));
    laButtonWidget_SetReleasedEventCallback(SliderUpButtonWidget, &SliderUpButtonWidget_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)SliderUpButtonWidget);

    SliderDownButtonWidget = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)SliderDownButtonWidget, 370, 180);
    laWidget_SetSize((laWidget*)SliderDownButtonWidget, 50, 36);
    laWidget_SetOptimizationFlags((laWidget*)SliderDownButtonWidget, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)SliderDownButtonWidget, &BlackBackground);
    laWidget_SetBackgroundType((laWidget*)SliderDownButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SliderDownButtonWidget, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(SliderDownButtonWidget, laString_CreateFromID(string_DownLeft));
    laButtonWidget_SetReleasedEventCallback(SliderDownButtonWidget, &SliderDownButtonWidget_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)SliderDownButtonWidget);

}

static void ScreenCreate_FifthScreen(laScreen* screen)
{
    laLayer* layer0;

    laScreen_SetHideEventCallback(screen, &FifthScreen_HideEvent);

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_NONE);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    GradientWidget6 = laGradientWidget_New();
    laWidget_SetSize((laWidget*)GradientWidget6, 480, 272);
    laWidget_SetScheme((laWidget*)GradientWidget6, &BackgroundGradientScheme);
    laWidget_SetBackgroundType((laWidget*)GradientWidget6, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GradientWidget6, LA_WIDGET_BORDER_NONE);
    laGradientWidget_SetDirection((laGradientWidget*)GradientWidget6, LA_GRADIENT_DIRECTION_DOWN);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)GradientWidget6);

    ImageSequenceWidget1 = laImageSequenceWidget_New();
    laWidget_SetPosition((laWidget*)ImageSequenceWidget1, 107, 41);
    laWidget_SetSize((laWidget*)ImageSequenceWidget1, 279, 161);
    laWidget_SetBackgroundType((laWidget*)ImageSequenceWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageSequenceWidget1, LA_WIDGET_BORDER_NONE);
    laImageSequenceWidget_SetImageCount(ImageSequenceWidget1, 5);
    laImageSequenceWidget_SetImage(ImageSequenceWidget1, 0, &LucyInTheSky);
    laImageSequenceWidget_SetImage(ImageSequenceWidget1, 1, &USA);
    laImageSequenceWidget_SetImage(ImageSequenceWidget1, 2, &ice_color);
    laImageSequenceWidget_SetImage(ImageSequenceWidget1, 3, &MicrochipLogo);
    laImageSequenceWidget_SetImage(ImageSequenceWidget1, 4, &NewHarmonyLogo);
    laImageSequenceWidget_SetRepeat(ImageSequenceWidget1, LA_TRUE);
    laImageSequenceWidget_Play(ImageSequenceWidget1);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageSequenceWidget1);

    ButtonWidget9 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget9, -9, 225);
    laWidget_SetSize((laWidget*)ButtonWidget9, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget9, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget9, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget9, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget9, &GFX_Help_60);
    laButtonWidget_SetReleasedImage(ButtonWidget9, &GFX_Help_60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget9, &ButtonWidget9_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget9);

    ButtonWidget11 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget11, 430, 225);
    laWidget_SetSize((laWidget*)ButtonWidget11, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget11, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget11, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget11, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget11, &GFX_Home_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidget11, &GFX_Home_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget11, &ButtonWidget11_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget11);

    LabelWidget10 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget10, 10, 6);
    laWidget_SetSize((laWidget*)LabelWidget10, 251, 25);
    laWidget_SetScheme((laWidget*)LabelWidget10, &BlackBackground);
    laWidget_SetBackgroundType((laWidget*)LabelWidget10, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget10, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget10, laString_CreateFromID(string_SlideShowDemo));
    laLabelWidget_SetHAlignment(LabelWidget10, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget10);

    ButtonWidget10 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget10, 0, 90);
    laWidget_SetSize((laWidget*)ButtonWidget10, 50, 74);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget10, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget10, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget10, &GFX_ArrowLeft_20x60);
    laButtonWidget_SetReleasedImage(ButtonWidget10, &GFX_ArrowLeft_20x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget10, &ButtonWidget10_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget10);

    ButtonWidget20 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget20, 430, 90);
    laWidget_SetSize((laWidget*)ButtonWidget20, 49, 65);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget20, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget20, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget20, &GFX_ArrowRight_20x60);
    laButtonWidget_SetReleasedImage(ButtonWidget20, &GFX_ArrowRight_20x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget20, &ButtonWidget20_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget20);

    ButtonWidget21 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget21, 261, 220);
    laWidget_SetSize((laWidget*)ButtonWidget21, 99, 38);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget21, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget21, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonWidget21, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetToggleable(ButtonWidget21, LA_TRUE);
    laButtonWidget_SetText(ButtonWidget21, laString_CreateFromID(string_msecs500));
    laButtonWidget_SetPressedImage(ButtonWidget21, &GFX_Stop_30x30);
    laButtonWidget_SetReleasedImage(ButtonWidget21, &GFX_FF_30x30);
    laButtonWidget_SetPressedEventCallback(ButtonWidget21, &ButtonWidget21_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget21, &ButtonWidget21_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget21);

    ButtonWidget22 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget22, 138, 220);
    laWidget_SetSize((laWidget*)ButtonWidget22, 92, 37);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget22, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget22, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonWidget22, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetToggleable(ButtonWidget22, LA_TRUE);
    laButtonWidget_SetText(ButtonWidget22, laString_CreateFromID(string_secs2));
    laButtonWidget_SetPressedImage(ButtonWidget22, &GFX_Stop_30x30);
    laButtonWidget_SetReleasedImage(ButtonWidget22, &GFX_Play_30x30);
    laButtonWidget_SetPressedEventCallback(ButtonWidget22, &ButtonWidget22_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget22, &ButtonWidget22_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget22);

    SSStatusImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)SSStatusImageWidget, 349, 10);
    laWidget_SetSize((laWidget*)SSStatusImageWidget, 20, 20);
    laWidget_SetOptimizationFlags((laWidget*)SSStatusImageWidget, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)SSStatusImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SSStatusImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(SSStatusImageWidget, &GFX_Pause_Pink_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)SSStatusImageWidget);

}

static void ScreenCreate_SettingsScreen(laScreen* screen)
{
    laLayer* layer0;
    laRadioButtonGroup* radioButtonGroup_0;

    laScreen_SetShowEventCallback(screen, &SettingsScreen_ShowEvent);

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &defaultScheme);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    GradientWidget7 = laGradientWidget_New();
    laWidget_SetSize((laWidget*)GradientWidget7, 480, 272);
    laWidget_SetScheme((laWidget*)GradientWidget7, &BackgroundGradientScheme);
    laWidget_SetBackgroundType((laWidget*)GradientWidget7, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GradientWidget7, LA_WIDGET_BORDER_NONE);
    laGradientWidget_SetDirection((laGradientWidget*)GradientWidget7, LA_GRADIENT_DIRECTION_DOWN);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)GradientWidget7);

    ButtonWidget12 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget12, 430, 220);
    laWidget_SetSize((laWidget*)ButtonWidget12, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget12, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget12, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget12, LA_WIDGET_BORDER_NONE);
    laWidget_SetAlphaEnable((laWidget*)ButtonWidget12, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)ButtonWidget12, 255);
    laButtonWidget_SetPressedImage(ButtonWidget12, &GFX_Home_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidget12, &GFX_Home_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget12, &ButtonWidget12_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget12);

    PanelWidget3 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget3, 39, 35);
    laWidget_SetSize((laWidget*)PanelWidget3, 407, 38);
    laWidget_SetScheme((laWidget*)PanelWidget3, &defaultScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget3, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget3, LA_WIDGET_BORDER_LINE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget3);

    LabelWidget11 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget11, 15, 5);
    laWidget_SetSize((laWidget*)LabelWidget11, 75, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget11, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget11, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget11, laString_CreateFromID(string_SetLanguage));
    laLabelWidget_SetHAlignment(LabelWidget11, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)LabelWidget11);

    RadioButtonChinese = laRadioButtonWidget_New();
    laWidget_SetPosition((laWidget*)RadioButtonChinese, 262, 6);
    laWidget_SetSize((laWidget*)RadioButtonChinese, 100, 25);
    laWidget_SetEnabled((laWidget*)RadioButtonChinese, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)RadioButtonChinese, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)RadioButtonChinese, LA_WIDGET_BORDER_NONE);
    laRadioButtonWidget_SetText(RadioButtonChinese, laString_CreateFromID(string_RadioButton_Chinese));
    laRadioButtonWidget_SetHAlignment(RadioButtonChinese, LA_HALIGN_LEFT);
    laRadioButtonGroup_Create(&radioButtonGroup_0);
    laRadioButtonGroup_AddButton(radioButtonGroup_0, RadioButtonChinese);
    laRadioButtonWidget_SetSelectedEventCallback(RadioButtonChinese, &RadioButtonChinese_CheckedEvent);

    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)RadioButtonChinese);

    RadioButtonEnglish = laRadioButtonWidget_New();
    laWidget_SetPosition((laWidget*)RadioButtonEnglish, 133, 6);
    laWidget_SetSize((laWidget*)RadioButtonEnglish, 100, 25);
    laWidget_SetEnabled((laWidget*)RadioButtonEnglish, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)RadioButtonEnglish, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)RadioButtonEnglish, LA_WIDGET_BORDER_NONE);
    laRadioButtonWidget_SetText(RadioButtonEnglish, laString_CreateFromID(string_RadioButton_English));
    laRadioButtonWidget_SetHAlignment(RadioButtonEnglish, LA_HALIGN_LEFT);
    laRadioButtonGroup_AddButton(radioButtonGroup_0, RadioButtonEnglish);
    laRadioButtonWidget_SetSelected(RadioButtonEnglish);
    laRadioButtonWidget_SetSelectedEventCallback(RadioButtonEnglish, &RadioButtonEnglish_CheckedEvent);

    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)RadioButtonEnglish);

    ButtonWidgetChinese = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidgetChinese, 254, 0);
    laWidget_SetSize((laWidget*)ButtonWidgetChinese, 123, 39);
    laWidget_SetBackgroundType((laWidget*)ButtonWidgetChinese, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidgetChinese, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedEventCallback(ButtonWidgetChinese, &ButtonWidgetChinese_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)ButtonWidgetChinese);

    ButtonWidgetEnglish = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidgetEnglish, 128, 0);
    laWidget_SetSize((laWidget*)ButtonWidgetEnglish, 111, 38);
    laWidget_SetBackgroundType((laWidget*)ButtonWidgetEnglish, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidgetEnglish, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedEventCallback(ButtonWidgetEnglish, &ButtonWidgetEnglish_PressedEvent);

    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)ButtonWidgetEnglish);

}

static void ScreenCreate_MainMenuHelp(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    ButtonWidget23 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget23, 440, 0);
    laWidget_SetSize((laWidget*)ButtonWidget23, 40, 36);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget23, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget23, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonWidget23, &GFX_CloseX_40x40);
    laButtonWidget_SetReleasedImage(ButtonWidget23, &GFX_CloseX_40x40);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget23, &ButtonWidget23_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget23);

    ImageWidget6 = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget6, 40, 40);
    laWidget_SetBackgroundType((laWidget*)ImageWidget6, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget6, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget6, &GFX_Help_40x40);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget6);

    LabelWidget12 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget12, 48, 6);
    laWidget_SetSize((laWidget*)LabelWidget12, 113, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget12, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget12, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget12, laString_CreateFromID(string_Help));
    laLabelWidget_SetHAlignment(LabelWidget12, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget12);

    LabelWidget13 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget13, 29, 47);
    laWidget_SetSize((laWidget*)LabelWidget13, 316, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget13, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget13, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget13, laString_CreateFromID(string_MainIconHelp));
    laLabelWidget_SetHAlignment(LabelWidget13, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget13);

    LabelWidget14 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget14, 81, 71);
    laWidget_SetSize((laWidget*)LabelWidget14, 229, 24);
    laWidget_SetBackgroundType((laWidget*)LabelWidget14, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget14, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget14, laString_CreateFromID(string_ListWheelWidgetDemoSmall));
    laLabelWidget_SetHAlignment(LabelWidget14, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget14);

    LabelWidget15 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget15, 81, 94);
    laWidget_SetSize((laWidget*)LabelWidget15, 286, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget15, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget15, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget15, laString_CreateFromID(string_TouchTestWidgetDemoSmall));
    laLabelWidget_SetHAlignment(LabelWidget15, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget15);

    LabelWidget16 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget16, 81, 118);
    laWidget_SetSize((laWidget*)LabelWidget16, 229, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget16, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget16, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget16, laString_CreateFromID(string_KeypadWidgetDemoSmall));
    laLabelWidget_SetHAlignment(LabelWidget16, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget16);

    LabelWidget17 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget17, 81, 142);
    laWidget_SetSize((laWidget*)LabelWidget17, 264, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget17, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget17, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget17, laString_CreateFromID(string_AlphaBlendingDemoSmall));
    laLabelWidget_SetHAlignment(LabelWidget17, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget17);

    LabelWidget18 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget18, 81, 166);
    laWidget_SetSize((laWidget*)LabelWidget18, 229, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget18, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget18, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget18, laString_CreateFromID(string_SlideShowDemoSmall));
    laLabelWidget_SetHAlignment(LabelWidget18, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget18);

    LabelWidget19 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget19, 56, 190);
    laWidget_SetSize((laWidget*)LabelWidget19, 289, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget19, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget19, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget19, laString_CreateFromID(string_MainHelpHelp));
    laLabelWidget_SetHAlignment(LabelWidget19, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget19);

    LabelWidget20 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget20, 56, 214);
    laWidget_SetSize((laWidget*)LabelWidget20, 348, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget20, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget20, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget20, laString_CreateFromID(string_MainSettingsHelp));
    laLabelWidget_SetHAlignment(LabelWidget20, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget20);

    ImageWidget7 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget7, 55, 144);
    laWidget_SetSize((laWidget*)ImageWidget7, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget7, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget7, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget7, &GFX_alpha_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget7);

    ImageWidget8 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget8, 31, 190);
    laWidget_SetSize((laWidget*)ImageWidget8, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget8, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget8, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget8, &GFX_Help_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget8);

    ImageWidget9 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget9, 30, 215);
    laWidget_SetSize((laWidget*)ImageWidget9, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget9, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget9, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget9, &GFX_Settings_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget9);

    ImageWidget10 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget10, 55, 71);
    laWidget_SetSize((laWidget*)ImageWidget10, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget10, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget10, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget10, &GFX_ListWheel_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget10);

    ImageWidget11 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget11, 55, 94);
    laWidget_SetSize((laWidget*)ImageWidget11, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget11, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget11, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget11, &GFX_Touch_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget11);

    ImageWidget12 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget12, 55, 167);
    laWidget_SetSize((laWidget*)ImageWidget12, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget12, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget12, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget12, &GFX_Slideshow_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget12);

    ImageWidget13 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget13, 55, 118);
    laWidget_SetSize((laWidget*)ImageWidget13, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget13, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget13, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget13, &GFX_Keypad_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget13);

}

static void ScreenCreate_ListWheelHelpScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget14 = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget14, 40, 40);
    laWidget_SetBackgroundType((laWidget*)ImageWidget14, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget14, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget14, &GFX_Help_40x40);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget14);

    LabelWidget21 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget21, 48, 6);
    laWidget_SetSize((laWidget*)LabelWidget21, 332, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget21, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget21, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget21, laString_CreateFromID(string_Help));
    laLabelWidget_SetHAlignment(LabelWidget21, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget21);

    ButtonWidget24 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget24, 440, 0);
    laWidget_SetSize((laWidget*)ButtonWidget24, 40, 40);
    laWidget_SetScheme((laWidget*)ButtonWidget24, &defaultScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget24, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget24, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonWidget24, &GFX_CloseX_40x40);
    laButtonWidget_SetReleasedImage(ButtonWidget24, &GFX_CloseX_40x40);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget24, &ButtonWidget24_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget24);

    LabelWidget22 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget22, 29, 47);
    laWidget_SetSize((laWidget*)LabelWidget22, 411, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget22, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget22, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget22, laString_CreateFromID(string_ListWheelHelp));
    laLabelWidget_SetHAlignment(LabelWidget22, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget22);

    LabelWidget24 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget24, 62, 71);
    laWidget_SetSize((laWidget*)LabelWidget24, 260, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget24, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget24, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget24, laString_CreateFromID(string_HomeHelpText));
    laLabelWidget_SetHAlignment(LabelWidget24, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget24);

    ImageWidget16 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget16, 36, 73);
    laWidget_SetSize((laWidget*)ImageWidget16, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget16, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget16, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget16, &GFX_Home_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget16);

}

static void ScreenCreate_TouchTestHelpScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget17 = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget17, 40, 40);
    laWidget_SetBackgroundType((laWidget*)ImageWidget17, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget17, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget17, &GFX_Help_40x40);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget17);

    ButtonWidget25 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget25, 440, 0);
    laWidget_SetSize((laWidget*)ButtonWidget25, 40, 40);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget25, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget25, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonWidget25, &GFX_CloseX_40x40);
    laButtonWidget_SetReleasedImage(ButtonWidget25, &GFX_CloseX_40x40);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget25, &ButtonWidget25_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget25);

    LabelWidget25 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget25, 48, 6);
    laWidget_SetSize((laWidget*)LabelWidget25, 100, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget25, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget25, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget25, laString_CreateFromID(string_Help));
    laLabelWidget_SetHAlignment(LabelWidget25, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget25);

    LabelWidget26 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget26, 29, 47);
    laWidget_SetSize((laWidget*)LabelWidget26, 387, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget26, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget26, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget26, laString_CreateFromID(string_TouchTestHelpInfo));
    laLabelWidget_SetHAlignment(LabelWidget26, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget26);

    LabelWidget28 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget28, 59, 71);
    laWidget_SetSize((laWidget*)LabelWidget28, 317, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget28, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget28, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget28, laString_CreateFromID(string_HomeHelpText));
    laLabelWidget_SetHAlignment(LabelWidget28, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget28);

    ImageWidget19 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget19, 32, 75);
    laWidget_SetSize((laWidget*)ImageWidget19, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget19, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget19, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget19, &GFX_Home_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget19);

}

static void ScreenCreate_KeypadHelpScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget20 = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget20, 40, 40);
    laWidget_SetBackgroundType((laWidget*)ImageWidget20, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget20, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget20, &GFX_Help_40x40);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget20);

    ButtonWidget26 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget26, 440, 0);
    laWidget_SetSize((laWidget*)ButtonWidget26, 40, 40);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget26, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget26, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonWidget26, &GFX_CloseX_40x40);
    laButtonWidget_SetReleasedImage(ButtonWidget26, &GFX_CloseX_40x40);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget26, &ButtonWidget26_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget26);

    LabelWidget29 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget29, 48, 6);
    laWidget_SetSize((laWidget*)LabelWidget29, 100, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget29, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget29, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget29, laString_CreateFromID(string_Help));
    laLabelWidget_SetHAlignment(LabelWidget29, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget29);

    LabelWidget30 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget30, 29, 47);
    laWidget_SetSize((laWidget*)LabelWidget30, 299, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget30, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget30, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget30, laString_CreateFromID(string_TouchTextField));
    laLabelWidget_SetHAlignment(LabelWidget30, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget30);

    LabelWidget32 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget32, 56, 71);
    laWidget_SetSize((laWidget*)LabelWidget32, 300, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget32, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget32, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget32, laString_CreateFromID(string_HomeHelpText));
    laLabelWidget_SetHAlignment(LabelWidget32, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget32);

    ImageWidget22 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget22, 32, 75);
    laWidget_SetSize((laWidget*)ImageWidget22, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget22, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget22, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget22, &GFX_Home_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget22);

}

static void ScreenCreate_AlphaBlendingHelpScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    ButtonWidget27 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget27, 440, 0);
    laWidget_SetSize((laWidget*)ButtonWidget27, 40, 40);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget27, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget27, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonWidget27, &GFX_CloseX_40x40);
    laButtonWidget_SetReleasedImage(ButtonWidget27, &GFX_CloseX_40x40);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget27, &ButtonWidget27_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget27);

    ImageWidget23 = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget23, 40, 40);
    laWidget_SetBackgroundType((laWidget*)ImageWidget23, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget23, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget23, &GFX_Help_40x40);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget23);

    LabelWidget33 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget33, 48, 6);
    laWidget_SetSize((laWidget*)LabelWidget33, 100, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget33, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget33, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget33, laString_CreateFromID(string_Help));
    laLabelWidget_SetHAlignment(LabelWidget33, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget33);

    LabelWidget34 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget34, 29, 47);
    laWidget_SetSize((laWidget*)LabelWidget34, 427, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget34, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget34, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget34, laString_CreateFromID(string_SliderDragHelpInfo));
    laLabelWidget_SetHAlignment(LabelWidget34, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget34);

    LabelWidget35 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget35, 29, 71);
    laWidget_SetSize((laWidget*)LabelWidget35, 411, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget35, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget35, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget35, laString_CreateFromID(string_PlusMinusAlphaHelpInfo));
    laLabelWidget_SetHAlignment(LabelWidget35, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget35);

    LabelWidget23 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget23, 70, 95);
    laWidget_SetSize((laWidget*)LabelWidget23, 369, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget23, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget23, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget23, laString_CreateFromID(string_HomeHelpText));
    laLabelWidget_SetHAlignment(LabelWidget23, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget23);

    ImageWidget15 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget15, 32, 100);
    laWidget_SetSize((laWidget*)ImageWidget15, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget15, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget15, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget15, &GFX_Home_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget15);

}

static void ScreenCreate_SlideshowHelpScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    ButtonWidget28 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget28, 440, 0);
    laWidget_SetSize((laWidget*)ButtonWidget28, 40, 40);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget28, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget28, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonWidget28, &GFX_CloseX_40x40);
    laButtonWidget_SetReleasedImage(ButtonWidget28, &GFX_CloseX_40x40);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget28, &ButtonWidget28_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget28);

    ImageWidget18 = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget18, 40, 40);
    laWidget_SetBackgroundType((laWidget*)ImageWidget18, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget18, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget18, &GFX_Help_40x40);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget18);

    LabelWidget27 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget27, 48, 6);
    laWidget_SetSize((laWidget*)LabelWidget27, 100, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget27, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget27, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget27, laString_CreateFromID(string_Help));
    laLabelWidget_SetHAlignment(LabelWidget27, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget27);

    LabelWidget31 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget31, 29, 47);
    laWidget_SetSize((laWidget*)LabelWidget31, 356, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget31, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget31, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget31, laString_CreateFromID(string_SlideShowNavHelpInfo));
    laLabelWidget_SetHAlignment(LabelWidget31, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget31);

    LabelWidget36 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget36, 63, 71);
    laWidget_SetSize((laWidget*)LabelWidget36, 355, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget36, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget36, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget36, laString_CreateFromID(string_TouchPlayHelpInfo));
    laLabelWidget_SetHAlignment(LabelWidget36, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget36);

    LabelWidget37 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget37, 63, 95);
    laWidget_SetSize((laWidget*)LabelWidget37, 373, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget37, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget37, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget37, laString_CreateFromID(string_TouchFFHelpInfo));
    laLabelWidget_SetHAlignment(LabelWidget37, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget37);

    LabelWidget38 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget38, 63, 145);
    laWidget_SetSize((laWidget*)LabelWidget38, 408, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget38, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget38, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget38, laString_CreateFromID(string_HomeHelpText));
    laLabelWidget_SetHAlignment(LabelWidget38, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget38);

    LabelWidget39 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget39, 63, 121);
    laWidget_SetSize((laWidget*)LabelWidget39, 372, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget39, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget39, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget39, laString_CreateFromID(string_TouchStopHelpInfo));
    laLabelWidget_SetHAlignment(LabelWidget39, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget39);

    ImageWidget21 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget21, 36, 75);
    laWidget_SetSize((laWidget*)ImageWidget21, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget21, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget21, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget21, &GFX_Play_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget21);

    ImageWidget24 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget24, 36, 100);
    laWidget_SetSize((laWidget*)ImageWidget24, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget24, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget24, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget24, &GFX_FF_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget24);

    ImageWidget25 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget25, 36, 149);
    laWidget_SetSize((laWidget*)ImageWidget25, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget25, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget25, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget25, &GFX_Home_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget25);

    ImageWidget26 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget26, 36, 125);
    laWidget_SetSize((laWidget*)ImageWidget26, 20, 20);
    laWidget_SetBackgroundType((laWidget*)ImageWidget26, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget26, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget26, &GFX_Stop_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget26);

}



