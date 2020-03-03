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

laScheme controllerTitle;
laScheme RedScheme;
laScheme helpScheme;
laScheme GreenScheme;
laScheme SettingsScheme;
laScheme infoScreen;
laScheme WhiteScheme;
laScheme YellowScheme;
laScheme clockScheme;
laImageWidget* Pic32Logo;
laImageWidget* HarmonyLogoWidget;
laWidget* PanelWidget;
laImageWidget* SplashBar;
laImageWidget* SplashBarLogo;
laButtonWidget* ButtonWidget1;
laLabelWidget* centerClockLabel;
laImageWidget* ImageWidget3;
laLabelWidget* LabelWidget4;
laButtonWidget* StartButton;
laLabelWidget* TimeLabel;
laButtonWidget* HomeButton;
laButtonWidget* FishButtonWidget;
laButtonWidget* PizzaButtonWidget;
laButtonWidget* VegeButtonWidget;
laButtonWidget* StartStopButton;
laButtonWidget* DoneButton;
laCircularGaugeWidget* FishGaugeWidget;
laCircularGaugeWidget* PizzaGaugeWidget;
laCircularGaugeWidget* TurkeyGaugeWidget;
laImageSequenceWidget* Flames;
laLabelWidget* LabelWidget15;
laButtonWidget* ButtonWidget16;
laLabelWidget* LabelWidget17;
laLabelWidget* LabelWidget18;
laLabelWidget* LabelWidget19;
laLabelWidget* LabelWidget20;
laLabelWidget* LabelWidget21;
laCircularGaugeWidget* CircularGaugeWidget22;
laLabelWidget* LabelWidget23;
laImageWidget* ImageWidget24;
laImageWidget* ImageWidget25;
laImageWidget* ImageWidget26;
laImageWidget* ImageWidget27;
laImageWidget* ImageWidget28;
laImageWidget* ImageWidget29;
laImageWidget* ImageWidget30;


static void ScreenCreate_SplashScreen(laScreen* screen);
static void ScreenCreate_homeScreen(laScreen* screen);
static void ScreenCreate_controllerScreen(laScreen* screen);
static void ScreenCreate_infoScreen(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&controllerTitle, GFX_COLOR_MODE_RGB_565);
    controllerTitle.base = 0xC67A;
    controllerTitle.highlight = 0xC67A;
    controllerTitle.highlightLight = 0xFFFF;
    controllerTitle.shadow = 0x8410;
    controllerTitle.shadowDark = 0x4208;
    controllerTitle.foreground = 0x0;
    controllerTitle.foregroundInactive = 0xD71C;
    controllerTitle.foregroundDisabled = 0x8410;
    controllerTitle.background = 0xFC00;
    controllerTitle.backgroundInactive = 0xD71C;
    controllerTitle.backgroundDisabled = 0xC67A;
    controllerTitle.text = 0xFC00;
    controllerTitle.textHighlight = 0x1F;
    controllerTitle.textHighlightText = 0xFFFF;
    controllerTitle.textInactive = 0xD71C;
    controllerTitle.textDisabled = 0x8C92;

    laScheme_Initialize(&RedScheme, GFX_COLOR_MODE_RGB_565);
    RedScheme.base = 0xC67A;
    RedScheme.highlight = 0xC67A;
    RedScheme.highlightLight = 0xFFFF;
    RedScheme.shadow = 0x8410;
    RedScheme.shadowDark = 0x4208;
    RedScheme.foreground = 0xF800;
    RedScheme.foregroundInactive = 0xD71C;
    RedScheme.foregroundDisabled = 0x8410;
    RedScheme.background = 0xFFFF;
    RedScheme.backgroundInactive = 0xD71C;
    RedScheme.backgroundDisabled = 0xC67A;
    RedScheme.text = 0x0;
    RedScheme.textHighlight = 0x1F;
    RedScheme.textHighlightText = 0xFFFF;
    RedScheme.textInactive = 0xD71C;
    RedScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&helpScheme, GFX_COLOR_MODE_RGB_565);
    helpScheme.base = 0x0;
    helpScheme.highlight = 0xC67A;
    helpScheme.highlightLight = 0xFFFF;
    helpScheme.shadow = 0x8410;
    helpScheme.shadowDark = 0x4208;
    helpScheme.foreground = 0x0;
    helpScheme.foregroundInactive = 0xD71C;
    helpScheme.foregroundDisabled = 0x8410;
    helpScheme.background = 0xFDF0;
    helpScheme.backgroundInactive = 0xD71C;
    helpScheme.backgroundDisabled = 0xC67A;
    helpScheme.text = 0xFFFF;
    helpScheme.textHighlight = 0x1F;
    helpScheme.textHighlightText = 0xFFFF;
    helpScheme.textInactive = 0xD71C;
    helpScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&GreenScheme, GFX_COLOR_MODE_RGB_565);
    GreenScheme.base = 0xFC00;
    GreenScheme.highlight = 0xC67A;
    GreenScheme.highlightLight = 0xFFFF;
    GreenScheme.shadow = 0x8410;
    GreenScheme.shadowDark = 0x4208;
    GreenScheme.foreground = 0x7E0;
    GreenScheme.foregroundInactive = 0xDEFB;
    GreenScheme.foregroundDisabled = 0x8410;
    GreenScheme.background = 0xFFFF;
    GreenScheme.backgroundInactive = 0xD71C;
    GreenScheme.backgroundDisabled = 0xC67A;
    GreenScheme.text = 0x0;
    GreenScheme.textHighlight = 0x1F;
    GreenScheme.textHighlightText = 0xFFFF;
    GreenScheme.textInactive = 0xD71C;
    GreenScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&SettingsScheme, GFX_COLOR_MODE_RGB_565);
    SettingsScheme.base = 0x0;
    SettingsScheme.highlight = 0xC67A;
    SettingsScheme.highlightLight = 0xFFFF;
    SettingsScheme.shadow = 0x8410;
    SettingsScheme.shadowDark = 0x4208;
    SettingsScheme.foreground = 0x0;
    SettingsScheme.foregroundInactive = 0xD71C;
    SettingsScheme.foregroundDisabled = 0x8410;
    SettingsScheme.background = 0xFFFF;
    SettingsScheme.backgroundInactive = 0xD71C;
    SettingsScheme.backgroundDisabled = 0xC67A;
    SettingsScheme.text = 0x0;
    SettingsScheme.textHighlight = 0x1F;
    SettingsScheme.textHighlightText = 0xFFFF;
    SettingsScheme.textInactive = 0xD71C;
    SettingsScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&infoScreen, GFX_COLOR_MODE_RGB_565);
    infoScreen.base = 0xC67A;
    infoScreen.highlight = 0xC67A;
    infoScreen.highlightLight = 0xFFFF;
    infoScreen.shadow = 0x8410;
    infoScreen.shadowDark = 0x4208;
    infoScreen.foreground = 0x0;
    infoScreen.foregroundInactive = 0xD71C;
    infoScreen.foregroundDisabled = 0x8410;
    infoScreen.background = 0xFFFF;
    infoScreen.backgroundInactive = 0xD71C;
    infoScreen.backgroundDisabled = 0xC67A;
    infoScreen.text = 0x0;
    infoScreen.textHighlight = 0x1F;
    infoScreen.textHighlightText = 0xFFFF;
    infoScreen.textInactive = 0xD71C;
    infoScreen.textDisabled = 0x8C92;

    laScheme_Initialize(&WhiteScheme, GFX_COLOR_MODE_RGB_565);
    WhiteScheme.base = 0xC67A;
    WhiteScheme.highlight = 0xC67A;
    WhiteScheme.highlightLight = 0xFFFF;
    WhiteScheme.shadow = 0x8410;
    WhiteScheme.shadowDark = 0x4208;
    WhiteScheme.foreground = 0x0;
    WhiteScheme.foregroundInactive = 0xD71C;
    WhiteScheme.foregroundDisabled = 0x8410;
    WhiteScheme.background = 0xFFFF;
    WhiteScheme.backgroundInactive = 0xD71C;
    WhiteScheme.backgroundDisabled = 0xC67A;
    WhiteScheme.text = 0x0;
    WhiteScheme.textHighlight = 0x1F;
    WhiteScheme.textHighlightText = 0xFFFF;
    WhiteScheme.textInactive = 0xD71C;
    WhiteScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&YellowScheme, GFX_COLOR_MODE_RGB_565);
    YellowScheme.base = 0xC67A;
    YellowScheme.highlight = 0xC67A;
    YellowScheme.highlightLight = 0xFFFF;
    YellowScheme.shadow = 0x8410;
    YellowScheme.shadowDark = 0x4208;
    YellowScheme.foreground = 0xFFE0;
    YellowScheme.foregroundInactive = 0xD71C;
    YellowScheme.foregroundDisabled = 0x8410;
    YellowScheme.background = 0xFFFF;
    YellowScheme.backgroundInactive = 0xD71C;
    YellowScheme.backgroundDisabled = 0xC67A;
    YellowScheme.text = 0x0;
    YellowScheme.textHighlight = 0x1F;
    YellowScheme.textHighlightText = 0xFFFF;
    YellowScheme.textInactive = 0xD71C;
    YellowScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&clockScheme, GFX_COLOR_MODE_RGB_565);
    clockScheme.base = 0xC67A;
    clockScheme.highlight = 0xC67A;
    clockScheme.highlightLight = 0xFFFF;
    clockScheme.shadow = 0x8410;
    clockScheme.shadowDark = 0x4208;
    clockScheme.foreground = 0x7FF;
    clockScheme.foregroundInactive = 0x7FF;
    clockScheme.foregroundDisabled = 0x8410;
    clockScheme.background = 0x0;
    clockScheme.backgroundInactive = 0xD71C;
    clockScheme.backgroundDisabled = 0xC67A;
    clockScheme.text = 0x7FF;
    clockScheme.textHighlight = 0x1F;
    clockScheme.textHighlightText = 0xFFFF;
    clockScheme.textInactive = 0xD71C;
    clockScheme.textDisabled = 0x8C92;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    laContext_SetStringTable(&stringTable);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_SplashScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_homeScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_controllerScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_infoScreen);
    laContext_AddScreen(screen);

    laContext_SetActiveScreen(3);

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
    laWidget_SetScheme((laWidget*)HarmonyLogoWidget, &helpScheme);
    laWidget_SetBackgroundType((laWidget*)HarmonyLogoWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)HarmonyLogoWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(HarmonyLogoWidget, &HarmonyLogo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)HarmonyLogoWidget);

    PanelWidget = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget, 0, 207);
    laWidget_SetSize((laWidget*)PanelWidget, 480, 65);
    laWidget_SetOptimizationFlags((laWidget*)PanelWidget, LA_WIDGET_OPT_DRAW_ONCE);
    laWidget_SetScheme((laWidget*)PanelWidget, &helpScheme);
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

static void ScreenCreate_homeScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &clockScheme);
    laLayer_SetBufferCount(layer0, 1);

    laScreen_SetLayer(screen, 0, layer0);

    ButtonWidget1 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget1, 409, 6);
    laWidget_SetSize((laWidget*)ButtonWidget1, 64, 72);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget1, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedImage(ButtonWidget1, &info);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget1, &ButtonWidget1_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget1);

    centerClockLabel = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)centerClockLabel, 147, 108);
    laWidget_SetSize((laWidget*)centerClockLabel, 185, 97);
    laWidget_SetScheme((laWidget*)centerClockLabel, &clockScheme);
    laWidget_SetBackgroundType((laWidget*)centerClockLabel, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)centerClockLabel, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(centerClockLabel, laString_CreateFromID(string_centerClock));
    laLabelWidget_SetHAlignment(centerClockLabel, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)centerClockLabel);

    ImageWidget3 = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget3, 197, 87);
    laWidget_SetBackgroundType((laWidget*)ImageWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget3, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget3, &brickovenlogo1);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget3);

    LabelWidget4 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget4, 126, 247);
    laWidget_SetSize((laWidget*)LabelWidget4, 232, 25);
    laWidget_SetScheme((laWidget*)LabelWidget4, &controllerTitle);
    laWidget_SetBackgroundType((laWidget*)LabelWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget4, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget4, laString_CreateFromID(string_press));
    laLabelWidget_SetHAlignment(LabelWidget4, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget4);

    StartButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)StartButton, 36, 41);
    laWidget_SetSize((laWidget*)StartButton, 378, 202);
    laWidget_SetBackgroundType((laWidget*)StartButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)StartButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedEventCallback(StartButton, &StartButton_PressedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)StartButton);

}

static void ScreenCreate_controllerScreen(laScreen* screen)
{
    laLayer* layer0;

    laScreen_SetShowEventCallback(screen, &controllerScreen_ShowEvent);

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &clockScheme);
    laLayer_SetBufferCount(layer0, 1);

    laScreen_SetLayer(screen, 0, layer0);

    TimeLabel = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)TimeLabel, 215, 5);
    laWidget_SetSize((laWidget*)TimeLabel, 53, 25);
    laWidget_SetScheme((laWidget*)TimeLabel, &clockScheme);
    laWidget_SetBackgroundType((laWidget*)TimeLabel, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TimeLabel, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(TimeLabel, laString_CreateFromID(string_upperClock));
    laLabelWidget_SetHAlignment(TimeLabel, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)TimeLabel);

    HomeButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)HomeButton, 406, 2);
    laWidget_SetSize((laWidget*)HomeButton, 72, 71);
    laWidget_SetBackgroundType((laWidget*)HomeButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)HomeButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetReleasedImage(HomeButton, &asset);
    laButtonWidget_SetReleasedEventCallback(HomeButton, &HomeButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)HomeButton);

    FishButtonWidget = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)FishButtonWidget, 92, 80);
    laWidget_SetSize((laWidget*)FishButtonWidget, 92, 92);
    laWidget_SetBackgroundType((laWidget*)FishButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)FishButtonWidget, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(FishButtonWidget, &FishButtonWidget_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)FishButtonWidget);

    PizzaButtonWidget = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)PizzaButtonWidget, 194, 80);
    laWidget_SetSize((laWidget*)PizzaButtonWidget, 92, 92);
    laWidget_SetBackgroundType((laWidget*)PizzaButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PizzaButtonWidget, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(PizzaButtonWidget, &PizzaButtonWidget_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)PizzaButtonWidget);

    VegeButtonWidget = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)VegeButtonWidget, 298, 80);
    laWidget_SetSize((laWidget*)VegeButtonWidget, 92, 92);
    laWidget_SetBackgroundType((laWidget*)VegeButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)VegeButtonWidget, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(VegeButtonWidget, &VegeButtonWidget_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)VegeButtonWidget);

    StartStopButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)StartStopButton, 189, 213);
    laWidget_SetSize((laWidget*)StartStopButton, 90, 51);
    laWidget_SetScheme((laWidget*)StartStopButton, &SettingsScheme);
    laWidget_SetBackgroundType((laWidget*)StartStopButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)StartStopButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetToggleable(StartStopButton, LA_TRUE);
    laButtonWidget_SetPressedImage(StartStopButton, &cancel);
    laButtonWidget_SetReleasedImage(StartStopButton, &start);
    laButtonWidget_SetPressedEventCallback(StartStopButton, &StartStopButton_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(StartStopButton, &StartStopButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)StartStopButton);

    DoneButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)DoneButton, 189, 213);
    laWidget_SetSize((laWidget*)DoneButton, 90, 51);
    laWidget_SetVisible((laWidget*)DoneButton, LA_FALSE);
    laWidget_SetScheme((laWidget*)DoneButton, &SettingsScheme);
    laWidget_SetBackgroundType((laWidget*)DoneButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)DoneButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(DoneButton, &done);
    laButtonWidget_SetReleasedImage(DoneButton, &done);
    laButtonWidget_SetReleasedEventCallback(DoneButton, &DoneButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)DoneButton);

    FishGaugeWidget = laCircularGaugeWidget_New();
    laWidget_SetPosition((laWidget*)FishGaugeWidget, 4, 176);
    laWidget_SetSize((laWidget*)FishGaugeWidget, 101, 90);
    laWidget_SetVisible((laWidget*)FishGaugeWidget, LA_FALSE);
    laWidget_SetScheme((laWidget*)FishGaugeWidget, &clockScheme);
    laWidget_SetBackgroundType((laWidget*)FishGaugeWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)FishGaugeWidget, LA_WIDGET_BORDER_NONE);
    laCircularGaugeWidget_SetRadius(FishGaugeWidget, 40);
    laCircularGaugeWidget_SetStartAngle(FishGaugeWidget, 90);
    laCircularGaugeWidget_SetCenterAngle(FishGaugeWidget, 360);
    laCircularGaugeWidget_SetEndValue(FishGaugeWidget, 180);
    laCircularGaugeWidget_SetValue(FishGaugeWidget, 120);
    laCircularGaugeWidget_SetTickValue(FishGaugeWidget, 15);
    laCircularGaugeWidget_SetHandRadius(FishGaugeWidget, 30);
    laCircularGaugeWidget_AddValueArc(FishGaugeWidget, 0, 40, 35, 6, &GreenScheme);
    laCircularGaugeWidget_AddValueArc(FishGaugeWidget, 30, 80, 35, 6, &YellowScheme);
    laCircularGaugeWidget_AddValueArc(FishGaugeWidget, 80, 120, 35, 6, &RedScheme);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)FishGaugeWidget);

    PizzaGaugeWidget = laCircularGaugeWidget_New();
    laWidget_SetPosition((laWidget*)PizzaGaugeWidget, 4, 176);
    laWidget_SetSize((laWidget*)PizzaGaugeWidget, 101, 90);
    laWidget_SetVisible((laWidget*)PizzaGaugeWidget, LA_FALSE);
    laWidget_SetScheme((laWidget*)PizzaGaugeWidget, &clockScheme);
    laWidget_SetBackgroundType((laWidget*)PizzaGaugeWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PizzaGaugeWidget, LA_WIDGET_BORDER_NONE);
    laCircularGaugeWidget_SetRadius(PizzaGaugeWidget, 40);
    laCircularGaugeWidget_SetStartAngle(PizzaGaugeWidget, 90);
    laCircularGaugeWidget_SetCenterAngle(PizzaGaugeWidget, 360);
    laCircularGaugeWidget_SetEndValue(PizzaGaugeWidget, 180);
    laCircularGaugeWidget_SetValue(PizzaGaugeWidget, 86);
    laCircularGaugeWidget_SetTickValue(PizzaGaugeWidget, 15);
    laCircularGaugeWidget_SetHandRadius(PizzaGaugeWidget, 30);
    laCircularGaugeWidget_AddValueArc(PizzaGaugeWidget, 0, 30, 35, 6, &GreenScheme);
    laCircularGaugeWidget_AddValueArc(PizzaGaugeWidget, 30, 60, 35, 6, &YellowScheme);
    laCircularGaugeWidget_AddValueArc(PizzaGaugeWidget, 60, 86, 35, 6, &RedScheme);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)PizzaGaugeWidget);

    TurkeyGaugeWidget = laCircularGaugeWidget_New();
    laWidget_SetPosition((laWidget*)TurkeyGaugeWidget, 4, 176);
    laWidget_SetSize((laWidget*)TurkeyGaugeWidget, 101, 90);
    laWidget_SetVisible((laWidget*)TurkeyGaugeWidget, LA_FALSE);
    laWidget_SetScheme((laWidget*)TurkeyGaugeWidget, &clockScheme);
    laWidget_SetBackgroundType((laWidget*)TurkeyGaugeWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TurkeyGaugeWidget, LA_WIDGET_BORDER_NONE);
    laCircularGaugeWidget_SetRadius(TurkeyGaugeWidget, 40);
    laCircularGaugeWidget_SetStartAngle(TurkeyGaugeWidget, 90);
    laCircularGaugeWidget_SetCenterAngle(TurkeyGaugeWidget, 360);
    laCircularGaugeWidget_SetEndValue(TurkeyGaugeWidget, 180);
    laCircularGaugeWidget_SetValue(TurkeyGaugeWidget, 160);
    laCircularGaugeWidget_SetTickValue(TurkeyGaugeWidget, 15);
    laCircularGaugeWidget_SetHandRadius(TurkeyGaugeWidget, 30);
    laCircularGaugeWidget_AddValueArc(TurkeyGaugeWidget, 0, 60, 35, 6, &GreenScheme);
    laCircularGaugeWidget_AddValueArc(TurkeyGaugeWidget, 60, 110, 35, 6, &YellowScheme);
    laCircularGaugeWidget_AddValueArc(TurkeyGaugeWidget, 110, 160, 35, 6, &RedScheme);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)TurkeyGaugeWidget);

    Flames = laImageSequenceWidget_New();
    laWidget_SetPosition((laWidget*)Flames, 400, 97);
    laWidget_SetSize((laWidget*)Flames, 60, 163);
    laWidget_SetVisible((laWidget*)Flames, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)Flames, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)Flames, LA_WIDGET_BORDER_NONE);
    laImageSequenceWidget_SetImageCount(Flames, 9);
    laImageSequenceWidget_SetImage(Flames, 0, &smoke10);
    laImageSequenceWidget_SetImageDelay(Flames, 0, 50);
    laImageSequenceWidget_SetImageVAlignment(Flames, 0, LA_VALIGN_BOTTOM);
    laImageSequenceWidget_SetImage(Flames, 1, &smoke2);
    laImageSequenceWidget_SetImageDelay(Flames, 1, 50);
    laImageSequenceWidget_SetImageVAlignment(Flames, 1, LA_VALIGN_BOTTOM);
    laImageSequenceWidget_SetImage(Flames, 2, &smoke3);
    laImageSequenceWidget_SetImageDelay(Flames, 2, 50);
    laImageSequenceWidget_SetImageVAlignment(Flames, 2, LA_VALIGN_BOTTOM);
    laImageSequenceWidget_SetImage(Flames, 3, &smoke4);
    laImageSequenceWidget_SetImageDelay(Flames, 3, 50);
    laImageSequenceWidget_SetImageVAlignment(Flames, 3, LA_VALIGN_BOTTOM);
    laImageSequenceWidget_SetImage(Flames, 4, &smoke5);
    laImageSequenceWidget_SetImageDelay(Flames, 4, 50);
    laImageSequenceWidget_SetImageVAlignment(Flames, 4, LA_VALIGN_BOTTOM);
    laImageSequenceWidget_SetImage(Flames, 5, &smoke6);
    laImageSequenceWidget_SetImageDelay(Flames, 5, 50);
    laImageSequenceWidget_SetImageVAlignment(Flames, 5, LA_VALIGN_BOTTOM);
    laImageSequenceWidget_SetImage(Flames, 6, &smoke7);
    laImageSequenceWidget_SetImageDelay(Flames, 6, 50);
    laImageSequenceWidget_SetImageVAlignment(Flames, 6, LA_VALIGN_BOTTOM);
    laImageSequenceWidget_SetImage(Flames, 7, &smoke8);
    laImageSequenceWidget_SetImageDelay(Flames, 7, 50);
    laImageSequenceWidget_SetImageVAlignment(Flames, 7, LA_VALIGN_BOTTOM);
    laImageSequenceWidget_SetImage(Flames, 8, &smoke9);
    laImageSequenceWidget_SetImageDelay(Flames, 8, 50);
    laImageSequenceWidget_SetImageVAlignment(Flames, 8, LA_VALIGN_BOTTOM);
    laImageSequenceWidget_SetRepeat(Flames, LA_TRUE);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)Flames);

}

static void ScreenCreate_infoScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &clockScheme);
    laLayer_SetBufferCount(layer0, 1);

    laScreen_SetLayer(screen, 0, layer0);

    LabelWidget15 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget15, 19, 9);
    laWidget_SetSize((laWidget*)LabelWidget15, 57, 35);
    laWidget_SetScheme((laWidget*)LabelWidget15, &clockScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget15, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget15, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget15, laString_CreateFromID(string_upperClock));
    laLabelWidget_SetHAlignment(LabelWidget15, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget15);

    ButtonWidget16 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget16, 418, 3);
    laWidget_SetSize((laWidget*)ButtonWidget16, 56, 61);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget16, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget16, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetReleasedImage(ButtonWidget16, &asset);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget16, &ButtonWidget16_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget16);

    LabelWidget17 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget17, 71, 11);
    laWidget_SetSize((laWidget*)LabelWidget17, 203, 30);
    laWidget_SetScheme((laWidget*)LabelWidget17, &helpScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget17, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelWidget17, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget17, laString_CreateFromID(string_timeHelp));
    laLabelWidget_SetHAlignment(LabelWidget17, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget17);

    LabelWidget18 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget18, 346, 56);
    laWidget_SetSize((laWidget*)LabelWidget18, 125, 30);
    laWidget_SetScheme((laWidget*)LabelWidget18, &helpScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget18, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelWidget18, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget18, laString_CreateFromID(string_returnHome));
    laLabelWidget_SetHAlignment(LabelWidget18, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget18);

    LabelWidget19 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget19, 69, 86);
    laWidget_SetSize((laWidget*)LabelWidget19, 134, 35);
    laWidget_SetScheme((laWidget*)LabelWidget19, &helpScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget19, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelWidget19, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget19, laString_CreateFromID(string_information));
    laLabelWidget_SetHAlignment(LabelWidget19, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget19);

    LabelWidget20 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget20, 297, 181);
    laWidget_SetSize((laWidget*)LabelWidget20, 144, 30);
    laWidget_SetScheme((laWidget*)LabelWidget20, &helpScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget20, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelWidget20, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget20, laString_CreateFromID(string_options));
    laLabelWidget_SetHAlignment(LabelWidget20, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget20);

    LabelWidget21 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget21, 373, 139);
    laWidget_SetSize((laWidget*)LabelWidget21, 100, 25);
    laWidget_SetScheme((laWidget*)LabelWidget21, &helpScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget21, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelWidget21, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget21, laString_CreateFromID(string_cookTimer));
    laLabelWidget_SetHAlignment(LabelWidget21, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget21);

    CircularGaugeWidget22 = laCircularGaugeWidget_New();
    laWidget_SetPosition((laWidget*)CircularGaugeWidget22, 288, 93);
    laWidget_SetSize((laWidget*)CircularGaugeWidget22, 71, 75);
    laWidget_SetScheme((laWidget*)CircularGaugeWidget22, &clockScheme);
    laWidget_SetBackgroundType((laWidget*)CircularGaugeWidget22, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CircularGaugeWidget22, LA_WIDGET_BORDER_NONE);
    laCircularGaugeWidget_SetRadius(CircularGaugeWidget22, 30);
    laCircularGaugeWidget_SetStartAngle(CircularGaugeWidget22, 90);
    laCircularGaugeWidget_SetCenterAngle(CircularGaugeWidget22, 360);
    laCircularGaugeWidget_SetEndValue(CircularGaugeWidget22, 180);
    laCircularGaugeWidget_SetValue(CircularGaugeWidget22, 120);
    laCircularGaugeWidget_SetTickValue(CircularGaugeWidget22, 15);
    laCircularGaugeWidget_SetHandRadius(CircularGaugeWidget22, 20);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)CircularGaugeWidget22);

    LabelWidget23 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget23, 315, 232);
    laWidget_SetSize((laWidget*)LabelWidget23, 149, 30);
    laWidget_SetScheme((laWidget*)LabelWidget23, &helpScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget23, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelWidget23, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget23, laString_CreateFromID(string_controls));
    laLabelWidget_SetHAlignment(LabelWidget23, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget23);

    ImageWidget24 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget24, 17, 127);
    laWidget_SetSize((laWidget*)ImageWidget24, 80, 73);
    laWidget_SetBackgroundType((laWidget*)ImageWidget24, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget24, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget24, &menufish);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget24);

    ImageWidget25 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget25, 106, 126);
    laWidget_SetSize((laWidget*)ImageWidget25, 80, 74);
    laWidget_SetBackgroundType((laWidget*)ImageWidget25, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageWidget25, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget25, &menuTurkey);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget25);

    ImageWidget26 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget26, 196, 125);
    laWidget_SetSize((laWidget*)ImageWidget26, 83, 74);
    laWidget_SetBackgroundType((laWidget*)ImageWidget26, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget26, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget26, &menuPizza);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget26);

    ImageWidget27 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget27, 3, 218);
    laWidget_SetSize((laWidget*)ImageWidget27, 88, 44);
    laWidget_SetBackgroundType((laWidget*)ImageWidget27, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageWidget27, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget27, &start);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget27);

    ImageWidget28 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget28, 84, 216);
    laWidget_SetSize((laWidget*)ImageWidget28, 87, 39);
    laWidget_SetBackgroundType((laWidget*)ImageWidget28, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget28, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget28, &cancel);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget28);

    ImageWidget29 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget29, 170, 224);
    laWidget_SetSize((laWidget*)ImageWidget29, 82, 33);
    laWidget_SetBackgroundType((laWidget*)ImageWidget29, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget29, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget29, &done);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget29);

    ImageWidget30 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget30, 21, 48);
    laWidget_SetSize((laWidget*)ImageWidget30, 42, 54);
    laWidget_SetBackgroundType((laWidget*)ImageWidget30, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget30, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget30, &info);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget30);

}




