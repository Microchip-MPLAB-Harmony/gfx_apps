#include "gfx/legato/generated/screen/le_gen_screen_MainMenuHelp.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget0;
leButtonWidget* MainMenuHelpCloseButton;
leImageWidget* ImageWidget6;
leLabelWidget* LabelWidget12;
leLabelWidget* LabelWidget13;
leLabelWidget* LabelWidget14;
leLabelWidget* LabelWidget15;
leLabelWidget* LabelWidget16;
leLabelWidget* LabelWidget17;
leLabelWidget* LabelWidget18;
leLabelWidget* LabelWidget19;
leLabelWidget* LabelWidget20;
leImageWidget* ImageWidget7;
leImageWidget* ImageWidget8;
leImageWidget* ImageWidget9;
leImageWidget* ImageWidget10;
leImageWidget* ImageWidget11;
leImageWidget* ImageWidget12;
leImageWidget* ImageWidget13;

// string list for this screen
static leTableString tableString_Help;
static leTableString tableString_MainIconHelp;
static leTableString tableString_ListWheelWidgetDemoSmall;
static leTableString tableString_TouchTestWidgetDemoSmall;
static leTableString tableString_KeypadWidgetDemoSmall;
static leTableString tableString_AlphaBlendingDemoSmall;
static leTableString tableString_SlideShowDemoSmall;
static leTableString tableString_MainHelpHelp;
static leTableString tableString_MainSettingsHelp;

static leBool showing = LE_FALSE;

leResult screenInit_MainMenuHelp()
{
    return LE_SUCCESS;
}

leResult screenShow_MainMenuHelp()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_Help, string_Help);
    leTableString_Constructor(&tableString_MainIconHelp, string_MainIconHelp);
    leTableString_Constructor(&tableString_ListWheelWidgetDemoSmall, string_ListWheelWidgetDemoSmall);
    leTableString_Constructor(&tableString_TouchTestWidgetDemoSmall, string_TouchTestWidgetDemoSmall);
    leTableString_Constructor(&tableString_KeypadWidgetDemoSmall, string_KeypadWidgetDemoSmall);
    leTableString_Constructor(&tableString_AlphaBlendingDemoSmall, string_AlphaBlendingDemoSmall);
    leTableString_Constructor(&tableString_SlideShowDemoSmall, string_SlideShowDemoSmall);
    leTableString_Constructor(&tableString_MainHelpHelp, string_MainHelpHelp);
    leTableString_Constructor(&tableString_MainSettingsHelp, string_MainSettingsHelp);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget0 = leWidget_New();
    PanelWidget0->fn->setPosition(PanelWidget0, 0, 0);
    PanelWidget0->fn->setSize(PanelWidget0, 480, 320);
    PanelWidget0->fn->setScheme(PanelWidget0, &whiteScheme);
    root0->fn->addChild(root0, PanelWidget0);

    MainMenuHelpCloseButton = leButtonWidget_New();
    MainMenuHelpCloseButton->fn->setPosition(MainMenuHelpCloseButton, 440, 0);
    MainMenuHelpCloseButton->fn->setSize(MainMenuHelpCloseButton, 40, 36);
    MainMenuHelpCloseButton->fn->setBackgroundType(MainMenuHelpCloseButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenuHelpCloseButton->fn->setPressedImage(MainMenuHelpCloseButton, &GFX_CloseX_40x40);
    MainMenuHelpCloseButton->fn->setReleasedImage(MainMenuHelpCloseButton, &GFX_CloseX_40x40);
    MainMenuHelpCloseButton->fn->setReleasedEventCallback(MainMenuHelpCloseButton, MainMenuHelpCloseButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenuHelpCloseButton);

    ImageWidget6 = leImageWidget_New();
    ImageWidget6->fn->setPosition(ImageWidget6, 0, 0);
    ImageWidget6->fn->setSize(ImageWidget6, 40, 40);
    ImageWidget6->fn->setBackgroundType(ImageWidget6, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget6->fn->setImage(ImageWidget6, &GFX_Help_40x40);
    root0->fn->addChild(root0, (leWidget*)ImageWidget6);

    LabelWidget12 = leLabelWidget_New();
    LabelWidget12->fn->setPosition(LabelWidget12, 48, 6);
    LabelWidget12->fn->setSize(LabelWidget12, 113, 25);
    LabelWidget12->fn->setBackgroundType(LabelWidget12, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget12->fn->setString(LabelWidget12, (leString*)&tableString_Help);
    root0->fn->addChild(root0, (leWidget*)LabelWidget12);

    LabelWidget13 = leLabelWidget_New();
    LabelWidget13->fn->setPosition(LabelWidget13, 29, 47);
    LabelWidget13->fn->setSize(LabelWidget13, 316, 25);
    LabelWidget13->fn->setBackgroundType(LabelWidget13, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget13->fn->setString(LabelWidget13, (leString*)&tableString_MainIconHelp);
    root0->fn->addChild(root0, (leWidget*)LabelWidget13);

    LabelWidget14 = leLabelWidget_New();
    LabelWidget14->fn->setPosition(LabelWidget14, 81, 71);
    LabelWidget14->fn->setSize(LabelWidget14, 229, 24);
    LabelWidget14->fn->setBackgroundType(LabelWidget14, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget14->fn->setString(LabelWidget14, (leString*)&tableString_ListWheelWidgetDemoSmall);
    root0->fn->addChild(root0, (leWidget*)LabelWidget14);

    LabelWidget15 = leLabelWidget_New();
    LabelWidget15->fn->setPosition(LabelWidget15, 81, 94);
    LabelWidget15->fn->setSize(LabelWidget15, 286, 25);
    LabelWidget15->fn->setBackgroundType(LabelWidget15, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget15->fn->setString(LabelWidget15, (leString*)&tableString_TouchTestWidgetDemoSmall);
    root0->fn->addChild(root0, (leWidget*)LabelWidget15);

    LabelWidget16 = leLabelWidget_New();
    LabelWidget16->fn->setPosition(LabelWidget16, 81, 118);
    LabelWidget16->fn->setSize(LabelWidget16, 229, 25);
    LabelWidget16->fn->setBackgroundType(LabelWidget16, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget16->fn->setString(LabelWidget16, (leString*)&tableString_KeypadWidgetDemoSmall);
    root0->fn->addChild(root0, (leWidget*)LabelWidget16);

    LabelWidget17 = leLabelWidget_New();
    LabelWidget17->fn->setPosition(LabelWidget17, 81, 142);
    LabelWidget17->fn->setSize(LabelWidget17, 264, 25);
    LabelWidget17->fn->setBackgroundType(LabelWidget17, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget17->fn->setString(LabelWidget17, (leString*)&tableString_AlphaBlendingDemoSmall);
    root0->fn->addChild(root0, (leWidget*)LabelWidget17);

    LabelWidget18 = leLabelWidget_New();
    LabelWidget18->fn->setPosition(LabelWidget18, 81, 166);
    LabelWidget18->fn->setSize(LabelWidget18, 229, 25);
    LabelWidget18->fn->setBackgroundType(LabelWidget18, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget18->fn->setString(LabelWidget18, (leString*)&tableString_SlideShowDemoSmall);
    root0->fn->addChild(root0, (leWidget*)LabelWidget18);

    LabelWidget19 = leLabelWidget_New();
    LabelWidget19->fn->setPosition(LabelWidget19, 56, 190);
    LabelWidget19->fn->setSize(LabelWidget19, 289, 25);
    LabelWidget19->fn->setBackgroundType(LabelWidget19, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget19->fn->setString(LabelWidget19, (leString*)&tableString_MainHelpHelp);
    root0->fn->addChild(root0, (leWidget*)LabelWidget19);

    LabelWidget20 = leLabelWidget_New();
    LabelWidget20->fn->setPosition(LabelWidget20, 56, 214);
    LabelWidget20->fn->setSize(LabelWidget20, 348, 25);
    LabelWidget20->fn->setBackgroundType(LabelWidget20, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget20->fn->setString(LabelWidget20, (leString*)&tableString_MainSettingsHelp);
    root0->fn->addChild(root0, (leWidget*)LabelWidget20);

    ImageWidget7 = leImageWidget_New();
    ImageWidget7->fn->setPosition(ImageWidget7, 55, 144);
    ImageWidget7->fn->setSize(ImageWidget7, 20, 20);
    ImageWidget7->fn->setBackgroundType(ImageWidget7, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget7->fn->setImage(ImageWidget7, &GFX_alpha_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget7);

    ImageWidget8 = leImageWidget_New();
    ImageWidget8->fn->setPosition(ImageWidget8, 31, 190);
    ImageWidget8->fn->setSize(ImageWidget8, 20, 20);
    ImageWidget8->fn->setBackgroundType(ImageWidget8, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget8->fn->setImage(ImageWidget8, &GFX_Help_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget8);

    ImageWidget9 = leImageWidget_New();
    ImageWidget9->fn->setPosition(ImageWidget9, 30, 215);
    ImageWidget9->fn->setSize(ImageWidget9, 20, 20);
    ImageWidget9->fn->setBackgroundType(ImageWidget9, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget9->fn->setImage(ImageWidget9, &GFX_Settings_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget9);

    ImageWidget10 = leImageWidget_New();
    ImageWidget10->fn->setPosition(ImageWidget10, 55, 71);
    ImageWidget10->fn->setSize(ImageWidget10, 20, 20);
    ImageWidget10->fn->setBackgroundType(ImageWidget10, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget10->fn->setImage(ImageWidget10, &GFX_ListWheel_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget10);

    ImageWidget11 = leImageWidget_New();
    ImageWidget11->fn->setPosition(ImageWidget11, 55, 94);
    ImageWidget11->fn->setSize(ImageWidget11, 20, 20);
    ImageWidget11->fn->setBackgroundType(ImageWidget11, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget11->fn->setImage(ImageWidget11, &GFX_Touch_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget11);

    ImageWidget12 = leImageWidget_New();
    ImageWidget12->fn->setPosition(ImageWidget12, 55, 167);
    ImageWidget12->fn->setSize(ImageWidget12, 20, 20);
    ImageWidget12->fn->setBackgroundType(ImageWidget12, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget12->fn->setImage(ImageWidget12, &GFX_Slideshow_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget12);

    ImageWidget13 = leImageWidget_New();
    ImageWidget13->fn->setPosition(ImageWidget13, 55, 118);
    ImageWidget13->fn->setSize(ImageWidget13, 20, 20);
    ImageWidget13->fn->setBackgroundType(ImageWidget13, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget13->fn->setImage(ImageWidget13, &GFX_Keypad_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget13);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    MainMenuHelp_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_MainMenuHelp()
{
    MainMenuHelp_OnUpdate();
}

void screenHide_MainMenuHelp()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget0 = NULL;
    MainMenuHelpCloseButton = NULL;
    ImageWidget6 = NULL;
    LabelWidget12 = NULL;
    LabelWidget13 = NULL;
    LabelWidget14 = NULL;
    LabelWidget15 = NULL;
    LabelWidget16 = NULL;
    LabelWidget17 = NULL;
    LabelWidget18 = NULL;
    LabelWidget19 = NULL;
    LabelWidget20 = NULL;
    ImageWidget7 = NULL;
    ImageWidget8 = NULL;
    ImageWidget9 = NULL;
    ImageWidget10 = NULL;
    ImageWidget11 = NULL;
    ImageWidget12 = NULL;
    ImageWidget13 = NULL;

    tableString_Help.fn->destructor(&tableString_Help);
    tableString_MainIconHelp.fn->destructor(&tableString_MainIconHelp);
    tableString_ListWheelWidgetDemoSmall.fn->destructor(&tableString_ListWheelWidgetDemoSmall);
    tableString_TouchTestWidgetDemoSmall.fn->destructor(&tableString_TouchTestWidgetDemoSmall);
    tableString_KeypadWidgetDemoSmall.fn->destructor(&tableString_KeypadWidgetDemoSmall);
    tableString_AlphaBlendingDemoSmall.fn->destructor(&tableString_AlphaBlendingDemoSmall);
    tableString_SlideShowDemoSmall.fn->destructor(&tableString_SlideShowDemoSmall);
    tableString_MainHelpHelp.fn->destructor(&tableString_MainHelpHelp);
    tableString_MainSettingsHelp.fn->destructor(&tableString_MainSettingsHelp);
    showing = LE_FALSE;
}

void screenDestroy_MainMenuHelp()
{

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

