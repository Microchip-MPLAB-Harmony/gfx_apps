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

#include "app.h"
#include "app_splash.h"
#include "gfx/hal/inc/gfx_context.h"
#include "gfx/libaria/libaria.h"
#include "gfx/libaria/libaria_init.h"
#include "gfx/gfx_assets.h"

#include "system/time/sys_time.h"

#define MAX_COUNTDOWN 9999
#define MIN_COUNTDOWN 0
#define MAX_COUNTUP 9999
#define MIN_COUNTUP 0
#define MIN_COUNTER_SIZE 1
#define MAX_COUNTER_SIZE 5
#define DEF_RECT_SIZE 40
#define RECT_PIXSIZE_INC 10
#define MAX_RECT_SIZE 260
#define MIN_RECT_SIZE 10
#define FULLSCREEN_RECT_SIZE 0xffffffff
#define MAX_NUM_IMAGES 2
#define MOTION_BLACKHOLE_WIDTH  120

#define FPS_UPDATE_TIMER_PERIOD_MS 1000
#define AVE_FPS_COUNT 10

#define MAX_FILL_SCHEMES_CYCLE 5

typedef enum
{
    RECT_WIDGET_0,
    RECT_WIDGET_1,
    RECT_WIDGET_2,
    RECT_WIDGET_3,
    RECT_WIDGET_4,
    RECT_WIDGET_5,
    RECT_WIDGET_6,
    RECT_WIDGET_7,
    RECT_WIDGET_8,
    RECT_WIDGET_9,
    MOTION_WIDGETS_NUM,
} MOTION_WIDGET_IDX;

typedef enum
{
    APP_IMG_40x40,
    APP_IMG_100x100,
    APP_IMG_200x200,
    APP_IMG_480x270,
    APP_IMG_MAX_SIZE,
} APP_IMAGE_SIZE_T;

typedef enum
{
    APP_IMG_PNG_8888,
    APP_IMG_JPG_24,
    APP_IMG_RAW_565,
    APP_IMG_RAW_RLE_565,
#if defined(PRE_PROCESSED_IMAGES_SUPPORTED)            
    APP_IMG_RAW_BLIT,
#endif            
    APP_IMG_MAX_TYPE,
} APP_IMAGE_TYPE_T;

typedef struct 
{
    MOTION_WIDGET_IDX idx;
    laWidget * widget;
    int dx;
    int dy;            
} MOTION_WIDGET_T;

typedef struct
{
    GFXU_ImageAsset * imgAsst[MAX_NUM_IMAGES];
} IMAGE_LIST_T;

typedef struct
{
    laLabelWidget* fpsCurrent;
    laLabelWidget* fpsAve;
    laLabelWidget* refreshRate;
    laButtonWidget * fpsButton;
} FPS_UPDATE_TIMER_CONTEXT_T;

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
static SYS_TIME_HANDLE fpsUpdateTimer;
static volatile GFX_Context * gfxContext;
static FPS_UPDATE_TIMER_CONTEXT_T fpsTmrCtxt;
extern unsigned int vsyncCount;
static uint32_t prevSwapCountAve[AVE_FPS_COUNT] = {0};
static volatile bool aveFPSValid = false;
static int aveCounter = 0;

MOTION_WIDGET_T motionWidgets[MOTION_WIDGETS_NUM] = 
{
    {RECT_WIDGET_0, NULL, 1, -1},
    {RECT_WIDGET_1, NULL, -1, 1},
    {RECT_WIDGET_2, NULL, 1, -1},
    {RECT_WIDGET_3, NULL, 1, 1},
    {RECT_WIDGET_4, NULL, -1, 1},    
    {RECT_WIDGET_5, NULL, 1, 1},    
    {RECT_WIDGET_6, NULL, 1, -1},    
    {RECT_WIDGET_7, NULL, 1, -1},    
    {RECT_WIDGET_8, NULL, 1, 1},    
    {RECT_WIDGET_9, NULL, -1, -1},    
};

unsigned int counterSizeStrings[MAX_COUNTER_SIZE + 1] =
{
    0x00,
    string_NumsTiny,
    string_NumsLittle,
    string_NumsSmall,
    string_NumsMed,
    string_NumsLarge,
};

laScheme * FillSchemes[MAX_FILL_SCHEMES_CYCLE] = 
{
    &PinkFillScheme,
    &PurpleFillScheme,
    &RedFillScheme,
    &BlueFillScheme,
    &LightRedBackgroundScheme,
};

IMAGE_LIST_T imagesPNG[] =
{
    [APP_IMG_40x40] = {
        {&PNG_GFX_mchp_40x40,
        &PNG_GFX_mplab_40x40},
    },
#ifdef APP_PNG_100x100_NOT_SUPPORTED
    [APP_IMG_100x100] = {
        {NULL,
        NULL},
    },    
#else
    [APP_IMG_100x100] = {
        {&PNG_GFX_mchp_100x100,
        &PNG_GFX_mplab_100x100},
    },
#endif    
    [APP_IMG_200x200] = {
        {NULL,
        NULL},
    },
    [APP_IMG_480x270] = {
        {NULL,
        NULL},
    },    
};

IMAGE_LIST_T imagesJPG[] =
{
    [APP_IMG_40x40] = {
        {&JPG_GFX_mchp_40x40,
        &JPG_GFX_mplab_40x40},
    },
    [APP_IMG_100x100] = {
        {&JPG_GFX_mchp_100x100,
        &JPG_GFX_mplab_100x100},
    },
    [APP_IMG_200x200] = {
        {&JPG_GFX_mchp_200x200,
        &JPG_GFX_mplab_200x200},
    },
    [APP_IMG_480x270] = {
        {&JPG_GFX_mchp_480x270,
        &JPG_GFX_mplab_480x270},
    },    
};

IMAGE_LIST_T imagesRAW[] =
{
    [APP_IMG_40x40] = {
        {&RAW_GFX_mchp_40x40,
        &RAW_GFX_mplab_40x40},
    },
    [APP_IMG_100x100] = {
        {&RAW_GFX_mchp_100x100,
        &RAW_GFX_mplab_100x100},
    },
    [APP_IMG_200x200] = {
        {&RAW_GFX_mchp_200x200,
        &RAW_GFX_mplab_200x200},
    },
    [APP_IMG_480x270] = {
        {&RAW_GFX_mchp_480x270,
        &RAW_GFX_mplab_480x270},
    },    
};

IMAGE_LIST_T imagesRAWRLE[] =
{
    [APP_IMG_40x40] = {
        {&RAWRLE_GFX_mchp_40x40,
        &RAWRLE_GFX_mplab_40x40},
    },
    [APP_IMG_100x100] = {
        {&RAWRLE_GFX_mchp_100x100,
        &RAWRLE_GFX_mplab_100x100},
    },
    [APP_IMG_200x200] = {
        {&RAWRLE_GFX_mchp_200x200,
        &RAWRLE_GFX_mplab_200x200},
    },
    [APP_IMG_480x270] = {
        {&RAWRLE_GFX_mchp_480x270,
        &RAWRLE_GFX_mplab_480x270},
    },    
};

#if defined(PRE_PROCESSED_IMAGES_SUPPORTED)
IMAGE_LIST_T imagesRAWBLIT[] =
{
    [APP_IMG_40x40] = {
        {&BLIT_GFX_mchp_40x40,
        &BLIT_GFX_mplab_40x40},
    },
    [APP_IMG_100x100] = {
        {&BLIT_GFX_mchp_100x100,
        &BLIT_GFX_mplab_100x100},
    },
    [APP_IMG_200x200] = {
        {&BLIT_GFX_mchp_200x200,
        &BLIT_GFX_mplab_200x200},
    },
    [APP_IMG_480x270] = {
        {&BLIT_GFX_mchp_480x270,
        &BLIT_GFX_mplab_480x270},
    },    
};
#endif

char * imageSizeNames[APP_IMG_MAX_SIZE] = 
{
    [APP_IMG_40x40] = "40x40",
    [APP_IMG_100x100] = "100x100",
    [APP_IMG_200x200] = "200x200",
    [APP_IMG_480x270] = "480x270",    
};

unsigned int imageTypeNames[APP_IMG_MAX_TYPE] = 
{
    [APP_IMG_PNG_8888] = string_PNG8888,
    [APP_IMG_JPG_24] = string_JPG24Bit,
    [APP_IMG_RAW_565] = string_Raw565,
    [APP_IMG_RAW_RLE_565] = string_RawRLE565,
#if defined(PRE_PROCESSED_IMAGES_SUPPORTED)    
    [APP_IMG_RAW_BLIT] = string_PreProcessedBlit,  
#endif    
};

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

static void APP_DecrementCount(laLabelWidget* labelWidget)
{
    static int tickDecCount = MAX_COUNTDOWN;
    char charBuff[16] = {0};
    laString str;
    
    tickDecCount--;
    
    if (tickDecCount <= MIN_COUNTDOWN)
        tickDecCount = MAX_COUNTDOWN;
    
    sprintf(charBuff, "%04u", tickDecCount);
    
    str = laString_CreateFromCharBuffer(charBuff, 
            GFXU_StringFontIndexLookup(&stringTable, counterSizeStrings[appData.counterStringSize], 0));
    
    laLabelWidget_SetText(labelWidget, str);
    
    laString_Destroy(&str);
    
}

static void fpsUpdateTimer_Callback ( uintptr_t context )
{
    static uint32_t prevSwapCount = 0;
    static uint32_t prevVsyncCount = 0;
    char charBuff[16] = {0};
    unsigned int rate;
    unsigned int i;
    laString str;
    
    if (fpsTmrCtxt.fpsButton == NULL)
        return;
    
    //Update the 10-pt rolling average
    prevSwapCountAve[aveCounter] = (gfxContext->layer.active->swapCount - 
                                    prevSwapCount);
    
    //If not pressed, show current FPS
    if (laButtonWidget_GetPressed(fpsTmrCtxt.fpsButton) == LA_FALSE)
    {
            //Update FPS
        rate =  (gfxContext->layer.active->swapCount - prevSwapCount)/
               (FPS_UPDATE_TIMER_PERIOD_MS/1000);

        sprintf(charBuff, "%u curr", rate);
    }
    //If pressed, show average FPS
    else
    {
        for (i = 0, rate = 0; i < AVE_FPS_COUNT; i++)
        {
            rate += prevSwapCountAve[i];
        }

        if (aveFPSValid)
        {
            sprintf(charBuff, "%u avg", 
                   (rate / ((AVE_FPS_COUNT)*(FPS_UPDATE_TIMER_PERIOD_MS/1000))));
        }
        else
        {
            sprintf(charBuff, "---");
        }
    }
    
    if (aveCounter < (AVE_FPS_COUNT - 1))
    {
        aveCounter++;
    }
    else
    {
        aveCounter = 0;
        aveFPSValid = true;
    }
    
    str = laString_CreateFromCharBuffer(charBuff, 
    GFXU_StringFontIndexLookup(&stringTable, string_NumsLittle, 0));

    laButtonWidget_SetText(fpsTmrCtxt.fpsButton, str);

    laString_Destroy(&str);
    

    //Update Refresh Rate
    rate =  (vsyncCount - prevVsyncCount)/
               (FPS_UPDATE_TIMER_PERIOD_MS/1000);

    //If vsyncCount does not increase, assume fixed refresh rate using vsyncCount
    //value
    if (rate == 0)
        rate = vsyncCount;

    sprintf(charBuff, "%u", rate);
    
    str = laString_CreateFromCharBuffer(charBuff, 
            GFXU_StringFontIndexLookup(&stringTable, string_NumsLittle, 0));
    
    laLabelWidget_SetText(fpsTmrCtxt.refreshRate, str);
    
    laString_Destroy(&str);
    
    prevSwapCount = gfxContext->layer.active->swapCount;
    prevVsyncCount = vsyncCount;
    
//    APP_DecrementCount(Counter1LabelWidget);
}

void resetFPS(void)
{
    char charBuff[16] = {0};
    laString str;
    
    aveFPSValid = false;
    aveCounter = 0;
    
    sprintf(charBuff, "---");
    
    str = laString_CreateFromCharBuffer(charBuff,
            GFXU_StringFontIndexLookup(&stringTable, string_NumsLittle, 0));
    
    laButtonWidget_SetText(fpsTmrCtxt.fpsButton, str);
    
    laString_Destroy(&str);
}

static void moveWidget(MOTION_WIDGET_IDX id)
{
    laWidget * widget = motionWidgets[id].widget;
    
    if (((widget->rect.x + appData.rectSize) >= (gfxContext->display_info->rect.width - MOTION_BLACKHOLE_WIDTH)) ||
        ((widget->rect.x + motionWidgets[id].dx + appData.rectSize) > (gfxContext->display_info->rect.width - MOTION_BLACKHOLE_WIDTH)))
    {
        motionWidgets[id].dx = -1;
    }
    
    if((widget->rect.x <= 0) ||
       ((widget->rect.x - motionWidgets[id].dx) < 0))
       
    {
        motionWidgets[id].dx = 1;
    }
    
    if (((widget->rect.y + appData.rectSize) >= gfxContext->display_info->rect.height) ||
        (((widget->rect.y + appData.rectSize) + motionWidgets[id].dy) > gfxContext->display_info->rect.height))
    {
        motionWidgets[id].dy = -1;
    }
    
    if ((widget->rect.y <= 0) ||
        ((widget->rect.y + motionWidgets[id].dy) < 0))
    {
        motionWidgets[id].dy = 1;
    }
   
    laWidget_SetPosition(widget, 
                         widget->rect.x + motionWidgets[id].dx,
                         widget->rect.y + motionWidgets[id].dy);
}

static void nextImage(laImageWidget * imgWidget)
{
    if (appData.imgType == APP_IMG_PNG_8888)
    {
        if (imagesPNG[appData.imgSize].imgAsst[appData.imgIndex] != NULL)
        {
            laImageWidget_SetImage(imgWidget, 
                                   imagesPNG[appData.imgSize].imgAsst[appData.imgIndex]);
        }
        else
        {
            
        }
    }
    else if (appData.imgType == APP_IMG_JPG_24)
    {
        if (imagesJPG[appData.imgSize].imgAsst[appData.imgIndex] != NULL)
        {
            laImageWidget_SetImage(imgWidget, 
                                   imagesJPG[appData.imgSize].imgAsst[appData.imgIndex]);
        }
    }
    else if (appData.imgType == APP_IMG_RAW_565)
    {
        if (imagesRAW[appData.imgSize].imgAsst[appData.imgIndex] != NULL)
        {
            laImageWidget_SetImage(imgWidget, 
                                   imagesRAW[appData.imgSize].imgAsst[appData.imgIndex]);
        }
    }
    else if (appData.imgType == APP_IMG_RAW_RLE_565)
    {
        if (imagesRAWRLE[appData.imgSize].imgAsst[appData.imgIndex] != NULL)
        {
            laImageWidget_SetImage(imgWidget, 
                                   imagesRAWRLE[appData.imgSize].imgAsst[appData.imgIndex]);
        }
    }
#if defined(PRE_PROCESSED_IMAGES_SUPPORTED)      
    else if (appData.imgType == APP_IMG_RAW_BLIT)
    {
        if (imagesRAWBLIT[appData.imgSize].imgAsst[appData.imgIndex] != NULL)
        {
            laImageWidget_SetImage(imgWidget, 
                                   imagesRAWBLIT[appData.imgSize].imgAsst[appData.imgIndex]);
        }
    }
#endif    
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

    
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */
void APP_Tasks ( void )
{
    char charBuff[10] = {0};
    laString str;
    
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
        
            if (appInitialized)
            {
                appData.event = APP_EVENT_INIT_STATE;
                appData.state = APP_STATE_SPLASH;
                gfxContext = GFX_ActiveContext();
                
            }
            break;
        }
        case APP_STATE_SPLASH:
        {            
            if (APP_IsSplashScreenComplete())
            {
                laContext_SetActiveScreen(FPSCounters_ID);
                appData.state = APP_STATE_RUN_FPS_COUNTERS;
                appData.event = APP_EVENT_INIT_STATE;
            }
        
            break;
        }
        case APP_STATE_RUN_FPS_COUNTERS:
        {

            switch (appData.event)
            {
                case APP_EVENT_NONE:
                {
                    //DO NOTHING
                    break;
                }
                case APP_EVENT_INIT_STATE:
                {
                    appData.counterStringSize = 1;

                    fpsTmrCtxt.refreshRate = RefreshRateCountLabelWidget;
                    fpsTmrCtxt.fpsButton = FPSButtonCounter;
                    
                    resetFPS();
                    
                    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
                    
                    memset(prevSwapCountAve, 0, sizeof(prevSwapCountAve));
                            
                    SYS_TIME_TimerDestroy(fpsUpdateTimer);

                    fpsUpdateTimer = SYS_TIME_CallbackRegisterMS(fpsUpdateTimer_Callback, 
                                        1,
                                        FPS_UPDATE_TIMER_PERIOD_MS,
                                        SYS_TIME_PERIODIC);
                    
                    sprintf(charBuff, "%u", appData.counterStringSize);
                    str = laString_CreateFromCharBuffer(charBuff,
                            GFXU_StringFontIndexLookup(&stringTable, 
                                                       string_NumsLittle, 
                                                       0));

                    laLabelWidget_SetText(StringSizeIdxLabel, str);
                    laString_Destroy(&str);
                    
                    laWidget_Invalidate((laWidget*)StringSizeIdxLabel);

                    appData.event = APP_EVENT_NONE;
                    
                    break;
                }
                case APP_EVENT_COUNTER_SIZE_UP:
                {
                    appData.counterStringSize = 
                        (appData.counterStringSize < MAX_COUNTER_SIZE) ? 
                        appData.counterStringSize + 1 :
                        appData.counterStringSize;
                    
                    
                    sprintf(charBuff, "%u", appData.counterStringSize);
                    str = laString_CreateFromCharBuffer(charBuff,
                            GFXU_StringFontIndexLookup(&stringTable, 
                                                       string_NumsLittle, 
                                                       0));

                    laLabelWidget_SetText(StringSizeIdxLabel, str);
                    laString_Destroy(&str);

                    appData.event = APP_EVENT_NONE;
                    
                    resetFPS();
                    
                    break;
                }
                case APP_EVENT_COUNTER_SIZE_DOWN:
                {
                    appData.counterStringSize = 
                        (appData.counterStringSize == 1) ? 
                        appData.counterStringSize :
                        appData.counterStringSize - 1;
                    
                    sprintf(charBuff, "%u", appData.counterStringSize);
                    str = laString_CreateFromCharBuffer(charBuff,
                            GFXU_StringFontIndexLookup(&stringTable, 
                                                       string_NumsLittle, 
                                                       0));

                    laLabelWidget_SetText(StringSizeIdxLabel, str);
                    laString_Destroy(&str);
                    
                    appData.event = APP_EVENT_NONE;
                    
                    resetFPS();
                    
                    break;                    
                }
                case APP_EVENT_NEXT:
                {
                    appData.state = APP_STATE_RUN_FPS_MOTION;
                    appData.event = APP_EVENT_INIT_STATE;

                    laContext_SetActiveScreen(FPSMotion_ID);
                    SYS_TIME_TimerDestroy(fpsUpdateTimer);
                    
                    aveFPSValid = false;
                    
                    break;                    
                }                
                default:
                    break;
            }
            
            APP_DecrementCount(Counter1LabelWidget);

            break;
        }
        
        case APP_STATE_RUN_FPS_MOTION:
        {
            unsigned int i;
            
//            if (laContext_IsDrawing())
//                break;
            
            switch (appData.event)
            {
                case APP_EVENT_NONE:
                {
                    //DO NOTHING
                    break;
                }
                case APP_EVENT_INIT_STATE:
                {
                    appData.event = APP_EVENT_NONE;
                    appData.motionRectsCount = 1;
                    appData.rectSize = DEF_RECT_SIZE;
                    
                    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
                    
                    //Initialize the motion widgets
                    motionWidgets[RECT_WIDGET_0].widget = 
                                &RectMotionWidget1->widget;
                    motionWidgets[RECT_WIDGET_1].widget = 
                                &RectMotionWidget2->widget;
                    motionWidgets[RECT_WIDGET_2].widget = 
                                &RectMotionWidget3->widget;
                    motionWidgets[RECT_WIDGET_3].widget = 
                                &RectMotionWidget4->widget;
                    motionWidgets[RECT_WIDGET_4].widget = 
                                &RectMotionWidget5->widget;
                    motionWidgets[RECT_WIDGET_5].widget = 
                                &RectMotionWidget6->widget;
                    motionWidgets[RECT_WIDGET_6].widget = 
                                &RectMotionWidget7->widget;
                    motionWidgets[RECT_WIDGET_7].widget = 
                                &RectMotionWidget8->widget;
                    motionWidgets[RECT_WIDGET_8].widget = 
                                &RectMotionWidget9->widget;
                    motionWidgets[RECT_WIDGET_9].widget = 
                                &RectMotionWidget10->widget;
                    
                    for (i = 0; i < MOTION_WIDGETS_NUM; i++)
                    {
                        laWidget_SetWidth(motionWidgets[RECT_WIDGET_0 + i].widget, 
                                    DEF_RECT_SIZE);
                        laWidget_SetHeight(motionWidgets[RECT_WIDGET_0 + i].widget,
                                    DEF_RECT_SIZE);
                        laWidget_SetVisible(motionWidgets[RECT_WIDGET_0 + i].widget, 
                                    LA_FALSE);
                    }
                    
                    laWidget_SetVisible(motionWidgets[RECT_WIDGET_0].widget, LA_TRUE);
                    
                    sprintf(charBuff, "%u", appData.motionRectsCount);
                    str = laString_CreateFromCharBuffer(charBuff,
                            GFXU_StringFontIndexLookup(&stringTable, 
                                                       string_NumsLittle, 
                                                       0));
                    laLabelWidget_SetText(NumRectCountLabel, str);
                    laString_Destroy(&str);
                    
                    sprintf(charBuff, "%u", appData.rectSize);
                    str = laString_CreateFromCharBuffer(charBuff,
                            GFXU_StringFontIndexLookup(&stringTable, string_NumsTiny, 0));

                    laLabelWidget_SetText(SquareSizeLabel, str);
                    laString_Destroy(&str);
                    
                    fpsTmrCtxt.refreshRate = RefreshRateMotionLabelWidget;
                    fpsTmrCtxt.fpsButton = FPSButtonMotion;
                    
                    resetFPS();
                    
                    memset(prevSwapCountAve, 0, sizeof(prevSwapCountAve));
                    if (fpsUpdateTimer != 0)
                        SYS_TIME_TimerDestroy(fpsUpdateTimer);
                    fpsUpdateTimer = SYS_TIME_CallbackRegisterMS(fpsUpdateTimer_Callback, 
                                            1,
                                            FPS_UPDATE_TIMER_PERIOD_MS,
                                            SYS_TIME_PERIODIC);
                    
                    break;
                }
                case APP_EVENT_RECT_SIZE_UP:
                case APP_EVENT_RECT_SIZE_DOWN:                    
                {
                    GFX_Context* context = GFX_ActiveContext();
                    
                    if (appData.event == APP_EVENT_RECT_SIZE_UP)
                    {
                        if (appData.rectSize == FULLSCREEN_RECT_SIZE)
                        {
                            appData.rectSize = MIN_RECT_SIZE;
                        }
                        else
                        {
                            //If max size is already reached, switch to full screen fill
                            appData.rectSize = (appData.rectSize < MAX_RECT_SIZE) ?
                                    appData.rectSize + RECT_PIXSIZE_INC : FULLSCREEN_RECT_SIZE;
                        }
                    }
                    else
                    {
                        if (appData.rectSize == FULLSCREEN_RECT_SIZE)
                        {
                            appData.rectSize = MAX_RECT_SIZE;
                        }
                        else
                        {
                            //If min size is already reached, switch to full screen fill
                            appData.rectSize = (appData.rectSize > MIN_RECT_SIZE) ?
                                appData.rectSize - RECT_PIXSIZE_INC : FULLSCREEN_RECT_SIZE;
                        }
                    }
                    
                    if (appData.rectSize == FULLSCREEN_RECT_SIZE)
                    {
                        laWidget_SetWidth(motionWidgets[RECT_WIDGET_0].widget, 
                                        context->display_info->rect.width);
                        laWidget_SetHeight(motionWidgets[RECT_WIDGET_0].widget, 
                                        context->display_info->rect.height);
                        
                        laLabelWidget_SetText(SquareSizeLabel, laString_CreateFromID(string_Fullscreen));
                    }
                    else
                    {
                        for (i = 0; i < MOTION_WIDGETS_NUM; i++)
                        {
                            laWidget_SetWidth(motionWidgets[RECT_WIDGET_0 + i].widget, 
                                        appData.rectSize);
                            laWidget_SetHeight(motionWidgets[RECT_WIDGET_0 + i].widget,
                                        appData.rectSize);                        
                        }
                        
                        //Update image size label
                        sprintf(charBuff, "%u", appData.rectSize);
                        str = laString_CreateFromCharBuffer(charBuff,
                        GFXU_StringFontIndexLookup(&stringTable, string_NumsTiny, 0));
                        laLabelWidget_SetText(SquareSizeLabel, str);
                        laString_Destroy(&str);
                    }
                    
                    appData.event = APP_EVENT_NONE;
                    
                    resetFPS();

                    break;
                }
                case APP_EVENT_MOTION_ADD_RECT:
                case APP_EVENT_MOTION_REMOVE_RECT:                    
                {
                    
                    if (appData.event == APP_EVENT_MOTION_ADD_RECT)
                    {
                        appData.motionRectsCount = (appData.motionRectsCount == MOTION_WIDGETS_NUM) ?
                            appData.motionRectsCount : appData.motionRectsCount + 1;
                    }
                    else
                    {
                        appData.motionRectsCount = (appData.motionRectsCount == 1) ?
                            appData.motionRectsCount : appData.motionRectsCount - 1;
                    }
                    
                    for (i = 0; i < MOTION_WIDGETS_NUM; i++)
                    {
                        if (i < appData.motionRectsCount)
                        {
                            laWidget_SetVisible(motionWidgets[RECT_WIDGET_0 + i].widget, LA_TRUE);
                        }
                        else
                        {
                            laWidget_SetVisible(motionWidgets[RECT_WIDGET_0 + i].widget, LA_FALSE);
                        }
                            
                    }
                    
                    // Update rectangle count label
                    sprintf(charBuff, "%u", appData.motionRectsCount);
                    str = laString_CreateFromCharBuffer(charBuff,
                            GFXU_StringFontIndexLookup(&stringTable, string_NumsTiny, 0));

                    laLabelWidget_SetText(NumRectCountLabel, str);
                    laString_Destroy(&str);
                    
                    appData.event = APP_EVENT_NONE;
                    
                    resetFPS();
                    
                    break;
                }
                case APP_EVENT_NEXT:
                {
                    appData.state = APP_STATE_RUN_FPS_IMAGE_RENDER;
                    appData.event = APP_EVENT_INIT_STATE;

                    laContext_SetActiveScreen(FPSImages_ID);
                    if (fpsUpdateTimer != 0)
                        SYS_TIME_TimerDestroy(fpsUpdateTimer);
                    
                    break;
                }
                default:
                    break;
            }
            
            //If doing full screen fill, just update the widget color
            if (appData.rectSize == FULLSCREEN_RECT_SIZE)
            {
                static uint32_t fillSchemeIndex = 0;

                laWidget_SetPosition((laWidget*) motionWidgets[0].widget, 
                        0, 0);                
                laWidget_SetScheme((laWidget*) motionWidgets[0].widget, 
                        FillSchemes[fillSchemeIndex]);
                
                fillSchemeIndex = (fillSchemeIndex == MAX_FILL_SCHEMES_CYCLE) ?
                    0 : fillSchemeIndex + 1;
            }
            else
            {
                for (i = 0; i < appData.motionRectsCount; i++)
                {
                    moveWidget(RECT_WIDGET_0 + i);
                }
            }
            
            break;
        }
        case APP_STATE_RUN_FPS_IMAGE_RENDER:
        {
            switch (appData.event)
            {
                case APP_EVENT_NONE:
                {
                    //DO NOTHING
                    break;
                }
                case APP_EVENT_INIT_STATE:
                {
                    appData.event = APP_EVENT_NONE;
                    appData.imgSize = APP_IMG_40x40;
                    appData.imgType = APP_IMG_RAW_RLE_565;
                    appData.imgIndex = 0;
                    
                    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
                    
                    // Initialize image size label
                    sprintf(charBuff, "%s", imageSizeNames[appData.imgSize]);
                    str = laString_CreateFromCharBuffer(charBuff,
                            GFXU_StringFontIndexLookup(&stringTable, string_NumsTiny, 0));

                    laLabelWidget_SetText(ImageSizeLabel, str);
                    laString_Destroy(&str);
                    
                    // Initialize image type label
                    laLabelWidget_SetText(ImageTypeLabel, laString_CreateFromID(imageTypeNames[appData.imgType])); 
                    
                    fpsTmrCtxt.refreshRate = ImageRefRateCountLabel;
                    fpsTmrCtxt.fpsButton = FPSButtonImages;
                    
                    resetFPS();
                    
                    memset(prevSwapCountAve, 0, sizeof(prevSwapCountAve));
                    if (fpsUpdateTimer != 0)
                        SYS_TIME_TimerDestroy(fpsUpdateTimer);
                    
                    fpsUpdateTimer = SYS_TIME_CallbackRegisterMS(fpsUpdateTimer_Callback, 
                                            1,
                                            FPS_UPDATE_TIMER_PERIOD_MS,
                                            SYS_TIME_PERIODIC);

                    break;
                }
                case APP_EVENT_NEXT:
                {
                    appData.state = APP_STATE_RUN_FPS_COUNTERS;
                    appData.event = APP_EVENT_INIT_STATE;

                    laContext_SetActiveScreen(FPSCounters_ID);
                    if (fpsUpdateTimer != 0)
                        SYS_TIME_TimerDestroy(fpsUpdateTimer);                    
                    
                    break;
                }
                case APP_EVENT_IMAGE_SIZE_UP:
                {
                    appData.imgSize = (appData.imgSize < (APP_IMG_MAX_SIZE - 1)) ? 
                            appData.imgSize + 1 : appData.imgSize;
                    
                    // Special handling, PNG sizes are limited to 100x100 due 
                    // to memory limitations
                    if ((appData.imgType == APP_IMG_PNG_8888) && 
                        (appData.imgSize > APP_IMG_100x100))
                    {
                        appData.imgSize = APP_IMG_100x100;
                    }
                    
                    //Update image size label
                    sprintf(charBuff, "%s", imageSizeNames[appData.imgSize]);
                    str = laString_CreateFromCharBuffer(charBuff,
                            GFXU_StringFontIndexLookup(&stringTable, string_NumsTiny, 0));

                    laLabelWidget_SetText(ImageSizeLabel, str);
                    laString_Destroy(&str);
                    
                    appData.event = APP_EVENT_NONE;
                    
                    resetFPS();
                    
                    break;
                }
                case APP_EVENT_IMAGE_SIZE_DOWN:
                {
                    appData.imgSize = (appData.imgSize != 0) ? 
                            appData.imgSize - 1 : appData.imgSize;
                    
                    //Update image size label
                    sprintf(charBuff, "%s", imageSizeNames[appData.imgSize]);
                    str = laString_CreateFromCharBuffer(charBuff,
                            GFXU_StringFontIndexLookup(&stringTable, string_NumsTiny, 0));

                    laLabelWidget_SetText(ImageSizeLabel, str);
                    laString_Destroy(&str);
                    
                    appData.event = APP_EVENT_NONE;
                    
                    resetFPS();
                    
                    break;
                }
                case APP_EVENT_IMAGE_TYPE_NEXT:
                {
                    appData.imgType = (appData.imgType < (APP_IMG_MAX_TYPE - 1)) ? 
                            appData.imgType + 1 : 0;
                    
                    //Update image type label
                    laLabelWidget_SetText(ImageTypeLabel, 
                        laString_CreateFromID(imageTypeNames[appData.imgType])); 

                    appData.event = APP_EVENT_NONE;
                    
                    resetFPS();
                    
                    break;
                }
                case APP_EVENT_IMAGE_TYPE_PREV:
                {
                    appData.imgType = (appData.imgType != 0) ? 
                            appData.imgType - 1 : (APP_IMG_MAX_TYPE - 1);
                    
                    //Update image type label
                    laLabelWidget_SetText(ImageTypeLabel,
                        laString_CreateFromID(imageTypeNames[appData.imgType])); 
                    
                    appData.event = APP_EVENT_NONE;
                    
                    resetFPS();
                    
                    break;
                }
                default:
                    break;
            }
            
            appData.imgIndex = (appData.imgIndex < (MAX_NUM_IMAGES - 1)) ?
                   (appData.imgIndex + 1) : 0;
            nextImage(ImageRenderWidget);
            
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