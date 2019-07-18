#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Font Asset
 * Name:         ArialNarrowMed
 * Height:       27
 * Baseline:     26
 * Style:        Plain
 * Glyph Count:  14
 * Range Count:  5
 * Glyph Ranges: 0x2B
                 0x2D
                 0x30-0x39
                 0x3C
                 0x3E
 *********************************/
/*********************************
 * font glyph kerning table description
 *
 * unsigned int - number of glyphs
 * for each glyph:
 *     unsigned short - codepoint         * the glyph's codepoint
 *     short          - width             * the glyph's width in pixels
 *     short          - height            * the glyph's height in pixels
 *     short          - advance           * the glyph's advance value in pixels
 *     short          - bearingX          * the glyph's bearing value in pixels on the X axis
 *     short          - bearingY          * the glyph's bearing value in pixels on the Y axis
 *     unsigned short - flags             * status flags for this glyph
 *     unsigned short - data row width    * the size of a row of glyph data in bytes
 *     unsigned int   - data table offset * the offset into the corresponding font data table
 ********************************/
const uint8_t ArialNarrowMed_glyphs[284] =
{
    0x0E,0x00,0x00,0x00,0x2B,0x00,0x12,0x00,0x12,0x00,0x15,0x00,0x01,0x00,0x16,0x00,
    0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x2D,0x00,0x0A,0x00,0x03,0x00,0x0C,0x00,
    0x01,0x00,0x0B,0x00,0x00,0x00,0x02,0x00,0x36,0x00,0x00,0x00,0x30,0x00,0x12,0x00,
    0x1A,0x00,0x15,0x00,0x01,0x00,0x1A,0x00,0x00,0x00,0x03,0x00,0x3C,0x00,0x00,0x00,
    0x31,0x00,0x0A,0x00,0x1A,0x00,0x15,0x00,0x03,0x00,0x1A,0x00,0x00,0x00,0x02,0x00,
    0x8A,0x00,0x00,0x00,0x32,0x00,0x12,0x00,0x1A,0x00,0x15,0x00,0x01,0x00,0x1A,0x00,
    0x00,0x00,0x03,0x00,0xBE,0x00,0x00,0x00,0x33,0x00,0x12,0x00,0x1A,0x00,0x15,0x00,
    0x01,0x00,0x1A,0x00,0x00,0x00,0x03,0x00,0x0C,0x01,0x00,0x00,0x34,0x00,0x14,0x00,
    0x1A,0x00,0x15,0x00,0x00,0x00,0x1A,0x00,0x00,0x00,0x03,0x00,0x5A,0x01,0x00,0x00,
    0x35,0x00,0x11,0x00,0x1A,0x00,0x15,0x00,0x02,0x00,0x1A,0x00,0x00,0x00,0x03,0x00,
    0xA8,0x01,0x00,0x00,0x36,0x00,0x12,0x00,0x1A,0x00,0x15,0x00,0x01,0x00,0x1A,0x00,
    0x00,0x00,0x03,0x00,0xF6,0x01,0x00,0x00,0x37,0x00,0x12,0x00,0x1A,0x00,0x15,0x00,
    0x01,0x00,0x1A,0x00,0x00,0x00,0x03,0x00,0x44,0x02,0x00,0x00,0x38,0x00,0x12,0x00,
    0x1A,0x00,0x15,0x00,0x01,0x00,0x1A,0x00,0x00,0x00,0x03,0x00,0x92,0x02,0x00,0x00,
    0x39,0x00,0x12,0x00,0x1A,0x00,0x15,0x00,0x01,0x00,0x1A,0x00,0x00,0x00,0x03,0x00,
    0xE0,0x02,0x00,0x00,0x3C,0x00,0x12,0x00,0x12,0x00,0x15,0x00,0x01,0x00,0x16,0x00,
    0x00,0x00,0x03,0x00,0x2E,0x03,0x00,0x00,0x3E,0x00,0x12,0x00,0x12,0x00,0x15,0x00,
    0x01,0x00,0x16,0x00,0x00,0x00,0x03,0x00,0x64,0x03,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t ArialNarrowMed_data[922] =
{
    0x00,0xE0,0x00,0x00,0xE0,0x00,0x00,0xE0,0x00,0x00,0xE0,0x00,0x00,0xE0,0x00,0x00,
    0xE0,0x00,0x00,0xE0,0x00,0x00,0xE0,0x00,0x7F,0xFF,0xC0,0x7F,0xFF,0xC0,0x7F,0xFF,
    0x80,0x00,0xE0,0x00,0x00,0xE0,0x00,0x00,0xE0,0x00,0x00,0xE0,0x00,0x00,0xE0,0x00,
    0x00,0xE0,0x00,0x00,0xE0,0x00,0x7F,0x80,0xFF,0x80,0xFF,0x80,0x03,0xF0,0x00,0x0F,
    0xFC,0x00,0x1F,0xFE,0x00,0x1E,0x0F,0x00,0x3C,0x07,0x00,0x38,0x07,0x80,0x78,0x03,
    0x80,0x70,0x03,0x80,0x70,0x03,0x80,0x70,0x03,0xC0,0x70,0x01,0xC0,0x70,0x01,0xC0,
    0x70,0x01,0xC0,0x70,0x01,0xC0,0x70,0x01,0xC0,0x70,0x01,0xC0,0x70,0x03,0xC0,0x70,
    0x03,0x80,0x70,0x03,0x80,0x38,0x03,0x80,0x38,0x07,0x80,0x3C,0x07,0x00,0x1E,0x0F,
    0x00,0x0F,0xFE,0x00,0x07,0xFC,0x00,0x03,0xF0,0x00,0x01,0xC0,0x07,0xC0,0x0F,0xC0,
    0x1F,0xC0,0x3D,0xC0,0x79,0xC0,0x61,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,
    0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,
    0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x03,0xF0,
    0x00,0x1F,0xFC,0x00,0x3F,0xFE,0x00,0x78,0x0F,0x00,0x30,0x07,0x00,0x00,0x07,0x80,
    0x00,0x07,0x80,0x00,0x07,0x80,0x00,0x07,0x80,0x00,0x07,0x00,0x00,0x07,0x00,0x00,
    0x0E,0x00,0x00,0x1E,0x00,0x00,0x1C,0x00,0x00,0x38,0x00,0x00,0x70,0x00,0x00,0xF0,
    0x00,0x01,0xE0,0x00,0x03,0xC0,0x00,0x07,0x80,0x00,0x0F,0x00,0x00,0x1E,0x00,0x00,
    0x3C,0x00,0x00,0x7F,0xFF,0x80,0x7F,0xFF,0xC0,0x7F,0xFF,0xC0,0x07,0xF0,0x00,0x1F,
    0xFC,0x00,0x7F,0xFE,0x00,0x78,0x0F,0x00,0x20,0x07,0x80,0x00,0x07,0x80,0x00,0x07,
    0x80,0x00,0x07,0x80,0x00,0x07,0x00,0x00,0x0F,0x00,0x00,0x3E,0x00,0x07,0xF8,0x00,
    0x07,0xF8,0x00,0x07,0xFE,0x00,0x00,0x0F,0x00,0x00,0x07,0x80,0x00,0x03,0x80,0x00,
    0x03,0x80,0x00,0x03,0xC0,0x00,0x03,0x80,0x00,0x03,0x80,0x00,0x07,0x80,0x60,0x0F,
    0x00,0x7F,0xFF,0x00,0x7F,0xFC,0x00,0x1F,0xF0,0x00,0x00,0x07,0x00,0x00,0x0F,0x00,
    0x00,0x1F,0x00,0x00,0x3F,0x00,0x00,0x3F,0x00,0x00,0x77,0x00,0x00,0xE7,0x00,0x00,
    0xE7,0x00,0x01,0xC7,0x00,0x03,0x87,0x00,0x07,0x87,0x00,0x07,0x07,0x00,0x0E,0x07,
    0x00,0x1C,0x07,0x00,0x1C,0x07,0x00,0x38,0x07,0x00,0x70,0x07,0x00,0x7F,0xFF,0xF0,
    0x7F,0xFF,0xF0,0x7F,0xFF,0xF0,0x00,0x07,0x00,0x00,0x07,0x00,0x00,0x07,0x00,0x00,
    0x07,0x00,0x00,0x07,0x00,0x00,0x07,0x00,0x3F,0xFE,0x00,0x3F,0xFE,0x00,0x3F,0xFC,
    0x00,0x30,0x00,0x00,0x70,0x00,0x00,0x70,0x00,0x00,0x70,0x00,0x00,0x70,0x00,0x00,
    0x70,0x00,0x00,0x73,0xC0,0x00,0x7F,0xF8,0x00,0x7F,0xFC,0x00,0x20,0x3E,0x00,0x00,
    0x0F,0x00,0x00,0x07,0x00,0x00,0x07,0x00,0x00,0x07,0x00,0x00,0x07,0x80,0x00,0x07,
    0x00,0x00,0x07,0x00,0x00,0x07,0x00,0x00,0x0F,0x00,0xC0,0x1E,0x00,0xFF,0xFC,0x00,
    0xFF,0xF8,0x00,0x1F,0xE0,0x00,0x00,0x7F,0x00,0x03,0xFF,0x00,0x07,0xFF,0x00,0x0F,
    0x80,0x00,0x1E,0x00,0x00,0x1C,0x00,0x00,0x3C,0x00,0x00,0x38,0x00,0x00,0x38,0x00,
    0x00,0x78,0x70,0x00,0x73,0xFE,0x00,0x77,0xFF,0x00,0x7E,0x0F,0x80,0x7C,0x03,0x80,
    0x78,0x03,0xC0,0x70,0x01,0xC0,0x70,0x01,0xC0,0x70,0x01,0xC0,0x70,0x01,0xC0,0x38,
    0x01,0xC0,0x38,0x03,0x80,0x3C,0x03,0x80,0x1E,0x07,0x80,0x0F,0xFF,0x00,0x07,0xFE,
    0x00,0x01,0xF8,0x00,0x7F,0xFF,0xC0,0x7F,0xFF,0xC0,0x7F,0xFF,0xC0,0x00,0x03,0x80,
    0x00,0x03,0x80,0x00,0x07,0x00,0x00,0x07,0x00,0x00,0x0F,0x00,0x00,0x0E,0x00,0x00,
    0x1E,0x00,0x00,0x1C,0x00,0x00,0x3C,0x00,0x00,0x38,0x00,0x00,0x38,0x00,0x00,0x70,
    0x00,0x00,0x70,0x00,0x00,0xF0,0x00,0x00,0xE0,0x00,0x01,0xE0,0x00,0x01,0xC0,0x00,
    0x03,0xC0,0x00,0x03,0x80,0x00,0x07,0x80,0x00,0x07,0x00,0x00,0x07,0x00,0x00,0x0F,
    0x00,0x00,0x03,0xF8,0x00,0x0F,0xFE,0x00,0x1F,0xFF,0x00,0x3C,0x0F,0x00,0x38,0x07,
    0x80,0x38,0x03,0x80,0x38,0x03,0x80,0x38,0x03,0x80,0x38,0x07,0x00,0x1C,0x0F,0x00,
    0x1F,0x1E,0x00,0x0F,0xFC,0x00,0x03,0xF8,0x00,0x0F,0xFC,0x00,0x1E,0x3E,0x00,0x3C,
    0x0F,0x00,0x78,0x03,0x80,0x70,0x03,0xC0,0x70,0x01,0xC0,0x70,0x01,0xC0,0x70,0x03,
    0xC0,0x78,0x03,0x80,0x3C,0x07,0x80,0x3F,0xFF,0x00,0x1F,0xFE,0x00,0x03,0xF8,0x00,
    0x03,0xF0,0x00,0x0F,0xFC,0x00,0x1F,0xFE,0x00,0x3C,0x0F,0x00,0x38,0x07,0x00,0x70,
    0x03,0x80,0x70,0x03,0x80,0x70,0x03,0x80,0x70,0x03,0xC0,0x70,0x03,0xC0,0x70,0x03,
    0xC0,0x78,0x07,0xC0,0x3C,0x0F,0xC0,0x3F,0xFF,0xC0,0x1F,0xFB,0xC0,0x07,0xE3,0x80,
    0x00,0x03,0x80,0x00,0x03,0x80,0x00,0x07,0x80,0x00,0x07,0x00,0x00,0x0F,0x00,0x00,
    0x1E,0x00,0x00,0x3E,0x00,0x1F,0xFC,0x00,0x1F,0xF0,0x00,0x1F,0xC0,0x00,0x00,0x00,
    0x40,0x00,0x01,0xC0,0x00,0x07,0xC0,0x00,0x1F,0x80,0x00,0x7C,0x00,0x01,0xF0,0x00,
    0x07,0xC0,0x00,0x1F,0x00,0x00,0x7C,0x00,0x00,0x78,0x00,0x00,0x7E,0x00,0x00,0x1F,
    0x80,0x00,0x03,0xF0,0x00,0x00,0xFC,0x00,0x00,0x3F,0x80,0x00,0x0F,0xC0,0x00,0x01,
    0xC0,0x00,0x00,0x40,0x40,0x00,0x00,0x70,0x00,0x00,0x7C,0x00,0x00,0x3F,0x00,0x00,
    0x0F,0xC0,0x00,0x03,0xF0,0x00,0x00,0xFC,0x00,0x00,0x3F,0x00,0x00,0x07,0x80,0x00,
    0x03,0xC0,0x00,0x0F,0x80,0x00,0x7E,0x00,0x01,0xF8,0x00,0x0F,0xE0,0x00,0x3F,0x00,
    0x00,0x7C,0x00,0x00,0x70,0x00,0x00,0x40,0x00,0x00,
};

leRasterFont ArialNarrowMed =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)ArialNarrowMed_data, // data address pointer
            922, // data size
        },
        LE_RASTER_FONT,
    },
    27,
    26,
    LE_FONT_BPP_1, // bits per pixel
    ArialNarrowMed_glyphs, // glyph table
};