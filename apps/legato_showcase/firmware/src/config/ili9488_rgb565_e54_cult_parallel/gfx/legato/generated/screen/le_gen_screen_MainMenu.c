#include "gfx/legato/generated/screen/le_gen_screen_MainMenu.h"

// widget list for layer 0
static leWidget* root0;

leGradientWidget* GradientWidget1;
leButtonWidget* ListwheelDemoMenuButton;
leButtonWidget* AlphaBlendingDemoMenuButton;
leButtonWidget* SlideShowDemoMenuButton;
leButtonWidget* TouchTestDemoMenuDemo;
leButtonWidget* KeypadDemoMenuButton;
leButtonWidget* MainMenuHelpButton;
leLabelWidget* LabelWidget1;
leLabelWidget* LabelWidget2;
leImageWidget* ImageWidget3;
leImageWidget* ImageWidget4;
leButtonWidget* MainMenuSettingsButton;
leButtonWidget* MainMenuNextButton;

// string list for this screen
static leTableString tableString_Harmony;
static leTableString tableString_Title;

static leBool showing = LE_FALSE;

leResult screenInit_MainMenu()
{
    return LE_SUCCESS;
}

leResult screenShow_MainMenu()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_Harmony, string_Harmony);
    leTableString_Constructor(&tableString_Title, string_Title);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    GradientWidget1 = leGradientWidget_New();
    GradientWidget1->fn->setPosition(GradientWidget1, 0, 0);
    GradientWidget1->fn->setSize(GradientWidget1, 480, 320);
    GradientWidget1->fn->setScheme(GradientWidget1, &BackgroundGradientScheme);
    GradientWidget1->fn->setDirection(GradientWidget1, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)GradientWidget1);

    ListwheelDemoMenuButton = leButtonWidget_New();
    ListwheelDemoMenuButton->fn->setPosition(ListwheelDemoMenuButton, 10, 83);
    ListwheelDemoMenuButton->fn->setSize(ListwheelDemoMenuButton, 85, 78);
    ListwheelDemoMenuButton->fn->setBackgroundType(ListwheelDemoMenuButton, LE_WIDGET_BACKGROUND_NONE);
    ListwheelDemoMenuButton->fn->setBorderType(ListwheelDemoMenuButton, LE_WIDGET_BORDER_NONE);
    ListwheelDemoMenuButton->fn->setPressedImage(ListwheelDemoMenuButton, &GFX_Slide_80_drop);
    ListwheelDemoMenuButton->fn->setReleasedImage(ListwheelDemoMenuButton, &GFX_Slide_80_drop);
    ListwheelDemoMenuButton->fn->setReleasedEventCallback(ListwheelDemoMenuButton, ListwheelDemoMenuButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ListwheelDemoMenuButton);

    AlphaBlendingDemoMenuButton = leButtonWidget_New();
    AlphaBlendingDemoMenuButton->fn->setPosition(AlphaBlendingDemoMenuButton, 296, 87);
    AlphaBlendingDemoMenuButton->fn->setSize(AlphaBlendingDemoMenuButton, 83, 74);
    AlphaBlendingDemoMenuButton->fn->setBackgroundType(AlphaBlendingDemoMenuButton, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingDemoMenuButton->fn->setBorderType(AlphaBlendingDemoMenuButton, LE_WIDGET_BORDER_NONE);
    AlphaBlendingDemoMenuButton->fn->setPressedImage(AlphaBlendingDemoMenuButton, &GFX_alpha_80x80_drop);
    AlphaBlendingDemoMenuButton->fn->setReleasedImage(AlphaBlendingDemoMenuButton, &GFX_alpha_80x80_drop);
    AlphaBlendingDemoMenuButton->fn->setReleasedEventCallback(AlphaBlendingDemoMenuButton, AlphaBlendingDemoMenuButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingDemoMenuButton);

    SlideShowDemoMenuButton = leButtonWidget_New();
    SlideShowDemoMenuButton->fn->setPosition(SlideShowDemoMenuButton, 386, 83);
    SlideShowDemoMenuButton->fn->setSize(SlideShowDemoMenuButton, 84, 80);
    SlideShowDemoMenuButton->fn->setBackgroundType(SlideShowDemoMenuButton, LE_WIDGET_BACKGROUND_NONE);
    SlideShowDemoMenuButton->fn->setBorderType(SlideShowDemoMenuButton, LE_WIDGET_BORDER_NONE);
    SlideShowDemoMenuButton->fn->setPressedImage(SlideShowDemoMenuButton, &GFX_SlideShow_80_drop);
    SlideShowDemoMenuButton->fn->setReleasedImage(SlideShowDemoMenuButton, &GFX_SlideShow_80_drop);
    SlideShowDemoMenuButton->fn->setReleasedEventCallback(SlideShowDemoMenuButton, SlideShowDemoMenuButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SlideShowDemoMenuButton);

    TouchTestDemoMenuDemo = leButtonWidget_New();
    TouchTestDemoMenuDemo->fn->setPosition(TouchTestDemoMenuDemo, 103, 83);
    TouchTestDemoMenuDemo->fn->setSize(TouchTestDemoMenuDemo, 86, 81);
    TouchTestDemoMenuDemo->fn->setBackgroundType(TouchTestDemoMenuDemo, LE_WIDGET_BACKGROUND_NONE);
    TouchTestDemoMenuDemo->fn->setBorderType(TouchTestDemoMenuDemo, LE_WIDGET_BORDER_NONE);
    TouchTestDemoMenuDemo->fn->setPressedImage(TouchTestDemoMenuDemo, &GFX_Touch_80);
    TouchTestDemoMenuDemo->fn->setReleasedImage(TouchTestDemoMenuDemo, &GFX_Touch_80);
    TouchTestDemoMenuDemo->fn->setReleasedEventCallback(TouchTestDemoMenuDemo, TouchTestDemoMenuDemo_OnReleased);
    root0->fn->addChild(root0, (leWidget*)TouchTestDemoMenuDemo);

    KeypadDemoMenuButton = leButtonWidget_New();
    KeypadDemoMenuButton->fn->setPosition(KeypadDemoMenuButton, 200, 84);
    KeypadDemoMenuButton->fn->setSize(KeypadDemoMenuButton, 84, 77);
    KeypadDemoMenuButton->fn->setBackgroundType(KeypadDemoMenuButton, LE_WIDGET_BACKGROUND_NONE);
    KeypadDemoMenuButton->fn->setBorderType(KeypadDemoMenuButton, LE_WIDGET_BORDER_NONE);
    KeypadDemoMenuButton->fn->setPressedImage(KeypadDemoMenuButton, &GFX_Keyboard_80_drop);
    KeypadDemoMenuButton->fn->setReleasedImage(KeypadDemoMenuButton, &GFX_Keyboard_80_drop);
    KeypadDemoMenuButton->fn->setReleasedEventCallback(KeypadDemoMenuButton, KeypadDemoMenuButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)KeypadDemoMenuButton);

    MainMenuHelpButton = leButtonWidget_New();
    MainMenuHelpButton->fn->setPosition(MainMenuHelpButton, 0, 260);
    MainMenuHelpButton->fn->setSize(MainMenuHelpButton, 60, 60);
    MainMenuHelpButton->fn->setAlphaAmount(MainMenuHelpButton, 220);
    MainMenuHelpButton->fn->setBackgroundType(MainMenuHelpButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelpButton->fn->setBorderType(MainMenuHelpButton, LE_WIDGET_BORDER_NONE);
    MainMenuHelpButton->fn->setPressedImage(MainMenuHelpButton, &GFX_Help_60);
    MainMenuHelpButton->fn->setReleasedImage(MainMenuHelpButton, &GFX_Help_60);
    MainMenuHelpButton->fn->setReleasedEventCallback(MainMenuHelpButton, MainMenuHelpButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelpButton);

    LabelWidget1 = leLabelWidget_New();
    LabelWidget1->fn->setPosition(LabelWidget1, 170, 169);
    LabelWidget1->fn->setSize(LabelWidget1, 161, 32);
    LabelWidget1->fn->setScheme(LabelWidget1, &BlackBackground);
    LabelWidget1->fn->setBackgroundType(LabelWidget1, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget1->fn->setHAlignment(LabelWidget1, LE_HALIGN_CENTER);
    LabelWidget1->fn->setString(LabelWidget1, (leString*)&tableString_Harmony);
    root0->fn->addChild(root0, (leWidget*)LabelWidget1);

    LabelWidget2 = leLabelWidget_New();
    LabelWidget2->fn->setPosition(LabelWidget2, 127, 203);
    LabelWidget2->fn->setSize(LabelWidget2, 243, 31);
    LabelWidget2->fn->setScheme(LabelWidget2, &BlackBackground);
    LabelWidget2->fn->setBackgroundType(LabelWidget2, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget2->fn->setHAlignment(LabelWidget2, LE_HALIGN_CENTER);
    LabelWidget2->fn->setString(LabelWidget2, (leString*)&tableString_Title);
    root0->fn->addChild(root0, (leWidget*)LabelWidget2);

    ImageWidget3 = leImageWidget_New();
    ImageWidget3->fn->setPosition(ImageWidget3, 2, 13);
    ImageWidget3->fn->setSize(ImageWidget3, 153, 37);
    ImageWidget3->fn->setBackgroundType(ImageWidget3, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget3->fn->setImage(ImageWidget3, &GFX_Microchip_logo_150x30);
    root0->fn->addChild(root0, (leWidget*)ImageWidget3);

    ImageWidget4 = leImageWidget_New();
    ImageWidget4->fn->setPosition(ImageWidget4, 386, 0);
    ImageWidget4->fn->setSize(ImageWidget4, 94, 56);
    ImageWidget4->fn->setAlphaAmount(ImageWidget4, 220);
    ImageWidget4->fn->setBackgroundType(ImageWidget4, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget4->fn->setImage(ImageWidget4, &GFX_mplab_logo_80x80);
    root0->fn->addChild(root0, (leWidget*)ImageWidget4);

    MainMenuSettingsButton = leButtonWidget_New();
    MainMenuSettingsButton->fn->setPosition(MainMenuSettingsButton, 420, 260);
    MainMenuSettingsButton->fn->setSize(MainMenuSettingsButton, 60, 60);
    MainMenuSettingsButton->fn->setBackgroundType(MainMenuSettingsButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenuSettingsButton->fn->setBorderType(MainMenuSettingsButton, LE_WIDGET_BORDER_NONE);
    MainMenuSettingsButton->fn->setPressedImage(MainMenuSettingsButton, &GFX_Settings_60x60);
    MainMenuSettingsButton->fn->setReleasedImage(MainMenuSettingsButton, &GFX_Settings_60x60);
    MainMenuSettingsButton->fn->setReleasedEventCallback(MainMenuSettingsButton, MainMenuSettingsButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenuSettingsButton);

    MainMenuNextButton = leButtonWidget_New();
    MainMenuNextButton->fn->setPosition(MainMenuNextButton, 359, 260);
    MainMenuNextButton->fn->setSize(MainMenuNextButton, 60, 60);
    MainMenuNextButton->fn->setBackgroundType(MainMenuNextButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenuNextButton->fn->setBorderType(MainMenuNextButton, LE_WIDGET_BORDER_NONE);
    MainMenuNextButton->fn->setPressedImage(MainMenuNextButton, &GFX_NextScreen_60x60);
    MainMenuNextButton->fn->setReleasedImage(MainMenuNextButton, &GFX_NextScreen_60x60);
    MainMenuNextButton->fn->setReleasedEventCallback(MainMenuNextButton, MainMenuNextButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenuNextButton);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    MainMenu_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_MainMenu()
{
    MainMenu_OnUpdate();
}

void screenHide_MainMenu()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    GradientWidget1 = NULL;
    ListwheelDemoMenuButton = NULL;
    AlphaBlendingDemoMenuButton = NULL;
    SlideShowDemoMenuButton = NULL;
    TouchTestDemoMenuDemo = NULL;
    KeypadDemoMenuButton = NULL;
    MainMenuHelpButton = NULL;
    LabelWidget1 = NULL;
    LabelWidget2 = NULL;
    ImageWidget3 = NULL;
    ImageWidget4 = NULL;
    MainMenuSettingsButton = NULL;
    MainMenuNextButton = NULL;

    tableString_Harmony.fn->destructor(&tableString_Harmony);
    tableString_Title.fn->destructor(&tableString_Title);
    showing = LE_FALSE;
}

void screenDestroy_MainMenu()
{

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

