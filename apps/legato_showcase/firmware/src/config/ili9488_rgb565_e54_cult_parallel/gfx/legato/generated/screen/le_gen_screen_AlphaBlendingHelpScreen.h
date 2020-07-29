#ifndef LE_GEN_SCREEN_ALPHABLENDINGHELPSCREEN_H
#define LE_GEN_SCREEN_ALPHABLENDINGHELPSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* AlphaBlendingHelpScreen_PanelWidget7;
extern leButtonWidget* AlphaBlendingHelpScreen_AlphaHelpCloseButton;
extern leImageWidget* AlphaBlendingHelpScreen_ImageWidget23;
extern leLabelWidget* AlphaBlendingHelpScreen_LabelWidget33;
extern leLabelWidget* AlphaBlendingHelpScreen_LabelWidget34;
extern leLabelWidget* AlphaBlendingHelpScreen_LabelWidget35;
extern leLabelWidget* AlphaBlendingHelpScreen_LabelWidget23;
extern leImageWidget* AlphaBlendingHelpScreen_ImageWidget15;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_AlphaBlendingHelpScreen_AlphaHelpCloseButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_AlphaBlendingHelpScreen(); // called when Legato is initialized
leResult screenShow_AlphaBlendingHelpScreen(); // called when screen is shown
void screenHide_AlphaBlendingHelpScreen(); // called when screen is hidden
void screenDestroy_AlphaBlendingHelpScreen(); // called when Legato is destroyed
void screenUpdate_AlphaBlendingHelpScreen(); // called when Legato is updating

leWidget* screenGetRoot_AlphaBlendingHelpScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void AlphaBlendingHelpScreen_OnShow(); // called when this screen is shown
void AlphaBlendingHelpScreen_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_ALPHABLENDINGHELPSCREEN_H
