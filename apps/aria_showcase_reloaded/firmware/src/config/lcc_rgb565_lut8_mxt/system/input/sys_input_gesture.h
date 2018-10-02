// DOM-IGNORE-BEGIN
/*******************************************************************************
 Module for Microchip Harmony Input System Service

  Company:
    Microchip Technology Inc.

  File Name:
    sys_input_gesture.h

  Summary:
    MPLAB Harmony Input System Service gesture event definition

  Description:
    MPLAB Harmony Input System Service gesture event definition
*******************************************************************************/

/*******************************************************************************
Copyright (c) 2018 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
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

#ifndef SYS_INPUT_GESTURE_H
#define SYS_INPUT_GESTURE_H
//DOM-IGNORE-END

#include <stdint.h>
#include <stddef.h>

// *****************************************************************************
/* Enumeration:
    SYS_INP_Guesture

  Summary:
    Enumerates gesture types

  Description:
    SYS_INP_SWIPE - a swipe gesture
    SYS_INP_PINCH - a pinch gesture
    
  Remarks:
    None.
*/
typedef enum SYS_INP_Guesture_t
{
    SYS_INP_SWIPE = 0,
    SYS_INP_PINCH,
    SYS_INP_GESTURE_LAST = SYS_INP_PINCH
} SYS_INP_Guesture;

/* Structure:
    SYS_INP_GestureEvent

  Summary:
    Defines a basic gesture event

  Description:
    type - type type of gesture
    
  Remarks:
    None.
*/
typedef struct SYS_INP_GestureEvent_t
{
    uint8_t type;
} SYS_INP_GestureEvent;

/* Structure:
    SYS_INP_FlickGestureEvent

  Summary:
    Defines a flick gesture event

  Description:
    x - the pinch x coordinate
    y - the pinch y coordinate
    dir - the direction of the flick
    dist - the distance between the two pinch points
    
  Remarks:
    None.
*/
typedef struct SYS_INP_FlickGestureEvent_t
{
    uint16_t x;
    uint16_t y;
    uint16_t dir;
    uint16_t dist;
} SYS_INP_FlickGestureEvent;

/* Structure:
    SYS_INP_PinchGestureEvent

  Summary:
    Defines a pinch gesture event

  Description:
    x - the starting x coordinate
    y - the starting y coordinate
    angle - the angle of the pinch
    sep - the distance between the two points
    
  Remarks:
    None.
*/
typedef struct SYS_INP_PinchGestureEvent_t
{
    uint16_t x;
    uint16_t y;
    uint16_t angle;
    uint16_t sep;
} SYS_INP_PinchGestureEvent;

/* Structure:
    SYS_INP_StretchGestureEvent

  Summary:
    Defines a stretch gesture event

  Description:
    x - the starting x coordinate
    y - the starting y coordinate
    angle - the angle of the pinch
    sep - the distance between the two points
    
  Remarks:
    None.
*/
typedef struct SYS_INP_StretchGestureEvent_t
{
    uint16_t x;
    uint16_t y;
    uint16_t angle;
    uint16_t sep;
} SYS_INP_StretchGestureEvent;

/* Structure:
    SYS_INP_RotateGestureEvent

  Summary:
    Defines a rotate gesture event

  Description:
    x - the starting x coordinate
    y - the starting y coordinate
    angle - the angle of the pinch
    sep - the distance between the two points
    dir - the direction of rotation
    
  Remarks:
    None.
*/
typedef struct SYS_INP_RotateGestureEvent_t
{
    uint16_t x;
    uint16_t y;
    uint16_t angle;
    uint16_t sep;
    uint16_t dir;
} SYS_INP_RotateGestureEvent;

/* Event handler function defintions */
typedef void (*SYS_INP_HandleFlickGestureEvent)(const SYS_INP_FlickGestureEvent* const);
typedef void (*SYS_INP_HandlePinchGestureEvent)(const SYS_INP_PinchGestureEvent* const);
typedef void (*SYS_INP_HandleStretchGestureEvent)(const SYS_INP_StretchGestureEvent* const);
typedef void (*SYS_INP_HandleRotateGestureEvent)(const SYS_INP_RotateGestureEvent* const);

#endif /* SYS_INPUT_GESTURE_H */