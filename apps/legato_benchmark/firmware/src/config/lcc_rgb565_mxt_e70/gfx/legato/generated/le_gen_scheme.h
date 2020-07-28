#ifndef LEGATO_INIT_SCHEME_H
#define LEGATO_INIT_SCHEME_H

#include "gfx/legato/legato.h"

extern const leScheme LightGreenBackgroundScheme;
extern const leScheme LightPinkFillScheme;
extern const leScheme LightBlueFillScheme;
extern const leScheme LightBlueBackgroundScheme;
extern const leScheme PurpleFillScheme;
extern const leScheme RedFillScheme;
extern const leScheme BlueFillScheme;
extern const leScheme defaultScheme;
extern const leScheme LightRedBackgroundScheme;
extern const leScheme BrownFillScheme;
extern const leScheme WhiteBackgroundScheme;
extern const leScheme BlackFillScheme;
extern const leScheme OrangeFillScheme;
extern const leScheme PinkFillScheme;
extern const leScheme YellowFillScheme;
extern const leScheme WhiteFillScheme;

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
