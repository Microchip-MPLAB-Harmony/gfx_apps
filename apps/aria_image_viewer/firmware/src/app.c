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

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "app_splash.h"
#include "gfx/driver/processor/2dgpu/libnano2D.h"
#include "gfx/driver/controller/glcd/plib_glcd.h"
#include "gfx/driver/controller/glcd/drv_gfx_glcd.h"
#include <sys/kmem.h>
#include <math.h>

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
/* This application makes use of 4 Hi-Res images defined by the following size */
#define IMAGE_WIDTH 1600
#define IMAGE_HEIGHT 1066

/*** GLCD Layer 0 Configuration ***/
#define  GFX_GLCD_LAYER0_BASEADDR                      0xA827D800
#define  GFX_GLCD_LAYER0_DBL_BASEADDR                  0xA81FE000
/*** GLCD Layer 1 Configuration ***/
#define  GFX_GLCD_LAYER1_BASEADDR                      0xA817E800
#define  GFX_GLCD_LAYER1_DBL_BASEADDR                  0xA80FF000
/*** GLCD Layer 2 Configuration ***/
#define  GFX_GLCD_LAYER2_BASEADDR                      0xA807F800
#define  GFX_GLCD_LAYER2_DBL_BASEADDR                  0xA8000000


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

/* image buffers and dimension */
static n2d_buffer_t layer0, src0, src1, src2, stage, alpha;
static n2d_buffer_t * src;
static n2d_rectangle_t rect0;
static int32_t width, height;
static int32_t left, top;

/* touch point zero */
static GFX_Point last0;
static GFX_Point delta0;
static GFX_Point curr0;
static laBool touch0_down;
    
/* touch point one */
static GFX_Point last1;
static GFX_Point delta1;
static GFX_Point curr1;
static laBool touch1_down;

/* pan, zoom, swipe */
static GFX_Point center;
static float scaleFactor;
static float curDist, lastDist;
static n2d_orientation_t orientation=N2D_0;
static int32_t scaleIndex, lastScaleIndex;  

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
/* Touch event callbacks */
static void App_GestureAreaDown(laWidget* widget, laInput_TouchDownEvent* evt);
static void App_GestureAreaUp(laWidget* widget, laInput_TouchUpEvent* evt);
static void App_GestureAreaMoved(laWidget* widget, laInput_TouchMovedEvent* evt);
static void App_HelpAreaDown(laWidget* widget, laInput_TouchDownEvent* evt);
static void App_HelpAreaUp(laWidget* widget, laInput_TouchUpEvent* evt);
static void App_HelpAreaMoved(laWidget* widget, laInput_TouchMovedEvent* evt);

/* TODO:  Add any necessary local functions.
*/

#define SYS_CLK_FREQ                        200000000ul

static void _appDelayMS ( unsigned int delayMs )
{
    if(delayMs)
    {
        uint32_t sysClk = SYS_CLK_FREQ;
        uint32_t t0;
        t0 = _CP0_GET_COUNT();
        while (_CP0_GET_COUNT() - t0 < (sysClk/2000)*delayMs);
    }
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

    /* set native screen dimensions */
    appData.display_info = GFX_ActiveContext()->display_info;
    
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
//                gfxContext = GFX_ActiveContext();
            }
            break;
        }

        case APP_STATE_SPLASH:
        {            
            if (APP_IsSplashScreenComplete())
            {
                appData.state = APP_STATE_IMAGE;
                laContext_SetActiveScreen(1);
            }
        
            break;
        }

        case APP_STATE_IMAGE:
        {                
            /* initialize image layer  */
            PLIB_GLCD_LayerGlobalAlphaSet(  0, 0xff );
            PLIB_GLCD_LayerDestBlendFuncSet( 0, GLCD_LAYER_DEST_BLEND_BLACK );
            PLIB_GLCD_LayerSrcBlendFuncSet( 0, GLCD_LAYER_SRC_BLEND_WHITE );
            PLIB_GLCD_LayerBaseAddressSet( 0, (uint32_t)GFX_GLCD_LAYER0_BASEADDR);

            /* initialize gui layer */
            PLIB_GLCD_LayerGlobalAlphaSet(  1, 0x00 );
            PLIB_GLCD_LayerDestBlendFuncSet( 1, GLCD_LAYER_DEST_BLEND_INV_SRC );
            PLIB_GLCD_LayerSrcBlendFuncSet( 1, GLCD_LAYER_SRC_BLEND_ALPHA_SRC );
            PLIB_GLCD_LayerBaseAddressSet( 1, (uint32_t)GFX_GLCD_LAYER1_BASEADDR);
                           
            /* initialize help layer */
            PLIB_GLCD_LayerGlobalAlphaSet(  2, 0xff );
            PLIB_GLCD_LayerDestBlendFuncSet( 2, GLCD_LAYER_DEST_BLEND_INV_GBL );
            PLIB_GLCD_LayerSrcBlendFuncSet( 2, GLCD_LAYER_SRC_BLEND_ALPHA_GBL );
            PLIB_GLCD_LayerBaseAddressSet( 2, (uint32_t)GFX_GLCD_LAYER2_BASEADDR);
            
            /* create GPU structures for GLCD layer 0 (dest) and scratch buffer (src) for image */
            layer0.format = N2D_RGBA8888;
            layer0.gpu = KVA_TO_PA(GFX_GLCD_LAYER0_BASEADDR);
            layer0.memory = (void*)GFX_GLCD_LAYER0_BASEADDR;
            layer0.width = appData.display_info->rect.width;
            layer0.height = appData.display_info->rect.height;
            layer0.orientation = orientation;
            layer0.stride = layer0.width * 32 / 8;

            src0.format = N2D_RGBA8888;
            src0.gpu = KVA_TO_PA(0xA9000400);
            src0.memory = (void*)0xA9000400;
            src0.width = IMAGE_WIDTH;
            src0.height = IMAGE_WIDTH;
            src0.orientation = orientation;
            src0.stride = src0.width * 32 / 8;

            src1.format = N2D_RGBA8888;
            src1.gpu = KVA_TO_PA(0xA82FD000);
            src1.memory = (void*)0xA82FD000;
            src1.width = IMAGE_WIDTH;
            src1.height = IMAGE_WIDTH;
            src1.orientation = orientation;
            src1.stride = src1.width * 32 / 8;
      
            src2.format = N2D_RGBA8888;
            src2.gpu = KVA_TO_PA(0xA897EA00);
            src2.memory = (void*)0xA897EA00;
            src2.width = IMAGE_WIDTH;
            src2.height = IMAGE_HEIGHT;
            src2.orientation = orientation;
            src2.stride = src2.width * 32 / 8;
            
            /* scratch buffer for rotation */
            stage.format = N2D_RGBA8888;
            stage.gpu = KVA_TO_PA(0xACFF1FA0);
            stage.memory = (void*)0xACFF1FA0;
            stage.width = appData.display_info->rect.width;
            stage.height = appData.display_info->rect.height;
            stage.orientation = orientation;
            stage.stride = stage.width * 32 / 8;
       
            /* alpha buffer for blending */
            alpha.format = N2D_A8;
            alpha.gpu = KVA_TO_PA(0xA978FE00);
            alpha.memory = (void*)0xA978FE00;
            alpha.width = appData.display_info->rect.width;
            alpha.height = appData.display_info->rect.height;
            alpha.orientation = orientation;
            alpha.stride = alpha.width * 8 / 8;
            
            /* show full image - no zoom */
            scaleIndex=0;
            lastScaleIndex = scaleIndex;
            scaleFactor = 1 - (float)scaleIndex/100;
            
            width = IMAGE_WIDTH*scaleFactor;
            height = IMAGE_HEIGHT*scaleFactor;
            left = IMAGE_WIDTH/2 - width/2;
            top = IMAGE_HEIGHT/2 - height/2;

            src = &src0;
            
            /* shrink image to size of native display resolution */
            rect0.x = left; rect0.y = top; rect0.width = width; rect0.height = height;
            n2d_blit(&layer0, N2D_NULL, src, &rect0, N2D_BLEND_NONE);

            center.x = IMAGE_WIDTH/2;
            center.y = IMAGE_HEIGHT/2;

            laWidget_OverrideTouchMovedEvent((laWidget*)ImageWidget, &App_GestureAreaMoved);
            laWidget_OverrideTouchDownEvent((laWidget*)ImageWidget, &App_GestureAreaDown);
            laWidget_OverrideTouchUpEvent((laWidget*)ImageWidget, &App_GestureAreaUp);
            
            laWidget_OverrideTouchMovedEvent((laWidget*)ImagePlusWidget2, &App_GestureAreaMoved);
            laWidget_OverrideTouchDownEvent((laWidget*)ImagePlusWidget2, &App_GestureAreaDown);
            laWidget_OverrideTouchUpEvent((laWidget*)ImagePlusWidget2, &App_GestureAreaUp); 
            
            laWidget_OverrideTouchMovedEvent((laWidget*)HelpArea, &App_HelpAreaMoved);
            laWidget_OverrideTouchDownEvent((laWidget*)HelpArea, &App_HelpAreaDown);
            laWidget_OverrideTouchUpEvent((laWidget*)HelpArea, &App_HelpAreaUp);
            
            /* fade out user gesture help display */
            int i;
            for ( i=255; i>0; i--)
            {            
                PLIB_GLCD_LayerGlobalAlphaSet( 2, i );
                _appDelayMS(10);
            }
            
            /* allow input events to pass through layer 2 */
            laScreen* scr = laContext_GetActiveScreen();
            laLayer_SetEnabled(scr->layers[2], LA_FALSE);
            
            appData.state = APP_STATE_RUNNING;

            break;
        }
                
        case APP_STATE_RUNNING:
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

static void App_GestureAreaDown(laWidget* widget, laInput_TouchDownEvent* evt)
{    
    /* retain last position */
    switch(evt->touchID)
    {
        case 0:
        {
            last0.x = curr0.x = evt->x;
            last0.y = curr0.y = evt->y;
            touch0_down = true;
            break;
        }
    
        case 1:
        {
            last1.x = curr1.x = evt->x;
            last1.y = curr1.y = evt->y;
            touch1_down = true;                      
            break;
        }
    }

    if ( touch0_down && touch1_down )
    {
        
        lastDist = (float)sqrt( (last0.x - last1.x)*(last0.x - last1.x) + 
                            (last0.y - last1.y)*(evt->y - last1.y) );
        
    }
    
    evt->event.accepted = LA_TRUE;
}

static void App_GestureAreaUp(laWidget* widget, laInput_TouchUpEvent* evt)
{        
    
    /* retain last position */
    switch(evt->touchID)
    {
        case 0:
        {            
            /* if single touch up with no second touch down - look for swipe or drag */
            if ( ! touch1_down )
            {              

                curDist = (float)abs(evt->x - last0.x) ; // (float)sqrt( (evt->x - last0.x)*(evt->x - last0.x) + 
                
                if  ( (last0.x < 50 || last0.x > 430) && curDist > 250 )
                {
                    int32_t direction = (evt->x > last0.x ? 0 : 1 );
                              
                    if ( src == &src0 )
                    {
                        if ( direction == 0)
                            src = &src1;
                        else
                            src = &src2;                           
                    }
                    else if ( src == &src1)
                    {
                        if ( direction == 0)
                            src = &src2;
                        else
                            src = &src0;
                    }
                    else if ( src == &src2)
                    {
                        if ( direction == 0)
                            src = &src0;
                        else
                            src = &src1;
                    }
                    else
                    {
                        if ( direction == 0)
                            src = &src0;
                        else
                            src = &src2;
                    }

                    /* set scale to 0 */
                    scaleIndex=0;
                    lastScaleIndex = scaleIndex;
                    scaleFactor = 1 - (float)scaleIndex/100;

                    /* set dimension of image to acquire */
                    width = IMAGE_WIDTH*scaleFactor;
                    height = IMAGE_HEIGHT*scaleFactor;
                    left = IMAGE_WIDTH/2 - width/2;
                    top = IMAGE_HEIGHT/2 - height/2;

                    /* shrink full image to size of native display resolution */                    
                    rect0.x = left; rect0.y = top; rect0.width = width; rect0.height = height;
                    n2d_blit(&layer0, N2D_NULL, src, &rect0, N2D_BLEND_NONE);

                    /* set center aspect */
                    center.x = IMAGE_WIDTH/2;
                    center.y = IMAGE_HEIGHT/2; 

                    evt->event.accepted = LA_TRUE;

                    /* bail out - no need to do anything else*/
                    return;
                }
                
                /* must be drag condition */
                else
                {
                    /* set left extent - check for original 0 and MAX IMAGE WIDTH */
                    left = left-delta0.x; 

                    /* set left extent - check for original 0 and MAX IMAGE HEIGHT */
                    top = top-delta0.y;

                    center.x -= delta0.x;
                    center.y -= delta0.y;


                    touch0_down = false;
                    
                    evt->event.accepted = LA_TRUE;

                    /* bail out - no need to do anything else*/
                    return;
                }
            }
            
            break;
        }
        
        case 1:
        {
            touch1_down = false;
            break;
        }
    }
    
    evt->event.accepted = LA_TRUE;
}

static void App_GestureAreaMoved(laWidget* widget, laInput_TouchMovedEvent* evt)
{    
    /* calculate current distance between touch points */
    switch(evt->touchID)
    {
        case 0:
        { 
            /* use distance formula to calculate distance of finger movement */
            delta0.x = evt->x - last0.x;
            delta0.y = evt->y - last0.y;    
            curr0.x = evt->x;
            curr0.y = evt->y;
            
            curDist = (float)sqrt( (evt->x - curr1.x)*(evt->x - curr1.x) + 
                (evt->y - curr1.y)*(evt->y - curr1.y) );
            
            break;
        }
        case 1:
        {
            delta1.x = evt->x - last1.x;
            delta1.y = evt->y - last1.y;
            curr1.x = evt->x;
            curr1.y = evt->y;
            
            curDist = (float)sqrt( (evt->x - curr0.x)*(evt->x - curr0.x) + 
                (evt->y - curr0.y)*(evt->y - curr0.y) );
                        
            break;
        }
    }
    
    // if multi-touch   ( pinch/zoom or orientation )        
    if ( touch0_down && touch1_down )
    {     
        
        if (lastScaleIndex + ( curDist - lastDist ) > 95 || lastScaleIndex + ( curDist - lastDist ) < 0)
        {
            evt->event.accepted = LA_TRUE;
            return;
        }

        if ( curDist > lastDist )
        {
            scaleIndex = lastScaleIndex + 1;//( curDist - lastDist );
        } 
        else
        {
            scaleIndex = lastScaleIndex - 1;
        }
        lastDist = curDist;

        scaleFactor = 1 - (float)scaleIndex/100;
        width = IMAGE_WIDTH*scaleFactor;
        height = IMAGE_HEIGHT*scaleFactor;
        left = center.x - width/2;
        if ( left < 0 ) left = 0;
        top = center.y - height/2;
        if ( top < 0 ) top = 0;

        /* calculate the rectangles */
        rect0.x = left; rect0.y = top; rect0.width = width; rect0.height = height;

        /* blit the new image rect to layer 0 */
        n2d_blit(&layer0, N2D_NULL, src, &rect0, N2D_BLEND_NONE);
        
        lastScaleIndex = scaleIndex;

        
    // if single touch ( swipe or move )
    } else 
    {   
        rect0.x = left - delta0.x;
        rect0.y = top - delta0.y;
        rect0.width = width;
        rect0.height = height;
        
        /* blit the new image rect to layer 0 */
        n2d_blit(&layer0, N2D_NULL, src, &rect0, N2D_BLEND_NONE);       
        
    }         
    
    evt->event.accepted = LA_TRUE;
}

void APP_OrientButtonRelease( void )
{
    switch ( orientation )
    {
        case 0:
            laButtonWidget_SetReleasedImage(ButtonWidget1, &iv_ninety);
            laButtonWidget_SetPressedImage(ButtonWidget1, &iv_ninety_pressed);
            orientation = N2D_90;
            break;
            
        case 1:
            laButtonWidget_SetReleasedImage(ButtonWidget1, &iv_oneEighty);
            laButtonWidget_SetPressedImage(ButtonWidget1, &iv_oneEighty_pressed);
            orientation = N2D_180;
            break;
            
        case 2:          
            laButtonWidget_SetReleasedImage(ButtonWidget1, &iv_twoSeventy);
            laButtonWidget_SetPressedImage(ButtonWidget1, &iv_twoSeventy_pressed);
            orientation = N2D_270;
            break;
            
        case 3:  
            laButtonWidget_SetReleasedImage(ButtonWidget1, &iv_zero);
            laButtonWidget_SetPressedImage(ButtonWidget1, &iv_zero_pressed);
            orientation = N2D_0;
            break;
    }
   
    layer0.orientation = orientation;
    rect0.x = left; rect0.y = top; rect0.width = width; rect0.height = height;
    n2d_blit(&layer0, N2D_NULL, src, &rect0, N2D_BLEND_NONE);
            
}

static void App_HelpAreaDown(laWidget* widget, laInput_TouchDownEvent* evt)
{    
    /* show help display */
    PLIB_GLCD_LayerGlobalAlphaSet(  2, 200 );

    /* allow input events to pass through layer 2 */
    laScreen* scr = laContext_GetActiveScreen();
    laLayer_SetEnabled(scr->layers[2], LA_TRUE);
    
    evt->event.accepted = LA_TRUE;
}

static void App_HelpAreaUp(laWidget* widget, laInput_TouchUpEvent* evt)
{
    /* fade out user gesture help display */
    int i;
    for ( i=200; i>0; i--)
    {            
        PLIB_GLCD_LayerGlobalAlphaSet( 2, i );
        _appDelayMS(5);
    }

    /* allow input events to pass through layer 2 */
    laScreen* scr = laContext_GetActiveScreen();
    laLayer_SetEnabled(scr->layers[2], LA_FALSE);
    
    evt->event.accepted = LA_TRUE;
}

static void App_HelpAreaMoved(laWidget* widget, laInput_TouchMovedEvent* evt)
{
    evt->event.accepted = LA_TRUE;
}

/*******************************************************************************
 End of File
 */
