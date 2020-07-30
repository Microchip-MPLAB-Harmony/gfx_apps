#ifndef LE_GEN_SCREEN_SCREEN1_H
#define LE_GEN_SCREEN_SCREEN1_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Screen1_FPSBackground;
extern leLabelWidget* Screen1_FPSCounterValue;
extern leWidget* Screen1_FPSSideContainer;
extern leButtonWidget* Screen1_FPSUpdateValue;
extern leLabelWidget* Screen1_FPSUpdateLabel;
extern leLabelWidget* Screen1_FPSRefreshLabel;
extern leLabelWidget* Screen1_FPSRefreshValue;
extern leButtonWidget* Screen1_FPSCounterSizeDown;
extern leButtonWidget* Screen1_FPSCounterSizeUp;
extern leLabelWidget* Screen1_FPSContainerTitle;
extern leButtonWidget* Screen1_FPSNextButton;
extern leLabelWidget* Screen1_FPSStringSize;
extern leLabelWidget* Screen1_FPSSizeLabel;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Screen1_FPSCounterSizeDown_OnPressed(leButtonWidget* btn);
void event_Screen1_FPSCounterSizeUp_OnPressed(leButtonWidget* btn);
void event_Screen1_FPSNextButton_OnPressed(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Screen1(); // called when Legato is initialized
leResult screenShow_Screen1(); // called when screen is shown
void screenHide_Screen1(); // called when screen is hidden
void screenDestroy_Screen1(); // called when Legato is destroyed
void screenUpdate_Screen1(); // called when Legato is updating

leWidget* screenGetRoot_Screen1(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Screen1_OnShow(); // called when this screen is shown
void Screen1_OnHide(); // called when this screen is hidden
void Screen1_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN1_H
