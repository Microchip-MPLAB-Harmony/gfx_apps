#include "gfx/legato/string/legato_tablestring.h"

#include "gfx/legato/asset/legato_stringtable.h"
#include "gfx/legato/core/legato_state.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_dynamicstring.h"

static leTableStringVTable tableStringVTable;

static leResult decodeCodePoint(uint32_t encoding,
                                uint8_t* data,
                                uint32_t max,
                                uint32_t* codePoint,
                                uint32_t* offset);

void _leString_Constructor(leString* str);
void _leString_Destructor(leString* str);

void leTableString_Constructor(leTableString* str,
                               uint32_t idx)
{
    str->base.fn = (void*)&tableStringVTable;
    str->fn = (void*)&tableStringVTable;
    
    _leString_Constructor((leString*)str);
    
    str->index = idx;
}

void _leTableString_Destructor(leTableString* str)
{
    str->index = LE_STRING_NULLIDX;
    
    _leString_Destructor((leString*)str);
}

leTableString* leTableString_New(uint32_t idx)
{
    leTableString* str;
    
    str = LE_MALLOC(sizeof(leTableString));
    
    leTableString_Constructor(str, idx);
    
    return str;
}

leFont* _leTableString_GetFont(const leTableString* str)
{
    if(str == NULL)
        return NULL;
        
    return leStringTable_FontIndexLookup(leGetState()->stringTable,
                                         str->index,
                                         leGetState()->languageID);
}

leResult _leTableString_SetFont(leTableString* str,
                                const leFont* font)
{
    return LE_FAILURE;
}

leResult _leTableString_SetFromString(leTableString* str,
                                      const leString* src)
{
    return LE_FAILURE;
}

leResult _leTableString_SetFromChar(leTableString* str,
                                    const leChar* buf,
                                    uint32_t size)
{
    return LE_FAILURE;
}

leResult _leTableString_SetFromCStr(leTableString* str,
                                    const char* cstr)
{
    return LE_FAILURE;
}

uint32_t _leTableString_Length(const leTableString* str)
{
    const leStringTable* tbl = leGetState()->stringTable;
    leStringInfo info;
    
    if(str == NULL || str->index == LE_STRING_NULLIDX)
        return 0;
    
    info.stringIndex = str->index;
    info.languageID = leGetState()->languageID;    
        
    if(leStringTable_StringLookup(tbl, &info) == LE_FAILURE)
        return 0;
        
    return info.size;
}

leBool _leTableString_IsEmpty(const leTableString* str)
{
    if(str == NULL)
        return LE_TRUE;
        
    return _leTableString_Length(str) == 0;
}

leChar _leTableString_CharAt(const leTableString* str,
                             uint32_t idx)
{
    leFont* fnt = NULL;
    uint32_t i, j;
    uint32_t codePoint;
    uint32_t offset = 0;
    const leStringTable* tbl = leGetState()->stringTable;
    uint32_t lang = leGetState()->languageID;
    leStringInfo info;
    
    if(tbl == NULL)
        return 0;
    
    fnt = leStringTable_FontIndexLookup(tbl, str->index, lang);
    
    if(fnt == NULL)
        return 0;
        
    info.stringIndex = str->index;
    info.languageID = lang;
    
    if(leStringTable_StringLookup(tbl, &info) == LE_FAILURE)
        return LE_FAILURE;
    
    j = 0;
    
    for(i = 0; i < info.size;)
    {
        if(decodeCodePoint(tbl->encodingMode,
                           info.address + i,
                           info.size,
                           &codePoint,
                           &offset) == LE_FAILURE)
            return LE_FAILURE;
        
        i += offset;
        
        if(j == idx)
            return codePoint;
        
        j++;
    }
    
    return 0;
}



int32_t _leTableString_Compare(const leTableString* str,
                               const leString* tgt)
{
    uint32_t myLen, len, itr, chr;
    
    if(str == NULL && tgt == NULL)
        return 0;
        
    if((str == NULL && tgt != NULL) ||
       (str != NULL && tgt == NULL))
        return -1;
    
    myLen = str->fn->length(str);
    len = tgt->fn->length(tgt);
    
    if(myLen < len)
    {
        len = myLen;
    }
    
    if(len == 0)
        return 0;
        
    for(itr = 0; itr < len; itr++)
    {
        chr = tgt->fn->charAt(tgt, itr);
        
        if(str->fn->charAt(str, itr) != chr)
        {
            return str->fn->charAt(str, itr) - chr;
        }
    }
    
    return 0;
}

leResult _leTableString_Append(leTableString* str,
                               const leString* val)
{
    return LE_FAILURE;
}

leResult _leTableString_Insert(leTableString* str,
                               const leString* val,
                               uint32_t idx)
{
    return LE_FAILURE;
}

leResult _leTableString_Remove(leTableString* str,
                               uint32_t idx,
                               uint32_t count)
{
    return LE_FAILURE;
}

void _leTableString_Clear(leTableString* str)
{
}

uint32_t _leTableString_ToChar(const leTableString* str, leChar* buf, uint32_t size)
{
    uint32_t myLen, itr;
    
    if(str == NULL ||
       str->index == LE_STRING_NULLIDX ||
       buf == NULL ||
       size == 0)
    {
        return LE_FAILURE;
    }
    
    myLen = str->fn->length(str);
        
    if(size >= myLen)
    {
        size = myLen;
    }
    
    for(itr = 0; itr < size; itr++)
    {
        buf[itr] = str->fn->charAt(str, itr);
    }
    
    return size;
}

leResult _leString_Draw(const leString* str,
                        int32_t x,
                        int32_t y,
                        leHAlignment align,
                        leColor clr,
                        uint32_t a);

leResult _leTableString_Draw(const leTableString* str,
                             int32_t x,
                             int32_t y,
                             leHAlignment align,
                             leColor clr,
                             uint32_t a)
{
    const leStringTable* table = leGetState()->stringTable;
    leFont* font = str->fn->getFont(str);
    leStringInfo info;
    
    if(font == NULL)
        return LE_FAILURE;
        
    info.stringIndex = str->index;
    info.languageID = leGetState()->languageID;
    
    if(leStringTable_StringLookup(table, &info) == LE_FAILURE)
        return LE_FAILURE;

    return _leString_Draw((void*)str,
                          x,
                          y,
                          align,
                          clr,
                          a);
}

uint32_t _leTableString_GetID(const leTableString* str)
{
    if(str == NULL)
        return 0;
        
    return str->index;
}

leResult _leTableString_SetID(leTableString* str, uint32_t id)
{
    if(str == NULL)
        return LE_FAILURE;
        
    str->index = id;
        
    return LE_SUCCESS;
}

uint32_t _leTableString_SizeInBytes(leTableString* str)
{
    const leStringTable* table;
    leStringInfo info;
    
    if(str == NULL)
        return 0;
    
    table = leGetState()->stringTable;
    
    info.stringIndex = str->index;
    info.languageID = leGetState()->languageID;
    
    if(leStringTable_StringLookup(table, &info))
        return 0;
        
    return info.size;
}

void _leString_FillVTable(leStringVTable* vt);

void _leTableString_GenerateVTable()
{
    _leString_FillVTable((void*)&tableStringVTable);
    
    /* base functions */
    tableStringVTable.destructor = _leTableString_Destructor;
    tableStringVTable.getFont = _leTableString_GetFont;
    tableStringVTable.setFont = _leTableString_SetFont;
    tableStringVTable.setFromString = _leTableString_SetFromString;
	tableStringVTable.setFromChar = _leTableString_SetFromChar;
	tableStringVTable.setFromCStr = _leTableString_SetFromCStr;
    tableStringVTable.charAt = _leTableString_CharAt;
    tableStringVTable.length = _leTableString_Length;
    tableStringVTable.isEmpty = _leTableString_IsEmpty;
    tableStringVTable.compare = _leTableString_Compare;
    tableStringVTable.append = _leTableString_Append;
    tableStringVTable.insert = _leTableString_Insert;
    tableStringVTable.remove = _leTableString_Remove;
    tableStringVTable.clear = _leTableString_Clear;
    tableStringVTable._draw = _leTableString_Draw;
    
    /* member functions */
    tableStringVTable.getID = _leTableString_GetID;
    tableStringVTable.setID = _leTableString_SetID;
    tableStringVTable.sizeInBytes = _leTableString_GetID;
}

static leResult decodeASCII(uint8_t* val,
                            uint32_t max,
                            uint32_t* codePoint,
                            uint32_t* size)
{
    *codePoint = val[0];
    *size = 1;
    
    return LE_SUCCESS;
}

static leResult decodeUTF8(uint8_t* val,
                           uint32_t max,
                           uint32_t* codePoint,
                           uint32_t* size)
{
    uint32_t point = 0;
    uint32_t length = 0;
    
    if((val[0] & 0x80) == 0x0)
    {
        length = 1;
        point = val[0] & 0x7F;
    }
    else if((val[0] & 0xE0) == 0xC0)
    {
        length = 2;
        
        if(max < 2)
            return LE_FAILURE;
        
        point |= (val[0] & 0x1F) << 6;
        point |= (val[1] & 0x3F);
    } 
    else if((val[0] & 0xF0) == 0xE0)
    {
        length = 3;
        
        if(max < 3)
            return LE_FAILURE;
        
        point |= (val[0] & 0xF) << 12;
        point |= (val[1] & 0x3F) << 6;
        point |= (val[2] & 0x3F);
    }
    else if((val[0] & 0xF8) == 0xF0)
    {
        length = 4;
        
        if(max < 4)
            return LE_FAILURE;
        
        point |= (val[0] & 0x7) << 18;
        point |= (val[1] & 0x3F) << 12;
        point |= (val[2] & 0x3F) << 6;
        point |= (val[3] & 0x3F);
    }
    else if((val[0] & 0xFC) == 0xF8)
    {   
        length = 5;
        
        if(max < 5)
            return LE_FAILURE;
        
        point |= (val[0] & 0x3) << 24;
        point |= (val[1] & 0x3F) << 18;
        point |= (val[2] & 0x3F) << 12;
        point |= (val[3] & 0x3F) << 6;
        point |= (val[4] & 0x3F);
    }
    else if((val[0] & 0xFE) == 0xFC)
    {
        length = 6;
        
        if(max < 6)
            return LE_FAILURE;
        
        point |= (val[0] & 0x1) << 30;
        point |= (val[1] & 0x3F) << 24;
        point |= (val[2] & 0x3F) << 18;
        point |= (val[3] & 0x3F) << 12;
        point |= (val[4] & 0x3F) << 6;
        point |= (val[5] & 0x3F);
    }
    else
        return LE_FAILURE;
    
    *size = length;
    *codePoint = point;
    
    return LE_SUCCESS;
}

static leResult decodeUTF16(uint8_t* val,
                            uint32_t max,
                            uint32_t* codePoint,
                            uint32_t* size)
{
    uint32_t point = 0;
    uint32_t high, low;
    
    if((val[1] & 0xFC) == 0xDC)
    {
        if(max < 4)
            return LE_FAILURE;
            
        *size = 4;
        
        high = val[0] << 8;
        high |= val[1];
        high -= 0xD800;
        
        low = val[2] << 8;
        low |= val[3];
        low -= 0xDC00;
        
        point = ((high << 10) + low) + 0x10000;
    }
    else
    {
        if(max < 2)
            return LE_FAILURE;
            
        *size = 2;
        
        point += val[0];
        point += (val[1] << 8);
    }
    
    *codePoint = point;
    
    return LE_SUCCESS;
}

typedef leResult (*decodeGlyph_FnPtr)(uint8_t*,
                                      uint32_t,
                                      uint32_t*,
                                      uint32_t*);
                                         
decodeGlyph_FnPtr decodeGlyph[] =
{
    &decodeASCII,
    &decodeUTF8,
    &decodeUTF16
};

static leResult decodeCodePoint(uint32_t encoding,
                                uint8_t* data,
                                uint32_t max,
                                uint32_t* codePoint,
                                uint32_t* offset)
{
    return decodeGlyph[encoding](data, max, codePoint, offset);
}