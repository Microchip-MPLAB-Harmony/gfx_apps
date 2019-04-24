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
    APP_STATE_SPLASH,
    APP_STATE_MAIN_PRETRANSITION,
    APP_STATE_MAIN_TRANSITION,
    APP_STATE_MAIN,
    APP_STATE_INFO

} APP_STATES;

typedef enum
{
	/* Keeps track of the phase location of the menu. */
	MODE_AC,
	MODE_NAV,
	MODE_BT,
	MODE_MUSIC,
	MODE_PHONE,
    
} APP_MODE_SELECTIONS;

typedef enum
{
	MODE_FACE,
	MODE_BOTH,
	MODE_FEET,
    
} APP_AC_MODE;

typedef enum
{
	MODE_INTAKE,
	MODE_LOOP,
    
} APP_INTAKE_MODE;


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
    
    bool launched;
    
    bool moveRightTrayOut;
    
    bool moveRightTrayIn;

    bool moveLeftTrayOut;

    bool moveLeftTrayIn;
  
    bool isGPUOn;
    
    bool gpuButtonNeedsUpdate;
    
    uint32_t delayCounter;
    
    uint32_t language;
    
    uint32_t baseLayerAlpha;
    
    uint32_t upperLayerAlpha;
    
    APP_MODE_SELECTIONS mode;
    
    APP_AC_MODE acMode;
    
    APP_INTAKE_MODE intakeMode;
    
    uint32_t rightTemp;
    
    uint32_t leftTemp;
    
    int32_t aspectRatio;
    
    bool touchDown0;
    
    bool touchDown1;
    
} APP_DATA;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void APP_GoToMainState(void);

void APP_GoToSplashState(void);

void APP_GoToInfoState(void);

void APP_ToggleGPU(void);

void APP_SelectItem(int32_t value);

void APP_ACMode(int32_t mode);

void APP_ACIntake(int32_t mode);

void APP_SyncAC(void);

void APP_RightACChange(int32_t value);

void APP_LeftACChange(int32_t value);

void APP_MusicShuffle(void);

void APP_MusicPlayTrack(void);

void APP_MoveTrayIn(void);

void APP_ModeUp(void);

void APP_ModeDown(void);

void APP_HandleTray(int32_t value);

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

