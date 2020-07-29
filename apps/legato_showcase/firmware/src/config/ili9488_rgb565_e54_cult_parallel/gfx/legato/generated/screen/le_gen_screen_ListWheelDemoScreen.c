#include "gfx/legato/generated/screen/le_gen_screen_ListWheelDemoScreen.h"

// screen member widget declarations
leWidget* root0;

leGradientWidget* ListWheelDemoScreen_GradientWidget3;
leButtonWidget* ListWheelDemoScreen_ListWheelHelpButton;
leButtonWidget* ListWheelDemoScreen_ListWheelHomeButton;
leRectangleWidget* ListWheelDemoScreen_RectangleWidget2;
leLabelWidget* ListWheelDemoScreen_LabelWidget4;
leLabelWidget* ListWheelDemoScreen_LabelWidget5;
leButtonWidget* ListWheelDemoScreen_ListWheelNextButton;
leLabelWidget* ListWheelDemoScreen_LabelWidget3;
leListWheelWidget* ListWheelDemoScreen_ListWheel2;
leListWheelWidget* ListWheelDemoScreen_ListWheel4;
leListWheelWidget* ListWheelDemoScreen_ListWheel5;
leListWheelWidget* ListWheelDemoScreen_ListWheel1;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_ListWheelDemoScreen()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_ListWheelDemoScreen()
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

    ListWheelDemoScreen_GradientWidget3 = leGradientWidget_New();
    ListWheelDemoScreen_GradientWidget3->fn->setPosition(ListWheelDemoScreen_GradientWidget3, 0, 0);
    ListWheelDemoScreen_GradientWidget3->fn->setSize(ListWheelDemoScreen_GradientWidget3, 480, 320);
    ListWheelDemoScreen_GradientWidget3->fn->setScheme(ListWheelDemoScreen_GradientWidget3, &BackgroundGradientScheme);
    ListWheelDemoScreen_GradientWidget3->fn->setDirection(ListWheelDemoScreen_GradientWidget3, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)ListWheelDemoScreen_GradientWidget3);

    ListWheelDemoScreen_ListWheelHelpButton = leButtonWidget_New();
    ListWheelDemoScreen_ListWheelHelpButton->fn->setPosition(ListWheelDemoScreen_ListWheelHelpButton, 0, 260);
    ListWheelDemoScreen_ListWheelHelpButton->fn->setSize(ListWheelDemoScreen_ListWheelHelpButton, 60, 60);
    ListWheelDemoScreen_ListWheelHelpButton->fn->setAlphaAmount(ListWheelDemoScreen_ListWheelHelpButton, 220);
    ListWheelDemoScreen_ListWheelHelpButton->fn->setBackgroundType(ListWheelDemoScreen_ListWheelHelpButton, LE_WIDGET_BACKGROUND_NONE);
    ListWheelDemoScreen_ListWheelHelpButton->fn->setBorderType(ListWheelDemoScreen_ListWheelHelpButton, LE_WIDGET_BORDER_NONE);
    ListWheelDemoScreen_ListWheelHelpButton->fn->setPressedImage(ListWheelDemoScreen_ListWheelHelpButton, (leImage*)&GFX_Help_60);
    ListWheelDemoScreen_ListWheelHelpButton->fn->setReleasedImage(ListWheelDemoScreen_ListWheelHelpButton, (leImage*)&GFX_Help_60);
    ListWheelDemoScreen_ListWheelHelpButton->fn->setReleasedEventCallback(ListWheelDemoScreen_ListWheelHelpButton, event_ListWheelDemoScreen_ListWheelHelpButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ListWheelDemoScreen_ListWheelHelpButton);

    ListWheelDemoScreen_ListWheelHomeButton = leButtonWidget_New();
    ListWheelDemoScreen_ListWheelHomeButton->fn->setPosition(ListWheelDemoScreen_ListWheelHomeButton, 421, 260);
    ListWheelDemoScreen_ListWheelHomeButton->fn->setSize(ListWheelDemoScreen_ListWheelHomeButton, 60, 60);
    ListWheelDemoScreen_ListWheelHomeButton->fn->setAlphaAmount(ListWheelDemoScreen_ListWheelHomeButton, 220);
    ListWheelDemoScreen_ListWheelHomeButton->fn->setBackgroundType(ListWheelDemoScreen_ListWheelHomeButton, LE_WIDGET_BACKGROUND_NONE);
    ListWheelDemoScreen_ListWheelHomeButton->fn->setBorderType(ListWheelDemoScreen_ListWheelHomeButton, LE_WIDGET_BORDER_NONE);
    ListWheelDemoScreen_ListWheelHomeButton->fn->setPressedImage(ListWheelDemoScreen_ListWheelHomeButton, (leImage*)&GFX_Home_60x60);
    ListWheelDemoScreen_ListWheelHomeButton->fn->setReleasedImage(ListWheelDemoScreen_ListWheelHomeButton, (leImage*)&GFX_Home_60x60);
    ListWheelDemoScreen_ListWheelHomeButton->fn->setReleasedEventCallback(ListWheelDemoScreen_ListWheelHomeButton, event_ListWheelDemoScreen_ListWheelHomeButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ListWheelDemoScreen_ListWheelHomeButton);

    ListWheelDemoScreen_RectangleWidget2 = leRectangleWidget_New();
    ListWheelDemoScreen_RectangleWidget2->fn->setPosition(ListWheelDemoScreen_RectangleWidget2, 148, 81);
    ListWheelDemoScreen_RectangleWidget2->fn->setSize(ListWheelDemoScreen_RectangleWidget2, 272, 141);
    ListWheelDemoScreen_RectangleWidget2->fn->setScheme(ListWheelDemoScreen_RectangleWidget2, &defaultScheme);
    ListWheelDemoScreen_RectangleWidget2->fn->setBackgroundType(ListWheelDemoScreen_RectangleWidget2, LE_WIDGET_BACKGROUND_NONE);
    ListWheelDemoScreen_RectangleWidget2->fn->setBorderType(ListWheelDemoScreen_RectangleWidget2, LE_WIDGET_BORDER_NONE);
    ListWheelDemoScreen_RectangleWidget2->fn->setThickness(ListWheelDemoScreen_RectangleWidget2, 0);
    root0->fn->addChild(root0, (leWidget*)ListWheelDemoScreen_RectangleWidget2);

    ListWheelDemoScreen_LabelWidget3 = leLabelWidget_New();
    ListWheelDemoScreen_LabelWidget3->fn->setPosition(ListWheelDemoScreen_LabelWidget3, 60, 54);
    ListWheelDemoScreen_LabelWidget3->fn->setSize(ListWheelDemoScreen_LabelWidget3, 11, 36);
    ListWheelDemoScreen_LabelWidget3->fn->setEnabled(ListWheelDemoScreen_LabelWidget3, LE_FALSE);
    ListWheelDemoScreen_LabelWidget3->fn->setBackgroundType(ListWheelDemoScreen_LabelWidget3, LE_WIDGET_BACKGROUND_NONE);
    ListWheelDemoScreen_LabelWidget3->fn->setVAlignment(ListWheelDemoScreen_LabelWidget3, LE_VALIGN_TOP);
    ListWheelDemoScreen_LabelWidget3->fn->setString(ListWheelDemoScreen_LabelWidget3, (leString*)&string_colon);
    ListWheelDemoScreen_RectangleWidget2->fn->addChild(ListWheelDemoScreen_RectangleWidget2, (leWidget*)ListWheelDemoScreen_LabelWidget3);

    ListWheelDemoScreen_ListWheel2 = leListWheelWidget_New();
    ListWheelDemoScreen_ListWheel2->fn->setPosition(ListWheelDemoScreen_ListWheel2, 4, 4);
    ListWheelDemoScreen_ListWheel2->fn->setSize(ListWheelDemoScreen_ListWheel2, 57, 133);
    ListWheelDemoScreen_ListWheel2->fn->setScheme(ListWheelDemoScreen_ListWheel2, &ListWheelScheme);
    ListWheelDemoScreen_ListWheel2->fn->setBorderType(ListWheelDemoScreen_ListWheel2, LE_WIDGET_BORDER_LINE);
    ListWheelDemoScreen_ListWheel2->fn->setFlickInitSpeed(ListWheelDemoScreen_ListWheel2, 5);
    ListWheelDemoScreen_ListWheel2->fn->setMaxMomentum(ListWheelDemoScreen_ListWheel2, 30000);
    ListWheelDemoScreen_ListWheel2->fn->setRotationUpdateRate(ListWheelDemoScreen_ListWheel2, 50);
    ListWheelDemoScreen_ListWheel2->fn->setAutoHideWheel(ListWheelDemoScreen_ListWheel2, LE_TRUE);
    ListWheelDemoScreen_ListWheel2->fn->appendItem(ListWheelDemoScreen_ListWheel2);
    ListWheelDemoScreen_ListWheel2->fn->setItemString(ListWheelDemoScreen_ListWheel2, 0, (leString*)&string_num12);
    ListWheelDemoScreen_ListWheel2->fn->appendItem(ListWheelDemoScreen_ListWheel2);
    ListWheelDemoScreen_ListWheel2->fn->setItemString(ListWheelDemoScreen_ListWheel2, 1, (leString*)&string_num1);
    ListWheelDemoScreen_ListWheel2->fn->appendItem(ListWheelDemoScreen_ListWheel2);
    ListWheelDemoScreen_ListWheel2->fn->setItemString(ListWheelDemoScreen_ListWheel2, 2, (leString*)&string_num2);
    ListWheelDemoScreen_ListWheel2->fn->appendItem(ListWheelDemoScreen_ListWheel2);
    ListWheelDemoScreen_ListWheel2->fn->setItemString(ListWheelDemoScreen_ListWheel2, 3, (leString*)&string_num3);
    ListWheelDemoScreen_ListWheel2->fn->appendItem(ListWheelDemoScreen_ListWheel2);
    ListWheelDemoScreen_ListWheel2->fn->setItemString(ListWheelDemoScreen_ListWheel2, 4, (leString*)&string_num4);
    ListWheelDemoScreen_ListWheel2->fn->appendItem(ListWheelDemoScreen_ListWheel2);
    ListWheelDemoScreen_ListWheel2->fn->setItemString(ListWheelDemoScreen_ListWheel2, 5, (leString*)&string_num5);
    ListWheelDemoScreen_ListWheel2->fn->appendItem(ListWheelDemoScreen_ListWheel2);
    ListWheelDemoScreen_ListWheel2->fn->setItemString(ListWheelDemoScreen_ListWheel2, 6, (leString*)&string_num6);
    ListWheelDemoScreen_ListWheel2->fn->appendItem(ListWheelDemoScreen_ListWheel2);
    ListWheelDemoScreen_ListWheel2->fn->setItemString(ListWheelDemoScreen_ListWheel2, 7, (leString*)&string_num7);
    ListWheelDemoScreen_ListWheel2->fn->appendItem(ListWheelDemoScreen_ListWheel2);
    ListWheelDemoScreen_ListWheel2->fn->setItemString(ListWheelDemoScreen_ListWheel2, 8, (leString*)&string_num8);
    ListWheelDemoScreen_ListWheel2->fn->appendItem(ListWheelDemoScreen_ListWheel2);
    ListWheelDemoScreen_ListWheel2->fn->setItemString(ListWheelDemoScreen_ListWheel2, 9, (leString*)&string_num9);
    ListWheelDemoScreen_ListWheel2->fn->appendItem(ListWheelDemoScreen_ListWheel2);
    ListWheelDemoScreen_ListWheel2->fn->setItemString(ListWheelDemoScreen_ListWheel2, 10, (leString*)&string_num10);
    ListWheelDemoScreen_ListWheel2->fn->appendItem(ListWheelDemoScreen_ListWheel2);
    ListWheelDemoScreen_ListWheel2->fn->setItemString(ListWheelDemoScreen_ListWheel2, 11, (leString*)&string_num11);
    ListWheelDemoScreen_RectangleWidget2->fn->addChild(ListWheelDemoScreen_RectangleWidget2, (leWidget*)ListWheelDemoScreen_ListWheel2);

    ListWheelDemoScreen_ListWheel4 = leListWheelWidget_New();
    ListWheelDemoScreen_ListWheel4->fn->setPosition(ListWheelDemoScreen_ListWheel4, 70, 4);
    ListWheelDemoScreen_ListWheel4->fn->setSize(ListWheelDemoScreen_ListWheel4, 56, 133);
    ListWheelDemoScreen_ListWheel4->fn->setScheme(ListWheelDemoScreen_ListWheel4, &ListWheelScheme);
    ListWheelDemoScreen_ListWheel4->fn->setBorderType(ListWheelDemoScreen_ListWheel4, LE_WIDGET_BORDER_LINE);
    ListWheelDemoScreen_ListWheel4->fn->setFlickInitSpeed(ListWheelDemoScreen_ListWheel4, 5);
    ListWheelDemoScreen_ListWheel4->fn->setMaxMomentum(ListWheelDemoScreen_ListWheel4, 30000);
    ListWheelDemoScreen_ListWheel4->fn->setRotationUpdateRate(ListWheelDemoScreen_ListWheel4, 50);
    ListWheelDemoScreen_ListWheel4->fn->setAutoHideWheel(ListWheelDemoScreen_ListWheel4, LE_TRUE);
    ListWheelDemoScreen_ListWheel4->fn->appendItem(ListWheelDemoScreen_ListWheel4);
    ListWheelDemoScreen_ListWheel4->fn->setItemString(ListWheelDemoScreen_ListWheel4, 0, (leString*)&string_num0);
    ListWheelDemoScreen_ListWheel4->fn->appendItem(ListWheelDemoScreen_ListWheel4);
    ListWheelDemoScreen_ListWheel4->fn->setItemString(ListWheelDemoScreen_ListWheel4, 1, (leString*)&string_num1);
    ListWheelDemoScreen_ListWheel4->fn->appendItem(ListWheelDemoScreen_ListWheel4);
    ListWheelDemoScreen_ListWheel4->fn->setItemString(ListWheelDemoScreen_ListWheel4, 2, (leString*)&string_num2);
    ListWheelDemoScreen_ListWheel4->fn->appendItem(ListWheelDemoScreen_ListWheel4);
    ListWheelDemoScreen_ListWheel4->fn->setItemString(ListWheelDemoScreen_ListWheel4, 3, (leString*)&string_num3);
    ListWheelDemoScreen_ListWheel4->fn->appendItem(ListWheelDemoScreen_ListWheel4);
    ListWheelDemoScreen_ListWheel4->fn->setItemString(ListWheelDemoScreen_ListWheel4, 4, (leString*)&string_num4);
    ListWheelDemoScreen_ListWheel4->fn->appendItem(ListWheelDemoScreen_ListWheel4);
    ListWheelDemoScreen_ListWheel4->fn->setItemString(ListWheelDemoScreen_ListWheel4, 5, (leString*)&string_num5);
    ListWheelDemoScreen_RectangleWidget2->fn->addChild(ListWheelDemoScreen_RectangleWidget2, (leWidget*)ListWheelDemoScreen_ListWheel4);

    ListWheelDemoScreen_ListWheel5 = leListWheelWidget_New();
    ListWheelDemoScreen_ListWheel5->fn->setPosition(ListWheelDemoScreen_ListWheel5, 129, 4);
    ListWheelDemoScreen_ListWheel5->fn->setSize(ListWheelDemoScreen_ListWheel5, 57, 133);
    ListWheelDemoScreen_ListWheel5->fn->setScheme(ListWheelDemoScreen_ListWheel5, &ListWheelScheme);
    ListWheelDemoScreen_ListWheel5->fn->setBorderType(ListWheelDemoScreen_ListWheel5, LE_WIDGET_BORDER_LINE);
    ListWheelDemoScreen_ListWheel5->fn->setFlickInitSpeed(ListWheelDemoScreen_ListWheel5, 5);
    ListWheelDemoScreen_ListWheel5->fn->setMaxMomentum(ListWheelDemoScreen_ListWheel5, 30000);
    ListWheelDemoScreen_ListWheel5->fn->setRotationUpdateRate(ListWheelDemoScreen_ListWheel5, 50);
    ListWheelDemoScreen_ListWheel5->fn->setAutoHideWheel(ListWheelDemoScreen_ListWheel5, LE_TRUE);
    ListWheelDemoScreen_ListWheel5->fn->appendItem(ListWheelDemoScreen_ListWheel5);
    ListWheelDemoScreen_ListWheel5->fn->setItemString(ListWheelDemoScreen_ListWheel5, 0, (leString*)&string_num0);
    ListWheelDemoScreen_ListWheel5->fn->appendItem(ListWheelDemoScreen_ListWheel5);
    ListWheelDemoScreen_ListWheel5->fn->setItemString(ListWheelDemoScreen_ListWheel5, 1, (leString*)&string_num1);
    ListWheelDemoScreen_ListWheel5->fn->appendItem(ListWheelDemoScreen_ListWheel5);
    ListWheelDemoScreen_ListWheel5->fn->setItemString(ListWheelDemoScreen_ListWheel5, 2, (leString*)&string_num2);
    ListWheelDemoScreen_ListWheel5->fn->appendItem(ListWheelDemoScreen_ListWheel5);
    ListWheelDemoScreen_ListWheel5->fn->setItemString(ListWheelDemoScreen_ListWheel5, 3, (leString*)&string_num3);
    ListWheelDemoScreen_ListWheel5->fn->appendItem(ListWheelDemoScreen_ListWheel5);
    ListWheelDemoScreen_ListWheel5->fn->setItemString(ListWheelDemoScreen_ListWheel5, 4, (leString*)&string_num4);
    ListWheelDemoScreen_ListWheel5->fn->appendItem(ListWheelDemoScreen_ListWheel5);
    ListWheelDemoScreen_ListWheel5->fn->setItemString(ListWheelDemoScreen_ListWheel5, 5, (leString*)&string_num5);
    ListWheelDemoScreen_ListWheel5->fn->appendItem(ListWheelDemoScreen_ListWheel5);
    ListWheelDemoScreen_ListWheel5->fn->setItemString(ListWheelDemoScreen_ListWheel5, 6, (leString*)&string_num6);
    ListWheelDemoScreen_ListWheel5->fn->appendItem(ListWheelDemoScreen_ListWheel5);
    ListWheelDemoScreen_ListWheel5->fn->setItemString(ListWheelDemoScreen_ListWheel5, 7, (leString*)&string_num7);
    ListWheelDemoScreen_ListWheel5->fn->appendItem(ListWheelDemoScreen_ListWheel5);
    ListWheelDemoScreen_ListWheel5->fn->setItemString(ListWheelDemoScreen_ListWheel5, 8, (leString*)&string_num8);
    ListWheelDemoScreen_ListWheel5->fn->appendItem(ListWheelDemoScreen_ListWheel5);
    ListWheelDemoScreen_ListWheel5->fn->setItemString(ListWheelDemoScreen_ListWheel5, 9, (leString*)&string_num9);
    ListWheelDemoScreen_RectangleWidget2->fn->addChild(ListWheelDemoScreen_RectangleWidget2, (leWidget*)ListWheelDemoScreen_ListWheel5);

    ListWheelDemoScreen_ListWheel1 = leListWheelWidget_New();
    ListWheelDemoScreen_ListWheel1->fn->setPosition(ListWheelDemoScreen_ListWheel1, 189, 4);
    ListWheelDemoScreen_ListWheel1->fn->setSize(ListWheelDemoScreen_ListWheel1, 80, 133);
    ListWheelDemoScreen_ListWheel1->fn->setScheme(ListWheelDemoScreen_ListWheel1, &ListWheelScheme);
    ListWheelDemoScreen_ListWheel1->fn->setBorderType(ListWheelDemoScreen_ListWheel1, LE_WIDGET_BORDER_LINE);
    ListWheelDemoScreen_ListWheel1->fn->setFlickInitSpeed(ListWheelDemoScreen_ListWheel1, 5);
    ListWheelDemoScreen_ListWheel1->fn->setMaxMomentum(ListWheelDemoScreen_ListWheel1, 500);
    ListWheelDemoScreen_ListWheel1->fn->setAutoHideWheel(ListWheelDemoScreen_ListWheel1, LE_TRUE);
    ListWheelDemoScreen_ListWheel1->fn->appendItem(ListWheelDemoScreen_ListWheel1);
    ListWheelDemoScreen_ListWheel1->fn->setItemString(ListWheelDemoScreen_ListWheel1, 0, (leString*)&string_AM);
    ListWheelDemoScreen_ListWheel1->fn->appendItem(ListWheelDemoScreen_ListWheel1);
    ListWheelDemoScreen_ListWheel1->fn->setItemString(ListWheelDemoScreen_ListWheel1, 1, (leString*)&string_PM);
    ListWheelDemoScreen_ListWheel1->fn->appendItem(ListWheelDemoScreen_ListWheel1);
    ListWheelDemoScreen_ListWheel1->fn->appendItem(ListWheelDemoScreen_ListWheel1);
    ListWheelDemoScreen_ListWheel1->fn->appendItem(ListWheelDemoScreen_ListWheel1);
    ListWheelDemoScreen_ListWheel1->fn->appendItem(ListWheelDemoScreen_ListWheel1);
    ListWheelDemoScreen_ListWheel1->fn->setSelectedItemChangedEventCallback(ListWheelDemoScreen_ListWheel1, event_ListWheelDemoScreen_ListWheel1_OnSelectionChanged);
    ListWheelDemoScreen_RectangleWidget2->fn->addChild(ListWheelDemoScreen_RectangleWidget2, (leWidget*)ListWheelDemoScreen_ListWheel1);

    ListWheelDemoScreen_LabelWidget4 = leLabelWidget_New();
    ListWheelDemoScreen_LabelWidget4->fn->setPosition(ListWheelDemoScreen_LabelWidget4, 40, 139);
    ListWheelDemoScreen_LabelWidget4->fn->setBackgroundType(ListWheelDemoScreen_LabelWidget4, LE_WIDGET_BACKGROUND_NONE);
    ListWheelDemoScreen_LabelWidget4->fn->setString(ListWheelDemoScreen_LabelWidget4, (leString*)&string_SetTime);
    root0->fn->addChild(root0, (leWidget*)ListWheelDemoScreen_LabelWidget4);

    ListWheelDemoScreen_LabelWidget5 = leLabelWidget_New();
    ListWheelDemoScreen_LabelWidget5->fn->setPosition(ListWheelDemoScreen_LabelWidget5, 10, 5);
    ListWheelDemoScreen_LabelWidget5->fn->setSize(ListWheelDemoScreen_LabelWidget5, 305, 25);
    ListWheelDemoScreen_LabelWidget5->fn->setScheme(ListWheelDemoScreen_LabelWidget5, &whiteScheme);
    ListWheelDemoScreen_LabelWidget5->fn->setBackgroundType(ListWheelDemoScreen_LabelWidget5, LE_WIDGET_BACKGROUND_NONE);
    ListWheelDemoScreen_LabelWidget5->fn->setString(ListWheelDemoScreen_LabelWidget5, (leString*)&string_ListWheelDemo);
    root0->fn->addChild(root0, (leWidget*)ListWheelDemoScreen_LabelWidget5);

    ListWheelDemoScreen_ListWheelNextButton = leButtonWidget_New();
    ListWheelDemoScreen_ListWheelNextButton->fn->setPosition(ListWheelDemoScreen_ListWheelNextButton, 359, 260);
    ListWheelDemoScreen_ListWheelNextButton->fn->setSize(ListWheelDemoScreen_ListWheelNextButton, 60, 60);
    ListWheelDemoScreen_ListWheelNextButton->fn->setBackgroundType(ListWheelDemoScreen_ListWheelNextButton, LE_WIDGET_BACKGROUND_NONE);
    ListWheelDemoScreen_ListWheelNextButton->fn->setBorderType(ListWheelDemoScreen_ListWheelNextButton, LE_WIDGET_BORDER_NONE);
    ListWheelDemoScreen_ListWheelNextButton->fn->setPressedImage(ListWheelDemoScreen_ListWheelNextButton, (leImage*)&GFX_NextScreen_60x60);
    ListWheelDemoScreen_ListWheelNextButton->fn->setReleasedImage(ListWheelDemoScreen_ListWheelNextButton, (leImage*)&GFX_NextScreen_60x60);
    ListWheelDemoScreen_ListWheelNextButton->fn->setReleasedEventCallback(ListWheelDemoScreen_ListWheelNextButton, event_ListWheelDemoScreen_ListWheelNextButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ListWheelDemoScreen_ListWheelNextButton);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    ListWheelDemoScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_ListWheelDemoScreen()
{
    ListWheelDemoScreen_OnUpdate(); // raise event
}

void screenHide_ListWheelDemoScreen()
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    ListWheelDemoScreen_GradientWidget3 = NULL;
    ListWheelDemoScreen_ListWheelHelpButton = NULL;
    ListWheelDemoScreen_ListWheelHomeButton = NULL;
    ListWheelDemoScreen_RectangleWidget2 = NULL;
    ListWheelDemoScreen_LabelWidget4 = NULL;
    ListWheelDemoScreen_LabelWidget5 = NULL;
    ListWheelDemoScreen_ListWheelNextButton = NULL;
    ListWheelDemoScreen_LabelWidget3 = NULL;
    ListWheelDemoScreen_ListWheel2 = NULL;
    ListWheelDemoScreen_ListWheel4 = NULL;
    ListWheelDemoScreen_ListWheel5 = NULL;
    ListWheelDemoScreen_ListWheel1 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_ListWheelDemoScreen()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
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

