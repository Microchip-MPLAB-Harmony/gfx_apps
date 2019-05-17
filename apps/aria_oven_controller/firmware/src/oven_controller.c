/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    oven_controller.c

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

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2017 released Microchip Technology Inc.  All rights reserved.

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
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "oven_controller.h"
#include "gfx/driver/controller/glcd/plib_glcd.h"
#include "gfx/driver/controller/glcd/drv_gfx_glcd.h"
#include <sys/kmem.h>
#include <math.h>

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define BUFFER_PER_LAYER	1
#define DISPLAY_WIDTH       480
#define DISPLAY_HEIGHT      272

static SYS_TIME_HANDLE actionTimer;
static n2d_buffer_t layer0, stage;
static GFX_PixelBuffer stagePixelBuffer;
static bool barVisible=false;
static int bakeTime=0;

static laCircularGaugeWidget * timerWidget;

extern uint16_t __attribute__((coherent, aligned(32))) framebuffer_0[BUFFER_PER_LAYER][DISPLAY_WIDTH * DISPLAY_HEIGHT];
uint16_t __attribute__((coherent, aligned(32))) stageBuffer[BUFFER_PER_LAYER][DISPLAY_WIDTH * DISPLAY_HEIGHT];

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

static void actionTimer_Callback ( uintptr_t context )
{ 
    n2d_rectangle_t src;
    static int i=0;
    
    switch (appData.event)
    {
        case APP_EVENT_SHRINK_OVEN_LOGO:
        {
            src.x = 0; src.y = 0; src.width = 190; src.height = 87;
            appData.action.current.width--; appData.action.current.height--;
            n2d_blit(&layer0, &appData.action.current, &stage, &src, N2D_BLEND_NONE); 
            if ( appData.action.current.width == appData.action.end.width )
            {
                appData.event = APP_EVENT_SHOW_MENU1;
                i=30;
            }
            break;
        }
        
        case APP_EVENT_SHOW_MENU1:
        {
            // show fish button
            src.x = 201; src.y = 0; src.width = 92; src.height = 92;

            appData.action.current.x = 90+i; appData.action.current.y = 80+i;
            appData.action.current.width = 92-i; appData.action.current.height = 92-i;
            n2d_blit(&layer0, &appData.action.current, &stage, &src, N2D_BLEND_NONE); 
            if ( i-- == 0) 
            {
                appData.event = APP_EVENT_SHOW_MENU2;
                i=30;
            }
            break;
        }
        
        case APP_EVENT_SHOW_MENU2:
        {                
            // show pizza button
            src.x = 294; src.y = 0; src.width = 92; src.height = 92;

            appData.action.current.x = 194+i; appData.action.current.y = 80+i;
            appData.action.current.width = 92-i; appData.action.current.height = 92-i;
            n2d_blit(&layer0, &appData.action.current, &stage, &src, N2D_BLEND_NONE);
            if ( i-- == 0) 
            {
                appData.event = APP_EVENT_SHOW_MENU3;
                i=30;
            }
            break;
        }
                
        case APP_EVENT_SHOW_MENU3:
        { 
            // show vegetable button
            src.x = 386; src.y = 0; src.width = 92; src.height = 92;

            appData.action.current.x = 298+i; appData.action.current.y = 80+i;
            appData.action.current.width = 92-i; appData.action.current.height = 92-i;
            n2d_blit(&layer0, &appData.action.current, &stage, &src, N2D_BLEND_NONE); 
            if ( i-- == 0) 
            {
                SYS_TIME_TimerDestroy(actionTimer);
                appData.event = APP_EVENT_SHRINK_OVEN_LOGO;
            }
            break;
        }
                    
        case APP_EVENT_ANIMATE_SMOKE_START:
        {
            laCircularGaugeWidget_SetValue(timerWidget, --bakeTime);
            laImageSequenceWidget_ShowNextImage(Flames);
            if ( bakeTime < 0 )
            {
                appData.event = APP_EVENT_ANIMATE_SMOKE_STOP;
            }
            
            break;
        }        
        case APP_EVENT_ANIMATE_SMOKE_STOP:
        { 
            appData.event = APP_EVENT_SHRINK_OVEN_LOGO;
            laWidget_SetVisible((laWidget* )DoneButton, true);
            laWidget_SetVisible((laWidget* )Flames, false);
            SYS_TIME_TimerDestroy(actionTimer);
            break;
        }               
        default:
            { break; }
    }
}

void APP_AnimateHomeScreen()
{
    appData.event = APP_EVENT_SHRINK_OVEN_LOGO;
}

void APP_AnimateControllerScreen()
{
    /* fade out user gesture help display */
    appData.action.start.x = 0; appData.action.start.y = 0; appData.action.start.width = 190; appData.action.start.height = 87;
    appData.action.current = appData.action.start;
    appData.action.end.x = 0; appData.action.end.y = 0; appData.action.end.width = 160; appData.action.end.height = 57;
    appData.action.shrinkStep = 1;

    SYS_TIME_TimerDestroy(actionTimer);
    actionTimer = SYS_TIME_CallbackRegisterMS(
                        actionTimer_Callback,
                        0, 10, 
                        SYS_TIME_PERIODIC);
                    
    // showInfoScreen - Show Screen - infoScreen
    laContext_SetActiveScreen(controllerScreen_ID);
    laWidget_SetVisible((laWidget* )StartStopButton, false);
    appData.event = APP_EVENT_SHRINK_OVEN_LOGO;
}

void APP_OnFishButtonRelease()
{
    n2d_rectangle_t rect;

    // show bar
    if ( barVisible == false )
    { 
        barVisible = true;
    // slide bar    
    } 
    else
    {
        n2d_fill(&layer0, &appData.action.last, 0x00, N2D_BLEND_NONE);
        laWidget_SetVisible((laWidget* )DoneButton, false);
        laButtonWidget_SetPressed(StartStopButton, false);
    }
    rect.x = 0; rect.y = 93; rect.width = 88; rect.height = 8;
    appData.action.current.x = 102; appData.action.current.y = 70;
    appData.action.current.width = 68; appData.action.current.height = 8;
    n2d_blit(&layer0, &appData.action.current, &stage, &rect, N2D_BLEND_NONE); 
    appData.action.last = appData.action.current;
    
    laWidget_SetVisible((laWidget* )StartStopButton, true);

    laWidget_SetVisible((laWidget* )PizzaGaugeWidget, false);
    laWidget_SetVisible((laWidget* )TurkeyGaugeWidget, false);
    laWidget_SetVisible((laWidget* )FishGaugeWidget, true);
    laCircularGaugeWidget_SetValue(FishGaugeWidget, 120);
    timerWidget = FishGaugeWidget;
    bakeTime=120;
}

void APP_OnPizzaButtonRelease()
{

    n2d_rectangle_t src;
    
    // show bar
    if ( barVisible == false )
    {
        barVisible = true;
    // slide bar    
    } else
    {
        n2d_fill(&layer0, &appData.action.last, 0x00, N2D_BLEND_NONE); 
        laWidget_SetVisible((laWidget* )DoneButton, false);
        laButtonWidget_SetPressed(StartStopButton, false);
    }
    src.x = 0; src.y = 93; src.width = 88; src.height = 8;
    appData.action.current.x = 205; appData.action.current.y = 70;
    appData.action.current.width = 68; appData.action.current.height = 8;
    n2d_blit(&layer0, &appData.action.current, &stage, &src, N2D_BLEND_NONE); 
    appData.action.last = appData.action.current;
    
    laWidget_SetVisible((laWidget* )StartStopButton, true);
    
    laWidget_SetVisible((laWidget* )PizzaGaugeWidget, true);
    laWidget_SetVisible((laWidget* )TurkeyGaugeWidget, false);
    laWidget_SetVisible((laWidget* )FishGaugeWidget, false);
    laCircularGaugeWidget_SetValue(PizzaGaugeWidget, 86);
    timerWidget = PizzaGaugeWidget;

    bakeTime=86;
}

void APP_OnVegeButtonRelease()
{
    n2d_rectangle_t src;

    // show bar
    if ( barVisible == false )
    {
        barVisible = true; 
    // slide bar    
    } else
    {
        n2d_fill(&layer0, &appData.action.last, 0x00, N2D_BLEND_NONE);
        laWidget_SetVisible((laWidget* )DoneButton, false);
        laButtonWidget_SetPressed(StartStopButton, false);
    }
    src.x = 0; src.y = 93; src.width = 88; src.height = 8;
    appData.action.current.x = 310; appData.action.current.y = 70;
    appData.action.current.width = 68; appData.action.current.height = 8;
    n2d_blit(&layer0, &appData.action.current, &stage, &src, N2D_BLEND_NONE); 
    appData.action.last = appData.action.current;
    laWidget_SetVisible((laWidget* )StartStopButton, true);
    
    laWidget_SetVisible((laWidget* )PizzaGaugeWidget, false);
    laWidget_SetVisible((laWidget* )TurkeyGaugeWidget, true);
    laWidget_SetVisible((laWidget* )FishGaugeWidget, false);
    laCircularGaugeWidget_SetValue(TurkeyGaugeWidget, 160);
    timerWidget = TurkeyGaugeWidget; 
    bakeTime=160;
}
        
void APP_OnStartButtonToggled( void )
{
    if ( laButtonWidget_GetPressed(StartStopButton) == true )
    {
        SYS_TIME_TimerDestroy(actionTimer);
        actionTimer = SYS_TIME_CallbackRegisterMS(
                        actionTimer_Callback,
                        1, 50, 
                        SYS_TIME_PERIODIC);
        appData.event = APP_EVENT_ANIMATE_SMOKE_START;
        laWidget_SetVisible((laWidget* )Flames, true);
    } else
    {
        appData.event = APP_EVENT_ANIMATE_SMOKE_STOP;
    }
}

void APP_OnButtonDoneReleased( void )
{
    laButtonWidget_SetPressed(StartStopButton, false);
    laWidget_SetVisible((laWidget* )DoneButton, false);
    laWidget_SetVisible((laWidget* )StartStopButton, false);
    n2d_fill(&layer0, &appData.action.last, 0x00, N2D_BLEND_NONE); 
    
    laWidget_SetVisible((laWidget* )PizzaGaugeWidget, false);
    laWidget_SetVisible((laWidget* )TurkeyGaugeWidget, false);
    laWidget_SetVisible((laWidget* )FishGaugeWidget, false);
}

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

void OvenController_Tasks ( void )
{
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void OvenController_Initialize ( void )
{ 
    /* create Nano2D GPU attributes for GLCD layer 0  - display refresh layer  */
    layer0.format = N2D_RGB565;
    layer0.gpu = KVA_TO_PA(framebuffer_0);
    layer0.memory = (void*)framebuffer_0;
    layer0.width = appData.display_info->rect.width;
    layer0.height = appData.display_info->rect.height;
    layer0.orientation = N2D_0;
    layer0.stride = layer0.width * 16 / 8;

    /* create Nano2D GPU attributes for image blitting  - source for all bliting */
    stage.format = N2D_RGB565;
    stage.gpu = KVA_TO_PA(stageBuffer);
    stage.memory = (void*)stageBuffer;
    stage.width = appData.display_info->rect.width;
    stage.height = appData.display_info->rect.height;
    stage.orientation = N2D_0;
    stage.stride = stage.width * 16 / 8;

    GFX_PixelBufferCreate(appData.display_info->rect.width,
      appData.display_info->rect.height,
      GFX_COLOR_MODE_RGB_565,
      (uint32_t*)stage.memory,
      &stagePixelBuffer);

    /* render all images for blitting to stage buffer */
    GFX_Begin();
        GFX_Set(GFXF_DRAW_TARGET, &stagePixelBuffer);                
        GFXU_DrawImage(&brickovenlogo1,
               0,
               0,
               190,
               87,
               0,
               0,
               NULL,
               NULL);
        
        GFXU_DrawImage(&menufish,
               0,
               0,
               92,
               92,
               201,
               0,
               NULL,
               NULL);
        
        GFXU_DrawImage(&menuPizza,
               0,
               0,
               92,
               92,
               294,
               0,
               NULL,
               NULL);
        
        GFXU_DrawImage(&menuTurkey,
               0,
               0,
               92,
               92,
               386,
               0,
               NULL,
               NULL);
        
        GFXU_DrawImage(&orangeBar,
               0,
               0,
               88,
               8,
               0,
               93,
               NULL,
               NULL);

        GFX_Set(GFXF_DRAW_TARGET, NULL);
    GFX_End();

}

void APP_ControllerScreenProcessEvents(void)
{
//    // nothing to do
//    if ( appData.event == APP_EVENT_ANIMATE_SMOKE_START )
//    {
//        laCircularGaugeWidget_SetValue(timerWidget, --bakeTime);
//        if ( bakeTime < 0 )
//        {
//            appData.event = APP_EVENT_ANIMATE_SMOKE_STOP;
//            laImageSequenceWidget_Stop(Flames);
//        }
//    }
}
/*******************************************************************************
 End of File
 */
