#ifndef LE_GEN_SCREEN_DEFAULT_H
#define LE_GEN_SCREEN_DEFAULT_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* Background;
extern leWidget* SysValue;
extern leLabelWidget* SysValue1;
extern leLabelWidget* SysValue10;
extern leLabelWidget* SysValue100;
extern leWidget* DiaValue;
extern leLabelWidget* DiaValue1;
extern leLabelWidget* DiaValue10;
extern leLabelWidget* DiaValue100;
extern leWidget* PulseValue;
extern leLabelWidget* PulseValue1;
extern leLabelWidget* PulseValue10;
extern leLabelWidget* PulseValue100;
extern leLabelWidget* DateLabel;
extern leImageWidget* HeartImage;
extern leLineWidget* LineWidget18;
extern leImageWidget* ImageWidget21;
extern leLineWidget* LineWidget22;
extern leLineWidget* LineWidget23;
extern leLineWidget* LineWidget24;
extern leLineWidget* LineWidget25;
extern leLineWidget* LineWidget26;
extern leImageWidget* MicrochipLogo;
extern leImageWidget* SideBar;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_default(); // called when Legato is initialized
leResult screenShow_default(); // called when screen is shown
void screenHide_default(); // called when screen is hidden
void screenDestroy_default(); // called when Legato is destroyed
void screenUpdate_default(); // called when Legato is updating

leWidget* screenGetRoot_default(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void default_OnShow(void);
void default_OnHide(void);
void default_OnUpdate(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_DEFAULT_H
