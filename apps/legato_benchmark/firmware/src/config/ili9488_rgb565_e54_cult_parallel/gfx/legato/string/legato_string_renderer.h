#ifndef LE_STRING_RENDERER_H
#define LE_STRING_RENDERER_H

#include "gfx/legato/string/legato_string.h"

typedef struct leStringRenderRequest
{
    const leString* str;
    int32_t x;
    int32_t y;
    leHAlignment align;
    leColor color;
    uint32_t alpha;
} leStringRenderRequest;

typedef struct leUStringRenderRequest
{
    const leChar* str;
    uint32_t length;
    const leFont* font;
    int32_t x;
    int32_t y;
    leHAlignment align;
    leColor color;
    uint32_t alpha;
} leUStringRenderRequest;

typedef struct leCStringRenderRequest
{
    const char* str;
    const leFont* font;
    int32_t x;
    int32_t y;
    leHAlignment align;
    leColor color;
    uint32_t alpha;
} leCStringRenderRequest;

leResult leStringRenderer_DrawString(leStringRenderRequest* req);

leResult leStringRenderer_DrawCString(leCStringRenderRequest* req);

leResult leStringRenderer_DrawUString(leUStringRenderRequest* req);

#endif /* LE_STRING_RENDERER_H */
