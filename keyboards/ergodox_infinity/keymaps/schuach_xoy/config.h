#include "../../config.h"

// https://docs.qmk.fm/feature_common_shortcuts.html#permissive-hold
/* #define PERMISSIVE_HOLD */

#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE  2

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
