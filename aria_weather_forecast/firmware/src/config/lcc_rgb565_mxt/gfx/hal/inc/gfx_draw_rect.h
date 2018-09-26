// DOM-IGNORE-BEGIN

/*******************************************************************************
 Module for Microchip Graphics Library - Hardware Abstraction Layer

  Company:
    Microchip Technology Inc.

  File Name:
    gfx_draw_rect.h

  Summary:
    Rectangle draw functions.

  Description:
    Rectangle with Gradient draw functions, internal use.
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
#ifndef GFX_DRAW_RECT_H
#define GFX_DRAW_RECT_H

#include "gfx/hal/inc/gfx_common.h"

typedef struct GFX_DrawState_t GFX_DrawState;

// DOM-IGNORE-BEGIN

// internal use only
GFX_Result cpuDrawRect_Line(const GFX_Rect* rect,
                            const GFX_DrawState* state);

// internal use only
GFX_Result cpuDrawRect_Fill(const GFX_Rect* rect,
                            const GFX_DrawState* state);

// internal use only
GFX_Result cpuDrawRect_Gradient_LeftRight(const GFX_Rect* rect,
                                          const GFX_DrawState* state);

// internal use only
GFX_Result cpuDrawRect_Gradient_TopBottom(const GFX_Rect* rect,
                                          const GFX_DrawState* state);

// internal use only
GFX_Result cpuDrawRect_Gradient_Quad(const GFX_Rect* rect,
                                     const GFX_DrawState* state);

// internal use only
GFX_Result cpuDrawRect_Line_AA(const GFX_Rect* rect,
                               const GFX_DrawState* state);

// internal use only
GFX_Result cpuDrawRect_Fill_AA(const GFX_Rect* rect,
                               const GFX_DrawState* state);

// internal use only
GFX_Result cpuDrawRect_Gradient_Bi_AA(const GFX_Rect* rect,
                                      const GFX_DrawState* state);

// internal use only
GFX_Result cpuDrawRect_Gradient_Quad_AA(const GFX_Rect* rect,
                                        const GFX_DrawState* state);

// DOM-IGNORE-END

#endif /* GFX_DRAW_RECT_H */

//DOM-IGNORE-END