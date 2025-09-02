// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum layer_names {
    _BASE,
    _RAISE,
    _LOWER
};

/* Base (qwerty)
* wired connection                                                     wired connection
* +-----0----------------------------------5--+                         +------0---------------------------------5--+
* | config location                                                     | config location                       
* | +---0----------------------------------5--+                         | +---11--------------------------------16--+
*0|0| ESC  |   q  |   w  |   e  |   r  |   t  |                        5|0|   y  |   u  |   i  |   o  |   p  |      |
* | |------+------+------+------+------+------|                         | |------+------+------+------+------+------|
* | | TAB  |   a  |   s  |   d  |   f  |   g  |                         | |   h  |   j  |   k  |   l  |   ;  |      |
* | |------+------+------+------+------+------|                         | |------+------+------+------+------+------|
* | | SHFT |   z  |   x  |   c  |   v  |   b  |                         | |   n  |   m  |   ,  |   .  |   /  |      |
* | +------+------+------+------+-------------+                         | +-------------+------+------+------+------+
* | |                    |      |      |      |                         | |      |      |      |
* | |                    |------+------+------|                         | |------+------+------|
*4|4|                           |      |      |                        9|4|      |      |
* | |                           +-------------+                         | +-------------+
* | |               left                                                                        right
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                   KC_SPC,  RAISE,   KC_HOME,             KC_END,  LOWER,   KC_ENT,
                                            KC_BSPC, KC_LALT,             KC_LGUI, KC_DEL
    ),

    [_LOWER] = LAYOUT(
        _______, _______, _______, _______, _______, KC_LBRC,             KC_RBRC, KC_P7,   KC_P8,   KC_P9,   QK_BOOT, KC_PLUS,
        _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_LPRN,             KC_RPRN, KC_P4,   KC_P5,   KC_P6,   KC_MINS, KC_PIPE,
        _______, _______, _______, _______, _______, _______,             _______, KC_P1,   KC_P2,   KC_P3,   KC_EQL,  KC_UNDS,
                                  _______, _______,  _______,             _______, _______, _______,
                                            _______, _______,             _______, _______
    ),

    [_RAISE] = LAYOUT(
        _______, QK_BOOT, _______, _______, _______, KC_LBRC,             KC_RBRC, _______, KC_NUM,  KC_INS,  KC_SCRL, KC_MUTE,
        _______, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_LPRN,             KC_RPRN, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, KC_VOLD,
                                   _______, _______, _______,             _______, _______, _______,
                                            _______, _______,             _______, _______
    )
};