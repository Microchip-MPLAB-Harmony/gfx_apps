// DOM-IGNORE-BEGIN
/*******************************************************************************
 Module for Microchip Harmony Input System Service

  Company:
    Microchip Technology Inc.

  File Name:
    sys_input_touch.h

  Summary:
    MPLAB Harmony Input System Service touch event definition

  Description:
    MPLAB Harmony Input System Service touch event definition
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

#ifndef SYS_INPUT_MOUSE_H
#define SYS_INPUT_MOUSE_H
//DOM-IGNORE-END

#include <stdint.h>
#include <stddef.h>

// *****************************************************************************
/* Enumeration:
    SYS_INP_MouseButton

  Summary:
    Enumerates mouse button value types

  Remarks:
    None.
*/
typedef enum SYS_INP_MouseButton_t
{
    SYS_INP_BUTTON_NONE = 0,
    SYS_INP_BUTTON_LEFT,
    SYS_INP_BUTTON_MIDDLE,
    SYS_INP_BUTTON_RIGHT,
    SYS_INP_BUTTON_WHEEL_UP,
    SYS_INP_BUTTON_WHEEL_DOWN,
    SYS_INP_BUTTON_LAST = SYS_INP_BUTTON_WHEEL_DOWN
} SYS_INP_MouseButton;

/* Structure:
    SYS_INP_MouseButtonEvent

  Summary:
    Defines a generic mouse button event

  Description:
    btn - the mouse button value that that experienced a change in state
    
  Remarks:
    None.
*/
typedef struct SYS_INP_MouseButtonEvent_t
{
    SYS_INP_MouseButton btn;
} SYS_INP_MouseButtonEvent;

/* Structure:
    SYS_INP_MouseMoveEvent

  Summary:
    Defines a mouse move event

  Description:
    x - the amount of change in x
    y - the amount of change in y
    
  Remarks:
    None.
*/
typedef struct SYS_INP_MouseMoveEvent_t
{
    uint16_t x;
    uint16_t y;
} SYS_INP_MouseMoveEvent;

/* Mouse Handler Function Definitions */
typedef void (*SYS_INP_HandleMouseMoveEvent)(const SYS_INP_MouseMoveEvent* const);
typedef void (*SYS_INP_HandleMouseButtonDownEvent)(const SYS_INP_MouseButtonEvent* const);
typedef void (*SYS_INP_HandleMouseButtonUpEvent)(const SYS_INP_MouseButtonEvent* const);

#endif /* SYS_INPUT_MOUSE_H */