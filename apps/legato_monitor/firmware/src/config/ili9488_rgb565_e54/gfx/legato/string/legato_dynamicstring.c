#include "gfx/legato/string/legato_dynamicstring.h"

#include <string.h>

#include "gfx/legato/memory/legato_memory.h"

static leDynamicStringVTable dynamicStringVTable;

void _leString_Constructor(leString* str);
void _leString_Destructor(leString* str);

void leDynamicString_Constructor(leDynamicString* str)
{
    str->base.fn = (void*)&dynamicStringVTable;
    str->fn = (void*)&dynamicStringVTable;
    
    _leString_Constructor((leString*)str);
    
    str->data = NULL;
    str->capacity = 0;
    str->length = 0;
    str->font = NULL;
}

leDynamicString* leDynamicString_New()
{
    leDynamicString* str;
    
    str = LE_MALLOC(sizeof(leDynamicString));
    
    leDynamicString_Constructor(str);
    
    return str;
}

void _leDynamicString_Destructor(leDynamicString* str)
{
    if(str->data != NULL)
    {
        LE_FREE(str->data);
    }
    
    str->data = NULL;
    str->capacity = 0;
    str->length = 0;
    str->font = NULL;
    
    _leString_Destructor((leString*)str);
}

leFont* _leDynamicString_GetFont(const leDynamicString* str)
{
    if(str == NULL)
        return NULL;
        
    return (leFont*)str->font;
}

leResult _leDynamicString_SetFont(leDynamicString* str,
                                  const leFont* font)
{
    if(str == NULL)
        return LE_FAILURE;
        
    str->font = font;
    
    return LE_SUCCESS;
}

uint32_t _leDynamicString_GetCapacity(leDynamicString* str)
{
    if(str == NULL)
        return 0;
        
    return str->capacity;
}

leResult _leDynamicString_SetCapacity(leDynamicString* str, uint32_t cap)
{
    if(str == NULL)
        return LE_FAILURE;
        
    if(str->capacity == cap)
        return LE_SUCCESS;
    
    if(str->data != NULL && cap == 0)
    {
        LE_FREE(str->data);
        
        str->data = NULL;
        str->capacity = 0;
        str->length = 0;
        
        return LE_SUCCESS;
    }
        
    str->data = LE_REALLOC(str->data, cap * sizeof(leChar));
    
    if(str->data == NULL)
        return LE_FAILURE;
    
    str->capacity = cap;
    
    if(str->length > str->capacity)
    {
        str->length = str->capacity;
    }
    
    return LE_SUCCESS;
}

leResult _leDynamicString_SetFromString(leDynamicString* str,
                                        const leString* src)
{ 
    uint32_t len, itr;
    
    if(str == NULL || src == NULL)
        return LE_FAILURE;
    
    len = src->fn->length(src);
    
    if(str->capacity < len)
    {
        if(str->fn->setCapacity(str, len) == LE_FAILURE)
        {
            return LE_FAILURE;
        }
    }
    
    for(itr = 0; itr < len; itr++)
    {
        str->data[itr] = src->fn->charAt(src, itr);
    }
    
    str->length = len;
    
    return LE_SUCCESS;
}

leResult _leDynamicString_SetFromChar(leDynamicString* str,
                                      const leChar* buf,
                                      uint32_t size)
{
    uint32_t itr;
    
    if(str == NULL || buf == NULL)
        return LE_FAILURE;
       
    if(str->capacity < size)
    {
        if(str->fn->setCapacity(str, size) == LE_FAILURE)
        {
            return LE_FAILURE;
        }
    }
    
    for(itr = 0; itr < size; itr++)
    {
        str->data[itr] = buf[itr];
    }
    
    str->length = size;
    
    return LE_SUCCESS;
}

leResult _leDynamicString_SetFromCStr(leDynamicString* str,
                                      const char* cstr)
{
    uint32_t len, itr;
    
    if(str == NULL || cstr == NULL)
    {
        return LE_FAILURE;
    }
    
    len = strlen(cstr);
    
    if(len == 0)
        return LE_SUCCESS;
        
    if(str->capacity < len)
    {
        if(str->fn->setCapacity(str, len) == LE_FAILURE)
        {
            return LE_FAILURE;
        }
    }
    
    str->length = len;
    
    for(itr = 0; itr < len; itr++)
    {
        str->data[itr] = (leChar)((unsigned char)cstr[itr]);
    }
    
    return LE_SUCCESS;
}

uint32_t _leDynamicString_Length(const leDynamicString* str)
{
    if(str == NULL)
        return 0;
        
    return str->length;
}

leBool _leDynamicString_IsEmpty(const leDynamicString* str)
{
    if(str == NULL)
        return LE_TRUE;
        
    return str->length == 0;
}

leChar _leDynamicString_CharAt(const leDynamicString* str,
                               uint32_t idx)
{
    if(str == NULL || idx >= str->length)
        return 0;
        
    return str->data[idx];
}

int32_t _leDynamicString_Compare(const leDynamicString* str,
                                 const leString* tgt)
{
    uint32_t len, itr, chr;
    
    if(str == NULL && tgt == NULL)
        return 0;
        
    if((str == NULL && tgt != NULL) ||
       (str != NULL && tgt == NULL))
        return -1;
    
    len = tgt->fn->length(tgt);
    
    if(str->length < len)
    {
        len = str->length;
    }
    
    if(len == 0)
        return 0;
        
    for(itr = 0; itr < len; itr++)
    {
        chr = tgt->fn->charAt(tgt, itr);
        
        if(str->data[itr] != chr)
        {
            return str->data[itr] - chr;
        }
    }
    
    return 0;
}

leResult _leDynamicString_Append(leDynamicString* str,
                                 const leString* val)
{
    uint32_t cpyLen, itr;
    
    if(str == NULL || str->data == NULL)
        return LE_FAILURE;
        
    if(val == NULL || val->fn->length(val) == 0)
        return LE_SUCCESS;
        
    cpyLen = val->fn->length(val);
    
    /* resize to fit */
    if(str->length + cpyLen > str->capacity)
    {
        if(str->fn->setCapacity(str, str->length + cpyLen) == LE_FAILURE)
        {
            return LE_FAILURE;
        }
    }
    
    for(itr = 0; itr < cpyLen; itr++)
    {
        str->data[str->length + itr] = val->fn->charAt(val, itr);
    }
        
    return LE_SUCCESS;
}

leResult _leDynamicString_Insert(leDynamicString* str,
                                 const leString* val,
                                 uint32_t idx)
{
    uint32_t cpyLen;
    int32_t itr;
    
    if(str == NULL || str->data == NULL)
        return LE_FAILURE;
        
    if(val == NULL || val->fn->length(val) == 0)
        return LE_SUCCESS;
        
    if(idx >= str->length)
    {
        return _leDynamicString_Append(str, val);
    }
        
    cpyLen = val->fn->length(val);
    
    if(cpyLen == 0)
        return LE_SUCCESS;
    
    /* resize to fit */  
    if(str->length + cpyLen > str->capacity)
    {
        if(str->fn->setCapacity(str, str->length + cpyLen) == LE_FAILURE)
        {
            return LE_FAILURE;
        }
    }
    
    /* shift data right as much as possible to make room for the new values */
    for(itr = (int32_t)str->length - 1; itr >= (int32_t)str->length - 1 - (int32_t)idx; itr--)
    {
        if(itr + cpyLen < str->capacity)
        {
            str->data[itr + cpyLen] = str->data[itr];
        }
    }
    
    /* insert new data */
    for(itr = 0; itr < (int32_t)cpyLen; itr++)
    {
        if(idx + itr >= str->capacity)
            break;
            
        str->data[idx + itr] = val->fn->charAt(val, itr); 
    }
    
    str->length += cpyLen;
    
    if(str->length > str->capacity)
    {
        str->length = str->capacity;
    }
   
    return LE_SUCCESS;
}

leResult _leDynamicString_Remove(leDynamicString* str,
                                 uint32_t idx,
                                 uint32_t count)
{
    uint32_t itr;
    
    if(str == NULL || str->data == NULL || idx >= str->length)
        return LE_FAILURE;
    
    if(count == 0)
        return LE_SUCCESS;
    
    /* simple case, just move length index */
    if(idx + count == str->length - 1)
    {
        str->length = idx;
        
        return LE_SUCCESS;
    }
    
    if(idx + count >= str->length)
    {
        count = str->length - 1 - idx;
    }
    
    /* shift data left */
    for(itr = 0; itr < count; itr++)
    {
        str->data[idx + itr] = str->data[idx + itr + 1];
    }
       
    str->length -= count;
    
    return LE_SUCCESS;
}

void _leDynamicString_Clear(leDynamicString* str)
{
    if(str == NULL)
        return;
        
    str->length = 0;
}

uint32_t _leDynamicString_ToChar(const leDynamicString* str,
                                 leChar* buf,
                                 uint32_t size)
{
    if(str == NULL || str->data == NULL || buf == NULL || size == 0)
        return LE_FAILURE;
        
    if(size >= str->length)
    {
        size = str->length;
    }
    
    memcpy(buf, str->data, size * sizeof(leChar));
    
    return size;
}

void _leString_FillVTable(leStringVTable* vt);

void _leDynamicString_GenerateVTable()
{
    _leString_FillVTable((void*)&dynamicStringVTable);
    
    dynamicStringVTable.destructor = _leDynamicString_Destructor;
    
    dynamicStringVTable.getFont = _leDynamicString_GetFont;
    dynamicStringVTable.setFont = _leDynamicString_SetFont;
    dynamicStringVTable.setFromString = _leDynamicString_SetFromString;
	dynamicStringVTable.setFromChar = _leDynamicString_SetFromChar;
	dynamicStringVTable.setFromCStr = _leDynamicString_SetFromCStr;
    dynamicStringVTable.charAt = _leDynamicString_CharAt;
    dynamicStringVTable.length = _leDynamicString_Length;
    dynamicStringVTable.isEmpty = _leDynamicString_IsEmpty;
    dynamicStringVTable.compare = _leDynamicString_Compare;
    dynamicStringVTable.append = _leDynamicString_Append;
    dynamicStringVTable.insert = _leDynamicString_Insert;
    dynamicStringVTable.remove = _leDynamicString_Remove;
    dynamicStringVTable.clear = _leDynamicString_Clear;
    dynamicStringVTable.toChar = _leDynamicString_ToChar;
    dynamicStringVTable.getCapacity = _leDynamicString_GetCapacity;
    dynamicStringVTable.setCapacity = _leDynamicString_SetCapacity;
}