#ifndef LEGATO_STRINGTABLE_H
#define LEGATO_STRINGTABLE_H

#include "gfx/legato/common/legato_common.h"
#include "gfx/legato/asset/legato_font.h"

// defines meta data sizes for the string table, don't change!
#define LE_STRING_ARRAY_SIZE      4
#define LE_STRING_ENTRY_SIZE      2
#define LE_STRING_MAX_CHAR_WIDTH  6

// *****************************************************************************
/* Enumeration:
    leStringEncodingMode

  Summary:
    Indicates the string encoding mode type.  Any characters above 255 must use
    UTF8 or UTF16
*/
typedef enum leStringEncodingMode
{
    LE_STRING_ENCODING_ASCII,
    LE_STRING_ENCODING_UTF8,
    LE_STRING_ENCODING_UTF16
} leStringEncodingMode;

// *****************************************************************************
/* Structure:
    leStringTable

  Summary:
    Describes a string table asset.  There is typically only ever one of these
    defined at any one time.
    
    header - standard asset header
    languageCount - the number of languages in the string table
    stringCount - the number of strings in the string table
    stringIndexTable - the pointer to the string index table.  the string index
                       table is a table that contains all of the unique strings
                       defined in the string table.
    fontTable - the font table contains an array of pointers to all defined
                font assets that the string table references
    fontIndexTable - the font index table is a table that maps strings to font
                     indices which can then be used to get an actual font pointer
                     from the font table
    encodingMode - indicates how strings are encoded in the stringIndexTable
*/
typedef struct leStringTable
{
    leAssetHeader header;
    uint32_t languageCount;
    uint32_t stringCount;
    uint8_t* stringIndexTable;
    leFont** fontTable;
    uint8_t* fontIndexTable;
    leStringEncodingMode encodingMode;
} leStringTable;

typedef struct leStringInfo
{
    uint32_t stringIndex;
    uint32_t languageID;
    uint16_t tableIndex;
    uint8_t* address;
    uint32_t size;
} leStringInfo;

LIB_EXPORT leFont* leStringTable_FontIndexLookup(const leStringTable* table,
                                                 uint32_t stringID,
                                                 uint32_t languageID);
                                      
LIB_EXPORT leResult leStringTable_StringLookup(const leStringTable* table,
                                               leStringInfo* info);                                                                             



#endif /* LEGATO_STRINGTABLE_H */