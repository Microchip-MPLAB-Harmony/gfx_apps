/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Implementation File

  File Name:
    libaria_events.c

  Summary:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#include "gfx/libaria/libaria_events.h"
#include "app.h"

// CounterSizeDownButton - PressedEvent
void CounterSizeDownButton_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_COUNTER_SIZE_DOWN;
}

// CounterSizeUpButton - PressedEvent
void CounterSizeUpButton_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_COUNTER_SIZE_UP;
}

// NextButton - PressedEvent
void NextButton_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_NEXT;
}

// ButtonWidget1 - PressedEvent
void ButtonWidget1_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    laButtonWidget_SetText(btn, laString_CreateFromID(string_GPUOn));
    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    resetFPS();
}

// ButtonWidget1 - ReleasedEvent
void ButtonWidget1_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    laButtonWidget_SetText(btn, laString_CreateFromID(string_GPUOff));
    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCU);
    resetFPS();
}

// FPSButtonCounter - PressedEvent
void FPSButtonCounter_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    
}

// FPSButtonCounter - ReleasedEvent
void FPSButtonCounter_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    
}

// MotionMenuNextButton - PressedEvent
void MotionMenuNextButton_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_NEXT;
}

// MotionMenuPlusButton - PressedEvent
void MotionMenuPlusButton_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_MOTION_REMOVE_RECT;
}

// MotionMenuMinusButton - PressedEvent
void MotionMenuMinusButton_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_MOTION_ADD_RECT;
}

// RectSizeDownButtonWidget - PressedEvent
void RectSizeDownButtonWidget_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_RECT_SIZE_DOWN;
}

// RectSizeUpButtonWidget - PressedEvent
void RectSizeUpButtonWidget_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_RECT_SIZE_UP;
}

// ButtonWidget2 - PressedEvent
void ButtonWidget2_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    laButtonWidget_SetText(btn, laString_CreateFromID(string_GPUOn));
    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    resetFPS();
}

// ButtonWidget2 - ReleasedEvent
void ButtonWidget2_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    laButtonWidget_SetText(btn, laString_CreateFromID(string_GPUOff));
    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCU);
    resetFPS();
}

// FPSButtonMotion - PressedEvent
void FPSButtonMotion_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    
}

// FPSButtonMotion - ReleasedEvent
void FPSButtonMotion_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    
}

// ImageNextButtonWidget - PressedEvent
void ImageNextButtonWidget_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_NEXT;
}

// ImageSizeDownButtonWidget - PressedEvent
void ImageSizeDownButtonWidget_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_IMAGE_SIZE_DOWN;
}

// ImageSizeUpButtonWidget - PressedEvent
void ImageSizeUpButtonWidget_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_IMAGE_SIZE_UP;
}

// ImageTypePrevButtonWidget - PressedEvent
void ImageTypePrevButtonWidget_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_IMAGE_TYPE_PREV;
}

// ImageTypeNextButtonWidget - PressedEvent
void ImageTypeNextButtonWidget_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    appData.event = APP_EVENT_IMAGE_TYPE_NEXT;
}

// ButtonWidget3 - PressedEvent
void ButtonWidget3_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    laButtonWidget_SetText(btn, laString_CreateFromID(string_GPUOn));
    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    resetFPS();
}

// ButtonWidget3 - ReleasedEvent
void ButtonWidget3_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    laButtonWidget_SetText(btn, laString_CreateFromID(string_GPUOff));
    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCU);
    resetFPS();
}

// FPSButtonImages - PressedEvent
void FPSButtonImages_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    
}

// FPSButtonImages - ReleasedEvent
void FPSButtonImages_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    
}





