#include "gfx/libaria/inc/libaria_scheme.h"

void laScheme_Initialize(laScheme* scheme, GFX_ColorMode mode)
{
    if(scheme == NULL)
        return;

    scheme->base = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0xC8D0D4);
    scheme->highlight = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0xC8D0D4);
    scheme->highlightLight = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0xFFFFFF);
    scheme->shadow = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0x808080);
    scheme->shadowDark = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0x404040);
    scheme->foreground = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0x000000);
    scheme->foregroundInactive = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0xD6E3F5);
    scheme->foregroundDisabled = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0x808080);
    scheme->background = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0xFFFFFF);
    scheme->backgroundInactive = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0xD6E3F5);
    scheme->backgroundDisabled = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0xC8D0D4);
    scheme->text = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0x000000);
    scheme->textHighlight = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0x0000FF);
    scheme->textHighlightText = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0xFFFFFF);
    scheme->textInactive = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0xD6E3F5);
    scheme->textDisabled = GFX_ColorConvert(GFX_COLOR_MODE_RGB_888, mode, 0x8C9294);
}