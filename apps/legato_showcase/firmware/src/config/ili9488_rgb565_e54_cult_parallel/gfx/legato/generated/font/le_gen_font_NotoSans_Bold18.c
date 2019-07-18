#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Bold18
 * Height:       19
 * Baseline:     14
 * Style:        Plain
 * Glyph Count:  13
 * Range Count:  10
 * Glyph Ranges: 0x20
                 0x47
                 0x53
                 0x61
                 0x63
                 0x65
                 0x68-0x69
                 0x6F-0x70
                 0x72-0x73
                 0x77
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
const uint8_t NotoSans_Bold18_glyphs[264] =
{
    0x0D,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x47,0x00,0x0B,0x00,0x0D,0x00,0x0D,0x00,
    0x01,0x00,0x0D,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x53,0x00,0x0A,0x00,
    0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x02,0x00,0x1A,0x00,0x00,0x00,
    0x61,0x00,0x0A,0x00,0x0A,0x00,0x0B,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x02,0x00,
    0x34,0x00,0x00,0x00,0x63,0x00,0x09,0x00,0x0A,0x00,0x09,0x00,0x00,0x00,0x0A,0x00,
    0x00,0x00,0x02,0x00,0x48,0x00,0x00,0x00,0x65,0x00,0x0A,0x00,0x0A,0x00,0x0B,0x00,
    0x00,0x00,0x0A,0x00,0x00,0x00,0x02,0x00,0x5C,0x00,0x00,0x00,0x68,0x00,0x0A,0x00,
    0x0E,0x00,0x0C,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x02,0x00,0x70,0x00,0x00,0x00,
    0x69,0x00,0x04,0x00,0x0E,0x00,0x05,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x01,0x00,
    0x8C,0x00,0x00,0x00,0x6F,0x00,0x0B,0x00,0x0A,0x00,0x0B,0x00,0x00,0x00,0x0A,0x00,
    0x00,0x00,0x02,0x00,0x9A,0x00,0x00,0x00,0x70,0x00,0x0A,0x00,0x0E,0x00,0x0B,0x00,
    0x01,0x00,0x0A,0x00,0x00,0x00,0x02,0x00,0xAE,0x00,0x00,0x00,0x72,0x00,0x07,0x00,
    0x0A,0x00,0x08,0x00,0x01,0x00,0x0A,0x00,0x00,0x00,0x01,0x00,0xCA,0x00,0x00,0x00,
    0x73,0x00,0x09,0x00,0x0A,0x00,0x09,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x02,0x00,
    0xD4,0x00,0x00,0x00,0x77,0x00,0x10,0x00,0x0A,0x00,0x0F,0x00,0x00,0x00,0x0A,0x00,
    0x00,0x00,0x02,0x00,0xE8,0x00,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t NotoSans_Bold18_data[252] =
{
    0x0F,0xC0,0x3F,0xC0,0x78,0x40,0x70,0x00,0xE0,0x00,0xE0,0x00,0xE7,0xE0,0xE7,0xE0,
    0xE0,0xE0,0x70,0xE0,0x78,0xE0,0x3F,0xE0,0x1F,0xC0,0x1F,0x00,0x3F,0x80,0x71,0x00,
    0x70,0x00,0x70,0x00,0x3C,0x00,0x3F,0x00,0x0F,0x80,0x03,0x80,0x03,0x80,0x63,0x80,
    0x7F,0x00,0x3E,0x00,0x1F,0x00,0x3F,0x80,0x03,0x80,0x01,0xC0,0x3F,0xC0,0x7F,0xC0,
    0x71,0xC0,0x73,0xC0,0x7F,0xC0,0x3D,0xC0,0x1F,0x00,0x3F,0x00,0x79,0x00,0x70,0x00,
    0x70,0x00,0x70,0x00,0x70,0x00,0x79,0x00,0x3F,0x00,0x1F,0x00,0x1F,0x00,0x3F,0x80,
    0x71,0x80,0x71,0xC0,0x7F,0xC0,0x7F,0xC0,0x70,0x00,0x78,0x80,0x3F,0x80,0x1F,0x80,
    0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xEF,0x00,0xFF,0x80,0xF3,0x80,0xE1,0x80,
    0xE1,0x80,0xE1,0x80,0xE1,0x80,0xE1,0x80,0xE1,0x80,0xE1,0x80,0x60,0xE0,0x00,0x00,
    0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0x1F,0x00,0x3F,0x80,0x71,0xC0,
    0x71,0xC0,0x70,0xC0,0x70,0xC0,0x71,0xC0,0x79,0xC0,0x3F,0x80,0x1F,0x00,0xEF,0x00,
    0xFF,0x80,0xF3,0x80,0xE1,0x80,0xE1,0xC0,0xE1,0xC0,0xE1,0x80,0xF3,0x80,0xFF,0x80,
    0xEF,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xEE,0xFE,0xF0,0xE0,0xE0,0xE0,
    0xE0,0xE0,0xE0,0xE0,0x3E,0x00,0x7F,0x00,0x72,0x00,0x70,0x00,0x3C,0x00,0x1F,0x00,
    0x07,0x00,0x47,0x00,0x7F,0x00,0x7E,0x00,0xE3,0x8E,0x63,0xCE,0x63,0xCE,0x76,0xCC,
    0x76,0xDC,0x36,0xDC,0x3E,0x78,0x3C,0x78,0x1C,0x78,0x1C,0x78,
};

leRasterFont NotoSans_Bold18 =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)NotoSans_Bold18_data, // data address pointer
            252, // data size
        },
        LE_RASTER_FONT,
    },
    19,
    14,
    LE_FONT_BPP_1, // bits per pixel
    NotoSans_Bold18_glyphs, // glyph table
};