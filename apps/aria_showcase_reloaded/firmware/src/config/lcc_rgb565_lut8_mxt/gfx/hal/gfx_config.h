#ifndef GFX_CONFIG_H
#define GFX_CONFIG_H

#ifndef LIB_EXPORT
#define LIB_EXPORT
#endif

#define GFX_MAX_BUFFER_COUNT    2
#define GFX_DRIVER_COUNT        1
#define GFX_DISPLAY_COUNT       1

/* configuration flags */
#define GFX_DRAW_PIPELINE_ENABLED     1
#define GFX_ALPHA_BLENDING_ENABLED    1
#define GFX_BOUNDS_CLIPPING_ENABLED   1
#define GFX_COLOR_CONVERSION_ENABLED  1
#define GFX_COLOR_MASKING_ENABLED     1
#define GFX_LAYER_CLIPPING_ENABLED    1
#define GFX_ORIENTATION_ENABLED       1

#define GFX_DRAW_ARC_ENABLED           1
#define GFX_DRAW_ELLIPSE_ENABLED       1


#endif /* GFX_CONFIG_H */