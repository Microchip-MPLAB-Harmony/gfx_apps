#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Font Asset
 * Name:         ArialTinyAve
 * Height:       7
 * Baseline:     6
 * Style:        Plain
 * Glyph Count:  1
 * Range Count:  1
 * Glyph Ranges: 0x61
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
const uint8_t ArialTinyAve_glyphs[24] =
{
    0x01,0x00,0x00,0x00,0x61,0x00,0x07,0x00,0x06,0x00,0x06,0x00,0x00,0x00,0x06,0x00,
    0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t ArialTinyAve_data[6] =
{
    0x34,0x4C,0x44,0x48,0x48,0x68,
};

leRasterFont ArialTinyAve =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)ArialTinyAve_data, // data address pointer
            6, // data size
        },
        LE_RASTER_FONT,
    },
    7,
    6,
    LE_FONT_BPP_1, // bits per pixel
    ArialTinyAve_glyphs, // glyph table
};
