/*******************************************************************************
  MPLAB Harmony Application SlideShow Screen Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    screen_SlideShow.c

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

#include "gfx/legato/generated/le_gen_init.h"
#include "system/time/sys_time.h"

#define SLIDESHOW_TIMER_PERIOD_FF_MS 500
#define SLIDESHOW_TIMER_PERIOD_PLAY_MS 2000

static enum
{
    EVENT_SLIDESHOW_SHOW_NEXT,
    EVENT_SLIDESHOW_SHOW_HELP,
    EVENT_SLIDESHOW_SHOW_MAIN,
    EVENT_SLIDESHOW_SHOW_DEMO,
    EVENT_SLIDESHOW_FF_START,
    EVENT_SLIDESHOW_FF_STOP,
    EVENT_SLIDESHOW_PLAY_START,
    EVENT_SLIDESHOW_PLAY_STOP,
    EVENT_SLIDESHOW_NEXT_IMG,
    EVENT_SLIDESHOW_PREV_IMG,
    EVENT_SLIDESHOW_NONE,
} slideShowScreenEvent;

static SYS_TIME_HANDLE handleTimer = SYS_TIME_HANDLE_INVALID;

static uint32_t eventScreenTable[] = 
{
    [EVENT_SLIDESHOW_SHOW_NEXT] = screenID_AlphaBlendingDemoScreen,
    [EVENT_SLIDESHOW_SHOW_HELP] = screenID_SlideshowHelpScreen,
    [EVENT_SLIDESHOW_SHOW_MAIN] = screenID_MainMenu,
    [EVENT_SLIDESHOW_SHOW_DEMO] = screenID_SlideShowDemoScreen,
};

static void Timer_Callback ( uintptr_t context)
{
    ImageSequenceWidget1->fn->showNextImage(ImageSequenceWidget1);
}

void SlideShowDemoScreen_OnShow(void)
{
    slideShowScreenEvent = EVENT_SLIDESHOW_NONE;
}

void SlideShowDemoScreen_OnHide(void)
{
    if (handleTimer != SYS_TIME_HANDLE_INVALID)
        SYS_TIME_TimerDestroy(handleTimer);
}

void SlideShowDemoScreen_OnUpdate(void)
{
    switch(slideShowScreenEvent)
    {
        case EVENT_SLIDESHOW_SHOW_NEXT:
        case EVENT_SLIDESHOW_SHOW_HELP:
        case EVENT_SLIDESHOW_SHOW_MAIN:
        case EVENT_SLIDESHOW_SHOW_DEMO:
            legato_showScreen(eventScreenTable[slideShowScreenEvent]);
            break;
        case EVENT_SLIDESHOW_FF_START:
        {
            SlideShowFFButton->fn->setPressed(SlideShowPlayButton, LE_FALSE);
        
            //Start Fast Forward show
            if (handleTimer != SYS_TIME_HANDLE_INVALID)
                SYS_TIME_TimerDestroy(handleTimer);

            handleTimer = SYS_TIME_CallbackRegisterMS(Timer_Callback, 1, SLIDESHOW_TIMER_PERIOD_FF_MS, SYS_TIME_PERIODIC);

            SSStatusImageWidget->fn->setImage(SSStatusImageWidget,&GFX_FF_Green_20x20);
            break;
        }
        case EVENT_SLIDESHOW_FF_STOP:
        {
            if (handleTimer != SYS_TIME_HANDLE_INVALID)
                SYS_TIME_TimerDestroy(handleTimer);
            
            handleTimer = SYS_TIME_HANDLE_INVALID;
            SSStatusImageWidget->fn->setImage(SSStatusImageWidget, &GFX_Pause_Pink_20x20);
            
            break;
        }
        case EVENT_SLIDESHOW_PLAY_START:
        {
            SlideShowFFButton->fn->setPressed(SlideShowFFButton, LE_FALSE);
        
            //Start Fast Forward show
            if (handleTimer != SYS_TIME_HANDLE_INVALID)
                SYS_TIME_TimerDestroy(handleTimer);

            handleTimer = SYS_TIME_CallbackRegisterMS(Timer_Callback, 1, SLIDESHOW_TIMER_PERIOD_PLAY_MS, SYS_TIME_PERIODIC);

            SSStatusImageWidget->fn->setImage(SSStatusImageWidget,&GFX_FF_Green_20x20);
            
            break;
        }
        case EVENT_SLIDESHOW_PLAY_STOP:
        {
            if (handleTimer != SYS_TIME_HANDLE_INVALID)
                SYS_TIME_TimerDestroy(handleTimer);
            
            handleTimer = SYS_TIME_HANDLE_INVALID;
            SSStatusImageWidget->fn->setImage(SSStatusImageWidget, &GFX_Pause_Pink_20x20);
            
            break;
        }
        case EVENT_SLIDESHOW_NEXT_IMG:
            ImageSequenceWidget1->fn->showNextImage(ImageSequenceWidget1);
            break;
        case EVENT_SLIDESHOW_PREV_IMG:
            ImageSequenceWidget1->fn->showPreviousImage(ImageSequenceWidget1);
            break;
        default:
            break;
    }
    
    slideShowScreenEvent = EVENT_SLIDESHOW_NONE;
}

void SlideshowHelpButton_OnReleased(leButtonWidget* btn)
{
    slideShowScreenEvent = EVENT_SLIDESHOW_SHOW_HELP;
}

void SlideShowHomeButton_OnReleased(leButtonWidget* btn)
{
    slideShowScreenEvent = EVENT_SLIDESHOW_SHOW_MAIN;
}

void SlideShowFFButton_OnPressed(leButtonWidget* btn)
{
    slideShowScreenEvent = EVENT_SLIDESHOW_FF_START;
}

void SlideShowFFButton_OnReleased(leButtonWidget* btn)
{
    slideShowScreenEvent = EVENT_SLIDESHOW_FF_STOP;
}

void SlideShowPlayButton_OnPressed(leButtonWidget* btn)
{
    slideShowScreenEvent = EVENT_SLIDESHOW_PLAY_START;
}

void SlideShowPlayButton_OnReleased(leButtonWidget* btn)
{
    slideShowScreenEvent = EVENT_SLIDESHOW_PLAY_STOP;
}

void SlideShowPrevButton_OnReleased(leButtonWidget* btn)
{
   slideShowScreenEvent = EVENT_SLIDESHOW_PREV_IMG; 
}

void SlideshowNextButton_OnReleased(leButtonWidget* btn)
{
    slideShowScreenEvent = EVENT_SLIDESHOW_NEXT_IMG; 
}

//Slide Show Help Events
void SlideshowHelpScreen_OnShow(void)
{
    slideShowScreenEvent = EVENT_SLIDESHOW_NONE;
}

void SlideshowHelpScreen_OnUpdate(void)
{
    if (slideShowScreenEvent == EVENT_SLIDESHOW_SHOW_MAIN)
    {
        legato_showScreen(eventScreenTable[slideShowScreenEvent]);
    }
    
    slideShowScreenEvent = EVENT_SLIDESHOW_NONE;
}

void SlideShowHelpCloseButton_OnReleased(leButtonWidget* btn)
{
    slideShowScreenEvent = EVENT_SLIDESHOW_SHOW_MAIN;
}