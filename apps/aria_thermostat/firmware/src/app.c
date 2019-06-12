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

#include "gfx/libaria/inc/libaria_scheme.h"
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

extern laScheme whiteScheme;
extern laScheme blueScheme;
extern laScheme redScheme;
extern laScheme coolingScheme;
extern laScheme warmingScheme;

#define BACKLIGHT_PWM_DELTA 0x1
#define BACKLIGHT_DELTA_DELAY_MS 5

#define SECONDS_TO_TEMP_CHANGE 5

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
static SYS_TIME_HANDLE displayToggleTimer = SYS_TIME_HANDLE_INVALID;
static SYS_TIME_HANDLE handleTimer = SYS_TIME_HANDLE_INVALID;
static SYS_TIME_HANDLE idleTimer = SYS_TIME_HANDLE_INVALID;

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

static inline void APP_DelayMS(int ms)
{
    SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

    if (SYS_TIME_DelayMS(ms, &timer) != SYS_TIME_SUCCESS)
        return;
    while (SYS_TIME_DelayIsComplete(timer) == false);
}

static void APP_SetDisplayBrightness(unsigned int pct)
{
    if (pct <= 100)
        GFX_Set(GFXF_BRIGHTNESS, pct);
}

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
    
    if (appData.state == APP_STATE_IDLE)
    {
        appData.state = APP_STATE_MAIN_TRANSITION;
        
        if (displayToggleTimer != SYS_TIME_HANDLE_INVALID)
        {
            SYS_TIME_TimerDestroy(displayToggleTimer);        
            displayToggleTimer = SYS_TIME_HANDLE_INVALID;
        }
    }
}

void APP_UpdateClockLabel()
{
    char buff[10]; 
    laString str;  

    sprintf(buff, "%02u:%02u:%02u", appData.currentHour, appData.currentMin, appData.currentSec); 

    str = laString_CreateFromCharBuffer(buff, 
            GFXU_StringFontIndexLookup(&stringTable, string_String_Time, 0));

    laLabelWidget_SetText(LabelWidget_Temp, str);

    laString_Destroy(&str);
}

void APP_UpdateCurrentTempArc()
{
    int32_t startAngle = 0;
    
    if (appData.currentTemp <= 85)
    {
        startAngle = (85 - appData.currentTemp) * 9;
    }
    else
    {
        startAngle = 360 - (appData.currentTemp - 85) * 9;
    }
    
    if (appData.targetTemp < appData.currentTemp)
    {
        laWidget_SetScheme((laWidget*)ArcWidget_CurrentTemp, &coolingScheme);
    }
    else if (appData.targetTemp > appData.currentTemp)
    {
        laWidget_SetScheme((laWidget*)ArcWidget_CurrentTemp, &warmingScheme);
    }
    else
    {
        laWidget_SetScheme((laWidget*)ArcWidget_CurrentTemp, &whiteScheme);
    }

    laArcWidget_SetStartAngle(ArcWidget_CurrentTemp, startAngle);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

static void APP_ToggleDisplayTimerCallback(uintptr_t context)
{
    appData.showClock = !appData.showClock;
}

static void APP_IdleTimerCallback(uintptr_t context)
{
    if (idleTimer != SYS_TIME_HANDLE_INVALID)
    {
        SYS_TIME_TimerDestroy(idleTimer);        
        idleTimer = SYS_TIME_HANDLE_INVALID;
    }
    
    if (displayToggleTimer == SYS_TIME_HANDLE_INVALID)
    {
        displayToggleTimer = SYS_TIME_CallbackRegisterMS(APP_ToggleDisplayTimerCallback, 1, 15000, SYS_TIME_PERIODIC);                
    }

    appData.state = APP_STATE_IDLE;
}

static void APP_OneSecondCallback (uintptr_t context)
{
    static laBool indicatorOn = LA_FALSE;
    
    indicatorOn = (indicatorOn == LA_FALSE) ? LA_TRUE : LA_FALSE;
    
    laWidget_SetVisible((laWidget*)ImageSequenceWidget_TimeDot, indicatorOn);
    
    appData.currentSec++;
    if (appData.currentSec >= 60)
    {
        appData.currentSec = 0;
        appData.currentMin++;
        if (appData.currentMin >= 60)
        {
            appData.currentMin = 0;
            appData.currentHour++;
            if (appData.currentHour >= 24)
            {
                appData.currentHour = 0;
            }
        }
    }    

    //Simulate HVAC in-operation
    if (appData.tempChangeCount-- <= 0)
    {
        appData.tempChangeCount = SECONDS_TO_TEMP_CHANGE;

        if (appData.targetTemp > appData.currentTemp)
        {
            appData.currentTemp++;
        }
        else if (appData.targetTemp < appData.currentTemp)
        {
            appData.currentTemp--;
        }
    }
    
    APP_UpdateCurrentTempArc();

    if (appData.state != APP_STATE_IDLE)
        return;
    
    if (appData.showClock == true)
    {
        laLabelWidget_SetText(LabelWidget_Action, laString_CreateFromID(string_String_Clock));
        APP_UpdateClockLabel();
        
    }
    else
    {
        laLabelWidget_SetText(LabelWidget_Action, laString_CreateFromID(string_String_Current));
        APP_UpdateTempLabel(appData.currentTemp);
    }
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

    APP_UpdateTargetTemp(value);

    if (appData.targetTemp < appData.currentTemp)
    {
        laWidget_SetScheme((laWidget*)ArcWidget_Indicator, &coolingScheme);
        laWidget_SetScheme((laWidget*)LabelWidget_Temp, &coolingScheme);
        laWidget_SetScheme((laWidget*)ArcWidget_CurrentTemp, &whiteScheme);
    }
    else
    {
        laWidget_SetScheme((laWidget*)ArcWidget_Indicator, &warmingScheme);
        laWidget_SetScheme((laWidget*)LabelWidget_Temp, &warmingScheme);
        laWidget_SetScheme((laWidget*)ArcWidget_CurrentTemp, &whiteScheme);
    }

    laLabelWidget_SetText(LabelWidget_Action, laString_CreateFromID(string_String_Set));
    
    laArcWidget_SetStartAngle(ArcWidget_Indicator, value);
}

void APP_OnTouchRelease(void)
{
    if (appData.targetTemp < appData.currentTemp)
    {
        laWidget_SetScheme((laWidget*)ArcWidget_Indicator, &whiteScheme);
        laWidget_SetScheme((laWidget*)ArcWidget_CurrentTemp, &coolingScheme);
    }
    else
    {
        laWidget_SetScheme((laWidget*)ArcWidget_Indicator, &whiteScheme);
        laWidget_SetScheme((laWidget*)ArcWidget_CurrentTemp, &warmingScheme);
    }
    
    laLabelWidget_SetText(LabelWidget_Action, laString_CreateFromID(string_String_Current));
    laWidget_SetScheme((laWidget*)LabelWidget_Temp, &whiteScheme);
    
    APP_UpdateTempLabel(appData.currentTemp);
    APP_UpdateCurrentTempArc();
    
    appData.showClock = false;
    
    appData.tempChangeCount = SECONDS_TO_TEMP_CHANGE;
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
    appData.displayBrightnessPct = 0;
    delayCount = 0;
    
    appData.targetTemp = 75;
    appData.currentTemp = 78;
    
    appData.showClock = false;
    
    appData.currentHour = 4;
    appData.currentMin = 19;
    appData.currentSec = 1;
    
    appData.tempChangeCount = SECONDS_TO_TEMP_CHANGE;
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
                laContext_SetActiveScreen(MainScreen_ID);

                appData.state = APP_STATE_MAIN_TRANSITION;

                APP_SetDisplayBrightness(appData.displayBrightnessPct);
            }
            break;
        }

        case APP_STATE_MAIN_TRANSITION:
        {
            if (appData.displayBrightnessPct < 100)
            {
                APP_SetDisplayBrightness(appData.displayBrightnessPct);
                appData.displayBrightnessPct += BACKLIGHT_PWM_DELTA;
                APP_DelayMS(BACKLIGHT_DELTA_DELAY_MS);
            }
            else
            {
                if (handleTimer == SYS_TIME_HANDLE_INVALID)
                {
                    handleTimer = SYS_TIME_CallbackRegisterMS(APP_OneSecondCallback, 1, 1000, SYS_TIME_PERIODIC);
                }            

                appData.state = APP_STATE_MAIN;
            }
            
            break;
        }

        case APP_STATE_MAIN:
        {
            if (idleTimer == SYS_TIME_HANDLE_INVALID)
            {
                idleTimer = SYS_TIME_CallbackRegisterMS(APP_IdleTimerCallback, 1, 10000, SYS_TIME_SINGLE);                
            }
            
            if (appData.targetTemp > 85)
            {
                laImageSequenceWidget_ShowImage(ImageSequenceWidget_TimeDot, 1);
            }
            else
            {
                laImageSequenceWidget_ShowImage(ImageSequenceWidget_TimeDot, 0);
            }
            break;
        }
        
        case APP_STATE_IDLE:
        {
            if (appData.displayBrightnessPct >= 10)
            {
                APP_SetDisplayBrightness(appData.displayBrightnessPct);
                appData.displayBrightnessPct -= BACKLIGHT_PWM_DELTA;
                APP_DelayMS(BACKLIGHT_DELTA_DELAY_MS);
            }
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
