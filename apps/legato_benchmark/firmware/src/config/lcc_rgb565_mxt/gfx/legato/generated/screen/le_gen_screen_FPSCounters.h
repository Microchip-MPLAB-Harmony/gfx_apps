#ifndef LE_GEN_SCREEN_FPSCOUNTERS_H
#define LE_GEN_SCREEN_FPSCOUNTERS_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* FPSBackground;
extern leLabelWidget* FPSCounterValue;
extern leWidget* FPSSideContainer;
extern leLabelWidget* FPSUpdateLabel;
extern leLabelWidget* FPSRefreshLabel;
extern leLabelWidget* FPSRefreshValue;
extern leButtonWidget* FPSCounterSizeDown;
extern leButtonWidget* FPSCounterSizeUp;
extern leLabelWidget* FPSContainerTitle;
extern leButtonWidget* FPSNextButton;
extern leLabelWidget* FPSStringSize;
extern leLabelWidget* FPSSizeLabel;
extern leButtonWidget* FPSUpdateValue;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_FPSCounters(); // called when Legato is initialized
leResult screenShow_FPSCounters(); // called when screen is shown
void screenHide_FPSCounters(); // called when screen is hidden
void screenDestroy_FPSCounters(); // called when Legato is destroyed
void screenUpdate_FPSCounters(); // called when Legato is updating

leWidget* screenGetRoot_FPSCounters(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void FPSCounters_OnShow(void);
void FPSCounters_OnHide(void);
void FPSCounters_OnUpdate(void);
void FPSCounterSizeDown_OnPressed(leButtonWidget* btn);
void FPSCounterSizeUp_OnPressed(leButtonWidget* btn);
void FPSNextButton_OnPressed(leButtonWidget* btn);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_FPSCOUNTERS_H
