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

#include "gfx/legato/widget/imagesequence/legato_widget_imagesequence.h"

#if LE_IMAGESEQUENCE_WIDGET_ENABLED

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          100

#define DEFAULT_DELAY           1000

void _leImageSequenceWidget_GetImageRect(leImageSequenceWidget* img,
                                         leRect* imgRect,
                                         leRect* imgSrcRect);

static leImageSequenceWidgetVTable imageSequenceWidgetVTable;

void leImageSequenceWidget_Constructor(leImageSequenceWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&imageSequenceWidgetVTable;
    _this->fn = &imageSequenceWidgetVTable;
    
    _this->widget.type = LE_WIDGET_IMAGESEQUENCE;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_NONE;

    _this->count = 0;
    _this->images = NULL;
    _this->activeIdx = 0;
    
    _this->playing = LE_FALSE;
    _this->time = 0;
    _this->repeat = LE_FALSE;
    
    _this->cb = NULL;
}

void _leWidget_Destructor(leWidget* _this);

static void destructor(leImageSequenceWidget* _this)
{
    if(_this->images != NULL)
    {
        LE_FREE(_this->images);
        _this->images = NULL;
    }
    
    _leWidget_Destructor((leWidget*)_this);
}

static void update(leImageSequenceWidget* _this,
                   uint32_t dt)
{
    // no need to update
    if(_this->playing == LE_FALSE || _this->count <= 1)
        return;
        
    // initial position
    if(_this->activeIdx == LE_IMAGESEQ_RESTART)
    {
        _this->activeIdx = 0;
        _this->time = 0;
        
        _this->fn->invalidate(_this);
        
        //printf("invalidating\n");
    }
    // normal update
    else
    {
        _this->time += dt;
        
        // advance frame?
        if(_this->time >= _this->images[_this->activeIdx].delay)
        {
            _this->activeIdx++;
            _this->time = 0;
            
            // end of sequence?
            if(_this->activeIdx >= (int32_t)_this->count)
            {
                // repeat?
                if(_this->repeat == LE_TRUE)
                {
                    _this->activeIdx = 0;
                    
                    if(_this->cb != NULL)
                        _this->cb(_this);
                    
                    _this->fn->invalidate(_this);
                    
                    //printf("invalidating\n");
                }
                else
                {
                    // just stay on last image, no redraw necessary
                    _this->playing = LE_FALSE;
                }
            }
            else
            {
                if(_this->cb != NULL)
                    _this->cb(_this);
        
                _this->fn->invalidate(_this);
                
                //printf("invalidating\n");
            }
        }
    }
}

leImageSequenceWidget* leImageSequenceWidget_New()
{
    leImageSequenceWidget* img = LE_MALLOC(sizeof(leImageSequenceWidget));
    
    if(img == NULL)
        return NULL;

    leImageSequenceWidget_Constructor(img);

    return img;
}

static uint32_t getImageCount(const leImageSequenceWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->count;
}

static leResult setImageCount(leImageSequenceWidget* _this,
                              uint32_t count)
{
    uint32_t i;
    
    LE_ASSERT_THIS();
        
    if(_this->count == count)
        return LE_SUCCESS;
        
    _this->images = LE_REALLOC(_this->images, sizeof(leImageSequenceEntry) * count);
                      
    if(count > _this->count)
    {
        for(i = _this->count; i < count; i++)
        {
            _this->images[i].image = NULL;
            _this->images[i].halign = LE_HALIGN_CENTER;
            _this->images[i].valign = LE_VALIGN_MIDDLE;
            _this->images[i].delay = DEFAULT_DELAY;
        }
    }
                                                
    _this->count = count;
    _this->activeIdx = 0; // just restart
        
    return LE_SUCCESS;
}

static leImage* getImage(const leImageSequenceWidget* _this,
                         uint32_t idx)
{
    LE_ASSERT_THIS();
    
    if(idx >= _this->count)
        return NULL;
        
    return (leImage*)_this->images[idx].image;
}

static leResult setImage(leImageSequenceWidget* _this,
                         uint32_t idx,
                         const leImage* imgAst)
{
    LE_ASSERT_THIS();
    
    if(idx >= _this->count)
        return LE_FAILURE;
        
    if(_this->images[idx].image == imgAst)
        return LE_SUCCESS;
        
    _this->images[idx].image = imgAst;
        
    if(_this->activeIdx == idx)
    {
        _this->fn->invalidate(_this);
    }
       
    return LE_SUCCESS;
}
                                              
static uint32_t getImageDelay(const leImageSequenceWidget* _this,
                              uint32_t idx)
{
    LE_ASSERT_THIS();
    
    if(idx >= _this->count)
        return 0;
        
    return _this->images[idx].delay;
}

static leResult setImageDelay(leImageSequenceWidget* _this,
                              uint32_t idx,
                              uint32_t delay)
{
    LE_ASSERT_THIS();
    
    if(idx >= _this->count)
        return LE_FAILURE;
        
    _this->images[idx].delay = delay;
        
    return LE_SUCCESS;
}

static leHAlignment getImageHAlignment(const leImageSequenceWidget* _this,
                                       uint32_t idx)
{
    LE_ASSERT_THIS();
  
    if(idx >= _this->count)
        return 0;
        
    return _this->images[idx].halign;
}

static leResult setImageHAlignment(leImageSequenceWidget* _this,
                                   uint32_t idx,
                                   leHAlignment align)
{
    LE_ASSERT_THIS();
    
    if(idx >= _this->count)
        return LE_FAILURE;
        
    if(_this->images[idx].halign == align)
        return LE_SUCCESS;
        
    _this->images[idx].halign = align;
        
    if(_this->activeIdx == idx)
    {
        _this->fn->invalidate(_this);
    }
       
    return LE_SUCCESS;
}

static leVAlignment getImageVAlignment(const leImageSequenceWidget* _this,
                                       uint32_t idx)
{
    LE_ASSERT_THIS();
 
    if(idx >= _this->count)
        return 0;
        
    return _this->images[idx].halign;
}

static leResult setImageVAlignment(leImageSequenceWidget* _this,
                                   uint32_t idx,
                                   leVAlignment align)
{
    LE_ASSERT_THIS();
    
    if(idx >= _this->count)
        return LE_FAILURE;
        
    if(_this->images[idx].valign == align)
        return LE_SUCCESS;
        
    _this->images[idx].valign = align;
        
    if(_this->activeIdx == idx)
        _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leResult stop(leImageSequenceWidget* _this)
{
    LE_ASSERT_THIS();
        
    _this->playing = LE_FALSE;
    
    return LE_SUCCESS;
}

static leResult play(leImageSequenceWidget* _this)
{
    LE_ASSERT_THIS();
        
    _this->playing = LE_TRUE;
    
    return LE_SUCCESS;
}

static leResult rewind(leImageSequenceWidget* _this)
{
    LE_ASSERT_THIS();
        
    _this->activeIdx = LE_IMAGESEQ_RESTART;
    _this->time = 0;
    
    return LE_SUCCESS;
}

static leBool isPlaying(const leImageSequenceWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->playing;
}

static leBool getRepeat(const leImageSequenceWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->repeat;
}

static leResult setRepeat(leImageSequenceWidget* _this,
                          leBool repeat)
{
    LE_ASSERT_THIS();
        
    _this->repeat = repeat;
    
    return LE_SUCCESS;
}

static leResult showImage(leImageSequenceWidget* _this,
                          uint32_t idx)
{
    LE_ASSERT_THIS();
    
    if(idx >= _this->count)
        return LE_FAILURE;
        
    _this->activeIdx = idx;
    _this->time = 0;
    
    if(_this->cb != NULL)
    {
        _this->cb(_this);
    }
    
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static leResult showNextImage(leImageSequenceWidget* _this)
{
    LE_ASSERT_THIS();
        
    if(_this->activeIdx == _this->count - 1)
    {
        if(_this->repeat == LE_TRUE)
        {
            _this->fn->showImage(_this, 0);
        }
    }
    else
    {
        _this->fn->showImage(_this, _this->activeIdx + 1);
    }
    
    return LE_SUCCESS;
}

static leResult showPreviousImage(leImageSequenceWidget* _this)
{
    LE_ASSERT_THIS();
        
    if(_this->activeIdx == 0)
    {
        if(_this->repeat == LE_TRUE)
        {
            _this->fn->showImage(_this, _this->count - 1);
        }
    }
    else
    {
        _this->fn->showImage(_this, _this->activeIdx - 1);
    }
    
    return LE_SUCCESS;
}

static leImageSequenceImageChangedEvent_FnPtr getImageChangedEventCallback(const leImageSequenceWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->cb;
}

static leResult setImageChangedEventCallback(leImageSequenceWidget* _this,
                                             leImageSequenceImageChangedEvent_FnPtr cb)
{
    LE_ASSERT_THIS();
        
    _this->cb = cb;
    
    return LE_SUCCESS;
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leImageSequenceWidget_Paint(leImageSequenceWidget* _this);

void _leImageSequenceWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&imageSequenceWidgetVTable);
    
    /* overrides from base class */
    imageSequenceWidgetVTable._destructor = destructor;
    imageSequenceWidgetVTable.update = update;
    imageSequenceWidgetVTable._paint = _leImageSequenceWidget_Paint;
    
    /* member functions */
    imageSequenceWidgetVTable.getImageCount = getImageCount;
    imageSequenceWidgetVTable.setImageCount = setImageCount;
    imageSequenceWidgetVTable.getImage = getImage;
    imageSequenceWidgetVTable.setImage = setImage;
    imageSequenceWidgetVTable.getImageDelay = getImageDelay;
    imageSequenceWidgetVTable.setImageDelay = setImageDelay;
    imageSequenceWidgetVTable.getImageHAlignment = getImageHAlignment;
    imageSequenceWidgetVTable.setImageHAlignment = setImageHAlignment;
    imageSequenceWidgetVTable.getImageVAlignment = getImageVAlignment;
    imageSequenceWidgetVTable.setImageVAlignment = setImageVAlignment;
    imageSequenceWidgetVTable.stop = stop;
    imageSequenceWidgetVTable.play = play;
    imageSequenceWidgetVTable.rewind = rewind;
    imageSequenceWidgetVTable.isPlaying = isPlaying;
    imageSequenceWidgetVTable.getRepeat = getRepeat;
    imageSequenceWidgetVTable.setRepeat = setRepeat;
    imageSequenceWidgetVTable.showImage = showImage;
    imageSequenceWidgetVTable.showNextImage = showNextImage;
    imageSequenceWidgetVTable.showPreviousImage = showPreviousImage;
    imageSequenceWidgetVTable.getImageChangedEventCallback = getImageChangedEventCallback;
    imageSequenceWidgetVTable.setImageChangedEventCallback = setImageChangedEventCallback;
}

void _leImageSequenceWidget_FillVTable(leImageSequenceWidgetVTable* tbl)
{
    *tbl = imageSequenceWidgetVTable;
}

#endif // LE_IMAGESEQUENCE_WIDGET_ENABLED
