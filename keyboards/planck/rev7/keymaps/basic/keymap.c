/* Copyright 2015-2023 Jack Humbert
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
#include "unicode-french-accents.h"

enum planck_layers { _QWERTY, _ERGOL, _DVORAK, _LOWER, _RAISE, _ADJUST, _NAVIM, _ACCENTS };

#define QWERTY PDF(_QWERTY)
#define DVORAK PDF(_DVORAK)
#define ERGOL PDF(_ERGOL)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ACCENTS LT(_ACCENTS, KC_RCTL)

#define RSE_COMP LT(_RAISE, KC_RCTL) // RControl is my compose key
#define SPC_NAV LT(_NAVIM, KC_SPC)
#define CTL_ESC LCTL_T(KC_ESC)
#define SFT_RALT LSFT(KC_RALT)

// QWERTY
// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

// Right-hand home row mods
#define CTL_J LCTL_T(KC_J) // RCTL is Compose, use LCTL to get Control
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN LGUI_T(KC_SCLN)

// Dvorak
// Left-hand home row mods
//#define GUI_A LGUI_T(KC_A)
#define ALT_O LALT_T(KC_O) // RCTL is Compose, use LCTL to get Control
#define SFT_E LSFT_T(KC_E)
#define CTL_U LCTL_T(KC_U)

// Right-hand home row mods
#define CTL_H LCTL_T(KC_H)
#define SHFT_T RSFT_T(KC_T)
#define ALT_N LALT_T(KC_N)
#define GUI_S LGUI_T(KC_S)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |Accnts|Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_ESC, GUI_A,   ALT_S,   SFT_D,   CTL_F,   KC_G,    KC_H,    CTL_J,   SFT_K,   ALT_L,   GUI_SCLN,KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LGUI, KC_LALT, ACCENTS, LOWER,   KC_RSFT, SPC_NAV, RSE_COMP,KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_ERGOL] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, RAISE,   _______, _______, _______, KC_RALT, _______, _______, _______, _______
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |Accnts|Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    CTL_ESC, GUI_A,   ALT_O,   SFT_E,   CTL_U,   KC_I,    KC_D,    CTL_H,   SHFT_T,  ALT_N,   GUI_S,   KC_SLSH,
    KC_LSFT, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
    KC_LCTL, KC_LGUI, KC_LALT, ACCENTS, LOWER,   KC_RSFT, SPC_NAV, RSE_COMP,KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   .  |   ,  |   €  |   $  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |Raise | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_DOT,  KC_COMM, EURO,    KC_DLR,  KC_PIPE,
    CW_TOGG, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, RAISE,   KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise/Symbols (this is the RALT Ergo-L layer - instead of having it done through
 * an OS keyboard layout, I prefer to have this mapped on the 'raise' key)
 *
 * Update: Will use OS-level keymaps instead as they are a lot more flexible
 * (eg altgr + shift gives dead keys for intl accents)
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   ^  |   <  |   >  |   $  |   %  |   @  |   &  |   *  |   '  |   `  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   {  |   (  |   )  |   }  |   =  |   \  |   +  |   -  |   /  |   "  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ~  |   [  |   ]  |   _  |   #  |   |  |   !  |   ;  |   :  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_CIRC, KC_LT,   KC_GT,   KC_DLR,  KC_PERC, KC_AT,   KC_AMPR, KC_ASTR, KC_QUOT, KC_GRV,  KC_BSPC,
    _______, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_EQL,  KC_BSLS, KC_PLUS, KC_MINS, KC_SLSH, KC_DQT,  _______,
    SFT_RALT,KC_TILD, KC_LBRC, KC_RBRC, KC_UNDS, KC_HASH, KC_PIPE, KC_EXLM, KC_SCLN, KC_COLN, KC_QUES, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|      |      |Qwerty|      |Dvorak|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|      |      |UniPrv|UniNxt|UniLnx|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_SPDU, UG_SPDD, KC_DEL ,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  _______, _______, QWERTY,  ERGOL,   DVORAK,  _______, _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  _______, _______, UC_PREV, UC_NEXT, UC_LINX, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Navigation/vim layer
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   $  |   7  |   8  |   9  |   €  | Home | PgDn | PgUp | End  | Del  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   0  |   4  |   5  |   6  |   0  | Left | Down |  Up  |Right | Bksp |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ,  |   1  |   2  |   3  |   .  | Home | PgDn | PgUp | End  | Del  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift| Ctrl | Alt  | GUI  |Lower |    Space    |LLock | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVIM] = LAYOUT_planck_grid(
    KC_GRV,  KC_DLR,  KC_7,    KC_8,    KC_9,  EURO,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,  KC_BSPC,
    KC_ESC,  KC_0,    KC_4,    KC_5,    KC_6,  KC_0,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, KC_QUOT,
    KC_LSFT, KC_COMM, KC_1,    KC_2,    KC_3,  KC_DOT,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,  KC_ENT ,
    KC_RSFT, KC_LCTL, KC_LALT, KC_LGUI, LOWER, XXXXXXX, KC_SPC,  QK_LLCK, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Accents (this is the * Ergo-L layer)
 * Will use OS-level keymaps instead as they are a lot more flexible (eg ** presses)
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   â  |   ç  |   œ  |      |      |      |   µ  |   _  |   ¨  |   û  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   à  |   é  |   è  |   ê  |      |   (  |   )  |   î  |   ï  |   ù  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   æ  |   ß  |   ‑  |   –  |      |   …  |      |      |   .  |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_ACCENTS] = LAYOUT_planck_grid(
    _______, A_CIRC, C_CEDI, OE,     XXXXXXX,XXXXXXX, XXXXXXX, MU,      KC_UNDS,KC_QUOT, U_CIRC, KC_BSPC,
    _______, A_GRAV, E_ACUT, E_GRAV, E_CIRC, XXXXXXX, KC_LPRN, KC_RPRN, I_CIRC, I_DIAE,  U_GRAV, KC_BSLS,
    _______, AE,     SHARP_S,KC_MINS,LNGDASH,XXXXXXX, THRDOTS, XXXXXXX, XXXXXXX, KC_DOT, XXXXXXX, KC_ENT,
    _______, _______,_______,_______,_______,_______, _______, _______, _______, _______,_______, _______
)

};

/* clang-format on */

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

/*
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
*/

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}
