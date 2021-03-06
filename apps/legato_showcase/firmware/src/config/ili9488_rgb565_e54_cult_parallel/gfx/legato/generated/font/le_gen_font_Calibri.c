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
 * Name:         Calibri
 * Height:       11
 * Baseline:     10
 * Style:        Antialias
 * Glyph Count:  3
 * Range Count:  3
 * Glyph Ranges: 0x2B
                 0x2D
                 0x3A
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
const uint8_t Calibri_glyphs[64] =
{
    0x03,0x00,0x00,0x00,0x2B,0x00,0x09,0x00,0x08,0x00,0x09,0x00,0x00,0x00,0x0A,0x00,
    0x00,0x00,0x09,0x00,0x00,0x00,0x00,0x00,0x2D,0x00,0x05,0x00,0x03,0x00,0x05,0x00,
    0x00,0x00,0x06,0x00,0x00,0x00,0x05,0x00,0x48,0x00,0x00,0x00,0x3A,0x00,0x03,0x00,
    0x09,0x00,0x04,0x00,0x01,0x00,0x09,0x00,0x00,0x00,0x03,0x00,0x57,0x00,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t Calibri_data[114] =
{
    0x00,0x00,0x00,0x04,0xFF,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xFF,0x24,0x00,
    0x00,0x00,0x00,0x04,0x04,0x07,0xFF,0x27,0x04,0x04,0x01,0x34,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0x50,0x09,0x30,0x30,0x33,0xFF,0x4D,0x30,0x30,0x0F,0x00,0x00,0x00,
    0x04,0xFF,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xFF,0x24,0x00,0x00,0x00,0x00,
    0x00,0x00,0x04,0xFF,0x24,0x00,0x00,0x00,0x01,0x04,0x04,0x04,0x02,0x5C,0xFF,0xFF,
    0xFF,0x84,0x11,0x30,0x30,0x30,0x18,0xA0,0xDA,0x0B,0xBA,0xF3,0x10,0x04,0x0D,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x0D,0x00,0xBB,0xF3,0x10,0x9D,
    0xD8,0x0A,
};

leRasterFont Calibri =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)Calibri_data, // data address pointer
            114, // data size
        },
        LE_RASTER_FONT,
    },
    11,
    10,
    LE_FONT_BPP_8, // bits per pixel
    Calibri_glyphs, // glyph table
};
