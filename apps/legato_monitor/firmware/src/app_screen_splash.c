/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_screen_default.c

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

#include "definitions.h"

#include <stdio.h>
#include <string.h>

#include "system/time/sys_time.h"

#define TIMER_DELAY_VALUE_MS     40
#define MAX_ALPHA 255

static SYS_TIME_HANDLE tickUpdateTimer;
static uint32_t lastTick;
static volatile uint32_t currentTick;
static int32_t barX;

typedef enum
{
    APP_SPLASH_STATE_INIT,
    APP_SPLASH_STATE_ANIMATION,
    APP_SPLASH_STATE_ANIMATION_COMPLETE,
} APP_SPLASH_STATES;

APP_SPLASH_STATES appSplashState;

static void tickUpdateTimer_Callback()
{
    currentTick++;
}

void Splash_OnShow()
{
    currentTick = lastTick = 0;
    
    tickUpdateTimer = SYS_TIME_CallbackRegisterMS(tickUpdateTimer_Callback, 
                                                  1,
                                                  TIMER_DELAY_VALUE_MS,
                                                  SYS_TIME_PERIODIC);
    
    barX = Splash_BarImageWidget->fn->getX(Splash_BarImageWidget);
        
    appSplashState = APP_SPLASH_STATE_INIT;
}

void Splash_OnHide()
{
}

void Splash_OnUpdate()
{
    switch(appSplashState)
    {
        case APP_SPLASH_STATE_INIT:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
                leEvent_GetCount() == 0)
            {
                appSplashState = APP_SPLASH_STATE_ANIMATION;
            }            
            
            break;
        }
        case APP_SPLASH_STATE_ANIMATION:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
                leEvent_GetCount() == 0)
            {
                if (currentTick > lastTick)
                {
                    if (barX/4 > 0)
                    {
                        barX -= barX/4;
                        Splash_BarImageWidget->fn->setX(Splash_BarImageWidget, barX);
                    }
                    else
                    {
                        Splash_BarImageWidget->fn->setX(Splash_BarImageWidget, 0);
                        Splash_MicrochipLogoImageWidget->fn->setVisible(Splash_MicrochipLogoImageWidget, LE_TRUE);
                        appSplashState = APP_SPLASH_STATE_ANIMATION_COMPLETE;
                    }

                    lastTick = currentTick;
                }
                else if (lastTick > currentTick)
                {
                    lastTick = currentTick;
                }
            }
            break;
        }
        case APP_SPLASH_STATE_ANIMATION_COMPLETE:
        default:
        {
            if (currentTick > lastTick &&
                currentTick - lastTick >= 1000/TIMER_DELAY_VALUE_MS)
            {
                legato_showScreen(screenID_default);
            }
            else if (lastTick > currentTick)
            {
                lastTick = currentTick;
            }
            
            break;
        }
    }
}
