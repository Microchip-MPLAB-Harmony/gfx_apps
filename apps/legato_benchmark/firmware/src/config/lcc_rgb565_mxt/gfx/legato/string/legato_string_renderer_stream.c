#include "gfx/legato/string/legato_string_renderer.h"

#include "gfx/legato/core/legato_state.h"
#include "gfx/legato/string/legato_stringtable.h"

#if LE_STREAMING_ENABLED == 1

#define LE_STRING_SPACE     0x20 // ' '
#define LE_STRING_LINEBREAK 0xA // '\n'

typedef enum leStringStreamState
{
    SS_NONE,
    SS_INIT,
    SS_DRAW,
    SS_NEWLINE,
    SS_WAITING,
    SS_CLEANUP,
    SS_DONE
} leStringStreamState;

static struct
{
    leStreamManager manager;
    leFontStream* stream;

    leStringStreamState state;

    const leString* string;

    uint32_t charItr;
    uint32_t len;
    uint32_t lines;
    uint32_t lineItr;
    leFontGlyph glyphInfo;
    int32_t stringY;
    int32_t lineX;
    leRect stringRect;
    leRect lineRect;
    uint32_t startIdx;
    uint32_t endIdx;
    const leRasterFont* font;

    int32_t x;
    int32_t y;
    int32_t clipX;
    int32_t clipY;
    int32_t clipWidth;
    int32_t clipHeight;

    leHAlignment align;
    leColor color;
    uint32_t alpha;

    uint8_t stringData[LE_STRING_MAX_CHAR_WIDTH];

    uint32_t glyphOffset;
    uint32_t glyphRow;
    uint32_t glyphWidth;
    uint8_t* glyphDataAddress;
    uint8_t* glyphData;
    uint32_t glyphDataWidth;
    uint32_t glyphDataSize;
    uint32_t glyphDataCapacity;
} renderState;

static void drawDone(uint32_t codepoint)
{
    if(renderState.state != SS_WAITING)
        return;

    renderState.charItr += 1;

    renderState.lineX += renderState.glyphInfo.advance;

    if(renderState.charItr >= renderState.endIdx)
    {
        renderState.state = SS_NEWLINE;
    }
    else
    {
        codepoint = renderState.string->fn->charAt(renderState.string, renderState.charItr);

        leFont_GetGlyphInfo((leFont *) renderState.font, codepoint, &renderState.glyphInfo);

        renderState.state = SS_DRAW;
    }
}

static leResult draw()
{
    renderState.state = SS_WAITING;

    if(renderState.glyphInfo.codePoint == LE_STRING_SPACE ||
       renderState.glyphInfo.codePoint == LE_STRING_LINEBREAK)
    {
        drawDone(renderState.glyphInfo.codePoint);

        return LE_SUCCESS;
    }

    renderState.stream->drawGlyph(&renderState.glyphInfo,
                                  renderState.x + renderState.lineX + renderState.glyphInfo.bearingX,
                                  renderState.stringY + (renderState.font->baseline - renderState.glyphInfo.bearingY),
                                  renderState.color,
                                  renderState.alpha,
                                  drawDone);

    return LE_SUCCESS;
}

static void getLineMetrics()
{
    uint32_t codepoint;

    renderState.string->fn->getLineIndices(renderState.string,
                                           renderState.lineItr,
                                           &renderState.startIdx,
                                           &renderState.endIdx);

    renderState.string->fn->getLineRect(renderState.string,
                                        renderState.lineItr,
                                        &renderState.lineRect);

    if(renderState.align == LE_HALIGN_CENTER)
    {
        renderState.lineX = renderState.stringRect.x + (renderState.stringRect.width / 2) - (renderState.lineRect.width / 2);
    }
    else if(renderState.align == LE_HALIGN_RIGHT)
    {
        renderState.lineX = renderState.stringRect.x + renderState.stringRect.width - renderState.lineRect.width;
    }
    else
    {
        renderState.lineX = renderState.stringRect.x;
    }

    renderState.charItr = renderState.startIdx;

    codepoint = renderState.string->fn->charAt(renderState.string, renderState.charItr);

    leFont_GetGlyphInfo((leFont *) renderState.font, codepoint, &renderState.glyphInfo);
}

static leResult newline()
{
    renderState.lineItr += 1;

    if(renderState.lineItr >= renderState.lines)
    {
        renderState.state = SS_CLEANUP;

        return LE_SUCCESS;
    }

    getLineMetrics();

    renderState.stringY += renderState.font->height;

    renderState.state = SS_DRAW;

    return LE_SUCCESS;
}

static void cleanup()
{
    leGetState()->activeStream = NULL;

    renderState.stream->close();

    renderState.state = SS_DONE;
}

static leResult exec(leStreamManager* man)
{
    while(renderState.state != SS_DONE)
    {
        switch(renderState.state)
        {
            case SS_DRAW:
            {
                draw();

                if(renderState.state == SS_WAITING)
                    return LE_SUCCESS;

                break;
            }
            case SS_NEWLINE:
            {
                newline();

                break;
            }
            case SS_CLEANUP:
            {
                cleanup();

                break;
            }
            default:
            {
                break;
            }
        }
    }

    return LE_SUCCESS;
}

static leBool isDone(leStreamManager* man)
{
    return renderState.state == SS_DONE;
}

static void abortDraw(leStreamManager* man)
{
    leGetState()->activeStream = NULL;

    renderState.stream->close();

    renderState.state = SS_CLEANUP;
}

leResult _leStringStreamRenderer_Draw(leStringRenderRequest* req)
{
    uint32_t codepoint;

    if(leGetActiveStream() != NULL || req == NULL || req->str == NULL)
        return LE_FAILURE;

    memset(&renderState, 0, sizeof(renderState));

    // store local values
    renderState.state = SS_NONE;

    renderState.string = req->str;
    renderState.x = req->x;
    renderState.y = req->y;
    renderState.align = req->align;
    renderState.color = req->color;
    renderState.alpha = req->alpha;

    renderState.len = req->str->fn->length(req->str);
    renderState.font = (leRasterFont*)req->str->fn->getFont(req->str);

    if(renderState.len == 0 ||
       renderState.font == NULL ||
       renderState.font->glyphTable == NULL)
    {
        return LE_FAILURE;
    }

    renderState.stringY = req->y;

    renderState.lines = req->str->fn->getLineCount(req->str);

    req->str->fn->getRect(req->str, &renderState.stringRect);

    getLineMetrics();

    renderState.stream = leFont_GetStream((leFont*)renderState.font);

    if(renderState.stream == NULL ||
       renderState.stream->open() == LE_FAILURE)
    {
        return LE_FAILURE;
    }

    // set up first draw
    codepoint = renderState.string->fn->charAt(renderState.string, renderState.charItr);

    leFont_GetGlyphInfo((leFont*)renderState.font, codepoint, &renderState.glyphInfo);

    renderState.manager.exec = exec;
    renderState.manager.isDone = isDone;
    renderState.manager.abort = abortDraw;

    renderState.state = SS_DRAW;

    // execute draw
    leGetState()->activeStream = (leStreamManager*)&renderState;

    renderState.manager.exec((leStreamManager*)&renderState);

    return LE_SUCCESS;
}

#endif