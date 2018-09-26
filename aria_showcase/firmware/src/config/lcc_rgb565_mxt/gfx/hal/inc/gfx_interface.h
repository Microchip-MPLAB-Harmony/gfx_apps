// DOM-IGNORE-BEGIN

/*******************************************************************************
 Module for Microchip Graphics Library - Hardware Abstraction Layer

  Company:
    Microchip Technology Inc.

  File Name:
    gfx_interface.h

  Summary:
    Defines the get and set interfaces for the main abstract interface API

  Description:
    Interface table generation.
*******************************************************************************/

/*******************************************************************************
Copyright (c) 2017 released Microchip Technology Inc.  All rights reserved.

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
#ifndef GFX_INTERFACE_H
#define GFX_INTERFACE_H

#include "gfx/hal/inc/gfx_common.h"

#include <stdarg.h>

#define GFX_GET 0
#define GFX_SET 1

#define GFX_INTERFACE(fn_name) \
GFX_Result get_##fn_name(va_list); \
GFX_Result set_##fn_name(va_list)

/* interfaces */
GFX_INTERFACE(unimplemented);
GFX_INTERFACE(displayCount);
GFX_INTERFACE(displayInfo);
GFX_INTERFACE(driverCount);
GFX_INTERFACE(driverInfo);
GFX_INTERFACE(brightnessRange);
GFX_INTERFACE(brightness);
GFX_INTERFACE(vsyncCallback);
GFX_INTERFACE(hsyncCallback);
GFX_INTERFACE(orientation);
GFX_INTERFACE(mirroring);
GFX_INTERFACE(colorMode);
GFX_INTERFACE(globalPalette);
GFX_INTERFACE(layerCount);
GFX_INTERFACE(layerActive);
GFX_INTERFACE(layerEnabled);
GFX_INTERFACE(layerVisible);
GFX_INTERFACE(layerVsync);
GFX_INTERFACE(layerInvalid);
GFX_INTERFACE(layerSwapSync);
GFX_INTERFACE(layerSwap);
GFX_INTERFACE(layerPosition);
GFX_INTERFACE(layerSize);
GFX_INTERFACE(layerAlphaEnable);
GFX_INTERFACE(layerAlphaAmount);
GFX_INTERFACE(layerMaskEnable);
GFX_INTERFACE(layerMaskColor);
GFX_INTERFACE(layerBufferCount);
GFX_INTERFACE(layerBufferAddress);
GFX_INTERFACE(layerBufferCoherent);
GFX_INTERFACE(layerBufferAllocated);
GFX_INTERFACE(layerBufferFree);

#if GFX_DRAW_PIPELINE_ENABLED

GFX_INTERFACE(drawPipelineMode);
GFX_INTERFACE(drawMode);
GFX_INTERFACE(drawColor);
GFX_INTERFACE(drawGradientColor);
GFX_INTERFACE(drawPalette);
GFX_INTERFACE(drawTarget);
GFX_INTERFACE(drawBlendMode);
GFX_INTERFACE(drawResizeMode);
GFX_INTERFACE(drawAlphaEnable);
GFX_INTERFACE(drawAlphaValue);
GFX_INTERFACE(drawMaskEnable);
GFX_INTERFACE(drawMaskValue);
GFX_INTERFACE(drawAntialias);
GFX_INTERFACE(drawThickness);
GFX_INTERFACE(drawClipEnable);
GFX_INTERFACE(drawClipRect);

#endif // GFX_DRAW_PIPELINE_ENABLED

typedef GFX_Result (*GFX_Interface_FnPtr)(va_list);

extern GFX_Interface_FnPtr GFX_InterfaceTable[GFX_NUM_FLAGS][2];

#endif /* GFX_INTERFACE_H */

//DOM-IGNORE-END