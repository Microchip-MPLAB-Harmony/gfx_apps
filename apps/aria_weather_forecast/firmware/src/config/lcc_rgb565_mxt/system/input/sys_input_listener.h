// DOM-IGNORE-BEGIN
/*******************************************************************************
 Module for Microchip Harmony Input System Service

  Company:
    Microchip Technology Inc.

  File Name:
    sys_input_listener.h

  Summary:
    MPLAB Harmony Input System Service listener definition

  Description:
    MPLAB Harmony Input System Service listener definition
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

#ifndef SYS_INPUT_LISTENER_H
#define SYS_INPUT_LISTENER_H
//DOM-IGNORE-END

#include "sys_input_gesture.h"
#include "sys_input_keyboard.h"
#include "sys_input_mouse.h"
#include "sys_input_touch.h"

// *****************************************************************************
/* Structure:
    SYS_INP_InputListener

  Summary:
    Defines input event listener functions.
    
  Description:
    An entity that desires to listen for input events must provide an
    SYS_INP_InputListener implementation and fill the function pointers
    appropriately to receive the events.
    
  Remarks:
    None
*/
typedef struct SYS_INP_InputListener_t
{
    /* keyboard handlers */
    SYS_INP_HandleKeyDownEvent handleKeyDown;
    SYS_INP_HandleKeyUpEvent handleKeyUp;
    
    /* mouse handlers */
    SYS_INP_HandleMouseMoveEvent handleMouseMove;
    SYS_INP_HandleMouseButtonDownEvent handleMouseButtonDown;
    SYS_INP_HandleMouseButtonUpEvent handleMouseButtonUp;
    
    /* touch handlers */
    SYS_INP_HandleTouchDownEvent handleTouchDown;
    SYS_INP_HandleTouchUpEvent handleTouchUp;
    SYS_INP_HandleTouchMoveEvent handleTouchMove;
    
    /* gesture handlers */
    SYS_INP_HandleFlickGestureEvent handleFlickGesture;
    SYS_INP_HandlePinchGestureEvent handlePinchGesture;
    SYS_INP_HandleStretchGestureEvent handleStretchGesture;
    SYS_INP_HandleRotateGestureEvent handleRotateGesture;
    
} SYS_INP_InputListener;

// *****************************************************************************
/* Function:
    void SYS_INP_ListenerInit(SYS_INP_InputListener* lst);

  Summary:
    Initializes an input listener struct to all empty functions.  Implementers
    must then overwrite the default function pointers with
    implementation-specific functions to handle events.
    
  Returns:
    None
*/
void SYS_INP_ListenerInit(SYS_INP_InputListener* l);


#endif /* SYS_INPUT_LISTENER_H */