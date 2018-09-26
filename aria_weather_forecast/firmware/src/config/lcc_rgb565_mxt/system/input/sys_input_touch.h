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

#ifndef SYS_INPUT_TOUCH_H
#define SYS_INPUT_TOUCH_H
//DOM-IGNORE-END

#include <stdint.h>
#include <stddef.h>

// *****************************************************************************
/* Structure:
    SYS_INP_TouchStateEvent

  Summary:
    Defines a generic touch state event

  Description:
    index - the touch index of the event
    x - the x coordinate
    y - the y coordinate
    
  Remarks:
    None.
*/
typedef struct SYS_INP_TouchStateEvent_t
{
    uint8_t index;
    int16_t x;
    int16_t y;
} SYS_INP_TouchStateEvent;

/* Structure:
    SYS_INP_TouchMoveEvent

  Summary:
    Defines a touch move event

  Description:
    index - the touch index of the event
    x - the x coordinate
    y - the y coordinate
    
  Remarks:
    None.
*/
typedef struct SYS_INP_TouchMoveEvent_t
{
    uint8_t index;
    int16_t x;
    int16_t y;
} SYS_INP_TouchMoveEvent;

/* Touch Handler Function Definitions */
typedef void (*SYS_INP_HandleTouchDownEvent)(const SYS_INP_TouchStateEvent* const);
typedef void (*SYS_INP_HandleTouchUpEvent)(const SYS_INP_TouchStateEvent* const);
typedef void (*SYS_INP_HandleTouchMoveEvent)(const SYS_INP_TouchMoveEvent* const);

#endif /* SYS_INPUT_TOUCH_H */