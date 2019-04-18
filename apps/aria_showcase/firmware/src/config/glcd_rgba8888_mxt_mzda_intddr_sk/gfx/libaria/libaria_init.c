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
laScheme ListWheelScheme;
laScheme AlternateGradientScheme;
laScheme RadioButtonsOnDarkScheme;
laScheme whiteScheme;
laScheme BlackBackground;
laScheme BackgroundGradientScheme;
laScheme ClearScheme;
laScheme MainMenuGradientScheme;
laScheme TouchTestScheme;
laScheme GradientScheme;
laImageWidget* Pic32Logo;
laImageWidget* SplashBar;
laImageWidget* HarmonyLogoWidget;
laImageWidget* SplashBarLogo;
laGradientWidget* GradientWidget1;
laImageWidget* ImageWidget3;
laImageWidget* ImageWidget4;
laLabelWidget* LabelWidget1;
laLabelWidget* LabelWidget2;
laButtonWidget* ButtonWidget18;
laButtonWidget* ButtonWidget19;
laButtonWidget* ButtonWidget29;
laButtonWidget* ButtonWidget13;
laButtonWidget* ButtonWidget14;
laButtonWidget* ButtonWidget15;
laButtonWidget* ButtonWidget16;
laButtonWidget* ButtonWidget17;
laGradientWidget* GradientWidget3;
laLabelWidget* LabelWidget4;
laLabelWidget* LabelWidget5;
laButtonWidget* ButtonWidget30;
laButtonWidget* ButtonWidget1;
laButtonWidget* ButtonWidget7;
laLabelWidget* LabelWidget3;
laListWheelWidget* ListWheel2;
laListWheelWidget* ListWheel4;
laListWheelWidget* ListWheel5;
laListWheelWidget* ListWheel1;
laGradientWidget* GradientWidget4;
laKeyPadWidget* KeyPadWidget1;
laTextFieldWidget* TextFieldWidget1;
laLabelWidget* LabelWidget8;
laButtonWidget* ButtonWidget32;
laButtonWidget* ButtonWidget6;
laButtonWidget* ButtonWidget5;
laGradientWidget* GradientWidget5;
laWidget* PanelWidget1;
laSliderWidget* SliderWidget1;
laLabelWidget* SliderValueLabelWidget;
laWidget* PanelWidget2;
laButtonWidget* ButtonWidget4;
laButtonWidget* ButtonWidget8;
laLabelWidget* LabelWidget9;
laButtonWidget* ButtonWidget33;
laButtonWidget* SliderUpButtonWidget;
laButtonWidget* SliderDownButtonWidget;
laImageWidget* ImageWidget1;
laImageWidget* ImageWidget2;
laGradientWidget* GradientWidget6;
laImageSequenceWidget* ImageSequenceWidget1;
laLabelWidget* LabelWidget10;
laButtonWidget* ButtonWidget10;
laButtonWidget* ButtonWidget20;
laButtonWidget* ButtonWidget21;
laButtonWidget* ButtonWidget22;
laImageWidget* SSStatusImageWidget;
laButtonWidget* ButtonWidget9;
laButtonWidget* ButtonWidget11;
laGradientWidget* GradientWidget7;
laButtonWidget* ButtonWidget12;
laWidget* PanelWidget3;
laLabelWidget* LabelWidget11;
laRadioButtonWidget* RadioButtonEnglish;
laRadioButtonWidget* RadioButtonChinese;
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
laGradientWidget* GradientWidgetTouchTest;
laTouchTestWidget* TouchTestWidget2;
laLabelWidget* LabelWidgetTouchTest2;
laImageWidget* ImageWidget;
laButtonWidget* ButtonWidgetHelpTT;
laButtonWidget* ButtonWidgetHomeTT;
laLabelWidget* LabelWidgetTouchTest;
laButtonWidget* ButtonWidgetNextTT;


static void ScreenCreate_SplashScreen(laScreen* screen);
static void ScreenCreate_MainMenu(laScreen* screen);
static void ScreenCreate_FirstScreen(laScreen* screen);
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
static void ScreenCreate_TouchTestScreen(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&defaultScheme, GFX_COLOR_MODE_RGBA_8888);
    defaultScheme.base = 0xFFFFFFFF;
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

    laScheme_Initialize(&ListWheelScheme, GFX_COLOR_MODE_RGBA_8888);
    ListWheelScheme.base = 0xFFFFFFFF;
    ListWheelScheme.highlight = 0xFFFFFFFF;
    ListWheelScheme.highlightLight = 0xFFFFFFFF;
    ListWheelScheme.shadow = 0xFFFFFFFF;
    ListWheelScheme.shadowDark = 0x404040FF;
    ListWheelScheme.foreground = 0xFF;
    ListWheelScheme.foregroundInactive = 0x4000FF;
    ListWheelScheme.foregroundDisabled = 0xC000FF;
    ListWheelScheme.background = 0xFFFFFFFF;
    ListWheelScheme.backgroundInactive = 0xFFFBFFFF;
    ListWheelScheme.backgroundDisabled = 0x6B696BFF;
    ListWheelScheme.text = 0xFF;
    ListWheelScheme.textHighlight = 0x424142FF;
    ListWheelScheme.textHighlightText = 0xFFFFFFFF;
    ListWheelScheme.textInactive = 0x212021FF;
    ListWheelScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&AlternateGradientScheme, GFX_COLOR_MODE_RGBA_8888);
    AlternateGradientScheme.base = 0xFF0000FF;
    AlternateGradientScheme.highlight = 0xC8D0D4FF;
    AlternateGradientScheme.highlightLight = 0xFFFFFFFF;
    AlternateGradientScheme.shadow = 0x808080FF;
    AlternateGradientScheme.shadowDark = 0x404040FF;
    AlternateGradientScheme.foreground = 0xFF0000FF;
    AlternateGradientScheme.foregroundInactive = 0xFFFF;
    AlternateGradientScheme.foregroundDisabled = 0x808080FF;
    AlternateGradientScheme.background = 0xBDFF;
    AlternateGradientScheme.backgroundInactive = 0xD6E3E7FF;
    AlternateGradientScheme.backgroundDisabled = 0xC8D0D4FF;
    AlternateGradientScheme.text = 0xFF;
    AlternateGradientScheme.textHighlight = 0xFFFF;
    AlternateGradientScheme.textHighlightText = 0xFFFFFFFF;
    AlternateGradientScheme.textInactive = 0xD6E3E7FF;
    AlternateGradientScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&RadioButtonsOnDarkScheme, GFX_COLOR_MODE_RGBA_8888);
    RadioButtonsOnDarkScheme.base = 0xC8D0D4FF;
    RadioButtonsOnDarkScheme.highlight = 0xC8D0D4FF;
    RadioButtonsOnDarkScheme.highlightLight = 0xFFFFFFFF;
    RadioButtonsOnDarkScheme.shadow = 0x808080FF;
    RadioButtonsOnDarkScheme.shadowDark = 0x404040FF;
    RadioButtonsOnDarkScheme.foreground = 0xFF;
    RadioButtonsOnDarkScheme.foregroundInactive = 0xD6E3E7FF;
    RadioButtonsOnDarkScheme.foregroundDisabled = 0x808080FF;
    RadioButtonsOnDarkScheme.background = 0xFFFFFFFF;
    RadioButtonsOnDarkScheme.backgroundInactive = 0xD6E3E7FF;
    RadioButtonsOnDarkScheme.backgroundDisabled = 0xC8D0D4FF;
    RadioButtonsOnDarkScheme.text = 0xFFFFFFFF;
    RadioButtonsOnDarkScheme.textHighlight = 0xFFFF;
    RadioButtonsOnDarkScheme.textHighlightText = 0xFFFFFFFF;
    RadioButtonsOnDarkScheme.textInactive = 0xD6E3E7FF;
    RadioButtonsOnDarkScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&whiteScheme, GFX_COLOR_MODE_RGBA_8888);
    whiteScheme.base = 0xFFFFFFFF;
    whiteScheme.highlight = 0xC8D0D4FF;
    whiteScheme.highlightLight = 0xFFFFFFFF;
    whiteScheme.shadow = 0x808080FF;
    whiteScheme.shadowDark = 0x404040FF;
    whiteScheme.foreground = 0xFF;
    whiteScheme.foregroundInactive = 0xD6E3E7FF;
    whiteScheme.foregroundDisabled = 0x808080FF;
    whiteScheme.background = 0xFFFFFFFF;
    whiteScheme.backgroundInactive = 0xD6E3E7FF;
    whiteScheme.backgroundDisabled = 0xC8D0D4FF;
    whiteScheme.text = 0xFF;
    whiteScheme.textHighlight = 0xFFFF;
    whiteScheme.textHighlightText = 0xFFFFFFFF;
    whiteScheme.textInactive = 0xD6E3E7FF;
    whiteScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&BlackBackground, GFX_COLOR_MODE_RGBA_8888);
    BlackBackground.base = 0xC8D0D4FF;
    BlackBackground.highlight = 0xC8D0D4FF;
    BlackBackground.highlightLight = 0xFFFFFFFF;
    BlackBackground.shadow = 0x808080FF;
    BlackBackground.shadowDark = 0x404040FF;
    BlackBackground.foreground = 0xFF;
    BlackBackground.foregroundInactive = 0xD6E3E7FF;
    BlackBackground.foregroundDisabled = 0x808080FF;
    BlackBackground.background = 0xFF;
    BlackBackground.backgroundInactive = 0xD6E3E7FF;
    BlackBackground.backgroundDisabled = 0xC8D0D4FF;
    BlackBackground.text = 0xCEE7EFFF;
    BlackBackground.textHighlight = 0xFFFF;
    BlackBackground.textHighlightText = 0xFFFFFFFF;
    BlackBackground.textInactive = 0xD6E3E7FF;
    BlackBackground.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&BackgroundGradientScheme, GFX_COLOR_MODE_RGBA_8888);
    BackgroundGradientScheme.base = 0xFF;
    BackgroundGradientScheme.highlight = 0xC8D0D4FF;
    BackgroundGradientScheme.highlightLight = 0xFFFFFFFF;
    BackgroundGradientScheme.shadow = 0x808080FF;
    BackgroundGradientScheme.shadowDark = 0x404040FF;
    BackgroundGradientScheme.foreground = 0xB5C2FFFF;
    BackgroundGradientScheme.foregroundInactive = 0x42FF;
    BackgroundGradientScheme.foregroundDisabled = 0x808080FF;
    BackgroundGradientScheme.background = 0x52FF;
    BackgroundGradientScheme.backgroundInactive = 0xD6E3E7FF;
    BackgroundGradientScheme.backgroundDisabled = 0xC8D0D4FF;
    BackgroundGradientScheme.text = 0xFF;
    BackgroundGradientScheme.textHighlight = 0xFFFF;
    BackgroundGradientScheme.textHighlightText = 0xFFFFFFFF;
    BackgroundGradientScheme.textInactive = 0xD6E3E7FF;
    BackgroundGradientScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&ClearScheme, GFX_COLOR_MODE_RGBA_8888);
    ClearScheme.base = 0x0;
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

    laScheme_Initialize(&MainMenuGradientScheme, GFX_COLOR_MODE_RGBA_8888);
    MainMenuGradientScheme.base = 0xFFFFFFFF;
    MainMenuGradientScheme.highlight = 0xC8D0D4FF;
    MainMenuGradientScheme.highlightLight = 0xFFFFFFFF;
    MainMenuGradientScheme.shadow = 0x808080FF;
    MainMenuGradientScheme.shadowDark = 0x404040FF;
    MainMenuGradientScheme.foreground = 0x848284FF;
    MainMenuGradientScheme.foregroundInactive = 0xD6E3E7FF;
    MainMenuGradientScheme.foregroundDisabled = 0x808080FF;
    MainMenuGradientScheme.background = 0xFFFFFFFF;
    MainMenuGradientScheme.backgroundInactive = 0xD6E3E7FF;
    MainMenuGradientScheme.backgroundDisabled = 0xC8D0D4FF;
    MainMenuGradientScheme.text = 0xFF;
    MainMenuGradientScheme.textHighlight = 0xFFFF;
    MainMenuGradientScheme.textHighlightText = 0xFFFFFFFF;
    MainMenuGradientScheme.textInactive = 0xD6E3E7FF;
    MainMenuGradientScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&TouchTestScheme, GFX_COLOR_MODE_RGBA_8888);
    TouchTestScheme.base = 0xFFFFFFFF;
    TouchTestScheme.highlight = 0xC8D0D4FF;
    TouchTestScheme.highlightLight = 0xFFFFFFFF;
    TouchTestScheme.shadow = 0x808080FF;
    TouchTestScheme.shadowDark = 0x404040FF;
    TouchTestScheme.foreground = 0xFF00FFFF;
    TouchTestScheme.foregroundInactive = 0xFFFFFF;
    TouchTestScheme.foregroundDisabled = 0x808080FF;
    TouchTestScheme.background = 0xBDFF;
    TouchTestScheme.backgroundInactive = 0xD6E3E7FF;
    TouchTestScheme.backgroundDisabled = 0xC8D0D4FF;
    TouchTestScheme.text = 0xFFFFFF;
    TouchTestScheme.textHighlight = 0xFF00FFFF;
    TouchTestScheme.textHighlightText = 0xFFFFFFFF;
    TouchTestScheme.textInactive = 0xD6E3E7FF;
    TouchTestScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&GradientScheme, GFX_COLOR_MODE_RGBA_8888);
    GradientScheme.base = 0xFF0000FF;
    GradientScheme.highlight = 0xC8D0D4FF;
    GradientScheme.highlightLight = 0xFFFFFFFF;
    GradientScheme.shadow = 0x808080FF;
    GradientScheme.shadowDark = 0x404040FF;
    GradientScheme.foreground = 0xFF00FF;
    GradientScheme.foregroundInactive = 0xFFFF00FF;
    GradientScheme.foregroundDisabled = 0x808080FF;
    GradientScheme.background = 0xBDFF;
    GradientScheme.backgroundInactive = 0xD6E3E7FF;
    GradientScheme.backgroundDisabled = 0xC8D0D4FF;
    GradientScheme.text = 0xFF;
    GradientScheme.textHighlight = 0xFFFF;
    GradientScheme.textHighlightText = 0x84FFFFFF;
    GradientScheme.textInactive = 0xD6E3E7FF;
    GradientScheme.textDisabled = 0x8C9294FF;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    laContext_SetStringTable(&stringTable);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_SplashScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_MainMenu);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_FirstScreen);
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

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_TouchTestScreen);
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
    laLayer_SetBufferCount(layer0, 2);
    laLayer_SetAlphaEnable(layer0, LA_TRUE);
    laLayer_SetAlphaAmount(layer0, 0xFF);

    laScreen_SetLayer(screen, 0, layer0);

    Pic32Logo = laImageWidget_New();
    laWidget_SetPosition((laWidget*)Pic32Logo, 123, 71);
    laWidget_SetSize((laWidget*)Pic32Logo, 240, 66);
    laWidget_SetBackgroundType((laWidget*)Pic32Logo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)Pic32Logo, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(Pic32Logo, &PIC32Logo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)Pic32Logo);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0xFF);

    laScreen_SetLayer(screen, 1, layer1);

    SplashBar = laImageWidget_New();
    laWidget_SetPosition((laWidget*)SplashBar, 480, 207);
    laWidget_SetSize((laWidget*)SplashBar, 480, 65);
    laWidget_SetBackgroundType((laWidget*)SplashBar, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SplashBar, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(SplashBar, &Bar);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)SplashBar);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x0);

    laScreen_SetLayer(screen, 2, layer2);

    HarmonyLogoWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)HarmonyLogoWidget, 144, 42);
    laWidget_SetSize((laWidget*)HarmonyLogoWidget, 197, 139);
    laWidget_SetScheme((laWidget*)HarmonyLogoWidget, &whiteScheme);
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
    laImageWidget_SetImage(SplashBarLogo, &MicrochipLogo_1);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)SplashBarLogo);

}

static void ScreenCreate_MainMenu(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &ClearScheme);
    laLayer_SetBufferCount(layer0, 2);
    laLayer_SetAlphaEnable(layer0, LA_TRUE);
    laLayer_SetAlphaAmount(layer0, 0xFF);

    laScreen_SetLayer(screen, 0, layer0);

    GradientWidget1 = laGradientWidget_New();
    laWidget_SetSize((laWidget*)GradientWidget1, 480, 272);
    laWidget_SetScheme((laWidget*)GradientWidget1, &BackgroundGradientScheme);
    laWidget_SetBackgroundType((laWidget*)GradientWidget1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GradientWidget1, LA_WIDGET_BORDER_NONE);
    laGradientWidget_SetDirection((laGradientWidget*)GradientWidget1, LA_GRADIENT_DIRECTION_DOWN);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)GradientWidget1);

    ImageWidget3 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget3, 2, 13);
    laWidget_SetSize((laWidget*)ImageWidget3, 153, 37);
    laWidget_SetScheme((laWidget*)ImageWidget3, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget3, LA_WIDGET_BORDER_NONE);
    laWidget_SetAlphaEnable((laWidget*)ImageWidget3, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)ImageWidget3, 255);
    laImageWidget_SetImage(ImageWidget3, &GFX_Microchip_logo_150x30);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget3);

    ImageWidget4 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget4, 386, 0);
    laWidget_SetSize((laWidget*)ImageWidget4, 94, 56);
    laWidget_SetScheme((laWidget*)ImageWidget4, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget4, LA_WIDGET_BORDER_NONE);
    laWidget_SetAlphaEnable((laWidget*)ImageWidget4, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)ImageWidget4, 255);
    laImageWidget_SetImage(ImageWidget4, &GFX_mplab_logo_80x80);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget4);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0x0);

    laScreen_SetLayer(screen, 1, layer1);

    LabelWidget1 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget1, 73, 179);
    laWidget_SetSize((laWidget*)LabelWidget1, 168, 32);
    laWidget_SetScheme((laWidget*)LabelWidget1, &BlackBackground);
    laWidget_SetBackgroundType((laWidget*)LabelWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget1, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget1, laString_CreateFromID(string_Harmony));
    laLabelWidget_SetHAlignment(LabelWidget1, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)LabelWidget1);

    LabelWidget2 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget2, 233, 180);
    laWidget_SetSize((laWidget*)LabelWidget2, 190, 31);
    laWidget_SetScheme((laWidget*)LabelWidget2, &BlackBackground);
    laWidget_SetBackgroundType((laWidget*)LabelWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget2, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget2, laString_CreateFromID(string_Title));
    laLabelWidget_SetHAlignment(LabelWidget2, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)LabelWidget2);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0xFF);

    laScreen_SetLayer(screen, 2, layer2);

    ButtonWidget18 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget18, -9, 225);
    laWidget_SetSize((laWidget*)ButtonWidget18, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget18, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget18, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget18, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget18, &GFX_Help_60);
    laButtonWidget_SetReleasedImage(ButtonWidget18, &GFX_Help_60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget18, &ButtonWidget18_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonWidget18);

    ButtonWidget19 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget19, 430, 225);
    laWidget_SetSize((laWidget*)ButtonWidget19, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget19, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget19, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget19, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget19, &GFX_Settings_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidget19, &GFX_Settings_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget19, &ButtonWidget19_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonWidget19);

    ButtonWidget29 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget29, 370, 225);
    laWidget_SetSize((laWidget*)ButtonWidget29, 60, 60);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget29, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget29, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget29, &GFX_NextScreen_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidget29, &GFX_NextScreen_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget29, &ButtonWidget29_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonWidget29);

    ButtonWidget13 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget13, 10, 83);
    laWidget_SetSize((laWidget*)ButtonWidget13, 81, 81);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget13, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget13, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget13, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget13, &GFX_Slide_80_drop);
    laButtonWidget_SetReleasedImage(ButtonWidget13, &GFX_Slide_80_drop);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget13, &ButtonWidget13_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonWidget13);

    ButtonWidget14 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget14, 296, 87);
    laWidget_SetSize((laWidget*)ButtonWidget14, 83, 74);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget14, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget14, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget14, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget14, &GFX_alpha_80x80_drop);
    laButtonWidget_SetReleasedImage(ButtonWidget14, &GFX_alpha_80x80_drop);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget14, &ButtonWidget14_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonWidget14);

    ButtonWidget15 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget15, 386, 83);
    laWidget_SetSize((laWidget*)ButtonWidget15, 84, 80);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget15, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget15, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget15, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget15, &GFX_SlideShow_80_drop);
    laButtonWidget_SetReleasedImage(ButtonWidget15, &GFX_SlideShow_80_drop);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget15, &ButtonWidget15_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonWidget15);

    ButtonWidget16 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget16, 103, 83);
    laWidget_SetSize((laWidget*)ButtonWidget16, 86, 81);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget16, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget16, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget16, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget16, &GFX_Touch_80_drop);
    laButtonWidget_SetReleasedImage(ButtonWidget16, &GFX_Touch_80_drop);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget16, &ButtonWidget16_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonWidget16);

    ButtonWidget17 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget17, 200, 84);
    laWidget_SetSize((laWidget*)ButtonWidget17, 84, 77);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidget17, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget17, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget17, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget17, &GFX_Keyboard_80_drop);
    laButtonWidget_SetReleasedImage(ButtonWidget17, &GFX_Keyboard_80_drop);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget17, &ButtonWidget17_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonWidget17);

}

static void ScreenCreate_FirstScreen(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_NONE);
    laLayer_SetBufferCount(layer0, 2);
    laLayer_SetAlphaEnable(layer0, LA_TRUE);
    laLayer_SetAlphaAmount(layer0, 0xFF);

    laScreen_SetLayer(screen, 0, layer0);

    GradientWidget3 = laGradientWidget_New();
    laWidget_SetSize((laWidget*)GradientWidget3, 480, 272);
    laWidget_SetScheme((laWidget*)GradientWidget3, &BackgroundGradientScheme);
    laWidget_SetBackgroundType((laWidget*)GradientWidget3, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GradientWidget3, LA_WIDGET_BORDER_NONE);
    laGradientWidget_SetDirection((laGradientWidget*)GradientWidget3, LA_GRADIENT_DIRECTION_DOWN);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)GradientWidget3);

    LabelWidget4 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget4, 361, 119);
    laWidget_SetSize((laWidget*)LabelWidget4, 70, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget4, LA_WIDGET_BACKGROUND_CACHE);
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

    LabelWidget3 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget3, 158, 115);
    laWidget_SetSize((laWidget*)LabelWidget3, 11, 36);
    laWidget_SetEnabled((laWidget*)LabelWidget3, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)LabelWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget3, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget3, laString_CreateFromID(string_colon));
    laLabelWidget_SetHAlignment(LabelWidget3, LA_HALIGN_LEFT);
    laLabelWidget_SetVAlignment(LabelWidget3, LA_VALIGN_TOP);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget3);

    ListWheel2 = laListWheelWidget_New();
    laWidget_SetPosition((laWidget*)ListWheel2, 102, 65);
    laWidget_SetSize((laWidget*)ListWheel2, 57, 133);
    laWidget_SetOptimizationFlags((laWidget*)ListWheel2, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)ListWheel2, &ListWheelScheme);
    laWidget_SetBackgroundType((laWidget*)ListWheel2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ListWheel2, LA_WIDGET_BORDER_LINE);
    laListWheelWidget_SetAlignment(ListWheel2, LA_HALIGN_RIGHT);
    laListWheelWidget_SetShaded(ListWheel2, LA_FALSE);
    laListWheelWidget_SetFlickInitSpeed(ListWheel2, 5);
    laListWheelWidget_SetMaxMomentum(ListWheel2, 10000);
    laListWheelWidget_SetRotationUpdateRate(ListWheel2, 18);
    laListWheelWidget_SetAutoHideWheel(ListWheel2, LA_TRUE);
    laListWheelWidget_SetZoomEffects(ListWheel2, LA_LISTWHEEL_ZOOM_EFFECT_FULL_SCALE);
    laListWheelWidget_SetIndicatorFill(ListWheel2, LA_LISTWHEEL_INDICATOR_FILL_GRADIENT);
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
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ListWheel2);

    ListWheel4 = laListWheelWidget_New();
    laWidget_SetPosition((laWidget*)ListWheel4, 168, 65);
    laWidget_SetSize((laWidget*)ListWheel4, 56, 133);
    laWidget_SetOptimizationFlags((laWidget*)ListWheel4, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)ListWheel4, &ListWheelScheme);
    laWidget_SetBackgroundType((laWidget*)ListWheel4, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ListWheel4, LA_WIDGET_BORDER_LINE);
    laListWheelWidget_SetShaded(ListWheel4, LA_FALSE);
    laListWheelWidget_SetFlickInitSpeed(ListWheel4, 5);
    laListWheelWidget_SetMaxMomentum(ListWheel4, 10000);
    laListWheelWidget_SetRotationUpdateRate(ListWheel4, 18);
    laListWheelWidget_SetAutoHideWheel(ListWheel4, LA_TRUE);
    laListWheelWidget_SetZoomEffects(ListWheel4, LA_LISTWHEEL_ZOOM_EFFECT_FIXED_SCALE);
    laListWheelWidget_SetIndicatorFill(ListWheel4, LA_LISTWHEEL_INDICATOR_FILL_GRADIENT);
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
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ListWheel4);

    ListWheel5 = laListWheelWidget_New();
    laWidget_SetPosition((laWidget*)ListWheel5, 227, 65);
    laWidget_SetSize((laWidget*)ListWheel5, 57, 133);
    laWidget_SetOptimizationFlags((laWidget*)ListWheel5, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)ListWheel5, &ListWheelScheme);
    laWidget_SetBackgroundType((laWidget*)ListWheel5, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ListWheel5, LA_WIDGET_BORDER_LINE);
    laListWheelWidget_SetShaded(ListWheel5, LA_FALSE);
    laListWheelWidget_SetFlickInitSpeed(ListWheel5, 5);
    laListWheelWidget_SetMaxMomentum(ListWheel5, 10000);
    laListWheelWidget_SetRotationUpdateRate(ListWheel5, 18);
    laListWheelWidget_SetAutoHideWheel(ListWheel5, LA_TRUE);
    laListWheelWidget_SetZoomEffects(ListWheel5, LA_LISTWHEEL_ZOOM_EFFECT_FIXED_SCALE);
    laListWheelWidget_SetIndicatorFill(ListWheel5, LA_LISTWHEEL_INDICATOR_FILL_GRADIENT);
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
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ListWheel5);

    ListWheel1 = laListWheelWidget_New();
    laWidget_SetPosition((laWidget*)ListWheel1, 287, 65);
    laWidget_SetSize((laWidget*)ListWheel1, 56, 133);
    laWidget_SetOptimizationFlags((laWidget*)ListWheel1, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)ListWheel1, &ListWheelScheme);
    laWidget_SetBackgroundType((laWidget*)ListWheel1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ListWheel1, LA_WIDGET_BORDER_LINE);
    laListWheelWidget_SetAlignment(ListWheel1, LA_HALIGN_LEFT);
    laListWheelWidget_SetShaded(ListWheel1, LA_FALSE);
    laListWheelWidget_SetFlickInitSpeed(ListWheel1, 5);
    laListWheelWidget_SetMaxMomentum(ListWheel1, 200);
    laListWheelWidget_SetRotationUpdateRate(ListWheel1, 18);
    laListWheelWidget_SetAutoHideWheel(ListWheel1, LA_TRUE);
    laListWheelWidget_SetZoomEffects(ListWheel1, LA_LISTWHEEL_ZOOM_EFFECT_FULL_SCALE);
    laListWheelWidget_SetIndicatorFill(ListWheel1, LA_LISTWHEEL_INDICATOR_FILL_GRADIENT);
    laListWheelWidget_AppendItem(ListWheel1);
    laListWheelWidget_SetItemText(ListWheel1, 0, laString_CreateFromID(string_AM));
    laListWheelWidget_AppendItem(ListWheel1);
    laListWheelWidget_SetItemText(ListWheel1, 1, laString_CreateFromID(string_PM));
    laListWheelWidget_AppendItem(ListWheel1);
    laListWheelWidget_AppendItem(ListWheel1);
    laListWheelWidget_AppendItem(ListWheel1);
    laListWheelWidget_AppendItem(ListWheel1);
    laListWheelWidget_SetSelectedItemChangedEventCallback(ListWheel1, &ListWheel1_SelectedItemChangedEvent);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ListWheel1);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0xFF);

    laScreen_SetLayer(screen, 1, layer1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0xFF);

    laScreen_SetLayer(screen, 2, layer2);

}

static void ScreenCreate_ThirdScreen(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_NONE);
    laLayer_SetBufferCount(layer0, 2);
    laLayer_SetAlphaEnable(layer0, LA_TRUE);
    laLayer_SetAlphaAmount(layer0, 0xFF);

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
    laWidget_SetVisible((laWidget*)KeyPadWidget1, LA_FALSE);
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
    laTextFieldWidget_SetFocusChangedEventCallback(TextFieldWidget1, &TextFieldWidget1_FocusChangedEvent);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)TextFieldWidget1);

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

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0xFF);

    laScreen_SetLayer(screen, 1, layer1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0xFF);

    laScreen_SetLayer(screen, 2, layer2);

}

static void ScreenCreate_FourthScreen(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    laScreen_SetShowEventCallback(screen, &FourthScreen_ShowEvent);
    laScreen_SetHideEventCallback(screen, &FourthScreen_HideEvent);

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_NONE);
    laLayer_SetBufferCount(layer0, 2);
    laLayer_SetAlphaEnable(layer0, LA_TRUE);
    laLayer_SetAlphaAmount(layer0, 0xFF);

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
    laWidget_SetSize((laWidget*)PanelWidget1, 98, 187);
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
    laWidget_SetBackgroundType((laWidget*)SliderValueLabelWidget, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)SliderValueLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetHAlignment(SliderValueLabelWidget, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget1, (laWidget*)SliderValueLabelWidget);

    PanelWidget2 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget2, 61, 36);
    laWidget_SetSize((laWidget*)PanelWidget2, 299, 180);
    laWidget_SetBackgroundType((laWidget*)PanelWidget2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget2, LA_WIDGET_BORDER_LINE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget2);

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

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0x7F);

    laScreen_SetLayer(screen, 1, layer1);

    ImageWidget1 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget1, 61, 36);
    laWidget_SetSize((laWidget*)ImageWidget1, 300, 180);
    laWidget_SetBackgroundType((laWidget*)ImageWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget1, LA_WIDGET_BORDER_LINE);
    laWidget_SetAlphaEnable((laWidget*)ImageWidget1, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)ImageWidget1, 255);
    laImageWidget_SetImage(ImageWidget1, &NewHarmonyLogo);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)ImageWidget1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x7F);

    laScreen_SetLayer(screen, 2, layer2);

    ImageWidget2 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget2, 61, 36);
    laWidget_SetSize((laWidget*)ImageWidget2, 300, 180);
    laWidget_SetBackgroundType((laWidget*)ImageWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget2, LA_WIDGET_BORDER_LINE);
    laWidget_SetAlphaEnable((laWidget*)ImageWidget2, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)ImageWidget2, 255);
    laImageWidget_SetImage(ImageWidget2, &MicrochipLogo);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)ImageWidget2);

}

static void ScreenCreate_FifthScreen(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    laScreen_SetHideEventCallback(screen, &FifthScreen_HideEvent);

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_NONE);
    laLayer_SetBufferCount(layer0, 2);
    laLayer_SetAlphaEnable(layer0, LA_TRUE);
    laLayer_SetAlphaAmount(layer0, 0xFF);

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
    laWidget_SetBackgroundType((laWidget*)ButtonWidget10, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)ButtonWidget10, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget10, &GFX_ArrowLeft_20x60);
    laButtonWidget_SetReleasedImage(ButtonWidget10, &GFX_ArrowLeft_20x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget10, &ButtonWidget10_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget10);

    ButtonWidget20 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget20, 430, 90);
    laWidget_SetSize((laWidget*)ButtonWidget20, 49, 65);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget20, LA_WIDGET_BACKGROUND_CACHE);
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
    laWidget_SetBackgroundType((laWidget*)SSStatusImageWidget, LA_WIDGET_BACKGROUND_CACHE);
    laWidget_SetBorderType((laWidget*)SSStatusImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(SSStatusImageWidget, &GFX_Pause_Pink_20x20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)SSStatusImageWidget);

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

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0xFF);

    laScreen_SetLayer(screen, 1, layer1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0xFF);

    laScreen_SetLayer(screen, 2, layer2);

}

static void ScreenCreate_SettingsScreen(laScreen* screen)
{
    laLayer* layer0;
    laRadioButtonGroup* radioButtonGroup_0;
    laLayer* layer1;
    laLayer* layer2;

    laScreen_SetShowEventCallback(screen, &SettingsScreen_ShowEvent);

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &defaultScheme);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    GradientWidget7 = laGradientWidget_New();
    laWidget_SetSize((laWidget*)GradientWidget7, 480, 272);
    laWidget_SetScheme((laWidget*)GradientWidget7, &BackgroundGradientScheme);
    laWidget_SetBackgroundType((laWidget*)GradientWidget7, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GradientWidget7, LA_WIDGET_BORDER_NONE);
    laGradientWidget_SetDirection((laGradientWidget*)GradientWidget7, LA_GRADIENT_DIRECTION_DOWN);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)GradientWidget7);

    ButtonWidget12 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget12, 430, 225);
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

    RadioButtonEnglish = laRadioButtonWidget_New();
    laWidget_SetPosition((laWidget*)RadioButtonEnglish, 133, 6);
    laWidget_SetSize((laWidget*)RadioButtonEnglish, 100, 25);
    laWidget_SetBackgroundType((laWidget*)RadioButtonEnglish, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)RadioButtonEnglish, LA_WIDGET_BORDER_NONE);
    laRadioButtonWidget_SetText(RadioButtonEnglish, laString_CreateFromID(string_RadioButton_English));
    laRadioButtonWidget_SetHAlignment(RadioButtonEnglish, LA_HALIGN_LEFT);
    laRadioButtonGroup_Create(&radioButtonGroup_0);
    laRadioButtonGroup_AddButton(radioButtonGroup_0, RadioButtonEnglish);
    laRadioButtonWidget_SetSelected(RadioButtonEnglish);
    laRadioButtonWidget_SetSelectedEventCallback(RadioButtonEnglish, &RadioButtonEnglish_CheckedEvent);

    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)RadioButtonEnglish);

    RadioButtonChinese = laRadioButtonWidget_New();
    laWidget_SetPosition((laWidget*)RadioButtonChinese, 262, 6);
    laWidget_SetSize((laWidget*)RadioButtonChinese, 100, 25);
    laWidget_SetBackgroundType((laWidget*)RadioButtonChinese, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)RadioButtonChinese, LA_WIDGET_BORDER_NONE);
    laRadioButtonWidget_SetText(RadioButtonChinese, laString_CreateFromID(string_RadioButton_Chinese));
    laRadioButtonWidget_SetHAlignment(RadioButtonChinese, LA_HALIGN_LEFT);
    laRadioButtonGroup_AddButton(radioButtonGroup_0, RadioButtonChinese);
    laRadioButtonWidget_SetSelectedEventCallback(RadioButtonChinese, &RadioButtonChinese_CheckedEvent);

    laWidget_AddChild((laWidget*)PanelWidget3, (laWidget*)RadioButtonChinese);

    ButtonWidgetChinese = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidgetChinese, 298, 35);
    laWidget_SetSize((laWidget*)ButtonWidgetChinese, 103, 38);
    laWidget_SetBackgroundType((laWidget*)ButtonWidgetChinese, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidgetChinese, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedEventCallback(ButtonWidgetChinese, &ButtonWidgetChinese_PressedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidgetChinese);

    ButtonWidgetEnglish = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidgetEnglish, 167, 35);
    laWidget_SetSize((laWidget*)ButtonWidgetEnglish, 108, 38);
    laWidget_SetBackgroundType((laWidget*)ButtonWidgetEnglish, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidgetEnglish, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedEventCallback(ButtonWidgetEnglish, &ButtonWidgetEnglish_PressedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidgetEnglish);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0xFF);

    laScreen_SetLayer(screen, 1, layer1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0xFF);

    laScreen_SetLayer(screen, 2, layer2);

}

static void ScreenCreate_MainMenuHelp(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 2);

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

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0x0);

    laScreen_SetLayer(screen, 1, layer1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x0);

    laScreen_SetLayer(screen, 2, layer2);

}

static void ScreenCreate_ListWheelHelpScreen(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 2);

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
    laWidget_SetBackgroundType((laWidget*)LabelWidget21, LA_WIDGET_BACKGROUND_CACHE);
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

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0x0);

    laScreen_SetLayer(screen, 1, layer1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x0);

    laScreen_SetLayer(screen, 2, layer2);

}

static void ScreenCreate_TouchTestHelpScreen(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 2);

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

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0x0);

    laScreen_SetLayer(screen, 1, layer1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x0);

    laScreen_SetLayer(screen, 2, layer2);

}

static void ScreenCreate_KeypadHelpScreen(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 2);
    laLayer_SetAlphaEnable(layer0, LA_TRUE);
    laLayer_SetAlphaAmount(layer0, 0xFF);

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

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0xFF);

    laScreen_SetLayer(screen, 1, layer1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0xFF);

    laScreen_SetLayer(screen, 2, layer2);

}

static void ScreenCreate_AlphaBlendingHelpScreen(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 2);

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

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0x0);

    laScreen_SetLayer(screen, 1, layer1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x0);

    laScreen_SetLayer(screen, 2, layer2);

}

static void ScreenCreate_SlideshowHelpScreen(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 2);
    laLayer_SetAlphaEnable(layer0, LA_TRUE);
    laLayer_SetAlphaAmount(layer0, 0xFF);

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

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0x0);

    laScreen_SetLayer(screen, 1, layer1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x0);

    laScreen_SetLayer(screen, 2, layer2);

}

static void ScreenCreate_TouchTestScreen(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_NONE);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    GradientWidgetTouchTest = laGradientWidget_New();
    laWidget_SetSize((laWidget*)GradientWidgetTouchTest, 480, 272);
    laWidget_SetScheme((laWidget*)GradientWidgetTouchTest, &BackgroundGradientScheme);
    laWidget_SetBackgroundType((laWidget*)GradientWidgetTouchTest, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)GradientWidgetTouchTest, LA_WIDGET_BORDER_NONE);
    laGradientWidget_SetDirection((laGradientWidget*)GradientWidgetTouchTest, LA_GRADIENT_DIRECTION_DOWN);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)GradientWidgetTouchTest);

    TouchTestWidget2 = laTouchTestWidget_New();
    laWidget_SetPosition((laWidget*)TouchTestWidget2, 130, 43);
    laWidget_SetSize((laWidget*)TouchTestWidget2, 297, 169);
    laWidget_SetOptimizationFlags((laWidget*)TouchTestWidget2, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)TouchTestWidget2, &TouchTestScheme);
    laWidget_SetBackgroundType((laWidget*)TouchTestWidget2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)TouchTestWidget2, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)TouchTestWidget2);

    LabelWidgetTouchTest2 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidgetTouchTest2, 125, 216);
    laWidget_SetSize((laWidget*)LabelWidgetTouchTest2, 228, 25);
    laWidget_SetOptimizationFlags((laWidget*)LabelWidgetTouchTest2, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetScheme((laWidget*)LabelWidgetTouchTest2, &BlackBackground);
    laWidget_SetBackgroundType((laWidget*)LabelWidgetTouchTest2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidgetTouchTest2, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidgetTouchTest2, laString_CreateFromID(string_TouchMe));
    laLabelWidget_SetHAlignment(LabelWidgetTouchTest2, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidgetTouchTest2);

    ImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget, 45, 152);
    laWidget_SetSize((laWidget*)ImageWidget, 81, 100);
    laWidget_SetBackgroundType((laWidget*)ImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget, &GFX_Touch_80);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget);

    ButtonWidgetHelpTT = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidgetHelpTT, -9, 226);
    laWidget_SetSize((laWidget*)ButtonWidgetHelpTT, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidgetHelpTT, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidgetHelpTT, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidgetHelpTT, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidgetHelpTT, &GFX_Help_60);
    laButtonWidget_SetReleasedImage(ButtonWidgetHelpTT, &GFX_Help_60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidgetHelpTT, &ButtonWidgetHelpTT_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidgetHelpTT);

    ButtonWidgetHomeTT = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidgetHomeTT, 430, 226);
    laWidget_SetSize((laWidget*)ButtonWidgetHomeTT, 60, 60);
    laWidget_SetBackgroundType((laWidget*)ButtonWidgetHomeTT, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidgetHomeTT, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidgetHomeTT, &GFX_Home_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidgetHomeTT, &GFX_Home_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidgetHomeTT, &ButtonWidgetHomeTT_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidgetHomeTT);

    LabelWidgetTouchTest = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidgetTouchTest, 10, 6);
    laWidget_SetSize((laWidget*)LabelWidgetTouchTest, 293, 25);
    laWidget_SetScheme((laWidget*)LabelWidgetTouchTest, &BlackBackground);
    laWidget_SetBackgroundType((laWidget*)LabelWidgetTouchTest, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidgetTouchTest, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidgetTouchTest, laString_CreateFromID(string_TouchTestWidgetDemo));
    laLabelWidget_SetHAlignment(LabelWidgetTouchTest, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidgetTouchTest);

    ButtonWidgetNextTT = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidgetNextTT, 370, 226);
    laWidget_SetSize((laWidget*)ButtonWidgetNextTT, 60, 60);
    laWidget_SetOptimizationFlags((laWidget*)ButtonWidgetNextTT, LA_WIDGET_OPT_LOCAL_REDRAW);
    laWidget_SetBackgroundType((laWidget*)ButtonWidgetNextTT, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidgetNextTT, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidgetNextTT, &GFX_NextScreen_60x60);
    laButtonWidget_SetReleasedImage(ButtonWidgetNextTT, &GFX_NextScreen_60x60);
    laButtonWidget_SetReleasedEventCallback(ButtonWidgetNextTT, &ButtonWidgetNextTT_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidgetNextTT);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0x0);

    laScreen_SetLayer(screen, 1, layer1);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x0);

    laScreen_SetLayer(screen, 2, layer2);

}



int32_t libaria_preprocess_assets(void)
{

    // process images configured for preprocessing
    laUtils_PreprocessImage(&MicrochipLogo,0xA85FD000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&NewHarmonyLogo,0xA867D000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&LucyInTheSky,0xA82FD000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&USA,0xA83FD000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&ice_color,0xA84FD000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&GFX_Keyboard_80_drop,0xA870D000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&GFX_SlideShow_80_drop,0xA871D000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&GFX_Touch_80_drop,0xA86FD000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&GFX_alpha_80x80_drop,0xA873D000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&GFX_Slide_80_drop,0xA872D000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);

    return 0;
}

