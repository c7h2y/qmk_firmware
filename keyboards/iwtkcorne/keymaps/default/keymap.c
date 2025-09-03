// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _MAIN,
    _LOW,
    _UP,
    _RGB,
    WIN,
    NAV
};

#define SPC_SFT LSFT_T(KC_SPC)
#define ENT_UP LT(_UP, KC_ENT)
#define HRM_DOT LT(WIN, KC_DOT)
#define BSP_CTL LCTL_T(KC_BSPC)
#define GUI_CTL LCTL_T(KC_LGUI)
#define ALT_LCS LCS_T(KC_LGUI)
#define one_LSFL LSFT_T(KC_1)
#define two_LCTL LCTL_T(KC_2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_TAB,     KC_ESC,     KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LALT,    KC_RALT,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  HRM_DOT, KC_SLSH,  KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          GUI_CTL, SPC_SFT, MO(_LOW),   BSP_CTL,  ENT_UP,  KC_ENT
                                      //`--------------------------'  `--------------------------'

  ),

  [_UP] = LAYOUT(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, KC_PAST, KC_9,   KC_8,   KC_7,    KC_BSLS, _______,    _______, KC_NUBS, KC_HOME,  KC_UP,   KC_END,  XXXXXXX, KC_PGUP,
  //|--------+--------+-------+--------+-----------+--------+--------|  |--------+----------------+--------+--------++--------+--------|
      _______, KC_0,    KC_3,two_LCTL, one_LSFL, KC_PLUS, _______,    _______, KC_EQL,  KC_LEFT, KC_DOWN, KC_RIGHT, _______, KC_PGDN,
  //|--------+--------+-------+ -------+-----------+--------+--------'  `--------+----------------+--------+--------++--------+--------|
      _______, KC_0,    KC_6,   KC_5,   KC_4,    KC_MINS,                      XXXXXXX, XXXXXXX, _______, _______,  _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, MO(_RGB),MO(_RGB),     _______, _______,_______
                                      //`--------------------------'  `--------------------------'
  ), 
  [NAV] = LAYOUT(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, KC_PAST, KC_9,   KC_8,   KC_7,    KC_BSLS, _______,    _______, KC_NUBS, KC_HOME,  KC_UP,   KC_END,  XXXXXXX, KC_PGUP,
  //|--------+--------+-------+--------+-----------+--------+--------|  |--------+----------------+--------+--------++--------+--------|
      _______, KC_0,    KC_3,   KC_2,   KC_1,    KC_PLUS, _______,    _______, KC_EQL,  KC_LEFT, KC_DOWN, KC_RIGHT, _______, KC_PGDN,
  //|--------+--------+-------+ -------+-----------+--------+--------'  `--------+----------------+--------+--------++--------+--------|
      _______, KC_0,    KC_6,   KC_5,   KC_4,    KC_MINS,                      XXXXXXX, XXXXXXX, _______, _______,  _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______,_______
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOW] = LAYOUT(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______,    _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, MO(_RGB), _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RGB] = LAYOUT(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      QK_BOOT, KC_F12,   KC_F9,   KC_F8,   KC_F7,   XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F10,   KC_F3,   KC_F2,   KC_F1,   XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+ -------+ -------+ -------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F11,   KC_F6,   KC_F5,   KC_F4,   XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  [WIN] = LAYOUT(  // Window management layer.
        XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, G(KC_3), G(KC_2), G(KC_1), G(KC_D),XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, XXXXXXX, KC_LALT, XXXXXXX,
        XXXXXXX, XXXXXXX, G(KC_6), G(KC_5), G(KC_4), G(KC_W),                     XXXXXXX, S(A(KC_TAB)), A(KC_TAB), XXXXXXX, XXXXXXX, G(KC_ENT),
                                         _______, KC_MPLY, G(KC_SPC),    _______, _______, _______
  )
};

const uint16_t ctrl_c_combo[] PROGMEM = {SPC_SFT, KC_C, COMBO_END};
const uint16_t ctrl_v_combo[] PROGMEM = {SPC_SFT, KC_V, COMBO_END};
const uint16_t ctrl_x_combo[] PROGMEM = {SPC_SFT, KC_X, COMBO_END};
const uint16_t ctrl_z_combo[] PROGMEM = {SPC_SFT, KC_Z, COMBO_END};
const uint16_t ctrl_a_combo[] PROGMEM = {SPC_SFT, KC_A, COMBO_END};
const uint16_t ctrl_s_combo[] PROGMEM = {SPC_SFT, KC_S, COMBO_END};

combo_t key_combos[] = {
    COMBO(ctrl_c_combo, LCTL(KC_C)),
    COMBO(ctrl_v_combo, LCTL(KC_V)),
    COMBO(ctrl_x_combo, LCTL(KC_X)),
    COMBO(ctrl_z_combo, LCTL(KC_Z)),
    COMBO(ctrl_a_combo, LCTL(KC_A)),
    COMBO(ctrl_s_combo, LCTL(KC_S)),
};