// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

#include "gfx/libaria/libaria_init.h"
#include "gfx/libaria/inc/libaria_utils.h"

laScheme ACButtonScheme;
laScheme ACDialScheme;
laScheme ClearScheme;
laScheme ButtonScheme;
laScheme PhoneListScheme;
laScheme NewScheme;
laScheme WhiteScheme;
laScheme TextScheme;
laScheme RadialMenuScheme;
laScheme VolumeDialScheme;
laImageWidget* ImageWidget1;
laImageWidget* ImageWidget3;
laImageWidget* ImageWidget2;
laImageWidget* ImageWidget4;
laWidget* ClimateControlPanel;
laImageWidget* BackgroundImage;
laButtonWidget* ButtonACFace;
laButtonWidget* ButtonACBoth;
laButtonWidget* ButtonACFeet;
laButtonWidget* ButtonDefrost;
laButtonWidget* ButtonACIntake;
laButtonWidget* ButtonACLoop;
laButtonWidget* ButtonACSync;
laLabelWidget* LabelSync;
laCircularSliderWidget* CircularSliderACRight;
laCircularSliderWidget* CircularSliderACLeft;
laWidget* PhonePanel;
laTextFieldWidget* TextFieldPhone;
laButtonWidget* ButtonBackspace;
laLabelWidget* LabelBackspace;
laButtonWidget* ButtonCall;
laImageWidget* ImagePhoneIcon;
laWidget* PhoneKeyPadPanel;
laButtonWidget* ButtonPhone1;
laButtonWidget* ButtonPhone2;
laLabelWidget* LabelNumber2;
laButtonWidget* ButtonPhone3;
laLabelWidget* LabelNumber3;
laButtonWidget* ButtonPhone4;
laLabelWidget* LabelNumber4;
laButtonWidget* ButtonPhone5;
laLabelWidget* LabelNumber5;
laButtonWidget* ButtonPhone6;
laLabelWidget* LabelNumber6;
laButtonWidget* ButtonPhone7;
laLabelWidget* LabelNumber7;
laButtonWidget* ButtonPhone8;
laLabelWidget* LabelNumber8;
laButtonWidget* ButtonPhone9;
laLabelWidget* LabelNumber9;
laButtonWidget* ButtonPhoneStar;
laButtonWidget* ButtonPhone0;
laLabelWidget* LabelNumber0;
laButtonWidget* ButtonPhonePound;
laListWidget* ListContacts;
laWidget* BluetoothPanel;
laButtonWidget* ButtonBluetoothPhone1;
laImageWidget* ImageSelectBluetoothDevice1;
laImageWidget* ImageBluetoothDevice1;
laLabelWidget* LabelPhone1;
laButtonWidget* ButtonBluetoothPhone2;
laImageWidget* ImageSelectBluetoothDevice2;
laImageWidget* ImageBluetoohDevice2;
laLabelWidget* LabelPhone2;
laWidget* NavPanel;
laImagePlusWidget* NavMap;
laWidget* BottomPanel;
laLabelWidget* LabelDistance;
laLabelWidget* LabelTravelTime;
laLabelWidget* LabelETA;
laButtonWidget* ButtonNavRead;
laWidget* MusicPanel;
laRadialMenuWidget* MusicSelector;
laImagePlusWidget* MusicSelector_Item0;
laImagePlusWidget* MusicSelector_Item1;
laImagePlusWidget* MusicSelector_Item2;
laImagePlusWidget* MusicSelector_Item3;
laImagePlusWidget* MusicSelector_Item4;
laImagePlusWidget* MusicSelector_Item5;
laImagePlusWidget* MusicSelector_Item6;
laImagePlusWidget* MusicSelector_Item7;
laImagePlusWidget* MusicSelector_Item8;
laImagePlusWidget* MusicSelector_Item9;
laButtonWidget* ButtonShuffle;
laButtonWidget* ButtonPlayPause;
laButtonWidget* ButtonNextTrack;
laImageWidget* ImageVolumeIcon;
laButtonWidget* ButtonVolumeUp;
laButtonWidget* ButtonVolumeDown;
laLineWidget* MusicLine;
laWidget* MusicPosition;
laButtonWidget* ButtonMusicReceiver;
laWidget* IconPanel;
laImageSequenceWidget* CellSignal;
laImageSequenceWidget* BatteryPower;
laImageSequenceWidget* WifiSignal;
laLabelWidget* LabelClock;
laImageWidget* ImageMCHPLogo;
laLabelWidget* LabelACTempLeft;
laLabelWidget* LabelCelciusLeft;
laLabelWidget* LabelACTempRight;
laLabelWidget* LabelCelciusRight;
laWidget* LeftTrayPanel;
laButtonWidget* LeftTrayLid;
laImageWidget* LeftLidArrow;
laWidget* PanelWidget;
laRadialMenuWidget* ModeSelector;
laImagePlusWidget* ModeSelector_Item0;
laImagePlusWidget* ModeSelector_Item1;
laImagePlusWidget* ModeSelector_Item2;
laImagePlusWidget* ModeSelector_Item3;
laImagePlusWidget* ModeSelector_Item4;
laWidget* RightTrayPanel;
laWidget* RightButtonPanel;
laButtonWidget* ButtonGPU;
laLabelWidget* LabelGPU;
laButtonWidget* ButtonInfo;
laImageWidget* ImageTrunk;
laButtonWidget* RightTrayLid;
laImageWidget* RightLidArrow;
laWidget* PanelUpChevron;
laButtonWidget* ButtonChevronUp;
laWidget* PanelDownChevron;
laButtonWidget* ButtonChevronDown;
laImageWidget* InfoPageHarmonyLogo;
laImageWidget* ImageWidget7;
laWidget* InfoTextDragPanel;
laImageWidget* InfoText;
laWidget* PanelWidget1;
laLabelWidget* TextTitle;
laButtonWidget* ReturnToMainButton;
laButtonWidget* ButtonSplashScreen;


static void ScreenCreate_SplashScreen(laScreen* screen);
static void ScreenCreate_MainScreen(laScreen* screen);
static void ScreenCreate_InfoScreen(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&ACButtonScheme, GFX_COLOR_MODE_RGBA_8888);
    ACButtonScheme.base = 0xE0E0E0FF;
    ACButtonScheme.highlight = 0xC8D0D4FF;
    ACButtonScheme.highlightLight = 0xFFFFFFFF;
    ACButtonScheme.shadow = 0x808080FF;
    ACButtonScheme.shadowDark = 0x404040FF;
    ACButtonScheme.foreground = 0xC0C0C0FF;
    ACButtonScheme.foregroundInactive = 0xD6E3E7FF;
    ACButtonScheme.foregroundDisabled = 0x808080FF;
    ACButtonScheme.background = 0xFFFFFFFF;
    ACButtonScheme.backgroundInactive = 0xD6E3E7FF;
    ACButtonScheme.backgroundDisabled = 0xC8D0D4FF;
    ACButtonScheme.text = 0xFF;
    ACButtonScheme.textHighlight = 0xFFFF;
    ACButtonScheme.textHighlightText = 0xFFFFFFFF;
    ACButtonScheme.textInactive = 0xD6E3E7FF;
    ACButtonScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&ACDialScheme, GFX_COLOR_MODE_RGBA_8888);
    ACDialScheme.base = 0x828282FF;
    ACDialScheme.highlight = 0xC8D0D4FF;
    ACDialScheme.highlightLight = 0xFFFFFFFF;
    ACDialScheme.shadow = 0x808080FF;
    ACDialScheme.shadowDark = 0x404040FF;
    ACDialScheme.foreground = 0x5986FFFF;
    ACDialScheme.foregroundInactive = 0xFF5151FF;
    ACDialScheme.foregroundDisabled = 0x808080FF;
    ACDialScheme.background = 0xFFFFFFFF;
    ACDialScheme.backgroundInactive = 0xD6E3E7FF;
    ACDialScheme.backgroundDisabled = 0xFF0000FF;
    ACDialScheme.text = 0xFF;
    ACDialScheme.textHighlight = 0xFFFF;
    ACDialScheme.textHighlightText = 0xFFFFFFFF;
    ACDialScheme.textInactive = 0xD6E3E7FF;
    ACDialScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&ClearScheme, GFX_COLOR_MODE_RGBA_8888);
    ClearScheme.base = 0xFFFFFF00;
    ClearScheme.highlight = 0xFFFFFF00;
    ClearScheme.highlightLight = 0xFFFFFF00;
    ClearScheme.shadow = 0xFFFFFF00;
    ClearScheme.shadowDark = 0xFFFFFF00;
    ClearScheme.foreground = 0xFFFFFF00;
    ClearScheme.foregroundInactive = 0xFFFFFF00;
    ClearScheme.foregroundDisabled = 0xFFFFFF00;
    ClearScheme.background = 0xFFFFFF00;
    ClearScheme.backgroundInactive = 0xFFFFFF00;
    ClearScheme.backgroundDisabled = 0xFFFFFF00;
    ClearScheme.text = 0x828282FF;
    ClearScheme.textHighlight = 0xFFFFFF00;
    ClearScheme.textHighlightText = 0xFFFFFF00;
    ClearScheme.textInactive = 0xFFFFFF00;
    ClearScheme.textDisabled = 0xFFFFFF00;

    laScheme_Initialize(&ButtonScheme, GFX_COLOR_MODE_RGBA_8888);
    ButtonScheme.base = 0xFFFFFFFF;
    ButtonScheme.highlight = 0xC8D0D4FF;
    ButtonScheme.highlightLight = 0xFFFFFFFF;
    ButtonScheme.shadow = 0x808080FF;
    ButtonScheme.shadowDark = 0x404040FF;
    ButtonScheme.foreground = 0xC0C0C0FF;
    ButtonScheme.foregroundInactive = 0xD6E3E7FF;
    ButtonScheme.foregroundDisabled = 0x808080FF;
    ButtonScheme.background = 0xFFFFFFFF;
    ButtonScheme.backgroundInactive = 0xD6E3E7FF;
    ButtonScheme.backgroundDisabled = 0xC8D0D4FF;
    ButtonScheme.text = 0xFF;
    ButtonScheme.textHighlight = 0xFFFF;
    ButtonScheme.textHighlightText = 0xFFFFFFFF;
    ButtonScheme.textInactive = 0xD6E3E7FF;
    ButtonScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&PhoneListScheme, GFX_COLOR_MODE_RGBA_8888);
    PhoneListScheme.base = 0xFFFFFFFF;
    PhoneListScheme.highlight = 0xFFFFFFFF;
    PhoneListScheme.highlightLight = 0xFFFFFFFF;
    PhoneListScheme.shadow = 0xFFFFFFFF;
    PhoneListScheme.shadowDark = 0x808080FF;
    PhoneListScheme.foreground = 0xFFFFFFFF;
    PhoneListScheme.foregroundInactive = 0xFFFFFFFF;
    PhoneListScheme.foregroundDisabled = 0xFFFFFFFF;
    PhoneListScheme.background = 0xFFFFFFFF;
    PhoneListScheme.backgroundInactive = 0xFFFFFFFF;
    PhoneListScheme.backgroundDisabled = 0xFFFFFFFF;
    PhoneListScheme.text = 0x808080FF;
    PhoneListScheme.textHighlight = 0x808080FF;
    PhoneListScheme.textHighlightText = 0xE0E0E0FF;
    PhoneListScheme.textInactive = 0xFFFFFFFF;
    PhoneListScheme.textDisabled = 0xFFFFFFFF;

    laScheme_Initialize(&NewScheme, GFX_COLOR_MODE_RGBA_8888);
    NewScheme.base = 0xC8D0D4FF;
    NewScheme.highlight = 0xC8D0D4FF;
    NewScheme.highlightLight = 0xFFFFFFFF;
    NewScheme.shadow = 0x808080FF;
    NewScheme.shadowDark = 0x404040FF;
    NewScheme.foreground = 0xFF;
    NewScheme.foregroundInactive = 0xD6E3E7FF;
    NewScheme.foregroundDisabled = 0x808080FF;
    NewScheme.background = 0xFFFFFFFF;
    NewScheme.backgroundInactive = 0xD6E3E7FF;
    NewScheme.backgroundDisabled = 0xC8D0D4FF;
    NewScheme.text = 0xFF;
    NewScheme.textHighlight = 0xFFFF;
    NewScheme.textHighlightText = 0xFFFFFFFF;
    NewScheme.textInactive = 0xD6E3E7FF;
    NewScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&WhiteScheme, GFX_COLOR_MODE_RGBA_8888);
    WhiteScheme.base = 0xFFFFFFFF;
    WhiteScheme.highlight = 0xFFFFFFFF;
    WhiteScheme.highlightLight = 0xFFFFFFFF;
    WhiteScheme.shadow = 0xFFFFFFFF;
    WhiteScheme.shadowDark = 0xFFFFFFFF;
    WhiteScheme.foreground = 0xFFFFFFFF;
    WhiteScheme.foregroundInactive = 0xFFFFFFFF;
    WhiteScheme.foregroundDisabled = 0xFFFFFFFF;
    WhiteScheme.background = 0xFFFFFFFF;
    WhiteScheme.backgroundInactive = 0xFFFFFFFF;
    WhiteScheme.backgroundDisabled = 0xFFFFFFFF;
    WhiteScheme.text = 0xFFFFFFFF;
    WhiteScheme.textHighlight = 0xFFFFFFFF;
    WhiteScheme.textHighlightText = 0xFFFFFFFF;
    WhiteScheme.textInactive = 0xFFFFFFFF;
    WhiteScheme.textDisabled = 0xFFFFFFFF;

    laScheme_Initialize(&TextScheme, GFX_COLOR_MODE_RGBA_8888);
    TextScheme.base = 0xFFFFFFFF;
    TextScheme.highlight = 0xFFFFFFFF;
    TextScheme.highlightLight = 0xFFFFFFFF;
    TextScheme.shadow = 0xFFFFFFFF;
    TextScheme.shadowDark = 0x808080FF;
    TextScheme.foreground = 0xFFFFFFFF;
    TextScheme.foregroundInactive = 0xFFFFFFFF;
    TextScheme.foregroundDisabled = 0xFFFFFFFF;
    TextScheme.background = 0xFFFFFFFF;
    TextScheme.backgroundInactive = 0xFFFFFFFF;
    TextScheme.backgroundDisabled = 0xFFFFFFFF;
    TextScheme.text = 0x818285FF;
    TextScheme.textHighlight = 0x808080FF;
    TextScheme.textHighlightText = 0xFFFFFFFF;
    TextScheme.textInactive = 0xFFFFFFFF;
    TextScheme.textDisabled = 0xFFFFFFFF;

    laScheme_Initialize(&RadialMenuScheme, GFX_COLOR_MODE_RGBA_8888);
    RadialMenuScheme.base = 0xFFFFFFFF;
    RadialMenuScheme.highlight = 0xFFFFFFFF;
    RadialMenuScheme.highlightLight = 0xFFFFFFFF;
    RadialMenuScheme.shadow = 0xFFFFFFFF;
    RadialMenuScheme.shadowDark = 0xFFFFFFFF;
    RadialMenuScheme.foreground = 0xFFFFFFFF;
    RadialMenuScheme.foregroundInactive = 0xFFFFFFFF;
    RadialMenuScheme.foregroundDisabled = 0xFFFFFFFF;
    RadialMenuScheme.background = 0xFFFFFFFF;
    RadialMenuScheme.backgroundInactive = 0xFFFFFFFF;
    RadialMenuScheme.backgroundDisabled = 0xFFFFFFFF;
    RadialMenuScheme.text = 0xFFFFFFFF;
    RadialMenuScheme.textHighlight = 0xFFFFFFFF;
    RadialMenuScheme.textHighlightText = 0xFFFFFFFF;
    RadialMenuScheme.textInactive = 0xFFFFFFFF;
    RadialMenuScheme.textDisabled = 0xFFFFFFFF;

    laScheme_Initialize(&VolumeDialScheme, GFX_COLOR_MODE_RGBA_8888);
    VolumeDialScheme.base = 0x828282FF;
    VolumeDialScheme.highlight = 0xC8D0D4FF;
    VolumeDialScheme.highlightLight = 0xFFFFFFFF;
    VolumeDialScheme.shadow = 0x808080FF;
    VolumeDialScheme.shadowDark = 0x404040FF;
    VolumeDialScheme.foreground = 0xE0E0E0FF;
    VolumeDialScheme.foregroundInactive = 0x808080FF;
    VolumeDialScheme.foregroundDisabled = 0x808080FF;
    VolumeDialScheme.background = 0xFFFFFFFF;
    VolumeDialScheme.backgroundInactive = 0xD6E3E7FF;
    VolumeDialScheme.backgroundDisabled = 0xFF0000FF;
    VolumeDialScheme.text = 0xFF;
    VolumeDialScheme.textHighlight = 0xFFFF;
    VolumeDialScheme.textHighlightText = 0xFFFFFFFF;
    VolumeDialScheme.textInactive = 0xD6E3E7FF;
    VolumeDialScheme.textDisabled = 0x8C9294FF;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    laContext_SetStringTable(&stringTable);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_SplashScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_MainScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_InfoScreen);
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

    ImageWidget1 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget1, 120, 89);
    laWidget_SetSize((laWidget*)ImageWidget1, 240, 62);
    laWidget_SetBackgroundType((laWidget*)ImageWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget1, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget1, &PIC32Logo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget1);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0xFF);
    laLayer_SetMaskEnable(layer1, LA_TRUE);
    laLayer_SetMaskColor(layer1, 0xFFFFFFFF);

    laScreen_SetLayer(screen, 1, layer1);

    ImageWidget3 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget3, 480, 207);
    laWidget_SetSize((laWidget*)ImageWidget3, 480, 65);
    laWidget_SetBackgroundType((laWidget*)ImageWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget3, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget3, &Bar);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)ImageWidget3);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x0);

    laScreen_SetLayer(screen, 2, layer2);

    ImageWidget2 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget2, 144, 42);
    laWidget_SetSize((laWidget*)ImageWidget2, 197, 139);
    laWidget_SetBackgroundType((laWidget*)ImageWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget2, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget2, &HarmonyLogo);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)ImageWidget2);

    ImageWidget4 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget4, 13, 225);
    laWidget_SetSize((laWidget*)ImageWidget4, 144, 39);
    laWidget_SetBackgroundType((laWidget*)ImageWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget4, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget4, &MicrochipLogo);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)ImageWidget4);

}

static void ScreenCreate_MainScreen(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &WhiteScheme);
    laLayer_SetBufferCount(layer0, 2);
    laLayer_SetAlphaEnable(layer0, LA_TRUE);
    laLayer_SetAlphaAmount(layer0, 0x0);

    laScreen_SetLayer(screen, 0, layer0);

    ClimateControlPanel = laWidget_New();
    laWidget_SetPosition((laWidget*)ClimateControlPanel, 0, 30);
    laWidget_SetSize((laWidget*)ClimateControlPanel, 480, 242);
    laWidget_SetScheme((laWidget*)ClimateControlPanel, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ClimateControlPanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ClimateControlPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, ClimateControlPanel);

    BackgroundImage = laImageWidget_New();
    laWidget_SetPosition((laWidget*)BackgroundImage, 176, 6);
    laWidget_SetSize((laWidget*)BackgroundImage, 128, 188);
    laWidget_SetBackgroundType((laWidget*)BackgroundImage, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)BackgroundImage, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(BackgroundImage, &Background);
    laWidget_AddChild((laWidget*)ClimateControlPanel, (laWidget*)BackgroundImage);

    ButtonACFace = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonACFace, 4, 3);
    laWidget_SetSize((laWidget*)ButtonACFace, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonACFace, &ButtonScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonACFace, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonACFace, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonACFace, &AC_Face);
    laButtonWidget_SetReleasedImage(ButtonACFace, &AC_Face);
    laButtonWidget_SetPressedEventCallback(ButtonACFace, &ButtonACFace_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(ButtonACFace, &ButtonACFace_ReleasedEvent);

    laWidget_AddChild((laWidget*)BackgroundImage, (laWidget*)ButtonACFace);

    ButtonACBoth = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonACBoth, 4, 63);
    laWidget_SetSize((laWidget*)ButtonACBoth, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonACBoth, &ButtonScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonACBoth, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonACBoth, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonACBoth, &AC_Both);
    laButtonWidget_SetReleasedImage(ButtonACBoth, &AC_Both);
    laButtonWidget_SetPressedEventCallback(ButtonACBoth, &ButtonACBoth_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(ButtonACBoth, &ButtonACBoth_ReleasedEvent);

    laWidget_AddChild((laWidget*)BackgroundImage, (laWidget*)ButtonACBoth);

    ButtonACFeet = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonACFeet, 64, 63);
    laWidget_SetSize((laWidget*)ButtonACFeet, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonACFeet, &ButtonScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonACFeet, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonACFeet, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonACFeet, &AC_Feet);
    laButtonWidget_SetReleasedImage(ButtonACFeet, &AC_Feet);
    laButtonWidget_SetPressedEventCallback(ButtonACFeet, &ButtonACFeet_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(ButtonACFeet, &ButtonACFeet_ReleasedEvent);

    laWidget_AddChild((laWidget*)BackgroundImage, (laWidget*)ButtonACFeet);

    ButtonDefrost = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonDefrost, 64, 3);
    laWidget_SetSize((laWidget*)ButtonDefrost, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonDefrost, &ButtonScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonDefrost, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonDefrost, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetToggleable(ButtonDefrost, LA_TRUE);
    laButtonWidget_SetPressedImage(ButtonDefrost, &Defrost);
    laButtonWidget_SetReleasedImage(ButtonDefrost, &Defrost);
    laButtonWidget_SetPressedEventCallback(ButtonDefrost, &ButtonDefrost_PressedEvent);

    laWidget_AddChild((laWidget*)BackgroundImage, (laWidget*)ButtonDefrost);

    ButtonACIntake = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonACIntake, 4, 123);
    laWidget_SetSize((laWidget*)ButtonACIntake, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonACIntake, &ButtonScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonACIntake, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonACIntake, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonACIntake, &AC_Intake);
    laButtonWidget_SetReleasedImage(ButtonACIntake, &AC_Intake);
    laButtonWidget_SetPressedEventCallback(ButtonACIntake, &ButtonACIntake_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(ButtonACIntake, &ButtonACIntake_ReleasedEvent);

    laWidget_AddChild((laWidget*)BackgroundImage, (laWidget*)ButtonACIntake);

    ButtonACLoop = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonACLoop, 64, 123);
    laWidget_SetSize((laWidget*)ButtonACLoop, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonACLoop, &ButtonScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonACLoop, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonACLoop, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonACLoop, &AC_Loop);
    laButtonWidget_SetReleasedImage(ButtonACLoop, &AC_Loop);
    laButtonWidget_SetPressedEventCallback(ButtonACLoop, &ButtonACLoop_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(ButtonACLoop, &ButtonACLoop_ReleasedEvent);

    laWidget_AddChild((laWidget*)BackgroundImage, (laWidget*)ButtonACLoop);

    ButtonACSync = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonACSync, 181, 192);
    laWidget_SetSize((laWidget*)ButtonACSync, 120, 52);
    laWidget_SetScheme((laWidget*)ButtonACSync, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonACSync, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonACSync, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)ButtonACSync, 0, 0, 0, 0);
    laButtonWidget_SetPressedImage(ButtonACSync, &OvalButtonPress);
    laButtonWidget_SetReleasedImage(ButtonACSync, &OvalButton);
    laButtonWidget_SetPressedEventCallback(ButtonACSync, &ButtonACSync_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(ButtonACSync, &ButtonACSync_ReleasedEvent);

    laWidget_AddChild((laWidget*)ClimateControlPanel, (laWidget*)ButtonACSync);

    LabelSync = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelSync, 11, 7);
    laWidget_SetSize((laWidget*)LabelSync, 100, 30);
    laWidget_SetScheme((laWidget*)LabelSync, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)LabelSync, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelSync, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelSync, laString_CreateFromID(string_String_ACSync));
    laWidget_AddChild((laWidget*)ButtonACSync, (laWidget*)LabelSync);

    CircularSliderACRight = laCircularSliderWidget_New();
    laWidget_SetPosition((laWidget*)CircularSliderACRight, 304, 10);
    laWidget_SetSize((laWidget*)CircularSliderACRight, 150, 180);
    laWidget_SetScheme((laWidget*)CircularSliderACRight, &ACDialScheme);
    laWidget_SetBackgroundType((laWidget*)CircularSliderACRight, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)CircularSliderACRight, LA_WIDGET_BORDER_NONE);
    laCircularSliderWidget_SetRadius(CircularSliderACRight, 70);
    laCircularSliderWidget_SetStartAngle(CircularSliderACRight, 90);
    laCircularSliderWidget_SetTouchOnButtonOnly(CircularSliderACRight, LA_FALSE);
    laCircularSliderWidget_SetArcVisible(CircularSliderACRight, OUTSIDE_CIRCLE_BORDER, LA_FALSE);
    laCircularSliderWidget_SetArcThickness(CircularSliderACRight, OUTSIDE_CIRCLE_BORDER, 2);
    laCircularSliderWidget_SetArcVisible(CircularSliderACRight, INSIDE_CIRCLE_BORDER, LA_FALSE);
    laCircularSliderWidget_SetArcThickness(CircularSliderACRight, INSIDE_CIRCLE_BORDER, 2);
    laCircularSliderWidget_SetArcThickness(CircularSliderACRight, ACTIVE_AREA, 38);
    laCircularSliderWidget_SetArcRadius(CircularSliderACRight, CIRCLE_BUTTON, 19);
    laCircularSliderWidget_SetArcThickness(CircularSliderACRight, CIRCLE_BUTTON, 0);
    laCircularSliderWidget_SetArcScheme(CircularSliderACRight, CIRCLE_BUTTON, &ACButtonScheme);
    laCircularSliderWidget_SetValueChangedEventCallback(CircularSliderACRight, &CircularSliderACRight_ValueChangedEvent);
    laCircularSliderWidget_SetPressedEventCallback(CircularSliderACRight, &CircularSliderACRight_PressedEvent);
    laWidget_AddChild((laWidget*)ClimateControlPanel, (laWidget*)CircularSliderACRight);

    CircularSliderACLeft = laCircularSliderWidget_New();
    laWidget_SetPosition((laWidget*)CircularSliderACLeft, 25, 10);
    laWidget_SetSize((laWidget*)CircularSliderACLeft, 150, 180);
    laWidget_SetScheme((laWidget*)CircularSliderACLeft, &ACDialScheme);
    laWidget_SetBackgroundType((laWidget*)CircularSliderACLeft, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)CircularSliderACLeft, LA_WIDGET_BORDER_NONE);
    laCircularSliderWidget_SetRadius(CircularSliderACLeft, 70);
    laCircularSliderWidget_SetStartAngle(CircularSliderACLeft, 90);
    laCircularSliderWidget_SetTouchOnButtonOnly(CircularSliderACLeft, LA_FALSE);
    laCircularSliderWidget_SetArcVisible(CircularSliderACLeft, OUTSIDE_CIRCLE_BORDER, LA_FALSE);
    laCircularSliderWidget_SetArcThickness(CircularSliderACLeft, OUTSIDE_CIRCLE_BORDER, 2);
    laCircularSliderWidget_SetArcVisible(CircularSliderACLeft, INSIDE_CIRCLE_BORDER, LA_FALSE);
    laCircularSliderWidget_SetArcThickness(CircularSliderACLeft, INSIDE_CIRCLE_BORDER, 2);
    laCircularSliderWidget_SetArcThickness(CircularSliderACLeft, ACTIVE_AREA, 38);
    laCircularSliderWidget_SetArcRadius(CircularSliderACLeft, CIRCLE_BUTTON, 19);
    laCircularSliderWidget_SetArcThickness(CircularSliderACLeft, CIRCLE_BUTTON, 0);
    laCircularSliderWidget_SetArcScheme(CircularSliderACLeft, CIRCLE_BUTTON, &ACButtonScheme);
    laCircularSliderWidget_SetValueChangedEventCallback(CircularSliderACLeft, &CircularSliderACLeft_ValueChangedEvent);
    laCircularSliderWidget_SetPressedEventCallback(CircularSliderACLeft, &CircularSliderACLeft_PressedEvent);
    laWidget_AddChild((laWidget*)ClimateControlPanel, (laWidget*)CircularSliderACLeft);

    PhonePanel = laWidget_New();
    laWidget_SetPosition((laWidget*)PhonePanel, 31, 30);
    laWidget_SetSize((laWidget*)PhonePanel, 420, 242);
    laWidget_SetEnabled((laWidget*)PhonePanel, LA_FALSE);
    laWidget_SetVisible((laWidget*)PhonePanel, LA_FALSE);
    laWidget_SetScheme((laWidget*)PhonePanel, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)PhonePanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PhonePanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PhonePanel);

    TextFieldPhone = laTextFieldWidget_New();
    laWidget_SetPosition((laWidget*)TextFieldPhone, 15, 15);
    laWidget_SetSize((laWidget*)TextFieldPhone, 215, 40);
    laWidget_SetScheme((laWidget*)TextFieldPhone, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)TextFieldPhone, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)TextFieldPhone, LA_WIDGET_BORDER_LINE);
    laTextFieldWidget_SetText(TextFieldPhone, laString_CreateFromID(string_String_Space));
    laTextFieldWidget_SetAlignment(TextFieldPhone, LA_HALIGN_CENTER);
    laTextFieldWidget_SetCursorEnabled(TextFieldPhone, LA_TRUE);
    laTextFieldWidget_SetTextChangedEventCallback(TextFieldPhone, &TextFieldPhone_TextChangedEvent);
    laTextFieldWidget_SetFocusChangedEventCallback(TextFieldPhone, &TextFieldPhone_FocusChangedEvent);
    laWidget_AddChild((laWidget*)PhonePanel, (laWidget*)TextFieldPhone);

    ButtonBackspace = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonBackspace, 185, 0);
    laWidget_SetSize((laWidget*)ButtonBackspace, 40, 35);
    laWidget_SetBackgroundType((laWidget*)ButtonBackspace, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonBackspace, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(ButtonBackspace, &ButtonBackspace_ReleasedEvent);

    laWidget_AddChild((laWidget*)TextFieldPhone, (laWidget*)ButtonBackspace);

    LabelBackspace = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelBackspace, 1, 1);
    laWidget_SetSize((laWidget*)LabelBackspace, 28, 38);
    laWidget_SetScheme((laWidget*)LabelBackspace, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)LabelBackspace, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelBackspace, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)LabelBackspace, 0, 0, 0, 0);
    laLabelWidget_SetText(LabelBackspace, laString_CreateFromID(string_String_Backspace));
    laWidget_AddChild((laWidget*)ButtonBackspace, (laWidget*)LabelBackspace);

    ButtonCall = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonCall, 65, 190);
    laWidget_SetSize((laWidget*)ButtonCall, 120, 55);
    laWidget_SetScheme((laWidget*)ButtonCall, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonCall, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonCall, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)ButtonCall, 0, 0, 0, 0);
    laButtonWidget_SetPressedImage(ButtonCall, &OvalButtonPress);
    laButtonWidget_SetReleasedImage(ButtonCall, &OvalButton);
    laButtonWidget_SetPressedEventCallback(ButtonCall, &ButtonCall_PressedEvent);

    laWidget_AddChild((laWidget*)PhonePanel, (laWidget*)ButtonCall);

    ImagePhoneIcon = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImagePhoneIcon, 48, 12);
    laWidget_SetSize((laWidget*)ImagePhoneIcon, 30, 30);
    laWidget_SetBackgroundType((laWidget*)ImagePhoneIcon, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImagePhoneIcon, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImagePhoneIcon, &PhoneIcon);
    laWidget_AddChild((laWidget*)ButtonCall, (laWidget*)ImagePhoneIcon);

    PhoneKeyPadPanel = laWidget_New();
    laWidget_SetPosition((laWidget*)PhoneKeyPadPanel, 240, 0);
    laWidget_SetSize((laWidget*)PhoneKeyPadPanel, 180, 240);
    laWidget_SetBackgroundType((laWidget*)PhoneKeyPadPanel, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PhoneKeyPadPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)PhonePanel, PhoneKeyPadPanel);

    ButtonPhone1 = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonPhone1, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonPhone1, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonPhone1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonPhone1, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetText(ButtonPhone1, laString_CreateFromID(string_String_One));
    laButtonWidget_SetReleasedEventCallback(ButtonPhone1, &ButtonPhone1_ReleasedEvent);

    laWidget_AddChild((laWidget*)PhoneKeyPadPanel, (laWidget*)ButtonPhone1);

    ButtonPhone2 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonPhone2, 60, 0);
    laWidget_SetSize((laWidget*)ButtonPhone2, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonPhone2, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonPhone2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonPhone2, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetText(ButtonPhone2, laString_CreateFromID(string_String_Two));
    laButtonWidget_SetReleasedEventCallback(ButtonPhone2, &ButtonPhone2_ReleasedEvent);

    laWidget_AddChild((laWidget*)PhoneKeyPadPanel, (laWidget*)ButtonPhone2);

    LabelNumber2 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelNumber2, 0, 45);
    laWidget_SetSize((laWidget*)LabelNumber2, 60, 15);
    laWidget_SetScheme((laWidget*)LabelNumber2, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelNumber2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelNumber2, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)LabelNumber2, 0, 0, 0, 0);
    laLabelWidget_SetText(LabelNumber2, laString_CreateFromID(string_String_AlphabetTwo));
    laWidget_AddChild((laWidget*)ButtonPhone2, (laWidget*)LabelNumber2);

    ButtonPhone3 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonPhone3, 120, 0);
    laWidget_SetSize((laWidget*)ButtonPhone3, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonPhone3, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonPhone3, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonPhone3, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetText(ButtonPhone3, laString_CreateFromID(string_String_Three));
    laButtonWidget_SetReleasedEventCallback(ButtonPhone3, &ButtonPhone3_ReleasedEvent);

    laWidget_AddChild((laWidget*)PhoneKeyPadPanel, (laWidget*)ButtonPhone3);

    LabelNumber3 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelNumber3, 0, 45);
    laWidget_SetSize((laWidget*)LabelNumber3, 60, 15);
    laWidget_SetScheme((laWidget*)LabelNumber3, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelNumber3, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelNumber3, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)LabelNumber3, 0, 0, 0, 0);
    laLabelWidget_SetText(LabelNumber3, laString_CreateFromID(string_String_AlphabetThree));
    laWidget_AddChild((laWidget*)ButtonPhone3, (laWidget*)LabelNumber3);

    ButtonPhone4 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonPhone4, 0, 60);
    laWidget_SetSize((laWidget*)ButtonPhone4, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonPhone4, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonPhone4, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonPhone4, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetText(ButtonPhone4, laString_CreateFromID(string_String_Four));
    laButtonWidget_SetReleasedEventCallback(ButtonPhone4, &ButtonPhone4_ReleasedEvent);

    laWidget_AddChild((laWidget*)PhoneKeyPadPanel, (laWidget*)ButtonPhone4);

    LabelNumber4 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelNumber4, 0, 45);
    laWidget_SetSize((laWidget*)LabelNumber4, 60, 15);
    laWidget_SetScheme((laWidget*)LabelNumber4, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelNumber4, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelNumber4, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)LabelNumber4, 0, 0, 0, 0);
    laLabelWidget_SetText(LabelNumber4, laString_CreateFromID(string_String_AlphabetFour));
    laWidget_AddChild((laWidget*)ButtonPhone4, (laWidget*)LabelNumber4);

    ButtonPhone5 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonPhone5, 60, 60);
    laWidget_SetSize((laWidget*)ButtonPhone5, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonPhone5, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonPhone5, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonPhone5, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetText(ButtonPhone5, laString_CreateFromID(string_String_Five));
    laButtonWidget_SetReleasedEventCallback(ButtonPhone5, &ButtonPhone5_ReleasedEvent);

    laWidget_AddChild((laWidget*)PhoneKeyPadPanel, (laWidget*)ButtonPhone5);

    LabelNumber5 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelNumber5, 0, 45);
    laWidget_SetSize((laWidget*)LabelNumber5, 60, 15);
    laWidget_SetScheme((laWidget*)LabelNumber5, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelNumber5, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelNumber5, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)LabelNumber5, 0, 0, 0, 0);
    laLabelWidget_SetText(LabelNumber5, laString_CreateFromID(string_String_AlphabetFive));
    laWidget_AddChild((laWidget*)ButtonPhone5, (laWidget*)LabelNumber5);

    ButtonPhone6 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonPhone6, 120, 60);
    laWidget_SetSize((laWidget*)ButtonPhone6, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonPhone6, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonPhone6, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonPhone6, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetText(ButtonPhone6, laString_CreateFromID(string_String_Six));
    laButtonWidget_SetReleasedEventCallback(ButtonPhone6, &ButtonPhone6_ReleasedEvent);

    laWidget_AddChild((laWidget*)PhoneKeyPadPanel, (laWidget*)ButtonPhone6);

    LabelNumber6 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelNumber6, 0, 45);
    laWidget_SetSize((laWidget*)LabelNumber6, 60, 15);
    laWidget_SetScheme((laWidget*)LabelNumber6, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelNumber6, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelNumber6, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)LabelNumber6, 0, 0, 0, 0);
    laLabelWidget_SetText(LabelNumber6, laString_CreateFromID(string_String_AlphabetSix));
    laWidget_AddChild((laWidget*)ButtonPhone6, (laWidget*)LabelNumber6);

    ButtonPhone7 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonPhone7, 0, 120);
    laWidget_SetSize((laWidget*)ButtonPhone7, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonPhone7, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonPhone7, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonPhone7, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetText(ButtonPhone7, laString_CreateFromID(string_String_Seven));
    laButtonWidget_SetReleasedEventCallback(ButtonPhone7, &ButtonPhone7_ReleasedEvent);

    laWidget_AddChild((laWidget*)PhoneKeyPadPanel, (laWidget*)ButtonPhone7);

    LabelNumber7 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelNumber7, 0, 45);
    laWidget_SetSize((laWidget*)LabelNumber7, 60, 15);
    laWidget_SetScheme((laWidget*)LabelNumber7, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelNumber7, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelNumber7, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)LabelNumber7, 0, 0, 0, 0);
    laLabelWidget_SetText(LabelNumber7, laString_CreateFromID(string_String_AlphabetSeven));
    laWidget_AddChild((laWidget*)ButtonPhone7, (laWidget*)LabelNumber7);

    ButtonPhone8 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonPhone8, 60, 120);
    laWidget_SetSize((laWidget*)ButtonPhone8, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonPhone8, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonPhone8, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonPhone8, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetText(ButtonPhone8, laString_CreateFromID(string_String_Eight));
    laButtonWidget_SetReleasedEventCallback(ButtonPhone8, &ButtonPhone8_ReleasedEvent);

    laWidget_AddChild((laWidget*)PhoneKeyPadPanel, (laWidget*)ButtonPhone8);

    LabelNumber8 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelNumber8, 0, 45);
    laWidget_SetSize((laWidget*)LabelNumber8, 60, 15);
    laWidget_SetScheme((laWidget*)LabelNumber8, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelNumber8, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelNumber8, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)LabelNumber8, 0, 0, 0, 0);
    laLabelWidget_SetText(LabelNumber8, laString_CreateFromID(string_String_AlphabetEight));
    laWidget_AddChild((laWidget*)ButtonPhone8, (laWidget*)LabelNumber8);

    ButtonPhone9 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonPhone9, 120, 120);
    laWidget_SetSize((laWidget*)ButtonPhone9, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonPhone9, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonPhone9, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonPhone9, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetText(ButtonPhone9, laString_CreateFromID(string_String_Nine));
    laButtonWidget_SetReleasedEventCallback(ButtonPhone9, &ButtonPhone9_ReleasedEvent);

    laWidget_AddChild((laWidget*)PhoneKeyPadPanel, (laWidget*)ButtonPhone9);

    LabelNumber9 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelNumber9, 0, 45);
    laWidget_SetSize((laWidget*)LabelNumber9, 60, 15);
    laWidget_SetScheme((laWidget*)LabelNumber9, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelNumber9, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelNumber9, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)LabelNumber9, 0, 0, 0, 0);
    laLabelWidget_SetText(LabelNumber9, laString_CreateFromID(string_String_AlphabetNine));
    laWidget_AddChild((laWidget*)ButtonPhone9, (laWidget*)LabelNumber9);

    ButtonPhoneStar = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonPhoneStar, 0, 180);
    laWidget_SetSize((laWidget*)ButtonPhoneStar, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonPhoneStar, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonPhoneStar, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonPhoneStar, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetText(ButtonPhoneStar, laString_CreateFromID(string_String_Star));
    laButtonWidget_SetReleasedEventCallback(ButtonPhoneStar, &ButtonPhoneStar_ReleasedEvent);

    laWidget_AddChild((laWidget*)PhoneKeyPadPanel, (laWidget*)ButtonPhoneStar);

    ButtonPhone0 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonPhone0, 60, 180);
    laWidget_SetSize((laWidget*)ButtonPhone0, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonPhone0, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonPhone0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonPhone0, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetText(ButtonPhone0, laString_CreateFromID(string_String_Zero));
    laButtonWidget_SetReleasedEventCallback(ButtonPhone0, &ButtonPhone0_ReleasedEvent);

    laWidget_AddChild((laWidget*)PhoneKeyPadPanel, (laWidget*)ButtonPhone0);

    LabelNumber0 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelNumber0, 0, 45);
    laWidget_SetSize((laWidget*)LabelNumber0, 60, 15);
    laWidget_SetScheme((laWidget*)LabelNumber0, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelNumber0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelNumber0, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)LabelNumber0, 0, 0, 0, 0);
    laLabelWidget_SetText(LabelNumber0, laString_CreateFromID(string_String_Plus));
    laWidget_AddChild((laWidget*)ButtonPhone0, (laWidget*)LabelNumber0);

    ButtonPhonePound = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonPhonePound, 120, 180);
    laWidget_SetSize((laWidget*)ButtonPhonePound, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonPhonePound, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonPhonePound, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonPhonePound, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetText(ButtonPhonePound, laString_CreateFromID(string_String_Pound));
    laButtonWidget_SetReleasedEventCallback(ButtonPhonePound, &ButtonPhonePound_ReleasedEvent);

    laWidget_AddChild((laWidget*)PhoneKeyPadPanel, (laWidget*)ButtonPhonePound);

    ListContacts = laListWidget_New();
    laWidget_SetPosition((laWidget*)ListContacts, 46, 95);
    laWidget_SetSize((laWidget*)ListContacts, 215, 120);
    laWidget_SetEnabled((laWidget*)ListContacts, LA_FALSE);
    laWidget_SetVisible((laWidget*)ListContacts, LA_FALSE);
    laWidget_SetScheme((laWidget*)ListContacts, &PhoneListScheme);
    laWidget_SetBackgroundType((laWidget*)ListContacts, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ListContacts, LA_WIDGET_BORDER_LINE);
    laListWidget_SetSelectionMode(ListContacts, LA_LIST_WIDGET_SELECTION_MODE_SINGLE);
    laListWidget_SetAlignment(ListContacts, LA_HALIGN_CENTER);
    laListWidget_SetIconPosition(ListContacts, LA_RELATIVE_POSITION_RIGHTOF);
    laListWidget_SetIconMargin(ListContacts, 5);
    laListWidget_AppendItem(ListContacts);
    laListWidget_SetItemText(ListContacts, 0, laString_CreateFromID(string_String_Contacts1));
    laListWidget_AppendItem(ListContacts);
    laListWidget_SetItemText(ListContacts, 1, laString_CreateFromID(string_String_Contacts2));
    laListWidget_AppendItem(ListContacts);
    laListWidget_SetItemText(ListContacts, 2, laString_CreateFromID(string_String_Contacts3));
    laListWidget_AppendItem(ListContacts);
    laListWidget_SetItemText(ListContacts, 3, laString_CreateFromID(string_String_Contacts4));
    laListWidget_AppendItem(ListContacts);
    laListWidget_AppendItem(ListContacts);
    laListWidget_SetSelectedItemChangedEventCallback(ListContacts, &ListContacts_SelectionChangedEvent);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ListContacts);

    BluetoothPanel = laWidget_New();
    laWidget_SetPosition((laWidget*)BluetoothPanel, 30, 30);
    laWidget_SetSize((laWidget*)BluetoothPanel, 420, 242);
    laWidget_SetEnabled((laWidget*)BluetoothPanel, LA_FALSE);
    laWidget_SetVisible((laWidget*)BluetoothPanel, LA_FALSE);
    laWidget_SetScheme((laWidget*)BluetoothPanel, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)BluetoothPanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)BluetoothPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, BluetoothPanel);

    ButtonBluetoothPhone1 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonBluetoothPhone1, 60, 30);
    laWidget_SetSize((laWidget*)ButtonBluetoothPhone1, 280, 60);
    laWidget_SetScheme((laWidget*)ButtonBluetoothPhone1, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonBluetoothPhone1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonBluetoothPhone1, LA_WIDGET_BORDER_LINE);
    laWidget_SetMargins((laWidget*)ButtonBluetoothPhone1, 0, 0, 0, 0);
    laButtonWidget_SetPressedEventCallback(ButtonBluetoothPhone1, &ButtonBluetoothPhone1_PressedEvent);

    laWidget_AddChild((laWidget*)BluetoothPanel, (laWidget*)ButtonBluetoothPhone1);

    ImageSelectBluetoothDevice1 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageSelectBluetoothDevice1, 243, 0);
    laWidget_SetSize((laWidget*)ImageSelectBluetoothDevice1, 38, 60);
    laWidget_SetScheme((laWidget*)ImageSelectBluetoothDevice1, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)ImageSelectBluetoothDevice1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageSelectBluetoothDevice1, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageSelectBluetoothDevice1, &ChevronSmall);
    laWidget_AddChild((laWidget*)ButtonBluetoothPhone1, (laWidget*)ImageSelectBluetoothDevice1);

    ImageBluetoothDevice1 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageBluetoothDevice1, 5, 5);
    laWidget_SetSize((laWidget*)ImageBluetoothDevice1, 50, 50);
    laWidget_SetScheme((laWidget*)ImageBluetoothDevice1, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageBluetoothDevice1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageBluetoothDevice1, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageBluetoothDevice1, &PhoneSmall);
    laWidget_AddChild((laWidget*)ButtonBluetoothPhone1, (laWidget*)ImageBluetoothDevice1);

    LabelPhone1 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelPhone1, 60, 15);
    laWidget_SetSize((laWidget*)LabelPhone1, 100, 30);
    laWidget_SetScheme((laWidget*)LabelPhone1, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelPhone1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelPhone1, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelPhone1, laString_CreateFromID(string_String_PixelTwo));
    laLabelWidget_SetHAlignment(LabelPhone1, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)ButtonBluetoothPhone1, (laWidget*)LabelPhone1);

    ButtonBluetoothPhone2 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonBluetoothPhone2, 60, 120);
    laWidget_SetSize((laWidget*)ButtonBluetoothPhone2, 280, 60);
    laWidget_SetScheme((laWidget*)ButtonBluetoothPhone2, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonBluetoothPhone2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonBluetoothPhone2, LA_WIDGET_BORDER_LINE);
    laWidget_SetMargins((laWidget*)ButtonBluetoothPhone2, 0, 0, 0, 0);
    laButtonWidget_SetPressedEventCallback(ButtonBluetoothPhone2, &ButtonBluetoothPhone2_PressedEvent);

    laWidget_AddChild((laWidget*)BluetoothPanel, (laWidget*)ButtonBluetoothPhone2);

    ImageSelectBluetoothDevice2 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageSelectBluetoothDevice2, 240, 0);
    laWidget_SetSize((laWidget*)ImageSelectBluetoothDevice2, 41, 60);
    laWidget_SetScheme((laWidget*)ImageSelectBluetoothDevice2, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)ImageSelectBluetoothDevice2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageSelectBluetoothDevice2, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageSelectBluetoothDevice2, &PlusSmall);
    laWidget_AddChild((laWidget*)ButtonBluetoothPhone2, (laWidget*)ImageSelectBluetoothDevice2);

    ImageBluetoohDevice2 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageBluetoohDevice2, 5, 5);
    laWidget_SetSize((laWidget*)ImageBluetoohDevice2, 50, 50);
    laWidget_SetScheme((laWidget*)ImageBluetoohDevice2, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageBluetoohDevice2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageBluetoohDevice2, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageBluetoohDevice2, &BluetoothLogoSmall);
    laWidget_AddChild((laWidget*)ButtonBluetoothPhone2, (laWidget*)ImageBluetoohDevice2);

    LabelPhone2 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelPhone2, 60, 15);
    laWidget_SetSize((laWidget*)LabelPhone2, 171, 30);
    laWidget_SetScheme((laWidget*)LabelPhone2, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelPhone2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelPhone2, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelPhone2, laString_CreateFromID(string_String_ConnectPhone));
    laLabelWidget_SetHAlignment(LabelPhone2, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)ButtonBluetoothPhone2, (laWidget*)LabelPhone2);

    NavPanel = laWidget_New();
    laWidget_SetPosition((laWidget*)NavPanel, 30, 30);
    laWidget_SetSize((laWidget*)NavPanel, 420, 242);
    laWidget_SetEnabled((laWidget*)NavPanel, LA_FALSE);
    laWidget_SetVisible((laWidget*)NavPanel, LA_FALSE);
    laWidget_SetScheme((laWidget*)NavPanel, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)NavPanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)NavPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, NavPanel);

    NavMap = laImagePlusWidget_New();
    laWidget_SetSize((laWidget*)NavMap, 420, 212);
    laWidget_SetBackgroundType((laWidget*)NavMap, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)NavMap, LA_WIDGET_BORDER_NONE);
    laImagePlusWidget_SetImage(NavMap, &ChargeMap);
    laImagePlusWidget_SetPreserveAspectEnabled(NavMap, LA_TRUE);
    laWidget_AddChild((laWidget*)NavPanel, (laWidget*)NavMap);

    BottomPanel = laWidget_New();
    laWidget_SetPosition((laWidget*)BottomPanel, 0, 212);
    laWidget_SetSize((laWidget*)BottomPanel, 420, 30);
    laWidget_SetScheme((laWidget*)BottomPanel, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)BottomPanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)BottomPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)NavPanel, BottomPanel);

    LabelDistance = laLabelWidget_New();
    laWidget_SetSize((laWidget*)LabelDistance, 90, 30);
    laWidget_SetScheme((laWidget*)LabelDistance, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelDistance, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelDistance, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelDistance, laString_CreateFromID(string_String_Distance));
    laLabelWidget_SetHAlignment(LabelDistance, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)BottomPanel, (laWidget*)LabelDistance);

    LabelTravelTime = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelTravelTime, 158, 0);
    laWidget_SetSize((laWidget*)LabelTravelTime, 90, 30);
    laWidget_SetScheme((laWidget*)LabelTravelTime, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelTravelTime, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelTravelTime, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelTravelTime, laString_CreateFromID(string_String_TravelTime));
    laWidget_AddChild((laWidget*)BottomPanel, (laWidget*)LabelTravelTime);

    LabelETA = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelETA, 330, 0);
    laWidget_SetSize((laWidget*)LabelETA, 90, 30);
    laWidget_SetScheme((laWidget*)LabelETA, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelETA, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelETA, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelETA, laString_CreateFromID(string_String_ETA));
    laLabelWidget_SetHAlignment(LabelETA, LA_HALIGN_RIGHT);
    laWidget_AddChild((laWidget*)BottomPanel, (laWidget*)LabelETA);

    ButtonNavRead = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonNavRead, 420, 242);
    laWidget_SetBackgroundType((laWidget*)ButtonNavRead, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonNavRead, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedEventCallback(ButtonNavRead, &ButtonNavRead_PressedEvent);

    laWidget_AddChild((laWidget*)NavPanel, (laWidget*)ButtonNavRead);

    MusicPanel = laWidget_New();
    laWidget_SetPosition((laWidget*)MusicPanel, 30, 30);
    laWidget_SetSize((laWidget*)MusicPanel, 420, 242);
    laWidget_SetEnabled((laWidget*)MusicPanel, LA_FALSE);
    laWidget_SetVisible((laWidget*)MusicPanel, LA_FALSE);
    laWidget_SetScheme((laWidget*)MusicPanel, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)MusicPanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)MusicPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, MusicPanel);

    MusicSelector = laRadialMenuWidget_New();
    laWidget_SetSize((laWidget*)MusicSelector, 420, 150);
    laWidget_SetScheme((laWidget*)MusicSelector, &RadialMenuScheme);
    laWidget_SetBackgroundType((laWidget*)MusicSelector, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)MusicSelector, LA_WIDGET_BORDER_NONE);
    laWidget_SetAlphaEnable((laWidget*)MusicSelector, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)MusicSelector, 255);
    laRadialMenuWidget_SetSizeScaling(MusicSelector, LA_RADIAL_MENU_SCALE_GRADUAL);
    laRadialMenuWidget_SetAlphaScaling(MusicSelector, LA_RADIAL_MENU_SCALE_GRADUAL);
    laRadialMenuWidget_SetSizeScaleMinMax(MusicSelector, 40, 100);
    laRadialMenuWidget_SetAlphaScaleMinMax(MusicSelector, 0, 250);
    laRadialMenuWidget_SetTheta(MusicSelector, 0);
    laRadialMenuWidget_SetTouchArea(MusicSelector, 0, 0, 420, 150);
    laRadialMenuWidget_SetHighlightProminent(MusicSelector, LA_TRUE);
    laRadialMenuWidget_SetEllipseType(MusicSelector, LA_RADIAL_MENU_ELLIPSE_TYPE_ORBITAL);

    MusicSelector_Item0 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)MusicSelector_Item0, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(MusicSelector_Item0, &cover1);
    laImagePlusWidget_SetTransformWidth(MusicSelector_Item0, 120);
    laImagePlusWidget_SetTransformHeight(MusicSelector_Item0, 120);
    laImagePlusWidget_SetStretchEnabled(MusicSelector_Item0, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(MusicSelector_Item0, LA_TRUE);
    laWidget_SetVisible((laWidget*)MusicSelector_Item0, LA_TRUE);
    laWidget_SetPosition((laWidget*)MusicSelector_Item0, 210, 75);
    laWidget_SetSize((laWidget*)MusicSelector_Item0, 120, 120);
    laRadialMenuWidget_AddWidget(MusicSelector, (laWidget*)MusicSelector_Item0);
    laWidget_AddChild((laWidget*)MusicSelector, (laWidget*)MusicSelector_Item0);

    MusicSelector_Item1 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)MusicSelector_Item1, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(MusicSelector_Item1, &cover2);
    laImagePlusWidget_SetTransformWidth(MusicSelector_Item1, 99);
    laImagePlusWidget_SetTransformHeight(MusicSelector_Item1, 99);
    laImagePlusWidget_SetStretchEnabled(MusicSelector_Item1, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(MusicSelector_Item1, LA_TRUE);
    laWidget_SetVisible((laWidget*)MusicSelector_Item1, LA_TRUE);
    laWidget_SetPosition((laWidget*)MusicSelector_Item1, 210, 75);
    laWidget_SetSize((laWidget*)MusicSelector_Item1, 120, 120);
    laRadialMenuWidget_AddWidget(MusicSelector, (laWidget*)MusicSelector_Item1);
    laWidget_AddChild((laWidget*)MusicSelector, (laWidget*)MusicSelector_Item1);

    MusicSelector_Item2 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)MusicSelector_Item2, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(MusicSelector_Item2, &cover3);
    laImagePlusWidget_SetTransformWidth(MusicSelector_Item2, 79);
    laImagePlusWidget_SetTransformHeight(MusicSelector_Item2, 79);
    laImagePlusWidget_SetStretchEnabled(MusicSelector_Item2, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(MusicSelector_Item2, LA_TRUE);
    laWidget_SetVisible((laWidget*)MusicSelector_Item2, LA_TRUE);
    laWidget_SetPosition((laWidget*)MusicSelector_Item2, 210, 75);
    laWidget_SetSize((laWidget*)MusicSelector_Item2, 120, 120);
    laRadialMenuWidget_AddWidget(MusicSelector, (laWidget*)MusicSelector_Item2);
    laWidget_AddChild((laWidget*)MusicSelector, (laWidget*)MusicSelector_Item2);

    MusicSelector_Item3 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)MusicSelector_Item3, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(MusicSelector_Item3, &cover4);
    laImagePlusWidget_SetTransformWidth(MusicSelector_Item3, 58);
    laImagePlusWidget_SetTransformHeight(MusicSelector_Item3, 58);
    laImagePlusWidget_SetStretchEnabled(MusicSelector_Item3, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(MusicSelector_Item3, LA_TRUE);
    laWidget_SetVisible((laWidget*)MusicSelector_Item3, LA_TRUE);
    laWidget_SetPosition((laWidget*)MusicSelector_Item3, 210, 75);
    laWidget_SetSize((laWidget*)MusicSelector_Item3, 120, 120);
    laRadialMenuWidget_AddWidget(MusicSelector, (laWidget*)MusicSelector_Item3);
    laWidget_AddChild((laWidget*)MusicSelector, (laWidget*)MusicSelector_Item3);

    MusicSelector_Item4 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)MusicSelector_Item4, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(MusicSelector_Item4, &cover5);
    laImagePlusWidget_SetTransformWidth(MusicSelector_Item4, 120);
    laImagePlusWidget_SetTransformHeight(MusicSelector_Item4, 120);
    laImagePlusWidget_SetStretchEnabled(MusicSelector_Item4, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(MusicSelector_Item4, LA_TRUE);
    laWidget_SetVisible((laWidget*)MusicSelector_Item4, LA_FALSE);
    laWidget_SetPosition((laWidget*)MusicSelector_Item4, 210, 75);
    laWidget_SetSize((laWidget*)MusicSelector_Item4, 120, 120);
    laRadialMenuWidget_AddWidget(MusicSelector, (laWidget*)MusicSelector_Item4);
    laWidget_AddChild((laWidget*)MusicSelector, (laWidget*)MusicSelector_Item4);

    MusicSelector_Item5 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)MusicSelector_Item5, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(MusicSelector_Item5, &cover6);
    laImagePlusWidget_SetTransformWidth(MusicSelector_Item5, 120);
    laImagePlusWidget_SetTransformHeight(MusicSelector_Item5, 120);
    laImagePlusWidget_SetStretchEnabled(MusicSelector_Item5, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(MusicSelector_Item5, LA_TRUE);
    laWidget_SetVisible((laWidget*)MusicSelector_Item5, LA_FALSE);
    laWidget_SetPosition((laWidget*)MusicSelector_Item5, 210, 75);
    laWidget_SetSize((laWidget*)MusicSelector_Item5, 120, 120);
    laRadialMenuWidget_AddWidget(MusicSelector, (laWidget*)MusicSelector_Item5);
    laWidget_AddChild((laWidget*)MusicSelector, (laWidget*)MusicSelector_Item5);

    MusicSelector_Item6 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)MusicSelector_Item6, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(MusicSelector_Item6, &cover7);
    laImagePlusWidget_SetTransformWidth(MusicSelector_Item6, 120);
    laImagePlusWidget_SetTransformHeight(MusicSelector_Item6, 120);
    laImagePlusWidget_SetStretchEnabled(MusicSelector_Item6, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(MusicSelector_Item6, LA_TRUE);
    laWidget_SetVisible((laWidget*)MusicSelector_Item6, LA_FALSE);
    laWidget_SetPosition((laWidget*)MusicSelector_Item6, 210, 75);
    laWidget_SetSize((laWidget*)MusicSelector_Item6, 120, 120);
    laRadialMenuWidget_AddWidget(MusicSelector, (laWidget*)MusicSelector_Item6);
    laWidget_AddChild((laWidget*)MusicSelector, (laWidget*)MusicSelector_Item6);

    MusicSelector_Item7 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)MusicSelector_Item7, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(MusicSelector_Item7, &cover8);
    laImagePlusWidget_SetTransformWidth(MusicSelector_Item7, 57);
    laImagePlusWidget_SetTransformHeight(MusicSelector_Item7, 57);
    laImagePlusWidget_SetStretchEnabled(MusicSelector_Item7, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(MusicSelector_Item7, LA_TRUE);
    laWidget_SetVisible((laWidget*)MusicSelector_Item7, LA_TRUE);
    laWidget_SetPosition((laWidget*)MusicSelector_Item7, 210, 75);
    laWidget_SetSize((laWidget*)MusicSelector_Item7, 120, 120);
    laRadialMenuWidget_AddWidget(MusicSelector, (laWidget*)MusicSelector_Item7);
    laWidget_AddChild((laWidget*)MusicSelector, (laWidget*)MusicSelector_Item7);

    MusicSelector_Item8 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)MusicSelector_Item8, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(MusicSelector_Item8, &cover9);
    laImagePlusWidget_SetTransformWidth(MusicSelector_Item8, 78);
    laImagePlusWidget_SetTransformHeight(MusicSelector_Item8, 78);
    laImagePlusWidget_SetStretchEnabled(MusicSelector_Item8, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(MusicSelector_Item8, LA_TRUE);
    laWidget_SetVisible((laWidget*)MusicSelector_Item8, LA_TRUE);
    laWidget_SetPosition((laWidget*)MusicSelector_Item8, 210, 75);
    laWidget_SetSize((laWidget*)MusicSelector_Item8, 120, 120);
    laRadialMenuWidget_AddWidget(MusicSelector, (laWidget*)MusicSelector_Item8);
    laWidget_AddChild((laWidget*)MusicSelector, (laWidget*)MusicSelector_Item8);

    MusicSelector_Item9 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)MusicSelector_Item9, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(MusicSelector_Item9, &cover10);
    laImagePlusWidget_SetTransformWidth(MusicSelector_Item9, 98);
    laImagePlusWidget_SetTransformHeight(MusicSelector_Item9, 98);
    laImagePlusWidget_SetStretchEnabled(MusicSelector_Item9, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(MusicSelector_Item9, LA_TRUE);
    laWidget_SetVisible((laWidget*)MusicSelector_Item9, LA_TRUE);
    laWidget_SetPosition((laWidget*)MusicSelector_Item9, 210, 75);
    laWidget_SetSize((laWidget*)MusicSelector_Item9, 120, 120);
    laRadialMenuWidget_AddWidget(MusicSelector, (laWidget*)MusicSelector_Item9);
    laWidget_AddChild((laWidget*)MusicSelector, (laWidget*)MusicSelector_Item9);

    laRadialMenuWidget_SetNumberOfItemsShown(MusicSelector, 7);
    laWidget_AddChild((laWidget*)MusicPanel, (laWidget*)MusicSelector);

    ButtonShuffle = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonShuffle, 30, 180);
    laWidget_SetSize((laWidget*)ButtonShuffle, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonShuffle, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonShuffle, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonShuffle, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonShuffle, &Shuffle);
    laButtonWidget_SetReleasedImage(ButtonShuffle, &Shuffle);
    laButtonWidget_SetPressedEventCallback(ButtonShuffle, &ButtonShuffle_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(ButtonShuffle, &ButtonShuffle_ReleasedEvent);

    laWidget_AddChild((laWidget*)MusicPanel, (laWidget*)ButtonShuffle);

    ButtonPlayPause = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonPlayPause, 125, 180);
    laWidget_SetSize((laWidget*)ButtonPlayPause, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonPlayPause, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonPlayPause, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonPlayPause, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonPlayPause, &PlayPause);
    laButtonWidget_SetReleasedImage(ButtonPlayPause, &PlayPause);
    laButtonWidget_SetPressedEventCallback(ButtonPlayPause, &ButtonPlayPause_PressedEvent);

    laWidget_AddChild((laWidget*)MusicPanel, (laWidget*)ButtonPlayPause);

    ButtonNextTrack = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonNextTrack, 215, 180);
    laWidget_SetSize((laWidget*)ButtonNextTrack, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonNextTrack, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonNextTrack, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonNextTrack, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonNextTrack, &NextTrack);
    laButtonWidget_SetReleasedImage(ButtonNextTrack, &NextTrack);
    laButtonWidget_SetPressedEventCallback(ButtonNextTrack, &ButtonNextTrack_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(ButtonNextTrack, &ButtonNextTrack_ReleasedEvent);

    laWidget_AddChild((laWidget*)MusicPanel, (laWidget*)ButtonNextTrack);

    ImageVolumeIcon = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageVolumeIcon, 300, 180);
    laWidget_SetSize((laWidget*)ImageVolumeIcon, 120, 60);
    laWidget_SetScheme((laWidget*)ImageVolumeIcon, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageVolumeIcon, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageVolumeIcon, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageVolumeIcon, &VolumeIcon);
    laImageWidget_SetVAlignment(ImageVolumeIcon, LA_VALIGN_BOTTOM);
    laWidget_AddChild((laWidget*)MusicPanel, (laWidget*)ImageVolumeIcon);

    ButtonVolumeUp = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonVolumeUp, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonVolumeUp, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonVolumeUp, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonVolumeUp, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonVolumeUp, &Plus);
    laButtonWidget_SetReleasedImage(ButtonVolumeUp, &Plus);
    laButtonWidget_SetPressedEventCallback(ButtonVolumeUp, &ButtonVolumeUp_PressedEvent);

    laWidget_AddChild((laWidget*)ImageVolumeIcon, (laWidget*)ButtonVolumeUp);

    ButtonVolumeDown = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonVolumeDown, 60, 0);
    laWidget_SetSize((laWidget*)ButtonVolumeDown, 60, 60);
    laWidget_SetScheme((laWidget*)ButtonVolumeDown, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonVolumeDown, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonVolumeDown, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonVolumeDown, &Minus);
    laButtonWidget_SetReleasedImage(ButtonVolumeDown, &Minus);
    laButtonWidget_SetPressedEventCallback(ButtonVolumeDown, &ButtonVolumeDown_PressedEvent);

    laWidget_AddChild((laWidget*)ImageVolumeIcon, (laWidget*)ButtonVolumeDown);

    MusicLine = laLineWidget_New();
    laWidget_SetPosition((laWidget*)MusicLine, 20, 160);
    laWidget_SetSize((laWidget*)MusicLine, 380, 10);
    laWidget_SetScheme((laWidget*)MusicLine, &ButtonScheme);
    laWidget_SetBackgroundType((laWidget*)MusicLine, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)MusicLine, LA_WIDGET_BORDER_NONE);
    laLineWidget_SetStartPoint(MusicLine, 0, 5);
    laLineWidget_SetEndPoint(MusicLine, 400, 5);
    laWidget_AddChild((laWidget*)MusicPanel, (laWidget*)MusicLine);

    MusicPosition = laWidget_New();
    laWidget_SetPosition((laWidget*)MusicPosition, 160, 0);
    laWidget_SetSize((laWidget*)MusicPosition, 20, 10);
    laWidget_SetScheme((laWidget*)MusicPosition, &NewScheme);
    laWidget_SetBackgroundType((laWidget*)MusicPosition, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)MusicPosition, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)MusicLine, MusicPosition);

    ButtonMusicReceiver = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonMusicReceiver, 420, 150);
    laWidget_SetBackgroundType((laWidget*)ButtonMusicReceiver, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonMusicReceiver, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)MusicPanel, (laWidget*)ButtonMusicReceiver);

    IconPanel = laWidget_New();
    laWidget_SetPosition((laWidget*)IconPanel, 30, 0);
    laWidget_SetSize((laWidget*)IconPanel, 420, 30);
    laWidget_SetScheme((laWidget*)IconPanel, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)IconPanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)IconPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, IconPanel);

    CellSignal = laImageSequenceWidget_New();
    laWidget_SetPosition((laWidget*)CellSignal, 391, 0);
    laWidget_SetSize((laWidget*)CellSignal, 30, 30);
    laWidget_SetScheme((laWidget*)CellSignal, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)CellSignal, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CellSignal, LA_WIDGET_BORDER_NONE);
    laImageSequenceWidget_SetImageCount(CellSignal, 5);
    laImageSequenceWidget_SetImage(CellSignal, 0, &CellSignal05);
    laImageSequenceWidget_SetImage(CellSignal, 1, &CellSignal04);
    laImageSequenceWidget_SetImage(CellSignal, 2, &CellSignal03);
    laImageSequenceWidget_SetImage(CellSignal, 3, &CellSignal02);
    laImageSequenceWidget_SetImage(CellSignal, 4, &CellSignal01);
    laImageSequenceWidget_SetRepeat(CellSignal, LA_TRUE);
    laWidget_AddChild((laWidget*)IconPanel, (laWidget*)CellSignal);

    BatteryPower = laImageSequenceWidget_New();
    laWidget_SetPosition((laWidget*)BatteryPower, 333, 1);
    laWidget_SetSize((laWidget*)BatteryPower, 30, 30);
    laWidget_SetScheme((laWidget*)BatteryPower, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)BatteryPower, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)BatteryPower, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)BatteryPower, 0, 0, 0, 0);
    laImageSequenceWidget_SetImageCount(BatteryPower, 7);
    laImageSequenceWidget_SetImage(BatteryPower, 0, &BatteryCharging);
    laImageSequenceWidget_SetImageVAlignment(BatteryPower, 0, LA_VALIGN_TOP);
    laImageSequenceWidget_SetImage(BatteryPower, 1, &BatteryFull);
    laImageSequenceWidget_SetImageVAlignment(BatteryPower, 1, LA_VALIGN_TOP);
    laImageSequenceWidget_SetImage(BatteryPower, 2, &BatteryThreeQuarter);
    laImageSequenceWidget_SetImageVAlignment(BatteryPower, 2, LA_VALIGN_TOP);
    laImageSequenceWidget_SetImage(BatteryPower, 3, &BatteryHalf);
    laImageSequenceWidget_SetImageVAlignment(BatteryPower, 3, LA_VALIGN_TOP);
    laImageSequenceWidget_SetImage(BatteryPower, 4, &BatteryOneQuarter);
    laImageSequenceWidget_SetImageVAlignment(BatteryPower, 4, LA_VALIGN_TOP);
    laImageSequenceWidget_SetImage(BatteryPower, 5, &BatteryLow);
    laImageSequenceWidget_SetImageVAlignment(BatteryPower, 5, LA_VALIGN_TOP);
    laImageSequenceWidget_SetImage(BatteryPower, 6, &BatteryExtremelyLow);
    laImageSequenceWidget_SetImageVAlignment(BatteryPower, 6, LA_VALIGN_TOP);
    laImageSequenceWidget_SetRepeat(BatteryPower, LA_TRUE);
    laWidget_AddChild((laWidget*)IconPanel, (laWidget*)BatteryPower);

    WifiSignal = laImageSequenceWidget_New();
    laWidget_SetPosition((laWidget*)WifiSignal, 362, 0);
    laWidget_SetSize((laWidget*)WifiSignal, 30, 30);
    laWidget_SetScheme((laWidget*)WifiSignal, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)WifiSignal, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)WifiSignal, LA_WIDGET_BORDER_NONE);
    laImageSequenceWidget_SetImageCount(WifiSignal, 4);
    laImageSequenceWidget_SetImage(WifiSignal, 0, &WifiMedium);
    laImageSequenceWidget_SetImage(WifiSignal, 1, &WifiStrong);
    laImageSequenceWidget_SetImage(WifiSignal, 2, &WifiGood);
    laImageSequenceWidget_SetImage(WifiSignal, 3, &WifiWeak);
    laImageSequenceWidget_SetRepeat(WifiSignal, LA_TRUE);
    laWidget_AddChild((laWidget*)IconPanel, (laWidget*)WifiSignal);

    LabelClock = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelClock, 183, 0);
    laWidget_SetSize((laWidget*)LabelClock, 60, 30);
    laWidget_SetScheme((laWidget*)LabelClock, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelClock, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelClock, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelClock, laString_CreateFromID(string_String_Time));
    laLabelWidget_SetVAlignment(LabelClock, LA_VALIGN_TOP);
    laWidget_AddChild((laWidget*)IconPanel, (laWidget*)LabelClock);

    ImageMCHPLogo = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageMCHPLogo, 0, 2);
    laWidget_SetSize((laWidget*)ImageMCHPLogo, 120, 28);
    laWidget_SetBackgroundType((laWidget*)ImageMCHPLogo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageMCHPLogo, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageMCHPLogo, &mchp_logo);
    laWidget_AddChild((laWidget*)IconPanel, (laWidget*)ImageMCHPLogo);

    LabelACTempLeft = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelACTempLeft, 80, 220);
    laWidget_SetSize((laWidget*)LabelACTempLeft, 60, 30);
    laWidget_SetScheme((laWidget*)LabelACTempLeft, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelACTempLeft, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelACTempLeft, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)LabelACTempLeft, 0, 0, 30, 0);
    laLabelWidget_SetText(LabelACTempLeft, laString_CreateFromID(string_String_ACTemp));
    laLabelWidget_SetHAlignment(LabelACTempLeft, LA_HALIGN_RIGHT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelACTempLeft);

    LabelCelciusLeft = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelCelciusLeft, 30, 0);
    laWidget_SetSize((laWidget*)LabelCelciusLeft, 30, 30);
    laWidget_SetScheme((laWidget*)LabelCelciusLeft, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelCelciusLeft, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelCelciusLeft, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelCelciusLeft, laString_CreateFromID(string_String_TempCelcius));
    laLabelWidget_SetHAlignment(LabelCelciusLeft, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)LabelACTempLeft, (laWidget*)LabelCelciusLeft);

    LabelACTempRight = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelACTempRight, 350, 220);
    laWidget_SetSize((laWidget*)LabelACTempRight, 60, 30);
    laWidget_SetScheme((laWidget*)LabelACTempRight, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelACTempRight, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelACTempRight, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)LabelACTempRight, 0, 0, 30, 0);
    laLabelWidget_SetText(LabelACTempRight, laString_CreateFromID(string_String_ACTemp));
    laLabelWidget_SetHAlignment(LabelACTempRight, LA_HALIGN_RIGHT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelACTempRight);

    LabelCelciusRight = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelCelciusRight, 30, 0);
    laWidget_SetSize((laWidget*)LabelCelciusRight, 30, 30);
    laWidget_SetScheme((laWidget*)LabelCelciusRight, &TextScheme);
    laWidget_SetBackgroundType((laWidget*)LabelCelciusRight, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LabelCelciusRight, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelCelciusRight, laString_CreateFromID(string_String_TempCelcius));
    laLabelWidget_SetHAlignment(LabelCelciusRight, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)LabelACTempRight, (laWidget*)LabelCelciusRight);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0x0);

    laScreen_SetLayer(screen, 1, layer1);

    LeftTrayPanel = laWidget_New();
    laWidget_SetPosition((laWidget*)LeftTrayPanel, -180, 0);
    laWidget_SetSize((laWidget*)LeftTrayPanel, 210, 272);
    laWidget_SetScheme((laWidget*)LeftTrayPanel, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)LeftTrayPanel, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LeftTrayPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer1, LeftTrayPanel);

    LeftTrayLid = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)LeftTrayLid, 180, 0);
    laWidget_SetSize((laWidget*)LeftTrayLid, 30, 272);
    laWidget_SetScheme((laWidget*)LeftTrayLid, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)LeftTrayLid, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)LeftTrayLid, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)LeftTrayLid, 0, 0, 0, 0);
    laButtonWidget_SetPressedImage(LeftTrayLid, &TrayLeftPress);
    laButtonWidget_SetReleasedImage(LeftTrayLid, &TrayLeft);
    laButtonWidget_SetReleasedEventCallback(LeftTrayLid, &LeftTrayLid_ReleasedEvent);

    laWidget_AddChild((laWidget*)LeftTrayPanel, (laWidget*)LeftTrayLid);

    LeftLidArrow = laImageWidget_New();
    laWidget_SetPosition((laWidget*)LeftLidArrow, 15, 120);
    laWidget_SetSize((laWidget*)LeftLidArrow, 7, 30);
    laWidget_SetScheme((laWidget*)LeftLidArrow, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)LeftLidArrow, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LeftLidArrow, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(LeftLidArrow, &LidArrowLeft);
    laWidget_AddChild((laWidget*)LeftTrayLid, (laWidget*)LeftLidArrow);

    PanelWidget = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget, 0, -100);
    laWidget_SetSize((laWidget*)PanelWidget, 180, 480);
    laWidget_SetScheme((laWidget*)PanelWidget, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)LeftTrayPanel, PanelWidget);

    ModeSelector = laRadialMenuWidget_New();
    laWidget_SetSize((laWidget*)ModeSelector, 180, 480);
    laWidget_SetScheme((laWidget*)ModeSelector, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ModeSelector, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ModeSelector, LA_WIDGET_BORDER_NONE);
    laWidget_SetAlphaEnable((laWidget*)ModeSelector, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)ModeSelector, 255);
    laRadialMenuWidget_SetSizeScaling(ModeSelector, LA_RADIAL_MENU_SCALE_GRADUAL);
    laRadialMenuWidget_SetAlphaScaling(ModeSelector, LA_RADIAL_MENU_SCALE_GRADUAL);
    laRadialMenuWidget_SetSizeScaleMinMax(ModeSelector, 60, 100);
    laRadialMenuWidget_SetAlphaScaleMinMax(ModeSelector, 0, 240);
    laRadialMenuWidget_SetTheta(ModeSelector, 90);
    laRadialMenuWidget_SetTouchArea(ModeSelector, 0, 0, 180, 480);
    laRadialMenuWidget_SetEllipseType(ModeSelector, LA_RADIAL_MENU_ELLIPSE_TYPE_ROLLODEX);

    ModeSelector_Item0 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)ModeSelector_Item0, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(ModeSelector_Item0, &Fan);
    laImagePlusWidget_SetTransformWidth(ModeSelector_Item0, 160);
    laImagePlusWidget_SetTransformHeight(ModeSelector_Item0, 160);
    laImagePlusWidget_SetStretchEnabled(ModeSelector_Item0, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(ModeSelector_Item0, LA_TRUE);
    laWidget_SetVisible((laWidget*)ModeSelector_Item0, LA_TRUE);
    laWidget_SetPosition((laWidget*)ModeSelector_Item0, 90, 240);
    laWidget_SetSize((laWidget*)ModeSelector_Item0, 160, 160);
    laRadialMenuWidget_AddWidget(ModeSelector, (laWidget*)ModeSelector_Item0);
    laWidget_AddChild((laWidget*)ModeSelector, (laWidget*)ModeSelector_Item0);

    ModeSelector_Item1 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)ModeSelector_Item1, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(ModeSelector_Item1, &Chargers);
    laImagePlusWidget_SetTransformWidth(ModeSelector_Item1, 134);
    laImagePlusWidget_SetTransformHeight(ModeSelector_Item1, 134);
    laImagePlusWidget_SetStretchEnabled(ModeSelector_Item1, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(ModeSelector_Item1, LA_TRUE);
    laWidget_SetVisible((laWidget*)ModeSelector_Item1, LA_TRUE);
    laWidget_SetPosition((laWidget*)ModeSelector_Item1, 90, 240);
    laWidget_SetSize((laWidget*)ModeSelector_Item1, 160, 160);
    laRadialMenuWidget_AddWidget(ModeSelector, (laWidget*)ModeSelector_Item1);
    laWidget_AddChild((laWidget*)ModeSelector, (laWidget*)ModeSelector_Item1);

    ModeSelector_Item2 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)ModeSelector_Item2, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(ModeSelector_Item2, &Bluetooth);
    laImagePlusWidget_SetTransformWidth(ModeSelector_Item2, 108);
    laImagePlusWidget_SetTransformHeight(ModeSelector_Item2, 108);
    laImagePlusWidget_SetStretchEnabled(ModeSelector_Item2, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(ModeSelector_Item2, LA_TRUE);
    laWidget_SetVisible((laWidget*)ModeSelector_Item2, LA_TRUE);
    laWidget_SetPosition((laWidget*)ModeSelector_Item2, 90, 240);
    laWidget_SetSize((laWidget*)ModeSelector_Item2, 160, 160);
    laRadialMenuWidget_AddWidget(ModeSelector, (laWidget*)ModeSelector_Item2);
    laWidget_AddChild((laWidget*)ModeSelector, (laWidget*)ModeSelector_Item2);

    ModeSelector_Item3 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)ModeSelector_Item3, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(ModeSelector_Item3, &Music);
    laImagePlusWidget_SetTransformWidth(ModeSelector_Item3, 108);
    laImagePlusWidget_SetTransformHeight(ModeSelector_Item3, 108);
    laImagePlusWidget_SetStretchEnabled(ModeSelector_Item3, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(ModeSelector_Item3, LA_TRUE);
    laWidget_SetVisible((laWidget*)ModeSelector_Item3, LA_TRUE);
    laWidget_SetPosition((laWidget*)ModeSelector_Item3, 90, 240);
    laWidget_SetSize((laWidget*)ModeSelector_Item3, 160, 160);
    laRadialMenuWidget_AddWidget(ModeSelector, (laWidget*)ModeSelector_Item3);
    laWidget_AddChild((laWidget*)ModeSelector, (laWidget*)ModeSelector_Item3);

    ModeSelector_Item4 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)ModeSelector_Item4, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(ModeSelector_Item4, &Phone);
    laImagePlusWidget_SetTransformWidth(ModeSelector_Item4, 134);
    laImagePlusWidget_SetTransformHeight(ModeSelector_Item4, 134);
    laImagePlusWidget_SetStretchEnabled(ModeSelector_Item4, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(ModeSelector_Item4, LA_TRUE);
    laWidget_SetVisible((laWidget*)ModeSelector_Item4, LA_TRUE);
    laWidget_SetPosition((laWidget*)ModeSelector_Item4, 90, 240);
    laWidget_SetSize((laWidget*)ModeSelector_Item4, 160, 160);
    laRadialMenuWidget_AddWidget(ModeSelector, (laWidget*)ModeSelector_Item4);
    laWidget_AddChild((laWidget*)ModeSelector, (laWidget*)ModeSelector_Item4);

    laRadialMenuWidget_SetItemProminenceChangedEventCallback(ModeSelector, &ModeSelector_ItemProminenceChangedEvent);
    laRadialMenuWidget_SetNumberOfItemsShown(ModeSelector, 5);
    laWidget_AddChild((laWidget*)PanelWidget, (laWidget*)ModeSelector);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x0);

    laScreen_SetLayer(screen, 2, layer2);

    RightTrayPanel = laWidget_New();
    laWidget_SetPosition((laWidget*)RightTrayPanel, 450, 0);
    laWidget_SetSize((laWidget*)RightTrayPanel, 100, 272);
    laWidget_SetScheme((laWidget*)RightTrayPanel, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)RightTrayPanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RightTrayPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer2, RightTrayPanel);

    RightButtonPanel = laWidget_New();
    laWidget_SetPosition((laWidget*)RightButtonPanel, 30, 0);
    laWidget_SetSize((laWidget*)RightButtonPanel, 70, 272);
    laWidget_SetScheme((laWidget*)RightButtonPanel, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)RightButtonPanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RightButtonPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)RightTrayPanel, RightButtonPanel);

    ButtonGPU = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonGPU, 0, 160);
    laWidget_SetSize((laWidget*)ButtonGPU, 70, 70);
    laWidget_SetScheme((laWidget*)ButtonGPU, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonGPU, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonGPU, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)ButtonGPU, 0, 0, 0, 0);
    laButtonWidget_SetPressedImage(ButtonGPU, &PlainButton);
    laButtonWidget_SetReleasedImage(ButtonGPU, &PlainButton);
    laButtonWidget_SetReleasedEventCallback(ButtonGPU, &ButtonGPU_ReleasedEvent);

    laWidget_AddChild((laWidget*)RightButtonPanel, (laWidget*)ButtonGPU);

    LabelGPU = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelGPU, 5, 5);
    laWidget_SetSize((laWidget*)LabelGPU, 60, 60);
    laWidget_SetScheme((laWidget*)LabelGPU, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)LabelGPU, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelGPU, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelGPU, laString_CreateFromID(string_String_GPUOff));
    laWidget_AddChild((laWidget*)ButtonGPU, (laWidget*)LabelGPU);

    ButtonInfo = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonInfo, 0, 50);
    laWidget_SetSize((laWidget*)ButtonInfo, 70, 70);
    laWidget_SetScheme((laWidget*)ButtonInfo, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonInfo, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonInfo, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)ButtonInfo, 0, 0, 0, 0);
    laButtonWidget_SetPressedImage(ButtonInfo, &PlainButton);
    laButtonWidget_SetReleasedImage(ButtonInfo, &PlainButton);
    laButtonWidget_SetReleasedEventCallback(ButtonInfo, &ButtonInfo_ReleasedEvent);

    laWidget_AddChild((laWidget*)RightButtonPanel, (laWidget*)ButtonInfo);

    ImageTrunk = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageTrunk, 10, 10);
    laWidget_SetSize((laWidget*)ImageTrunk, 50, 50);
    laWidget_SetScheme((laWidget*)ImageTrunk, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)ImageTrunk, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageTrunk, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageTrunk, &Trunk);
    laWidget_AddChild((laWidget*)ButtonInfo, (laWidget*)ImageTrunk);

    RightTrayLid = laButtonWidget_New();
    laWidget_SetSize((laWidget*)RightTrayLid, 30, 272);
    laWidget_SetScheme((laWidget*)RightTrayLid, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)RightTrayLid, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RightTrayLid, LA_WIDGET_BORDER_NONE);
    laWidget_SetMargins((laWidget*)RightTrayLid, 0, 0, 0, 0);
    laButtonWidget_SetPressedImage(RightTrayLid, &TrayRightPress);
    laButtonWidget_SetReleasedImage(RightTrayLid, &TrayRight);
    laButtonWidget_SetReleasedEventCallback(RightTrayLid, &RightTrayLid_ReleasedEvent);

    laWidget_AddChild((laWidget*)RightTrayPanel, (laWidget*)RightTrayLid);

    RightLidArrow = laImageWidget_New();
    laWidget_SetPosition((laWidget*)RightLidArrow, 10, 120);
    laWidget_SetSize((laWidget*)RightLidArrow, 7, 30);
    laWidget_SetScheme((laWidget*)RightLidArrow, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)RightLidArrow, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)RightLidArrow, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(RightLidArrow, &LidArrowRight);
    laWidget_AddChild((laWidget*)RightTrayLid, (laWidget*)RightLidArrow);

    PanelUpChevron = laWidget_New();
    laWidget_SetSize((laWidget*)PanelUpChevron, 180, 30);
    laWidget_SetScheme((laWidget*)PanelUpChevron, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)PanelUpChevron, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelUpChevron, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer2, PanelUpChevron);

    ButtonChevronUp = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonChevronUp, 180, 30);
    laWidget_SetEnabled((laWidget*)ButtonChevronUp, LA_FALSE);
    laWidget_SetVisible((laWidget*)ButtonChevronUp, LA_FALSE);
    laWidget_SetScheme((laWidget*)ButtonChevronUp, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonChevronUp, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonChevronUp, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonChevronUp, &chevron_up);
    laButtonWidget_SetReleasedImage(ButtonChevronUp, &chevron_up);
    laButtonWidget_SetReleasedEventCallback(ButtonChevronUp, &ButtonChevronUp_ReleasedEvent);

    laWidget_AddChild((laWidget*)PanelUpChevron, (laWidget*)ButtonChevronUp);

    PanelDownChevron = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelDownChevron, 0, 242);
    laWidget_SetSize((laWidget*)PanelDownChevron, 180, 30);
    laWidget_SetScheme((laWidget*)PanelDownChevron, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)PanelDownChevron, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelDownChevron, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer2, PanelDownChevron);

    ButtonChevronDown = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonChevronDown, 180, 30);
    laWidget_SetEnabled((laWidget*)ButtonChevronDown, LA_FALSE);
    laWidget_SetVisible((laWidget*)ButtonChevronDown, LA_FALSE);
    laWidget_SetScheme((laWidget*)ButtonChevronDown, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonChevronDown, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonChevronDown, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonChevronDown, &chevron_down);
    laButtonWidget_SetReleasedImage(ButtonChevronDown, &chevron_down);
    laButtonWidget_SetReleasedEventCallback(ButtonChevronDown, &ButtonChevronDown_ReleasedEvent);

    laWidget_AddChild((laWidget*)PanelDownChevron, (laWidget*)ButtonChevronDown);

}

static void ScreenCreate_InfoScreen(laScreen* screen)
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

    InfoPageHarmonyLogo = laImageWidget_New();
    laWidget_SetPosition((laWidget*)InfoPageHarmonyLogo, 0, -1);
    laWidget_SetSize((laWidget*)InfoPageHarmonyLogo, 480, 272);
    laWidget_SetBackgroundType((laWidget*)InfoPageHarmonyLogo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)InfoPageHarmonyLogo, LA_WIDGET_BORDER_NONE);
    laWidget_SetAlphaEnable((laWidget*)InfoPageHarmonyLogo, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)InfoPageHarmonyLogo, 128);
    laImageWidget_SetImage(InfoPageHarmonyLogo, &HarmonyLogo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)InfoPageHarmonyLogo);

    ImageWidget7 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget7, 410, 110);
    laWidget_SetSize((laWidget*)ImageWidget7, 60, 67);
    laWidget_SetBackgroundType((laWidget*)ImageWidget7, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget7, LA_WIDGET_BORDER_NONE);
    laWidget_SetAlphaEnable((laWidget*)ImageWidget7, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)ImageWidget7, 128);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget7);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0xC8);
    laLayer_SetMaskEnable(layer1, LA_TRUE);
    laLayer_SetMaskColor(layer1, 0xFFFFFFFF);

    laScreen_SetLayer(screen, 1, layer1);

    InfoTextDragPanel = laWidget_New();
    laWidget_SetSize((laWidget*)InfoTextDragPanel, 480, 272);
    laWidget_SetScheme((laWidget*)InfoTextDragPanel, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)InfoTextDragPanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)InfoTextDragPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer1, InfoTextDragPanel);

    InfoText = laImageWidget_New();
    laWidget_SetPosition((laWidget*)InfoText, 0, 49);
    laWidget_SetSize((laWidget*)InfoText, 480, 384);
    laWidget_SetScheme((laWidget*)InfoText, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)InfoText, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)InfoText, LA_WIDGET_BORDER_NONE);
    laWidget_SetAlphaEnable((laWidget*)InfoText, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)InfoText, 255);
    laImageWidget_SetImage(InfoText, &info_text_en);
    laImageWidget_SetHAlignment(InfoText, LA_HALIGN_LEFT);
    laImageWidget_SetVAlignment(InfoText, LA_VALIGN_TOP);
    laWidget_AddChild((laWidget*)InfoTextDragPanel, (laWidget*)InfoText);

    PanelWidget1 = laWidget_New();
    laWidget_SetSize((laWidget*)PanelWidget1, 480, 50);
    laWidget_SetScheme((laWidget*)PanelWidget1, &WhiteScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget1, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer1, PanelWidget1);

    TextTitle = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)TextTitle, 10, 0);
    laWidget_SetSize((laWidget*)TextTitle, 470, 50);
    laWidget_SetScheme((laWidget*)TextTitle, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)TextTitle, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)TextTitle, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(TextTitle, laString_CreateFromID(string_String_Features));
    laLabelWidget_SetHAlignment(TextTitle, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget1, (laWidget*)TextTitle);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0xFF);

    laScreen_SetLayer(screen, 2, layer2);

    ReturnToMainButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ReturnToMainButton, 400, 191);
    laWidget_SetSize((laWidget*)ReturnToMainButton, 80, 80);
    laWidget_SetScheme((laWidget*)ReturnToMainButton, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)ReturnToMainButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ReturnToMainButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ReturnToMainButton, &HomeButton);
    laButtonWidget_SetReleasedImage(ReturnToMainButton, &HomeButton);
    laButtonWidget_SetReleasedEventCallback(ReturnToMainButton, &ReturnToMainButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ReturnToMainButton);

    ButtonSplashScreen = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonSplashScreen, 401, 0);
    laWidget_SetSize((laWidget*)ButtonSplashScreen, 80, 80);
    laWidget_SetScheme((laWidget*)ButtonSplashScreen, &ClearScheme);
    laWidget_SetBackgroundType((laWidget*)ButtonSplashScreen, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ButtonSplashScreen, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonSplashScreen, &microchip_button);
    laButtonWidget_SetReleasedImage(ButtonSplashScreen, &microchip_button);
    laButtonWidget_SetReleasedEventCallback(ButtonSplashScreen, &ButtonSplashScreen_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonSplashScreen);

}



int32_t libaria_preprocess_assets(void)
{

    // process images configured for preprocessing
    laUtils_PreprocessImage(&Bar,0xA8C5D000,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&MicrochipLogo,0xA8DCF780,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&Bluetooth,0xA8C7B780,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&Chargers,0xA8BFD000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&Fan,0xA8C94780,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&Music,0xA8CAD780,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&Phone,0xA8CC6780,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&CellSignal01,0xA8E1DE30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&CellSignal02,0xA8E1EE30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&CellSignal03,0xA8E1FE30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&CellSignal04,0xA8E20E30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&CellSignal05,0xA8E21E30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&BatteryExtremelyLow,0xA8E22E30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&BatteryFull,0xA8E23E30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&BatteryHalf,0xA8E24E30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&BatteryLow,0xA8E25E30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&BatteryOneQuarter,0xA8E26E30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&BatteryThreeQuarter,0xA8E27E30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&BatteryCharging,0xA8E28E30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&WifiGood,0xA8E29E30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&WifiMedium,0xA8E2AE30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&WifiStrong,0xA8E2BE30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&WifiWeak,0xA8E2CE30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&chevron_down,0xA8DEC960,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&chevron_up,0xA8DF01A0,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&AC_Both,0xA8DF39E0,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&AC_Face,0xA8DF7220,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&AC_Feet,0xA8DFAA60,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&AC_Intake,0xA8DFE2A0,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&AC_Loop,0xA8E01AE0,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&Defrost,0xA8E05320,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&TrayLeft,0xA8CDF780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&LidArrowLeft,0xA8E2FC70,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&LidArrowRight,0xA8E30070,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&TrayLeftPress,0xA8CEF780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&TrayRight,0xA8CFF780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&TrayRightPress,0xA8D0F780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&PlainButton,0xA8DE8F40,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&Trunk,0xA8DD4F40,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&mchp_logo,0xA8DD8F40,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&OvalButton,0xA8DDCF40,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&OvalButtonPress,0xA8DE0F40,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&PhoneIcon,0xA8E2F630,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover1,0xA8D1F780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover10,0xA8D2F780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover2,0xA8D3F780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover3,0xA8D4F780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover4,0xA8D5F780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover5,0xA8D6F780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover6,0xA8D7F780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover7,0xA8D8F780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover8,0xA8D9F780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover9,0xA8DAF780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&NextTrack,0xA8E0FBE0,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&PlayPause,0xA8E12CA0,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&Shuffle,0xA8E157C0,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&Minus,0xA8E08B60,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&Plus,0xA8E0C3A0,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&VolumeIcon,0xA8E2EE30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&PhoneSmall,0xA8E17E30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&BluetoothLogoSmall,0xA8E19E30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&ChevronSmall,0xA8E1BE30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&PlusSmall,0xA8E2DE30,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&HomeButton,0xA8DBF780,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&microchip_button,0xA8DE4F40,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&info_text_en,0xA8800000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&Background,0xA8C3D000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&ChargeMap,0xA8000000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);

    return 0;
}

