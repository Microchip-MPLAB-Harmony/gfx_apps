#ifndef LE_GEN_SCREEN_SCREEN1_H
#define LE_GEN_SCREEN_SCREEN1_H

#include "gfx/legato/legato.h"

#include "gfx/legato/generated/le_gen_scheme.h"
#include "gfx/legato/generated/le_gen_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// screen member widget declarations
extern leImageWidget* screen1_BackgroundImage;
extern leButtonWidget* screen1_RecirculateButton;
extern leButtonWidget* screen1_WindshieldVentButton;
extern leButtonWidget* screen1_RearVentButton;
extern leButtonWidget* screen1_ClimateControlButton;
extern leButtonWidget* screen1_SeatHeaterButton;
extern leButtonWidget* screen1_DriverZoneButton;
extern leButtonWidget* screen1_FrontPassZoneButton;
extern leButtonWidget* screen1_RearRightPassZoneButton;
extern leButtonWidget* screen1_RearLeftPassZoneButton;
extern leImageSequenceWidget* screen1_TempImageSequenceWidget;
extern leImageSequenceWidget* screen1_FanLevel1;
extern leImageSequenceWidget* screen1_FanLevel2;
extern leImageSequenceWidget* screen1_FanLevel3;
extern leImageSequenceWidget* screen1_FanLevel4;
extern leImageSequenceWidget* screen1_FanLevel5;
extern leImageSequenceWidget* screen1_FanLevel6;
extern leImageSequenceWidget* screen1_ZoneImageSequence;
extern leButtonWidget* screen1_TempControlButton;
extern leButtonWidget* screen1_SyncButton;
extern leButtonWidget* screen1_HighVentButton;
extern leButtonWidget* screen1_MidVentButton;
extern leButtonWidget* screen1_LowVentButton;
extern leButtonWidget* screen1_FanButtonWidget;
extern leButtonWidget* screen1_InfoPageButton;
extern leButtonWidget* screen1_mchpButton;
extern leButtonWidget* screen1_AirconButton;
extern leWidget* screen1_PanelWidget1;
extern leImageWidget* screen1_ImageWidget1;
extern leWidget* screen1_PanelWidget0;
extern leImageSequenceWidget* screen1_HourTimeWidget;
extern leImageWidget* screen1_ColonImage;
extern leImageSequenceWidget* screen1_MinuteTimeWidget;
extern leImageWidget* screen1_AMImageWidget;
extern leImageWidget* screen1_ImageWidget2;
extern leButtonWidget* screen1_TopBannerButton;

// event handlers
// !!THESE MUST BE IMPLEMENTED IN THE APPLICATION CODE!!
void event_screen1_RecirculateButton_OnPressed(leButtonWidget* btn);
void event_screen1_RecirculateButton_OnReleased(leButtonWidget* btn);
void event_screen1_WindshieldVentButton_OnPressed(leButtonWidget* btn);
void event_screen1_WindshieldVentButton_OnReleased(leButtonWidget* btn);
void event_screen1_RearVentButton_OnPressed(leButtonWidget* btn);
void event_screen1_RearVentButton_OnReleased(leButtonWidget* btn);
void event_screen1_ClimateControlButton_OnPressed(leButtonWidget* btn);
void event_screen1_ClimateControlButton_OnReleased(leButtonWidget* btn);
void event_screen1_SeatHeaterButton_OnPressed(leButtonWidget* btn);
void event_screen1_SeatHeaterButton_OnReleased(leButtonWidget* btn);
void event_screen1_DriverZoneButton_OnPressed(leButtonWidget* btn);
void event_screen1_FrontPassZoneButton_OnPressed(leButtonWidget* btn);
void event_screen1_RearRightPassZoneButton_OnPressed(leButtonWidget* btn);
void event_screen1_RearLeftPassZoneButton_OnPressed(leButtonWidget* btn);
void event_screen1_SyncButton_OnPressed(leButtonWidget* btn);
void event_screen1_SyncButton_OnReleased(leButtonWidget* btn);
void event_screen1_HighVentButton_OnPressed(leButtonWidget* btn);
void event_screen1_HighVentButton_OnReleased(leButtonWidget* btn);
void event_screen1_MidVentButton_OnPressed(leButtonWidget* btn);
void event_screen1_MidVentButton_OnReleased(leButtonWidget* btn);
void event_screen1_LowVentButton_OnPressed(leButtonWidget* btn);
void event_screen1_LowVentButton_OnReleased(leButtonWidget* btn);
void event_screen1_InfoPageButton_OnPressed(leButtonWidget* btn);
void event_screen1_InfoPageButton_OnReleased(leButtonWidget* btn);
void event_screen1_mchpButton_OnPressed(leButtonWidget* btn);
void event_screen1_mchpButton_OnReleased(leButtonWidget* btn);
void event_screen1_AirconButton_OnPressed(leButtonWidget* btn);
void event_screen1_AirconButton_OnReleased(leButtonWidget* btn);
void event_screen1_TopBannerButton_OnPressed(leButtonWidget* btn);
void event_screen1_TopBannerButton_OnReleased(leButtonWidget* btn);

// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_screen1(); // called when Legato is initialized
leResult screenShow_screen1(); // called when screen is shown
void screenHide_screen1(); // called when screen is hidden
void screenDestroy_screen1(); // called when Legato is destroyed
void screenUpdate_screen1(); // called when Legato is updating

leWidget* screenGetRoot_screen1(uint32_t lyrIdx); // gets a root widget for this screen

// Screen Events:
void screen1_OnShow(); // called when this screen is shown
void screen1_OnHide(); // called when this screen is hidden
void screen1_OnUpdate(); // called when this screen is updated

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN1_H
