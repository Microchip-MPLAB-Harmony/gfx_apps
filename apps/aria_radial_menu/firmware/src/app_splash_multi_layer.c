/*******************************************************************************
  MPLAB Harmony Application Splash Screen Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app_splash.c

  Summary:
    This file contains the source code for the demo splash screen.

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

#include "app_splash.h"
#include "gfx/hal/inc/gfx_context.h"
#include "gfx/libaria/libaria_init.h"
#include "gfx/libaria/inc/libaria_context.h"

#define DELAY_IN_TICKS       2000000
#define GET_TICKS() __builtin_mfc0(9, 0)

// *****************************************************************************
/* Application Splash Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

APP_SPLASH_DATA appSplashData;

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

bool APP_IsSplashScreenComplete(void)
{    
    laContext* context = laContext_GetActive();
    uint32_t currentTick = 0;
    static uint32_t tiggerTick = 0;
    
    currentTick = GET_TICKS();
    
    /* Check the application's current state. */
    switch ( appSplashData.state )
    {
        /* Application's initial state. */
        case APP_STATE_SPLASH_INIT:
        {
            laContext_SetActiveScreen(0);
            
            appSplashData.splashAlpha = 255;        
            appSplashData.barPosX = GFX_ActiveContext()->display_info->rect.width;      
               
            appSplashData.state = APP_STATE_SPLASH_1;            
            break;
        }

        case APP_STATE_SPLASH_1:
        {            
            //Check that the screen is the initial screen 
            //and that it has been rendered
            if (context->activeScreen->id == 0 
                    && context->activeScreen->layers[2]->widget.drawState == LA_WIDGET_DRAW_STATE_DONE)
            {
                appSplashData.state = APP_STATE_SPLASH_2;
                laWidget_SetPosition((laWidget*)ImageWidget3, appSplashData.barPosX, ImageWidget3->widget.rect.y);            
                tiggerTick = currentTick + DELAY_IN_TICKS;
            }
        
            break;
        }

        case APP_STATE_SPLASH_2:
        {
            if (tiggerTick < currentTick)
            {
                tiggerTick = currentTick + DELAY_IN_TICKS;
                appSplashData.splashAlpha -= appSplashData.splashAlpha / 9;
                appSplashData.barPosX = appSplashData.barPosX * 3 / 4;
            }
            
            if (appSplashData.splashAlpha <= 10 && appSplashData.barPosX <= 0)
            {
                tiggerTick = currentTick + DELAY_IN_TICKS;
                appSplashData.state = APP_STATE_SPLASH_3;
                appSplashData.splashAlpha = 0;
                appSplashData.barPosX = 0;
            }            

            laLayer_SetAlphaAmount(context->activeScreen->layers[0], appSplashData.splashAlpha);
            laWidget_SetPosition((laWidget*)ImageWidget3, appSplashData.barPosX, ImageWidget3->widget.rect.y);            
            break;
        }
        
        case APP_STATE_SPLASH_3:
        {
            if (tiggerTick < currentTick)
            {
                appSplashData.splashAlpha += 4;
                tiggerTick = currentTick + DELAY_IN_TICKS;
            }

            if (appSplashData.splashAlpha >= 255)
            {
                appSplashData.state = APP_STATE_SPLASH_4;
                appSplashData.splashAlpha = 255;
            }

            laLayer_SetAlphaAmount(context->activeScreen->layers[2], appSplashData.splashAlpha);
            break;
        }
        
        case APP_STATE_SPLASH_4:
        {
            if (tiggerTick < currentTick)
            {
                appSplashData.splashAlpha -= appSplashData.splashAlpha / 10;
                tiggerTick = currentTick + DELAY_IN_TICKS;
            }

            laLayer_SetAlphaAmount(context->activeScreen->layers[1], appSplashData.splashAlpha);
            laLayer_SetAlphaAmount(context->activeScreen->layers[2], appSplashData.splashAlpha);

            if (appSplashData.splashAlpha <= 10)
            {
                //Reset the splash screen            
                laLayer_SetAlphaAmount(context->activeScreen->layers[1], 0);
                laLayer_SetAlphaAmount(context->activeScreen->layers[2], 0);

                appSplashData.state = APP_STATE_SPLASH_DONE;
            }
            break;
        }

        case APP_STATE_SPLASH_DONE:
        {
            static uint32_t count = 0;
            
            if (tiggerTick < currentTick)
            {
                count++;
                tiggerTick = currentTick + DELAY_IN_TICKS;
            }
            
            if (count > 50)
            {
                count = 0;
                appSplashData.state = APP_STATE_SPLASH_INIT;
                return true;
            }
            break;
        }
    }
    
    return false;
}

 

/*******************************************************************************
 End of File
 */
