#ifndef LE_GEN_SCREEN_LISTWHEELHELPSCREEN_H
#define LE_GEN_SCREEN_LISTWHEELHELPSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* ListWheelHelpScreen_PanelWidget4;
extern leImageWidget* ListWheelHelpScreen_ImageWidget14;
extern leLabelWidget* ListWheelHelpScreen_LabelWidget21;
extern leButtonWidget* ListWheelHelpScreen_ListWheelHelpCloseButton;
extern leLabelWidget* ListWheelHelpScreen_LabelWidget22;
extern leLabelWidget* ListWheelHelpScreen_LabelWidget24;
extern leImageWidget* ListWheelHelpScreen_ImageWidget16;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_ListWheelHelpScreen_ListWheelHelpCloseButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_ListWheelHelpScreen(); // called when Legato is initialized
leResult screenShow_ListWheelHelpScreen(); // called when screen is shown
void screenHide_ListWheelHelpScreen(); // called when screen is hidden
void screenDestroy_ListWheelHelpScreen(); // called when Legato is destroyed
void screenUpdate_ListWheelHelpScreen(); // called when Legato is updating

leWidget* screenGetRoot_ListWheelHelpScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void ListWheelHelpScreen_OnShow(); // called when this screen is shown
void ListWheelHelpScreen_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_LISTWHEELHELPSCREEN_H
