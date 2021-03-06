// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Font Asset
 * Name:         NotoSansCJKsc_Regular16
 * Height:       19
 * Baseline:     14
 * Style:        Antialias
 * Glyph Count:  58
 * Range Count:  12
 * Glyph Ranges: 0x20
                 0x28-0x29
                 0x2B-0x3A
                 0x3C
                 0x3E-0x3F
                 0x41-0x42
                 0x44-0x45
                 0x48
                 0x4B-0x4C
                 0x53-0x54
                 0x57
                 0x61-0x7A
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
const uint8_t NotoSansCJKsc_Regular16_glyphs[1164] =
{
    0x3A,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x28,0x00,0x04,0x00,0x11,0x00,0x05,0x00,
    0x01,0x00,0x0D,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x29,0x00,0x04,0x00,
    0x11,0x00,0x05,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x04,0x00,0x44,0x00,0x00,0x00,
    0x2B,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,
    0x88,0x00,0x00,0x00,0x2C,0x00,0x04,0x00,0x07,0x00,0x04,0x00,0x00,0x00,0x03,0x00,
    0x00,0x00,0x04,0x00,0xD9,0x00,0x00,0x00,0x2D,0x00,0x05,0x00,0x02,0x00,0x06,0x00,
    0x00,0x00,0x05,0x00,0x00,0x00,0x05,0x00,0xF5,0x00,0x00,0x00,0x2E,0x00,0x03,0x00,
    0x03,0x00,0x04,0x00,0x01,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0xFF,0x00,0x00,0x00,
    0x2F,0x00,0x07,0x00,0x10,0x00,0x06,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x07,0x00,
    0x08,0x01,0x00,0x00,0x30,0x00,0x09,0x00,0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,
    0x00,0x00,0x09,0x00,0x78,0x01,0x00,0x00,0x31,0x00,0x07,0x00,0x0C,0x00,0x09,0x00,
    0x01,0x00,0x0C,0x00,0x00,0x00,0x07,0x00,0xE4,0x01,0x00,0x00,0x32,0x00,0x09,0x00,
    0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,0x38,0x02,0x00,0x00,
    0x33,0x00,0x08,0x00,0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x08,0x00,
    0xA4,0x02,0x00,0x00,0x34,0x00,0x09,0x00,0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,
    0x00,0x00,0x09,0x00,0x04,0x03,0x00,0x00,0x35,0x00,0x09,0x00,0x0C,0x00,0x09,0x00,
    0x00,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,0x70,0x03,0x00,0x00,0x36,0x00,0x09,0x00,
    0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,0xDC,0x03,0x00,0x00,
    0x37,0x00,0x09,0x00,0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,
    0x48,0x04,0x00,0x00,0x38,0x00,0x09,0x00,0x0C,0x00,0x09,0x00,0x00,0x00,0x0C,0x00,
    0x00,0x00,0x09,0x00,0xB4,0x04,0x00,0x00,0x39,0x00,0x08,0x00,0x0C,0x00,0x09,0x00,
    0x00,0x00,0x0C,0x00,0x00,0x00,0x08,0x00,0x20,0x05,0x00,0x00,0x3A,0x00,0x03,0x00,
    0x09,0x00,0x04,0x00,0x01,0x00,0x09,0x00,0x00,0x00,0x03,0x00,0x80,0x05,0x00,0x00,
    0x3C,0x00,0x09,0x00,0x08,0x00,0x09,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,
    0x9B,0x05,0x00,0x00,0x3E,0x00,0x09,0x00,0x08,0x00,0x09,0x00,0x00,0x00,0x0A,0x00,
    0x00,0x00,0x09,0x00,0xE3,0x05,0x00,0x00,0x3F,0x00,0x07,0x00,0x0D,0x00,0x08,0x00,
    0x00,0x00,0x0D,0x00,0x00,0x00,0x07,0x00,0x2B,0x06,0x00,0x00,0x41,0x00,0x0A,0x00,
    0x0C,0x00,0x0A,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x0A,0x00,0x86,0x06,0x00,0x00,
    0x42,0x00,0x09,0x00,0x0C,0x00,0x0B,0x00,0x01,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,
    0xFE,0x06,0x00,0x00,0x44,0x00,0x0A,0x00,0x0C,0x00,0x0B,0x00,0x01,0x00,0x0C,0x00,
    0x00,0x00,0x0A,0x00,0x6A,0x07,0x00,0x00,0x45,0x00,0x08,0x00,0x0C,0x00,0x09,0x00,
    0x01,0x00,0x0C,0x00,0x00,0x00,0x08,0x00,0xE2,0x07,0x00,0x00,0x48,0x00,0x0A,0x00,
    0x0C,0x00,0x0C,0x00,0x01,0x00,0x0C,0x00,0x00,0x00,0x0A,0x00,0x42,0x08,0x00,0x00,
    0x4B,0x00,0x0A,0x00,0x0C,0x00,0x0A,0x00,0x01,0x00,0x0C,0x00,0x00,0x00,0x0A,0x00,
    0xBA,0x08,0x00,0x00,0x4C,0x00,0x08,0x00,0x0C,0x00,0x09,0x00,0x01,0x00,0x0C,0x00,
    0x00,0x00,0x08,0x00,0x32,0x09,0x00,0x00,0x53,0x00,0x09,0x00,0x0C,0x00,0x0A,0x00,
    0x00,0x00,0x0C,0x00,0x00,0x00,0x09,0x00,0x92,0x09,0x00,0x00,0x54,0x00,0x0A,0x00,
    0x0C,0x00,0x0A,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x0A,0x00,0xFE,0x09,0x00,0x00,
    0x57,0x00,0x0E,0x00,0x0C,0x00,0x0E,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x0E,0x00,
    0x76,0x0A,0x00,0x00,0x61,0x00,0x08,0x00,0x09,0x00,0x09,0x00,0x00,0x00,0x09,0x00,
    0x00,0x00,0x08,0x00,0x1E,0x0B,0x00,0x00,0x62,0x00,0x09,0x00,0x0D,0x00,0x0A,0x00,
    0x01,0x00,0x0D,0x00,0x00,0x00,0x09,0x00,0x66,0x0B,0x00,0x00,0x63,0x00,0x08,0x00,
    0x09,0x00,0x08,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x08,0x00,0xDB,0x0B,0x00,0x00,
    0x64,0x00,0x09,0x00,0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x09,0x00,
    0x23,0x0C,0x00,0x00,0x65,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x00,0x00,0x09,0x00,
    0x00,0x00,0x09,0x00,0x98,0x0C,0x00,0x00,0x66,0x00,0x06,0x00,0x0E,0x00,0x05,0x00,
    0x00,0x00,0x0E,0x00,0x00,0x00,0x06,0x00,0xE9,0x0C,0x00,0x00,0x67,0x00,0x09,0x00,
    0x0D,0x00,0x09,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x09,0x00,0x3D,0x0D,0x00,0x00,
    0x68,0x00,0x08,0x00,0x0D,0x00,0x0A,0x00,0x01,0x00,0x0D,0x00,0x00,0x00,0x08,0x00,
    0xB2,0x0D,0x00,0x00,0x69,0x00,0x03,0x00,0x0D,0x00,0x04,0x00,0x01,0x00,0x0D,0x00,
    0x00,0x00,0x03,0x00,0x1A,0x0E,0x00,0x00,0x6A,0x00,0x05,0x00,0x11,0x00,0x04,0x00,
    0xFF,0xFF,0x0D,0x00,0x00,0x00,0x05,0x00,0x41,0x0E,0x00,0x00,0x6B,0x00,0x08,0x00,
    0x0E,0x00,0x09,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x08,0x00,0x96,0x0E,0x00,0x00,
    0x6C,0x00,0x03,0x00,0x0D,0x00,0x05,0x00,0x01,0x00,0x0D,0x00,0x00,0x00,0x03,0x00,
    0x06,0x0F,0x00,0x00,0x6D,0x00,0x0D,0x00,0x09,0x00,0x0F,0x00,0x01,0x00,0x09,0x00,
    0x00,0x00,0x0D,0x00,0x2D,0x0F,0x00,0x00,0x6E,0x00,0x08,0x00,0x09,0x00,0x0A,0x00,
    0x01,0x00,0x09,0x00,0x00,0x00,0x08,0x00,0xA2,0x0F,0x00,0x00,0x6F,0x00,0x09,0x00,
    0x09,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x09,0x00,0xEA,0x0F,0x00,0x00,
    0x70,0x00,0x09,0x00,0x0D,0x00,0x0A,0x00,0x01,0x00,0x09,0x00,0x00,0x00,0x09,0x00,
    0x3B,0x10,0x00,0x00,0x71,0x00,0x09,0x00,0x0D,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,
    0x00,0x00,0x09,0x00,0xB0,0x10,0x00,0x00,0x72,0x00,0x06,0x00,0x09,0x00,0x06,0x00,
    0x01,0x00,0x09,0x00,0x00,0x00,0x06,0x00,0x25,0x11,0x00,0x00,0x73,0x00,0x07,0x00,
    0x09,0x00,0x07,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x07,0x00,0x5B,0x11,0x00,0x00,
    0x74,0x00,0x06,0x00,0x0C,0x00,0x06,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x06,0x00,
    0x9A,0x11,0x00,0x00,0x75,0x00,0x08,0x00,0x09,0x00,0x0A,0x00,0x01,0x00,0x09,0x00,
    0x00,0x00,0x08,0x00,0xE2,0x11,0x00,0x00,0x76,0x00,0x09,0x00,0x09,0x00,0x08,0x00,
    0x00,0x00,0x09,0x00,0x00,0x00,0x09,0x00,0x2A,0x12,0x00,0x00,0x77,0x00,0x0D,0x00,
    0x09,0x00,0x0D,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x0D,0x00,0x7B,0x12,0x00,0x00,
    0x78,0x00,0x08,0x00,0x09,0x00,0x08,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x08,0x00,
    0xF0,0x12,0x00,0x00,0x79,0x00,0x09,0x00,0x0D,0x00,0x08,0x00,0x00,0x00,0x09,0x00,
    0x00,0x00,0x09,0x00,0x38,0x13,0x00,0x00,0x7A,0x00,0x08,0x00,0x09,0x00,0x08,0x00,
    0x00,0x00,0x09,0x00,0x00,0x00,0x08,0x00,0xAD,0x13,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t NotoSansCJKsc_Regular16_data[5109] =
{
    0x00,0x00,0x73,0x76,0x00,0x0F,0xEC,0x30,0x00,0x6D,0xBB,0x00,0x00,0xCD,0x64,0x00,
    0x13,0xFF,0x1D,0x00,0x4A,0xEB,0x00,0x00,0x6B,0xC8,0x00,0x00,0x7D,0xB8,0x00,0x00,
    0x81,0xB5,0x00,0x00,0x6F,0xC4,0x00,0x00,0x57,0xE0,0x00,0x00,0x21,0xFF,0x11,0x00,
    0x00,0xE2,0x4E,0x00,0x00,0x86,0xA3,0x00,0x00,0x22,0xF1,0x17,0x00,0x00,0x97,0x86,
    0x00,0x00,0x0E,0x07,0x1E,0xC1,0x03,0x00,0x00,0xC6,0x63,0x00,0x00,0x53,0xD3,0x00,
    0x00,0x08,0xF3,0x35,0x00,0x00,0xB3,0x7A,0x00,0x00,0x82,0xB3,0x00,0x00,0x5E,0xD4,
    0x00,0x00,0x4E,0xE7,0x00,0x00,0x4A,0xEC,0x00,0x00,0x5A,0xD9,0x00,0x00,0x76,0xBF,
    0x00,0x00,0xA7,0x89,0x00,0x01,0xE3,0x4A,0x00,0x3B,0xE8,0x04,0x00,0xA5,0x83,0x00,
    0x1E,0xE9,0x0F,0x00,0x00,0x15,0x00,0x00,0x00,0x00,0x00,0x16,0x8F,0x02,0x00,0x00,
    0x00,0x00,0x00,0x00,0x27,0xFF,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x27,0xFF,0x03,
    0x00,0x00,0x00,0x08,0x13,0x13,0x38,0xFF,0x17,0x13,0x13,0x05,0x67,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0x43,0x00,0x00,0x00,0x27,0xFF,0x03,0x00,0x00,0x00,0x00,0x00,
    0x00,0x27,0xFF,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x27,0xFF,0x03,0x00,0x00,0x00,
    0x00,0x00,0x00,0x14,0x83,0x02,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x89,0xF3,
    0x2D,0x00,0x89,0xFE,0x75,0x00,0x00,0xBC,0x66,0x00,0x51,0xE8,0x11,0x0A,0xCE,0x33,
    0x00,0x00,0x00,0x00,0x00,0x43,0xFF,0xFF,0xFF,0xD3,0x08,0x1F,0x1F,0x1F,0x1A,0x05,
    0x1A,0x00,0xAD,0xFC,0x20,0x86,0xDD,0x13,0x00,0x00,0x00,0x00,0x10,0x83,0x00,0x00,
    0x00,0x00,0x00,0x5B,0xB4,0x00,0x00,0x00,0x00,0x00,0xAA,0x65,0x00,0x00,0x00,0x00,
    0x06,0xF0,0x18,0x00,0x00,0x00,0x00,0x48,0xC7,0x00,0x00,0x00,0x00,0x00,0x97,0x78,
    0x00,0x00,0x00,0x00,0x01,0xE4,0x29,0x00,0x00,0x00,0x00,0x35,0xDB,0x00,0x00,0x00,
    0x00,0x00,0x84,0x8B,0x00,0x00,0x00,0x00,0x00,0xD3,0x3C,0x00,0x00,0x00,0x00,0x22,
    0xEA,0x02,0x00,0x00,0x00,0x00,0x71,0x9E,0x00,0x00,0x00,0x00,0x00,0xC0,0x4F,0x00,
    0x00,0x00,0x00,0x12,0xF2,0x0A,0x00,0x00,0x00,0x00,0x5E,0xB1,0x00,0x00,0x00,0x00,
    0x00,0xAC,0x62,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xC3,0xEF,0xBC,0x2B,0x00,
    0x00,0x00,0x31,0xF6,0x97,0x44,0xAE,0xEB,0x1B,0x00,0x00,0xA0,0xC8,0x00,0x00,0x07,
    0xE4,0x7D,0x00,0x00,0xF4,0x75,0x00,0x00,0x00,0x97,0xD3,0x00,0x13,0xFF,0x4E,0x00,
    0x00,0x00,0x71,0xF1,0x00,0x2C,0xFF,0x3C,0x00,0x00,0x00,0x5D,0xFF,0x0B,0x2B,0xFF,
    0x3C,0x00,0x00,0x00,0x5E,0xFF,0x0A,0x12,0xFF,0x4E,0x00,0x00,0x00,0x71,0xF0,0x00,
    0x00,0xF3,0x75,0x00,0x00,0x00,0x97,0xD2,0x00,0x00,0x9E,0xC7,0x00,0x00,0x06,0xE4,
    0x7C,0x00,0x00,0x30,0xF5,0x91,0x3B,0xA9,0xEA,0x1A,0x00,0x00,0x00,0x3F,0xC4,0xF0,
    0xBC,0x2B,0x00,0x00,0x03,0x5A,0xB3,0xFA,0x7B,0x00,0x00,0x0F,0xC3,0xC3,0xFF,0x7B,
    0x00,0x00,0x00,0x00,0x00,0xFB,0x7B,0x00,0x00,0x00,0x00,0x00,0xFB,0x7B,0x00,0x00,
    0x00,0x00,0x00,0xFB,0x7B,0x00,0x00,0x00,0x00,0x00,0xFB,0x7B,0x00,0x00,0x00,0x00,
    0x00,0xFB,0x7B,0x00,0x00,0x00,0x00,0x00,0xFB,0x7B,0x00,0x00,0x00,0x00,0x00,0xFB,
    0x7B,0x00,0x00,0x00,0x00,0x00,0xFB,0x7B,0x00,0x00,0x1E,0x33,0x33,0xFC,0x96,0x33,
    0x2B,0x97,0xFF,0xFF,0xFF,0xFF,0xFF,0xD3,0x00,0x17,0xA5,0xED,0xEC,0xB0,0x22,0x00,
    0x00,0x1E,0xE3,0xB6,0x53,0x51,0xD0,0xDF,0x0A,0x00,0x01,0x58,0x01,0x00,0x00,0x25,
    0xFF,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF6,0x74,0x00,0x00,0x00,0x00,0x00,
    0x00,0x1F,0xFF,0x4E,0x00,0x00,0x00,0x00,0x00,0x00,0x76,0xF4,0x14,0x00,0x00,0x00,
    0x00,0x00,0x14,0xF0,0x86,0x00,0x00,0x00,0x00,0x00,0x04,0xBB,0xD8,0x0D,0x00,0x00,
    0x00,0x00,0x00,0x98,0xF3,0x2A,0x00,0x00,0x00,0x00,0x01,0x90,0xF7,0x43,0x00,0x00,
    0x00,0x00,0x02,0x9C,0xFE,0x74,0x3A,0x3F,0x3F,0x3F,0x04,0x49,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0x13,0x00,0x18,0x9A,0xD9,0xF2,0xC4,0x45,0x00,0x02,0xD1,0xB4,0x52,
    0x3E,0xB0,0xFA,0x31,0x00,0x15,0x00,0x00,0x00,0x08,0xF8,0x7F,0x00,0x00,0x00,0x00,
    0x00,0x0F,0xFC,0x73,0x00,0x00,0x00,0x10,0x3C,0xBF,0xCC,0x10,0x00,0x00,0x27,0xFF,
    0xFF,0xD3,0x16,0x00,0x00,0x00,0x05,0x31,0x54,0xBE,0xE9,0x2F,0x00,0x00,0x00,0x00,
    0x00,0x04,0xCC,0xBE,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0xEF,0x0B,0x4E,0x00,0x00,
    0x00,0x00,0xC3,0xCB,0x45,0xF9,0xA3,0x59,0x44,0xA1,0xFF,0x57,0x00,0x35,0xB6,0xED,
    0xF3,0xC8,0x51,0x00,0x00,0x00,0x00,0x00,0x25,0xF8,0xCF,0x00,0x00,0x00,0x00,0x00,
    0x00,0xB8,0xF0,0xCF,0x00,0x00,0x00,0x00,0x00,0x54,0xEF,0x96,0xCF,0x00,0x00,0x00,
    0x00,0x0B,0xE3,0x7A,0x8F,0xCF,0x00,0x00,0x00,0x00,0x8A,0xD9,0x07,0x93,0xCF,0x00,
    0x00,0x00,0x2A,0xFA,0x44,0x00,0x93,0xCF,0x00,0x00,0x00,0xBF,0xA6,0x00,0x00,0x93,
    0xCF,0x00,0x00,0x5B,0xF9,0x40,0x27,0x27,0xA4,0xD7,0x27,0x0E,0xAF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0x5B,0x00,0x00,0x00,0x00,0x00,0x93,0xCF,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x93,0xCF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x93,0xCF,0x00,0x00,
    0x00,0x4D,0xFF,0xFF,0xFF,0xFF,0xFF,0x73,0x00,0x00,0x5E,0xFC,0x40,0x3F,0x3F,0x3F,
    0x1C,0x00,0x00,0x6F,0xE7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xD0,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x92,0xE6,0xD3,0xF5,0xD2,0x5F,0x00,0x00,0x00,0x53,0x9E,
    0x38,0x2F,0x97,0xFF,0x57,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC8,0xCA,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x88,0xF3,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x91,0xE4,
    0x00,0x0A,0x44,0x00,0x00,0x00,0x07,0xDD,0xAE,0x00,0x4B,0xFA,0x9C,0x55,0x4B,0xBF,
    0xF7,0x27,0x00,0x00,0x3B,0xB9,0xEE,0xEF,0xB8,0x2D,0x00,0x00,0x00,0x00,0x03,0x84,
    0xD6,0xED,0xB6,0x2D,0x00,0x00,0x00,0xB4,0xEA,0x68,0x4A,0xA9,0xAD,0x00,0x00,0x44,
    0xFD,0x2C,0x00,0x00,0x00,0x08,0x00,0x00,0xB3,0xB3,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xDE,0x73,0x00,0x04,0x02,0x00,0x00,0x00,0x02,0xFA,0x64,0xA0,0xF2,0xF7,0xAD,
    0x17,0x00,0x14,0xFF,0xE9,0x65,0x12,0x31,0xD9,0xB0,0x00,0x03,0xFA,0x65,0x00,0x00,
    0x00,0x5B,0xFD,0x09,0x00,0xDD,0x79,0x00,0x00,0x00,0x3D,0xFF,0x1F,0x00,0x89,0xD3,
    0x01,0x00,0x00,0x70,0xF4,0x02,0x00,0x17,0xE9,0xA3,0x33,0x53,0xED,0x7D,0x00,0x00,
    0x00,0x1F,0xB1,0xEC,0xDC,0x75,0x02,0x00,0x37,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0x1E,0x0D,0x3F,0x3F,0x3F,0x3F,0x3F,0xD4,0xBA,0x00,0x00,0x00,0x00,0x00,0x00,0x4B,
    0xF4,0x21,0x00,0x00,0x00,0x00,0x00,0x05,0xDD,0x78,0x00,0x00,0x00,0x00,0x00,0x00,
    0x53,0xF8,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0xB9,0xA5,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0F,0xFD,0x58,0x00,0x00,0x00,0x00,0x00,0x00,0x45,0xFF,0x26,0x00,0x00,0x00,
    0x00,0x00,0x00,0x7D,0xF4,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x9F,0xDA,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xB6,0xC9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCC,0xB8,
    0x00,0x00,0x00,0x00,0x00,0x00,0x58,0xD2,0xF4,0xD2,0x59,0x00,0x00,0x00,0x47,0xFC,
    0x65,0x20,0x67,0xFC,0x44,0x00,0x00,0xA0,0xB7,0x00,0x00,0x00,0xAB,0x9C,0x00,0x00,
    0xA2,0xC1,0x00,0x00,0x00,0x9F,0xA5,0x00,0x00,0x3A,0xF9,0x78,0x06,0x12,0xE6,0x4B,
    0x00,0x00,0x00,0x61,0xFF,0xE1,0xCB,0x81,0x00,0x00,0x00,0x2F,0xDB,0x63,0x94,0xF8,
    0xBD,0x12,0x00,0x06,0xE1,0x74,0x00,0x00,0x1C,0xD8,0xBC,0x00,0x36,0xFF,0x24,0x00,
    0x00,0x00,0x5E,0xFF,0x10,0x26,0xFF,0x3B,0x00,0x00,0x00,0x61,0xFB,0x0A,0x00,0xB7,
    0xDB,0x49,0x1D,0x4F,0xE6,0x9C,0x00,0x00,0x0C,0x86,0xDB,0xF6,0xD7,0x7A,0x07,0x00,
    0x00,0x06,0x87,0xE0,0xE6,0xA5,0x14,0x00,0x00,0x9C,0xE1,0x4D,0x41,0xBA,0xDF,0x0A,
    0x17,0xFE,0x50,0x00,0x00,0x08,0xE6,0x75,0x40,0xFF,0x1D,0x00,0x00,0x00,0x92,0xC3,
    0x29,0xFF,0x39,0x00,0x00,0x00,0x83,0xE6,0x03,0xD1,0xC4,0x24,0x18,0x79,0xEE,0xF6,
    0x00,0x25,0xC2,0xFC,0xEE,0x92,0x7D,0xDA,0x00,0x00,0x00,0x08,0x02,0x00,0x97,0xBD,
    0x00,0x00,0x00,0x00,0x00,0x00,0xD6,0x8F,0x00,0x07,0x00,0x00,0x00,0x4A,0xFD,0x24,
    0x01,0xC7,0x96,0x45,0x6B,0xF3,0x93,0x00,0x00,0x3E,0xBE,0xF0,0xD3,0x75,0x00,0x00,
    0x82,0xDB,0x10,0xB1,0xFD,0x22,0x07,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x05,0x1A,0x00,0xAD,0xFC,0x22,0x85,0xDB,0x10,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x01,0x08,0x00,0x00,0x00,0x00,0x00,0x1A,0x7A,0xDD,0x43,0x00,0x00,0x04,
    0x4D,0xB2,0xFA,0xBC,0x5D,0x08,0x19,0x85,0xE6,0xD9,0x7A,0x1D,0x00,0x00,0x00,0x67,
    0xFF,0xA3,0x11,0x00,0x00,0x00,0x00,0x00,0x08,0x5A,0xBE,0xF7,0xAA,0x4A,0x03,0x00,
    0x00,0x00,0x00,0x00,0x24,0x87,0xE7,0xE7,0x8C,0x15,0x00,0x00,0x00,0x00,0x00,0x04,
    0x4F,0xB3,0x40,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x67,0xD1,0x6C,0x11,
    0x00,0x00,0x00,0x00,0x00,0x10,0x6A,0xC9,0xF7,0xA4,0x3F,0x01,0x00,0x00,0x00,0x00,
    0x00,0x29,0x88,0xE4,0xDB,0x77,0x0F,0x00,0x00,0x00,0x00,0x00,0x1C,0xB9,0xFF,0x43,
    0x00,0x00,0x08,0x58,0xB7,0xF8,0xB0,0x4C,0x03,0x23,0x99,0xF0,0xDC,0x79,0x19,0x00,
    0x00,0x00,0x5F,0xA5,0x41,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x21,0x13,
    0x00,0x00,0x00,0x62,0xE7,0xFF,0xFF,0xAE,0x08,0x15,0xCD,0x52,0x0E,0x4B,0xFF,0x7A,
    0x00,0x00,0x00,0x00,0x00,0xCB,0xAD,0x00,0x00,0x00,0x00,0x06,0xEF,0x78,0x00,0x00,
    0x00,0x00,0x86,0xE8,0x18,0x00,0x00,0x00,0x42,0xFD,0x45,0x00,0x00,0x00,0x01,0xDA,
    0x95,0x00,0x00,0x00,0x00,0x24,0xFF,0x32,0x00,0x00,0x00,0x00,0x0D,0x53,0x0C,0x00,
    0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x5D,0xFF,0x6F,0x00,0x00,0x00,
    0x00,0x42,0xE6,0x52,0x00,0x00,0x00,0x00,0x00,0x23,0xFF,0xD5,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x78,0xC7,0xFC,0x2A,0x00,0x00,0x00,0x00,0x00,0x00,0xCD,0x6A,0xC1,
    0x7F,0x00,0x00,0x00,0x00,0x00,0x22,0xFF,0x1F,0x75,0xD4,0x00,0x00,0x00,0x00,0x00,
    0x77,0xD4,0x00,0x29,0xFF,0x29,0x00,0x00,0x00,0x00,0xCC,0x87,0x00,0x00,0xDC,0x7E,
    0x00,0x00,0x00,0x21,0xFF,0x34,0x00,0x00,0x8C,0xD3,0x00,0x00,0x00,0x76,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0x28,0x00,0x00,0xCB,0xA5,0x2F,0x2F,0x2F,0x30,0xED,0x7D,0x00,
    0x20,0xFF,0x4A,0x00,0x00,0x00,0x00,0xA5,0xD2,0x00,0x75,0xF5,0x09,0x00,0x00,0x00,
    0x00,0x59,0xFF,0x27,0xC9,0xB1,0x00,0x00,0x00,0x00,0x00,0x11,0xFC,0x7C,0x67,0xFF,
    0xFF,0xFF,0xF4,0xD8,0x87,0x0C,0x00,0x67,0xFF,0x3C,0x2C,0x39,0x6E,0xF2,0xB0,0x00,
    0x67,0xFF,0x13,0x00,0x00,0x00,0x78,0xFB,0x09,0x67,0xFF,0x13,0x00,0x00,0x00,0x6F,
    0xEC,0x02,0x67,0xFF,0x13,0x00,0x10,0x4E,0xE8,0x8E,0x00,0x67,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xCA,0x1A,0x00,0x67,0xFF,0x35,0x23,0x2E,0x52,0xC0,0xEB,0x28,0x67,0xFF,0x13,
    0x00,0x00,0x00,0x07,0xE1,0x9D,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0xB9,0xBB,0x67,
    0xFF,0x13,0x00,0x00,0x00,0x10,0xEB,0x8F,0x67,0xFF,0x3C,0x2B,0x36,0x5D,0xD0,0xED,
    0x23,0x67,0xFF,0xFF,0xFF,0xF9,0xDD,0x9E,0x26,0x00,0x67,0xFF,0xFF,0xFB,0xD6,0xAB,
    0x3A,0x00,0x00,0x00,0x67,0xFF,0x43,0x3C,0x65,0xBB,0xFD,0x7F,0x00,0x00,0x67,0xFF,
    0x13,0x00,0x00,0x01,0x89,0xFE,0x34,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,0x09,0xE6,
    0xB1,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0xA4,0xDE,0x00,0x67,0xFF,0x13,0x00,
    0x00,0x00,0x00,0x83,0xFC,0x06,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x85,0xFB,0x04,
    0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0xA6,0xDB,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,
    0x0C,0xEA,0xAC,0x00,0x67,0xFF,0x13,0x00,0x00,0x01,0x90,0xFD,0x2F,0x00,0x67,0xFF,
    0x43,0x3C,0x65,0xBD,0xFD,0x7A,0x00,0x00,0x67,0xFF,0xFF,0xFC,0xD8,0xAC,0x3B,0x00,
    0x00,0x00,0x67,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x5B,0x67,0xFF,0x4E,0x3F,0x3F,0x3F,
    0x3F,0x16,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,
    0x00,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x00,0x67,0xFF,0xFF,0xFF,0xFF,0xFF,
    0x87,0x00,0x67,0xFF,0x52,0x43,0x43,0x43,0x24,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,
    0x00,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,
    0x00,0x00,0x67,0xFF,0x4E,0x3F,0x3F,0x3F,0x3F,0x22,0x67,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0x8B,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x6F,0xFF,0x07,0x67,0xFF,0x13,0x00,
    0x00,0x00,0x00,0x6F,0xFF,0x07,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x6F,0xFF,0x07,
    0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x6F,0xFF,0x07,0x67,0xFF,0x13,0x00,0x00,0x00,
    0x00,0x6F,0xFF,0x07,0x67,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x07,0x67,0xFF,
    0x56,0x47,0x47,0x47,0x47,0x98,0xFF,0x07,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x6F,
    0xFF,0x07,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x6F,0xFF,0x07,0x67,0xFF,0x13,0x00,
    0x00,0x00,0x00,0x6F,0xFF,0x07,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x6F,0xFF,0x07,
    0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x6F,0xFF,0x07,0x67,0xFF,0x13,0x00,0x00,0x00,
    0x60,0xFD,0x4B,0x00,0x67,0xFF,0x13,0x00,0x00,0x37,0xF8,0x7C,0x00,0x00,0x67,0xFF,
    0x13,0x00,0x1A,0xE6,0xAF,0x01,0x00,0x00,0x67,0xFF,0x13,0x07,0xC9,0xD6,0x0D,0x00,
    0x00,0x00,0x67,0xFF,0x14,0xA0,0xFF,0x36,0x00,0x00,0x00,0x00,0x67,0xFF,0x85,0xFE,
    0xF7,0x8D,0x00,0x00,0x00,0x00,0x67,0xFF,0xFF,0x79,0x7C,0xFA,0x25,0x00,0x00,0x00,
    0x67,0xFF,0xA6,0x00,0x09,0xE3,0xB1,0x00,0x00,0x00,0x67,0xFF,0x18,0x00,0x00,0x5C,
    0xFF,0x44,0x00,0x00,0x67,0xFF,0x13,0x00,0x00,0x01,0xCB,0xD2,0x03,0x00,0x67,0xFF,
    0x13,0x00,0x00,0x00,0x3D,0xFF,0x67,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0xAC,
    0xEA,0x0F,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,
    0x00,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,
    0x00,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,
    0x00,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,
    0x00,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,0x00,0x00,0x67,0xFF,0x13,0x00,0x00,0x00,
    0x00,0x00,0x67,0xFF,0x4E,0x3F,0x3F,0x3F,0x3F,0x0C,0x67,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0x33,0x00,0x00,0x32,0xB4,0xEB,0xE4,0xAF,0x36,0x00,0x00,0x2A,0xF4,0xBF,0x5E,
    0x66,0xAA,0xFB,0x31,0x00,0x8D,0xEB,0x07,0x00,0x00,0x00,0x2E,0x00,0x00,0x9B,0xEC,
    0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0xFF,0xC0,0x35,0x00,0x00,0x00,0x00,0x00,
    0x00,0x4B,0xE1,0xFF,0xC2,0x4D,0x00,0x00,0x00,0x00,0x00,0x09,0x65,0xD6,0xFF,0xAA,
    0x0F,0x00,0x00,0x00,0x00,0x00,0x03,0x68,0xFD,0x8F,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xBB,0xCA,0x00,0x72,0x25,0x00,0x00,0x00,0x03,0xD6,0xAB,0x0E,0xC7,0xF4,0x97,
    0x5E,0x5D,0xBB,0xF9,0x34,0x00,0x03,0x71,0xB9,0xEC,0xE7,0xB3,0x32,0x00,0x83,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x13,0x20,0x3F,0x3F,0x3F,0xF6,0xA5,0x3F,0x3F,
    0x3F,0x04,0x00,0x00,0x00,0x00,0xF3,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xF3,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0x87,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xF3,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0x87,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0x87,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xF3,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0x87,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xF3,0x87,0x00,0x00,0x00,0x00,0x81,0xFB,0x08,0x00,0x00,0x00,0xC0,0xD7,0x00,0x00,
    0x00,0x00,0xE8,0x81,0x4C,0xFF,0x33,0x00,0x00,0x07,0xF7,0xFF,0x19,0x00,0x00,0x18,
    0xFF,0x4D,0x17,0xFF,0x64,0x00,0x00,0x3E,0xDF,0xD9,0x59,0x00,0x00,0x49,0xFF,0x19,
    0x00,0xE1,0x94,0x00,0x00,0x7D,0xA9,0xA3,0x9A,0x00,0x00,0x79,0xE6,0x00,0x00,0xAC,
    0xC4,0x00,0x00,0xBC,0x72,0x6D,0xDB,0x00,0x00,0xA9,0xB2,0x00,0x00,0x77,0xF3,0x02,
    0x05,0xF5,0x37,0x31,0xFF,0x1C,0x00,0xDA,0x7E,0x00,0x00,0x41,0xFF,0x26,0x39,0xF5,
    0x05,0x02,0xEF,0x5C,0x0C,0xFE,0x4B,0x00,0x00,0x0E,0xFE,0x52,0x72,0xBC,0x00,0x00,
    0xB3,0x93,0x36,0xFF,0x18,0x00,0x00,0x00,0xD7,0x7F,0xAA,0x7E,0x00,0x00,0x74,0xC9,
    0x62,0xE3,0x00,0x00,0x00,0x00,0xA1,0xAC,0xE2,0x41,0x00,0x00,0x35,0xF9,0x95,0xB0,
    0x00,0x00,0x00,0x00,0x6C,0xEE,0xFA,0x09,0x00,0x00,0x03,0xF2,0xEC,0x7C,0x00,0x00,
    0x00,0x00,0x36,0xFF,0xC6,0x00,0x00,0x00,0x00,0xB7,0xFF,0x49,0x00,0x00,0x00,0x0C,
    0x78,0xC2,0xF1,0xD8,0x67,0x00,0x00,0x7E,0xCF,0x6C,0x46,0x96,0xFF,0x3E,0x00,0x06,
    0x02,0x00,0x00,0x02,0xF1,0x95,0x00,0x00,0x00,0x0B,0x3F,0x6C,0xE6,0xB2,0x00,0x0A,
    0x94,0xE6,0xA6,0x73,0xD2,0xB7,0x00,0xB0,0xC4,0x0F,0x00,0x00,0xBB,0xB7,0x06,0xFA,
    0x65,0x00,0x00,0x02,0xC9,0xB7,0x00,0xE4,0xC6,0x44,0x4D,0xBE,0xF1,0xB7,0x00,0x39,
    0xCF,0xF3,0xC1,0x4F,0x88,0xB7,0x6E,0xBF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x87,
    0xEB,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x87,0xEB,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x87,0xEB,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x87,0xE4,0x34,0xB7,0xEF,0xCD,
    0x58,0x00,0x00,0x87,0xF9,0xE3,0x70,0x4D,0xAA,0xFF,0x4D,0x00,0x87,0xF3,0x17,0x00,
    0x00,0x01,0xD3,0xC3,0x00,0x87,0xEB,0x00,0x00,0x00,0x00,0x8B,0xF3,0x00,0x87,0xEB,
    0x00,0x00,0x00,0x00,0x7C,0xFE,0x06,0x87,0xEB,0x00,0x00,0x00,0x00,0x9B,0xE0,0x00,
    0x87,0xED,0x00,0x00,0x00,0x0D,0xED,0xA1,0x00,0x87,0xFD,0xBE,0x50,0x4E,0xC9,0xF2,
    0x1F,0x00,0x87,0xB2,0x5D,0xD2,0xF0,0xB8,0x27,0x00,0x00,0x00,0x00,0x22,0xAB,0xE7,
    0xE4,0x9D,0x14,0x00,0x28,0xF4,0xCB,0x57,0x52,0xBD,0x34,0x00,0xBD,0xDF,0x08,0x00,
    0x00,0x00,0x00,0x06,0xFB,0x7D,0x00,0x00,0x00,0x00,0x00,0x25,0xFF,0x5D,0x00,0x00,
    0x00,0x00,0x00,0x09,0xFD,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0xC9,0xD8,0x05,0x00,
    0x00,0x00,0x00,0x00,0x38,0xFA,0xC1,0x4F,0x4E,0xB1,0x6A,0x00,0x00,0x31,0xB9,0xED,
    0xE2,0x9E,0x17,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xCF,0x57,0x00,0x00,0x00,0x00,
    0x00,0x00,0x07,0xFF,0x6B,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0x6B,0x00,0x00,
    0x00,0x00,0x00,0x00,0x06,0xFF,0x6B,0x00,0x00,0x30,0xBD,0xF0,0xCF,0x55,0xFB,0x6B,
    0x00,0x2D,0xF7,0xC4,0x53,0x5D,0xD0,0xFF,0x6B,0x00,0xB8,0xDD,0x07,0x00,0x00,0x0B,
    0xFF,0x6B,0x02,0xF7,0x7E,0x00,0x00,0x00,0x07,0xFF,0x6B,0x1D,0xFF,0x5F,0x00,0x00,
    0x00,0x07,0xFF,0x6B,0x0A,0xFF,0x75,0x00,0x00,0x00,0x07,0xFF,0x6B,0x00,0xD8,0xC6,
    0x00,0x00,0x00,0x20,0xFF,0x6B,0x00,0x5A,0xFF,0xA3,0x45,0x67,0xE1,0xFA,0x6B,0x00,
    0x00,0x5C,0xD0,0xF1,0xBB,0x35,0xD0,0x6B,0x00,0x00,0x26,0xB4,0xEE,0xD7,0x75,0x01,
    0x00,0x00,0x27,0xF3,0xA1,0x3D,0x5B,0xEA,0x77,0x00,0x00,0xB5,0xBA,0x00,0x00,0x00,
    0x61,0xEC,0x00,0x04,0xF9,0x62,0x07,0x07,0x07,0x2E,0xFF,0x18,0x23,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0x28,0x0B,0xFE,0x5E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCC,
    0xBD,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x36,0xFA,0xAE,0x44,0x36,0x6D,0x6A,0x00,
    0x00,0x00,0x2D,0xB4,0xEA,0xEA,0xB8,0x43,0x00,0x00,0x00,0x00,0x09,0x18,0x00,0x00,
    0x00,0x79,0xFC,0xFF,0x89,0x00,0x1C,0xFD,0x95,0x13,0x12,0x00,0x45,0xFF,0x36,0x00,
    0x00,0x00,0x4B,0xFF,0x27,0x00,0x00,0x72,0xFA,0xFF,0xFF,0xFF,0x00,0x17,0x6D,0xFF,
    0x50,0x2F,0x00,0x00,0x4B,0xFF,0x27,0x00,0x00,0x00,0x4B,0xFF,0x27,0x00,0x00,0x00,
    0x4B,0xFF,0x27,0x00,0x00,0x00,0x4B,0xFF,0x27,0x00,0x00,0x00,0x4B,0xFF,0x27,0x00,
    0x00,0x00,0x4B,0xFF,0x27,0x00,0x00,0x00,0x4B,0xFF,0x27,0x00,0x00,0x00,0x00,0x66,
    0xD6,0xFC,0xFF,0xFF,0xFF,0xA3,0x00,0x63,0xF9,0x59,0x20,0x83,0xFC,0x43,0x14,0x00,
    0xC3,0xA2,0x00,0x00,0x00,0xDE,0x7A,0x00,0x00,0xC0,0x9E,0x00,0x00,0x00,0xDA,0x73,
    0x00,0x00,0x5E,0xF5,0x44,0x09,0x70,0xF6,0x25,0x00,0x00,0x12,0xE3,0xCD,0xF3,0xC8,
    0x40,0x00,0x00,0x00,0x8C,0xA1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9B,0xDC,0x54,
    0x34,0x33,0x20,0x03,0x00,0x00,0x27,0xFC,0xFF,0xFF,0xFF,0xFF,0xE4,0x39,0x00,0xB3,
    0x85,0x00,0x00,0x04,0x2D,0xD9,0xB1,0x1E,0xFF,0x25,0x00,0x00,0x00,0x00,0xBD,0x9F,
    0x06,0xEB,0xA7,0x22,0x03,0x1D,0x89,0xF0,0x2C,0x00,0x2B,0xAD,0xE8,0xF7,0xDA,0x9B,
    0x23,0x00,0x6E,0xBF,0x00,0x00,0x00,0x00,0x00,0x00,0x87,0xEB,0x00,0x00,0x00,0x00,
    0x00,0x00,0x87,0xEB,0x00,0x00,0x00,0x00,0x00,0x00,0x87,0xEB,0x00,0x00,0x00,0x00,
    0x00,0x00,0x87,0xE5,0x1D,0xA5,0xEA,0xDB,0x53,0x00,0x87,0xF3,0xDD,0x83,0x57,0xC7,
    0xF6,0x14,0x87,0xF7,0x2F,0x00,0x00,0x34,0xFF,0x4D,0x87,0xEB,0x00,0x00,0x00,0x11,
    0xFF,0x65,0x87,0xEB,0x00,0x00,0x00,0x0B,0xFF,0x67,0x87,0xEB,0x00,0x00,0x00,0x0B,
    0xFF,0x67,0x87,0xEB,0x00,0x00,0x00,0x0B,0xFF,0x67,0x87,0xEB,0x00,0x00,0x00,0x0B,
    0xFF,0x67,0x87,0xEB,0x00,0x00,0x00,0x0B,0xFF,0x67,0x75,0xC0,0x09,0x8D,0xDE,0x0F,
    0x00,0x00,0x00,0x00,0x00,0x00,0x87,0xEB,0x00,0x87,0xEB,0x00,0x87,0xEB,0x00,0x87,
    0xEB,0x00,0x87,0xEB,0x00,0x87,0xEB,0x00,0x87,0xEB,0x00,0x87,0xEB,0x00,0x87,0xEB,
    0x00,0x00,0x00,0x72,0xC1,0x0B,0x00,0x00,0x89,0xDF,0x11,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x83,0xEF,0x00,0x00,0x00,0x83,0xEF,0x00,0x00,
    0x00,0x83,0xEF,0x00,0x00,0x00,0x83,0xEF,0x00,0x00,0x00,0x83,0xEF,0x00,0x00,0x00,
    0x83,0xEF,0x00,0x00,0x00,0x83,0xEF,0x00,0x00,0x00,0x83,0xEF,0x00,0x00,0x00,0x83,
    0xEF,0x00,0x00,0x00,0x83,0xEF,0x00,0x00,0x00,0x98,0xE3,0x00,0x23,0x3B,0xDC,0xB2,
    0x00,0x9B,0xFB,0xCB,0x28,0x00,0x06,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x87,0xE7,
    0x00,0x00,0x00,0x00,0x00,0x00,0x87,0xE7,0x00,0x00,0x00,0x00,0x00,0x00,0x87,0xE7,
    0x00,0x00,0x00,0x00,0x00,0x00,0x87,0xE7,0x00,0x00,0x00,0x00,0x00,0x00,0x87,0xE7,
    0x00,0x00,0x02,0xB6,0xD4,0x0C,0x87,0xE7,0x00,0x00,0x81,0xEF,0x24,0x00,0x87,0xE7,
    0x00,0x4B,0xFB,0x49,0x00,0x00,0x87,0xE7,0x23,0xEF,0x92,0x00,0x00,0x00,0x87,0xEE,
    0xD0,0xEC,0xDF,0x09,0x00,0x00,0x87,0xFF,0xCE,0x1B,0xEA,0x85,0x00,0x00,0x87,0xF6,
    0x1D,0x00,0x64,0xF9,0x28,0x00,0x87,0xE7,0x00,0x00,0x02,0xCB,0xBF,0x00,0x87,0xE7,
    0x00,0x00,0x00,0x39,0xFE,0x5C,0x7F,0xDD,0x00,0x87,0xEB,0x00,0x87,0xEB,0x00,0x87,
    0xEB,0x00,0x87,0xEB,0x00,0x87,0xEB,0x00,0x87,0xEB,0x00,0x87,0xEB,0x00,0x87,0xEB,
    0x00,0x87,0xEB,0x00,0x87,0xEB,0x00,0x6C,0xF9,0x2B,0x21,0xE2,0xB8,0x87,0xB5,0x23,
    0xAE,0xF0,0xCF,0x2B,0x08,0x8E,0xE4,0xDE,0x5C,0x00,0x87,0xE5,0xDC,0x7A,0x5E,0xE5,
    0xD0,0xC4,0x97,0x57,0xC0,0xFA,0x1B,0x87,0xF7,0x2C,0x00,0x00,0x6D,0xFF,0x68,0x00,
    0x00,0x29,0xFF,0x58,0x87,0xEB,0x00,0x00,0x00,0x49,0xFF,0x2F,0x00,0x00,0x05,0xFF,
    0x71,0x87,0xEB,0x00,0x00,0x00,0x43,0xFF,0x2F,0x00,0x00,0x00,0xFF,0x73,0x87,0xEB,
    0x00,0x00,0x00,0x43,0xFF,0x2F,0x00,0x00,0x00,0xFF,0x73,0x87,0xEB,0x00,0x00,0x00,
    0x43,0xFF,0x2F,0x00,0x00,0x00,0xFF,0x73,0x87,0xEB,0x00,0x00,0x00,0x43,0xFF,0x2F,
    0x00,0x00,0x00,0xFF,0x73,0x87,0xEB,0x00,0x00,0x00,0x43,0xFF,0x2F,0x00,0x00,0x00,
    0xFF,0x73,0x87,0xB5,0x1E,0xA6,0xEA,0xDB,0x53,0x00,0x87,0xE6,0xDE,0x83,0x57,0xC7,
    0xF6,0x14,0x87,0xF7,0x2F,0x00,0x00,0x34,0xFF,0x4D,0x87,0xEB,0x00,0x00,0x00,0x11,
    0xFF,0x65,0x87,0xEB,0x00,0x00,0x00,0x0B,0xFF,0x67,0x87,0xEB,0x00,0x00,0x00,0x0B,
    0xFF,0x67,0x87,0xEB,0x00,0x00,0x00,0x0B,0xFF,0x67,0x87,0xEB,0x00,0x00,0x00,0x0B,
    0xFF,0x67,0x87,0xEB,0x00,0x00,0x00,0x0B,0xFF,0x67,0x00,0x00,0x29,0xB4,0xEC,0xDD,
    0x91,0x0C,0x00,0x00,0x2E,0xF7,0xB9,0x4E,0x61,0xE4,0xCF,0x05,0x00,0xC1,0xD5,0x03,
    0x00,0x00,0x2A,0xFD,0x70,0x07,0xFC,0x78,0x00,0x00,0x00,0x00,0xC6,0xB1,0x25,0xFF,
    0x5C,0x00,0x00,0x00,0x00,0xA9,0xD4,0x08,0xFC,0x76,0x00,0x00,0x00,0x00,0xC4,0xB3,
    0x00,0xC4,0xD1,0x02,0x00,0x00,0x25,0xFC,0x72,0x00,0x30,0xF8,0xB3,0x49,0x5B,0xE0,
    0xD2,0x06,0x00,0x00,0x2B,0xB6,0xED,0xDF,0x93,0x0D,0x00,0x87,0xB8,0x38,0xB6,0xEF,
    0xCE,0x58,0x00,0x00,0x87,0xF5,0xE5,0x70,0x4D,0xAA,0xFF,0x4C,0x00,0x87,0xF3,0x17,
    0x00,0x00,0x01,0xD3,0xC3,0x00,0x87,0xEB,0x00,0x00,0x00,0x00,0x8B,0xF3,0x00,0x87,
    0xEB,0x00,0x00,0x00,0x00,0x7C,0xFE,0x06,0x87,0xEB,0x00,0x00,0x00,0x00,0x9C,0xE1,
    0x00,0x87,0xEE,0x01,0x00,0x00,0x0E,0xED,0xA1,0x00,0x87,0xFF,0xC3,0x51,0x4F,0xCA,
    0xF3,0x1F,0x00,0x87,0xE7,0x61,0xD4,0xF0,0xB8,0x28,0x00,0x00,0x87,0xEB,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x87,0xEB,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x87,0xEB,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x87,0xEB,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x32,0xBE,0xF1,0xD0,0x55,0xCB,0x6B,0x00,0x31,0xF8,0xC4,0x53,0x5D,0xD0,
    0xFE,0x6B,0x00,0xBD,0xDD,0x07,0x00,0x00,0x0B,0xFF,0x6B,0x04,0xF9,0x7E,0x00,0x00,
    0x00,0x07,0xFF,0x6B,0x1E,0xFF,0x5F,0x00,0x00,0x00,0x07,0xFF,0x6B,0x08,0xFE,0x75,
    0x00,0x00,0x00,0x07,0xFF,0x6B,0x00,0xD5,0xC6,0x00,0x00,0x00,0x20,0xFF,0x6B,0x00,
    0x57,0xFF,0xA3,0x45,0x67,0xE1,0xFE,0x6B,0x00,0x00,0x5B,0xD0,0xF1,0xBC,0x36,0xFC,
    0x6B,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xFF,0x6B,0x00,0x00,0x00,0x00,0x00,0x00,
    0x07,0xFF,0x6B,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0x6B,0x00,0x00,0x00,0x00,
    0x00,0x00,0x07,0xFF,0x6B,0x87,0xB3,0x23,0xB4,0xFB,0x24,0x87,0xD3,0xCF,0x94,0x68,
    0x02,0x87,0xFF,0x64,0x00,0x00,0x00,0x87,0xF1,0x02,0x00,0x00,0x00,0x87,0xEB,0x00,
    0x00,0x00,0x00,0x87,0xEB,0x00,0x00,0x00,0x00,0x87,0xEB,0x00,0x00,0x00,0x00,0x87,
    0xEB,0x00,0x00,0x00,0x00,0x87,0xEB,0x00,0x00,0x00,0x00,0x00,0x22,0xB2,0xEF,0xE1,
    0x9F,0x1E,0x00,0xCF,0xCC,0x48,0x46,0xAB,0x3F,0x06,0xFE,0x6B,0x00,0x00,0x00,0x00,
    0x00,0xB2,0xED,0x74,0x11,0x00,0x00,0x00,0x07,0x6C,0xE3,0xF2,0x88,0x0B,0x00,0x00,
    0x00,0x05,0x60,0xF1,0x9E,0x00,0x05,0x00,0x00,0x00,0x98,0xD9,0x3E,0xE4,0x69,0x30,
    0x56,0xE9,0x99,0x02,0x66,0xC4,0xF1,0xE3,0x92,0x0C,0x00,0x05,0x6B,0x12,0x00,0x00,
    0x00,0x1A,0xFF,0x2B,0x00,0x00,0x00,0x2E,0xFF,0x2B,0x00,0x00,0x89,0xFA,0xFF,0xFF,
    0xFF,0x87,0x1B,0x6A,0xFF,0x53,0x2F,0x19,0x00,0x47,0xFF,0x2B,0x00,0x00,0x00,0x47,
    0xFF,0x2B,0x00,0x00,0x00,0x47,0xFF,0x2B,0x00,0x00,0x00,0x47,0xFF,0x2B,0x00,0x00,
    0x00,0x3C,0xFF,0x43,0x00,0x00,0x00,0x13,0xF8,0xAB,0x38,0x32,0x00,0x00,0x5F,0xE1,
    0xEF,0x8C,0xA3,0xCF,0x00,0x00,0x00,0x33,0xFF,0x3F,0xA3,0xCF,0x00,0x00,0x00,0x33,
    0xFF,0x3F,0xA3,0xCF,0x00,0x00,0x00,0x33,0xFF,0x3F,0xA3,0xCF,0x00,0x00,0x00,0x33,
    0xFF,0x3F,0xA3,0xCF,0x00,0x00,0x00,0x33,0xFF,0x3F,0xA1,0xD3,0x00,0x00,0x00,0x33,
    0xFF,0x3F,0x8C,0xEE,0x04,0x00,0x00,0x7C,0xFF,0x3F,0x4B,0xFF,0x97,0x4F,0x9A,0xC8,
    0xFF,0x3F,0x01,0x87,0xE8,0xDD,0x8B,0x09,0xFE,0x3F,0x9F,0xDF,0x00,0x00,0x00,0x00,
    0x79,0xED,0x05,0x46,0xFF,0x31,0x00,0x00,0x00,0xCB,0x9A,0x00,0x03,0xE9,0x82,0x00,
    0x00,0x1E,0xFF,0x42,0x00,0x00,0x93,0xD4,0x00,0x00,0x6F,0xE8,0x03,0x00,0x00,0x3A,
    0xFF,0x26,0x00,0xC2,0x92,0x00,0x00,0x00,0x01,0xE0,0x76,0x15,0xFD,0x3A,0x00,0x00,
    0x00,0x00,0x87,0xC3,0x5E,0xE2,0x01,0x00,0x00,0x00,0x00,0x2E,0xFD,0xC0,0x8A,0x00,
    0x00,0x00,0x00,0x00,0x00,0xD4,0xFF,0x33,0x00,0x00,0x00,0x72,0xFB,0x0C,0x00,0x00,
    0x65,0xFF,0x48,0x00,0x00,0x1B,0xFF,0x41,0x2D,0xFF,0x46,0x00,0x00,0xA6,0xE8,0x8C,
    0x00,0x00,0x5A,0xF7,0x08,0x00,0xE7,0x86,0x00,0x00,0xE8,0x7A,0xCF,0x00,0x00,0x99,
    0xBD,0x00,0x00,0xA3,0xC5,0x00,0x2A,0xE9,0x1E,0xFE,0x15,0x00,0xD8,0x7B,0x00,0x00,
    0x5E,0xFA,0x0B,0x6C,0xAE,0x00,0xE0,0x56,0x17,0xFF,0x39,0x00,0x00,0x1A,0xFF,0x42,
    0xAC,0x6D,0x00,0x9D,0x98,0x52,0xF2,0x04,0x00,0x00,0x00,0xD4,0x75,0xE7,0x2C,0x00,
    0x5B,0xD3,0x88,0xB4,0x00,0x00,0x00,0x00,0x8F,0xCE,0xEB,0x01,0x00,0x19,0xFD,0xCF,
    0x72,0x00,0x00,0x00,0x00,0x4A,0xFF,0xAB,0x00,0x00,0x00,0xD5,0xFF,0x30,0x00,0x00,
    0x3F,0xFF,0x50,0x00,0x00,0x49,0xFE,0x35,0x00,0xA1,0xDD,0x07,0x02,0xD1,0x9C,0x00,
    0x00,0x15,0xEE,0x7A,0x5B,0xEF,0x15,0x00,0x00,0x00,0x67,0xF5,0xE1,0x6D,0x00,0x00,
    0x00,0x00,0x18,0xFC,0xF7,0x0B,0x00,0x00,0x00,0x00,0xA1,0xBF,0xEA,0x81,0x00,0x00,
    0x00,0x3E,0xFC,0x2C,0x64,0xF9,0x29,0x00,0x05,0xD4,0x9A,0x00,0x02,0xC9,0xC3,0x01,
    0x75,0xF3,0x18,0x00,0x00,0x31,0xFC,0x66,0x9B,0xE2,0x01,0x00,0x00,0x00,0x73,0xEF,
    0x05,0x3A,0xFF,0x3D,0x00,0x00,0x00,0xC2,0xA0,0x00,0x00,0xD8,0x97,0x00,0x00,0x14,
    0xFC,0x4B,0x00,0x00,0x77,0xEC,0x05,0x00,0x60,0xF0,0x06,0x00,0x00,0x19,0xFC,0x4B,
    0x00,0xAE,0xA1,0x00,0x00,0x00,0x00,0xB4,0xA2,0x06,0xF4,0x4C,0x00,0x00,0x00,0x00,
    0x53,0xEF,0x4A,0xF0,0x06,0x00,0x00,0x00,0x00,0x06,0xEB,0xD3,0xA2,0x00,0x00,0x00,
    0x00,0x00,0x00,0x90,0xFF,0x4D,0x00,0x00,0x00,0x00,0x00,0x00,0x6A,0xF1,0x07,0x00,
    0x00,0x00,0x00,0x00,0x03,0xD6,0x96,0x00,0x00,0x00,0x00,0x0E,0x3E,0x98,0xF2,0x1F,
    0x00,0x00,0x00,0x00,0x47,0xF4,0xCE,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0xFF,
    0xFF,0xFF,0xFF,0xF4,0x00,0x00,0x2D,0x2F,0x2F,0x50,0xFC,0x82,0x00,0x00,0x00,0x00,
    0x00,0xBA,0xD5,0x06,0x00,0x00,0x00,0x00,0x61,0xFD,0x38,0x00,0x00,0x00,0x00,0x19,
    0xEF,0x8E,0x00,0x00,0x00,0x00,0x00,0xAE,0xDD,0x0A,0x00,0x00,0x00,0x00,0x55,0xFF,
    0x42,0x00,0x00,0x00,0x00,0x13,0xE9,0xB7,0x2B,0x2B,0x2B,0x2B,0x05,0x70,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0x1F,
};

leRasterFont NotoSansCJKsc_Regular16 =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)NotoSansCJKsc_Regular16_data, // data address pointer
            5109, // data size
        },
        LE_RASTER_FONT,
    },
    19,
    14,
    LE_FONT_BPP_8, // bits per pixel
    NotoSansCJKsc_Regular16_glyphs, // glyph table
};
