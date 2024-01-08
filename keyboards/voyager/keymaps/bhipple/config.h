/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-config-file
*/
#define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"dAA/M7l"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define RGB_MATRIX_STARTUP_SPD 60

// bhipple options
#define TAPPING_TERM 150
#define RETRO_TAPPING

// Only auto shift the number keys
#define NO_AUTO_SHIFT_ALPHA
#define NO_AUTO_SHIFT_SPECIAL

#undef PERMISSIVE_HOLD
#undef PERMISSIVE_HOLD_PER_KEY

// This is allegedly the default on QMK 21+, but the Voyager version doesn't have it yet.
#define IGNORE_MOD_TAP_INTERRUPT
