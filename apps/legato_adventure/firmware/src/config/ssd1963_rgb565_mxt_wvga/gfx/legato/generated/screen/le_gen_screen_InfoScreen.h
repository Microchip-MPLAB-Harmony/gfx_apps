#ifndef LE_GEN_SCREEN_INFOSCREEN_H
#define LE_GEN_SCREEN_INFOSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget0;
extern leImageWidget* ImageWidget1;
extern leLabelWidget* LabelWidget0;
extern leLabelWidget* LabelWidget1;
extern leLabelWidget* LabelWidget2;
extern leLabelWidget* LabelWidget3;
extern leLabelWidget* LabelWidget4;
extern leLabelWidget* LabelWidget5;
extern leButtonWidget* ButtonWidget0;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_InfoScreen(); // called when Legato is initialized
leResult screenShow_InfoScreen(); // called when screen is shown
void screenHide_InfoScreen(); // called when screen is hidden
void screenDestroy_InfoScreen(); // called when Legato is destroyed
void screenUpdate_InfoScreen(); // called when Legato is updating

leWidget* screenGetRoot_InfoScreen(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_INFOSCREEN_H
