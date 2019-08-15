#include "gfx/legato/font/legato_font.h"

#if LE_STREAMING_ENABLED == 1

#ifndef LE_RASTERFONT_GLYPH_CACHE_SIZE
#define LE_RASTERFONT_GLYPH_CACHE_SIZE  256
#endif

static uint8_t glyphCache[LE_RASTERFONT_GLYPH_CACHE_SIZE];

static struct
{
    leFontStream fontStream;

    leStreamState state;

    leRasterFont* font;
    leFontGlyph info;
    int32_t x;
    int32_t y;
    leColor clr;
    uint32_t a;
} rasterStream;

static void streamDataReady(leStream* stream)
{
    leFont_DrawGlyphData((leFont*)rasterStream.font,
                         &rasterStream.info,
                         glyphCache,
                         rasterStream.x,
                         rasterStream.y,
                         rasterStream.clr,
                         rasterStream.a);

    rasterStream.state = LE_STREAM_READY;

    if(rasterStream.fontStream.cb != NULL)
    {
        rasterStream.fontStream.cb(rasterStream.info.codePoint);
    }
}

static leResult drawGlyph(const leFontGlyph* glyph,
                          int32_t x,
                          int32_t y,
                          leColor clr,
                          uint32_t a,
                          leFontStream_DrawCompleteFn cb)
{
    if(rasterStream.state == LE_STREAM_WAITING ||
       rasterStream.font == NULL ||
       glyph == NULL)
    {
        return LE_FAILURE;
    }

    rasterStream.info = *glyph;

    if(rasterStream.info.dataRowWidth * rasterStream.info.height >= LE_RASTERFONT_GLYPH_CACHE_SIZE)
        return LE_FAILURE;

    rasterStream.info = *glyph;
    rasterStream.x = x;
    rasterStream.y = y;
    rasterStream.clr = clr;
    rasterStream.a = a;
    rasterStream.fontStream.cb = cb;

    rasterStream.state = LE_STREAM_WAITING;

    leStream_Read(&rasterStream.fontStream.stream,
                  (uint32_t)rasterStream.font->base.header.address + rasterStream.info.dataOffset,
                  rasterStream.info.dataRowWidth * rasterStream.info.height,
                  glyphCache,
                  streamDataReady);

    return LE_SUCCESS;
}

static leBool isDone()
{
    return rasterStream.state == LE_STREAM_READY;
}

static void close()
{
    if(rasterStream.state != LE_STREAM_CLOSED)
    {
        leStream_Close(&rasterStream.fontStream.stream);
    }

    memset(&rasterStream, 0, sizeof(rasterStream));
}

static leResult open()
{
    if(rasterStream.state != LE_STREAM_CLOSED)
        return LE_FAILURE;

    if(leStream_Open(&rasterStream.fontStream.stream) == LE_FAILURE)
        return LE_FAILURE;

    rasterStream.state = LE_STREAM_READY;

    return LE_SUCCESS;
}

leFontStream* leRasterFontStream_Init(leFont* font)
{
    if(rasterStream.font != NULL)
    {
        close();
    }

    leStream_Init(&rasterStream.fontStream.stream,
                  (leStreamDescriptor*)font,
                  0,
                  NULL,
                  NULL);

    rasterStream.font = (leRasterFont*)font;
    rasterStream.state = LE_STREAM_CLOSED;

    rasterStream.fontStream.open = open;
    rasterStream.fontStream.drawGlyph = drawGlyph;
    rasterStream.fontStream.isDone = isDone;
    rasterStream.fontStream.close = close;

    return (leFontStream*)&rasterStream;
}

#endif