/*******************************************************************************
 Module for Microchip Graphics Library - Graphics Utilities Library

  Company:
    Microchip Technology Inc.

  File Name:
    gfx_image_utils.h

  Summary:
    Image return utilities

  Description:
    Internal library use only
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
#ifndef GFXU_IMAGE_UTILS_H
#define GFXU_IMAGE_UTILS_H
//DOM-IGNORE-END

#include "gfx/utils/inc/gfxu_image.h"

// internal use only
uint32_t getRLEDataAtIndex(uint8_t* data,
                           uint32_t max,
                           uint32_t idx,
                           uint32_t* startBlock,
                           uint32_t* startOffset);

// internal use only                        
uint32_t getDiscreteValueAtIndex(uint32_t index, uint32_t value, GFX_ColorMode mode);

// internal use only
uint32_t getOffsetFromIndexAndBPP(uint32_t index, GFX_BitsPerPixel bpp);

// internal use only
GFX_Result convertColorAndSetDraw(uint32_t color, GFX_ColorMode mode);

// internal use only
void createDefaultMemIntf(GFXU_MemoryIntf* memIntf);

#endif /* GFXU_IMAGE_UTILS_H */