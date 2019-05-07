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
laScheme clearScheme;
laScheme labelModeScheme1;
laScheme titleLabelScheme;
laScheme labelModeScheme0;
laScheme labelModeScheme3;
laScheme GradientScheme;
laScheme labelModeScheme2;
laScheme blackScheme;
laImageWidget* ImageWidget1;
laImageWidget* ImageWidget3;
laImageWidget* ImageWidget2;
laImageWidget* ImageWidget4;
laImageWidget* ImageWidget;
laLabelWidget* LabelWidget3;
laRadialMenuWidget* RadialMenuWidget_Main;
laImagePlusWidget* RadialMenuWidget_Main_Item0;
laImagePlusWidget* RadialMenuWidget_Main_Item1;
laImagePlusWidget* RadialMenuWidget_Main_Item2;
laImagePlusWidget* RadialMenuWidget_Main_Item3;
laButtonWidget* InfoButton;
laLabelWidget* ModeLabel;
laImageWidget* InfoPageHarmonyLogo;
laImageWidget* ImageWidget7;
laImageWidget* ImageWidget;
laWidget* InfoTextDragPanel;
laImageWidget* InfoTextImage;
laWidget* PanelWidget1;
laLabelWidget* TextTitle;
laButtonWidget* ReturnToMainButton;
laButtonWidget* ButtonWidget;
laImageWidget* ImageWidget;
laLabelWidget* LabelWidget;
laButtonWidget* ButtonWidget4;
laRadialMenuWidget* RadialMenuWidget_Album;
laImagePlusWidget* RadialMenuWidget_Album_Item0;
laImagePlusWidget* RadialMenuWidget_Album_Item1;
laImagePlusWidget* RadialMenuWidget_Album_Item2;
laImagePlusWidget* RadialMenuWidget_Album_Item3;
laImagePlusWidget* RadialMenuWidget_Album_Item4;
laImagePlusWidget* RadialMenuWidget_Album_Item5;
laImagePlusWidget* RadialMenuWidget_Album_Item6;
laImagePlusWidget* RadialMenuWidget_Album_Item7;
laImagePlusWidget* RadialMenuWidget_Album_Item8;
laImagePlusWidget* RadialMenuWidget_Album_Item9;
laButtonWidget* ButtonWidget2;
laImageWidget* ImageWidget;
laLabelWidget* LabelWidget7;
laRadialMenuWidget* RadialMenuWidget_Business;
laImagePlusWidget* RadialMenuWidget_Business_Item0;
laImagePlusWidget* RadialMenuWidget_Business_Item1;
laImagePlusWidget* RadialMenuWidget_Business_Item2;
laImagePlusWidget* RadialMenuWidget_Business_Item3;
laImagePlusWidget* RadialMenuWidget_Business_Item4;
laImagePlusWidget* RadialMenuWidget_Business_Item5;
laButtonWidget* ButtonWidget8;
laButtonWidget* ButtonWidget6;
laLabelWidget* LabelWidget2;
laRadialMenuWidget* RadialMenuWidget4;
laImagePlusWidget* RadialMenuWidget4_Item0;
laImagePlusWidget* RadialMenuWidget4_Item1;
laImagePlusWidget* RadialMenuWidget4_Item2;
laImagePlusWidget* RadialMenuWidget4_Item3;
laImagePlusWidget* RadialMenuWidget4_Item4;
laImagePlusWidget* RadialMenuWidget4_Item5;
laImagePlusWidget* RadialMenuWidget4_Item6;
laButtonWidget* ButtonWidget3;
laButtonWidget* ButtonWidget1;


static void ScreenCreate_SplashScreen(laScreen* screen);
static void ScreenCreate_MainScreen(laScreen* screen);
static void ScreenCreate_InfoScreen(laScreen* screen);
static void ScreenCreate_AlbumScreen(laScreen* screen);
static void ScreenCreate_BusinessScreen(laScreen* screen);
static void ScreenCreate_PortraitScreen(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&defaultScheme, GFX_COLOR_MODE_RGBA_8888);
    defaultScheme.base = 0xC8D0D4FF;
    defaultScheme.highlight = 0xC8D0D4FF;
    defaultScheme.highlightLight = 0xFFFFFFFF;
    defaultScheme.shadow = 0x808080FF;
    defaultScheme.shadowDark = 0x404040FF;
    defaultScheme.foreground = 0xE0E0E0FF;
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

    laScheme_Initialize(&clearScheme, GFX_COLOR_MODE_RGBA_8888);
    clearScheme.base = 0x0;
    clearScheme.highlight = 0xC8D0D4FF;
    clearScheme.highlightLight = 0xFFFFFFFF;
    clearScheme.shadow = 0x808080FF;
    clearScheme.shadowDark = 0x404040FF;
    clearScheme.foreground = 0xFF;
    clearScheme.foregroundInactive = 0xD6E3E7FF;
    clearScheme.foregroundDisabled = 0x808080FF;
    clearScheme.background = 0x0;
    clearScheme.backgroundInactive = 0xD6E3E7FF;
    clearScheme.backgroundDisabled = 0xC8D0D4FF;
    clearScheme.text = 0xFF;
    clearScheme.textHighlight = 0xFFFF;
    clearScheme.textHighlightText = 0xFFFFFFFF;
    clearScheme.textInactive = 0xD6E3E7FF;
    clearScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&labelModeScheme1, GFX_COLOR_MODE_RGBA_8888);
    labelModeScheme1.base = 0xC8D0D4FF;
    labelModeScheme1.highlight = 0xC8D0D4FF;
    labelModeScheme1.highlightLight = 0xFFFFFFFF;
    labelModeScheme1.shadow = 0x808080FF;
    labelModeScheme1.shadowDark = 0x404040FF;
    labelModeScheme1.foreground = 0xFF;
    labelModeScheme1.foregroundInactive = 0xD6E3E7FF;
    labelModeScheme1.foregroundDisabled = 0x808080FF;
    labelModeScheme1.background = 0xFFFFFFFF;
    labelModeScheme1.backgroundInactive = 0xD6E3E7FF;
    labelModeScheme1.backgroundDisabled = 0xC8D0D4FF;
    labelModeScheme1.text = 0xFF0000FF;
    labelModeScheme1.textHighlight = 0xFFFF;
    labelModeScheme1.textHighlightText = 0xFFFFFFFF;
    labelModeScheme1.textInactive = 0xD6E3E7FF;
    labelModeScheme1.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&titleLabelScheme, GFX_COLOR_MODE_RGBA_8888);
    titleLabelScheme.base = 0xC8D0D4FF;
    titleLabelScheme.highlight = 0xC8D0D4FF;
    titleLabelScheme.highlightLight = 0xFFFFFFFF;
    titleLabelScheme.shadow = 0x808080FF;
    titleLabelScheme.shadowDark = 0x404040FF;
    titleLabelScheme.foreground = 0xFF;
    titleLabelScheme.foregroundInactive = 0xD6E3E7FF;
    titleLabelScheme.foregroundDisabled = 0x808080FF;
    titleLabelScheme.background = 0xFFFFFFFF;
    titleLabelScheme.backgroundInactive = 0xD6E3E7FF;
    titleLabelScheme.backgroundDisabled = 0xC8D0D4FF;
    titleLabelScheme.text = 0xE0E0E0FF;
    titleLabelScheme.textHighlight = 0xFFFF;
    titleLabelScheme.textHighlightText = 0xFFFFFFFF;
    titleLabelScheme.textInactive = 0xD6E3E7FF;
    titleLabelScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&labelModeScheme0, GFX_COLOR_MODE_RGBA_8888);
    labelModeScheme0.base = 0xC8D0D4FF;
    labelModeScheme0.highlight = 0xC8D0D4FF;
    labelModeScheme0.highlightLight = 0xFFFFFFFF;
    labelModeScheme0.shadow = 0x808080FF;
    labelModeScheme0.shadowDark = 0x404040FF;
    labelModeScheme0.foreground = 0xFF;
    labelModeScheme0.foregroundInactive = 0xD6E3E7FF;
    labelModeScheme0.foregroundDisabled = 0x808080FF;
    labelModeScheme0.background = 0xFFFFFFFF;
    labelModeScheme0.backgroundInactive = 0xD6E3E7FF;
    labelModeScheme0.backgroundDisabled = 0xC8D0D4FF;
    labelModeScheme0.text = 0xFF00FF;
    labelModeScheme0.textHighlight = 0xFFFF;
    labelModeScheme0.textHighlightText = 0xFFFFFFFF;
    labelModeScheme0.textInactive = 0xD6E3E7FF;
    labelModeScheme0.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&labelModeScheme3, GFX_COLOR_MODE_RGBA_8888);
    labelModeScheme3.base = 0xC8D0D4FF;
    labelModeScheme3.highlight = 0xC8D0D4FF;
    labelModeScheme3.highlightLight = 0xFFFFFFFF;
    labelModeScheme3.shadow = 0x808080FF;
    labelModeScheme3.shadowDark = 0x404040FF;
    labelModeScheme3.foreground = 0xFF;
    labelModeScheme3.foregroundInactive = 0xD6E3E7FF;
    labelModeScheme3.foregroundDisabled = 0x808080FF;
    labelModeScheme3.background = 0xFFFFFFFF;
    labelModeScheme3.backgroundInactive = 0xD6E3E7FF;
    labelModeScheme3.backgroundDisabled = 0xC8D0D4FF;
    labelModeScheme3.text = 0xFFA100FF;
    labelModeScheme3.textHighlight = 0xFFFF;
    labelModeScheme3.textHighlightText = 0xFFFFFFFF;
    labelModeScheme3.textInactive = 0xD6E3E7FF;
    labelModeScheme3.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&GradientScheme, GFX_COLOR_MODE_RGBA_8888);
    GradientScheme.base = 0xC8D0D4FF;
    GradientScheme.highlight = 0xC8D0D4FF;
    GradientScheme.highlightLight = 0xFFFFFFFF;
    GradientScheme.shadow = 0x808080FF;
    GradientScheme.shadowDark = 0x404040FF;
    GradientScheme.foreground = 0xFF0000FF;
    GradientScheme.foregroundInactive = 0xFFFF00FF;
    GradientScheme.foregroundDisabled = 0x808080FF;
    GradientScheme.background = 0xFFFFFFFF;
    GradientScheme.backgroundInactive = 0xD6E3E7FF;
    GradientScheme.backgroundDisabled = 0xC8D0D4FF;
    GradientScheme.text = 0xFF;
    GradientScheme.textHighlight = 0xFFFF;
    GradientScheme.textHighlightText = 0xFFFFFFFF;
    GradientScheme.textInactive = 0xD6E3E7FF;
    GradientScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&labelModeScheme2, GFX_COLOR_MODE_RGBA_8888);
    labelModeScheme2.base = 0xC8D0D4FF;
    labelModeScheme2.highlight = 0xC8D0D4FF;
    labelModeScheme2.highlightLight = 0xFFFFFFFF;
    labelModeScheme2.shadow = 0x808080FF;
    labelModeScheme2.shadowDark = 0x404040FF;
    labelModeScheme2.foreground = 0xFF;
    labelModeScheme2.foregroundInactive = 0xD6E3E7FF;
    labelModeScheme2.foregroundDisabled = 0x808080FF;
    labelModeScheme2.background = 0xFFFFFFFF;
    labelModeScheme2.backgroundInactive = 0xD6E3E7FF;
    labelModeScheme2.backgroundDisabled = 0xC8D0D4FF;
    labelModeScheme2.text = 0xFFFF00FF;
    labelModeScheme2.textHighlight = 0xFFFF;
    labelModeScheme2.textHighlightText = 0xFFFFFFFF;
    labelModeScheme2.textInactive = 0xD6E3E7FF;
    labelModeScheme2.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&blackScheme, GFX_COLOR_MODE_RGBA_8888);
    blackScheme.base = 0xC8D0D4FF;
    blackScheme.highlight = 0xC8D0D4FF;
    blackScheme.highlightLight = 0xFFFFFFFF;
    blackScheme.shadow = 0x808080FF;
    blackScheme.shadowDark = 0x404040FF;
    blackScheme.foreground = 0xE0E0E0FF;
    blackScheme.foregroundInactive = 0xD6E3E7FF;
    blackScheme.foregroundDisabled = 0x808080FF;
    blackScheme.background = 0xFF;
    blackScheme.backgroundInactive = 0xD6E3E7FF;
    blackScheme.backgroundDisabled = 0xC8D0D4FF;
    blackScheme.text = 0xFF;
    blackScheme.textHighlight = 0xFFFF;
    blackScheme.textHighlightText = 0xFFFFFFFF;
    blackScheme.textInactive = 0xD6E3E7FF;
    blackScheme.textDisabled = 0x8C9294FF;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    laContext_SetStringTable(&stringTable);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_SplashScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_MainScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_InfoScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_AlbumScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_BusinessScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_PortraitScreen);
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
    laWidget_SetScheme((laWidget*)layer0, &defaultScheme);
    laLayer_SetBufferCount(layer0, 2);
    laLayer_SetAlphaEnable(layer0, LA_TRUE);
    laLayer_SetAlphaAmount(layer0, 0xFF);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget1 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget1, 155, 100);
    laWidget_SetSize((laWidget*)ImageWidget1, 186, 48);
    laWidget_SetBackgroundType((laWidget*)ImageWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget1, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget1, &PIC32Logo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget1);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &clearScheme);
    laLayer_SetBufferCount(layer1, 2);
    laLayer_SetAlphaEnable(layer1, LA_TRUE);
    laLayer_SetAlphaAmount(layer1, 0xFF);
    laLayer_SetVSync(layer1, LA_FALSE);

    laScreen_SetLayer(screen, 1, layer1);

    ImageWidget3 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget3, 480, 217);
    laWidget_SetSize((laWidget*)ImageWidget3, 480, 55);
    laWidget_SetBackgroundType((laWidget*)ImageWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget3, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget3, &Bar);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)ImageWidget3);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &clearScheme);
    laLayer_SetBufferCount(layer2, 2);
    laLayer_SetAlphaEnable(layer2, LA_TRUE);
    laLayer_SetAlphaAmount(layer2, 0x0);
    laLayer_SetVSync(layer2, LA_FALSE);

    laScreen_SetLayer(screen, 2, layer2);

    ImageWidget2 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget2, 167, 70);
    laWidget_SetSize((laWidget*)ImageWidget2, 154, 107);
    laWidget_SetBackgroundType((laWidget*)ImageWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget2, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget2, &HarmonyLogo);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)ImageWidget2);

    ImageWidget4 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget4, 11, 234);
    laWidget_SetSize((laWidget*)ImageWidget4, 100, 27);
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
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget, 480, 272);
    laWidget_SetScheme((laWidget*)ImageWidget, &clearScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget, &TouchBackground);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget);

    LabelWidget3 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget3, 310, 0);
    laWidget_SetSize((laWidget*)LabelWidget3, 170, 40);
    laWidget_SetScheme((laWidget*)LabelWidget3, &titleLabelScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget3, LA_WIDGET_BORDER_NONE);
    laWidget_SetAlphaEnable((laWidget*)LabelWidget3, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)LabelWidget3, 200);
    laLabelWidget_SetText(LabelWidget3, laString_CreateFromID(string_Title));
    laLabelWidget_SetHAlignment(LabelWidget3, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget3);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &clearScheme);
    laLayer_SetBufferCount(layer1, 2);

    laScreen_SetLayer(screen, 1, layer1);

    RadialMenuWidget_Main = laRadialMenuWidget_New();
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Main, 31, 70);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Main, 420, 180);
    laWidget_SetScheme((laWidget*)RadialMenuWidget_Main, &clearScheme);
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Main, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)RadialMenuWidget_Main, LA_WIDGET_BORDER_NONE);
    laWidget_SetAlphaEnable((laWidget*)RadialMenuWidget_Main, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)RadialMenuWidget_Main, 255);
    laRadialMenuWidget_SetSizeScaling(RadialMenuWidget_Main, LA_RADIAL_MENU_SCALE_GRADUAL);
    laRadialMenuWidget_SetAlphaScaling(RadialMenuWidget_Main, LA_RADIAL_MENU_SCALE_GRADUAL);
    laRadialMenuWidget_SetSizeScaleMinMax(RadialMenuWidget_Main, 30, 100);
    laRadialMenuWidget_SetAlphaScaleMinMax(RadialMenuWidget_Main, 0, 255);
    laRadialMenuWidget_SetTheta(RadialMenuWidget_Main, 0);
    laRadialMenuWidget_SetTouchArea(RadialMenuWidget_Main, 0, 81, 420, 99);

    RadialMenuWidget_Main_Item0 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Main_Item0, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Main_Item0, &audio_icons_01);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Main_Item0, 64);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Main_Item0, 64);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Main_Item0, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Main_Item0, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Main_Item0, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Main_Item0, 241, 160);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Main_Item0, 64, 64);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Main, (laWidget*)RadialMenuWidget_Main_Item0);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Main, (laWidget*)RadialMenuWidget_Main_Item0);

    RadialMenuWidget_Main_Item1 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Main_Item1, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Main_Item1, &audio_icons_06);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Main_Item1, 41);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Main_Item1, 41);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Main_Item1, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Main_Item1, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Main_Item1, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Main_Item1, 241, 160);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Main_Item1, 64, 64);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Main, (laWidget*)RadialMenuWidget_Main_Item1);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Main, (laWidget*)RadialMenuWidget_Main_Item1);

    RadialMenuWidget_Main_Item2 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Main_Item2, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Main_Item2, &audio_icons_07);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Main_Item2, 19);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Main_Item2, 19);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Main_Item2, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Main_Item2, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Main_Item2, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Main_Item2, 241, 160);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Main_Item2, 64, 64);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Main, (laWidget*)RadialMenuWidget_Main_Item2);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Main, (laWidget*)RadialMenuWidget_Main_Item2);

    RadialMenuWidget_Main_Item3 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Main_Item3, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Main_Item3, &audio_icons_05);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Main_Item3, 41);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Main_Item3, 41);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Main_Item3, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Main_Item3, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Main_Item3, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Main_Item3, 241, 160);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Main_Item3, 64, 64);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Main, (laWidget*)RadialMenuWidget_Main_Item3);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Main, (laWidget*)RadialMenuWidget_Main_Item3);

    laRadialMenuWidget_SetItemSelectedEventCallback(RadialMenuWidget_Main, &RadialMenuWidget_Main_ItemSelectedEvent);
    laRadialMenuWidget_SetItemProminenceChangedEventCallback(RadialMenuWidget_Main, &RadialMenuWidget_Main_ItemProminenceChangedEvent);
    laRadialMenuWidget_SetNumberOfItemsShown(RadialMenuWidget_Main, 4);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)RadialMenuWidget_Main);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &clearScheme);
    laLayer_SetBufferCount(layer2, 2);

    laScreen_SetLayer(screen, 2, layer2);

    InfoButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)InfoButton, 10, 4);
    laWidget_SetSize((laWidget*)InfoButton, 100, 27);
    laWidget_SetBackgroundType((laWidget*)InfoButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)InfoButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(InfoButton, &MicrochipLogo);
    laButtonWidget_SetReleasedImage(InfoButton, &MicrochipLogo);
    laButtonWidget_SetImagePosition(InfoButton, LA_RELATIVE_POSITION_BEHIND);
    laButtonWidget_SetReleasedEventCallback(InfoButton, &InfoButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)InfoButton);

    ModeLabel = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)ModeLabel, 100, 380);
    laWidget_SetSize((laWidget*)ModeLabel, 600, 50);
    laWidget_SetScheme((laWidget*)ModeLabel, &labelModeScheme0);
    laWidget_SetBackgroundType((laWidget*)ModeLabel, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ModeLabel, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(ModeLabel, laString_CreateFromID(string_Mode1));
    laWidget_AddChild((laWidget*)layer2, (laWidget*)ModeLabel);

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

    laScreen_SetLayer(screen, 0, layer0);

    InfoPageHarmonyLogo = laImageWidget_New();
    laWidget_SetSize((laWidget*)InfoPageHarmonyLogo, 480, 272);
    laWidget_SetBackgroundType((laWidget*)InfoPageHarmonyLogo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)InfoPageHarmonyLogo, LA_WIDGET_BORDER_NONE);
    laWidget_SetAlphaEnable((laWidget*)InfoPageHarmonyLogo, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)InfoPageHarmonyLogo, 128);
    laImageWidget_SetImage(InfoPageHarmonyLogo, &HarmonyLogo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)InfoPageHarmonyLogo);

    ImageWidget7 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget7, 431, 117);
    laWidget_SetSize((laWidget*)ImageWidget7, 30, 34);
    laWidget_SetBackgroundType((laWidget*)ImageWidget7, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget7, LA_WIDGET_BORDER_NONE);
    laWidget_SetAlphaEnable((laWidget*)ImageWidget7, GFX_TRUE);
    laWidget_SetAlphaAmount((laWidget*)ImageWidget7, 128);
    laImageWidget_SetImage(ImageWidget7, &vertical_touch);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget7);

    ImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget, 21, 62);
    laWidget_SetSize((laWidget*)ImageWidget, 100, 100);
    laWidget_SetBackgroundType((laWidget*)ImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &clearScheme);
    laLayer_SetBufferCount(layer1, 2);

    laScreen_SetLayer(screen, 1, layer1);

    InfoTextDragPanel = laWidget_New();
    laWidget_SetSize((laWidget*)InfoTextDragPanel, 480, 1000);
    laWidget_SetScheme((laWidget*)InfoTextDragPanel, &clearScheme);
    laWidget_SetBackgroundType((laWidget*)InfoTextDragPanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)InfoTextDragPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer1, InfoTextDragPanel);

    InfoTextImage = laImageWidget_New();
    laWidget_SetPosition((laWidget*)InfoTextImage, 5, 26);
    laWidget_SetSize((laWidget*)InfoTextImage, 465, 300);
    laWidget_SetBackgroundType((laWidget*)InfoTextImage, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)InfoTextImage, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(InfoTextImage, &info_text);
    laImageWidget_SetHAlignment(InfoTextImage, LA_HALIGN_LEFT);
    laImageWidget_SetVAlignment(InfoTextImage, LA_VALIGN_TOP);
    laWidget_AddChild((laWidget*)InfoTextDragPanel, (laWidget*)InfoTextImage);

    PanelWidget1 = laWidget_New();
    laWidget_SetSize((laWidget*)PanelWidget1, 480, 25);
    laWidget_SetScheme((laWidget*)PanelWidget1, &clearScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget1, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer1, PanelWidget1);

    TextTitle = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)TextTitle, 5, 0);
    laWidget_SetSize((laWidget*)TextTitle, 475, 25);
    laWidget_SetScheme((laWidget*)TextTitle, &defaultScheme);
    laWidget_SetBackgroundType((laWidget*)TextTitle, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TextTitle, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(TextTitle, laString_CreateFromID(string_InfoTitle));
    laLabelWidget_SetHAlignment(TextTitle, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)PanelWidget1, (laWidget*)TextTitle);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &clearScheme);
    laLayer_SetBufferCount(layer2, 2);

    laScreen_SetLayer(screen, 2, layer2);

    ReturnToMainButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ReturnToMainButton, 426, 220);
    laWidget_SetSize((laWidget*)ReturnToMainButton, 45, 45);
    laWidget_SetBackgroundType((laWidget*)ReturnToMainButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ReturnToMainButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ReturnToMainButton, &HomeButton);
    laButtonWidget_SetReleasedImage(ReturnToMainButton, &HomeButton);
    laButtonWidget_SetReleasedEventCallback(ReturnToMainButton, &ReturnToMainButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ReturnToMainButton);

    ButtonWidget = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget, 426, 10);
    laWidget_SetSize((laWidget*)ButtonWidget, 45, 45);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget, &microchip_button);
    laButtonWidget_SetReleasedImage(ButtonWidget, &microchip_button);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget, &ButtonWidget_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonWidget);

}

static void ScreenCreate_AlbumScreen(laScreen* screen)
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

    ImageWidget = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget, 480, 272);
    laWidget_SetBackgroundType((laWidget*)ImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget, &ConcertBackground);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget);

    LabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget, 171, 27);
    laWidget_SetSize((laWidget*)LabelWidget, 130, 25);
    laWidget_SetScheme((laWidget*)LabelWidget, &titleLabelScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget, laString_CreateFromID(string_AlbumTitle));
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget);

    ButtonWidget4 = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonWidget4, 100, 27);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget4, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget4, &MicrochipLogo);
    laButtonWidget_SetReleasedImage(ButtonWidget4, &MicrochipLogo);
    laButtonWidget_SetImagePosition(ButtonWidget4, LA_RELATIVE_POSITION_BEHIND);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget4, &ButtonWidget4_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget4);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &clearScheme);
    laLayer_SetBufferCount(layer1, 2);

    laScreen_SetLayer(screen, 1, layer1);

    RadialMenuWidget_Album = laRadialMenuWidget_New();
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Album, 0, 30);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Album, 480, 201);
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Album, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)RadialMenuWidget_Album, LA_WIDGET_BORDER_NONE);
    laRadialMenuWidget_SetSizeScaling(RadialMenuWidget_Album, LA_RADIAL_MENU_SCALE_PROMINENT);
    laRadialMenuWidget_SetAlphaScaling(RadialMenuWidget_Album, LA_RADIAL_MENU_SCALE_GRADUAL);
    laRadialMenuWidget_SetSizeScaleMinMax(RadialMenuWidget_Album, 30, 100);
    laRadialMenuWidget_SetAlphaScaleMinMax(RadialMenuWidget_Album, 128, 255);
    laRadialMenuWidget_SetTheta(RadialMenuWidget_Album, 8);
    laRadialMenuWidget_SetTouchArea(RadialMenuWidget_Album, 0, 80, 480, 120);
    laRadialMenuWidget_SetEllipseType(RadialMenuWidget_Album, LA_RADIAL_MENU_ELLIPSE_TYPE_ORBITAL);

    RadialMenuWidget_Album_Item0 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Album_Item0, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Album_Item0, &cover1);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Album_Item0, 128);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Album_Item0, 128);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Album_Item0, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Album_Item0, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Album_Item0, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Album_Item0, 240, 130);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Album_Item0, 128, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item0);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item0);

    RadialMenuWidget_Album_Item1 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Album_Item1, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Album_Item1, &cover2);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Album_Item1, 38);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Album_Item1, 38);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Album_Item1, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Album_Item1, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Album_Item1, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Album_Item1, 240, 130);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Album_Item1, 128, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item1);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item1);

    RadialMenuWidget_Album_Item2 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Album_Item2, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Album_Item2, &cover3);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Album_Item2, 38);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Album_Item2, 38);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Album_Item2, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Album_Item2, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Album_Item2, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Album_Item2, 240, 130);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Album_Item2, 128, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item2);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item2);

    RadialMenuWidget_Album_Item3 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Album_Item3, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Album_Item3, &cover4);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Album_Item3, 38);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Album_Item3, 38);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Album_Item3, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Album_Item3, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Album_Item3, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Album_Item3, 240, 130);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Album_Item3, 128, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item3);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item3);

    RadialMenuWidget_Album_Item4 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Album_Item4, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Album_Item4, &cover5);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Album_Item4, 128);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Album_Item4, 128);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Album_Item4, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Album_Item4, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Album_Item4, LA_FALSE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Album_Item4, 240, 130);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Album_Item4, 128, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item4);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item4);

    RadialMenuWidget_Album_Item5 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Album_Item5, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Album_Item5, &cover6);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Album_Item5, 128);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Album_Item5, 128);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Album_Item5, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Album_Item5, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Album_Item5, LA_FALSE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Album_Item5, 240, 130);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Album_Item5, 128, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item5);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item5);

    RadialMenuWidget_Album_Item6 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Album_Item6, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Album_Item6, &cover7);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Album_Item6, 128);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Album_Item6, 128);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Album_Item6, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Album_Item6, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Album_Item6, LA_FALSE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Album_Item6, 240, 130);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Album_Item6, 128, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item6);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item6);

    RadialMenuWidget_Album_Item7 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Album_Item7, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Album_Item7, &cover8);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Album_Item7, 38);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Album_Item7, 38);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Album_Item7, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Album_Item7, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Album_Item7, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Album_Item7, 240, 130);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Album_Item7, 128, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item7);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item7);

    RadialMenuWidget_Album_Item8 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Album_Item8, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Album_Item8, &cover9);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Album_Item8, 38);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Album_Item8, 38);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Album_Item8, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Album_Item8, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Album_Item8, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Album_Item8, 240, 130);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Album_Item8, 128, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item8);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item8);

    RadialMenuWidget_Album_Item9 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Album_Item9, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Album_Item9, &cover10);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Album_Item9, 38);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Album_Item9, 38);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Album_Item9, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Album_Item9, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Album_Item9, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Album_Item9, 240, 130);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Album_Item9, 128, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item9);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Album, (laWidget*)RadialMenuWidget_Album_Item9);

    laRadialMenuWidget_SetNumberOfItemsShown(RadialMenuWidget_Album, 7);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)RadialMenuWidget_Album);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &clearScheme);
    laLayer_SetBufferCount(layer2, 2);

    laScreen_SetLayer(screen, 2, layer2);

    ButtonWidget2 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget2, 430, 220);
    laWidget_SetSize((laWidget*)ButtonWidget2, 45, 45);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget2, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget2, &HomeButton);
    laButtonWidget_SetReleasedImage(ButtonWidget2, &HomeButton);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget2, &ButtonWidget2_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonWidget2);

}

static void ScreenCreate_BusinessScreen(laScreen* screen)
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

    ImageWidget = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget, 480, 272);
    laWidget_SetBackgroundType((laWidget*)ImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget, &MoleculeBackground);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget);

    LabelWidget7 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget7, 340, 1);
    laWidget_SetSize((laWidget*)LabelWidget7, 140, 20);
    laWidget_SetScheme((laWidget*)LabelWidget7, &defaultScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget7, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget7, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget7, laString_CreateFromID(string_RolodexTitle));
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget7);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &clearScheme);
    laLayer_SetBufferCount(layer1, 2);

    laScreen_SetLayer(screen, 1, layer1);

    RadialMenuWidget_Business = laRadialMenuWidget_New();
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Business, 90, 0);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Business, 300, 272);
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Business, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)RadialMenuWidget_Business, LA_WIDGET_BORDER_NONE);
    laRadialMenuWidget_SetSizeScaling(RadialMenuWidget_Business, LA_RADIAL_MENU_SCALE_GRADUAL);
    laRadialMenuWidget_SetAlphaScaling(RadialMenuWidget_Business, LA_RADIAL_MENU_SCALE_GRADUAL);
    laRadialMenuWidget_SetSizeScaleMinMax(RadialMenuWidget_Business, 1, 100);
    laRadialMenuWidget_SetAlphaScaleMinMax(RadialMenuWidget_Business, 128, 255);
    laRadialMenuWidget_SetTheta(RadialMenuWidget_Business, 90);
    laRadialMenuWidget_SetTouchArea(RadialMenuWidget_Business, 0, 0, 300, 272);
    laRadialMenuWidget_SetEllipseType(RadialMenuWidget_Business, LA_RADIAL_MENU_ELLIPSE_TYPE_ROLLODEX);

    RadialMenuWidget_Business_Item0 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Business_Item0, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Business_Item0, &card1);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Business_Item0, 224);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Business_Item0, 128);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Business_Item0, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Business_Item0, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Business_Item0, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Business_Item0, 240, 136);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Business_Item0, 224, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Business, (laWidget*)RadialMenuWidget_Business_Item0);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Business, (laWidget*)RadialMenuWidget_Business_Item0);

    RadialMenuWidget_Business_Item1 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Business_Item1, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Business_Item1, &card2);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Business_Item1, 134);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Business_Item1, 76);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Business_Item1, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Business_Item1, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Business_Item1, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Business_Item1, 240, 136);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Business_Item1, 224, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Business, (laWidget*)RadialMenuWidget_Business_Item1);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Business, (laWidget*)RadialMenuWidget_Business_Item1);

    RadialMenuWidget_Business_Item2 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Business_Item2, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Business_Item2, &card3);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Business_Item2, 47);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Business_Item2, 26);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Business_Item2, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Business_Item2, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Business_Item2, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Business_Item2, 240, 136);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Business_Item2, 224, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Business, (laWidget*)RadialMenuWidget_Business_Item2);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Business, (laWidget*)RadialMenuWidget_Business_Item2);

    RadialMenuWidget_Business_Item3 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Business_Item3, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Business_Item3, &card4);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Business_Item3, 224);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Business_Item3, 128);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Business_Item3, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Business_Item3, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Business_Item3, LA_FALSE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Business_Item3, 240, 136);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Business_Item3, 224, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Business, (laWidget*)RadialMenuWidget_Business_Item3);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Business, (laWidget*)RadialMenuWidget_Business_Item3);

    RadialMenuWidget_Business_Item4 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Business_Item4, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Business_Item4, &card5);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Business_Item4, 47);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Business_Item4, 26);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Business_Item4, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Business_Item4, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Business_Item4, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Business_Item4, 240, 136);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Business_Item4, 224, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Business, (laWidget*)RadialMenuWidget_Business_Item4);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Business, (laWidget*)RadialMenuWidget_Business_Item4);

    RadialMenuWidget_Business_Item5 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget_Business_Item5, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget_Business_Item5, &card6);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget_Business_Item5, 134);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget_Business_Item5, 76);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget_Business_Item5, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget_Business_Item5, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget_Business_Item5, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget_Business_Item5, 240, 136);
    laWidget_SetSize((laWidget*)RadialMenuWidget_Business_Item5, 224, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget_Business, (laWidget*)RadialMenuWidget_Business_Item5);
    laWidget_AddChild((laWidget*)RadialMenuWidget_Business, (laWidget*)RadialMenuWidget_Business_Item5);

    laRadialMenuWidget_SetNumberOfItemsShown(RadialMenuWidget_Business, 5);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)RadialMenuWidget_Business);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &clearScheme);
    laLayer_SetBufferCount(layer2, 2);

    laScreen_SetLayer(screen, 2, layer2);

    ButtonWidget8 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget8, 426, 220);
    laWidget_SetSize((laWidget*)ButtonWidget8, 45, 45);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget8, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget8, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget8, &HomeButton);
    laButtonWidget_SetReleasedImage(ButtonWidget8, &HomeButton);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget8, &ButtonWidget8_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonWidget8);

    ButtonWidget6 = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonWidget6, 100, 25);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget6, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget6, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget6, &MicrochipLogo);
    laButtonWidget_SetReleasedImage(ButtonWidget6, &MicrochipLogo);
    laButtonWidget_SetImagePosition(ButtonWidget6, LA_RELATIVE_POSITION_BEHIND);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget6, &ButtonWidget6_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonWidget6);

}

static void ScreenCreate_PortraitScreen(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &blackScheme);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    LabelWidget2 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget2, 331, 1);
    laWidget_SetSize((laWidget*)LabelWidget2, 140, 20);
    laWidget_SetScheme((laWidget*)LabelWidget2, &titleLabelScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget2, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget2, laString_CreateFromID(string_PortraitTitle));
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget2);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &clearScheme);
    laLayer_SetBufferCount(layer1, 2);

    laScreen_SetLayer(screen, 1, layer1);

    RadialMenuWidget4 = laRadialMenuWidget_New();
    laWidget_SetPosition((laWidget*)RadialMenuWidget4, 0, 61);
    laWidget_SetSize((laWidget*)RadialMenuWidget4, 480, 170);
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)RadialMenuWidget4, LA_WIDGET_BORDER_NONE);
    laRadialMenuWidget_SetSizeScaling(RadialMenuWidget4, LA_RADIAL_MENU_SCALE_GRADUAL);
    laRadialMenuWidget_SetAlphaScaling(RadialMenuWidget4, LA_RADIAL_MENU_SCALE_GRADUAL);
    laRadialMenuWidget_SetSizeScaleMinMax(RadialMenuWidget4, 30, 90);
    laRadialMenuWidget_SetAlphaScaleMinMax(RadialMenuWidget4, 128, 255);
    laRadialMenuWidget_SetTheta(RadialMenuWidget4, 0);
    laRadialMenuWidget_SetTouchArea(RadialMenuWidget4, 0, 68, 480, 102);

    RadialMenuWidget4_Item0 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget4_Item0, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget4_Item0, &portrait01);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget4_Item0, 150);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget4_Item0, 115);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget4_Item0, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget4_Item0, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget4_Item0, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget4_Item0, 240, 146);
    laWidget_SetSize((laWidget*)RadialMenuWidget4_Item0, 167, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget4, (laWidget*)RadialMenuWidget4_Item0);
    laWidget_AddChild((laWidget*)RadialMenuWidget4, (laWidget*)RadialMenuWidget4_Item0);

    RadialMenuWidget4_Item1 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget4_Item1, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget4_Item1, &portrait02);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget4_Item1, 93);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget4_Item1, 64);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget4_Item1, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget4_Item1, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget4_Item1, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget4_Item1, 240, 146);
    laWidget_SetSize((laWidget*)RadialMenuWidget4_Item1, 186, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget4, (laWidget*)RadialMenuWidget4_Item1);
    laWidget_AddChild((laWidget*)RadialMenuWidget4, (laWidget*)RadialMenuWidget4_Item1);

    RadialMenuWidget4_Item2 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget4_Item2, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget4_Item2, &portrait03);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget4_Item2, 230);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget4_Item2, 128);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget4_Item2, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget4_Item2, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget4_Item2, LA_FALSE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget4_Item2, 240, 146);
    laWidget_SetSize((laWidget*)RadialMenuWidget4_Item2, 230, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget4, (laWidget*)RadialMenuWidget4_Item2);
    laWidget_AddChild((laWidget*)RadialMenuWidget4, (laWidget*)RadialMenuWidget4_Item2);

    RadialMenuWidget4_Item3 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget4_Item3, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget4_Item3, &portrait04);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget4_Item3, 91);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget4_Item3, 128);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget4_Item3, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget4_Item3, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget4_Item3, LA_FALSE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget4_Item3, 240, 146);
    laWidget_SetSize((laWidget*)RadialMenuWidget4_Item3, 91, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget4, (laWidget*)RadialMenuWidget4_Item3);
    laWidget_AddChild((laWidget*)RadialMenuWidget4, (laWidget*)RadialMenuWidget4_Item3);

    RadialMenuWidget4_Item4 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget4_Item4, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget4_Item4, &portrait05);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget4_Item4, 95);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget4_Item4, 128);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget4_Item4, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget4_Item4, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget4_Item4, LA_FALSE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget4_Item4, 240, 146);
    laWidget_SetSize((laWidget*)RadialMenuWidget4_Item4, 95, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget4, (laWidget*)RadialMenuWidget4_Item4);
    laWidget_AddChild((laWidget*)RadialMenuWidget4, (laWidget*)RadialMenuWidget4_Item4);

    RadialMenuWidget4_Item5 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget4_Item5, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget4_Item5, &portrait06);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget4_Item5, 91);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget4_Item5, 128);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget4_Item5, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget4_Item5, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget4_Item5, LA_FALSE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget4_Item5, 240, 146);
    laWidget_SetSize((laWidget*)RadialMenuWidget4_Item5, 91, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget4, (laWidget*)RadialMenuWidget4_Item5);
    laWidget_AddChild((laWidget*)RadialMenuWidget4, (laWidget*)RadialMenuWidget4_Item5);

    RadialMenuWidget4_Item6 = laImagePlusWidget_New();
    laWidget_SetBackgroundType((laWidget*)RadialMenuWidget4_Item6, LA_WIDGET_BACKGROUND_NONE);
    laImagePlusWidget_SetImage(RadialMenuWidget4_Item6, &portrait07);
    laImagePlusWidget_SetTransformWidth(RadialMenuWidget4_Item6, 52);
    laImagePlusWidget_SetTransformHeight(RadialMenuWidget4_Item6, 64);
    laImagePlusWidget_SetStretchEnabled(RadialMenuWidget4_Item6, LA_TRUE);
    laImagePlusWidget_SetPreserveAspectEnabled(RadialMenuWidget4_Item6, LA_TRUE);
    laWidget_SetVisible((laWidget*)RadialMenuWidget4_Item6, LA_TRUE);
    laWidget_SetPosition((laWidget*)RadialMenuWidget4_Item6, 240, 146);
    laWidget_SetSize((laWidget*)RadialMenuWidget4_Item6, 104, 128);
    laRadialMenuWidget_AddWidget(RadialMenuWidget4, (laWidget*)RadialMenuWidget4_Item6);
    laWidget_AddChild((laWidget*)RadialMenuWidget4, (laWidget*)RadialMenuWidget4_Item6);

    laRadialMenuWidget_SetNumberOfItemsShown(RadialMenuWidget4, 3);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)RadialMenuWidget4);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &clearScheme);
    laLayer_SetBufferCount(layer2, 2);

    laScreen_SetLayer(screen, 2, layer2);

    ButtonWidget3 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget3, 426, 220);
    laWidget_SetSize((laWidget*)ButtonWidget3, 45, 45);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget3, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget3, &HomeButton);
    laButtonWidget_SetReleasedImage(ButtonWidget3, &HomeButton);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget3, &ButtonWidget3_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonWidget3);

    ButtonWidget1 = laButtonWidget_New();
    laWidget_SetSize((laWidget*)ButtonWidget1, 100, 25);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget1, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ButtonWidget1, &MicrochipLogo);
    laButtonWidget_SetReleasedImage(ButtonWidget1, &MicrochipLogo);
    laButtonWidget_SetImagePosition(ButtonWidget1, LA_RELATIVE_POSITION_BEHIND);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget1, &ButtonWidget1_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)ButtonWidget1);

}



int32_t libaria_preprocess_assets(void)
{

    // process images configured for preprocessing
    laUtils_PreprocessImage(&Bar,0xA83FD000,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&question_button,0xA8416C80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&HomeButton,0xA8426C80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&audio_icons_01,0xA842AC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&audio_icons_05,0xA842EC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&audio_icons_06,0xA8432C80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&audio_icons_07,0xA8436C80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&portrait01,0xA843AC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&portrait02,0xA845AC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&portrait03,0xA847AC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&portrait07,0xA849AC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&portrait05,0xA84AAC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&portrait04,0xA84BAC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&portrait06,0xA84CAC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&ConcertBackground,0xA84DAC80,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&MoleculeBackground,0xA8561C80,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&TouchBackground,0xA85E8C80,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover1,0xA866FC80,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover10,0xA867FC80,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover2,0xA868FC80,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover3,0xA869FC80,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover4,0xA86AFC80,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover5,0xA86BFC80,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover6,0xA86CFC80,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover7,0xA86DFC80,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover8,0xA86EFC80,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&cover9,0xA86FFC80,GFX_COLOR_MODE_RGBA_8888,GFX_FALSE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&card1,0xA870FC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&card2,0xA872FC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&card3,0xA874FC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&card4,0xA876FC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&card5,0xA878FC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&card6,0xA87AFC80,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&info_text,0xA82FD000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);

    return 0;
}

