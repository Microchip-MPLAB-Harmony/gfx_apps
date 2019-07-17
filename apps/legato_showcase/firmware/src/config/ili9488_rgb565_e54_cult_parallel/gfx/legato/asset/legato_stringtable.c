#include "gfx/legato/asset/legato_stringtable.h"

leFont* leStringTable_FontIndexLookup(const leStringTable* table,
                                      uint32_t stringID,
                                      uint32_t languageID)
{
    uint8_t* indexTable;
    uint8_t indexWidth;
    uint32_t fontID;
    
    if(table == NULL || 
       stringID >= table->stringCount || 
       languageID >= table->languageCount)
    {
        return NULL;
    }
    
    indexTable = table->fontIndexTable;
    
    // skip header
    indexTable += 2;
    
    indexWidth = indexTable[0];
       
    indexTable += 1;
    
    // skip to string index
    fontID = indexTable[indexWidth * (languageID + stringID)];

    if(fontID == -1)
        return NULL;
    
    return table->fontTable[fontID];
}

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

leResult leStringTable_StringLookup(const leStringTable* table,
                                    leStringInfo* info)
{
    //uint32_t i;
    //uint32_t stringCount, offset;
    uint8_t* data;
    
    if(table == NULL || info == NULL)
        return LE_FAILURE;
        
    info->tableIndex = stringIndexLookup(table,
                                         info->stringIndex,
                                         info->languageID);
        
    if(info->tableIndex == 0xFFFF)
        return LE_FAILURE;
        
    data = table->header.dataAddress;

    // get string count
    //stringCount = *((uint16_t*)data);

    //data += 2;
    
    // find the string data in the string table
//    for(i = 0; i < stringCount; i++)
//    {
//        if(i == info->tableIndex)
//            break;
//        
//        offset = data[0] + (data[1] << 8);
//        
//        data += LE_STRING_ENTRY_SIZE + offset;
//        
//        /*word = (uint16_t*)address;
//        
//        offset = *word;
//        offset += leSTRING_ENTRY_SIZE;
//    
//        address += offset;*/
//    }
        
    data += /*2 +*/ info->tableIndex;
    
    //word = (uint16_t*)address;
    info->size = *((uint16_t*)data);
    
    data += LE_STRING_ENTRY_SIZE;
    //address += leSTRING_ENTRY_SIZE;
    
    info->address = data;
    
    return LE_SUCCESS;
}