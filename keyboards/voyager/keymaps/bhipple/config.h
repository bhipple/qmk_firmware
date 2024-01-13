#include "config_bhipple_common.h"

#define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"dAA/M7l"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define RGB_MATRIX_STARTUP_SPD 60

// This is allegedly the default on QMK 21+, but the Voyager version doesn't have it yet.
#define IGNORE_MOD_TAP_INTERRUPT
