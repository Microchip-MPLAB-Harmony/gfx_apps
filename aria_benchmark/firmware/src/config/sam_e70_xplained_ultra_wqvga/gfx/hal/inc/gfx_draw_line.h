// DOM-IGNORE-BEGIN

/*******************************************************************************
 Module for Microchip Graphics Library - Hardware Abstraction Layer

  Company:
    Microchip Technology Inc.

  File Name:
    gfx_draw_line.h

  Summary:
    Line and gradient functions.

  Description:
    Line and gradient drawing, internal use.
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
#ifndef GFX_DRAW_LINE_H
#define GFX_DRAW_LINE_H

#include "gfx/hal/inc/gfx_common.h"

#if GFX_DRAW_PIPELINE_ENABLED

typedef struct GFX_DrawState_t GFX_DrawState;

// internal use only
GFX_Result cpuDrawLine(const GFX_Point* p1,
                       const GFX_Point* p2,
                       const GFX_DrawState* state);

// internal use only                
GFX_Result cpuDrawLine_Normal(const GFX_Point* p1,
                              const GFX_Point* p2,
                              const GFX_DrawState* state);

// internal use only                
GFX_Result cpuDrawLine_Thick(const GFX_Point* p1,
                             const GFX_Point* p2,
                             const GFX_DrawState* state);

// internal use only                         
GFX_Result cpuDrawLine_Thick_AA(const GFX_Point* p1,
                                const GFX_Point* p2,
                                const GFX_DrawState* state);

// internal use only                            
GFX_Result cpuDrawLine_AA(const GFX_Point* p1,
                          const GFX_Point* p2,
                          const GFX_DrawState* state);

// internal use only                      
GFX_Result cpuDrawLine_Gradient(const GFX_Point* p1,
                                const GFX_Point* p2,
                                const GFX_DrawState* state);

// internal use only                                
GFX_Result cpuDrawLine_Gradient_AA(const GFX_Point* p1,
                                   const GFX_Point* p2,
                                   const GFX_DrawState* state);                                

// internal use only                               
GFX_Result cpuDrawLine_Horz(const GFX_Point* p1,
                            const GFX_Point* p2,
                            const GFX_DrawState* state);


// internal use only                       
GFX_Result cpuDrawLine_Vert(const GFX_Point* p1,
                            const GFX_Point* p2,
                            const GFX_DrawState* state);   
                           
#endif // GFX_DRAW_PIPELINE_ENABLED                              
#endif /* GFX_DRAW_LINE_H */                              

//DOM-IGNORE-END
