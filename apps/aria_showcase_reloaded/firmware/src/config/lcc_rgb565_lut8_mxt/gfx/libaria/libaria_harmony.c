/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Implementation File

  File Name:
    libaria_harmony.c

  Summary:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2018 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
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

#include "gfx/libaria/libaria_harmony.h"
#include "gfx/libaria/libaria_init.h"

#include "gfx/libaria/libaria.h"
#include "gfx/libaria/libaria_demo_mode.h"


#include "system/input/sys_input.h"

SYS_INP_InputListener inputListener;

static void touchDownHandler(const SYS_INP_TouchStateEvent* const evt);
static void touchUpHandler(const SYS_INP_TouchStateEvent* const evt);
static void touchMoveHandler(const SYS_INP_TouchMoveEvent* const evt);

/*** libaria Object Global ***/
libaria_objects libariaObj;
static LIBARIA_STATES libariaState;

GFXU_MemoryIntf memIntf;

static GFX_Result LibAria_MediaOpenRequest(GFXU_AssetHeader* asset);

static GFX_Result LibAria_MediaReadRequest(GFXU_ExternalAssetReader* reader,
                                           GFXU_AssetHeader* asset,
                                           void* address,
                                           uint32_t readSize,
                                           uint8_t* destBuffer,
                                           GFXU_MediaReadRequestCallback_FnPtr cb);

static void LibAria_MediaCloseRequest(GFXU_AssetHeader* asset);




int32_t LibAria_Initialize(void)
{
    if(laInitialize() == LA_FAILURE)
        return -1;

    memIntf.heap.malloc = &malloc;
    //memIntf.heap.coherent_alloc = &__pic32_alloc_coherent; // FIXME for H3
    memIntf.heap.coherent_alloc = &malloc;
    memIntf.heap.calloc = &calloc;
    memIntf.heap.free = &free;
    memIntf.heap.coherent_free = &free;
    //memIntf.heap.coherent_free = &__pic32_free_coherent; // FIXME for H3

    memIntf.heap.memcpy = &memcpy;
    memIntf.heap.memset = (void*)&memset;
    memIntf.heap.realloc = &realloc;
    memIntf.open = &LibAria_MediaOpenRequest;
    memIntf.read = &LibAria_MediaReadRequest;
    memIntf.close = &LibAria_MediaCloseRequest;

    libariaObj.context = laContext_Create(0, 0, 0, GFX_COLOR_MODE_GS_8, &memIntf);

    if(libariaObj.context == NULL)
        return -1;

    laContext_SetActive(libariaObj.context);


    libaria_initialize(); // use auto-generated initialization functions

    inputListener.handleTouchDown = &touchDownHandler;
    inputListener.handleTouchUp = &touchUpHandler;
    inputListener.handleTouchMove = &touchMoveHandler;

    libariaState = LIBARIA_STATE_INIT;

    return 0;
}

void LibAria_Tasks(void)
{
    switch(libariaState)
    {
        case LIBARIA_STATE_INIT:
        {
            SYS_INP_AddListener(&inputListener);

            libariaState = LIBARIA_STATE_RUNNING;

            break;
        }
        case LIBARIA_STATE_RUNNING:
        {
            laContext_SetActive(libariaObj.context);

            LibAria_DemoModeProcessEvents();

            laUpdate(0);

            break;
        }

        default:
        {
            break;
        }
    }
}

void touchDownHandler(const SYS_INP_TouchStateEvent* const evt)
{
    laInput_InjectTouchDown(evt->index, evt->x, evt->y);
}

void touchUpHandler(const SYS_INP_TouchStateEvent* const evt)
{
    laInput_InjectTouchUp(evt->index, evt->x, evt->y);
}

void touchMoveHandler(const SYS_INP_TouchMoveEvent* const evt)
{
    laInput_InjectTouchMoved(evt->index, evt->x, evt->y);
}


static GFX_Result LibAria_MediaOpenRequest(GFXU_AssetHeader* asset)
{
    return GFX_FAILURE;
}

static GFX_Result LibAria_MediaReadRequest(GFXU_ExternalAssetReader* reader,
                                           GFXU_AssetHeader* asset,
                                           void* address,
                                           uint32_t readSize,
                                           uint8_t* destBuffer,
                                           GFXU_MediaReadRequestCallback_FnPtr cb)
{
    return GFX_FAILURE;
}

static void LibAria_MediaCloseRequest(GFXU_AssetHeader* asset)
{
}

