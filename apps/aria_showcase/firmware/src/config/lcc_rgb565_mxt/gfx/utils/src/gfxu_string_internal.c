#include "gfx/utils/inc/gfxu_string.h"
#include "gfx/utils/inc/gfxu_font.h"
#include "gfx/utils/inc/gfxu_string_utils.h"

#define GFXU_STRING_ARRAY_SIZE 4
#define GFXU_STRING_ENTRY_SIZE 2

GFX_Result GFXU_DrawStringInternal(GFXU_StringTableAsset* tbl,
                                   GFXU_FontAsset* fnt,
                                   uint32_t id,
                                   uint32_t lang,
                                   int32_t clipX,
                                   int32_t clipY,
                                   int32_t clipWidth,
                                   int32_t clipHeight,
                                   int32_t x,
                                   int32_t y)
{
    uint16_t idx;
    uint8_t* stringAddress;
    uint32_t stringSize;
    
    idx = GFXU_StringIndexLookup(tbl, id, lang);
    
    if(GFXU_StringLookup(tbl, idx, &stringAddress, &stringSize))
        return GFX_FAILURE;
        
    GFXU_DecodeAndDrawString(stringAddress,
                             stringSize,
                             tbl->encodingMode,
                             fnt,
                             clipX,
                             clipY,
                             clipWidth,
                             clipHeight,
                             x,
                             y);
    
    return GFX_SUCCESS;
}

GFX_Result GFXU_DrawStringBufferInternal(GFXU_CHAR* buffer,
                                         GFXU_FontAsset* fnt,
                                         int32_t clipX,
                                         int32_t clipY,
                                         int32_t clipWidth,
                                         int32_t clipHeight,
                                         int32_t x,
                                         int32_t y)
{
    uint32_t len = 0;
    uint32_t i;
    
    while(buffer[len] != '\0')
        len++;
        
    if(len == 0)
        return 0;

    for(i = 0; i < len; i++)
    {
        x += GFXU_DrawGlyph(fnt,
                            buffer[i],
                            clipX,
                            clipY,
                            clipWidth,
                            clipHeight,
                            x,
                            y);
    }
    
    return GFX_SUCCESS;
}

GFX_Result GFXU_DrawSubStringBufferInternal(GFXU_CHAR* buffer,
                                            GFXU_FontAsset* fnt,
							                uint32_t start,
                                            uint32_t end,
                                            int32_t clipX,
                                            int32_t clipY,
                                            int32_t clipWidth,
                                            int32_t clipHeight,
                                            int32_t x,
                                            int32_t y)
{
    uint32_t len = 0;
    uint32_t i;
    
    while(buffer[len] != '\0')
        len++;
        
    if(len == 0)
        return 0;

    len = (end < len) ? end : len;
    
    for(i = start; i < len; i++)
    {
        x += GFXU_DrawGlyph(fnt,
                            buffer[i],
                            clipX,
                            clipY,
                            clipWidth,
                            clipHeight,
                            x,
                            y);
    }
    
    return GFX_SUCCESS;
}

GFX_Result GFXU_DrawSubStringInternal(GFXU_StringTableAsset* tbl,
                                   GFXU_FontAsset* fnt,
                                   uint32_t id,
                                   uint32_t lang,
                                   uint32_t start,
                                   uint32_t end,
                                   int32_t clipX,
                                   int32_t clipY,
                                   int32_t clipWidth,
                                   int32_t clipHeight,
                                   int32_t x,
                                   int32_t y)
{
    uint16_t idx;
    uint8_t* stringAddress;
    uint32_t stringSize;
    
    idx = GFXU_StringIndexLookup(tbl, id, lang);
    
    if(GFXU_StringLookup(tbl, idx, &stringAddress, &stringSize))
        return GFX_FAILURE;
        
    GFXU_DecodeAndDrawSubString(stringAddress,
                                stringSize,
                                tbl->encodingMode,
                                fnt,
							    start,
                                end,
                                clipX,
                                clipY,
                                clipWidth,
                                clipHeight,
                                x,
                                y);
    
    return GFX_SUCCESS;
}