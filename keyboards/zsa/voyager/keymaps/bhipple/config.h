#include "config_bhipple_common.h"

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"dAA/M7l"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define RGB_MATRIX_STARTUP_SPD 60

// Keep all LEDs dark by default; layer indicators in keymap.c light specific keys
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 0
#define RGB_MATRIX_DEFAULT_VAL 0
