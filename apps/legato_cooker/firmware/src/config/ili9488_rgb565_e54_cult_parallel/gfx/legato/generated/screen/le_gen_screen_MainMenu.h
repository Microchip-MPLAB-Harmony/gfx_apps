#ifndef LE_GEN_SCREEN_MAINMENU_H
#define LE_GEN_SCREEN_MAINMENU_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget1;
extern leImageWidget* ImageWidget1;
extern leWidget* PanelWidget3;
extern leListWheelWidget* ListWheelWidget2;
extern leWidget* MainPanel;
extern leButtonWidget* BakeButton;
extern leButtonWidget* CookButton;
extern leButtonWidget* BroilButton;
extern leButtonWidget* ReheatButton;
extern leImageWidget* ImageWidget2;
extern leImageWidget* ImageWidget3;
extern leImageWidget* ImageWidget4;
extern leWidget* Badge;
extern leLabelWidget* LabelWidget0;
extern leLabelWidget* LabelWidget3;
extern leLabelWidget* LabelWidget1;
extern leWidget* ClockPanel;
extern leLabelWidget* MinuteLabel;
extern leLabelWidget* ColonLabel;
extern leImageWidget* ImageWidget6;
extern leLabelWidget* HourLabel;
extern leImageWidget* ImageWidget8;
extern leWidget* PanelWidget0;
extern leImageWidget* ImageWidget0;
extern leRectangleWidget* RectangleWidget0;
extern leRectangleWidget* RectangleWidget1;
extern leRectangleWidget* RectangleWidget2;
extern leRectangleWidget* RectangleWidget3;
extern leImageWidget* ModeImageWidget;
extern leLabelWidget* CookTimeLabel;
extern leProgressBarWidget* ProgressBarWidget0;
extern leButtonWidget* CancelButton;
extern leButtonWidget* RestartButton;
extern leButtonWidget* SliderButton0;
extern leButtonWidget* ButtonWidget0;
extern leImageWidget* ImageWidget9;
extern leButtonWidget* DemoModeOnButton;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_MainMenu(); // called when Legato is initialized
leResult screenShow_MainMenu(); // called when screen is shown
void screenHide_MainMenu(); // called when screen is hidden
void screenDestroy_MainMenu(); // called when Legato is destroyed
void screenUpdate_MainMenu(); // called when Legato is updating

leWidget* screenGetRoot_MainMenu(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void MainMenu_OnShow(void);

void MainMenu_OnHide(void);

void MainMenu_OnUpdate(void);

void ListWheelWidget2_OnSelectionChanged(leListWheelWidget* lst, int32_t idx)
;

void BakeButton_OnReleased(leButtonWidget* btn)
;

void CookButton_OnReleased(leButtonWidget* btn)
;

void BroilButton_OnReleased(leButtonWidget* btn)
;

void ReheatButton_OnReleased(leButtonWidget* btn)
;

void CancelButton_OnReleased(leButtonWidget* btn)
;

void RestartButton_OnPressed(leButtonWidget* btn)
;

void RestartButton_OnReleased(leButtonWidget* btn)
;

void ButtonWidget0_OnReleased(leButtonWidget* btn)
;

void DemoModeOnButton_OnPressed(leButtonWidget* btn)
;

void DemoModeOnButton_OnReleased(leButtonWidget* btn)
;


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_MAINMENU_H
