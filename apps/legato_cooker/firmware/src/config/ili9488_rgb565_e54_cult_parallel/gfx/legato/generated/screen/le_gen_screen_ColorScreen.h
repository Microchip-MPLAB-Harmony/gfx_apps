#ifndef LE_GEN_SCREEN_COLORSCREEN_H
#define LE_GEN_SCREEN_COLORSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget2;
extern leWidget* PanelWidget5;
extern leRectangleWidget* ProgressRect;
extern leWidget* PanelWidget4;
extern leButtonWidget* ReheatButtonWidget;
extern leButtonWidget* CookButtonWidget;
extern leButtonWidget* ButtonWidget5;
extern leWidget* QuickSelectionsPanel;
extern leWidget* MenuItem1;
extern leRectangleWidget* ButtonRect1Back;
extern leRectangleWidget* Button1Rect;
extern leImageWidget* ButtonImage1;
extern leLabelWidget* MenuItem1Label;
extern leButtonWidget* ButtonWidget1;
extern leLabelWidget* LabelWidget2;
extern leWidget* MenuItem2;
extern leRectangleWidget* Button2RectBack;
extern leRectangleWidget* Button2Rect;
extern leImageWidget* ButtonImage2;
extern leLabelWidget* MenuItem2Label;
extern leButtonWidget* ButtonWidget2;
extern leWidget* MenuItem3;
extern leRectangleWidget* Button3RectBack;
extern leRectangleWidget* Button3Rect;
extern leImageWidget* ButtonImage3;
extern leLabelWidget* MenuItem3Label;
extern leButtonWidget* ButtonWidget3;
extern leWidget* MenuItem4;
extern leRectangleWidget* Button4RectBack;
extern leRectangleWidget* Button4Rect;
extern leImageWidget* Button4Image;
extern leLabelWidget* MenuItem4Label;
extern leButtonWidget* ButtonWidget4;
extern leWidget* Screen2MainClockPanel;
extern leLabelWidget* Screen2HourLabel;
extern leLabelWidget* Screen2ColonLabel;
extern leLabelWidget* Screen2MinuteLabel;
extern leWidget* Screen2LabelPanel;
extern leLabelWidget* Screen2GoodLabel;
extern leLabelWidget* Screen2BytesLabel;
extern leLabelWidget* Screen2SmartCookerLabel;
extern leButtonWidget* ButtonWidget6;
extern leButtonWidget* SliderButton2;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_ColorScreen(); // called when Legato is initialized
leResult screenShow_ColorScreen(); // called when screen is shown
void screenHide_ColorScreen(); // called when screen is hidden
void screenDestroy_ColorScreen(); // called when Legato is destroyed
void screenUpdate_ColorScreen(); // called when Legato is updating

leWidget* screenGetRoot_ColorScreen(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void ColorScreen_OnShow(void);

void ColorScreen_OnHide(void);

void ColorScreen_OnUpdate(void);

void ReheatButtonWidget_OnPressed(leButtonWidget* btn)
;

void CookButtonWidget_OnPressed(leButtonWidget* btn)
;

void ButtonWidget5_OnPressed(leButtonWidget* btn)
;

void ButtonWidget1_OnPressed(leButtonWidget* btn)
;

void ButtonWidget2_OnPressed(leButtonWidget* btn)
;

void ButtonWidget3_OnPressed(leButtonWidget* btn)
;

void ButtonWidget4_OnPressed(leButtonWidget* btn)
;

void ButtonWidget6_OnPressed(leButtonWidget* btn)
;

void ButtonWidget6_OnReleased(leButtonWidget* btn)
;


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_COLORSCREEN_H
