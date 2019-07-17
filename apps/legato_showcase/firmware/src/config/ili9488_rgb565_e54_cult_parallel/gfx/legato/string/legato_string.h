/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_string.h

  Summary:
    A string library implementation for the Legato user interface library.  

  Description:
    This is a string library implementation that is used internally by the 
    Legato user interface library.  
    
    This implementation relies on the leChar definition for characters.  
    This chararcter definition is 16 bits in size and allows the library to
    support international character code points and Unicode encoding standards.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#ifndef LEGATO_STRING_H
#define LEGATO_STRING_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#include "gfx/legato/font/legato_font.h"
#include "gfx/legato/common/legato_error.h"

//DOM-IGNORE-BEGIN
struct leString;

typedef void (*leString_InvalidateCallback)(const struct leString* str, void* userData);

#define LE_STRING_VTABLE(THIS_TYPE) \
    void        (*destructor)(THIS_TYPE* str); \
	leFont*     (*getFont)(const THIS_TYPE* str); \
	leResult    (*setFont)(THIS_TYPE* str, const leFont* font); \
	leResult    (*setFromString)(THIS_TYPE* str, const struct leString* src); \
	leResult    (*setFromChar)(THIS_TYPE* str, const leChar* buf, uint32_t size); \
	leResult    (*setFromCStr)(THIS_TYPE* str, const char* cstr); \
    leChar      (*charAt)(const THIS_TYPE* str, uint32_t idx); \
    uint32_t    (*length)(const THIS_TYPE* str); \
    leBool      (*isEmpty)(const THIS_TYPE* str); \
    int32_t     (*compare)(const THIS_TYPE* str, const struct leString* tgt); \
    leResult    (*append)(THIS_TYPE* str, const struct leString* val); \
    leResult    (*insert)(THIS_TYPE* str, const struct leString* val, uint32_t idx); \
    leResult    (*remove)(THIS_TYPE* str, uint32_t idx, uint32_t count); \
    void        (*clear)(THIS_TYPE* str); \
    uint32_t    (*toChar)(const THIS_TYPE* str, leChar* buf, uint32_t size); \
    leResult    (*getRect)(const THIS_TYPE* str, leRect* rect); \
    uint32_t    (*getLineCount)(const THIS_TYPE* str); \
    leResult    (*getLineRect)(const THIS_TYPE* str, uint32_t line, leRect* rect); \
    leResult    (*getLineIndices)(const THIS_TYPE* str, uint32_t line, uint32_t* start, uint32_t* end); \
    leResult    (*getCharRect)(const THIS_TYPE* str, uint32_t idx, leRect* rect); \
    leResult    (*getCharIndexAtPoint)(const THIS_TYPE* str, lePoint* pt, uint32_t* idx); \
    leResult    (*_draw)(const THIS_TYPE* str, int32_t x, int32_t y, leHAlignment align, leColor clr, uint32_t a); \
    void        (*preinvalidate)(THIS_TYPE* str); \
    void        (*invalidate)(THIS_TYPE* str); \
    leResult    (*setPreInvalidateCallback)(THIS_TYPE* str, leString_InvalidateCallback, void* userData); \
    leResult    (*setInvalidateCallback)(THIS_TYPE* str, leString_InvalidateCallback, void* userData);

typedef struct leStringVTable
{
	LE_STRING_VTABLE(struct leString)
} leStringVTable;
//DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leString

  Summary:
    String definition

  Remarks:
    None.
*/
typedef struct leString
{
    leStringVTable* fn;

    leString_InvalidateCallback preInvCallback;
    void* preCBUserData;

    leString_InvalidateCallback invCallback;
    void* invCBUserData;
} leString;

// *****************************************************************************
/* Function:
    void leString_Delete(leString* str)

   Summary:
    Frees the memory that was allocated using the la{TYPE}String_New type
    allocator functions

   Parameters:

   Returns:

   Remarks:
    Used in conjunction with the la{TYPE}String_New type allocator functions
*/
LIB_EXPORT void leString_Delete(leString* str);

#if 0
// *****************************************************************************
/* Function:
    void leString_Initialize(leString* str)

   Summary:
    Initializes a string struct to default

   Parameters:
    leString* str - pointer to a string object

  Returns:
    void

  Remarks:
    Allocates no memory
*/
LIB_EXPORT void leString_Initialize(leString* str);

// *****************************************************************************
/* Function:
    leString leString_CreateFromBuffer(const leChar* chr, leFont* fnt)

   Summary:
    Creates a string object from a leChar buffer and a font asset pointer

   Parameters:
    const leChar* chr - pointer to a leChar buffer, can be NULL
    leFont* fnt - pointer to a font asset, can be NULL

  Returns:
    leString - created string object

  Remarks:
    Makes an internal copy of the input buffer for the string object.  Caller
    is responsible for the allocated memory but does not need to preserve the
    input buffer to maintain the string buffer state.
    
    Caller must also ensure that the font contains all the glyphs for the
    string or rendering may not be possible.
*/
LIB_EXPORT leString leString_CreateFromBuffer(const leChar* chr, leFont* fnt);

// *****************************************************************************
/* Function:
    leString leString_CreateFromCharBuffer(const char* chr, leFont* fnt)

   Summary:
    Creates a string object from a const char* buffer and a font asset pointer.
    This method provides compatibility with standard c-style strings.  Input
    string will be converted from 8-bit with to 32-bit width.

   Parameters:
    const char* chr - pointer to a const char* buffer, can be NULL
    leFont* fnt - pointer to a font asset, can be NULL

  Returns:
    leString - created string object

  Remarks:
    Makes an internal copy of the input buffer for the string object.  Caller
    is responsible for the allocated memory but does not need to preserve the
    input buffer to maintain the string buffer state.
    
    Caller must also ensure that the font contains all the glyphs for the
    string or rendering may not be possible.
*/
LIB_EXPORT leString leString_CreateFromCharBuffer(const char* chr, leFont* fnt);



// *****************************************************************************
/* Function:
    void leString_Allocate(leString* str, uint32_t size)

   Summary:
    Attempts to resize the local data buffer for a string.

   Parameters:
    leString* str - the string to modify
    uint32_t size - the desired size of the string

  Returns:
    leResult - LE_SUCCESS if the function succeeded

  Remarks:
    If size is zero then the memory will be freed and the function will return
    success.
*/
LIB_EXPORT leResult leString_Allocate(leString* str, uint32_t size);

// *****************************************************************************
/* Function:
    leResult leString_Set(leString* str, const leChar* buffer)

   Summary:
    Attempts to set the local data buffer of a string to an input buffer

   Parameters:
    leString* str - the string to modify
    const leChar* buffer - the input buffer

  Returns:
    leResult - LE_SUCCESS if the function succeeded

  Remarks:
    Makes an internal copy of the input buffer for the string object.  Caller
    is responsible for the allocated memory but does not need to preserve the
    input buffer to maintain the string buffer state.
        
    Caller must also ensure that the font contains all the glyphs for the
    string or rendering may not be possible.
*/
LIB_EXPORT leResult leString_Set(leString* str, const leChar* buffer);

// *****************************************************************************
/* Function:
    void leString_Destroy(leString* str)

   Summary:
    Destroys a string object.  This frees the strings internal data buffer, if
    it exists, sets its string table reference to null, and clears all supporting
    attributes.

   Parameters:
    leString* str - the string to modify
*/
LIB_EXPORT void leString_Destroy(leString* str);

// *****************************************************************************
/* Function:
    leResult leString_Copy(leString* dst, const leString* src)

   Summary:
    Copies the values from one string into another

   Parameters:
    leString* dst - the destination string object
    leString* src - the source string object

  Returns:
    leResult - LE_SUCCESS if the function succeeded

  Remarks:
    Makes duplicate of a given string.  Destination will have the same length and
    data but may not have the same overall capacity.  The source may have lots of
    unused space and the destination may not match to avoid waste.  Caller
    is responsible for the allocated memory but does not need to preserve the
    input string to maintain the destination string buffer state.
        
    Caller must also ensure that the font contains all the glyphs for the
    string or rendering may not be possible.
*/
LIB_EXPORT leResult leString_Copy(leString* dst, const leString* src);

// *****************************************************************************
/* Function:
    void leString_ExtractFromTable(leString* dst, uint32_t table_index)

   Summary:
    Extracts a read-only string from the string table into a modifiable
    string object.  This relies on the active context to indicate which string
    table to reference as well as which language entry to extract.

   Parameters:
    leString* dst - the destination string object
    uint32_t table_index - the table index to extract

  Returns:
    void

  Remarks:
    Caller is responsible for the allocated memory but does not need to preserve the
    input buffer to maintain the string buffer state.
*/
LIB_EXPORT void leString_ExtractFromTable(leString* dst, uint32_t table_index);

// *****************************************************************************
/* Function:
    leChar leString_CharAt(const leString* str, uint32_t idx)

   Summary:
    Extracts the code point for the character in a string at a given index.

   Parameters:
    const leString* str - the string to reference
    uint32_t idx - the character index to reference

  Returns:
    leChar - the code point of the character
*/
LIB_EXPORT leChar leString_CharAt(const leString* str, uint32_t idx);

// *****************************************************************************
/* Function:
    uint32_t leString_Length(const leString* str)

   Summary:
    Calculates the length of a string in characters

   Parameters:
    const leString* str - the string to reference

  Returns:
    uint32_t - the number of characters in the string
*/
LIB_EXPORT uint32_t leString_Length(const leString* str);

// *****************************************************************************
/* Function:
    void leString_ReduceLength(leString* str, uint32_t length)

   Summary:
    Reduces the length of a string.  This simply slides the null terminator to
    the left and does not affect the string's capacity value.

   Parameters:
    leString* str - the string to modify
    uint32_t length - the new desired length in characters

  Returns:
    void
*/
LIB_EXPORT void leString_ReduceLength(leString* str, uint32_t length);

// *****************************************************************************
/* Function:
    uint32_t leString_Capacity(const leString* str)

   Summary:
    Returns the capacity of a string

   Parameters:
    const leString* str - the string to reference

  Returns:
    uint32_t - the capacity of a string in characters
*/
LIB_EXPORT uint32_t leString_Capacity(const leString* str);

// *****************************************************************************
/* Function:
    void leString_SetCapacity(leString* str, uint32_t cap)

   Summary:
    Attempts to adjust the capacity of a string

   Parameters:
    leString* str - the string to modify
    uint32_t cap - the new desired capacity
    
  Returns:
    leResult - LE_SUCCESS if the operation succeeded
*/
LIB_EXPORT leResult leString_SetCapacity(leString* str, uint32_t cap);

// *****************************************************************************
/* Function:
    int32_t leString_Compare(const leString* lstr, const leString* rstr)

   Summary:
    Compares two string objects

   Parameters:
    const leString* lstr - the left argument
    const leString* rstr - the right argument
    
  Returns:
    int32_t - the result of the string comparison, 0 if the strings are equal
              see strcmp() for more information
*/
LIB_EXPORT int32_t leString_Compare(const leString* lstr, const leString* rstr);

// *****************************************************************************
/* Function:
    int32_t leString_Compare(const leString* lstr, const leChar* buffer)

   Summary:
    Compares a string object and a leChar* buffer

   Parameters:
    const leString* lstr - the string
    const leChar* buffer - the leChar buffer
    
  Returns:
    int32_t - the result of the string comparison, 0 if the strings are equal
              see strcmp() for more information
*/
LIB_EXPORT int32_t leString_CompareBuffer(const leString* str, const leChar* buffer);

// *****************************************************************************
/* Function:
    void leString_Append(leString* dst, const leString* src)

   Summary:
    Appends a string onto the end of another string

   Parameters:
    leString* dst - the destination string
    const leString* src - the source string
    
  Returns:
    leResult - LE_SUCCESS if the operation succeeded
*/
LIB_EXPORT leResult leString_Append(leString* dst, const leString* src);

// *****************************************************************************
/* Function:
    void leString_Insert(leString* dst,const leString* src, uint32_t idx)

   Summary:
    Inserts a string into another string at a given index

   Parameters:
    leString* dst - the destination string
    const leString* src - the source string
    uint32_t idx - the insertion index
    
  Returns:
    leResult - LE_SUCCESS if the operation succeeded
*/
LIB_EXPORT leResult leString_Insert(leString* dst, const leString* src, uint32_t idx);

// *****************************************************************************
/* Function:
    uint32_t leString_Remove(leString* str, uint32_t idx, uint32_t count)

   Summary:
    Removes a number of characters from a string at a given index

   Parameters:
    leString* str - the string to operate on
    uint32_t idx - the index to remove from
    uint32_t idx - the number of characters to remove
    
  Returns:
    uint32_t - the number of characters removed
*/
LIB_EXPORT uint32_t leString_Remove(leString* str, uint32_t idx, uint32_t count);

// *****************************************************************************
/* Function:
    void leString_Clear(leString* str)

   Summary:
    Sets a string's length to zero and its string table reference to NULL.
    Does not free any associated data and preserves capacity.

   Parameters:
    leString* str - the string to modify
    
  Returns:
    void
*/
LIB_EXPORT void leString_Clear(leString* str);
#endif

// *****************************************************************************
/* Function:
    uint32_t leString_ToCharBuffer(const leString* str,
                                   leChar* buffer,
                                   uint32_t size)

   Summary:
    Extracts the data buffer from a string and copies it into the provided
    buffer argument.

   Parameters:
    leString* str - the string to reference
    leChar* buffer - the destination buffer
    uint32_t size - the max size of the destination buffer
    
  Returns:
    uint32_t - the number of characters copied
*/
LIB_EXPORT uint32_t leString_ToCharBuffer(const leString* str,
                                          leChar* buffer,
                                          uint32_t size);

// *****************************************************************************
/* Function:
    void leString_GetRect(leString* str, leRect* rect)

   Summary:
    Calculates the rectangle for a given string object.  References the
    associated font for the height but must perform a summation for each
    character in the string by doing a font meta-data lookup.

   Parameters:
    leString* str - the string to reference
    leRect* rect - the calculated string rectangle result
    
  Returns:
    void
*/
LIB_EXPORT void leString_GetRect(leString* str, leRect* rect);

// *****************************************************************************
/* Function:
    void leString_GetLineRect(leString* str, uint32_t offset, leRect* rect, uint32_t * endoffset)

   Summary:
    Calculates the rectangle for a line in a string object.  References the
    associated font for the height but must perform a summation for each
    character in the string by doing a font meta-data lookup. The line ends
    when a line feed or end of string is reached.

   Parameters:
    leString* str - the string to reference
    uint32_t start - the start offset of the line in the string
    leRect* rect - the calculated string rectangle result
    uint32_t * end - the calculated end of the line (including line feed or end of string)

  Returns:
    void
*/
LIB_EXPORT void leString_GetLineRect(leString* str, uint32_t start, leRect* rect, uint32_t * end);

// *****************************************************************************
/* Function:
    void leString_GetMultiLineRect(leString* str, leRect* rect)

   Summary:
    Calculates the rectangle for a given multi-line string object.  References the
    associated font for the height but must perform a summation for each
    character in the string by doing a font meta-data lookup. The height the sum of
    the heights of the bounding rectangles for each line and the width is the widest
    among the bounding rectangles.

   Parameters:
    leString* str - the string to reference
    leRect* rect - the calculated string rectangle result
    int32_t lineSpace - the space between lines. if -1, will use font ascent

  Returns:
    void
*/
LIB_EXPORT void leString_GetMultiLineRect(leString* str, leRect* rect, int32_t lineSpace);

// *****************************************************************************
/* Function:
    uint32_t leString_GetHeight(leString* str)

   Summary:
    Returns the height of a string by referencing its associated font asset
    data.

   Parameters:
    leString* str - the string to reference
    
  Returns:
    uint32_t - the height of the string
*/
LIB_EXPORT uint32_t leString_GetHeight(leString* str);

// *****************************************************************************
/* Function:
    uint32_t leString_GetAscent(leString* str)

   Summary:
    Returns the ascent of a string by referencing its associated font asset
    data.

   Parameters:
    leString* str - the string to reference
    
  Returns:
    uint32_t - the ascent of the string
*/
LIB_EXPORT uint32_t leString_GetAscent(leString* str);

// *****************************************************************************
/* Function:
    uint32_t leString_GetCharOffset(leString* str, uint32_t idx)

   Summary:
    Returns the offset of a given character index in pixels.

   Parameters:
    leString* str - the string to reference
    uint32_t idx - the character index offset to calculate
    
  Returns:
    uint32_t - the offset in pixels
*/
LIB_EXPORT uint32_t leString_GetCharOffset(leString* str, uint32_t idx);

// *****************************************************************************
/* Function:
    uint32_t leString_GetCharIndexAtPoint(leString* str, int32_t x)

   Summary:
    Given an offset in pixels returns the corresponding character index.

   Parameters:
    leString* str - the string to reference
    int32_t x - x offset in pixels
    
  Returns:
    uint32_t - character index
*/
LIB_EXPORT uint32_t leString_GetCharIndexAtPoint(leString* str, int32_t x);

// *****************************************************************************
/* Function:
    uint32_t leString_GetCharWidth(leString* str, uint32_t idx)

   Summary:
    Given a character index, gets the width of that character.  Only accurate
    if the string has a font associated with it and that font contains all 
    the characters in the string in question.

   Parameters:
    leString* str - the string to reference
    uint32_t x - character index to reference
    
  Returns:
    uint32_t - character width in pixels
*/
LIB_EXPORT uint32_t leString_GetCharWidth(leString* str, uint32_t idx);

// *****************************************************************************
/* Function:
    void leString_Draw(leString* str,
                       int32_t x,
                       int32_t y,
                       leExternalAssetReader** reader)

   Summary:
    Wrapper around GFX Utility string draw function for Legato user interface
    library.  Internal use only.

   Parameters:
    leString* str - the string to draw
    int32_t x - x position to render at
    int32_t y - y position to render at
    
  Returns:
    void
*/
LIB_EXPORT void leString_Draw(leString* str,
                              int32_t x,
                              int32_t y);
                              
// *****************************************************************************
/* Function:
    void leString_DrawClipped(leString* str,
                              int32_t strX,
                              int32_t strY,
                              int32_t strWidth,
                              int32_t strHeight,
                              int32_t x,
                              int32_t y)

   Summary:
    Wrapper around GFX Utility string draw function for Legato user interface
    library.  Draws only a clipped area of a string.  Internal use only.

   Parameters:
    leString* str - the string to draw
    int32_t strX - clipped x position
    int32_t strY - clipped y position
    int32_t strWidth - clipped rectangle width
    int32_t strHeight - clipped rectangle height
    int32_t x - x position to render at
    int32_t y - y position to render at
    
  Returns:
    void
*/
LIB_EXPORT void leString_DrawClipped(leString* str,
                                     int32_t strX,
                                     int32_t strY,
                                     int32_t strWidth,
                                     int32_t strHeight,
                                     int32_t x,
                                     int32_t y);

// *****************************************************************************
/* Function:
    void leString_DrawSubStringClipped(leString* str,
                              int32_t strX,
                              int32_t strY,
                              int32_t strWidth,
                              int32_t strHeight,
                              int32_t x,
                              int32_t y)

   Summary:
    Wrapper around GFX Utility string draw function for Legato user interface
    library.  Draws the substring between the start and end offset, and draws
    only the section of the string within the clipping rectangle.
    Internal use only.

   Parameters:
    leString* str - the string to draw
    uint32_t start - the start position of the substring
    uint32_t end - the end position of the substring
    int32_t strX - clipped x position
    int32_t strY - clipped y position
    int32_t strWidth - clipped rectangle width
    int32_t strHeight - clipped rectangle height
    int32_t x - x position to render at
    int32_t y - y position to render at

  Returns:
    void
*/
LIB_EXPORT void leString_DrawSubStringClipped(leString* str,
                          uint32_t start,
                          uint32_t end,
                          int32_t clipX,
                          int32_t clipY,
                          int32_t clipWidth,
                          int32_t clipHeight,
                          int32_t x,
                          int32_t y);
                              
// *****************************************************************************
/* Function:
    leBool leString_IsEmpty(leString* str)

   Summary:
    Returns a boolean indicating if the provided string contains data or has
    a link to the string table.

   Parameters:
    const leString* str - the string to analyze
    
  Returns:
    leBool - LE_TRUE if the string has data, LE_FALSE if not
*/
LIB_EXPORT leBool leString_IsEmpty(const leString* str);       

#endif // LEGATO_STRING_H


// *****************************************************************************
/* Function:
    leResult copyTo(const leTableString* str, leString* dst)

   Summary:
    Copies the data from this string into another string

   Parameters:
    const leTableString* str - the 'this' pointer of the string
    leString* dst - the destination string

  Returns:
    leResult - LE_SUCCESS if the function succeeded

  Remarks:
    The destination string will determine if and how much data it is able to
    accept from this string
    
    Usage: str->fn->copyTo(str, dst);
*/

// *****************************************************************************
/* Function:
    leChar charAt(const leTableString* str, uint32_t idx)

   Summary:
    Extracts the code point for the character in a string at a given index.

   Parameters:
    const leTableString* str - the 'this' pointer of the string
    uint32_t idx - the character index to reference

  Returns:
    leChar - the code point of the character
    
    Usage: str->fn->charAt(str, idx);
*/

// *****************************************************************************
/* Function:
    uint32_t length(const leTableString* str)

   Summary:
    Calculates the length of a string in characters

   Parameters:
    const leTableString* str - the 'this' pointer of the string

  Returns:
    uint32_t - the number of characters in the string
    
    Usage: str->fn->length(str, idx);
*/

// *****************************************************************************
/* Function:
    int32_t compareToString(const leString* str, const leString* tgt)

   Summary:
    Compares two string objects

   Parameters:
    const leTableString* str - the 'this' pointer of the string
    const leString* tgt - the target string to compare to
    
  Returns:
    int32_t - the result of the string comparison, 0 if the strings are equal
              see strcmp() for more information
              
    Usage: str->fn->compareToString(str, tgt);
*/

// *****************************************************************************
/* Function:
    int32_t compareToBuffer(const leString* str, const leChar* buf)

   Summary:
    Compares two string objects

   Parameters:
    const leTableString* str - the 'this' pointer of the string
    const leChar* buf - the buffer to compare to
    
  Returns:
    int32_t - the result of the string comparison, 0 if the strings are equal
              see strcmp() for more information
              
    Usage: str->fn->compareToBuffer(str, buf);
*/