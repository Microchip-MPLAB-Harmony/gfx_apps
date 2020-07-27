/*******************************************************************************
  MPLAB Harmony Application Main Screen Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    screen_Main.c

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

#include "gfx/legato/generated/le_gen_init.h"

#include <stdio.h>
#include <string.h>

#include "system/time/sys_time.h"

#define APP_SPRITE_STEP_X  16
#define APP_SPRITE_OFFSET 8
#define APP_IDLE_SPRITE_DELAY 100
#define APP_JUMP_SPRITE_DELAY 0
#define APP_HURT_SPRITE_DELAY 10
#define APP_RUN_SPRITE_DELAY 0
#define APP_DIZZY_SPRITE_DELAY 40

int32_t spriteIndex = 0;
int32_t spritePosX = 0;
int32_t triggerCount = 0;
int32_t tickDelay = APP_IDLE_SPRITE_DELAY;

int32_t APP_SPRITE_ANCHOR_MIN = 0;
int32_t APP_SPRITE_ANCHOR_MAX = 0;

leImageSequenceWidget* Screen1_spriteWidgetToPlay;
leImageSequenceWidget* currentWidget;

SYS_TIME_HANDLE handleAnimation;
SYS_TIME_HANDLE handleLocomotion;

static enum
{
    SCREEN_INIT = 0,
    SCREEN_RUNNING,    
} screenState;

static enum
{
    FACE_RIGHT = 0,
    FACE_LEFT,
} spriteFacing;

static enum
{
    IDLE = 0,
    RUN,
    HURT,
    DIZZY,
    JUMP
} spriteState;

static void MainScreen_HandleLocomotion(uintptr_t context)
{
    if(spriteState != RUN)
    {
        return;
    }

    if(leGetRenderState()->frameState == LE_FRAME_READY &&
       leEvent_GetCount() == 0)
    {
        if (spriteFacing == FACE_RIGHT)
        {
            spritePosX += APP_SPRITE_STEP_X;
        }
        else if (spriteFacing == FACE_LEFT)
        {
            spritePosX -= APP_SPRITE_STEP_X;
        }

        spritePosX = leClampi(APP_SPRITE_ANCHOR_MIN, APP_SPRITE_ANCHOR_MAX, spritePosX);

        if (spritePosX >= APP_SPRITE_ANCHOR_MAX || spritePosX <= APP_SPRITE_ANCHOR_MIN)
        {
            spriteState = HURT;
            tickDelay = APP_HURT_SPRITE_DELAY;
            triggerCount = 0;
        }
    }
}

static void MainScreen_HandleAnimation(uintptr_t context)
{
    uint32_t offset = Screen1_PositionWidget->fn->getWidth(Screen1_PositionWidget) / 2;
    uint32_t Screen1_leftButtonWidth = Screen1_ButtonWidget_RunLeft->fn->getWidth(Screen1_ButtonWidget_RunLeft);
    
    if(leGetRenderState()->frameState == LE_FRAME_READY)
    {
        Screen1_PositionWidget->fn->setX(Screen1_PositionWidget, spritePosX);
        Screen1_ButtonWidget_RunLeft->fn->setX(Screen1_ButtonWidget_RunLeft, spritePosX + offset - Screen1_leftButtonWidth);
        Screen1_ButtonWidget_RunRight->fn->setX(Screen1_ButtonWidget_RunRight, spritePosX + offset);

        if (spriteState == IDLE)
        {
            if (spriteFacing == FACE_RIGHT)
            {
                Screen1_spriteWidgetToPlay = Screen1_ImageSequenceWidget_IdleRight;
            }
            else
            {
                Screen1_spriteWidgetToPlay = Screen1_ImageSequenceWidget_IdleLeft;
            }
        }
        else if (spriteState == RUN)
        {
            if (spriteFacing == FACE_RIGHT)
            {
                Screen1_spriteWidgetToPlay = Screen1_ImageSequenceWidget_RunRight;
            }
            else
            {
                Screen1_spriteWidgetToPlay = Screen1_ImageSequenceWidget_RunLeft;
            }
        }
        else if (spriteState == JUMP)
        {
            if (spriteFacing == FACE_RIGHT)
            {
                Screen1_spriteWidgetToPlay = Screen1_ImageSequenceWidget_JumpRight;
            }
            else
            {
                Screen1_spriteWidgetToPlay = Screen1_ImageSequenceWidget_JumpLeft;
            }
        }
        else if (spriteState == HURT)
        {
            if (spriteFacing == FACE_RIGHT)
            {
                Screen1_spriteWidgetToPlay = Screen1_ImageSequenceWidget_HurtRight;
            }
            else
            {
                Screen1_spriteWidgetToPlay = Screen1_ImageSequenceWidget_HurtLeft;
            }
        }
        else if (spriteState == DIZZY)
        {
            if (spriteFacing == FACE_RIGHT)
            {
                Screen1_spriteWidgetToPlay = Screen1_ImageSequenceWidget_DizzieRight;
            }
            else
            {
                Screen1_spriteWidgetToPlay = Screen1_ImageSequenceWidget_DizzieLeft;
            }
        }
        
        if (triggerCount-- > 0)
        {
            return;
        }
        else
        {
            //Renew tick count
            triggerCount = tickDelay;
        }
        
        if (currentWidget != Screen1_spriteWidgetToPlay)
        {
            currentWidget->fn->setVisible(currentWidget, LE_FALSE);
            currentWidget->fn->stop(currentWidget);
            currentWidget->fn->rewind(currentWidget);
            
            currentWidget = Screen1_spriteWidgetToPlay;
            currentWidget->fn->setVisible(currentWidget, LE_TRUE);
            spriteIndex = 0;
        }
        
        currentWidget->fn->showNextImage(currentWidget);
        spriteIndex++;
            
        if (spriteIndex >= currentWidget->fn->getImageCount(currentWidget))
        {
            spriteIndex = 0;
            
            if (spriteState == HURT)
            {
                spriteState = DIZZY;
                tickDelay = APP_DIZZY_SPRITE_DELAY;
            }
            else if (spriteState == JUMP)
            {
                spriteState = IDLE;
                tickDelay = APP_IDLE_SPRITE_DELAY;
            }
            else if (spriteState == DIZZY)
            {
                spriteState = IDLE;
                tickDelay = APP_IDLE_SPRITE_DELAY;
                
                if (spritePosX <= APP_SPRITE_ANCHOR_MIN)
                {
                    spritePosX = APP_SPRITE_ANCHOR_MIN + 1;
                }
                else if (spritePosX >= APP_SPRITE_ANCHOR_MAX)
                {
                    spritePosX = APP_SPRITE_ANCHOR_MAX - 1;
                }
            }
            
            triggerCount = 0;
        }        
    }
}

void Screen1_OnShow()
{
    screenState = SCREEN_INIT;
    spriteState = IDLE;
    spriteFacing = FACE_RIGHT;
    spriteIndex = 0;
}

void Screen1_OnHide()
{
    SYS_TIME_TimerDestroy(handleAnimation);
    SYS_TIME_TimerDestroy(handleLocomotion);
}

void Screen1_OnUpdate()
{
    switch (screenState)
    {
        case SCREEN_INIT:
        {
            if(leGetRenderState()->frameState == LE_FRAME_READY &&
               leEvent_GetCount() == 0)
            {
                spritePosX = Screen1_PositionWidget->fn->getX(Screen1_PositionWidget);
                spriteState = IDLE;
                spriteFacing = FACE_RIGHT;
                tickDelay = APP_IDLE_SPRITE_DELAY;
                triggerCount = 0;

                Screen1_spriteWidgetToPlay = Screen1_ImageSequenceWidget_IdleRight;
                currentWidget = Screen1_spriteWidgetToPlay;
                
                APP_SPRITE_ANCHOR_MAX = Screen1_PanelBackground->fn->getWidth(Screen1_PanelBackground) 
                        - Screen1_ImageSequenceWidget_IdleRight->fn->getWidth(Screen1_ImageSequenceWidget_IdleRight)
                        + APP_SPRITE_OFFSET;

                APP_SPRITE_ANCHOR_MIN = 0 - APP_SPRITE_OFFSET;

                handleAnimation = SYS_TIME_CallbackRegisterMS(MainScreen_HandleAnimation, 0, 10, SYS_TIME_PERIODIC);
                handleLocomotion = SYS_TIME_CallbackRegisterMS(MainScreen_HandleLocomotion, 0, 2, SYS_TIME_PERIODIC);
                
                screenState = SCREEN_RUNNING;
            }
            
            break;
        }
        case SCREEN_RUNNING:
        default:
            break;
    }
}

void event_Screen1_ButtonWidget_RunRight_OnPressed(leButtonWidget *btn)
{
    if (spriteState == RUN && spriteFacing == FACE_RIGHT)
    {      
    }
    else
    {
        spriteFacing = FACE_RIGHT;
        spriteState = RUN;

        tickDelay = APP_RUN_SPRITE_DELAY;
        triggerCount = 0;
    }
}

void event_Screen1_ButtonWidget_RunRight_OnReleased(leButtonWidget *btn)
{
}

void event_Screen1_ButtonWidget_RunLeft_OnPressed(leButtonWidget *btn)
{
    if (spriteState == RUN && spriteFacing == FACE_LEFT)
    {      
    }
    else
    {
        spriteFacing = FACE_LEFT;
        spriteState = RUN;

        tickDelay = APP_RUN_SPRITE_DELAY;
        triggerCount = 0;
    }
}

void event_Screen1_ButtonWidget_RunLeft_OnReleased(leButtonWidget *btn)
{
}

void event_Screen1_ButtonWidget_Jump_OnPressed(leButtonWidget *btn)
{
    if (spriteState != JUMP && spriteState != DIZZY)
    {
        spriteState = JUMP;

        tickDelay = APP_JUMP_SPRITE_DELAY;
        triggerCount = 0;
    }
}

void event_Screen1_ButtonWidget_Jump_OnReleased(leButtonWidget *btn)
{
}

/*******************************************************************************
 End of File
 */
