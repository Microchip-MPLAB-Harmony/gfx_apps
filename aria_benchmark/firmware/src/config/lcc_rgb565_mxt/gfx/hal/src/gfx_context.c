#include "gfx/hal/inc/gfx_context.h"

GFX_Context* _contextActive = NULL;

GFX_Context* GFX_ActiveContext(void)
{
    return _contextActive;
}

void GFX_ContextActiveSet(GFX_Context* const context)
{
    _contextActive = context;
}

void _GFX_DefaultSyncCallback(void)
{ }