// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

#include <stdlib.h>

#include "gfx/driver/gfx_driver.h"
#include "gfx/canvas/gfx_canvas_api.h"
#include "gfx/canvas/gfx_canvas.h"


#include "definitions.h"


/*******************************************************************************
  GFX Canvas

  Company:
    Microchip Technology Inc.

  File Name:
    gfx_canvas.c

  Summary:
    GFX Canvas Virtual Display Component private header file

  Description:
    The GFX Canvas provides a virtual display driver interface. 

  Remarks:
    None
*******************************************************************************/

typedef enum 
{
    GFXC_INIT,
    GFXC_RUNNING,
} GFXC_STATE;

//LE Driver interface function prototypes
static gfxColorMode GFXC_GetColorMode(void);
static uint32_t GFXC_GetBufferCount(void);
static uint32_t GFXC_GetDisplayWidth(void);
static uint32_t GFXC_GetDisplayHeight(void);
static void GFXC_Update(void);
static uint32_t GFXC_GetLayerCount();
static uint32_t GFXC_GetActiveLayer();
static gfxResult GFXC_SetActiveLayer(uint32_t idx);
static gfxResult GFXC_BlitBuffer(int32_t x, int32_t y, gfxPixelBuffer* buf);
static gfxResult GFXC_SetPalette(gfxBuffer* palette,
                          gfxColorMode mode,
                          uint32_t colorCount);
static gfxLayerState GFXC_GetLayerState(uint32_t idx);
static void GFXC_Swap(void);
static uint32_t GFXC_GetVSYNCCount(void);
static gfxPixelBuffer * GFXC_GetPixelBuffer(int32_t idx);

GFXC_CANVAS canvas[CONFIG_NUM_CANVAS_OBJ];
unsigned int numLayers = CONFIG_NUM_LAYERS;

static unsigned int activeCanvasID = 0;
static GFXC_STATE gfxcState;

static unsigned int effectsIntervalMS = CONFIG_FX_INTERVAL_MS;
static SYS_TIME_HANDLE effectsTimer;
static volatile unsigned int effectsTick = 0;
static unsigned int oldEffectsTick = 0;

static unsigned int displayWidth = 0;
static unsigned int displayHeight = 0;


const gfxGraphicsProcessor * gfxcGPU = NULL;

extern const gfxDisplayDriver glcdDisplayDriver;
const gfxDisplayDriver * gfxDispCtrlr = &glcdDisplayDriver;


const gfxDisplayDriver gfxDriverInterface =
{
    GFXC_GetColorMode,
    GFXC_GetBufferCount,
    GFXC_GetDisplayWidth,
    GFXC_GetDisplayHeight,
    GFXC_Update,
    GFXC_GetLayerCount,
    GFXC_GetActiveLayer,
    GFXC_SetActiveLayer,
    GFXC_GetLayerState,
    GFXC_BlitBuffer,
    GFXC_Swap,
    GFXC_GetVSYNCCount,
    GFXC_GetPixelBuffer,
    GFXC_SetPalette,
};


static void gfxcObjectsInitialize(void)
{
    unsigned int id;

    id = gfxcCreate();
    gfxcSetPixelBuffer(id, 800, 480, GFX_COLOR_MODE_RGBA_8888,
                       (void *) 0xa8000000);
    id = gfxcCreate();
    gfxcSetPixelBuffer(id, 800, 480, GFX_COLOR_MODE_RGBA_8888,
                       (void *) 0xa8177000);
    id = gfxcCreate();
    gfxcSetPixelBuffer(id, 800, 480, GFX_COLOR_MODE_RGBA_8888,
                       (void *) 0xa82ee000);
}

static void effectsTimerCallback ( uintptr_t context )
{
    effectsTick++;
}


void GFX_CANVAS_Initialize(void)
{
    unsigned int i;
    gfxcState = GFXC_INIT;
    
    //Initialize canvas objects
    for (i = 0; i < CONFIG_NUM_CANVAS_OBJ; i++)
    {
        canvas[i].pixelBuffer.mode = CANVAS_DEFAULT_FORMAT;
        canvas[i].id = CANVAS_ID_INVALID;
        canvas[i].layer.id = LAYER_ID_INVALID;
        canvas[i].effects.cb = NULL;
        canvas[i].effects.fade.status = GFXC_FX_IDLE;
        canvas[i].effects.move.status = GFXC_FX_IDLE;
    }

    numLayers =  gfxDispCtrlr->getLayerCount();

    if (gfxDispCtrlr != NULL)
    {
        displayWidth = gfxDispCtrlr->getDisplayWidth();
        displayHeight = gfxDispCtrlr->getDisplayHeight();
    }

    gfxcObjectsInitialize();
}


//Library interface functions
gfxColorMode GFXC_GetColorMode()
{
    return canvas[activeCanvasID].pixelBuffer.mode;
}

uint32_t GFXC_GetBufferCount()
{
    return 1;
}

uint32_t GFXC_GetDisplayWidth()
{
    return canvas[activeCanvasID].pixelBuffer.size.width;
}

uint32_t GFXC_GetDisplayHeight()
{
    return canvas[activeCanvasID].pixelBuffer.size.height;
}

uint32_t GFXC_GetLayerCount()
{
    return CONFIG_NUM_CANVAS_OBJ;
}

uint32_t GFXC_GetActiveLayer()
{
    return activeCanvasID;
}

gfxResult GFXC_SetActiveLayer(uint32_t canvasID)
{
    if (canvasID < CONFIG_NUM_CANVAS_OBJ)
    {
        activeCanvasID = canvasID;
        
        return GFX_SUCCESS;
    }
    
    return GFX_FAILURE;    
}

void GFXC_Swap(void)
{

}

uint32_t GFXC_GetVSYNCCount(void)
{
    return 0;
}

void GFXC_Update()
{
}

gfxPixelBuffer * GFXC_GetPixelBuffer(int32_t idx)
{
    return &canvas[activeCanvasID].pixelBuffer;
}

gfxResult GFXC_BlitBuffer(int32_t x,
                          int32_t y,
                          gfxPixelBuffer* buf)
{
    void* srcPtr;
    void* destPtr;
    uint32_t row, rowSize;    

    if (gfxcState != GFXC_RUNNING)
        return GFX_FAILURE;

    rowSize = buf->size.width * gfxColorInfoTable[buf->mode].size;

    for(row = 0; row < buf->size.height; row++)
    {
        srcPtr = gfxPixelBufferOffsetGet(buf, 0, row);
        destPtr = gfxPixelBufferOffsetGet(&canvas[activeCanvasID].pixelBuffer,
                                          x, y + row);

        memcpy(destPtr, srcPtr, rowSize);
    }

    return GFX_SUCCESS;
}

gfxResult GFXC_SetPalette(gfxBuffer* palette,
                          gfxColorMode mode,
                          uint32_t colorCount)
{
    return GFX_FAILURE;
}

gfxLayerState GFXC_GetLayerState(uint32_t idx)
{
    gfxLayerState layerState;

    layerState.rect.x = canvas[idx].layer.pos.xpos;
    layerState.rect.y = canvas[idx].layer.pos.ypos;
    layerState.rect.width = canvas[idx].layer.size.width;
    layerState.rect.height = canvas[idx].layer.size.height;

    layerState.enabled = canvas[idx].active;

    return layerState;
}

GFXC_RESULT _gfxcCanvasUpdate(unsigned int canvasID)
{
    argSetSize setSizeParm;
    argSetSize setResParm;
    argSetPosition setPositionParm;
    argSetValue setAlphaParm;
    argSetValue setBaseAddressParm;
    argSetValue setColorModeParm;
    
    if (canvasID < CONFIG_NUM_CANVAS_OBJ &&
        canvas[canvasID].layer.id != LAYER_ID_INVALID &&
        gfxDispCtrlr != NULL &&
        gfxDispCtrlr->ctrlrConfig != NULL)
    {
        setBaseAddressParm.layerID = canvas[canvasID].layer.id;
        if (canvas[canvasID].pixelBuffer.pixels != NULL)
            setBaseAddressParm.value = (unsigned int) canvas[canvasID].pixelBuffer.pixels;
        else
        {
            gfxDispCtrlr->setActiveLayer(canvas[canvasID].layer.id);
            setBaseAddressParm.value = (unsigned int) gfxDispCtrlr->getFrameBuffer(0)->pixels;
        }
                    
        setColorModeParm.layerID = canvas[canvasID].layer.id;
        setColorModeParm.value = (unsigned int) canvas[canvasID].pixelBuffer.mode;
        
        setResParm.layerID = canvas[canvasID].layer.id;
        setResParm.width = canvas[canvasID].pixelBuffer.size.width;
        setResParm.height = canvas[canvasID].pixelBuffer.size.height;
        
        setSizeParm.layerID = canvas[canvasID].layer.id;
        setSizeParm.width = canvas[canvasID].layer.size.width;
        setSizeParm.height = canvas[canvasID].layer.size.height; 
        
        setPositionParm.layerID = canvas[canvasID].layer.id;
        setPositionParm.xpos = canvas[canvasID].layer.pos.xpos;
        setPositionParm.ypos = canvas[canvasID].layer.pos.ypos;   
        
        setAlphaParm.layerID = canvas[canvasID].layer.id;
        setAlphaParm.value = canvas[canvasID].layer.alpha;   

        //clipping code
        if (setPositionParm.xpos < 0)
        {
            setBaseAddressParm.value += abs(setPositionParm.xpos) * 
                    gfxColorInfoTable[canvas[canvasID].pixelBuffer.mode].size; 

            setSizeParm.width += setPositionParm.xpos;
            setPositionParm.xpos = 0;
        }

        if (setPositionParm.ypos < 0)
        {
            setBaseAddressParm.value += abs(setPositionParm.ypos) * 
                    setResParm.width * 
                    gfxColorInfoTable[canvas[canvasID].pixelBuffer.mode].size;

            setSizeParm.height += setPositionParm.ypos;
            setPositionParm.ypos = 0;
        }

        if (setPositionParm.xpos + setSizeParm.width > displayWidth)
            setSizeParm.width = displayWidth - setPositionParm.xpos;

        if (setPositionParm.ypos + setSizeParm.height > displayHeight)
            setSizeParm.height = displayHeight - setPositionParm.ypos;
        
        //Lock layer and apply layer properties
        gfxDispCtrlr->ctrlrConfig(GFX_CTRLR_SET_LAYER_LOCK, (void *) &canvas[canvasID].layer.id);
        
        if (setBaseAddressParm.value != NULL)
            gfxDispCtrlr->ctrlrConfig(GFX_CTRLR_SET_LAYER_BASE_ADDRESS, (void *) &setBaseAddressParm);
        
        gfxDispCtrlr->ctrlrConfig(GFX_CTRLR_SET_LAYER_COLOR_MODE, (void *) &setColorModeParm);
        gfxDispCtrlr->ctrlrConfig(GFX_CTRLR_SET_LAYER_SIZE, (void *) &setResParm);
        gfxDispCtrlr->ctrlrConfig(GFX_CTRLR_SET_LAYER_WINDOW_POSITION, (void *) &setPositionParm);
        gfxDispCtrlr->ctrlrConfig(GFX_CTRLR_SET_LAYER_WINDOW_SIZE, (void *) &setSizeParm);
        
        gfxDispCtrlr->ctrlrConfig(GFX_CTRLR_SET_LAYER_ALPHA, (void *) &setAlphaParm);
        
        if (canvas[canvasID].active == true)
            gfxDispCtrlr->ctrlrConfig(GFX_CTRLR_SET_LAYER_ENABLE, (void *) &canvas[canvasID].layer.id);
        else
            gfxDispCtrlr->ctrlrConfig(GFX_CTRLR_SET_LAYER_DISABLE, (void *) &canvas[canvasID].layer.id);

        
        //Unlock layer to affect changes
        gfxDispCtrlr->ctrlrConfig(GFX_CTRLR_SET_LAYER_UNLOCK, (void *) &canvas[canvasID].layer.id);

        return GFX_SUCCESS;
    }
            
    return GFX_FAILURE;
}

GFXC_RESULT _gfxcSetEffectsIntervalMS(unsigned int ms)
{
    effectsIntervalMS = ms;

    SYS_TIME_TimerDestroy(effectsTimer);
    
    effectsTimer = SYS_TIME_CallbackRegisterMS(effectsTimerCallback, 
                           (uintptr_t) NULL,
                           effectsIntervalMS,
                           SYS_TIME_PERIODIC);
    SYS_TIME_TimerStop(effectsTimer);
    
    return GFX_SUCCESS;
}

GFXC_RESULT _gfxcStartEffects(void)
{
    SYS_TIME_TimerStart(effectsTimer);
    
    return GFX_SUCCESS;
}

GFXC_RESULT _gfxcStopEffects(void)
{
    SYS_TIME_TimerStop(effectsTimer);
    
    return GFX_SUCCESS;
}

static GFXC_RESULT gfxcProcessFadeEffect(GFXC_CANVAS * canvas)
{
    GFXC_RESULT retval = GFX_FAILURE;
    
    //Fade out
    if (canvas->effects.fade.startAlpha > canvas->effects.fade.endAlpha)
    {
        if (canvas->layer.alpha > canvas->effects.fade.endAlpha + 
                                  canvas->effects.fade.delta)
        {
            canvas->layer.alpha -= canvas->effects.fade.delta;
            
            retval = GFX_SUCCESS;
        }
        else
        {
            canvas->layer.alpha = canvas->effects.fade.endAlpha;
            canvas->effects.fade.status = GFXC_FX_DONE;
        }
    }
    //Fade in
    else if (canvas->effects.fade.startAlpha < canvas->effects.fade.endAlpha)
    {
        if (canvas->layer.alpha < canvas->effects.fade.endAlpha - 
                                  canvas->effects.fade.delta)
        {
            canvas->layer.alpha += canvas->effects.fade.delta;
            
            retval = GFX_SUCCESS;
        }
        else
        {
            canvas->layer.alpha = canvas->effects.fade.endAlpha;
            canvas->effects.fade.status = GFXC_FX_DONE;
        }
    }
    
    gfxcCanvasUpdate(canvas->id);
    
    if (retval == GFX_FAILURE && canvas->effects.cb != NULL)
        canvas->effects.cb(canvas->id,
                           GFXC_FX_FADE,
                           GFXC_FX_DONE,
                           canvas->effects.parm);            
        

        
    return retval;
}

static GFXC_RESULT gfxcProcessMoveEffect(GFXC_CANVAS * canvas)
{
    GFXC_RESULT retval = GFX_FAILURE;
    int deltaX, deltaY;
    
    switch(canvas->effects.move.type)
    {
        case GFXC_FX_MOVE_ACC:
        {
            deltaX = (canvas->effects.move.startX != canvas->effects.move.endX) ? 
                      abs(canvas->layer.pos.xpos - canvas->effects.move.startX) /
                      canvas->effects.move.delta + 1 : 0;
            deltaY = (canvas->effects.move.startY != canvas->effects.move.endY) ? 
                      abs(canvas->layer.pos.ypos - canvas->effects.move.startY) /
                        canvas->effects.move.delta + 1 : 0;
            break;
        }
        case GFXC_FX_MOVE_DEC:
        {
            deltaX = (canvas->effects.move.startX != canvas->effects.move.endX) ? 
                     abs(canvas->effects.move.endX - canvas->layer.pos.xpos) /
                        canvas->effects.move.delta + 1 : 0;
            deltaY = (canvas->effects.move.startY != canvas->effects.move.endY) ? 
                     abs(canvas->effects.move.endY - canvas->layer.pos.ypos) /
                        canvas->effects.move.delta + 1 : 0;
            break;
        }
        case GFXC_FX_MOVE_FIXED:
        default:
        {
            deltaX = deltaY = canvas->effects.move.delta;
            break;
        }
    }
    
    //Move right
    if (canvas->effects.move.startX < canvas->effects.move.endX)
    {
        if (canvas->layer.pos.xpos < canvas->effects.move.endX -
                                  deltaX)
        {
            canvas->layer.pos.xpos += deltaX;
            retval = GFX_SUCCESS;
        }
        else
        {
            canvas->layer.pos.xpos = canvas->effects.move.endX;
        }
    }
    //Move left
    else if (canvas->effects.move.startX > canvas->effects.move.endX)
    {
        if (canvas->layer.pos.xpos > canvas->effects.move.endX +
                                  deltaX)
        {
            canvas->layer.pos.xpos -= deltaX;
            retval = GFX_SUCCESS;
        }
        else
        {
            canvas->layer.pos.xpos = canvas->effects.move.endX;
        }
    }
    
        //Move down
    if (canvas->effects.move.startY < canvas->effects.move.endY)
    {
        if (canvas->layer.pos.ypos < canvas->effects.move.endY -
                                  deltaY)
        {
            canvas->layer.pos.ypos += deltaY;
            retval = GFX_SUCCESS;
        }
        else
        {
            canvas->layer.pos.ypos = canvas->effects.move.endY;
        }
    }
    //Move up
    else if (canvas->effects.move.startY > canvas->effects.move.endY)
    {
        if (canvas->layer.pos.ypos > canvas->effects.move.endY +
                                  deltaY)
        {
            canvas->layer.pos.ypos -= deltaY;
            retval = GFX_SUCCESS;
        }
        else
        {
            canvas->layer.pos.ypos = canvas->effects.move.endY;
        }
    }
    
    gfxcCanvasUpdate(canvas->id);
    
    if (retval == GFX_FAILURE)
    {
        canvas->effects.move.status = GFXC_FX_DONE;
        
        if (canvas->effects.cb != NULL)
           canvas->effects.cb(canvas->id,
                               GFXC_FX_MOVE,
                               GFXC_FX_DONE,
                               canvas->effects.parm);
    }
    
    return retval;
}

void GFX_CANVAS_Task(void)
{
    switch(gfxcState)
    {
        case GFXC_INIT:
        {
            effectsTimer = SYS_TIME_CallbackRegisterMS(effectsTimerCallback, 
                           (uintptr_t) NULL,
                           effectsIntervalMS,
                           SYS_TIME_PERIODIC);
            SYS_TIME_TimerStop(effectsTimer);
            gfxcState = GFXC_RUNNING;
            break;
        }
        case GFXC_RUNNING:
        {
            unsigned int i;

            //Process effects
            if (oldEffectsTick != effectsTick)
            {
                GFXC_RESULT gres = GFX_FAILURE; 
                
                for (i = 0; i < CONFIG_NUM_CANVAS_OBJ; i++)
                {
                    if (canvas[i].id != CANVAS_ID_INVALID)
                    {
                        GFXC_RESULT res = GFX_FAILURE; 

                        //Process alpha effects
                        switch(canvas[i].effects.fade.status)
                        {
                            case GFXC_FX_START:
                            {
                                canvas[i].effects.fade.status = GFXC_FX_RUN;
                                //no break, start running effect;
                            }
                            case GFXC_FX_RUN:
                            {
                                res = gfxcProcessFadeEffect(&canvas[i]);
                                if (gres == GFX_FAILURE)
                                    gres = res;
                                break;
                            }
                            default:
                                break;
                        }
                        //Process move effects
                        switch(canvas[i].effects.move.status)
                        {
                            case GFXC_FX_START:
                            {
                                canvas[i].effects.move.status = GFXC_FX_RUN;
                                //no break, start running effect;
                            }
                            case GFXC_FX_RUN:
                            {
                                res = gfxcProcessMoveEffect(&canvas[i]);
                                if (gres == GFX_FAILURE)
                                    gres = res;
                                break;
                            }
                            default:
                                break;
                        }
                    }
                }
                
                if (gres == GFX_FAILURE)
                    SYS_TIME_TimerStop(effectsTimer);
                
                oldEffectsTick = effectsTick;
            }
            break;
        }
        default:
            break;
    }
}

/* *****************************************************************************
 End of File
 */
