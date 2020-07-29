#include "gfx/legato/generated/screen/le_gen_screen_AlphaBlendingHelpScreen.h"

// screen member widget declarations
leWidget* root0;

leWidget* AlphaBlendingHelpScreen_PanelWidget7;
leButtonWidget* AlphaBlendingHelpScreen_AlphaHelpCloseButton;
leImageWidget* AlphaBlendingHelpScreen_ImageWidget23;
leLabelWidget* AlphaBlendingHelpScreen_LabelWidget33;
leLabelWidget* AlphaBlendingHelpScreen_LabelWidget34;
leLabelWidget* AlphaBlendingHelpScreen_LabelWidget35;
leLabelWidget* AlphaBlendingHelpScreen_LabelWidget23;
leImageWidget* AlphaBlendingHelpScreen_ImageWidget15;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_AlphaBlendingHelpScreen()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_AlphaBlendingHelpScreen()
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

    AlphaBlendingHelpScreen_PanelWidget7 = leWidget_New();
    AlphaBlendingHelpScreen_PanelWidget7->fn->setPosition(AlphaBlendingHelpScreen_PanelWidget7, 0, 0);
    AlphaBlendingHelpScreen_PanelWidget7->fn->setSize(AlphaBlendingHelpScreen_PanelWidget7, 480, 320);
    AlphaBlendingHelpScreen_PanelWidget7->fn->setScheme(AlphaBlendingHelpScreen_PanelWidget7, &whiteScheme);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingHelpScreen_PanelWidget7);

    AlphaBlendingHelpScreen_AlphaHelpCloseButton = leButtonWidget_New();
    AlphaBlendingHelpScreen_AlphaHelpCloseButton->fn->setPosition(AlphaBlendingHelpScreen_AlphaHelpCloseButton, 440, 0);
    AlphaBlendingHelpScreen_AlphaHelpCloseButton->fn->setSize(AlphaBlendingHelpScreen_AlphaHelpCloseButton, 40, 40);
    AlphaBlendingHelpScreen_AlphaHelpCloseButton->fn->setBackgroundType(AlphaBlendingHelpScreen_AlphaHelpCloseButton, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingHelpScreen_AlphaHelpCloseButton->fn->setPressedImage(AlphaBlendingHelpScreen_AlphaHelpCloseButton, (leImage*)&GFX_CloseX_40x40);
    AlphaBlendingHelpScreen_AlphaHelpCloseButton->fn->setReleasedImage(AlphaBlendingHelpScreen_AlphaHelpCloseButton, (leImage*)&GFX_CloseX_40x40);
    AlphaBlendingHelpScreen_AlphaHelpCloseButton->fn->setReleasedEventCallback(AlphaBlendingHelpScreen_AlphaHelpCloseButton, event_AlphaBlendingHelpScreen_AlphaHelpCloseButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingHelpScreen_AlphaHelpCloseButton);

    AlphaBlendingHelpScreen_ImageWidget23 = leImageWidget_New();
    AlphaBlendingHelpScreen_ImageWidget23->fn->setPosition(AlphaBlendingHelpScreen_ImageWidget23, 0, 0);
    AlphaBlendingHelpScreen_ImageWidget23->fn->setSize(AlphaBlendingHelpScreen_ImageWidget23, 40, 40);
    AlphaBlendingHelpScreen_ImageWidget23->fn->setBackgroundType(AlphaBlendingHelpScreen_ImageWidget23, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingHelpScreen_ImageWidget23->fn->setBorderType(AlphaBlendingHelpScreen_ImageWidget23, LE_WIDGET_BORDER_NONE);
    AlphaBlendingHelpScreen_ImageWidget23->fn->setImage(AlphaBlendingHelpScreen_ImageWidget23, (leImage*)&GFX_Help_40x40);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingHelpScreen_ImageWidget23);

    AlphaBlendingHelpScreen_LabelWidget33 = leLabelWidget_New();
    AlphaBlendingHelpScreen_LabelWidget33->fn->setPosition(AlphaBlendingHelpScreen_LabelWidget33, 48, 6);
    AlphaBlendingHelpScreen_LabelWidget33->fn->setBackgroundType(AlphaBlendingHelpScreen_LabelWidget33, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingHelpScreen_LabelWidget33->fn->setString(AlphaBlendingHelpScreen_LabelWidget33, (leString*)&string_Help);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingHelpScreen_LabelWidget33);

    AlphaBlendingHelpScreen_LabelWidget34 = leLabelWidget_New();
    AlphaBlendingHelpScreen_LabelWidget34->fn->setPosition(AlphaBlendingHelpScreen_LabelWidget34, 29, 47);
    AlphaBlendingHelpScreen_LabelWidget34->fn->setSize(AlphaBlendingHelpScreen_LabelWidget34, 378, 25);
    AlphaBlendingHelpScreen_LabelWidget34->fn->setBackgroundType(AlphaBlendingHelpScreen_LabelWidget34, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingHelpScreen_LabelWidget34->fn->setString(AlphaBlendingHelpScreen_LabelWidget34, (leString*)&string_SliderDragHelpInfo);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingHelpScreen_LabelWidget34);

    AlphaBlendingHelpScreen_LabelWidget35 = leLabelWidget_New();
    AlphaBlendingHelpScreen_LabelWidget35->fn->setPosition(AlphaBlendingHelpScreen_LabelWidget35, 29, 71);
    AlphaBlendingHelpScreen_LabelWidget35->fn->setSize(AlphaBlendingHelpScreen_LabelWidget35, 385, 25);
    AlphaBlendingHelpScreen_LabelWidget35->fn->setBackgroundType(AlphaBlendingHelpScreen_LabelWidget35, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingHelpScreen_LabelWidget35->fn->setString(AlphaBlendingHelpScreen_LabelWidget35, (leString*)&string_PlusMinusAlphaHelpInfo);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingHelpScreen_LabelWidget35);

    AlphaBlendingHelpScreen_LabelWidget23 = leLabelWidget_New();
    AlphaBlendingHelpScreen_LabelWidget23->fn->setPosition(AlphaBlendingHelpScreen_LabelWidget23, 70, 95);
    AlphaBlendingHelpScreen_LabelWidget23->fn->setSize(AlphaBlendingHelpScreen_LabelWidget23, 369, 25);
    AlphaBlendingHelpScreen_LabelWidget23->fn->setBackgroundType(AlphaBlendingHelpScreen_LabelWidget23, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingHelpScreen_LabelWidget23->fn->setString(AlphaBlendingHelpScreen_LabelWidget23, (leString*)&string_HomeHelpText);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingHelpScreen_LabelWidget23);

    AlphaBlendingHelpScreen_ImageWidget15 = leImageWidget_New();
    AlphaBlendingHelpScreen_ImageWidget15->fn->setPosition(AlphaBlendingHelpScreen_ImageWidget15, 32, 100);
    AlphaBlendingHelpScreen_ImageWidget15->fn->setSize(AlphaBlendingHelpScreen_ImageWidget15, 20, 20);
    AlphaBlendingHelpScreen_ImageWidget15->fn->setBackgroundType(AlphaBlendingHelpScreen_ImageWidget15, LE_WIDGET_BACKGROUND_NONE);
    AlphaBlendingHelpScreen_ImageWidget15->fn->setBorderType(AlphaBlendingHelpScreen_ImageWidget15, LE_WIDGET_BORDER_NONE);
    AlphaBlendingHelpScreen_ImageWidget15->fn->setImage(AlphaBlendingHelpScreen_ImageWidget15, (leImage*)&GFX_Home_20x20);
    root0->fn->addChild(root0, (leWidget*)AlphaBlendingHelpScreen_ImageWidget15);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    AlphaBlendingHelpScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_AlphaBlendingHelpScreen()
{
    AlphaBlendingHelpScreen_OnUpdate(); // raise event
}

void screenHide_AlphaBlendingHelpScreen()
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    AlphaBlendingHelpScreen_PanelWidget7 = NULL;
    AlphaBlendingHelpScreen_AlphaHelpCloseButton = NULL;
    AlphaBlendingHelpScreen_ImageWidget23 = NULL;
    AlphaBlendingHelpScreen_LabelWidget33 = NULL;
    AlphaBlendingHelpScreen_LabelWidget34 = NULL;
    AlphaBlendingHelpScreen_LabelWidget35 = NULL;
    AlphaBlendingHelpScreen_LabelWidget23 = NULL;
    AlphaBlendingHelpScreen_ImageWidget15 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_AlphaBlendingHelpScreen()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_AlphaBlendingHelpScreen(uint32_t lyrIdx)
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

