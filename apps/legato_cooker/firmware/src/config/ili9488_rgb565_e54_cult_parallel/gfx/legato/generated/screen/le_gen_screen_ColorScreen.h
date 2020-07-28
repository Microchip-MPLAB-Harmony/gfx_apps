#ifndef LE_GEN_SCREEN_COLORSCREEN_H
#define LE_GEN_SCREEN_COLORSCREEN_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* ColorScreen_PanelWidget2;
extern leWidget* ColorScreen_PanelWidget5;
extern leWidget* ColorScreen_PanelWidget4;
extern leWidget* ColorScreen_QuickSelectionsPanel;
extern leWidget* ColorScreen_Screen2MainClockPanel;
extern leWidget* ColorScreen_Screen2LabelPanel;
extern leButtonWidget* ColorScreen_SliderButton2;
extern leRectangleWidget* ColorScreen_ProgressRect;
extern leButtonWidget* ColorScreen_ReheatButtonWidget;
extern leButtonWidget* ColorScreen_CookButtonWidget;
extern leButtonWidget* ColorScreen_ButtonWidget5;
extern leWidget* ColorScreen_MenuItem1;
extern leLabelWidget* ColorScreen_LabelWidget2;
extern leWidget* ColorScreen_MenuItem2;
extern leWidget* ColorScreen_MenuItem3;
extern leWidget* ColorScreen_MenuItem4;
extern leRectangleWidget* ColorScreen_ButtonRect1Back;
extern leRectangleWidget* ColorScreen_Button1Rect;
extern leImageWidget* ColorScreen_ButtonImage1;
extern leLabelWidget* ColorScreen_MenuItem1Label;
extern leButtonWidget* ColorScreen_ButtonWidget1;
extern leRectangleWidget* ColorScreen_Button2RectBack;
extern leRectangleWidget* ColorScreen_Button2Rect;
extern leImageWidget* ColorScreen_ButtonImage2;
extern leLabelWidget* ColorScreen_MenuItem2Label;
extern leButtonWidget* ColorScreen_ButtonWidget2;
extern leRectangleWidget* ColorScreen_Button3RectBack;
extern leRectangleWidget* ColorScreen_Button3Rect;
extern leImageWidget* ColorScreen_ButtonImage3;
extern leLabelWidget* ColorScreen_MenuItem3Label;
extern leButtonWidget* ColorScreen_ButtonWidget3;
extern leRectangleWidget* ColorScreen_Button4RectBack;
extern leRectangleWidget* ColorScreen_Button4Rect;
extern leImageWidget* ColorScreen_Button4Image;
extern leLabelWidget* ColorScreen_MenuItem4Label;
extern leButtonWidget* ColorScreen_ButtonWidget4;
extern leLabelWidget* ColorScreen_Screen2HourLabel;
extern leLabelWidget* ColorScreen_Screen2ColonLabel;
extern leLabelWidget* ColorScreen_Screen2MinuteLabel;
extern leLabelWidget* ColorScreen_Screen2GoodLabel;
extern leLabelWidget* ColorScreen_Screen2BytesLabel;
extern leLabelWidget* ColorScreen_Screen2SmartCookerLabel;
extern leButtonWidget* ColorScreen_ButtonWidget6;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_ColorScreen_ReheatButtonWidget_OnPressed(leButtonWidget* btn);
void event_ColorScreen_CookButtonWidget_OnPressed(leButtonWidget* btn);
void event_ColorScreen_ButtonWidget5_OnPressed(leButtonWidget* btn);
void event_ColorScreen_ButtonWidget1_OnPressed(leButtonWidget* btn);
void event_ColorScreen_ButtonWidget2_OnPressed(leButtonWidget* btn);
void event_ColorScreen_ButtonWidget3_OnPressed(leButtonWidget* btn);
void event_ColorScreen_ButtonWidget4_OnPressed(leButtonWidget* btn);
void event_ColorScreen_ButtonWidget6_OnPressed(leButtonWidget* btn);
void event_ColorScreen_ButtonWidget6_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_ColorScreen(); // called when Legato is initialized
leResult screenShow_ColorScreen(); // called when screen is shown
void screenHide_ColorScreen(); // called when screen is hidden
void screenDestroy_ColorScreen(); // called when Legato is destroyed
void screenUpdate_ColorScreen(); // called when Legato is updating

leWidget* screenGetRoot_ColorScreen(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void ColorScreen_OnShow(); // called when this screen is shown
void ColorScreen_OnHide(); // called when this screen is hidden
void ColorScreen_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_COLORSCREEN_H
