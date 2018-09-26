/*******************************************************************************
 Module for Microchip Graphics Library - Graphics Utilities Library

  Company:
    Microchip Technology Inc.

  File Name:
    gfx_font.h

  Summary:
    Describes font assets

  Description:
    Type definitions.
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
#ifndef GFX_FONT_H
#define GFX_FONT_H
//DOM-IGNORE-END

#include "gfx/utils/inc/gfxu_global.h"

// *****************************************************************************
/* Enumeration:
    GFXU_FontAssetBPP

  Summary:
    Indicates the bits per pixel mode of a font
*/
typedef enum GFXU_FontAssetBPP
{
    GFXU_FONT_BPP_1, // standard
    GFXU_FONT_BPP_8  // antialiased
} GFXU_FontAssetBPP;

// *****************************************************************************
/* Structure:
    GFXU_FontGlyphRange_t

  Summary:
    Describes a range of glyphs for a font.  All IDs are in raw code points and
    are not encoded in any way
    
    glyphCount - number of glyphs in the range
    startID - the starting glyph id
    endID - the ending glyph id
    lookupTable - the corresponding look up table to find the glyph raster data
*/
typedef struct GFXU_FontGlyphRange_t
{
    uint32_t glyphCount;
    uint32_t startID;
    uint32_t endID;
    uint8_t* lookupTable;
} GFXU_FontGlyphRange;

// *****************************************************************************
/* Structure:
    GFXU_FontGlyphIndexTable_t

  Summary:
    Describes a font glyph index table.  Essentially a series of glyph look up
    tables where each non-consecutive range of glyphs occupies one range entry
    
    count - number of ranges in the index table
    ranges - the glyph range array
*/
typedef struct GFXU_FontGlyphIndexTable_t
{
    uint32_t count;
    GFXU_FontGlyphRange ranges[];    
} GFXU_FontGlyphIndexTable;

// *****************************************************************************
/* Structure:
    GFXU_FontAsset_t

  Summary:
    Describes a font asset.  A font asset is a series of raster images that
    represet linguistic characters.  These characters are referenced by an index
    called a 'code point'.  This code point is 1-4 bytes in length.  Code points
    may be encoded to save space.  Fonts also contain kerning data that describes
    character positioning data.
    
    header - standard asset header
    height - font height in pixels
    ascent - font ascent in pixels
    descent - font descent in pixels
    baseline - font baseline in pixels
    bpp - font pixel size, either 1 or 8.  8 is for anti-aliased font data
    indexTable - pointer to the corresponding glyph index table.  this table
                 is used to reference code points to glyph data.
*/
typedef struct GFXU_FontAsset_t
{
    GFXU_AssetHeader header;
    uint32_t height;
    uint32_t ascent;
    uint32_t descent;
    uint32_t baseline;
    GFXU_FontAssetBPP bpp; 
    GFXU_FontGlyphIndexTable* indexTable;
} GFXU_FontAsset;

#endif /* GFX_FONT_H */