#include "gfx/legato/generated/screen/le_gen_screen_TouchTestDemoScreen.h"

// screen member widget declarations
leWidget* root0;

leGradientWidget* TouchTestDemoScreen_GradientWidget2;
leTouchTestWidget* TouchTestDemoScreen_TouchTestWidget1;
leLabelWidget* TouchTestDemoScreen_LabelWidget6;
leImageWidget* TouchTestDemoScreen_ImageWidget5;
leButtonWidget* TouchTestDemoScreen_TouchTestHelpButton;
leButtonWidget* TouchTestDemoScreen_TouchTestHomeButton;
leLabelWidget* TouchTestDemoScreen_LabelWidget7;
leButtonWidget* TouchTestDemoScreen_TouchTestNextButton;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_TouchTestDemoScreen()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_TouchTestDemoScreen()
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

    TouchTestDemoScreen_GradientWidget2 = leGradientWidget_New();
    TouchTestDemoScreen_GradientWidget2->fn->setPosition(TouchTestDemoScreen_GradientWidget2, 0, 0);
    TouchTestDemoScreen_GradientWidget2->fn->setSize(TouchTestDemoScreen_GradientWidget2, 480, 320);
    TouchTestDemoScreen_GradientWidget2->fn->setScheme(TouchTestDemoScreen_GradientWidget2, &BackgroundGradientScheme);
    TouchTestDemoScreen_GradientWidget2->fn->setDirection(TouchTestDemoScreen_GradientWidget2, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)TouchTestDemoScreen_GradientWidget2);

    TouchTestDemoScreen_TouchTestWidget1 = leTouchTestWidget_New();
    TouchTestDemoScreen_TouchTestWidget1->fn->setPosition(TouchTestDemoScreen_TouchTestWidget1, 130, 42);
    TouchTestDemoScreen_TouchTestWidget1->fn->setSize(TouchTestDemoScreen_TouchTestWidget1, 297, 169);
    TouchTestDemoScreen_TouchTestWidget1->fn->setScheme(TouchTestDemoScreen_TouchTestWidget1, &TouchTestScheme);
    TouchTestDemoScreen_TouchTestWidget1->fn->setBorderType(TouchTestDemoScreen_TouchTestWidget1, LE_WIDGET_BORDER_NONE);
    root0->fn->addChild(root0, (leWidget*)TouchTestDemoScreen_TouchTestWidget1);

    TouchTestDemoScreen_LabelWidget6 = leLabelWidget_New();
    TouchTestDemoScreen_LabelWidget6->fn->setPosition(TouchTestDemoScreen_LabelWidget6, 125, 215);
    TouchTestDemoScreen_LabelWidget6->fn->setSize(TouchTestDemoScreen_LabelWidget6, 228, 25);
    TouchTestDemoScreen_LabelWidget6->fn->setScheme(TouchTestDemoScreen_LabelWidget6, &BlackBackground);
    TouchTestDemoScreen_LabelWidget6->fn->setBackgroundType(TouchTestDemoScreen_LabelWidget6, LE_WIDGET_BACKGROUND_NONE);
    TouchTestDemoScreen_LabelWidget6->fn->setString(TouchTestDemoScreen_LabelWidget6, (leString*)&string_TouchMe);
    root0->fn->addChild(root0, (leWidget*)TouchTestDemoScreen_LabelWidget6);

    TouchTestDemoScreen_ImageWidget5 = leImageWidget_New();
    TouchTestDemoScreen_ImageWidget5->fn->setPosition(TouchTestDemoScreen_ImageWidget5, 45, 151);
    TouchTestDemoScreen_ImageWidget5->fn->setSize(TouchTestDemoScreen_ImageWidget5, 81, 100);
    TouchTestDemoScreen_ImageWidget5->fn->setBackgroundType(TouchTestDemoScreen_ImageWidget5, LE_WIDGET_BACKGROUND_NONE);
    TouchTestDemoScreen_ImageWidget5->fn->setBorderType(TouchTestDemoScreen_ImageWidget5, LE_WIDGET_BORDER_NONE);
    TouchTestDemoScreen_ImageWidget5->fn->setImage(TouchTestDemoScreen_ImageWidget5, (leImage*)&GFX_Touch_80);
    root0->fn->addChild(root0, (leWidget*)TouchTestDemoScreen_ImageWidget5);

    TouchTestDemoScreen_TouchTestHelpButton = leButtonWidget_New();
    TouchTestDemoScreen_TouchTestHelpButton->fn->setPosition(TouchTestDemoScreen_TouchTestHelpButton, 0, 260);
    TouchTestDemoScreen_TouchTestHelpButton->fn->setSize(TouchTestDemoScreen_TouchTestHelpButton, 60, 60);
    TouchTestDemoScreen_TouchTestHelpButton->fn->setAlphaAmount(TouchTestDemoScreen_TouchTestHelpButton, 220);
    TouchTestDemoScreen_TouchTestHelpButton->fn->setBackgroundType(TouchTestDemoScreen_TouchTestHelpButton, LE_WIDGET_BACKGROUND_NONE);
    TouchTestDemoScreen_TouchTestHelpButton->fn->setBorderType(TouchTestDemoScreen_TouchTestHelpButton, LE_WIDGET_BORDER_NONE);
    TouchTestDemoScreen_TouchTestHelpButton->fn->setPressedImage(TouchTestDemoScreen_TouchTestHelpButton, (leImage*)&GFX_Help_60);
    TouchTestDemoScreen_TouchTestHelpButton->fn->setReleasedImage(TouchTestDemoScreen_TouchTestHelpButton, (leImage*)&GFX_Help_60);
    TouchTestDemoScreen_TouchTestHelpButton->fn->setReleasedEventCallback(TouchTestDemoScreen_TouchTestHelpButton, event_TouchTestDemoScreen_TouchTestHelpButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)TouchTestDemoScreen_TouchTestHelpButton);

    TouchTestDemoScreen_TouchTestHomeButton = leButtonWidget_New();
    TouchTestDemoScreen_TouchTestHomeButton->fn->setPosition(TouchTestDemoScreen_TouchTestHomeButton, 421, 260);
    TouchTestDemoScreen_TouchTestHomeButton->fn->setSize(TouchTestDemoScreen_TouchTestHomeButton, 60, 60);
    TouchTestDemoScreen_TouchTestHomeButton->fn->setAlphaAmount(TouchTestDemoScreen_TouchTestHomeButton, 220);
    TouchTestDemoScreen_TouchTestHomeButton->fn->setBackgroundType(TouchTestDemoScreen_TouchTestHomeButton, LE_WIDGET_BACKGROUND_NONE);
    TouchTestDemoScreen_TouchTestHomeButton->fn->setBorderType(TouchTestDemoScreen_TouchTestHomeButton, LE_WIDGET_BORDER_NONE);
    TouchTestDemoScreen_TouchTestHomeButton->fn->setPressedImage(TouchTestDemoScreen_TouchTestHomeButton, (leImage*)&GFX_Home_60x60);
    TouchTestDemoScreen_TouchTestHomeButton->fn->setReleasedImage(TouchTestDemoScreen_TouchTestHomeButton, (leImage*)&GFX_Home_60x60);
    TouchTestDemoScreen_TouchTestHomeButton->fn->setReleasedEventCallback(TouchTestDemoScreen_TouchTestHomeButton, event_TouchTestDemoScreen_TouchTestHomeButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)TouchTestDemoScreen_TouchTestHomeButton);

    TouchTestDemoScreen_LabelWidget7 = leLabelWidget_New();
    TouchTestDemoScreen_LabelWidget7->fn->setPosition(TouchTestDemoScreen_LabelWidget7, 10, 5);
    TouchTestDemoScreen_LabelWidget7->fn->setSize(TouchTestDemoScreen_LabelWidget7, 293, 25);
    TouchTestDemoScreen_LabelWidget7->fn->setScheme(TouchTestDemoScreen_LabelWidget7, &whiteScheme);
    TouchTestDemoScreen_LabelWidget7->fn->setBackgroundType(TouchTestDemoScreen_LabelWidget7, LE_WIDGET_BACKGROUND_NONE);
    TouchTestDemoScreen_LabelWidget7->fn->setString(TouchTestDemoScreen_LabelWidget7, (leString*)&string_TouchTestWidgetDemo);
    root0->fn->addChild(root0, (leWidget*)TouchTestDemoScreen_LabelWidget7);

    TouchTestDemoScreen_TouchTestNextButton = leButtonWidget_New();
    TouchTestDemoScreen_TouchTestNextButton->fn->setPosition(TouchTestDemoScreen_TouchTestNextButton, 360, 260);
    TouchTestDemoScreen_TouchTestNextButton->fn->setSize(TouchTestDemoScreen_TouchTestNextButton, 60, 60);
    TouchTestDemoScreen_TouchTestNextButton->fn->setBackgroundType(TouchTestDemoScreen_TouchTestNextButton, LE_WIDGET_BACKGROUND_NONE);
    TouchTestDemoScreen_TouchTestNextButton->fn->setBorderType(TouchTestDemoScreen_TouchTestNextButton, LE_WIDGET_BORDER_NONE);
    TouchTestDemoScreen_TouchTestNextButton->fn->setPressedImage(TouchTestDemoScreen_TouchTestNextButton, (leImage*)&GFX_NextScreen_60x60);
    TouchTestDemoScreen_TouchTestNextButton->fn->setReleasedImage(TouchTestDemoScreen_TouchTestNextButton, (leImage*)&GFX_NextScreen_60x60);
    TouchTestDemoScreen_TouchTestNextButton->fn->setReleasedEventCallback(TouchTestDemoScreen_TouchTestNextButton, event_TouchTestDemoScreen_TouchTestNextButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)TouchTestDemoScreen_TouchTestNextButton);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    TouchTestDemoScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_TouchTestDemoScreen()
{
    TouchTestDemoScreen_OnUpdate(); // raise event
}

void screenHide_TouchTestDemoScreen()
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    TouchTestDemoScreen_GradientWidget2 = NULL;
    TouchTestDemoScreen_TouchTestWidget1 = NULL;
    TouchTestDemoScreen_LabelWidget6 = NULL;
    TouchTestDemoScreen_ImageWidget5 = NULL;
    TouchTestDemoScreen_TouchTestHelpButton = NULL;
    TouchTestDemoScreen_TouchTestHomeButton = NULL;
    TouchTestDemoScreen_LabelWidget7 = NULL;
    TouchTestDemoScreen_TouchTestNextButton = NULL;


    showing = LE_FALSE;
}

void screenDestroy_TouchTestDemoScreen()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_TouchTestDemoScreen(uint32_t lyrIdx)
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

