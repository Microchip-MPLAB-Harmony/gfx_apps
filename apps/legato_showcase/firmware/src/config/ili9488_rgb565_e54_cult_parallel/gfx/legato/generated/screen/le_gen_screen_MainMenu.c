#include "gfx/legato/generated/screen/le_gen_screen_MainMenu.h"

// screen member widget declarations
leWidget* root0;

leGradientWidget* MainMenu_GradientWidget1;
leButtonWidget* MainMenu_ListwheelDemoMenuButton;
leButtonWidget* MainMenu_AlphaBlendingDemoMenuButton;
leButtonWidget* MainMenu_SlideShowDemoMenuButton;
leButtonWidget* MainMenu_TouchTestDemoMenuDemo;
leButtonWidget* MainMenu_KeypadDemoMenuButton;
leButtonWidget* MainMenu_MainMenuHelpButton;
leLabelWidget* MainMenu_LabelWidget1;
leLabelWidget* MainMenu_LabelWidget2;
leImageWidget* MainMenu_ImageWidget3;
leImageWidget* MainMenu_ImageWidget4;
leButtonWidget* MainMenu_MainMenuSettingsButton;
leButtonWidget* MainMenu_MainMenuNextButton;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_MainMenu()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_MainMenu()
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

    MainMenu_GradientWidget1 = leGradientWidget_New();
    MainMenu_GradientWidget1->fn->setPosition(MainMenu_GradientWidget1, 0, 0);
    MainMenu_GradientWidget1->fn->setSize(MainMenu_GradientWidget1, 480, 320);
    MainMenu_GradientWidget1->fn->setScheme(MainMenu_GradientWidget1, &BackgroundGradientScheme);
    MainMenu_GradientWidget1->fn->setDirection(MainMenu_GradientWidget1, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)MainMenu_GradientWidget1);

    MainMenu_ListwheelDemoMenuButton = leButtonWidget_New();
    MainMenu_ListwheelDemoMenuButton->fn->setPosition(MainMenu_ListwheelDemoMenuButton, 10, 83);
    MainMenu_ListwheelDemoMenuButton->fn->setSize(MainMenu_ListwheelDemoMenuButton, 85, 78);
    MainMenu_ListwheelDemoMenuButton->fn->setBackgroundType(MainMenu_ListwheelDemoMenuButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_ListwheelDemoMenuButton->fn->setBorderType(MainMenu_ListwheelDemoMenuButton, LE_WIDGET_BORDER_NONE);
    MainMenu_ListwheelDemoMenuButton->fn->setPressedImage(MainMenu_ListwheelDemoMenuButton, (leImage*)&GFX_Slide_80_drop);
    MainMenu_ListwheelDemoMenuButton->fn->setReleasedImage(MainMenu_ListwheelDemoMenuButton, (leImage*)&GFX_Slide_80_drop);
    MainMenu_ListwheelDemoMenuButton->fn->setReleasedEventCallback(MainMenu_ListwheelDemoMenuButton, event_MainMenu_ListwheelDemoMenuButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenu_ListwheelDemoMenuButton);

    MainMenu_AlphaBlendingDemoMenuButton = leButtonWidget_New();
    MainMenu_AlphaBlendingDemoMenuButton->fn->setPosition(MainMenu_AlphaBlendingDemoMenuButton, 296, 87);
    MainMenu_AlphaBlendingDemoMenuButton->fn->setSize(MainMenu_AlphaBlendingDemoMenuButton, 83, 74);
    MainMenu_AlphaBlendingDemoMenuButton->fn->setBackgroundType(MainMenu_AlphaBlendingDemoMenuButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_AlphaBlendingDemoMenuButton->fn->setBorderType(MainMenu_AlphaBlendingDemoMenuButton, LE_WIDGET_BORDER_NONE);
    MainMenu_AlphaBlendingDemoMenuButton->fn->setPressedImage(MainMenu_AlphaBlendingDemoMenuButton, (leImage*)&GFX_alpha_80x80_drop);
    MainMenu_AlphaBlendingDemoMenuButton->fn->setReleasedImage(MainMenu_AlphaBlendingDemoMenuButton, (leImage*)&GFX_alpha_80x80_drop);
    MainMenu_AlphaBlendingDemoMenuButton->fn->setReleasedEventCallback(MainMenu_AlphaBlendingDemoMenuButton, event_MainMenu_AlphaBlendingDemoMenuButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenu_AlphaBlendingDemoMenuButton);

    MainMenu_SlideShowDemoMenuButton = leButtonWidget_New();
    MainMenu_SlideShowDemoMenuButton->fn->setPosition(MainMenu_SlideShowDemoMenuButton, 386, 83);
    MainMenu_SlideShowDemoMenuButton->fn->setSize(MainMenu_SlideShowDemoMenuButton, 84, 80);
    MainMenu_SlideShowDemoMenuButton->fn->setBackgroundType(MainMenu_SlideShowDemoMenuButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_SlideShowDemoMenuButton->fn->setBorderType(MainMenu_SlideShowDemoMenuButton, LE_WIDGET_BORDER_NONE);
    MainMenu_SlideShowDemoMenuButton->fn->setPressedImage(MainMenu_SlideShowDemoMenuButton, (leImage*)&GFX_SlideShow_80_drop);
    MainMenu_SlideShowDemoMenuButton->fn->setReleasedImage(MainMenu_SlideShowDemoMenuButton, (leImage*)&GFX_SlideShow_80_drop);
    MainMenu_SlideShowDemoMenuButton->fn->setReleasedEventCallback(MainMenu_SlideShowDemoMenuButton, event_MainMenu_SlideShowDemoMenuButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenu_SlideShowDemoMenuButton);

    MainMenu_TouchTestDemoMenuDemo = leButtonWidget_New();
    MainMenu_TouchTestDemoMenuDemo->fn->setPosition(MainMenu_TouchTestDemoMenuDemo, 103, 83);
    MainMenu_TouchTestDemoMenuDemo->fn->setSize(MainMenu_TouchTestDemoMenuDemo, 86, 81);
    MainMenu_TouchTestDemoMenuDemo->fn->setBackgroundType(MainMenu_TouchTestDemoMenuDemo, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_TouchTestDemoMenuDemo->fn->setBorderType(MainMenu_TouchTestDemoMenuDemo, LE_WIDGET_BORDER_NONE);
    MainMenu_TouchTestDemoMenuDemo->fn->setPressedImage(MainMenu_TouchTestDemoMenuDemo, (leImage*)&GFX_Touch_80);
    MainMenu_TouchTestDemoMenuDemo->fn->setReleasedImage(MainMenu_TouchTestDemoMenuDemo, (leImage*)&GFX_Touch_80);
    MainMenu_TouchTestDemoMenuDemo->fn->setReleasedEventCallback(MainMenu_TouchTestDemoMenuDemo, event_MainMenu_TouchTestDemoMenuDemo_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenu_TouchTestDemoMenuDemo);

    MainMenu_KeypadDemoMenuButton = leButtonWidget_New();
    MainMenu_KeypadDemoMenuButton->fn->setPosition(MainMenu_KeypadDemoMenuButton, 200, 84);
    MainMenu_KeypadDemoMenuButton->fn->setSize(MainMenu_KeypadDemoMenuButton, 84, 77);
    MainMenu_KeypadDemoMenuButton->fn->setBackgroundType(MainMenu_KeypadDemoMenuButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_KeypadDemoMenuButton->fn->setBorderType(MainMenu_KeypadDemoMenuButton, LE_WIDGET_BORDER_NONE);
    MainMenu_KeypadDemoMenuButton->fn->setPressedImage(MainMenu_KeypadDemoMenuButton, (leImage*)&GFX_Keyboard_80_drop);
    MainMenu_KeypadDemoMenuButton->fn->setReleasedImage(MainMenu_KeypadDemoMenuButton, (leImage*)&GFX_Keyboard_80_drop);
    MainMenu_KeypadDemoMenuButton->fn->setReleasedEventCallback(MainMenu_KeypadDemoMenuButton, event_MainMenu_KeypadDemoMenuButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenu_KeypadDemoMenuButton);

    MainMenu_MainMenuHelpButton = leButtonWidget_New();
    MainMenu_MainMenuHelpButton->fn->setPosition(MainMenu_MainMenuHelpButton, 0, 260);
    MainMenu_MainMenuHelpButton->fn->setSize(MainMenu_MainMenuHelpButton, 60, 60);
    MainMenu_MainMenuHelpButton->fn->setAlphaAmount(MainMenu_MainMenuHelpButton, 220);
    MainMenu_MainMenuHelpButton->fn->setBackgroundType(MainMenu_MainMenuHelpButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_MainMenuHelpButton->fn->setBorderType(MainMenu_MainMenuHelpButton, LE_WIDGET_BORDER_NONE);
    MainMenu_MainMenuHelpButton->fn->setPressedImage(MainMenu_MainMenuHelpButton, (leImage*)&GFX_Help_60);
    MainMenu_MainMenuHelpButton->fn->setReleasedImage(MainMenu_MainMenuHelpButton, (leImage*)&GFX_Help_60);
    MainMenu_MainMenuHelpButton->fn->setReleasedEventCallback(MainMenu_MainMenuHelpButton, event_MainMenu_MainMenuHelpButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenu_MainMenuHelpButton);

    MainMenu_LabelWidget1 = leLabelWidget_New();
    MainMenu_LabelWidget1->fn->setPosition(MainMenu_LabelWidget1, 170, 169);
    MainMenu_LabelWidget1->fn->setSize(MainMenu_LabelWidget1, 161, 32);
    MainMenu_LabelWidget1->fn->setScheme(MainMenu_LabelWidget1, &BlackBackground);
    MainMenu_LabelWidget1->fn->setBackgroundType(MainMenu_LabelWidget1, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_LabelWidget1->fn->setHAlignment(MainMenu_LabelWidget1, LE_HALIGN_CENTER);
    MainMenu_LabelWidget1->fn->setString(MainMenu_LabelWidget1, (leString*)&string_Harmony);
    root0->fn->addChild(root0, (leWidget*)MainMenu_LabelWidget1);

    MainMenu_LabelWidget2 = leLabelWidget_New();
    MainMenu_LabelWidget2->fn->setPosition(MainMenu_LabelWidget2, 127, 203);
    MainMenu_LabelWidget2->fn->setSize(MainMenu_LabelWidget2, 243, 31);
    MainMenu_LabelWidget2->fn->setScheme(MainMenu_LabelWidget2, &BlackBackground);
    MainMenu_LabelWidget2->fn->setBackgroundType(MainMenu_LabelWidget2, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_LabelWidget2->fn->setHAlignment(MainMenu_LabelWidget2, LE_HALIGN_CENTER);
    MainMenu_LabelWidget2->fn->setString(MainMenu_LabelWidget2, (leString*)&string_Title);
    root0->fn->addChild(root0, (leWidget*)MainMenu_LabelWidget2);

    MainMenu_ImageWidget3 = leImageWidget_New();
    MainMenu_ImageWidget3->fn->setPosition(MainMenu_ImageWidget3, 2, 13);
    MainMenu_ImageWidget3->fn->setSize(MainMenu_ImageWidget3, 153, 37);
    MainMenu_ImageWidget3->fn->setBackgroundType(MainMenu_ImageWidget3, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_ImageWidget3->fn->setBorderType(MainMenu_ImageWidget3, LE_WIDGET_BORDER_NONE);
    MainMenu_ImageWidget3->fn->setImage(MainMenu_ImageWidget3, (leImage*)&GFX_Microchip_logo_150x30);
    root0->fn->addChild(root0, (leWidget*)MainMenu_ImageWidget3);

    MainMenu_ImageWidget4 = leImageWidget_New();
    MainMenu_ImageWidget4->fn->setPosition(MainMenu_ImageWidget4, 386, 0);
    MainMenu_ImageWidget4->fn->setSize(MainMenu_ImageWidget4, 94, 56);
    MainMenu_ImageWidget4->fn->setAlphaAmount(MainMenu_ImageWidget4, 220);
    MainMenu_ImageWidget4->fn->setBackgroundType(MainMenu_ImageWidget4, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_ImageWidget4->fn->setBorderType(MainMenu_ImageWidget4, LE_WIDGET_BORDER_NONE);
    MainMenu_ImageWidget4->fn->setImage(MainMenu_ImageWidget4, (leImage*)&GFX_mplab_logo_80x80);
    root0->fn->addChild(root0, (leWidget*)MainMenu_ImageWidget4);

    MainMenu_MainMenuSettingsButton = leButtonWidget_New();
    MainMenu_MainMenuSettingsButton->fn->setPosition(MainMenu_MainMenuSettingsButton, 420, 260);
    MainMenu_MainMenuSettingsButton->fn->setSize(MainMenu_MainMenuSettingsButton, 60, 60);
    MainMenu_MainMenuSettingsButton->fn->setBackgroundType(MainMenu_MainMenuSettingsButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_MainMenuSettingsButton->fn->setBorderType(MainMenu_MainMenuSettingsButton, LE_WIDGET_BORDER_NONE);
    MainMenu_MainMenuSettingsButton->fn->setPressedImage(MainMenu_MainMenuSettingsButton, (leImage*)&GFX_Settings_60x60);
    MainMenu_MainMenuSettingsButton->fn->setReleasedImage(MainMenu_MainMenuSettingsButton, (leImage*)&GFX_Settings_60x60);
    MainMenu_MainMenuSettingsButton->fn->setReleasedEventCallback(MainMenu_MainMenuSettingsButton, event_MainMenu_MainMenuSettingsButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenu_MainMenuSettingsButton);

    MainMenu_MainMenuNextButton = leButtonWidget_New();
    MainMenu_MainMenuNextButton->fn->setPosition(MainMenu_MainMenuNextButton, 359, 260);
    MainMenu_MainMenuNextButton->fn->setSize(MainMenu_MainMenuNextButton, 60, 60);
    MainMenu_MainMenuNextButton->fn->setBackgroundType(MainMenu_MainMenuNextButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_MainMenuNextButton->fn->setBorderType(MainMenu_MainMenuNextButton, LE_WIDGET_BORDER_NONE);
    MainMenu_MainMenuNextButton->fn->setPressedImage(MainMenu_MainMenuNextButton, (leImage*)&GFX_NextScreen_60x60);
    MainMenu_MainMenuNextButton->fn->setReleasedImage(MainMenu_MainMenuNextButton, (leImage*)&GFX_NextScreen_60x60);
    MainMenu_MainMenuNextButton->fn->setReleasedEventCallback(MainMenu_MainMenuNextButton, event_MainMenu_MainMenuNextButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenu_MainMenuNextButton);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    MainMenu_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_MainMenu()
{
    MainMenu_OnUpdate(); // raise event
}

void screenHide_MainMenu()
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    MainMenu_GradientWidget1 = NULL;
    MainMenu_ListwheelDemoMenuButton = NULL;
    MainMenu_AlphaBlendingDemoMenuButton = NULL;
    MainMenu_SlideShowDemoMenuButton = NULL;
    MainMenu_TouchTestDemoMenuDemo = NULL;
    MainMenu_KeypadDemoMenuButton = NULL;
    MainMenu_MainMenuHelpButton = NULL;
    MainMenu_LabelWidget1 = NULL;
    MainMenu_LabelWidget2 = NULL;
    MainMenu_ImageWidget3 = NULL;
    MainMenu_ImageWidget4 = NULL;
    MainMenu_MainMenuSettingsButton = NULL;
    MainMenu_MainMenuNextButton = NULL;


    showing = LE_FALSE;
}

void screenDestroy_MainMenu()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_MainMenu(uint32_t lyrIdx)
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

