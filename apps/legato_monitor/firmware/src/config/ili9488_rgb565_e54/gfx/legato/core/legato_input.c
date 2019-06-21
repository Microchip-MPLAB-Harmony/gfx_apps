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

#include "gfx/legato/core/legato_input.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/widget/legato_widget.h"
#include "legato_state.h"
#include "gfx/legato/renderer/legato_renderer.h"

#include <string.h>

//#define INPUT_EVENT_DEBUG

static leInputState _state; // the global input state

leInputState* _leGetInputState()
{
    return &_state;
}

leResult leInput_Init()
{
    memset(&_state, 0, sizeof(leInputState));
    
    _state.enabled = LE_TRUE;
    
    return LE_SUCCESS;
}

void leInput_Shutdown()
{
    
}

leBool leInput_GetEnabled()
{
    return _state.enabled;
}

leResult leInput_SetEnabled(leBool enable)
{
    _state.enabled = enable;

    return LE_SUCCESS;
}

static lePoint transformCoordinate(int32_t x, int32_t y)
{
    lePoint pnt;
    
    /*leRect rect;
    GFX_Orientation orientation;
    leBool mirror;*/
    
    // reorient touch coordinates if the user interface is rotated
    pnt.x = x;
    pnt.y = y;
    
    /*rect = leContext_GetScreenRect();
    
    GFX_Get(GFXF_ORIENTATION, &orientation);
    GFX_Get(GFXF_MIRRORED, &mirror);
    
    pnt = leUtils_ScreenToOrientedSpace(&pnt, &rect, orientation);
    
    if(mirror == LE_TRUE)
        pnt = leUtils_ScreenToMirroredSpace(&pnt, &rect, orientation);*/

    return pnt;
}

leResult leInput_InjectTouchDown(uint32_t id, int32_t x, int32_t y)
{
    leInput_TouchDownEvent* evt;
    lePoint pnt;

    if(_state.enabled == LE_FALSE ||               // inputs are disabled
       id >= LE_MAX_TOUCH_STATES ||                // don't overrun array
       _state.touch[id].valid == LE_TRUE)  // touch id must be invalid
    {
        return LE_FAILURE;
    }
    
    // reorient touch coordinates if the user interface is rotated
    pnt = transformCoordinate(x, y);

    // dispatch the event
    _state.touch[id].valid = LE_TRUE;
    _state.touch[id].x = pnt.x;
    _state.touch[id].y = pnt.y;

    evt = LE_MALLOC(sizeof(leInput_TouchDownEvent));

    if(evt == NULL)
        return LE_FAILURE;
    
    evt->event.id = LE_EVENT_TOUCH_DOWN;
    evt->touchID = id;
    evt->x = pnt.x;
    evt->y = pnt.y;

#ifdef INPUT_EVENT_DEBUG
    printf("adding touch down event %i, %i\n", evt->x, evt->y);
#endif

    if(leEvent_AddEvent((leEvent*)evt) == LE_FAILURE)
    {
        LE_FREE(evt);

        return LE_FAILURE;
    }    

    return LE_SUCCESS;
}

leResult leInput_InjectTouchUp(uint32_t id, int32_t x, int32_t y)
{
    leInput_TouchUpEvent* evt;
    lePoint pnt;

    if(id >= LE_MAX_TOUCH_STATES ||         // don't overrun array
       _state.touch[id].valid == LE_FALSE)  // touch id must be valid
    {
        return LE_FAILURE;
    }
    
    _state.touch[id].valid = LE_FALSE;

    // reorient touch coordinates if the user interface is rotated
    pnt = transformCoordinate(x, y);

    // dispatch event
    evt = LE_MALLOC(sizeof(leInput_TouchUpEvent));

    if(evt == NULL)
        return LE_FAILURE;
    
    evt->event.id = LE_EVENT_TOUCH_UP;
    evt->touchID = id;
    evt->x = pnt.x;
    evt->y = pnt.y;
    
#ifdef INPUT_EVENT_DEBUG
    printf("adding touch up event %i, %i\n", evt->x, evt->y);
#endif

    if(leEvent_AddEvent((leEvent*)evt) == LE_FAILURE)
    {
        LE_FREE(evt);

        return LE_FAILURE;
    }    

    return LE_SUCCESS;
}

leResult leInput_InjectTouchMoved(uint32_t id, int32_t x, int32_t y)
{
    leInput_TouchMoveEvent* evt;
    leEvent* evtPtr;
    lePoint pnt;
    leListNode* node;

    if(id >= LE_MAX_TOUCH_STATES ||         // don't overrun array
       _state.touch[id].valid == LE_FALSE)  // touch id must be valid
        return LE_FAILURE;
        
    // find any existing touch moved event and overwrite
    node = _leGetEventState()->events.head;
    
    while(node != NULL)
    {
        evtPtr = (leEvent*)node->val;
        
        if(evtPtr->id == LE_EVENT_TOUCH_MOVE)
        {
            evt = (leInput_TouchMoveEvent*)evtPtr;
         
            if(evt->touchID == id)
            {   
#ifdef INPUT_EVENT_DEBUG
                printf("overwriting previous move event\n");
#endif                
                
                // reorient touch coordinates if the user interface is rotated
                pnt = transformCoordinate(x, y);
                
                evt->x = x;
                evt->y = y;
                
                evt->x = pnt.x;
                evt->y = pnt.y;

                _state.touch[id].x = pnt.x;
                _state.touch[id].y = pnt.y;
                
                return LE_SUCCESS;
            }
        }
        
        node = node->next;
    }

    evt = LE_MALLOC(sizeof(leInput_TouchMoveEvent));

    if(evt == NULL)
        return LE_FAILURE;

    // reorient touch coordinates if the user interface is rotated
    pnt = transformCoordinate(x, y);

    evt->event.id = LE_EVENT_TOUCH_MOVE;
    evt->touchID = id;
    evt->prevX = _state.touch[id].x;
    evt->prevY = _state.touch[id].y;
    evt->x = pnt.x;
    evt->y = pnt.y;

    _state.touch[id].x = pnt.x;
    _state.touch[id].y = pnt.y;

#ifdef INPUT_EVENT_DEBUG
    printf("adding move event %i, %i, %i, %i\n", evt->x, evt->y, evt->prevX, evt->prevY);
#endif

    if(leEvent_AddEvent((leEvent*)evt) == LE_FAILURE)
    {
        LE_FREE(evt);

        return LE_FAILURE;
    }    

    return LE_SUCCESS;
}

leEventResult handleTouchDown(leInput_TouchDownEvent* evt)
{
    leWidget* targetWidget = NULL;
    leWidget* rootWidget;
    int32_t i;
    
    // find the topmost widget on the topmost layer for the touch event
    for(i = LE_LAYER_COUNT - 1; i >= 0; i--)
    {
        rootWidget = &leGetState()->rootWidget[i];
        
        targetWidget = leUtils_PickFromWidget(rootWidget, evt->x, evt->y);
        
        if(targetWidget != NULL)
            break; 
    }

    // no widget qualified
    if(targetWidget == NULL)
    {
        leSetFocusWidget(NULL);
        
        return LE_EVENT_HANDLED;
    }

    if(leIsDrawing() == LE_TRUE)
        return LE_EVENT_DEFERRED;

    while(targetWidget != NULL)
    {
        targetWidget->fn->_handleEvent(targetWidget, (leEvent*)evt);
        
        if(evt->event.accepted == LE_TRUE)
            break;

        targetWidget = targetWidget->parent;
    }

    leSetFocusWidget(targetWidget);
    
#ifdef INPUT_EVENT_DEBUG  
    printf("handling touch down event %i, %i\n", evt->x, evt->y);
#endif
    
    return LE_EVENT_HANDLED;
}

leBool handleTouchUp(leInput_TouchUpEvent* evt)
{
    leWidget* wgt = leGetFocusWidget();
    
    if(wgt == NULL)
        return LE_EVENT_HANDLED;
        
    if(leIsDrawing() == LE_FALSE)
    {
        wgt->fn->_handleEvent(wgt, (leEvent*)evt);

#ifdef INPUT_EVENT_DEBUG
        printf("handling touch up event %i, %i\n", evt->x, evt->y);
#endif       
        
        return LE_EVENT_HANDLED;
    }
    
    return LE_EVENT_DEFERRED;
}

leBool handleTouchMoved(leInput_TouchMoveEvent* evt)
{
    leWidget* wgt = leGetFocusWidget();

    if(wgt == NULL)
        return LE_EVENT_HANDLED;
        
    if(leIsDrawing() == LE_FALSE)
    {
       wgt->fn->_handleEvent(wgt, (leEvent*)evt);

#ifdef INPUT_EVENT_DEBUG        
        printf("handling touch move event %i, %i, %i, %i\n", evt->x, evt->y, evt->prevX, evt->prevY);
#endif
        
        return LE_EVENT_HANDLED;
    }

    return LE_EVENT_DEFERRED;
}

leEventResult _leInput_HandleInputEvent(leEvent* evt)
{
    switch(evt->id)
    {
        case LE_EVENT_TOUCH_DOWN:
        {
            return handleTouchDown((leInput_TouchDownEvent*)evt);

#ifdef INPUT_EVENT_DEBUG                
            printf("handled touch down\n");
#endif                
                
            break;
        }
        case LE_EVENT_TOUCH_UP:
        {
            return handleTouchUp((leInput_TouchUpEvent*)evt);

#ifdef INPUT_EVENT_DEBUG               
            printf("handled touch up\n");
#endif                
                
            break;
        }
        case LE_EVENT_TOUCH_MOVE:
        {
            return handleTouchMoved((leInput_TouchMoveEvent*)evt);
                return LE_FAILURE;

#ifdef INPUT_EVENT_DEBUG                
            printf("handled touch move\n");
#endif                
                
            break;
        }
        default:
            break;
    }

    return LE_SUCCESS;
}