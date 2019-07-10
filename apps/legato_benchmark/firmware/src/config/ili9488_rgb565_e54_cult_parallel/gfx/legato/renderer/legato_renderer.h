#ifndef LEGATO_RENDERER_H
#define LEGATO_RENDERER_H

#include "gfx/legato/common/legato_common.h"
#include "gfx/legato/common/legato_pixelbuffer.h"
#include "gfx/legato/common/legato_rect.h"
#include "gfx/legato/datastructure/legato_rectarray.h"
#include "gfx/legato/renderer/legato_driver.h"
#include "gfx/legato/widget/legato_widget.h"

// DOM-IGNORE-BEGIN

typedef enum leFrameState
{
    LE_FRAME_READY = 0,
    LE_FRAME_PREFRAME,
    LE_FRAME_PRELAYER,
    LE_FRAME_PRERECT,
    LE_FRAME_PREWIDGET,
    LE_FRAME_DRAWING,
    LE_FRAME_POSTWIDGET,
    LE_FRAME_POSTRECT,
    LE_FRAME_POSTLAYER,
    LE_FRAME_POSTFRAME,
} leFrameState;

typedef struct leRenderState
{
    const leDisplayDriver* dispDriver;
    
    uint32_t layerIdx;
    
    leRect displayRect;
    uint32_t bufferCount;
    
    leRectArray prevDamageRects; // previous damaged rectangle list
    leRectArray currentDamageRects; // queued damaged rectangle list
    leRectArray pendingDamageRects; // pending damaged rectangle list
                                    // these are rectangles added during
                                    // a frame in progress

    leRectArray scratchRectList; // used for rectangle culling phase
    leRectArray frameRectList;   // this of rects to draw for a frame

    uint32_t frameRectIdx;
    leWidget* currentWidget;
    
    leRect drawRect;              // the current damage rectangle clipped
                                  // to the currently rendering widget

    leBool drawingPrev;           // indicates if the layer is currently
                                  // drawing from its previous rectangle
                                  // array

    leFrameState frameState;      // the current frame render state

    uint32_t drawCount;           // the number of times the screen has drawn

    uint32_t frameDrawCount;      // the number of widgets that have rendered
                                  // on the screen

    uint32_t deltaTime;           // stores delta time for updates that happen
                                  // during rendering
                      
    leColorMode colorMode;        // the color mode the library uses
    
#if LE_ALPHA_BLENDING_ENABLED == 1
    leBool alphaEnable;
    uint8_t alpha;
#endif
                                  
    //leBool maskEnable;
    //uint32_t maskValue;
    
    //lePixelBuffer* palette;
    
    lePixelBuffer* renderBuffer;
} leRenderState;

typedef struct leGradient
{
    leColor c0;
    leColor c1;
    leColor c2;
    leColor c3;
} leGradient;

/* internal use only */
leResult leRenderer_Initialize(const leDisplayDriver* dispDriver);

void leRenderer_Shutdown();

leResult leRenderer_DamageArea(const leRect* rect);
							 
void leRenderer_Paint();



LIB_EXPORT leRenderState* leGetRenderState();

leColor leRenderer_ConvertColor(leColor inColor, leColorMode inMode);

leRect leRenderer_GetDisplayRect();

leRect leRenderer_GetDrawRect();
leBool leRenderer_CullDrawRect(const leRect* rect);
leBool leRenderer_CullDrawXY(int32_t x, int32_t y);
leBool leRenderer_CullDrawPoint(const lePoint* pt);
void leRenderer_ClipDrawRect(const leRect* rect, leRect* res);

leColor leRenderer_GetPixel(int32_t x,
                            int32_t y);

leResult leRenderer_GetPixel_Safe(int32_t x,
                                  int32_t y,
                                  leColor* clr);

leResult leRenderer_PutPixel(int32_t x,
                             int32_t y,
                             leColor clr);

leResult leRenderer_BlendPixel(int32_t x,
                               int32_t y,
                               leColor clr,
                               uint32_t a);

leResult leRenderer_PutPixel_Safe(int32_t x,
                                  int32_t y,
                                  leColor clr);

leResult leRenderer_BlendPixel_Safe(int32_t x,
                                    int32_t y,
                                    leColor clr,
                                    uint32_t a);

leResult leRenderer_HorzLine(int32_t x,
                             int32_t y,
                             int32_t w,
                             leColor clr,
                             uint32_t a);

leResult leRenderer_VertLine(int32_t x,
                             int32_t y,
                             int32_t h,
                             leColor clr,
                             uint32_t a); 
                             
leResult leRenderer_DrawLine(int32_t x0,
                             int32_t y0,
                             int32_t x1,
                             int32_t y1,
                             leColor clr,
                             uint32_t a);
                             
leResult leRenderer_RectLine(const leRect* rect,
                             leColor clr,
                             uint32_t a);

leResult leRenderer_RectFill(const leRect* rect,
                             leColor clr,
                             uint32_t a);

leResult leRenderer_HorzGradientRect(const leRect* rect,
                                     leColor clr1,
                                     leColor clr2,
                                     uint32_t a);
                                          
leResult leRenderer_VertGradientRect(const leRect* rect,
                                     leColor clr1,
                                     leColor clr2,
                                     uint32_t a);

leResult leRenderer_CircleDraw(const leRect* rect,
                               int32_t x,
                               int32_t y,
                               uint32_t radius,
                               uint32_t thickness,
                               leColor clr,
                               uint32_t alpha);

leResult leRenderer_CircleDraw(const leRect* rect,
                               int32_t x,
                               int32_t y,
                               uint32_t radius,
                               uint32_t thickness,
                               leColor clr,
                               uint32_t alpha);

leResult leRenderer_CircleFill(const leRect* rect,
                               int32_t x,
                               int32_t y,
                               uint32_t radius,
                               uint32_t thickness,
                               leColor borderClr,
                               leColor fillClr,
                               uint32_t alpha);

leResult leRenderer_ArcLine(int32_t x,
                            int32_t y,
                            int32_t r,
                            int32_t startAngle,
                            int32_t centerAngle,
                            leColor clr,
                            uint32_t a);   
                            
leResult leRenderer_ArcFill(const leRect* drawRect,
                            int32_t x,
                            int32_t y,
                            int32_t r,
                            int32_t startAngle,
                            int32_t centerAngle,
                            uint32_t thickness,
                            leColor clr,
                            leBool antialias,
                            uint32_t a);    
                            
leResult leRenderer_EllipseLine(int32_t x,
                                int32_t y,
                                int32_t a,
                                int32_t b,
                                int32_t theta,
                                int32_t startAngle,
                                int32_t endAngle,
                                leColor clr,
                                uint32_t alpha);                                                                         
                             
// DOM-IGNORE-END

#endif // LEGATO_RENDERER_H