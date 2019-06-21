/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_image.h

  Summary:


  Description:
    This module implements image widget functions.
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

#ifndef LEGATO_IMAGEPLUS_H
#define LEGATO_IMAGEPLUS_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_IMAGEPLUS_WIDGET_ENABLED

#include "gfx/legato/image/legato_image.h"
#include "gfx/legato/widget/legato_widget.h"

typedef struct leImagePlusWidget leImagePlusWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

typedef enum leImagePlusWidget_ResizeFilter
{
    LE_IMAGEFILTER_NEARESTNEIGHBOR = 0x0,
    LE_IMAGEFILTER_BILINEAR
} leImagePlusWidget_ResizeFilter;

// DOM-IGNORE-BEGIN
typedef struct leImagePlusWidget leImagePlusWidget;

#define LE_IMAGEPLUSWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leImage*         (*getImage)(const THIS_TYPE* _this); \
    leResult         (*setImage)(THIS_TYPE* _this, const leImage* img); \
    int32_t          (*getTransformX)(const THIS_TYPE* _this); \
    leResult         (*setTransformX)(THIS_TYPE* _this, int32_t x); \
    int32_t          (*getTransformY)(const THIS_TYPE* _this); \
    leResult         (*setTransformY)(THIS_TYPE* _this, int32_t y); \
    int32_t          (*getTransformWidth)(const THIS_TYPE* _this); \
    leResult         (*setTransformWidth)(THIS_TYPE* _this, int32_t w); \
    int32_t          (*getTransformHeight)(const THIS_TYPE* _this); \
    leResult         (*setTransformHeight)(THIS_TYPE* _this, int32_t h); \
    leResult         (*resetTransform)(THIS_TYPE* _this); \
    leBool           (*getStretchEnabled)(const THIS_TYPE* _this); \
    leResult         (*setStretchEnabled)(THIS_TYPE* _this, leBool b); \
    leBool           (*getPreserveAspectEnabled)(const THIS_TYPE* _this); \
    leResult         (*setPreserveAspectEnabled)(THIS_TYPE* _this, leBool b); \
    leImagePlusWidget_ResizeFilter (*getResizeFilter)(const THIS_TYPE* _this); \
    leResult         (*setResizeFilter)(THIS_TYPE* _this, leImagePlusWidget_ResizeFilter filter); \
    leBool           (*getInteractive)(const THIS_TYPE* _this); \
    leResult         (*setInteractive)(THIS_TYPE* _this, leBool b); \
    
typedef struct leImagePlusWidgetVTable
{
	LE_IMAGEPLUSWIDGET_VTABLE(leImagePlusWidget)
} leImagePlusWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Enumeration:
    leImagePlusWidget

  Summary:
    Image plus widget struct definition

  Description:
    An image plus widget displays an image asset and can translate and resize that image.

  Remarks:
    None.
*/
typedef struct leImagePlusWidget
{
    leWidget widget; // widget base class
    
    leImagePlusWidgetVTable* fn;

    const leImage* image; // pointer to image asset

    int32_t transformX;
    int32_t transformY;
    int32_t transformWidth;
    int32_t transformHeight;

    leBool resizeToFit;
    leBool preserveAspect;

    leImagePlusWidget_ResizeFilter resizeFilter;

    leBool inputEnabled;

    lePoint touch0;
    leBool touch0_down;

    lePoint touch1;
    leBool touch1_down;
} leImagePlusWidget;

// DOM-IGNORE-BEGIN
// internal use only

void _leImagePlusWidget_Destructor(leImagePlusWidget* img);

void _leImagePlusWidget_Paint(leImagePlusWidget* img);
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leImagePlusWidget* leImagePlusWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Description:


  Parameters:
    void

  Returns:
    leImagePlusWidget* - the widget

  Remarks:

*/
LIB_EXPORT leImagePlusWidget* leImagePlusWidget_New();

LIB_EXPORT void leImagePlusWidget_Constructor(leImagePlusWidget* img);

#if 0
// *****************************************************************************
/* Function:
    leImage* leImagePlusWidget_GetImage(leImagePlusWidget* img)

  Summary:
    Gets the image asset pointer for the widget.

  Description:


  Parameters:
    leImagePlusWidget* img - the widget

  Returns:
    leImage* - the image asset pointer

  Remarks:

*/
LIB_EXPORT leImage* leImagePlusWidget_GetImage(leImagePlusWidget* img);

// *****************************************************************************
/* Function:
    leResult leImagePlusWidget_SetImage(leImagePlusWidget* img,
                                        leImage* imgAst)

  Summary:
    Sets the image asset pointer for the widget.

  Description:


  Parameters:
    leImagePlusWidget* img - the widget
    leImage* imgAst - the image asset pointer

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leImagePlusWidget_SetImage(leImagePlusWidget* img,
                                               leImage* imgAst);


/*    Function:
        int32_t leImagePlusWidget_GetTransformX(leImagePlusWidget* img)

    Summary:
        Returns the image transform x coefficient

    Description:
        Returns the image transform x coefficient

    Parameters:
        leImagePlusWidget* img - the widget

    Returns:
        int32_t - the x translation coefficient

*/
LIB_EXPORT int32_t leImagePlusWidget_GetTransformX(leImagePlusWidget* img);

/*    Function:
        leResult leImagePlusWidget_SetTransformX(leImagePlusWidget* img, int32_t x)

    Summary:
        Sets the image transform x coefficient

    Description:
        Sets the image transform x coefficient

    Parameters:
        leImagePlusWidget* img - the widget
        int32_t x - the desired x value

    Returns:
        leResult - result of the operation

*/
LIB_EXPORT leResult leImagePlusWidget_SetTransformX(leImagePlusWidget* img, int32_t x);

/*    Function:
        int32_t leImagePlusWidget_GetTransformY(leImagePlusWidget* img)

    Summary:
        Returns the image transform y coefficient

    Description:
        Returns the image transform y coefficient

    Parameters:
        leImagePlusWidget* img - the widget

    Returns:
        int32_t - the y translation coefficient

*/
LIB_EXPORT int32_t leImagePlusWidget_GetTransformY(leImagePlusWidget* img);

/*    Function:
        leResult leImagePlusWidget_SetTransformY(leImagePlusWidget* img, int32_t y)

    Summary:
        Sets the image transform y coefficient

    Description:
        Sets the image transform y coefficient

    Parameters:
        leImagePlusWidget* img - the widget
        int32_t y - the desired y value

    Returns:
        leResult - result of the operation

*/
LIB_EXPORT leResult leImagePlusWidget_SetTransformY(leImagePlusWidget* img, int32_t y);

/*    Function:
        int32_t leImagePlusWidget_GetTransformWidth(leImagePlusWidget* img)

    Summary:
        Returns the image scale width coefficient

    Description:
        Returns the image scale width coefficient

    Parameters:
        leImagePlusWidget* img - the widget

    Returns:
        int32_t - the scale width coordinate value in pixels

*/
LIB_EXPORT int32_t leImagePlusWidget_GetTransformWidth(leImagePlusWidget* img);

/*    Function:
        leResult leImagePlusWidget_SetTransformWidth(leImagePlusWidget* img,
                                                     int32_t width)

    Summary:
        Sets the image scale width coefficient.  This value is in pixels not
        percentage

    Description:
        Sets the image scale width coefficient.  This value is in pixels not
        percentage

    Parameters:
        leImagePlusWidget* img - the widget
        int32_t width - the desired width value, must be > 0

    Returns:
        leResult - result of the operation

*/
LIB_EXPORT leResult leImagePlusWidget_SetTransformWidth(leImagePlusWidget* img, int32_t width);

/*    Function:
        int32_t leImagePlusWidget_GetTransformHeight(leImagePlusWidget* img)

    Summary:
        Returns the image scale height coefficient

    Description:
        Returns the image scale height coefficient

    Parameters:
        leImagePlusWidget* img - the widget

    Returns:
        int32_t - the scale width coordinate value in pixels

*/
LIB_EXPORT int32_t leImagePlusWidget_GetTransformHeight(leImagePlusWidget* img);

/*    Function:
        leResult leImagePlusWidget_SetTransformHeight(leImagePlusWidget* img,
                                                      int32_t height)

    Summary:
        Sets the image scale height coefficient.  This value is in pixels not
        percentage

    Description:
        Sets the image scale height coefficient.  This value is in pixels not
        percentage

    Parameters:
        leImagePlusWidget* img - the widget
        int32_t height - the desired height value, must be > 0

    Returns:
        leResult - result of the operation

*/
LIB_EXPORT leResult leImagePlusWidget_SetTransformHeight(leImagePlusWidget* img,
                                                         int32_t height);


/*    Function:
        leResult leImagePlusWidget_ResetTransform(leImagePlusWidget* img)

    Summary:
        Resets the image transform values to zero

    Description:
        Resets the image transform values to zero

    Parameters:
        leImagePlusWidget* img - the widget

    Returns:
        leResult - result of the operation

*/
LIB_EXPORT leResult leImagePlusWidget_ResetTransform(leImagePlusWidget* img);

// *****************************************************************************
/* Function:
    leBool leImagePlusWidget_GetStretchEnabled(leImagePlusWidget* img)

  Summary:
    Returns the boolean value of the 'stretch to fit' property

  Description:
    Returns the boolean value of the 'stretch to fit' property.  This flag will
    cause the image to be stretched to fill the space of the container widget.
    Widget margins are still considered.

  Parameters:
    leWidget* wgt - the widget

  Returns:
    leBool - the value of the resize flag

  Remarks:

*/
LIB_EXPORT leBool leImagePlusWidget_GetStretchEnabled(leImagePlusWidget* img);

// *****************************************************************************
/* Function:
    leResult leImagePlusWidget_SetStretchEnabled(leImagePlusWidget* img, leBool enable)

  Summary:
    Sets the boolean value of the stretch property

  Description:
    Sets the boolean value of the stretch property

  Parameters:
    leImagePlusWidget* img - the widget
    leBool - the desired flag value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leImagePlusWidget_SetStretchEnabled(leImagePlusWidget* img,
                                                        leBool enable);


// *****************************************************************************
/* Function:
    leBool leImagePlusWidget_GetPreserveAspectEnabled(leImagePlusWidget* img)

  Summary:
    Returns the boolean value of the 'preserve aspect' property

  Description:
    Returns the boolean value of the 'preserve aspect' property.  If the stretch
    flag is enabled then this flag will cause the resized image to fill as much
    of the container widget as possible while still preserving its original aspect
    ratio.

  Parameters:
    leImagePlusWidget* img - the widget

  Returns:
    leBool - the value of the aspect flag

  Remarks:

*/
LIB_EXPORT leBool leImagePlusWidget_GetPreserveAspectEnabled(leImagePlusWidget* img);

// *****************************************************************************
/* Function:
    leResult leImagePlusWidget_SetStretchEnabled(leImagePlusWidget* img, leBool enable)

  Summary:
    Sets the boolean value of the 'preserve aspect' property

  Description:
    Sets the boolean value of the 'preserve aspect' property

  Parameters:
    leImagePlusWidget* img - the widget
    leBool - the desired flag value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leImagePlusWidget_SetPreserveAspectEnabled(leImagePlusWidget* img,
                                                               leBool enable);


// *****************************************************************************
/* Function:
    leImagePlusWidget_ResizeFilter leImagePlusWidget_GetResizeFilter(leImagePlusWidget* img)

  Summary:
    Returns the resize filter setting for this image widget

  Description:
    Returns the resize filter setting for this image widget.  This flag affects
    the speed and quality of the image resize operation.

  Parameters:
    leImagePlusWidget* img - the widget

  Returns:
    leImagePlusWidget_ResizeFilter - the filter setting

  Remarks:

*/
LIB_EXPORT leImagePlusWidget_ResizeFilter leImagePlusWidget_GetResizeFilter(leImagePlusWidget* img);

// *****************************************************************************
/* Function:
    leResult leImagePlusWidget_SetResizeFilter(leImagePlusWidget* img,
                                               leImagePlusWidget_ResizeFilter filter)

  Summary:
    Sets the resize filter value of the widget

  Description:
    Sets the resize filter value of the widget

  Parameters:
    leImagePlusWidget* img - the widget
    leImagePlusWidget_ResizeFilter filter - the desired filter

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leImagePlusWidget_SetResizeFilter(leImagePlusWidget* img,
                                                      leImagePlusWidget_ResizeFilter filter);


// *****************************************************************************
/* Function:
    leBool leImagePlusWidget_GetInteractive(leImagePlusWidget* img)

  Summary:
    Returns true if the widget is configured to respond to input events

  Description:
    This widget can be configured to respond to input events.  It can react to
    single and double touch events.  These events will directly modify the
    transform state and cause the image to translate and resize as desired.

  Parameters:
    leImagePlusWidget* img - the widget

  Returns:
    leBool - the value of the interactive flag

  Remarks:

*/
LIB_EXPORT leBool leImagePlusWidget_GetInteractive(leImagePlusWidget* img);

// *****************************************************************************
/* Function:
    leResult leImagePlusWidget_SetInteractive(leImagePlusWidget* img, leBool interactive)

  Summary:
    Sets the widget interactive flag

  Description:
    Sets the widget interactive flag

  Parameters:
    leImagePlusWidget* img - the widget
    leBool - the desired flag value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leImagePlusWidget_SetInteractive(leImagePlusWidget* img,
                                                     leBool interactive);

// DOM-IGNORE-BEGIN
// internal use only
void _leImagePlusWidget_GetImageRect(leImagePlusWidget* img,
                                     leRect* imgRect,
                                     leRect* imgSrcRect);
// DOM-IGNORE-END

#endif

#endif // LE_IMAGE_WIDGET_ENABLED
#endif /* LEGATO_IMAGE_H */