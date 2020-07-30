#ifndef LE_GEN_SCREEN_SCREEN2_H
#define LE_GEN_SCREEN_SCREEN2_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* Screen2_MotionBackground;
extern leRectangleWidget* Screen2_RectMotionWidget10;
extern leRectangleWidget* Screen2_RectMotionWidget9;
extern leRectangleWidget* Screen2_RectMotionWidget8;
extern leRectangleWidget* Screen2_RectMotionWidget7;
extern leRectangleWidget* Screen2_RectMotionWidget6;
extern leRectangleWidget* Screen2_RectMotionWidget5;
extern leRectangleWidget* Screen2_RectMotionWidget4;
extern leRectangleWidget* Screen2_RectMotionWidget3;
extern leRectangleWidget* Screen2_RectMotionWidget2;
extern leRectangleWidget* Screen2_RectMotionWidget1;
extern leWidget* Screen2_MotionSideContainer;
extern leLabelWidget* Screen2_MotionUpdateLabel;
extern leLabelWidget* Screen2_MotionRefreshLabel;
extern leLabelWidget* Screen2_MotionRefreshValue;
extern leLabelWidget* Screen2_MotionContainerTitle;
extern leButtonWidget* Screen2_MotionNextButton;
extern leButtonWidget* Screen2_MotionMinusButton;
extern leButtonWidget* Screen2_MotionPlusButton;
extern leLabelWidget* Screen2_MotionNumLabel;
extern leLabelWidget* Screen2_MotionRectCount;
extern leLabelWidget* Screen2_MotionRectSizeLabel;
extern leLabelWidget* Screen2_MotionRectSizeValue;
extern leButtonWidget* Screen2_MotionSizeDownButton;
extern leButtonWidget* Screen2_MotionSizeUpButton;
extern leButtonWidget* Screen2_MotionUpdateValue;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_Screen2_MotionNextButton_OnPressed(leButtonWidget* btn);
void event_Screen2_MotionMinusButton_OnPressed(leButtonWidget* btn);
void event_Screen2_MotionPlusButton_OnPressed(leButtonWidget* btn);
void event_Screen2_MotionSizeDownButton_OnPressed(leButtonWidget* btn);
void event_Screen2_MotionSizeUpButton_OnPressed(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_Screen2(); // called when Legato is initialized
leResult screenShow_Screen2(); // called when screen is shown
void screenHide_Screen2(); // called when screen is hidden
void screenDestroy_Screen2(); // called when Legato is destroyed
void screenUpdate_Screen2(); // called when Legato is updating

leWidget* screenGetRoot_Screen2(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void Screen2_OnShow(); // called when this screen is shown
void Screen2_OnHide(); // called when this screen is hidden
void Screen2_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN2_H
