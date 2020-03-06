// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#include "gfx/legato/generated/screen/le_gen_screen_MainMenu.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget1;
leImageWidget* ImageWidget1;
leWidget* PanelWidget3;
leListWheelWidget* ListWheelWidget2;
leWidget* MainPanel;
leButtonWidget* BakeButton;
leButtonWidget* CookButton;
leButtonWidget* BroilButton;
leButtonWidget* ReheatButton;
leImageWidget* ImageWidget2;
leImageWidget* ImageWidget3;
leImageWidget* ImageWidget4;
leWidget* Badge;
leLabelWidget* LabelWidget0;
leLabelWidget* LabelWidget3;
leLabelWidget* LabelWidget1;
leWidget* ClockPanel;
leLabelWidget* MinuteLabel;
leLabelWidget* ColonLabel;
leImageWidget* ImageWidget6;
leLabelWidget* HourLabel;
leImageWidget* ImageWidget8;
leWidget* PanelWidget0;
leImageWidget* ImageWidget0;
leRectangleWidget* RectangleWidget0;
leRectangleWidget* RectangleWidget1;
leRectangleWidget* RectangleWidget2;
leRectangleWidget* RectangleWidget3;
leImageWidget* ModeImageWidget;
leLabelWidget* CookTimeLabel;
leProgressBarWidget* ProgressBarWidget0;
leButtonWidget* CancelButton;
leButtonWidget* RestartButton;
leButtonWidget* SliderButton0;
leButtonWidget* ButtonWidget0;
leImageWidget* ImageWidget9;
leButtonWidget* DemoModeOnButton;

// string list for this screen
static leTableString tableString_Hotdog;
static leTableString tableString_Kabobs;
static leTableString tableString_Steak;
static leTableString tableString_Bacon;
static leTableString tableString_Vegetables;
static leTableString tableString_GoodBytes;
static leTableString tableString_Bytes;
static leTableString tableString_SmartCooker;
static leTableString tableString_DefaultMinute;
static leTableString tableString_Colon;
static leTableString tableString_DefaultHour;
static leTableString tableString_DefaultCookTime;

static leBool showing = LE_FALSE;

leResult screenInit_MainMenu()
{
    return LE_SUCCESS;
}

leResult screenShow_MainMenu()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_Hotdog, string_Hotdog);
    leTableString_Constructor(&tableString_Kabobs, string_Kabobs);
    leTableString_Constructor(&tableString_Steak, string_Steak);
    leTableString_Constructor(&tableString_Bacon, string_Bacon);
    leTableString_Constructor(&tableString_Vegetables, string_Vegetables);
    leTableString_Constructor(&tableString_GoodBytes, string_GoodBytes);
    leTableString_Constructor(&tableString_Bytes, string_Bytes);
    leTableString_Constructor(&tableString_SmartCooker, string_SmartCooker);
    leTableString_Constructor(&tableString_DefaultMinute, string_DefaultMinute);
    leTableString_Constructor(&tableString_Colon, string_Colon);
    leTableString_Constructor(&tableString_DefaultHour, string_DefaultHour);
    leTableString_Constructor(&tableString_DefaultCookTime, string_DefaultCookTime);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget1 = leWidget_New();
    PanelWidget1->fn->setPosition(PanelWidget1, 0, 0);
    PanelWidget1->fn->setSize(PanelWidget1, 480, 320);
    PanelWidget1->fn->setScheme(PanelWidget1, &BlackBackground);
    root0->fn->addChild(root0, PanelWidget1);

    ImageWidget1 = leImageWidget_New();
    ImageWidget1->fn->setPosition(ImageWidget1, 6, 111);
    ImageWidget1->fn->setSize(ImageWidget1, 105, 200);
    ImageWidget1->fn->setBackgroundType(ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget1->fn->setHAlignment(ImageWidget1, LE_HALIGN_LEFT);
    ImageWidget1->fn->setImage(ImageWidget1, &smartstart2);
    root0->fn->addChild(root0, (leWidget*)ImageWidget1);

    PanelWidget3 = leWidget_New();
    PanelWidget3->fn->setPosition(PanelWidget3, 110, 124);
    PanelWidget3->fn->setSize(PanelWidget3, 116, 172);
    PanelWidget3->fn->setBackgroundType(PanelWidget3, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, PanelWidget3);

    ListWheelWidget2 = leListWheelWidget_New();
    ListWheelWidget2->fn->setPosition(ListWheelWidget2, 0, 1);
    ListWheelWidget2->fn->setSize(ListWheelWidget2, 115, 170);
    ListWheelWidget2->fn->setScheme(ListWheelWidget2, &ListWheelScheme);
    ListWheelWidget2->fn->setBackgroundType(ListWheelWidget2, LE_WIDGET_BACKGROUND_NONE);
    ListWheelWidget2->fn->setBorderType(ListWheelWidget2, LE_WIDGET_BORDER_NONE);
    ListWheelWidget2->fn->appendItem(ListWheelWidget2);
    ListWheelWidget2->fn->setItemString(ListWheelWidget2, 0, (leString*)&tableString_Hotdog);
    ListWheelWidget2->fn->appendItem(ListWheelWidget2);
    ListWheelWidget2->fn->setItemString(ListWheelWidget2, 1, (leString*)&tableString_Kabobs);
    ListWheelWidget2->fn->appendItem(ListWheelWidget2);
    ListWheelWidget2->fn->setItemString(ListWheelWidget2, 2, (leString*)&tableString_Steak);
    ListWheelWidget2->fn->appendItem(ListWheelWidget2);
    ListWheelWidget2->fn->setItemString(ListWheelWidget2, 3, (leString*)&tableString_Bacon);
    ListWheelWidget2->fn->appendItem(ListWheelWidget2);
    ListWheelWidget2->fn->setItemString(ListWheelWidget2, 4, (leString*)&tableString_Vegetables);
    ListWheelWidget2->fn->setIconMargin(ListWheelWidget2, 5);
    ListWheelWidget2->fn->setShaded(ListWheelWidget2, LE_FALSE);
    ListWheelWidget2->fn->setShaded(ListWheelWidget2, LE_FALSE);
    ListWheelWidget2->fn->setShowIndicators(ListWheelWidget2, LE_FALSE);
    ListWheelWidget2->fn->setSelectedItemChangedEventCallback(ListWheelWidget2, ListWheelWidget2_OnSelectionChanged);
    PanelWidget3->fn->addChild(PanelWidget3, (leWidget*)ListWheelWidget2);

    MainPanel = leWidget_New();
    MainPanel->fn->setPosition(MainPanel, 264, 102);
    MainPanel->fn->setSize(MainPanel, 207, 210);
    MainPanel->fn->setBackgroundType(MainPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, MainPanel);

    BakeButton = leButtonWidget_New();
    BakeButton->fn->setPosition(BakeButton, 9, 106);
    BakeButton->fn->setSize(BakeButton, 100, 100);
    BakeButton->fn->setScheme(BakeButton, &SquareButtonScheme);
    BakeButton->fn->setBackgroundType(BakeButton, LE_WIDGET_BACKGROUND_NONE);
    BakeButton->fn->setBorderType(BakeButton, LE_WIDGET_BORDER_NONE);
    BakeButton->fn->setPressedImage(BakeButton, &bake100);
    BakeButton->fn->setReleasedImage(BakeButton, &bake100);
    BakeButton->fn->setImagePosition(BakeButton, LE_RELATIVE_POSITION_ABOVE);
    BakeButton->fn->setReleasedEventCallback(BakeButton, BakeButton_OnReleased);
    MainPanel->fn->addChild(MainPanel, (leWidget*)BakeButton);

    CookButton = leButtonWidget_New();
    CookButton->fn->setPosition(CookButton, 9, 5);
    CookButton->fn->setSize(CookButton, 100, 100);
    CookButton->fn->setBackgroundType(CookButton, LE_WIDGET_BACKGROUND_NONE);
    CookButton->fn->setBorderType(CookButton, LE_WIDGET_BORDER_NONE);
    CookButton->fn->setPressedImage(CookButton, &cook100);
    CookButton->fn->setReleasedImage(CookButton, &cook100);
    CookButton->fn->setReleasedEventCallback(CookButton, CookButton_OnReleased);
    MainPanel->fn->addChild(MainPanel, (leWidget*)CookButton);

    BroilButton = leButtonWidget_New();
    BroilButton->fn->setPosition(BroilButton, 108, 106);
    BroilButton->fn->setSize(BroilButton, 100, 100);
    BroilButton->fn->setBackgroundType(BroilButton, LE_WIDGET_BACKGROUND_NONE);
    BroilButton->fn->setBorderType(BroilButton, LE_WIDGET_BORDER_NONE);
    BroilButton->fn->setPressedImage(BroilButton, &broil100);
    BroilButton->fn->setReleasedImage(BroilButton, &broil100);
    BroilButton->fn->setReleasedEventCallback(BroilButton, BroilButton_OnReleased);
    MainPanel->fn->addChild(MainPanel, (leWidget*)BroilButton);

    ReheatButton = leButtonWidget_New();
    ReheatButton->fn->setPosition(ReheatButton, 108, 5);
    ReheatButton->fn->setSize(ReheatButton, 100, 100);
    ReheatButton->fn->setBackgroundType(ReheatButton, LE_WIDGET_BACKGROUND_NONE);
    ReheatButton->fn->setBorderType(ReheatButton, LE_WIDGET_BORDER_NONE);
    ReheatButton->fn->setPressedImage(ReheatButton, &reheat100);
    ReheatButton->fn->setReleasedImage(ReheatButton, &reheat100);
    ReheatButton->fn->setReleasedEventCallback(ReheatButton, ReheatButton_OnReleased);
    MainPanel->fn->addChild(MainPanel, (leWidget*)ReheatButton);

    ImageWidget2 = leImageWidget_New();
    ImageWidget2->fn->setPosition(ImageWidget2, 228, 110);
    ImageWidget2->fn->setSize(ImageWidget2, 22, 200);
    ImageWidget2->fn->setBackgroundType(ImageWidget2, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget2->fn->setHAlignment(ImageWidget2, LE_HALIGN_RIGHT);
    ImageWidget2->fn->setImage(ImageWidget2, &smartstart2);
    root0->fn->addChild(root0, (leWidget*)ImageWidget2);

    ImageWidget3 = leImageWidget_New();
    ImageWidget3->fn->setPosition(ImageWidget3, 110, 111);
    ImageWidget3->fn->setSize(ImageWidget3, 141, 12);
    ImageWidget3->fn->setBackgroundType(ImageWidget3, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget3->fn->setHAlignment(ImageWidget3, LE_HALIGN_RIGHT);
    ImageWidget3->fn->setVAlignment(ImageWidget3, LE_VALIGN_TOP);
    ImageWidget3->fn->setMargins(ImageWidget3, 4, 0, 4, 0);
    ImageWidget3->fn->setImage(ImageWidget3, &smartstart2);
    root0->fn->addChild(root0, (leWidget*)ImageWidget3);

    ImageWidget4 = leImageWidget_New();
    ImageWidget4->fn->setPosition(ImageWidget4, 109, 299);
    ImageWidget4->fn->setSize(ImageWidget4, 139, 12);
    ImageWidget4->fn->setBackgroundType(ImageWidget4, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget4->fn->setHAlignment(ImageWidget4, LE_HALIGN_RIGHT);
    ImageWidget4->fn->setVAlignment(ImageWidget4, LE_VALIGN_BOTTOM);
    ImageWidget4->fn->setMargins(ImageWidget4, 4, 0, 4, 0);
    ImageWidget4->fn->setImage(ImageWidget4, &smartstart2);
    root0->fn->addChild(root0, (leWidget*)ImageWidget4);

    Badge = leWidget_New();
    Badge->fn->setPosition(Badge, 18, 38);
    Badge->fn->setSize(Badge, 225, 54);
    Badge->fn->setBackgroundType(Badge, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, Badge);

    LabelWidget0 = leLabelWidget_New();
    LabelWidget0->fn->setPosition(LabelWidget0, 3, -1);
    LabelWidget0->fn->setSize(LabelWidget0, 75, 30);
    LabelWidget0->fn->setScheme(LabelWidget0, &WhiteTextScheme);
    LabelWidget0->fn->setBackgroundType(LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget0->fn->setString(LabelWidget0, (leString*)&tableString_GoodBytes);
    Badge->fn->addChild(Badge, (leWidget*)LabelWidget0);

    LabelWidget3 = leLabelWidget_New();
    LabelWidget3->fn->setPosition(LabelWidget3, 75, 1);
    LabelWidget3->fn->setSize(LabelWidget3, 72, 30);
    LabelWidget3->fn->setScheme(LabelWidget3, &BlackTextScheme);
    LabelWidget3->fn->setMargins(LabelWidget3, 4, 0, 4, 0);
    LabelWidget3->fn->setString(LabelWidget3, (leString*)&tableString_Bytes);
    Badge->fn->addChild(Badge, (leWidget*)LabelWidget3);

    LabelWidget1 = leLabelWidget_New();
    LabelWidget1->fn->setPosition(LabelWidget1, 87, 31);
    LabelWidget1->fn->setSize(LabelWidget1, 125, 23);
    LabelWidget1->fn->setScheme(LabelWidget1, &WhiteTextScheme);
    LabelWidget1->fn->setBackgroundType(LabelWidget1, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget1->fn->setHAlignment(LabelWidget1, LE_HALIGN_RIGHT);
    LabelWidget1->fn->setString(LabelWidget1, (leString*)&tableString_SmartCooker);
    Badge->fn->addChild(Badge, (leWidget*)LabelWidget1);

    ClockPanel = leWidget_New();
    ClockPanel->fn->setPosition(ClockPanel, 271, 23);
    ClockPanel->fn->setSize(ClockPanel, 224, 70);
    ClockPanel->fn->setBackgroundType(ClockPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, ClockPanel);

    MinuteLabel = leLabelWidget_New();
    MinuteLabel->fn->setPosition(MinuteLabel, 115, 2);
    MinuteLabel->fn->setSize(MinuteLabel, 88, 75);
    MinuteLabel->fn->setScheme(MinuteLabel, &WhiteTextScheme);
    MinuteLabel->fn->setBackgroundType(MinuteLabel, LE_WIDGET_BACKGROUND_NONE);
    MinuteLabel->fn->setString(MinuteLabel, (leString*)&tableString_DefaultMinute);
    ClockPanel->fn->addChild(ClockPanel, (leWidget*)MinuteLabel);

    ColonLabel = leLabelWidget_New();
    ColonLabel->fn->setPosition(ColonLabel, 98, 6);
    ColonLabel->fn->setSize(ColonLabel, 23, 57);
    ColonLabel->fn->setScheme(ColonLabel, &WhiteTextScheme);
    ColonLabel->fn->setBackgroundType(ColonLabel, LE_WIDGET_BACKGROUND_NONE);
    ColonLabel->fn->setString(ColonLabel, (leString*)&tableString_Colon);
    ClockPanel->fn->addChild(ClockPanel, (leWidget*)ColonLabel);

    ImageWidget6 = leImageWidget_New();
    ImageWidget6->fn->setPosition(ImageWidget6, 0, 36);
    ImageWidget6->fn->setSize(ImageWidget6, 28, 24);
    ImageWidget6->fn->setBackgroundType(ImageWidget6, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget6->fn->setImage(ImageWidget6, &time30);
    ClockPanel->fn->addChild(ClockPanel, (leWidget*)ImageWidget6);

    HourLabel = leLabelWidget_New();
    HourLabel->fn->setPosition(HourLabel, 21, 1);
    HourLabel->fn->setSize(HourLabel, 90, 75);
    HourLabel->fn->setScheme(HourLabel, &WhiteTextScheme);
    HourLabel->fn->setBackgroundType(HourLabel, LE_WIDGET_BACKGROUND_NONE);
    HourLabel->fn->setHAlignment(HourLabel, LE_HALIGN_CENTER);
    HourLabel->fn->setString(HourLabel, (leString*)&tableString_DefaultHour);
    ClockPanel->fn->addChild(ClockPanel, (leWidget*)HourLabel);

    ImageWidget8 = leImageWidget_New();
    ImageWidget8->fn->setPosition(ImageWidget8, 20, 193);
    ImageWidget8->fn->setSize(ImageWidget8, 80, 80);
    ImageWidget8->fn->setScheme(ImageWidget8, &BlackBackground);
    ImageWidget8->fn->setImage(ImageWidget8, &hotdog70);
    root0->fn->addChild(root0, (leWidget*)ImageWidget8);

    PanelWidget0 = leWidget_New();
    PanelWidget0->fn->setPosition(PanelWidget0, 480, 102);
    PanelWidget0->fn->setSize(PanelWidget0, 480, 218);
    PanelWidget0->fn->setScheme(PanelWidget0, &BlackBackground);
    root0->fn->addChild(root0, PanelWidget0);

    ImageWidget0 = leImageWidget_New();
    ImageWidget0->fn->setPosition(ImageWidget0, 30, 0);
    ImageWidget0->fn->setSize(ImageWidget0, 415, 218);
    ImageWidget0->fn->setScheme(ImageWidget0, &BlackBackground);
    ImageWidget0->fn->setBackgroundType(ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget0->fn->setImage(ImageWidget0, &main_rect);
    PanelWidget0->fn->addChild(PanelWidget0, (leWidget*)ImageWidget0);

    RectangleWidget0 = leRectangleWidget_New();
    RectangleWidget0->fn->setPosition(RectangleWidget0, 66, 8);
    RectangleWidget0->fn->setSize(RectangleWidget0, 340, 9);
    RectangleWidget0->fn->setVisible(RectangleWidget0, LE_FALSE);
    RectangleWidget0->fn->setScheme(RectangleWidget0, &BlackBackground);
    RectangleWidget0->fn->setThickness(RectangleWidget0, 0);
    PanelWidget0->fn->addChild(PanelWidget0, (leWidget*)RectangleWidget0);

    RectangleWidget1 = leRectangleWidget_New();
    RectangleWidget1->fn->setPosition(RectangleWidget1, 66, 199);
    RectangleWidget1->fn->setSize(RectangleWidget1, 340, 9);
    RectangleWidget1->fn->setVisible(RectangleWidget1, LE_FALSE);
    RectangleWidget1->fn->setScheme(RectangleWidget1, &BlackBackground);
    RectangleWidget1->fn->setThickness(RectangleWidget1, 0);
    PanelWidget0->fn->addChild(PanelWidget0, (leWidget*)RectangleWidget1);

    RectangleWidget2 = leRectangleWidget_New();
    RectangleWidget2->fn->setPosition(RectangleWidget2, 406, 8);
    RectangleWidget2->fn->setSize(RectangleWidget2, 33, 200);
    RectangleWidget2->fn->setVisible(RectangleWidget2, LE_FALSE);
    RectangleWidget2->fn->setScheme(RectangleWidget2, &BlackBackground);
    RectangleWidget2->fn->setThickness(RectangleWidget2, 0);
    PanelWidget0->fn->addChild(PanelWidget0, (leWidget*)RectangleWidget2);

    RectangleWidget3 = leRectangleWidget_New();
    RectangleWidget3->fn->setPosition(RectangleWidget3, 36, 8);
    RectangleWidget3->fn->setSize(RectangleWidget3, 30, 200);
    RectangleWidget3->fn->setVisible(RectangleWidget3, LE_FALSE);
    RectangleWidget3->fn->setScheme(RectangleWidget3, &BlackBackground);
    RectangleWidget3->fn->setThickness(RectangleWidget3, 0);
    PanelWidget0->fn->addChild(PanelWidget0, (leWidget*)RectangleWidget3);

    ModeImageWidget = leImageWidget_New();
    ModeImageWidget->fn->setPosition(ModeImageWidget, 0, 62);
    ModeImageWidget->fn->setScheme(ModeImageWidget, &BlackBackground);
    ModeImageWidget->fn->setImage(ModeImageWidget, &reheat100);
    PanelWidget0->fn->addChild(PanelWidget0, (leWidget*)ModeImageWidget);

    CookTimeLabel = leLabelWidget_New();
    CookTimeLabel->fn->setPosition(CookTimeLabel, 149, 29);
    CookTimeLabel->fn->setSize(CookTimeLabel, 189, 64);
    CookTimeLabel->fn->setScheme(CookTimeLabel, &WhiteTextScheme);
    CookTimeLabel->fn->setBackgroundType(CookTimeLabel, LE_WIDGET_BACKGROUND_NONE);
    CookTimeLabel->fn->setHAlignment(CookTimeLabel, LE_HALIGN_CENTER);
    CookTimeLabel->fn->setString(CookTimeLabel, (leString*)&tableString_DefaultCookTime);
    PanelWidget0->fn->addChild(PanelWidget0, (leWidget*)CookTimeLabel);

    ProgressBarWidget0 = leProgressBarWidget_New();
    ProgressBarWidget0->fn->setPosition(ProgressBarWidget0, 106, 117);
    ProgressBarWidget0->fn->setSize(ProgressBarWidget0, 276, 15);
    ProgressBarWidget0->fn->setScheme(ProgressBarWidget0, &ProgressBarScheme);
    ProgressBarWidget0->fn->setBorderType(ProgressBarWidget0, LE_WIDGET_BORDER_NONE);
    ProgressBarWidget0->fn->setValue(ProgressBarWidget0, 50);
    PanelWidget0->fn->addChild(PanelWidget0, (leWidget*)ProgressBarWidget0);

    CancelButton = leButtonWidget_New();
    CancelButton->fn->setPosition(CancelButton, 377, 69);
    CancelButton->fn->setSize(CancelButton, 100, 100);
    CancelButton->fn->setBackgroundType(CancelButton, LE_WIDGET_BACKGROUND_NONE);
    CancelButton->fn->setBorderType(CancelButton, LE_WIDGET_BORDER_NONE);
    CancelButton->fn->setPressedImage(CancelButton, &cancel_80);
    CancelButton->fn->setReleasedImage(CancelButton, &cancel_80);
    CancelButton->fn->setReleasedEventCallback(CancelButton, CancelButton_OnReleased);
    PanelWidget0->fn->addChild(PanelWidget0, (leWidget*)CancelButton);

    RestartButton = leButtonWidget_New();
    RestartButton->fn->setPosition(RestartButton, 0, 62);
    RestartButton->fn->setSize(RestartButton, 100, 100);
    RestartButton->fn->setBackgroundType(RestartButton, LE_WIDGET_BACKGROUND_NONE);
    RestartButton->fn->setBorderType(RestartButton, LE_WIDGET_BORDER_NONE);
    RestartButton->fn->setToggleable(RestartButton, LE_TRUE);
    RestartButton->fn->setPressedOffset(RestartButton, 0);
    RestartButton->fn->setPressedEventCallback(RestartButton, RestartButton_OnPressed);
    RestartButton->fn->setReleasedEventCallback(RestartButton, RestartButton_OnReleased);
    PanelWidget0->fn->addChild(PanelWidget0, (leWidget*)RestartButton);

    SliderButton0 = leButtonWidget_New();
    SliderButton0->fn->setPosition(SliderButton0, 106, 88);
    SliderButton0->fn->setSize(SliderButton0, 276, 70);
    SliderButton0->fn->setBackgroundType(SliderButton0, LE_WIDGET_BACKGROUND_NONE);
    SliderButton0->fn->setBorderType(SliderButton0, LE_WIDGET_BORDER_NONE);
    PanelWidget0->fn->addChild(PanelWidget0, (leWidget*)SliderButton0);

    ButtonWidget0 = leButtonWidget_New();
    ButtonWidget0->fn->setPosition(ButtonWidget0, 360, 0);
    ButtonWidget0->fn->setSize(ButtonWidget0, 120, 30);
    ButtonWidget0->fn->setBackgroundType(ButtonWidget0, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget0->fn->setBorderType(ButtonWidget0, LE_WIDGET_BORDER_NONE);
    ButtonWidget0->fn->setPressedImage(ButtonWidget0, &rgbsmall);
    ButtonWidget0->fn->setReleasedImage(ButtonWidget0, &rgbsmall);
    ButtonWidget0->fn->setReleasedEventCallback(ButtonWidget0, ButtonWidget0_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget0);

    ImageWidget9 = leImageWidget_New();
    ImageWidget9->fn->setPosition(ImageWidget9, 0, 0);
    ImageWidget9->fn->setSize(ImageWidget9, 132, 35);
    ImageWidget9->fn->setBackgroundType(ImageWidget9, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget9->fn->setImage(ImageWidget9, &mchp_black);
    root0->fn->addChild(root0, (leWidget*)ImageWidget9);

    DemoModeOnButton = leButtonWidget_New();
    DemoModeOnButton->fn->setPosition(DemoModeOnButton, 173, 0);
    DemoModeOnButton->fn->setSize(DemoModeOnButton, 150, 35);
    DemoModeOnButton->fn->setBackgroundType(DemoModeOnButton, LE_WIDGET_BACKGROUND_NONE);
    DemoModeOnButton->fn->setBorderType(DemoModeOnButton, LE_WIDGET_BORDER_NONE);
    DemoModeOnButton->fn->setToggleable(DemoModeOnButton, LE_TRUE);
    DemoModeOnButton->fn->setPressedImage(DemoModeOnButton, &DemoOff);
    DemoModeOnButton->fn->setReleasedImage(DemoModeOnButton, &DemoOn);
    DemoModeOnButton->fn->setPressedEventCallback(DemoModeOnButton, DemoModeOnButton_OnPressed);
    DemoModeOnButton->fn->setReleasedEventCallback(DemoModeOnButton, DemoModeOnButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)DemoModeOnButton);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    MainMenu_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_MainMenu()
{
    MainMenu_OnUpdate();
}

void screenHide_MainMenu()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget1 = NULL;
    ImageWidget1 = NULL;
    PanelWidget3 = NULL;
    ListWheelWidget2 = NULL;
    MainPanel = NULL;
    BakeButton = NULL;
    CookButton = NULL;
    BroilButton = NULL;
    ReheatButton = NULL;
    ImageWidget2 = NULL;
    ImageWidget3 = NULL;
    ImageWidget4 = NULL;
    Badge = NULL;
    LabelWidget0 = NULL;
    LabelWidget3 = NULL;
    LabelWidget1 = NULL;
    ClockPanel = NULL;
    MinuteLabel = NULL;
    ColonLabel = NULL;
    ImageWidget6 = NULL;
    HourLabel = NULL;
    ImageWidget8 = NULL;
    PanelWidget0 = NULL;
    ImageWidget0 = NULL;
    RectangleWidget0 = NULL;
    RectangleWidget1 = NULL;
    RectangleWidget2 = NULL;
    RectangleWidget3 = NULL;
    ModeImageWidget = NULL;
    CookTimeLabel = NULL;
    ProgressBarWidget0 = NULL;
    CancelButton = NULL;
    RestartButton = NULL;
    SliderButton0 = NULL;
    ButtonWidget0 = NULL;
    ImageWidget9 = NULL;
    DemoModeOnButton = NULL;

    tableString_Hotdog.fn->destructor(&tableString_Hotdog);
    tableString_Kabobs.fn->destructor(&tableString_Kabobs);
    tableString_Steak.fn->destructor(&tableString_Steak);
    tableString_Bacon.fn->destructor(&tableString_Bacon);
    tableString_Vegetables.fn->destructor(&tableString_Vegetables);
    tableString_GoodBytes.fn->destructor(&tableString_GoodBytes);
    tableString_Bytes.fn->destructor(&tableString_Bytes);
    tableString_SmartCooker.fn->destructor(&tableString_SmartCooker);
    tableString_DefaultMinute.fn->destructor(&tableString_DefaultMinute);
    tableString_Colon.fn->destructor(&tableString_Colon);
    tableString_DefaultHour.fn->destructor(&tableString_DefaultHour);
    tableString_DefaultCookTime.fn->destructor(&tableString_DefaultCookTime);
    showing = LE_FALSE;

    MainMenu_OnHide();
}

void screenDestroy_MainMenu()
{

}

leWidget* screenGetRoot_MainMenu(uint32_t lyrIdx)
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

