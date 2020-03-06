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

laScheme defaultScheme;
laScheme TouchTestScheme;
laImageWidget* ImageWidget1;
laImageWidget* ImageWidget2;
laWidget* PanelWidget3;
laImageWidget* ImageWidget3;
laImageWidget* ImageWidget4;
laLabelWidget* LabelWidget1;
laImageWidget* ImageWidget;
laButtonWidget* mainLoadButton;
laButtonWidget* mainTestButton;
laImageWidget* ImageWidget;
laImageWidget* ImageWidget;
laImageWidget* ImageWidget5;
laImageWidget* ImageWidget6;
laImageWidget* ImageWidget8;
laImageWidget* ImageWidget10;
laButtonWidget* loadButton;
laProgressBarWidget* loadProgressBar;
laLabelWidget* LabelWidget13;
laButtonWidget* ButtonWidget14;
laLabelWidget* LabelWidget15;
laRadioButtonWidget* loadProgramRadioButton;
laRadioButtonWidget* loadSDCardRadioButton;
laRadioButtonWidget* loadUSBRadioButton;
laRadioButtonWidget* loadPCRadioButton;
laButtonWidget* loadProgramButton;
laButtonWidget* loadSDCardButton;
laButtonWidget* loadPCButton;
laButtonWidget* loadUSBBUtton;
laButtonWidget* loadNextButton;
laKeyPadWidget* KeyPadWidget2;
laButtonWidget* ButtonWidget3;
laButtonWidget* ButtonWidget4;
laLabelWidget* LabelWidget6;
laTouchTestWidget* TouchTestWidget25;
laButtonWidget* ButtonWidget20;
laLabelWidget* LabelWidget32;
laButtonWidget* testStoreButton;
laButtonWidget* ButtonWidget5;
laProgressBarWidget* storeProgressBar;
laButtonWidget* ButtonWidget21;
laButtonWidget* storeSaveButton;
laImageWidget* ImageWidget29;
laLabelWidget* LabelWidget30;
laImageWidget* ImageWidget34;
laButtonWidget* storeDoneButton;


static void ScreenCreate_splash_screen(laScreen* screen);
static void ScreenCreate_main_screen(laScreen* screen);
static void ScreenCreate_load_screen(laScreen* screen);
static void ScreenCreate_test_screen_buttons(laScreen* screen);
static void ScreenCreate_test_screen(laScreen* screen);
static void ScreenCreate_store_screen(laScreen* screen);


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
    defaultScheme.textHighlight = 0x7FF;
    defaultScheme.textHighlightText = 0xFFFF;
    defaultScheme.textInactive = 0xD71C;
    defaultScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&TouchTestScheme, GFX_COLOR_MODE_RGB_565);
    TouchTestScheme.base = 0x7E0;
    TouchTestScheme.highlight = 0xFC00;
    TouchTestScheme.highlightLight = 0xFFFF;
    TouchTestScheme.shadow = 0x8410;
    TouchTestScheme.shadowDark = 0x4208;
    TouchTestScheme.foreground = 0x0;
    TouchTestScheme.foregroundInactive = 0xD71C;
    TouchTestScheme.foregroundDisabled = 0x8410;
    TouchTestScheme.background = 0x5F7;
    TouchTestScheme.backgroundInactive = 0x200;
    TouchTestScheme.backgroundDisabled = 0xF81F;
    TouchTestScheme.text = 0x17;
    TouchTestScheme.textHighlight = 0xF800;
    TouchTestScheme.textHighlightText = 0xFFFF;
    TouchTestScheme.textInactive = 0xD71C;
    TouchTestScheme.textDisabled = 0x8C92;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCU);
    laContext_SetStringTable(&stringTable);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_splash_screen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_main_screen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_load_screen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_test_screen_buttons);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_test_screen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_store_screen);
    laContext_AddScreen(screen);

    laContext_SetActiveScreen(1);

	return 0;
}

static void ScreenCreate_splash_screen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 2);
    laWidget_SetOptimizationFlags((laWidget*)layer0, LA_WIDGET_OPT_DRAW_ONCE);
    laLayer_SetAlphaEnable(layer0, LA_TRUE);
    laLayer_SetAlphaAmount(layer0, 0xFF);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget1 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget1, 124, 69);
    laWidget_SetSize((laWidget*)ImageWidget1, 240, 139);
    laWidget_SetBackgroundType((laWidget*)ImageWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget1, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget1, &HarmonyLogo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget1);

    ImageWidget2 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget2, 124, 69);
    laWidget_SetSize((laWidget*)ImageWidget2, 240, 139);
    laWidget_SetVisible((laWidget*)ImageWidget2, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)ImageWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget2, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget2, &PIC32Logo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget2);

    PanelWidget3 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget3, 0, 215);
    laWidget_SetSize((laWidget*)PanelWidget3, 480, 65);
    laWidget_SetOptimizationFlags((laWidget*)PanelWidget3, LA_WIDGET_OPT_DRAW_ONCE);
    laWidget_SetBackgroundType((laWidget*)PanelWidget3, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget3, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget3);

    ImageWidget3 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget3, 272, 0);
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

static void ScreenCreate_main_screen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    LabelWidget1 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget1, 156, 10);
    laWidget_SetSize((laWidget*)LabelWidget1, 179, 39);
    laWidget_SetBackgroundType((laWidget*)LabelWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget1, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget1, laString_CreateFromID(string_GFX_MXT_Configure));
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget1);

    ImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget, 113, 49);
    laWidget_SetSize((laWidget*)ImageWidget, 242, 150);
    laWidget_SetBackgroundType((laWidget*)ImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget, &controller);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget);

    mainLoadButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)mainLoadButton, 76, 211);
    laWidget_SetSize((laWidget*)mainLoadButton, 111, 40);
    laWidget_SetBackgroundType((laWidget*)mainLoadButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)mainLoadButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(mainLoadButton, laString_CreateFromID(string_Configure));
    laButtonWidget_SetReleasedEventCallback(mainLoadButton, &mainLoadButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)mainLoadButton);

    mainTestButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)mainTestButton, 290, 210);
    laWidget_SetSize((laWidget*)mainTestButton, 111, 40);
    laWidget_SetBackgroundType((laWidget*)mainTestButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)mainTestButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(mainTestButton, laString_CreateFromID(string_Test));
    laButtonWidget_SetReleasedEventCallback(mainTestButton, &mainTestButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)mainTestButton);

    ImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget, 30, 12);
    laWidget_SetSize((laWidget*)ImageWidget, 98, 88);
    laWidget_SetBackgroundType((laWidget*)ImageWidget, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget, &mosture);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget);

    ImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget, 340, 10);
    laWidget_SetSize((laWidget*)ImageWidget, 100, 78);
    laWidget_SetBackgroundType((laWidget*)ImageWidget, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget, &glove);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget);

    ImageWidget5 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget5, 6, 120);
    laWidget_SetSize((laWidget*)ImageWidget5, 74, 81);
    laWidget_SetBackgroundType((laWidget*)ImageWidget5, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageWidget5, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget5, &passive_stylus);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget5);

    ImageWidget6 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget6, 430, 82);
    laWidget_SetSize((laWidget*)ImageWidget6, 48, 119);
    laWidget_SetBackgroundType((laWidget*)ImageWidget6, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageWidget6, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget6, &active_stylus);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget6);

}

static void ScreenCreate_load_screen(laScreen* screen)
{
    laLayer* layer0;
    laRadioButtonGroup* radioButtonGroup_0;

    laScreen_SetShowEventCallback(screen, &load_screen_ShowEvent);

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget8 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget8, 271, 152);
    laWidget_SetSize((laWidget*)ImageWidget8, 200, 105);
    laWidget_SetBackgroundType((laWidget*)ImageWidget8, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget8, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget8, &flash);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget8);

    ImageWidget10 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget10, 344, 115);
    laWidget_SetSize((laWidget*)ImageWidget10, 48, 26);
    laWidget_SetVisible((laWidget*)ImageWidget10, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)ImageWidget10, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget10, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget10, &down_arrow);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget10);

    loadButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)loadButton, 332, 70);
    laWidget_SetSize((laWidget*)loadButton, 74, 41);
    laWidget_SetVisible((laWidget*)loadButton, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)loadButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)loadButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(loadButton, laString_CreateFromID(string_Load));
    laButtonWidget_SetReleasedEventCallback(loadButton, &loadButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)loadButton);

    loadProgressBar = laProgressBarWidget_New();
    laWidget_SetPosition((laWidget*)loadProgressBar, 50, 70);
    laWidget_SetSize((laWidget*)loadProgressBar, 250, 25);
    laWidget_SetScheme((laWidget*)loadProgressBar, &defaultScheme);
    laWidget_SetBackgroundType((laWidget*)loadProgressBar, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)loadProgressBar, LA_WIDGET_BORDER_BEVEL);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)loadProgressBar);

    LabelWidget13 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget13, 125, 10);
    laWidget_SetSize((laWidget*)LabelWidget13, 225, 25);
    laWidget_SetScheme((laWidget*)LabelWidget13, &defaultScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget13, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget13, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget13, laString_CreateFromID(string_load_title));
    laLabelWidget_SetHAlignment(LabelWidget13, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget13);

    ButtonWidget14 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget14, 2, 2);
    laWidget_SetSize((laWidget*)ButtonWidget14, 60, 50);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget14, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget14, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonWidget14, &back);
    laButtonWidget_SetReleasedImage(ButtonWidget14, &back);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget14, &ButtonWidget14_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget14);

    LabelWidget15 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget15, 1, 120);
    laWidget_SetSize((laWidget*)LabelWidget15, 169, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget15, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget15, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget15, laString_CreateFromID(string_load_source));
    laLabelWidget_SetHAlignment(LabelWidget15, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget15);

    loadProgramRadioButton = laRadioButtonWidget_New();
    laWidget_SetPosition((laWidget*)loadProgramRadioButton, 10, 153);
    laWidget_SetSize((laWidget*)loadProgramRadioButton, 110, 48);
    laWidget_SetBackgroundType((laWidget*)loadProgramRadioButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)loadProgramRadioButton, LA_WIDGET_BORDER_NONE);
    laRadioButtonWidget_SetText(loadProgramRadioButton, laString_CreateFromID(string_load_programflash));
    laRadioButtonWidget_SetHAlignment(loadProgramRadioButton, LA_HALIGN_LEFT);
    laRadioButtonGroup_Create(&radioButtonGroup_0);
    laRadioButtonGroup_AddButton(radioButtonGroup_0, loadProgramRadioButton);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)loadProgramRadioButton);

    loadSDCardRadioButton = laRadioButtonWidget_New();
    laWidget_SetPosition((laWidget*)loadSDCardRadioButton, 10, 211);
    laWidget_SetSize((laWidget*)loadSDCardRadioButton, 110, 47);
    laWidget_SetBackgroundType((laWidget*)loadSDCardRadioButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)loadSDCardRadioButton, LA_WIDGET_BORDER_NONE);
    laRadioButtonWidget_SetText(loadSDCardRadioButton, laString_CreateFromID(string_load_sdcard));
    laRadioButtonWidget_SetHAlignment(loadSDCardRadioButton, LA_HALIGN_LEFT);
    laRadioButtonGroup_AddButton(radioButtonGroup_0, loadSDCardRadioButton);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)loadSDCardRadioButton);

    loadUSBRadioButton = laRadioButtonWidget_New();
    laWidget_SetPosition((laWidget*)loadUSBRadioButton, 150, 211);
    laWidget_SetSize((laWidget*)loadUSBRadioButton, 110, 48);
    laWidget_SetEnabled((laWidget*)loadUSBRadioButton, LA_FALSE);
    laWidget_SetVisible((laWidget*)loadUSBRadioButton, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)loadUSBRadioButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)loadUSBRadioButton, LA_WIDGET_BORDER_NONE);
    laRadioButtonWidget_SetText(loadUSBRadioButton, laString_CreateFromID(string_load_usbdrive));
    laRadioButtonWidget_SetHAlignment(loadUSBRadioButton, LA_HALIGN_LEFT);
    laRadioButtonGroup_AddButton(radioButtonGroup_0, loadUSBRadioButton);
    laRadioButtonWidget_SetSelected(loadUSBRadioButton);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)loadUSBRadioButton);

    loadPCRadioButton = laRadioButtonWidget_New();
    laWidget_SetPosition((laWidget*)loadPCRadioButton, 145, 153);
    laWidget_SetSize((laWidget*)loadPCRadioButton, 110, 48);
    laWidget_SetBackgroundType((laWidget*)loadPCRadioButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)loadPCRadioButton, LA_WIDGET_BORDER_NONE);
    laRadioButtonWidget_SetText(loadPCRadioButton, laString_CreateFromID(string_load_pc));
    laRadioButtonWidget_SetHAlignment(loadPCRadioButton, LA_HALIGN_LEFT);
    laRadioButtonGroup_AddButton(radioButtonGroup_0, loadPCRadioButton);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)loadPCRadioButton);

    loadProgramButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)loadProgramButton, 10, 153);
    laWidget_SetSize((laWidget*)loadProgramButton, 110, 48);
    laWidget_SetBackgroundType((laWidget*)loadProgramButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)loadProgramButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetReleasedEventCallback(loadProgramButton, &loadProgramButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)loadProgramButton);

    loadSDCardButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)loadSDCardButton, 10, 211);
    laWidget_SetSize((laWidget*)loadSDCardButton, 110, 47);
    laWidget_SetBackgroundType((laWidget*)loadSDCardButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)loadSDCardButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetReleasedEventCallback(loadSDCardButton, &loadSDCardButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)loadSDCardButton);

    loadPCButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)loadPCButton, 145, 153);
    laWidget_SetSize((laWidget*)loadPCButton, 110, 48);
    laWidget_SetBackgroundType((laWidget*)loadPCButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)loadPCButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetReleasedEventCallback(loadPCButton, &loadPCButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)loadPCButton);

    loadUSBBUtton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)loadUSBBUtton, 145, 213);
    laWidget_SetSize((laWidget*)loadUSBBUtton, 110, 48);
    laWidget_SetVisible((laWidget*)loadUSBBUtton, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)loadUSBBUtton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)loadUSBBUtton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetReleasedEventCallback(loadUSBBUtton, &loadUSBBUtton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)loadUSBBUtton);

    loadNextButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)loadNextButton, 422, 2);
    laWidget_SetSize((laWidget*)loadNextButton, 60, 50);
    laWidget_SetBackgroundType((laWidget*)loadNextButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)loadNextButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(loadNextButton, &forward);
    laButtonWidget_SetReleasedImage(loadNextButton, &forward);
    laButtonWidget_SetReleasedEventCallback(loadNextButton, &loadNextButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)loadNextButton);

}

static void ScreenCreate_test_screen_buttons(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);

    laScreen_SetLayer(screen, 0, layer0);

    KeyPadWidget2 = laKeyPadWidget_New(5, 5);
    laWidget_SetPosition((laWidget*)KeyPadWidget2, 20, 60);
    laWidget_SetSize((laWidget*)KeyPadWidget2, 440, 200);
    laWidget_SetBackgroundType((laWidget*)KeyPadWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)KeyPadWidget2, LA_WIDGET_BORDER_BEVEL);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 0, 0, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 0, 0, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 0, 1, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 0, 1, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 0, 2, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 0, 2, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 0, 3, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 0, 3, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 0, 4, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 0, 4, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 1, 0, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 1, 0, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 1, 1, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 1, 1, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 1, 2, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 1, 2, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 1, 3, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 1, 3, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 1, 4, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 1, 4, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 2, 0, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 2, 0, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 2, 1, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 2, 1, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 2, 2, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 2, 2, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 2, 3, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 2, 3, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 2, 4, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 2, 4, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 3, 0, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 3, 0, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 3, 1, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 3, 1, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 3, 2, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 3, 2, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 3, 3, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 3, 3, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 3, 4, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 3, 4, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 4, 0, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 4, 0, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 4, 1, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 4, 1, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 4, 2, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 4, 2, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 4, 3, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 4, 3, LA_RELATIVE_POSITION_BEHIND);
    laKeyPadWidget_SetKeyAction(KeyPadWidget2, 4, 4, LA_KEYPAD_CELL_ACTION_NONE);
    laKeyPadWidget_SetKeyImagePosition(KeyPadWidget2, 4, 4, LA_RELATIVE_POSITION_BEHIND);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)KeyPadWidget2);

    ButtonWidget3 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget3, 2, 2);
    laWidget_SetSize((laWidget*)ButtonWidget3, 60, 50);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget3, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonWidget3, &back);
    laButtonWidget_SetReleasedImage(ButtonWidget3, &back);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget3, &ButtonWidget3_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget3);

    ButtonWidget4 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget4, 422, 2);
    laWidget_SetSize((laWidget*)ButtonWidget4, 60, 50);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget4, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonWidget4, &forward);
    laButtonWidget_SetReleasedImage(ButtonWidget4, &forward);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget4, &ButtonWidget4_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget4);

    LabelWidget6 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget6, 135, 10);
    laWidget_SetSize((laWidget*)LabelWidget6, 205, 25);
    laWidget_SetScheme((laWidget*)LabelWidget6, &defaultScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget6, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget6, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget6, laString_CreateFromID(string_button_test));
    laLabelWidget_SetHAlignment(LabelWidget6, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget6);

}

static void ScreenCreate_test_screen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);

    laScreen_SetLayer(screen, 0, layer0);

    TouchTestWidget25 = laTouchTestWidget_New();
    laWidget_SetSize((laWidget*)TouchTestWidget25, 480, 272);
    laWidget_SetScheme((laWidget*)TouchTestWidget25, &TouchTestScheme);
    laWidget_SetBackgroundType((laWidget*)TouchTestWidget25, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TouchTestWidget25, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)TouchTestWidget25);

    ButtonWidget20 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget20, 2, 2);
    laWidget_SetSize((laWidget*)ButtonWidget20, 60, 50);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget20, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget20, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonWidget20, &back);
    laButtonWidget_SetReleasedImage(ButtonWidget20, &back);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget20, &ButtonWidget20_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget20);

    LabelWidget32 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget32, 160, 10);
    laWidget_SetSize((laWidget*)LabelWidget32, 162, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget32, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget32, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget32, laString_CreateFromID(string_test_title));
    laLabelWidget_SetHAlignment(LabelWidget32, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget32);

    testStoreButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)testStoreButton, 170, 221);
    laWidget_SetSize((laWidget*)testStoreButton, 130, 40);
    laWidget_SetEnabled((laWidget*)testStoreButton, LA_FALSE);
    laWidget_SetVisible((laWidget*)testStoreButton, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)testStoreButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)testStoreButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(testStoreButton, laString_CreateFromID(string_Store));
    laButtonWidget_SetReleasedEventCallback(testStoreButton, &testStoreButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)testStoreButton);

    ButtonWidget5 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget5, 422, 2);
    laWidget_SetSize((laWidget*)ButtonWidget5, 60, 50);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget5, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget5, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonWidget5, &forward);
    laButtonWidget_SetReleasedImage(ButtonWidget5, &forward);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget5, &ButtonWidget5_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget5);

}

static void ScreenCreate_store_screen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);

    laScreen_SetLayer(screen, 0, layer0);

    storeProgressBar = laProgressBarWidget_New();
    laWidget_SetPosition((laWidget*)storeProgressBar, 50, 80);
    laWidget_SetSize((laWidget*)storeProgressBar, 250, 25);
    laWidget_SetScheme((laWidget*)storeProgressBar, &defaultScheme);
    laWidget_SetBackgroundType((laWidget*)storeProgressBar, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)storeProgressBar, LA_WIDGET_BORDER_BEVEL);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)storeProgressBar);

    ButtonWidget21 = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ButtonWidget21, 2, 2);
    laWidget_SetSize((laWidget*)ButtonWidget21, 60, 50);
    laWidget_SetBackgroundType((laWidget*)ButtonWidget21, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ButtonWidget21, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetPressedImage(ButtonWidget21, &back);
    laButtonWidget_SetReleasedImage(ButtonWidget21, &back);
    laButtonWidget_SetReleasedEventCallback(ButtonWidget21, &ButtonWidget21_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ButtonWidget21);

    storeSaveButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)storeSaveButton, 367, 70);
    laWidget_SetSize((laWidget*)storeSaveButton, 74, 41);
    laWidget_SetBackgroundType((laWidget*)storeSaveButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)storeSaveButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(storeSaveButton, laString_CreateFromID(string_store_save));
    laButtonWidget_SetReleasedEventCallback(storeSaveButton, &storeSaveButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)storeSaveButton);

    ImageWidget29 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget29, 251, 152);
    laWidget_SetSize((laWidget*)ImageWidget29, 200, 105);
    laWidget_SetBackgroundType((laWidget*)ImageWidget29, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget29, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget29, &flash);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget29);

    LabelWidget30 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget30, 130, 10);
    laWidget_SetSize((laWidget*)LabelWidget30, 220, 25);
    laWidget_SetBackgroundType((laWidget*)LabelWidget30, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget30, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget30, laString_CreateFromID(string_store_title));
    laLabelWidget_SetHAlignment(LabelWidget30, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget30);

    ImageWidget34 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget34, 371, 116);
    laWidget_SetSize((laWidget*)ImageWidget34, 64, 35);
    laWidget_SetBackgroundType((laWidget*)ImageWidget34, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget34, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget34, &down_arrow);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget34);

    storeDoneButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)storeDoneButton, 367, 70);
    laWidget_SetSize((laWidget*)storeDoneButton, 74, 41);
    laWidget_SetVisible((laWidget*)storeDoneButton, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)storeDoneButton, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)storeDoneButton, LA_WIDGET_BORDER_BEVEL);
    laButtonWidget_SetText(storeDoneButton, laString_CreateFromID(string_store_done));
    laButtonWidget_SetReleasedEventCallback(storeDoneButton, &storeDoneButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)storeDoneButton);

}




