#ifndef LEGATO_INIT_SCHEME_H
#define LEGATO_INIT_SCHEME_H

#include "gfx/legato/legato.h"

extern const leScheme defaultScheme;
extern const leScheme ListWheelScheme;
extern const leScheme AlternateGradientScheme;
extern const leScheme RadioButtonsOnDarkScheme;
extern const leScheme whiteScheme;
extern const leScheme BlackBackground;
extern const leScheme BackgroundGradientScheme;
extern const leScheme MainMenuGradientScheme;
extern const leScheme TouchTestScheme;
extern const leScheme GradientScheme;

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

void legato_initialize_schemes();

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LEGATO_INIT_SCHEME_H
