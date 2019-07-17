/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_imagesequence.h

  Summary:


  Description:
    This module implements image sequence (slide show) widget drawing functions.
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

#ifndef LEGATO_IMAGESEQUENCE_H
#define LEGATO_IMAGESEQUENCE_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_IMAGESEQUENCE_WIDGET_ENABLED

#include "gfx/legato/image/legato_image.h"
#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/string/legato_string.h"

// DOM-IGNORE-BEGIN
#define LE_IMAGESEQ_RESTART -1
// DOM-IGNORE-END

typedef struct leImageSequenceWidget leImageSequenceWidget;

// *****************************************************************************
/* Function Pointer:
    leImageSequenceImageChangedEvent_FnPtr

  Summary:
    Image changed event function callback type
*/
typedef void (*leImageSequenceImageChangedEvent_FnPtr)(leImageSequenceWidget*);

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    leImageSequenceEntry

  Summary:
    Image sequence entry definition

  Description:
    Defines a single entry for the image sequence widget

  Remarks:
    None.
*/
typedef struct leImageSequenceEntry
{
    const leImage* image; // image asset pointer

    uint32_t delay; // how many time units to display this entry

    leHAlignment halign; // the horizontal alignment for this entry
    leVAlignment valign; // the vertical alignment for this entry
} leImageSequenceEntry;

// DOM-IGNORE-BEGIN

#define LE_IMAGESEQUENCEWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    uint32_t      (*getImageCount)(const THIS_TYPE* _this); \
    leResult      (*setImageCount)(THIS_TYPE* _this, uint32_t cnt); \
    leImage*      (*getImage)(const THIS_TYPE* _this, uint32_t idx); \
    leResult      (*setImage)(THIS_TYPE* _this, uint32_t idx, const leImage* img); \
    uint32_t      (*getImageDelay)(const THIS_TYPE* _this, uint32_t idx); \
    leResult      (*setImageDelay)(THIS_TYPE* _this, uint32_t idx, uint32_t dly); \
    leHAlignment  (*getImageHAlignment)(const THIS_TYPE* _this, uint32_t idx); \
    leResult      (*setImageHAlignment)(THIS_TYPE* _this, uint32_t idx, leHAlignment align); \
    leVAlignment  (*getImageVAlignment)(const THIS_TYPE* _this, uint32_t idx); \
    leResult      (*setImageVAlignment)(THIS_TYPE* _this, uint32_t idx, leVAlignment align); \
    leResult      (*stop)(THIS_TYPE* _this); \
    leResult      (*play)(THIS_TYPE* _this); \
    leResult      (*rewind)(THIS_TYPE* _this); \
    leBool        (*isPlaying)(const THIS_TYPE* _this); \
    leBool        (*getRepeat)(const THIS_TYPE* _this); \
    leResult      (*setRepeat)(THIS_TYPE* _this, leBool rpt); \
    leResult      (*showImage)(THIS_TYPE* _this, uint32_t idx); \
    leResult      (*showNextImage)(THIS_TYPE* _this); \
    leResult      (*showPreviousImage)(THIS_TYPE* _this); \
    leImageSequenceImageChangedEvent_FnPtr (*getImageChangedEventCallback)(const THIS_TYPE* _this); \
    leResult      (*setImageChangedEventCallback)(THIS_TYPE* _this, leImageSequenceImageChangedEvent_FnPtr cb); \
    
typedef struct leImageSequenceWidgetVTable
{
	LE_IMAGESEQUENCEWIDGET_VTABLE(leImageSequenceWidget)
} leImageSequenceWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Enumeration:
    leImageSequenceWidget

  Summary:
    Image sequence widget struct definition

  Description:
    An image sequence widget is similar to an image widget with the additional
    capability of showing a sequence of images and automating the transition
    between them.

    This widget is dependent on the time value provided to leUpdate.  If
    leUpdate is not provided with time information this widget will not be
    able to automatically cycle.

  Remarks:
    None.
*/
typedef struct leImageSequenceWidget
{
    leWidget widget; // widget base class
    
    leImageSequenceWidgetVTable* fn;

    uint32_t count; // number of image entries for this widget
    leImageSequenceEntry* images; // image entry array

    int32_t activeIdx; // currently displayed entry

    leBool playing; // indicates that the widget is automatically cycling
    uint32_t time; // current cycle time

    leBool repeat; // indicates that the sequence should repeat when it
                   // reaches the end of the sequence

    leImageSequenceImageChangedEvent_FnPtr cb; // callback when the image changes
} leImageSequenceWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leImageSequenceWidget* leImageSequenceWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Description:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Parameters:
    void

  Returns:
    leImageSequenceWidget*

  Remarks:

*/
LIB_EXPORT leImageSequenceWidget* leImageSequenceWidget_New();

LIB_EXPORT void leImageSequenceWidget_Constructor(leImageSequenceWidget* img);

#if 0
// *****************************************************************************
/* Function:
    uint32_t leImageSequenceWidget_GetImageCount(leImageSequenceWidget* img)

  Summary:
    Gets the number of image entries for this widget.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget

  Returns:
    uint32_t - the number of entries for this sequence widget

  Remarks:

*/
LIB_EXPORT uint32_t leImageSequenceWidget_GetImageCount(leImageSequenceWidget* img);

// *****************************************************************************
/* Function:
    leResult leImageSequenceWidget_SetImageCount(leImageSequenceWidget* img,
                                                 uint32_t count)

  Summary:
    Sets the number of image entries for this widget.  An image entry that is
    null will show nothing.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget
    uint32_t count - the desired number of entries

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leImageSequenceWidget_SetImageCount(leImageSequenceWidget* img,
                                                        uint32_t count);

// *****************************************************************************
/* Function:
    leImage* leImageSequenceWidget_GetImage(leImageSequenceWidget* img,
                                                    uint32_t idx)

  Summary:
    Gets the image asset pointer for an entry.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget
    uint32_t idx - the index

  Returns:
    leImage* - the image asset pointer

  Remarks:

*/
LIB_EXPORT leImage* leImageSequenceWidget_GetImage(leImageSequenceWidget* img,
                                                           uint32_t idx);
// *****************************************************************************
/* Function:
    leResult leImageSequenceWidget_SetImage(leImageSequenceWidget* img,
                                            uint32_t idx,
                                            leImage* imgAst)

  Summary:
    Sets the image asset pointer for an entry.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget
    uint32_t idx - the index
    leImage* imgAst - the image asset pointer

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leImageSequenceWidget_SetImage(leImageSequenceWidget* img,
                                                   uint32_t idx,
                                                   leImage* imgAst);

// *****************************************************************************
/* Function:
    uint32_t leImageSequenceWidget_GetImageDelay(leImageSequenceWidget* img,
                                                        uint32_t idx)

  Summary:
    Gets the image delay for an entry.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget
    uint32_t idx - the index

  Returns:
    uint32_t - the delay value

  Remarks:

*/
LIB_EXPORT uint32_t leImageSequenceWidget_GetImageDelay(leImageSequenceWidget* img,
                                                        uint32_t idx);

// *****************************************************************************
/* Function:
    leResult leImageSequenceWidget_SetImageDelay(leImageSequenceWidget* img,
                                                        uint32_t idx,
                                                        uint32_t delay)

  Summary:
    Sets the image delay for an entry.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget
    uint32_t idx - the index
    uint32_t delay - the delay value

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leImageSequenceWidget_SetImageDelay(leImageSequenceWidget* img,
                                                        uint32_t idx,
                                                        uint32_t delay);

// *****************************************************************************
/* Function:
    leHAlignment leImageSequenceWidget_GetImageHAlignment(leImageSequenceWidget* img,
                                                          uint32_t idx)

  Summary:
    Gets the horizontal alignment for an image entry

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget
    uint32_t idx - the index

  Returns:
    leHAlignment - the halign value

  Remarks:

*/
LIB_EXPORT leHAlignment leImageSequenceWidget_GetImageHAlignment(leImageSequenceWidget* img,
                                                                 uint32_t idx);

// *****************************************************************************
/* Function:
    leResult leImageSequenceWidget_SetImageHAlignment(leImageSequenceWidget* img,
                                                      uint32_t idx,
                                                      leHAlignment align)

  Summary:
    Sets the horizontal alignment for an image entry.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget
    uint32_t idx - the index
    leHAlignment align - the halign value

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leImageSequenceWidget_SetImageHAlignment(leImageSequenceWidget* img,
                                                             uint32_t idx,
                                                             leHAlignment align);

// *****************************************************************************
/* Function:
    leVAlignment leImageSequenceWidget_GetImageVAlignment(leImageSequenceWidget* img,
                                                          uint32_t idx)

  Summary:
    Sets the vertical alignment for an image entry

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget
    uint32_t idx - the index

  Returns:
    leVAlignment - the valign value

  Remarks:

*/
LIB_EXPORT leVAlignment leImageSequenceWidget_GetImageVAlignment(leImageSequenceWidget* img,
                                                                 uint32_t idx);

// *****************************************************************************
/* Function:
    leResult leImageSequenceWidget_SetImageVAlignment(leImageSequenceWidget* img,
                                                             uint32_t idx,
                                                             leVAlignment align)

  Summary:
    Sets the vertical alignment value for an image entry

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget
    uint32_t idx - the index
    leVAlignment align - the vertical alignment setting

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leImageSequenceWidget_SetImageVAlignment(leImageSequenceWidget* img,
                                                             uint32_t idx,
                                                             leVAlignment align);

// *****************************************************************************
/* Function:
    leResult leImageSequenceWidget_Stop(leImageSequenceWidget* img)

  Summary:
    Stops the widget from automatically cycling through the image entries.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leImageSequenceWidget_Stop(leImageSequenceWidget* img);

// *****************************************************************************
/* Function:
    leResult leImageSequenceWidget_Play(leImageSequenceWidget* img)

  Summary:
    Starts the widget automatically cycling through the image entries.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leImageSequenceWidget_Play(leImageSequenceWidget* img);

// *****************************************************************************
/* Function:
    leResult leImageSequenceWidget_Rewind(leImageSequenceWidget* img)

  Summary:
    Resets the current image sequence display index to zero.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leImageSequenceWidget_Rewind(leImageSequenceWidget* img);

// *****************************************************************************
/* Function:
    leBool leImageSequenceWidget_IsPlaying(leImageSequenceWidget* img)

  Summary:
    Indicates if the widget is currently cycling through the image entries.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget

  Returns:
    leBool - indicates if the widget is automatically cycling

  Remarks:

*/
LIB_EXPORT leBool leImageSequenceWidget_IsPlaying(leImageSequenceWidget* img);

// *****************************************************************************
/* Function:
    leBool leImageSequenceWidget_GetRepeat(leImageSequenceWidget* img)

  Summary:
    Indicates if the widget will repeat through the image entries.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget

  Returns:
    leBool - indicates if the widget is automatically repeating

  Remarks:

*/
LIB_EXPORT leBool leImageSequenceWidget_GetRepeat(leImageSequenceWidget* img);

// *****************************************************************************
/* Function:
    leResult leImageSequenceWidget_SetRepeat(leImageSequenceWidget* img,
                                                    leBool repeat)

  Summary:
    Sets the repeat flag for the widget

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget
    leBool repeat - the desired repeat setting

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leImageSequenceWidget_SetRepeat(leImageSequenceWidget* img,
                                                    leBool repeat);

// *****************************************************************************
/* Function:
    leResult leImageSequenceWidget_ShowImage(leImageSequenceWidget* img,
                                             uint32_t idx)

  Summary:
    Sets the active display index to the indicated value.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget
    uint32_t idx - the desired index

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leImageSequenceWidget_ShowImage(leImageSequenceWidget* img,
                                                    uint32_t idx);

// *****************************************************************************
/* Function:
    leResult leImageSequenceWidget_ShowNextImage(leImageSequenceWidget* img)

  Summary:
    Sets the active display index to the next index value.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leImageSequenceWidget_ShowNextImage(leImageSequenceWidget* img);

// *****************************************************************************
/* Function:
    leResult leImageSequenceWidget_ShowPreviousImage(leImageSequenceWidget* img)

  Summary:
    Sets the active display index to the previous index value.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leImageSequenceWidget_ShowPreviousImage(leImageSequenceWidget* img);

// *****************************************************************************
/* Function:
    leImageSequenceImageChangedEvent_FnPtr leImageSequenceWidget_GetImageChangedEventCallback(leImageSequenceWidget* img)

  Summary:
    Gets the image changed event callback pointer.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget

  Returns:
    leImageSequenceImageChangedEvent_FnPtr - a valid callback pointer or NULL

  Remarks:

*/
LIB_EXPORT leImageSequenceImageChangedEvent_FnPtr leImageSequenceWidget_GetImageChangedEventCallback(leImageSequenceWidget* img);

// *****************************************************************************
/* Function:
    leResult leImageSequenceWidget_SetImageChangedEventCallback(leImageSequenceWidget* img,
                                                                leImageSequenceImageChangedEvent_FnPtr cb)

  Summary:
    Sets the image changed event callback pointer.  This callback is called
    whenever the active display index is changed.

  Description:


  Parameters:
    leImageSequenceWidget* img - the widget
    leImageSequenceImageChangedEvent_FnPtr cb - a valid callback pointer or NULL

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leImageSequenceWidget_SetImageChangedEventCallback(leImageSequenceWidget* img,
                                                                       leImageSequenceImageChangedEvent_FnPtr cb);

// DOM-IGNORE-BEGIN
// internal use only
void _leImageSequenceWidget_GetImageRect(leImageSequenceWidget* img,
                                         leRect* imgRect,
                                         leRect* imgSrcRect);
// DOM-IGNORE-END

#endif

#endif // LE_IMAGESEQUENCE_WIDGET_ENABLED
#endif /* LEGATO_IMAGESEQUENCE_H */
