#ifndef LE_GEN_SCREEN_LISTWHEELDEMOSCREEN_H
#define LE_GEN_SCREEN_LISTWHEELDEMOSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leGradientWidget* ListWheelDemoScreen_GradientWidget3;
extern leButtonWidget* ListWheelDemoScreen_ListWheelHelpButton;
extern leButtonWidget* ListWheelDemoScreen_ListWheelHomeButton;
extern leRectangleWidget* ListWheelDemoScreen_RectangleWidget2;
extern leLabelWidget* ListWheelDemoScreen_LabelWidget4;
extern leLabelWidget* ListWheelDemoScreen_LabelWidget5;
extern leButtonWidget* ListWheelDemoScreen_ListWheelNextButton;
extern leListWheelWidget* ListWheelDemoScreen_ListWheel1;
extern leListWheelWidget* ListWheelDemoScreen_ListWheel5;
extern leListWheelWidget* ListWheelDemoScreen_ListWheel4;
extern leListWheelWidget* ListWheelDemoScreen_ListWheel2;
extern leLabelWidget* ListWheelDemoScreen_LabelWidget3;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_ListWheelDemoScreen_ListWheelHelpButton_OnReleased(leButtonWidget* btn);
void event_ListWheelDemoScreen_ListWheelHomeButton_OnReleased(leButtonWidget* btn);
void event_ListWheelDemoScreen_ListWheelNextButton_OnReleased(leButtonWidget* btn);
void event_ListWheelDemoScreen_ListWheel1_OnSelectionChanged(leListWheelWidget* wgt, int32_t idx);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_ListWheelDemoScreen(); // called when Legato is initialized
leResult screenShow_ListWheelDemoScreen(); // called when screen is shown
void screenHide_ListWheelDemoScreen(); // called when screen is hidden
void screenDestroy_ListWheelDemoScreen(); // called when Legato is destroyed
void screenUpdate_ListWheelDemoScreen(); // called when Legato is updating

leWidget* screenGetRoot_ListWheelDemoScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void ListWheelDemoScreen_OnShow(); // called when this screen is shown
void ListWheelDemoScreen_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_LISTWHEELDEMOSCREEN_H
