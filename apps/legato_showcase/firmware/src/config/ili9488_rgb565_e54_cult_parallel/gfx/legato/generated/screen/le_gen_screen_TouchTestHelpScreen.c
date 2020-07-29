#include "gfx/legato/generated/screen/le_gen_screen_TouchTestHelpScreen.h"

// screen member widget declarations
leWidget* root0;

leWidget* TouchTestHelpScreen_PanelWidget5;
leImageWidget* TouchTestHelpScreen_ImageWidget17;
leButtonWidget* TouchTestHelpScreen_TouchTestHelpCloseButton;
leLabelWidget* TouchTestHelpScreen_LabelWidget25;
leLabelWidget* TouchTestHelpScreen_LabelWidget26;
leLabelWidget* TouchTestHelpScreen_LabelWidget28;
leImageWidget* TouchTestHelpScreen_ImageWidget19;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_TouchTestHelpScreen()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_TouchTestHelpScreen()
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

    TouchTestHelpScreen_PanelWidget5 = leWidget_New();
    TouchTestHelpScreen_PanelWidget5->fn->setPosition(TouchTestHelpScreen_PanelWidget5, 0, 0);
    TouchTestHelpScreen_PanelWidget5->fn->setSize(TouchTestHelpScreen_PanelWidget5, 480, 320);
    TouchTestHelpScreen_PanelWidget5->fn->setScheme(TouchTestHelpScreen_PanelWidget5, &whiteScheme);
    root0->fn->addChild(root0, (leWidget*)TouchTestHelpScreen_PanelWidget5);

    TouchTestHelpScreen_ImageWidget17 = leImageWidget_New();
    TouchTestHelpScreen_ImageWidget17->fn->setPosition(TouchTestHelpScreen_ImageWidget17, 0, 0);
    TouchTestHelpScreen_ImageWidget17->fn->setSize(TouchTestHelpScreen_ImageWidget17, 40, 40);
    TouchTestHelpScreen_ImageWidget17->fn->setBackgroundType(TouchTestHelpScreen_ImageWidget17, LE_WIDGET_BACKGROUND_NONE);
    TouchTestHelpScreen_ImageWidget17->fn->setBorderType(TouchTestHelpScreen_ImageWidget17, LE_WIDGET_BORDER_NONE);
    TouchTestHelpScreen_ImageWidget17->fn->setImage(TouchTestHelpScreen_ImageWidget17, (leImage*)&GFX_Help_40x40);
    root0->fn->addChild(root0, (leWidget*)TouchTestHelpScreen_ImageWidget17);

    TouchTestHelpScreen_TouchTestHelpCloseButton = leButtonWidget_New();
    TouchTestHelpScreen_TouchTestHelpCloseButton->fn->setPosition(TouchTestHelpScreen_TouchTestHelpCloseButton, 440, 0);
    TouchTestHelpScreen_TouchTestHelpCloseButton->fn->setSize(TouchTestHelpScreen_TouchTestHelpCloseButton, 40, 40);
    TouchTestHelpScreen_TouchTestHelpCloseButton->fn->setBackgroundType(TouchTestHelpScreen_TouchTestHelpCloseButton, LE_WIDGET_BACKGROUND_NONE);
    TouchTestHelpScreen_TouchTestHelpCloseButton->fn->setPressedImage(TouchTestHelpScreen_TouchTestHelpCloseButton, (leImage*)&GFX_CloseX_40x40);
    TouchTestHelpScreen_TouchTestHelpCloseButton->fn->setReleasedImage(TouchTestHelpScreen_TouchTestHelpCloseButton, (leImage*)&GFX_CloseX_40x40);
    TouchTestHelpScreen_TouchTestHelpCloseButton->fn->setReleasedEventCallback(TouchTestHelpScreen_TouchTestHelpCloseButton, event_TouchTestHelpScreen_TouchTestHelpCloseButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)TouchTestHelpScreen_TouchTestHelpCloseButton);

    TouchTestHelpScreen_LabelWidget25 = leLabelWidget_New();
    TouchTestHelpScreen_LabelWidget25->fn->setPosition(TouchTestHelpScreen_LabelWidget25, 48, 6);
    TouchTestHelpScreen_LabelWidget25->fn->setBackgroundType(TouchTestHelpScreen_LabelWidget25, LE_WIDGET_BACKGROUND_NONE);
    TouchTestHelpScreen_LabelWidget25->fn->setString(TouchTestHelpScreen_LabelWidget25, (leString*)&string_Help);
    root0->fn->addChild(root0, (leWidget*)TouchTestHelpScreen_LabelWidget25);

    TouchTestHelpScreen_LabelWidget26 = leLabelWidget_New();
    TouchTestHelpScreen_LabelWidget26->fn->setPosition(TouchTestHelpScreen_LabelWidget26, 29, 47);
    TouchTestHelpScreen_LabelWidget26->fn->setSize(TouchTestHelpScreen_LabelWidget26, 387, 25);
    TouchTestHelpScreen_LabelWidget26->fn->setBackgroundType(TouchTestHelpScreen_LabelWidget26, LE_WIDGET_BACKGROUND_NONE);
    TouchTestHelpScreen_LabelWidget26->fn->setString(TouchTestHelpScreen_LabelWidget26, (leString*)&string_TouchTestHelpInfo);
    root0->fn->addChild(root0, (leWidget*)TouchTestHelpScreen_LabelWidget26);

    TouchTestHelpScreen_LabelWidget28 = leLabelWidget_New();
    TouchTestHelpScreen_LabelWidget28->fn->setPosition(TouchTestHelpScreen_LabelWidget28, 59, 71);
    TouchTestHelpScreen_LabelWidget28->fn->setSize(TouchTestHelpScreen_LabelWidget28, 317, 25);
    TouchTestHelpScreen_LabelWidget28->fn->setBackgroundType(TouchTestHelpScreen_LabelWidget28, LE_WIDGET_BACKGROUND_NONE);
    TouchTestHelpScreen_LabelWidget28->fn->setString(TouchTestHelpScreen_LabelWidget28, (leString*)&string_HomeHelpText);
    root0->fn->addChild(root0, (leWidget*)TouchTestHelpScreen_LabelWidget28);

    TouchTestHelpScreen_ImageWidget19 = leImageWidget_New();
    TouchTestHelpScreen_ImageWidget19->fn->setPosition(TouchTestHelpScreen_ImageWidget19, 32, 75);
    TouchTestHelpScreen_ImageWidget19->fn->setSize(TouchTestHelpScreen_ImageWidget19, 20, 20);
    TouchTestHelpScreen_ImageWidget19->fn->setBackgroundType(TouchTestHelpScreen_ImageWidget19, LE_WIDGET_BACKGROUND_NONE);
    TouchTestHelpScreen_ImageWidget19->fn->setBorderType(TouchTestHelpScreen_ImageWidget19, LE_WIDGET_BORDER_NONE);
    TouchTestHelpScreen_ImageWidget19->fn->setImage(TouchTestHelpScreen_ImageWidget19, (leImage*)&GFX_Home_20x20);
    root0->fn->addChild(root0, (leWidget*)TouchTestHelpScreen_ImageWidget19);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    TouchTestHelpScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_TouchTestHelpScreen()
{
    TouchTestHelpScreen_OnUpdate(); // raise event
}

void screenHide_TouchTestHelpScreen()
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    TouchTestHelpScreen_PanelWidget5 = NULL;
    TouchTestHelpScreen_ImageWidget17 = NULL;
    TouchTestHelpScreen_TouchTestHelpCloseButton = NULL;
    TouchTestHelpScreen_LabelWidget25 = NULL;
    TouchTestHelpScreen_LabelWidget26 = NULL;
    TouchTestHelpScreen_LabelWidget28 = NULL;
    TouchTestHelpScreen_ImageWidget19 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_TouchTestHelpScreen()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
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

