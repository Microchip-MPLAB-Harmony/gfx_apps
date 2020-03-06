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

#include "gfx/legato/generated/screen/le_gen_screen_ColorScreen.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget2;
leWidget* PanelWidget5;
leRectangleWidget* ProgressRect;
leWidget* PanelWidget4;
leButtonWidget* ReheatButtonWidget;
leButtonWidget* CookButtonWidget;
leButtonWidget* ButtonWidget5;
leWidget* QuickSelectionsPanel;
leWidget* MenuItem1;
leRectangleWidget* ButtonRect1Back;
leRectangleWidget* Button1Rect;
leImageWidget* ButtonImage1;
leLabelWidget* MenuItem1Label;
leButtonWidget* ButtonWidget1;
leLabelWidget* LabelWidget2;
leWidget* MenuItem2;
leRectangleWidget* Button2RectBack;
leRectangleWidget* Button2Rect;
leImageWidget* ButtonImage2;
leLabelWidget* MenuItem2Label;
leButtonWidget* ButtonWidget2;
leWidget* MenuItem3;
leRectangleWidget* Button3RectBack;
leRectangleWidget* Button3Rect;
leImageWidget* ButtonImage3;
leLabelWidget* MenuItem3Label;
leButtonWidget* ButtonWidget3;
leWidget* MenuItem4;
leRectangleWidget* Button4RectBack;
leRectangleWidget* Button4Rect;
leImageWidget* Button4Image;
leLabelWidget* MenuItem4Label;
leButtonWidget* ButtonWidget4;
leWidget* Screen2MainClockPanel;
leLabelWidget* Screen2HourLabel;
leLabelWidget* Screen2ColonLabel;
leLabelWidget* Screen2MinuteLabel;
leWidget* Screen2LabelPanel;
leLabelWidget* Screen2GoodLabel;
leLabelWidget* Screen2BytesLabel;
leLabelWidget* Screen2SmartCookerLabel;
leButtonWidget* ButtonWidget6;
leButtonWidget* SliderButton2;

// string list for this screen
static leTableString tableString_SteakMenuItem;
static leTableString tableString_QuickItems;
static leTableString tableString_SalmonMenuItem;
static leTableString tableString_PizzaMenuItem;
static leTableString tableString_Pasta;
static leTableString tableString_DefaultHour2;
static leTableString tableString_Colon;
static leTableString tableString_DefaultMinute2;
static leTableString tableString_GoodBytes;
static leTableString tableString_Bytes;
static leTableString tableString_SmartCooker;

static leBool showing = LE_FALSE;

leResult screenInit_ColorScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_ColorScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_SteakMenuItem, string_SteakMenuItem);
    leTableString_Constructor(&tableString_QuickItems, string_QuickItems);
    leTableString_Constructor(&tableString_SalmonMenuItem, string_SalmonMenuItem);
    leTableString_Constructor(&tableString_PizzaMenuItem, string_PizzaMenuItem);
    leTableString_Constructor(&tableString_Pasta, string_Pasta);
    leTableString_Constructor(&tableString_DefaultHour2, string_DefaultHour2);
    leTableString_Constructor(&tableString_Colon, string_Colon);
    leTableString_Constructor(&tableString_DefaultMinute2, string_DefaultMinute2);
    leTableString_Constructor(&tableString_GoodBytes, string_GoodBytes);
    leTableString_Constructor(&tableString_Bytes, string_Bytes);
    leTableString_Constructor(&tableString_SmartCooker, string_SmartCooker);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget2 = leWidget_New();
    PanelWidget2->fn->setPosition(PanelWidget2, 0, 0);
    PanelWidget2->fn->setSize(PanelWidget2, 480, 320);
    PanelWidget2->fn->setScheme(PanelWidget2, &WhiteBackgroundScheme);
    root0->fn->addChild(root0, PanelWidget2);

    PanelWidget5 = leWidget_New();
    PanelWidget5->fn->setPosition(PanelWidget5, 212, 22);
    PanelWidget5->fn->setSize(PanelWidget5, 153, 290);
    PanelWidget5->fn->setScheme(PanelWidget5, &VeryDarkGrayScheme);
    root0->fn->addChild(root0, PanelWidget5);

    ProgressRect = leRectangleWidget_New();
    ProgressRect->fn->setPosition(ProgressRect, 0, 30);
    ProgressRect->fn->setSize(ProgressRect, 153, 260);
    ProgressRect->fn->setScheme(ProgressRect, &Button1Scheme);
    ProgressRect->fn->setThickness(ProgressRect, 0);
    PanelWidget5->fn->addChild(PanelWidget5, (leWidget*)ProgressRect);

    PanelWidget4 = leWidget_New();
    PanelWidget4->fn->setPosition(PanelWidget4, 365, 0);
    PanelWidget4->fn->setSize(PanelWidget4, 115, 320);
    PanelWidget4->fn->setScheme(PanelWidget4, &RightPanelScheme);
    root0->fn->addChild(root0, PanelWidget4);

    ReheatButtonWidget = leButtonWidget_New();
    ReheatButtonWidget->fn->setPosition(ReheatButtonWidget, 5, 173);
    ReheatButtonWidget->fn->setSize(ReheatButtonWidget, 110, 91);
    ReheatButtonWidget->fn->setScheme(ReheatButtonWidget, &BlackBackground);
    ReheatButtonWidget->fn->setBackgroundType(ReheatButtonWidget, LE_WIDGET_BACKGROUND_NONE);
    ReheatButtonWidget->fn->setBorderType(ReheatButtonWidget, LE_WIDGET_BORDER_NONE);
    ReheatButtonWidget->fn->setPressedImage(ReheatButtonWidget, &reheat2);
    ReheatButtonWidget->fn->setReleasedImage(ReheatButtonWidget, &reheat2);
    ReheatButtonWidget->fn->setPressedOffset(ReheatButtonWidget, 0);
    ReheatButtonWidget->fn->setPressedEventCallback(ReheatButtonWidget, ReheatButtonWidget_OnPressed);
    PanelWidget4->fn->addChild(PanelWidget4, (leWidget*)ReheatButtonWidget);

    CookButtonWidget = leButtonWidget_New();
    CookButtonWidget->fn->setPosition(CookButtonWidget, 0, 75);
    CookButtonWidget->fn->setSize(CookButtonWidget, 115, 98);
    CookButtonWidget->fn->setScheme(CookButtonWidget, &BlackBackground);
    CookButtonWidget->fn->setBackgroundType(CookButtonWidget, LE_WIDGET_BACKGROUND_NONE);
    CookButtonWidget->fn->setBorderType(CookButtonWidget, LE_WIDGET_BORDER_NONE);
    CookButtonWidget->fn->setPressedImage(CookButtonWidget, &cook2);
    CookButtonWidget->fn->setReleasedImage(CookButtonWidget, &cook2);
    CookButtonWidget->fn->setPressedOffset(CookButtonWidget, 0);
    CookButtonWidget->fn->setPressedEventCallback(CookButtonWidget, CookButtonWidget_OnPressed);
    PanelWidget4->fn->addChild(PanelWidget4, (leWidget*)CookButtonWidget);

    ButtonWidget5 = leButtonWidget_New();
    ButtonWidget5->fn->setPosition(ButtonWidget5, 0, 280);
    ButtonWidget5->fn->setSize(ButtonWidget5, 115, 40);
    ButtonWidget5->fn->setBackgroundType(ButtonWidget5, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget5->fn->setBorderType(ButtonWidget5, LE_WIDGET_BORDER_NONE);
    ButtonWidget5->fn->setPressedImage(ButtonWidget5, &gscalesmall);
    ButtonWidget5->fn->setReleasedImage(ButtonWidget5, &gscalesmall);
    ButtonWidget5->fn->setPressedOffset(ButtonWidget5, 0);
    ButtonWidget5->fn->setPressedEventCallback(ButtonWidget5, ButtonWidget5_OnPressed);
    PanelWidget4->fn->addChild(PanelWidget4, (leWidget*)ButtonWidget5);

    QuickSelectionsPanel = leWidget_New();
    QuickSelectionsPanel->fn->setPosition(QuickSelectionsPanel, 0, 0);
    QuickSelectionsPanel->fn->setSize(QuickSelectionsPanel, 212, 320);
    QuickSelectionsPanel->fn->setBackgroundType(QuickSelectionsPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, QuickSelectionsPanel);

    MenuItem1 = leWidget_New();
    MenuItem1->fn->setPosition(MenuItem1, 0, 31);
    MenuItem1->fn->setSize(MenuItem1, 212, 70);
    MenuItem1->fn->setBackgroundType(MenuItem1, LE_WIDGET_BACKGROUND_NONE);
    QuickSelectionsPanel->fn->addChild(QuickSelectionsPanel, MenuItem1);

    ButtonRect1Back = leRectangleWidget_New();
    ButtonRect1Back->fn->setPosition(ButtonRect1Back, 6, 57);
    ButtonRect1Back->fn->setSize(ButtonRect1Back, 206, 8);
    ButtonRect1Back->fn->setScheme(ButtonRect1Back, &VeryDarkGrayScheme);
    ButtonRect1Back->fn->setThickness(ButtonRect1Back, 0);
    MenuItem1->fn->addChild(MenuItem1, (leWidget*)ButtonRect1Back);

    Button1Rect = leRectangleWidget_New();
    Button1Rect->fn->setPosition(Button1Rect, 0, 7);
    Button1Rect->fn->setSize(Button1Rect, 212, 50);
    Button1Rect->fn->setScheme(Button1Rect, &Button1Scheme);
    Button1Rect->fn->setThickness(Button1Rect, 0);
    MenuItem1->fn->addChild(MenuItem1, (leWidget*)Button1Rect);

    ButtonImage1 = leImageWidget_New();
    ButtonImage1->fn->setPosition(ButtonImage1, 13, 0);
    ButtonImage1->fn->setSize(ButtonImage1, 70, 70);
    ButtonImage1->fn->setBackgroundType(ButtonImage1, LE_WIDGET_BACKGROUND_NONE);
    ButtonImage1->fn->setImage(ButtonImage1, &steak_photo_70);
    MenuItem1->fn->addChild(MenuItem1, (leWidget*)ButtonImage1);

    MenuItem1Label = leLabelWidget_New();
    MenuItem1Label->fn->setPosition(MenuItem1Label, 99, 20);
    MenuItem1Label->fn->setScheme(MenuItem1Label, &WhiteTextScheme);
    MenuItem1Label->fn->setBackgroundType(MenuItem1Label, LE_WIDGET_BACKGROUND_NONE);
    MenuItem1Label->fn->setString(MenuItem1Label, (leString*)&tableString_SteakMenuItem);
    MenuItem1->fn->addChild(MenuItem1, (leWidget*)MenuItem1Label);

    ButtonWidget1 = leButtonWidget_New();
    ButtonWidget1->fn->setPosition(ButtonWidget1, 0, 0);
    ButtonWidget1->fn->setSize(ButtonWidget1, 212, 70);
    ButtonWidget1->fn->setBackgroundType(ButtonWidget1, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget1->fn->setBorderType(ButtonWidget1, LE_WIDGET_BORDER_NONE);
    ButtonWidget1->fn->setPressedOffset(ButtonWidget1, 0);
    ButtonWidget1->fn->setPressedEventCallback(ButtonWidget1, ButtonWidget1_OnPressed);
    MenuItem1->fn->addChild(MenuItem1, (leWidget*)ButtonWidget1);

    LabelWidget2 = leLabelWidget_New();
    LabelWidget2->fn->setPosition(LabelWidget2, 0, -1);
    LabelWidget2->fn->setSize(LabelWidget2, 212, 31);
    LabelWidget2->fn->setBackgroundType(LabelWidget2, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget2->fn->setHAlignment(LabelWidget2, LE_HALIGN_CENTER);
    LabelWidget2->fn->setString(LabelWidget2, (leString*)&tableString_QuickItems);
    QuickSelectionsPanel->fn->addChild(QuickSelectionsPanel, (leWidget*)LabelWidget2);

    MenuItem2 = leWidget_New();
    MenuItem2->fn->setPosition(MenuItem2, 0, 102);
    MenuItem2->fn->setSize(MenuItem2, 212, 70);
    MenuItem2->fn->setBackgroundType(MenuItem2, LE_WIDGET_BACKGROUND_NONE);
    QuickSelectionsPanel->fn->addChild(QuickSelectionsPanel, MenuItem2);

    Button2RectBack = leRectangleWidget_New();
    Button2RectBack->fn->setPosition(Button2RectBack, 6, 57);
    Button2RectBack->fn->setSize(Button2RectBack, 206, 8);
    Button2RectBack->fn->setScheme(Button2RectBack, &VeryDarkGrayScheme);
    Button2RectBack->fn->setThickness(Button2RectBack, 0);
    MenuItem2->fn->addChild(MenuItem2, (leWidget*)Button2RectBack);

    Button2Rect = leRectangleWidget_New();
    Button2Rect->fn->setPosition(Button2Rect, 0, 7);
    Button2Rect->fn->setSize(Button2Rect, 212, 50);
    Button2Rect->fn->setScheme(Button2Rect, &Button2Scheme);
    Button2Rect->fn->setThickness(Button2Rect, 0);
    MenuItem2->fn->addChild(MenuItem2, (leWidget*)Button2Rect);

    ButtonImage2 = leImageWidget_New();
    ButtonImage2->fn->setPosition(ButtonImage2, 23, 0);
    ButtonImage2->fn->setSize(ButtonImage2, 70, 70);
    ButtonImage2->fn->setBackgroundType(ButtonImage2, LE_WIDGET_BACKGROUND_NONE);
    ButtonImage2->fn->setImage(ButtonImage2, &salmon_photo_70);
    MenuItem2->fn->addChild(MenuItem2, (leWidget*)ButtonImage2);

    MenuItem2Label = leLabelWidget_New();
    MenuItem2Label->fn->setPosition(MenuItem2Label, 109, 19);
    MenuItem2Label->fn->setScheme(MenuItem2Label, &UnselectedItemTextScheme);
    MenuItem2Label->fn->setBackgroundType(MenuItem2Label, LE_WIDGET_BACKGROUND_NONE);
    MenuItem2Label->fn->setString(MenuItem2Label, (leString*)&tableString_SalmonMenuItem);
    MenuItem2->fn->addChild(MenuItem2, (leWidget*)MenuItem2Label);

    ButtonWidget2 = leButtonWidget_New();
    ButtonWidget2->fn->setPosition(ButtonWidget2, 0, 0);
    ButtonWidget2->fn->setSize(ButtonWidget2, 212, 70);
    ButtonWidget2->fn->setBackgroundType(ButtonWidget2, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget2->fn->setBorderType(ButtonWidget2, LE_WIDGET_BORDER_NONE);
    ButtonWidget2->fn->setPressedEventCallback(ButtonWidget2, ButtonWidget2_OnPressed);
    MenuItem2->fn->addChild(MenuItem2, (leWidget*)ButtonWidget2);

    MenuItem3 = leWidget_New();
    MenuItem3->fn->setPosition(MenuItem3, 0, 175);
    MenuItem3->fn->setSize(MenuItem3, 212, 70);
    MenuItem3->fn->setBackgroundType(MenuItem3, LE_WIDGET_BACKGROUND_NONE);
    QuickSelectionsPanel->fn->addChild(QuickSelectionsPanel, MenuItem3);

    Button3RectBack = leRectangleWidget_New();
    Button3RectBack->fn->setPosition(Button3RectBack, 6, 56);
    Button3RectBack->fn->setSize(Button3RectBack, 206, 9);
    Button3RectBack->fn->setScheme(Button3RectBack, &VeryDarkGrayScheme);
    Button3RectBack->fn->setThickness(Button3RectBack, 0);
    MenuItem3->fn->addChild(MenuItem3, (leWidget*)Button3RectBack);

    Button3Rect = leRectangleWidget_New();
    Button3Rect->fn->setPosition(Button3Rect, 0, 7);
    Button3Rect->fn->setSize(Button3Rect, 212, 50);
    Button3Rect->fn->setScheme(Button3Rect, &Button3Scheme);
    Button3Rect->fn->setThickness(Button3Rect, 0);
    MenuItem3->fn->addChild(MenuItem3, (leWidget*)Button3Rect);

    ButtonImage3 = leImageWidget_New();
    ButtonImage3->fn->setPosition(ButtonImage3, 13, 0);
    ButtonImage3->fn->setSize(ButtonImage3, 70, 70);
    ButtonImage3->fn->setBackgroundType(ButtonImage3, LE_WIDGET_BACKGROUND_NONE);
    ButtonImage3->fn->setImage(ButtonImage3, &pizza_photo70);
    MenuItem3->fn->addChild(MenuItem3, (leWidget*)ButtonImage3);

    MenuItem3Label = leLabelWidget_New();
    MenuItem3Label->fn->setPosition(MenuItem3Label, 99, 21);
    MenuItem3Label->fn->setScheme(MenuItem3Label, &UnselectedItemTextScheme);
    MenuItem3Label->fn->setBackgroundType(MenuItem3Label, LE_WIDGET_BACKGROUND_NONE);
    MenuItem3Label->fn->setString(MenuItem3Label, (leString*)&tableString_PizzaMenuItem);
    MenuItem3->fn->addChild(MenuItem3, (leWidget*)MenuItem3Label);

    ButtonWidget3 = leButtonWidget_New();
    ButtonWidget3->fn->setPosition(ButtonWidget3, 0, 0);
    ButtonWidget3->fn->setSize(ButtonWidget3, 212, 70);
    ButtonWidget3->fn->setBackgroundType(ButtonWidget3, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget3->fn->setBorderType(ButtonWidget3, LE_WIDGET_BORDER_NONE);
    ButtonWidget3->fn->setPressedEventCallback(ButtonWidget3, ButtonWidget3_OnPressed);
    MenuItem3->fn->addChild(MenuItem3, (leWidget*)ButtonWidget3);

    MenuItem4 = leWidget_New();
    MenuItem4->fn->setPosition(MenuItem4, 0, 246);
    MenuItem4->fn->setSize(MenuItem4, 212, 70);
    MenuItem4->fn->setBackgroundType(MenuItem4, LE_WIDGET_BACKGROUND_NONE);
    QuickSelectionsPanel->fn->addChild(QuickSelectionsPanel, MenuItem4);

    Button4RectBack = leRectangleWidget_New();
    Button4RectBack->fn->setPosition(Button4RectBack, 6, 57);
    Button4RectBack->fn->setSize(Button4RectBack, 206, 8);
    Button4RectBack->fn->setScheme(Button4RectBack, &VeryDarkGrayScheme);
    Button4RectBack->fn->setThickness(Button4RectBack, 0);
    MenuItem4->fn->addChild(MenuItem4, (leWidget*)Button4RectBack);

    Button4Rect = leRectangleWidget_New();
    Button4Rect->fn->setPosition(Button4Rect, 0, 7);
    Button4Rect->fn->setSize(Button4Rect, 212, 50);
    Button4Rect->fn->setScheme(Button4Rect, &Button4Scheme);
    Button4Rect->fn->setThickness(Button4Rect, 0);
    MenuItem4->fn->addChild(MenuItem4, (leWidget*)Button4Rect);

    Button4Image = leImageWidget_New();
    Button4Image->fn->setPosition(Button4Image, 23, 0);
    Button4Image->fn->setSize(Button4Image, 70, 70);
    Button4Image->fn->setBackgroundType(Button4Image, LE_WIDGET_BACKGROUND_NONE);
    Button4Image->fn->setImage(Button4Image, &pasta_photo_70);
    MenuItem4->fn->addChild(MenuItem4, (leWidget*)Button4Image);

    MenuItem4Label = leLabelWidget_New();
    MenuItem4Label->fn->setPosition(MenuItem4Label, 108, 21);
    MenuItem4Label->fn->setScheme(MenuItem4Label, &UnselectedItemTextScheme);
    MenuItem4Label->fn->setBackgroundType(MenuItem4Label, LE_WIDGET_BACKGROUND_NONE);
    MenuItem4Label->fn->setString(MenuItem4Label, (leString*)&tableString_Pasta);
    MenuItem4->fn->addChild(MenuItem4, (leWidget*)MenuItem4Label);

    ButtonWidget4 = leButtonWidget_New();
    ButtonWidget4->fn->setPosition(ButtonWidget4, 0, 0);
    ButtonWidget4->fn->setSize(ButtonWidget4, 212, 70);
    ButtonWidget4->fn->setBackgroundType(ButtonWidget4, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget4->fn->setBorderType(ButtonWidget4, LE_WIDGET_BORDER_NONE);
    ButtonWidget4->fn->setPressedEventCallback(ButtonWidget4, ButtonWidget4_OnPressed);
    MenuItem4->fn->addChild(MenuItem4, (leWidget*)ButtonWidget4);

    Screen2MainClockPanel = leWidget_New();
    Screen2MainClockPanel->fn->setPosition(Screen2MainClockPanel, 212, 22);
    Screen2MainClockPanel->fn->setSize(Screen2MainClockPanel, 153, 290);
    Screen2MainClockPanel->fn->setBackgroundType(Screen2MainClockPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, Screen2MainClockPanel);

    Screen2HourLabel = leLabelWidget_New();
    Screen2HourLabel->fn->setPosition(Screen2HourLabel, 0, 64);
    Screen2HourLabel->fn->setSize(Screen2HourLabel, 153, 75);
    Screen2HourLabel->fn->setScheme(Screen2HourLabel, &WhiteTextScheme);
    Screen2HourLabel->fn->setBackgroundType(Screen2HourLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen2HourLabel->fn->setHAlignment(Screen2HourLabel, LE_HALIGN_CENTER);
    Screen2HourLabel->fn->setString(Screen2HourLabel, (leString*)&tableString_DefaultHour2);
    Screen2MainClockPanel->fn->addChild(Screen2MainClockPanel, (leWidget*)Screen2HourLabel);

    Screen2ColonLabel = leLabelWidget_New();
    Screen2ColonLabel->fn->setPosition(Screen2ColonLabel, 26, 146);
    Screen2ColonLabel->fn->setSize(Screen2ColonLabel, 26, 52);
    Screen2ColonLabel->fn->setScheme(Screen2ColonLabel, &WhiteTextScheme);
    Screen2ColonLabel->fn->setBackgroundType(Screen2ColonLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen2ColonLabel->fn->setString(Screen2ColonLabel, (leString*)&tableString_Colon);
    Screen2MainClockPanel->fn->addChild(Screen2MainClockPanel, (leWidget*)Screen2ColonLabel);

    Screen2MinuteLabel = leLabelWidget_New();
    Screen2MinuteLabel->fn->setPosition(Screen2MinuteLabel, 51, 138);
    Screen2MinuteLabel->fn->setSize(Screen2MinuteLabel, 101, 80);
    Screen2MinuteLabel->fn->setScheme(Screen2MinuteLabel, &WhiteTextScheme);
    Screen2MinuteLabel->fn->setBackgroundType(Screen2MinuteLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen2MinuteLabel->fn->setString(Screen2MinuteLabel, (leString*)&tableString_DefaultMinute2);
    Screen2MainClockPanel->fn->addChild(Screen2MainClockPanel, (leWidget*)Screen2MinuteLabel);

    Screen2LabelPanel = leWidget_New();
    Screen2LabelPanel->fn->setPosition(Screen2LabelPanel, 205, 0);
    Screen2LabelPanel->fn->setSize(Screen2LabelPanel, 275, 76);
    Screen2LabelPanel->fn->setBackgroundType(Screen2LabelPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, Screen2LabelPanel);

    Screen2GoodLabel = leLabelWidget_New();
    Screen2GoodLabel->fn->setPosition(Screen2GoodLabel, 161, 0);
    Screen2GoodLabel->fn->setSize(Screen2GoodLabel, 71, 29);
    Screen2GoodLabel->fn->setScheme(Screen2GoodLabel, &WhiteTextScheme);
    Screen2GoodLabel->fn->setBackgroundType(Screen2GoodLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen2GoodLabel->fn->setHAlignment(Screen2GoodLabel, LE_HALIGN_CENTER);
    Screen2GoodLabel->fn->setString(Screen2GoodLabel, (leString*)&tableString_GoodBytes);
    Screen2LabelPanel->fn->addChild(Screen2LabelPanel, (leWidget*)Screen2GoodLabel);

    Screen2BytesLabel = leLabelWidget_New();
    Screen2BytesLabel->fn->setPosition(Screen2BytesLabel, 0, 22);
    Screen2BytesLabel->fn->setSize(Screen2BytesLabel, 268, 30);
    Screen2BytesLabel->fn->setScheme(Screen2BytesLabel, &LabelBannerScheme);
    Screen2BytesLabel->fn->setHAlignment(Screen2BytesLabel, LE_HALIGN_RIGHT);
    Screen2BytesLabel->fn->setString(Screen2BytesLabel, (leString*)&tableString_Bytes);
    Screen2LabelPanel->fn->addChild(Screen2LabelPanel, (leWidget*)Screen2BytesLabel);

    Screen2SmartCookerLabel = leLabelWidget_New();
    Screen2SmartCookerLabel->fn->setPosition(Screen2SmartCookerLabel, 160, 48);
    Screen2SmartCookerLabel->fn->setSize(Screen2SmartCookerLabel, 115, 25);
    Screen2SmartCookerLabel->fn->setScheme(Screen2SmartCookerLabel, &WhiteTextScheme);
    Screen2SmartCookerLabel->fn->setBackgroundType(Screen2SmartCookerLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen2SmartCookerLabel->fn->setHAlignment(Screen2SmartCookerLabel, LE_HALIGN_CENTER);
    Screen2SmartCookerLabel->fn->setString(Screen2SmartCookerLabel, (leString*)&tableString_SmartCooker);
    Screen2LabelPanel->fn->addChild(Screen2LabelPanel, (leWidget*)Screen2SmartCookerLabel);

    ButtonWidget6 = leButtonWidget_New();
    ButtonWidget6->fn->setPosition(ButtonWidget6, 0, 22);
    ButtonWidget6->fn->setSize(ButtonWidget6, 160, 30);
    ButtonWidget6->fn->setBackgroundType(ButtonWidget6, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget6->fn->setBorderType(ButtonWidget6, LE_WIDGET_BORDER_NONE);
    ButtonWidget6->fn->setToggleable(ButtonWidget6, LE_TRUE);
    ButtonWidget6->fn->setPressedImage(ButtonWidget6, &DemoOff);
    ButtonWidget6->fn->setReleasedImage(ButtonWidget6, &DemoOn);
    ButtonWidget6->fn->setPressedEventCallback(ButtonWidget6, ButtonWidget6_OnPressed);
    ButtonWidget6->fn->setReleasedEventCallback(ButtonWidget6, ButtonWidget6_OnReleased);
    Screen2LabelPanel->fn->addChild(Screen2LabelPanel, (leWidget*)ButtonWidget6);

    SliderButton2 = leButtonWidget_New();
    SliderButton2->fn->setPosition(SliderButton2, 212, 52);
    SliderButton2->fn->setSize(SliderButton2, 153, 260);
    SliderButton2->fn->setBackgroundType(SliderButton2, LE_WIDGET_BACKGROUND_NONE);
    SliderButton2->fn->setBorderType(SliderButton2, LE_WIDGET_BORDER_NONE);
    root0->fn->addChild(root0, (leWidget*)SliderButton2);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    ColorScreen_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_ColorScreen()
{
    ColorScreen_OnUpdate();
}

void screenHide_ColorScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget2 = NULL;
    PanelWidget5 = NULL;
    ProgressRect = NULL;
    PanelWidget4 = NULL;
    ReheatButtonWidget = NULL;
    CookButtonWidget = NULL;
    ButtonWidget5 = NULL;
    QuickSelectionsPanel = NULL;
    MenuItem1 = NULL;
    ButtonRect1Back = NULL;
    Button1Rect = NULL;
    ButtonImage1 = NULL;
    MenuItem1Label = NULL;
    ButtonWidget1 = NULL;
    LabelWidget2 = NULL;
    MenuItem2 = NULL;
    Button2RectBack = NULL;
    Button2Rect = NULL;
    ButtonImage2 = NULL;
    MenuItem2Label = NULL;
    ButtonWidget2 = NULL;
    MenuItem3 = NULL;
    Button3RectBack = NULL;
    Button3Rect = NULL;
    ButtonImage3 = NULL;
    MenuItem3Label = NULL;
    ButtonWidget3 = NULL;
    MenuItem4 = NULL;
    Button4RectBack = NULL;
    Button4Rect = NULL;
    Button4Image = NULL;
    MenuItem4Label = NULL;
    ButtonWidget4 = NULL;
    Screen2MainClockPanel = NULL;
    Screen2HourLabel = NULL;
    Screen2ColonLabel = NULL;
    Screen2MinuteLabel = NULL;
    Screen2LabelPanel = NULL;
    Screen2GoodLabel = NULL;
    Screen2BytesLabel = NULL;
    Screen2SmartCookerLabel = NULL;
    ButtonWidget6 = NULL;
    SliderButton2 = NULL;

    tableString_SteakMenuItem.fn->destructor(&tableString_SteakMenuItem);
    tableString_QuickItems.fn->destructor(&tableString_QuickItems);
    tableString_SalmonMenuItem.fn->destructor(&tableString_SalmonMenuItem);
    tableString_PizzaMenuItem.fn->destructor(&tableString_PizzaMenuItem);
    tableString_Pasta.fn->destructor(&tableString_Pasta);
    tableString_DefaultHour2.fn->destructor(&tableString_DefaultHour2);
    tableString_Colon.fn->destructor(&tableString_Colon);
    tableString_DefaultMinute2.fn->destructor(&tableString_DefaultMinute2);
    tableString_GoodBytes.fn->destructor(&tableString_GoodBytes);
    tableString_Bytes.fn->destructor(&tableString_Bytes);
    tableString_SmartCooker.fn->destructor(&tableString_SmartCooker);
    showing = LE_FALSE;

    ColorScreen_OnHide();
}

void screenDestroy_ColorScreen()
{

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

