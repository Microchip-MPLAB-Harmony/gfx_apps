/*******************************************************************************
 Module for Microchip Graphics Library - Hardware Abstraction Layer

  Company:
    Microchip Technology Inc.

  File Name:
    gfx_processor_interface.h

  Summary:
    Defines MPLAB Harmony Graphics Hardware Abstraction Layer graphics
    processor interface struct

  Description:
    Graphics processor information, internal use.
*******************************************************************************/

// DOM-IGNORE-BEGIN
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
#ifndef GFX_PROCESSOR_IMPL_H
#define GFX_PROCESSOR_IMPL_H
//DOM-IGNORE-END

#include "gfx/hal/inc/gfx_common.h"
#include "gfx/hal/inc/gfx_color.h"
#include "gfx/hal/inc/gfx_context.h"
#include "gfx/hal/inc/gfx_util.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Structure:
    GFX_ProcessorInfo_t

  Summary:
    A processor description structure.

  Description:
    name - a short human-readable name.
    color formats - a mask of supported color formats

  Remarks:
    None.
*/
typedef struct GFX_ProcessorInfo_t
{
    char name[16];
    
    GFX_ColorMask color_formats;
} GFX_ProcessorInfo;

// DOM-IGNORE-BEGIN

/* gets capability information from the processor */
typedef GFX_Result (*GFX_ProcessorInfoGet_FnPtr)(GFX_ProcessorInfo*);

/* creates a context of the driver */
typedef GFX_Result (*GFX_ProcessorContextCreate_FnPtr)(GFX_Context* context);

typedef struct GFX_ProcessorIntf_t
{
    GFX_ProcessorInfoGet_FnPtr       infoGet;
    GFX_ProcessorContextCreate_FnPtr contextInitialize;
} GFX_ProcessorIntf;

extern GFX_ProcessorIntf GFX_ProcessorInterfaces[];

// this is typically created and called automatically by a code generator
// internal use only
GFX_Result         GFX_InitializeProcessorList(void);
GFX_Result         GFX_ProcessorIntfInitialize(void);
GFX_Result         GFX_ProcessorIntfGet(GFX_Processor idx, GFX_ProcessorIntf* iface);
GFX_ProcessorIntf* GFX_ProcessorIntfPtrGet(GFX_Processor idx);

// DOM-IGNORE-END

#endif /* GFX_PROCESSOR_IMPL_H */