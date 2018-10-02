/*******************************************************************************
 Module for Microchip Graphics Library - Hardware Abstraction Layer

  Company:
    Microchip Technology Inc.

  File Name:
    gfx_display.h

  Summary:
    Defines MPLAB Harmony Graphics Hardware Abstraction Layer display
    information struct

  Description:
    Display information.
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
#ifndef GFX_DISPLAY_H
#define GFX_DISPLAY_H
//DOM-IGNORE-END

#include "gfx/hal/inc/gfx_common.h"
#include "gfx/hal/inc/gfx_color.h"

// *****************************************************************************
/* Structure:
    GFX_DisplayInfo_t

  Summary:
    Describes a graphical display device.

  Description:
    name - a short human-readable name
    color_formats - mask of color formats this display supports
    rect - the size of the display   

  Remarks:
    None.
*/
typedef struct GFX_DisplayInfo_t
{
    const char name[16];
    
    GFX_ColorMask color_formats;

    GFX_Rect rect;
    
    struct attributes_t
    {        
        int8_t data_width;
        
        struct horizontal_t
        {
            int8_t pulse_width;
            int8_t back_porch;
            int8_t front_porch;
        } horz;
        
        struct vertical_t
        {
            int8_t pulse_width;
            int8_t back_porch;
            int8_t front_porch;
        } vert;
        
        int32_t inv_left_shift;
          
    } attributes;
} GFX_DisplayInfo;

//DOM-IGNORE-BEGIN
// internal use only
LIB_EXPORT GFX_DisplayInfo* GFX_DisplayInfoPtrGet(GFX_Display idx);
//DOM-IGNORE-END

#endif /* GFX_DISPLAY_H */