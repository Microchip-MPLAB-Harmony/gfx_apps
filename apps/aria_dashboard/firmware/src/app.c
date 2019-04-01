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
#include "gfx/hal/inc/gfx_common.h"
#include "gfx/hal/inc/gfx_interface.h"
#include "gfx/hal/inc/gfx_math.h"
#include "gfx/hal/inc/gfx_context.h"
#include "gfx/libaria/libaria_init.h"
#include "system/time/sys_time.h"
#include "app_splash.h"
#include "app.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
uint32_t maxValueGear[] =
{
   IDLE_VALUE,
   MAX_VALUE_FIRST_GEAR,
   MAX_VALUE_SECOND_GEAR,
   MAX_VALUE_THIRD_GEAR,
   MAX_VALUE_FOURTH_GEAR,
   MAX_VALUE_FIFTH_GEAR,
   MAX_VALUE_SIXTH_GEAR,
};

uint32_t RPMDropGear[] =
{
   GET_RPM_FROM_VALUE(IDLE_VALUE),
   MAX_RPMx100_FIRST_GEAR,
   MAX_RPMx100_FIRST_GEAR * RATIO_SECOND_GEAR_DIV100 / RATIO_FIRST_GEAR_DIV100 + 2,
   MAX_RPMx100_SECOND_GEAR * RATIO_THIRD_GEAR_DIV100 / RATIO_SECOND_GEAR_DIV100 + 1,
   MAX_RPMx100_THIRD_GEAR * RATIO_FOURTH_GEAR_DIV100 / RATIO_THIRD_GEAR_DIV100 + 1,
   MAX_RPMx100_FOURTH_GEAR * RATIO_FIFTH_GEAR_DIV100 / RATIO_FOURTH_GEAR_DIV100 + 1,
   MAX_RPMx100_FIFTH_GEAR * RATIO_SIXTH_GEAR_DIV100 / RATIO_FIFTH_GEAR_DIV100 + 1,
};

uint32_t RPMFactorByGear[] =
{
   0,
   RATIO_FIRST_GEAR_DIV100,
   RATIO_SECOND_GEAR_DIV100,
   RATIO_THIRD_GEAR_DIV100,
   RATIO_FOURTH_GEAR_DIV100,
   RATIO_FIFTH_GEAR_DIV100,
   RATIO_SIXTH_GEAR_DIV100,
};

char * GearNums[] =
{
   "P",
   "1",
   "2",
   "3",
   "4",
   "5",
   "6",
};

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
static SYS_TIME_HANDLE handleTimerBlinker = SYS_TIME_HANDLE_INVALID;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

static void Timer_Callback (uintptr_t context)
{
    static laBool indicatorOn = LA_FALSE;
    
    switch (appData.event)
    {
        case APP_EVENT_GAS_ON_LEFT:
        {
            laWidget_SetVisible((laWidget*) TurnLeftImageWidget, indicatorOn);
            laWidget_SetVisible((laWidget*) TurnRightImageWidget, LA_FALSE);
            break;
        }
        case APP_EVENT_GAS_ON_RIGHT:
        {
            laWidget_SetVisible((laWidget*) TurnLeftImageWidget, LA_FALSE);
            laWidget_SetVisible((laWidget*) TurnRightImageWidget, indicatorOn);
            break;
        }
        default:
        {
            laWidget_SetVisible((laWidget*) TurnLeftImageWidget, LA_FALSE);
            laWidget_SetVisible((laWidget*) TurnRightImageWidget, LA_FALSE);
            break;
        }
    }
    
    indicatorOn = (indicatorOn == LA_FALSE) ? LA_TRUE : LA_FALSE;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


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



    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

void APP_Update_Gear(char * gear)
{
    char charBuff[10] = {0};
    laString str;

    sprintf(charBuff, "%s", gear);

    str = laString_CreateFromCharBuffer(charBuff, 
            GFXU_StringFontIndexLookup(&stringTable, string_GearLabelStringSet, 0));

    laLabelWidget_SetText(GearLabelWidget, str);

    laString_Destroy(&str);
}

void APP_Update_Speed(uint32_t speed)
{
    char charBuff[10] = {0};
    laString str;
    
    appData.speed = speed;
    
    sprintf(charBuff, "%d", speed);

    str = laString_CreateFromCharBuffer(charBuff, 
            GFXU_StringFontIndexLookup(&stringTable, string_SpeedoLabelStringSet, 0));

    laLabelWidget_SetText(SpeedoLabelWidget, str);

    laString_Destroy(&str);
}

void APP_Update_Odo(void)
{
    static uint32_t odoValue = 10000;
    static uint32_t TripAOdoValue = 2653;
    char charBuff[10];
    laString str;
    
    odoValue += appData.speed/30;
    TripAOdoValue += appData.speed/30;

    sprintf(charBuff, "%d", odoValue);

    str = laString_CreateFromCharBuffer(charBuff, 
            GFXU_StringFontIndexLookup(&stringTable, string_OdoLabelStringSet, 0));

    laLabelWidget_SetText(OdometerLabelWidget, str);
    
    laString_Destroy(&str);

    sprintf(charBuff, "%d", TripAOdoValue);

    str = laString_CreateFromCharBuffer(charBuff, 
            GFXU_StringFontIndexLookup(&stringTable, string_TripStringSet, 0));

    laLabelWidget_SetText(TripALabelWidget, str);
    
    laString_Destroy(&str);
}

void APP_Update_Fuel_Gauge(uint32_t fuel)
{
    laWidget_SetVisible((laWidget*) GasGauge100Rect, (laBool) (fuel > MAX_FUEL_VALUE * 9 / 10));
    laWidget_SetVisible((laWidget*) GasGauge90Rect, (laBool) (fuel > MAX_FUEL_VALUE * 8 / 10));
    laWidget_SetVisible((laWidget*) GasGauge80Rect, (laBool) (fuel > MAX_FUEL_VALUE * 7 / 10));
    laWidget_SetVisible((laWidget*) GasGauge70Rect, (laBool) (fuel > MAX_FUEL_VALUE * 6 / 10));
    laWidget_SetVisible((laWidget*) GasGauge60Rect, (laBool) (fuel > MAX_FUEL_VALUE * 5 / 10));
    laWidget_SetVisible((laWidget*) GasGauge50Rect, (laBool) (fuel > MAX_FUEL_VALUE * 4 / 10));
    laWidget_SetVisible((laWidget*) GasGauge40Rect, (laBool) (fuel > MAX_FUEL_VALUE * 3 / 10));
    laWidget_SetVisible((laWidget*) GasGauge30Rect, (laBool) (fuel > MAX_FUEL_VALUE * 2 / 10));
    laWidget_SetVisible((laWidget*) GasGauge20Rect, (laBool) (fuel > MAX_FUEL_VALUE / 10));
    laWidget_SetVisible((laWidget*) GasGauge10Rect, (laBool) (fuel > 0));
    laWidget_SetVisible((laWidget*) GasGauge0Rect, (LA_TRUE));
}

static inline void APP_DelayMS(int ms)
{
    SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

    if (SYS_TIME_DelayMS(ms, &timer) != SYS_TIME_SUCCESS)
        return;
    while (SYS_TIME_DelayIsComplete(timer) == false);
}

           
static void buttonTouchDown(laWidget* widget, laInput_TouchDownEvent* evt)
{
    evt->event.accepted = LA_TRUE;
    
    if (evt->x > GFX_ActiveContext()->display_info->rect.width * 2 / 3)
        appData.event = APP_EVENT_GAS_ON_RIGHT;
    else if (evt->x > GFX_ActiveContext()->display_info->rect.width / 3)
        appData.event = APP_EVENT_GAS_ON;
    else
        appData.event = APP_EVENT_GAS_ON_LEFT;
        
    if (handleTimerBlinker == SYS_TIME_HANDLE_INVALID)
        handleTimerBlinker = SYS_TIME_CallbackRegisterMS(Timer_Callback, 1, 500, SYS_TIME_PERIODIC);

    evt->event.accepted = LA_TRUE;
}
 
static void buttonTouchMoved(laWidget* widget, laInput_TouchMovedEvent* evt)
{
    evt->event.accepted = LA_TRUE;

    if (evt->x > GFX_ActiveContext()->display_info->rect.width * 2 / 3)
        appData.event = APP_EVENT_GAS_ON_RIGHT;
    else if (evt->x > GFX_ActiveContext()->display_info->rect.width / 3)
        appData.event = APP_EVENT_GAS_ON;
    else
        appData.event = APP_EVENT_GAS_ON_LEFT;
         
    evt->event.accepted = LA_TRUE;
}

static void buttonTouchUp(laWidget* widget, laInput_TouchUpEvent* evt)
{
    evt->event.accepted = LA_TRUE;
    
    appData.event = APP_EVENT_GAS_OFF;
     
    laWidget_SetVisible((laWidget*) TurnLeftImageWidget, LA_FALSE);
    laWidget_SetVisible((laWidget*) TurnRightImageWidget, LA_FALSE);
     
    if (handleTimerBlinker != SYS_TIME_HANDLE_INVALID)
    {
        SYS_TIME_TimerDestroy(handleTimerBlinker);        
        handleTimerBlinker = SYS_TIME_HANDLE_INVALID;
    }
}

static void APP_EnableIndicators(laBool enable)
{
    laWidget_SetVisible((laWidget*) ClimateControlLabelWidget, enable);
    laWidget_SetVisible((laWidget*) TripBLabelWidget, enable);
    laWidget_SetVisible((laWidget*) OdometerLabelWidget, enable);
    laWidget_SetVisible((laWidget*) TripALabelWidget, enable);
    laWidget_SetVisible((laWidget*) MPGLabelWidget, enable);
    laWidget_SetVisible((laWidget*) GPSBaseImageWidget, enable);
    laWidget_SetVisible((laWidget*) DriveModeImageWidget, enable);
    laWidget_SetVisible((laWidget*) SpeedoLabelWidget, enable);
}

static void APP_SetdisplayBrightnessPctValue(unsigned int pct)
{
    if (pct <= 100)
        GFX_Set(GFXF_BRIGHTNESS, pct);
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
  
    static uint32_t displayBrightnessPct = 0;

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;

            if (appInitialized)
            {
                appData.speed = 0;
                appData.state = APP_STATE_SPLASH_BRIGHTEN;
                appData.value = MIN_VALUE;
                appData.event = APP_EVENT_NONE;
                appData.fuel = 0;
                displayBrightnessPct = 0;
            }
            break;
        }
        case APP_STATE_SPLASH_BRIGHTEN:
        {
            if (laContext_GetActive()->activeScreen->id != 0)
                break;            
            
            if (displayBrightnessPct < 100)
            {
                APP_SetdisplayBrightnessPctValue(displayBrightnessPct);
                displayBrightnessPct += BACKLIGHT_PWM_DELTA;
                APP_DelayMS(BACKLIGHT_DELTA_DELAY_MS);
            }
            else
            {
                APP_SetdisplayBrightnessPctValue(100);
                appData.state = APP_STATE_SPLASH;
            }    
            break;          
        }
        case APP_STATE_SPLASH:
        {
            if (APP_IsSplashScreenComplete())
            {   
                appData.state = APP_STATE_SPLASH_DIM;
                displayBrightnessPct = 100;
            }
            break;
        }
        case APP_STATE_SPLASH_DIM:
        {
            if (displayBrightnessPct > 0)
            {
                APP_SetdisplayBrightnessPctValue(displayBrightnessPct);
                displayBrightnessPct -= BACKLIGHT_PWM_DELTA;
                APP_DelayMS(BACKLIGHT_DELTA_DELAY_MS);
            }
            else
            {
                APP_SetdisplayBrightnessPctValue(0);
                
                laContext_SetActiveScreen(1);
                appData.state = APP_STATE_SCREEN_INIT;
            }          
            break;
        }
        case APP_STATE_SCREEN_INIT:
        {
            laWidget_Invalidate((laWidget*) TachoDrawSurface);
            APP_Update_Gear("P");
            APP_Update_Speed(0);
            APP_Update_Odo();
              
            APP_Update_Fuel_Gauge(0);
              
            laWidget_OverrideTouchDownEvent((laWidget*)CenterButtonWidget, &buttonTouchDown);
            laWidget_OverrideTouchMovedEvent((laWidget*)CenterButtonWidget, &buttonTouchMoved);
            laWidget_OverrideTouchUpEvent((laWidget*)CenterButtonWidget, &buttonTouchUp);
            
            laWidget_SetEnabled((laWidget *) CenterButtonWidget, LA_FALSE);
            
            appData.state = APP_STATE_SCREEN_ON;
            displayBrightnessPct = 0;
          
            break;
        }
        case APP_STATE_SCREEN_ON:
        {
            if (displayBrightnessPct < BACKLIGHT_PWM_VALUE_ENGINE_OFF)
            {
                APP_SetdisplayBrightnessPctValue(displayBrightnessPct);
                displayBrightnessPct += BACKLIGHT_PWM_DELTA;
                APP_DelayMS(BACKLIGHT_DELTA_DELAY_MS);
            }
            else
            {
                APP_SetdisplayBrightnessPctValue(BACKLIGHT_PWM_VALUE_ENGINE_OFF);
                appData.state = APP_STATE_ENGINE_OFF;
                
                laWidget_SetEnabled((laWidget*) EngineOnButton, LA_TRUE);
            }
            break;
        }
        case APP_STATE_ENGINE_OFF:
        {
            if (appData.event == APP_EVENT_ENGINE_ON)
            {
                displayBrightnessPct = BACKLIGHT_PWM_VALUE_ENGINE_OFF;
                appData.state = APP_STATE_ENGINE_TURNING_ON;
                appData.event = APP_EVENT_NONE;
                
                appData.value = MIN_VALUE;
                
                appData.fuel = 0;
                
                APP_Update_Fuel_Gauge(appData.fuel);
                laWidget_Invalidate((laWidget*) TachoDrawSurface);                
                
                laWidget_SetEnabled((laWidget*) EngineOnButton, LA_FALSE);
            }
            
            break;
        }
        case APP_STATE_ENGINE_TURNING_ON:
        {
            if (displayBrightnessPct < BACKLIGHT_PWM_VALUE_ENGINE_ON)
            {
                APP_SetdisplayBrightnessPctValue(displayBrightnessPct);
                displayBrightnessPct += BACKLIGHT_PWM_DELTA;
                APP_DelayMS(BACKLIGHT_DELTA_DELAY_MS);
            }
            else
            {
                APP_SetdisplayBrightnessPctValue(BACKLIGHT_PWM_VALUE_ENGINE_ON);
                
                appData.state = APP_STATE_TACHO_REV_UP;
            }
            
            break;          
        }
        case APP_STATE_TACHO_REV_UP:
        {
            appData.value += SPEED_VALUE_INC_ANGLE_STARTUP;            
            
            if (appData.value > MAX_VALUE)
            {
                appData.value = MAX_VALUE;
                appData.state = APP_STATE_TACHO_REV_DOWN;
            }
            
            laWidget_Invalidate((laWidget*) TachoDrawSurface);
              
            break;
        }
        case APP_STATE_TACHO_REV_DOWN:
        {
            appData.value -= SPEED_VALUE_DEC_ANGLE_STARTUP;
            
            if (appData.value < MIN_VALUE)
            {
                appData.value = MIN_VALUE;
                appData.state = APP_STATE_INDICATORS_LIGHTS_INIT;
            }
            
            laWidget_Invalidate((laWidget*) TachoDrawSurface);
            
            break;
        }
        case APP_STATE_INDICATORS_LIGHTS_INIT:
        {
            laWidget_SetVisible((laWidget*) IndicatorLightsOnImageWidget, LA_TRUE);
            laWidget_SetVisible((laWidget*) TurnLeftImageWidget, LA_TRUE);
            laWidget_SetVisible((laWidget*) TurnRightImageWidget, LA_TRUE);  
            
            appData.state = APP_STATE_INDICATOR_TEXTS_INIT;
            
            break;
        }
        case APP_STATE_INDICATOR_TEXTS_INIT:
        {
            APP_EnableIndicators(LA_TRUE);
            
            appData.state = APP_STATE_STARTUP_FUEL;
            
            break;
        }
        case APP_STATE_STARTUP_FUEL:
        {
            if (appData.fuel < MAX_FUEL_VALUE)
            {
                appData.fuel += FUEL_INC_VALUE;
                APP_Update_Fuel_Gauge(appData.fuel);
            }
            else
            {
                appData.fuel = MAX_FUEL_VALUE;
                
                APP_Update_Fuel_Gauge(appData.fuel);

                laWidget_SetVisible((laWidget*) IndicatorLightsOnImageWidget, LA_FALSE);
                laWidget_SetVisible((laWidget*) TurnLeftImageWidget, LA_FALSE);
                laWidget_SetVisible((laWidget*) TurnRightImageWidget, LA_FALSE);
                
                appData.state = APP_STATE_STARTUP;           
            }            
            break;
        }
        case APP_STATE_STARTUP:
        {
            if (appData.value < IDLE_VALUE)
            {
                appData.value += SPEED_VALUE_INC_STARTUP;
                laWidget_Invalidate((laWidget*) TachoDrawSurface);
            }
            else
            {
                appData.value = IDLE_VALUE;
                
                appData.state = APP_STATE_IDLE;
                appData.gear = APP_GEAR_IDLE;
                
                appData.event = APP_EVENT_NONE;
                
                laWidget_Invalidate((laWidget*) TachoDrawSurface);
                laWidget_SetVisible((laWidget*) DriveModeImageWidget, LA_TRUE);
                
                laWidget_SetEnabled((laWidget*) EngineOnButton, LA_TRUE);
                laWidget_SetEnabled((laWidget *) CenterButtonWidget, LA_TRUE);
            }
            
            break;
        }
        case APP_STATE_IDLE:
        {
            switch(appData.event)
            {
                case APP_EVENT_GAS_ON_LEFT:
                case APP_EVENT_GAS_ON_RIGHT:
                case APP_EVENT_GAS_ON:
                {
                    appData.gear = APP_GEAR_FIRST;
                    appData.state = APP_STATE_RUN;
                    APP_Update_Gear(GearNums[appData.gear]);
                    laWidget_SetEnabled((laWidget*) EngineOnButton, LA_FALSE);

                    break;
                }
                case APP_EVENT_ENGINE_OFF:
                {
                    appData.gear = APP_GEAR_IDLE;
                    appData.state = APP_STATE_ENGINE_TURNING_OFF_ENGINE;
                    appData.event = APP_EVENT_NONE;
                    displayBrightnessPct = BACKLIGHT_PWM_VALUE_ENGINE_ON;
                    
                    laWidget_SetEnabled((laWidget *) CenterButtonWidget, LA_FALSE);
                    laWidget_SetEnabled((laWidget*) EngineOnButton, LA_FALSE);
                    break;
                }
                default:
                {
                    if (appData.value > IDLE_VALUE)
                        appData.value = IDLE_VALUE;
                    else
                        appData.value = IDLE_VALUE + 1;
                    
                    laWidget_Invalidate((laWidget*) TachoDrawSurface);
                    
                    break;
                }
            }
            
            break;
        }
        case APP_STATE_ENGINE_TURNING_OFF_ENGINE:
        {
            if (appData.value > MIN_VALUE)
            {
                laWidget_Invalidate((laWidget*) TachoDrawSurface);
                appData.value -= SPEED_VALUE_INC_STARTUP;
            }
            else
            {
                appData.value = MIN_VALUE;
                
                laWidget_Invalidate((laWidget*) TachoDrawSurface);
                
                appData.state = APP_STATE_ENGINE_TURNING_OFF_FUEL;
            }
            
            break;
        }
       case APP_STATE_ENGINE_TURNING_OFF_FUEL:
        {
            if (appData.fuel > 0)
            {
                APP_Update_Fuel_Gauge(appData.fuel);
                appData.fuel -= FUEL_DEC_OFF_VALUE;
            }
            else
            {
                appData.fuel = 0;
                
                APP_Update_Fuel_Gauge(appData.fuel);
                
                appData.state = APP_STATE_ENGINE_TURNING_OFF_INDICATORS;
            }
            
            break;
        }
        case APP_STATE_ENGINE_TURNING_OFF_INDICATORS:
        {
            APP_EnableIndicators(LA_FALSE);
                
            appData.state = APP_STATE_ENGINE_TURNING_OFF_DIM;
            
            break;
        }           
        case APP_STATE_ENGINE_TURNING_OFF_DIM:
        {
            if (displayBrightnessPct > BACKLIGHT_PWM_VALUE_ENGINE_OFF)
            {
                APP_SetdisplayBrightnessPctValue(displayBrightnessPct);
                displayBrightnessPct -= BACKLIGHT_PWM_DELTA;
                APP_DelayMS(BACKLIGHT_DELTA_DELAY_MS);
            }
            else
            {
                APP_SetdisplayBrightnessPctValue(BACKLIGHT_PWM_VALUE_ENGINE_OFF);
                
                laWidget_SetEnabled((laWidget*) EngineOnButton, LA_TRUE);
                
                appData.state = APP_STATE_ENGINE_OFF;
            }
            
            break;
        }              
        case APP_STATE_RUN:
        {
            if (appData.event == APP_EVENT_GAS_OFF)
            {
                appData.value -= SPEED_VALUE_DEC_OFF;
                    
                if (appData.value <= maxValueGear[appData.gear - 1])
                    appData.gear--;
                
                if (appData.gear == APP_GEAR_IDLE)
                {
                    APP_Update_Gear(GearNums[appData.gear]);
                    appData.state = APP_STATE_IDLE;
                    APP_Update_Speed(0);
                    laWidget_SetEnabled((laWidget*) EngineOnButton, LA_TRUE);
                }
                else
                {
                    APP_Update_Gear(GearNums[appData.gear]);
                    APP_Update_Speed(GET_SPEED_FROM_RPMx100(GET_RPMx100_FROM_VALUE(appData.value), 
                             RPMFactorByGear[appData.gear]));                    
                }
                
            }
            else
            {
                if (appData.fuel > 0)
                {
                    appData.fuel -= FUEL_DEC_VALUE;
                }
              
                appData.value += SPEED_VALUE_INC_RUN;
                
                if (appData.value >= MAX_VALUE)
                {
                    appData.value = MAX_VALUE;
                }
                else if (appData.value >= maxValueGear[appData.gear])
                {
                    if (appData.gear < APP_GEAR_SIXTH)
                    {
                        appData.gear++;
                        appData.value = GET_VALUE_FROM_RPMx100(RPMDropGear[appData.gear]);                         
                        APP_Update_Gear(GearNums[appData.gear]);
                    }
                }
                
                APP_Update_Speed(GET_SPEED_FROM_RPMx100(GET_RPMx100_FROM_VALUE(appData.value), 
                             RPMFactorByGear[appData.gear]));
            }
            
            if (appData.fuel <= 0)
            {
                appData.fuel = 0;
                appData.state = APP_STATE_COAST;
                appData.event = APP_EVENT_NONE;
            }
            
            APP_Update_Fuel_Gauge(appData.fuel);
            APP_Update_Odo();
            laWidget_Invalidate((laWidget*) TachoDrawSurface);            
            
            break;
        }
        case APP_STATE_COAST:
        {
            appData.value -= SPEED_VALUE_DEC_OFF;
            appData.event = APP_EVENT_NONE;
            
            if (appData.value <= maxValueGear[appData.gear - 1])
            {
                appData.gear--;
                APP_Update_Gear(GearNums[appData.gear]);
            }
                
            if (appData.gear == APP_GEAR_IDLE)
            {
                appData.state = APP_STATE_REFUEL;
                APP_Update_Speed(0);
            }
            else
            {
                APP_Update_Speed(GET_SPEED_FROM_RPMx100(GET_RPMx100_FROM_VALUE(appData.value), RPMFactorByGear[appData.gear]));
            }
                
            APP_Update_Odo();
            laWidget_Invalidate((laWidget*) TachoDrawSurface);    
              
            break;
        }
        case APP_STATE_REFUEL:
        {
            if (appData.fuel < MAX_FUEL_VALUE)
            {
                appData.fuel += FUEL_INC_VALUE;
            }
            else
            {
                appData.value = IDLE_VALUE;
                appData.state = APP_STATE_IDLE;
                appData.gear = APP_GEAR_IDLE;
                appData.fuel = MAX_FUEL_VALUE;
                laWidget_SetEnabled((laWidget*) EngineOnButton, LA_TRUE);
                
            }
            
            APP_Update_Fuel_Gauge(appData.fuel);
            
            appData.event = APP_EVENT_NONE;
            
            break;
        }   
        
        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
