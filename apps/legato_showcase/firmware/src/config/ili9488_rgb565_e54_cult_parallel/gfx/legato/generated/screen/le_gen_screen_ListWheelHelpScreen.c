#include "gfx/legato/generated/screen/le_gen_screen_ListWheelHelpScreen.h"

// screen member widget declarations
leWidget* root0;

leWidget* ListWheelHelpScreen_PanelWidget4;
leImageWidget* ListWheelHelpScreen_ImageWidget14;
leLabelWidget* ListWheelHelpScreen_LabelWidget21;
leButtonWidget* ListWheelHelpScreen_ListWheelHelpCloseButton;
leLabelWidget* ListWheelHelpScreen_LabelWidget22;
leLabelWidget* ListWheelHelpScreen_LabelWidget24;
leImageWidget* ListWheelHelpScreen_ImageWidget16;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_ListWheelHelpScreen()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_ListWheelHelpScreen()
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

    ListWheelHelpScreen_PanelWidget4 = leWidget_New();
    ListWheelHelpScreen_PanelWidget4->fn->setPosition(ListWheelHelpScreen_PanelWidget4, 0, 0);
    ListWheelHelpScreen_PanelWidget4->fn->setSize(ListWheelHelpScreen_PanelWidget4, 480, 320);
    ListWheelHelpScreen_PanelWidget4->fn->setScheme(ListWheelHelpScreen_PanelWidget4, &whiteScheme);
    root0->fn->addChild(root0, (leWidget*)ListWheelHelpScreen_PanelWidget4);

    ListWheelHelpScreen_ImageWidget14 = leImageWidget_New();
    ListWheelHelpScreen_ImageWidget14->fn->setPosition(ListWheelHelpScreen_ImageWidget14, 0, 0);
    ListWheelHelpScreen_ImageWidget14->fn->setSize(ListWheelHelpScreen_ImageWidget14, 40, 40);
    ListWheelHelpScreen_ImageWidget14->fn->setBackgroundType(ListWheelHelpScreen_ImageWidget14, LE_WIDGET_BACKGROUND_NONE);
    ListWheelHelpScreen_ImageWidget14->fn->setBorderType(ListWheelHelpScreen_ImageWidget14, LE_WIDGET_BORDER_NONE);
    ListWheelHelpScreen_ImageWidget14->fn->setImage(ListWheelHelpScreen_ImageWidget14, (leImage*)&GFX_Help_40x40);
    root0->fn->addChild(root0, (leWidget*)ListWheelHelpScreen_ImageWidget14);

    ListWheelHelpScreen_LabelWidget21 = leLabelWidget_New();
    ListWheelHelpScreen_LabelWidget21->fn->setPosition(ListWheelHelpScreen_LabelWidget21, 48, 6);
    ListWheelHelpScreen_LabelWidget21->fn->setSize(ListWheelHelpScreen_LabelWidget21, 332, 25);
    ListWheelHelpScreen_LabelWidget21->fn->setBackgroundType(ListWheelHelpScreen_LabelWidget21, LE_WIDGET_BACKGROUND_NONE);
    ListWheelHelpScreen_LabelWidget21->fn->setString(ListWheelHelpScreen_LabelWidget21, (leString*)&string_Help);
    root0->fn->addChild(root0, (leWidget*)ListWheelHelpScreen_LabelWidget21);

    ListWheelHelpScreen_ListWheelHelpCloseButton = leButtonWidget_New();
    ListWheelHelpScreen_ListWheelHelpCloseButton->fn->setPosition(ListWheelHelpScreen_ListWheelHelpCloseButton, 440, 0);
    ListWheelHelpScreen_ListWheelHelpCloseButton->fn->setSize(ListWheelHelpScreen_ListWheelHelpCloseButton, 40, 40);
    ListWheelHelpScreen_ListWheelHelpCloseButton->fn->setScheme(ListWheelHelpScreen_ListWheelHelpCloseButton, &defaultScheme);
    ListWheelHelpScreen_ListWheelHelpCloseButton->fn->setBackgroundType(ListWheelHelpScreen_ListWheelHelpCloseButton, LE_WIDGET_BACKGROUND_NONE);
    ListWheelHelpScreen_ListWheelHelpCloseButton->fn->setPressedImage(ListWheelHelpScreen_ListWheelHelpCloseButton, (leImage*)&GFX_CloseX_40x40);
    ListWheelHelpScreen_ListWheelHelpCloseButton->fn->setReleasedImage(ListWheelHelpScreen_ListWheelHelpCloseButton, (leImage*)&GFX_CloseX_40x40);
    ListWheelHelpScreen_ListWheelHelpCloseButton->fn->setReleasedEventCallback(ListWheelHelpScreen_ListWheelHelpCloseButton, event_ListWheelHelpScreen_ListWheelHelpCloseButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ListWheelHelpScreen_ListWheelHelpCloseButton);

    ListWheelHelpScreen_LabelWidget22 = leLabelWidget_New();
    ListWheelHelpScreen_LabelWidget22->fn->setPosition(ListWheelHelpScreen_LabelWidget22, 29, 47);
    ListWheelHelpScreen_LabelWidget22->fn->setSize(ListWheelHelpScreen_LabelWidget22, 493, 25);
    ListWheelHelpScreen_LabelWidget22->fn->setBackgroundType(ListWheelHelpScreen_LabelWidget22, LE_WIDGET_BACKGROUND_NONE);
    ListWheelHelpScreen_LabelWidget22->fn->setString(ListWheelHelpScreen_LabelWidget22, (leString*)&string_ListWheelHelp);
    root0->fn->addChild(root0, (leWidget*)ListWheelHelpScreen_LabelWidget22);

    ListWheelHelpScreen_LabelWidget24 = leLabelWidget_New();
    ListWheelHelpScreen_LabelWidget24->fn->setPosition(ListWheelHelpScreen_LabelWidget24, 62, 71);
    ListWheelHelpScreen_LabelWidget24->fn->setSize(ListWheelHelpScreen_LabelWidget24, 378, 25);
    ListWheelHelpScreen_LabelWidget24->fn->setBackgroundType(ListWheelHelpScreen_LabelWidget24, LE_WIDGET_BACKGROUND_NONE);
    ListWheelHelpScreen_LabelWidget24->fn->setString(ListWheelHelpScreen_LabelWidget24, (leString*)&string_HomeHelpText);
    root0->fn->addChild(root0, (leWidget*)ListWheelHelpScreen_LabelWidget24);

    ListWheelHelpScreen_ImageWidget16 = leImageWidget_New();
    ListWheelHelpScreen_ImageWidget16->fn->setPosition(ListWheelHelpScreen_ImageWidget16, 36, 73);
    ListWheelHelpScreen_ImageWidget16->fn->setSize(ListWheelHelpScreen_ImageWidget16, 20, 20);
    ListWheelHelpScreen_ImageWidget16->fn->setBackgroundType(ListWheelHelpScreen_ImageWidget16, LE_WIDGET_BACKGROUND_NONE);
    ListWheelHelpScreen_ImageWidget16->fn->setBorderType(ListWheelHelpScreen_ImageWidget16, LE_WIDGET_BORDER_NONE);
    ListWheelHelpScreen_ImageWidget16->fn->setImage(ListWheelHelpScreen_ImageWidget16, (leImage*)&GFX_Home_20x20);
    root0->fn->addChild(root0, (leWidget*)ListWheelHelpScreen_ImageWidget16);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    ListWheelHelpScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_ListWheelHelpScreen()
{
    ListWheelHelpScreen_OnUpdate(); // raise event
}

void screenHide_ListWheelHelpScreen()
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    ListWheelHelpScreen_PanelWidget4 = NULL;
    ListWheelHelpScreen_ImageWidget14 = NULL;
    ListWheelHelpScreen_LabelWidget21 = NULL;
    ListWheelHelpScreen_ListWheelHelpCloseButton = NULL;
    ListWheelHelpScreen_LabelWidget22 = NULL;
    ListWheelHelpScreen_LabelWidget24 = NULL;
    ListWheelHelpScreen_ImageWidget16 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_ListWheelHelpScreen()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
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

