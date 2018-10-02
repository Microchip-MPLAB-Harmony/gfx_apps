/*******************************************************************************
 Module for Microchip Graphics Library - Graphics Utilities Library

  Company:
    Microchip Technology Inc.

  File Name:
    gfx_palette.h

  Summary:
    Defines palette assets

  Description:
    Get palette color
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

#ifndef GFXU_PALETTE_H
#define GFXU_PALETTE_H
//DOM-IGNORE-END

#include "gfx/utils/inc/gfxu_global.h"

// *****************************************************************************
/* Structure:
    GFXU_PaletteAsset_t

  Summary:
    Describes a palette asset.  A palette is a lookup table for unique colors.
    Given in an index, a color can be retrieved.
    
    header - standard asset header
    colorCount - the number of colors contained in the palette
    colorMode - the color mode of the image
*/
typedef struct GFXU_PaletteAsset_t
{
    GFXU_AssetHeader header;
    uint32_t colorCount;
    GFX_ColorMode colorMode;
} GFXU_PaletteAsset;

// *****************************************************************************
/* Function:
    GFX_Result GFXU_PaletteGetColor(void);

  Summary:
    Gets a color from a palette asset given an index value.
     
  Parameters:
    GFXU_PaletteAsset* pal - pointer to the palette to read
    uint32_t idx - the index of the color to look up
    GFXU_MemoryIntf* read_cb - a pointer to a memory interface to use for
                               memory operations, not needed for internal
                               assets
    GFXU_ExternalAssetReader** reader - will return as a valid pointer if
                          the palette asset is located in an external source.
                          If this is the case then the caller is responsible
                          for servicing the external asset reader state
                          machine until completion.  The caller is then
                          responsible for freeing the reader's memory.
  Returns:
    GFX_Color - the color that was retrieved
*/
GFX_Color GFXU_PaletteGetColor(GFXU_PaletteAsset* pal,
                               uint32_t idx,
                               GFXU_MemoryIntf* read_cb,
                               GFXU_ExternalAssetReader** reader);


#endif /* GFXU_PALETTE_H */