#include "gfx/legato/generated/screen/le_gen_screen_MainMenuHelp.h"

// screen member widget declarations
leWidget* root0;

leWidget* MainMenuHelp_PanelWidget0;
leButtonWidget* MainMenuHelp_MainMenuHelpCloseButton;
leImageWidget* MainMenuHelp_ImageWidget6;
leLabelWidget* MainMenuHelp_LabelWidget12;
leLabelWidget* MainMenuHelp_LabelWidget13;
leLabelWidget* MainMenuHelp_LabelWidget14;
leLabelWidget* MainMenuHelp_LabelWidget15;
leLabelWidget* MainMenuHelp_LabelWidget16;
leLabelWidget* MainMenuHelp_LabelWidget17;
leLabelWidget* MainMenuHelp_LabelWidget18;
leLabelWidget* MainMenuHelp_LabelWidget19;
leLabelWidget* MainMenuHelp_LabelWidget20;
leImageWidget* MainMenuHelp_ImageWidget7;
leImageWidget* MainMenuHelp_ImageWidget8;
leImageWidget* MainMenuHelp_ImageWidget9;
leImageWidget* MainMenuHelp_ImageWidget10;
leImageWidget* MainMenuHelp_ImageWidget11;
leImageWidget* MainMenuHelp_ImageWidget12;
leImageWidget* MainMenuHelp_ImageWidget13;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_MainMenuHelp()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_MainMenuHelp()
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

    MainMenuHelp_PanelWidget0 = leWidget_New();
    MainMenuHelp_PanelWidget0->fn->setPosition(MainMenuHelp_PanelWidget0, 0, 0);
    MainMenuHelp_PanelWidget0->fn->setSize(MainMenuHelp_PanelWidget0, 480, 320);
    MainMenuHelp_PanelWidget0->fn->setScheme(MainMenuHelp_PanelWidget0, &whiteScheme);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_PanelWidget0);

    MainMenuHelp_MainMenuHelpCloseButton = leButtonWidget_New();
    MainMenuHelp_MainMenuHelpCloseButton->fn->setPosition(MainMenuHelp_MainMenuHelpCloseButton, 440, 0);
    MainMenuHelp_MainMenuHelpCloseButton->fn->setSize(MainMenuHelp_MainMenuHelpCloseButton, 40, 36);
    MainMenuHelp_MainMenuHelpCloseButton->fn->setBackgroundType(MainMenuHelp_MainMenuHelpCloseButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_MainMenuHelpCloseButton->fn->setPressedImage(MainMenuHelp_MainMenuHelpCloseButton, (leImage*)&GFX_CloseX_40x40);
    MainMenuHelp_MainMenuHelpCloseButton->fn->setReleasedImage(MainMenuHelp_MainMenuHelpCloseButton, (leImage*)&GFX_CloseX_40x40);
    MainMenuHelp_MainMenuHelpCloseButton->fn->setReleasedEventCallback(MainMenuHelp_MainMenuHelpCloseButton, event_MainMenuHelp_MainMenuHelpCloseButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_MainMenuHelpCloseButton);

    MainMenuHelp_ImageWidget6 = leImageWidget_New();
    MainMenuHelp_ImageWidget6->fn->setPosition(MainMenuHelp_ImageWidget6, 0, 0);
    MainMenuHelp_ImageWidget6->fn->setSize(MainMenuHelp_ImageWidget6, 40, 40);
    MainMenuHelp_ImageWidget6->fn->setBackgroundType(MainMenuHelp_ImageWidget6, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_ImageWidget6->fn->setBorderType(MainMenuHelp_ImageWidget6, LE_WIDGET_BORDER_NONE);
    MainMenuHelp_ImageWidget6->fn->setImage(MainMenuHelp_ImageWidget6, (leImage*)&GFX_Help_40x40);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_ImageWidget6);

    MainMenuHelp_LabelWidget12 = leLabelWidget_New();
    MainMenuHelp_LabelWidget12->fn->setPosition(MainMenuHelp_LabelWidget12, 48, 6);
    MainMenuHelp_LabelWidget12->fn->setSize(MainMenuHelp_LabelWidget12, 113, 25);
    MainMenuHelp_LabelWidget12->fn->setBackgroundType(MainMenuHelp_LabelWidget12, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_LabelWidget12->fn->setString(MainMenuHelp_LabelWidget12, (leString*)&string_Help);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_LabelWidget12);

    MainMenuHelp_LabelWidget13 = leLabelWidget_New();
    MainMenuHelp_LabelWidget13->fn->setPosition(MainMenuHelp_LabelWidget13, 29, 47);
    MainMenuHelp_LabelWidget13->fn->setSize(MainMenuHelp_LabelWidget13, 406, 25);
    MainMenuHelp_LabelWidget13->fn->setBackgroundType(MainMenuHelp_LabelWidget13, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_LabelWidget13->fn->setString(MainMenuHelp_LabelWidget13, (leString*)&string_MainIconHelp);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_LabelWidget13);

    MainMenuHelp_LabelWidget14 = leLabelWidget_New();
    MainMenuHelp_LabelWidget14->fn->setPosition(MainMenuHelp_LabelWidget14, 81, 71);
    MainMenuHelp_LabelWidget14->fn->setSize(MainMenuHelp_LabelWidget14, 229, 24);
    MainMenuHelp_LabelWidget14->fn->setBackgroundType(MainMenuHelp_LabelWidget14, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_LabelWidget14->fn->setString(MainMenuHelp_LabelWidget14, (leString*)&string_ListWheelWidgetDemoSmall);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_LabelWidget14);

    MainMenuHelp_LabelWidget15 = leLabelWidget_New();
    MainMenuHelp_LabelWidget15->fn->setPosition(MainMenuHelp_LabelWidget15, 81, 94);
    MainMenuHelp_LabelWidget15->fn->setSize(MainMenuHelp_LabelWidget15, 286, 25);
    MainMenuHelp_LabelWidget15->fn->setBackgroundType(MainMenuHelp_LabelWidget15, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_LabelWidget15->fn->setString(MainMenuHelp_LabelWidget15, (leString*)&string_TouchTestWidgetDemoSmall);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_LabelWidget15);

    MainMenuHelp_LabelWidget16 = leLabelWidget_New();
    MainMenuHelp_LabelWidget16->fn->setPosition(MainMenuHelp_LabelWidget16, 81, 118);
    MainMenuHelp_LabelWidget16->fn->setSize(MainMenuHelp_LabelWidget16, 229, 25);
    MainMenuHelp_LabelWidget16->fn->setBackgroundType(MainMenuHelp_LabelWidget16, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_LabelWidget16->fn->setString(MainMenuHelp_LabelWidget16, (leString*)&string_KeypadWidgetDemoSmall);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_LabelWidget16);

    MainMenuHelp_LabelWidget17 = leLabelWidget_New();
    MainMenuHelp_LabelWidget17->fn->setPosition(MainMenuHelp_LabelWidget17, 81, 142);
    MainMenuHelp_LabelWidget17->fn->setSize(MainMenuHelp_LabelWidget17, 264, 25);
    MainMenuHelp_LabelWidget17->fn->setBackgroundType(MainMenuHelp_LabelWidget17, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_LabelWidget17->fn->setString(MainMenuHelp_LabelWidget17, (leString*)&string_AlphaBlendingDemoSmall);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_LabelWidget17);

    MainMenuHelp_LabelWidget18 = leLabelWidget_New();
    MainMenuHelp_LabelWidget18->fn->setPosition(MainMenuHelp_LabelWidget18, 81, 166);
    MainMenuHelp_LabelWidget18->fn->setSize(MainMenuHelp_LabelWidget18, 229, 25);
    MainMenuHelp_LabelWidget18->fn->setBackgroundType(MainMenuHelp_LabelWidget18, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_LabelWidget18->fn->setString(MainMenuHelp_LabelWidget18, (leString*)&string_SlideShowDemoSmall);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_LabelWidget18);

    MainMenuHelp_LabelWidget19 = leLabelWidget_New();
    MainMenuHelp_LabelWidget19->fn->setPosition(MainMenuHelp_LabelWidget19, 56, 190);
    MainMenuHelp_LabelWidget19->fn->setSize(MainMenuHelp_LabelWidget19, 367, 25);
    MainMenuHelp_LabelWidget19->fn->setBackgroundType(MainMenuHelp_LabelWidget19, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_LabelWidget19->fn->setString(MainMenuHelp_LabelWidget19, (leString*)&string_MainHelpHelp);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_LabelWidget19);

    MainMenuHelp_LabelWidget20 = leLabelWidget_New();
    MainMenuHelp_LabelWidget20->fn->setPosition(MainMenuHelp_LabelWidget20, 56, 214);
    MainMenuHelp_LabelWidget20->fn->setSize(MainMenuHelp_LabelWidget20, 236, 25);
    MainMenuHelp_LabelWidget20->fn->setBackgroundType(MainMenuHelp_LabelWidget20, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_LabelWidget20->fn->setString(MainMenuHelp_LabelWidget20, (leString*)&string_MainSettingsHelp);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_LabelWidget20);

    MainMenuHelp_ImageWidget7 = leImageWidget_New();
    MainMenuHelp_ImageWidget7->fn->setPosition(MainMenuHelp_ImageWidget7, 55, 144);
    MainMenuHelp_ImageWidget7->fn->setSize(MainMenuHelp_ImageWidget7, 20, 20);
    MainMenuHelp_ImageWidget7->fn->setBackgroundType(MainMenuHelp_ImageWidget7, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_ImageWidget7->fn->setBorderType(MainMenuHelp_ImageWidget7, LE_WIDGET_BORDER_NONE);
    MainMenuHelp_ImageWidget7->fn->setImage(MainMenuHelp_ImageWidget7, (leImage*)&GFX_alpha_20x20);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_ImageWidget7);

    MainMenuHelp_ImageWidget8 = leImageWidget_New();
    MainMenuHelp_ImageWidget8->fn->setPosition(MainMenuHelp_ImageWidget8, 31, 190);
    MainMenuHelp_ImageWidget8->fn->setSize(MainMenuHelp_ImageWidget8, 20, 20);
    MainMenuHelp_ImageWidget8->fn->setBackgroundType(MainMenuHelp_ImageWidget8, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_ImageWidget8->fn->setBorderType(MainMenuHelp_ImageWidget8, LE_WIDGET_BORDER_NONE);
    MainMenuHelp_ImageWidget8->fn->setImage(MainMenuHelp_ImageWidget8, (leImage*)&GFX_Help_20x20);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_ImageWidget8);

    MainMenuHelp_ImageWidget9 = leImageWidget_New();
    MainMenuHelp_ImageWidget9->fn->setPosition(MainMenuHelp_ImageWidget9, 30, 215);
    MainMenuHelp_ImageWidget9->fn->setSize(MainMenuHelp_ImageWidget9, 20, 20);
    MainMenuHelp_ImageWidget9->fn->setBackgroundType(MainMenuHelp_ImageWidget9, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_ImageWidget9->fn->setBorderType(MainMenuHelp_ImageWidget9, LE_WIDGET_BORDER_NONE);
    MainMenuHelp_ImageWidget9->fn->setImage(MainMenuHelp_ImageWidget9, (leImage*)&GFX_Settings_20x20);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_ImageWidget9);

    MainMenuHelp_ImageWidget10 = leImageWidget_New();
    MainMenuHelp_ImageWidget10->fn->setPosition(MainMenuHelp_ImageWidget10, 55, 71);
    MainMenuHelp_ImageWidget10->fn->setSize(MainMenuHelp_ImageWidget10, 20, 20);
    MainMenuHelp_ImageWidget10->fn->setBackgroundType(MainMenuHelp_ImageWidget10, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_ImageWidget10->fn->setBorderType(MainMenuHelp_ImageWidget10, LE_WIDGET_BORDER_NONE);
    MainMenuHelp_ImageWidget10->fn->setImage(MainMenuHelp_ImageWidget10, (leImage*)&GFX_ListWheel_20x20);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_ImageWidget10);

    MainMenuHelp_ImageWidget11 = leImageWidget_New();
    MainMenuHelp_ImageWidget11->fn->setPosition(MainMenuHelp_ImageWidget11, 55, 94);
    MainMenuHelp_ImageWidget11->fn->setSize(MainMenuHelp_ImageWidget11, 20, 20);
    MainMenuHelp_ImageWidget11->fn->setBackgroundType(MainMenuHelp_ImageWidget11, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_ImageWidget11->fn->setBorderType(MainMenuHelp_ImageWidget11, LE_WIDGET_BORDER_NONE);
    MainMenuHelp_ImageWidget11->fn->setImage(MainMenuHelp_ImageWidget11, (leImage*)&GFX_Touch_20x20);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_ImageWidget11);

    MainMenuHelp_ImageWidget12 = leImageWidget_New();
    MainMenuHelp_ImageWidget12->fn->setPosition(MainMenuHelp_ImageWidget12, 55, 167);
    MainMenuHelp_ImageWidget12->fn->setSize(MainMenuHelp_ImageWidget12, 20, 20);
    MainMenuHelp_ImageWidget12->fn->setBackgroundType(MainMenuHelp_ImageWidget12, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_ImageWidget12->fn->setBorderType(MainMenuHelp_ImageWidget12, LE_WIDGET_BORDER_NONE);
    MainMenuHelp_ImageWidget12->fn->setImage(MainMenuHelp_ImageWidget12, (leImage*)&GFX_Slideshow_20x20);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_ImageWidget12);

    MainMenuHelp_ImageWidget13 = leImageWidget_New();
    MainMenuHelp_ImageWidget13->fn->setPosition(MainMenuHelp_ImageWidget13, 55, 118);
    MainMenuHelp_ImageWidget13->fn->setSize(MainMenuHelp_ImageWidget13, 20, 20);
    MainMenuHelp_ImageWidget13->fn->setBackgroundType(MainMenuHelp_ImageWidget13, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelp_ImageWidget13->fn->setBorderType(MainMenuHelp_ImageWidget13, LE_WIDGET_BORDER_NONE);
    MainMenuHelp_ImageWidget13->fn->setImage(MainMenuHelp_ImageWidget13, (leImage*)&GFX_Keypad_20x20);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelp_ImageWidget13);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    MainMenuHelp_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_MainMenuHelp()
{
    MainMenuHelp_OnUpdate(); // raise event
}

void screenHide_MainMenuHelp()
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    MainMenuHelp_PanelWidget0 = NULL;
    MainMenuHelp_MainMenuHelpCloseButton = NULL;
    MainMenuHelp_ImageWidget6 = NULL;
    MainMenuHelp_LabelWidget12 = NULL;
    MainMenuHelp_LabelWidget13 = NULL;
    MainMenuHelp_LabelWidget14 = NULL;
    MainMenuHelp_LabelWidget15 = NULL;
    MainMenuHelp_LabelWidget16 = NULL;
    MainMenuHelp_LabelWidget17 = NULL;
    MainMenuHelp_LabelWidget18 = NULL;
    MainMenuHelp_LabelWidget19 = NULL;
    MainMenuHelp_LabelWidget20 = NULL;
    MainMenuHelp_ImageWidget7 = NULL;
    MainMenuHelp_ImageWidget8 = NULL;
    MainMenuHelp_ImageWidget9 = NULL;
    MainMenuHelp_ImageWidget10 = NULL;
    MainMenuHelp_ImageWidget11 = NULL;
    MainMenuHelp_ImageWidget12 = NULL;
    MainMenuHelp_ImageWidget13 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_MainMenuHelp()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_MainMenuHelp(uint32_t lyrIdx)
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

