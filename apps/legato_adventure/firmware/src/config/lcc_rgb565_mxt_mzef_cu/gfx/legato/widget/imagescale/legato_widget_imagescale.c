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

#include "gfx/legato/widget/imagescale/legato_widget_imagescale.h"

#if LE_IMAGESCALE_WIDGET_ENABLED

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          100

static leImageScaleWidgetVTable imageScaleWidgetVTable;

void _leImageScaleWidget_GetImageRect(const leImageScaleWidget* img,
                                      leRect* imgRect,
                                      leRect* imgSrcRect);

static void invalidateImageRect(const leImageScaleWidget* _this)
{
    leRect imgRect, imgSrcRect;
    
    _leImageScaleWidget_GetImageRect(_this, &imgRect, &imgSrcRect);
    
    _this->fn->_damageArea(_this, &imgRect);
}

void leImageScaleWidget_Constructor(leImageScaleWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&imageScaleWidgetVTable;
    _this->fn = &imageScaleWidgetVTable;
    
    _this->widget.type = LE_WIDGET_IMAGESCALE;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_FILL;
    
    _this->transformX = 0;
    _this->transformY = 0;
    _this->transformWidth = 00;
    _this->transformHeight = 0;
    
    _this->resizeToFit = LE_FALSE;
    _this->preserveAspect = LE_FALSE;
    _this->filter = LE_IMAGEFILTER_NEAREST_NEIGHBOR;
    _this->inputEnabled = LE_FALSE;
    
    _this->image = NULL;
}

void _leWidget_Destructor(leWidget* _this);

void _leImageScaleWidget_Destructor(leImageScaleWidget* _this)
{
    _leWidget_Destructor((leWidget*)_this);
}

leImageScaleWidget* leImageScaleWidget_New()
{
    leImageScaleWidget* img = NULL;

    img = LE_MALLOC(sizeof(leImageScaleWidget));

    if(img == NULL)
        return NULL;
    
    leImageScaleWidget_Constructor(img);

    return img;
}

static leImage* getImage(const leImageScaleWidget* _this)
{
    LE_ASSERT_THIS();

    return (leImage*)_this->image;
}

static leResult setImage(leImageScaleWidget* _this,
                         const leImage* imgAst)
{
    LE_ASSERT_THIS();

    _this->image = imgAst;

    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static int32_t getTransformX(const leImageScaleWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->transformX;
}

static leResult setTransformX(leImageScaleWidget* _this,
                              int32_t x)
{
    LE_ASSERT_THIS();
        
    if(_this->transformX == x)
        return LE_SUCCESS;

    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    _this->transformX = x;

    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    return LE_SUCCESS;
}

static int32_t getTransformY(const leImageScaleWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->transformY;
}

static leResult setTransformY(leImageScaleWidget* _this,
                              int32_t y)
{
    LE_ASSERT_THIS();
        
    if(_this->transformY == y)
        return LE_SUCCESS;

    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    _this->transformY = y;
    
    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    return LE_SUCCESS;
}

static int32_t getTransformWidth(const leImageScaleWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->transformWidth;
}

static leResult setTransformWidth(leImageScaleWidget* _this,
                                  int32_t width)
{
    LE_ASSERT_THIS();
        
    if(_this->transformWidth == width)
        return LE_SUCCESS;

    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    _this->transformWidth = width;
    
    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    return LE_SUCCESS;
}

static int32_t getTransformHeight(const leImageScaleWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->transformHeight;
}

static leResult setTransformHeight(leImageScaleWidget* _this,
                                   int32_t height)
{
    LE_ASSERT_THIS();
        
    if(_this->transformHeight == height)
        return LE_SUCCESS;

    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    _this->transformHeight = height;
    
    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    return LE_SUCCESS;
}

static leResult resetTransform(leImageScaleWidget* _this)
{
    LE_ASSERT_THIS();
        
    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
       
    _this->transformX = 0;
    _this->transformY = 0;
    _this->transformWidth = 0;
    _this->transformHeight = 0;
    
    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    return LE_SUCCESS;
}

static leBool getStretchEnabled(const leImageScaleWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->resizeToFit;
}

static leResult setStretchEnabled(leImageScaleWidget* _this,
                                  leBool stretch)
{
    LE_ASSERT_THIS();
        
    if(_this->resizeToFit == stretch)
        return LE_SUCCESS;
        
    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    _this->resizeToFit = stretch;
    
    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    return LE_SUCCESS;
}

static leBool getPreserveAspectEnabled(const leImageScaleWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->preserveAspect;
}

static leResult setPreserveAspectEnabled(leImageScaleWidget* _this,
                                         leBool preserve)
{
    LE_ASSERT_THIS();
        
    if(_this->preserveAspect == preserve)
        return LE_SUCCESS;
        
    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    _this->preserveAspect = preserve;
    
    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    return LE_SUCCESS;
}

static leImageFilterMode getFilter(const leImageScaleWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->filter;
}

static leResult setFilter(leImageScaleWidget* _this,
                          leImageFilterMode filter)
{
    LE_ASSERT_THIS();
        
    if(_this->filter == filter)
        return LE_SUCCESS;
        
    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    _this->filter = filter;
    
    if(_this->image != NULL)
    {
        invalidateImageRect(_this);
    }
        
    return LE_SUCCESS;
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leImageScaleWidget_Paint(leImageScaleWidget* _this);

void _leImageScaleWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&imageScaleWidgetVTable);
    
    /* overrides from base class */
    imageScaleWidgetVTable._destructor = _leImageScaleWidget_Destructor;
    imageScaleWidgetVTable._paint = _leImageScaleWidget_Paint;
    imageScaleWidgetVTable.invalidateContents = invalidateImageRect;

    /* member functions */
    imageScaleWidgetVTable.getImage = getImage;
    imageScaleWidgetVTable.setImage = setImage;
    imageScaleWidgetVTable.getTransformX = getTransformX;
    imageScaleWidgetVTable.setTransformX = setTransformX;
    imageScaleWidgetVTable.getTransformY = getTransformY;
    imageScaleWidgetVTable.setTransformY = setTransformY;
    imageScaleWidgetVTable.getTransformWidth = getTransformWidth;
    imageScaleWidgetVTable.setTransformWidth = setTransformWidth;
    imageScaleWidgetVTable.getTransformHeight = getTransformHeight;
    imageScaleWidgetVTable.setTransformHeight = setTransformHeight;
    imageScaleWidgetVTable.resetTransform = resetTransform;
    imageScaleWidgetVTable.getStretchEnabled = getStretchEnabled;
    imageScaleWidgetVTable.setStretchEnabled = setStretchEnabled;
    imageScaleWidgetVTable.getPreserveAspectEnabled = getPreserveAspectEnabled;
    imageScaleWidgetVTable.setPreserveAspectEnabled = setPreserveAspectEnabled;
    imageScaleWidgetVTable.getFilter = getFilter;
    imageScaleWidgetVTable.setFilter = setFilter;
}

void _leImageScaleWidget_FillVTable(leImageScaleWidgetVTable* tbl)
{
    *tbl = imageScaleWidgetVTable;
}


#endif // LE_IMAGESCALE_WIDGET_ENABLED