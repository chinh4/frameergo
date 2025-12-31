// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ 0 │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ 0 │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ 0 │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     *         ┌───┬───┬───┬───┬───┬───┐
     *         │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │
     *         └───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,
        KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,
        KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,
                    KC_0, KC_1, KC_2, KC_3, KC_4, KC_5

    )
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif
