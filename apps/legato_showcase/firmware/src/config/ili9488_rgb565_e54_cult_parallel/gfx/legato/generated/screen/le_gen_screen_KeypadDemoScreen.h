#ifndef LE_GEN_SCREEN_KEYPADDEMOSCREEN_H
#define LE_GEN_SCREEN_KEYPADDEMOSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leGradientWidget* BackgroundGradient2;
extern leKeyPadWidget* KeyPadWidget1;
extern leTextFieldWidget* TextFieldWidget1;
extern leButtonWidget* KeypadHelpButton;
extern leButtonWidget* KeypadHomeButton;
extern leLabelWidget* LabelWidget8;
extern leButtonWidget* KeypadNextButton;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_KeypadDemoScreen(); // called when Legato is initialized
leResult screenShow_KeypadDemoScreen(); // called when screen is shown
void screenHide_KeypadDemoScreen(); // called when screen is hidden
void screenDestroy_KeypadDemoScreen(); // called when Legato is destroyed
void screenUpdate_KeypadDemoScreen(); // called when Legato is updating

leWidget* screenGetRoot_KeypadDemoScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void KeypadDemoScreen_OnShow(void);

void KeypadDemoScreen_OnHide(void);

void KeypadDemoScreen_OnUpdate(void);

void TextFieldWidget1_OnFocusChanged(leTextFieldWidget* txt, leBool focused)
;

void KeypadHelpButton_OnReleased(leButtonWidget* btn)
;

void KeypadHomeButton_OnReleased(leButtonWidget* btn)
;

void KeypadNextButton_OnReleased(leButtonWidget* btn)
;


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_KEYPADDEMOSCREEN_H
