#include QMK_KEYBOARD_H

enum layers {
    BASE,  // qwerty linux
    OSX,   // qwerty osx
    _FL, // function key layer
    _ADJUST,
};

enum keycodes {
    // default layout switcher
    LAY_LIN = SAFE_RANGE,
    LAY_OSX,
    TICK_ESC,
};

// clang-format off

/*
 * ,---------------------------------------------------------------------|
 * |`  |1  |2  |3  |4  |5  |6  |7  |8  |9  |0   |-   |=   |\  |Esc | Ins |
 * |---------------------------------------------------------------------|
 * |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  | ]  |    BSpc| PgUp|
 * |---------------------------------------------------------------------|
 * |LCTRL |A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |  Enter    | PgDn |
 * |---------------------------------------------------------------------|
 * |Shft    |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/   |   Shift | Up |Del |
 * |---------------------------------------------------------------------|
 * |Ctrl|GUI |Alt |     Space                    |Alt| Ctrl|▓|Lt |Dn |Rt |
 * `---------------------------------------------------------------------|'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_65_ansi_blocker_doublebs(
        TICK_ESC, KC_1,   KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0, KC_MINS, KC_EQL,  KC_BSLS, KC_GRV, LT(_ADJUST,KC_DEL),
        KC_TAB, KC_Q,   KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, KC_LBRC, KC_RBRC, KC_BSPC, KC_PGUP,

        LCTL_T(KC_ESC), KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN,  KC_QUOT,    KC_ENT, KC_PGDN,
        KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M, KC_COMM, KC_DOT,KC_SLSH,         KC_RSFT, KC_UP, KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                 LT(_FL,KC_SPC),                      KC_RALT, KC_RCTRL, KC_LEFT, KC_DOWN,KC_RGHT),

    [OSX] = LAYOUT_65_ansi_blocker_doublebs(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_LALT, KC_LGUI,                  _______,                             KC_LGUI, KC_RALT, _______, _______, _______),

    [_FL] = LAYOUT_65_ansi_blocker_doublebs(
        KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12, KC_F13 , KC_DEL, MO(_ADJUST),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______, _______, _______,                  _______,                             _______,   _______, _______, _______,_______),

    [_ADJUST] = LAYOUT_65_ansi_blocker_doublebs(
        RESET,   LAY_LIN, LAY_OSX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(_ADJUST),
        BL_TOGG, BL_DEC, BL_INC, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAI, _______,
        _______, _______, _______,                  _______,                             _______, _______, RGB_MOD, RGB_VAD, RGB_HUD),


};


// clang-format on
static bool tick_esc_was_shifted = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* layout switcher */
        case LAY_LIN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(BASE);
            }
            return false;
            break;
        case LAY_OSX:
            if (record->event.pressed) {
                set_single_persistent_default_layer(OSX);
            }
            return false;
            break;
        case TICK_ESC: {
            uint8_t guied = get_mods() & (MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI));

            if (record->event.pressed) {
                tick_esc_was_shifted = guied;
                add_key(guied ? KC_ESCAPE : KC_GRAVE);
            } else {
                del_key(tick_esc_was_shifted ? KC_ESCAPE : KC_GRAVE);
            }

            send_keyboard_report();
            return false;
        }
    }
    return true;
}

