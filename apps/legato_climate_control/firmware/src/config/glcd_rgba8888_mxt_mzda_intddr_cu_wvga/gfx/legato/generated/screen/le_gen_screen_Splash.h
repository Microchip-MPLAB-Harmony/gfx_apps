#ifndef LE_GEN_SCREEN_SPLASH_H
#define LE_GEN_SCREEN_SPLASH_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Splash_Layer_0_FillPanel;
extern leImageWidget* Splash_ImageWidget;
extern leImageWidget* Splash_ImageWidget;

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Splash(); // called when Legato is initialized
leResult screenShow_Splash(); // called when screen is shown
void screenHide_Splash(); // called when screen is hidden
void screenDestroy_Splash(); // called when Legato is destroyed
void screenUpdate_Splash(); // called when Legato is updating

leWidget* screenGetRoot_Splash(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Splash_OnShow(); // called when this screen is shown
void Splash_OnHide(); // called when this screen is hidden
void Splash_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SPLASH_H
