#ifndef LE_GEN_SCREEN_SPLASHSCREEN_H
#define LE_GEN_SCREEN_SPLASHSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget;
extern leImageWidget* SplashBar;
extern leImageWidget* SplashMicrochipLogo;
extern leImageWidget* SplashPic32Logo;
extern leImageWidget* SplashHarmonyLogo;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_SplashScreen(); // called when Legato is initialized
leResult screenShow_SplashScreen(); // called when screen is shown
void screenHide_SplashScreen(); // called when screen is hidden
void screenDestroy_SplashScreen(); // called when Legato is destroyed
void screenUpdate_SplashScreen(); // called when Legato is updating

leWidget* screenGetRoot_SplashScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void SplashScreen_OnShow(void);
void SplashScreen_OnHide(void);
void SplashScreen_OnUpdate(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SPLASHSCREEN_H
