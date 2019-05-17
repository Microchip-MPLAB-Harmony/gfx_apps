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
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app_splash.h"
#include "gfx/hal/inc/gfx_context.h"
#include "gfx/libaria/inc/libaria_widget.h"
#include "gfx/libaria/libaria_init.h"

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
                laWidget_SetPosition((laWidget*)SplashBar, appSplashData.barPosX, SplashBar->widget.rect.y);            
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
            laWidget_SetPosition((laWidget*)SplashBar, appSplashData.barPosX, SplashBar->widget.rect.y);            
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
                laWidget_SetVisible((laWidget*) Pic32Logo, LA_FALSE);
                laLayer_SetAlphaAmount(context->activeScreen->layers[0], 255);
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
