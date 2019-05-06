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
#include "gfx/libaria/inc/libaria_widget_imagesequence.h"
#include "gfx/libaria/inc/libaria_screen.h"
#include "gfx/gfx_assets.h"
#include "gfx/hal/inc/gfx_math.h"
#include "app_splash.h"
#include "system/time/sys_time.h"

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
    APP_STATE_MAIN_TRANSITION,
    APP_STATE_SETUP_IMAGE,
    APP_STATE_AUDIO_CODEC_OPEN,
    APP_STATE_RUNNING,
    APP_STATE_INFO,    

} APP_STATES;

typedef enum
{
    SPRITE_IDLE,
    SPRITE_RUN,
    SPRITE_BLAZE,
    SPRITE_HURT,
    SPRITE_FALL,
    SPRITE_DIZZY
    
} APP_SPRITE_STATE;

typedef enum
{
    FACING_RIGHT,
    FACING_LEFT,
    
    FACING_DEFAULT = FACING_RIGHT,            
} APP_FACING_DIRECTIONS;

typedef enum
{
    USER_REQUESTED_STOP,
    USER_REQUESTED_GO_RIGHT,
    USER_REQUESTED_GO_LEFT,
            
} APP_USER_REQUESTED_DIRECTIONS;

// TODO: Placeholder until audio support reintroduced
//typedef struct
//{
//    DRV_HANDLE handle;
//    DRV_CODEC_BUFFER_HANDLE bufHandle; 
//    DRV_CODEC_BUFFER_EVENT_HANDLER bufferEventHandler;
//    uintptr_t context;
//    uint8_t *bufferObject1;
//    uint8_t *bufferObject2;
//    uint32_t bufferSize;
//    bool isCodecReadComplete1;
//} APP_CODEC_CLIENT;

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
    
    bool isEasterEggMode;

    int32_t layerX0;

    int32_t layerX1;

    int32_t layerX2;

    int32_t layerLimit0;
    
    int32_t layerLimit1;

    int32_t layerLimit2;

    int32_t spriteAnchorX;
    
    int32_t speedFactor;
    
    APP_FACING_DIRECTIONS spriteFacingDirection;
    
    APP_USER_REQUESTED_DIRECTIONS requestedDirection;
    
    APP_USER_REQUESTED_DIRECTIONS lastRequestedDirection;

    uint32_t backgroundLayerWidth;

    uint32_t backgroundLayerHeight;
    
    uint32_t middleLayerWidth;

    uint32_t middleLayerHeight;

    uint32_t foregroundLayerWidth;

    uint32_t foregroundLayerHeight;

    uint32_t delayCounter;
    
    uint32_t baseLayerAlpha;
    
    SYS_TIME_HANDLE  spriteTimer;
    
    SYS_TIME_HANDLE  pressCountTimer;
    
    int32_t spriteTriggerCount;
    
    laImageSequenceWidget* currentSequence;
    
    APP_SPRITE_STATE spriteState;
    
    int32_t uiLayerAlpha;
    
    int32_t spriteStamina;

    uint32_t spriteFrameLeft; //Used for the hurt, fall, dizzy sequence
    
    uint32_t currentScore;
    
    uint32_t topScore;

// TODO: Placeholder until audio support is reintroduced    
//    APP_CODEC_CLIENT codecClient;
    
    bool updateTopScore;
    
    bool demoMode;
    
} APP_DATA;



// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

void APP_Stop(void);
void APP_Right(void);
void APP_Left(void);
void APP_IdleRight_CallBack( uintptr_t context, uint32_t currTick );
void APP_IdleLeft_CallBack( uintptr_t context, uint32_t currTick );
void APP_RunRight_CallBack( uintptr_t context, uint32_t currTick );
void APP_RunLeft_CallBack( uintptr_t context, uint32_t currTick );
void APP_BlazeRight_CallBack( uintptr_t context, uint32_t currTick );
void APP_BlazeLeft_CallBack( uintptr_t context, uint32_t currTick );
void APP_GoToInfoState(void);
void APP_GoToMainState(void);
void APP_ToggleEasterEgg(void);

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

