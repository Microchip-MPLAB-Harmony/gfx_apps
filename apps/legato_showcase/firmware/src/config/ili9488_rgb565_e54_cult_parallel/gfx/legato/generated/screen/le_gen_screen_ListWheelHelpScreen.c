#include "gfx/legato/generated/screen/le_gen_screen_ListWheelHelpScreen.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget4;
leImageWidget* ImageWidget14;
leLabelWidget* LabelWidget21;
leButtonWidget* ListWheelHelpCloseButton;
leLabelWidget* LabelWidget22;
leLabelWidget* LabelWidget24;
leImageWidget* ImageWidget16;

// string list for this screen
static leTableString tableString_Help;
static leTableString tableString_ListWheelHelp;
static leTableString tableString_HomeHelpText;

static leBool showing = LE_FALSE;

leResult screenInit_ListWheelHelpScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_ListWheelHelpScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_Help, string_Help);
    leTableString_Constructor(&tableString_ListWheelHelp, string_ListWheelHelp);
    leTableString_Constructor(&tableString_HomeHelpText, string_HomeHelpText);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget4 = leWidget_New();
    PanelWidget4->fn->setPosition(PanelWidget4, 0, 0);
    PanelWidget4->fn->setSize(PanelWidget4, 480, 320);
    PanelWidget4->fn->setScheme(PanelWidget4, &whiteScheme);
    root0->fn->addChild(root0, PanelWidget4);

    ImageWidget14 = leImageWidget_New();
    ImageWidget14->fn->setPosition(ImageWidget14, 0, 0);
    ImageWidget14->fn->setSize(ImageWidget14, 40, 40);
    ImageWidget14->fn->setBackgroundType(ImageWidget14, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget14->fn->setImage(ImageWidget14, &GFX_Help_40x40);
    root0->fn->addChild(root0, (leWidget*)ImageWidget14);

    LabelWidget21 = leLabelWidget_New();
    LabelWidget21->fn->setPosition(LabelWidget21, 48, 6);
    LabelWidget21->fn->setSize(LabelWidget21, 332, 25);
    LabelWidget21->fn->setBackgroundType(LabelWidget21, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget21->fn->setString(LabelWidget21, (leString*)&tableString_Help);
    root0->fn->addChild(root0, (leWidget*)LabelWidget21);

    ListWheelHelpCloseButton = leButtonWidget_New();
    ListWheelHelpCloseButton->fn->setPosition(ListWheelHelpCloseButton, 440, 0);
    ListWheelHelpCloseButton->fn->setSize(ListWheelHelpCloseButton, 40, 40);
    ListWheelHelpCloseButton->fn->setScheme(ListWheelHelpCloseButton, &defaultScheme);
    ListWheelHelpCloseButton->fn->setBackgroundType(ListWheelHelpCloseButton, LE_WIDGET_BACKGROUND_NONE);
    ListWheelHelpCloseButton->fn->setPressedImage(ListWheelHelpCloseButton, &GFX_CloseX_40x40);
    ListWheelHelpCloseButton->fn->setReleasedImage(ListWheelHelpCloseButton, &GFX_CloseX_40x40);
    ListWheelHelpCloseButton->fn->setReleasedEventCallback(ListWheelHelpCloseButton, ListWheelHelpCloseButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ListWheelHelpCloseButton);

    LabelWidget22 = leLabelWidget_New();
    LabelWidget22->fn->setPosition(LabelWidget22, 29, 47);
    LabelWidget22->fn->setSize(LabelWidget22, 411, 25);
    LabelWidget22->fn->setBackgroundType(LabelWidget22, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget22->fn->setString(LabelWidget22, (leString*)&tableString_ListWheelHelp);
    root0->fn->addChild(root0, (leWidget*)LabelWidget22);

    LabelWidget24 = leLabelWidget_New();
    LabelWidget24->fn->setPosition(LabelWidget24, 62, 71);
    LabelWidget24->fn->setSize(LabelWidget24, 260, 25);
    LabelWidget24->fn->setBackgroundType(LabelWidget24, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget24->fn->setString(LabelWidget24, (leString*)&tableString_HomeHelpText);
    root0->fn->addChild(root0, (leWidget*)LabelWidget24);

    ImageWidget16 = leImageWidget_New();
    ImageWidget16->fn->setPosition(ImageWidget16, 36, 73);
    ImageWidget16->fn->setSize(ImageWidget16, 20, 20);
    ImageWidget16->fn->setBackgroundType(ImageWidget16, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget16->fn->setImage(ImageWidget16, &GFX_Home_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget16);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    ListWheelHelpScreen_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_ListWheelHelpScreen()
{
    ListWheelHelpScreen_OnUpdate();
}

void screenHide_ListWheelHelpScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget4 = NULL;
    ImageWidget14 = NULL;
    LabelWidget21 = NULL;
    ListWheelHelpCloseButton = NULL;
    LabelWidget22 = NULL;
    LabelWidget24 = NULL;
    ImageWidget16 = NULL;

    tableString_Help.fn->destructor(&tableString_Help);
    tableString_ListWheelHelp.fn->destructor(&tableString_ListWheelHelp);
    tableString_HomeHelpText.fn->destructor(&tableString_HomeHelpText);
    showing = LE_FALSE;
}

void screenDestroy_ListWheelHelpScreen()
{

}

leWidget* screenGetRoot_ListWheelHelpScreen(uint32_t lyrIdx)
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

