#ifndef LE_GEN_SCREEN_SPLASH_H
#define LE_GEN_SCREEN_SPLASH_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget0;
extern leImageWidget* MHGCImageWidget;
extern leImageWidget* BarImageWidget;
extern leImageWidget* MicrochipLogoImageWidget;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Splash(); // called when Legato is initialized
leResult screenShow_Splash(); // called when screen is shown
void screenHide_Splash(); // called when screen is hidden
void screenDestroy_Splash(); // called when Legato is destroyed
void screenUpdate_Splash(); // called when Legato is updating

leWidget* screenGetRoot_Splash(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void Splash_OnShow(void);
void Splash_OnHide(void);
void Splash_OnUpdate(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SPLASH_H
