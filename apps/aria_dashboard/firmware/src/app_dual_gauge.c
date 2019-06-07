/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_dual_gauge.c

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

#include "gfx/libaria/inc/libaria_utils.h"
#include "gfx/hal/inc/gfx_common.h"
#include "gfx/hal/inc/gfx_interface.h"
#include "gfx/hal/inc/gfx_math.h"
#include "gfx/hal/inc/gfx_context.h"
#include "gfx/libaria/libaria_init.h"
#include "app.h"
#include "app_splash.h"
#include "definitions.h"
#include "system/time/sys_time.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
#define START_VALUE_ANGLE 240
#define START_SPEED_ANGLE 225
#define END_VALUE_ANGLE 0
#define MIN_VALUE 0
#define MIN_SPEED 0
#define IDLE_VALUE 22
#define MAX_VALUE 240
#define MAX_SPEED 225
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

#define RATIO_FIRST_GEAR_DIV100     250
#define RATIO_SECOND_GEAR_DIV100    230
#define RATIO_THIRD_GEAR_DIV100     210
#define RATIO_FOURTH_GEAR_DIV100    190
#define RATIO_FIFTH_GEAR_DIV100     170
#define RATIO_SIXTH_GEAR_DIV100     150
#define RATIO_FINAL_DRIVE_DIV     4

#define GET_VALUE_FROM_RPMx100(rpm)             (rpm * VALUE_RPM_FACTOR)
#define GET_RPMx100_FROM_VALUE(value)           (value / VALUE_RPM_FACTOR)
#define GET_RPM_FROM_VALUE(value)               (value * 1000 / VALUE_RPM_FACTOR)
#define GET_SPEED_FROM_RPMx100(rpm_x100, gear_ratio_d100)  \
                              ((rpm_x100 * 100 * 100 * TIRE_CIRC_FT) / \
                             (RATIO_FINAL_DRIVE_DIV * gear_ratio_d100 * 88))
#define GET_ANGLE_FROM_VALUE(value)             (START_VALUE_ANGLE - value)
#define GET_ANGLE_FROM_SPEED(speed)             (START_SPEED_ANGLE - speed)
  
#define SPEED_VALUE_DEC_OFF 2
#define SPEED_VALUE_INC_RUN 1
#define SPEED_VALUE_INC_STARTUP 2 
#define SPEED_VALUE_DEC_GEAR_CHANGE 5
  
#define SPEED_VALUE_INC_ANGLE_STARTUP 10
#define SPEED_VALUE_DEC_ANGLE_STARTUP 8
    
#define MAX_VIEW_IMAGES 4
    
#define BLINKER_PERIOD_MS 300
                                
#define BACKLIGHT_PWM_DELTA 0x1
#define BACKLIGHT_DELTA_DELAY_MS 2
                                
#define BACKLIGHT_PWM_VALUE_ENGINE_OFF 33
#define BACKLIGHT_PWM_VALUE_ENGINE_ON 100
    
#define WINDSHIELD_BLOCKER_HEIGHT 170
#define WINDSHIELD_HEIGHT_INC 5
    
#define SPEED_INC_GEAR_FIRST 1
#define SPEED_INC_GEAR_SECOND 1
#define SPEED_INC_GEAR_THIRD 1
#define SPEED_INC_GEAR_FOURTH 2
#define SPEED_INC_GEAR_FIFTH 2
#define SPEED_INC_GEAR_SIXTH 1
#define SPEED_DEC_GEAR_SIXTH 2

#define BLINKER_INDICATOR_PERIOD_MS 500
#define NUM_MAP_POINTS 29

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
    APP_STATE_INDICATORS_LIGHTS_INIT,
    APP_STATE_INDICATOR_TEXTS_INIT,
    APP_STATE_WINDSHIELD_OPEN,
    APP_STATE_WINDSHIELD_CLOSE,
    APP_STATE_STARTUP,
    APP_STATE_IDLE,
    APP_STATE_RUN,
    APP_STATE_COAST,
    APP_STATE_ENGINE_OFF,
    APP_STATE_ENGINE_TURNING_ON,
    APP_STATE_ENGINE_TURNING_OFF_ENGINE,
    APP_STATE_ENGINE_TURNING_OFF_FUEL,
    APP_STATE_ENGINE_TURNING_OFF_INDICATORS,
    APP_STATE_ENGINE_TURNING_OFF_DIM,
    /* TODO: Define states used by the application state machine. */

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
    WQVGA,
    WVGA
} APP_RESOLUTION;

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
    APP_RESOLUTION res;
} APP_DATA;

static uint32_t maxValueGear[] =
{
   IDLE_VALUE,
   MAX_VALUE_FIRST_GEAR,
   MAX_VALUE_SECOND_GEAR,
   MAX_VALUE_THIRD_GEAR,
   MAX_VALUE_FOURTH_GEAR,
   MAX_VALUE_FIFTH_GEAR,
   MAX_VALUE_SIXTH_GEAR,
};

static uint32_t RPMDropGear[] =
{
   GET_RPM_FROM_VALUE(IDLE_VALUE),
   MAX_RPMx100_FIRST_GEAR,
   MAX_RPMx100_FIRST_GEAR * RATIO_SECOND_GEAR_DIV100 / RATIO_FIRST_GEAR_DIV100 - 2,
   MAX_RPMx100_SECOND_GEAR * RATIO_THIRD_GEAR_DIV100 / RATIO_SECOND_GEAR_DIV100 - 2,
   MAX_RPMx100_THIRD_GEAR * RATIO_FOURTH_GEAR_DIV100 / RATIO_THIRD_GEAR_DIV100 - 1,
   MAX_RPMx100_FOURTH_GEAR * RATIO_FIFTH_GEAR_DIV100 / RATIO_FOURTH_GEAR_DIV100 - 1,
   MAX_RPMx100_FIFTH_GEAR * RATIO_SIXTH_GEAR_DIV100 / RATIO_FIFTH_GEAR_DIV100 - 1,
};

static uint32_t RPMFactorByGear[] =
{
   0,
   RATIO_FIRST_GEAR_DIV100,
   RATIO_SECOND_GEAR_DIV100,
   RATIO_THIRD_GEAR_DIV100,
   RATIO_FOURTH_GEAR_DIV100,
   RATIO_FIFTH_GEAR_DIV100,
   RATIO_SIXTH_GEAR_DIV100,
};

static const GFX_Point mapPointsWVGA[NUM_MAP_POINTS] =
{{497, 375}, {497, 365}, {497, 355}, {487, 350}, {483, 362}, {473, 362}, {463, 362},
{463, 356}, {473, 356}, {473, 346}, {467, 344}, {459, 334}, {459, 324}, {459, 314},
{459, 314}, {459, 304}, {464, 294}, {474, 286}, {484, 279}, {484, 279}, {494, 272},
{500, 262}, {500, 252}, {485, 252}, {485, 252}, {483, 262}, {473, 264}, {462, 261},
{460, 251}};
//start @299, 25
static const GFX_Point mapPointsWQVGA[NUM_MAP_POINTS] =
{{299, 225}, {299, 220}, {299, 215}, {293, 211}, {291, 216}, {287, 218}, {282, 218},
{277, 216}, {282, 214}, {287, 209}, {282, 207}, {276, 207}, {276, 202}, {276, 197},
{276, 192}, {276, 187}, {276, 182}, {277, 177}, {282, 173}, {288, 169}, {288, 169},
{294, 164}, {300, 160}, {300, 155}, {300, 155}, {292, 150}, {283, 158}, {276, 150},
{460, 251}};

static unsigned int ptIdx = 0;

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

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/

static void APP_Update_Map(unsigned int ptIdx)
{
    if (appData.res == WQVGA)
        laWidget_SetPosition((laWidget *) MapPointImage, mapPointsWQVGA[ptIdx].x, mapPointsWQVGA[ptIdx].y);
    else
        laWidget_SetPosition((laWidget *) MapPointImage, mapPointsWVGA[ptIdx].x, mapPointsWVGA[ptIdx].y);
}

static void APP_Update_Speed(uint32_t speed)
{
    appData.speed = speed;
}

void APP_SetdisplayBrightnessPctValue (uint32_t percent)
{
    uint32_t tmrPeriod = TMR2_PeriodGet();
    
    uint32_t ocPeriod = (tmrPeriod * percent) / 100;
    
    OCMP5_CompareSecondaryValueSet(ocPeriod);
}

static inline void APP_DelayMS(int ms)
{
    SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

    if (SYS_TIME_DelayMS(ms, &timer) != SYS_TIME_SUCCESS)
        return;
    while (SYS_TIME_DelayIsComplete(timer) == false);
}

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
    
    ptIdx++;
    
    if (ptIdx >= NUM_MAP_POINTS)
        ptIdx = 0;

    APP_Update_Map(ptIdx);
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
}

static void APP_EnableIndicators(laBool enable)
{
    if (enable)
        laWidget_SetVisible((laWidget*)IndicatorBlockPanel, LA_FALSE);
    else
        laWidget_SetVisible((laWidget*)IndicatorBlockPanel, LA_TRUE);
    
    laWidget_SetVisible((laWidget*) MapPointImage, enable);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/******************************************************************************
  Function:
    void APP_Task ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Task ( void )
{
    static uint32_t viewImageIndex = 0;
    static unsigned int displayBrightnessPct = 0;
    static uint32_t windshieldBlockerHeight = WINDSHIELD_BLOCKER_HEIGHT;
    
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
                appData.value = MIN_VALUE;
                appData.event = APP_EVENT_NONE;
                appData.state = APP_STATE_SPLASH_BRIGHTEN;
                displayBrightnessPct = 0;
                APP_SetdisplayBrightnessPctValue(displayBrightnessPct);
                
                if (GFX_ActiveContext()->display_info->rect.width > 480)
                    appData.res = WVGA;
                else
                    appData.res = WQVGA;
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
            APP_Update_Speed(0);
            laWidget_Invalidate((laWidget*) RPMDrawSurfaceWidget);
            laWidget_Invalidate((laWidget*) SpeedDrawSurfaceWidget);
  
            laWidget_OverrideTouchDownEvent((laWidget*)CenterButtonWidget, &buttonTouchDown);
            laWidget_OverrideTouchMovedEvent((laWidget*)CenterButtonWidget, &buttonTouchMoved);
            laWidget_OverrideTouchUpEvent((laWidget*)CenterButtonWidget, &buttonTouchUp);
            
            laWidget_SetEnabled((laWidget *) CenterButtonWidget, LA_FALSE);
            laWidget_SetVisible((laWidget*) TurnLeftImageWidget, LA_FALSE);
            laWidget_SetVisible((laWidget*) TurnRightImageWidget, LA_FALSE); 
            laWidget_SetVisible((laWidget*) MapPointImage, LA_FALSE);
            APP_EnableIndicators(LA_FALSE);
            
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
                ptIdx = 0;
                APP_SetdisplayBrightnessPctValue(BACKLIGHT_PWM_VALUE_ENGINE_ON);

                laWidget_SetVisible((laWidget*) TurnLeftImageWidget, LA_TRUE);
                laWidget_SetVisible((laWidget*) TurnRightImageWidget, LA_TRUE);
                
                APP_Update_Map(ptIdx);
                APP_EnableIndicators(LA_TRUE);                
                appData.state = APP_STATE_TACHO_REV_UP;
            }
            
            break;          
        }
        case APP_STATE_TACHO_REV_UP:
        {
            if (appData.value < MAX_VALUE)
                appData.value += SPEED_VALUE_INC_ANGLE_STARTUP;
            else
                appData.value = MAX_VALUE;
            
            if (appData.speed < MAX_SPEED)
                appData.speed += SPEED_VALUE_INC_ANGLE_STARTUP;
            else
                appData.speed = MAX_SPEED;
            
            if (appData.value == MAX_VALUE && appData.speed == MAX_SPEED)
            {
                appData.state = APP_STATE_TACHO_REV_DOWN;
            }
            
            laWidget_Invalidate((laWidget*) RPMDrawSurfaceWidget);
            laWidget_Invalidate((laWidget*) SpeedDrawSurfaceWidget);
              
            break;
        }
        case APP_STATE_TACHO_REV_DOWN:
        {
            if (appData.value > MIN_VALUE)
                appData.value -= SPEED_VALUE_DEC_ANGLE_STARTUP;
            else
                appData.value = MIN_VALUE;
            
            if (appData.speed > MIN_SPEED)
                appData.speed -= SPEED_VALUE_DEC_ANGLE_STARTUP;
            else
                appData.speed = MIN_SPEED;
            
            if (appData.value == MIN_VALUE && appData.speed == MIN_SPEED)
            {
                appData.state = APP_STATE_WINDSHIELD_OPEN;
                laWidget_SetVisible((laWidget*) TurnLeftImageWidget, LA_FALSE);
                laWidget_SetVisible((laWidget*) TurnRightImageWidget, LA_FALSE); 
            }
            
            laWidget_Invalidate((laWidget*) RPMDrawSurfaceWidget);
            laWidget_Invalidate((laWidget*) SpeedDrawSurfaceWidget);
            
            break;
        }
        case APP_STATE_WINDSHIELD_OPEN:
        {
            if (windshieldBlockerHeight > 0)
                windshieldBlockerHeight -= WINDSHIELD_HEIGHT_INC;
            else
                appData.state = APP_STATE_STARTUP;
            
            laWidget_SetSize((laWidget*)WindshieldBlockPanel,
                            GFX_ActiveContext()->display_info->rect.width,
                            windshieldBlockerHeight);
            break;
        }
        case APP_STATE_STARTUP:
        {
            if (appData.value < IDLE_VALUE)
            {
                appData.value += SPEED_VALUE_INC_STARTUP;
                laWidget_Invalidate((laWidget*) RPMDrawSurfaceWidget);
                laWidget_Invalidate((laWidget*) SpeedDrawSurfaceWidget);
            }
            else
            {
                appData.value = IDLE_VALUE;
                
                appData.state = APP_STATE_IDLE;
                appData.gear = APP_GEAR_IDLE;
                
                appData.event = APP_EVENT_NONE;
                
                laWidget_Invalidate((laWidget*) RPMDrawSurfaceWidget);
                laWidget_Invalidate((laWidget*) SpeedDrawSurfaceWidget);
                
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
                    laWidget_SetEnabled((laWidget*) EngineOnButton, LA_FALSE);
                    
                    if (handleTimerBlinker == SYS_TIME_HANDLE_INVALID)
                        handleTimerBlinker = SYS_TIME_CallbackRegisterMS(
                                                    Timer_Callback,
                                                    1,
                                                    BLINKER_INDICATOR_PERIOD_MS,
                                                    SYS_TIME_PERIODIC);

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
                    
                    laWidget_Invalidate((laWidget*) RPMDrawSurfaceWidget);
                    
                    break;
                }
            }

            break;
        }
        case APP_STATE_ENGINE_TURNING_OFF_ENGINE:
        {
            if (appData.value > MIN_VALUE)
                appData.value -= SPEED_VALUE_INC_STARTUP;
            else
            {
                appData.value = MIN_VALUE;
                appData.state = APP_STATE_ENGINE_TURNING_OFF_INDICATORS;
            }
            
            laWidget_Invalidate((laWidget*) RPMDrawSurfaceWidget);
            
            break;
        }
        case APP_STATE_ENGINE_TURNING_OFF_INDICATORS:
        {
            APP_EnableIndicators(LA_FALSE);
                
            appData.state = APP_STATE_WINDSHIELD_CLOSE;
            
            break;
        }
        case APP_STATE_WINDSHIELD_CLOSE:
        {
            if (windshieldBlockerHeight < GFX_ActiveContext()->display_info->rect.height/3 + 5)
                windshieldBlockerHeight += WINDSHIELD_HEIGHT_INC;
            else
                appData.state = APP_STATE_ENGINE_TURNING_OFF_DIM;
            
            laWidget_SetSize((laWidget*)WindshieldBlockPanel,
                            GFX_ActiveContext()->display_info->rect.width,
                            windshieldBlockerHeight);
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
                if (appData.gear == APP_GEAR_IDLE)
                {
                    appData.state = APP_STATE_IDLE;
                    APP_Update_Speed(0);
                    viewImageIndex = 0;
                    laImageSequenceWidget_ShowImage(ImageSequenceWidget5, viewImageIndex);
                    laWidget_SetEnabled((laWidget*) EngineOnButton, LA_TRUE);
                    
                    if (handleTimerBlinker != SYS_TIME_HANDLE_INVALID)
                    {
                        SYS_TIME_TimerDestroy(handleTimerBlinker);        
                        handleTimerBlinker = SYS_TIME_HANDLE_INVALID;
                    }                    
                }
                else
                {
                    if (appData.speed < GET_SPEED_FROM_RPMx100(GET_RPMx100_FROM_VALUE(MAX_VALUE), 
                             RPMFactorByGear[APP_GEAR_SIXTH]))
                    {
                        APP_Update_Speed(GET_SPEED_FROM_RPMx100(GET_RPMx100_FROM_VALUE(appData.value), 
                                 RPMFactorByGear[appData.gear]));  
                        
                        appData.value -= SPEED_VALUE_DEC_OFF;
                        
                        if (appData.value <= maxValueGear[appData.gear - 1])
                            appData.gear--;                        
                    }
                    else
                    {
                        appData.speed -= SPEED_DEC_GEAR_SIXTH;
                    }
                        
                    if (viewImageIndex > 1)
                    {
                        viewImageIndex--;
                        laImageSequenceWidget_ShowImage(ImageSequenceWidget5, viewImageIndex);
                    }
                }
            }
            else
            {
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
                    }
                }
                
                if (appData.speed < GET_SPEED_FROM_RPMx100(GET_RPMx100_FROM_VALUE(MAX_VALUE), 
                             RPMFactorByGear[APP_GEAR_SIXTH]))
                {
                    APP_Update_Speed(GET_SPEED_FROM_RPMx100(GET_RPMx100_FROM_VALUE(appData.value), 
                             RPMFactorByGear[appData.gear]));
                }
                else if (appData.speed < MAX_SPEED)
                {
                    appData.speed += SPEED_INC_GEAR_SIXTH;
                }
                
                if (viewImageIndex < MAX_VIEW_IMAGES)
                {
                    viewImageIndex++;
                    laImageSequenceWidget_ShowImage(ImageSequenceWidget5, viewImageIndex);
                }
            }
            
            laWidget_Invalidate((laWidget*) RPMDrawSurfaceWidget);
            laWidget_Invalidate((laWidget*) SpeedDrawSurfaceWidget);
            
            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

void APP_Send_Event(APP_EVENTS event)
{
    appData.event = event;
}

uint32_t APP_GetValueAngle(void)
{
    return GET_ANGLE_FROM_VALUE(appData.value);
}

uint32_t APP_GetSpeedAngle(void)
{
    return GET_ANGLE_FROM_SPEED(appData.speed);
}

void APP_StateInit(void)
{
    appData.state = APP_STATE_INIT;
}


/*******************************************************************************
 End of File
 */
