#include "gfx/legato/string/legato_stringtable.h"

#include "gfx/legato/core/legato_state.h"
#include "gfx/legato/string/legato_stringutils.h"

typedef struct leStringTableHeader
{
    uint16_t indexCount;
    uint16_t languageCount;
} leStringTableHeader;

typedef struct leStringTableIndex
{
    uint8_t fontID;
    uint8_t offset[3];
} leStringTableIndex;

typedef struct leStringTableEntry
{
    uint32_t length;
    uint8_t* data;
} leStringTableEntry;

uint32_t leStringTable_GetStringCount(const leStringTable* table)
{
    leStringTableHeader* hdr;

    if(table == NULL)
        return 0;

    hdr = (leStringTableHeader*)table->stringTableData;

    return hdr->indexCount;
}

uint32_t leStringTable_GetLanguageCount(const leStringTable* table)
{
    leStringTableHeader* hdr;

    if(table == NULL)
        return 0;

    hdr = (leStringTableHeader*)table->stringTableData;

    return hdr->languageCount;
}

uint32_t leStringTable_GetStringOffset(const leStringTable* table,
                                       uint32_t stringID,
                                       uint32_t languageID)
{
    leStringTableHeader* hdr;
    leStringTableIndex* idxTable;
    uint32_t offs = 0;

    if(table == NULL)
        return 0;

    hdr = (leStringTableHeader*)table->stringTableData;

    if(stringID >= hdr->indexCount || languageID >= hdr->languageCount)
        return 0;

    idxTable = (leStringTableIndex*)(table->stringTableData + sizeof(leStringTableHeader));

    memcpy(&offs, &idxTable[stringID + languageID].offset, 3);

    return offs;
}

uint32_t leStringTable_GetActiveStringOffset(const leStringTable* table,
                                             uint32_t stringID)
{
    return leStringTable_GetStringOffset(table, stringID, leGetStringLanguage());
}

leFont* leStringTable_GetStringFont(const leStringTable* table,
                                    uint32_t stringID,
                                    uint32_t languageID)
{
    leStringTableHeader* hdr;
    leStringTableIndex* idxTable;

    if(table == NULL)
        return 0;

    hdr = (leStringTableHeader*)table->stringTableData;

    if(stringID >= hdr->indexCount || languageID >= hdr->languageCount)
        return 0;

    idxTable = (leStringTableIndex*)(table->stringTableData + sizeof(leStringTableHeader));

    if(idxTable[stringID + languageID].fontID == 0xFF)
        return NULL;
    
    return table->fontTable[idxTable[stringID + languageID].fontID];
}

#if 0
static uint16_t stringIndexLookup(const leStringTable* table,
                                  uint32_t stringID,
                                  uint32_t languageID)
{
    uint8_t* indexTable = table->stringIndexTable;
    uint16_t* ptr;
    //uint32_t languageCount;
    uint32_t indexWidth;
    uint32_t i;
    
    if(stringID >= table->stringCount || languageID >= table->languageCount)
        return 0;
        
    // skip header
    indexTable += 3;
    
    //languageCount = indexTable[0];
    //indexTable += 1;
    
    indexWidth = indexTable[0];
    indexTable += 1;
    
    // skip to string index
    indexTable += (table->languageCount * indexWidth) * stringID;
    
    if(indexWidth == 1)
    {
        i = indexTable[languageID];
        
        if(i == 0xFF)
        {
            return 0xFFFF;
        }
        else
        {
            return i;
        }
    }
    else
    {
        ptr = (uint16_t*)indexTable;
        
        return ptr[languageID];
    }
}
#endif

leResult leStringTable_StringLookup(const leStringTable* table,
                                    leStringInfo* info)
{
    leStringTableEntry entry;
    entry.length = 0;
    entry.data = NULL;
    
    if(table == NULL || info == NULL)
        return LE_FAILURE;
        
    info->offset = leStringTable_GetStringOffset(table,
                                                 info->stringIndex,
                                                 info->languageID);

    memcpy(&entry.length, (uint8_t*)table->stringTableData + info->offset, 2);
    entry.data = (uint8_t*)table->stringTableData + info->offset + 2;

    info->data = entry.data;
    info->dataSize = entry.length;
    info->length = 0;

    return LE_SUCCESS;
}

leResult leStringTable_GetStringLength(const leStringTable* table,
                                       leStringInfo* info)
{
    uint32_t i;
    uint32_t codePoint;
    uint32_t offset = 0;

    info->length = 0;

    for(i = 0; i < info->dataSize;)
    {
        if(leDecodeCodePoint(table->encodingMode,
                             info->data + i,
                             info->dataSize,
                             &codePoint,
                             &offset) == LE_FAILURE)
            return LE_FAILURE;

        i += offset;

        info->length++;
    }

    return LE_SUCCESS;
}

