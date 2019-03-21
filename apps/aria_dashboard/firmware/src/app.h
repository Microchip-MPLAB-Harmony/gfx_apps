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
#define START_VALUE_ANGLE 240
#define END_VALUE_ANGLE 0
#define MIN_VALUE 0
#define IDLE_VALUE 22
#define MAX_VALUE 240
#define VALUE_PER_1K_RPM 30
#define MAX_RPMx100_FIRST_GEAR 15
#define MAX_RPMx100_SECOND_GEAR 21
#define MAX_RPMx100_THIRD_GEAR 28
#define MAX_RPMx100_FOURTH_GEAR 35
#define MAX_RPMx100_FIFTH_GEAR 45
#define VALUE_RPM_FACTOR 3
#define MAX_VALUE_FIRST_GEAR (MAX_RPMx100_FIRST_GEAR * VALUE_RPM_FACTOR)
#define MAX_VALUE_SECOND_GEAR (MAX_RPMx100_SECOND_GEAR * VALUE_RPM_FACTOR)
#define MAX_VALUE_THIRD_GEAR (MAX_RPMx100_THIRD_GEAR * VALUE_RPM_FACTOR)
#define MAX_VALUE_FOURTH_GEAR (MAX_RPMx100_FOURTH_GEAR * VALUE_RPM_FACTOR)
#define MAX_VALUE_FIFTH_GEAR (MAX_RPMx100_FIFTH_GEAR * VALUE_RPM_FACTOR)
#define MAX_VALUE_SIXTH_GEAR MAX_VALUE
  
#define TIRE_CIRC_FT 6

#define RATIO_FIRST_GEAR_DIV100     378
#define RATIO_SECOND_GEAR_DIV100    206
#define RATIO_THIRD_GEAR_DIV100     123
#define RATIO_FOURTH_GEAR_DIV100    83
#define RATIO_FIFTH_GEAR_DIV100     79
#define RATIO_SIXTH_GEAR_DIV100     79
#define RATIO_FINAL_DRIVE_DIV     4
  
#define MAX_FUEL_VALUE  100000
#define FUEL_DEC_VALUE  200
#define FUEL_INC_VALUE  1

#define GET_VALUE_FROM_RPMx100(rpm)             (rpm * VALUE_RPM_FACTOR)
#define GET_RPMx100_FROM_VALUE(value)           (value / VALUE_RPM_FACTOR)
#define GET_RPM_FROM_VALUE(value)               (value * 1000 / VALUE_RPM_FACTOR)
#define GET_SPEED_FROM_RPMx100(rpm_x100, gear_ratio_d100)  \
                              ((rpm_x100 * 100 * 100 * TIRE_CIRC_FT) / \
                             (RATIO_FINAL_DRIVE_DIV * gear_ratio_d100 * 88))
#define GET_ANGLE_FROM_VALUE(value)             (START_VALUE_ANGLE - value)
  
#define SPEED_VALUE_DEC_OFF 2
#define SPEED_VALUE_INC_RUN 1
#define SPEED_VALUE_DEC_GEAR_CHANGE 5
  
#define SPEED_VALUE_INC_ANGLE_STARTUP 30
#define SPEED_VALUE_DEC_ANGLE_STARTUP 30
                                
#define BLINKER_PERIOD_MS 300
                                
#define BACKLIGHT_PWM_DELTA 0x1
#define BACKLIGHT_DELTA_DELAY_MS 2
      
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
    APP_STATE_SPLASH_BRIGHTEN,
    APP_STATE_SPLASH,
    APP_STATE_SPLASH_DIM,
    APP_STATE_SCREEN_INIT,
    APP_STATE_SCREEN_ON,
    APP_STATE_TACHO_REV_UP,
    APP_STATE_TACHO_REV_DOWN, 
    APP_STATE_INDICATOR_LIGHTS_INIT,
    APP_STATE_INDICATOR_TEXTS_INIT,
    APP_STATE_STARTUP,
    APP_STATE_REFUEL,    
    APP_STATE_IDLE,
    APP_STATE_RUN,
    APP_STATE_COAST,
} APP_STATES;

typedef enum
{
    APP_GEAR_IDLE,  
    APP_GEAR_FIRST,
    APP_GEAR_SECOND,
    APP_GEAR_THIRD,
    APP_GEAR_FOURTH,
    APP_GEAR_FIFTH,
    APP_GEAR_SIXTH,
} APP_GEAR;

typedef enum
{
    APP_EVENT_GAS_ON_LEFT,
    APP_EVENT_GAS_ON_RIGHT,
    APP_EVENT_GAS_ON,
    APP_EVENT_GAS_OFF,
    APP_EVENT_NONE,
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
    int value;
    APP_EVENTS event;
    APP_GEAR gear;
    int speed;
    int fuel;

    /* TODO: Define any additional data used by the application. */

} APP_DATA;

extern APP_DATA appData;

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



#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

