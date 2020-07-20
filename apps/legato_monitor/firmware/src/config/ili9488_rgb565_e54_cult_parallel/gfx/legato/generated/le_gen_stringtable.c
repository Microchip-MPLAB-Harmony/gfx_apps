#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   2
 *****************************************************************************/

/*****************************************************************************
 * string table data
 * 
 * this table contains the raw character data for each string
 * 
 * unsigned short - number of indices in the table
 * unsigned short - number of languages in the table
 * 
 * index array (size = number of indices * number of languages
 * 
 * for each index in the array:
 *   unsigned byte - the font ID for the index
 *   unsigned byte[3] - the offset of the string codepoint data in
 *                      the table
 * 
 * string data is found by jumping to the index offset from the start
 * of the table
 * 
 * string data entry:
 *     unsigned short - length of the string in bytes (encoding dependent)
 *     codepoint data - the string data
 ****************************************************************************/

const uint8_t stringTable_data[72] =
{
    0x02,0x00,0x01,0x00,0x00,0x0C,0x00,0x00,0x00,0x26,0x00,0x00,0x18,0x00,0x4D,0x6F,
    0x64,0x69,0x66,0x79,0x2E,0x20,0x52,0x65,0x67,0x65,0x6E,0x65,0x72,0x61,0x74,0x65,
    0x2E,0x20,0x52,0x75,0x6E,0x00,0x20,0x00,0x4D,0x50,0x4C,0x41,0x42,0x20,0x48,0x61,
    0x72,0x6D,0x6F,0x6E,0x79,0x20,0x47,0x72,0x61,0x70,0x68,0x69,0x63,0x73,0x20,0x43,
    0x6F,0x6D,0x70,0x6F,0x73,0x65,0x72,0x00,
};

/* font asset pointer list */
leFont* fontList[1] =
{
    (leFont*)&NotoSans_Medium,
};

const leStringTable stringTable =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        72, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_ASCII // encoding standard
};
