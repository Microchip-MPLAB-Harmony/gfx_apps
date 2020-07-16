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

#include "app.h"
#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define MAX_TEMP_IDX 20
#define MAX_FAN_IDX 6
#define CLOCK_SEC_PERIOD_MS 1000
#define CLOCK_ANIM_TIMER_PERIOD_MS 30

#define IDLE_MODE_TIMEOUT_PERIOD_S 20
#define DIM_MODE_TIMEOUT_PERIOD_S 5

#define OCMP_VALUE_FULL 3906
#define SWIPE_DELTA_PIXELS 10

#define BACKGROUND_CANVAS_ID 0
#define INFO_PAGE_CANVAS_ID 1
#define CLOCK_PANEL_CANVAS_ID 2

#define INFO_PAGE_HIDE_XPOS 500
#define INFO_PAGE_HIDE_YPOS 480
#define INFO_PAGE_SHOW_XPOS 500
#define INFO_PAGE_SHOW_YPOS 70

#define CLOCK_PANEL_HIDE_XPOS -250
#define CLOCK_PANEL_HIDE_YPOS 0
#define CLOCK_PANEL_SHOW_XPOS 0
#define CLOCK_PANEL_SHOW_YPOS 0

#define LAYER_FX_DELTA 5
//#define USE_GLOBAL_PALETTE 
//#define ENABLE_INFOPAGE_MOVE

#ifdef USE_GLOBAL_PALETTE
#define BYTES_PER_PIXEL 1
#else
#define BYTES_PER_PIXEL 4
#endif

typedef struct
{
    bool sync;
    bool autocc;
    bool seatwarm;
    bool highvent;
    bool midvent;
    bool lowvent;
    unsigned int tempidx;
    unsigned int fanidx;
} ZONE_OBJ;

typedef enum
{
    ANIM_START,
    ANIM_STOP,
    ANIM_START_SHOW,
    ANIM_START_HIDE,
    ANIM_RUN,
    ANIM_DONE,
    ANIM_IDLE
} ANIM_STATE;

typedef enum
{
    LAYER_ID_BASE,
    LAYER_ID_INFOPAGE,
    LAYER_ID_CLOCK,
} LAYER_ID;

typedef enum
{
    GEST_NONE,
    SWIPE_RIGHT,
    SWIPE_LEFT,
    MOVE_RIGHT,
    MOVE_LEFT,
            
    SWIPE_UP,
    SWIPE_DOWN,
    MOVE_UP,
    MOVE_DOWN,         
} INPUT_GESTURE;

typedef struct
{
    unsigned int timeout;
    APP_EVENTS event;
} DEMO_MODE_OBJ;

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
ZONE_OBJ zones[ZONE_MAX];
static SYS_TIME_HANDLE  clockTimer;
static SYS_TIME_HANDLE  animTimer;

static unsigned int secCounter = 0;
static unsigned int secCounterLast = 0;
static unsigned int fadeCounter = 0;
static unsigned int fadeCounterLast = 0;
static unsigned int idleSecCounter = 0;

static unsigned int demoModeCounter = 0;
static unsigned int demoModeCounterLast = 0;
static unsigned int demoModeEventIndex = 0;
static unsigned int demoModeIntervalCounter = 0;

static bool backgroundAnimDone = false;
static bool clockPanelAnimDone = false;
static bool infoPageAnimDone = false;

static bool infoPageHandleLock = false;
static bool infoPageVisible = false;
static bool clockPanelVisible = false;

static unsigned int brightness = 0;
static unsigned int newBrightness = 0;

static int32_t lastX = 0, lastY = 0, deltaX = 0, deltaY = 0;

ANIM_STATE clockAnim = ANIM_DONE;
ANIM_STATE infoPageAnim = ANIM_DONE;

static DEMO_MODE_OBJ demo_mode_obj[] =
{
    {3, EVENT_SHOW_CLOCK},
    {3, EVENT_SHOW_INFOPAGE},
    {10, EVENT_HIDE_INFOPAGE},
    {3, EVENT_HIDE_CLOCK},
    
    {3, EVENT_ZONE_FRONT_PASS},
    {3, EVENT_SYNC_ON},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP},
    {1, EVENT_TEMP_UP}, 
    {1, EVENT_SHOW_CLOCK},
    {1, EVENT_SHOW_INFOPAGE},    
    {3, EVENT_HIGHVENT_ON},
    {3, EVENT_LOWVENT_ON},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_TEMP_DOWN},
    {1, EVENT_HIDE_INFOPAGE},
    {3, EVENT_ZONE_DRIVER},
    {3, EVENT_SYNC_OFF},
    {3, EVENT_HIGHVENT_OFF},
    {3, EVENT_LOWVENT_OFF},
    {1, EVENT_HIDE_CLOCK},    
};

void APP_Resize_Layer(LAYER_ID id, uint32_t resx, uint32_t resy, uint32_t resxfb, uint32_t resyfb);
void APP_Layer_SetOffset(LAYER_ID id, uint32_t offx, uint32_t offy, uint32_t resxfb, uint32_t resyfb);
void APP_Layer_SetPosition(LAYER_ID id, uint32_t xpos, uint32_t ypos);
void APP_Layer_SetAlpha(LAYER_ID id, uint8_t alpha);

extern uint8_t GLCD_GetLayerBaseAddress(uint32_t layerid, uint32_t buffid);

SYS_INP_InputListener appInputListener;

static void APP_Canvas_EffectsCallback(unsigned int canvasID,
                                       GFXC_FX_TYPE effect,
                                       GFXC_FX_STATUS status,
                                       void * parm)
{
    if (status == GFXC_FX_START)
    {
        switch (canvasID)
        {
            case BACKGROUND_CANVAS_ID:
                backgroundAnimDone = false;
                break;
            case INFO_PAGE_CANVAS_ID:
                infoPageAnimDone = false;
                break;
            case CLOCK_PANEL_CANVAS_ID:
                clockPanelAnimDone = false;
                break;
            default:
                break;
        }
    }
    else if (status == GFXC_FX_DONE)
    {
        switch (canvasID)
        {
            case BACKGROUND_CANVAS_ID:
                backgroundAnimDone = true;
                break;
            case INFO_PAGE_CANVAS_ID:
                infoPageVisible = !infoPageVisible;
                infoPageAnimDone = true;
                break;
            case CLOCK_PANEL_CANVAS_ID:
                clockPanelVisible = !clockPanelVisible;
                clockPanelAnimDone = true;
                break;
            default:
                break;
        }
    }
}

static void resetDemoModeCounters(void)
{
    demoModeIntervalCounter = 0;
    idleSecCounter = 0;
    demoModeEventIndex = 0;
    newBrightness = 100;
}

//Gesture handlers
static void touchDownHandler(const SYS_INP_TouchStateEvent* const evt)
{
    lastX = evt->x;
    lastY = evt->y;  
    
    resetDemoModeCounters();
}

static void touchUpHandler(const SYS_INP_TouchStateEvent* const evt)
{
    resetDemoModeCounters();
}

static void touchMoveHandler(const SYS_INP_TouchMoveEvent* const evt)
{
    INPUT_GESTURE gest = GEST_NONE;
    
    resetDemoModeCounters();
    
    //Move left
    if (evt->x < lastX)
    {
        if (lastX - evt->x > SWIPE_DELTA_PIXELS)
            gest = SWIPE_LEFT;
        else
            gest = MOVE_LEFT;
        
        deltaX = lastX - evt->x;
    }
    //Move right
    else if (evt->x > lastX)
    {
        if (evt->x - lastX > SWIPE_DELTA_PIXELS)
            gest = SWIPE_RIGHT;
        else
            gest = MOVE_RIGHT;
        
        deltaX = evt->x - lastX;
    }
    //Move up
    else if (evt->y < lastY)
    {
        if (lastY - evt->y > SWIPE_DELTA_PIXELS)
            gest = SWIPE_UP;
        else
            gest = MOVE_UP;
        
        deltaY = lastY - evt->y;
    }
    //Move down
    else if (evt->y > lastY)
    {
        if (evt->y - lastY > SWIPE_DELTA_PIXELS)
            gest = SWIPE_DOWN;
        else
            gest = MOVE_DOWN;
        
        deltaY = evt->y - lastY;
    }
    
    //Process swipe for weather/clock banner
    if (evt->y < 65 && evt-> x < 400)
    {
        if (gest == SWIPE_RIGHT)
            APP_SetEvent(EVENT_SHOW_CLOCK);
        else if (gest == SWIPE_LEFT)
            APP_SetEvent(EVENT_HIDE_CLOCK);
    }
    
    //Process swipe for infopage
    if (evt->x > 500 && evt->x < 740)
    {
        if (gest == SWIPE_UP || gest == MOVE_UP)
        {   
            infoPageHandleLock = false;
            APP_SetEvent(EVENT_SHOW_INFOPAGE);
        }
        else if (gest == SWIPE_DOWN || gest == MOVE_DOWN)
        {
            infoPageHandleLock = false;
            APP_SetEvent(EVENT_HIDE_INFOPAGE);
        }
    }
    
    lastX = evt->x;
    lastY = evt->y;   
    
}

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */
void APP_SetBrightness(unsigned int pct)
{
    #define TMR_PERIOD 3906
    OCMP1_CompareSecondaryValueSet( (TMR_PERIOD * pct)/100);
}

ANIM_STATE APP_ProcessBrightness(void)
{
    ANIM_STATE retval = ANIM_IDLE;
    
    #define BRIGHTNESS_DELTA_PCT_DOWN 2
    #define BRIGHTNESS_DELTA_PCT_UP 5

    if (brightness != newBrightness &&
        fadeCounter != fadeCounterLast)
    {
        retval = ANIM_RUN;
        
        if (newBrightness > brightness)
        {
            if (brightness < newBrightness - BRIGHTNESS_DELTA_PCT_UP)
            {
                brightness += BRIGHTNESS_DELTA_PCT_UP;
            }
            else
            {
                brightness = newBrightness;
                retval = ANIM_DONE;
            }
        }
        else
        {
            if (brightness > newBrightness + BRIGHTNESS_DELTA_PCT_DOWN)
            {
                brightness -= BRIGHTNESS_DELTA_PCT_DOWN;
            }
            else
            {
                brightness = newBrightness;
                retval = ANIM_DONE;
            }        
        }

        APP_SetBrightness(brightness);
        
        fadeCounterLast = fadeCounter;
    }
    else if (brightness == newBrightness)
    {
        retval = ANIM_DONE;
    }
    
    return retval;
}

void APP_ProcessDemoMode(void)
{
    if (demoModeCounter != demoModeCounterLast)
    {
        demoModeIntervalCounter++;
        
        if (demoModeIntervalCounter == demo_mode_obj[demoModeEventIndex].timeout)
        {
            APP_SetEvent(demo_mode_obj[demoModeEventIndex].event);

            demoModeEventIndex = 
                            (demoModeEventIndex < sizeof(demo_mode_obj)/sizeof(DEMO_MODE_OBJ) - 1) ? 
                            demoModeEventIndex + 1 : 0;
            
            demoModeIntervalCounter = 0;
        }
        
        demoModeCounterLast = demoModeCounter;
    }
}

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    appData.event = EVENT_NONE;
    appData.zone = ZONE_DRIVER;
    memset(zones, 0, ZONE_MAX * sizeof(ZONE_OBJ));
    
        /* Initialize canvas objects */
    gfxcSetLayer(BACKGROUND_CANVAS_ID, 0);
    gfxcSetLayer(INFO_PAGE_CANVAS_ID, 1);
    gfxcSetLayer(CLOCK_PANEL_CANVAS_ID, 2);
    
    gfxcSetWindowSize(BACKGROUND_CANVAS_ID, 800, 480);
    gfxcSetWindowSize(INFO_PAGE_CANVAS_ID, 300, 350);
    gfxcSetWindowSize(CLOCK_PANEL_CANVAS_ID, 400, 50);
    
    gfxcHideCanvas(BACKGROUND_CANVAS_ID);
    gfxcHideCanvas(INFO_PAGE_CANVAS_ID);
    gfxcHideCanvas(CLOCK_PANEL_CANVAS_ID);

    gfxcCanvasUpdate(BACKGROUND_CANVAS_ID);
    gfxcCanvasUpdate(INFO_PAGE_CANVAS_ID);
    gfxcCanvasUpdate(CLOCK_PANEL_CANVAS_ID);
}

void APP_SetEvent(APP_EVENTS event)
{
    appData.event = event;
}

void APP_UpdateFanControl(unsigned int idx)
{
    unsigned int i = 0;
    
    leImageSequenceWidget * widgets[MAX_FAN_IDX] = 
    {
        screen1_FanLevel1,
        screen1_FanLevel2,
        screen1_FanLevel3,
        screen1_FanLevel4,
        screen1_FanLevel5,
        screen1_FanLevel6 
    };
    
    zones[appData.zone].fanidx = idx;
    
    for (i = 0; i < MAX_FAN_IDX; i++)
    {
        if (i < idx)
        {
            widgets[i]->fn->showImage(widgets[i], 1);
        }
        else
        {
            widgets[i]->fn->showImage(widgets[i], 0);
        }
    }
}

static void Clock_Timer_Callback ( uintptr_t context )
{
    secCounter++;
    idleSecCounter++;
    
    if (idleSecCounter > IDLE_MODE_TIMEOUT_PERIOD_S)
    {
        demoModeCounter++;
        newBrightness = 100;
    }
    else if (idleSecCounter > DIM_MODE_TIMEOUT_PERIOD_S)
    {
        newBrightness = 10;
    }
}

static void Anim_TimerCallback ( uintptr_t context )
{
    fadeCounter++;
}

static void APP_AnimShowInfoPage(bool show)
{
    if (show == true && 
        infoPageVisible == false)
    {
        gfxcStartEffectMove(INFO_PAGE_CANVAS_ID,
                            GFXC_FX_MOVE_DEC,
                            INFO_PAGE_HIDE_XPOS,
                            INFO_PAGE_HIDE_YPOS,
                            INFO_PAGE_SHOW_XPOS,
                            INFO_PAGE_SHOW_YPOS,
                            LAYER_FX_DELTA);        
        
    }
    else if (show == false &&
             infoPageVisible == true)
    {
        gfxcStartEffectMove(INFO_PAGE_CANVAS_ID,
                            GFXC_FX_MOVE_DEC,
                            INFO_PAGE_SHOW_XPOS,
                            INFO_PAGE_SHOW_YPOS,
                            INFO_PAGE_HIDE_XPOS,
                            INFO_PAGE_HIDE_YPOS,
                            LAYER_FX_DELTA);              
    }
}

static void APP_AnimShowClockPanel(bool show)
{
    if (show == true && clockPanelVisible == false)
    {
        gfxcStartEffectMove(CLOCK_PANEL_CANVAS_ID,
                            GFXC_FX_MOVE_DEC,
                            CLOCK_PANEL_HIDE_XPOS,
                            CLOCK_PANEL_HIDE_YPOS,
                            CLOCK_PANEL_SHOW_XPOS,
                            CLOCK_PANEL_SHOW_YPOS,
                            LAYER_FX_DELTA);        
    }
    else if (show == false && clockPanelVisible == true)
    {
        gfxcStartEffectMove(CLOCK_PANEL_CANVAS_ID,
                            GFXC_FX_MOVE_DEC,
                            CLOCK_PANEL_SHOW_XPOS,
                            CLOCK_PANEL_SHOW_YPOS,
                            CLOCK_PANEL_HIDE_XPOS,
                            CLOCK_PANEL_HIDE_YPOS,
                            LAYER_FX_DELTA);          
    }
}

static leBool screen1_filterEvent(leWidget* target, leWidgetEvent* evt, void* data)
{
    switch(evt->id)
    {
        case LE_EVENT_TOUCH_DOWN:
        case LE_EVENT_TOUCH_MOVE:            
        { 
            if (evt->id == LE_EVENT_TOUCH_DOWN)
            {
                leWidgetEvent_TouchDown * down = (leWidgetEvent_TouchDown *) evt;
                if (target == (leWidget*) screen1_TempControlButton)
                {                
                    if (down->y > 245)
                        APP_SetEvent(EVENT_TEMP_DOWN);
                    else if (down->y <= 245)
                        APP_SetEvent(EVENT_TEMP_UP);
                }
                else if (target == (leWidget*) screen1_FanButtonWidget)
                {
                    if (down->y < 140)
                        APP_SetEvent(EVENT_FAN_UP);
                    else if (down->y < 185)
                        APP_UpdateFanControl(6);
                    else if (down->y < 223)
                        APP_UpdateFanControl(5);
                    else if (down->y < 262)
                        APP_UpdateFanControl(4);
                    else if (down->y < 300)
                        APP_UpdateFanControl(3);
                    else if (down->y < 340)
                        APP_UpdateFanControl(2);
                    else if (down->y < 370)
                        APP_UpdateFanControl(1);
                    else 
                        APP_SetEvent(EVENT_FAN_DOWN);                    
                }
             
            }
            else
            {
                leWidgetEvent_TouchMove * move = (leWidgetEvent_TouchMove *) evt;
                if (target == (leWidget*) screen1_TempControlButton)
                {
                    if (move->prevY < move->y)
                        APP_SetEvent(EVENT_TEMP_DOWN);
                    else if (move->prevY > move->y)
                        APP_SetEvent(EVENT_TEMP_UP);
                }
                else if (target == (leWidget*) screen1_FanButtonWidget)
                {
                    if (move->y < 185)
                        APP_UpdateFanControl(6);
                    else if (move->y < 223)
                        APP_UpdateFanControl(5);
                    else if (move->y < 262)
                        APP_UpdateFanControl(4);
                    else if (move->y < 300)
                        APP_UpdateFanControl(3);
                    else if (move->y < 340)
                        APP_UpdateFanControl(2);
                    else if (move->y < 370)
                        APP_UpdateFanControl(1);
                    else 
                        APP_UpdateFanControl(0);                    
                }
            }

            evt->accepted = LE_TRUE;
            
            break;
        }
        default:
            break;
    }
    
    return LE_FALSE;
}

static leWidgetEventFilter screen1_eventFilter =
{
    screen1_filterEvent,
    NULL
};

static void APP_ProcessClock(void)
{
    static unsigned int sec = 0;
    static unsigned int min = 0;
    
    if (secCounter != secCounterLast)
    {
        sec++;

        screen1_ColonImage->fn->setVisible(screen1_ColonImage, (leBool)(sec & 0x1));

        if (sec == 60)
        {
            min++;
            sec = 0;

            if (min == 60)
            {
                min = 0;
                screen1_HourTimeWidget->fn->showNextImage(screen1_HourTimeWidget);
            }

            screen1_MinuteTimeWidget->fn->showNextImage(screen1_MinuteTimeWidget);
        }        
        
        secCounterLast = secCounter;
    }
}

static void APP_Process_Events(void)
{
    switch(appData.event)
    {
        case EVENT_ZONE_DRIVER:
        {
            screen1_ZoneImageSequence->fn->showImage(screen1_ZoneImageSequence,
                                                     ZONE_DRIVER);
            appData.zone = ZONE_DRIVER;
            break;
        }
        case EVENT_ZONE_FRONT_PASS:
        {
            screen1_ZoneImageSequence->fn->showImage(screen1_ZoneImageSequence,
                                                     ZONE_FRONT_PASSENGER);
            appData.zone = ZONE_FRONT_PASSENGER;
            break;
        }
        case EVENT_ZONE_LEFT_PASS:
        {
            screen1_ZoneImageSequence->fn->showImage(screen1_ZoneImageSequence,
                                                     ZONE_LEFT_PASSENGER);
            appData.zone = ZONE_LEFT_PASSENGER;
            break;
        }
        case EVENT_ZONE_RIGHT_PASS:
        {
            screen1_ZoneImageSequence->fn->showImage(screen1_ZoneImageSequence,
                                                     ZONE_RIGHT_PASSENGER);                        
            appData.zone = ZONE_RIGHT_PASSENGER;
            break;
        }
        case EVENT_SYNC_ON:
        {
            zones[appData.zone].sync = true;
            break;
        }
        case EVENT_SYNC_OFF:
        {
            zones[appData.zone].sync = false;
            break;
        }
        case EVENT_TEMP_UP:
        {
            if (zones[appData.zone].tempidx < MAX_TEMP_IDX)
            {
                zones[appData.zone].tempidx++;
                screen1_TempImageSequenceWidget->fn->showImage(
                                        screen1_TempImageSequenceWidget,
                                        zones[appData.zone].tempidx);
            }
            break;
        }
        case EVENT_TEMP_DOWN:
        {
            if (zones[appData.zone].tempidx > 0)
            {
                zones[appData.zone].tempidx--;
                screen1_TempImageSequenceWidget->fn->showImage(
                                        screen1_TempImageSequenceWidget,
                                        zones[appData.zone].tempidx);
            }
            break;
        }
        case EVENT_FAN_UP:
        {
            if (zones[appData.zone].fanidx < MAX_FAN_IDX)
            {
                APP_UpdateFanControl(zones[appData.zone].fanidx + 1);
            }
            
            if (infoPageAnim != ANIM_RUN)
            {
                infoPageAnim = ANIM_START;
//                SYS_TIME_TimerStart(animTimer);
            }

            break;
        }
        case EVENT_FAN_DOWN:
        {
            if (zones[appData.zone].fanidx > 0)
            {
                APP_UpdateFanControl(zones[appData.zone].fanidx - 1);
            }
            else
            {
                APP_UpdateFanControl(0);
            }
            
            if (zones[appData.zone].fanidx == 0 && infoPageAnim == ANIM_RUN)
            {
                infoPageAnim = ANIM_STOP;
            }

            break;
        }
        case EVENT_HIGHVENT_ON:
        {
            zones[appData.zone].highvent = true;
            break;
        }
        case EVENT_HIGHVENT_OFF:
        {
            zones[appData.zone].highvent = false;
            break;
        }
        case EVENT_MIDVENT_ON:
        {
            zones[appData.zone].midvent = true;
            break;
        }
        case EVENT_MIDVENT_OFF:
        {
            zones[appData.zone].midvent = false;
            break;
        }
        case EVENT_LOWVENT_ON:
        {
            zones[appData.zone].lowvent = true;
            break;
        }
        case EVENT_LOWVENT_OFF:
        {
            zones[appData.zone].midvent = false;
            break;
        }
        case EVENT_CC_ON:
        {
            zones[appData.zone].autocc = true;
            break;
        }
        case EVENT_CC_OFF:
        {
            zones[appData.zone].autocc = false;
            break;
        }
        case EVENT_SEAT_WARM_ON:
        {
            zones[appData.zone].seatwarm = true;
            break;
        }
        case EVENT_SEAT_WARM_OFF:
        {    
            zones[appData.zone].seatwarm = false;
            break;
        }
        case EVENT_SHOW_CLOCK:
        {
            APP_AnimShowClockPanel(true);
            break;
        }
        case EVENT_HIDE_CLOCK:
        {
            APP_AnimShowClockPanel(false);
            break;
        }
        case EVENT_HIDE_INFOPAGE:
        {
            APP_AnimShowInfoPage(false);
            break;
        }
        case EVENT_SHOW_INFOPAGE:
        {
            APP_AnimShowInfoPage(true);
            break;
        }
        default:
            break;
    }
    
    appData.event = EVENT_NONE;    
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
            
            clockTimer = SYS_TIME_CallbackRegisterMS(Clock_Timer_Callback, 
                                    (uintptr_t) NULL,
                                    CLOCK_SEC_PERIOD_MS,
                                    SYS_TIME_PERIODIC);

            animTimer = SYS_TIME_CallbackRegisterMS(Anim_TimerCallback, 
                                    (uintptr_t) NULL,
                                    CLOCK_ANIM_TIMER_PERIOD_MS,
                                    SYS_TIME_PERIODIC);
            
            gfxcSetEffectsCallback(BACKGROUND_CANVAS_ID,
                                   APP_Canvas_EffectsCallback,
                                   NULL);
            gfxcSetEffectsCallback(INFO_PAGE_CANVAS_ID,
                                   APP_Canvas_EffectsCallback,
                                   NULL);
            gfxcSetEffectsCallback(CLOCK_PANEL_CANVAS_ID,
                                   APP_Canvas_EffectsCallback,
                                   NULL);
            
            appInputListener.handleTouchDown = &touchDownHandler;
            appInputListener.handleTouchUp = &touchUpHandler;
            appInputListener.handleTouchMove = &touchMoveHandler;
            
            SYS_INP_AddListener(&appInputListener);
            
            TMR2_Start();
            OCMP1_Enable();
            
            if (appInitialized)
            {
                gfxcShowCanvas(BACKGROUND_CANVAS_ID);
                gfxcCanvasUpdate(BACKGROUND_CANVAS_ID);
                newBrightness = 100;
                appData.state = APP_STATE_LOAD_SPLASH;
            }
            break;
        }
        case APP_STATE_LOAD_SPLASH:
        {
            if (APP_ProcessBrightness() == ANIM_DONE)
            {
                secCounterLast = secCounter;
                
                appData.state = APP_STATE_SPLASH;    
            }
            
            break;
        }
        case APP_STATE_SPLASH:
        {
            if (secCounter != secCounterLast)
            {
                newBrightness = 0;
                appData.state = APP_STATE_UNLOAD_SPLASH;
            }
            break;
        }
        case APP_STATE_UNLOAD_SPLASH:
        {
            if (APP_ProcessBrightness() == ANIM_DONE)
            {
                appData.state = APP_STATE_LOAD_MAIN_SCREEN;
            
                legato_showScreen(screenID_screen1);
            }
            
            break;
        }
        case APP_STATE_LOAD_MAIN_SCREEN:
        {
            //Slide in the other layers
            gfxcShowCanvas(INFO_PAGE_CANVAS_ID);
            APP_AnimShowInfoPage(true);
            
            gfxcCanvasUpdate(INFO_PAGE_CANVAS_ID);
            
            gfxcShowCanvas(CLOCK_PANEL_CANVAS_ID);            
            APP_AnimShowClockPanel(true);
            gfxcCanvasUpdate(CLOCK_PANEL_CANVAS_ID);
            
            clockAnim = ANIM_START_HIDE;     
            newBrightness = 100;
            
            appData.state = APP_STATE_ANIMATE_MAIN_SCREEN0;
            
            break;
        }
        case APP_STATE_ANIMATE_MAIN_SCREEN0:
        {
            if (APP_ProcessBrightness() == ANIM_DONE &&
                infoPageAnimDone == true &&
                clockPanelAnimDone == true)
            {
                appData.state = APP_STATE_PROCESS_MAIN_SCREEN;
            }
            
            resetDemoModeCounters();
            
            break;
        }
        case APP_STATE_PROCESS_MAIN_SCREEN:
        {
            
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

//Widget Event Handlers
void event_screen1_AirconButton_OnPressed(leButtonWidget* btn)
{

}
void event_screen1_AirconButton_OnReleased(leButtonWidget* btn)
{

}

void event_screen1_RecirculateButton_OnPressed(leButtonWidget* btn)
{

}

void event_screen1_RecirculateButton_OnReleased(leButtonWidget* btn)
{

}

void event_screen1_WindshieldVentButton_OnPressed(leButtonWidget* btn)
{

}

void event_screen1_WindshieldVentButton_OnReleased(leButtonWidget* btn)
{

}

void event_screen1_RearVentButton_OnPressed(leButtonWidget* btn)
{

}

void event_screen1_RearVentButton_OnReleased(leButtonWidget* btn)
{

}

void event_screen1_ClimateControlButton_OnPressed(leButtonWidget* btn)
{

}

void event_screen1_ClimateControlButton_OnReleased(leButtonWidget* btn)
{

}

void event_screen1_SeatHeaterButton_OnPressed(leButtonWidget* btn)
{

}

void event_screen1_SeatHeaterButton_OnReleased(leButtonWidget* btn)
{

}

void event_screen1_DriverZoneButton_OnPressed(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_ZONE_DRIVER);
}

void event_screen1_FrontPassZoneButton_OnPressed(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_ZONE_FRONT_PASS);
}

void event_screen1_RearRightPassZoneButton_OnPressed(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_ZONE_RIGHT_PASS);
}

void event_screen1_RearLeftPassZoneButton_OnPressed(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_ZONE_LEFT_PASS);
}

void event_screen1_SyncButton_OnPressed(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_SYNC_ON);
}

void event_screen1_SyncButton_OnReleased(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_SYNC_OFF);
}

void event_screen1_HighVentButton_OnPressed(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_HIGHVENT_ON);
}

void event_screen1_HighVentButton_OnReleased(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_HIGHVENT_OFF);
}

void event_screen1_MidVentButton_OnPressed(leButtonWidget* btn)
{
     APP_SetEvent(EVENT_MIDVENT_ON);
}

void event_screen1_MidVentButton_OnReleased(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_MIDVENT_OFF);
}

void event_screen1_LowVentButton_OnPressed(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_LOWVENT_ON);
}

void event_screen1_LowVentButton_OnReleased(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_LOWVENT_OFF);
}

void event_screen1_InfoPageButton_OnPressed(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_HIDE_INFOPAGE);
}

void event_screen1_InfoPageButton_OnReleased(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_SHOW_INFOPAGE);
}

void event_screen1_mchpButton_OnPressed(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_SHOW_INFOPAGE);
}

void event_screen1_mchpButton_OnReleased(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_HIDE_INFOPAGE);
}

void event_screen1_TopBannerButton_OnPressed(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_SHOW_CLOCK);
}

void event_screen1_TopBannerButton_OnReleased(leButtonWidget* btn)
{
    APP_SetEvent(EVENT_HIDE_CLOCK);
}

void Splash_OnShow()
{
    
}

void Splash_OnHide()
{
    
}

void Splash_OnUpdate()
{
    
}

void screen1_OnShow()
{
    screen1_TempControlButton->fn->installEventFilter(screen1_TempControlButton, screen1_eventFilter);
    screen1_FanButtonWidget->fn->installEventFilter(screen1_FanButtonWidget, screen1_eventFilter);
}

void screen1_OnHide()
{
    
}

void screen1_OnUpdate()
{
    //Process events
    APP_Process_Events();

    //Process clock
    APP_ProcessClock();

    //Process Demo Mode
    APP_ProcessDemoMode();

    //Process Backlight control
    APP_ProcessBrightness();    
    
}


/*******************************************************************************
 End of File
 */
