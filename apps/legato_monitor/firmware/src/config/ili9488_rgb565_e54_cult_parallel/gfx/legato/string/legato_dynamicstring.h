#ifndef LEGATO_DYNAMICSTRING_H
#define LEGATO_DYNAMICSTRING_H

#include "gfx/legato/string/legato_string.h"

// DOM-IGNORE-BEGIN
struct leDynamicString;

#define LE_DYNAMICSTRING_VTABLE(THIS_TYPE) \
    LE_STRING_VTABLE(THIS_TYPE) \
    \
	uint32_t (*getCapacity)(THIS_TYPE* str); \
	leResult (*setCapacity)(THIS_TYPE* str, uint32_t cap); \

typedef struct leDynamicStringVTable
{
	LE_DYNAMICSTRING_VTABLE(struct leDynamicString)
} leDynamicStringVTable;
// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leDynamicString

  Summary:
    String type that dynamically allocates internal memory to accomodate dynamic
    string operations.

  Remarks:
    None.
*/
typedef struct leDynamicString
{
    leString base;
    
    leDynamicStringVTable* fn;
    
    leChar*     data;     // local string data storage
    
    uint16_t    capacity; // actual memory capacity of the string
    uint16_t    length;   // actual length of the string
                          
    const leFont*  font; // the font used for this string 
} leDynamicString;

// *****************************************************************************
/* Function:
    leDynamicString* leDynamicString_New()

   Summary:
    Allocates a memory for a new dynamic string and automatically calls its
    constructor function

   Parameters:
    

  Returns:
    leDynamicString* - pointer to the newly allocated string

  Remarks:
    Caller is responsible for freeing the memory allocated by this function
    using leDynamicString_Delete()
*/
LIB_EXPORT leDynamicString* leDynamicString_New();

// *****************************************************************************
/* Function:
    void leDynamicString_Constructor(leDynamicString* str)

   Summary:
    Constructs a new dynamic string at the given pointer

   Parameters:
    leDynamicString* str - the string to construct

  Returns:
    
  Remarks:
    It is assumed that the pointer provided is being managed by the caller.  Use
    the destructor member function to clean properly clean this object up.
*/
LIB_EXPORT void leDynamicString_Constructor(leDynamicString* str);

#endif /* LEGATO_DYNAMICSTRING_H */