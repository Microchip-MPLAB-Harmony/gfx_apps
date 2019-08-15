#ifndef LE_STRING_RENDERER_H
#define LE_STRING_RENDERER_H

#include "gfx/legato/string/legato_string.h"

// *****************************************************************************
/* Structure:
    struct leStringRenderRequest

  Summary:
    Defines the arguments necessary to perform an leString draw operation

   Description:
    const leString* str - the string to draw
    int32_t x - the x position in screen space
    int32_t y - the y position in screen space
    leHAlignment align - the alignment of the string
    leColor color - the color to write
    uint32_t alpha - global alpha value to apply

  Remarks:
    None.
*/
typedef struct leStringRenderRequest
{
    const leString* str;
    int32_t x;
    int32_t y;
    leHAlignment align;
    leColor color;
    uint32_t alpha;
} leStringRenderRequest;

// *****************************************************************************
/* Structure:
    struct leUStringRenderRequest

  Summary:
    Defines the arguments necessary to perform an leChar string draw operation

   Description:
    const leChar* str - the string buffer to draw
    uint32_t length - the length of the string in leChar
    const leFont* font - the font to reference for rendering
    int32_t x - the x position in screen space
    int32_t y - the y position in screen space
    leHAlignment align - the alignment of the string
    leColor color - the color to write
    uint32_t alpha - global alpha value to apply

  Remarks:
    None.
*/
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

// *****************************************************************************
/* Structure:
    struct leCStringRenderRequest

  Summary:
    Defines the arguments necessary to perform a C-style string draw operation

   Description:
    const char* str - the c string buffer to draw
    const leFont* font - the font to reference for rendering
    int32_t x - the x position in screen space
    int32_t y - the y position in screen space
    leHAlignment align - the alignment of the string
    leColor color - the color to write
    uint32_t alpha - global alpha value to apply

  Remarks:
    None.
*/
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

// *****************************************************************************
/* Function:
    leResult  leStringRenderer_DrawString(leStringRenderRequest* req)

  Summary:
    draws an leString

  Description:
    draws an leString

  Parameters:
    leStringRenderRequest* req - the render request details

  Remarks:

  Returns:
    leResult - the result of the operation
*/
leResult leStringRenderer_DrawString(leStringRenderRequest* req);

// *****************************************************************************
/* Function:
    leResult  leStringRenderer_DrawCString(leCStringRenderRequest* req)

  Summary:
    draws a leChar string buffer

  Description:
    draws a leChar string buffer

  Parameters:
    leCStringRenderRequest* req - the render request details

  Remarks:

  Returns:
    leResult - the result of the operation
*/
leResult leStringRenderer_DrawCString(leCStringRenderRequest* req);

// *****************************************************************************
/* Function:
    leResult  leStringRenderer_DrawUString(leUStringRenderRequest* req)

  Summary:
    draws a C-style string buffer

  Description:
    draws a C-style string buffer

  Parameters:
    leUStringRenderRequest* req - the render request details

  Remarks:

  Returns:
    leResult - the result of the operation
*/
leResult leStringRenderer_DrawUString(leUStringRenderRequest* req);

#endif /* LE_STRING_RENDERER_H */
