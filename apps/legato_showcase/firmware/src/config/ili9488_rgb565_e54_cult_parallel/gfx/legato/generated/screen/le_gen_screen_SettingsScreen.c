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

#include "gfx/legato/generated/screen/le_gen_screen_SettingsScreen.h"

// widget list for layer 0
static leWidget* root0;

leGradientWidget* GradientWidget7;
leButtonWidget* SettingsHomeButton;
leWidget* PanelWidget3;
leLabelWidget* LabelWidget11;
leRadioButtonWidget* RadioButtonChinese;
leRadioButtonWidget* RadioButtonEnglish;
leButtonWidget* ButtonWidgetChinese;
leButtonWidget* ButtonWidgetEnglish;

static leRadioButtonGroup* RadioButtonGroup_0;

// string list for this screen
static leTableString tableString_SetLanguage;
static leTableString tableString_RadioButton_Chinese;
static leTableString tableString_RadioButton_English;

static leBool showing = LE_FALSE;

leResult screenInit_SettingsScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_SettingsScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_SetLanguage, string_SetLanguage);
    leTableString_Constructor(&tableString_RadioButton_Chinese, string_RadioButton_Chinese);
    leTableString_Constructor(&tableString_RadioButton_English, string_RadioButton_English);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    GradientWidget7 = leGradientWidget_New();
    GradientWidget7->fn->setPosition(GradientWidget7, 0, 0);
    GradientWidget7->fn->setSize(GradientWidget7, 480, 320);
    GradientWidget7->fn->setScheme(GradientWidget7, &BackgroundGradientScheme);
    GradientWidget7->fn->setDirection(GradientWidget7, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)GradientWidget7);

    SettingsHomeButton = leButtonWidget_New();
    SettingsHomeButton->fn->setPosition(SettingsHomeButton, 421, 260);
    SettingsHomeButton->fn->setSize(SettingsHomeButton, 60, 60);
    SettingsHomeButton->fn->setAlphaEnabled(SettingsHomeButton, LE_TRUE);
    SettingsHomeButton->fn->setBackgroundType(SettingsHomeButton, LE_WIDGET_BACKGROUND_NONE);
    SettingsHomeButton->fn->setBorderType(SettingsHomeButton, LE_WIDGET_BORDER_NONE);
    SettingsHomeButton->fn->setPressedImage(SettingsHomeButton, &GFX_Home_60x60);
    SettingsHomeButton->fn->setReleasedImage(SettingsHomeButton, &GFX_Home_60x60);
    SettingsHomeButton->fn->setReleasedEventCallback(SettingsHomeButton, SettingsHomeButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SettingsHomeButton);

    PanelWidget3 = leWidget_New();
    PanelWidget3->fn->setPosition(PanelWidget3, 39, 35);
    PanelWidget3->fn->setSize(PanelWidget3, 407, 38);
    PanelWidget3->fn->setScheme(PanelWidget3, &defaultScheme);
    PanelWidget3->fn->setBorderType(PanelWidget3, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, PanelWidget3);

    LabelWidget11 = leLabelWidget_New();
    LabelWidget11->fn->setPosition(LabelWidget11, 15, 5);
    LabelWidget11->fn->setSize(LabelWidget11, 98, 25);
    LabelWidget11->fn->setBackgroundType(LabelWidget11, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget11->fn->setString(LabelWidget11, (leString*)&tableString_SetLanguage);
    PanelWidget3->fn->addChild(PanelWidget3, (leWidget*)LabelWidget11);

    RadioButtonChinese = leRadioButtonWidget_New();
    RadioButtonChinese->fn->setPosition(RadioButtonChinese, 262, 6);
    RadioButtonChinese->fn->setSize(RadioButtonChinese, 127, 25);
    RadioButtonChinese->fn->setEnabled(RadioButtonChinese, LE_FALSE);
    RadioButtonChinese->fn->setVisible(RadioButtonChinese, LE_FALSE);
    RadioButtonChinese->fn->setBackgroundType(RadioButtonChinese, LE_WIDGET_BACKGROUND_NONE);
    RadioButtonChinese->fn->setString(RadioButtonChinese, (leString*)&tableString_RadioButton_Chinese);
    PanelWidget3->fn->addChild(PanelWidget3, (leWidget*)RadioButtonChinese);

    RadioButtonEnglish = leRadioButtonWidget_New();
    RadioButtonEnglish->fn->setPosition(RadioButtonEnglish, 133, 6);
    RadioButtonEnglish->fn->setEnabled(RadioButtonEnglish, LE_FALSE);
    RadioButtonEnglish->fn->setBackgroundType(RadioButtonEnglish, LE_WIDGET_BACKGROUND_NONE);
    RadioButtonEnglish->fn->setString(RadioButtonEnglish, (leString*)&tableString_RadioButton_English);
    PanelWidget3->fn->addChild(PanelWidget3, (leWidget*)RadioButtonEnglish);

    ButtonWidgetChinese = leButtonWidget_New();
    ButtonWidgetChinese->fn->setPosition(ButtonWidgetChinese, 254, 0);
    ButtonWidgetChinese->fn->setSize(ButtonWidgetChinese, 123, 39);
    ButtonWidgetChinese->fn->setEnabled(ButtonWidgetChinese, LE_FALSE);
    ButtonWidgetChinese->fn->setBackgroundType(ButtonWidgetChinese, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidgetChinese->fn->setBorderType(ButtonWidgetChinese, LE_WIDGET_BORDER_NONE);
    ButtonWidgetChinese->fn->setReleasedEventCallback(ButtonWidgetChinese, ButtonWidgetChinese_OnReleased);
    PanelWidget3->fn->addChild(PanelWidget3, (leWidget*)ButtonWidgetChinese);

    ButtonWidgetEnglish = leButtonWidget_New();
    ButtonWidgetEnglish->fn->setPosition(ButtonWidgetEnglish, 128, 0);
    ButtonWidgetEnglish->fn->setSize(ButtonWidgetEnglish, 126, 38);
    ButtonWidgetEnglish->fn->setBackgroundType(ButtonWidgetEnglish, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidgetEnglish->fn->setBorderType(ButtonWidgetEnglish, LE_WIDGET_BORDER_NONE);
    ButtonWidgetEnglish->fn->setReleasedEventCallback(ButtonWidgetEnglish, ButtonWidgetEnglish_OnReleased);
    PanelWidget3->fn->addChild(PanelWidget3, (leWidget*)ButtonWidgetEnglish);

    leRadioButtonGroup_Create(&RadioButtonGroup_0);
    leRadioButtonGroup_AddButton(RadioButtonGroup_0, RadioButtonEnglish);
    leRadioButtonGroup_AddButton(RadioButtonGroup_0, RadioButtonChinese);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    SettingsScreen_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_SettingsScreen()
{
    SettingsScreen_OnUpdate();
}

void screenHide_SettingsScreen()
{

    leRadioButtonGroup_Destroy(RadioButtonGroup_0);

    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    GradientWidget7 = NULL;
    SettingsHomeButton = NULL;
    PanelWidget3 = NULL;
    LabelWidget11 = NULL;
    RadioButtonChinese = NULL;
    RadioButtonEnglish = NULL;
    ButtonWidgetChinese = NULL;
    ButtonWidgetEnglish = NULL;

    tableString_SetLanguage.fn->destructor(&tableString_SetLanguage);
    tableString_RadioButton_Chinese.fn->destructor(&tableString_RadioButton_Chinese);
    tableString_RadioButton_English.fn->destructor(&tableString_RadioButton_English);
    showing = LE_FALSE;
}

void screenDestroy_SettingsScreen()
{

}

leWidget* screenGetRoot_SettingsScreen(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        default:
        {
            return NULL;
        }
    }
}

