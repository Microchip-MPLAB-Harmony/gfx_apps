#ifndef LE_GEN_SCREEN_MAINMENU_H
#define LE_GEN_SCREEN_MAINMENU_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leWidget* MainMenu_PanelWidget1;
extern leImageWidget* MainMenu_ImageWidget1;
extern leWidget* MainMenu_PanelWidget3;
extern leWidget* MainMenu_MainPanel;
extern leImageWidget* MainMenu_ImageWidget2;
extern leImageWidget* MainMenu_ImageWidget3;
extern leImageWidget* MainMenu_ImageWidget4;
extern leWidget* MainMenu_Badge;
extern leWidget* MainMenu_ClockPanel;
extern leImageWidget* MainMenu_ImageWidget8;
extern leWidget* MainMenu_PanelWidget0;
extern leButtonWidget* MainMenu_ButtonWidget0;
extern leImageWidget* MainMenu_ImageWidget9;
extern leButtonWidget* MainMenu_DemoModeOnButton;
extern leListWheelWidget* MainMenu_ListWheelWidget2;
extern leButtonWidget* MainMenu_ReheatButton;
extern leButtonWidget* MainMenu_BroilButton;
extern leButtonWidget* MainMenu_CookButton;
extern leButtonWidget* MainMenu_BakeButton;
extern leLabelWidget* MainMenu_LabelWidget1;
extern leLabelWidget* MainMenu_LabelWidget3;
extern leLabelWidget* MainMenu_LabelWidget0;
extern leLabelWidget* MainMenu_HourLabel;
extern leImageWidget* MainMenu_ImageWidget6;
extern leLabelWidget* MainMenu_ColonLabel;
extern leLabelWidget* MainMenu_MinuteLabel;
extern leButtonWidget* MainMenu_SliderButton0;
extern leButtonWidget* MainMenu_RestartButton;
extern leButtonWidget* MainMenu_CancelButton;
extern leProgressBarWidget* MainMenu_ProgressBarWidget0;
extern leLabelWidget* MainMenu_CookTimeLabel;
extern leImageWidget* MainMenu_ModeImageWidget;
extern leRectangleWidget* MainMenu_RectangleWidget3;
extern leRectangleWidget* MainMenu_RectangleWidget2;
extern leRectangleWidget* MainMenu_RectangleWidget1;
extern leRectangleWidget* MainMenu_RectangleWidget0;
extern leImageWidget* MainMenu_ImageWidget0;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_MainMenu_ButtonWidget0_OnReleased(leButtonWidget* btn);
void event_MainMenu_DemoModeOnButton_OnPressed(leButtonWidget* btn);
void event_MainMenu_DemoModeOnButton_OnReleased(leButtonWidget* btn);
void event_MainMenu_ListWheelWidget2_OnSelectionChanged(leListWheelWidget* wgt, int32_t idx);
void event_MainMenu_ReheatButton_OnReleased(leButtonWidget* btn);
void event_MainMenu_BroilButton_OnReleased(leButtonWidget* btn);
void event_MainMenu_CookButton_OnReleased(leButtonWidget* btn);
void event_MainMenu_BakeButton_OnReleased(leButtonWidget* btn);
void event_MainMenu_RestartButton_OnReleased(leButtonWidget* btn);
void event_MainMenu_CancelButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_MainMenu(); // called when Legato is initialized
leResult screenShow_MainMenu(); // called when screen is shown
void screenHide_MainMenu(); // called when screen is hidden
void screenDestroy_MainMenu(); // called when Legato is destroyed
void screenUpdate_MainMenu(); // called when Legato is updating

leWidget* screenGetRoot_MainMenu(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void MainMenu_OnShow(); // called when this screen is shown
void MainMenu_OnHide(); // called when this screen is hidden
void MainMenu_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_MAINMENU_H
