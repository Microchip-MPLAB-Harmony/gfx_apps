#include "gfx/legato/generated/screen/le_gen_screen_ListWheelDemoScreen.h"

// widget list for layer 0
static leWidget* root0;

leGradientWidget* GradientWidget3;
leButtonWidget* ListWheelHelpButton;
leButtonWidget* ListWheelHomeButton;
leRectangleWidget* RectangleWidget2;
leLabelWidget* LabelWidget3;
leListWheelWidget* ListWheel2;
leListWheelWidget* ListWheel4;
leListWheelWidget* ListWheel5;
leListWheelWidget* ListWheel1;
leLabelWidget* LabelWidget4;
leLabelWidget* LabelWidget5;
leButtonWidget* ListWheelNextButton;

// string list for this screen
static leTableString tableString_colon;
static leTableString tableString_num12;
static leTableString tableString_num1;
static leTableString tableString_num2;
static leTableString tableString_num3;
static leTableString tableString_num4;
static leTableString tableString_num5;
static leTableString tableString_num6;
static leTableString tableString_num7;
static leTableString tableString_num8;
static leTableString tableString_num9;
static leTableString tableString_num10;
static leTableString tableString_num11;
static leTableString tableString_num0;
static leTableString tableString_AM;
static leTableString tableString_PM;
static leTableString tableString_SetTime;
static leTableString tableString_ListWheelDemo;

static leBool showing = LE_FALSE;

leResult screenInit_ListWheelDemoScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_ListWheelDemoScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_colon, string_colon);
    leTableString_Constructor(&tableString_num12, string_num12);
    leTableString_Constructor(&tableString_num1, string_num1);
    leTableString_Constructor(&tableString_num2, string_num2);
    leTableString_Constructor(&tableString_num3, string_num3);
    leTableString_Constructor(&tableString_num4, string_num4);
    leTableString_Constructor(&tableString_num5, string_num5);
    leTableString_Constructor(&tableString_num6, string_num6);
    leTableString_Constructor(&tableString_num7, string_num7);
    leTableString_Constructor(&tableString_num8, string_num8);
    leTableString_Constructor(&tableString_num9, string_num9);
    leTableString_Constructor(&tableString_num10, string_num10);
    leTableString_Constructor(&tableString_num11, string_num11);
    leTableString_Constructor(&tableString_num0, string_num0);
    leTableString_Constructor(&tableString_AM, string_AM);
    leTableString_Constructor(&tableString_PM, string_PM);
    leTableString_Constructor(&tableString_SetTime, string_SetTime);
    leTableString_Constructor(&tableString_ListWheelDemo, string_ListWheelDemo);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    GradientWidget3 = leGradientWidget_New();
    GradientWidget3->fn->setPosition(GradientWidget3, 0, 0);
    GradientWidget3->fn->setSize(GradientWidget3, 480, 320);
    GradientWidget3->fn->setScheme(GradientWidget3, &BackgroundGradientScheme);
    GradientWidget3->fn->setDirection(GradientWidget3, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)GradientWidget3);

    ListWheelHelpButton = leButtonWidget_New();
    ListWheelHelpButton->fn->setPosition(ListWheelHelpButton, 0, 260);
    ListWheelHelpButton->fn->setSize(ListWheelHelpButton, 60, 60);
    ListWheelHelpButton->fn->setAlphaAmount(ListWheelHelpButton, 220);
    ListWheelHelpButton->fn->setBackgroundType(ListWheelHelpButton, LE_WIDGET_BACKGROUND_NONE);
    ListWheelHelpButton->fn->setBorderType(ListWheelHelpButton, LE_WIDGET_BORDER_NONE);
    ListWheelHelpButton->fn->setPressedImage(ListWheelHelpButton, &GFX_Help_60);
    ListWheelHelpButton->fn->setReleasedImage(ListWheelHelpButton, &GFX_Help_60);
    ListWheelHelpButton->fn->setReleasedEventCallback(ListWheelHelpButton, ListWheelHelpButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ListWheelHelpButton);

    ListWheelHomeButton = leButtonWidget_New();
    ListWheelHomeButton->fn->setPosition(ListWheelHomeButton, 421, 260);
    ListWheelHomeButton->fn->setSize(ListWheelHomeButton, 60, 60);
    ListWheelHomeButton->fn->setAlphaAmount(ListWheelHomeButton, 220);
    ListWheelHomeButton->fn->setBackgroundType(ListWheelHomeButton, LE_WIDGET_BACKGROUND_NONE);
    ListWheelHomeButton->fn->setBorderType(ListWheelHomeButton, LE_WIDGET_BORDER_NONE);
    ListWheelHomeButton->fn->setPressedImage(ListWheelHomeButton, &GFX_Home_60x60);
    ListWheelHomeButton->fn->setReleasedImage(ListWheelHomeButton, &GFX_Home_60x60);
    ListWheelHomeButton->fn->setReleasedEventCallback(ListWheelHomeButton, ListWheelHomeButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ListWheelHomeButton);

    RectangleWidget2 = leRectangleWidget_New();
    RectangleWidget2->fn->setPosition(RectangleWidget2, 148, 81);
    RectangleWidget2->fn->setSize(RectangleWidget2, 272, 141);
    RectangleWidget2->fn->setScheme(RectangleWidget2, &defaultScheme);
    RectangleWidget2->fn->setBackgroundType(RectangleWidget2, LE_WIDGET_BACKGROUND_NONE);
    RectangleWidget2->fn->setThickness(RectangleWidget2, 0);
    root0->fn->addChild(root0, (leWidget*)RectangleWidget2);

    LabelWidget3 = leLabelWidget_New();
    LabelWidget3->fn->setPosition(LabelWidget3, 60, 54);
    LabelWidget3->fn->setSize(LabelWidget3, 11, 36);
    LabelWidget3->fn->setEnabled(LabelWidget3, LE_FALSE);
    LabelWidget3->fn->setBackgroundType(LabelWidget3, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget3->fn->setVAlignment(LabelWidget3, LE_VALIGN_TOP);
    LabelWidget3->fn->setString(LabelWidget3, (leString*)&tableString_colon);
    RectangleWidget2->fn->addChild(RectangleWidget2, (leWidget*)LabelWidget3);

    ListWheel2 = leListWheelWidget_New();
    ListWheel2->fn->setPosition(ListWheel2, 4, 4);
    ListWheel2->fn->setSize(ListWheel2, 57, 133);
    ListWheel2->fn->setScheme(ListWheel2, &ListWheelScheme);
    ListWheel2->fn->setBorderType(ListWheel2, LE_WIDGET_BORDER_LINE);
    ListWheel2->fn->appendItem(ListWheel2);
    ListWheel2->fn->setItemString(ListWheel2, 0, (leString*)&tableString_num12);
    ListWheel2->fn->appendItem(ListWheel2);
    ListWheel2->fn->setItemString(ListWheel2, 1, (leString*)&tableString_num1);
    ListWheel2->fn->appendItem(ListWheel2);
    ListWheel2->fn->setItemString(ListWheel2, 2, (leString*)&tableString_num2);
    ListWheel2->fn->appendItem(ListWheel2);
    ListWheel2->fn->setItemString(ListWheel2, 3, (leString*)&tableString_num3);
    ListWheel2->fn->appendItem(ListWheel2);
    ListWheel2->fn->setItemString(ListWheel2, 4, (leString*)&tableString_num4);
    ListWheel2->fn->appendItem(ListWheel2);
    ListWheel2->fn->setItemString(ListWheel2, 5, (leString*)&tableString_num5);
    ListWheel2->fn->appendItem(ListWheel2);
    ListWheel2->fn->setItemString(ListWheel2, 6, (leString*)&tableString_num6);
    ListWheel2->fn->appendItem(ListWheel2);
    ListWheel2->fn->setItemString(ListWheel2, 7, (leString*)&tableString_num7);
    ListWheel2->fn->appendItem(ListWheel2);
    ListWheel2->fn->setItemString(ListWheel2, 8, (leString*)&tableString_num8);
    ListWheel2->fn->appendItem(ListWheel2);
    ListWheel2->fn->setItemString(ListWheel2, 9, (leString*)&tableString_num9);
    ListWheel2->fn->appendItem(ListWheel2);
    ListWheel2->fn->setItemString(ListWheel2, 10, (leString*)&tableString_num10);
    ListWheel2->fn->appendItem(ListWheel2);
    ListWheel2->fn->setItemString(ListWheel2, 11, (leString*)&tableString_num11);
    ListWheel2->fn->setAutoHideWheel(ListWheel2, LE_TRUE);
    ListWheel2->fn->setIndicatorFill(ListWheel2, LE_LISTWHEEL_INDICATOR_FILL_GRADIENT);
    ListWheel2->fn->setFlickInitSpeed(ListWheel2, 5);
    ListWheel2->fn->setMaxMomentum(ListWheel2, 30000);
    ListWheel2->fn->setRotationUpdateRate(ListWheel2, 50);
    RectangleWidget2->fn->addChild(RectangleWidget2, (leWidget*)ListWheel2);

    ListWheel4 = leListWheelWidget_New();
    ListWheel4->fn->setPosition(ListWheel4, 70, 4);
    ListWheel4->fn->setSize(ListWheel4, 56, 133);
    ListWheel4->fn->setScheme(ListWheel4, &ListWheelScheme);
    ListWheel4->fn->setBorderType(ListWheel4, LE_WIDGET_BORDER_LINE);
    ListWheel4->fn->appendItem(ListWheel4);
    ListWheel4->fn->setItemString(ListWheel4, 0, (leString*)&tableString_num0);
    ListWheel4->fn->appendItem(ListWheel4);
    ListWheel4->fn->setItemString(ListWheel4, 1, (leString*)&tableString_num1);
    ListWheel4->fn->appendItem(ListWheel4);
    ListWheel4->fn->setItemString(ListWheel4, 2, (leString*)&tableString_num2);
    ListWheel4->fn->appendItem(ListWheel4);
    ListWheel4->fn->setItemString(ListWheel4, 3, (leString*)&tableString_num3);
    ListWheel4->fn->appendItem(ListWheel4);
    ListWheel4->fn->setItemString(ListWheel4, 4, (leString*)&tableString_num4);
    ListWheel4->fn->appendItem(ListWheel4);
    ListWheel4->fn->setItemString(ListWheel4, 5, (leString*)&tableString_num5);
    ListWheel4->fn->setAutoHideWheel(ListWheel4, LE_TRUE);
    ListWheel4->fn->setIndicatorFill(ListWheel4, LE_LISTWHEEL_INDICATOR_FILL_GRADIENT);
    ListWheel4->fn->setFlickInitSpeed(ListWheel4, 5);
    ListWheel4->fn->setMaxMomentum(ListWheel4, 30000);
    ListWheel4->fn->setRotationUpdateRate(ListWheel4, 50);
    RectangleWidget2->fn->addChild(RectangleWidget2, (leWidget*)ListWheel4);

    ListWheel5 = leListWheelWidget_New();
    ListWheel5->fn->setPosition(ListWheel5, 129, 4);
    ListWheel5->fn->setSize(ListWheel5, 57, 133);
    ListWheel5->fn->setScheme(ListWheel5, &ListWheelScheme);
    ListWheel5->fn->setBorderType(ListWheel5, LE_WIDGET_BORDER_LINE);
    ListWheel5->fn->appendItem(ListWheel5);
    ListWheel5->fn->setItemString(ListWheel5, 0, (leString*)&tableString_num0);
    ListWheel5->fn->appendItem(ListWheel5);
    ListWheel5->fn->setItemString(ListWheel5, 1, (leString*)&tableString_num1);
    ListWheel5->fn->appendItem(ListWheel5);
    ListWheel5->fn->setItemString(ListWheel5, 2, (leString*)&tableString_num2);
    ListWheel5->fn->appendItem(ListWheel5);
    ListWheel5->fn->setItemString(ListWheel5, 3, (leString*)&tableString_num3);
    ListWheel5->fn->appendItem(ListWheel5);
    ListWheel5->fn->setItemString(ListWheel5, 4, (leString*)&tableString_num4);
    ListWheel5->fn->appendItem(ListWheel5);
    ListWheel5->fn->setItemString(ListWheel5, 5, (leString*)&tableString_num5);
    ListWheel5->fn->appendItem(ListWheel5);
    ListWheel5->fn->setItemString(ListWheel5, 6, (leString*)&tableString_num6);
    ListWheel5->fn->appendItem(ListWheel5);
    ListWheel5->fn->setItemString(ListWheel5, 7, (leString*)&tableString_num7);
    ListWheel5->fn->appendItem(ListWheel5);
    ListWheel5->fn->setItemString(ListWheel5, 8, (leString*)&tableString_num8);
    ListWheel5->fn->appendItem(ListWheel5);
    ListWheel5->fn->setItemString(ListWheel5, 9, (leString*)&tableString_num9);
    ListWheel5->fn->setAutoHideWheel(ListWheel5, LE_TRUE);
    ListWheel5->fn->setIndicatorFill(ListWheel5, LE_LISTWHEEL_INDICATOR_FILL_GRADIENT);
    ListWheel5->fn->setFlickInitSpeed(ListWheel5, 5);
    ListWheel5->fn->setMaxMomentum(ListWheel5, 30000);
    ListWheel5->fn->setRotationUpdateRate(ListWheel5, 50);
    RectangleWidget2->fn->addChild(RectangleWidget2, (leWidget*)ListWheel5);

    ListWheel1 = leListWheelWidget_New();
    ListWheel1->fn->setPosition(ListWheel1, 189, 4);
    ListWheel1->fn->setSize(ListWheel1, 80, 133);
    ListWheel1->fn->setScheme(ListWheel1, &ListWheelScheme);
    ListWheel1->fn->setBorderType(ListWheel1, LE_WIDGET_BORDER_LINE);
    ListWheel1->fn->appendItem(ListWheel1);
    ListWheel1->fn->setItemString(ListWheel1, 0, (leString*)&tableString_AM);
    ListWheel1->fn->appendItem(ListWheel1);
    ListWheel1->fn->setItemString(ListWheel1, 1, (leString*)&tableString_PM);
    ListWheel1->fn->appendItem(ListWheel1);
    ListWheel1->fn->appendItem(ListWheel1);
    ListWheel1->fn->appendItem(ListWheel1);
    ListWheel1->fn->appendItem(ListWheel1);
    ListWheel1->fn->setAutoHideWheel(ListWheel1, LE_TRUE);
    ListWheel1->fn->setIndicatorFill(ListWheel1, LE_LISTWHEEL_INDICATOR_FILL_GRADIENT);
    ListWheel1->fn->setFlickInitSpeed(ListWheel1, 5);
    ListWheel1->fn->setMaxMomentum(ListWheel1, 500);
    ListWheel1->fn->setSelectedItemChangedEventCallback(ListWheel1, ListWheel1_OnSelectionChanged);
    RectangleWidget2->fn->addChild(RectangleWidget2, (leWidget*)ListWheel1);

    LabelWidget4 = leLabelWidget_New();
    LabelWidget4->fn->setPosition(LabelWidget4, 40, 139);
    LabelWidget4->fn->setBackgroundType(LabelWidget4, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget4->fn->setString(LabelWidget4, (leString*)&tableString_SetTime);
    root0->fn->addChild(root0, (leWidget*)LabelWidget4);

    LabelWidget5 = leLabelWidget_New();
    LabelWidget5->fn->setPosition(LabelWidget5, 10, 5);
    LabelWidget5->fn->setSize(LabelWidget5, 305, 25);
    LabelWidget5->fn->setScheme(LabelWidget5, &whiteScheme);
    LabelWidget5->fn->setBackgroundType(LabelWidget5, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget5->fn->setString(LabelWidget5, (leString*)&tableString_ListWheelDemo);
    root0->fn->addChild(root0, (leWidget*)LabelWidget5);

    ListWheelNextButton = leButtonWidget_New();
    ListWheelNextButton->fn->setPosition(ListWheelNextButton, 359, 260);
    ListWheelNextButton->fn->setSize(ListWheelNextButton, 60, 60);
    ListWheelNextButton->fn->setBackgroundType(ListWheelNextButton, LE_WIDGET_BACKGROUND_NONE);
    ListWheelNextButton->fn->setBorderType(ListWheelNextButton, LE_WIDGET_BORDER_NONE);
    ListWheelNextButton->fn->setPressedImage(ListWheelNextButton, &GFX_NextScreen_60x60);
    ListWheelNextButton->fn->setReleasedImage(ListWheelNextButton, &GFX_NextScreen_60x60);
    ListWheelNextButton->fn->setReleasedEventCallback(ListWheelNextButton, ListWheelNextButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ListWheelNextButton);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    ListWheelDemoScreen_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_ListWheelDemoScreen()
{
    ListWheelDemoScreen_OnUpdate();
}

void screenHide_ListWheelDemoScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    GradientWidget3 = NULL;
    ListWheelHelpButton = NULL;
    ListWheelHomeButton = NULL;
    RectangleWidget2 = NULL;
    LabelWidget3 = NULL;
    ListWheel2 = NULL;
    ListWheel4 = NULL;
    ListWheel5 = NULL;
    ListWheel1 = NULL;
    LabelWidget4 = NULL;
    LabelWidget5 = NULL;
    ListWheelNextButton = NULL;

    tableString_colon.fn->destructor(&tableString_colon);
    tableString_num12.fn->destructor(&tableString_num12);
    tableString_num1.fn->destructor(&tableString_num1);
    tableString_num2.fn->destructor(&tableString_num2);
    tableString_num3.fn->destructor(&tableString_num3);
    tableString_num4.fn->destructor(&tableString_num4);
    tableString_num5.fn->destructor(&tableString_num5);
    tableString_num6.fn->destructor(&tableString_num6);
    tableString_num7.fn->destructor(&tableString_num7);
    tableString_num8.fn->destructor(&tableString_num8);
    tableString_num9.fn->destructor(&tableString_num9);
    tableString_num10.fn->destructor(&tableString_num10);
    tableString_num11.fn->destructor(&tableString_num11);
    tableString_num0.fn->destructor(&tableString_num0);
    tableString_AM.fn->destructor(&tableString_AM);
    tableString_PM.fn->destructor(&tableString_PM);
    tableString_SetTime.fn->destructor(&tableString_SetTime);
    tableString_ListWheelDemo.fn->destructor(&tableString_ListWheelDemo);
    showing = LE_FALSE;
}

void screenDestroy_ListWheelDemoScreen()
{

}

leWidget* screenGetRoot_ListWheelDemoScreen(uint32_t lyrIdx)
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

