/*******************************************************************************
  MPLAB Harmony Application Splash Screen Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    screen_Splash.c

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
Copyright (c) 2019 - 2020 released Microchip Technology Inc.  All rights reserved.

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

#include "gfx/legato/generated/le_gen_init.h"

#define DELAY_IN_TICKS       2
#define ALPHA_BLEND_DELTA   30

static uint32_t splashAlpha;
static uint32_t barPosX;
static uint32_t triggerTick;
static uint32_t currentTick;
static uint32_t delayCount;

static enum
{
    SCREEN_SETUP = 0,
    SCREEN_MOVE_BAR,
    SCREEN_SWAP_LOGO_ALPHA,
    SCREEN_SHOW_SMALL_ICON,
    SCREEN_END_DELAY,
    SCREEN_WAIT_FOR_NEXT,
    SCREEN_MOVE_TO_NEXT,
    SCREEN_NEXT,
    SCREEN_DONE
} screenState;

static void setup()
{
    SplashScreen_SplashBar->fn->setX(SplashScreen_SplashBar, barPosX);
                
    SplashScreen_SplashPic32Logo->fn->setAlphaEnabled(SplashScreen_SplashPic32Logo, LE_TRUE);
    SplashScreen_SplashPic32Logo->fn->setAlphaAmount(SplashScreen_SplashPic32Logo, splashAlpha);

    SplashScreen_SplashHarmonyLogo->fn->setAlphaEnabled(SplashScreen_SplashHarmonyLogo, LE_TRUE);
    SplashScreen_SplashHarmonyLogo->fn->setVisible(SplashScreen_SplashHarmonyLogo, LE_TRUE);
    SplashScreen_SplashHarmonyLogo->fn->setAlphaAmount(SplashScreen_SplashHarmonyLogo, 255 - splashAlpha);

    SplashScreen_SplashMicrochipLogo->fn->setVisible(SplashScreen_SplashMicrochipLogo, LE_FALSE);
    SplashScreen_SplashMicrochipLogo->fn->setAlphaEnabled(SplashScreen_SplashMicrochipLogo, LE_TRUE);
    SplashScreen_SplashMicrochipLogo->fn->setAlphaAmount(SplashScreen_SplashMicrochipLogo, 0);

    triggerTick = currentTick + DELAY_IN_TICKS;
    
    screenState = SCREEN_MOVE_BAR;
}

static void moveBar()
{
    currentTick++;
    
    if (triggerTick < currentTick)
    {
        triggerTick = currentTick + DELAY_IN_TICKS;
        barPosX = barPosX * 3 / 4;
    }

    if(barPosX <= 0)
    {
        triggerTick = currentTick + DELAY_IN_TICKS;
        barPosX = 0;
        
        screenState = SCREEN_SWAP_LOGO_ALPHA;
    }            

    SplashScreen_SplashBar->fn->setX(SplashScreen_SplashBar, barPosX);      
}

static void swapLogoAlpha()
{
    currentTick++;
    
    if (triggerTick < currentTick)
    {
        splashAlpha -= ALPHA_BLEND_DELTA;
        triggerTick = currentTick + DELAY_IN_TICKS;

        SplashScreen_SplashPic32Logo->fn->setAlphaAmount(SplashScreen_SplashPic32Logo, splashAlpha);
        SplashScreen_SplashHarmonyLogo->fn->setAlphaAmount(SplashScreen_SplashHarmonyLogo, 255 - splashAlpha);
    }

    /*switch(appSplashData.splashAlpha)
    {
        case 20:
            if(lastSet == 20)
                break;

            lastSet = 20;

            SplashScreen_SplashPic32Logo->fn->setImage(SplashScreen_SplashPic32Logo, &CrossFade3);
            break;
        case 40:
            if(lastSet == 40)
                break;

            lastSet = 40;
            SplashScreen_SplashPic32Logo->fn->setImage(SplashScreen_SplashPic32Logo, &CrossFade2);
            break;
        case 60:
            if(lastSet == 60)
                break;

            lastSet = 60;
            SplashScreen_SplashPic32Logo->fn->setImage(SplashScreen_SplashPic32Logo, &CrossFade1);
            break;
        case 80:
            if(lastSet == 80)
                break;

            lastSet = 80;
            SplashScreen_SplashPic32Logo->fn->setImage(SplashScreen_SplashPic32Logo, &CrossFade0);
            break;
        default:
            break;
    }*/

    if(splashAlpha <= ALPHA_BLEND_DELTA)
    {
        SplashScreen_SplashPic32Logo->fn->setVisible(SplashScreen_SplashPic32Logo, LE_FALSE);
        SplashScreen_SplashPic32Logo->fn->setAlphaEnabled(SplashScreen_SplashPic32Logo, LE_FALSE);

        SplashScreen_SplashHarmonyLogo->fn->setAlphaEnabled(SplashScreen_SplashHarmonyLogo, LE_FALSE);
        
        screenState = SCREEN_SHOW_SMALL_ICON;
    }
}

static void showSmallIcon()
{
    SplashScreen_SplashMicrochipLogo->fn->setVisible(SplashScreen_SplashMicrochipLogo, LE_TRUE);
    SplashScreen_SplashMicrochipLogo->fn->setAlphaEnabled(SplashScreen_SplashMicrochipLogo, LE_FALSE);
    
    delayCount = 0;
    
    screenState = SCREEN_END_DELAY;
}

static void endDelay()
{
    currentTick++;
    
    if(triggerTick < currentTick)
    {
        delayCount++;
        
        triggerTick = currentTick + DELAY_IN_TICKS;
    }

    if(delayCount > 50)
    {
        delayCount = 0;
        
        screenState = SCREEN_WAIT_FOR_NEXT;
    }
}

void SplashScreen_OnShow()
{
    splashAlpha = 255;        
    barPosX = 480;
    
    screenState = SCREEN_SETUP;
}

void SplashScreen_OnHide()
{
    
}

void SplashScreen_OnUpdate()
{
    switch (screenState)
    {
        case SCREEN_SETUP:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
               leEvent_GetCount() == 0)
            {
                setup();
            }
            
            break;
        }
        case SCREEN_MOVE_BAR:
        {
            moveBar();
            
            break;
        }
        case SCREEN_SWAP_LOGO_ALPHA:
        {
            swapLogoAlpha();
            
            break;                    
        }
        case SCREEN_SHOW_SMALL_ICON:
        {
            showSmallIcon();
            
            break;
        }
        case SCREEN_END_DELAY:
        {
            endDelay();
            
            break;                    
        }
        case SCREEN_WAIT_FOR_NEXT:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
               leEvent_GetCount() == 0)
            {
                screenState = SCREEN_MOVE_TO_NEXT;
            }

            break;
        }
        case SCREEN_MOVE_TO_NEXT:
        {
            legato_showScreen(screenID_MainMenu);

            screenState = SCREEN_DONE;

            break;
        }
        case SCREEN_DONE:
        default:
            break;
    }
}

/*******************************************************************************
 End of File
 */
