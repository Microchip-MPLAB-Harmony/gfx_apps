#include "gfx/legato/generated/screen/le_gen_screen_MainMenu.h"

// screen member widget declarations
leWidget* root0;

leWidget* MainMenu_PanelWidget1;
leImageWidget* MainMenu_ImageWidget1;
leWidget* MainMenu_PanelWidget3;
leWidget* MainMenu_MainPanel;
leImageWidget* MainMenu_ImageWidget2;
leImageWidget* MainMenu_ImageWidget3;
leImageWidget* MainMenu_ImageWidget4;
leWidget* MainMenu_Badge;
leWidget* MainMenu_ClockPanel;
leImageWidget* MainMenu_ImageWidget8;
leWidget* MainMenu_PanelWidget0;
leButtonWidget* MainMenu_ButtonWidget0;
leImageWidget* MainMenu_ImageWidget9;
leButtonWidget* MainMenu_DemoModeOnButton;
leListWheelWidget* MainMenu_ListWheelWidget2;
leButtonWidget* MainMenu_ReheatButton;
leButtonWidget* MainMenu_BroilButton;
leButtonWidget* MainMenu_CookButton;
leButtonWidget* MainMenu_BakeButton;
leLabelWidget* MainMenu_LabelWidget1;
leLabelWidget* MainMenu_LabelWidget3;
leLabelWidget* MainMenu_LabelWidget0;
leLabelWidget* MainMenu_HourLabel;
leImageWidget* MainMenu_ImageWidget6;
leLabelWidget* MainMenu_ColonLabel;
leLabelWidget* MainMenu_MinuteLabel;
leImageWidget* MainMenu_ImageWidget0;
leProgressBarWidget* MainMenu_ProgressBarWidget0;
leImageWidget* MainMenu_ModeImageWidget;
leRectangleWidget* MainMenu_RectangleWidget3;
leRectangleWidget* MainMenu_RectangleWidget2;
leRectangleWidget* MainMenu_RectangleWidget1;
leRectangleWidget* MainMenu_RectangleWidget0;
leLabelWidget* MainMenu_CookTimeLabel;
leButtonWidget* MainMenu_RestartButton;
leButtonWidget* MainMenu_SliderButton0;
leButtonWidget* MainMenu_CancelButton;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_MainMenu()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_MainMenu()
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

    MainMenu_PanelWidget1 = leWidget_New();
    MainMenu_PanelWidget1->fn->setPosition(MainMenu_PanelWidget1, 0, 0);
    MainMenu_PanelWidget1->fn->setSize(MainMenu_PanelWidget1, 480, 320);
    MainMenu_PanelWidget1->fn->setScheme(MainMenu_PanelWidget1, &BlackBackground);
    root0->fn->addChild(root0, (leWidget*)MainMenu_PanelWidget1);

    MainMenu_ImageWidget1 = leImageWidget_New();
    MainMenu_ImageWidget1->fn->setPosition(MainMenu_ImageWidget1, 6, 111);
    MainMenu_ImageWidget1->fn->setSize(MainMenu_ImageWidget1, 105, 200);
    MainMenu_ImageWidget1->fn->setBackgroundType(MainMenu_ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_ImageWidget1->fn->setBorderType(MainMenu_ImageWidget1, LE_WIDGET_BORDER_NONE);
    MainMenu_ImageWidget1->fn->setHAlignment(MainMenu_ImageWidget1, LE_HALIGN_LEFT);
    MainMenu_ImageWidget1->fn->setImage(MainMenu_ImageWidget1, (leImage*)&smartstart2);
    root0->fn->addChild(root0, (leWidget*)MainMenu_ImageWidget1);

    MainMenu_PanelWidget3 = leWidget_New();
    MainMenu_PanelWidget3->fn->setPosition(MainMenu_PanelWidget3, 110, 124);
    MainMenu_PanelWidget3->fn->setSize(MainMenu_PanelWidget3, 116, 172);
    MainMenu_PanelWidget3->fn->setBackgroundType(MainMenu_PanelWidget3, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)MainMenu_PanelWidget3);

    MainMenu_ListWheelWidget2 = leListWheelWidget_New();
    MainMenu_ListWheelWidget2->fn->setPosition(MainMenu_ListWheelWidget2, 0, 1);
    MainMenu_ListWheelWidget2->fn->setSize(MainMenu_ListWheelWidget2, 115, 170);
    MainMenu_ListWheelWidget2->fn->setScheme(MainMenu_ListWheelWidget2, &ListWheelScheme);
    MainMenu_ListWheelWidget2->fn->setBackgroundType(MainMenu_ListWheelWidget2, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_ListWheelWidget2->fn->setBorderType(MainMenu_ListWheelWidget2, LE_WIDGET_BORDER_NONE);
    MainMenu_ListWheelWidget2->fn->setIconMargin(MainMenu_ListWheelWidget2, 5);
    MainMenu_ListWheelWidget2->fn->setShowIndicators(MainMenu_ListWheelWidget2, LE_FALSE);
    MainMenu_ListWheelWidget2->fn->setShaded(MainMenu_ListWheelWidget2, LE_FALSE);
    MainMenu_ListWheelWidget2->fn->appendItem(MainMenu_ListWheelWidget2);
    MainMenu_ListWheelWidget2->fn->setItemString(MainMenu_ListWheelWidget2, 0, (leString*)&string_Hotdog);
    MainMenu_ListWheelWidget2->fn->appendItem(MainMenu_ListWheelWidget2);
    MainMenu_ListWheelWidget2->fn->setItemString(MainMenu_ListWheelWidget2, 1, (leString*)&string_Kabobs);
    MainMenu_ListWheelWidget2->fn->appendItem(MainMenu_ListWheelWidget2);
    MainMenu_ListWheelWidget2->fn->setItemString(MainMenu_ListWheelWidget2, 2, (leString*)&string_Steak);
    MainMenu_ListWheelWidget2->fn->appendItem(MainMenu_ListWheelWidget2);
    MainMenu_ListWheelWidget2->fn->setItemString(MainMenu_ListWheelWidget2, 3, (leString*)&string_Bacon);
    MainMenu_ListWheelWidget2->fn->appendItem(MainMenu_ListWheelWidget2);
    MainMenu_ListWheelWidget2->fn->setItemString(MainMenu_ListWheelWidget2, 4, (leString*)&string_Vegetables);
    MainMenu_ListWheelWidget2->fn->setSelectedItemChangedEventCallback(MainMenu_ListWheelWidget2, event_MainMenu_ListWheelWidget2_OnSelectionChanged);
    MainMenu_PanelWidget3->fn->addChild(MainMenu_PanelWidget3, (leWidget*)MainMenu_ListWheelWidget2);

    MainMenu_MainPanel = leWidget_New();
    MainMenu_MainPanel->fn->setPosition(MainMenu_MainPanel, 264, 102);
    MainMenu_MainPanel->fn->setSize(MainMenu_MainPanel, 207, 210);
    MainMenu_MainPanel->fn->setBackgroundType(MainMenu_MainPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)MainMenu_MainPanel);

    MainMenu_ReheatButton = leButtonWidget_New();
    MainMenu_ReheatButton->fn->setPosition(MainMenu_ReheatButton, 108, 5);
    MainMenu_ReheatButton->fn->setSize(MainMenu_ReheatButton, 100, 100);
    MainMenu_ReheatButton->fn->setBackgroundType(MainMenu_ReheatButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_ReheatButton->fn->setBorderType(MainMenu_ReheatButton, LE_WIDGET_BORDER_NONE);
    MainMenu_ReheatButton->fn->setPressedImage(MainMenu_ReheatButton, (leImage*)&reheat100);
    MainMenu_ReheatButton->fn->setReleasedImage(MainMenu_ReheatButton, (leImage*)&reheat100);
    MainMenu_ReheatButton->fn->setReleasedEventCallback(MainMenu_ReheatButton, event_MainMenu_ReheatButton_OnReleased);
    MainMenu_MainPanel->fn->addChild(MainMenu_MainPanel, (leWidget*)MainMenu_ReheatButton);

    MainMenu_BroilButton = leButtonWidget_New();
    MainMenu_BroilButton->fn->setPosition(MainMenu_BroilButton, 108, 106);
    MainMenu_BroilButton->fn->setSize(MainMenu_BroilButton, 100, 100);
    MainMenu_BroilButton->fn->setBackgroundType(MainMenu_BroilButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_BroilButton->fn->setBorderType(MainMenu_BroilButton, LE_WIDGET_BORDER_NONE);
    MainMenu_BroilButton->fn->setPressedImage(MainMenu_BroilButton, (leImage*)&broil100);
    MainMenu_BroilButton->fn->setReleasedImage(MainMenu_BroilButton, (leImage*)&broil100);
    MainMenu_BroilButton->fn->setReleasedEventCallback(MainMenu_BroilButton, event_MainMenu_BroilButton_OnReleased);
    MainMenu_MainPanel->fn->addChild(MainMenu_MainPanel, (leWidget*)MainMenu_BroilButton);

    MainMenu_CookButton = leButtonWidget_New();
    MainMenu_CookButton->fn->setPosition(MainMenu_CookButton, 9, 5);
    MainMenu_CookButton->fn->setSize(MainMenu_CookButton, 100, 100);
    MainMenu_CookButton->fn->setBackgroundType(MainMenu_CookButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_CookButton->fn->setBorderType(MainMenu_CookButton, LE_WIDGET_BORDER_NONE);
    MainMenu_CookButton->fn->setPressedImage(MainMenu_CookButton, (leImage*)&cook100);
    MainMenu_CookButton->fn->setReleasedImage(MainMenu_CookButton, (leImage*)&cook100);
    MainMenu_CookButton->fn->setReleasedEventCallback(MainMenu_CookButton, event_MainMenu_CookButton_OnReleased);
    MainMenu_MainPanel->fn->addChild(MainMenu_MainPanel, (leWidget*)MainMenu_CookButton);

    MainMenu_BakeButton = leButtonWidget_New();
    MainMenu_BakeButton->fn->setPosition(MainMenu_BakeButton, 9, 106);
    MainMenu_BakeButton->fn->setSize(MainMenu_BakeButton, 100, 100);
    MainMenu_BakeButton->fn->setScheme(MainMenu_BakeButton, &SquareButtonScheme);
    MainMenu_BakeButton->fn->setBackgroundType(MainMenu_BakeButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_BakeButton->fn->setBorderType(MainMenu_BakeButton, LE_WIDGET_BORDER_NONE);
    MainMenu_BakeButton->fn->setPressedImage(MainMenu_BakeButton, (leImage*)&bake100);
    MainMenu_BakeButton->fn->setReleasedImage(MainMenu_BakeButton, (leImage*)&bake100);
    MainMenu_BakeButton->fn->setImagePosition(MainMenu_BakeButton, LE_RELATIVE_POSITION_ABOVE);
    MainMenu_BakeButton->fn->setReleasedEventCallback(MainMenu_BakeButton, event_MainMenu_BakeButton_OnReleased);
    MainMenu_MainPanel->fn->addChild(MainMenu_MainPanel, (leWidget*)MainMenu_BakeButton);

    MainMenu_ImageWidget2 = leImageWidget_New();
    MainMenu_ImageWidget2->fn->setPosition(MainMenu_ImageWidget2, 228, 110);
    MainMenu_ImageWidget2->fn->setSize(MainMenu_ImageWidget2, 22, 200);
    MainMenu_ImageWidget2->fn->setBackgroundType(MainMenu_ImageWidget2, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_ImageWidget2->fn->setBorderType(MainMenu_ImageWidget2, LE_WIDGET_BORDER_NONE);
    MainMenu_ImageWidget2->fn->setHAlignment(MainMenu_ImageWidget2, LE_HALIGN_RIGHT);
    MainMenu_ImageWidget2->fn->setImage(MainMenu_ImageWidget2, (leImage*)&smartstart2);
    root0->fn->addChild(root0, (leWidget*)MainMenu_ImageWidget2);

    MainMenu_ImageWidget3 = leImageWidget_New();
    MainMenu_ImageWidget3->fn->setPosition(MainMenu_ImageWidget3, 110, 111);
    MainMenu_ImageWidget3->fn->setSize(MainMenu_ImageWidget3, 141, 12);
    MainMenu_ImageWidget3->fn->setBackgroundType(MainMenu_ImageWidget3, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_ImageWidget3->fn->setBorderType(MainMenu_ImageWidget3, LE_WIDGET_BORDER_NONE);
    MainMenu_ImageWidget3->fn->setHAlignment(MainMenu_ImageWidget3, LE_HALIGN_RIGHT);
    MainMenu_ImageWidget3->fn->setVAlignment(MainMenu_ImageWidget3, LE_VALIGN_TOP);
    MainMenu_ImageWidget3->fn->setMargins(MainMenu_ImageWidget3, 4, 0, 4, 0);
    MainMenu_ImageWidget3->fn->setImage(MainMenu_ImageWidget3, (leImage*)&smartstart2);
    root0->fn->addChild(root0, (leWidget*)MainMenu_ImageWidget3);

    MainMenu_ImageWidget4 = leImageWidget_New();
    MainMenu_ImageWidget4->fn->setPosition(MainMenu_ImageWidget4, 109, 299);
    MainMenu_ImageWidget4->fn->setSize(MainMenu_ImageWidget4, 139, 12);
    MainMenu_ImageWidget4->fn->setBackgroundType(MainMenu_ImageWidget4, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_ImageWidget4->fn->setBorderType(MainMenu_ImageWidget4, LE_WIDGET_BORDER_NONE);
    MainMenu_ImageWidget4->fn->setHAlignment(MainMenu_ImageWidget4, LE_HALIGN_RIGHT);
    MainMenu_ImageWidget4->fn->setVAlignment(MainMenu_ImageWidget4, LE_VALIGN_BOTTOM);
    MainMenu_ImageWidget4->fn->setMargins(MainMenu_ImageWidget4, 4, 0, 4, 0);
    MainMenu_ImageWidget4->fn->setImage(MainMenu_ImageWidget4, (leImage*)&smartstart2);
    root0->fn->addChild(root0, (leWidget*)MainMenu_ImageWidget4);

    MainMenu_Badge = leWidget_New();
    MainMenu_Badge->fn->setPosition(MainMenu_Badge, 18, 38);
    MainMenu_Badge->fn->setSize(MainMenu_Badge, 225, 54);
    MainMenu_Badge->fn->setBackgroundType(MainMenu_Badge, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)MainMenu_Badge);

    MainMenu_LabelWidget1 = leLabelWidget_New();
    MainMenu_LabelWidget1->fn->setPosition(MainMenu_LabelWidget1, 87, 31);
    MainMenu_LabelWidget1->fn->setSize(MainMenu_LabelWidget1, 125, 23);
    MainMenu_LabelWidget1->fn->setScheme(MainMenu_LabelWidget1, &WhiteTextScheme);
    MainMenu_LabelWidget1->fn->setBackgroundType(MainMenu_LabelWidget1, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_LabelWidget1->fn->setHAlignment(MainMenu_LabelWidget1, LE_HALIGN_RIGHT);
    MainMenu_LabelWidget1->fn->setString(MainMenu_LabelWidget1, (leString*)&string_SmartCooker);
    MainMenu_Badge->fn->addChild(MainMenu_Badge, (leWidget*)MainMenu_LabelWidget1);

    MainMenu_LabelWidget3 = leLabelWidget_New();
    MainMenu_LabelWidget3->fn->setPosition(MainMenu_LabelWidget3, 75, 1);
    MainMenu_LabelWidget3->fn->setSize(MainMenu_LabelWidget3, 72, 30);
    MainMenu_LabelWidget3->fn->setScheme(MainMenu_LabelWidget3, &BlackTextScheme);
    MainMenu_LabelWidget3->fn->setMargins(MainMenu_LabelWidget3, 4, 0, 4, 0);
    MainMenu_LabelWidget3->fn->setString(MainMenu_LabelWidget3, (leString*)&string_Bytes);
    MainMenu_Badge->fn->addChild(MainMenu_Badge, (leWidget*)MainMenu_LabelWidget3);

    MainMenu_LabelWidget0 = leLabelWidget_New();
    MainMenu_LabelWidget0->fn->setPosition(MainMenu_LabelWidget0, 3, -1);
    MainMenu_LabelWidget0->fn->setSize(MainMenu_LabelWidget0, 75, 30);
    MainMenu_LabelWidget0->fn->setScheme(MainMenu_LabelWidget0, &WhiteTextScheme);
    MainMenu_LabelWidget0->fn->setBackgroundType(MainMenu_LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_LabelWidget0->fn->setString(MainMenu_LabelWidget0, (leString*)&string_GoodBytes);
    MainMenu_Badge->fn->addChild(MainMenu_Badge, (leWidget*)MainMenu_LabelWidget0);

    MainMenu_ClockPanel = leWidget_New();
    MainMenu_ClockPanel->fn->setPosition(MainMenu_ClockPanel, 271, 23);
    MainMenu_ClockPanel->fn->setSize(MainMenu_ClockPanel, 224, 70);
    MainMenu_ClockPanel->fn->setBackgroundType(MainMenu_ClockPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)MainMenu_ClockPanel);

    MainMenu_HourLabel = leLabelWidget_New();
    MainMenu_HourLabel->fn->setPosition(MainMenu_HourLabel, 21, 1);
    MainMenu_HourLabel->fn->setSize(MainMenu_HourLabel, 90, 75);
    MainMenu_HourLabel->fn->setScheme(MainMenu_HourLabel, &WhiteTextScheme);
    MainMenu_HourLabel->fn->setBackgroundType(MainMenu_HourLabel, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_HourLabel->fn->setHAlignment(MainMenu_HourLabel, LE_HALIGN_CENTER);
    MainMenu_HourLabel->fn->setString(MainMenu_HourLabel, (leString*)&string_DefaultHour);
    MainMenu_ClockPanel->fn->addChild(MainMenu_ClockPanel, (leWidget*)MainMenu_HourLabel);

    MainMenu_ImageWidget6 = leImageWidget_New();
    MainMenu_ImageWidget6->fn->setPosition(MainMenu_ImageWidget6, 0, 36);
    MainMenu_ImageWidget6->fn->setSize(MainMenu_ImageWidget6, 28, 24);
    MainMenu_ImageWidget6->fn->setBackgroundType(MainMenu_ImageWidget6, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_ImageWidget6->fn->setBorderType(MainMenu_ImageWidget6, LE_WIDGET_BORDER_NONE);
    MainMenu_ImageWidget6->fn->setImage(MainMenu_ImageWidget6, (leImage*)&time30);
    MainMenu_ClockPanel->fn->addChild(MainMenu_ClockPanel, (leWidget*)MainMenu_ImageWidget6);

    MainMenu_ColonLabel = leLabelWidget_New();
    MainMenu_ColonLabel->fn->setPosition(MainMenu_ColonLabel, 98, 6);
    MainMenu_ColonLabel->fn->setSize(MainMenu_ColonLabel, 23, 57);
    MainMenu_ColonLabel->fn->setScheme(MainMenu_ColonLabel, &WhiteTextScheme);
    MainMenu_ColonLabel->fn->setBackgroundType(MainMenu_ColonLabel, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_ColonLabel->fn->setString(MainMenu_ColonLabel, (leString*)&string_Colon);
    MainMenu_ClockPanel->fn->addChild(MainMenu_ClockPanel, (leWidget*)MainMenu_ColonLabel);

    MainMenu_MinuteLabel = leLabelWidget_New();
    MainMenu_MinuteLabel->fn->setPosition(MainMenu_MinuteLabel, 115, 2);
    MainMenu_MinuteLabel->fn->setSize(MainMenu_MinuteLabel, 88, 75);
    MainMenu_MinuteLabel->fn->setScheme(MainMenu_MinuteLabel, &WhiteTextScheme);
    MainMenu_MinuteLabel->fn->setBackgroundType(MainMenu_MinuteLabel, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_MinuteLabel->fn->setString(MainMenu_MinuteLabel, (leString*)&string_DefaultMinute);
    MainMenu_ClockPanel->fn->addChild(MainMenu_ClockPanel, (leWidget*)MainMenu_MinuteLabel);

    MainMenu_ImageWidget8 = leImageWidget_New();
    MainMenu_ImageWidget8->fn->setPosition(MainMenu_ImageWidget8, 20, 193);
    MainMenu_ImageWidget8->fn->setSize(MainMenu_ImageWidget8, 80, 80);
    MainMenu_ImageWidget8->fn->setScheme(MainMenu_ImageWidget8, &BlackBackground);
    MainMenu_ImageWidget8->fn->setBorderType(MainMenu_ImageWidget8, LE_WIDGET_BORDER_NONE);
    MainMenu_ImageWidget8->fn->setImage(MainMenu_ImageWidget8, (leImage*)&hotdog70);
    root0->fn->addChild(root0, (leWidget*)MainMenu_ImageWidget8);

    MainMenu_PanelWidget0 = leWidget_New();
    MainMenu_PanelWidget0->fn->setPosition(MainMenu_PanelWidget0, 480, 102);
    MainMenu_PanelWidget0->fn->setSize(MainMenu_PanelWidget0, 480, 218);
    MainMenu_PanelWidget0->fn->setScheme(MainMenu_PanelWidget0, &BlackBackground);
    root0->fn->addChild(root0, (leWidget*)MainMenu_PanelWidget0);

    MainMenu_ImageWidget0 = leImageWidget_New();
    MainMenu_ImageWidget0->fn->setPosition(MainMenu_ImageWidget0, 30, 0);
    MainMenu_ImageWidget0->fn->setSize(MainMenu_ImageWidget0, 415, 218);
    MainMenu_ImageWidget0->fn->setScheme(MainMenu_ImageWidget0, &BlackBackground);
    MainMenu_ImageWidget0->fn->setBackgroundType(MainMenu_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_ImageWidget0->fn->setBorderType(MainMenu_ImageWidget0, LE_WIDGET_BORDER_NONE);
    MainMenu_ImageWidget0->fn->setImage(MainMenu_ImageWidget0, (leImage*)&main_rect);
    MainMenu_PanelWidget0->fn->addChild(MainMenu_PanelWidget0, (leWidget*)MainMenu_ImageWidget0);

    MainMenu_ProgressBarWidget0 = leProgressBarWidget_New();
    MainMenu_ProgressBarWidget0->fn->setPosition(MainMenu_ProgressBarWidget0, 106, 117);
    MainMenu_ProgressBarWidget0->fn->setSize(MainMenu_ProgressBarWidget0, 276, 15);
    MainMenu_ProgressBarWidget0->fn->setScheme(MainMenu_ProgressBarWidget0, &ProgressBarScheme);
    MainMenu_ProgressBarWidget0->fn->setBorderType(MainMenu_ProgressBarWidget0, LE_WIDGET_BORDER_NONE);
    MainMenu_ProgressBarWidget0->fn->setValue(MainMenu_ProgressBarWidget0, 50);
    MainMenu_PanelWidget0->fn->addChild(MainMenu_PanelWidget0, (leWidget*)MainMenu_ProgressBarWidget0);

    MainMenu_ModeImageWidget = leImageWidget_New();
    MainMenu_ModeImageWidget->fn->setPosition(MainMenu_ModeImageWidget, 0, 62);
    MainMenu_ModeImageWidget->fn->setScheme(MainMenu_ModeImageWidget, &BlackBackground);
    MainMenu_ModeImageWidget->fn->setBorderType(MainMenu_ModeImageWidget, LE_WIDGET_BORDER_NONE);
    MainMenu_ModeImageWidget->fn->setImage(MainMenu_ModeImageWidget, (leImage*)&reheat100);
    MainMenu_PanelWidget0->fn->addChild(MainMenu_PanelWidget0, (leWidget*)MainMenu_ModeImageWidget);

    MainMenu_RectangleWidget3 = leRectangleWidget_New();
    MainMenu_RectangleWidget3->fn->setPosition(MainMenu_RectangleWidget3, 36, 8);
    MainMenu_RectangleWidget3->fn->setSize(MainMenu_RectangleWidget3, 30, 200);
    MainMenu_RectangleWidget3->fn->setVisible(MainMenu_RectangleWidget3, LE_FALSE);
    MainMenu_RectangleWidget3->fn->setScheme(MainMenu_RectangleWidget3, &BlackBackground);
    MainMenu_RectangleWidget3->fn->setBorderType(MainMenu_RectangleWidget3, LE_WIDGET_BORDER_NONE);
    MainMenu_RectangleWidget3->fn->setThickness(MainMenu_RectangleWidget3, 0);
    MainMenu_PanelWidget0->fn->addChild(MainMenu_PanelWidget0, (leWidget*)MainMenu_RectangleWidget3);

    MainMenu_RectangleWidget2 = leRectangleWidget_New();
    MainMenu_RectangleWidget2->fn->setPosition(MainMenu_RectangleWidget2, 406, 8);
    MainMenu_RectangleWidget2->fn->setSize(MainMenu_RectangleWidget2, 33, 200);
    MainMenu_RectangleWidget2->fn->setVisible(MainMenu_RectangleWidget2, LE_FALSE);
    MainMenu_RectangleWidget2->fn->setScheme(MainMenu_RectangleWidget2, &BlackBackground);
    MainMenu_RectangleWidget2->fn->setBorderType(MainMenu_RectangleWidget2, LE_WIDGET_BORDER_NONE);
    MainMenu_RectangleWidget2->fn->setThickness(MainMenu_RectangleWidget2, 0);
    MainMenu_PanelWidget0->fn->addChild(MainMenu_PanelWidget0, (leWidget*)MainMenu_RectangleWidget2);

    MainMenu_RectangleWidget1 = leRectangleWidget_New();
    MainMenu_RectangleWidget1->fn->setPosition(MainMenu_RectangleWidget1, 66, 199);
    MainMenu_RectangleWidget1->fn->setSize(MainMenu_RectangleWidget1, 340, 9);
    MainMenu_RectangleWidget1->fn->setVisible(MainMenu_RectangleWidget1, LE_FALSE);
    MainMenu_RectangleWidget1->fn->setScheme(MainMenu_RectangleWidget1, &BlackBackground);
    MainMenu_RectangleWidget1->fn->setBorderType(MainMenu_RectangleWidget1, LE_WIDGET_BORDER_NONE);
    MainMenu_RectangleWidget1->fn->setThickness(MainMenu_RectangleWidget1, 0);
    MainMenu_PanelWidget0->fn->addChild(MainMenu_PanelWidget0, (leWidget*)MainMenu_RectangleWidget1);

    MainMenu_RectangleWidget0 = leRectangleWidget_New();
    MainMenu_RectangleWidget0->fn->setPosition(MainMenu_RectangleWidget0, 66, 8);
    MainMenu_RectangleWidget0->fn->setSize(MainMenu_RectangleWidget0, 340, 9);
    MainMenu_RectangleWidget0->fn->setVisible(MainMenu_RectangleWidget0, LE_FALSE);
    MainMenu_RectangleWidget0->fn->setScheme(MainMenu_RectangleWidget0, &BlackBackground);
    MainMenu_RectangleWidget0->fn->setBorderType(MainMenu_RectangleWidget0, LE_WIDGET_BORDER_NONE);
    MainMenu_RectangleWidget0->fn->setThickness(MainMenu_RectangleWidget0, 0);
    MainMenu_PanelWidget0->fn->addChild(MainMenu_PanelWidget0, (leWidget*)MainMenu_RectangleWidget0);

    MainMenu_CookTimeLabel = leLabelWidget_New();
    MainMenu_CookTimeLabel->fn->setPosition(MainMenu_CookTimeLabel, 149, 29);
    MainMenu_CookTimeLabel->fn->setSize(MainMenu_CookTimeLabel, 189, 64);
    MainMenu_CookTimeLabel->fn->setScheme(MainMenu_CookTimeLabel, &WhiteTextScheme);
    MainMenu_CookTimeLabel->fn->setBackgroundType(MainMenu_CookTimeLabel, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_CookTimeLabel->fn->setHAlignment(MainMenu_CookTimeLabel, LE_HALIGN_CENTER);
    MainMenu_CookTimeLabel->fn->setString(MainMenu_CookTimeLabel, (leString*)&string_DefaultCookTime);
    MainMenu_PanelWidget0->fn->addChild(MainMenu_PanelWidget0, (leWidget*)MainMenu_CookTimeLabel);

    MainMenu_RestartButton = leButtonWidget_New();
    MainMenu_RestartButton->fn->setPosition(MainMenu_RestartButton, 0, 62);
    MainMenu_RestartButton->fn->setSize(MainMenu_RestartButton, 100, 100);
    MainMenu_RestartButton->fn->setBackgroundType(MainMenu_RestartButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_RestartButton->fn->setBorderType(MainMenu_RestartButton, LE_WIDGET_BORDER_NONE);
    MainMenu_RestartButton->fn->setToggleable(MainMenu_RestartButton, LE_TRUE);
    MainMenu_RestartButton->fn->setPressedOffset(MainMenu_RestartButton, 0);
    MainMenu_RestartButton->fn->setReleasedEventCallback(MainMenu_RestartButton, event_MainMenu_RestartButton_OnReleased);
    MainMenu_PanelWidget0->fn->addChild(MainMenu_PanelWidget0, (leWidget*)MainMenu_RestartButton);

    MainMenu_SliderButton0 = leButtonWidget_New();
    MainMenu_SliderButton0->fn->setPosition(MainMenu_SliderButton0, 106, 88);
    MainMenu_SliderButton0->fn->setSize(MainMenu_SliderButton0, 276, 70);
    MainMenu_SliderButton0->fn->setBackgroundType(MainMenu_SliderButton0, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_SliderButton0->fn->setBorderType(MainMenu_SliderButton0, LE_WIDGET_BORDER_NONE);
    MainMenu_PanelWidget0->fn->addChild(MainMenu_PanelWidget0, (leWidget*)MainMenu_SliderButton0);

    MainMenu_CancelButton = leButtonWidget_New();
    MainMenu_CancelButton->fn->setPosition(MainMenu_CancelButton, 377, 69);
    MainMenu_CancelButton->fn->setSize(MainMenu_CancelButton, 100, 100);
    MainMenu_CancelButton->fn->setBackgroundType(MainMenu_CancelButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_CancelButton->fn->setBorderType(MainMenu_CancelButton, LE_WIDGET_BORDER_NONE);
    MainMenu_CancelButton->fn->setPressedImage(MainMenu_CancelButton, (leImage*)&cancel_80);
    MainMenu_CancelButton->fn->setReleasedImage(MainMenu_CancelButton, (leImage*)&cancel_80);
    MainMenu_CancelButton->fn->setReleasedEventCallback(MainMenu_CancelButton, event_MainMenu_CancelButton_OnReleased);
    MainMenu_PanelWidget0->fn->addChild(MainMenu_PanelWidget0, (leWidget*)MainMenu_CancelButton);

    MainMenu_ButtonWidget0 = leButtonWidget_New();
    MainMenu_ButtonWidget0->fn->setPosition(MainMenu_ButtonWidget0, 360, 0);
    MainMenu_ButtonWidget0->fn->setSize(MainMenu_ButtonWidget0, 120, 30);
    MainMenu_ButtonWidget0->fn->setBackgroundType(MainMenu_ButtonWidget0, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_ButtonWidget0->fn->setBorderType(MainMenu_ButtonWidget0, LE_WIDGET_BORDER_NONE);
    MainMenu_ButtonWidget0->fn->setPressedImage(MainMenu_ButtonWidget0, (leImage*)&rgbsmall);
    MainMenu_ButtonWidget0->fn->setReleasedImage(MainMenu_ButtonWidget0, (leImage*)&rgbsmall);
    MainMenu_ButtonWidget0->fn->setReleasedEventCallback(MainMenu_ButtonWidget0, event_MainMenu_ButtonWidget0_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenu_ButtonWidget0);

    MainMenu_ImageWidget9 = leImageWidget_New();
    MainMenu_ImageWidget9->fn->setPosition(MainMenu_ImageWidget9, 0, 0);
    MainMenu_ImageWidget9->fn->setSize(MainMenu_ImageWidget9, 132, 35);
    MainMenu_ImageWidget9->fn->setBackgroundType(MainMenu_ImageWidget9, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_ImageWidget9->fn->setBorderType(MainMenu_ImageWidget9, LE_WIDGET_BORDER_NONE);
    MainMenu_ImageWidget9->fn->setImage(MainMenu_ImageWidget9, (leImage*)&mchp_black);
    root0->fn->addChild(root0, (leWidget*)MainMenu_ImageWidget9);

    MainMenu_DemoModeOnButton = leButtonWidget_New();
    MainMenu_DemoModeOnButton->fn->setPosition(MainMenu_DemoModeOnButton, 173, 0);
    MainMenu_DemoModeOnButton->fn->setSize(MainMenu_DemoModeOnButton, 150, 35);
    MainMenu_DemoModeOnButton->fn->setBackgroundType(MainMenu_DemoModeOnButton, LE_WIDGET_BACKGROUND_NONE);
    MainMenu_DemoModeOnButton->fn->setBorderType(MainMenu_DemoModeOnButton, LE_WIDGET_BORDER_NONE);
    MainMenu_DemoModeOnButton->fn->setToggleable(MainMenu_DemoModeOnButton, LE_TRUE);
    MainMenu_DemoModeOnButton->fn->setPressedImage(MainMenu_DemoModeOnButton, (leImage*)&DemoOff);
    MainMenu_DemoModeOnButton->fn->setReleasedImage(MainMenu_DemoModeOnButton, (leImage*)&DemoOn);
    MainMenu_DemoModeOnButton->fn->setPressedEventCallback(MainMenu_DemoModeOnButton, event_MainMenu_DemoModeOnButton_OnPressed);
    MainMenu_DemoModeOnButton->fn->setReleasedEventCallback(MainMenu_DemoModeOnButton, event_MainMenu_DemoModeOnButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)MainMenu_DemoModeOnButton);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    MainMenu_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_MainMenu()
{
    MainMenu_OnUpdate(); // raise event
}

void screenHide_MainMenu()
{
    MainMenu_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    MainMenu_PanelWidget1 = NULL;
    MainMenu_ImageWidget1 = NULL;
    MainMenu_PanelWidget3 = NULL;
    MainMenu_MainPanel = NULL;
    MainMenu_ImageWidget2 = NULL;
    MainMenu_ImageWidget3 = NULL;
    MainMenu_ImageWidget4 = NULL;
    MainMenu_Badge = NULL;
    MainMenu_ClockPanel = NULL;
    MainMenu_ImageWidget8 = NULL;
    MainMenu_PanelWidget0 = NULL;
    MainMenu_ButtonWidget0 = NULL;
    MainMenu_ImageWidget9 = NULL;
    MainMenu_DemoModeOnButton = NULL;
    MainMenu_ListWheelWidget2 = NULL;
    MainMenu_ReheatButton = NULL;
    MainMenu_BroilButton = NULL;
    MainMenu_CookButton = NULL;
    MainMenu_BakeButton = NULL;
    MainMenu_LabelWidget1 = NULL;
    MainMenu_LabelWidget3 = NULL;
    MainMenu_LabelWidget0 = NULL;
    MainMenu_HourLabel = NULL;
    MainMenu_ImageWidget6 = NULL;
    MainMenu_ColonLabel = NULL;
    MainMenu_MinuteLabel = NULL;
    MainMenu_ImageWidget0 = NULL;
    MainMenu_ProgressBarWidget0 = NULL;
    MainMenu_ModeImageWidget = NULL;
    MainMenu_RectangleWidget3 = NULL;
    MainMenu_RectangleWidget2 = NULL;
    MainMenu_RectangleWidget1 = NULL;
    MainMenu_RectangleWidget0 = NULL;
    MainMenu_CookTimeLabel = NULL;
    MainMenu_RestartButton = NULL;
    MainMenu_SliderButton0 = NULL;
    MainMenu_CancelButton = NULL;


    showing = LE_FALSE;
}

void screenDestroy_MainMenu()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
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

