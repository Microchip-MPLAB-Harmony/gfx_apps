#include "gfx/legato/generated/screen/le_gen_screen_TouchTestHelpScreen.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget5;
leImageWidget* ImageWidget17;
leButtonWidget* TouchTestHelpCloseButton;
leLabelWidget* LabelWidget25;
leLabelWidget* LabelWidget26;
leLabelWidget* LabelWidget28;
leImageWidget* ImageWidget19;

// string list for this screen
static leTableString tableString_Help;
static leTableString tableString_TouchTestHelpInfo;
static leTableString tableString_HomeHelpText;

static leBool showing = LE_FALSE;

leResult screenInit_TouchTestHelpScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_TouchTestHelpScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_Help, string_Help);
    leTableString_Constructor(&tableString_TouchTestHelpInfo, string_TouchTestHelpInfo);
    leTableString_Constructor(&tableString_HomeHelpText, string_HomeHelpText);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget5 = leWidget_New();
    PanelWidget5->fn->setPosition(PanelWidget5, 0, 0);
    PanelWidget5->fn->setSize(PanelWidget5, 480, 320);
    PanelWidget5->fn->setScheme(PanelWidget5, &whiteScheme);
    root0->fn->addChild(root0, PanelWidget5);

    ImageWidget17 = leImageWidget_New();
    ImageWidget17->fn->setPosition(ImageWidget17, 0, 0);
    ImageWidget17->fn->setSize(ImageWidget17, 40, 40);
    ImageWidget17->fn->setBackgroundType(ImageWidget17, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget17->fn->setImage(ImageWidget17, &GFX_Help_40x40);
    root0->fn->addChild(root0, (leWidget*)ImageWidget17);

    TouchTestHelpCloseButton = leButtonWidget_New();
    TouchTestHelpCloseButton->fn->setPosition(TouchTestHelpCloseButton, 440, 0);
    TouchTestHelpCloseButton->fn->setSize(TouchTestHelpCloseButton, 40, 40);
    TouchTestHelpCloseButton->fn->setBackgroundType(TouchTestHelpCloseButton, LE_WIDGET_BACKGROUND_NONE);
    TouchTestHelpCloseButton->fn->setPressedImage(TouchTestHelpCloseButton, &GFX_CloseX_40x40);
    TouchTestHelpCloseButton->fn->setReleasedImage(TouchTestHelpCloseButton, &GFX_CloseX_40x40);
    TouchTestHelpCloseButton->fn->setReleasedEventCallback(TouchTestHelpCloseButton, TouchTestHelpCloseButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)TouchTestHelpCloseButton);

    LabelWidget25 = leLabelWidget_New();
    LabelWidget25->fn->setPosition(LabelWidget25, 48, 6);
    LabelWidget25->fn->setBackgroundType(LabelWidget25, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget25->fn->setString(LabelWidget25, (leString*)&tableString_Help);
    root0->fn->addChild(root0, (leWidget*)LabelWidget25);

    LabelWidget26 = leLabelWidget_New();
    LabelWidget26->fn->setPosition(LabelWidget26, 29, 47);
    LabelWidget26->fn->setSize(LabelWidget26, 387, 25);
    LabelWidget26->fn->setBackgroundType(LabelWidget26, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget26->fn->setString(LabelWidget26, (leString*)&tableString_TouchTestHelpInfo);
    root0->fn->addChild(root0, (leWidget*)LabelWidget26);

    LabelWidget28 = leLabelWidget_New();
    LabelWidget28->fn->setPosition(LabelWidget28, 59, 71);
    LabelWidget28->fn->setSize(LabelWidget28, 317, 25);
    LabelWidget28->fn->setBackgroundType(LabelWidget28, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget28->fn->setString(LabelWidget28, (leString*)&tableString_HomeHelpText);
    root0->fn->addChild(root0, (leWidget*)LabelWidget28);

    ImageWidget19 = leImageWidget_New();
    ImageWidget19->fn->setPosition(ImageWidget19, 32, 75);
    ImageWidget19->fn->setSize(ImageWidget19, 20, 20);
    ImageWidget19->fn->setBackgroundType(ImageWidget19, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget19->fn->setImage(ImageWidget19, &GFX_Home_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget19);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    TouchTestHelpScreen_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_TouchTestHelpScreen()
{
    TouchTestHelpScreen_OnUpdate();
}

void screenHide_TouchTestHelpScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget5 = NULL;
    ImageWidget17 = NULL;
    TouchTestHelpCloseButton = NULL;
    LabelWidget25 = NULL;
    LabelWidget26 = NULL;
    LabelWidget28 = NULL;
    ImageWidget19 = NULL;

    tableString_Help.fn->destructor(&tableString_Help);
    tableString_TouchTestHelpInfo.fn->destructor(&tableString_TouchTestHelpInfo);
    tableString_HomeHelpText.fn->destructor(&tableString_HomeHelpText);
    showing = LE_FALSE;
}

void screenDestroy_TouchTestHelpScreen()
{

}

leWidget* screenGetRoot_TouchTestHelpScreen(uint32_t lyrIdx)
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

