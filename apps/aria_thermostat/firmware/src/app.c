/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>

#include "gfx/libaria/inc/libaria_utils.h"
#include "gfx/libaria/inc/libaria_context.h"
#include "gfx/libaria/libaria_init.h"
#include "gfx/hal/inc/gfx_common.h"
#include "gfx/hal/inc/gfx_interface.h"
#include "gfx/hal/inc/gfx_math.h"
#include "gfx/hal/inc/gfx_context.h"
#include "system/time/sys_time.h"

#include "app.h"
#include "app_splash.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

uint32_t delayCount;
static SYS_TIME_HANDLE handleTimer = SYS_TIME_HANDLE_INVALID;

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

void APP_UpdateTempLabel(int32_t value)
{
    char charBuff[10] = {0};
    laString str;
    
    sprintf(charBuff, "%d", value);
    
    str = laString_CreateFromCharBuffer(charBuff, 
            GFXU_StringFontIndexLookup(&stringTable, string_String_Numbers_Large, 0));

    laLabelWidget_SetText(LabelWidget_Temp, str);

    laString_Destroy(&str);
}

void APP_UpdateTargetTemp(int32_t value)
{
    if(value > 0 && value <= 228)
    {
        appData.targetTemp = 85 - value / 9;
    }
    else
    {
        appData.targetTemp = 85 + (360 - value) / 9;
    }
    
    APP_UpdateTempLabel(appData.targetTemp);
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

static void APP_TimerCallback (uintptr_t context)
{
    static laBool indicatorOn = LA_FALSE;
    
    indicatorOn = (indicatorOn == LA_FALSE) ? LA_TRUE : LA_FALSE;
    
    laWidget_SetVisible((laWidget*)ImageSequenceWidget_TimeDot, indicatorOn);
}

void APP_ValueChanged(int32_t value)
{
    if (laContext_IsDrawing())
        return;
    
    if (value > 228 && value < 310)
    {
        if (value <= 269)
        {
            value = 228;
        }
        else
        {
            value = 310;
        }
    }

    laArcWidget_SetStartAngle(ArcWidget_Indicator, value);
    
    APP_UpdateTargetTemp(value);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    
    delayCount = 0;
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

                appData.state = APP_STATE_SPLASH;
            }
            break;
        }

        case APP_STATE_SPLASH:
        {
            if (APP_IsSplashScreenComplete())
            {
                appData.state = APP_STATE_MAIN_TRANSITION;
            }
            break;
        }

        case APP_STATE_MAIN_TRANSITION:
        {
            if (delayCount++ < 500000)
                break;

            delayCount = 0;
            
            laContext_SetActiveScreen(MainScreen_ID);

            handleTimer = SYS_TIME_CallbackRegisterMS(APP_TimerCallback, 1, 1000, SYS_TIME_PERIODIC);
            
            appData.state = APP_STATE_MAIN;
            
            break;
        }

        case APP_STATE_MAIN:
        {
            break;
        }
        
        /* The default state should never be executed. */
        default:
        {
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
