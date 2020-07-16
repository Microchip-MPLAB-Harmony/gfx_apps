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
    APP_STATE_LOAD_SPLASH,
    APP_STATE_SPLASH,
    APP_STATE_UNLOAD_SPLASH, 
    APP_STATE_ANIMATE_MAIN_SCREEN0,
    APP_STATE_ANIMATE_MAIN_SCREEN1,
    APP_STATE_ANIMATE_MAIN_SCREEN2,
    APP_STATE_LOAD_MAIN_SCREEN,
    APP_STATE_PROCESS_MAIN_SCREEN,
    APP_STATE_IDLE_MAIN_SCREEN,
    /* TODO: Define states used by the application state machine. */

} APP_STATES;

typedef enum
{
    ZONE_DRIVER,
    ZONE_FRONT_PASSENGER,
    ZONE_LEFT_PASSENGER,
    ZONE_RIGHT_PASSENGER,
    ZONE_MAX,
} ZONE;

typedef enum
{
    EVENT_NONE,
    EVENT_ZONE_DRIVER,
    EVENT_ZONE_FRONT_PASS,
    EVENT_ZONE_LEFT_PASS,
    EVENT_ZONE_RIGHT_PASS,
    EVENT_SYNC_ON,
    EVENT_SYNC_OFF,
    EVENT_TEMP_UP,
    EVENT_TEMP_DOWN,
    EVENT_FAN_UP,
    EVENT_FAN_DOWN,
    EVENT_HIGHVENT_ON,
    EVENT_HIGHVENT_OFF,
    EVENT_MIDVENT_ON,
    EVENT_MIDVENT_OFF,
    EVENT_LOWVENT_ON,
    EVENT_LOWVENT_OFF,
    EVENT_CC_ON,
    EVENT_CC_OFF,
    EVENT_SEAT_WARM_ON,
    EVENT_SEAT_WARM_OFF,
    EVENT_AC_ON,
    EVENT_AC_OFF,
    EVENT_FRESH_AIR,
    EVENT_RECIRCULATE,
    EVENT_FRONT_VENT_ON,
    EVENT_FRONT_VENT_OFF,
    EVENT_REAR_VENT_ON,
    EVENT_REAR_VENT_OFF,
    EVENT_HIDE_CLOCK,
    EVENT_SHOW_CLOCK,
    EVENT_HIDE_INFOPAGE,
    EVENT_SHOW_INFOPAGE,
    EVENT_MOVEUP_INFOPAGE,
    EVENT_MOVEDOWN_INFOPAGE,   
    EVENT_HANDLE_LOCK_INFOPAGE,
    EVENT_HANDLE_UNLOCK_INFOPAGE,            
} APP_EVENTS;


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
    APP_EVENTS event;
    ZONE zone;

    /* TODO: Define any additional data used by the application. */

} APP_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

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

void APP_SetEvent(APP_EVENTS event);



#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

