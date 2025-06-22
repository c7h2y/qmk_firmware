// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


enum layer_names {
    BASE,
    CODE,
    SYM,
    NAV,
    NUM,
    WIN,
    FUN,
    EXT
};

// // The "magic" key is the Alternate Repeat Key.
// #define MAGIC QK_AREP
// // F20 mutes the mic on my system.
// #define MUTEMIC KC_F20

// Short aliases for home row mods and other tap-hold keys.
#define HRM_A LALT_T(KC_A)
#define HRM_S LT(SYM, KC_S)
#define HRM_D LSFT_T(KC_D)
#define HRM_F LT(NAV, KC_F)
#define HRM_Z LGUI_T(KC_Z)
#define HRM_V LCTL_T(KC_V)

#define HRM_J LT(NUM, KC_J)
#define HRM_K RSFT_T(KC_K)
#define HRM_L LT(SYM, KC_L)
#define HRM_GUT LALT_T(G(KC_TAB))
#define HRM_M RCTL_T(KC_M)
#define HRM_DOT LT(WIN, KC_DOT)
#define HRM_QUO RGUI_T(KC_QUOT)

#define EXT_COL LT(EXT, KC_SCLN)
#define NAV_SLS LSFT_T(KC_SLSH)
#define NAV_EQL LT(0, KC_EQL)


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
    [BASE] = LAYOUT(  // Base layer.
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,            KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_SLSH,
        KC_HOME, HRM_A  , HRM_S  , HRM_D  , HRM_F  , KC_Y   ,            KC_H   , HRM_J  , HRM_K  , HRM_L  , HRM_GUT, KC_MINS,
        EXT_COL, HRM_Z  , KC_X   , KC_C   , HRM_V  , KC_B   ,            KC_N   , HRM_M  , KC_COMM, HRM_DOT, HRM_QUO, KC_END ,
                                   C(KC_V), C(KC_A), KC_SPC ,            KC_LEFT, KC_RGHT, KC_ENT ,
                                            KC_UNDS, C(KC_C),            KC_BSPC, KC_ESC
    ),

    [SYM] = LAYOUT(
        _______, KC_GRV , KC_LABK, KC_RABK, KC_MINS, KC_PIPE,            KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR , _______, _______,
        _______, KC_EXLM, KC_ASTR, NAV_SLS, NAV_EQL, KC_AMPR,            KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQUO, _______,
        _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,            KC_AT  , KC_COLN, KC_COMM, KC_DOT , KC_QUOT, _______,
                                   _______, _______, _______,            _______, _______, QK_LLCK,
                                            QK_BOOT, _______,            _______, QK_BOOT
    ),

    [NAV] = LAYOUT(  // Navigation layer.
    _______,KC_WREF, C(KC_PGUP), C(KC_PGDN), XXXXXXX, XXXXXXX,           KC_PGUP, KC_HOME, KC_UP  , KC_END , XXXXXXX, _______, 
    _______,KC_LALT, KC_LCTL   , KC_LSFT   , XXXXXXX, XXXXXXX,           KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL , _______, 
    _______,KC_LGUI, KC_PGUP   , KC_PGDN   , XXXXXXX, XXXXXXX,           C(KC_Z), XXXXXXX, XXXXXXX, KC_APP , XXXXXXX, _______, 
                                   _______, _______, _______,            _______, _______, QK_LLCK,
                                            _______, _______,            _______, _______
    ),

    [NUM] = LAYOUT(  // Number layer.
        _______, KC_SLSH, KC_9   , KC_8   , KC_7   , KC_ASTR,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, KC_MINS, KC_3   , KC_2   , KC_1   , KC_PLUS,            XXXXXXX, XXXXXXX, KC_E   , KC_RCTL, KC_LALT, _______,
        _______, KC_X   , KC_6   , KC_5   , KC_4   , KC_PERC,            XXXXXXX, XXXXXXX, KC_COMM, KC_DOT , KC_LGUI, _______,
                                   _______, _______, _______,            _______, KC_0   , QK_LLCK,
                                            _______, _______,            _______, _______
    ),

    [WIN] = LAYOUT(  // Window management layer.
        XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, G(KC_3), G(KC_2), G(KC_1), G(KC_D),            XXXXXXX, XXXXXXX, KC_RSFT, XXXXXXX, KC_LALT, XXXXXXX,
        XXXXXXX, XXXXXXX, G(KC_6), G(KC_5), G(KC_4), G(KC_W),            XXXXXXX, S(A(KC_TAB)), A(KC_TAB), XXXXXXX, XXXXXXX, G(KC_ENT),
                                   _______, KC_MPLY, G(KC_SPC),          _______, _______, QK_LLCK,
                                            _______, _______,            _______, _______
    ),

    [FUN] = LAYOUT(  // Funky fun layer.
    XXXXXXX, KC_F12 , KC_F9  , KC_F8  , KC_F7  , XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    XXXXXXX, KC_F10 , KC_F3  , KC_F2  , KC_F1  , XXXXXXX,               XXXXXXX, XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, XXXXXXX,
    XXXXXXX, KC_F11 , KC_F6  , KC_F5  , KC_F4  , XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RGUI, QK_RBT ,
                                   _______, _______,_______,          _______, _______, QK_LLCK,
                                            _______, _______,            _______, _______
    ),

    [EXT] = LAYOUT(  // Funky fun layer.
    XXXXXXX, KC_F12 , KC_F9  , KC_F8  , KC_F7  , XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    XXXXXXX, KC_F10 , KC_F3  , KC_F2  , KC_F1  , XXXXXXX,               XXXXXXX, XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, XXXXXXX,
    XXXXXXX, KC_F11 , KC_F6  , KC_F5  , KC_F4  , XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RGUI, QK_RBT ,
                                   _______, _______, _______,          _______, _______, QK_LLCK,
                                            _______, _______,            _______, _______
    )

    // [_LOWER] = LAYOUT(
    //     _______, _______, _______, _______, _______, _______,             _______, _______, _______,  _______, _______, QK_BOOT,
    //     KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,               KC_P7,   KC_P8,   KC_P9,    KC_P0,   _______, _______,
    //     KC_NUM,  _______, KC_GRAVE,KC_PIPE, KC_PPLS, KC_MINS,             KC_EQL,  KC_AMPR, KC_UNDS,  KC_HASH, _______, _______,
    //                               _______,  MO(_TEST),KC_LSFT,            _______, _______, KC_RSFT,
    //                                         KC_DEL, KC_LALT,              _______, _______
    // ),
    // [_RAISE] = LAYOUT(
    //     _______, QK_BOOT, _______, _______, KC_LPRN, KC_LBRC,             KC_RBRC, KC_RPRN, KC_NUM,  KC_INS,  KC_SCRL, QK_BOOT,
    //     _______, KC_LEFT, KC_UP  , KC_DOWN, C(KC_C), C(KC_V),             KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, _______, KC_VOLU,
    //     _______, _______, _______, _______, _______, _______,             LGUI(KC_LEFT),LGUI(KC_UP),LGUI(KC_DOWN),LGUI(KC_RGHT),_______, KC_VOLD,
    //                                _______, _______, KC_LCTL,             KC_HOME, KC_END,  KC_DEL,
    //                                         KC_LCTL, _______,             KC_PGUP, KC_PGDN
    // ),
    
    // [_TEST] = LAYOUT(
    //     _______, QK_BOOT, _______, _______, _______, KC_LBRC,             KC_RBRC, _______, KC_NUM,  KC_INS,  KC_SCRL, KC_MUTE,
    //     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5 ,  KC_F6  ,             KC_F7  , KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    //     _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, KC_VOLD,
    //                                _______, _______, KC_LCTL,             KC_RSFT,KC_TAB,KC_LALT, 
    //                                         _______, _______,             LCA(KC_T),_______ 
    // ),
    // [_CODE] = LAYOUT(
    //   //open side     open bot  sfile       sfuncla   split     closewin               multwordedt  dupline      
    //     LCTL(KC_B),LCTL(KC_GRV),LCTL(KC_P),KC_AT,LCTL(KC_BSLS),LCTL(KC_W),             RCS(KC_L), MEH(KC_DOWN), _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
    //   // 
    //     _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
    //   // 
    //                                _______, _______, _______,             _______, _______, _______,
    //   // 
    //                                         _______, _______,             _______, _______
    // )
};