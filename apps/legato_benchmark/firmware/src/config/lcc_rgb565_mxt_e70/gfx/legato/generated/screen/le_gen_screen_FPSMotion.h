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

#ifndef LE_GEN_SCREEN_FPSMOTION_H
#define LE_GEN_SCREEN_FPSMOTION_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* MotionBackground;
extern leRectangleWidget* RectMotionWidget10;
extern leRectangleWidget* RectMotionWidget9;
extern leRectangleWidget* RectMotionWidget8;
extern leRectangleWidget* RectMotionWidget7;
extern leRectangleWidget* RectMotionWidget6;
extern leRectangleWidget* RectMotionWidget5;
extern leRectangleWidget* RectMotionWidget4;
extern leRectangleWidget* RectMotionWidget3;
extern leRectangleWidget* RectMotionWidget2;
extern leRectangleWidget* RectMotionWidget1;
extern leWidget* MotionSideContainer;
extern leLabelWidget* MotionUpdateLabel;
extern leLabelWidget* MotionRefreshLabel;
extern leLabelWidget* MotionRefreshValue;
extern leLabelWidget* MotionContainerTitle;
extern leButtonWidget* MotionNextButton;
extern leButtonWidget* MotionMinusButton;
extern leButtonWidget* MotionPlusButton;
extern leLabelWidget* MotionNumLabel;
extern leLabelWidget* MotionRectCount;
extern leLabelWidget* MotionRectSizeLabel;
extern leLabelWidget* MotionRectSizeValue;
extern leButtonWidget* MotionSizeDownButton;
extern leButtonWidget* MotionSizeUpButton;
extern leButtonWidget* MotionUpdateValue;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_FPSMotion(); // called when Legato is initialized
leResult screenShow_FPSMotion(); // called when screen is shown
void screenHide_FPSMotion(); // called when screen is hidden
void screenDestroy_FPSMotion(); // called when Legato is destroyed
void screenUpdate_FPSMotion(); // called when Legato is updating

leWidget* screenGetRoot_FPSMotion(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void FPSMotion_OnShow(void);

void FPSMotion_OnHide(void);

void FPSMotion_OnUpdate(void);

void MotionNextButton_OnPressed(leButtonWidget* btn)
;

void MotionMinusButton_OnPressed(leButtonWidget* btn)
;

void MotionPlusButton_OnPressed(leButtonWidget* btn)
;

void MotionSizeDownButton_OnPressed(leButtonWidget* btn)
;

void MotionSizeUpButton_OnPressed(leButtonWidget* btn)
;


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_FPSMOTION_H
