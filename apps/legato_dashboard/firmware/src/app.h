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
#include "definitions.h"

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
    APP_STATE_FADE_IN_SPLASH,
    APP_STATE_FADE_OUT_SPLASH,            
    APP_STATE_INIT_OVERLAYS,
    APP_STATE_PROCESS_SCENE1,
    APP_STATE_PROCESS_SCENE2,
 
} APP_STATES;

typedef enum
{
    /* Application's state machine's initial state. */
    APP_SCENE_STATE_INIT,
    APP_SCENE_STATE_READY_EVENT_HANDLERS,
    APP_SCENE_STATE_FADE_IN_SCREEN,
    APP_SCENE_STATE_INTRO_NEEDLES_UP,
    APP_SCENE_STATE_INTRO_NEEDLES_DOWN,
    APP_SCENE_STATE_PROCESS_TASKS,
    APP_SCENE_STATE_SWITCH_SCENE_1_2_0,
    APP_SCENE_STATE_SWITCH_SCENE_1_2_1,
    APP_SCENE_STATE_SWITCH_SCENE_WAIT,
    /* TODO: Define states used by the application state machine. */
} APP_SCENE_STATES;

typedef enum
{
    APP_SCENE_1,
    APP_SCENE_2,
} APP_SCENE;

typedef enum
{
    APP_LAYER0 = 0,
    APP_LAYER1,
    APP_LAYER2
} APP_LAYERS;

typedef enum
{
    LEVEL0,
    LEVEL1,
    LEVEL2,
    LEVEL3,
    LEVEL_MAX,
} APP_ENERGY_LEVEL;

typedef struct
{
    leImage * imgAst;
    uint32_t x;
    uint32_t y;
} needleObj;

#define PDA_5IN_DISPLAY

#ifdef PDA_5IN_DISPLAY
#define GFX_GLCD_CONFIG_CLK_DIVIDER_FAST 4 
#define GFX_GLCD_CONFIG_CLK_DIVIDER_MED 5
#define GFX_GLCD_CONFIG_CLK_DIVIDER_SLOW 12

#define GFX_GLCD_CONFIG_CLK_DIVIDER_NORMAL 4 
#define GFX_GLCD_CONFIG_CLK_DIVIDER_PREPROCESSING 4
#else
#define GFX_GLCD_CONFIG_CLK_DIVIDER_FAST 8
#define GFX_GLCD_CONFIG_CLK_DIVIDER_MED 8
#define GFX_GLCD_CONFIG_CLK_DIVIDER_SLOW 12

#define GFX_GLCD_CONFIG_CLK_DIVIDER_NORMAL 8
#define GFX_GLCD_CONFIG_CLK_DIVIDER_PREPROCESSING 8
#endif

#define SCREEN_WIDTH_PX 800
#define SCREEN_HEIGHT_PX 480

#define ANIM_DEMO_MODE_TIMER_PERIOD_MS 800

//Start demo after idle period
#define ANIM_DEMO_MODE_IDLE_PERIOD_MS 10000

//Run demo for a while, then switch to next scene
#define ANIM_DEMO_MODE_RUN_PERIOD_MS 20000 //20 seconds

#define ANIM_TIMER_PERIOD_US 3000

#define DOUBLE_TAP_PERIOD_MS 100

#define DOUBLE_TAP_COUNT_LIMIT ((DOUBLE_TAP_PERIOD_MS * 1000)/ANIM_TIMER_PERIOD_US)
#define SWIPE_THRESHOLD_PIXELS 5
#define RIGHT_EDGE_TOUCH_X_MIN 790
#define LEFT_EDGE_TOUCH_X_MAX 10
#define TOP_EDGE_TOUCH_Y_MAX 10
#define BOTTOM_EDGE_TOUCH_X_MAX 470

//Backlight defines
#define BACKLIGHT_IDLE_PERIOD_US 5000000 //5seconds
#define BACKLIGHT_IDLE_TIMEOUT_COUNT (BACKLIGHT_IDLE_PERIOD_US/ANIM_TIMER_PERIOD_US)
#define ON_BRIGHTNESS 100
#define DIM_BRIGHTNESS 30
#define OFF_BRIGHTNESS 0



typedef struct
{
    uint32_t left;
    uint32_t right;
} DEMO_MODE_GAUGE_VALUES;

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
    APP_SCENE_STATES scene_state;

    /* TODO: Define any additional data used by the application. */

} APP_DATA;

extern SYS_TIME_HANDLE animTimer;
extern volatile unsigned int animCounter;
extern unsigned int animCounterOld;
extern APP_DATA appData;
extern volatile uint32_t layerAlpha[3];
extern needleObj leftNeedles[360];
extern needleObj rightNeedles[360];
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
void animTimer_Callback ( uintptr_t context);
void appSetLayerFrame(uint32_t layerID, 
                      uint32_t addr,
                      uint32_t x,
                      uint32_t y,
                      uint32_t width,
                      uint32_t height);

void APP_PreprocessSplashImages(void);
void APP_PreprocessNeedleImages(void);
void StartAnimTimer();

void appSetLeftNeedleImageData(leImage * imgAst,
                           uint32_t angle,
                           uint32_t x,
                           uint32_t y);

void appSetRightNeedleImageData(leImage * imgAst,
                           uint32_t angle,
                           uint32_t x,
                           uint32_t y);

void APP_Process_Scene1(void);
void APP_Process_Scene2(void);
void APP_SetBacklightBrightness(unsigned int pct);
unsigned int APP_GetBacklightBrightness(void);

#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

