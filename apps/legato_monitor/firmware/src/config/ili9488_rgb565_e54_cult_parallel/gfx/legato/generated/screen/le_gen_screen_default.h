#ifndef LE_GEN_SCREEN_DEFAULT_H
#define LE_GEN_SCREEN_DEFAULT_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leImageWidget* default_BackgroundImage;
extern leLabelWidget* default_PulseLabel;
extern leLabelWidget* default_DiaLabel;
extern leLabelWidget* default_SysLabel;
extern leLabelWidget* default_ClockLabel;
extern leImageWidget* default_HeartImage;
extern leImageWidget* default_ImageWidget6;
extern leButtonWidget* default_ButtonWidget0;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_default_ButtonWidget0_OnPressed(leButtonWidget* btn);
void event_default_ButtonWidget0_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_default(); // called when Legato is initialized
leResult screenShow_default(); // called when screen is shown
void screenHide_default(); // called when screen is hidden
void screenDestroy_default(); // called when Legato is destroyed
void screenUpdate_default(); // called when Legato is updating

leWidget* screenGetRoot_default(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void default_OnShow(); // called when this screen is shown
void default_OnHide(); // called when this screen is hidden
void default_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_DEFAULT_H
