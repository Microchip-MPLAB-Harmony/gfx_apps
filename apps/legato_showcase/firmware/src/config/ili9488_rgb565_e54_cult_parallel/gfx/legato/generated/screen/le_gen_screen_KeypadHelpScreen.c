#include "gfx/legato/generated/screen/le_gen_screen_KeypadHelpScreen.h"

// screen member widget declarations
leWidget* root0;

leWidget* KeypadHelpScreen_PanelWidget6;
leImageWidget* KeypadHelpScreen_ImageWidget20;
leButtonWidget* KeypadHelpScreen_KeypadHelpCloseButton;
leLabelWidget* KeypadHelpScreen_LabelWidget29;
leLabelWidget* KeypadHelpScreen_LabelWidget30;
leLabelWidget* KeypadHelpScreen_LabelWidget32;
leImageWidget* KeypadHelpScreen_ImageWidget22;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_KeypadHelpScreen()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_KeypadHelpScreen()
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

    KeypadHelpScreen_PanelWidget6 = leWidget_New();
    KeypadHelpScreen_PanelWidget6->fn->setPosition(KeypadHelpScreen_PanelWidget6, 0, 0);
    KeypadHelpScreen_PanelWidget6->fn->setSize(KeypadHelpScreen_PanelWidget6, 480, 320);
    KeypadHelpScreen_PanelWidget6->fn->setScheme(KeypadHelpScreen_PanelWidget6, &whiteScheme);
    root0->fn->addChild(root0, (leWidget*)KeypadHelpScreen_PanelWidget6);

    KeypadHelpScreen_ImageWidget20 = leImageWidget_New();
    KeypadHelpScreen_ImageWidget20->fn->setPosition(KeypadHelpScreen_ImageWidget20, 0, 0);
    KeypadHelpScreen_ImageWidget20->fn->setSize(KeypadHelpScreen_ImageWidget20, 40, 40);
    KeypadHelpScreen_ImageWidget20->fn->setBackgroundType(KeypadHelpScreen_ImageWidget20, LE_WIDGET_BACKGROUND_NONE);
    KeypadHelpScreen_ImageWidget20->fn->setBorderType(KeypadHelpScreen_ImageWidget20, LE_WIDGET_BORDER_NONE);
    KeypadHelpScreen_ImageWidget20->fn->setImage(KeypadHelpScreen_ImageWidget20, (leImage*)&GFX_Help_40x40);
    root0->fn->addChild(root0, (leWidget*)KeypadHelpScreen_ImageWidget20);

    KeypadHelpScreen_KeypadHelpCloseButton = leButtonWidget_New();
    KeypadHelpScreen_KeypadHelpCloseButton->fn->setPosition(KeypadHelpScreen_KeypadHelpCloseButton, 440, 0);
    KeypadHelpScreen_KeypadHelpCloseButton->fn->setSize(KeypadHelpScreen_KeypadHelpCloseButton, 40, 40);
    KeypadHelpScreen_KeypadHelpCloseButton->fn->setBackgroundType(KeypadHelpScreen_KeypadHelpCloseButton, LE_WIDGET_BACKGROUND_NONE);
    KeypadHelpScreen_KeypadHelpCloseButton->fn->setPressedImage(KeypadHelpScreen_KeypadHelpCloseButton, (leImage*)&GFX_CloseX_40x40);
    KeypadHelpScreen_KeypadHelpCloseButton->fn->setReleasedImage(KeypadHelpScreen_KeypadHelpCloseButton, (leImage*)&GFX_CloseX_40x40);
    KeypadHelpScreen_KeypadHelpCloseButton->fn->setReleasedEventCallback(KeypadHelpScreen_KeypadHelpCloseButton, event_KeypadHelpScreen_KeypadHelpCloseButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)KeypadHelpScreen_KeypadHelpCloseButton);

    KeypadHelpScreen_LabelWidget29 = leLabelWidget_New();
    KeypadHelpScreen_LabelWidget29->fn->setPosition(KeypadHelpScreen_LabelWidget29, 48, 6);
    KeypadHelpScreen_LabelWidget29->fn->setBackgroundType(KeypadHelpScreen_LabelWidget29, LE_WIDGET_BACKGROUND_NONE);
    KeypadHelpScreen_LabelWidget29->fn->setString(KeypadHelpScreen_LabelWidget29, (leString*)&string_Help);
    root0->fn->addChild(root0, (leWidget*)KeypadHelpScreen_LabelWidget29);

    KeypadHelpScreen_LabelWidget30 = leLabelWidget_New();
    KeypadHelpScreen_LabelWidget30->fn->setPosition(KeypadHelpScreen_LabelWidget30, 29, 47);
    KeypadHelpScreen_LabelWidget30->fn->setSize(KeypadHelpScreen_LabelWidget30, 385, 25);
    KeypadHelpScreen_LabelWidget30->fn->setBackgroundType(KeypadHelpScreen_LabelWidget30, LE_WIDGET_BACKGROUND_NONE);
    KeypadHelpScreen_LabelWidget30->fn->setString(KeypadHelpScreen_LabelWidget30, (leString*)&string_TouchTextField);
    root0->fn->addChild(root0, (leWidget*)KeypadHelpScreen_LabelWidget30);

    KeypadHelpScreen_LabelWidget32 = leLabelWidget_New();
    KeypadHelpScreen_LabelWidget32->fn->setPosition(KeypadHelpScreen_LabelWidget32, 56, 71);
    KeypadHelpScreen_LabelWidget32->fn->setSize(KeypadHelpScreen_LabelWidget32, 300, 25);
    KeypadHelpScreen_LabelWidget32->fn->setBackgroundType(KeypadHelpScreen_LabelWidget32, LE_WIDGET_BACKGROUND_NONE);
    KeypadHelpScreen_LabelWidget32->fn->setString(KeypadHelpScreen_LabelWidget32, (leString*)&string_HomeHelpText);
    root0->fn->addChild(root0, (leWidget*)KeypadHelpScreen_LabelWidget32);

    KeypadHelpScreen_ImageWidget22 = leImageWidget_New();
    KeypadHelpScreen_ImageWidget22->fn->setPosition(KeypadHelpScreen_ImageWidget22, 32, 75);
    KeypadHelpScreen_ImageWidget22->fn->setSize(KeypadHelpScreen_ImageWidget22, 20, 20);
    KeypadHelpScreen_ImageWidget22->fn->setBackgroundType(KeypadHelpScreen_ImageWidget22, LE_WIDGET_BACKGROUND_NONE);
    KeypadHelpScreen_ImageWidget22->fn->setBorderType(KeypadHelpScreen_ImageWidget22, LE_WIDGET_BORDER_NONE);
    KeypadHelpScreen_ImageWidget22->fn->setImage(KeypadHelpScreen_ImageWidget22, (leImage*)&GFX_Home_20x20);
    root0->fn->addChild(root0, (leWidget*)KeypadHelpScreen_ImageWidget22);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    KeypadHelpScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_KeypadHelpScreen()
{
    KeypadHelpScreen_OnUpdate(); // raise event
}

void screenHide_KeypadHelpScreen()
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    KeypadHelpScreen_PanelWidget6 = NULL;
    KeypadHelpScreen_ImageWidget20 = NULL;
    KeypadHelpScreen_KeypadHelpCloseButton = NULL;
    KeypadHelpScreen_LabelWidget29 = NULL;
    KeypadHelpScreen_LabelWidget30 = NULL;
    KeypadHelpScreen_LabelWidget32 = NULL;
    KeypadHelpScreen_ImageWidget22 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_KeypadHelpScreen()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
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

