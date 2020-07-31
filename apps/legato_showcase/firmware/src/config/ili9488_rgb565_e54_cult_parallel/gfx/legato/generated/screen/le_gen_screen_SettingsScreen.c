#include "gfx/legato/generated/screen/le_gen_screen_SettingsScreen.h"

// screen member widget declarations
leWidget* root0;

leGradientWidget* SettingsScreen_GradientWidget7;
leButtonWidget* SettingsScreen_SettingsHomeButton;
leWidget* SettingsScreen_PanelWidget3;
leButtonWidget* SettingsScreen_ButtonWidgetEnglish;
leButtonWidget* SettingsScreen_ButtonWidgetChinese;
leRadioButtonWidget* SettingsScreen_RadioButtonEnglish;
leRadioButtonWidget* SettingsScreen_RadioButtonChinese;
leLabelWidget* SettingsScreen_LabelWidget11;

static leRadioButtonGroup* radioButtonGroup_0;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_SettingsScreen()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_SettingsScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    leRadioButtonGroup_Create(&radioButtonGroup_0);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    SettingsScreen_GradientWidget7 = leGradientWidget_New();
    SettingsScreen_GradientWidget7->fn->setPosition(SettingsScreen_GradientWidget7, 0, 0);
    SettingsScreen_GradientWidget7->fn->setSize(SettingsScreen_GradientWidget7, 480, 320);
    SettingsScreen_GradientWidget7->fn->setScheme(SettingsScreen_GradientWidget7, &BackgroundGradientScheme);
    SettingsScreen_GradientWidget7->fn->setDirection(SettingsScreen_GradientWidget7, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)SettingsScreen_GradientWidget7);

    SettingsScreen_SettingsHomeButton = leButtonWidget_New();
    SettingsScreen_SettingsHomeButton->fn->setPosition(SettingsScreen_SettingsHomeButton, 421, 260);
    SettingsScreen_SettingsHomeButton->fn->setSize(SettingsScreen_SettingsHomeButton, 60, 60);
    SettingsScreen_SettingsHomeButton->fn->setAlphaEnabled(SettingsScreen_SettingsHomeButton, LE_TRUE);
    SettingsScreen_SettingsHomeButton->fn->setBackgroundType(SettingsScreen_SettingsHomeButton, LE_WIDGET_BACKGROUND_NONE);
    SettingsScreen_SettingsHomeButton->fn->setBorderType(SettingsScreen_SettingsHomeButton, LE_WIDGET_BORDER_NONE);
    SettingsScreen_SettingsHomeButton->fn->setPressedImage(SettingsScreen_SettingsHomeButton, (leImage*)&GFX_Home_60x60);
    SettingsScreen_SettingsHomeButton->fn->setReleasedImage(SettingsScreen_SettingsHomeButton, (leImage*)&GFX_Home_60x60);
    SettingsScreen_SettingsHomeButton->fn->setReleasedEventCallback(SettingsScreen_SettingsHomeButton, event_SettingsScreen_SettingsHomeButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SettingsScreen_SettingsHomeButton);

    SettingsScreen_PanelWidget3 = leWidget_New();
    SettingsScreen_PanelWidget3->fn->setPosition(SettingsScreen_PanelWidget3, 39, 35);
    SettingsScreen_PanelWidget3->fn->setSize(SettingsScreen_PanelWidget3, 407, 38);
    SettingsScreen_PanelWidget3->fn->setScheme(SettingsScreen_PanelWidget3, &defaultScheme);
    SettingsScreen_PanelWidget3->fn->setBorderType(SettingsScreen_PanelWidget3, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, (leWidget*)SettingsScreen_PanelWidget3);

    SettingsScreen_ButtonWidgetEnglish = leButtonWidget_New();
    SettingsScreen_ButtonWidgetEnglish->fn->setPosition(SettingsScreen_ButtonWidgetEnglish, 128, 0);
    SettingsScreen_ButtonWidgetEnglish->fn->setSize(SettingsScreen_ButtonWidgetEnglish, 126, 38);
    SettingsScreen_ButtonWidgetEnglish->fn->setBackgroundType(SettingsScreen_ButtonWidgetEnglish, LE_WIDGET_BACKGROUND_NONE);
    SettingsScreen_ButtonWidgetEnglish->fn->setBorderType(SettingsScreen_ButtonWidgetEnglish, LE_WIDGET_BORDER_NONE);
    SettingsScreen_ButtonWidgetEnglish->fn->setReleasedEventCallback(SettingsScreen_ButtonWidgetEnglish, event_SettingsScreen_ButtonWidgetEnglish_OnReleased);
    SettingsScreen_PanelWidget3->fn->addChild(SettingsScreen_PanelWidget3, (leWidget*)SettingsScreen_ButtonWidgetEnglish);

    SettingsScreen_ButtonWidgetChinese = leButtonWidget_New();
    SettingsScreen_ButtonWidgetChinese->fn->setPosition(SettingsScreen_ButtonWidgetChinese, 254, 0);
    SettingsScreen_ButtonWidgetChinese->fn->setSize(SettingsScreen_ButtonWidgetChinese, 123, 39);
    SettingsScreen_ButtonWidgetChinese->fn->setEnabled(SettingsScreen_ButtonWidgetChinese, LE_FALSE);
    SettingsScreen_ButtonWidgetChinese->fn->setBackgroundType(SettingsScreen_ButtonWidgetChinese, LE_WIDGET_BACKGROUND_NONE);
    SettingsScreen_ButtonWidgetChinese->fn->setBorderType(SettingsScreen_ButtonWidgetChinese, LE_WIDGET_BORDER_NONE);
    SettingsScreen_ButtonWidgetChinese->fn->setReleasedEventCallback(SettingsScreen_ButtonWidgetChinese, event_SettingsScreen_ButtonWidgetChinese_OnReleased);
    SettingsScreen_PanelWidget3->fn->addChild(SettingsScreen_PanelWidget3, (leWidget*)SettingsScreen_ButtonWidgetChinese);

    SettingsScreen_RadioButtonEnglish = leRadioButtonWidget_New();
    SettingsScreen_RadioButtonEnglish->fn->setPosition(SettingsScreen_RadioButtonEnglish, 133, 6);
    SettingsScreen_RadioButtonEnglish->fn->setEnabled(SettingsScreen_RadioButtonEnglish, LE_FALSE);
    SettingsScreen_RadioButtonEnglish->fn->setBackgroundType(SettingsScreen_RadioButtonEnglish, LE_WIDGET_BACKGROUND_NONE);
    SettingsScreen_RadioButtonEnglish->fn->setString(SettingsScreen_RadioButtonEnglish, (leString*)&string_RadioButton_English);
    leRadioButtonGroup_AddButton(radioButtonGroup_0, SettingsScreen_RadioButtonEnglish);
    SettingsScreen_RadioButtonEnglish->fn->setSelected(SettingsScreen_RadioButtonEnglish);
    SettingsScreen_PanelWidget3->fn->addChild(SettingsScreen_PanelWidget3, (leWidget*)SettingsScreen_RadioButtonEnglish);

    SettingsScreen_RadioButtonChinese = leRadioButtonWidget_New();
    SettingsScreen_RadioButtonChinese->fn->setPosition(SettingsScreen_RadioButtonChinese, 262, 6);
    SettingsScreen_RadioButtonChinese->fn->setSize(SettingsScreen_RadioButtonChinese, 127, 25);
    SettingsScreen_RadioButtonChinese->fn->setEnabled(SettingsScreen_RadioButtonChinese, LE_FALSE);
    SettingsScreen_RadioButtonChinese->fn->setVisible(SettingsScreen_RadioButtonChinese, LE_FALSE);
    SettingsScreen_RadioButtonChinese->fn->setBackgroundType(SettingsScreen_RadioButtonChinese, LE_WIDGET_BACKGROUND_NONE);
    SettingsScreen_RadioButtonChinese->fn->setString(SettingsScreen_RadioButtonChinese, (leString*)&string_RadioButton_Chinese);
    leRadioButtonGroup_AddButton(radioButtonGroup_0, SettingsScreen_RadioButtonChinese);
    SettingsScreen_RadioButtonChinese->fn->setSelected(SettingsScreen_RadioButtonChinese);
    SettingsScreen_PanelWidget3->fn->addChild(SettingsScreen_PanelWidget3, (leWidget*)SettingsScreen_RadioButtonChinese);

    SettingsScreen_LabelWidget11 = leLabelWidget_New();
    SettingsScreen_LabelWidget11->fn->setPosition(SettingsScreen_LabelWidget11, 15, 5);
    SettingsScreen_LabelWidget11->fn->setSize(SettingsScreen_LabelWidget11, 98, 25);
    SettingsScreen_LabelWidget11->fn->setBackgroundType(SettingsScreen_LabelWidget11, LE_WIDGET_BACKGROUND_NONE);
    SettingsScreen_LabelWidget11->fn->setString(SettingsScreen_LabelWidget11, (leString*)&string_SetLanguage);
    SettingsScreen_PanelWidget3->fn->addChild(SettingsScreen_PanelWidget3, (leWidget*)SettingsScreen_LabelWidget11);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    SettingsScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_SettingsScreen()
{
    SettingsScreen_OnUpdate(); // raise event
}

void screenHide_SettingsScreen()
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    SettingsScreen_GradientWidget7 = NULL;
    SettingsScreen_SettingsHomeButton = NULL;
    SettingsScreen_PanelWidget3 = NULL;
    SettingsScreen_ButtonWidgetEnglish = NULL;
    SettingsScreen_ButtonWidgetChinese = NULL;
    SettingsScreen_RadioButtonEnglish = NULL;
    SettingsScreen_RadioButtonChinese = NULL;
    SettingsScreen_LabelWidget11 = NULL;

    leRadioButtonGroup_Destroy(radioButtonGroup_0);


    showing = LE_FALSE;
}

void screenDestroy_SettingsScreen()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
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

