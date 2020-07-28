#include "gfx/legato/generated/screen/le_gen_screen_Screen2.h"

// screen member widget declarations
leWidget* root0;

leWidget* Screen2_MotionBackground;
leRectangleWidget* Screen2_RectMotionWidget10;
leRectangleWidget* Screen2_RectMotionWidget9;
leRectangleWidget* Screen2_RectMotionWidget8;
leRectangleWidget* Screen2_RectMotionWidget7;
leRectangleWidget* Screen2_RectMotionWidget6;
leRectangleWidget* Screen2_RectMotionWidget5;
leRectangleWidget* Screen2_RectMotionWidget4;
leRectangleWidget* Screen2_RectMotionWidget3;
leRectangleWidget* Screen2_RectMotionWidget2;
leRectangleWidget* Screen2_RectMotionWidget1;
leWidget* Screen2_MotionSideContainer;
leButtonWidget* Screen2_MotionUpdateValue;
leButtonWidget* Screen2_MotionSizeUpButton;
leButtonWidget* Screen2_MotionSizeDownButton;
leLabelWidget* Screen2_MotionRectSizeValue;
leLabelWidget* Screen2_MotionRectSizeLabel;
leLabelWidget* Screen2_MotionRectCount;
leLabelWidget* Screen2_MotionNumLabel;
leButtonWidget* Screen2_MotionPlusButton;
leButtonWidget* Screen2_MotionMinusButton;
leButtonWidget* Screen2_MotionNextButton;
leLabelWidget* Screen2_MotionContainerTitle;
leLabelWidget* Screen2_MotionRefreshValue;
leLabelWidget* Screen2_MotionRefreshLabel;
leLabelWidget* Screen2_MotionUpdateLabel;

// string list for this screen
static leTableString string_NumsLarge;
static leTableString string_NumsLittle;
static leTableString string_Size;
static leTableString string_Next;
static leTableString string_DynamicString;
static leTableString string_Plus;
static leTableString string_Minus;
static leTableString string_RefreshRate;
static leTableString string_FPS;
static leTableString string_NumsTiny;
static leTableString string_RectanglesNum;
static leTableString string_MotionUpdates;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen2()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen2()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&string_NumsLarge, stringID_NumsLarge);
    leTableString_Constructor(&string_NumsLittle, stringID_NumsLittle);
    leTableString_Constructor(&string_Size, stringID_Size);
    leTableString_Constructor(&string_Next, stringID_Next);
    leTableString_Constructor(&string_DynamicString, stringID_DynamicString);
    leTableString_Constructor(&string_Plus, stringID_Plus);
    leTableString_Constructor(&string_Minus, stringID_Minus);
    leTableString_Constructor(&string_RefreshRate, stringID_RefreshRate);
    leTableString_Constructor(&string_FPS, stringID_FPS);
    leTableString_Constructor(&string_NumsTiny, stringID_NumsTiny);
    leTableString_Constructor(&string_RectanglesNum, stringID_RectanglesNum);
    leTableString_Constructor(&string_MotionUpdates, stringID_MotionUpdates);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen2_MotionBackground = leWidget_New();
    Screen2_MotionBackground->fn->setPosition(Screen2_MotionBackground, 0, 0);
    Screen2_MotionBackground->fn->setSize(Screen2_MotionBackground, 480, 320);
    Screen2_MotionBackground->fn->setScheme(Screen2_MotionBackground, &LightGreenBackgroundScheme);
    root0->fn->addChild(root0, (leWidget*)Screen2_MotionBackground);

    Screen2_RectMotionWidget10 = leRectangleWidget_New();
    Screen2_RectMotionWidget10->fn->setPosition(Screen2_RectMotionWidget10, 314, 131);
    Screen2_RectMotionWidget10->fn->setSize(Screen2_RectMotionWidget10, 40, 40);
    Screen2_RectMotionWidget10->fn->setScheme(Screen2_RectMotionWidget10, &BrownFillScheme);
    Screen2_RectMotionWidget10->fn->setBorderType(Screen2_RectMotionWidget10, LE_WIDGET_BORDER_NONE);
    Screen2_RectMotionWidget10->fn->setThickness(Screen2_RectMotionWidget10, 0);
    root0->fn->addChild(root0, (leWidget*)Screen2_RectMotionWidget10);

    Screen2_RectMotionWidget9 = leRectangleWidget_New();
    Screen2_RectMotionWidget9->fn->setPosition(Screen2_RectMotionWidget9, 178, 169);
    Screen2_RectMotionWidget9->fn->setSize(Screen2_RectMotionWidget9, 40, 40);
    Screen2_RectMotionWidget9->fn->setScheme(Screen2_RectMotionWidget9, &LightBlueFillScheme);
    Screen2_RectMotionWidget9->fn->setBorderType(Screen2_RectMotionWidget9, LE_WIDGET_BORDER_NONE);
    Screen2_RectMotionWidget9->fn->setThickness(Screen2_RectMotionWidget9, 0);
    root0->fn->addChild(root0, (leWidget*)Screen2_RectMotionWidget9);

    Screen2_RectMotionWidget8 = leRectangleWidget_New();
    Screen2_RectMotionWidget8->fn->setPosition(Screen2_RectMotionWidget8, 193, 3);
    Screen2_RectMotionWidget8->fn->setSize(Screen2_RectMotionWidget8, 40, 40);
    Screen2_RectMotionWidget8->fn->setScheme(Screen2_RectMotionWidget8, &PurpleFillScheme);
    Screen2_RectMotionWidget8->fn->setBorderType(Screen2_RectMotionWidget8, LE_WIDGET_BORDER_NONE);
    Screen2_RectMotionWidget8->fn->setThickness(Screen2_RectMotionWidget8, 0);
    root0->fn->addChild(root0, (leWidget*)Screen2_RectMotionWidget8);

    Screen2_RectMotionWidget7 = leRectangleWidget_New();
    Screen2_RectMotionWidget7->fn->setPosition(Screen2_RectMotionWidget7, 155, 70);
    Screen2_RectMotionWidget7->fn->setSize(Screen2_RectMotionWidget7, 40, 40);
    Screen2_RectMotionWidget7->fn->setScheme(Screen2_RectMotionWidget7, &PinkFillScheme);
    Screen2_RectMotionWidget7->fn->setBorderType(Screen2_RectMotionWidget7, LE_WIDGET_BORDER_NONE);
    Screen2_RectMotionWidget7->fn->setThickness(Screen2_RectMotionWidget7, 0);
    root0->fn->addChild(root0, (leWidget*)Screen2_RectMotionWidget7);

    Screen2_RectMotionWidget6 = leRectangleWidget_New();
    Screen2_RectMotionWidget6->fn->setPosition(Screen2_RectMotionWidget6, 98, 24);
    Screen2_RectMotionWidget6->fn->setSize(Screen2_RectMotionWidget6, 40, 40);
    Screen2_RectMotionWidget6->fn->setScheme(Screen2_RectMotionWidget6, &OrangeFillScheme);
    Screen2_RectMotionWidget6->fn->setBorderType(Screen2_RectMotionWidget6, LE_WIDGET_BORDER_NONE);
    Screen2_RectMotionWidget6->fn->setThickness(Screen2_RectMotionWidget6, 0);
    root0->fn->addChild(root0, (leWidget*)Screen2_RectMotionWidget6);

    Screen2_RectMotionWidget5 = leRectangleWidget_New();
    Screen2_RectMotionWidget5->fn->setPosition(Screen2_RectMotionWidget5, 197, 101);
    Screen2_RectMotionWidget5->fn->setSize(Screen2_RectMotionWidget5, 40, 40);
    Screen2_RectMotionWidget5->fn->setScheme(Screen2_RectMotionWidget5, &BlueFillScheme);
    Screen2_RectMotionWidget5->fn->setBorderType(Screen2_RectMotionWidget5, LE_WIDGET_BORDER_NONE);
    Screen2_RectMotionWidget5->fn->setThickness(Screen2_RectMotionWidget5, 0);
    root0->fn->addChild(root0, (leWidget*)Screen2_RectMotionWidget5);

    Screen2_RectMotionWidget4 = leRectangleWidget_New();
    Screen2_RectMotionWidget4->fn->setPosition(Screen2_RectMotionWidget4, 264, 79);
    Screen2_RectMotionWidget4->fn->setSize(Screen2_RectMotionWidget4, 40, 40);
    Screen2_RectMotionWidget4->fn->setScheme(Screen2_RectMotionWidget4, &YellowFillScheme);
    Screen2_RectMotionWidget4->fn->setBorderType(Screen2_RectMotionWidget4, LE_WIDGET_BORDER_NONE);
    Screen2_RectMotionWidget4->fn->setThickness(Screen2_RectMotionWidget4, 0);
    root0->fn->addChild(root0, (leWidget*)Screen2_RectMotionWidget4);

    Screen2_RectMotionWidget3 = leRectangleWidget_New();
    Screen2_RectMotionWidget3->fn->setPosition(Screen2_RectMotionWidget3, 84, 185);
    Screen2_RectMotionWidget3->fn->setSize(Screen2_RectMotionWidget3, 40, 40);
    Screen2_RectMotionWidget3->fn->setScheme(Screen2_RectMotionWidget3, &WhiteFillScheme);
    Screen2_RectMotionWidget3->fn->setBorderType(Screen2_RectMotionWidget3, LE_WIDGET_BORDER_NONE);
    Screen2_RectMotionWidget3->fn->setThickness(Screen2_RectMotionWidget3, 0);
    root0->fn->addChild(root0, (leWidget*)Screen2_RectMotionWidget3);

    Screen2_RectMotionWidget2 = leRectangleWidget_New();
    Screen2_RectMotionWidget2->fn->setPosition(Screen2_RectMotionWidget2, 286, 206);
    Screen2_RectMotionWidget2->fn->setSize(Screen2_RectMotionWidget2, 40, 40);
    Screen2_RectMotionWidget2->fn->setScheme(Screen2_RectMotionWidget2, &RedFillScheme);
    Screen2_RectMotionWidget2->fn->setBorderType(Screen2_RectMotionWidget2, LE_WIDGET_BORDER_NONE);
    Screen2_RectMotionWidget2->fn->setThickness(Screen2_RectMotionWidget2, 0);
    root0->fn->addChild(root0, (leWidget*)Screen2_RectMotionWidget2);

    Screen2_RectMotionWidget1 = leRectangleWidget_New();
    Screen2_RectMotionWidget1->fn->setPosition(Screen2_RectMotionWidget1, 9, 118);
    Screen2_RectMotionWidget1->fn->setSize(Screen2_RectMotionWidget1, 40, 40);
    Screen2_RectMotionWidget1->fn->setScheme(Screen2_RectMotionWidget1, &LightPinkFillScheme);
    Screen2_RectMotionWidget1->fn->setBorderType(Screen2_RectMotionWidget1, LE_WIDGET_BORDER_NONE);
    Screen2_RectMotionWidget1->fn->setThickness(Screen2_RectMotionWidget1, 0);
    root0->fn->addChild(root0, (leWidget*)Screen2_RectMotionWidget1);

    Screen2_MotionSideContainer = leWidget_New();
    Screen2_MotionSideContainer->fn->setPosition(Screen2_MotionSideContainer, 359, 8);
    Screen2_MotionSideContainer->fn->setSize(Screen2_MotionSideContainer, 113, 260);
    Screen2_MotionSideContainer->fn->setScheme(Screen2_MotionSideContainer, &WhiteBackgroundScheme);
    Screen2_MotionSideContainer->fn->setBackgroundType(Screen2_MotionSideContainer, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionSideContainer->fn->setBorderType(Screen2_MotionSideContainer, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, (leWidget*)Screen2_MotionSideContainer);

    Screen2_MotionUpdateValue = leButtonWidget_New();
    Screen2_MotionUpdateValue->fn->setPosition(Screen2_MotionUpdateValue, 4, 39);
    Screen2_MotionUpdateValue->fn->setSize(Screen2_MotionUpdateValue, 105, 30);
    Screen2_MotionUpdateValue->fn->setBackgroundType(Screen2_MotionUpdateValue, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionUpdateValue->fn->setToggleable(Screen2_MotionUpdateValue, LE_TRUE);
    Screen2_MotionUpdateValue->fn->setString(Screen2_MotionUpdateValue, (leString*)&string_NumsLittle);
    Screen2_MotionSideContainer->fn->addChild(Screen2_MotionSideContainer, (leWidget*)Screen2_MotionUpdateValue);

    Screen2_MotionSizeUpButton = leButtonWidget_New();
    Screen2_MotionSizeUpButton->fn->setPosition(Screen2_MotionSizeUpButton, 57, 184);
    Screen2_MotionSizeUpButton->fn->setSize(Screen2_MotionSizeUpButton, 55, 30);
    Screen2_MotionSizeUpButton->fn->setBackgroundType(Screen2_MotionSizeUpButton, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionSizeUpButton->fn->setString(Screen2_MotionSizeUpButton, (leString*)&string_Plus);
    Screen2_MotionSizeUpButton->fn->setPressedEventCallback(Screen2_MotionSizeUpButton, event_Screen2_MotionSizeUpButton_OnPressed);
    Screen2_MotionSideContainer->fn->addChild(Screen2_MotionSideContainer, (leWidget*)Screen2_MotionSizeUpButton);

    Screen2_MotionSizeDownButton = leButtonWidget_New();
    Screen2_MotionSizeDownButton->fn->setPosition(Screen2_MotionSizeDownButton, 1, 184);
    Screen2_MotionSizeDownButton->fn->setSize(Screen2_MotionSizeDownButton, 55, 30);
    Screen2_MotionSizeDownButton->fn->setBackgroundType(Screen2_MotionSizeDownButton, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionSizeDownButton->fn->setString(Screen2_MotionSizeDownButton, (leString*)&string_Minus);
    Screen2_MotionSizeDownButton->fn->setPressedEventCallback(Screen2_MotionSizeDownButton, event_Screen2_MotionSizeDownButton_OnPressed);
    Screen2_MotionSideContainer->fn->addChild(Screen2_MotionSideContainer, (leWidget*)Screen2_MotionSizeDownButton);

    Screen2_MotionRectSizeValue = leLabelWidget_New();
    Screen2_MotionRectSizeValue->fn->setPosition(Screen2_MotionRectSizeValue, 44, 167);
    Screen2_MotionRectSizeValue->fn->setSize(Screen2_MotionRectSizeValue, 62, 16);
    Screen2_MotionRectSizeValue->fn->setBackgroundType(Screen2_MotionRectSizeValue, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionRectSizeValue->fn->setString(Screen2_MotionRectSizeValue, (leString*)&string_NumsTiny);
    Screen2_MotionSideContainer->fn->addChild(Screen2_MotionSideContainer, (leWidget*)Screen2_MotionRectSizeValue);

    Screen2_MotionRectSizeLabel = leLabelWidget_New();
    Screen2_MotionRectSizeLabel->fn->setPosition(Screen2_MotionRectSizeLabel, 2, 162);
    Screen2_MotionRectSizeLabel->fn->setSize(Screen2_MotionRectSizeLabel, 38, 22);
    Screen2_MotionRectSizeLabel->fn->setBackgroundType(Screen2_MotionRectSizeLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionRectSizeLabel->fn->setString(Screen2_MotionRectSizeLabel, (leString*)&string_Size);
    Screen2_MotionSideContainer->fn->addChild(Screen2_MotionSideContainer, (leWidget*)Screen2_MotionRectSizeLabel);

    Screen2_MotionRectCount = leLabelWidget_New();
    Screen2_MotionRectCount->fn->setPosition(Screen2_MotionRectCount, 44, 114);
    Screen2_MotionRectCount->fn->setSize(Screen2_MotionRectCount, 24, 16);
    Screen2_MotionRectCount->fn->setBackgroundType(Screen2_MotionRectCount, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionRectCount->fn->setString(Screen2_MotionRectCount, (leString*)&string_NumsTiny);
    Screen2_MotionSideContainer->fn->addChild(Screen2_MotionSideContainer, (leWidget*)Screen2_MotionRectCount);

    Screen2_MotionNumLabel = leLabelWidget_New();
    Screen2_MotionNumLabel->fn->setPosition(Screen2_MotionNumLabel, 2, 112);
    Screen2_MotionNumLabel->fn->setSize(Screen2_MotionNumLabel, 38, 19);
    Screen2_MotionNumLabel->fn->setBackgroundType(Screen2_MotionNumLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionNumLabel->fn->setString(Screen2_MotionNumLabel, (leString*)&string_RectanglesNum);
    Screen2_MotionSideContainer->fn->addChild(Screen2_MotionSideContainer, (leWidget*)Screen2_MotionNumLabel);

    Screen2_MotionPlusButton = leButtonWidget_New();
    Screen2_MotionPlusButton->fn->setPosition(Screen2_MotionPlusButton, 57, 133);
    Screen2_MotionPlusButton->fn->setSize(Screen2_MotionPlusButton, 55, 30);
    Screen2_MotionPlusButton->fn->setBackgroundType(Screen2_MotionPlusButton, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionPlusButton->fn->setString(Screen2_MotionPlusButton, (leString*)&string_Plus);
    Screen2_MotionPlusButton->fn->setPressedEventCallback(Screen2_MotionPlusButton, event_Screen2_MotionPlusButton_OnPressed);
    Screen2_MotionSideContainer->fn->addChild(Screen2_MotionSideContainer, (leWidget*)Screen2_MotionPlusButton);

    Screen2_MotionMinusButton = leButtonWidget_New();
    Screen2_MotionMinusButton->fn->setPosition(Screen2_MotionMinusButton, 1, 133);
    Screen2_MotionMinusButton->fn->setSize(Screen2_MotionMinusButton, 55, 30);
    Screen2_MotionMinusButton->fn->setBackgroundType(Screen2_MotionMinusButton, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionMinusButton->fn->setString(Screen2_MotionMinusButton, (leString*)&string_Minus);
    Screen2_MotionMinusButton->fn->setPressedEventCallback(Screen2_MotionMinusButton, event_Screen2_MotionMinusButton_OnPressed);
    Screen2_MotionSideContainer->fn->addChild(Screen2_MotionSideContainer, (leWidget*)Screen2_MotionMinusButton);

    Screen2_MotionNextButton = leButtonWidget_New();
    Screen2_MotionNextButton->fn->setPosition(Screen2_MotionNextButton, 57, 229);
    Screen2_MotionNextButton->fn->setSize(Screen2_MotionNextButton, 55, 30);
    Screen2_MotionNextButton->fn->setBackgroundType(Screen2_MotionNextButton, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionNextButton->fn->setString(Screen2_MotionNextButton, (leString*)&string_Next);
    Screen2_MotionNextButton->fn->setPressedEventCallback(Screen2_MotionNextButton, event_Screen2_MotionNextButton_OnPressed);
    Screen2_MotionSideContainer->fn->addChild(Screen2_MotionSideContainer, (leWidget*)Screen2_MotionNextButton);

    Screen2_MotionContainerTitle = leLabelWidget_New();
    Screen2_MotionContainerTitle->fn->setPosition(Screen2_MotionContainerTitle, 5, 1);
    Screen2_MotionContainerTitle->fn->setSize(Screen2_MotionContainerTitle, 103, 25);
    Screen2_MotionContainerTitle->fn->setBackgroundType(Screen2_MotionContainerTitle, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionContainerTitle->fn->setHAlignment(Screen2_MotionContainerTitle, LE_HALIGN_CENTER);
    Screen2_MotionContainerTitle->fn->setString(Screen2_MotionContainerTitle, (leString*)&string_MotionUpdates);
    Screen2_MotionSideContainer->fn->addChild(Screen2_MotionSideContainer, (leWidget*)Screen2_MotionContainerTitle);

    Screen2_MotionRefreshValue = leLabelWidget_New();
    Screen2_MotionRefreshValue->fn->setPosition(Screen2_MotionRefreshValue, 6, 88);
    Screen2_MotionRefreshValue->fn->setSize(Screen2_MotionRefreshValue, 101, 27);
    Screen2_MotionRefreshValue->fn->setBackgroundType(Screen2_MotionRefreshValue, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionRefreshValue->fn->setHAlignment(Screen2_MotionRefreshValue, LE_HALIGN_CENTER);
    Screen2_MotionRefreshValue->fn->setString(Screen2_MotionRefreshValue, (leString*)&string_NumsLittle);
    Screen2_MotionSideContainer->fn->addChild(Screen2_MotionSideContainer, (leWidget*)Screen2_MotionRefreshValue);

    Screen2_MotionRefreshLabel = leLabelWidget_New();
    Screen2_MotionRefreshLabel->fn->setPosition(Screen2_MotionRefreshLabel, 1, 69);
    Screen2_MotionRefreshLabel->fn->setSize(Screen2_MotionRefreshLabel, 108, 18);
    Screen2_MotionRefreshLabel->fn->setBackgroundType(Screen2_MotionRefreshLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionRefreshLabel->fn->setString(Screen2_MotionRefreshLabel, (leString*)&string_RefreshRate);
    Screen2_MotionSideContainer->fn->addChild(Screen2_MotionSideContainer, (leWidget*)Screen2_MotionRefreshLabel);

    Screen2_MotionUpdateLabel = leLabelWidget_New();
    Screen2_MotionUpdateLabel->fn->setPosition(Screen2_MotionUpdateLabel, 1, 22);
    Screen2_MotionUpdateLabel->fn->setSize(Screen2_MotionUpdateLabel, 108, 18);
    Screen2_MotionUpdateLabel->fn->setBackgroundType(Screen2_MotionUpdateLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen2_MotionUpdateLabel->fn->setString(Screen2_MotionUpdateLabel, (leString*)&string_FPS);
    Screen2_MotionSideContainer->fn->addChild(Screen2_MotionSideContainer, (leWidget*)Screen2_MotionUpdateLabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    Screen2_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen2()
{
    Screen2_OnUpdate(); // raise event
}

void screenHide_Screen2()
{
    Screen2_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen2_MotionBackground = NULL;
    Screen2_RectMotionWidget10 = NULL;
    Screen2_RectMotionWidget9 = NULL;
    Screen2_RectMotionWidget8 = NULL;
    Screen2_RectMotionWidget7 = NULL;
    Screen2_RectMotionWidget6 = NULL;
    Screen2_RectMotionWidget5 = NULL;
    Screen2_RectMotionWidget4 = NULL;
    Screen2_RectMotionWidget3 = NULL;
    Screen2_RectMotionWidget2 = NULL;
    Screen2_RectMotionWidget1 = NULL;
    Screen2_MotionSideContainer = NULL;
    Screen2_MotionUpdateValue = NULL;
    Screen2_MotionSizeUpButton = NULL;
    Screen2_MotionSizeDownButton = NULL;
    Screen2_MotionRectSizeValue = NULL;
    Screen2_MotionRectSizeLabel = NULL;
    Screen2_MotionRectCount = NULL;
    Screen2_MotionNumLabel = NULL;
    Screen2_MotionPlusButton = NULL;
    Screen2_MotionMinusButton = NULL;
    Screen2_MotionNextButton = NULL;
    Screen2_MotionContainerTitle = NULL;
    Screen2_MotionRefreshValue = NULL;
    Screen2_MotionRefreshLabel = NULL;
    Screen2_MotionUpdateLabel = NULL;

    string_NumsLarge.fn->destructor(&string_NumsLarge);
    string_NumsLittle.fn->destructor(&string_NumsLittle);
    string_Size.fn->destructor(&string_Size);
    string_Next.fn->destructor(&string_Next);
    string_DynamicString.fn->destructor(&string_DynamicString);
    string_Plus.fn->destructor(&string_Plus);
    string_Minus.fn->destructor(&string_Minus);
    string_RefreshRate.fn->destructor(&string_RefreshRate);
    string_FPS.fn->destructor(&string_FPS);
    string_NumsTiny.fn->destructor(&string_NumsTiny);
    string_RectanglesNum.fn->destructor(&string_RectanglesNum);
    string_MotionUpdates.fn->destructor(&string_MotionUpdates);


    showing = LE_FALSE;
}

void screenDestroy_Screen2()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen2(uint32_t lyrIdx)
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

