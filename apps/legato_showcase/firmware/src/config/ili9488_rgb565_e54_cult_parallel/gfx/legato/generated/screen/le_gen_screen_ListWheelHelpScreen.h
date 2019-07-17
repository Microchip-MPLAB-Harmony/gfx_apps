#ifndef LE_GEN_SCREEN_LISTWHEELHELPSCREEN_H
#define LE_GEN_SCREEN_LISTWHEELHELPSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget4;
extern leImageWidget* ImageWidget14;
extern leLabelWidget* LabelWidget21;
extern leButtonWidget* ListWheelHelpCloseButton;
extern leLabelWidget* LabelWidget22;
extern leLabelWidget* LabelWidget24;
extern leImageWidget* ImageWidget16;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_ListWheelHelpScreen(); // called when Legato is initialized
leResult screenShow_ListWheelHelpScreen(); // called when screen is shown
void screenHide_ListWheelHelpScreen(); // called when screen is hidden
void screenDestroy_ListWheelHelpScreen(); // called when Legato is destroyed
void screenUpdate_ListWheelHelpScreen(); // called when Legato is updating

leWidget* screenGetRoot_ListWheelHelpScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void ListWheelHelpScreen_OnShow(void);
void ListWheelHelpScreen_OnUpdate(void);
void ListWheelHelpCloseButton_OnReleased(leButtonWidget* btn);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_LISTWHEELHELPSCREEN_H
