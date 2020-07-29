#ifndef LE_GEN_SCREEN_TOUCHTESTHELPSCREEN_H
#define LE_GEN_SCREEN_TOUCHTESTHELPSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* TouchTestHelpScreen_PanelWidget5;
extern leImageWidget* TouchTestHelpScreen_ImageWidget17;
extern leButtonWidget* TouchTestHelpScreen_TouchTestHelpCloseButton;
extern leLabelWidget* TouchTestHelpScreen_LabelWidget25;
extern leLabelWidget* TouchTestHelpScreen_LabelWidget26;
extern leLabelWidget* TouchTestHelpScreen_LabelWidget28;
extern leImageWidget* TouchTestHelpScreen_ImageWidget19;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_TouchTestHelpScreen_TouchTestHelpCloseButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_TouchTestHelpScreen(); // called when Legato is initialized
leResult screenShow_TouchTestHelpScreen(); // called when screen is shown
void screenHide_TouchTestHelpScreen(); // called when screen is hidden
void screenDestroy_TouchTestHelpScreen(); // called when Legato is destroyed
void screenUpdate_TouchTestHelpScreen(); // called when Legato is updating

leWidget* screenGetRoot_TouchTestHelpScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void TouchTestHelpScreen_OnShow(); // called when this screen is shown
void TouchTestHelpScreen_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_TOUCHTESTHELPSCREEN_H
