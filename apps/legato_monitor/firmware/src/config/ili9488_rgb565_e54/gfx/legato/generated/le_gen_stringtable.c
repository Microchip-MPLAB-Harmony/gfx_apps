#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   11
*****************************************************************************/

/*****************************************************************************
 * string table data
 * 
 * this table contains the raw character data for each string
 * 
 * unsigned short - number of strings in the table
 * for each string:
 *   unsigned short - the length of the string
 *   'length' number of codepoints - the characters of the string (depends on encoding)
 ****************************************************************************/

const uint8_t stringTable_data[83] =
{
    0x0B,0x00,0x0E,0x00,0x4D,0x61,0x72,0x63,0x68,0x20,0x32,0x36,0x2C,0x20,0x32,0x30,
    0x31,0x39,0x03,0x00,0x44,0x49,0x41,0x02,0x00,0x38,0x34,0x05,0x00,0x50,0x55,0x4C,
    0x53,0x45,0x02,0x00,0x37,0x30,0x0A,0x00,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,
    0x38,0x39,0x03,0x00,0x53,0x59,0x53,0x01,0x00,0x38,0x0B,0x00,0x30,0x31,0x32,0x33,
    0x34,0x35,0x36,0x37,0x38,0x39,0x20,0x04,0x00,0x6D,0x6D,0x48,0x67,0x04,0x00,0x2F,
    0x6D,0x69,0x6E,
};

/*****************************************************************************
 * string index table data
 * 
 * this table quickly maps a string ID to an offset into the string
 * data table
 * 
 * unsigned short - number of indices in the table
 * unsigned byte - number of languages in the table
 * unsigned byte - size of each index, either 1 byte or 2
 * array of index sub arrays - each sub array contains an index for each
 *                             defined language
 * array size is: (language count * index size) * index count
 ****************************************************************************/

const uint8_t stringIndexTable_data[15] =
{
    0x0B,0x00,0x01,0x01,0x02,0x12,0x17,0x1B,0x22,0x26,0x32,0x37,0x3A,0x47,0x4D,
};

/* font asset pointer list */
leFont* fontList[6] =
{
    &Arial48,
    &Arial30,
    &Arial14,
    &Calibri98,
    &Calibri,
    &CourierNew,
};
/*****************************************************************************
 * font index table
 * 
 * this table maps a string ID to a font asset
 * 
 * unsigned short - number of indices in the table
 * unsigned byte - size of each index, either 1 byte or 2
 * array of index sub arrays - each sub array contains an index for each
 *                             defined language
 * array size is: (language count * index size) * index count
 ****************************************************************************/

const uint8_t fontIndexTable_data[14] =
{
    0x06,0x00,0x01,0x02,0x00,0x03,0x01,0x04,0x04,0x00,0x05,0x05,0x02,0x02,
};

const leStringTable stringTable =
{
    {
        LE_ASSET_TYPE_STRINGTABLE, // asset type
        LE_ASSET_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        83, // data size
    },
    1,
    11,
    (void*)stringIndexTable_data, // font lookup table
    fontList, // font lookup table
    (void*)fontIndexTable_data, // font index table
    LE_STRING_ENCODING_ASCII // encoding standard
};
