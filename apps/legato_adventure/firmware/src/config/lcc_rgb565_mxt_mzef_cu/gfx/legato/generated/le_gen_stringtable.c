#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   8
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

const uint8_t stringTable_data[292] =
{
    0x08,0x00,0x01,0x00,0x00,0x24,0x00,0x00,0x01,0x3C,0x00,0x00,0x01,0x4C,0x00,0x00,
    0x01,0x76,0x00,0x00,0x01,0x9A,0x00,0x00,0x01,0xD0,0x00,0x00,0x00,0xEC,0x00,0x00,
    0x01,0x02,0x01,0x00,0x15,0x00,0x44,0x65,0x6D,0x6F,0x6E,0x73,0x74,0x72,0x61,0x74,
    0x65,0x64,0x20,0x46,0x65,0x61,0x74,0x75,0x72,0x65,0x73,0x00,0x0D,0x00,0x57,0x51,
    0x56,0x47,0x41,0x20,0x34,0x38,0x30,0x78,0x32,0x37,0x32,0x00,0x28,0x00,0x31,0x36,
    0x2D,0x62,0x69,0x74,0x20,0x52,0x47,0x42,0x35,0x36,0x35,0x20,0x43,0x6F,0x6C,0x6F,
    0x72,0x20,0x44,0x65,0x70,0x74,0x68,0x20,0x28,0x36,0x35,0x35,0x33,0x36,0x20,0x43,
    0x6F,0x6C,0x6F,0x72,0x73,0x29,0x21,0x00,0x4E,0x65,0x78,0x74,0x2D,0x47,0x65,0x6E,
    0x20,0x48,0x69,0x67,0x68,0x20,0x50,0x65,0x72,0x66,0x6F,0x72,0x6D,0x61,0x6E,0x63,
    0x65,0x20,0x4C,0x69,0x62,0x72,0x61,0x72,0x79,0x00,0x34,0x00,0x57,0x69,0x64,0x67,
    0x65,0x74,0x73,0x3A,0x20,0x4C,0x61,0x62,0x65,0x6C,0x2C,0x20,0x42,0x75,0x74,0x74,
    0x6F,0x6E,0x2C,0x20,0x50,0x61,0x6E,0x65,0x6C,0x2C,0x20,0x49,0x6D,0x61,0x67,0x65,
    0x2C,0x20,0x49,0x6D,0x61,0x67,0x65,0x20,0x53,0x65,0x71,0x75,0x65,0x6E,0x63,0x65,
    0x19,0x00,0x50,0x49,0x43,0x33,0x32,0x20,0x4D,0x5A,0x20,0x45,0x46,0x20,0x43,0x75,
    0x72,0x69,0x6F,0x73,0x69,0x74,0x79,0x20,0x32,0x2E,0x30,0x00,0x14,0x00,0x50,0x72,
    0x65,0x73,0x73,0x20,0x48,0x65,0x72,0x65,0x20,0x74,0x6F,0x20,0x52,0x65,0x74,0x75,
    0x72,0x6E,0x20,0x00,0x4C,0x6F,0x77,0x2D,0x43,0x6F,0x73,0x74,0x20,0x43,0x6F,0x6E,
    0x74,0x72,0x6F,0x6C,0x6C,0x65,0x72,0x6C,0x65,0x73,0x73,0x20,0x47,0x72,0x61,0x70,
    0x68,0x69,0x63,0x73,
};

/* font asset pointer list */
leFont* fontList[2] =
{
    (leFont*)&NotoSans_Regular,
    (leFont*)&NotoSans_Regular_Small,
};

const leStringTable stringTable =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        292, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_ASCII // encoding standard
};


// string list
leTableString string_String_Demonstrated;
leTableString string_String_Resolution;
leTableString string_String_ColorDepth;
leTableString string_String_Library;
leTableString string_String_Features;
leTableString string_String_Device;
leTableString string_String_PressHere;
leTableString string_String_GfxController;

void initializeStrings(void)
{
    leTableString_Constructor(&string_String_Demonstrated, stringID_String_Demonstrated);
    leTableString_Constructor(&string_String_Resolution, stringID_String_Resolution);
    leTableString_Constructor(&string_String_ColorDepth, stringID_String_ColorDepth);
    leTableString_Constructor(&string_String_Library, stringID_String_Library);
    leTableString_Constructor(&string_String_Features, stringID_String_Features);
    leTableString_Constructor(&string_String_Device, stringID_String_Device);
    leTableString_Constructor(&string_String_PressHere, stringID_String_PressHere);
    leTableString_Constructor(&string_String_GfxController, stringID_String_GfxController);
}
