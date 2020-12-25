/* Copyright 2019 MechMerlin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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

#define LAYOUT_65_ansi_blocker_split_bs( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F, \
    k10,      k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E, k1F, \
    k20,      k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D,      k2F, \
    k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3D,      k3E, k3F, \
    k40, k41,      k43,                k47,           k4A, k4B,      k4D, k4E, k4F  \
) \
{ \
    { k00, k01,   k02,   k03, k04,   k05,   k06,   k07, k08,   k09,   k0A, k0B, k0C,   k0D,   k0E,   k0F }, \
    { k10, KC_NO, k12,   k13, k14,   k15,   k16,   k17, k18,   k19,   k1A, k1B, k1C,   k1D,   k1E,   k1F }, \
    { k20, KC_NO, k22,   k23, k24,   k25,   k26,   k27, k28,   k29,   k2A, k2B, k2C,   k2D,   KC_NO, k2F }, \
    { k30, KC_NO, k32,   k33, k34,   k35,   k36,   k37, k38,   k39,   k3A, k3B, KC_NO, k3D,   k3E,   k3F }, \
    { k40, k41,   KC_NO, k43, KC_NO, KC_NO, KC_NO, k47, KC_NO, KC_NO, k4A, k4B, KC_NO, k4D,   k4E,   k4F }, \
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_65_ansi_blocker_split_bs(
        TICK_ESC, KC_1,   KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0, KC_MINS, KC_EQL,  KC_BSLS, KC_GRV, LT(_ADJUST,KC_DEL),
        KC_TAB, KC_Q,   KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, KC_LBRC, KC_RBRC, KC_BSPC, KC_END,

        LCTL_T(KC_ESC), KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN,  KC_QUOT, KC_ENT, KC_PGUP,
        KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M, KC_COMM, KC_DOT,KC_SLSH,         KC_RSFT, KC_UP, KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                 LT(_FL,KC_SPC),                      KC_RALT, KC_RCTRL, KC_LEFT, KC_DOWN, KC_RGHT),

    [OSX] = LAYOUT_65_ansi_blocker_split_bs(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_LALT, KC_LGUI,                  _______,                             KC_LGUI, KC_RALT, _______,_______, _______),

    [_FL] = LAYOUT_65_ansi_blocker_split_bs(
        KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12, KC_F13 , KC_DEL, MO(_ADJUST),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______,
        _______, _______, _______,                  _______,                             _______,   _______, _______, _______, _______),

    [_ADJUST] = LAYOUT_65_ansi_blocker_split_bs(
        RESET,   LAY_LIN, LAY_OSX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(_ADJUST),
        BL_TOGG, BL_DEC, BL_INC, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAI, _______,
        _______, _______, _______,                  _______,                             _______, _______, RGB_MOD, RGB_VAD, RGB_HUD),


};

// clang-format on
static bool tick_esc_was_shifted = false;

extern rgblight_config_t rgblight_config;

bool     edit = false;
rgblight_config_t temp_config;

void keyboard_post_init_user(void) { temp_config.raw = rgblight_config.raw; }

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
        case BL_TOGG: {
            if (record->event.pressed) {
                if (!is_backlight_enabled()) {
                    writePinLow(B6);
                } else {
                    writePinHigh(B6);
                }
                return false;
            }
            break;
        }
        case RGB_MOD:
            // allows to set the rgb mode while in the ADJUST layer which uses
            // its own mode
            if (record->event.pressed) {
                rgblight_mode(temp_config.mode);
                rgblight_step();
                temp_config.mode = rgblight_config.mode;
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

uint32_t layer_state_set_user(uint32_t state) {
    if (state == BASE && edit == true) {
        temp_config.hue  = rgblight_get_hue();
        temp_config.sat  = rgblight_get_sat();
        temp_config.val  = rgblight_get_val();
        edit = false;
    }

    switch (biton32(state)) {
        case _ADJUST:
            temp_config.mode = rgblight_get_mode();
            rgblight_mode_noeeprom(1);
            rgblight_setrgb(0xD3, 0x7F, 0xED);
            edit = true;
            break;
        default:
            rgblight_mode(temp_config.mode);
            rgblight_sethsv(temp_config.hue, temp_config.sat, temp_config.val);
            break;
    }
    return state;
}
