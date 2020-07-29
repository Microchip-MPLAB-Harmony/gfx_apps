#ifndef LE_GEN_SCREEN_KEYPADDEMOSCREEN_H
#define LE_GEN_SCREEN_KEYPADDEMOSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leGradientWidget* KeypadDemoScreen_BackgroundGradient2;
extern leKeyPadWidget* KeypadDemoScreen_KeyPadWidget1;
extern leTextFieldWidget* KeypadDemoScreen_TextFieldWidget1;
extern leButtonWidget* KeypadDemoScreen_KeypadHelpButton;
extern leButtonWidget* KeypadDemoScreen_KeypadHomeButton;
extern leLabelWidget* KeypadDemoScreen_LabelWidget8;
extern leButtonWidget* KeypadDemoScreen_KeypadNextButton;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_KeypadDemoScreen_TextFieldWidget1_OnFocusChanged(leTextFieldWidget* btn, leBool state);
void event_KeypadDemoScreen_KeypadHelpButton_OnReleased(leButtonWidget* btn);
void event_KeypadDemoScreen_KeypadHomeButton_OnReleased(leButtonWidget* btn);
void event_KeypadDemoScreen_KeypadNextButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_KeypadDemoScreen(); // called when Legato is initialized
leResult screenShow_KeypadDemoScreen(); // called when screen is shown
void screenHide_KeypadDemoScreen(); // called when screen is hidden
void screenDestroy_KeypadDemoScreen(); // called when Legato is destroyed
void screenUpdate_KeypadDemoScreen(); // called when Legato is updating

leWidget* screenGetRoot_KeypadDemoScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void KeypadDemoScreen_OnShow(); // called when this screen is shown
void KeypadDemoScreen_OnHide(); // called when this screen is hidden
void KeypadDemoScreen_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_KEYPADDEMOSCREEN_H
