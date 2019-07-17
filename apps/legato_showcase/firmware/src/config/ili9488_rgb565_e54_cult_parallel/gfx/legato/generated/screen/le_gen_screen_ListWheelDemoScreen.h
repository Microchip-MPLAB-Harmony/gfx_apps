#ifndef LE_GEN_SCREEN_LISTWHEELDEMOSCREEN_H
#define LE_GEN_SCREEN_LISTWHEELDEMOSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leGradientWidget* GradientWidget3;
extern leButtonWidget* ListWheelHelpButton;
extern leButtonWidget* ListWheelHomeButton;
extern leRectangleWidget* RectangleWidget2;
extern leLabelWidget* LabelWidget3;
extern leListWheelWidget* ListWheel2;
extern leListWheelWidget* ListWheel4;
extern leListWheelWidget* ListWheel5;
extern leListWheelWidget* ListWheel1;
extern leLabelWidget* LabelWidget4;
extern leLabelWidget* LabelWidget5;
extern leButtonWidget* ListWheelNextButton;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_ListWheelDemoScreen(); // called when Legato is initialized
leResult screenShow_ListWheelDemoScreen(); // called when screen is shown
void screenHide_ListWheelDemoScreen(); // called when screen is hidden
void screenDestroy_ListWheelDemoScreen(); // called when Legato is destroyed
void screenUpdate_ListWheelDemoScreen(); // called when Legato is updating

leWidget* screenGetRoot_ListWheelDemoScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void ListWheelDemoScreen_OnShow(void);
void ListWheelDemoScreen_OnUpdate(void);
void ListWheelHelpButton_OnReleased(leButtonWidget* btn);
void ListWheelHomeButton_OnReleased(leButtonWidget* btn);
void ListWheel1_OnSelectionChanged(leListWheelWidget* lst, int32_t idx);
void ListWheelNextButton_OnReleased(leButtonWidget* btn);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_LISTWHEELDEMOSCREEN_H
