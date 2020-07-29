#ifndef LE_GEN_SCREEN_SPLASHSCREEN_H
#define LE_GEN_SCREEN_SPLASHSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* SplashScreen_PanelWidget;
extern leImageWidget* SplashScreen_SplashPic32Logo;
extern leImageWidget* SplashScreen_SplashHarmonyLogo;
extern leImageWidget* SplashScreen_SplashBar;
extern leImageWidget* SplashScreen_SplashMicrochipLogo;

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_SplashScreen(); // called when Legato is initialized
leResult screenShow_SplashScreen(); // called when screen is shown
void screenHide_SplashScreen(); // called when screen is hidden
void screenDestroy_SplashScreen(); // called when Legato is destroyed
void screenUpdate_SplashScreen(); // called when Legato is updating

leWidget* screenGetRoot_SplashScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void SplashScreen_OnShow(); // called when this screen is shown
void SplashScreen_OnHide(); // called when this screen is hidden
void SplashScreen_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SPLASHSCREEN_H
