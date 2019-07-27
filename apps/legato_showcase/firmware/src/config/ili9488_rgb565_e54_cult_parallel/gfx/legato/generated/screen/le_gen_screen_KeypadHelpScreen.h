#ifndef LE_GEN_SCREEN_KEYPADHELPSCREEN_H
#define LE_GEN_SCREEN_KEYPADHELPSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget6;
extern leImageWidget* ImageWidget20;
extern leButtonWidget* KeypadHelpCloseButton;
extern leLabelWidget* LabelWidget29;
extern leLabelWidget* LabelWidget30;
extern leLabelWidget* LabelWidget32;
extern leImageWidget* ImageWidget22;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_KeypadHelpScreen(); // called when Legato is initialized
leResult screenShow_KeypadHelpScreen(); // called when screen is shown
void screenHide_KeypadHelpScreen(); // called when screen is hidden
void screenDestroy_KeypadHelpScreen(); // called when Legato is destroyed
void screenUpdate_KeypadHelpScreen(); // called when Legato is updating

leWidget* screenGetRoot_KeypadHelpScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void KeypadHelpScreen_OnShow(void);

void KeypadHelpScreen_OnUpdate(void);

void KeypadHelpCloseButton_OnReleased(leButtonWidget* btn)
;


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_KEYPADHELPSCREEN_H
