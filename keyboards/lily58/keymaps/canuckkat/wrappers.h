/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2021 Kat Wong aka canuckkat (@canuckkat) <rambaldi.kat.47@gmail.com>
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

#pragma once
// #include "canuckkat.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

#if (!defined(LAYOUT) && defined(KEYMAP))
#define LAYOUT KEYMAP
#endif

// #define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
/* The keycodes in the base section correspond to the keycodes in the wrapper section. */
#define LAYOUT_lily58_base( \
        K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
        K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
        K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A,  \
        K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A  \
    ) \
    LAYOUT_wrapper( \
        KC_ESC,  K01, K02, K03, K04, K05,                    K06, K07, K08, K09, K0A, KC_BSPC,  \
        KC_TAB,  K11, K12, K13, K14, K15,                    K16, K17, K18, K19, K1A, KC_BSLS, \
        KC_LCTL, K21, K22, K23, K24, K25,                    K26, K27, K28, K29, K2A, KC_QUOT, \
        KC_LSFT, K31, K32, K33, K34, K35, KC_LBRC,  KC_RBRC, K36, K37, K38, K39, K3A, KC_RSFT, \
            KC_LEAD, KC_LALT, MO(_LOWER), KC_SPC,   KC_ENT,  MO(_RAISE), KC_BSPC, KC_RGUI           \
    )
/* Re-pass though to allow templates to be used */
#define LAYOUT_lily58_base_wrapper(...) LAYOUT_lily58_base(__VA_ARGS__)


/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/
// clang-format off
#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define ________________FUNC_LEFT_5________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define ________________FUNC_LEFT_6________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6
#define ________________FUNC_RIGHT_5_______________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define ________________FUNC_RIGHT_6_______________       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12

#define __________________BLANK_4__________________        _______, _______,    _______,    _______
#define __________________BLANK_5__________________        _______, _______,    _______,    _______, _______
#define __________________BLANK_6__________________        _______, _______,    _______,    _______, _______, _______
#define ________________THUMB_LEFT_________________        KC_LALT, KC_LGUI,    MO(_LOWER), KC_SPC
#define ________________THUMB_RIGHT________________        KC_ENT,  MO(_RAISE), KC_RGUI,    KC_BSPC


#define _________________LOWER_L1__________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________        _________________FUNC_LEFT_________________
#define _________________LOWER_L3__________________        _________________FUNC_RIGHT________________

#define _________________LOWER_R1__________________        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________LOWER_R2__________________        _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR
#define _________________LOWER_R3__________________        _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END



#define _________________RAISE_L1__________________        ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________        ___________________BLANK___________________
#define _________________RAISE_L3__________________        ___________________BLANK___________________

#define _________________RAISE_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT



#define _________________ADJUST_L1_________________        RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG
#define _________________ADJUST_L2_________________        MU_TOG , CK_TOGG, AU_ON,   AU_OFF,  CG_NORM
#define _________________ADJUST_L3_________________        RGB_RMOD,RGB_HUD,RGB_SAD, RGB_VAD, KC_RGB_T

#define _________________ADJUST_R1_________________        KC_SEC1, KC_SEC2, KC_SEC3, KC_SEC4, KC_SEC5
#define _________________ADJUST_R2_________________        CG_SWAP, QWERTY,  COLEMAK, DVORAK,  WORKMAN
#define _________________ADJUST_R3_________________        MG_NKRO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT

#define ______________LOL_NUMBER_LEFT______________       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4
#define _________________LOL_CAMS__________________       KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_F5
// clang-format on
