 /* Copyright 2021 OpenAnnePro community
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

enum anne_pro_layers {
    BASE,
    FN1,
    FN2,
    FN3,
    FN4,
};

// clang-format off
// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer BASE
* ,-----------------------------------------------------------------------------------------.
* | esc |  1! | 2@  | 3#  | 4$  | 5%  | 6^  | 7&  | 8*  | 9(  | 0)  | -_  | =+  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* |  Tab   |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  | [{  | ]}  |   \|   |
* |-----------------------------------------------------------------------------------------+
* |   FN4   |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  | ;:  | '"  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* |   LShift   |  z  |  x  |  c  |  v  |  b  |  n  |  m  | ,<  | .>  | /?  |     RShift     |
* |-----------------------------------------------------------------------------------------+
* | LCtrl |  L1   | LAlt  |               space             | RAlt  |  FN1  |  FN2  | RCtrl |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in BASE
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |  SCRL   |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |                |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |       |       |       |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [BASE] = LAYOUT_60_ansi( /* Base */
    KC_ESC,           KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8, KC_9,    KC_0,             KC_MINS,          KC_EQL,        KC_BSPC,
    KC_TAB,           KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,   KC_U, KC_I, KC_O,    KC_P,             KC_LBRC,          KC_RBRC,       KC_BSLS,
    LT(FN4, KC_SCRL), KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K, KC_L,    KC_SCLN,          KC_QUOT,          KC_ENT,
    KC_LSFT,                   KC_Z,    KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT,           KC_SLSH,          KC_RSFT,
    KC_LCTL,       KC_LGUI, KC_LALT,                    KC_SPC,               KC_RALT, MO(FN1),          MO(FN2),          KC_RCTL
),
  /*
  * Layer FN1
  * ,-----------------------------------------------------------------------------------------.
  * |  `~ |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |    F13    |
  * |-----------------------------------------------------------------------------------------+
  * |        |     | UP  |     |     |     |     |     |     |PAUSE| PS | HOME | END |        |
  * |-----------------------------------------------------------------------------------------+
  * |   CAPS  |LEFT |DOWN |RIGHT|     |     |     |     |     |SYRQ |PGUP |PGDN |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |MENU |INSRT| DEL |                |
  * |-----------------------------------------------------------------------------------------+
  * |  FN3  |       |       |            KEY_LOCK             |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN1] = LAYOUT_60_ansi( /* FN1 */
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,
    _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, KC_PAUS, KC_PSCR, KC_HOME, KC_END,  _______,
    KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, KC_SYRQ, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  KC_APP, KC_INS,  KC_DEL,  _______,
    TG(FN3), _______, _______,                            KC_LOCK,                   _______, _______, _______, _______
),
  /*
  * Layer FN2
  * ,-----------------------------------------------------------------------------------------.
  * |     | BT1 | BT2 | BT3 | BT4 |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        | B-UP |V-UP |V-DWN|MUTE |    |     |     |     |     |    |      |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |B-DOWN|V-NEXT|V-PREV|V-PAUSE|V-STOP|     |     |     |     |     |     |       |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN2] = LAYOUT_60_ansi( /* FN2 */
    _______, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,    KC_BRIU, KC_VOLU,    KC_VOLD,    KC_MUTE,    _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,    KC_BRID, KC_MNXT,    KC_MPRV,    KC_MPLY,    KC_MSTP, _______, _______, _______, _______, _______, _______, _______,
    _______,             _______,    _______,    _______,    _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,    _______,                                     _______,                   _______, _______, _______, _______
 ),
  /*
  * Layer FN3
  * ,-----------------------------------------------------------------------------------------.
  * |     |MWHL0|MWHL1|MWHL2|     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |MWHLU |     |     |    |     |     |     |     |    |      |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |MWHLL|MWHLD|MWHLR|     |     |MCRSL|MCRSD|MCRSU|MCRSR|     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |MBTN3|MBTN1|MBTN2|     |     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |  FN3  |       |       |                                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN3] = LAYOUT_60_ansi( /* FN3 */
    _______, KC_ACL0,    KC_ACL1,    KC_ACL2,    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,    KC_WH_U,    _______,    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_WH_L,    KC_WH_D,    KC_WH_R,    _______,    _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______,
    _______,             KC_BTN3,    KC_BTN1,    KC_BTN2,    _______, _______, _______, _______, _______, _______, _______, _______,
    TG(FN3), _______,    _______,                                     _______,                   _______, _______, _______, _______
 ),
  /*
  * Layer FN4
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |BOOTLOADER |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |      |     |     |    |     |     |     |     |    |      |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |     |     |     |     |     |     |     |     |     |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN4] = LAYOUT_60_ansi( /* FN4 */
    _______, _______,    _______,    _______,    _______,    _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
    _______, _______,    _______,    _______,    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,    _______,    _______,    _______,    _______, _______, _______, _______, _______, _______, _______, _______,
    _______,             _______,    _______,    _______,    _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,    _______,                                     _______,                   _______, _______, _______, _______
 ),
};
// clang-format on
