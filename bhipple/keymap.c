#include QMK_KEYBOARD_H

// Define Aliases
#define D_BLUETOOTH_CON KC_WWW_SEARCH
#define D_BLUETOOTH_DISC KC_MAIL
#define D_PROGRAM LALT(KC_P)
#define D_TERMINAL LALT(KC_ENTER)

#include "generated.h"

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // All LEDs off, regardless of whatever effect/mode is stored in EEPROM
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, RGB_OFF);
    }

    // Layer indicators. OSL and momentary holds both activate the layer in
    // layer_state, so this covers one-shot and hold-to-shift alike.
    uint8_t layer = get_highest_layer(layer_state);
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led = g_led_config.matrix_co[row][col];
            if (led == NO_LED) {
                continue;
            }
            uint16_t kc = keymap_key_to_keycode(layer, (keypos_t){.col = col, .row = row});

            // Qwerty: light up only the Q key and the escape hatch back to Colemak
            if (layer == Qwerty && (kc == KC_Q || kc == TO(Colemak))) {
                rgb_matrix_set_color(led, RGB_RED);
            }

            // Macros: light up every key that does something on this layer
            if (layer == Macros && kc != KC_TRNS && kc != KC_NO) {
                rgb_matrix_set_color(led, RGB_BLUE);
            }
        }
    }

    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Only do things on key presses, not lift ups
    if (!record->event.pressed) {
        return true;
    }

    // All of the standard ones that are just mapping KEY -> STRING
    return generated_keycode_process(keycode);
}
