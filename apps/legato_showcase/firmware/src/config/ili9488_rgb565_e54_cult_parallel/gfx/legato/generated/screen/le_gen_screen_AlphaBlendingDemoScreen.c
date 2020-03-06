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

#include "gfx/legato/generated/screen/le_gen_screen_AlphaBlendingDemoScreen.h"

// widget list for layer 0
static leWidget* root0;

leGradientWidget* GradientWidget5;
leWidget* PanelWidget1;
leSliderWidget* SliderWidget1;
leLabelWidget* SliderValueLabelWidget;
leWidget* PanelWidget2;
leImageWidget* ImageWidget1;
leImageWidget* ImageWidget2;
leButtonWidget* AlphaHelpButton;
leButtonWidget* AlphaHomeButton;
leLabelWidget* LabelWidget9;
leButtonWidget* AlphaNextButton;
leButtonWidget* SliderUpButtonWidget;
leButtonWidget* SliderDownButtonWidget;

// string list for this screen
static leTableString tableString_AlphaBlendingDemo;
static leTableString tableString_UpRight;
static leTableString tableString_DownLeft;

static leBool showing = LE_FALSE;

leResult screenInit_AlphaBlendingDemoScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_AlphaBlendingDemoScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_AlphaBlendingDemo, string_AlphaBlendingDemo);
    leTableString_Constructor(&tableString_UpRight, string_UpRight);
    leTableString_Constructor(&tableString_DownLeft, string_DownLeft);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    GradientWidget5 = leGradientWidget_New();
    GradientWidget5->fn->setPosition(GradientWidget5, 0, 0);
    GradientWidget5->fn->setSize(GradientWidget5, 480, 320);
    GradientWidget5->fn->setScheme(GradientWidget5, &BackgroundGradientScheme);
    GradientWidget5->fn->setDirection(GradientWidget5, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)GradientWidget5);

    PanelWidget1 = leWidget_New();
    PanelWidget1->fn->setPosition(PanelWidget1, 370, 29);
    PanelWidget1->fn->setSize(PanelWidget1, 119, 187);
    PanelWidget1->fn->setBackgroundType(PanelWidget1, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, PanelWidget1);

    SliderWidget1 = leSliderWidget_New();
    SliderWidget1->fn->setPosition(SliderWidget1, 1, 42);
    SliderWidget1->fn->setSize(SliderWidget1, 48, 106);
    SliderWidget1->fn->setBackgroundType(SliderWidget1, LE_WIDGET_BACKGROUND_NONE);
    SliderWidget1->fn->setMaximumValue(SliderWidget1, 255);
    SliderWidget1->fn->setValue(SliderWidget1, 127);
    SliderWidget1->fn->setGripSize(SliderWidget1, 15);
    SliderWidget1->fn->setValueChangedEventCallback(SliderWidget1, SliderWidget1_OnValueChanged);
    PanelWidget1->fn->addChild(PanelWidget1, (leWidget*)SliderWidget1);

    SliderValueLabelWidget = leLabelWidget_New();
    SliderValueLabelWidget->fn->setPosition(SliderValueLabelWidget, 58, 78);
    SliderValueLabelWidget->fn->setSize(SliderValueLabelWidget, 50, 32);
    SliderValueLabelWidget->fn->setBackgroundType(SliderValueLabelWidget, LE_WIDGET_BACKGROUND_NONE);
    PanelWidget1->fn->addChild(PanelWidget1, (leWidget*)SliderValueLabelWidget);

    PanelWidget2 = leWidget_New();
    PanelWidget2->fn->setPosition(PanelWidget2, 61, 36);
    PanelWidget2->fn->setSize(PanelWidget2, 299, 180);
    PanelWidget2->fn->setBorderType(PanelWidget2, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, PanelWidget2);

    ImageWidget1 = leImageWidget_New();
    ImageWidget1->fn->setPosition(ImageWidget1, 0, 0);
    ImageWidget1->fn->setSize(ImageWidget1, 305, 180);
    ImageWidget1->fn->setAlphaEnabled(ImageWidget1, LE_TRUE);
    ImageWidget1->fn->setAlphaAmount(ImageWidget1, 127);
    ImageWidget1->fn->setBackgroundType(ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget1->fn->setBorderType(ImageWidget1, LE_WIDGET_BORDER_LINE);
    ImageWidget1->fn->setImage(ImageWidget1, &NewHarmonyLogo);
    PanelWidget2->fn->addChild(PanelWidget2, (leWidget*)ImageWidget1);

    ImageWidget2 = leImageWidget_New();
    ImageWidget2->fn->setPosition(ImageWidget2, 0, 0);
    ImageWidget2->fn->setSize(ImageWidget2, 304, 180);
    ImageWidget2->fn->setAlphaEnabled(ImageWidget2, LE_TRUE);
    ImageWidget2->fn->setAlphaAmount(ImageWidget2, 127);
    ImageWidget2->fn->setBackgroundType(ImageWidget2, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget2->fn->setBorderType(ImageWidget2, LE_WIDGET_BORDER_LINE);
    ImageWidget2->fn->setImage(ImageWidget2, &MicrochipLogo);
    PanelWidget2->fn->addChild(PanelWidget2, (leWidget*)ImageWidget2);

    AlphaHelpButton = leButtonWidget_New();
    AlphaHelpButton->fn->setPosition(AlphaHelpButton, 0, 260);
    AlphaHelpButton->fn->setSize(AlphaHelpButton, 60, 60);
    AlphaHelpButton->fn->setBackgroundType(AlphaHelpButton, LE_WIDGET_BACKGROUND_NONE);
    AlphaHelpButton->fn->setBorderType(AlphaHelpButton, LE_WIDGET_BORDER_NONE);
    AlphaHelpButton->fn->setPressedImage(AlphaHelpButton, &GFX_Help_60);
    AlphaHelpButton->fn->setReleasedImage(AlphaHelpButton, &GFX_Help_60);
    AlphaHelpButton->fn->setReleasedEventCallback(AlphaHelpButton, AlphaHelpButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)AlphaHelpButton);

    AlphaHomeButton = leButtonWidget_New();
    AlphaHomeButton->fn->setPosition(AlphaHomeButton, 421, 260);
    AlphaHomeButton->fn->setSize(AlphaHomeButton, 60, 60);
    AlphaHomeButton->fn->setBackgroundType(AlphaHomeButton, LE_WIDGET_BACKGROUND_NONE);
    AlphaHomeButton->fn->setBorderType(AlphaHomeButton, LE_WIDGET_BORDER_NONE);
    AlphaHomeButton->fn->setPressedImage(AlphaHomeButton, &GFX_Home_60x60);
    AlphaHomeButton->fn->setReleasedImage(AlphaHomeButton, &GFX_Home_60x60);
    AlphaHomeButton->fn->setReleasedEventCallback(AlphaHomeButton, AlphaHomeButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)AlphaHomeButton);

    LabelWidget9 = leLabelWidget_New();
    LabelWidget9->fn->setPosition(LabelWidget9, 10, 5);
    LabelWidget9->fn->setSize(LabelWidget9, 297, 25);
    LabelWidget9->fn->setScheme(LabelWidget9, &whiteScheme);
    LabelWidget9->fn->setBackgroundType(LabelWidget9, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget9->fn->setString(LabelWidget9, (leString*)&tableString_AlphaBlendingDemo);
    root0->fn->addChild(root0, (leWidget*)LabelWidget9);

    AlphaNextButton = leButtonWidget_New();
    AlphaNextButton->fn->setPosition(AlphaNextButton, 359, 260);
    AlphaNextButton->fn->setSize(AlphaNextButton, 60, 60);
    AlphaNextButton->fn->setBackgroundType(AlphaNextButton, LE_WIDGET_BACKGROUND_NONE);
    AlphaNextButton->fn->setBorderType(AlphaNextButton, LE_WIDGET_BORDER_NONE);
    AlphaNextButton->fn->setPressedImage(AlphaNextButton, &GFX_NextScreen_60x60);
    AlphaNextButton->fn->setReleasedImage(AlphaNextButton, &GFX_NextScreen_60x60);
    AlphaNextButton->fn->setReleasedEventCallback(AlphaNextButton, AlphaNextButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)AlphaNextButton);

    SliderUpButtonWidget = leButtonWidget_New();
    SliderUpButtonWidget->fn->setPosition(SliderUpButtonWidget, 370, 31);
    SliderUpButtonWidget->fn->setSize(SliderUpButtonWidget, 50, 36);
    SliderUpButtonWidget->fn->setScheme(SliderUpButtonWidget, &BlackBackground);
    SliderUpButtonWidget->fn->setBackgroundType(SliderUpButtonWidget, LE_WIDGET_BACKGROUND_NONE);
    SliderUpButtonWidget->fn->setString(SliderUpButtonWidget, (leString*)&tableString_UpRight);
    SliderUpButtonWidget->fn->setReleasedEventCallback(SliderUpButtonWidget, SliderUpButtonWidget_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SliderUpButtonWidget);

    SliderDownButtonWidget = leButtonWidget_New();
    SliderDownButtonWidget->fn->setPosition(SliderDownButtonWidget, 370, 180);
    SliderDownButtonWidget->fn->setSize(SliderDownButtonWidget, 50, 36);
    SliderDownButtonWidget->fn->setScheme(SliderDownButtonWidget, &BlackBackground);
    SliderDownButtonWidget->fn->setBackgroundType(SliderDownButtonWidget, LE_WIDGET_BACKGROUND_NONE);
    SliderDownButtonWidget->fn->setString(SliderDownButtonWidget, (leString*)&tableString_DownLeft);
    SliderDownButtonWidget->fn->setReleasedEventCallback(SliderDownButtonWidget, SliderDownButtonWidget_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SliderDownButtonWidget);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    AlphaBlendingDemoScreen_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_AlphaBlendingDemoScreen()
{
    AlphaBlendingDemoScreen_OnUpdate();
}

void screenHide_AlphaBlendingDemoScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    GradientWidget5 = NULL;
    PanelWidget1 = NULL;
    SliderWidget1 = NULL;
    SliderValueLabelWidget = NULL;
    PanelWidget2 = NULL;
    ImageWidget1 = NULL;
    ImageWidget2 = NULL;
    AlphaHelpButton = NULL;
    AlphaHomeButton = NULL;
    LabelWidget9 = NULL;
    AlphaNextButton = NULL;
    SliderUpButtonWidget = NULL;
    SliderDownButtonWidget = NULL;

    tableString_AlphaBlendingDemo.fn->destructor(&tableString_AlphaBlendingDemo);
    tableString_UpRight.fn->destructor(&tableString_UpRight);
    tableString_DownLeft.fn->destructor(&tableString_DownLeft);
    showing = LE_FALSE;

    AlphaBlendingDemoScreen_OnHide();
}

void screenDestroy_AlphaBlendingDemoScreen()
{

}

leWidget* screenGetRoot_AlphaBlendingDemoScreen(uint32_t lyrIdx)
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

