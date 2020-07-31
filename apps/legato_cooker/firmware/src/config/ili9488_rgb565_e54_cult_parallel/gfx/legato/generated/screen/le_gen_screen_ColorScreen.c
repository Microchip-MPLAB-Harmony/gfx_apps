#include "gfx/legato/generated/screen/le_gen_screen_ColorScreen.h"

// screen member widget declarations
leWidget* root0;

leWidget* ColorScreen_PanelWidget2;
leWidget* ColorScreen_PanelWidget5;
leWidget* ColorScreen_PanelWidget4;
leWidget* ColorScreen_QuickSelectionsPanel;
leWidget* ColorScreen_Screen2MainClockPanel;
leWidget* ColorScreen_Screen2LabelPanel;
leButtonWidget* ColorScreen_SliderButton2;
leRectangleWidget* ColorScreen_ProgressRect;
leButtonWidget* ColorScreen_ButtonWidget5;
leButtonWidget* ColorScreen_CookButtonWidget;
leButtonWidget* ColorScreen_ReheatButtonWidget;
leWidget* ColorScreen_MenuItem4;
leWidget* ColorScreen_MenuItem3;
leWidget* ColorScreen_MenuItem2;
leLabelWidget* ColorScreen_LabelWidget2;
leWidget* ColorScreen_MenuItem1;
leRectangleWidget* ColorScreen_Button4Rect;
leRectangleWidget* ColorScreen_Button4RectBack;
leLabelWidget* ColorScreen_MenuItem4Label;
leImageWidget* ColorScreen_Button4Image;
leButtonWidget* ColorScreen_ButtonWidget4;
leRectangleWidget* ColorScreen_Button3Rect;
leRectangleWidget* ColorScreen_Button3RectBack;
leLabelWidget* ColorScreen_MenuItem3Label;
leImageWidget* ColorScreen_ButtonImage3;
leButtonWidget* ColorScreen_ButtonWidget3;
leRectangleWidget* ColorScreen_Button2Rect;
leRectangleWidget* ColorScreen_Button2RectBack;
leImageWidget* ColorScreen_ButtonImage2;
leLabelWidget* ColorScreen_MenuItem2Label;
leButtonWidget* ColorScreen_ButtonWidget2;
leRectangleWidget* ColorScreen_Button1Rect;
leRectangleWidget* ColorScreen_ButtonRect1Back;
leLabelWidget* ColorScreen_MenuItem1Label;
leImageWidget* ColorScreen_ButtonImage1;
leButtonWidget* ColorScreen_ButtonWidget1;
leLabelWidget* ColorScreen_Screen2MinuteLabel;
leLabelWidget* ColorScreen_Screen2ColonLabel;
leLabelWidget* ColorScreen_Screen2HourLabel;
leButtonWidget* ColorScreen_ButtonWidget6;
leLabelWidget* ColorScreen_Screen2SmartCookerLabel;
leLabelWidget* ColorScreen_Screen2BytesLabel;
leLabelWidget* ColorScreen_Screen2GoodLabel;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_ColorScreen()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_ColorScreen()
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

    ColorScreen_PanelWidget2 = leWidget_New();
    ColorScreen_PanelWidget2->fn->setPosition(ColorScreen_PanelWidget2, 0, 0);
    ColorScreen_PanelWidget2->fn->setSize(ColorScreen_PanelWidget2, 480, 320);
    ColorScreen_PanelWidget2->fn->setScheme(ColorScreen_PanelWidget2, &WhiteBackgroundScheme);
    root0->fn->addChild(root0, (leWidget*)ColorScreen_PanelWidget2);

    ColorScreen_PanelWidget5 = leWidget_New();
    ColorScreen_PanelWidget5->fn->setPosition(ColorScreen_PanelWidget5, 212, 22);
    ColorScreen_PanelWidget5->fn->setSize(ColorScreen_PanelWidget5, 153, 290);
    ColorScreen_PanelWidget5->fn->setScheme(ColorScreen_PanelWidget5, &VeryDarkGrayScheme);
    root0->fn->addChild(root0, (leWidget*)ColorScreen_PanelWidget5);

    ColorScreen_ProgressRect = leRectangleWidget_New();
    ColorScreen_ProgressRect->fn->setPosition(ColorScreen_ProgressRect, 0, 30);
    ColorScreen_ProgressRect->fn->setSize(ColorScreen_ProgressRect, 153, 260);
    ColorScreen_ProgressRect->fn->setScheme(ColorScreen_ProgressRect, &Button1Scheme);
    ColorScreen_ProgressRect->fn->setBorderType(ColorScreen_ProgressRect, LE_WIDGET_BORDER_NONE);
    ColorScreen_ProgressRect->fn->setThickness(ColorScreen_ProgressRect, 0);
    ColorScreen_PanelWidget5->fn->addChild(ColorScreen_PanelWidget5, (leWidget*)ColorScreen_ProgressRect);

    ColorScreen_PanelWidget4 = leWidget_New();
    ColorScreen_PanelWidget4->fn->setPosition(ColorScreen_PanelWidget4, 365, 0);
    ColorScreen_PanelWidget4->fn->setSize(ColorScreen_PanelWidget4, 115, 320);
    ColorScreen_PanelWidget4->fn->setScheme(ColorScreen_PanelWidget4, &RightPanelScheme);
    root0->fn->addChild(root0, (leWidget*)ColorScreen_PanelWidget4);

    ColorScreen_ButtonWidget5 = leButtonWidget_New();
    ColorScreen_ButtonWidget5->fn->setPosition(ColorScreen_ButtonWidget5, 0, 280);
    ColorScreen_ButtonWidget5->fn->setSize(ColorScreen_ButtonWidget5, 115, 40);
    ColorScreen_ButtonWidget5->fn->setBackgroundType(ColorScreen_ButtonWidget5, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_ButtonWidget5->fn->setBorderType(ColorScreen_ButtonWidget5, LE_WIDGET_BORDER_NONE);
    ColorScreen_ButtonWidget5->fn->setPressedImage(ColorScreen_ButtonWidget5, (leImage*)&gscalesmall);
    ColorScreen_ButtonWidget5->fn->setReleasedImage(ColorScreen_ButtonWidget5, (leImage*)&gscalesmall);
    ColorScreen_ButtonWidget5->fn->setPressedOffset(ColorScreen_ButtonWidget5, 0);
    ColorScreen_ButtonWidget5->fn->setPressedEventCallback(ColorScreen_ButtonWidget5, event_ColorScreen_ButtonWidget5_OnPressed);
    ColorScreen_PanelWidget4->fn->addChild(ColorScreen_PanelWidget4, (leWidget*)ColorScreen_ButtonWidget5);

    ColorScreen_CookButtonWidget = leButtonWidget_New();
    ColorScreen_CookButtonWidget->fn->setPosition(ColorScreen_CookButtonWidget, 0, 75);
    ColorScreen_CookButtonWidget->fn->setSize(ColorScreen_CookButtonWidget, 115, 98);
    ColorScreen_CookButtonWidget->fn->setScheme(ColorScreen_CookButtonWidget, &BlackBackground);
    ColorScreen_CookButtonWidget->fn->setBackgroundType(ColorScreen_CookButtonWidget, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_CookButtonWidget->fn->setBorderType(ColorScreen_CookButtonWidget, LE_WIDGET_BORDER_NONE);
    ColorScreen_CookButtonWidget->fn->setPressedImage(ColorScreen_CookButtonWidget, (leImage*)&cook2);
    ColorScreen_CookButtonWidget->fn->setReleasedImage(ColorScreen_CookButtonWidget, (leImage*)&cook2);
    ColorScreen_CookButtonWidget->fn->setPressedOffset(ColorScreen_CookButtonWidget, 0);
    ColorScreen_CookButtonWidget->fn->setPressedEventCallback(ColorScreen_CookButtonWidget, event_ColorScreen_CookButtonWidget_OnPressed);
    ColorScreen_PanelWidget4->fn->addChild(ColorScreen_PanelWidget4, (leWidget*)ColorScreen_CookButtonWidget);

    ColorScreen_ReheatButtonWidget = leButtonWidget_New();
    ColorScreen_ReheatButtonWidget->fn->setPosition(ColorScreen_ReheatButtonWidget, 5, 173);
    ColorScreen_ReheatButtonWidget->fn->setSize(ColorScreen_ReheatButtonWidget, 110, 91);
    ColorScreen_ReheatButtonWidget->fn->setScheme(ColorScreen_ReheatButtonWidget, &BlackBackground);
    ColorScreen_ReheatButtonWidget->fn->setBackgroundType(ColorScreen_ReheatButtonWidget, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_ReheatButtonWidget->fn->setBorderType(ColorScreen_ReheatButtonWidget, LE_WIDGET_BORDER_NONE);
    ColorScreen_ReheatButtonWidget->fn->setPressedImage(ColorScreen_ReheatButtonWidget, (leImage*)&reheat2);
    ColorScreen_ReheatButtonWidget->fn->setReleasedImage(ColorScreen_ReheatButtonWidget, (leImage*)&reheat2);
    ColorScreen_ReheatButtonWidget->fn->setPressedOffset(ColorScreen_ReheatButtonWidget, 0);
    ColorScreen_ReheatButtonWidget->fn->setPressedEventCallback(ColorScreen_ReheatButtonWidget, event_ColorScreen_ReheatButtonWidget_OnPressed);
    ColorScreen_PanelWidget4->fn->addChild(ColorScreen_PanelWidget4, (leWidget*)ColorScreen_ReheatButtonWidget);

    ColorScreen_QuickSelectionsPanel = leWidget_New();
    ColorScreen_QuickSelectionsPanel->fn->setPosition(ColorScreen_QuickSelectionsPanel, 0, 0);
    ColorScreen_QuickSelectionsPanel->fn->setSize(ColorScreen_QuickSelectionsPanel, 212, 320);
    ColorScreen_QuickSelectionsPanel->fn->setBackgroundType(ColorScreen_QuickSelectionsPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)ColorScreen_QuickSelectionsPanel);

    ColorScreen_MenuItem4 = leWidget_New();
    ColorScreen_MenuItem4->fn->setPosition(ColorScreen_MenuItem4, 0, 246);
    ColorScreen_MenuItem4->fn->setSize(ColorScreen_MenuItem4, 212, 70);
    ColorScreen_MenuItem4->fn->setBackgroundType(ColorScreen_MenuItem4, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_QuickSelectionsPanel->fn->addChild(ColorScreen_QuickSelectionsPanel, (leWidget*)ColorScreen_MenuItem4);

    ColorScreen_Button4Rect = leRectangleWidget_New();
    ColorScreen_Button4Rect->fn->setPosition(ColorScreen_Button4Rect, 0, 7);
    ColorScreen_Button4Rect->fn->setSize(ColorScreen_Button4Rect, 212, 50);
    ColorScreen_Button4Rect->fn->setScheme(ColorScreen_Button4Rect, &Button4Scheme);
    ColorScreen_Button4Rect->fn->setBorderType(ColorScreen_Button4Rect, LE_WIDGET_BORDER_NONE);
    ColorScreen_Button4Rect->fn->setThickness(ColorScreen_Button4Rect, 0);
    ColorScreen_MenuItem4->fn->addChild(ColorScreen_MenuItem4, (leWidget*)ColorScreen_Button4Rect);

    ColorScreen_Button4RectBack = leRectangleWidget_New();
    ColorScreen_Button4RectBack->fn->setPosition(ColorScreen_Button4RectBack, 6, 57);
    ColorScreen_Button4RectBack->fn->setSize(ColorScreen_Button4RectBack, 206, 8);
    ColorScreen_Button4RectBack->fn->setScheme(ColorScreen_Button4RectBack, &VeryDarkGrayScheme);
    ColorScreen_Button4RectBack->fn->setBorderType(ColorScreen_Button4RectBack, LE_WIDGET_BORDER_NONE);
    ColorScreen_Button4RectBack->fn->setThickness(ColorScreen_Button4RectBack, 0);
    ColorScreen_MenuItem4->fn->addChild(ColorScreen_MenuItem4, (leWidget*)ColorScreen_Button4RectBack);

    ColorScreen_MenuItem4Label = leLabelWidget_New();
    ColorScreen_MenuItem4Label->fn->setPosition(ColorScreen_MenuItem4Label, 108, 21);
    ColorScreen_MenuItem4Label->fn->setScheme(ColorScreen_MenuItem4Label, &UnselectedItemTextScheme);
    ColorScreen_MenuItem4Label->fn->setBackgroundType(ColorScreen_MenuItem4Label, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_MenuItem4Label->fn->setString(ColorScreen_MenuItem4Label, (leString*)&string_Pasta);
    ColorScreen_MenuItem4->fn->addChild(ColorScreen_MenuItem4, (leWidget*)ColorScreen_MenuItem4Label);

    ColorScreen_Button4Image = leImageWidget_New();
    ColorScreen_Button4Image->fn->setPosition(ColorScreen_Button4Image, 23, 0);
    ColorScreen_Button4Image->fn->setSize(ColorScreen_Button4Image, 70, 70);
    ColorScreen_Button4Image->fn->setBackgroundType(ColorScreen_Button4Image, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_Button4Image->fn->setBorderType(ColorScreen_Button4Image, LE_WIDGET_BORDER_NONE);
    ColorScreen_Button4Image->fn->setImage(ColorScreen_Button4Image, (leImage*)&pasta_photo_70);
    ColorScreen_MenuItem4->fn->addChild(ColorScreen_MenuItem4, (leWidget*)ColorScreen_Button4Image);

    ColorScreen_ButtonWidget4 = leButtonWidget_New();
    ColorScreen_ButtonWidget4->fn->setPosition(ColorScreen_ButtonWidget4, 0, 0);
    ColorScreen_ButtonWidget4->fn->setSize(ColorScreen_ButtonWidget4, 212, 70);
    ColorScreen_ButtonWidget4->fn->setBackgroundType(ColorScreen_ButtonWidget4, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_ButtonWidget4->fn->setBorderType(ColorScreen_ButtonWidget4, LE_WIDGET_BORDER_NONE);
    ColorScreen_ButtonWidget4->fn->setPressedEventCallback(ColorScreen_ButtonWidget4, event_ColorScreen_ButtonWidget4_OnPressed);
    ColorScreen_MenuItem4->fn->addChild(ColorScreen_MenuItem4, (leWidget*)ColorScreen_ButtonWidget4);

    ColorScreen_MenuItem3 = leWidget_New();
    ColorScreen_MenuItem3->fn->setPosition(ColorScreen_MenuItem3, 0, 175);
    ColorScreen_MenuItem3->fn->setSize(ColorScreen_MenuItem3, 212, 70);
    ColorScreen_MenuItem3->fn->setBackgroundType(ColorScreen_MenuItem3, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_QuickSelectionsPanel->fn->addChild(ColorScreen_QuickSelectionsPanel, (leWidget*)ColorScreen_MenuItem3);

    ColorScreen_Button3Rect = leRectangleWidget_New();
    ColorScreen_Button3Rect->fn->setPosition(ColorScreen_Button3Rect, 0, 7);
    ColorScreen_Button3Rect->fn->setSize(ColorScreen_Button3Rect, 212, 50);
    ColorScreen_Button3Rect->fn->setScheme(ColorScreen_Button3Rect, &Button3Scheme);
    ColorScreen_Button3Rect->fn->setBorderType(ColorScreen_Button3Rect, LE_WIDGET_BORDER_NONE);
    ColorScreen_Button3Rect->fn->setThickness(ColorScreen_Button3Rect, 0);
    ColorScreen_MenuItem3->fn->addChild(ColorScreen_MenuItem3, (leWidget*)ColorScreen_Button3Rect);

    ColorScreen_Button3RectBack = leRectangleWidget_New();
    ColorScreen_Button3RectBack->fn->setPosition(ColorScreen_Button3RectBack, 6, 56);
    ColorScreen_Button3RectBack->fn->setSize(ColorScreen_Button3RectBack, 206, 9);
    ColorScreen_Button3RectBack->fn->setScheme(ColorScreen_Button3RectBack, &VeryDarkGrayScheme);
    ColorScreen_Button3RectBack->fn->setBorderType(ColorScreen_Button3RectBack, LE_WIDGET_BORDER_NONE);
    ColorScreen_Button3RectBack->fn->setThickness(ColorScreen_Button3RectBack, 0);
    ColorScreen_MenuItem3->fn->addChild(ColorScreen_MenuItem3, (leWidget*)ColorScreen_Button3RectBack);

    ColorScreen_MenuItem3Label = leLabelWidget_New();
    ColorScreen_MenuItem3Label->fn->setPosition(ColorScreen_MenuItem3Label, 99, 21);
    ColorScreen_MenuItem3Label->fn->setScheme(ColorScreen_MenuItem3Label, &UnselectedItemTextScheme);
    ColorScreen_MenuItem3Label->fn->setBackgroundType(ColorScreen_MenuItem3Label, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_MenuItem3Label->fn->setString(ColorScreen_MenuItem3Label, (leString*)&string_PizzaMenuItem);
    ColorScreen_MenuItem3->fn->addChild(ColorScreen_MenuItem3, (leWidget*)ColorScreen_MenuItem3Label);

    ColorScreen_ButtonImage3 = leImageWidget_New();
    ColorScreen_ButtonImage3->fn->setPosition(ColorScreen_ButtonImage3, 13, 0);
    ColorScreen_ButtonImage3->fn->setSize(ColorScreen_ButtonImage3, 70, 70);
    ColorScreen_ButtonImage3->fn->setBackgroundType(ColorScreen_ButtonImage3, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_ButtonImage3->fn->setBorderType(ColorScreen_ButtonImage3, LE_WIDGET_BORDER_NONE);
    ColorScreen_ButtonImage3->fn->setImage(ColorScreen_ButtonImage3, (leImage*)&pizza_photo70);
    ColorScreen_MenuItem3->fn->addChild(ColorScreen_MenuItem3, (leWidget*)ColorScreen_ButtonImage3);

    ColorScreen_ButtonWidget3 = leButtonWidget_New();
    ColorScreen_ButtonWidget3->fn->setPosition(ColorScreen_ButtonWidget3, 0, 0);
    ColorScreen_ButtonWidget3->fn->setSize(ColorScreen_ButtonWidget3, 212, 70);
    ColorScreen_ButtonWidget3->fn->setBackgroundType(ColorScreen_ButtonWidget3, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_ButtonWidget3->fn->setBorderType(ColorScreen_ButtonWidget3, LE_WIDGET_BORDER_NONE);
    ColorScreen_ButtonWidget3->fn->setPressedEventCallback(ColorScreen_ButtonWidget3, event_ColorScreen_ButtonWidget3_OnPressed);
    ColorScreen_MenuItem3->fn->addChild(ColorScreen_MenuItem3, (leWidget*)ColorScreen_ButtonWidget3);

    ColorScreen_MenuItem2 = leWidget_New();
    ColorScreen_MenuItem2->fn->setPosition(ColorScreen_MenuItem2, 0, 102);
    ColorScreen_MenuItem2->fn->setSize(ColorScreen_MenuItem2, 212, 70);
    ColorScreen_MenuItem2->fn->setBackgroundType(ColorScreen_MenuItem2, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_QuickSelectionsPanel->fn->addChild(ColorScreen_QuickSelectionsPanel, (leWidget*)ColorScreen_MenuItem2);

    ColorScreen_Button2Rect = leRectangleWidget_New();
    ColorScreen_Button2Rect->fn->setPosition(ColorScreen_Button2Rect, 0, 7);
    ColorScreen_Button2Rect->fn->setSize(ColorScreen_Button2Rect, 212, 50);
    ColorScreen_Button2Rect->fn->setScheme(ColorScreen_Button2Rect, &Button2Scheme);
    ColorScreen_Button2Rect->fn->setBorderType(ColorScreen_Button2Rect, LE_WIDGET_BORDER_NONE);
    ColorScreen_Button2Rect->fn->setThickness(ColorScreen_Button2Rect, 0);
    ColorScreen_MenuItem2->fn->addChild(ColorScreen_MenuItem2, (leWidget*)ColorScreen_Button2Rect);

    ColorScreen_Button2RectBack = leRectangleWidget_New();
    ColorScreen_Button2RectBack->fn->setPosition(ColorScreen_Button2RectBack, 6, 57);
    ColorScreen_Button2RectBack->fn->setSize(ColorScreen_Button2RectBack, 206, 8);
    ColorScreen_Button2RectBack->fn->setScheme(ColorScreen_Button2RectBack, &VeryDarkGrayScheme);
    ColorScreen_Button2RectBack->fn->setBorderType(ColorScreen_Button2RectBack, LE_WIDGET_BORDER_NONE);
    ColorScreen_Button2RectBack->fn->setThickness(ColorScreen_Button2RectBack, 0);
    ColorScreen_MenuItem2->fn->addChild(ColorScreen_MenuItem2, (leWidget*)ColorScreen_Button2RectBack);

    ColorScreen_ButtonImage2 = leImageWidget_New();
    ColorScreen_ButtonImage2->fn->setPosition(ColorScreen_ButtonImage2, 23, 0);
    ColorScreen_ButtonImage2->fn->setSize(ColorScreen_ButtonImage2, 70, 70);
    ColorScreen_ButtonImage2->fn->setBackgroundType(ColorScreen_ButtonImage2, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_ButtonImage2->fn->setBorderType(ColorScreen_ButtonImage2, LE_WIDGET_BORDER_NONE);
    ColorScreen_ButtonImage2->fn->setImage(ColorScreen_ButtonImage2, (leImage*)&salmon_photo_70);
    ColorScreen_MenuItem2->fn->addChild(ColorScreen_MenuItem2, (leWidget*)ColorScreen_ButtonImage2);

    ColorScreen_MenuItem2Label = leLabelWidget_New();
    ColorScreen_MenuItem2Label->fn->setPosition(ColorScreen_MenuItem2Label, 109, 19);
    ColorScreen_MenuItem2Label->fn->setScheme(ColorScreen_MenuItem2Label, &UnselectedItemTextScheme);
    ColorScreen_MenuItem2Label->fn->setBackgroundType(ColorScreen_MenuItem2Label, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_MenuItem2Label->fn->setString(ColorScreen_MenuItem2Label, (leString*)&string_SalmonMenuItem);
    ColorScreen_MenuItem2->fn->addChild(ColorScreen_MenuItem2, (leWidget*)ColorScreen_MenuItem2Label);

    ColorScreen_ButtonWidget2 = leButtonWidget_New();
    ColorScreen_ButtonWidget2->fn->setPosition(ColorScreen_ButtonWidget2, 0, 0);
    ColorScreen_ButtonWidget2->fn->setSize(ColorScreen_ButtonWidget2, 212, 70);
    ColorScreen_ButtonWidget2->fn->setBackgroundType(ColorScreen_ButtonWidget2, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_ButtonWidget2->fn->setBorderType(ColorScreen_ButtonWidget2, LE_WIDGET_BORDER_NONE);
    ColorScreen_ButtonWidget2->fn->setPressedEventCallback(ColorScreen_ButtonWidget2, event_ColorScreen_ButtonWidget2_OnPressed);
    ColorScreen_MenuItem2->fn->addChild(ColorScreen_MenuItem2, (leWidget*)ColorScreen_ButtonWidget2);

    ColorScreen_LabelWidget2 = leLabelWidget_New();
    ColorScreen_LabelWidget2->fn->setPosition(ColorScreen_LabelWidget2, 0, -1);
    ColorScreen_LabelWidget2->fn->setSize(ColorScreen_LabelWidget2, 212, 31);
    ColorScreen_LabelWidget2->fn->setBackgroundType(ColorScreen_LabelWidget2, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_LabelWidget2->fn->setHAlignment(ColorScreen_LabelWidget2, LE_HALIGN_CENTER);
    ColorScreen_LabelWidget2->fn->setString(ColorScreen_LabelWidget2, (leString*)&string_QuickItems);
    ColorScreen_QuickSelectionsPanel->fn->addChild(ColorScreen_QuickSelectionsPanel, (leWidget*)ColorScreen_LabelWidget2);

    ColorScreen_MenuItem1 = leWidget_New();
    ColorScreen_MenuItem1->fn->setPosition(ColorScreen_MenuItem1, 0, 31);
    ColorScreen_MenuItem1->fn->setSize(ColorScreen_MenuItem1, 212, 70);
    ColorScreen_MenuItem1->fn->setBackgroundType(ColorScreen_MenuItem1, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_QuickSelectionsPanel->fn->addChild(ColorScreen_QuickSelectionsPanel, (leWidget*)ColorScreen_MenuItem1);

    ColorScreen_Button1Rect = leRectangleWidget_New();
    ColorScreen_Button1Rect->fn->setPosition(ColorScreen_Button1Rect, 0, 7);
    ColorScreen_Button1Rect->fn->setSize(ColorScreen_Button1Rect, 212, 50);
    ColorScreen_Button1Rect->fn->setScheme(ColorScreen_Button1Rect, &Button1Scheme);
    ColorScreen_Button1Rect->fn->setBorderType(ColorScreen_Button1Rect, LE_WIDGET_BORDER_NONE);
    ColorScreen_Button1Rect->fn->setThickness(ColorScreen_Button1Rect, 0);
    ColorScreen_MenuItem1->fn->addChild(ColorScreen_MenuItem1, (leWidget*)ColorScreen_Button1Rect);

    ColorScreen_ButtonRect1Back = leRectangleWidget_New();
    ColorScreen_ButtonRect1Back->fn->setPosition(ColorScreen_ButtonRect1Back, 6, 57);
    ColorScreen_ButtonRect1Back->fn->setSize(ColorScreen_ButtonRect1Back, 206, 8);
    ColorScreen_ButtonRect1Back->fn->setScheme(ColorScreen_ButtonRect1Back, &VeryDarkGrayScheme);
    ColorScreen_ButtonRect1Back->fn->setBorderType(ColorScreen_ButtonRect1Back, LE_WIDGET_BORDER_NONE);
    ColorScreen_ButtonRect1Back->fn->setThickness(ColorScreen_ButtonRect1Back, 0);
    ColorScreen_MenuItem1->fn->addChild(ColorScreen_MenuItem1, (leWidget*)ColorScreen_ButtonRect1Back);

    ColorScreen_MenuItem1Label = leLabelWidget_New();
    ColorScreen_MenuItem1Label->fn->setPosition(ColorScreen_MenuItem1Label, 99, 20);
    ColorScreen_MenuItem1Label->fn->setScheme(ColorScreen_MenuItem1Label, &WhiteTextScheme);
    ColorScreen_MenuItem1Label->fn->setBackgroundType(ColorScreen_MenuItem1Label, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_MenuItem1Label->fn->setString(ColorScreen_MenuItem1Label, (leString*)&string_SteakMenuItem);
    ColorScreen_MenuItem1->fn->addChild(ColorScreen_MenuItem1, (leWidget*)ColorScreen_MenuItem1Label);

    ColorScreen_ButtonImage1 = leImageWidget_New();
    ColorScreen_ButtonImage1->fn->setPosition(ColorScreen_ButtonImage1, 13, 0);
    ColorScreen_ButtonImage1->fn->setSize(ColorScreen_ButtonImage1, 70, 70);
    ColorScreen_ButtonImage1->fn->setBackgroundType(ColorScreen_ButtonImage1, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_ButtonImage1->fn->setBorderType(ColorScreen_ButtonImage1, LE_WIDGET_BORDER_NONE);
    ColorScreen_ButtonImage1->fn->setImage(ColorScreen_ButtonImage1, (leImage*)&steak_photo_70);
    ColorScreen_MenuItem1->fn->addChild(ColorScreen_MenuItem1, (leWidget*)ColorScreen_ButtonImage1);

    ColorScreen_ButtonWidget1 = leButtonWidget_New();
    ColorScreen_ButtonWidget1->fn->setPosition(ColorScreen_ButtonWidget1, 0, 0);
    ColorScreen_ButtonWidget1->fn->setSize(ColorScreen_ButtonWidget1, 212, 70);
    ColorScreen_ButtonWidget1->fn->setBackgroundType(ColorScreen_ButtonWidget1, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_ButtonWidget1->fn->setBorderType(ColorScreen_ButtonWidget1, LE_WIDGET_BORDER_NONE);
    ColorScreen_ButtonWidget1->fn->setPressedOffset(ColorScreen_ButtonWidget1, 0);
    ColorScreen_ButtonWidget1->fn->setPressedEventCallback(ColorScreen_ButtonWidget1, event_ColorScreen_ButtonWidget1_OnPressed);
    ColorScreen_MenuItem1->fn->addChild(ColorScreen_MenuItem1, (leWidget*)ColorScreen_ButtonWidget1);

    ColorScreen_Screen2MainClockPanel = leWidget_New();
    ColorScreen_Screen2MainClockPanel->fn->setPosition(ColorScreen_Screen2MainClockPanel, 212, 22);
    ColorScreen_Screen2MainClockPanel->fn->setSize(ColorScreen_Screen2MainClockPanel, 153, 290);
    ColorScreen_Screen2MainClockPanel->fn->setBackgroundType(ColorScreen_Screen2MainClockPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)ColorScreen_Screen2MainClockPanel);

    ColorScreen_Screen2MinuteLabel = leLabelWidget_New();
    ColorScreen_Screen2MinuteLabel->fn->setPosition(ColorScreen_Screen2MinuteLabel, 51, 138);
    ColorScreen_Screen2MinuteLabel->fn->setSize(ColorScreen_Screen2MinuteLabel, 101, 80);
    ColorScreen_Screen2MinuteLabel->fn->setScheme(ColorScreen_Screen2MinuteLabel, &WhiteTextScheme);
    ColorScreen_Screen2MinuteLabel->fn->setBackgroundType(ColorScreen_Screen2MinuteLabel, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_Screen2MinuteLabel->fn->setString(ColorScreen_Screen2MinuteLabel, (leString*)&string_DefaultMinute2);
    ColorScreen_Screen2MainClockPanel->fn->addChild(ColorScreen_Screen2MainClockPanel, (leWidget*)ColorScreen_Screen2MinuteLabel);

    ColorScreen_Screen2ColonLabel = leLabelWidget_New();
    ColorScreen_Screen2ColonLabel->fn->setPosition(ColorScreen_Screen2ColonLabel, 26, 146);
    ColorScreen_Screen2ColonLabel->fn->setSize(ColorScreen_Screen2ColonLabel, 26, 52);
    ColorScreen_Screen2ColonLabel->fn->setScheme(ColorScreen_Screen2ColonLabel, &WhiteTextScheme);
    ColorScreen_Screen2ColonLabel->fn->setBackgroundType(ColorScreen_Screen2ColonLabel, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_Screen2ColonLabel->fn->setString(ColorScreen_Screen2ColonLabel, (leString*)&string_Colon);
    ColorScreen_Screen2MainClockPanel->fn->addChild(ColorScreen_Screen2MainClockPanel, (leWidget*)ColorScreen_Screen2ColonLabel);

    ColorScreen_Screen2HourLabel = leLabelWidget_New();
    ColorScreen_Screen2HourLabel->fn->setPosition(ColorScreen_Screen2HourLabel, 0, 64);
    ColorScreen_Screen2HourLabel->fn->setSize(ColorScreen_Screen2HourLabel, 153, 75);
    ColorScreen_Screen2HourLabel->fn->setScheme(ColorScreen_Screen2HourLabel, &WhiteTextScheme);
    ColorScreen_Screen2HourLabel->fn->setBackgroundType(ColorScreen_Screen2HourLabel, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_Screen2HourLabel->fn->setHAlignment(ColorScreen_Screen2HourLabel, LE_HALIGN_CENTER);
    ColorScreen_Screen2HourLabel->fn->setString(ColorScreen_Screen2HourLabel, (leString*)&string_DefaultHour2);
    ColorScreen_Screen2MainClockPanel->fn->addChild(ColorScreen_Screen2MainClockPanel, (leWidget*)ColorScreen_Screen2HourLabel);

    ColorScreen_Screen2LabelPanel = leWidget_New();
    ColorScreen_Screen2LabelPanel->fn->setPosition(ColorScreen_Screen2LabelPanel, 205, 0);
    ColorScreen_Screen2LabelPanel->fn->setSize(ColorScreen_Screen2LabelPanel, 275, 76);
    ColorScreen_Screen2LabelPanel->fn->setBackgroundType(ColorScreen_Screen2LabelPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)ColorScreen_Screen2LabelPanel);

    ColorScreen_ButtonWidget6 = leButtonWidget_New();
    ColorScreen_ButtonWidget6->fn->setPosition(ColorScreen_ButtonWidget6, 0, 22);
    ColorScreen_ButtonWidget6->fn->setSize(ColorScreen_ButtonWidget6, 160, 30);
    ColorScreen_ButtonWidget6->fn->setBackgroundType(ColorScreen_ButtonWidget6, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_ButtonWidget6->fn->setBorderType(ColorScreen_ButtonWidget6, LE_WIDGET_BORDER_NONE);
    ColorScreen_ButtonWidget6->fn->setToggleable(ColorScreen_ButtonWidget6, LE_TRUE);
    ColorScreen_ButtonWidget6->fn->setPressedImage(ColorScreen_ButtonWidget6, (leImage*)&DemoOff);
    ColorScreen_ButtonWidget6->fn->setReleasedImage(ColorScreen_ButtonWidget6, (leImage*)&DemoOn);
    ColorScreen_ButtonWidget6->fn->setPressedEventCallback(ColorScreen_ButtonWidget6, event_ColorScreen_ButtonWidget6_OnPressed);
    ColorScreen_ButtonWidget6->fn->setReleasedEventCallback(ColorScreen_ButtonWidget6, event_ColorScreen_ButtonWidget6_OnReleased);
    ColorScreen_Screen2LabelPanel->fn->addChild(ColorScreen_Screen2LabelPanel, (leWidget*)ColorScreen_ButtonWidget6);

    ColorScreen_Screen2SmartCookerLabel = leLabelWidget_New();
    ColorScreen_Screen2SmartCookerLabel->fn->setPosition(ColorScreen_Screen2SmartCookerLabel, 160, 48);
    ColorScreen_Screen2SmartCookerLabel->fn->setSize(ColorScreen_Screen2SmartCookerLabel, 115, 25);
    ColorScreen_Screen2SmartCookerLabel->fn->setScheme(ColorScreen_Screen2SmartCookerLabel, &WhiteTextScheme);
    ColorScreen_Screen2SmartCookerLabel->fn->setBackgroundType(ColorScreen_Screen2SmartCookerLabel, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_Screen2SmartCookerLabel->fn->setHAlignment(ColorScreen_Screen2SmartCookerLabel, LE_HALIGN_CENTER);
    ColorScreen_Screen2SmartCookerLabel->fn->setString(ColorScreen_Screen2SmartCookerLabel, (leString*)&string_SmartCooker);
    ColorScreen_Screen2LabelPanel->fn->addChild(ColorScreen_Screen2LabelPanel, (leWidget*)ColorScreen_Screen2SmartCookerLabel);

    ColorScreen_Screen2BytesLabel = leLabelWidget_New();
    ColorScreen_Screen2BytesLabel->fn->setPosition(ColorScreen_Screen2BytesLabel, 0, 22);
    ColorScreen_Screen2BytesLabel->fn->setSize(ColorScreen_Screen2BytesLabel, 268, 30);
    ColorScreen_Screen2BytesLabel->fn->setScheme(ColorScreen_Screen2BytesLabel, &LabelBannerScheme);
    ColorScreen_Screen2BytesLabel->fn->setHAlignment(ColorScreen_Screen2BytesLabel, LE_HALIGN_RIGHT);
    ColorScreen_Screen2BytesLabel->fn->setString(ColorScreen_Screen2BytesLabel, (leString*)&string_Bytes);
    ColorScreen_Screen2LabelPanel->fn->addChild(ColorScreen_Screen2LabelPanel, (leWidget*)ColorScreen_Screen2BytesLabel);

    ColorScreen_Screen2GoodLabel = leLabelWidget_New();
    ColorScreen_Screen2GoodLabel->fn->setPosition(ColorScreen_Screen2GoodLabel, 161, 0);
    ColorScreen_Screen2GoodLabel->fn->setSize(ColorScreen_Screen2GoodLabel, 71, 29);
    ColorScreen_Screen2GoodLabel->fn->setScheme(ColorScreen_Screen2GoodLabel, &WhiteTextScheme);
    ColorScreen_Screen2GoodLabel->fn->setBackgroundType(ColorScreen_Screen2GoodLabel, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_Screen2GoodLabel->fn->setHAlignment(ColorScreen_Screen2GoodLabel, LE_HALIGN_CENTER);
    ColorScreen_Screen2GoodLabel->fn->setString(ColorScreen_Screen2GoodLabel, (leString*)&string_GoodBytes);
    ColorScreen_Screen2LabelPanel->fn->addChild(ColorScreen_Screen2LabelPanel, (leWidget*)ColorScreen_Screen2GoodLabel);

    ColorScreen_SliderButton2 = leButtonWidget_New();
    ColorScreen_SliderButton2->fn->setPosition(ColorScreen_SliderButton2, 212, 52);
    ColorScreen_SliderButton2->fn->setSize(ColorScreen_SliderButton2, 153, 260);
    ColorScreen_SliderButton2->fn->setBackgroundType(ColorScreen_SliderButton2, LE_WIDGET_BACKGROUND_NONE);
    ColorScreen_SliderButton2->fn->setBorderType(ColorScreen_SliderButton2, LE_WIDGET_BORDER_NONE);
    root0->fn->addChild(root0, (leWidget*)ColorScreen_SliderButton2);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    ColorScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_ColorScreen()
{
    ColorScreen_OnUpdate(); // raise event
}

void screenHide_ColorScreen()
{
    ColorScreen_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    ColorScreen_PanelWidget2 = NULL;
    ColorScreen_PanelWidget5 = NULL;
    ColorScreen_PanelWidget4 = NULL;
    ColorScreen_QuickSelectionsPanel = NULL;
    ColorScreen_Screen2MainClockPanel = NULL;
    ColorScreen_Screen2LabelPanel = NULL;
    ColorScreen_SliderButton2 = NULL;
    ColorScreen_ProgressRect = NULL;
    ColorScreen_ButtonWidget5 = NULL;
    ColorScreen_CookButtonWidget = NULL;
    ColorScreen_ReheatButtonWidget = NULL;
    ColorScreen_MenuItem4 = NULL;
    ColorScreen_MenuItem3 = NULL;
    ColorScreen_MenuItem2 = NULL;
    ColorScreen_LabelWidget2 = NULL;
    ColorScreen_MenuItem1 = NULL;
    ColorScreen_Button4Rect = NULL;
    ColorScreen_Button4RectBack = NULL;
    ColorScreen_MenuItem4Label = NULL;
    ColorScreen_Button4Image = NULL;
    ColorScreen_ButtonWidget4 = NULL;
    ColorScreen_Button3Rect = NULL;
    ColorScreen_Button3RectBack = NULL;
    ColorScreen_MenuItem3Label = NULL;
    ColorScreen_ButtonImage3 = NULL;
    ColorScreen_ButtonWidget3 = NULL;
    ColorScreen_Button2Rect = NULL;
    ColorScreen_Button2RectBack = NULL;
    ColorScreen_ButtonImage2 = NULL;
    ColorScreen_MenuItem2Label = NULL;
    ColorScreen_ButtonWidget2 = NULL;
    ColorScreen_Button1Rect = NULL;
    ColorScreen_ButtonRect1Back = NULL;
    ColorScreen_MenuItem1Label = NULL;
    ColorScreen_ButtonImage1 = NULL;
    ColorScreen_ButtonWidget1 = NULL;
    ColorScreen_Screen2MinuteLabel = NULL;
    ColorScreen_Screen2ColonLabel = NULL;
    ColorScreen_Screen2HourLabel = NULL;
    ColorScreen_ButtonWidget6 = NULL;
    ColorScreen_Screen2SmartCookerLabel = NULL;
    ColorScreen_Screen2BytesLabel = NULL;
    ColorScreen_Screen2GoodLabel = NULL;


    showing = LE_FALSE;
}

void screenDestroy_ColorScreen()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_ColorScreen(uint32_t lyrIdx)
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

