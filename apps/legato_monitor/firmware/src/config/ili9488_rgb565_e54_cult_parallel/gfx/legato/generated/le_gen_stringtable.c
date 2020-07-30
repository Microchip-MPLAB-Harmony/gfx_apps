#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   5
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
    0x05,0x00,0x01,0x00,0x00,0x18,0x00,0x00,0x01,0x24,0x00,0x00,0x00,0x2A,0x00,0x00,
    0x01,0x34,0x00,0x00,0x01,0x42,0x00,0x00,0x0A,0x00,0x30,0x31,0x32,0x33,0x34,0x35,
    0x36,0x37,0x38,0x39,0x03,0x00,0x2D,0x2D,0x2D,0x00,0x08,0x00,0x31,0x32,0x3A,0x30,
    0x30,0x3A,0x30,0x30,0x0B,0x00,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x39,0x38,
    0x20,0x00,0x03,0x00,0x31,0x32,0x33,0x00,
};

/* font asset pointer list */
leFont* fontList[2] =
{
    (leFont*)&NotoSans_Regular,
    (leFont*)&NotoSans_Bold,
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


// string list
leTableString string_ClockNums;
leTableString string_ClearVal;
leTableString string_DefaultTime;
leTableString string_Nums;
leTableString string_Default;

void initializeStrings(void)
{
    leTableString_Constructor(&string_ClockNums, stringID_ClockNums);
    leTableString_Constructor(&string_ClearVal, stringID_ClearVal);
    leTableString_Constructor(&string_DefaultTime, stringID_DefaultTime);
    leTableString_Constructor(&string_Nums, stringID_Nums);
    leTableString_Constructor(&string_Default, stringID_Default);
}
