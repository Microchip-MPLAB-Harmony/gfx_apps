#include "gfx/legato/generated/screen/le_gen_screen_TouchTestDemoScreen.h"

// widget list for layer 0
static leWidget* root0;

leGradientWidget* GradientWidget2;
leTouchTestWidget* TouchTestWidget1;
leLabelWidget* LabelWidget6;
leImageWidget* ImageWidget5;
leButtonWidget* TouchTestHelpButton;
leButtonWidget* TouchTestHomeButton;
leLabelWidget* LabelWidget7;
leButtonWidget* TouchTestNextButton;

// string list for this screen
static leTableString tableString_TouchMe;
static leTableString tableString_TouchTestWidgetDemo;

static leBool showing = LE_FALSE;

leResult screenInit_TouchTestDemoScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_TouchTestDemoScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_TouchMe, string_TouchMe);
    leTableString_Constructor(&tableString_TouchTestWidgetDemo, string_TouchTestWidgetDemo);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    GradientWidget2 = leGradientWidget_New();
    GradientWidget2->fn->setPosition(GradientWidget2, 0, 0);
    GradientWidget2->fn->setSize(GradientWidget2, 480, 320);
    GradientWidget2->fn->setScheme(GradientWidget2, &BackgroundGradientScheme);
    GradientWidget2->fn->setDirection(GradientWidget2, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)GradientWidget2);

    TouchTestWidget1 = leTouchTestWidget_New();
    TouchTestWidget1->fn->setPosition(TouchTestWidget1, 130, 42);
    TouchTestWidget1->fn->setSize(TouchTestWidget1, 297, 169);
    TouchTestWidget1->fn->setScheme(TouchTestWidget1, &TouchTestScheme);
    root0->fn->addChild(root0, (leWidget*)TouchTestWidget1);

    LabelWidget6 = leLabelWidget_New();
    LabelWidget6->fn->setPosition(LabelWidget6, 125, 215);
    LabelWidget6->fn->setSize(LabelWidget6, 228, 25);
    LabelWidget6->fn->setScheme(LabelWidget6, &BlackBackground);
    LabelWidget6->fn->setBackgroundType(LabelWidget6, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget6->fn->setString(LabelWidget6, (leString*)&tableString_TouchMe);
    root0->fn->addChild(root0, (leWidget*)LabelWidget6);

    ImageWidget5 = leImageWidget_New();
    ImageWidget5->fn->setPosition(ImageWidget5, 45, 151);
    ImageWidget5->fn->setSize(ImageWidget5, 81, 100);
    ImageWidget5->fn->setBackgroundType(ImageWidget5, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget5->fn->setImage(ImageWidget5, &GFX_Touch_80);
    root0->fn->addChild(root0, (leWidget*)ImageWidget5);

    TouchTestHelpButton = leButtonWidget_New();
    TouchTestHelpButton->fn->setPosition(TouchTestHelpButton, 0, 260);
    TouchTestHelpButton->fn->setSize(TouchTestHelpButton, 60, 60);
    TouchTestHelpButton->fn->setAlphaAmount(TouchTestHelpButton, 220);
    TouchTestHelpButton->fn->setBackgroundType(TouchTestHelpButton, LE_WIDGET_BACKGROUND_NONE);
    TouchTestHelpButton->fn->setBorderType(TouchTestHelpButton, LE_WIDGET_BORDER_NONE);
    TouchTestHelpButton->fn->setPressedImage(TouchTestHelpButton, &GFX_Help_60);
    TouchTestHelpButton->fn->setReleasedImage(TouchTestHelpButton, &GFX_Help_60);
    TouchTestHelpButton->fn->setReleasedEventCallback(TouchTestHelpButton, TouchTestHelpButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)TouchTestHelpButton);

    TouchTestHomeButton = leButtonWidget_New();
    TouchTestHomeButton->fn->setPosition(TouchTestHomeButton, 421, 260);
    TouchTestHomeButton->fn->setSize(TouchTestHomeButton, 60, 60);
    TouchTestHomeButton->fn->setAlphaAmount(TouchTestHomeButton, 220);
    TouchTestHomeButton->fn->setBackgroundType(TouchTestHomeButton, LE_WIDGET_BACKGROUND_NONE);
    TouchTestHomeButton->fn->setBorderType(TouchTestHomeButton, LE_WIDGET_BORDER_NONE);
    TouchTestHomeButton->fn->setPressedImage(TouchTestHomeButton, &GFX_Home_60x60);
    TouchTestHomeButton->fn->setReleasedImage(TouchTestHomeButton, &GFX_Home_60x60);
    TouchTestHomeButton->fn->setReleasedEventCallback(TouchTestHomeButton, TouchTestHomeButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)TouchTestHomeButton);

    LabelWidget7 = leLabelWidget_New();
    LabelWidget7->fn->setPosition(LabelWidget7, 10, 5);
    LabelWidget7->fn->setSize(LabelWidget7, 293, 25);
    LabelWidget7->fn->setScheme(LabelWidget7, &whiteScheme);
    LabelWidget7->fn->setBackgroundType(LabelWidget7, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget7->fn->setString(LabelWidget7, (leString*)&tableString_TouchTestWidgetDemo);
    root0->fn->addChild(root0, (leWidget*)LabelWidget7);

    TouchTestNextButton = leButtonWidget_New();
    TouchTestNextButton->fn->setPosition(TouchTestNextButton, 360, 260);
    TouchTestNextButton->fn->setSize(TouchTestNextButton, 60, 60);
    TouchTestNextButton->fn->setBackgroundType(TouchTestNextButton, LE_WIDGET_BACKGROUND_NONE);
    TouchTestNextButton->fn->setBorderType(TouchTestNextButton, LE_WIDGET_BORDER_NONE);
    TouchTestNextButton->fn->setPressedImage(TouchTestNextButton, &GFX_NextScreen_60x60);
    TouchTestNextButton->fn->setReleasedImage(TouchTestNextButton, &GFX_NextScreen_60x60);
    TouchTestNextButton->fn->setReleasedEventCallback(TouchTestNextButton, TouchTestNextButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)TouchTestNextButton);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    TouchTestDemoScreen_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_TouchTestDemoScreen()
{
    TouchTestDemoScreen_OnUpdate();
}

void screenHide_TouchTestDemoScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    GradientWidget2 = NULL;
    TouchTestWidget1 = NULL;
    LabelWidget6 = NULL;
    ImageWidget5 = NULL;
    TouchTestHelpButton = NULL;
    TouchTestHomeButton = NULL;
    LabelWidget7 = NULL;
    TouchTestNextButton = NULL;

    tableString_TouchMe.fn->destructor(&tableString_TouchMe);
    tableString_TouchTestWidgetDemo.fn->destructor(&tableString_TouchTestWidgetDemo);
    showing = LE_FALSE;
}

void screenDestroy_TouchTestDemoScreen()
{

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

