#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Regular
 * Height:       14
 * Baseline:     13
 * Style:        Antialias
 * Glyph Count:  11
 * Range Count:  1
 * Glyph Ranges: 0x30-0x3A
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
const uint8_t NotoSans_Regular_glyphs[224] =
{
    0x0B,0x00,0x00,0x00,0x30,0x00,0x0A,0x00,0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,
    0x00,0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0x31,0x00,0x06,0x00,0x0D,0x00,0x0A,0x00,
    0x01,0x00,0x0D,0x00,0x00,0x00,0x06,0x00,0x82,0x00,0x00,0x00,0x32,0x00,0x0A,0x00,
    0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x0A,0x00,0xD0,0x00,0x00,0x00,
    0x33,0x00,0x0A,0x00,0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x0A,0x00,
    0x52,0x01,0x00,0x00,0x34,0x00,0x0A,0x00,0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,
    0x00,0x00,0x0A,0x00,0xD4,0x01,0x00,0x00,0x35,0x00,0x09,0x00,0x0D,0x00,0x0A,0x00,
    0x01,0x00,0x0D,0x00,0x00,0x00,0x09,0x00,0x56,0x02,0x00,0x00,0x36,0x00,0x0A,0x00,
    0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x0A,0x00,0xCB,0x02,0x00,0x00,
    0x37,0x00,0x0A,0x00,0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x0A,0x00,
    0x4D,0x03,0x00,0x00,0x38,0x00,0x0A,0x00,0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,
    0x00,0x00,0x0A,0x00,0xCF,0x03,0x00,0x00,0x39,0x00,0x0A,0x00,0x0D,0x00,0x0A,0x00,
    0x00,0x00,0x0D,0x00,0x00,0x00,0x0A,0x00,0x51,0x04,0x00,0x00,0x3A,0x00,0x03,0x00,
    0x0A,0x00,0x05,0x00,0x01,0x00,0x0A,0x00,0x00,0x00,0x03,0x00,0xD3,0x04,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t NotoSans_Regular_data[1265] =
{
    0x00,0x00,0x22,0xAA,0xE9,0xF4,0xC1,0x3C,0x00,0x00,0x00,0x13,0xE0,0xE3,0x6F,0x61,
    0xC7,0xF8,0x32,0x00,0x00,0x7E,0xFE,0x2B,0x00,0x00,0x09,0xE0,0xB9,0x00,0x00,0xCE,
    0xC7,0x00,0x00,0x00,0x00,0x84,0xFC,0x12,0x03,0xFA,0x96,0x00,0x00,0x00,0x00,0x51,
    0xFF,0x41,0x12,0xFF,0x7F,0x00,0x00,0x00,0x00,0x39,0xFF,0x5C,0x1D,0xFF,0x79,0x00,
    0x00,0x00,0x00,0x32,0xFF,0x64,0x15,0xFF,0x80,0x00,0x00,0x00,0x00,0x39,0xFF,0x58,
    0x02,0xF7,0x97,0x00,0x00,0x00,0x00,0x51,0xFF,0x43,0x00,0xC8,0xC6,0x00,0x00,0x00,
    0x00,0x83,0xFF,0x12,0x00,0x75,0xFD,0x29,0x00,0x00,0x08,0xDE,0xBF,0x00,0x00,0x0D,
    0xDC,0xE2,0x6E,0x61,0xC6,0xF9,0x3A,0x00,0x00,0x00,0x1C,0xA8,0xEF,0xF2,0xC2,0x3F,
    0x00,0x00,0x00,0x00,0x02,0x86,0xFF,0x64,0x00,0x0E,0xB4,0xF9,0xFF,0x64,0x1E,0xD7,
    0xE6,0x53,0xFF,0x64,0x0A,0xA3,0x1B,0x27,0xFF,0x64,0x00,0x00,0x00,0x28,0xFF,0x64,
    0x00,0x00,0x00,0x28,0xFF,0x64,0x00,0x00,0x00,0x28,0xFF,0x64,0x00,0x00,0x00,0x28,
    0xFF,0x64,0x00,0x00,0x00,0x28,0xFF,0x64,0x00,0x00,0x00,0x28,0xFF,0x64,0x00,0x00,
    0x00,0x28,0xFF,0x64,0x00,0x00,0x00,0x28,0xFF,0x64,0x00,0x00,0x00,0x28,0xFF,0x64,
    0x00,0x00,0x5D,0xC7,0xF4,0xEB,0xBB,0x3B,0x00,0x00,0x00,0xA4,0xFC,0xA0,0x5F,0x6A,
    0xD5,0xFC,0x43,0x00,0x00,0x44,0x35,0x00,0x00,0x00,0x15,0xF5,0xB5,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xD1,0xD1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xEB,
    0xB2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x56,0xFF,0x57,0x00,0x00,0x00,0x00,0x00,
    0x00,0x21,0xEC,0xBF,0x01,0x00,0x00,0x00,0x00,0x00,0x16,0xD9,0xDA,0x16,0x00,0x00,
    0x00,0x00,0x00,0x12,0xD1,0xE2,0x1E,0x00,0x00,0x00,0x00,0x00,0x11,0xCE,0xE3,0x24,
    0x00,0x00,0x00,0x00,0x00,0x0F,0xCA,0xE3,0x24,0x00,0x00,0x00,0x00,0x00,0x09,0xC7,
    0xFD,0x78,0x54,0x54,0x54,0x54,0x54,0x1E,0x24,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0x5C,0x00,0x1C,0x8A,0xD7,0xF7,0xF6,0xD1,0x70,0x00,0x00,0x03,0xD5,0xDD,0x81,
    0x5B,0x65,0xBB,0xFF,0x73,0x00,0x00,0x15,0x03,0x00,0x00,0x00,0x02,0xDD,0xCD,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x05,0xE5,0xBB,0x00,0x00,0x00,0x04,0x14,0x1F,0x46,
    0xBC,0xEA,0x34,0x00,0x00,0x00,0x3C,0xFF,0xFF,0xFF,0xC1,0x2A,0x00,0x00,0x00,0x00,
    0x0F,0x40,0x4C,0x6F,0xCF,0xF6,0x57,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xC7,
    0xF0,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x76,0xFF,0x35,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x80,0xFF,0x2F,0x0B,0x0C,0x00,0x00,0x00,0x00,0x09,0xDB,0xE9,0x05,
    0x30,0xF2,0x9C,0x6F,0x5C,0x7A,0xDC,0xFD,0x56,0x00,0x11,0x8D,0xD6,0xF0,0xFA,0xE6,
    0xAC,0x39,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0xDE,0xFF,0x10,0x00,0x00,0x00,
    0x00,0x00,0x00,0x97,0xF7,0xFF,0x10,0x00,0x00,0x00,0x00,0x00,0x45,0xFC,0x9A,0xFF,
    0x10,0x00,0x00,0x00,0x00,0x0E,0xE2,0x93,0x73,0xFF,0x10,0x00,0x00,0x00,0x00,0x9E,
    0xDB,0x0A,0x77,0xFF,0x10,0x00,0x00,0x00,0x4B,0xFC,0x3A,0x00,0x78,0xFF,0x10,0x00,
    0x00,0x11,0xE6,0x89,0x00,0x00,0x78,0xFF,0x10,0x00,0x00,0xA5,0xD4,0x07,0x00,0x00,
    0x78,0xFF,0x10,0x00,0x51,0xFE,0x52,0x20,0x20,0x20,0x89,0xFF,0x2E,0x1E,0xA0,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x32,0x50,0x50,0x50,0x50,0x50,0xA2,0xFF,
    0x5B,0x4B,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0xFF,0x10,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x78,0xFF,0x10,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x60,0x00,0x33,
    0xFF,0x7F,0x54,0x54,0x54,0x54,0x1F,0x00,0x48,0xFF,0x2E,0x00,0x00,0x00,0x00,0x00,
    0x00,0x5C,0xFF,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x71,0xFF,0x05,0x0B,0x04,0x00,
    0x00,0x00,0x00,0x86,0xFF,0xF3,0xFF,0xFB,0xD6,0x64,0x02,0x00,0x1D,0x7A,0x57,0x47,
    0x61,0xBF,0xFF,0x93,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xBC,0xFD,0x16,0x00,0x00,
    0x00,0x00,0x00,0x00,0x69,0xFF,0x3D,0x00,0x00,0x00,0x00,0x00,0x00,0x74,0xFF,0x2F,
    0x07,0x00,0x00,0x00,0x00,0x08,0xD0,0xE6,0x03,0xCB,0x9E,0x72,0x5C,0x78,0xD9,0xFC,
    0x50,0x00,0x70,0xCA,0xEA,0xFB,0xEA,0xAF,0x38,0x00,0x00,0x00,0x00,0x00,0x1F,0x92,
    0xDB,0xF6,0xF5,0x64,0x00,0x00,0x00,0x3A,0xF0,0xE8,0x88,0x5E,0x61,0x3C,0x00,0x00,
    0x0A,0xE5,0xD2,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x69,0xFF,0x47,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xB5,0xE2,0x01,0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0xD9,0xB7,
    0x54,0xDD,0xFF,0xF1,0xA4,0x17,0x00,0x00,0xF0,0xD9,0xD6,0x65,0x49,0x7D,0xF5,0xD4,
    0x04,0x00,0xFD,0xE4,0x10,0x00,0x00,0x00,0x6C,0xFF,0x49,0x00,0xED,0xA0,0x00,0x00,
    0x00,0x00,0x29,0xFF,0x6D,0x00,0xC3,0xBF,0x00,0x00,0x00,0x00,0x35,0xFF,0x63,0x00,
    0x6D,0xFD,0x38,0x00,0x00,0x00,0x89,0xFF,0x28,0x00,0x05,0xC8,0xEE,0x7D,0x5F,0x9E,
    0xFE,0x9F,0x00,0x00,0x00,0x0C,0x8D,0xE2,0xF9,0xDB,0x7A,0x03,0x00,0x34,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x68,0x11,0x54,0x54,0x54,0x54,0x54,0x54,0x9E,0xFF,
    0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCF,0xCD,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x43,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB7,0xE6,0x05,0x00,0x00,
    0x00,0x00,0x00,0x00,0x2A,0xFE,0x7B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9E,0xF7,
    0x14,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xF8,0x9A,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x85,0xFF,0x2B,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0xED,0xB9,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x6C,0xFF,0x49,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xDC,0xD7,
    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x52,0xFF,0x68,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x3F,0xBC,0xF1,0xF3,0xCD,0x65,0x01,0x00,0x00,0x3B,0xFB,0xCE,0x6A,0x61,0xAD,
    0xFF,0x86,0x00,0x00,0x9F,0xF6,0x0E,0x00,0x00,0x00,0xC1,0xE8,0x00,0x00,0xA2,0xE5,
    0x00,0x00,0x00,0x00,0xA5,0xED,0x00,0x00,0x55,0xFF,0x6D,0x00,0x00,0x2B,0xF1,0x87,
    0x00,0x00,0x00,0x87,0xFE,0xB8,0x8A,0xF4,0x95,0x02,0x00,0x00,0x00,0x20,0xD0,0xFC,
    0xFF,0xDE,0x37,0x00,0x00,0x00,0x35,0xF3,0xB2,0x20,0x30,0xAD,0xFE,0x74,0x00,0x01,
    0xDF,0xC2,0x01,0x00,0x00,0x00,0x8D,0xFE,0x29,0x18,0xFF,0x7C,0x00,0x00,0x00,0x00,
    0x36,0xFF,0x5C,0x09,0xF8,0xB5,0x00,0x00,0x00,0x00,0x73,0xFF,0x40,0x00,0x8F,0xFF,
    0xB6,0x68,0x5F,0x98,0xFA,0xC1,0x02,0x00,0x02,0x60,0xC7,0xEC,0xF4,0xD3,0x78,0x0A,
    0x00,0x00,0x00,0x3A,0xBA,0xF0,0xEF,0xB2,0x2E,0x00,0x00,0x00,0x3C,0xFB,0xD1,0x6C,
    0x68,0xD1,0xF3,0x30,0x00,0x00,0xC2,0xE1,0x0A,0x00,0x00,0x0C,0xDA,0xC2,0x00,0x04,
    0xFD,0x92,0x00,0x00,0x00,0x00,0x6B,0xFE,0x1B,0x13,0xFF,0x81,0x00,0x00,0x00,0x00,
    0x44,0xFF,0x44,0x02,0xF2,0xB5,0x00,0x00,0x00,0x00,0x83,0xFF,0x55,0x00,0x96,0xFF,
    0x7E,0x25,0x25,0x80,0xE9,0xFF,0x45,0x00,0x0A,0xA9,0xFF,0xFF,0xFF,0xBC,0x6E,0xFF,
    0x2E,0x00,0x00,0x00,0x1A,0x3A,0x21,0x00,0x80,0xFC,0x0D,0x00,0x00,0x00,0x00,0x00,
    0x00,0x02,0xD3,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x81,0xFF,0x4A,0x00,0x00,
    0x15,0x74,0x5A,0x70,0xC2,0xFF,0x83,0x00,0x00,0x00,0x21,0xED,0xFB,0xE6,0xB2,0x47,
    0x00,0x00,0x00,0x6E,0xF1,0x43,0xAC,0xFF,0x7F,0x52,0xC9,0x2F,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x00,0x93,0xFF,0x65,0x77,0xEB,
    0x4F,
};

leRasterFont NotoSans_Regular =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)NotoSans_Regular_data, // data address pointer
            1265, // data size
        },
        LE_RASTER_FONT,
    },
    14,
    13,
    LE_FONT_BPP_8, // bits per pixel
    NotoSans_Regular_glyphs, // glyph table
};
