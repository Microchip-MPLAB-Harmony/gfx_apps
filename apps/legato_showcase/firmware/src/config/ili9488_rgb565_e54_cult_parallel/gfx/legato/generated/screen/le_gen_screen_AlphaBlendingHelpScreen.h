#ifndef LE_GEN_SCREEN_ALPHABLENDINGHELPSCREEN_H
#define LE_GEN_SCREEN_ALPHABLENDINGHELPSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget7;
extern leButtonWidget* AlphaHelpCloseButton;
extern leImageWidget* ImageWidget23;
extern leLabelWidget* LabelWidget33;
extern leLabelWidget* LabelWidget34;
extern leLabelWidget* LabelWidget35;
extern leLabelWidget* LabelWidget23;
extern leImageWidget* ImageWidget15;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_AlphaBlendingHelpScreen(); // called when Legato is initialized
leResult screenShow_AlphaBlendingHelpScreen(); // called when screen is shown
void screenHide_AlphaBlendingHelpScreen(); // called when screen is hidden
void screenDestroy_AlphaBlendingHelpScreen(); // called when Legato is destroyed
void screenUpdate_AlphaBlendingHelpScreen(); // called when Legato is updating

leWidget* screenGetRoot_AlphaBlendingHelpScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void AlphaBlendingHelpScreen_OnShow(void);

void AlphaBlendingHelpScreen_OnUpdate(void);

void AlphaHelpCloseButton_OnReleased(leButtonWidget* btn)
;


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_ALPHABLENDINGHELPSCREEN_H
