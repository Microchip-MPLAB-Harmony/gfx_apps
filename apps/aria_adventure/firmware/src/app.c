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
Software only when embedded on a Microchip microcontroller or Digital signal
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
#include "gfx/libaria/inc/libaria_utils.h"
#include "gfx/libaria/libaria_init.h"
// TODO: Placeholder until audio support reintroduced
//#include "sound_effects/run_sound.h"
//#include "sound_effects/blaze_sound.h"
//#include "sound_effects/hurt_sound.h"
//#include "sound_effects/dizzy_sound.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

#define APP_SPRITE_TIMER_DELAY 2
#define APP_RUN_SPRITE_DELAY 5  //This has to be greater than APP_SPEED_FACTOR_LIMIT 
#define APP_BLAZE_SPRITE_DELAY 5 //This has to be greater than APP_SPEED_FACTOR_LIMIT 
#define APP_IDLE_SPRITE_DELAY 480 
#define APP_HURT_SPRITE_DELAY 1  
#define APP_FALL_SPRITE_DELAY 5  
#define APP_DIZZY_SPRITE_DELAY 300
#define APP_SPRITE_STEP_X APP_LAYER_MOVE_FACTOR2 / 2
#define APP_PRESS_COUNTER_DELAY 800
#define APP_UI_LAYER_MAX_ALPHA 155
#define APP_LAMB_STAMINA 1000
#define APP_LAMB_BLAZE_ZONE 300
#define APP_LAMB_FATIGUE_LIMIT 100
#define APP_SCORE_MAX_COUNT 999999
#define APP_SCORE_RUN_INCREMENT 1
#define APP_SCORE_BLAZE_INCREMENT 2

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

int32_t miny = 0;
int32_t maxy = 0;

int32_t APP_SPRITE_ANCHOR_INIT = 0;
int32_t APP_SPRITE_ANCHOR_LEFT_LIMIT = 0;
int32_t APP_SPRITE_ANCHOR_RIGHT_LIMIT = 0;

int32_t APP_LAYER_MOVE_FACTOR0 = 1;
int32_t APP_LAYER_MOVE_FACTOR1 = 2;
int32_t APP_LAYER_MOVE_FACTOR2 = 4;
int32_t APP_BLAZE_SPEED_FACTOR_LIMIT = 6;
int32_t APP_SPEED_FACTOR_LIMIT = 3;

// TODO: Placeholder until audio support is reintroduced
//static uint32_t run_sound_size = 0;
//static uint32_t blaze_sound_size = 0;
//static uint32_t hurt_sound_size = 0;
//static uint32_t dizzy_sound_size = 0;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
static void touchDown(laWidget* widget, laInput_TouchDownEvent* evt)
{
	evt->event.accepted = LA_TRUE;
}

static void touchUp(laWidget* widget, laInput_TouchUpEvent* evt)
{
	evt->event.accepted = LA_TRUE;
}

static void touchMovedUpDown(laWidget* widget, laInput_TouchMovedEvent* evt)
{
	int32_t dy;

	dy = evt->y - evt->prevY;

	dy *= 3;
	dy /= 2;

	if (InfoTextDragPanel->rect.y + dy < miny)
	{
		laWidget_SetPosition((laWidget*)InfoTextDragPanel, InfoTextDragPanel->rect.x, miny);
	}
	else if (InfoTextDragPanel->rect.y + dy > maxy)
	{
		laWidget_SetPosition((laWidget*)InfoTextDragPanel, InfoTextDragPanel->rect.x, maxy);
	}
	else
	{
		laWidget_Translate((laWidget*)InfoTextDragPanel, 0, dy);
	}

	evt->event.accepted = LA_TRUE;
}

laResult APP_IsReadyForPreprocess(laContextPreprocessAssetsState state)
{
    laContextFrameState frameState = laContext_GetActive()->frameState;

    switch(state)
    {
        case LA_CONTEXT_PREPROCESS_ASSETS_PENDING:
        {
            // Do not continue to trigger any redraw if any layer hasn't been completely drawn
            if (frameState != LA_CONTEXT_FRAME_READY)
                return LA_FAILURE;
            
//            appData.uiLayerAlpha = 0;
//
//            laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[1], appData.uiLayerAlpha);
//            laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[2], appData.uiLayerAlpha);

            break;
        }
        case LA_CONTEXT_PREPROCESS_ASSETS_DONE:
        {
//            appData.uiLayerAlpha = 255;
//            laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[1], appData.uiLayerAlpha);

            appData.state = APP_STATE_SPLASH;
            break;
        }
        default:
            break;
    }


    return LA_SUCCESS;
}

static void playSoundEffect()
{
    switch(appData.spriteState)
    {
        
        case SPRITE_RUN:
// TODO: Placeholder for when audio support is added back
//            DRV_CODEC_BufferAddWrite(appData.codecClient.handle, 
//                        &(appData.codecClient.bufHandle),
//                        (void*)RUN_SOUND_EFFECT, run_sound_size);
            break;
        case SPRITE_BLAZE:
// TODO: Placeholder for when audio support is added back
//            DRV_CODEC_BufferAddWrite(appData.codecClient.handle, 
//                                    &(appData.codecClient.bufHandle),
//                                    (void*)BLAZE_SOUND_EFFECT, blaze_sound_size);
            break;
        case SPRITE_HURT:
// TODO: Placeholder for when audio support is added back
//            DRV_CODEC_BufferAddWrite(appData.codecClient.handle, 
//                        &(appData.codecClient.bufHandle),
//                        (void*)HURT_SOUND_EFFECT, hurt_sound_size);
            break;
        case SPRITE_FALL:
// TODO: Placeholder for when audio support is added back
//            DRV_CODEC_BufferAddWrite(appData.codecClient.handle, 
//                        &(appData.codecClient.bufHandle),
//                        (void*)HURT_SOUND_EFFECT, hurt_sound_size);
            break;
        case SPRITE_DIZZY:
// TODO: Placeholder for when audio support is added back
//            DRV_CODEC_BufferAddWrite(appData.codecClient.handle, 
//                        &(appData.codecClient.bufHandle),
//                        (void*)DIZZY_SOUND_EFFECT, dizzy_sound_size);
            break;
        case SPRITE_IDLE:
        default:
            break;
    }
                
}

// TODO: Placeholder for when audio support is added back
//static void audioCodecBufferWriteEventHandler(DRV_CODEC_BUFFER_EVENT event,
//        DRV_CODEC_BUFFER_HANDLE handle, uintptr_t context )
//{
//    switch(event)
//    {
//        case DRV_CODEC_BUFFER_EVENT_COMPLETE:
//        {
//            
//        }
//        
//        break;
//        case DRV_CODEC_BUFFER_EVENT_ERROR:
//        {
//            Nop();
//        } break;
//
//        case DRV_CODEC_BUFFER_EVENT_ABORT:
//        {
//            Nop();
//        } break;
//
//    }
//}

void APP_SetScoreScheme(laScheme* scheme)
{
    laWidget_SetScheme((laWidget*)Digit0, scheme);
    laWidget_SetScheme((laWidget*)Digit1, scheme);
    laWidget_SetScheme((laWidget*)Digit2, scheme);
    laWidget_SetScheme((laWidget*)Digit3, scheme);
    laWidget_SetScheme((laWidget*)Digit4, scheme);
    laWidget_SetScheme((laWidget*)Digit5, scheme);
}

void APP_SetScore(uint32_t score, bool topScore)
{
    if (score > APP_SCORE_MAX_COUNT)
    {
        score = APP_SCORE_MAX_COUNT;
        return;
    }

    uint32_t scoreMod = score % 10;
    uint32_t scoreMod10 = (score / 10) % 10;
    uint32_t scoreMod100 = (score / 100) % 10;
    uint32_t scoreMod1000 = (score / 1000) % 10;
    uint32_t scoreMod10000 = (score / 10000) % 10;
    uint32_t scoreMod100000 = (score / 100000) % 10;    
    
    switch (scoreMod)
    {
        case 0:
            if (topScore)
                laLabelWidget_SetText(TopDigit0, laString_CreateFromID(string_Zero));                            
            else
                laLabelWidget_SetText(Digit0, laString_CreateFromID(string_Zero));            
            break;
        case 1:
            if (topScore)
                laLabelWidget_SetText(TopDigit0, laString_CreateFromID(string_One));                            
            else
                laLabelWidget_SetText(Digit0, laString_CreateFromID(string_One));            
            break;
        case 2:
            if (topScore)
                laLabelWidget_SetText(TopDigit0, laString_CreateFromID(string_Two));                            
            else
                laLabelWidget_SetText(Digit0, laString_CreateFromID(string_Two));            
            break;
        case 3:
            if (topScore)
                laLabelWidget_SetText(TopDigit0, laString_CreateFromID(string_Three));                            
            else
                laLabelWidget_SetText(Digit0, laString_CreateFromID(string_Three));            
            break;
        case 4:
            if (topScore)
                laLabelWidget_SetText(TopDigit0, laString_CreateFromID(string_Four));                            
            else
                laLabelWidget_SetText(Digit0, laString_CreateFromID(string_Four));            
            break;
        case 5:
            if (topScore)
                laLabelWidget_SetText(TopDigit0, laString_CreateFromID(string_Five));                            
            else
                laLabelWidget_SetText(Digit0, laString_CreateFromID(string_Five));            
            break;
        case 6:
            if (topScore)
                laLabelWidget_SetText(TopDigit0, laString_CreateFromID(string_Six));                            
            else
                laLabelWidget_SetText(Digit0, laString_CreateFromID(string_Six));            
            break;
        case 7:
            if (topScore)
                laLabelWidget_SetText(TopDigit0, laString_CreateFromID(string_Seven));                            
            else
                laLabelWidget_SetText(Digit0, laString_CreateFromID(string_Seven));            
            break;
        case 8:
            if (topScore)
                laLabelWidget_SetText(TopDigit0, laString_CreateFromID(string_Eight));                            
            else
                laLabelWidget_SetText(Digit0, laString_CreateFromID(string_Eight));            
            break;
        case 9:
            if (topScore)
                laLabelWidget_SetText(TopDigit0, laString_CreateFromID(string_Nine));                            
            else
                laLabelWidget_SetText(Digit0, laString_CreateFromID(string_Nine));            
            break;
        default:
            break;
    }

    switch (scoreMod10)
    {
        case 0:
            if (topScore)
                laLabelWidget_SetText(TopDigit1, laString_CreateFromID(string_Zero));                            
            else
                laLabelWidget_SetText(Digit1, laString_CreateFromID(string_Zero));            
            break;
        case 1:
            if (topScore)
                laLabelWidget_SetText(TopDigit1, laString_CreateFromID(string_One));                            
            else
                laLabelWidget_SetText(Digit1, laString_CreateFromID(string_One));            
            break;
        case 2:
            if (topScore)
                laLabelWidget_SetText(TopDigit1, laString_CreateFromID(string_Two));                            
            else
                laLabelWidget_SetText(Digit1, laString_CreateFromID(string_Two));            
            break;
        case 3:
            if (topScore)
                laLabelWidget_SetText(TopDigit1, laString_CreateFromID(string_Three));                            
            else
                laLabelWidget_SetText(Digit1, laString_CreateFromID(string_Three));            
            break;
        case 4:
            if (topScore)
                laLabelWidget_SetText(TopDigit1, laString_CreateFromID(string_Four));                            
            else
                laLabelWidget_SetText(Digit1, laString_CreateFromID(string_Four));            
            break;
        case 5:
            if (topScore)
                laLabelWidget_SetText(TopDigit1, laString_CreateFromID(string_Five));                            
            else
                laLabelWidget_SetText(Digit1, laString_CreateFromID(string_Five));            
            break;
        case 6:
            if (topScore)
                laLabelWidget_SetText(TopDigit1, laString_CreateFromID(string_Six));                            
            else
                laLabelWidget_SetText(Digit1, laString_CreateFromID(string_Six));            
            break;
        case 7:
            if (topScore)
                laLabelWidget_SetText(TopDigit1, laString_CreateFromID(string_Seven));                            
            else
                laLabelWidget_SetText(Digit1, laString_CreateFromID(string_Seven));            
            break;
        case 8:
            if (topScore)
                laLabelWidget_SetText(TopDigit1, laString_CreateFromID(string_Eight));                            
            else
                laLabelWidget_SetText(Digit1, laString_CreateFromID(string_Eight));            
            break;
        case 9:
            if (topScore)
                laLabelWidget_SetText(TopDigit1, laString_CreateFromID(string_Nine));                            
            else
                laLabelWidget_SetText(Digit1, laString_CreateFromID(string_Nine));            
            break;
        default:
            break;
    }

    switch (scoreMod100)
    {
        case 0:
            if (topScore)
                laLabelWidget_SetText(TopDigit2, laString_CreateFromID(string_Zero));                            
            else
                laLabelWidget_SetText(Digit2, laString_CreateFromID(string_Zero));            
            break;
        case 1:
            if (topScore)
                laLabelWidget_SetText(TopDigit2, laString_CreateFromID(string_One));                            
            else
                laLabelWidget_SetText(Digit2, laString_CreateFromID(string_One));            
            break;
        case 2:
            if (topScore)
                laLabelWidget_SetText(TopDigit2, laString_CreateFromID(string_Two));                            
            else
                laLabelWidget_SetText(Digit2, laString_CreateFromID(string_Two));            
            break;
        case 3:
            if (topScore)
                laLabelWidget_SetText(TopDigit2, laString_CreateFromID(string_Three));                            
            else
                laLabelWidget_SetText(Digit2, laString_CreateFromID(string_Three));            
            break;
        case 4:
            if (topScore)
                laLabelWidget_SetText(TopDigit2, laString_CreateFromID(string_Four));                            
            else
                laLabelWidget_SetText(Digit2, laString_CreateFromID(string_Four));            
            break;
        case 5:
            if (topScore)
                laLabelWidget_SetText(TopDigit2, laString_CreateFromID(string_Five));                            
            else
                laLabelWidget_SetText(Digit2, laString_CreateFromID(string_Five));            
            break;
        case 6:
            if (topScore)
                laLabelWidget_SetText(TopDigit2, laString_CreateFromID(string_Six));                            
            else
                laLabelWidget_SetText(Digit2, laString_CreateFromID(string_Six));            
            break;
        case 7:
            if (topScore)
                laLabelWidget_SetText(TopDigit2, laString_CreateFromID(string_Seven));                            
            else
                laLabelWidget_SetText(Digit2, laString_CreateFromID(string_Seven));            
            break;
        case 8:
            if (topScore)
                laLabelWidget_SetText(TopDigit2, laString_CreateFromID(string_Eight));                            
            else
                laLabelWidget_SetText(Digit2, laString_CreateFromID(string_Eight));            
            break;
        case 9:
            if (topScore)
                laLabelWidget_SetText(TopDigit2, laString_CreateFromID(string_Nine));                            
            else
                laLabelWidget_SetText(Digit2, laString_CreateFromID(string_Nine));            
            break;
        default:
            break;
    }

    switch (scoreMod1000)
    {
        case 0:
            if (topScore)
                laLabelWidget_SetText(TopDigit3, laString_CreateFromID(string_Zero));                            
            else
                laLabelWidget_SetText(Digit3, laString_CreateFromID(string_Zero));            
            break;
        case 1:
            if (topScore)
                laLabelWidget_SetText(TopDigit3, laString_CreateFromID(string_One));                            
            else
                laLabelWidget_SetText(Digit3, laString_CreateFromID(string_One));            
            break;
        case 2:
            if (topScore)
                laLabelWidget_SetText(TopDigit3, laString_CreateFromID(string_Two));                            
            else
                laLabelWidget_SetText(Digit3, laString_CreateFromID(string_Two));            
            break;
        case 3:
            if (topScore)
                laLabelWidget_SetText(TopDigit3, laString_CreateFromID(string_Three));                            
            else
                laLabelWidget_SetText(Digit3, laString_CreateFromID(string_Three));            
            break;
        case 4:
            if (topScore)
                laLabelWidget_SetText(TopDigit3, laString_CreateFromID(string_Four));                            
            else
                laLabelWidget_SetText(Digit3, laString_CreateFromID(string_Four));            
            break;
        case 5:
            if (topScore)
                laLabelWidget_SetText(TopDigit3, laString_CreateFromID(string_Five));                            
            else
                laLabelWidget_SetText(Digit3, laString_CreateFromID(string_Five));            
            break;
        case 6:
            if (topScore)
                laLabelWidget_SetText(TopDigit3, laString_CreateFromID(string_Six));                            
            else
                laLabelWidget_SetText(Digit3, laString_CreateFromID(string_Six));            
            break;
        case 7:
            if (topScore)
                laLabelWidget_SetText(TopDigit3, laString_CreateFromID(string_Seven));                            
            else
                laLabelWidget_SetText(Digit3, laString_CreateFromID(string_Seven));            
            break;
        case 8:
            if (topScore)
                laLabelWidget_SetText(TopDigit3, laString_CreateFromID(string_Eight));                            
            else
                laLabelWidget_SetText(Digit3, laString_CreateFromID(string_Eight));            
            break;
        case 9:
            if (topScore)
                laLabelWidget_SetText(TopDigit3, laString_CreateFromID(string_Nine));                            
            else
                laLabelWidget_SetText(Digit3, laString_CreateFromID(string_Nine));            
            break;
        default:
            break;
    }

    switch (scoreMod10000)
    {
        case 0:
            if (topScore)
                laLabelWidget_SetText(TopDigit4, laString_CreateFromID(string_Zero));                            
            else
                laLabelWidget_SetText(Digit4, laString_CreateFromID(string_Zero));            
            break;
        case 1:
            if (topScore)
                laLabelWidget_SetText(TopDigit4, laString_CreateFromID(string_One));                            
            else
                laLabelWidget_SetText(Digit4, laString_CreateFromID(string_One));            
            break;
        case 2:
            if (topScore)
                laLabelWidget_SetText(TopDigit4, laString_CreateFromID(string_Two));                            
            else
                laLabelWidget_SetText(Digit4, laString_CreateFromID(string_Two));            
            break;
        case 3:
            if (topScore)
                laLabelWidget_SetText(TopDigit4, laString_CreateFromID(string_Three));                            
            else
                laLabelWidget_SetText(Digit4, laString_CreateFromID(string_Three));            
            break;
        case 4:
            if (topScore)
                laLabelWidget_SetText(TopDigit4, laString_CreateFromID(string_Four));                            
            else
                laLabelWidget_SetText(Digit4, laString_CreateFromID(string_Four));            
            break;
        case 5:
            if (topScore)
                laLabelWidget_SetText(TopDigit4, laString_CreateFromID(string_Five));                            
            else
                laLabelWidget_SetText(Digit4, laString_CreateFromID(string_Five));            
            break;
        case 6:
            if (topScore)
                laLabelWidget_SetText(TopDigit4, laString_CreateFromID(string_Six));                            
            else
                laLabelWidget_SetText(Digit4, laString_CreateFromID(string_Six));            
            break;
        case 7:
            if (topScore)
                laLabelWidget_SetText(TopDigit4, laString_CreateFromID(string_Seven));                            
            else
                laLabelWidget_SetText(Digit4, laString_CreateFromID(string_Seven));            
            break;
        case 8:
            if (topScore)
                laLabelWidget_SetText(TopDigit4, laString_CreateFromID(string_Eight));                            
            else
                laLabelWidget_SetText(Digit4, laString_CreateFromID(string_Eight));            
            break;
        case 9:
            if (topScore)
                laLabelWidget_SetText(TopDigit4, laString_CreateFromID(string_Nine));                            
            else
                laLabelWidget_SetText(Digit4, laString_CreateFromID(string_Nine));            
            break;
        default:
            break;
    }

    switch (scoreMod100000)
    {
        case 0:
            if (topScore)
                laLabelWidget_SetText(TopDigit5, laString_CreateFromID(string_Zero));                            
            else
                laLabelWidget_SetText(Digit5, laString_CreateFromID(string_Zero));            
            break;
        case 1:
            if (topScore)
                laLabelWidget_SetText(TopDigit5, laString_CreateFromID(string_One));                            
            else
                laLabelWidget_SetText(Digit5, laString_CreateFromID(string_One));            
            break;
        case 2:
            if (topScore)
                laLabelWidget_SetText(TopDigit5, laString_CreateFromID(string_Two));                            
            else
                laLabelWidget_SetText(Digit5, laString_CreateFromID(string_Two));            
            break;
        case 3:
            if (topScore)
                laLabelWidget_SetText(TopDigit5, laString_CreateFromID(string_Three));                            
            else
                laLabelWidget_SetText(Digit5, laString_CreateFromID(string_Three));            
            break;
        case 4:
            if (topScore)
                laLabelWidget_SetText(TopDigit5, laString_CreateFromID(string_Four));                            
            else
                laLabelWidget_SetText(Digit5, laString_CreateFromID(string_Four));            
            break;
        case 5:
            if (topScore)
                laLabelWidget_SetText(TopDigit5, laString_CreateFromID(string_Five));                            
            else
                laLabelWidget_SetText(Digit5, laString_CreateFromID(string_Five));            
            break;
        case 6:
            if (topScore)
                laLabelWidget_SetText(TopDigit5, laString_CreateFromID(string_Six));                            
            else
                laLabelWidget_SetText(Digit5, laString_CreateFromID(string_Six));            
            break;
        case 7:
            if (topScore)
                laLabelWidget_SetText(TopDigit5, laString_CreateFromID(string_Seven));                            
            else
                laLabelWidget_SetText(Digit5, laString_CreateFromID(string_Seven));            
            break;
        case 8:
            if (topScore)
                laLabelWidget_SetText(TopDigit5, laString_CreateFromID(string_Eight));                            
            else
                laLabelWidget_SetText(Digit5, laString_CreateFromID(string_Eight));            
            break;
        case 9:
            if (topScore)
                laLabelWidget_SetText(TopDigit5, laString_CreateFromID(string_Nine));                            
            else
                laLabelWidget_SetText(Digit5, laString_CreateFromID(string_Nine));            
            break;
        default:
            break;
    }
}


void APP_HideAllSequences(void)
{
    laWidget_SetVisible((laWidget*)RunLeftSequence, LA_FALSE);
    laImageSequenceWidget_Stop(RunLeftSequence);
    
    laWidget_SetVisible((laWidget*)RunRightSequence, LA_FALSE);
    laImageSequenceWidget_Stop(RunRightSequence);

    laWidget_SetVisible((laWidget*)IdleLeftSequence, LA_FALSE);
    laImageSequenceWidget_Stop(IdleLeftSequence);

    laWidget_SetVisible((laWidget*)IdleRightSequence, LA_FALSE);
    laImageSequenceWidget_Stop(IdleRightSequence);

    laWidget_SetVisible((laWidget*)BlazeLeftSequence, LA_FALSE);
    laImageSequenceWidget_Stop(BlazeLeftSequence);
    
    laWidget_SetVisible((laWidget*)BlazeRightSequence, LA_FALSE);
    laImageSequenceWidget_Stop(BlazeRightSequence);
    
    laWidget_SetVisible((laWidget*)DizzySequence, LA_FALSE);
    laImageSequenceWidget_Stop(DizzySequence);
    
    laWidget_SetVisible((laWidget*)DizzyLeftSequence, LA_FALSE);
    laImageSequenceWidget_Stop(DizzyLeftSequence);
    
    laWidget_SetVisible((laWidget*)FallSequence, LA_FALSE);
    laImageSequenceWidget_Stop(FallSequence);
    
    laWidget_SetVisible((laWidget*)FallLeftSequence, LA_FALSE);
    laImageSequenceWidget_Stop(FallLeftSequence);

    laWidget_SetVisible((laWidget*)HurtSequence, LA_FALSE);
    laImageSequenceWidget_Stop(HurtSequence);
    
    laWidget_SetVisible((laWidget*)HurtLeftSequence, LA_FALSE);
    laImageSequenceWidget_Stop(HurtLeftSequence);
}

void APP_PressCounter_CallBack ( uintptr_t context )
{
    if (appData.requestedDirection != USER_REQUESTED_STOP            
            && ((appData.requestedDirection == USER_REQUESTED_GO_RIGHT
                && appData.spriteFacingDirection == FACING_RIGHT)
                ||(appData.requestedDirection == USER_REQUESTED_GO_LEFT
                && appData.spriteFacingDirection == FACING_LEFT))) 
    {
        appData.speedFactor += 1;        
    }
    else
    {
        appData.speedFactor -= 1;
    }
    
    appData.speedFactor = GFX_Clampi(1, APP_SPEED_FACTOR_LIMIT, appData.speedFactor);
}

void APP_SpriteSequence_CallBack( uintptr_t context )
{
    if (laContext_GetActiveScreen() && 
        laContext_GetActiveScreen()->id != MainScreen_ID)
         return;
    
    laWidget_SetVisible((laWidget*)appData.currentSequence, LA_TRUE);

    if(appData.spriteTriggerCount-- <= 0)
    {
        switch(appData.spriteState)
        {
            case SPRITE_IDLE:
                appData.spriteTriggerCount = APP_IDLE_SPRITE_DELAY;
                break;
            case SPRITE_BLAZE:
                appData.spriteTriggerCount = APP_BLAZE_SPRITE_DELAY;
                break;
            case SPRITE_RUN:
                appData.spriteTriggerCount = (int32_t)APP_RUN_SPRITE_DELAY - (int32_t)appData.speedFactor;
                break;
            case SPRITE_HURT:
                if (appData.spriteFrameLeft > 1)
                {
                    appData.spriteFrameLeft--;
                }
                else
                {
                    appData.spriteFrameLeft = 0;
                }
                appData.spriteTriggerCount = APP_HURT_SPRITE_DELAY;
                break;
            case SPRITE_FALL:
                if (appData.spriteFrameLeft > 1)
                {
                    appData.spriteFrameLeft--;
                }
                else
                {
                    appData.spriteFrameLeft = 0;
                }
                appData.spriteTriggerCount = APP_FALL_SPRITE_DELAY;
                break;
            case SPRITE_DIZZY:
                if (appData.spriteFrameLeft > 1)
                {
                    appData.spriteFrameLeft--;
                    appData.spriteTriggerCount = APP_DIZZY_SPRITE_DELAY;
                }
                else
                {
                    appData.currentScore = 0;
                    appData.spriteState = SPRITE_IDLE;
                    appData.spriteFrameLeft = 0;
                    APP_SetScore(appData.currentScore, false);
                    appData.spriteTriggerCount = 0;
                }
                break;                
            default:
                appData.spriteTriggerCount = APP_IDLE_SPRITE_DELAY;
                break;            
        }
        
        laImageSequenceWidget_ShowNextImage(appData.currentSequence);
    }

    if (appData.spriteState != SPRITE_HURT
            && appData.spriteState != SPRITE_DIZZY
            && appData.spriteState != SPRITE_FALL
            && appData.spriteStamina <= APP_LAMB_FATIGUE_LIMIT
            && appData.isEasterEggMode == false)
    {
        appData.spriteState = SPRITE_HURT;
        appData.spriteFrameLeft = 100;
    }
    else
    {
        if (appData.requestedDirection == USER_REQUESTED_STOP 
                || appData.spriteState == SPRITE_IDLE
                || appData.spriteState == SPRITE_DIZZY
                || appData.spriteState == SPRITE_FALL)
        {
            appData.spriteStamina += 1;
            
            if (appData.spriteState == SPRITE_BLAZE && appData.spriteStamina > APP_LAMB_BLAZE_ZONE)
            {
                appData.speedFactor = APP_SPEED_FACTOR_LIMIT;
            }
        }
        else if (appData.spriteTriggerCount % 6 == 0)
        {
            if (appData.spriteState == SPRITE_RUN)
            {
                appData.spriteStamina -= 2;
                appData.currentScore += APP_SCORE_RUN_INCREMENT; 

                if (appData.spriteStamina < APP_LAMB_BLAZE_ZONE)
                {
                    appData.spriteStamina = APP_LAMB_BLAZE_ZONE;
                }
            }
            else if (appData.spriteState == SPRITE_BLAZE)
            {
                appData.spriteStamina -= 3;       
                appData.currentScore += APP_SCORE_BLAZE_INCREMENT;                
            }        

            APP_SetScore(appData.currentScore, false);
            if (appData.currentScore > appData.topScore)
            {
                appData.topScore = appData.currentScore;
                APP_SetScore(appData.topScore, true);            
            }
        }
        
        if (appData.spriteState == SPRITE_BLAZE)
        {
            APP_SetScoreScheme(&yellowScheme);                
        }
        else if (appData.spriteState == SPRITE_RUN)
        {
            APP_SetScoreScheme(&greenScheme);                
        }
        else
        {
            APP_SetScoreScheme(&defaultScheme);
        }
        
        appData.spriteStamina = GFX_Clampi(0, APP_LAMB_STAMINA, appData.spriteStamina);
        
        uint32_t percent = GFX_PercentWholeRounded((uint32_t)appData.spriteStamina, APP_LAMB_STAMINA);
        laCircularGaugeWidget_SetValue(CircularGaugeWidget, (int32_t)percent);        
    }        
}

void APP_Right(void)
{
    if (appData.spriteState == SPRITE_DIZZY 
            || appData.spriteState == SPRITE_FALL
            || appData.spriteState == SPRITE_HURT)
    {
        appData.requestedDirection = USER_REQUESTED_STOP;
        return;
    }
    
    appData.requestedDirection = USER_REQUESTED_GO_RIGHT;
    
    if (appData.spriteFacingDirection == FACING_LEFT)
    {
        appData.speedFactor = 1;        
    }
}

void APP_Left(void)
{
    if (appData.spriteState == SPRITE_DIZZY 
            || appData.spriteState == SPRITE_FALL
            || appData.spriteState == SPRITE_HURT)
    {
        appData.requestedDirection = USER_REQUESTED_STOP;
        return;
    }
    
    appData.requestedDirection = USER_REQUESTED_GO_LEFT;

    if (appData.spriteFacingDirection == FACING_RIGHT)
    {
        appData.speedFactor = 1;        
    }
}

void APP_Stop(void)
{
    appData.uiLayerAlpha = APP_UI_LAYER_MAX_ALPHA;
    appData.lastRequestedDirection = appData.requestedDirection;
    appData.requestedDirection = USER_REQUESTED_STOP;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************
void APP_PrepareLayers(void)
{
    appData.backgroundLayerWidth = laContext_GetActiveScreen()->layers[0]->widget.rect.width;
    appData.backgroundLayerHeight = laContext_GetActiveScreen()->layers[0]->widget.rect.height;

    appData.middleLayerWidth = laContext_GetActiveScreen()->layers[1]->widget.rect.width;
    appData.middleLayerHeight = laContext_GetActiveScreen()->layers[1]->widget.rect.height;

    appData.foregroundLayerWidth = laContext_GetActiveScreen()->layers[2]->widget.rect.width;
    appData.foregroundLayerHeight = laContext_GetActiveScreen()->layers[2]->widget.rect.height;

    appData.layerLimit0 = -1 * BackLayer.width;
    appData.layerLimit1 = -1 * MiddleLayer.width;
    appData.layerLimit2 = -1 * FrontLayer.width;  
    
    APP_SPRITE_ANCHOR_LEFT_LIMIT = appData.middleLayerWidth / 25;
    APP_SPRITE_ANCHOR_RIGHT_LIMIT = appData.middleLayerWidth - APP_SPRITE_ANCHOR_LEFT_LIMIT - SpriteAnchor->rect.width;
    APP_SPRITE_ANCHOR_INIT = appData.middleLayerWidth / 32 * 10;  
    
    if (appData.backgroundLayerWidth > 480)
    {
        APP_SPEED_FACTOR_LIMIT = 4;
        APP_LAYER_MOVE_FACTOR0 = 2;
        APP_LAYER_MOVE_FACTOR1 = 4;
        APP_LAYER_MOVE_FACTOR2 = 8;
        APP_BLAZE_SPEED_FACTOR_LIMIT = 20;
    }
}

void APP_HandleSpriteAnimation(void)
{
    if (appData.spriteState != SPRITE_HURT 
            && appData.spriteState != SPRITE_DIZZY  
            && appData.spriteState != SPRITE_FALL)
    {
        if (appData.requestedDirection == USER_REQUESTED_GO_RIGHT)
        {
            if (appData.spriteStamina <= APP_LAMB_BLAZE_ZONE
                    && appData.speedFactor >= APP_SPEED_FACTOR_LIMIT)
            {
                if (laImageSequenceWidget_IsPlaying(BlazeRightSequence) == LA_FALSE)
                {
                    APP_HideAllSequences();

                    laImageSequenceWidget_Play(BlazeRightSequence);
                    appData.currentSequence = BlazeRightSequence;
                    laImageSequenceWidget_ShowNextImage(appData.currentSequence);
                    appData.speedFactor = APP_BLAZE_SPEED_FACTOR_LIMIT;
                    appData.spriteTriggerCount = APP_BLAZE_SPRITE_DELAY;
                    appData.spriteState = SPRITE_BLAZE;
                }                                    
            }
            else
            {
                if (laImageSequenceWidget_IsPlaying(RunRightSequence) == LA_FALSE)
                {
                    APP_HideAllSequences();

                    laImageSequenceWidget_Play(RunRightSequence);
                    appData.currentSequence = RunRightSequence;
                    laImageSequenceWidget_ShowNextImage(appData.currentSequence);
                    appData.spriteTriggerCount = (int32_t)APP_RUN_SPRITE_DELAY - (int32_t)appData.speedFactor;
                    appData.spriteState = SPRITE_RUN;
                }                    
            }
        }
        else if (appData.requestedDirection == USER_REQUESTED_GO_LEFT)
        {
            if (appData.spriteStamina <= APP_LAMB_BLAZE_ZONE
                    && appData.speedFactor >= APP_SPEED_FACTOR_LIMIT)
            {
                if (laImageSequenceWidget_IsPlaying(BlazeLeftSequence) == LA_FALSE)
                {
                    APP_HideAllSequences();

                    laImageSequenceWidget_Play(BlazeLeftSequence);
                    appData.currentSequence = BlazeLeftSequence;
                    laImageSequenceWidget_ShowNextImage(appData.currentSequence);
                    appData.speedFactor = APP_BLAZE_SPEED_FACTOR_LIMIT;
                    appData.spriteTriggerCount = APP_BLAZE_SPRITE_DELAY;
                    appData.spriteState = SPRITE_BLAZE;
                }                                    
            }
            else
            {
                if (laImageSequenceWidget_IsPlaying(RunLeftSequence) == LA_FALSE)
                {
                    APP_HideAllSequences();

                    laImageSequenceWidget_Play(RunLeftSequence);
                    appData.currentSequence = RunLeftSequence;
                    laImageSequenceWidget_ShowNextImage(appData.currentSequence);
                    appData.spriteTriggerCount = (int32_t)APP_RUN_SPRITE_DELAY - (int32_t)appData.speedFactor;
                    appData.spriteState = SPRITE_RUN;
                }
            }
        }
        else if (appData.requestedDirection == USER_REQUESTED_STOP)
        {
            if (appData.spriteFacingDirection == FACING_LEFT)
            {
                if (appData.spriteAnchorX != APP_SPRITE_ANCHOR_INIT)
                {
                    if (laImageSequenceWidget_IsPlaying(RunLeftSequence) == LA_FALSE)
                    {
                        APP_HideAllSequences();

                        laImageSequenceWidget_Play(RunLeftSequence);
                        appData.currentSequence = RunLeftSequence;
                        laImageSequenceWidget_ShowNextImage(appData.currentSequence);
                        appData.spriteTriggerCount = (int32_t)APP_RUN_SPRITE_DELAY - (int32_t)appData.speedFactor;
                        appData.spriteState = SPRITE_RUN;
                    }                    
                }
                else if (laImageSequenceWidget_IsPlaying(IdleLeftSequence) == LA_FALSE)
                {
                    APP_HideAllSequences();

                    laImageSequenceWidget_Play(IdleLeftSequence);
                    appData.currentSequence = IdleLeftSequence;
                    laImageSequenceWidget_ShowNextImage(appData.currentSequence);
                    appData.spriteTriggerCount = APP_IDLE_SPRITE_DELAY;
                    appData.spriteState = SPRITE_IDLE;
                }
            }
            else
            {
                if (appData.spriteAnchorX != APP_SPRITE_ANCHOR_INIT)
                {
                    if (laImageSequenceWidget_IsPlaying(RunRightSequence) == LA_FALSE)
                    {
                        APP_HideAllSequences();

                        laImageSequenceWidget_Play(RunRightSequence);
                        appData.currentSequence = RunRightSequence;
                        laImageSequenceWidget_ShowNextImage(appData.currentSequence);
                        appData.spriteTriggerCount = (int32_t)APP_RUN_SPRITE_DELAY - (int32_t)appData.speedFactor;
                        appData.spriteState = SPRITE_RUN;
                    }                    
                }
                else if (laImageSequenceWidget_IsPlaying(IdleRightSequence) == LA_FALSE)
                {
                    APP_HideAllSequences();

                    laImageSequenceWidget_Play(IdleRightSequence);
                    appData.currentSequence = IdleRightSequence;
                    laImageSequenceWidget_ShowNextImage(appData.currentSequence);
                    appData.spriteTriggerCount = APP_IDLE_SPRITE_DELAY;
                    appData.spriteState = SPRITE_IDLE;
                }
            }
        }
    }

    if (appData.spriteState == SPRITE_HURT && appData.spriteFrameLeft == 100)
    {
        if (appData.spriteFacingDirection == FACING_LEFT)
        {
            APP_HideAllSequences();

            laImageSequenceWidget_Play(HurtLeftSequence);
            appData.currentSequence = HurtLeftSequence;
            laImageSequenceWidget_ShowNextImage(appData.currentSequence);
            appData.spriteTriggerCount = APP_HURT_SPRITE_DELAY;
            appData.spriteFrameLeft = laImageSequenceWidget_GetImageCount(appData.currentSequence) * 3;
            appData.spriteState = SPRITE_HURT;
        }
        else
        {
            APP_HideAllSequences();

            laImageSequenceWidget_Play(HurtSequence);
            appData.currentSequence = HurtSequence;
            laImageSequenceWidget_ShowNextImage(appData.currentSequence);
            appData.spriteFrameLeft = laImageSequenceWidget_GetImageCount(appData.currentSequence) * 3;
            appData.spriteTriggerCount = APP_HURT_SPRITE_DELAY;
            appData.spriteState = SPRITE_HURT;            
        }
    }
    else if (appData.spriteState == SPRITE_HURT && appData.spriteFrameLeft == 0)
    {
        if (appData.spriteFacingDirection == FACING_LEFT)
        {
            APP_HideAllSequences();

            laImageSequenceWidget_Rewind(FallLeftSequence);
            laImageSequenceWidget_Play(FallLeftSequence);
            appData.currentSequence = FallLeftSequence;
            laImageSequenceWidget_ShowNextImage(appData.currentSequence);
            appData.spriteFrameLeft = laImageSequenceWidget_GetImageCount(appData.currentSequence);
            appData.spriteTriggerCount = APP_FALL_SPRITE_DELAY;
            appData.spriteState = SPRITE_FALL;
        }
        else
        {
            APP_HideAllSequences();

            laImageSequenceWidget_Rewind(FallSequence);
            laImageSequenceWidget_Play(FallSequence);
            appData.currentSequence = FallSequence;
            laImageSequenceWidget_ShowNextImage(appData.currentSequence);
            appData.spriteFrameLeft = laImageSequenceWidget_GetImageCount(appData.currentSequence);
            appData.spriteTriggerCount = APP_FALL_SPRITE_DELAY;
            appData.spriteState = SPRITE_FALL;            
        }
    }
    else if (appData.spriteState == SPRITE_FALL 
            && appData.spriteFrameLeft == 0
            && appData.spriteAnchorX == APP_SPRITE_ANCHOR_INIT)
    {
        if (appData.spriteFacingDirection == FACING_LEFT)
        {
            APP_HideAllSequences();

            laImageSequenceWidget_Play(DizzyLeftSequence);
            appData.currentSequence = DizzyLeftSequence;
            laImageSequenceWidget_ShowNextImage(appData.currentSequence);
            appData.spriteFrameLeft = laImageSequenceWidget_GetImageCount(appData.currentSequence) * 2;
            appData.spriteTriggerCount = APP_DIZZY_SPRITE_DELAY;
            appData.spriteState = SPRITE_DIZZY;
        }
        else
        {
            APP_HideAllSequences();

            laImageSequenceWidget_Play(DizzySequence);
            appData.currentSequence = DizzySequence;
            laImageSequenceWidget_ShowNextImage(appData.currentSequence);
            appData.spriteFrameLeft = laImageSequenceWidget_GetImageCount(appData.currentSequence) * 2;
            appData.spriteTriggerCount = APP_DIZZY_SPRITE_DELAY;
            appData.spriteState = SPRITE_DIZZY;            
        }
    }
}

void APP_GoToDemoMode (void)
{
    appData.demoMode = true;
    
    appData.state = APP_STATE_SPLASH;    
}

void APP_GoToInfoState(void)
{
	appData.state = APP_STATE_INFO;
    
    if (appData.pressCountTimer != SYS_TIME_HANDLE_INVALID)
    {
        SYS_TIME_TimerDestroy(appData.pressCountTimer);
        appData.pressCountTimer = SYS_TIME_HANDLE_INVALID;
    }

    if (appData.spriteTimer != SYS_TIME_HANDLE_INVALID)
    {
        SYS_TIME_TimerDestroy(appData.spriteTimer);
        appData.spriteTimer = SYS_TIME_HANDLE_INVALID;
    }
}

void APP_GoToMainState(void)
{
    appData.state = APP_STATE_MAIN_TRANSITION;                     
    appData.spriteState = SPRITE_IDLE;
    appData.layerX0 = 0;
    appData.currentScore = 0;
    appData.delayCounter = 0;
    appData.updateTopScore = true;
    
    appData.baseLayerAlpha = 0;
    appData.uiLayerAlpha = 0;

    laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[0], appData.baseLayerAlpha);
    laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[1], appData.baseLayerAlpha);
    laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[2], appData.uiLayerAlpha);
}

void APP_ToggleEasterEgg(void)
{
    appData.isEasterEggMode = !appData.isEasterEggMode;    
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
    appData.spriteState = SPRITE_IDLE;
    appData.spriteStamina = APP_LAMB_STAMINA;;
    appData.spriteAnchorX = APP_SPRITE_ANCHOR_INIT;
    appData.speedFactor = 1;
    appData.uiLayerAlpha = APP_UI_LAYER_MAX_ALPHA;
    appData.spriteFrameLeft = -1; //Max Frames

    appData.isEasterEggMode = false;
    appData.currentScore = 0;
    appData.topScore = 10000;
    appData.updateTopScore = false;
    
// TODO: Placeholder for when audio support is added back
//    appData.codecClient.bufferEventHandler = (DRV_CODEC_BUFFER_EVENT_HANDLER) audioCodecBufferWriteEventHandler;
//    
//    run_sound_size = sizeof(RUN_SOUND_EFFECT);
//    blaze_sound_size = sizeof(BLAZE_SOUND_EFFECT);
//    hurt_sound_size = sizeof(HURT_SOUND_EFFECT);
//    dizzy_sound_size = sizeof(DIZZY_SOUND_EFFECT);
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */
void APP_Tasks ( void )
{
    //TODO: Placeholder until audio support is reintroduced
    //SYS_STATUS codecStatus;
    
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            //Draw the PIC32 logo, then trigger image preprocessing
            laContext_SetPreprocessAssetStateChangedCallback(APP_IsReadyForPreprocess);
            break;
        }

// TODO: Placeholder for when audio support is added back
//        case APP_STATE_AUDIO_CODEC_OPEN:
//            codecStatus = DRV_CODEC_Status(sysObjdrvCodec0);
//            if (SYS_STATUS_READY == codecStatus) 
//            {
//                appData.codecClient.handle =
//                    DRV_CODEC_Open(DRV_CODEC_INDEX_0,
//                    DRV_IO_INTENT_WRITE|DRV_IO_INTENT_EXCLUSIVE);
//                if (appData.codecClient.handle != DRV_HANDLE_INVALID) {
//                    appData.state = APP_STATE_SPLASH;
//                    DRV_CODEC_BufferEventHandlerSet(appData.codecClient.handle,
//                                            appData.codecClient.bufferEventHandler,
//                                            appData.codecClient.context);
//                   
//                } 
//            }

            break;
        case APP_STATE_SPLASH:
        {
            if (laContext_GetActiveScreen() && 
                laContext_GetActiveScreen()->id != SplashScreen_ID)
                 break;

            if (APP_IsSplashScreenComplete() == true)
            {
                laContext_SetActiveScreen(MainScreen_ID);
                appData.state = APP_STATE_MAIN_TRANSITION;
                appData.spriteState = SPRITE_IDLE;
                appData.layerX0 = 0;
                appData.currentScore = 0;
                appData.baseLayerAlpha = 0;
                appData.uiLayerAlpha = 0;

                laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[0], appData.baseLayerAlpha);
                laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[1], appData.baseLayerAlpha);
                laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[2], appData.uiLayerAlpha);
            }
        }
        
        case APP_STATE_MAIN_TRANSITION:
        {
            // Do not continue to trigger any redraw if any layer hasn't been completely drawn
            if (laContext_IsDrawing())
                break;
                
            if (laContext_GetActive()->activeScreen->id != MainScreen_ID)
                break;

            APP_PrepareLayers();
            
            laWidget_SetPosition(SpriteAnchor, appData.spriteAnchorX, SpriteAnchor->rect.y);
            laWidget_SetPosition(BackPanel, appData.layerX0, BackPanel->rect.y);
            laWidget_SetPosition(MiddlePanel, appData.layerX1, MiddlePanel->rect.y);
            laWidget_SetPosition(FrontPanel, appData.layerX2, FrontPanel->rect.y);

            if (appData.delayCounter++ > 200)
            {
                if (appData.baseLayerAlpha < 255)
                {
                    laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[0], appData.baseLayerAlpha++);
                    laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[1], appData.baseLayerAlpha++);
                }

                if (appData.uiLayerAlpha < APP_UI_LAYER_MAX_ALPHA)
                {
                    appData.uiLayerAlpha++;
                }
                
                appData.delayCounter = 0;
            }
            
            if (appData.baseLayerAlpha >= 255 && appData.uiLayerAlpha >= APP_UI_LAYER_MAX_ALPHA)
            {
                appData.state = APP_STATE_SETUP_IMAGE;

                if (appData.pressCountTimer != SYS_TIME_HANDLE_INVALID)
                {
                    SYS_TIME_TimerDestroy(appData.pressCountTimer);
                    appData.pressCountTimer = SYS_TIME_HANDLE_INVALID;
                }
                
                appData.pressCountTimer = SYS_TIME_CallbackRegisterMS(APP_PressCounter_CallBack, 0 , APP_PRESS_COUNTER_DELAY, SYS_TIME_PERIODIC);                                    

                if (appData.spriteTimer != SYS_TIME_HANDLE_INVALID)
                {
                    SYS_TIME_TimerDestroy(appData.spriteTimer);
                    appData.spriteTimer = SYS_TIME_HANDLE_INVALID;
                }
                appData.spriteTimer = SYS_TIME_CallbackRegisterMS(APP_SpriteSequence_CallBack, 0 , APP_SPRITE_TIMER_DELAY, SYS_TIME_PERIODIC);                                    
            }
            break;
        }
                
        case APP_STATE_SETUP_IMAGE:
        {
            if (laContext_GetActiveScreen() && 
                laContext_GetActiveScreen()->id != MainScreen_ID)
                 break;

            APP_PrepareLayers();
            
            laWidget_SetPosition(SpriteAnchor, appData.spriteAnchorX, SpriteAnchor->rect.y);
            laWidget_SetPosition(BackPanel, appData.layerX0, BackPanel->rect.y);
            laWidget_SetPosition(MiddlePanel, appData.layerX1, MiddlePanel->rect.y);
            laWidget_SetPosition(FrontPanel, appData.layerX2, FrontPanel->rect.y);

            if (appData.requestedDirection != USER_REQUESTED_STOP)
            {
                appData.uiLayerAlpha -= 3;
                if (appData.uiLayerAlpha < 0)
                {
                    appData.uiLayerAlpha = 0;
                }
            }

            laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[2], appData.uiLayerAlpha);
    
            APP_HandleSpriteAnimation();
            
            appData.state = APP_STATE_RUNNING;                                

            break;
        }
        
        case APP_STATE_RUNNING:
        {
            appData.state = APP_STATE_SETUP_IMAGE;                                

            if (appData.updateTopScore == true)
            {
                APP_SetScore(appData.topScore, true);
                appData.updateTopScore = false;
            }
                        
            playSoundEffect();
            
            if (appData.spriteState == SPRITE_IDLE 
                    || appData.spriteState == SPRITE_DIZZY)
            {
                break;
            }

            if (appData.requestedDirection == USER_REQUESTED_GO_RIGHT && appData.spriteState != SPRITE_FALL)
            {
                appData.spriteFacingDirection = FACING_RIGHT;
                appData.spriteAnchorX += APP_SPRITE_STEP_X;

                appData.spriteAnchorX = GFX_Clampi(APP_SPRITE_ANCHOR_INIT, APP_SPRITE_ANCHOR_RIGHT_LIMIT, appData.spriteAnchorX);
            }
            else if (appData.requestedDirection == USER_REQUESTED_GO_LEFT && appData.spriteState != SPRITE_FALL)
            {
                appData.spriteFacingDirection = FACING_LEFT;
                appData.spriteAnchorX -= APP_SPRITE_STEP_X;
                
                appData.spriteAnchorX = GFX_Clampi(APP_SPRITE_ANCHOR_LEFT_LIMIT, APP_SPRITE_ANCHOR_INIT, appData.spriteAnchorX);
            }
            else if (appData.spriteState != SPRITE_HURT)
            {
                if (appData.spriteFacingDirection == FACING_LEFT)
                {
                    appData.spriteAnchorX += APP_SPRITE_STEP_X * 2;
                    appData.spriteAnchorX = GFX_Clampi(APP_SPRITE_ANCHOR_LEFT_LIMIT, APP_SPRITE_ANCHOR_INIT, appData.spriteAnchorX);
                }
                else
                {
                    appData.spriteAnchorX -= APP_SPRITE_STEP_X * 2;
                    appData.spriteAnchorX = GFX_Clampi(APP_SPRITE_ANCHOR_INIT, APP_SPRITE_ANCHOR_RIGHT_LIMIT, appData.spriteAnchorX);
                }
            }

            if (appData.spriteFacingDirection == FACING_RIGHT)
            {                
                appData.layerX0 -= APP_LAYER_MOVE_FACTOR0 * appData.speedFactor; 
                appData.layerX1 -= APP_LAYER_MOVE_FACTOR1 * appData.speedFactor; 
                appData.layerX2 -= APP_LAYER_MOVE_FACTOR2 * appData.speedFactor; 
                
                if (appData.layerX0 < appData.layerLimit0)
                {
                    appData.layerX0 = 0;
                }

                if (appData.layerX1 < appData.layerLimit1)
                {
                    appData.layerX1 = 0;
                }

                if (appData.layerX2 < appData.layerLimit2)
                {
                    appData.layerX2 = 0;
                }
            }
            else if (appData.spriteFacingDirection == FACING_LEFT)
            {
                appData.layerX0 += APP_LAYER_MOVE_FACTOR0 * appData.speedFactor; 
                appData.layerX1 += APP_LAYER_MOVE_FACTOR1 * appData.speedFactor; 
                appData.layerX2 += APP_LAYER_MOVE_FACTOR2 * appData.speedFactor; 

                if (appData.layerX0 > 0)
                {
                    appData.layerX0 = appData.layerLimit0;
                }
                
                if (appData.layerX1 > 0)
                {
                    appData.layerX1 = appData.layerLimit1;
                }

                if (appData.layerX2 > 0)
                {
                    appData.layerX2 = appData.layerLimit2;
                }
            }
            break;
        }

        case APP_STATE_INFO:
		{
			// Do not continue to trigger any redraw if any layer hasn't been completely drawn
			if (laContext_IsDrawing())
				break;

			if (laContext_GetActive()->activeScreen->id != 2)
				break;

			if (InfoTextDragPanel != NULL)
			{
				miny = 0 - InfoTextDragPanel->rect.height;
				maxy = 0;

				laWidget_OverrideTouchDownEvent((laWidget*)InfoTextDragPanel, &touchDown);
				laWidget_OverrideTouchMovedEvent((laWidget*)InfoTextDragPanel, &touchMovedUpDown);
				laWidget_OverrideTouchUpEvent((laWidget*)InfoTextDragPanel, &touchUp);
			}
			break;
		}

        /* The default state should never be executed. */
        default:
        {
            break;
        }
    }
}

 

/*******************************************************************************
 End of File
 */
