#ifndef LE_GEN_SCREEN_INTRO_H
#define LE_GEN_SCREEN_INTRO_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Intro_PanelWidget6;
extern leImageWidget* Intro_ImageWidget5;
extern leImageWidget* Intro_ImageWidget7;

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Intro(); // called when Legato is initialized
leResult screenShow_Intro(); // called when screen is shown
void screenHide_Intro(); // called when screen is hidden
void screenDestroy_Intro(); // called when Legato is destroyed
void screenUpdate_Intro(); // called when Legato is updating

leWidget* screenGetRoot_Intro(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Intro_OnShow(); // called when this screen is shown
void Intro_OnHide(); // called when this screen is hidden
void Intro_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_INTRO_H
