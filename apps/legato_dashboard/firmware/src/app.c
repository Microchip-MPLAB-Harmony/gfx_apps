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
#include "config/glcd_rgba8888_mxt_mzda_intddr_cu_wvga/gfx/canvas/gfx_canvas_api.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
#define BACKLIGHT_TIMER_PERIOD_MS 30
#define TMR_PERIOD 3906
#define BRIGHTNESS_DELTA_PCT_DOWN 2
#define BRIGHTNESS_DELTA_PCT_UP 5

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
SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;

needleObj leftNeedles[360];
needleObj rightNeedles[360];
SYS_TIME_HANDLE animTimer;
SYS_TIME_HANDLE backlightTimer;
volatile unsigned int animCounter;
unsigned int animCounterOld;
static unsigned int brightness = 0;
static unsigned int newBrightness = 0;


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


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************
void appSetLeftNeedleImageData(leImage * imgAst,
                           uint32_t angle,
                           uint32_t x,
                           uint32_t y)
{
    leftNeedles[angle].x = x;
    leftNeedles[angle].y = y;
    leftNeedles[angle].imgAst = imgAst;
}

void appSetRightNeedleImageData(leImage * imgAst,
                           uint32_t angle,
                           uint32_t x,
                           uint32_t y)
{
    rightNeedles[angle].x = x;
    rightNeedles[angle].y = y;
    rightNeedles[angle].imgAst = imgAst;
}



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

    /* Early pre-process splash screen images */
    APP_PreprocessSplashImages();
    
    /* Initialize canvas objects */
    gfxcSetLayer(BACKGROUND_CANVAS_ID, BACKGROUND_LAYER_ID);
    gfxcSetLayer(INFOPAGE_CANVAS_ID, INFOPAGE_LAYER_ID);
    gfxcSetLayer(LEFT_NEEDLE_CANVAS_ID, LEFT_NEEDLE_LAYER_ID);
    gfxcSetLayer(RIGHT_NEEDLE_CANVAS_ID, RIGHT_NEEDLE_LAYER_ID);
    gfxcSetLayer(MCHP_LOGO_CANVAS_ID, MCHP_LOGO_LAYER_ID);
    gfxcSetLayer(MHGC_LOGO_CANVAS_ID, MHGC_LOGO_LAYER_ID);    

    gfxcSetWindowSize(BACKGROUND_CANVAS_ID, 1600, 480);

    //Show splash screen using canvas
    appSetLayerFrame(MHGC_LOGO_CANVAS_ID, 
                    (uint32_t) MHGC_200x200_white.buffer.pixels, 
                    300,
                    140,
                    MHGC_200x200_white.buffer.size.width, 
                    MHGC_200x200_white.buffer.size.height);
    
    appSetLayerFrame(MCHP_LOGO_CANVAS_ID,
                    (uint32_t) mchpLogo_light.buffer.pixels, 
                    0,
                    0,
                    mchpLogo_light.buffer.size.width, 
                    mchpLogo_light.buffer.size.height);    
    
    gfxcHideCanvas(BACKGROUND_CANVAS_ID);
    gfxcShowCanvas(MCHP_LOGO_CANVAS_ID);
    gfxcShowCanvas(MHGC_LOGO_CANVAS_ID);

    gfxcCanvasUpdate(BACKGROUND_CANVAS_ID);
    gfxcCanvasUpdate(MCHP_LOGO_CANVAS_ID);
    gfxcCanvasUpdate(MHGC_LOGO_CANVAS_ID);
}

void animTimer_Callback ( uintptr_t context )
{
    animCounter++;
}

void StartAnimTimer(void)
{
    SYS_TIME_TimerStop(animTimer);
    SYS_TIME_TimerDestroy(animTimer);
    
    animTimer = SYS_TIME_CallbackRegisterUS(animTimer_Callback, 
                    NULL,
                    ANIM_TIMER_PERIOD_US,
                    SYS_TIME_PERIODIC); 
}

void appSetLayerFrame(uint32_t layerID, 
                      uint32_t addr,
                      uint32_t x,
                      uint32_t y,
                      uint32_t width,
                      uint32_t height)
{
    gfxcSetPixelBuffer(layerID,
                       width,
                       height,
                       GFX_COLOR_MODE_RGBA_8888,
                       (void *) addr);
    
    gfxcSetWindowPosition(layerID, x, y);
    gfxcSetWindowSize(layerID, width, height);
    gfxcCanvasUpdate(layerID);
}

static void Backlight_TimerCallback ( uintptr_t context )
{
    if (brightness != newBrightness)
    {
        if (newBrightness > brightness)
        {
            if (brightness < newBrightness - BRIGHTNESS_DELTA_PCT_UP)
            {
                brightness += BRIGHTNESS_DELTA_PCT_UP;
            }
            else
            {
                brightness = newBrightness;
                SYS_TIME_TimerStop(backlightTimer);
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
                SYS_TIME_TimerStop(backlightTimer);
            }        
        }

        OCMP1_CompareSecondaryValueSet( (TMR_PERIOD * brightness)/100);

    }
    else if (brightness == newBrightness)
    {
        SYS_TIME_TimerStop(backlightTimer);
    }
}

void APP_SetBacklightBrightness(unsigned int pct)
{
    if (pct == brightness)
        return;
    
    if (pct > ON_BRIGHTNESS)
        newBrightness = ON_BRIGHTNESS;
    else    
        newBrightness = pct;
    
    SYS_TIME_TimerStart(backlightTimer);
}

unsigned int APP_GetBacklightBrightness(void)
{
    return brightness;
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
            
            backlightTimer = SYS_TIME_CallbackRegisterMS(Backlight_TimerCallback, 
                                    (uintptr_t) NULL,
                                    BACKLIGHT_TIMER_PERIOD_MS,
                                    SYS_TIME_PERIODIC);   
            
            TMR2_Start();
            OCMP1_Enable();
            
            APP_SetBacklightBrightness(ON_BRIGHTNESS);
            APP_PreprocessNeedleImages();

            if (appInitialized)
            {
                appData.state = APP_STATE_FADE_IN_SPLASH;
            }
            break;
        }
        case APP_STATE_FADE_IN_SPLASH:
        {
            if (APP_GetBacklightBrightness() > ON_BRIGHTNESS)
                break;
            
            appData.state = APP_STATE_FADE_OUT_SPLASH;
            
            APP_SetBacklightBrightness(OFF_BRIGHTNESS);
            break;
        }
        case APP_STATE_FADE_OUT_SPLASH:
        {
            appData.state = APP_STATE_INIT_OVERLAYS;
            break;
        }
        case APP_STATE_INIT_OVERLAYS:
        {
            if (APP_GetBacklightBrightness() > OFF_BRIGHTNESS)
                break;
            
            //show the background cluster
            gfxcShowCanvas(BACKGROUND_CANVAS_ID);
            gfxcCanvasUpdate(BACKGROUND_CANVAS_ID);
            
            //hide the logos
            gfxcHideCanvas(MCHP_LOGO_CANVAS_ID);
            gfxcCanvasUpdate(MCHP_LOGO_CANVAS_ID);
            gfxcHideCanvas(MHGC_LOGO_CANVAS_ID);
            gfxcCanvasUpdate(MHGC_LOGO_CANVAS_ID);
            
            //show infopage
            gfxcSetWindowSize(INFOPAGE_CANVAS_ID, 300, 350); 
            gfxcSetWindowAlpha(INFOPAGE_CANVAS_ID, 220);
            gfxcShowCanvas(INFOPAGE_CANVAS_ID);            
            gfxcCanvasUpdate(INFOPAGE_CANVAS_ID);
            gfxcStartEffectMove(INFOPAGE_CANVAS_ID,
                            GFXC_FX_MOVE_DEC,
                            250,
                            -350,
                            250,
                            65,
                            10);   
            APP_SetBacklightBrightness(ON_BRIGHTNESS);
       
            
            appData.state = APP_STATE_SHOW_HELP;
            
            break;
        }
        case APP_STATE_SHOW_HELP:
        {
            //wait for touch to happen
            break;
        }
        case APP_STATE_START_SCENE:
        {
            StartAnimTimer();     
            
            appData.state = APP_STATE_PROCESS_SCENE1;
            break;
        }
        case APP_STATE_PROCESS_SCENE1:
            //No break
        case APP_STATE_PROCESS_SCENE2:
        {
            APP_Process_Scene1();
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

void event_Screen0_ButtonWidget0_OnPressed(leButtonWidget* btn)
{
    switch(appData.state)
    {   
        case APP_STATE_SHOW_HELP:
        {
            appData.state = APP_STATE_START_SCENE;
            break;
        }
        case APP_STATE_PROCESS_SCENE1:
        {    
            appData.scene_state = APP_SCENE_STATE_HIDE_HELP;
            break;
        }
        case APP_STATE_PROCESS_SCENE2:
        {   
            appData.scene_state = APP_SCENE_STATE_HIDE_HELP;
            break;
        }
        default:
            break;
    }
}

void Screen0_OnUpdate()
{
    
}

/*******************************************************************************
 End of File
 */
