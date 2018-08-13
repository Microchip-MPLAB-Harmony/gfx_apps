/*******************************************************************************
 Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_draw.h

  Summary:
    Internal standard drawing help function definitions.
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
#ifndef GOL_DRAW_H
#define GOL_DRAW_H
//DOM-IGNORE-END

#include "gfx/libaria/inc/libaria_common.h"
#include "gfx/hal/inc/gfx_rect.h"

// *****************************************************************************
/* Function:
    void laDraw_LineBorder(GFX_Rect* rect, GFX_Color color)

   Summary:
    Internal utility function to draw a basic line border

   Parameters:
    GFX_Rect* rect - the rect to draw (screen space)
    GFX_Color color - the color to draw
*/
LIB_EXPORT void laDraw_LineBorder(GFX_Rect* rect, GFX_Color color);

// *****************************************************************************
/* Function:
    void laDraw_1x2BevelBorder(GFX_Rect* rect,
                               GFX_Color topColor,
                               GFX_Color bottomInnerColor,
                               GFX_Color bottomOuterColor)

   Summary:
    Internal utility function to draw a 1x2 bevel border

   Parameters:
    GFX_Rect* rect - the rect to draw (screen space)
    GFX_Color topColor - the color of the top left lines
    GFX_Color bottomInnerColor - the color of the bottom inner line
    GFX_Color bottomOuterColor - the color of the bottom outer line
*/
LIB_EXPORT void laDraw_1x2BevelBorder(GFX_Rect* rect,
                                      GFX_Color topColor,
                                      GFX_Color bottomInnerColor,
                                      GFX_Color bottomOuterColor);

// *****************************************************************************
/* Function:
    void laDraw_2x1BevelBorder(GFX_Rect* rect,
                               GFX_Color topOuterColor,
                               GFX_Color topInnerColor,
                               GFX_Color bottomOuterColor)

   Summary:
    Internal utility function to draw a 2x1 bevel border

   Parameters:
    GFX_Rect* rect - the rect to draw (screen space)
    GFX_Color topOuterColor - the color of the top outer line
    GFX_Color topInnerColor - the color of the top inner line
    GFX_Color bottomOuterColor - the color of the bottom lines
*/
LIB_EXPORT void laDraw_2x1BevelBorder(GFX_Rect* rect,
                                      GFX_Color topOuterColor,
                                      GFX_Color topInnerColor,
                                      GFX_Color bottomOuterColor);

// *****************************************************************************
/* Function:
    void laDraw_2x2BevelBorder(GFX_Rect* rect,
                               GFX_Color topOuterColor,
                               GFX_Color topInnerColor,
                               GFX_Color bottomInnerColor,
                               GFX_Color bottomOuterColor)

   Summary:
    Internal utility function to draw a 2x2 bevel border

   Parameters:
    GFX_Rect* rect - the rect to draw (screen space)
    GFX_Color topOuterColor - the color of the top outer line
    GFX_Color topInnerColor - the color of the top inner line
    GFX_Color bottomInnerColor - the color of the bottom inner line
    GFX_Color bottomOuterColor - the color of the bottom outer line
*/
LIB_EXPORT void laDraw_2x2BevelBorder(GFX_Rect* rect,
                                      GFX_Color topOuterColor,
                                      GFX_Color topInnerColor,
                                      GFX_Color bottomInnerColor,
                                      GFX_Color bottomOuterColor);

#endif /* GOL_DRAW_H */