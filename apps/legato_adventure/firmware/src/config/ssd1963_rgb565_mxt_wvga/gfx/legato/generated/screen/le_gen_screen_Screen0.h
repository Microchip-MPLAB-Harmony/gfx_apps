#ifndef LE_GEN_SCREEN_SCREEN0_H
#define LE_GEN_SCREEN_SCREEN0_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Screen0_SplashBackground;
extern leImageWidget* Screen0_SplashPIC32Logo;
extern leImageWidget* Screen0_SplashHarmonyLogo;
extern leImageWidget* Screen0_SplashBar;
extern leImageWidget* Screen0_SplashMicrochipLogo;
extern leImageWidget* Screen0_ImageWidget2;

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Screen0(); // called when Legato is initialized
leResult screenShow_Screen0(); // called when screen is shown
void screenHide_Screen0(); // called when screen is hidden
void screenDestroy_Screen0(); // called when Legato is destroyed
void screenUpdate_Screen0(); // called when Legato is updating

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Screen0_OnShow(); // called when this screen is shown
void Screen0_OnHide(); // called when this screen is hidden
void Screen0_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN0_H
