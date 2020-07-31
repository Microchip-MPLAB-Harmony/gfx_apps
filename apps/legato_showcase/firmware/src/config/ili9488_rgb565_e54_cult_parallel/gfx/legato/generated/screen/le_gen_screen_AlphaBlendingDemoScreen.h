#ifndef LE_GEN_SCREEN_ALPHABLENDINGDEMOSCREEN_H
#define LE_GEN_SCREEN_ALPHABLENDINGDEMOSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leGradientWidget* AlphaBlendingDemoScreen_GradientWidget5;
extern leWidget* AlphaBlendingDemoScreen_PanelWidget1;
extern leWidget* AlphaBlendingDemoScreen_PanelWidget2;
extern leButtonWidget* AlphaBlendingDemoScreen_AlphaHelpButton;
extern leButtonWidget* AlphaBlendingDemoScreen_AlphaHomeButton;
extern leLabelWidget* AlphaBlendingDemoScreen_LabelWidget9;
extern leButtonWidget* AlphaBlendingDemoScreen_AlphaNextButton;
extern leButtonWidget* AlphaBlendingDemoScreen_SliderUpButtonWidget;
extern leButtonWidget* AlphaBlendingDemoScreen_SliderDownButtonWidget;
extern leLabelWidget* AlphaBlendingDemoScreen_SliderValueLabelWidget;
extern leSliderWidget* AlphaBlendingDemoScreen_SliderWidget1;
extern leImageWidget* AlphaBlendingDemoScreen_ImageWidget2;
extern leImageWidget* AlphaBlendingDemoScreen_ImageWidget1;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_AlphaBlendingDemoScreen_AlphaHelpButton_OnReleased(leButtonWidget* btn);
void event_AlphaBlendingDemoScreen_AlphaHomeButton_OnReleased(leButtonWidget* btn);
void event_AlphaBlendingDemoScreen_AlphaNextButton_OnReleased(leButtonWidget* btn);
void event_AlphaBlendingDemoScreen_SliderUpButtonWidget_OnReleased(leButtonWidget* btn);
void event_AlphaBlendingDemoScreen_SliderDownButtonWidget_OnReleased(leButtonWidget* btn);
void event_AlphaBlendingDemoScreen_SliderWidget1_OnValueChanged(leSliderWidget* scr);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_AlphaBlendingDemoScreen(); // called when Legato is initialized
leResult screenShow_AlphaBlendingDemoScreen(); // called when screen is shown
void screenHide_AlphaBlendingDemoScreen(); // called when screen is hidden
void screenDestroy_AlphaBlendingDemoScreen(); // called when Legato is destroyed
void screenUpdate_AlphaBlendingDemoScreen(); // called when Legato is updating

leWidget* screenGetRoot_AlphaBlendingDemoScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void AlphaBlendingDemoScreen_OnShow(); // called when this screen is shown
void AlphaBlendingDemoScreen_OnHide(); // called when this screen is hidden
void AlphaBlendingDemoScreen_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_ALPHABLENDINGDEMOSCREEN_H
