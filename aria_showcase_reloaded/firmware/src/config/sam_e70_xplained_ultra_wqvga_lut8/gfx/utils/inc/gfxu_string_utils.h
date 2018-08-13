/*******************************************************************************
 Module for Microchip Graphics Library - Graphics Utilities Library

  Company:
    Microchip Technology Inc.

  File Name:
    gfx_string_utils.h

  Summary:
    Contains definitions for various internal string utility functions.

  Description:
    Internal use only
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

#ifndef GFXU_STRING_UTILS_H
#define GFXU_STRING_UTILS_H
//DOM-IGNORE-END

#include "gfx/utils/inc/gfxu_string.h"
#include "gfx/utils/inc/gfxu_font.h"

// internal use only
uint16_t GFXU_StringIndexLookup(GFXU_StringTableAsset* table,
                                uint32_t stringID,
                                uint32_t languageID);

// internal use only                                
GFX_Result GFXU_StringLookup(GFXU_StringTableAsset* table,
                             uint32_t stringIndex,
                             uint8_t** stringAddress,
                             uint32_t* stringSize);

// internal use only
LIB_EXPORT GFXU_FontAsset* GFXU_StringFontIndexLookup(GFXU_StringTableAsset* table,
                                                      uint32_t stringID,
                                                      uint32_t languageID);

// internal use only
GFX_Result GFXU_FontGetLookupTableEntry(uint8_t* table,
                                        uint32_t index,
                                        uint32_t max,
                                        uint32_t* offset,
                                        uint32_t* width);

// internal use only
GFX_Result GFXU_FontGetGlyphInfo(GFXU_FontAsset* fnt,
                                 uint32_t glyph,
                                 uint32_t* offset,
                                 uint32_t* width);

// internal use only
GFX_Result GFXU_DecodeUTF8(uint8_t* val,
                           uint32_t max,
                           uint32_t* codePoint,
                           uint32_t* size);

// internal use only                           
GFX_Result GFXU_DecodeUTF16(uint8_t* val,
                            uint32_t max,
                            uint32_t* codePoint,
                            uint32_t* size);

// internal use only                            
GFX_Result GFXU_DecodeCodePoint(uint32_t encoding,
                                uint8_t* data,
                                uint32_t max,
                                uint32_t* codePoint,
                                uint32_t* offset);                             

// internal use only                            
GFX_Result GFXU_DecodeAndDrawString(uint8_t* string,
                                    uint32_t length,
                                    GFXU_StringEncodingMode mode,
                                    GFXU_FontAsset* fnt,
                                    int32_t clipX,
                                    int32_t clipY,
                                    int32_t clipWidth,
                                    int32_t clipHeight,
                                    int32_t x,
                                    int32_t y);

// internal use only 
GFX_Result GFXU_DecodeAndDrawSubString(uint8_t* string,
                                    uint32_t length,
                                    GFXU_StringEncodingMode mode,
                                    GFXU_FontAsset* fnt,
									uint32_t start,
                                    uint32_t end,
                                    int32_t clipX,
                                    int32_t clipY,
                                    int32_t clipWidth,
                                    int32_t clipHeight,
                                    int32_t x,
                                    int32_t y);

// internal use only
int32_t GFXU_DrawGlyph(GFXU_FontAsset* fnt,
                       uint32_t glyph,
                       int32_t clipX,
                       int32_t clipY,
                       int32_t clipWidth,
                       int32_t clipHeight,
                       int32_t x,
                       int32_t y);

// internal use only
int32_t GFXU_GetGlyphRowDataSize(GFXU_FontAssetBPP bpp,
                                 int32_t width);

// internal use only                                 
void GFXU_DrawGlyphRow(GFXU_FontAssetBPP bpp,
                       uint8_t* data,
                       int32_t width,
                       int32_t x,
                       int32_t y,
                       int32_t clipXStart,
                       int32_t clipXEnd);

// internal use only                             
int32_t GFXU_DrawUnknownGlyph(int32_t x,
                           int32_t y,
                           int32_t height,
                           int32_t clipX,
                           int32_t clipY,
                           int32_t clipWidth,
                           int32_t clipHeight);

#endif /* GFXU_STRING_UTILS_H */