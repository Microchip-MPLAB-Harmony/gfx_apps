#include "gfx/legato/generated/screen/le_gen_screen_AlphaBlendingDemoScreen.h"

// screen member widget declarations
leWidget* root0;

leGradientWidget* AlphaBlendingDemoScreen_GradientWidget5;
leWidget* AlphaBlendingDemoScreen_PanelWidget1;
leWidget* AlphaBlendingDemoScreen_PanelWidget2;
leButtonWidget* AlphaBlendingDemoScreen_AlphaHelpButton;
leButtonWidget* AlphaBlendingDemoScreen_AlphaHomeButton;
leLabelWidget* AlphaBlendingDemoScreen_LabelWidget9;
leButtonWidget* AlphaBlendingDemoScreen_AlphaNextButton;
leButtonWidget* AlphaBlendingDemoScreen_SliderUpButtonWidget;
leButtonWidget* AlphaBlendingDemoScreen_SliderDownButtonWidget;
leSliderWidget* AlphaBlendingDemoScreen_SliderWidget1;
leLabelWidget* AlphaBlendingDemoScreen_SliderValueLabelWidget;
leImageWidget* AlphaBlendingDemoScreen_ImageWidget1;
leImageWidget* AlphaBlendingDemoScreen_ImageWidget2;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_AlphaBlendingDemoScreen()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_AlphaBlendingDemoScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    AlphaBlendingDemoScreen_GradientWidget5 = leGradientWidget_New();
    AlphaBlendingDemoScreen_GradientWidget5->fn->setPosition(AlphaBlendingDemoScreen_GradientWidget5, 0, 0);
    AlphaBlendingDemoScreen_GradientWidget5->fn->setSize(AlphaBlendingDemoScreen_GradientWidget5, 480, 320);
    AlphaBlendingDemoScreen_GradientWidget5->fn->setScheme(AlphaBlendingDemoScreen_GradientWidget5, &BackgroundGradientScheme);
    AlphaBlendingDemoScreen_GradientWidget5->fn->setDirection(AlphaBlendingDemoScreen_GradientWidget5, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingDemoScreen_GradientWidget5);

    AlphaBlendingDemoScreen_PanelWidget1 = leWidget_New();
    AlphaBlendingDemoScreen_PanelWidget1->fn->setPosition(AlphaBlendingDemoScreen_PanelWidget1, 370, 29);
    AlphaBlendingDemoScreen_PanelWidget1->fn->setSize(AlphaBlendingDemoScreen_PanelWidget1, 119, 187);
    AlphaBlendingDemoScreen_PanelWidget1->fn->setBackgroundType(AlphaBlendingDemoScreen_PanelWidget1, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingDemoScreen_PanelWidget1);

    AlphaBlendingDemoScreen_SliderWidget1 = leSliderWidget_New();
    AlphaBlendingDemoScreen_SliderWidget1->fn->setPosition(AlphaBlendingDemoScreen_SliderWidget1, 1, 42);
    AlphaBlendingDemoScreen_SliderWidget1->fn->setSize(AlphaBlendingDemoScreen_SliderWidget1, 48, 106);
    AlphaBlendingDemoScreen_SliderWidget1->fn->setBackgroundType(AlphaBlendingDemoScreen_SliderWidget1, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingDemoScreen_SliderWidget1->fn->setMaximumValue(AlphaBlendingDemoScreen_SliderWidget1, 255);
    AlphaBlendingDemoScreen_SliderWidget1->fn->setGripSize(AlphaBlendingDemoScreen_SliderWidget1, 15);
    AlphaBlendingDemoScreen_SliderWidget1->fn->setValueChangedEventCallback(AlphaBlendingDemoScreen_SliderWidget1, event_AlphaBlendingDemoScreen_SliderWidget1_OnValueChanged);
    AlphaBlendingDemoScreen_PanelWidget1->fn->addChild(AlphaBlendingDemoScreen_PanelWidget1, (leWidget*)AlphaBlendingDemoScreen_SliderWidget1);

    AlphaBlendingDemoScreen_SliderValueLabelWidget = leLabelWidget_New();
    AlphaBlendingDemoScreen_SliderValueLabelWidget->fn->setPosition(AlphaBlendingDemoScreen_SliderValueLabelWidget, 58, 78);
    AlphaBlendingDemoScreen_SliderValueLabelWidget->fn->setSize(AlphaBlendingDemoScreen_SliderValueLabelWidget, 50, 32);
    AlphaBlendingDemoScreen_SliderValueLabelWidget->fn->setBackgroundType(AlphaBlendingDemoScreen_SliderValueLabelWidget, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingDemoScreen_SliderValueLabelWidget->fn->setString(AlphaBlendingDemoScreen_SliderValueLabelWidget, (leString*)&string_AlphaBlendDefaultValue);
    AlphaBlendingDemoScreen_PanelWidget1->fn->addChild(AlphaBlendingDemoScreen_PanelWidget1, (leWidget*)AlphaBlendingDemoScreen_SliderValueLabelWidget);

    AlphaBlendingDemoScreen_PanelWidget2 = leWidget_New();
    AlphaBlendingDemoScreen_PanelWidget2->fn->setPosition(AlphaBlendingDemoScreen_PanelWidget2, 61, 36);
    AlphaBlendingDemoScreen_PanelWidget2->fn->setSize(AlphaBlendingDemoScreen_PanelWidget2, 299, 180);
    AlphaBlendingDemoScreen_PanelWidget2->fn->setBorderType(AlphaBlendingDemoScreen_PanelWidget2, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingDemoScreen_PanelWidget2);

    AlphaBlendingDemoScreen_ImageWidget1 = leImageWidget_New();
    AlphaBlendingDemoScreen_ImageWidget1->fn->setPosition(AlphaBlendingDemoScreen_ImageWidget1, 0, 0);
    AlphaBlendingDemoScreen_ImageWidget1->fn->setSize(AlphaBlendingDemoScreen_ImageWidget1, 305, 180);
    AlphaBlendingDemoScreen_ImageWidget1->fn->setAlphaEnabled(AlphaBlendingDemoScreen_ImageWidget1, LE_TRUE);
    AlphaBlendingDemoScreen_ImageWidget1->fn->setAlphaAmount(AlphaBlendingDemoScreen_ImageWidget1, 127);
    AlphaBlendingDemoScreen_ImageWidget1->fn->setBackgroundType(AlphaBlendingDemoScreen_ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingDemoScreen_ImageWidget1->fn->setBorderType(AlphaBlendingDemoScreen_ImageWidget1, LE_WIDGET_BORDER_LINE);
    AlphaBlendingDemoScreen_ImageWidget1->fn->setImage(AlphaBlendingDemoScreen_ImageWidget1, (leImage*)&NewHarmonyLogo);
    AlphaBlendingDemoScreen_PanelWidget2->fn->addChild(AlphaBlendingDemoScreen_PanelWidget2, (leWidget*)AlphaBlendingDemoScreen_ImageWidget1);

    AlphaBlendingDemoScreen_ImageWidget2 = leImageWidget_New();
    AlphaBlendingDemoScreen_ImageWidget2->fn->setPosition(AlphaBlendingDemoScreen_ImageWidget2, 0, 0);
    AlphaBlendingDemoScreen_ImageWidget2->fn->setSize(AlphaBlendingDemoScreen_ImageWidget2, 304, 180);
    AlphaBlendingDemoScreen_ImageWidget2->fn->setAlphaEnabled(AlphaBlendingDemoScreen_ImageWidget2, LE_TRUE);
    AlphaBlendingDemoScreen_ImageWidget2->fn->setAlphaAmount(AlphaBlendingDemoScreen_ImageWidget2, 127);
    AlphaBlendingDemoScreen_ImageWidget2->fn->setBackgroundType(AlphaBlendingDemoScreen_ImageWidget2, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingDemoScreen_ImageWidget2->fn->setBorderType(AlphaBlendingDemoScreen_ImageWidget2, LE_WIDGET_BORDER_LINE);
    AlphaBlendingDemoScreen_ImageWidget2->fn->setImage(AlphaBlendingDemoScreen_ImageWidget2, (leImage*)&MicrochipLogo);
    AlphaBlendingDemoScreen_PanelWidget2->fn->addChild(AlphaBlendingDemoScreen_PanelWidget2, (leWidget*)AlphaBlendingDemoScreen_ImageWidget2);

    AlphaBlendingDemoScreen_AlphaHelpButton = leButtonWidget_New();
    AlphaBlendingDemoScreen_AlphaHelpButton->fn->setPosition(AlphaBlendingDemoScreen_AlphaHelpButton, 0, 260);
    AlphaBlendingDemoScreen_AlphaHelpButton->fn->setSize(AlphaBlendingDemoScreen_AlphaHelpButton, 60, 60);
    AlphaBlendingDemoScreen_AlphaHelpButton->fn->setBackgroundType(AlphaBlendingDemoScreen_AlphaHelpButton, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingDemoScreen_AlphaHelpButton->fn->setBorderType(AlphaBlendingDemoScreen_AlphaHelpButton, LE_WIDGET_BORDER_NONE);
    AlphaBlendingDemoScreen_AlphaHelpButton->fn->setPressedImage(AlphaBlendingDemoScreen_AlphaHelpButton, (leImage*)&GFX_Help_60);
    AlphaBlendingDemoScreen_AlphaHelpButton->fn->setReleasedImage(AlphaBlendingDemoScreen_AlphaHelpButton, (leImage*)&GFX_Help_60);
    AlphaBlendingDemoScreen_AlphaHelpButton->fn->setReleasedEventCallback(AlphaBlendingDemoScreen_AlphaHelpButton, event_AlphaBlendingDemoScreen_AlphaHelpButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingDemoScreen_AlphaHelpButton);

    AlphaBlendingDemoScreen_AlphaHomeButton = leButtonWidget_New();
    AlphaBlendingDemoScreen_AlphaHomeButton->fn->setPosition(AlphaBlendingDemoScreen_AlphaHomeButton, 421, 260);
    AlphaBlendingDemoScreen_AlphaHomeButton->fn->setSize(AlphaBlendingDemoScreen_AlphaHomeButton, 60, 60);
    AlphaBlendingDemoScreen_AlphaHomeButton->fn->setBackgroundType(AlphaBlendingDemoScreen_AlphaHomeButton, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingDemoScreen_AlphaHomeButton->fn->setBorderType(AlphaBlendingDemoScreen_AlphaHomeButton, LE_WIDGET_BORDER_NONE);
    AlphaBlendingDemoScreen_AlphaHomeButton->fn->setPressedImage(AlphaBlendingDemoScreen_AlphaHomeButton, (leImage*)&GFX_Home_60x60);
    AlphaBlendingDemoScreen_AlphaHomeButton->fn->setReleasedImage(AlphaBlendingDemoScreen_AlphaHomeButton, (leImage*)&GFX_Home_60x60);
    AlphaBlendingDemoScreen_AlphaHomeButton->fn->setReleasedEventCallback(AlphaBlendingDemoScreen_AlphaHomeButton, event_AlphaBlendingDemoScreen_AlphaHomeButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingDemoScreen_AlphaHomeButton);

    AlphaBlendingDemoScreen_LabelWidget9 = leLabelWidget_New();
    AlphaBlendingDemoScreen_LabelWidget9->fn->setPosition(AlphaBlendingDemoScreen_LabelWidget9, 10, 5);
    AlphaBlendingDemoScreen_LabelWidget9->fn->setSize(AlphaBlendingDemoScreen_LabelWidget9, 297, 25);
    AlphaBlendingDemoScreen_LabelWidget9->fn->setScheme(AlphaBlendingDemoScreen_LabelWidget9, &whiteScheme);
    AlphaBlendingDemoScreen_LabelWidget9->fn->setBackgroundType(AlphaBlendingDemoScreen_LabelWidget9, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingDemoScreen_LabelWidget9->fn->setString(AlphaBlendingDemoScreen_LabelWidget9, (leString*)&string_AlphaBlendingDemo);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingDemoScreen_LabelWidget9);

    AlphaBlendingDemoScreen_AlphaNextButton = leButtonWidget_New();
    AlphaBlendingDemoScreen_AlphaNextButton->fn->setPosition(AlphaBlendingDemoScreen_AlphaNextButton, 359, 260);
    AlphaBlendingDemoScreen_AlphaNextButton->fn->setSize(AlphaBlendingDemoScreen_AlphaNextButton, 60, 60);
    AlphaBlendingDemoScreen_AlphaNextButton->fn->setBackgroundType(AlphaBlendingDemoScreen_AlphaNextButton, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingDemoScreen_AlphaNextButton->fn->setBorderType(AlphaBlendingDemoScreen_AlphaNextButton, LE_WIDGET_BORDER_NONE);
    AlphaBlendingDemoScreen_AlphaNextButton->fn->setPressedImage(AlphaBlendingDemoScreen_AlphaNextButton, (leImage*)&GFX_NextScreen_60x60);
    AlphaBlendingDemoScreen_AlphaNextButton->fn->setReleasedImage(AlphaBlendingDemoScreen_AlphaNextButton, (leImage*)&GFX_NextScreen_60x60);
    AlphaBlendingDemoScreen_AlphaNextButton->fn->setReleasedEventCallback(AlphaBlendingDemoScreen_AlphaNextButton, event_AlphaBlendingDemoScreen_AlphaNextButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingDemoScreen_AlphaNextButton);

    AlphaBlendingDemoScreen_SliderUpButtonWidget = leButtonWidget_New();
    AlphaBlendingDemoScreen_SliderUpButtonWidget->fn->setPosition(AlphaBlendingDemoScreen_SliderUpButtonWidget, 370, 31);
    AlphaBlendingDemoScreen_SliderUpButtonWidget->fn->setSize(AlphaBlendingDemoScreen_SliderUpButtonWidget, 50, 36);
    AlphaBlendingDemoScreen_SliderUpButtonWidget->fn->setScheme(AlphaBlendingDemoScreen_SliderUpButtonWidget, &BlackBackground);
    AlphaBlendingDemoScreen_SliderUpButtonWidget->fn->setBackgroundType(AlphaBlendingDemoScreen_SliderUpButtonWidget, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingDemoScreen_SliderUpButtonWidget->fn->setString(AlphaBlendingDemoScreen_SliderUpButtonWidget, (leString*)&string_UpRight);
    AlphaBlendingDemoScreen_SliderUpButtonWidget->fn->setReleasedEventCallback(AlphaBlendingDemoScreen_SliderUpButtonWidget, event_AlphaBlendingDemoScreen_SliderUpButtonWidget_OnReleased);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingDemoScreen_SliderUpButtonWidget);

    AlphaBlendingDemoScreen_SliderDownButtonWidget = leButtonWidget_New();
    AlphaBlendingDemoScreen_SliderDownButtonWidget->fn->setPosition(AlphaBlendingDemoScreen_SliderDownButtonWidget, 370, 180);
    AlphaBlendingDemoScreen_SliderDownButtonWidget->fn->setSize(AlphaBlendingDemoScreen_SliderDownButtonWidget, 50, 36);
    AlphaBlendingDemoScreen_SliderDownButtonWidget->fn->setScheme(AlphaBlendingDemoScreen_SliderDownButtonWidget, &BlackBackground);
    AlphaBlendingDemoScreen_SliderDownButtonWidget->fn->setBackgroundType(AlphaBlendingDemoScreen_SliderDownButtonWidget, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingDemoScreen_SliderDownButtonWidget->fn->setString(AlphaBlendingDemoScreen_SliderDownButtonWidget, (leString*)&string_DownLeft);
    AlphaBlendingDemoScreen_SliderDownButtonWidget->fn->setReleasedEventCallback(AlphaBlendingDemoScreen_SliderDownButtonWidget, event_AlphaBlendingDemoScreen_SliderDownButtonWidget_OnReleased);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingDemoScreen_SliderDownButtonWidget);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    AlphaBlendingDemoScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_AlphaBlendingDemoScreen()
{
    AlphaBlendingDemoScreen_OnUpdate(); // raise event
}

void screenHide_AlphaBlendingDemoScreen()
{
    AlphaBlendingDemoScreen_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    AlphaBlendingDemoScreen_GradientWidget5 = NULL;
    AlphaBlendingDemoScreen_PanelWidget1 = NULL;
    AlphaBlendingDemoScreen_PanelWidget2 = NULL;
    AlphaBlendingDemoScreen_AlphaHelpButton = NULL;
    AlphaBlendingDemoScreen_AlphaHomeButton = NULL;
    AlphaBlendingDemoScreen_LabelWidget9 = NULL;
    AlphaBlendingDemoScreen_AlphaNextButton = NULL;
    AlphaBlendingDemoScreen_SliderUpButtonWidget = NULL;
    AlphaBlendingDemoScreen_SliderDownButtonWidget = NULL;
    AlphaBlendingDemoScreen_SliderWidget1 = NULL;
    AlphaBlendingDemoScreen_SliderValueLabelWidget = NULL;
    AlphaBlendingDemoScreen_ImageWidget1 = NULL;
    AlphaBlendingDemoScreen_ImageWidget2 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_AlphaBlendingDemoScreen()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_AlphaBlendingDemoScreen(uint32_t lyrIdx)
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

