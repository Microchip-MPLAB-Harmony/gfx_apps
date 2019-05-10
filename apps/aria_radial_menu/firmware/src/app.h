/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

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
//DOM-IGNORE-END

#ifndef _APP_H
#define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"

#include "bsp/bsp.h"
#include "gfx/libaria/inc/libaria_widget.h"
#include "gfx/hal/inc/gfx_common.h"
#include "gfx/hal/inc/gfx_processor_interface.h"
#include "gfx/driver/processor/2dgpu/libnano2D.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

//This is the first memory location after the last GLCD frame buffer
#define APP_PRELOAD_IMAGE_DDR_ADDRESS GFX_GLCD_LAYER2_DBL_BASEADDR + 0x177000
    
// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
	/* Application's state machine's initial state. */
	APP_STATE_INIT=0,
	APP_STATE_SPLASH,
	APP_STATE_MAIN,
	APP_STATE_INFO

} APP_STATES;

typedef enum
{
	/* Keeps track of the phase location of the menu. */
	MODE_SELECT_0,
	MODE_SELECT_1,
	MODE_SELECT_2,
	MODE_SELECT_3,
	MODE_SELECT_4,
	MODE_SELECT_5,
    
} APP_MODE_SELECTIONS;

typedef enum
{
	/* Keeps track of the phase location of the menu. */
	RADIAL_PHASE_0,
	RADIAL_PHASE_1,
	RADIAL_PHASE_2,
	RADIAL_PHASE_3,
	RADIAL_PHASE_4,
	RADIAL_PHASE_5,

	RADIAL_PHASE_TOTAL

} APP_RADIAL_MENU_PHASES;

#define APP_TOTAL_WIDGETS RADIAL_PHASE_TOTAL


// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* The application's current state */
    APP_STATES state;

    GFX_Rect widgetPos[APP_TOTAL_WIDGETS];
    
    APP_RADIAL_MENU_PHASES phase;
    
    void* buttonWidget[APP_TOTAL_WIDGETS];
    
    laWidget_TouchDownEvent_FnPtr buttonDefaultTouchDown[APP_TOTAL_WIDGETS];
    laWidget_TouchUpEvent_FnPtr buttonDefaultTouchUp[APP_TOTAL_WIDGETS];

	bool isGPUOn;
    
    bool gpuButtonNeedsUpdate;
    
    bool launched;
    
    bool touchPressed;    
    
    bool rotateDone;
    
    bool demoMode;
    
    int32_t touchMenuItemX;

    int32_t touchMenuItemY;
    
    uint8_t currentSelectionIndex;

} APP_DATA;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/
void APP_GoToSplashState ( bool demoMode );

void APP_GoToInfoState(void);

void APP_GoToMainState(void);

void APP_SwitchScreenRequest(APP_MODE_SELECTIONS select);

void APP_SelectItem(APP_MODE_SELECTIONS select);

void APP_ToggleGPU(void);

void APP_ResortDrawOrder(int top, int second, int third, int fourth, int fifth, int bottom);

GFX_Rect APP_RectLerp(GFX_Rect from, GFX_Rect to, GFX_Rect current, GFX_Rect widget, int32_t dx, int32_t* rollover);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the 
    application in its initial state and prepares it to run so that its 
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_Tasks( void );


#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

