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

#include "gfx/legato/generated/screen/le_gen_screen_default.h"

// widget list for layer 0
static leWidget* root0;

leImageWidget* BackgroundImage;
leLabelWidget* PulseLabel;
leLabelWidget* DiaLabel;
leLabelWidget* SysLabel;
leLabelWidget* ClockLabel;
leImageWidget* HeartImage;
leImageWidget* ImageWidget6;
leButtonWidget* ButtonWidget0;

// string list for this screen
static leTableString tableString_ClearVal;
static leTableString tableString_DefaultTime;

// event handlers
static void default_OnHide(void);


static leBool showing = LE_FALSE;

leResult screenInit_default()
{
    return LE_SUCCESS;
}

leResult screenShow_default()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_ClearVal, string_ClearVal);
    leTableString_Constructor(&tableString_DefaultTime, string_DefaultTime);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 320, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    BackgroundImage = leImageWidget_New();
    BackgroundImage->fn->setPosition(BackgroundImage, 0, 0);
    BackgroundImage->fn->setSize(BackgroundImage, 320, 480);
    BackgroundImage->fn->setBackgroundType(BackgroundImage, LE_WIDGET_BACKGROUND_NONE);
    BackgroundImage->fn->setImage(BackgroundImage, &Background);
    root0->fn->addChild(root0, (leWidget*)BackgroundImage);

    PulseLabel = leLabelWidget_New();
    PulseLabel->fn->setPosition(PulseLabel, 120, 355);
    PulseLabel->fn->setSize(PulseLabel, 155, 75);
    PulseLabel->fn->setBackgroundType(PulseLabel, LE_WIDGET_BACKGROUND_NONE);
    PulseLabel->fn->setHAlignment(PulseLabel, LE_HALIGN_RIGHT);
    PulseLabel->fn->setString(PulseLabel, (leString*)&tableString_ClearVal);
    root0->fn->addChild(root0, (leWidget*)PulseLabel);

    DiaLabel = leLabelWidget_New();
    DiaLabel->fn->setPosition(DiaLabel, 121, 225);
    DiaLabel->fn->setSize(DiaLabel, 155, 75);
    DiaLabel->fn->setScheme(DiaLabel, &HighStage2Scheme);
    DiaLabel->fn->setBackgroundType(DiaLabel, LE_WIDGET_BACKGROUND_NONE);
    DiaLabel->fn->setHAlignment(DiaLabel, LE_HALIGN_RIGHT);
    DiaLabel->fn->setString(DiaLabel, (leString*)&tableString_ClearVal);
    root0->fn->addChild(root0, (leWidget*)DiaLabel);

    SysLabel = leLabelWidget_New();
    SysLabel->fn->setPosition(SysLabel, 120, 96);
    SysLabel->fn->setSize(SysLabel, 155, 75);
    SysLabel->fn->setScheme(SysLabel, &HighStage2Scheme);
    SysLabel->fn->setBackgroundType(SysLabel, LE_WIDGET_BACKGROUND_NONE);
    SysLabel->fn->setHAlignment(SysLabel, LE_HALIGN_RIGHT);
    SysLabel->fn->setString(SysLabel, (leString*)&tableString_ClearVal);
    root0->fn->addChild(root0, (leWidget*)SysLabel);

    ClockLabel = leLabelWidget_New();
    ClockLabel->fn->setPosition(ClockLabel, 140, 30);
    ClockLabel->fn->setSize(ClockLabel, 91, 30);
    ClockLabel->fn->setBackgroundType(ClockLabel, LE_WIDGET_BACKGROUND_NONE);
    ClockLabel->fn->setHAlignment(ClockLabel, LE_HALIGN_RIGHT);
    ClockLabel->fn->setString(ClockLabel, (leString*)&tableString_DefaultTime);
    root0->fn->addChild(root0, (leWidget*)ClockLabel);

    HeartImage = leImageWidget_New();
    HeartImage->fn->setPosition(HeartImage, 31, 31);
    HeartImage->fn->setSize(HeartImage, 30, 30);
    HeartImage->fn->setBackgroundType(HeartImage, LE_WIDGET_BACKGROUND_NONE);
    HeartImage->fn->setImage(HeartImage, &heart);
    root0->fn->addChild(root0, (leWidget*)HeartImage);

    ImageWidget6 = leImageWidget_New();
    ImageWidget6->fn->setPosition(ImageWidget6, 241, 30);
    ImageWidget6->fn->setSize(ImageWidget6, 40, 30);
    ImageWidget6->fn->setBackgroundType(ImageWidget6, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget6->fn->setHAlignment(ImageWidget6, LE_HALIGN_LEFT);
    ImageWidget6->fn->setMargins(ImageWidget6, 0, 4, 4, 4);
    ImageWidget6->fn->setImage(ImageWidget6, &Microchip_meatball);
    root0->fn->addChild(root0, (leWidget*)ImageWidget6);

    ButtonWidget0 = leButtonWidget_New();
    ButtonWidget0->fn->setPosition(ButtonWidget0, 0, 0);
    ButtonWidget0->fn->setSize(ButtonWidget0, 320, 480);
    ButtonWidget0->fn->setBackgroundType(ButtonWidget0, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget0->fn->setBorderType(ButtonWidget0, LE_WIDGET_BORDER_NONE);
    ButtonWidget0->fn->setPressedEventCallback(ButtonWidget0, ButtonWidget0_OnPressed);
    ButtonWidget0->fn->setReleasedEventCallback(ButtonWidget0, ButtonWidget0_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget0);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    default_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_default()
{
    default_OnUpdate();
}

void screenHide_default()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    BackgroundImage = NULL;
    PulseLabel = NULL;
    DiaLabel = NULL;
    SysLabel = NULL;
    ClockLabel = NULL;
    HeartImage = NULL;
    ImageWidget6 = NULL;
    ButtonWidget0 = NULL;

    tableString_ClearVal.fn->destructor(&tableString_ClearVal);
    tableString_DefaultTime.fn->destructor(&tableString_DefaultTime);
    showing = LE_FALSE;

    default_OnHide();
}

void screenDestroy_default()
{

}

leWidget* screenGetRoot_default(uint32_t lyrIdx)
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
void default_OnHide(void){
}



