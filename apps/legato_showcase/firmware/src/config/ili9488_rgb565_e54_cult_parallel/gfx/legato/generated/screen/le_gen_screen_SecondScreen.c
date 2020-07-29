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

#include "gfx/legato/generated/screen/le_gen_screen_SecondScreen.h"

// widget list for layer 0
static leWidget* root0;

leGradientWidget* GradientWidget2;
leTouchTestWidget* TouchTestWidget1;
leLabelWidget* LabelWidget6;
leImageWidget* ImageWidget5;
leButtonWidget* ButtonWidget2;
leButtonWidget* ButtonWidget3;
leLabelWidget* LabelWidget7;
leButtonWidget* ButtonWidget31;

// string list for this screen
static leTableString tableString_TouchMe;
static leTableString tableString_TouchTestWidgetDemo;

// event handlers
static void ButtonWidget2_OnReleased(leButtonWidget* btn);
static void ButtonWidget3_OnReleased(leButtonWidget* btn);
static void ButtonWidget31_OnReleased(leButtonWidget* btn);

static leBool showing = LE_FALSE;

leResult screenInit_SecondScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_SecondScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_TouchMe, stringID_TouchMe);
    leTableString_Constructor(&tableString_TouchTestWidgetDemo, stringID_TouchTestWidgetDemo);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    GradientWidget2 = leGradientWidget_New();
    GradientWidget2->fn->setPosition(GradientWidget2, 0, 0);
    GradientWidget2->fn->setSize(GradientWidget2, 480, 320);
    GradientWidget2->fn->setScheme(GradientWidget2, &BackgroundGradientScheme);
    GradientWidget2->fn->setDirection(GradientWidget2, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)GradientWidget2);

    TouchTestWidget1 = leTouchTestWidget_New();
    TouchTestWidget1->fn->setPosition(TouchTestWidget1, 130, 42);
    TouchTestWidget1->fn->setSize(TouchTestWidget1, 297, 169);
    TouchTestWidget1->fn->setScheme(TouchTestWidget1, &TouchTestScheme);
    root0->fn->addChild(root0, (leWidget*)TouchTestWidget1);

    LabelWidget6 = leLabelWidget_New();
    LabelWidget6->fn->setPosition(LabelWidget6, 125, 215);
    LabelWidget6->fn->setSize(LabelWidget6, 228, 25);
    LabelWidget6->fn->setScheme(LabelWidget6, &BlackBackground);
    LabelWidget6->fn->setBackgroundType(LabelWidget6, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget6->fn->setString(LabelWidget6, (leString*)&tableString_TouchMe);
    root0->fn->addChild(root0, (leWidget*)LabelWidget6);

    ImageWidget5 = leImageWidget_New();
    ImageWidget5->fn->setPosition(ImageWidget5, 45, 151);
    ImageWidget5->fn->setSize(ImageWidget5, 81, 100);
    ImageWidget5->fn->setBackgroundType(ImageWidget5, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget5->fn->setImage(ImageWidget5, &GFX_Touch_80);
    root0->fn->addChild(root0, (leWidget*)ImageWidget5);

    ButtonWidget2 = leButtonWidget_New();
    ButtonWidget2->fn->setPosition(ButtonWidget2, 0, 260);
    ButtonWidget2->fn->setSize(ButtonWidget2, 60, 60);
    ButtonWidget2->fn->setAlphaAmount(ButtonWidget2, 220);
    ButtonWidget2->fn->setBackgroundType(ButtonWidget2, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget2->fn->setBorderType(ButtonWidget2, LE_WIDGET_BORDER_NONE);
    ButtonWidget2->fn->setPressedImage(ButtonWidget2, &GFX_Help_60);
    ButtonWidget2->fn->setReleasedImage(ButtonWidget2, &GFX_Help_60);
    ButtonWidget2->fn->setReleasedEventCallback(ButtonWidget2, ButtonWidget2_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget2);

    ButtonWidget3 = leButtonWidget_New();
    ButtonWidget3->fn->setPosition(ButtonWidget3, 421, 260);
    ButtonWidget3->fn->setSize(ButtonWidget3, 60, 60);
    ButtonWidget3->fn->setAlphaAmount(ButtonWidget3, 220);
    ButtonWidget3->fn->setBackgroundType(ButtonWidget3, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget3->fn->setBorderType(ButtonWidget3, LE_WIDGET_BORDER_NONE);
    ButtonWidget3->fn->setPressedImage(ButtonWidget3, &GFX_Home_60x60);
    ButtonWidget3->fn->setReleasedImage(ButtonWidget3, &GFX_Home_60x60);
    ButtonWidget3->fn->setReleasedEventCallback(ButtonWidget3, ButtonWidget3_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget3);

    LabelWidget7 = leLabelWidget_New();
    LabelWidget7->fn->setPosition(LabelWidget7, 10, 5);
    LabelWidget7->fn->setSize(LabelWidget7, 293, 25);
    LabelWidget7->fn->setScheme(LabelWidget7, &BlackBackground);
    LabelWidget7->fn->setBackgroundType(LabelWidget7, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget7->fn->setString(LabelWidget7, (leString*)&tableString_TouchTestWidgetDemo);
    root0->fn->addChild(root0, (leWidget*)LabelWidget7);

    ButtonWidget31 = leButtonWidget_New();
    ButtonWidget31->fn->setPosition(ButtonWidget31, 360, 260);
    ButtonWidget31->fn->setSize(ButtonWidget31, 60, 60);
    ButtonWidget31->fn->setBackgroundType(ButtonWidget31, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget31->fn->setBorderType(ButtonWidget31, LE_WIDGET_BORDER_NONE);
    ButtonWidget31->fn->setPressedImage(ButtonWidget31, &GFX_NextScreen_60x60);
    ButtonWidget31->fn->setReleasedImage(ButtonWidget31, &GFX_NextScreen_60x60);
    ButtonWidget31->fn->setReleasedEventCallback(ButtonWidget31, ButtonWidget31_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget31);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_SecondScreen()
{
}

void screenHide_SecondScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    GradientWidget2 = NULL;
    TouchTestWidget1 = NULL;
    LabelWidget6 = NULL;
    ImageWidget5 = NULL;
    ButtonWidget2 = NULL;
    ButtonWidget3 = NULL;
    LabelWidget7 = NULL;
    ButtonWidget31 = NULL;

    tableString_TouchMe.fn->destructor(&tableString_TouchMe);
    tableString_TouchTestWidgetDemo.fn->destructor(&tableString_TouchTestWidgetDemo);
    showing = LE_FALSE;
}

void screenDestroy_SecondScreen()
{

}

leWidget* screenGetRoot_SecondScreen(uint32_t lyrIdx)
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

// event handlers
void ButtonWidget2_OnReleased(leButtonWidget* btn)
{
}

void ButtonWidget3_OnReleased(leButtonWidget* btn)
{
}

void ButtonWidget31_OnReleased(leButtonWidget* btn)
{
}


