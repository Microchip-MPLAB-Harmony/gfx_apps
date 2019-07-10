#include "gfx/legato/string/legato_stringutils.h"

#include "gfx/legato/common/legato_rect.h"

#define ASCII_SPACE 0x20
#define ASCII_MIN   0x20
#define ASCII_MAX   0x7E

#define LINE_BREAK  0xA

uint32_t leStringUtils_FromCStr(const char* str,
                                leChar* buf,
                                uint32_t size)
{
    uint32_t len, itr;

    if(str == NULL || buf == NULL)
        return LE_FAILURE;

    len = strlen(str);

    for(itr = 0; itr < len; itr++)
    {
        if(itr >= size)
            break;

        buf[itr] = str[itr];
    }

    return itr;
}

uint32_t leStringUtils_ToCStr(const leChar* str,
                              uint32_t strSize,
                              char* buf,
                              uint32_t bufSize)
{
    uint32_t itr;

    if(str == NULL || strSize == 0 || buf == NULL || bufSize == 0)
        return LE_FAILURE;

    for(itr = 0; itr < strSize; itr++)
    {
        if(itr >= bufSize)
            break;

        if(str[itr] >= ASCII_MIN && str[itr] <= ASCII_MAX)
        {
            buf[itr] = (char)str[itr];
        }
        else
        {
            buf[itr] = ASCII_SPACE;
        }
    }

    return itr;
}

leResult leStringUtils_GetRect(const leChar* str,
                               uint32_t size,
                               const leFont* font,
                               leRect* rect)
{
    uint32_t idx;
    uint32_t lines;
    leRect lineRect;

    *rect = leRect_Zero;

    if(str == NULL)
        return LE_FAILURE;

    if(size == 0)
        return LE_SUCCESS;

    lines = leStringUtils_GetLineCount(str, size);

    for(idx = 0; idx < lines; idx++)
    {
        leStringUtils_GetLineRect(str, size, font, idx, &lineRect);

        if(idx < lines - 1)
        {
            rect->height += font->height;
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

leResult leStringUtils_GetRectCStr(const char* str,
                                   const leFont* font,
                                   leRect* rect)
{
    uint32_t idx;
    uint32_t lines;
    leRect lineRect = leRect_Zero;
    uint32_t size;

    *rect = leRect_Zero;

    if(str == NULL)
        return LE_FAILURE;

    size = strlen(str);

    if(size == 0)
        return LE_SUCCESS;

    lines = leStringUtils_GetLineCountCStr(str);

    for(idx = 0; idx < lines; idx++)
    {
        leStringUtils_GetLineRectCStr(str, font, idx, &lineRect);

        if(idx < lines - 1)
        {
            rect->height += font->height;
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

uint32_t leStringUtils_GetLineCount(const leChar* str,
                                    uint32_t size)
{
    uint32_t idx;
    uint32_t count;

    if(str == NULL || size == 0)
        return 0;

    count = 1;

    for(idx = 0; idx < size; idx++)
    {
        if(str[idx] == LINE_BREAK)
        {
            count += 1;
        }
    }

    return count;
}

uint32_t leStringUtils_GetLineCountCStr(const char* str)
{
    uint32_t idx;
    uint32_t count;
    uint32_t size;

    if(str == NULL)
        return 0;

    size = strlen(str);

    if(size == 0)
        return LE_FAILURE;

    count = 1;

    for(idx = 0; idx < size; idx++)
    {
        if(str[idx] == LINE_BREAK)
        {
            count += 1;
        }
    }

    return count;
}

leResult leStringUtils_GetLineIndices(const leChar* str,
                                      uint32_t size,
                                      uint32_t line,
                                      uint32_t* start,
                                      uint32_t* end)
{
    uint32_t idx;
    uint32_t count;

    if(str == NULL)
        return LE_FAILURE;

    if(size == 0 || line >= leStringUtils_GetLineCount(str, size))
        return LE_FAILURE;

    count = 0;

    *start = 0;
    *end = 0;

    for(idx = 0; idx < size; idx++)
    {
        if(str[idx] == LINE_BREAK)
        {
            *end = idx;

            if(count == line)
                return LE_SUCCESS;

            count += 1;

            /* TODO test this */
            *start = idx + 1;
        }
    }

    *end = size;

    return LE_SUCCESS;
}

leResult leStringUtils_GetLineIndicesCStr(const char* str,
                                          uint32_t line,
                                          uint32_t* start,
                                          uint32_t* end)
{
    uint32_t idx;
    uint32_t count;
    uint32_t size;

    if(str == NULL)
        return LE_FAILURE;

    size = strlen(str);

    if(size == 0 || line >= leStringUtils_GetLineCountCStr(str))
        return LE_FAILURE;

    count = 0;

    *start = 0;
    *end = 0;

    for(idx = 0; idx < size; idx++)
    {
        if(str[idx] == LINE_BREAK)
        {
            *end = idx;

            if(count == line)
                return LE_SUCCESS;

            count += 1;

            /* TODO test this */
            *start = idx + 1;
        }
    }

    *end = size;

    return LE_SUCCESS;
}

leResult leStringUtils_GetLineRect(const leChar* str,
                                   uint32_t size,
                                   const leFont* font,
                                   uint32_t line,
                                   leRect* rect)
{
    uint32_t idx;
    leFontGlyph glyph;
    uint32_t startIdx = 0;
    uint32_t endIdx = 0;

    if(str == NULL ||
        size == 0 ||
        font == NULL ||
        font->glyphTable == NULL ||
        rect == NULL)
    {
        return LE_FAILURE;
    }

    *rect = leRect_Zero;

    if(line >= leStringUtils_GetLineCount(str, size))
    {
        return LE_FAILURE;
    }

    leStringUtils_GetLineIndices(str, size, line, &startIdx, &endIdx);

    for(idx = startIdx; idx < endIdx; idx++)
    {
        leFont_GetGlyphInfo(font, str[idx], &glyph);

        rect->width += glyph.advance;
    }

    rect->height = font->height;

    return LE_SUCCESS;
}

leResult leStringUtils_GetLineRectCStr(const char* str,
                                       const leFont* font,
                                       uint32_t line,
                                       leRect* rect)
{
    uint32_t idx;
    leFontGlyph glyph;
    uint32_t startIdx = 0;
    uint32_t endIdx = 0;
    uint32_t size;

    if(str == NULL ||
        font == NULL ||
        font->glyphTable == NULL ||
        rect == NULL)
    {
        return LE_FAILURE;
    }

    size = strlen(str);

    if(size == 0)
        return LE_FAILURE;

    *rect = leRect_Zero;

    if(line >= leStringUtils_GetLineCountCStr(str))
    {
        return LE_FAILURE;
    }

    leStringUtils_GetLineIndicesCStr(str, line, &startIdx, &endIdx);

    for(idx = startIdx; idx < endIdx; idx++)
    {
        leFont_GetGlyphInfo(font, str[idx], &glyph);

        rect->width += glyph.advance;
    }

    rect->height = font->height;

    return LE_SUCCESS;
}

leResult leStringUtils_GetCharRect(const leChar* str,
                                   uint32_t size,
                                   const leFont* font,
                                   uint32_t charIdx,
                                   leRect* rect)
{
    uint32_t idx;
    leFontGlyph glyph;

    if(str == NULL ||
       size == 0 ||
       charIdx >= size ||
       font == NULL ||
       font->glyphTable == NULL ||
       rect == NULL)
    {
        return LE_FAILURE;
    }

    *rect = leRect_Zero;

    for(idx = 0; idx < size; idx++)
    {
        if(str[idx] == LINE_BREAK)
        { }
        else if(idx == charIdx)
        {
            leFont_GetGlyphInfo(font, str[idx], &glyph);

            rect->width = glyph.advance;
            rect->height = font->height;

            return LE_SUCCESS;
        }
        else
        {
            leFont_GetGlyphInfo(font, str[idx], &glyph);

            rect->x += glyph.advance;
        }
    }

    return LE_FAILURE;
}

leResult leStringUtils_GetCharRectCStr(const char* str,
                                       const leFont* font,
                                       uint32_t charIdx,
                                       leRect* rect)
{
    uint32_t idx;
    leFontGlyph glyph;
    uint32_t size;

    if(str == NULL ||
        font == NULL ||
        font->glyphTable == NULL ||
        rect == NULL)
    {
        return LE_FAILURE;
    }

    size = strlen(str);

    if(size == 0 || charIdx >= size)
        return LE_FAILURE;

    *rect = leRect_Zero;

    for(idx = 0; idx < size; idx++)
    {
        if(str[idx] == LINE_BREAK)
        { }
        else if(idx == charIdx)
        {
            leFont_GetGlyphInfo(font, str[idx], &glyph);

            rect->width = glyph.advance;
            rect->height = font->height;

            return LE_SUCCESS;
        }
        else
        {
            leFont_GetGlyphInfo(font, str[idx], &glyph);

            rect->x += glyph.advance;
        }
    }

    return LE_FAILURE;
}

leResult leStringUtils_GetCharIndexAtPoint(const leChar* str,
                                           uint32_t size,
                                           const leFont* font,
                                           lePoint pt,
                                           uint32_t* charIdx)
{
    uint32_t idx;
    leFontGlyph glyph;
    leRect rect;

    rect.x = 0;
    rect.y = 0;

    if(str == NULL ||
       size == 0 ||
       font == NULL ||
       font->glyphTable == NULL ||
       charIdx == NULL)
    {
        return LE_FAILURE;
    }

    for(idx = 0; idx < size; idx++)
    {
        if(str[idx] == LINE_BREAK)
        {
            rect.x = 0;
            rect.y += font->height;
        }
        else
        {
            leFont_GetGlyphInfo(font, str[idx], &glyph);

            rect.width = glyph.advance;
            rect.height = glyph.height;

            if(leRectContainsPoint(&rect, &pt) == LE_TRUE)
            {
                *charIdx = idx;

                return LE_SUCCESS;
            }

            rect.x += glyph.advance;
        }
    }

    return LE_FAILURE;
}

leResult leStringUtils_GetCharIndexAtPointCStr(const char* str,
                                               const leFont* font,
                                               lePoint pt,
                                               uint32_t* charIdx)
{
    uint32_t idx;
    leFontGlyph glyph;
    leRect rect;
    uint32_t size;

    rect.x = 0;
    rect.y = 0;

    if(str == NULL ||
        font == NULL ||
        font->glyphTable == NULL ||
        charIdx == NULL)
    {
        return LE_FAILURE;
    }

    size = strlen(str);

    if(size == 0)
        return LE_FAILURE;

    for(idx = 0; idx < size; idx++)
    {
        if(str[idx] == LINE_BREAK)
        {
            rect.x = 0;
            rect.y += font->height;
        }
        else
        {
            leFont_GetGlyphInfo(font, str[idx], &glyph);

            rect.width = glyph.advance;
            rect.height = glyph.height;

            if(leRectContainsPoint(&rect, &pt) == LE_TRUE)
            {
                *charIdx = idx;

                return LE_SUCCESS;
            }

            rect.x += glyph.advance;
        }
    }

    return LE_FAILURE;
}

void leStringUtils_DrawString(const leChar* str,
                              uint32_t size,
                              const leFont* font,
                              int32_t x,
                              int32_t y,
                              leHAlignment align,
                              leColor clr,
                              uint32_t a)
{
    uint32_t charItr, lines, lineItr;
    leFontGlyph glyphInfo;
    leChar codePoint = 0;
    int32_t stringY, lineX;
    leRect stringRect;
    leRect lineRect = leRect_Zero;
    uint32_t startIdx = 0;
    uint32_t endIdx = 0;

    if(str == NULL ||
        size == 0 ||
        font == NULL ||
        font->glyphTable == NULL)
    {
        return;
    }

    stringY = y;

    lines = leStringUtils_GetLineCount(str, size);

    leStringUtils_GetRect(str, size, font, &stringRect);

    for(lineItr = 0; lineItr < lines; lineItr++)
    {
        leStringUtils_GetLineIndices(str, size, lineItr, &startIdx, &endIdx);
        leStringUtils_GetLineRect(str, size, font, lineItr, &lineRect);

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
            leFont_GetGlyphInfo(font, str[charItr], &glyphInfo);

            if(codePoint == ASCII_SPACE)
            {

            }
            else
            {
                leFont_DrawGlyph(font,
                                 &glyphInfo,
                                 x + lineX + glyphInfo.bearingX,
                                 stringY + (font->baseline - glyphInfo.bearingY),
                                 clr,
                                 a);
            }

            lineX += glyphInfo.advance;
        }

        stringY += font->height;
    }
}

void leStringUtils_DrawCString(const char* str,
                               const leFont* font,
                               int32_t x,
                               int32_t y,
                               leHAlignment align,
                               leColor clr,
                               uint32_t a)
{
    uint32_t charItr, lines, lineItr;
    uint32_t size;
    leFontGlyph glyphInfo;
    leChar codePoint = 0;
    int32_t stringY, lineX;
    leRect stringRect, lineRect;
    uint32_t startIdx = 0;
    uint32_t endIdx = 0;

    if(str == NULL ||
        font == NULL ||
        font->glyphTable == NULL)
    {
        return;
    }

    size = strlen(str);

    if(size == 0)
        return;

    stringY = y;

    lines = leStringUtils_GetLineCountCStr(str);

    leStringUtils_GetRectCStr(str, font, &stringRect);

    for(lineItr = 0; lineItr < lines; lineItr++)
    {
        leStringUtils_GetLineIndicesCStr(str, lineItr, &startIdx, &endIdx);
        leStringUtils_GetLineRectCStr(str, font, lineItr, &lineRect);

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
            leFont_GetGlyphInfo(font, str[charItr], &glyphInfo);

            if(codePoint == ASCII_SPACE)
            {

            }
            else
            {
                leFont_DrawGlyph(font,
                                 &glyphInfo,
                                 x + lineX + glyphInfo.bearingX,
                                 stringY + (font->baseline - glyphInfo.bearingY),
                                 clr,
                                 a);
            }

            lineX += glyphInfo.advance;
        }

        stringY += font->height;
    }
}
