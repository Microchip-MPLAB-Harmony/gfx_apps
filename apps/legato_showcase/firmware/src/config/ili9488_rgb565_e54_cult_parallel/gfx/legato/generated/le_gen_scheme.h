#ifndef LEGATO_INIT_SCHEME_H
#define LEGATO_INIT_SCHEME_H

#include "gfx/legato/legato.h"

extern leScheme AlternateGradientScheme;
extern leScheme BackgroundGradientScheme;
extern leScheme BlackBackground;
extern leScheme defaultScheme;
extern leScheme GradientScheme;
extern leScheme ListWheelScheme;
extern leScheme MainMenuGradientScheme;
extern leScheme RadioButtonsOnDarkScheme;
extern leScheme TouchTestScheme;
extern leScheme whiteScheme;

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
