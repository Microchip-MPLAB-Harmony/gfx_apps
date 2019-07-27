#ifndef LE_GEN_SCREEN_TOUCHTESTHELPSCREEN_H
#define LE_GEN_SCREEN_TOUCHTESTHELPSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget5;
extern leImageWidget* ImageWidget17;
extern leButtonWidget* TouchTestHelpCloseButton;
extern leLabelWidget* LabelWidget25;
extern leLabelWidget* LabelWidget26;
extern leLabelWidget* LabelWidget28;
extern leImageWidget* ImageWidget19;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_TouchTestHelpScreen(); // called when Legato is initialized
leResult screenShow_TouchTestHelpScreen(); // called when screen is shown
void screenHide_TouchTestHelpScreen(); // called when screen is hidden
void screenDestroy_TouchTestHelpScreen(); // called when Legato is destroyed
void screenUpdate_TouchTestHelpScreen(); // called when Legato is updating

leWidget* screenGetRoot_TouchTestHelpScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void TouchTestHelpScreen_OnShow(void);

void TouchTestHelpScreen_OnUpdate(void);

void TouchTestHelpCloseButton_OnReleased(leButtonWidget* btn)
;


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_TOUCHTESTHELPSCREEN_H
