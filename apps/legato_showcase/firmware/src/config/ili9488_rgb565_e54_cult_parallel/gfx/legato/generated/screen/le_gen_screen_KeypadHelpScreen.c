#include "gfx/legato/generated/screen/le_gen_screen_KeypadHelpScreen.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget6;
leImageWidget* ImageWidget20;
leButtonWidget* KeypadHelpCloseButton;
leLabelWidget* LabelWidget29;
leLabelWidget* LabelWidget30;
leLabelWidget* LabelWidget32;
leImageWidget* ImageWidget22;

// string list for this screen
static leTableString tableString_Help;
static leTableString tableString_TouchTextField;
static leTableString tableString_HomeHelpText;

static leBool showing = LE_FALSE;

leResult screenInit_KeypadHelpScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_KeypadHelpScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_Help, string_Help);
    leTableString_Constructor(&tableString_TouchTextField, string_TouchTextField);
    leTableString_Constructor(&tableString_HomeHelpText, string_HomeHelpText);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget6 = leWidget_New();
    PanelWidget6->fn->setPosition(PanelWidget6, 0, 0);
    PanelWidget6->fn->setSize(PanelWidget6, 480, 320);
    PanelWidget6->fn->setScheme(PanelWidget6, &whiteScheme);
    root0->fn->addChild(root0, PanelWidget6);

    ImageWidget20 = leImageWidget_New();
    ImageWidget20->fn->setPosition(ImageWidget20, 0, 0);
    ImageWidget20->fn->setSize(ImageWidget20, 40, 40);
    ImageWidget20->fn->setBackgroundType(ImageWidget20, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget20->fn->setImage(ImageWidget20, &GFX_Help_40x40);
    root0->fn->addChild(root0, (leWidget*)ImageWidget20);

    KeypadHelpCloseButton = leButtonWidget_New();
    KeypadHelpCloseButton->fn->setPosition(KeypadHelpCloseButton, 440, 0);
    KeypadHelpCloseButton->fn->setSize(KeypadHelpCloseButton, 40, 40);
    KeypadHelpCloseButton->fn->setBackgroundType(KeypadHelpCloseButton, LE_WIDGET_BACKGROUND_NONE);
    KeypadHelpCloseButton->fn->setPressedImage(KeypadHelpCloseButton, &GFX_CloseX_40x40);
    KeypadHelpCloseButton->fn->setReleasedImage(KeypadHelpCloseButton, &GFX_CloseX_40x40);
    KeypadHelpCloseButton->fn->setReleasedEventCallback(KeypadHelpCloseButton, KeypadHelpCloseButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)KeypadHelpCloseButton);

    LabelWidget29 = leLabelWidget_New();
    LabelWidget29->fn->setPosition(LabelWidget29, 48, 6);
    LabelWidget29->fn->setBackgroundType(LabelWidget29, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget29->fn->setString(LabelWidget29, (leString*)&tableString_Help);
    root0->fn->addChild(root0, (leWidget*)LabelWidget29);

    LabelWidget30 = leLabelWidget_New();
    LabelWidget30->fn->setPosition(LabelWidget30, 29, 47);
    LabelWidget30->fn->setSize(LabelWidget30, 299, 25);
    LabelWidget30->fn->setBackgroundType(LabelWidget30, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget30->fn->setString(LabelWidget30, (leString*)&tableString_TouchTextField);
    root0->fn->addChild(root0, (leWidget*)LabelWidget30);

    LabelWidget32 = leLabelWidget_New();
    LabelWidget32->fn->setPosition(LabelWidget32, 56, 71);
    LabelWidget32->fn->setSize(LabelWidget32, 300, 25);
    LabelWidget32->fn->setBackgroundType(LabelWidget32, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget32->fn->setString(LabelWidget32, (leString*)&tableString_HomeHelpText);
    root0->fn->addChild(root0, (leWidget*)LabelWidget32);

    ImageWidget22 = leImageWidget_New();
    ImageWidget22->fn->setPosition(ImageWidget22, 32, 75);
    ImageWidget22->fn->setSize(ImageWidget22, 20, 20);
    ImageWidget22->fn->setBackgroundType(ImageWidget22, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget22->fn->setImage(ImageWidget22, &GFX_Home_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget22);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    KeypadHelpScreen_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_KeypadHelpScreen()
{
    KeypadHelpScreen_OnUpdate();
}

void screenHide_KeypadHelpScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget6 = NULL;
    ImageWidget20 = NULL;
    KeypadHelpCloseButton = NULL;
    LabelWidget29 = NULL;
    LabelWidget30 = NULL;
    LabelWidget32 = NULL;
    ImageWidget22 = NULL;

    tableString_Help.fn->destructor(&tableString_Help);
    tableString_TouchTextField.fn->destructor(&tableString_TouchTextField);
    tableString_HomeHelpText.fn->destructor(&tableString_HomeHelpText);
    showing = LE_FALSE;
}

void screenDestroy_KeypadHelpScreen()
{

}

leWidget* screenGetRoot_KeypadHelpScreen(uint32_t lyrIdx)
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

