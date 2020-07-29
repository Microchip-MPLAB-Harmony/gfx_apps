#ifndef LE_GEN_SCREEN_KEYPADHELPSCREEN_H
#define LE_GEN_SCREEN_KEYPADHELPSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* KeypadHelpScreen_PanelWidget6;
extern leImageWidget* KeypadHelpScreen_ImageWidget20;
extern leButtonWidget* KeypadHelpScreen_KeypadHelpCloseButton;
extern leLabelWidget* KeypadHelpScreen_LabelWidget29;
extern leLabelWidget* KeypadHelpScreen_LabelWidget30;
extern leLabelWidget* KeypadHelpScreen_LabelWidget32;
extern leImageWidget* KeypadHelpScreen_ImageWidget22;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_KeypadHelpScreen_KeypadHelpCloseButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_KeypadHelpScreen(); // called when Legato is initialized
leResult screenShow_KeypadHelpScreen(); // called when screen is shown
void screenHide_KeypadHelpScreen(); // called when screen is hidden
void screenDestroy_KeypadHelpScreen(); // called when Legato is destroyed
void screenUpdate_KeypadHelpScreen(); // called when Legato is updating

leWidget* screenGetRoot_KeypadHelpScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void KeypadHelpScreen_OnShow(); // called when this screen is shown
void KeypadHelpScreen_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_KEYPADHELPSCREEN_H
