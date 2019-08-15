#include "gfx/legato/generated/screen/le_gen_screen_FPSMotion.h"

// widget list for layer 0
static leWidget* root0;

leWidget* MotionBackground;
leRectangleWidget* RectMotionWidget10;
leRectangleWidget* RectMotionWidget9;
leRectangleWidget* RectMotionWidget8;
leRectangleWidget* RectMotionWidget7;
leRectangleWidget* RectMotionWidget6;
leRectangleWidget* RectMotionWidget5;
leRectangleWidget* RectMotionWidget4;
leRectangleWidget* RectMotionWidget3;
leRectangleWidget* RectMotionWidget2;
leRectangleWidget* RectMotionWidget1;
leWidget* MotionSideContainer;
leLabelWidget* MotionUpdateLabel;
leLabelWidget* MotionRefreshLabel;
leLabelWidget* MotionRefreshValue;
leLabelWidget* MotionContainerTitle;
leButtonWidget* MotionNextButton;
leButtonWidget* MotionMinusButton;
leButtonWidget* MotionPlusButton;
leLabelWidget* MotionNumLabel;
leLabelWidget* MotionRectCount;
leLabelWidget* MotionRectSizeLabel;
leLabelWidget* MotionRectSizeValue;
leButtonWidget* MotionSizeDownButton;
leButtonWidget* MotionSizeUpButton;
leButtonWidget* MotionUpdateValue;

// string list for this screen
static leTableString tableString_FPS;
static leTableString tableString_RefreshRate;
static leTableString tableString_NumsLittle;
static leTableString tableString_MotionUpdates;
static leTableString tableString_Next;
static leTableString tableString_Minus;
static leTableString tableString_Plus;
static leTableString tableString_RectanglesNum;
static leTableString tableString_NumsTiny;
static leTableString tableString_Size;

static leBool showing = LE_FALSE;

leResult screenInit_FPSMotion()
{
    return LE_SUCCESS;
}

leResult screenShow_FPSMotion()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_FPS, string_FPS);
    leTableString_Constructor(&tableString_RefreshRate, string_RefreshRate);
    leTableString_Constructor(&tableString_NumsLittle, string_NumsLittle);
    leTableString_Constructor(&tableString_MotionUpdates, string_MotionUpdates);
    leTableString_Constructor(&tableString_Next, string_Next);
    leTableString_Constructor(&tableString_Minus, string_Minus);
    leTableString_Constructor(&tableString_Plus, string_Plus);
    leTableString_Constructor(&tableString_RectanglesNum, string_RectanglesNum);
    leTableString_Constructor(&tableString_NumsTiny, string_NumsTiny);
    leTableString_Constructor(&tableString_Size, string_Size);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 272);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    MotionBackground = leWidget_New();
    MotionBackground->fn->setPosition(MotionBackground, 0, 0);
    MotionBackground->fn->setSize(MotionBackground, 480, 272);
    MotionBackground->fn->setScheme(MotionBackground, &LightGreenBackgroundScheme);
    root0->fn->addChild(root0, MotionBackground);

    RectMotionWidget10 = leRectangleWidget_New();
    RectMotionWidget10->fn->setPosition(RectMotionWidget10, 314, 131);
    RectMotionWidget10->fn->setSize(RectMotionWidget10, 40, 40);
    RectMotionWidget10->fn->setScheme(RectMotionWidget10, &BrownFillScheme);
    RectMotionWidget10->fn->setThickness(RectMotionWidget10, 0);
    root0->fn->addChild(root0, (leWidget*)RectMotionWidget10);

    RectMotionWidget9 = leRectangleWidget_New();
    RectMotionWidget9->fn->setPosition(RectMotionWidget9, 178, 169);
    RectMotionWidget9->fn->setSize(RectMotionWidget9, 40, 40);
    RectMotionWidget9->fn->setScheme(RectMotionWidget9, &LightBlueFillScheme);
    RectMotionWidget9->fn->setThickness(RectMotionWidget9, 0);
    root0->fn->addChild(root0, (leWidget*)RectMotionWidget9);

    RectMotionWidget8 = leRectangleWidget_New();
    RectMotionWidget8->fn->setPosition(RectMotionWidget8, 193, 3);
    RectMotionWidget8->fn->setSize(RectMotionWidget8, 40, 40);
    RectMotionWidget8->fn->setScheme(RectMotionWidget8, &PurpleFillScheme);
    RectMotionWidget8->fn->setThickness(RectMotionWidget8, 0);
    root0->fn->addChild(root0, (leWidget*)RectMotionWidget8);

    RectMotionWidget7 = leRectangleWidget_New();
    RectMotionWidget7->fn->setPosition(RectMotionWidget7, 155, 70);
    RectMotionWidget7->fn->setSize(RectMotionWidget7, 40, 40);
    RectMotionWidget7->fn->setScheme(RectMotionWidget7, &PinkFillScheme);
    RectMotionWidget7->fn->setThickness(RectMotionWidget7, 0);
    root0->fn->addChild(root0, (leWidget*)RectMotionWidget7);

    RectMotionWidget6 = leRectangleWidget_New();
    RectMotionWidget6->fn->setPosition(RectMotionWidget6, 98, 24);
    RectMotionWidget6->fn->setSize(RectMotionWidget6, 40, 40);
    RectMotionWidget6->fn->setScheme(RectMotionWidget6, &OrangeFillScheme);
    RectMotionWidget6->fn->setThickness(RectMotionWidget6, 0);
    root0->fn->addChild(root0, (leWidget*)RectMotionWidget6);

    RectMotionWidget5 = leRectangleWidget_New();
    RectMotionWidget5->fn->setPosition(RectMotionWidget5, 197, 101);
    RectMotionWidget5->fn->setSize(RectMotionWidget5, 40, 40);
    RectMotionWidget5->fn->setScheme(RectMotionWidget5, &BlueFillScheme);
    RectMotionWidget5->fn->setThickness(RectMotionWidget5, 0);
    root0->fn->addChild(root0, (leWidget*)RectMotionWidget5);

    RectMotionWidget4 = leRectangleWidget_New();
    RectMotionWidget4->fn->setPosition(RectMotionWidget4, 264, 79);
    RectMotionWidget4->fn->setSize(RectMotionWidget4, 40, 40);
    RectMotionWidget4->fn->setScheme(RectMotionWidget4, &YellowFillScheme);
    RectMotionWidget4->fn->setThickness(RectMotionWidget4, 0);
    root0->fn->addChild(root0, (leWidget*)RectMotionWidget4);

    RectMotionWidget3 = leRectangleWidget_New();
    RectMotionWidget3->fn->setPosition(RectMotionWidget3, 84, 185);
    RectMotionWidget3->fn->setSize(RectMotionWidget3, 40, 40);
    RectMotionWidget3->fn->setScheme(RectMotionWidget3, &WhiteFillScheme);
    RectMotionWidget3->fn->setThickness(RectMotionWidget3, 0);
    root0->fn->addChild(root0, (leWidget*)RectMotionWidget3);

    RectMotionWidget2 = leRectangleWidget_New();
    RectMotionWidget2->fn->setPosition(RectMotionWidget2, 286, 206);
    RectMotionWidget2->fn->setSize(RectMotionWidget2, 40, 40);
    RectMotionWidget2->fn->setScheme(RectMotionWidget2, &RedFillScheme);
    RectMotionWidget2->fn->setThickness(RectMotionWidget2, 0);
    root0->fn->addChild(root0, (leWidget*)RectMotionWidget2);

    RectMotionWidget1 = leRectangleWidget_New();
    RectMotionWidget1->fn->setPosition(RectMotionWidget1, 9, 118);
    RectMotionWidget1->fn->setSize(RectMotionWidget1, 40, 40);
    RectMotionWidget1->fn->setScheme(RectMotionWidget1, &LightPinkFillScheme);
    RectMotionWidget1->fn->setThickness(RectMotionWidget1, 0);
    root0->fn->addChild(root0, (leWidget*)RectMotionWidget1);

    MotionSideContainer = leWidget_New();
    MotionSideContainer->fn->setPosition(MotionSideContainer, 359, 8);
    MotionSideContainer->fn->setSize(MotionSideContainer, 113, 260);
    MotionSideContainer->fn->setScheme(MotionSideContainer, &WhiteBackgroundScheme);
    MotionSideContainer->fn->setBackgroundType(MotionSideContainer, LE_WIDGET_BACKGROUND_NONE);
    MotionSideContainer->fn->setBorderType(MotionSideContainer, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, MotionSideContainer);

    MotionUpdateLabel = leLabelWidget_New();
    MotionUpdateLabel->fn->setPosition(MotionUpdateLabel, 1, 22);
    MotionUpdateLabel->fn->setSize(MotionUpdateLabel, 108, 18);
    MotionUpdateLabel->fn->setBackgroundType(MotionUpdateLabel, LE_WIDGET_BACKGROUND_NONE);
    MotionUpdateLabel->fn->setString(MotionUpdateLabel, (leString*)&tableString_FPS);
    MotionSideContainer->fn->addChild(MotionSideContainer, (leWidget*)MotionUpdateLabel);

    MotionRefreshLabel = leLabelWidget_New();
    MotionRefreshLabel->fn->setPosition(MotionRefreshLabel, 1, 69);
    MotionRefreshLabel->fn->setSize(MotionRefreshLabel, 108, 18);
    MotionRefreshLabel->fn->setBackgroundType(MotionRefreshLabel, LE_WIDGET_BACKGROUND_NONE);
    MotionRefreshLabel->fn->setString(MotionRefreshLabel, (leString*)&tableString_RefreshRate);
    MotionSideContainer->fn->addChild(MotionSideContainer, (leWidget*)MotionRefreshLabel);

    MotionRefreshValue = leLabelWidget_New();
    MotionRefreshValue->fn->setPosition(MotionRefreshValue, 6, 88);
    MotionRefreshValue->fn->setSize(MotionRefreshValue, 101, 27);
    MotionRefreshValue->fn->setBackgroundType(MotionRefreshValue, LE_WIDGET_BACKGROUND_NONE);
    MotionRefreshValue->fn->setHAlignment(MotionRefreshValue, LE_HALIGN_CENTER);
    MotionRefreshValue->fn->setString(MotionRefreshValue, (leString*)&tableString_NumsLittle);
    MotionSideContainer->fn->addChild(MotionSideContainer, (leWidget*)MotionRefreshValue);

    MotionContainerTitle = leLabelWidget_New();
    MotionContainerTitle->fn->setPosition(MotionContainerTitle, 5, 1);
    MotionContainerTitle->fn->setSize(MotionContainerTitle, 103, 25);
    MotionContainerTitle->fn->setBackgroundType(MotionContainerTitle, LE_WIDGET_BACKGROUND_NONE);
    MotionContainerTitle->fn->setHAlignment(MotionContainerTitle, LE_HALIGN_CENTER);
    MotionContainerTitle->fn->setString(MotionContainerTitle, (leString*)&tableString_MotionUpdates);
    MotionSideContainer->fn->addChild(MotionSideContainer, (leWidget*)MotionContainerTitle);

    MotionNextButton = leButtonWidget_New();
    MotionNextButton->fn->setPosition(MotionNextButton, 57, 229);
    MotionNextButton->fn->setSize(MotionNextButton, 55, 30);
    MotionNextButton->fn->setBackgroundType(MotionNextButton, LE_WIDGET_BACKGROUND_NONE);
    MotionNextButton->fn->setString(MotionNextButton, (leString*)&tableString_Next);
    MotionNextButton->fn->setPressedEventCallback(MotionNextButton, MotionNextButton_OnPressed);
    MotionSideContainer->fn->addChild(MotionSideContainer, (leWidget*)MotionNextButton);

    MotionMinusButton = leButtonWidget_New();
    MotionMinusButton->fn->setPosition(MotionMinusButton, 1, 133);
    MotionMinusButton->fn->setSize(MotionMinusButton, 55, 30);
    MotionMinusButton->fn->setBackgroundType(MotionMinusButton, LE_WIDGET_BACKGROUND_NONE);
    MotionMinusButton->fn->setString(MotionMinusButton, (leString*)&tableString_Minus);
    MotionMinusButton->fn->setPressedEventCallback(MotionMinusButton, MotionMinusButton_OnPressed);
    MotionSideContainer->fn->addChild(MotionSideContainer, (leWidget*)MotionMinusButton);

    MotionPlusButton = leButtonWidget_New();
    MotionPlusButton->fn->setPosition(MotionPlusButton, 57, 133);
    MotionPlusButton->fn->setSize(MotionPlusButton, 55, 30);
    MotionPlusButton->fn->setBackgroundType(MotionPlusButton, LE_WIDGET_BACKGROUND_NONE);
    MotionPlusButton->fn->setString(MotionPlusButton, (leString*)&tableString_Plus);
    MotionPlusButton->fn->setPressedEventCallback(MotionPlusButton, MotionPlusButton_OnPressed);
    MotionSideContainer->fn->addChild(MotionSideContainer, (leWidget*)MotionPlusButton);

    MotionNumLabel = leLabelWidget_New();
    MotionNumLabel->fn->setPosition(MotionNumLabel, 2, 112);
    MotionNumLabel->fn->setSize(MotionNumLabel, 38, 19);
    MotionNumLabel->fn->setBackgroundType(MotionNumLabel, LE_WIDGET_BACKGROUND_NONE);
    MotionNumLabel->fn->setString(MotionNumLabel, (leString*)&tableString_RectanglesNum);
    MotionSideContainer->fn->addChild(MotionSideContainer, (leWidget*)MotionNumLabel);

    MotionRectCount = leLabelWidget_New();
    MotionRectCount->fn->setPosition(MotionRectCount, 44, 114);
    MotionRectCount->fn->setSize(MotionRectCount, 24, 16);
    MotionRectCount->fn->setBackgroundType(MotionRectCount, LE_WIDGET_BACKGROUND_NONE);
    MotionRectCount->fn->setString(MotionRectCount, (leString*)&tableString_NumsTiny);
    MotionSideContainer->fn->addChild(MotionSideContainer, (leWidget*)MotionRectCount);

    MotionRectSizeLabel = leLabelWidget_New();
    MotionRectSizeLabel->fn->setPosition(MotionRectSizeLabel, 2, 162);
    MotionRectSizeLabel->fn->setSize(MotionRectSizeLabel, 38, 22);
    MotionRectSizeLabel->fn->setBackgroundType(MotionRectSizeLabel, LE_WIDGET_BACKGROUND_NONE);
    MotionRectSizeLabel->fn->setString(MotionRectSizeLabel, (leString*)&tableString_Size);
    MotionSideContainer->fn->addChild(MotionSideContainer, (leWidget*)MotionRectSizeLabel);

    MotionRectSizeValue = leLabelWidget_New();
    MotionRectSizeValue->fn->setPosition(MotionRectSizeValue, 44, 167);
    MotionRectSizeValue->fn->setSize(MotionRectSizeValue, 62, 16);
    MotionRectSizeValue->fn->setBackgroundType(MotionRectSizeValue, LE_WIDGET_BACKGROUND_NONE);
    MotionRectSizeValue->fn->setString(MotionRectSizeValue, (leString*)&tableString_NumsTiny);
    MotionSideContainer->fn->addChild(MotionSideContainer, (leWidget*)MotionRectSizeValue);

    MotionSizeDownButton = leButtonWidget_New();
    MotionSizeDownButton->fn->setPosition(MotionSizeDownButton, 1, 184);
    MotionSizeDownButton->fn->setSize(MotionSizeDownButton, 55, 30);
    MotionSizeDownButton->fn->setBackgroundType(MotionSizeDownButton, LE_WIDGET_BACKGROUND_NONE);
    MotionSizeDownButton->fn->setString(MotionSizeDownButton, (leString*)&tableString_Minus);
    MotionSizeDownButton->fn->setPressedEventCallback(MotionSizeDownButton, MotionSizeDownButton_OnPressed);
    MotionSideContainer->fn->addChild(MotionSideContainer, (leWidget*)MotionSizeDownButton);

    MotionSizeUpButton = leButtonWidget_New();
    MotionSizeUpButton->fn->setPosition(MotionSizeUpButton, 57, 184);
    MotionSizeUpButton->fn->setSize(MotionSizeUpButton, 55, 30);
    MotionSizeUpButton->fn->setBackgroundType(MotionSizeUpButton, LE_WIDGET_BACKGROUND_NONE);
    MotionSizeUpButton->fn->setString(MotionSizeUpButton, (leString*)&tableString_Plus);
    MotionSizeUpButton->fn->setPressedEventCallback(MotionSizeUpButton, MotionSizeUpButton_OnPressed);
    MotionSideContainer->fn->addChild(MotionSideContainer, (leWidget*)MotionSizeUpButton);

    MotionUpdateValue = leButtonWidget_New();
    MotionUpdateValue->fn->setPosition(MotionUpdateValue, 4, 39);
    MotionUpdateValue->fn->setSize(MotionUpdateValue, 105, 30);
    MotionUpdateValue->fn->setBackgroundType(MotionUpdateValue, LE_WIDGET_BACKGROUND_NONE);
    MotionUpdateValue->fn->setToggleable(MotionUpdateValue, LE_TRUE);
    MotionUpdateValue->fn->setString(MotionUpdateValue, (leString*)&tableString_NumsLittle);
    MotionSideContainer->fn->addChild(MotionSideContainer, (leWidget*)MotionUpdateValue);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    FPSMotion_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_FPSMotion()
{
    FPSMotion_OnUpdate();
}

void screenHide_FPSMotion()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    MotionBackground = NULL;
    RectMotionWidget10 = NULL;
    RectMotionWidget9 = NULL;
    RectMotionWidget8 = NULL;
    RectMotionWidget7 = NULL;
    RectMotionWidget6 = NULL;
    RectMotionWidget5 = NULL;
    RectMotionWidget4 = NULL;
    RectMotionWidget3 = NULL;
    RectMotionWidget2 = NULL;
    RectMotionWidget1 = NULL;
    MotionSideContainer = NULL;
    MotionUpdateLabel = NULL;
    MotionRefreshLabel = NULL;
    MotionRefreshValue = NULL;
    MotionContainerTitle = NULL;
    MotionNextButton = NULL;
    MotionMinusButton = NULL;
    MotionPlusButton = NULL;
    MotionNumLabel = NULL;
    MotionRectCount = NULL;
    MotionRectSizeLabel = NULL;
    MotionRectSizeValue = NULL;
    MotionSizeDownButton = NULL;
    MotionSizeUpButton = NULL;
    MotionUpdateValue = NULL;

    tableString_FPS.fn->destructor(&tableString_FPS);
    tableString_RefreshRate.fn->destructor(&tableString_RefreshRate);
    tableString_NumsLittle.fn->destructor(&tableString_NumsLittle);
    tableString_MotionUpdates.fn->destructor(&tableString_MotionUpdates);
    tableString_Next.fn->destructor(&tableString_Next);
    tableString_Minus.fn->destructor(&tableString_Minus);
    tableString_Plus.fn->destructor(&tableString_Plus);
    tableString_RectanglesNum.fn->destructor(&tableString_RectanglesNum);
    tableString_NumsTiny.fn->destructor(&tableString_NumsTiny);
    tableString_Size.fn->destructor(&tableString_Size);
    showing = LE_FALSE;

    FPSMotion_OnHide();
}

void screenDestroy_FPSMotion()
{

}

leWidget* screenGetRoot_FPSMotion(uint32_t lyrIdx)
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

