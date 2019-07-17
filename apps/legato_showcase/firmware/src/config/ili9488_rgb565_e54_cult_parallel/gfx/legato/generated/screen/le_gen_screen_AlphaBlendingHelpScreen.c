#include "gfx/legato/generated/screen/le_gen_screen_AlphaBlendingHelpScreen.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget7;
leButtonWidget* AlphaHelpCloseButton;
leImageWidget* ImageWidget23;
leLabelWidget* LabelWidget33;
leLabelWidget* LabelWidget34;
leLabelWidget* LabelWidget35;
leLabelWidget* LabelWidget23;
leImageWidget* ImageWidget15;

// string list for this screen
static leTableString tableString_Help;
static leTableString tableString_SliderDragHelpInfo;
static leTableString tableString_PlusMinusAlphaHelpInfo;
static leTableString tableString_HomeHelpText;

static leBool showing = LE_FALSE;

leResult screenInit_AlphaBlendingHelpScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_AlphaBlendingHelpScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_Help, string_Help);
    leTableString_Constructor(&tableString_SliderDragHelpInfo, string_SliderDragHelpInfo);
    leTableString_Constructor(&tableString_PlusMinusAlphaHelpInfo, string_PlusMinusAlphaHelpInfo);
    leTableString_Constructor(&tableString_HomeHelpText, string_HomeHelpText);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget7 = leWidget_New();
    PanelWidget7->fn->setPosition(PanelWidget7, 0, 0);
    PanelWidget7->fn->setSize(PanelWidget7, 480, 320);
    PanelWidget7->fn->setScheme(PanelWidget7, &whiteScheme);
    root0->fn->addChild(root0, PanelWidget7);

    AlphaHelpCloseButton = leButtonWidget_New();
    AlphaHelpCloseButton->fn->setPosition(AlphaHelpCloseButton, 440, 0);
    AlphaHelpCloseButton->fn->setSize(AlphaHelpCloseButton, 40, 40);
    AlphaHelpCloseButton->fn->setBackgroundType(AlphaHelpCloseButton, LE_WIDGET_BACKGROUND_NONE);
    AlphaHelpCloseButton->fn->setPressedImage(AlphaHelpCloseButton, &GFX_CloseX_40x40);
    AlphaHelpCloseButton->fn->setReleasedImage(AlphaHelpCloseButton, &GFX_CloseX_40x40);
    AlphaHelpCloseButton->fn->setReleasedEventCallback(AlphaHelpCloseButton, AlphaHelpCloseButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)AlphaHelpCloseButton);

    ImageWidget23 = leImageWidget_New();
    ImageWidget23->fn->setPosition(ImageWidget23, 0, 0);
    ImageWidget23->fn->setSize(ImageWidget23, 40, 40);
    ImageWidget23->fn->setBackgroundType(ImageWidget23, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget23->fn->setImage(ImageWidget23, &GFX_Help_40x40);
    root0->fn->addChild(root0, (leWidget*)ImageWidget23);

    LabelWidget33 = leLabelWidget_New();
    LabelWidget33->fn->setPosition(LabelWidget33, 48, 6);
    LabelWidget33->fn->setBackgroundType(LabelWidget33, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget33->fn->setString(LabelWidget33, (leString*)&tableString_Help);
    root0->fn->addChild(root0, (leWidget*)LabelWidget33);

    LabelWidget34 = leLabelWidget_New();
    LabelWidget34->fn->setPosition(LabelWidget34, 29, 47);
    LabelWidget34->fn->setSize(LabelWidget34, 427, 25);
    LabelWidget34->fn->setBackgroundType(LabelWidget34, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget34->fn->setString(LabelWidget34, (leString*)&tableString_SliderDragHelpInfo);
    root0->fn->addChild(root0, (leWidget*)LabelWidget34);

    LabelWidget35 = leLabelWidget_New();
    LabelWidget35->fn->setPosition(LabelWidget35, 29, 71);
    LabelWidget35->fn->setSize(LabelWidget35, 411, 25);
    LabelWidget35->fn->setBackgroundType(LabelWidget35, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget35->fn->setString(LabelWidget35, (leString*)&tableString_PlusMinusAlphaHelpInfo);
    root0->fn->addChild(root0, (leWidget*)LabelWidget35);

    LabelWidget23 = leLabelWidget_New();
    LabelWidget23->fn->setPosition(LabelWidget23, 70, 95);
    LabelWidget23->fn->setSize(LabelWidget23, 369, 25);
    LabelWidget23->fn->setBackgroundType(LabelWidget23, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget23->fn->setString(LabelWidget23, (leString*)&tableString_HomeHelpText);
    root0->fn->addChild(root0, (leWidget*)LabelWidget23);

    ImageWidget15 = leImageWidget_New();
    ImageWidget15->fn->setPosition(ImageWidget15, 32, 100);
    ImageWidget15->fn->setSize(ImageWidget15, 20, 20);
    ImageWidget15->fn->setBackgroundType(ImageWidget15, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget15->fn->setImage(ImageWidget15, &GFX_Home_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget15);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    AlphaBlendingHelpScreen_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_AlphaBlendingHelpScreen()
{
    AlphaBlendingHelpScreen_OnUpdate();
}

void screenHide_AlphaBlendingHelpScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget7 = NULL;
    AlphaHelpCloseButton = NULL;
    ImageWidget23 = NULL;
    LabelWidget33 = NULL;
    LabelWidget34 = NULL;
    LabelWidget35 = NULL;
    LabelWidget23 = NULL;
    ImageWidget15 = NULL;

    tableString_Help.fn->destructor(&tableString_Help);
    tableString_SliderDragHelpInfo.fn->destructor(&tableString_SliderDragHelpInfo);
    tableString_PlusMinusAlphaHelpInfo.fn->destructor(&tableString_PlusMinusAlphaHelpInfo);
    tableString_HomeHelpText.fn->destructor(&tableString_HomeHelpText);
    showing = LE_FALSE;
}

void screenDestroy_AlphaBlendingHelpScreen()
{

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

