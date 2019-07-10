/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#include "gfx/legato/string/legato_string.h"

#include <string.h>

#include "gfx/legato/asset/legato_font.h"
#include "gfx/legato/core/legato_state.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/renderer/legato_renderer.h"

static leStringVTable stringVTable;

#define LE_STRING_SPACE     0x20 // ' '
#define LE_STRING_LINEBREAK 0xA // '\n'

void _leString_Constructor(leString* str)
{
    
}

void _leString_Destructor(leString* str)
{
    
}


leResult _leString_GetRect(const leString* str,
                           leRect* rect)
{
    uint32_t idx;
    uint32_t len, lines;
    leRect lineRect;
    
    *rect = leRect_Zero;
    
    if(str == NULL)
        return LE_FAILURE;
        
    len = str->fn->length(str);
    
    if(len == 0)
    {
        return LE_SUCCESS;
    }
        
    lines = str->fn->getLineCount(str);
    
    for(idx = 0; idx < lines; idx++)
    {
        str->fn->getLineRect(str, idx, &lineRect);
        
        if(idx < lines - 1)
        {
            rect->height += str->fn->getFont(str)->height;
        }
        else
        {
            rect->height += lineRect.height;
        }
        
        if(rect->width < lineRect.width)
        {
            rect->width = lineRect.width;
        }
    }
    
    return LE_SUCCESS;
}

uint32_t _leString_GetLineCount(const leString* str)
{
    uint32_t len;
    uint32_t idx;
    uint32_t count;
    leChar chr;
    
    len = str->fn->length(str);
    
    count = 1;
    
    if(len == 0)
        return count;
        
    for(idx = 0; idx < len; idx++)
    {
        chr = str->fn->charAt(str, idx);
        
        if(chr == LE_STRING_LINEBREAK)
        {
            count += 1;
        }
    }
    
    return count;
}

leResult _leString_GetLineIndices(const leString* str,
                                  uint32_t line,
                                  uint32_t* start,
                                  uint32_t* end)
{
    uint32_t idx;
    uint32_t len;
    uint32_t count;
    leChar chr;
    
    if(str == NULL)
        return LE_FAILURE;
        
    len = str->fn->length(str);
    
    if(len == 0 || line >= str->fn->getLineCount(str))
        return LE_FAILURE;
        
    count = 0;
    
    *start = 0;
    *end = 0;
        
    for(idx = 0; idx < len; idx++)
    {
        chr = str->fn->charAt(str, idx);
        
        if(chr == LE_STRING_LINEBREAK)
        {
            *end = idx;
            
            if(count == line)
                return LE_SUCCESS;
                
            count += 1;
                
            /* TODO test this */
            *start = idx + 1;
        }
    }
    
    *end = len;
    
    return LE_SUCCESS;
}

leResult _leString_GetLineRect(const leString* str,
                               uint32_t line,
                               leRect* rect)
{
    uint32_t idx;
    uint32_t len;
    leFont* fnt;
    leFontGlyph glyph;
    uint32_t startIdx, endIdx;
    leChar chr;
    
    *rect = leRect_Zero;
    
    if(str == NULL)
        return LE_FAILURE;
        
    len = str->fn->length(str);
    fnt = str->fn->getFont(str);
    
    if(len == 0 || fnt == NULL || line >= str->fn->getLineCount(str))
        return LE_FAILURE;
        
    if(fnt->glyphTable == NULL)
        return LE_FAILURE;
    
    str->fn->getLineIndices(str, line, &startIdx, &endIdx);
    
    for(idx = startIdx; idx < endIdx; idx++)
    {
        chr = str->fn->charAt(str, idx);
        
        leFont_GetGlyphInfo(fnt, chr, &glyph);
            
        rect->width += glyph.advance;
    }
    
    rect->height = fnt->height;
    
    return LE_SUCCESS;
}

leResult _leString_GetCharRect(const leString* str,
                               uint32_t charIdx,
                               leRect* rect)
{
    uint32_t idx;
    uint32_t len;
    leFont* fnt;
    leFontGlyph glyph;
    leChar chr;
    
    *rect = leRect_Zero;
    
    if(str == NULL)
        return LE_FAILURE;
        
    len = str->fn->length(str);
    fnt = str->fn->getFont(str);
    
    if(len == 0 || fnt == NULL || charIdx >= len)
        return LE_FAILURE;
        
    if(fnt->glyphTable == NULL)
        return LE_FAILURE;
    
    for(idx = 0; idx < len; idx++)
    {
        chr = str->fn->charAt(str, idx);
        
        if(chr == LE_STRING_LINEBREAK)
        {
            //rect->x = 0;
            //rect->y += fnt->height + linePadding;
        }
        else if(idx == charIdx)
        {
            leFont_GetGlyphInfo(fnt, chr, &glyph);
            
            rect->width = glyph.advance;
            rect->height = fnt->height;
            
            return LE_SUCCESS;
        }
        else
        {
            leFont_GetGlyphInfo(fnt, chr, &glyph);            
            
            rect->x += glyph.advance;
        }
    }
    
    return LE_FAILURE;
}

// TODO does not support multiline
leResult _leString_GetCharIndexAtPoint(const leString* str,
                                       lePoint* pt,
                                       uint32_t* charIdx)
{
    uint32_t idx;
    uint32_t len;
    leFont* fnt;
    leFontGlyph glyph;
    leChar chr;
    leRect rect;
    
    rect.x = 0;
    rect.y = 0;

    *charIdx = 0;
    
    if(str == NULL || pt->x < 0 || pt->y < 0)
        return LE_FAILURE;
        
    len = str->fn->length(str);
    fnt = str->fn->getFont(str);
    
    if(len == 0 || fnt == NULL)
        return LE_SUCCESS;

    for(idx = 0; idx < len; idx++)
    {
        chr = str->fn->charAt(str, idx);
        
        if(chr == LE_STRING_LINEBREAK)
        {
            rect.x = 0;
            rect.y += fnt->height;
        }
        else
        {
            leFont_GetGlyphInfo(fnt, chr, &glyph);            
            
            rect.width = glyph.advance;
            rect.height = glyph.height;
            
            if(leRectContainsPoint(&rect, pt) == LE_TRUE)
            {
                *charIdx = idx;
                
                return LE_SUCCESS;
            }
                
            rect.x += glyph.advance;
        }
    }

    return LE_FAILURE;
}

static leResult drawInternalString(const leString* str,
                                   int32_t x,
                                   int32_t y,
                                   leHAlignment align,
                                   leColor clr,
                                   uint32_t a)
{
    uint32_t charItr, len, lines, lineItr;
    leFont* fnt = str->fn->getFont(str);
    leFontGlyph glyphInfo;
    leChar codePoint;
    int32_t stringY, lineX;
    leRect stringRect, lineRect;
    uint32_t startIdx, endIdx;
    //leRect drawRect;
    
    len = str->fn->length(str);
    
    if(len == 0)
        return 0;
        
    stringY = y;
    
    lines = str->fn->getLineCount(str);
    
    str->fn->getRect(str, &stringRect);
    
    //drawRect = stringRect;
    //drawRect.x += x;
    //drawRect.y += y;    
    
    //leRenderer_RectLine(&drawRect, clr);
    
    for(lineItr = 0; lineItr < lines; lineItr++)
    {
        str->fn->getLineIndices(str, lineItr, &startIdx, &endIdx);
        str->fn->getLineRect(str, lineItr, &lineRect);
        
        if(align == LE_HALIGN_CENTER)
        {
            lineX = stringRect.x + (stringRect.width / 2) - (lineRect.width / 2);
        }
        else if(align == LE_HALIGN_RIGHT)
        {
            lineX = stringRect.x + stringRect.width - lineRect.width; 
        }
        else
        {
            lineX = stringRect.x;
        }
        
        for(charItr = startIdx; charItr < endIdx; charItr++)
        {
            codePoint = str->fn->charAt(str, charItr);
            
            leFont_GetGlyphInfo(fnt, codePoint, &glyphInfo);
            
            if(codePoint == LE_STRING_SPACE)
            {
                
            }
            else
            {
                leFont_DrawGlyph(fnt,
                                 &glyphInfo,
                                 x + lineX + glyphInfo.bearingX,
                                 stringY + (fnt->baseline - glyphInfo.bearingY),
                                 clr,
                                 a);
            }
                             
            lineX += glyphInfo.advance;
        }
        
        stringY += fnt->height;
    }
    
    return LE_SUCCESS;
}
                          

leResult _leString_Draw(const leString* str,
                        int32_t x,
                        int32_t y,
                        leHAlignment align,
                        leColor clr,
                        uint32_t a)
{
    if(str->fn->getFont(str) == NULL)
        return LE_FAILURE;
        
#if LE_EXTERNAL_STREAMING_ENABLED == 1
    if(str->font->header.dataLocation == LE_ASSET_LOCATION_INTERNAL)
    {
#endif
        return drawInternalString(str,
                                  x,
                                  y,
                                  align,
                                  clr,
                                  a);
                                  
#if LE_EXTERNAL_STREAMING_ENABLED == 1
    }
    else
    {
        return LE_FAILURE;
#if 0
        //TODO: Implement substring draw
        return leDrawStringBufferExternal(str,
                                          x,
                                          y,
                                          memoryInterface,
                                          reader);
#endif
    }
#endif
}

void _leString_GenerateVTable()
{
    stringVTable.getRect = _leString_GetRect;
    stringVTable.getLineCount = _leString_GetLineCount;
    stringVTable.getLineRect = _leString_GetLineRect;
    stringVTable.getLineIndices = _leString_GetLineIndices;
    stringVTable.getCharRect = _leString_GetCharRect;
    stringVTable.getCharIndexAtPoint = _leString_GetCharIndexAtPoint;
    stringVTable._draw = _leString_Draw;
}

void _leString_FillVTable(leStringVTable* vt)
{
    *vt = stringVTable;
}


#if 0
void leString_GetRect(leString* str, leRect* rect)
{
    if(rect == NULL)
        return;
        
    rect->x = 0;
    rect->y = 0;
    rect->width = 0;
    rect->height = 0;
    
    if(str == NULL)
        return;
    
    if(str->table_index != LE_STRING_NULLIDX)
    {
        leGetStringRect(leGetState()->stringTable,
                        str->table_index,
                        leGetState()->languageID,
                        rect);
    }
    else
    {
        if(str->font == NULL)
            return;
            
        rect->x = 0;
        rect->y = 0;
        rect->height = str->font->height;
        rect->width = leCalculateCharStringWidth(str->data, str->font);
    }
}

void leString_GetLineRect(leString* str, uint32_t start, leRect* rect, uint32_t * end)
{
    if(rect == NULL)
        return;

    rect->x = 0;
    rect->y = 0;
    rect->width = 0;
    rect->height = 0;

    if(str == NULL)
        return;

    if(str->table_index != LE_STRING_NULLIDX)
    {
		*end = leGetStringLineRect(leGetState()->stringTable, 
                                      str->table_index,
                                      leGetState()->languageID,
                                      start,
                                      rect);
    }
    else
    {
        if(str->font == NULL)
            return;

        *end = leGetCharStringLineRect(str->data,
                                          str->font,
                                          start,
                                          rect);
    }
}

void leString_GetMultiLineRect(leString* str, leRect* rect, int32_t lineSpace)
{
    uint32_t offset = 0, newoffset = 0;
    leRect lineRect;

    rect->height = 0;
    rect->width = 0;

    while (1)
	{
		offset = newoffset;

		leString_GetLineRect(str, offset, &lineRect, &newoffset);

        //At end of string
        if (offset == newoffset)
        {
            if (lineSpace >= 0)
                rect->height += lineSpace;
            else
                rect->height += leString_GetHeight(str) - leString_GetAscent(str);                
            break;
        }

        if (lineSpace >= 0)
            rect->height += lineSpace;
        else
            rect->height += leString_GetAscent(str);
        

		if (lineRect.width > rect->width)
		{
			rect->width = lineRect.width;
		}
	}
}

uint32_t leString_GetHeight(leString* str)
{
    if(str == NULL)
        return 0;
    
    if(str->table_index != LE_STRING_NULLIDX)
    {
        return leGetStringHeight(leGetState()->stringTable,
                                 str->table_index,
                                 leGetState()->languageID);
    }
    else
    {
        if(str->font == NULL)
            return 0;
            
        return str->font->height;
    }
    
    return 0;
}

uint32_t leString_GetAscent(leString* str)
{
    if(str == NULL)
        return 0;
    
    if(str->table_index != LE_STRING_NULLIDX)
    {
        return leGetStringAscent(leGetState()->stringTable,
                                    str->table_index,
                                    leGetState()->languageID);
    }
    else
    {
        if(str->font == NULL)
            return 0;
            
        return str->font->ascent;
    }
    
    return 0;
}

uint32_t leString_GetCharOffset(leString* str, uint32_t idx)
{
    if(str->table_index != LE_STRING_NULLIDX)
    {
        return leCalculatePartialStringWidth(leGetState()->stringTable,
                                                str->table_index,
                                                leGetState()->languageID,
                                                idx);
    }
    else
    {
        if(str->font == NULL)
            return 0;
            
        return leCalculatePartialCharStringWidth(str->data, str->font, idx);
    }
}

uint32_t leString_GetCharIndexAtPoint(leString* str, int32_t x)
{
    int32_t last, curr, width, length;
    int32_t i;
    
    length = leString_Length(str);
    
    if(x < 0)
        return 0;
    
    last = 0;
        
    for(i = 0; i < length; i++)
    {
        width = leString_GetCharWidth(str, i);
        curr = last + width;
        
        if(x < curr)
        {
            if(x - last < curr - x)
                return i;
            else
                return i + 1;
        }
        
        last = curr;
    }
    
    return length;
}

uint32_t leString_GetCharWidth(leString* str, uint32_t idx)
{
    leChar chr;
    leFont* ast;
    
    if(str->table_index == LE_STRING_NULLIDX)
    {
        return leGetCharWidth(str->data[idx], str->font);
    }
    else
    {
        chr = leGetCharAt(leGetState()->stringTable,
                             str->table_index,
                             leGetState()->languageID,
                             idx);
                             
        ast = leStringFontIndexLookup(leGetState()->stringTable,
                                         str->table_index,
                                         leGetState()->languageID);
                             
        return leGetCharWidth(chr, ast);
    }
}

#endif