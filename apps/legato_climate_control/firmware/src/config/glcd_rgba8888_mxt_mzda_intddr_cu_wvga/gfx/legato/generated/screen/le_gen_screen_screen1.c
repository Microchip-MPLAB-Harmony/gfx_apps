#include "gfx/legato/generated/screen/le_gen_screen_screen1.h"

// screen member widget declarations
leWidget* root0;
leWidget* root1;
leWidget* root2;

leImageWidget* screen1_BackgroundImage;
leButtonWidget* screen1_RecirculateButton;
leButtonWidget* screen1_WindshieldVentButton;
leButtonWidget* screen1_RearVentButton;
leButtonWidget* screen1_ClimateControlButton;
leButtonWidget* screen1_SeatHeaterButton;
leButtonWidget* screen1_DriverZoneButton;
leButtonWidget* screen1_FrontPassZoneButton;
leButtonWidget* screen1_RearRightPassZoneButton;
leButtonWidget* screen1_RearLeftPassZoneButton;
leImageSequenceWidget* screen1_TempImageSequenceWidget;
leImageSequenceWidget* screen1_FanLevel1;
leImageSequenceWidget* screen1_FanLevel2;
leImageSequenceWidget* screen1_FanLevel3;
leImageSequenceWidget* screen1_FanLevel4;
leImageSequenceWidget* screen1_FanLevel5;
leImageSequenceWidget* screen1_FanLevel6;
leImageSequenceWidget* screen1_ZoneImageSequence;
leButtonWidget* screen1_TempControlButton;
leButtonWidget* screen1_SyncButton;
leButtonWidget* screen1_HighVentButton;
leButtonWidget* screen1_MidVentButton;
leButtonWidget* screen1_LowVentButton;
leButtonWidget* screen1_FanButtonWidget;
leButtonWidget* screen1_InfoPageButton;
leButtonWidget* screen1_mchpButton;
leButtonWidget* screen1_AirconButton;
leWidget* screen1_PanelWidget1;
leImageWidget* screen1_ImageWidget1;
leWidget* screen1_PanelWidget0;
leImageSequenceWidget* screen1_HourTimeWidget;
leImageWidget* screen1_ColonImage;
leImageSequenceWidget* screen1_MinuteTimeWidget;
leImageWidget* screen1_AMImageWidget;
leImageWidget* screen1_ImageWidget2;
leButtonWidget* screen1_TopBannerButton;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_screen1()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_screen1()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    screen1_BackgroundImage = leImageWidget_New();
    screen1_BackgroundImage->fn->setPosition(screen1_BackgroundImage, 0, 0);
    screen1_BackgroundImage->fn->setSize(screen1_BackgroundImage, 800, 480);
    screen1_BackgroundImage->fn->setBackgroundType(screen1_BackgroundImage, LE_WIDGET_BACKGROUND_NONE);
    screen1_BackgroundImage->fn->setBorderType(screen1_BackgroundImage, LE_WIDGET_BORDER_NONE);
    screen1_BackgroundImage->fn->setImage(screen1_BackgroundImage, (leImage*)&background5);
    root0->fn->addChild(root0, (leWidget*)screen1_BackgroundImage);

    screen1_RecirculateButton = leButtonWidget_New();
    screen1_RecirculateButton->fn->setPosition(screen1_RecirculateButton, 82, 410);
    screen1_RecirculateButton->fn->setSize(screen1_RecirculateButton, 70, 70);
    screen1_RecirculateButton->fn->setBackgroundType(screen1_RecirculateButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_RecirculateButton->fn->setBorderType(screen1_RecirculateButton, LE_WIDGET_BORDER_NONE);
    screen1_RecirculateButton->fn->setToggleable(screen1_RecirculateButton, LE_TRUE);
    screen1_RecirculateButton->fn->setPressedImage(screen1_RecirculateButton, (leImage*)&fresh_air_on2);
    screen1_RecirculateButton->fn->setReleasedImage(screen1_RecirculateButton, (leImage*)&recirc_on2);
    screen1_RecirculateButton->fn->setPressedOffset(screen1_RecirculateButton, 0);
    screen1_RecirculateButton->fn->setPressedEventCallback(screen1_RecirculateButton, event_screen1_RecirculateButton_OnPressed);
    screen1_RecirculateButton->fn->setReleasedEventCallback(screen1_RecirculateButton, event_screen1_RecirculateButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)screen1_RecirculateButton);

    screen1_WindshieldVentButton = leButtonWidget_New();
    screen1_WindshieldVentButton->fn->setPosition(screen1_WindshieldVentButton, 159, 410);
    screen1_WindshieldVentButton->fn->setSize(screen1_WindshieldVentButton, 70, 70);
    screen1_WindshieldVentButton->fn->setBackgroundType(screen1_WindshieldVentButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_WindshieldVentButton->fn->setBorderType(screen1_WindshieldVentButton, LE_WIDGET_BORDER_NONE);
    screen1_WindshieldVentButton->fn->setToggleable(screen1_WindshieldVentButton, LE_TRUE);
    screen1_WindshieldVentButton->fn->setPressedImage(screen1_WindshieldVentButton, (leImage*)&front_vent_on2);
    screen1_WindshieldVentButton->fn->setReleasedImage(screen1_WindshieldVentButton, (leImage*)&front_vent_off2);
    screen1_WindshieldVentButton->fn->setPressedOffset(screen1_WindshieldVentButton, 0);
    screen1_WindshieldVentButton->fn->setPressedEventCallback(screen1_WindshieldVentButton, event_screen1_WindshieldVentButton_OnPressed);
    screen1_WindshieldVentButton->fn->setReleasedEventCallback(screen1_WindshieldVentButton, event_screen1_WindshieldVentButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)screen1_WindshieldVentButton);

    screen1_RearVentButton = leButtonWidget_New();
    screen1_RearVentButton->fn->setPosition(screen1_RearVentButton, 237, 410);
    screen1_RearVentButton->fn->setSize(screen1_RearVentButton, 70, 70);
    screen1_RearVentButton->fn->setBackgroundType(screen1_RearVentButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_RearVentButton->fn->setBorderType(screen1_RearVentButton, LE_WIDGET_BORDER_NONE);
    screen1_RearVentButton->fn->setToggleable(screen1_RearVentButton, LE_TRUE);
    screen1_RearVentButton->fn->setPressedImage(screen1_RearVentButton, (leImage*)&rear_vent_on2);
    screen1_RearVentButton->fn->setReleasedImage(screen1_RearVentButton, (leImage*)&rear_vent_off2);
    screen1_RearVentButton->fn->setPressedOffset(screen1_RearVentButton, 0);
    screen1_RearVentButton->fn->setPressedEventCallback(screen1_RearVentButton, event_screen1_RearVentButton_OnPressed);
    screen1_RearVentButton->fn->setReleasedEventCallback(screen1_RearVentButton, event_screen1_RearVentButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)screen1_RearVentButton);

    screen1_ClimateControlButton = leButtonWidget_New();
    screen1_ClimateControlButton->fn->setPosition(screen1_ClimateControlButton, 507, 411);
    screen1_ClimateControlButton->fn->setSize(screen1_ClimateControlButton, 70, 70);
    screen1_ClimateControlButton->fn->setBackgroundType(screen1_ClimateControlButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_ClimateControlButton->fn->setBorderType(screen1_ClimateControlButton, LE_WIDGET_BORDER_NONE);
    screen1_ClimateControlButton->fn->setToggleable(screen1_ClimateControlButton, LE_TRUE);
    screen1_ClimateControlButton->fn->setPressedImage(screen1_ClimateControlButton, (leImage*)&climate_control_on);
    screen1_ClimateControlButton->fn->setReleasedImage(screen1_ClimateControlButton, (leImage*)&climate_control_off);
    screen1_ClimateControlButton->fn->setPressedOffset(screen1_ClimateControlButton, 0);
    screen1_ClimateControlButton->fn->setPressedEventCallback(screen1_ClimateControlButton, event_screen1_ClimateControlButton_OnPressed);
    screen1_ClimateControlButton->fn->setReleasedEventCallback(screen1_ClimateControlButton, event_screen1_ClimateControlButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)screen1_ClimateControlButton);

    screen1_SeatHeaterButton = leButtonWidget_New();
    screen1_SeatHeaterButton->fn->setPosition(screen1_SeatHeaterButton, 576, 409);
    screen1_SeatHeaterButton->fn->setSize(screen1_SeatHeaterButton, 70, 71);
    screen1_SeatHeaterButton->fn->setBackgroundType(screen1_SeatHeaterButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_SeatHeaterButton->fn->setBorderType(screen1_SeatHeaterButton, LE_WIDGET_BORDER_NONE);
    screen1_SeatHeaterButton->fn->setToggleable(screen1_SeatHeaterButton, LE_TRUE);
    screen1_SeatHeaterButton->fn->setPressedImage(screen1_SeatHeaterButton, (leImage*)&seat_warm_on);
    screen1_SeatHeaterButton->fn->setReleasedImage(screen1_SeatHeaterButton, (leImage*)&seat_warm_off);
    screen1_SeatHeaterButton->fn->setPressedOffset(screen1_SeatHeaterButton, 0);
    screen1_SeatHeaterButton->fn->setPressedEventCallback(screen1_SeatHeaterButton, event_screen1_SeatHeaterButton_OnPressed);
    screen1_SeatHeaterButton->fn->setReleasedEventCallback(screen1_SeatHeaterButton, event_screen1_SeatHeaterButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)screen1_SeatHeaterButton);

    screen1_DriverZoneButton = leButtonWidget_New();
    screen1_DriverZoneButton->fn->setPosition(screen1_DriverZoneButton, 38, 67);
    screen1_DriverZoneButton->fn->setSize(screen1_DriverZoneButton, 110, 170);
    screen1_DriverZoneButton->fn->setBackgroundType(screen1_DriverZoneButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_DriverZoneButton->fn->setBorderType(screen1_DriverZoneButton, LE_WIDGET_BORDER_NONE);
    screen1_DriverZoneButton->fn->setPressedEventCallback(screen1_DriverZoneButton, event_screen1_DriverZoneButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)screen1_DriverZoneButton);

    screen1_FrontPassZoneButton = leButtonWidget_New();
    screen1_FrontPassZoneButton->fn->setPosition(screen1_FrontPassZoneButton, 148, 67);
    screen1_FrontPassZoneButton->fn->setSize(screen1_FrontPassZoneButton, 110, 170);
    screen1_FrontPassZoneButton->fn->setBackgroundType(screen1_FrontPassZoneButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_FrontPassZoneButton->fn->setBorderType(screen1_FrontPassZoneButton, LE_WIDGET_BORDER_NONE);
    screen1_FrontPassZoneButton->fn->setPressedEventCallback(screen1_FrontPassZoneButton, event_screen1_FrontPassZoneButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)screen1_FrontPassZoneButton);

    screen1_RearRightPassZoneButton = leButtonWidget_New();
    screen1_RearRightPassZoneButton->fn->setPosition(screen1_RearRightPassZoneButton, 147, 237);
    screen1_RearRightPassZoneButton->fn->setSize(screen1_RearRightPassZoneButton, 110, 170);
    screen1_RearRightPassZoneButton->fn->setBackgroundType(screen1_RearRightPassZoneButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_RearRightPassZoneButton->fn->setBorderType(screen1_RearRightPassZoneButton, LE_WIDGET_BORDER_NONE);
    screen1_RearRightPassZoneButton->fn->setPressedEventCallback(screen1_RearRightPassZoneButton, event_screen1_RearRightPassZoneButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)screen1_RearRightPassZoneButton);

    screen1_RearLeftPassZoneButton = leButtonWidget_New();
    screen1_RearLeftPassZoneButton->fn->setPosition(screen1_RearLeftPassZoneButton, 37, 237);
    screen1_RearLeftPassZoneButton->fn->setSize(screen1_RearLeftPassZoneButton, 110, 170);
    screen1_RearLeftPassZoneButton->fn->setBackgroundType(screen1_RearLeftPassZoneButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_RearLeftPassZoneButton->fn->setBorderType(screen1_RearLeftPassZoneButton, LE_WIDGET_BORDER_NONE);
    screen1_RearLeftPassZoneButton->fn->setPressedEventCallback(screen1_RearLeftPassZoneButton, event_screen1_RearLeftPassZoneButton_OnPressed);
    root0->fn->addChild(root0, (leWidget*)screen1_RearLeftPassZoneButton);

    screen1_TempImageSequenceWidget = leImageSequenceWidget_New();
    screen1_TempImageSequenceWidget->fn->setPosition(screen1_TempImageSequenceWidget, 356, 215);
    screen1_TempImageSequenceWidget->fn->setSize(screen1_TempImageSequenceWidget, 100, 60);
    screen1_TempImageSequenceWidget->fn->setBackgroundType(screen1_TempImageSequenceWidget, LE_WIDGET_BACKGROUND_NONE);
    screen1_TempImageSequenceWidget->fn->setHAlignment(screen1_TempImageSequenceWidget, LE_HALIGN_RIGHT);
    screen1_TempImageSequenceWidget->fn->setVAlignment(screen1_TempImageSequenceWidget, LE_VALIGN_BOTTOM);
    screen1_TempImageSequenceWidget->fn->setImageCount(screen1_TempImageSequenceWidget, 21);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 0, &deg65);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 0, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 1, &deg66);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 1, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 2, &deg67);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 2, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 3, &deg68);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 3, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 4, &deg69);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 4, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 5, &deg70);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 5, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 6, &deg71);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 6, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 7, &deg72);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 7, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 8, &deg73);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 8, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 9, &deg74);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 9, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 10, &deg75);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 10, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 11, &deg76);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 11, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 12, &deg77);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 12, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 13, &deg78);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 13, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 14, &deg79);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 14, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 15, &deg80);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 15, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 16, &deg81);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 16, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 17, &deg82);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 17, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 18, &deg83);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 18, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 19, &deg84);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 19, 1000);
    screen1_TempImageSequenceWidget->fn->setImage(screen1_TempImageSequenceWidget, 20, &deg85);
    screen1_TempImageSequenceWidget->fn->setImageDelay(screen1_TempImageSequenceWidget, 20, 1000);
    root0->fn->addChild(root0, (leWidget*)screen1_TempImageSequenceWidget);

    screen1_FanLevel1 = leImageSequenceWidget_New();
    screen1_FanLevel1->fn->setPosition(screen1_FanLevel1, 770, 339);
    screen1_FanLevel1->fn->setSize(screen1_FanLevel1, 25, 25);
    screen1_FanLevel1->fn->setScheme(screen1_FanLevel1, &BlackBack);
    screen1_FanLevel1->fn->setBackgroundType(screen1_FanLevel1, LE_WIDGET_BACKGROUND_NONE);
    screen1_FanLevel1->fn->setHAlignment(screen1_FanLevel1, LE_HALIGN_RIGHT);
    screen1_FanLevel1->fn->setVAlignment(screen1_FanLevel1, LE_VALIGN_BOTTOM);
    screen1_FanLevel1->fn->setImageCount(screen1_FanLevel1, 2);
    screen1_FanLevel1->fn->setImage(screen1_FanLevel1, 0, &circle_nofill);
    screen1_FanLevel1->fn->setImageDelay(screen1_FanLevel1, 0, 1000);
    screen1_FanLevel1->fn->setImage(screen1_FanLevel1, 1, &circle_fill);
    screen1_FanLevel1->fn->setImageDelay(screen1_FanLevel1, 1, 1000);
    root0->fn->addChild(root0, (leWidget*)screen1_FanLevel1);

    screen1_FanLevel2 = leImageSequenceWidget_New();
    screen1_FanLevel2->fn->setPosition(screen1_FanLevel2, 770, 301);
    screen1_FanLevel2->fn->setSize(screen1_FanLevel2, 25, 25);
    screen1_FanLevel2->fn->setBackgroundType(screen1_FanLevel2, LE_WIDGET_BACKGROUND_NONE);
    screen1_FanLevel2->fn->setHAlignment(screen1_FanLevel2, LE_HALIGN_RIGHT);
    screen1_FanLevel2->fn->setVAlignment(screen1_FanLevel2, LE_VALIGN_BOTTOM);
    screen1_FanLevel2->fn->setImageCount(screen1_FanLevel2, 2);
    screen1_FanLevel2->fn->setImage(screen1_FanLevel2, 0, &circle_nofill);
    screen1_FanLevel2->fn->setImageDelay(screen1_FanLevel2, 0, 1000);
    screen1_FanLevel2->fn->setImage(screen1_FanLevel2, 1, &circle_fill);
    screen1_FanLevel2->fn->setImageDelay(screen1_FanLevel2, 1, 1000);
    root0->fn->addChild(root0, (leWidget*)screen1_FanLevel2);

    screen1_FanLevel3 = leImageSequenceWidget_New();
    screen1_FanLevel3->fn->setPosition(screen1_FanLevel3, 770, 262);
    screen1_FanLevel3->fn->setSize(screen1_FanLevel3, 25, 25);
    screen1_FanLevel3->fn->setBackgroundType(screen1_FanLevel3, LE_WIDGET_BACKGROUND_NONE);
    screen1_FanLevel3->fn->setHAlignment(screen1_FanLevel3, LE_HALIGN_RIGHT);
    screen1_FanLevel3->fn->setVAlignment(screen1_FanLevel3, LE_VALIGN_BOTTOM);
    screen1_FanLevel3->fn->setImageCount(screen1_FanLevel3, 2);
    screen1_FanLevel3->fn->setImage(screen1_FanLevel3, 0, &circle_nofill);
    screen1_FanLevel3->fn->setImageDelay(screen1_FanLevel3, 0, 1000);
    screen1_FanLevel3->fn->setImage(screen1_FanLevel3, 1, &circle_fill);
    screen1_FanLevel3->fn->setImageDelay(screen1_FanLevel3, 1, 1000);
    root0->fn->addChild(root0, (leWidget*)screen1_FanLevel3);

    screen1_FanLevel4 = leImageSequenceWidget_New();
    screen1_FanLevel4->fn->setPosition(screen1_FanLevel4, 770, 223);
    screen1_FanLevel4->fn->setSize(screen1_FanLevel4, 25, 25);
    screen1_FanLevel4->fn->setBackgroundType(screen1_FanLevel4, LE_WIDGET_BACKGROUND_NONE);
    screen1_FanLevel4->fn->setHAlignment(screen1_FanLevel4, LE_HALIGN_RIGHT);
    screen1_FanLevel4->fn->setVAlignment(screen1_FanLevel4, LE_VALIGN_BOTTOM);
    screen1_FanLevel4->fn->setImageCount(screen1_FanLevel4, 2);
    screen1_FanLevel4->fn->setImage(screen1_FanLevel4, 0, &circle_nofill);
    screen1_FanLevel4->fn->setImageDelay(screen1_FanLevel4, 0, 1000);
    screen1_FanLevel4->fn->setImage(screen1_FanLevel4, 1, &circle_fill);
    screen1_FanLevel4->fn->setImageDelay(screen1_FanLevel4, 1, 1000);
    root0->fn->addChild(root0, (leWidget*)screen1_FanLevel4);

    screen1_FanLevel5 = leImageSequenceWidget_New();
    screen1_FanLevel5->fn->setPosition(screen1_FanLevel5, 770, 185);
    screen1_FanLevel5->fn->setSize(screen1_FanLevel5, 25, 25);
    screen1_FanLevel5->fn->setBackgroundType(screen1_FanLevel5, LE_WIDGET_BACKGROUND_NONE);
    screen1_FanLevel5->fn->setHAlignment(screen1_FanLevel5, LE_HALIGN_RIGHT);
    screen1_FanLevel5->fn->setVAlignment(screen1_FanLevel5, LE_VALIGN_BOTTOM);
    screen1_FanLevel5->fn->setImageCount(screen1_FanLevel5, 2);
    screen1_FanLevel5->fn->setImage(screen1_FanLevel5, 0, &circle_nofill);
    screen1_FanLevel5->fn->setImageDelay(screen1_FanLevel5, 0, 1000);
    screen1_FanLevel5->fn->setImage(screen1_FanLevel5, 1, &circle_fill);
    screen1_FanLevel5->fn->setImageDelay(screen1_FanLevel5, 1, 1000);
    root0->fn->addChild(root0, (leWidget*)screen1_FanLevel5);

    screen1_FanLevel6 = leImageSequenceWidget_New();
    screen1_FanLevel6->fn->setPosition(screen1_FanLevel6, 770, 146);
    screen1_FanLevel6->fn->setSize(screen1_FanLevel6, 25, 25);
    screen1_FanLevel6->fn->setScheme(screen1_FanLevel6, &ClearScheme);
    screen1_FanLevel6->fn->setBackgroundType(screen1_FanLevel6, LE_WIDGET_BACKGROUND_NONE);
    screen1_FanLevel6->fn->setHAlignment(screen1_FanLevel6, LE_HALIGN_RIGHT);
    screen1_FanLevel6->fn->setVAlignment(screen1_FanLevel6, LE_VALIGN_BOTTOM);
    screen1_FanLevel6->fn->setImageCount(screen1_FanLevel6, 2);
    screen1_FanLevel6->fn->setImage(screen1_FanLevel6, 0, &circle_nofill);
    screen1_FanLevel6->fn->setImageDelay(screen1_FanLevel6, 0, 1000);
    screen1_FanLevel6->fn->setImage(screen1_FanLevel6, 1, &circle_fill);
    screen1_FanLevel6->fn->setImageDelay(screen1_FanLevel6, 1, 1000);
    root0->fn->addChild(root0, (leWidget*)screen1_FanLevel6);

    screen1_ZoneImageSequence = leImageSequenceWidget_New();
    screen1_ZoneImageSequence->fn->setPosition(screen1_ZoneImageSequence, 314, 73);
    screen1_ZoneImageSequence->fn->setSize(screen1_ZoneImageSequence, 180, 36);
    screen1_ZoneImageSequence->fn->setBackgroundType(screen1_ZoneImageSequence, LE_WIDGET_BACKGROUND_NONE);
    screen1_ZoneImageSequence->fn->setHAlignment(screen1_ZoneImageSequence, LE_HALIGN_RIGHT);
    screen1_ZoneImageSequence->fn->setVAlignment(screen1_ZoneImageSequence, LE_VALIGN_BOTTOM);
    screen1_ZoneImageSequence->fn->setImageCount(screen1_ZoneImageSequence, 4);
    screen1_ZoneImageSequence->fn->setImage(screen1_ZoneImageSequence, 0, &Driver);
    screen1_ZoneImageSequence->fn->setImageDelay(screen1_ZoneImageSequence, 0, 1000);
    screen1_ZoneImageSequence->fn->setImage(screen1_ZoneImageSequence, 1, &FontPassenger);
    screen1_ZoneImageSequence->fn->setImageDelay(screen1_ZoneImageSequence, 1, 1000);
    screen1_ZoneImageSequence->fn->setImage(screen1_ZoneImageSequence, 2, &LeftPassenger);
    screen1_ZoneImageSequence->fn->setImageDelay(screen1_ZoneImageSequence, 2, 1000);
    screen1_ZoneImageSequence->fn->setImage(screen1_ZoneImageSequence, 3, &RightPassenger);
    screen1_ZoneImageSequence->fn->setImageDelay(screen1_ZoneImageSequence, 3, 1000);
    root0->fn->addChild(root0, (leWidget*)screen1_ZoneImageSequence);

    screen1_TempControlButton = leButtonWidget_New();
    screen1_TempControlButton->fn->setPosition(screen1_TempControlButton, 315, 131);
    screen1_TempControlButton->fn->setSize(screen1_TempControlButton, 178, 238);
    screen1_TempControlButton->fn->setBackgroundType(screen1_TempControlButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_TempControlButton->fn->setBorderType(screen1_TempControlButton, LE_WIDGET_BORDER_NONE);
    root0->fn->addChild(root0, (leWidget*)screen1_TempControlButton);

    screen1_SyncButton = leButtonWidget_New();
    screen1_SyncButton->fn->setPosition(screen1_SyncButton, 313, 366);
    screen1_SyncButton->fn->setSize(screen1_SyncButton, 180, 60);
    screen1_SyncButton->fn->setBackgroundType(screen1_SyncButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_SyncButton->fn->setBorderType(screen1_SyncButton, LE_WIDGET_BORDER_NONE);
    screen1_SyncButton->fn->setToggleable(screen1_SyncButton, LE_TRUE);
    screen1_SyncButton->fn->setPressed(screen1_SyncButton, LE_TRUE);
    screen1_SyncButton->fn->setPressedImage(screen1_SyncButton, (leImage*)&syncOn_rs);
    screen1_SyncButton->fn->setReleasedImage(screen1_SyncButton, (leImage*)&syncOff_rs);
    screen1_SyncButton->fn->setPressedOffset(screen1_SyncButton, 0);
    screen1_SyncButton->fn->setPressedEventCallback(screen1_SyncButton, event_screen1_SyncButton_OnPressed);
    screen1_SyncButton->fn->setReleasedEventCallback(screen1_SyncButton, event_screen1_SyncButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)screen1_SyncButton);

    screen1_HighVentButton = leButtonWidget_New();
    screen1_HighVentButton->fn->setPosition(screen1_HighVentButton, 523, 120);
    screen1_HighVentButton->fn->setSize(screen1_HighVentButton, 206, 80);
    screen1_HighVentButton->fn->setBackgroundType(screen1_HighVentButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_HighVentButton->fn->setBorderType(screen1_HighVentButton, LE_WIDGET_BORDER_NONE);
    screen1_HighVentButton->fn->setHAlignment(screen1_HighVentButton, LE_HALIGN_LEFT);
    screen1_HighVentButton->fn->setMargins(screen1_HighVentButton, 50, 4, 4, 4);
    screen1_HighVentButton->fn->setToggleable(screen1_HighVentButton, LE_TRUE);
    screen1_HighVentButton->fn->setPressedImage(screen1_HighVentButton, (leImage*)&breeze_on);
    screen1_HighVentButton->fn->setReleasedImage(screen1_HighVentButton, (leImage*)&breeze_off);
    screen1_HighVentButton->fn->setPressedOffset(screen1_HighVentButton, 0);
    screen1_HighVentButton->fn->setPressedEventCallback(screen1_HighVentButton, event_screen1_HighVentButton_OnPressed);
    screen1_HighVentButton->fn->setReleasedEventCallback(screen1_HighVentButton, event_screen1_HighVentButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)screen1_HighVentButton);

    screen1_MidVentButton = leButtonWidget_New();
    screen1_MidVentButton->fn->setPosition(screen1_MidVentButton, 523, 201);
    screen1_MidVentButton->fn->setSize(screen1_MidVentButton, 207, 74);
    screen1_MidVentButton->fn->setBackgroundType(screen1_MidVentButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_MidVentButton->fn->setBorderType(screen1_MidVentButton, LE_WIDGET_BORDER_NONE);
    screen1_MidVentButton->fn->setHAlignment(screen1_MidVentButton, LE_HALIGN_LEFT);
    screen1_MidVentButton->fn->setMargins(screen1_MidVentButton, 40, 4, 4, 4);
    screen1_MidVentButton->fn->setToggleable(screen1_MidVentButton, LE_TRUE);
    screen1_MidVentButton->fn->setPressedImage(screen1_MidVentButton, (leImage*)&breeze_on);
    screen1_MidVentButton->fn->setReleasedImage(screen1_MidVentButton, (leImage*)&breeze_off);
    screen1_MidVentButton->fn->setImageMargin(screen1_MidVentButton, 0);
    screen1_MidVentButton->fn->setPressedOffset(screen1_MidVentButton, 0);
    screen1_MidVentButton->fn->setPressedEventCallback(screen1_MidVentButton, event_screen1_MidVentButton_OnPressed);
    screen1_MidVentButton->fn->setReleasedEventCallback(screen1_MidVentButton, event_screen1_MidVentButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)screen1_MidVentButton);

    screen1_LowVentButton = leButtonWidget_New();
    screen1_LowVentButton->fn->setPosition(screen1_LowVentButton, 523, 275);
    screen1_LowVentButton->fn->setSize(screen1_LowVentButton, 210, 81);
    screen1_LowVentButton->fn->setBackgroundType(screen1_LowVentButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_LowVentButton->fn->setBorderType(screen1_LowVentButton, LE_WIDGET_BORDER_NONE);
    screen1_LowVentButton->fn->setHAlignment(screen1_LowVentButton, LE_HALIGN_LEFT);
    screen1_LowVentButton->fn->setMargins(screen1_LowVentButton, 50, 4, 4, 4);
    screen1_LowVentButton->fn->setToggleable(screen1_LowVentButton, LE_TRUE);
    screen1_LowVentButton->fn->setPressedImage(screen1_LowVentButton, (leImage*)&breeze_on);
    screen1_LowVentButton->fn->setReleasedImage(screen1_LowVentButton, (leImage*)&breeze_off);
    screen1_LowVentButton->fn->setImageMargin(screen1_LowVentButton, 0);
    screen1_LowVentButton->fn->setPressedOffset(screen1_LowVentButton, 0);
    screen1_LowVentButton->fn->setPressedEventCallback(screen1_LowVentButton, event_screen1_LowVentButton_OnPressed);
    screen1_LowVentButton->fn->setReleasedEventCallback(screen1_LowVentButton, event_screen1_LowVentButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)screen1_LowVentButton);

    screen1_FanButtonWidget = leButtonWidget_New();
    screen1_FanButtonWidget->fn->setPosition(screen1_FanButtonWidget, 741, 73);
    screen1_FanButtonWidget->fn->setSize(screen1_FanButtonWidget, 57, 345);
    screen1_FanButtonWidget->fn->setBackgroundType(screen1_FanButtonWidget, LE_WIDGET_BACKGROUND_NONE);
    screen1_FanButtonWidget->fn->setBorderType(screen1_FanButtonWidget, LE_WIDGET_BORDER_NONE);
    screen1_FanButtonWidget->fn->setPressedOffset(screen1_FanButtonWidget, 0);
    root0->fn->addChild(root0, (leWidget*)screen1_FanButtonWidget);

    screen1_InfoPageButton = leButtonWidget_New();
    screen1_InfoPageButton->fn->setPosition(screen1_InfoPageButton, 473, 0);
    screen1_InfoPageButton->fn->setSize(screen1_InfoPageButton, 327, 60);
    screen1_InfoPageButton->fn->setBackgroundType(screen1_InfoPageButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_InfoPageButton->fn->setBorderType(screen1_InfoPageButton, LE_WIDGET_BORDER_NONE);
    screen1_InfoPageButton->fn->setToggleable(screen1_InfoPageButton, LE_TRUE);
    screen1_InfoPageButton->fn->setPressedEventCallback(screen1_InfoPageButton, event_screen1_InfoPageButton_OnPressed);
    screen1_InfoPageButton->fn->setReleasedEventCallback(screen1_InfoPageButton, event_screen1_InfoPageButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)screen1_InfoPageButton);

    screen1_mchpButton = leButtonWidget_New();
    screen1_mchpButton->fn->setPosition(screen1_mchpButton, 646, 426);
    screen1_mchpButton->fn->setSize(screen1_mchpButton, 154, 54);
    screen1_mchpButton->fn->setBackgroundType(screen1_mchpButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_mchpButton->fn->setBorderType(screen1_mchpButton, LE_WIDGET_BORDER_NONE);
    screen1_mchpButton->fn->setToggleable(screen1_mchpButton, LE_TRUE);
    screen1_mchpButton->fn->setPressedEventCallback(screen1_mchpButton, event_screen1_mchpButton_OnPressed);
    screen1_mchpButton->fn->setReleasedEventCallback(screen1_mchpButton, event_screen1_mchpButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)screen1_mchpButton);

    screen1_AirconButton = leButtonWidget_New();
    screen1_AirconButton->fn->setPosition(screen1_AirconButton, 8, 410);
    screen1_AirconButton->fn->setSize(screen1_AirconButton, 70, 70);
    screen1_AirconButton->fn->setBackgroundType(screen1_AirconButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_AirconButton->fn->setBorderType(screen1_AirconButton, LE_WIDGET_BORDER_NONE);
    screen1_AirconButton->fn->setToggleable(screen1_AirconButton, LE_TRUE);
    screen1_AirconButton->fn->setPressedImage(screen1_AirconButton, (leImage*)&aircon_on2);
    screen1_AirconButton->fn->setReleasedImage(screen1_AirconButton, (leImage*)&aircon_off2);
    screen1_AirconButton->fn->setPressedOffset(screen1_AirconButton, 0);
    screen1_AirconButton->fn->setPressedEventCallback(screen1_AirconButton, event_screen1_AirconButton_OnPressed);
    screen1_AirconButton->fn->setReleasedEventCallback(screen1_AirconButton, event_screen1_AirconButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)screen1_AirconButton);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_INDEX_8);

    // layer 1
    root1 = leWidget_New();
    root1->fn->setSize(root1, 300, 350);
    root1->fn->setBackgroundType(root1, LE_WIDGET_BACKGROUND_NONE);
    root1->fn->setMargins(root1, 0, 0, 0, 0);
    root1->flags |= LE_WIDGET_IGNOREEVENTS;
    root1->flags |= LE_WIDGET_IGNOREPICK;

    screen1_PanelWidget1 = leWidget_New();
    screen1_PanelWidget1->fn->setPosition(screen1_PanelWidget1, 0, 0);
    screen1_PanelWidget1->fn->setSize(screen1_PanelWidget1, 300, 350);
    screen1_PanelWidget1->fn->setEnabled(screen1_PanelWidget1, LE_FALSE);
    screen1_PanelWidget1->fn->setScheme(screen1_PanelWidget1, &BlackBack);
    root1->fn->addChild(root1, (leWidget*)screen1_PanelWidget1);

    screen1_ImageWidget1 = leImageWidget_New();
    screen1_ImageWidget1->fn->setPosition(screen1_ImageWidget1, 0, 0);
    screen1_ImageWidget1->fn->setSize(screen1_ImageWidget1, 300, 350);
    screen1_ImageWidget1->fn->setEnabled(screen1_ImageWidget1, LE_FALSE);
    screen1_ImageWidget1->fn->setBackgroundType(screen1_ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    screen1_ImageWidget1->fn->setBorderType(screen1_ImageWidget1, LE_WIDGET_BORDER_NONE);
    screen1_ImageWidget1->fn->setImage(screen1_ImageWidget1, (leImage*)&InfoPage);
    root1->fn->addChild(root1, (leWidget*)screen1_ImageWidget1);

    leAddRootWidget(root1, 1);
    leSetLayerColorMode(1, LE_COLOR_MODE_INDEX_8);

    // layer 2
    root2 = leWidget_New();
    root2->fn->setSize(root2, 400, 50);
    root2->fn->setBackgroundType(root2, LE_WIDGET_BACKGROUND_NONE);
    root2->fn->setMargins(root2, 0, 0, 0, 0);
    root2->flags |= LE_WIDGET_IGNOREEVENTS;
    root2->flags |= LE_WIDGET_IGNOREPICK;

    screen1_PanelWidget0 = leWidget_New();
    screen1_PanelWidget0->fn->setPosition(screen1_PanelWidget0, 0, 0);
    screen1_PanelWidget0->fn->setSize(screen1_PanelWidget0, 400, 50);
    screen1_PanelWidget0->fn->setEnabled(screen1_PanelWidget0, LE_FALSE);
    screen1_PanelWidget0->fn->setScheme(screen1_PanelWidget0, &BlackBack);
    root2->fn->addChild(root2, (leWidget*)screen1_PanelWidget0);

    screen1_HourTimeWidget = leImageSequenceWidget_New();
    screen1_HourTimeWidget->fn->setPosition(screen1_HourTimeWidget, 251, 0);
    screen1_HourTimeWidget->fn->setSize(screen1_HourTimeWidget, 55, 50);
    screen1_HourTimeWidget->fn->setBackgroundType(screen1_HourTimeWidget, LE_WIDGET_BACKGROUND_NONE);
    screen1_HourTimeWidget->fn->setHAlignment(screen1_HourTimeWidget, LE_HALIGN_RIGHT);
    screen1_HourTimeWidget->fn->setVAlignment(screen1_HourTimeWidget, LE_VALIGN_BOTTOM);
    screen1_HourTimeWidget->fn->setRepeat(screen1_HourTimeWidget, LE_TRUE);
    screen1_HourTimeWidget->fn->setImageCount(screen1_HourTimeWidget, 12);
    screen1_HourTimeWidget->fn->setImage(screen1_HourTimeWidget, 0, &h12);
    screen1_HourTimeWidget->fn->setImageDelay(screen1_HourTimeWidget, 0, 1000);
    screen1_HourTimeWidget->fn->setImage(screen1_HourTimeWidget, 1, &h1);
    screen1_HourTimeWidget->fn->setImageDelay(screen1_HourTimeWidget, 1, 1000);
    screen1_HourTimeWidget->fn->setImage(screen1_HourTimeWidget, 2, &h2);
    screen1_HourTimeWidget->fn->setImageDelay(screen1_HourTimeWidget, 2, 1000);
    screen1_HourTimeWidget->fn->setImage(screen1_HourTimeWidget, 3, &h3);
    screen1_HourTimeWidget->fn->setImageDelay(screen1_HourTimeWidget, 3, 1000);
    screen1_HourTimeWidget->fn->setImage(screen1_HourTimeWidget, 4, &h4);
    screen1_HourTimeWidget->fn->setImageDelay(screen1_HourTimeWidget, 4, 1000);
    screen1_HourTimeWidget->fn->setImage(screen1_HourTimeWidget, 5, &h5);
    screen1_HourTimeWidget->fn->setImageDelay(screen1_HourTimeWidget, 5, 1000);
    screen1_HourTimeWidget->fn->setImage(screen1_HourTimeWidget, 6, &h6);
    screen1_HourTimeWidget->fn->setImageDelay(screen1_HourTimeWidget, 6, 1000);
    screen1_HourTimeWidget->fn->setImage(screen1_HourTimeWidget, 7, &h7);
    screen1_HourTimeWidget->fn->setImageDelay(screen1_HourTimeWidget, 7, 1000);
    screen1_HourTimeWidget->fn->setImage(screen1_HourTimeWidget, 8, &h8);
    screen1_HourTimeWidget->fn->setImageDelay(screen1_HourTimeWidget, 8, 1000);
    screen1_HourTimeWidget->fn->setImage(screen1_HourTimeWidget, 9, &h9);
    screen1_HourTimeWidget->fn->setImageDelay(screen1_HourTimeWidget, 9, 1000);
    screen1_HourTimeWidget->fn->setImage(screen1_HourTimeWidget, 10, &h10);
    screen1_HourTimeWidget->fn->setImageDelay(screen1_HourTimeWidget, 10, 1000);
    screen1_HourTimeWidget->fn->setImage(screen1_HourTimeWidget, 11, &h11);
    screen1_HourTimeWidget->fn->setImageDelay(screen1_HourTimeWidget, 11, 1000);
    root2->fn->addChild(root2, (leWidget*)screen1_HourTimeWidget);

    screen1_ColonImage = leImageWidget_New();
    screen1_ColonImage->fn->setPosition(screen1_ColonImage, 307, 16);
    screen1_ColonImage->fn->setSize(screen1_ColonImage, 10, 23);
    screen1_ColonImage->fn->setScheme(screen1_ColonImage, &BlackBack);
    screen1_ColonImage->fn->setBorderType(screen1_ColonImage, LE_WIDGET_BORDER_NONE);
    screen1_ColonImage->fn->setImage(screen1_ColonImage, (leImage*)&colon);
    root2->fn->addChild(root2, (leWidget*)screen1_ColonImage);

    screen1_MinuteTimeWidget = leImageSequenceWidget_New();
    screen1_MinuteTimeWidget->fn->setPosition(screen1_MinuteTimeWidget, 319, 6);
    screen1_MinuteTimeWidget->fn->setSize(screen1_MinuteTimeWidget, 41, 40);
    screen1_MinuteTimeWidget->fn->setBackgroundType(screen1_MinuteTimeWidget, LE_WIDGET_BACKGROUND_NONE);
    screen1_MinuteTimeWidget->fn->setHAlignment(screen1_MinuteTimeWidget, LE_HALIGN_RIGHT);
    screen1_MinuteTimeWidget->fn->setVAlignment(screen1_MinuteTimeWidget, LE_VALIGN_BOTTOM);
    screen1_MinuteTimeWidget->fn->setRepeat(screen1_MinuteTimeWidget, LE_TRUE);
    screen1_MinuteTimeWidget->fn->setImageCount(screen1_MinuteTimeWidget, 60);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 0, &m00);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 0, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 1, &m01);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 1, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 2, &m02);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 2, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 3, &m03);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 3, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 4, &m04);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 4, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 5, &m05);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 5, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 6, &m06);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 6, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 7, &m07);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 7, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 8, &m08);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 8, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 9, &m09);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 9, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 10, &m10);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 10, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 11, &m11);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 11, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 12, &m12);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 12, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 13, &m13);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 13, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 14, &m14);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 14, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 15, &m15);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 15, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 16, &m16);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 16, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 17, &m17);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 17, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 18, &m18);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 18, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 19, &m19);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 19, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 20, &m20);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 20, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 21, &m21);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 21, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 22, &m22);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 22, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 23, &m23);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 23, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 24, &m24);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 24, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 25, &m25);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 25, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 26, &m26);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 26, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 27, &m27);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 27, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 28, &m28);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 28, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 29, &m29);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 29, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 30, &m30);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 30, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 31, &m31);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 31, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 32, &m32);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 32, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 33, &m33);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 33, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 34, &m34);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 34, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 35, &m35);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 35, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 36, &m36);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 36, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 37, &m37);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 37, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 38, &m38);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 38, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 39, &m39);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 39, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 40, &m40);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 40, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 41, &m41);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 41, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 42, &m42);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 42, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 43, &m43);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 43, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 44, &m44);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 44, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 45, &m45);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 45, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 46, &m46);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 46, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 47, &m47);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 47, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 48, &m48);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 48, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 49, &m49);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 49, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 50, &m50);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 50, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 51, &m51);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 51, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 52, &m52);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 52, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 53, &m53);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 53, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 54, &m54);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 54, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 55, &m55);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 55, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 56, &m56);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 56, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 57, &m57);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 57, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 58, &m58);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 58, 1000);
    screen1_MinuteTimeWidget->fn->setImage(screen1_MinuteTimeWidget, 59, &m59);
    screen1_MinuteTimeWidget->fn->setImageDelay(screen1_MinuteTimeWidget, 59, 1000);
    root2->fn->addChild(root2, (leWidget*)screen1_MinuteTimeWidget);

    screen1_AMImageWidget = leImageWidget_New();
    screen1_AMImageWidget->fn->setPosition(screen1_AMImageWidget, 360, 19);
    screen1_AMImageWidget->fn->setSize(screen1_AMImageWidget, 27, 23);
    screen1_AMImageWidget->fn->setBackgroundType(screen1_AMImageWidget, LE_WIDGET_BACKGROUND_NONE);
    screen1_AMImageWidget->fn->setBorderType(screen1_AMImageWidget, LE_WIDGET_BORDER_NONE);
    screen1_AMImageWidget->fn->setImage(screen1_AMImageWidget, (leImage*)&AM);
    root2->fn->addChild(root2, (leWidget*)screen1_AMImageWidget);

    screen1_ImageWidget2 = leImageWidget_New();
    screen1_ImageWidget2->fn->setPosition(screen1_ImageWidget2, -1, 1);
    screen1_ImageWidget2->fn->setSize(screen1_ImageWidget2, 252, 50);
    screen1_ImageWidget2->fn->setScheme(screen1_ImageWidget2, &BlackBack);
    screen1_ImageWidget2->fn->setBorderType(screen1_ImageWidget2, LE_WIDGET_BORDER_NONE);
    screen1_ImageWidget2->fn->setImage(screen1_ImageWidget2, (leImage*)&weather);
    root2->fn->addChild(root2, (leWidget*)screen1_ImageWidget2);

    screen1_TopBannerButton = leButtonWidget_New();
    screen1_TopBannerButton->fn->setPosition(screen1_TopBannerButton, 0, 0);
    screen1_TopBannerButton->fn->setSize(screen1_TopBannerButton, 400, 50);
    screen1_TopBannerButton->fn->setBackgroundType(screen1_TopBannerButton, LE_WIDGET_BACKGROUND_NONE);
    screen1_TopBannerButton->fn->setBorderType(screen1_TopBannerButton, LE_WIDGET_BORDER_NONE);
    screen1_TopBannerButton->fn->setToggleable(screen1_TopBannerButton, LE_TRUE);
    screen1_TopBannerButton->fn->setPressedEventCallback(screen1_TopBannerButton, event_screen1_TopBannerButton_OnPressed);
    screen1_TopBannerButton->fn->setReleasedEventCallback(screen1_TopBannerButton, event_screen1_TopBannerButton_OnReleased);
    root2->fn->addChild(root2, (leWidget*)screen1_TopBannerButton);

    leAddRootWidget(root2, 2);
    leSetLayerColorMode(2, LE_COLOR_MODE_INDEX_8);

    screen1_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_screen1()
{
    screen1_OnUpdate(); // raise event
}

void screenHide_screen1()
{
    screen1_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    screen1_BackgroundImage = NULL;
    screen1_RecirculateButton = NULL;
    screen1_WindshieldVentButton = NULL;
    screen1_RearVentButton = NULL;
    screen1_ClimateControlButton = NULL;
    screen1_SeatHeaterButton = NULL;
    screen1_DriverZoneButton = NULL;
    screen1_FrontPassZoneButton = NULL;
    screen1_RearRightPassZoneButton = NULL;
    screen1_RearLeftPassZoneButton = NULL;
    screen1_TempImageSequenceWidget = NULL;
    screen1_FanLevel1 = NULL;
    screen1_FanLevel2 = NULL;
    screen1_FanLevel3 = NULL;
    screen1_FanLevel4 = NULL;
    screen1_FanLevel5 = NULL;
    screen1_FanLevel6 = NULL;
    screen1_ZoneImageSequence = NULL;
    screen1_TempControlButton = NULL;
    screen1_SyncButton = NULL;
    screen1_HighVentButton = NULL;
    screen1_MidVentButton = NULL;
    screen1_LowVentButton = NULL;
    screen1_FanButtonWidget = NULL;
    screen1_InfoPageButton = NULL;
    screen1_mchpButton = NULL;
    screen1_AirconButton = NULL;

    leRemoveRootWidget(root1, 1);
    leWidget_Delete(root1);
    root1 = NULL;

    screen1_PanelWidget1 = NULL;
    screen1_ImageWidget1 = NULL;

    leRemoveRootWidget(root2, 2);
    leWidget_Delete(root2);
    root2 = NULL;

    screen1_PanelWidget0 = NULL;
    screen1_HourTimeWidget = NULL;
    screen1_ColonImage = NULL;
    screen1_MinuteTimeWidget = NULL;
    screen1_AMImageWidget = NULL;
    screen1_ImageWidget2 = NULL;
    screen1_TopBannerButton = NULL;


    showing = LE_FALSE;
}

void screenDestroy_screen1()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_screen1(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        case 1:
        {
            return root1;
        }
        case 2:
        {
            return root2;
        }
        default:
        {
            return NULL;
        }
    }
}

