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
Copyright (c) 2018 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END

#include "gfx/libaria/libaria_events.h"

//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!
#include "app.h"
//END OF CUSTOM CODE

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





