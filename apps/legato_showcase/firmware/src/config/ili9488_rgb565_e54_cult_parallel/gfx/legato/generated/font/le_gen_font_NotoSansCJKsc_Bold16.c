#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Font Asset
 * Name:         NotoSansCJKsc_Bold16
 * Height:       20
 * Baseline:     15
 * Style:        Antialias
 * Glyph Count:  29
 * Range Count:  15
 * Glyph Ranges: 0x20
                 0x3F
                 0x41-0x42
                 0x44
                 0x48
                 0x4B-0x4D
                 0x50
                 0x54
                 0x57
                 0x61
                 0x63-0x65
                 0x67-0x69
                 0x6C-0x70
                 0x72-0x75
                 0x79
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
const uint8_t NotoSansCJKsc_Bold16_glyphs[584] =
{
    0x1D,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x09,0x00,0x0F,0x00,0x09,0x00,
    0x00,0x00,0x0F,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x00,0x00,0x41,0x00,0x0D,0x00,
    0x0E,0x00,0x0C,0x00,0xFF,0xFF,0x0E,0x00,0x00,0x00,0x0D,0x00,0x87,0x00,0x00,0x00,
    0x42,0x00,0x0B,0x00,0x0E,0x00,0x0C,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x0B,0x00,
    0x3D,0x01,0x00,0x00,0x44,0x00,0x0B,0x00,0x0E,0x00,0x0D,0x00,0x01,0x00,0x0E,0x00,
    0x00,0x00,0x0B,0x00,0xD7,0x01,0x00,0x00,0x48,0x00,0x0B,0x00,0x0E,0x00,0x0E,0x00,
    0x01,0x00,0x0E,0x00,0x00,0x00,0x0B,0x00,0x71,0x02,0x00,0x00,0x4B,0x00,0x0C,0x00,
    0x0E,0x00,0x0C,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x0C,0x00,0x0B,0x03,0x00,0x00,
    0x4C,0x00,0x09,0x00,0x0E,0x00,0x0A,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x09,0x00,
    0xB3,0x03,0x00,0x00,0x4D,0x00,0x0D,0x00,0x0E,0x00,0x0F,0x00,0x01,0x00,0x0E,0x00,
    0x00,0x00,0x0D,0x00,0x31,0x04,0x00,0x00,0x50,0x00,0x0B,0x00,0x0E,0x00,0x0C,0x00,
    0x01,0x00,0x0E,0x00,0x00,0x00,0x0B,0x00,0xE7,0x04,0x00,0x00,0x54,0x00,0x0B,0x00,
    0x0E,0x00,0x0B,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x0B,0x00,0x81,0x05,0x00,0x00,
    0x57,0x00,0x11,0x00,0x0E,0x00,0x10,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x11,0x00,
    0x1B,0x06,0x00,0x00,0x61,0x00,0x0A,0x00,0x0A,0x00,0x0B,0x00,0x00,0x00,0x0A,0x00,
    0x00,0x00,0x0A,0x00,0x09,0x07,0x00,0x00,0x63,0x00,0x09,0x00,0x0A,0x00,0x09,0x00,
    0x00,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,0x6D,0x07,0x00,0x00,0x64,0x00,0x0B,0x00,
    0x0F,0x00,0x0C,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x0B,0x00,0xC7,0x07,0x00,0x00,
    0x65,0x00,0x0A,0x00,0x0A,0x00,0x0A,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x0A,0x00,
    0x6C,0x08,0x00,0x00,0x67,0x00,0x0B,0x00,0x0E,0x00,0x0B,0x00,0x00,0x00,0x0A,0x00,
    0x00,0x00,0x0B,0x00,0xD0,0x08,0x00,0x00,0x68,0x00,0x0A,0x00,0x0F,0x00,0x0C,0x00,
    0x01,0x00,0x0F,0x00,0x00,0x00,0x0A,0x00,0x6A,0x09,0x00,0x00,0x69,0x00,0x04,0x00,
    0x0F,0x00,0x05,0x00,0x01,0x00,0x0F,0x00,0x00,0x00,0x04,0x00,0x00,0x0A,0x00,0x00,
    0x6C,0x00,0x05,0x00,0x0F,0x00,0x06,0x00,0x01,0x00,0x0F,0x00,0x00,0x00,0x05,0x00,
    0x3C,0x0A,0x00,0x00,0x6D,0x00,0x10,0x00,0x0A,0x00,0x11,0x00,0x01,0x00,0x0A,0x00,
    0x00,0x00,0x10,0x00,0x87,0x0A,0x00,0x00,0x6E,0x00,0x0A,0x00,0x0A,0x00,0x0C,0x00,
    0x01,0x00,0x0A,0x00,0x00,0x00,0x0A,0x00,0x27,0x0B,0x00,0x00,0x6F,0x00,0x0B,0x00,
    0x0A,0x00,0x0B,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x0B,0x00,0x8B,0x0B,0x00,0x00,
    0x70,0x00,0x0A,0x00,0x0E,0x00,0x0C,0x00,0x01,0x00,0x0A,0x00,0x00,0x00,0x0A,0x00,
    0xF9,0x0B,0x00,0x00,0x72,0x00,0x07,0x00,0x0A,0x00,0x08,0x00,0x01,0x00,0x0A,0x00,
    0x00,0x00,0x07,0x00,0x85,0x0C,0x00,0x00,0x73,0x00,0x09,0x00,0x0A,0x00,0x09,0x00,
    0x00,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,0xCB,0x0C,0x00,0x00,0x74,0x00,0x08,0x00,
    0x0D,0x00,0x08,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x08,0x00,0x25,0x0D,0x00,0x00,
    0x75,0x00,0x0A,0x00,0x0A,0x00,0x0B,0x00,0x01,0x00,0x0A,0x00,0x00,0x00,0x0A,0x00,
    0x8D,0x0D,0x00,0x00,0x79,0x00,0x0B,0x00,0x0E,0x00,0x0A,0x00,0x00,0x00,0x0A,0x00,
    0x00,0x00,0x0B,0x00,0xF1,0x0D,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t NotoSansCJKsc_Bold16_data[3723] =
{
    0x00,0x00,0x00,0x01,0x13,0x02,0x00,0x00,0x00,0x00,0x09,0x92,0xF1,0xFF,0xF8,0xAE,
    0x1F,0x00,0x06,0xCB,0xFF,0xFF,0xFF,0xFF,0xFF,0xCF,0x04,0x00,0x51,0xC6,0x37,0x1A,
    0xAA,0xFF,0xFF,0x30,0x00,0x00,0x00,0x00,0x00,0x49,0xFF,0xFF,0x4B,0x00,0x00,0x00,
    0x00,0x00,0x9A,0xFF,0xF8,0x16,0x00,0x00,0x00,0x00,0x53,0xFE,0xFF,0x6B,0x00,0x00,
    0x00,0x00,0x1A,0xF0,0xFF,0xA4,0x00,0x00,0x00,0x00,0x00,0x9D,0xFF,0xDF,0x0C,0x00,
    0x00,0x00,0x00,0x00,0xD4,0xFF,0x8A,0x00,0x00,0x00,0x00,0x00,0x00,0x31,0x3B,0x1D,
    0x00,0x00,0x00,0x00,0x00,0x00,0x2F,0x65,0x11,0x00,0x00,0x00,0x00,0x00,0x0E,0xF5,
    0xFF,0xAE,0x00,0x00,0x00,0x00,0x00,0x33,0xFF,0xFF,0xDE,0x00,0x00,0x00,0x00,0x00,
    0x00,0xB2,0xF2,0x65,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0xF1,0xFF,0xFF,0x7A,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0xFF,0xFF,0xFF,0xC8,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x92,0xFF,0xAE,0xFF,0xFE,0x18,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xE0,0xFF,0x49,0xE1,0xFF,0x65,0x00,0x00,0x00,0x00,0x00,0x00,0x2E,0xFF,
    0xFB,0x0C,0x9E,0xFF,0xB3,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0xFF,0xC7,0x00,0x5B,
    0xFF,0xF7,0x0A,0x00,0x00,0x00,0x00,0x00,0xCA,0xFF,0x87,0x00,0x18,0xFF,0xFF,0x50,
    0x00,0x00,0x00,0x00,0x1A,0xFE,0xFF,0x44,0x00,0x00,0xD5,0xFF,0x9E,0x00,0x00,0x00,
    0x00,0x66,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xEA,0x02,0x00,0x00,0x00,0xB4,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3A,0x00,0x00,0x0B,0xF7,0xFF,0x7E,0x13,0x13,
    0x13,0x1C,0xFB,0xFF,0x89,0x00,0x00,0x50,0xFF,0xFF,0x38,0x00,0x00,0x00,0x00,0xC9,
    0xFF,0xD7,0x00,0x00,0x9E,0xFF,0xF6,0x05,0x00,0x00,0x00,0x00,0x8C,0xFF,0xFF,0x25,
    0x02,0xEA,0xFF,0xBE,0x00,0x00,0x00,0x00,0x00,0x4E,0xFF,0xFF,0x74,0x5F,0xFF,0xFF,
    0xFF,0xFF,0xF5,0xDE,0xA0,0x33,0x00,0x00,0x5F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xF6,0x3A,0x00,0x5F,0xFF,0xFF,0x54,0x0C,0x1D,0x75,0xFF,0xFF,0xA6,0x00,0x5F,0xFF,
    0xFF,0x4B,0x00,0x00,0x00,0xCD,0xFF,0xD0,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,
    0xD2,0xFF,0xA0,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x15,0x7C,0xFF,0xFF,0x53,0x00,0x5F,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x00,0x00,0x5F,0xFF,0xFF,0xFD,0xFB,0xFF,
    0xFF,0xFF,0xF1,0x65,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x05,0x2A,0xB5,0xFF,0xFD,0x2F,
    0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x21,0xFF,0xFF,0x75,0x5F,0xFF,0xFF,0x4B,0x00,
    0x00,0x00,0x2F,0xFF,0xFF,0x70,0x5F,0xFF,0xFF,0x54,0x0B,0x14,0x40,0xCC,0xFF,0xFF,
    0x34,0x5F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x89,0x00,0x5F,0xFF,0xFF,0xFF,
    0xFF,0xFA,0xE0,0xB5,0x4B,0x01,0x00,0x5F,0xFF,0xFF,0xFF,0xF5,0xD1,0xAB,0x60,0x05,
    0x00,0x00,0x5F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC8,0x15,0x00,0x5F,0xFF,0xFF,
    0x62,0x2F,0x5A,0xD3,0xFF,0xFF,0xBC,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x06,0xC9,
    0xFF,0xFF,0x42,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x44,0xFF,0xFF,0x91,0x5F,0xFF,
    0xFF,0x4B,0x00,0x00,0x00,0x09,0xFF,0xFF,0xC3,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,
    0x00,0xE7,0xFF,0xD7,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0xEA,0xFF,0xD5,0x5F,
    0xFF,0xFF,0x4B,0x00,0x00,0x00,0x0B,0xFF,0xFF,0xC0,0x5F,0xFF,0xFF,0x4B,0x00,0x00,
    0x00,0x4C,0xFF,0xFF,0x8D,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x0A,0xD0,0xFF,0xFF,0x3A,
    0x5F,0xFF,0xFF,0x65,0x33,0x5F,0xDA,0xFF,0xFF,0xB4,0x00,0x5F,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xC4,0x12,0x00,0x5F,0xFF,0xFF,0xFF,0xF9,0xD5,0xAC,0x60,0x04,0x00,
    0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0xA7,0xFF,0xFB,0x5F,0xFF,0xFF,0x4B,
    0x00,0x00,0x00,0x00,0xA7,0xFF,0xFB,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0xA7,
    0xFF,0xFB,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0xA7,0xFF,0xFB,0x5F,0xFF,0xFF,
    0x4B,0x00,0x00,0x00,0x00,0xA7,0xFF,0xFB,0x5F,0xFF,0xFF,0x84,0x4F,0x4F,0x4F,0x4F,
    0xC3,0xFF,0xFB,0x5F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFB,0x5F,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFB,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,
    0x00,0xA7,0xFF,0xFB,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0xA7,0xFF,0xFB,0x5F,
    0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0xA7,0xFF,0xFB,0x5F,0xFF,0xFF,0x4B,0x00,0x00,
    0x00,0x00,0xA7,0xFF,0xFB,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0xA7,0xFF,0xFB,
    0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0xA7,0xFF,0xFB,0x5F,0xFF,0xFF,0x4B,0x00,
    0x00,0x00,0x99,0xFF,0xFF,0x55,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x54,0xFF,0xFF,
    0x97,0x00,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x1E,0xEF,0xFF,0xD2,0x08,0x00,0x00,0x5F,
    0xFF,0xFF,0x4B,0x03,0xC4,0xFF,0xF4,0x28,0x00,0x00,0x00,0x5F,0xFF,0xFF,0x4B,0x82,
    0xFF,0xFF,0x5F,0x00,0x00,0x00,0x00,0x5F,0xFF,0xFF,0x8B,0xFD,0xFF,0xCA,0x00,0x00,
    0x00,0x00,0x00,0x5F,0xFF,0xFF,0xFE,0xFF,0xFF,0xFD,0x30,0x00,0x00,0x00,0x00,0x5F,
    0xFF,0xFF,0xFF,0xFB,0xF7,0xFF,0xBE,0x00,0x00,0x00,0x00,0x5F,0xFF,0xFF,0xFF,0x76,
    0x86,0xFF,0xFF,0x4F,0x00,0x00,0x00,0x5F,0xFF,0xFF,0xB7,0x01,0x0F,0xEB,0xFF,0xDA,
    0x05,0x00,0x00,0x5F,0xFF,0xFF,0x4C,0x00,0x00,0x6E,0xFF,0xFF,0x70,0x00,0x00,0x5F,
    0xFF,0xFF,0x4B,0x00,0x00,0x06,0xDD,0xFF,0xEE,0x12,0x00,0x5F,0xFF,0xFF,0x4B,0x00,
    0x00,0x00,0x56,0xFF,0xFF,0x92,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x01,0xC9,
    0xFF,0xFB,0x28,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0x00,0x5F,0xFF,0xFF,0x4B,
    0x00,0x00,0x00,0x00,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0x00,0x5F,0xFF,
    0xFF,0x4B,0x00,0x00,0x00,0x00,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0x00,
    0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,
    0x00,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0x00,0x5F,0xFF,0xFF,0x4B,0x00,
    0x00,0x00,0x00,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0x00,0x5F,0xFF,0xFF,
    0x4B,0x00,0x00,0x00,0x00,0x00,0x5F,0xFF,0xFF,0x73,0x37,0x37,0x37,0x37,0x27,0x5F,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xB3,0x5F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xB3,0x5F,0xFF,0xFF,0xC1,0x00,0x00,0x00,0x00,0x00,0x64,0xFF,0xFF,0xBB,0x5F,0xFF,
    0xFF,0xFE,0x1F,0x00,0x00,0x00,0x00,0xBE,0xFF,0xFF,0xBB,0x5F,0xFF,0xFF,0xFF,0x79,
    0x00,0x00,0x00,0x1A,0xFD,0xFF,0xFF,0xBB,0x5F,0xFF,0xEA,0xFF,0xD5,0x00,0x00,0x00,
    0x71,0xFF,0xE7,0xFF,0xBB,0x5F,0xFF,0xC5,0xE2,0xFF,0x31,0x00,0x00,0xCB,0xFF,0xA2,
    0xFF,0xBB,0x5F,0xFF,0xD6,0x8F,0xFF,0x8D,0x00,0x25,0xFF,0xD8,0x87,0xFF,0xBB,0x5F,
    0xFF,0xE8,0x3B,0xFF,0xE5,0x01,0x7B,0xFF,0x83,0x99,0xFF,0xBB,0x5F,0xFF,0xFA,0x01,
    0xDE,0xFF,0x34,0xCA,0xFF,0x28,0xAC,0xFF,0xBB,0x5F,0xFF,0xFF,0x07,0x82,0xFF,0x9B,
    0xFE,0xCB,0x00,0xB3,0xFF,0xBB,0x5F,0xFF,0xFF,0x07,0x25,0xFF,0xFF,0xFF,0x6F,0x00,
    0xB3,0xFF,0xBB,0x5F,0xFF,0xFF,0x07,0x00,0xC7,0xFF,0xFC,0x17,0x00,0xB3,0xFF,0xBB,
    0x5F,0xFF,0xFF,0x07,0x00,0x69,0xFF,0xB7,0x00,0x00,0xB3,0xFF,0xBB,0x5F,0xFF,0xFF,
    0x07,0x00,0x0E,0x53,0x28,0x00,0x00,0xB3,0xFF,0xBB,0x5F,0xFF,0xFF,0x07,0x00,0x00,
    0x00,0x00,0x00,0x00,0xB3,0xFF,0xBB,0x5F,0xFF,0xFF,0xFF,0xFF,0xF2,0xD7,0x98,0x29,
    0x00,0x00,0x5F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF7,0x36,0x00,0x5F,0xFF,0xFF,
    0x5F,0x1C,0x2D,0x71,0xF9,0xFF,0xD8,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x92,
    0xFF,0xFF,0x10,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x6E,0xFF,0xFF,0x2E,0x5F,0xFF,
    0xFF,0x4B,0x00,0x00,0x00,0xA0,0xFF,0xFB,0x08,0x5F,0xFF,0xFF,0x5C,0x18,0x2B,0x7C,
    0xFD,0xFF,0xBE,0x00,0x5F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xEB,0x1E,0x00,0x5F,
    0xFF,0xFF,0xFF,0xFF,0xF2,0xD1,0x88,0x13,0x00,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x5F,0xFF,0xFF,0x4B,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x5F,0xFF,0xFF,0x4B,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x77,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xB7,0x77,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xB7,0x1A,0x37,0x37,0x37,0xC7,0xFF,0xF3,0x37,0x37,
    0x37,0x28,0x00,0x00,0x00,0x00,0xB7,0xFF,0xEF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xB7,0xFF,0xEF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB7,0xFF,0xEF,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB7,0xFF,0xEF,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xB7,0xFF,0xEF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB7,0xFF,0xEF,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB7,0xFF,0xEF,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0xB7,0xFF,0xEF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB7,0xFF,
    0xEF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB7,0xFF,0xEF,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xB7,0xFF,0xEF,0x00,0x00,0x00,0x00,0x98,0xFF,0xFF,0x1B,0x00,
    0x00,0x01,0xEF,0xFF,0x8C,0x00,0x00,0x00,0x83,0xFF,0xFC,0x08,0x69,0xFF,0xFF,0x42,
    0x00,0x00,0x2A,0xFF,0xFF,0xC5,0x00,0x00,0x00,0xA9,0xFF,0xD7,0x00,0x3A,0xFF,0xFF,
    0x69,0x00,0x00,0x63,0xFF,0xFF,0xF8,0x07,0x00,0x00,0xCF,0xFF,0xAA,0x00,0x0D,0xFE,
    0xFF,0x90,0x00,0x00,0x9C,0xFF,0xFD,0xFF,0x39,0x00,0x01,0xF4,0xFF,0x7D,0x00,0x00,
    0xDC,0xFF,0xB8,0x00,0x00,0xD5,0xFF,0xB9,0xFF,0x73,0x00,0x1B,0xFF,0xFF,0x50,0x00,
    0x00,0xAD,0xFF,0xDF,0x00,0x10,0xFE,0xE6,0x77,0xFF,0xAC,0x00,0x41,0xFF,0xFF,0x23,
    0x00,0x00,0x7D,0xFF,0xFD,0x09,0x48,0xFF,0xB9,0x4A,0xFF,0xE7,0x00,0x67,0xFF,0xF4,
    0x01,0x00,0x00,0x4E,0xFF,0xFF,0x2B,0x7B,0xFF,0x89,0x19,0xFF,0xFF,0x1A,0x8B,0xFF,
    0xC8,0x00,0x00,0x00,0x1F,0xFF,0xFF,0x4D,0xAB,0xFF,0x52,0x00,0xE1,0xFF,0x4A,0xAD,
    0xFF,0x9B,0x00,0x00,0x00,0x00,0xEF,0xFF,0x70,0xDB,0xFF,0x1C,0x00,0xA9,0xFF,0x7A,
    0xCE,0xFF,0x6E,0x00,0x00,0x00,0x00,0xC1,0xFF,0xA0,0xFE,0xE6,0x00,0x00,0x70,0xFF,
    0xAB,0xF0,0xFF,0x41,0x00,0x00,0x00,0x00,0x92,0xFF,0xEF,0xFF,0xAF,0x00,0x00,0x38,
    0xFF,0xED,0xFF,0xFF,0x14,0x00,0x00,0x00,0x00,0x63,0xFF,0xFF,0xFF,0x78,0x00,0x00,
    0x07,0xF9,0xFF,0xFF,0xE7,0x00,0x00,0x00,0x00,0x00,0x33,0xFF,0xFF,0xFF,0x42,0x00,
    0x00,0x00,0xC8,0xFF,0xFF,0xBA,0x00,0x00,0x00,0x00,0x00,0x3F,0xA3,0xD2,0xF4,0xD3,
    0x7A,0x03,0x00,0x00,0x7D,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x93,0x00,0x00,0x1F,0xDB,
    0x77,0x38,0x38,0xD4,0xFF,0xFA,0x16,0x00,0x00,0x00,0x00,0x00,0x03,0x7F,0xFF,0xFF,
    0x3E,0x00,0x00,0x1F,0x82,0xD0,0xF8,0xFF,0xFF,0xFF,0x59,0x00,0x47,0xF7,0xFF,0xC6,
    0x81,0x7E,0xFF,0xFF,0x5B,0x00,0xE1,0xFF,0x9B,0x00,0x00,0x4B,0xFF,0xFF,0x5B,0x09,
    0xFF,0xFF,0xBF,0x24,0x3E,0xCB,0xFF,0xFF,0x5B,0x00,0xC0,0xFF,0xFF,0xFF,0xFF,0xE6,
    0xFE,0xFF,0x5B,0x00,0x17,0xA7,0xED,0xDC,0x94,0x11,0xE2,0xFF,0x5B,0x00,0x00,0x00,
    0x5A,0xBC,0xEB,0xE2,0xA6,0x23,0x00,0x02,0xB1,0xFF,0xFF,0xFF,0xFF,0xFF,0x91,0x00,
    0x7A,0xFF,0xFF,0xBC,0x48,0x42,0x91,0x07,0x00,0xE9,0xFF,0xDB,0x06,0x00,0x00,0x00,
    0x00,0x1D,0xFF,0xFF,0x90,0x00,0x00,0x00,0x00,0x00,0x22,0xFF,0xFF,0x8E,0x00,0x00,
    0x00,0x00,0x00,0x01,0xF2,0xFF,0xD6,0x04,0x00,0x00,0x00,0x00,0x00,0x92,0xFF,0xFF,
    0xB2,0x3F,0x41,0xA1,0x34,0x00,0x0B,0xCF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC4,0x00,0x00,
    0x06,0x7A,0xC9,0xF2,0xDD,0x9E,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,
    0x07,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7B,0xFF,0xFF,0x2B,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x7B,0xFF,0xFF,0x2B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7B,
    0xFF,0xFF,0x2B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7A,0xFF,0xFF,0x2B,0x00,0x00,
    0x0A,0x91,0xDD,0xE7,0xA1,0x7F,0xFF,0xFF,0x2B,0x00,0x09,0xD1,0xFF,0xFF,0xFF,0xFF,
    0xFD,0xFF,0xFF,0x2B,0x00,0x7D,0xFF,0xFF,0xA7,0x3E,0x5C,0xDB,0xFF,0xFF,0x2B,0x00,
    0xE1,0xFF,0xDD,0x04,0x00,0x00,0x7B,0xFF,0xFF,0x2B,0x0C,0xFF,0xFF,0xA0,0x00,0x00,
    0x00,0x7B,0xFF,0xFF,0x2B,0x1B,0xFF,0xFF,0x9D,0x00,0x00,0x00,0x7B,0xFF,0xFF,0x2B,
    0x01,0xF6,0xFF,0xD3,0x00,0x00,0x00,0x7D,0xFF,0xFF,0x2B,0x00,0xAB,0xFF,0xFF,0x93,
    0x39,0x66,0xF1,0xFF,0xFF,0x2B,0x00,0x25,0xEF,0xFF,0xFF,0xFF,0xFF,0xEB,0xFF,0xFF,
    0x2B,0x00,0x00,0x22,0xAE,0xE7,0xDE,0x8E,0x1C,0xFF,0xFF,0x2B,0x00,0x00,0x03,0x74,
    0xC9,0xF2,0xCB,0x78,0x02,0x00,0x00,0x05,0xC0,0xFF,0xFF,0xFF,0xFF,0xFF,0xAC,0x00,
    0x00,0x80,0xFF,0xF4,0x57,0x1A,0x53,0xF8,0xFF,0x42,0x00,0xEC,0xFF,0x7E,0x00,0x00,
    0x00,0xA8,0xFF,0x89,0x1E,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xAB,0x21,0xFF,
    0xFF,0xD9,0xBF,0xBF,0xBF,0xBF,0xBF,0x76,0x01,0xF0,0xFF,0x9F,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x8C,0xFF,0xFF,0x80,0x1E,0x14,0x45,0x5A,0x00,0x00,0x08,0xC7,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xF6,0x1A,0x00,0x00,0x03,0x71,0xC5,0xF1,0xE3,0xB5,0x49,0x00,
    0x00,0x00,0x34,0xB0,0xE7,0xFF,0xFF,0xFF,0xFF,0xFF,0x43,0x00,0x3D,0xF9,0xFF,0xF8,
    0xEE,0xFF,0xFF,0xFA,0xF3,0x40,0x00,0xBD,0xFF,0xD0,0x11,0x06,0x9F,0xFF,0xCF,0x00,
    0x00,0x00,0xE1,0xFF,0x97,0x00,0x00,0x5B,0xFF,0xF5,0x00,0x00,0x00,0x9C,0xFF,0xE2,
    0x39,0x24,0xBC,0xFF,0xC0,0x00,0x00,0x00,0x10,0xD7,0xFF,0xFF,0xFF,0xFF,0xED,0x2C,
    0x00,0x00,0x00,0x39,0xF7,0xC3,0x87,0x96,0x6E,0x0F,0x00,0x00,0x00,0x00,0xA3,0xFF,
    0x93,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x83,0xFF,0xFF,0xFA,0xEB,0xEA,0xD8,
    0xAE,0x3E,0x00,0x00,0x18,0xF3,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x28,0x02,0xD6,
    0xFF,0x36,0x0C,0x13,0x1E,0x63,0xFF,0xFF,0x5F,0x2C,0xFF,0xFD,0x26,0x00,0x00,0x00,
    0x64,0xFF,0xFF,0x29,0x04,0xE0,0xFF,0xFB,0xD3,0xBA,0xEA,0xFF,0xFF,0x73,0x00,0x00,
    0x19,0x93,0xDB,0xF5,0xF0,0xD2,0x9C,0x30,0x00,0x00,0x04,0x07,0x07,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x00,0x00,0x00,0x00,0x93,0xFF,
    0xFF,0x0B,0x00,0x00,0x00,0x00,0x00,0x00,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x00,0x00,
    0x00,0x00,0x93,0xFF,0xFF,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x93,0xFF,0xFD,0x11,
    0x90,0xD7,0xEB,0xA5,0x10,0x00,0x93,0xFF,0xFA,0xDE,0xFF,0xFF,0xFF,0xFF,0xAA,0x00,
    0x93,0xFF,0xFF,0xE7,0x73,0x5C,0xE8,0xFF,0xFC,0x0C,0x93,0xFF,0xFF,0x21,0x00,0x00,
    0x99,0xFF,0xFF,0x2A,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x6E,0xFF,0xFF,0x37,0x93,0xFF,
    0xFF,0x0B,0x00,0x00,0x6B,0xFF,0xFF,0x37,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x6B,0xFF,
    0xFF,0x37,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x6B,0xFF,0xFF,0x37,0x93,0xFF,0xFF,0x0B,
    0x00,0x00,0x6B,0xFF,0xFF,0x37,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x6B,0xFF,0xFF,0x37,
    0x43,0xC3,0x96,0x01,0xBC,0xFF,0xFF,0x33,0x56,0xE3,0xB5,0x04,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x93,0xFF,0xFF,0x0B,0x93,0xFF,0xFF,0x0B,0x93,0xFF,0xFF,0x0B,
    0x93,0xFF,0xFF,0x0B,0x93,0xFF,0xFF,0x0B,0x93,0xFF,0xFF,0x0B,0x93,0xFF,0xFF,0x0B,
    0x93,0xFF,0xFF,0x0B,0x93,0xFF,0xFF,0x0B,0x93,0xFF,0xFF,0x0B,0x5A,0x9B,0x9B,0x07,
    0x00,0x93,0xFF,0xFF,0x0B,0x00,0x93,0xFF,0xFF,0x0B,0x00,0x93,0xFF,0xFF,0x0B,0x00,
    0x93,0xFF,0xFF,0x0B,0x00,0x93,0xFF,0xFF,0x0B,0x00,0x93,0xFF,0xFF,0x0B,0x00,0x93,
    0xFF,0xFF,0x0B,0x00,0x93,0xFF,0xFF,0x0B,0x00,0x93,0xFF,0xFF,0x0B,0x00,0x93,0xFF,
    0xFF,0x0B,0x00,0x93,0xFF,0xFF,0x0B,0x00,0x85,0xFF,0xFF,0x4E,0x00,0x50,0xFF,0xFF,
    0xFF,0x0D,0x02,0x92,0xEC,0xE7,0x29,0x93,0xFF,0xA1,0x14,0xA5,0xF0,0xEC,0x94,0x06,
    0x12,0xA2,0xEF,0xE1,0x87,0x03,0x00,0x93,0xFF,0xD6,0xDE,0xFF,0xFF,0xFF,0xFF,0xA2,
    0xD9,0xFF,0xFF,0xFF,0xFF,0x76,0x00,0x93,0xFF,0xFF,0xE6,0x6C,0x6B,0xFA,0xFF,0xFF,
    0xE6,0x6C,0x6B,0xFA,0xFF,0xD7,0x00,0x93,0xFF,0xFF,0x20,0x00,0x00,0xC9,0xFF,0xFF,
    0x20,0x00,0x00,0xC9,0xFF,0xF8,0x01,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x9E,0xFF,0xFF,
    0x0B,0x00,0x00,0x9E,0xFF,0xFF,0x07,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x9B,0xFF,0xFF,
    0x0B,0x00,0x00,0x9B,0xFF,0xFF,0x07,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x9B,0xFF,0xFF,
    0x0B,0x00,0x00,0x9B,0xFF,0xFF,0x07,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x9B,0xFF,0xFF,
    0x0B,0x00,0x00,0x9B,0xFF,0xFF,0x07,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x9B,0xFF,0xFF,
    0x0B,0x00,0x00,0x9B,0xFF,0xFF,0x07,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x9B,0xFF,0xFF,
    0x0B,0x00,0x00,0x9B,0xFF,0xFF,0x07,0x93,0xFF,0xA1,0x0F,0x8F,0xD6,0xEB,0xA5,0x10,
    0x00,0x93,0xFF,0xD7,0xDC,0xFF,0xFF,0xFF,0xFF,0xAA,0x00,0x93,0xFF,0xFF,0xE7,0x73,
    0x5C,0xE8,0xFF,0xFC,0x0C,0x93,0xFF,0xFF,0x21,0x00,0x00,0x99,0xFF,0xFF,0x2A,0x93,
    0xFF,0xFF,0x0B,0x00,0x00,0x6E,0xFF,0xFF,0x37,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x6B,
    0xFF,0xFF,0x37,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x6B,0xFF,0xFF,0x37,0x93,0xFF,0xFF,
    0x0B,0x00,0x00,0x6B,0xFF,0xFF,0x37,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x6B,0xFF,0xFF,
    0x37,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x6B,0xFF,0xFF,0x37,0x00,0x00,0x02,0x6F,0xC6,
    0xF2,0xD3,0x90,0x0F,0x00,0x00,0x00,0x05,0xC1,0xFF,0xFF,0xFF,0xFF,0xFF,0xE5,0x22,
    0x00,0x00,0x83,0xFF,0xFF,0x96,0x3B,0x6F,0xF8,0xFF,0xC1,0x01,0x00,0xED,0xFF,0xCA,
    0x00,0x00,0x00,0x8B,0xFF,0xFF,0x2B,0x1E,0xFF,0xFF,0x8B,0x00,0x00,0x00,0x4C,0xFF,
    0xFF,0x5C,0x20,0xFF,0xFF,0x8A,0x00,0x00,0x00,0x4B,0xFF,0xFF,0x60,0x00,0xEE,0xFF,
    0xC6,0x00,0x00,0x00,0x87,0xFF,0xFF,0x2D,0x00,0x89,0xFF,0xFF,0x8F,0x36,0x69,0xF6,
    0xFF,0xC5,0x02,0x00,0x07,0xC4,0xFF,0xFF,0xFF,0xFF,0xFF,0xE7,0x24,0x00,0x00,0x00,
    0x03,0x72,0xC9,0xF3,0xD5,0x92,0x11,0x00,0x00,0x93,0xFF,0xA4,0x2B,0xAD,0xEA,0xD7,
    0x8A,0x06,0x00,0x93,0xFF,0xED,0xF9,0xFF,0xFF,0xFF,0xFF,0xB8,0x00,0x93,0xFF,0xFF,
    0xCA,0x51,0x47,0xCD,0xFF,0xFF,0x47,0x93,0xFF,0xFF,0x0E,0x00,0x00,0x2F,0xFF,0xFF,
    0x92,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x02,0xFC,0xFF,0xB6,0x93,0xFF,0xFF,0x0B,0x00,
    0x00,0x09,0xFF,0xFF,0xA7,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x4B,0xFF,0xFF,0x7C,0x93,
    0xFF,0xFF,0xA1,0x3E,0x53,0xE3,0xFF,0xF8,0x22,0x93,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0x76,0x00,0x93,0xFF,0xFD,0x45,0xC7,0xF1,0xC5,0x53,0x00,0x00,0x93,0xFF,0xFF,
    0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x00,0x00,0x00,
    0x00,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x00,0x00,0x00,0x00,0x93,0xFF,0xFF,0x0B,0x00,
    0x00,0x00,0x00,0x00,0x00,0x93,0xFF,0x9E,0x0A,0x95,0xEB,0xC7,0x93,0xFF,0xB6,0xB0,
    0xFF,0xFF,0x97,0x93,0xFF,0xFE,0xFE,0xA1,0x65,0x36,0x93,0xFF,0xFF,0x81,0x00,0x00,
    0x00,0x93,0xFF,0xFF,0x0C,0x00,0x00,0x00,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x00,0x93,
    0xFF,0xFF,0x0B,0x00,0x00,0x00,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x00,0x93,0xFF,0xFF,
    0x0B,0x00,0x00,0x00,0x93,0xFF,0xFF,0x0B,0x00,0x00,0x00,0x00,0x02,0x6A,0xD0,0xF4,
    0xD6,0x9E,0x26,0x00,0x00,0x83,0xFF,0xFF,0xFF,0xFF,0xFF,0xDB,0x05,0x00,0xEB,0xFF,
    0xAE,0x11,0x22,0x89,0x34,0x00,0x00,0xE8,0xFF,0xCF,0x36,0x00,0x00,0x00,0x00,0x00,
    0x5A,0xF7,0xFF,0xFF,0xD3,0x5C,0x03,0x00,0x00,0x00,0x1B,0x93,0xF2,0xFF,0xFF,0xBE,
    0x03,0x00,0x00,0x00,0x00,0x0B,0x91,0xFF,0xFF,0x35,0x01,0xA7,0x81,0x21,0x08,0x76,
    0xFF,0xFF,0x2E,0x45,0xFD,0xFF,0xFF,0xFE,0xFF,0xFF,0xBB,0x02,0x00,0x30,0xA4,0xD8,
    0xF5,0xD4,0x80,0x0C,0x00,0x00,0x00,0x90,0xAF,0x4C,0x00,0x00,0x00,0x00,0x00,0xE9,
    0xFF,0x6F,0x00,0x00,0x00,0x00,0x07,0xFE,0xFF,0x6F,0x00,0x00,0x00,0x8D,0xF5,0xFF,
    0xFF,0xFF,0xFF,0xEB,0x00,0x9F,0xFF,0xFF,0xFF,0xFF,0xFF,0xEB,0x00,0x0E,0x47,0xFF,
    0xFF,0x7D,0x17,0x16,0x00,0x00,0x33,0xFF,0xFF,0x6F,0x00,0x00,0x00,0x00,0x33,0xFF,
    0xFF,0x6F,0x00,0x00,0x00,0x00,0x33,0xFF,0xFF,0x6F,0x00,0x00,0x00,0x00,0x2D,0xFF,
    0xFF,0x81,0x00,0x00,0x00,0x00,0x10,0xFE,0xFF,0xD6,0x34,0x2A,0x00,0x00,0x00,0xAE,
    0xFF,0xFF,0xFF,0xF4,0x04,0x00,0x00,0x10,0xA0,0xE5,0xED,0xC1,0x1B,0xAF,0xFF,0xF3,
    0x00,0x00,0x00,0x97,0xFF,0xFF,0x0F,0xAF,0xFF,0xF3,0x00,0x00,0x00,0x97,0xFF,0xFF,
    0x0F,0xAF,0xFF,0xF3,0x00,0x00,0x00,0x97,0xFF,0xFF,0x0F,0xAF,0xFF,0xF3,0x00,0x00,
    0x00,0x97,0xFF,0xFF,0x0F,0xAF,0xFF,0xF3,0x00,0x00,0x00,0x97,0xFF,0xFF,0x0F,0xAF,
    0xFF,0xF6,0x00,0x00,0x00,0x97,0xFF,0xFF,0x0F,0xA3,0xFF,0xFF,0x1E,0x00,0x00,0xB4,
    0xFF,0xFF,0x0F,0x83,0xFF,0xFF,0x9C,0x53,0xAB,0xFF,0xFF,0xFF,0x0F,0x28,0xFE,0xFF,
    0xFF,0xFF,0xFD,0xA9,0xFF,0xFF,0x0F,0x00,0x51,0xD3,0xF0,0xB9,0x4A,0x2A,0xFF,0xFF,
    0x0F,0x8C,0xFF,0xFC,0x17,0x00,0x00,0x00,0x99,0xFF,0xE7,0x03,0x27,0xFF,0xFF,0x6C,
    0x00,0x00,0x00,0xE4,0xFF,0x91,0x00,0x00,0xC0,0xFF,0xC5,0x00,0x00,0x31,0xFF,0xFF,
    0x38,0x00,0x00,0x59,0xFF,0xFE,0x1F,0x00,0x7D,0xFF,0xDE,0x00,0x00,0x00,0x07,0xEC,
    0xFF,0x76,0x00,0xC8,0xFF,0x86,0x00,0x00,0x00,0x00,0x8C,0xFF,0xC5,0x0F,0xFC,0xFF,
    0x2D,0x00,0x00,0x00,0x00,0x27,0xFF,0xFD,0x63,0xFF,0xD4,0x00,0x00,0x00,0x00,0x00,
    0x00,0xBF,0xFF,0xE6,0xFF,0x7B,0x00,0x00,0x00,0x00,0x00,0x00,0x59,0xFF,0xFF,0xFF,
    0x23,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xEF,0xFF,0xC9,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x1F,0xFB,0xFF,0x69,0x00,0x00,0x00,0x00,0x00,0x1B,0x3C,0xC2,0xFF,0xEB,
    0x09,0x00,0x00,0x00,0x00,0x00,0xC4,0xFF,0xFF,0xFF,0x50,0x00,0x00,0x00,0x00,0x00,
    0x05,0xF7,0xF5,0xCA,0x4B,0x00,0x00,0x00,0x00,0x00,0x00,
};

leRasterFont NotoSansCJKsc_Bold16 =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)NotoSansCJKsc_Bold16_data, // data address pointer
            3723, // data size
        },
        LE_RASTER_FONT,
    },
    20,
    15,
    LE_FONT_BPP_8, // bits per pixel
    NotoSansCJKsc_Bold16_glyphs, // glyph table
};
