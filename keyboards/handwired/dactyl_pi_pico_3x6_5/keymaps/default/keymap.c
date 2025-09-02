// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#undef COMBO_TERM
#define COMBO_TERM 50

enum layer_names {
    BASE,
    CODE,
    SYM,
    NAV,
    NUM,
    WIN,
    FUN,
    EXT,
    KANA,
    KANA_SHIFT,
    KANA_NUM,
    KANA_YOU
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
#define HRM_C LCTL_T(KC_C)
#define HRM_V LCTL_T(KC_V)

#define HRM_J LT(NUM, KC_J)
#define HRM_K RSFT_T(KC_K)
#define HRM_L LT(SYM, KC_L)
#define HRM_MIN LALT_T(KC_MINS)
#define HRM_M RCTL_T(KC_M)
#define HRM_DOT LT(WIN, KC_DOT)
#define HRM_QUO RGUI_T(KC_QUOT)
#define SPC_SFT LT(KANA_SHIFT, KC_SPC)

#define EXT_COL LT(EXT, KC_SCLN)
#define NAV_SLS LSFT_T(KC_SLSH)
#define NAV_EQL LT(0, KC_EQL)

enum custom_keycodes {
    ALT_TAB = SAFE_RANGE,
    TRNSLT,
    CLST,
    SRCH,
    
    JP_A,
    JP_I,
    JP_U,
    JP_E,
    JP_O,
    JP_KA,
    JP_KI,
    JP_KU,
    JP_KE,
    JP_KO,
    JP_SA,
    JP_SI,
    JP_SU,
    JP_SE,
    JP_SO,
    JP_TA,
    JP_TI,
    JP_TU,
    JP_TE,
    JP_TO,
    JP_NA,
    JP_NI,
    JP_NU,
    JP_NE,
    JP_NO,
    JP_HA,
    JP_HI,
    JP_HU,
    JP_HE,
    JP_HO,
    JP_MA,
    JP_MI,
    JP_MU,
    JP_ME,
    JP_MO,
    JP_YA,
    JP_YI,
    JP_YU,
    JP_YE,
    JP_YO,
    JP_RA,
    JP_RI,
    JP_RU,
    JP_RE,
    JP_RO,
    JP_WA,
    JP_WI,
    JP_WU,
    JP_WE,
    JP_WO,
    JP_NN,
    JP_GA,
    JP_GI,
    JP_GU,
    JP_GE,
    JP_GO,
    JP_ZA,
    JP_ZI,
    JP_ZU,
    JP_ZE,
    JP_ZO,
    JP_DA,
    JP_DI,
    JP_DU,
    JP_DE,
    JP_DO,
    JP_BA,
    JP_BI,
    JP_BU,
    JP_BE,
    JP_BO,
    JP_PA,
    JP_PI,
    JP_PU,
    JP_PE,
    JP_PO,
    JP_KYA,
    JP_KYU,
    JP_KYO,
    JP_GYA,
    JP_GYU,
    JP_GYO,
    JP_SYA,
    JP_SYU,
    JP_SYO,
    JP_JA,
    JP_JU,
    JP_JO,
    JP_TYA,
    JP_TYU,
    JP_TYO,
    JP_NYA,
    JP_NYU,
    JP_NYO,
    JP_HYA,
    JP_HYU,
    JP_HYO,
    JP_BYA,
    JP_BYU,
    JP_BYO,
    JP_PYA,
    JP_PYU,
    JP_PYO,
    JP_MYA,
    JP_MYU,
    JP_MYO,
    JP_RYA,
    JP_RYU,
    JP_RYO,
    JP_VA,
    JP_VI,
    JP_VU,
    JP_VE,
    JP_VO,
    JP_LTU,
    JP_LYA,
    JP_LYU,
    JP_LYO,
    JP_DYA,
    JP_DYU,
    JP_DYO,
    JP_TELI,
    JP_DELI,
    JP_TOLU,
    JP_DOLU,
    JP_TELYU,
    JP_DELYU,
    JP_SHE,
    JP_JE,
    JP_CHE,
    JP_DILE,
    JP_ULI,
    JP_VLI,
    JP_ULE,
    JP_VULE,
    JP_ULO,
    JP_VULO,
    JP_VULYU,
    JP_ILE,
    JP_TULA,
    JP_FA,
    JP_FI,
    JP_FE,
    JP_FO,
    JP_FLYU,
    JP_KULA,
    JP_GULA,
    JP_KULI,
    JP_GULI,
    JP_KULE,
    JP_GULE,
    JP_KULO,
    JP_GULO,
    JP_KULWA,
    JP_GULWA,

    JP_LA,
    JP_LI,
    JP_LU,
    JP_LE,
    JP_LO,
    JP_LWA,

    JP_KUTEN,
    JP_TOUTEN,
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
    [BASE] = LAYOUT(  // Base layer.
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,            KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_SLSH,
        EXT_COL, HRM_A  , HRM_S  , HRM_D  , HRM_F  , KC_G   ,            KC_H   , HRM_J  , HRM_K  , HRM_L  , HRM_MIN, ALT_TAB ,
        KC_HOME, HRM_Z  , KC_X   , HRM_C  , HRM_V  , KC_B   ,            KC_N   , HRM_M  , KC_COMM, HRM_DOT, HRM_QUO, KC_END ,
                                  KC_ENT , KC_SPC ,G(KC_SPC),            KC_BSPC, KC_ESC , KC_ENT ,
                                            KC_ESC ,TO(KANA),            TO(BASE),KC_GRV
    ),

    [KANA] = LAYOUT(  // Base layer.
        _______ , MO(KANA_YOU),JP_KI  , JP_TE  , JP_SI  , KC_DOWN,       KC_UP  , KC_BSPC, JP_RU  , JP_SU  , JP_HE  , _______,
        _______, JP_RO  , JP_KE  , JP_TO  , JP_KA  , JP_LTU ,            JP_KU  , JP_A   , JP_I   , JP_U   , KC_MINS, _______ ,
        _______, JP_HO  , JP_HI  , JP_HA  , JP_KO  , JP_SO  ,            JP_TA  , JP_NA  , JP_NN  , JP_RA  , JP_RE  , _______ ,
                                   MO(NAV), SPC_SFT ,_______,           _______, SPC_SFT , _______,
                                       MO(KANA_NUM), _______,           _______, MO(KANA_NUM)
    ),
    
    [KANA_SHIFT] = LAYOUT(
        _______ , MO(KANA_YOU), JP_NU  , JP_RI  , JP_ME  , KC_DOWN,      KC_UP  , JP_SA  , JP_YO  , JP_E   , JP_YU , _______,
        _______, JP_SE  , JP_MI  , JP_NI  , JP_MA  , JP_TI  ,            JP_YA  , JP_NO  , JP_MO  , JP_TU  , JP_HU  , _______,
        _______, JP_HO  , JP_HI   ,JP_WO  , JP_KUTEN,JP_MU  ,            JP_O   , JP_TOUTEN,JP_NE , JP_WA  , JP_RE  , _______ ,
                                   MO(NAV), _______, _______,            _______, _______, _______,
                                       MO(KANA_NUM), _______,            _______, MO(KANA_NUM)
    ),

    [KANA_YOU] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, JP_LYO , JP_LE  , JP_LYU , XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            JP_LYA , JP_LA  , JP_LI  , JP_LU  , XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            JP_LO  , XXXXXXX, XXXXXXX, JP_LWA , XXXXXXX, XXXXXXX,
                                   MO(NAV), _______, _______,            _______, _______, _______,
                                           MO(KANA_NUM), _______,            _______, MO(KANA_NUM)
    ),

    [KANA_NUM] = LAYOUT(  // Number layer.
        _______, KC_SLSH, KC_9   , KC_8   , KC_7   , KC_ASTR,            XXXXXXX, KC_7   , KC_8   , KC_9 , XXXXXXX, _______,
        _______, KC_MINS, KC_3   , KC_2   , KC_1   , KC_PLUS,            XXXXXXX, KC_4   , KC_5   , KC_6 , KC_LALT, _______,
        _______, KC_X   , KC_6   , KC_5   , KC_4   , KC_PERC,            KC_0   , KC_1   , KC_2   , KC_3 , KC_LGUI, _______,
                                   MO(NAV), _______, _______,            _______, _______, QK_LLCK,
                                            _______, _______,            _______, _______
    ),

    [SYM] = LAYOUT(
        _______, KC_GRV , KC_LABK, KC_RABK, KC_MINS, KC_PIPE,            KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR , _______, _______,
        _______, KC_EXLM, KC_ASTR, NAV_SLS, NAV_EQL, KC_AMPR,            KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQUO, _______,
        _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,            KC_AT  , KC_COLN, KC_COMM, KC_DOT , KC_QUOT, _______,
                                   _______, _______, KC_GRV ,            _______, _______, QK_LLCK,
                                            QK_BOOT, _______,            _______, QK_BOOT
    ),

    [NAV] = LAYOUT(  // Navigation layer.
    _______,KC_WREF, C(KC_PGUP), C(KC_PGDN), XXXXXXX, XXXXXXX,           KC_PGUP, KC_HOME, KC_UP  , KC_END , XXXXXXX, _______, 
    _______,KC_LALT, KC_LCTL   , KC_LSFT   , XXXXXXX, XXXXXXX,           KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL , _______, 
    _______,KC_LGUI, KC_PGUP   , KC_PGDN   , XXXXXXX, XXXXXXX,           C(KC_Z), XXXXXXX, XXXXXXX, KC_APP , XXXXXXX, _______, 
                                       TRNSLT,  SRCH,    CLST,           _______, _______, QK_LLCK,
                                           RCS(KC_T), _______,           _______, _______
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

const uint16_t caps_combo[] PROGMEM = {KC_C, KC_COMM, COMBO_END};
const uint16_t x_c_combo[] PROGMEM = {KC_X, KC_C, COMBO_END};
const uint16_t comm_dot_combo[] PROGMEM = {KC_COMM, HRM_DOT, COMBO_END};
const uint16_t h_j_combo[] PROGMEM = {KC_H, HRM_J, COMBO_END};

const uint16_t combo_ga      [] PROGMEM = {JP_A, JP_KA, COMBO_END};
const uint16_t combo_gi      [] PROGMEM = {JP_A, JP_KI, COMBO_END};
const uint16_t combo_gu      [] PROGMEM = {JP_A, JP_KU, COMBO_END};
const uint16_t combo_ge      [] PROGMEM = {JP_A, JP_KE, COMBO_END};
const uint16_t combo_go      [] PROGMEM = {JP_A, JP_KO, COMBO_END};
const uint16_t combo_gi_k    [] PROGMEM = {JP_KA, JP_KI, COMBO_END};
const uint16_t combo_gu_k    [] PROGMEM = {JP_KA, JP_KU, COMBO_END};
const uint16_t combo_ge_k    [] PROGMEM = {JP_KA, JP_KE, COMBO_END};
const uint16_t combo_go_k    [] PROGMEM = {JP_KA, JP_KO, COMBO_END};
const uint16_t combo_za      [] PROGMEM = {JP_NO, JP_SA, COMBO_END};
const uint16_t combo_zi      [] PROGMEM = {JP_A, JP_SI, COMBO_END};
const uint16_t combo_zu      [] PROGMEM = {JP_A, JP_SU, COMBO_END};
const uint16_t combo_ze      [] PROGMEM = {JP_NO, JP_SE, COMBO_END};
const uint16_t combo_zo      [] PROGMEM = {JP_A, JP_SO, COMBO_END};
const uint16_t combo_za_k    [] PROGMEM = {JP_MA, JP_SA, COMBO_END};
const uint16_t combo_zi_k    [] PROGMEM = {JP_KA, JP_SI, COMBO_END};
const uint16_t combo_zu_k    [] PROGMEM = {JP_KA, JP_SU, COMBO_END};
const uint16_t combo_ze_k    [] PROGMEM = {JP_MA, JP_SE, COMBO_END};
const uint16_t combo_zo_k    [] PROGMEM = {JP_KA, JP_SO, COMBO_END};
const uint16_t combo_da      [] PROGMEM = {JP_A, JP_TA, COMBO_END};
const uint16_t combo_di      [] PROGMEM = {JP_NO, JP_TI, COMBO_END};
const uint16_t combo_du      [] PROGMEM = {JP_A, JP_U, COMBO_END};
const uint16_t combo_de      [] PROGMEM = {JP_A, JP_TE, COMBO_END};
const uint16_t combo_do      [] PROGMEM = {JP_A, JP_TO, COMBO_END};
const uint16_t combo_da_k    [] PROGMEM = {JP_KA, JP_TA, COMBO_END};
const uint16_t combo_di_k    [] PROGMEM = {JP_MA, JP_TI, COMBO_END};
const uint16_t combo_du_k    [] PROGMEM = {JP_KA, JP_U, COMBO_END};
const uint16_t combo_de_k    [] PROGMEM = {JP_KA, JP_TE, COMBO_END};
const uint16_t combo_do_k    [] PROGMEM = {JP_KA, JP_TO, COMBO_END};
const uint16_t combo_ba      [] PROGMEM = {JP_A, JP_HA, COMBO_END};
const uint16_t combo_bi      [] PROGMEM = {JP_A, JP_HI, COMBO_END};
const uint16_t combo_bu      [] PROGMEM = {JP_A, KC_MINS, COMBO_END};
const uint16_t combo_be      [] PROGMEM = {JP_A, JP_HE, COMBO_END};
const uint16_t combo_bo      [] PROGMEM = {JP_A, JP_HO, COMBO_END};
const uint16_t combo_ba_k    [] PROGMEM = {JP_KA, JP_HA, COMBO_END};
const uint16_t combo_bi_k    [] PROGMEM = {JP_KA, JP_HI, COMBO_END};
const uint16_t combo_bu_k    [] PROGMEM = {JP_KA, KC_MINS, COMBO_END};
const uint16_t combo_be_k    [] PROGMEM = {JP_KA, JP_HE, COMBO_END};
const uint16_t combo_bo_k    [] PROGMEM = {JP_KA, JP_HO, COMBO_END};
const uint16_t combo_pa      [] PROGMEM = {JP_NA, JP_HA, COMBO_END};
const uint16_t combo_pi      [] PROGMEM = {JP_NA, JP_HI, COMBO_END};
const uint16_t combo_pu      [] PROGMEM = {JP_NA, KC_MINS, COMBO_END};
const uint16_t combo_pe      [] PROGMEM = {JP_NA, JP_HE, COMBO_END};
const uint16_t combo_po      [] PROGMEM = {JP_NA, JP_HO, COMBO_END};
const uint16_t combo_pa_k    [] PROGMEM = {JP_KO, JP_HA, COMBO_END};
const uint16_t combo_pi_k    [] PROGMEM = {JP_KO, JP_HI, COMBO_END};
const uint16_t combo_pu_k    [] PROGMEM = {JP_KO, KC_MINS, COMBO_END};
const uint16_t combo_pe_k    [] PROGMEM = {JP_KO, JP_HE, COMBO_END};
const uint16_t combo_po_k    [] PROGMEM = {JP_KO, JP_HO, COMBO_END};
const uint16_t combo_kya     [] PROGMEM = {JP_KI, JP_KU, COMBO_END};
const uint16_t combo_kyu     [] PROGMEM = {JP_KI, JP_HE, COMBO_END};
const uint16_t combo_kyo     [] PROGMEM = {JP_KI, JP_RU, COMBO_END};
const uint16_t combo_gya     [] PROGMEM = {JP_KI, JP_KU, JP_A,  COMBO_END};
const uint16_t combo_gyu     [] PROGMEM = {JP_KI, JP_HE, JP_A,  COMBO_END};
const uint16_t combo_gyo     [] PROGMEM = {JP_KI, JP_RU, JP_A,  COMBO_END};
const uint16_t combo_gya_k   [] PROGMEM = {JP_KI, JP_KU, JP_KA, COMBO_END};
const uint16_t combo_gyu_k   [] PROGMEM = {JP_KI, JP_HE, JP_KA, COMBO_END};
const uint16_t combo_gyo_k   [] PROGMEM = {JP_KI, JP_RU, JP_KA, COMBO_END};
const uint16_t combo_sya     [] PROGMEM = {JP_SI, JP_KU, COMBO_END};
const uint16_t combo_syu     [] PROGMEM = {JP_SI, JP_HE, COMBO_END};
const uint16_t combo_syo     [] PROGMEM = {JP_SI, JP_RU, COMBO_END};
const uint16_t combo_ja      [] PROGMEM = {JP_SI, JP_KU, JP_A, COMBO_END};
const uint16_t combo_ju      [] PROGMEM = {JP_SI, JP_HE, JP_A, COMBO_END};
const uint16_t combo_jo      [] PROGMEM = {JP_SI, JP_RU, JP_A, COMBO_END};
const uint16_t combo_ja_k    [] PROGMEM = {JP_SI, JP_KU, JP_KA, COMBO_END};
const uint16_t combo_ju_k    [] PROGMEM = {JP_SI, JP_HE, JP_KA, COMBO_END};
const uint16_t combo_jo_k    [] PROGMEM = {JP_SI, JP_RU, JP_KA, COMBO_END};
const uint16_t combo_tya     [] PROGMEM = {JP_TU, JP_YA, COMBO_END};
const uint16_t combo_tyu     [] PROGMEM = {JP_TU, JP_YU, COMBO_END};
const uint16_t combo_tyo     [] PROGMEM = {JP_TU, JP_YO, COMBO_END};
const uint16_t combo_tya_l   [] PROGMEM = {JP_LTU,JP_KU, COMBO_END};
const uint16_t combo_tyu_l   [] PROGMEM = {JP_LTU,JP_HE, COMBO_END};
const uint16_t combo_tyo_l   [] PROGMEM = {JP_LTU,JP_RU, COMBO_END};
const uint16_t combo_dya     [] PROGMEM = {JP_LTU,JP_KU, JP_NO, COMBO_END};
const uint16_t combo_dyu     [] PROGMEM = {JP_LTU,JP_HE, JP_NO, COMBO_END};
const uint16_t combo_dyo     [] PROGMEM = {JP_LTU,JP_RU, JP_NO, COMBO_END};
const uint16_t combo_dya_k   [] PROGMEM = {JP_LTU,JP_KU, JP_MA, COMBO_END};
const uint16_t combo_dyu_k   [] PROGMEM = {JP_LTU,JP_HE, JP_MA, COMBO_END};
const uint16_t combo_dyo_k   [] PROGMEM = {JP_LTU,JP_RU, JP_MA, COMBO_END};
const uint16_t combo_nya     [] PROGMEM = {JP_NI, JP_YA, COMBO_END};
const uint16_t combo_nyu     [] PROGMEM = {JP_NI, JP_YU, COMBO_END};
const uint16_t combo_nyo     [] PROGMEM = {JP_NI, JP_YO, COMBO_END};
const uint16_t combo_nya_t   [] PROGMEM = {JP_TO, JP_KU, COMBO_END};
const uint16_t combo_nyu_t   [] PROGMEM = {JP_TO, JP_HE, COMBO_END};
const uint16_t combo_nyo_t   [] PROGMEM = {JP_TO, JP_RU, COMBO_END};
const uint16_t combo_mya     [] PROGMEM = {JP_MI, JP_YA, COMBO_END};
const uint16_t combo_myu     [] PROGMEM = {JP_MI, JP_YU, COMBO_END};
const uint16_t combo_myo     [] PROGMEM = {JP_MI, JP_YO, COMBO_END};
const uint16_t combo_mya_k   [] PROGMEM = {JP_KE, JP_KU, COMBO_END};
const uint16_t combo_myu_k   [] PROGMEM = {JP_KE, JP_HE, COMBO_END};
const uint16_t combo_myo_k   [] PROGMEM = {JP_KE, JP_RU, COMBO_END};
const uint16_t combo_hya     [] PROGMEM = {JP_HI, JP_KU, COMBO_END};
const uint16_t combo_hyu     [] PROGMEM = {JP_HI, JP_HE, COMBO_END};
const uint16_t combo_hyo     [] PROGMEM = {JP_HI, JP_RU, COMBO_END};
const uint16_t combo_bya     [] PROGMEM = {JP_HI, JP_KU, JP_A, COMBO_END};
const uint16_t combo_byu     [] PROGMEM = {JP_HI, JP_HE, JP_A, COMBO_END};
const uint16_t combo_byo     [] PROGMEM = {JP_HI, JP_RU, JP_A, COMBO_END};
const uint16_t combo_bya_k   [] PROGMEM = {JP_HI, JP_KU, JP_KA, COMBO_END};
const uint16_t combo_byu_k   [] PROGMEM = {JP_HI, JP_HE, JP_KA, COMBO_END};
const uint16_t combo_byo_k   [] PROGMEM = {JP_HI, JP_RU, JP_KA, COMBO_END};
const uint16_t combo_pya     [] PROGMEM = {JP_HI, JP_KU, JP_NA, COMBO_END};
const uint16_t combo_pyu     [] PROGMEM = {JP_HI, JP_HE, JP_NA, COMBO_END};
const uint16_t combo_pyo     [] PROGMEM = {JP_HI, JP_RU, JP_NA, COMBO_END};
const uint16_t combo_pya_k   [] PROGMEM = {JP_HI, JP_KU, JP_KO, COMBO_END};
const uint16_t combo_pyu_k   [] PROGMEM = {JP_HI, JP_HE, JP_KO, COMBO_END};
const uint16_t combo_pyo_k   [] PROGMEM = {JP_HI, JP_RU, JP_KO, COMBO_END};
const uint16_t combo_rya     [] PROGMEM = {JP_RI, JP_YA, COMBO_END};
const uint16_t combo_ryu     [] PROGMEM = {JP_RI, JP_YU, COMBO_END};
const uint16_t combo_ryo     [] PROGMEM = {JP_RI, JP_YO, COMBO_END};
const uint16_t combo_rya_t   [] PROGMEM = {JP_TE, JP_KU, COMBO_END};
const uint16_t combo_ryu_t   [] PROGMEM = {JP_TE, JP_HE, COMBO_END};
const uint16_t combo_ryo_t   [] PROGMEM = {JP_TE, JP_RU, COMBO_END};
const uint16_t combo_teli_na [] PROGMEM = {JP_TE, JP_I,  JP_NA, COMBO_END};
const uint16_t combo_teli_ko [] PROGMEM = {JP_TE, JP_I,  JP_KO, COMBO_END};
const uint16_t combo_deli_ka [] PROGMEM = {JP_TE, JP_I, JP_KA, COMBO_END};
const uint16_t combo_deli_a  [] PROGMEM = {JP_TE, JP_I, JP_A , COMBO_END};
const uint16_t combo_tolu_na [] PROGMEM = {JP_TO, JP_U, JP_NA, COMBO_END};
const uint16_t combo_tolu_ko [] PROGMEM = {JP_TO, JP_U, JP_KO, COMBO_END};
const uint16_t combo_dolu_ka [] PROGMEM = {JP_TO, JP_U, JP_KA, COMBO_END};
const uint16_t combo_dolu_a  [] PROGMEM = {JP_TO, JP_U, JP_A , COMBO_END};
const uint16_t combo_telyu_na[] PROGMEM = {JP_TE, JP_HE, JP_NA, COMBO_END};
const uint16_t combo_telyu_ko[] PROGMEM = {JP_TE, JP_HE, JP_KO, COMBO_END};
const uint16_t combo_delyu_ka[] PROGMEM = {JP_TE, JP_HE, JP_KA, COMBO_END};
const uint16_t combo_delyu_a [] PROGMEM = {JP_TE, JP_HE, JP_A , COMBO_END};
const uint16_t combo_she_na  [] PROGMEM = {JP_SI, JP_SU, JP_NA, COMBO_END};
const uint16_t combo_she_ko  [] PROGMEM = {JP_SI, JP_SU, JP_KO, COMBO_END};
const uint16_t combo_je_ka   [] PROGMEM = {JP_SI, JP_SU, JP_KA, COMBO_END};
const uint16_t combo_je_a    [] PROGMEM = {JP_SI, JP_SU, JP_A , COMBO_END};
const uint16_t combo_che_na  [] PROGMEM = {JP_TI, JP_E, JP_KUTEN, COMBO_END};
const uint16_t combo_che_ko  [] PROGMEM = {JP_TI, JP_E, JP_TOUTEN, COMBO_END};
const uint16_t combo_dile_ka [] PROGMEM = {JP_TI, JP_E, JP_NO, COMBO_END};
const uint16_t combo_dile_a  [] PROGMEM = {JP_TI, JP_E, JP_MA, COMBO_END};
const uint16_t combo_vu      [] PROGMEM = {JP_U, KC_MINS, COMBO_END};
const uint16_t combo_va_na   [] PROGMEM = {JP_U, JP_A, JP_NA, COMBO_END};
const uint16_t combo_va_ko   [] PROGMEM = {JP_U, JP_A, JP_KO, COMBO_END};
const uint16_t combo_va_ka   [] PROGMEM = {JP_U, JP_A, JP_KA, COMBO_END};
const uint16_t combo_va_a    [] PROGMEM = {JP_U, JP_A, JP_A , COMBO_END};
const uint16_t combo_uli_na  [] PROGMEM = {JP_U, JP_I, JP_NA, COMBO_END};
const uint16_t combo_uli_ko  [] PROGMEM = {JP_U, JP_I, JP_KO, COMBO_END};
const uint16_t combo_vuli_ka [] PROGMEM = {JP_U, JP_I, JP_KA, COMBO_END};
const uint16_t combo_vuli_a  [] PROGMEM = {JP_U, JP_I, JP_A , COMBO_END};
const uint16_t combo_ule_na  [] PROGMEM = {JP_U, JP_SU, JP_NA, COMBO_END};
const uint16_t combo_ule_ko  [] PROGMEM = {JP_U, JP_SU, JP_KO, COMBO_END};
const uint16_t combo_vule_ka [] PROGMEM = {JP_U, JP_SU, JP_KA, COMBO_END};
const uint16_t combo_vule_a  [] PROGMEM = {JP_U, JP_SU, JP_A , COMBO_END};
const uint16_t combo_ulo_na  [] PROGMEM = {JP_U, JP_TA, JP_NA, COMBO_END};
const uint16_t combo_ulo_ko  [] PROGMEM = {JP_U, JP_TA, JP_KO, COMBO_END};
const uint16_t combo_vulo_ka [] PROGMEM = {JP_U, JP_TA, JP_KA, COMBO_END};
const uint16_t combo_vulo_a  [] PROGMEM = {JP_U, JP_TA, JP_A , COMBO_END};
const uint16_t combo_vulyu_na[] PROGMEM = {JP_U, JP_HE, JP_NA, COMBO_END};
const uint16_t combo_vulyu_ko[] PROGMEM = {JP_U, JP_HE, JP_KO, COMBO_END};
const uint16_t combo_vulyu_ka[] PROGMEM = {JP_U, JP_HE, JP_KA, COMBO_END};
const uint16_t combo_vulyu_a [] PROGMEM = {JP_U, JP_HE, JP_A , COMBO_END};
const uint16_t combo_ile_na  [] PROGMEM = {JP_I, JP_SU, JP_NA, COMBO_END};
const uint16_t combo_ile_ko  [] PROGMEM = {JP_I, JP_SU, JP_KO, COMBO_END};
const uint16_t combo_ile_ka  [] PROGMEM = {JP_I, JP_SU, JP_KA, COMBO_END};
const uint16_t combo_ile_a   [] PROGMEM = {JP_I, JP_SU, JP_A , COMBO_END};


const uint16_t combo_tula_na [] PROGMEM = {JP_TU, JP_NO, JP_NA, COMBO_END};
const uint16_t combo_tula_ko [] PROGMEM = {JP_TU, JP_NO, JP_MA    , COMBO_END};
const uint16_t combo_tula_ka [] PROGMEM = {JP_TU, JP_NO, JP_TOUTEN, COMBO_END};
const uint16_t combo_tula_a  [] PROGMEM = {JP_TU, JP_NO, JP_KUTEN , COMBO_END};
const uint16_t combo_fa_na   [] PROGMEM = {KC_MINS, JP_A , JP_NA , COMBO_END};
const uint16_t combo_fa_ko   [] PROGMEM = {KC_MINS, JP_A , JP_KO , COMBO_END};
const uint16_t combo_fa_ka   [] PROGMEM = {KC_MINS, JP_A , JP_KA , COMBO_END};
const uint16_t combo_fa_a    [] PROGMEM = {KC_MINS, JP_A , JP_A  , COMBO_END};
const uint16_t combo_fi_na   [] PROGMEM = {KC_MINS, JP_I , JP_NA , COMBO_END};
const uint16_t combo_fi_ko   [] PROGMEM = {KC_MINS, JP_I , JP_KO , COMBO_END};
const uint16_t combo_fi_ka   [] PROGMEM = {KC_MINS, JP_I , JP_KA , COMBO_END};
const uint16_t combo_fi_a    [] PROGMEM = {KC_MINS, JP_I , JP_A  , COMBO_END};
const uint16_t combo_fe_na   [] PROGMEM = {KC_MINS, JP_SU, JP_NA , COMBO_END};
const uint16_t combo_fe_ko   [] PROGMEM = {KC_MINS, JP_SU, JP_KO , COMBO_END};
const uint16_t combo_fe_ka   [] PROGMEM = {KC_MINS, JP_SU, JP_KA , COMBO_END};
const uint16_t combo_fe_a    [] PROGMEM = {KC_MINS, JP_SU, JP_A  , COMBO_END};
const uint16_t combo_fo_na   [] PROGMEM = {KC_MINS, JP_TA, JP_NA , COMBO_END};
const uint16_t combo_fo_ko   [] PROGMEM = {KC_MINS, JP_TA, JP_KO , COMBO_END};
const uint16_t combo_fo_ka   [] PROGMEM = {KC_MINS, JP_TA, JP_KA , COMBO_END};
const uint16_t combo_fo_a    [] PROGMEM = {KC_MINS, JP_TA, JP_A  , COMBO_END};
const uint16_t combo_fulyu_na[] PROGMEM = {KC_MINS, JP_HE, JP_NA , COMBO_END};
const uint16_t combo_fulyu_ko[] PROGMEM = {KC_MINS, JP_HE, JP_KO , COMBO_END};
const uint16_t combo_fulyu_ka[] PROGMEM = {KC_MINS, JP_HE, JP_KA , COMBO_END};
const uint16_t combo_fulyu_a [] PROGMEM = {KC_MINS, JP_HE, JP_A  , COMBO_END};
const uint16_t combo_kula_na [] PROGMEM = {JP_KU, JP_A, JP_NA, COMBO_END};
const uint16_t combo_kula_ko [] PROGMEM = {JP_KU, JP_A, JP_KO, COMBO_END};
const uint16_t combo_gula_ka [] PROGMEM = {JP_KU, JP_A, JP_KA, COMBO_END};
const uint16_t combo_gula_a  [] PROGMEM = {JP_KU, JP_A, JP_A , COMBO_END};
const uint16_t combo_kuli_na [] PROGMEM = {JP_KU, JP_I, JP_NA, COMBO_END};
const uint16_t combo_kuli_ko [] PROGMEM = {JP_KU, JP_I, JP_KO, COMBO_END};
const uint16_t combo_guli_ka [] PROGMEM = {JP_KU, JP_I, JP_KA, COMBO_END};
const uint16_t combo_guli_a  [] PROGMEM = {JP_KU, JP_I, JP_A , COMBO_END};
const uint16_t combo_kule_na [] PROGMEM = {JP_KU, JP_SU, JP_NA, COMBO_END};
const uint16_t combo_kule_ko [] PROGMEM = {JP_KU, JP_SU, JP_KO, COMBO_END};
const uint16_t combo_gule_ka [] PROGMEM = {JP_KU, JP_SU, JP_KA, COMBO_END};
const uint16_t combo_gule_a  [] PROGMEM = {JP_KU, JP_SU, JP_A , COMBO_END};
const uint16_t combo_kulo_na [] PROGMEM = {JP_KU, JP_TA, JP_NA, COMBO_END};
const uint16_t combo_kulo_ko [] PROGMEM = {JP_KU, JP_TA, JP_KO, COMBO_END};
const uint16_t combo_gulo_ka [] PROGMEM = {JP_KU, JP_TA, JP_KA, COMBO_END};
const uint16_t combo_gulo_a  [] PROGMEM = {JP_KU, JP_TA, JP_A , COMBO_END};
const uint16_t combo_kulwa_na[] PROGMEM = {JP_KU, JP_RA, JP_NA, COMBO_END};
const uint16_t combo_kulwa_ko[] PROGMEM = {JP_KU, JP_RA, JP_KO, COMBO_END};
const uint16_t combo_gulwa_ka[] PROGMEM = {JP_KU, JP_RA, JP_KA, COMBO_END};
const uint16_t combo_gulwa_a [] PROGMEM = {JP_KU, JP_RA, JP_A , COMBO_END};


// clang-format off
combo_t key_combos[] = {
    COMBO(caps_combo, CW_TOGG),          // J and , => activate Caps Word.
    COMBO(x_c_combo, KC_BSLS),           // J and K => backslash
    COMBO(comm_dot_combo, KC_SCLN),      // , and . => ;
    COMBO(h_j_combo, OSL(FUN)),          // F and N => FUN layer

    COMBO(combo_ga      ,JP_GA ),
    COMBO(combo_gi      ,JP_GI ),
    COMBO(combo_gu      ,JP_GU ),
    COMBO(combo_ge      ,JP_GE ),
    COMBO(combo_go      ,JP_GO ),
    COMBO(combo_gi_k    ,JP_GI ),
    COMBO(combo_gu_k    ,JP_GU ),
    COMBO(combo_ge_k    ,JP_GE ),
    COMBO(combo_go_k    ,JP_GO ),
    COMBO(combo_za      ,JP_ZA ),
    COMBO(combo_zi      ,JP_ZI ),
    COMBO(combo_zu      ,JP_ZU ),
    COMBO(combo_ze      ,JP_ZE ),
    COMBO(combo_zo      ,JP_ZO ),
    COMBO(combo_za_k    ,JP_ZA ),
    COMBO(combo_zi_k    ,JP_ZI ),
    COMBO(combo_zu_k    ,JP_ZU ),
    COMBO(combo_ze_k    ,JP_ZE ),
    COMBO(combo_zo_k    ,JP_ZO ),
    COMBO(combo_da      ,JP_DA ),
    COMBO(combo_di      ,JP_DI ),
    COMBO(combo_du      ,JP_DU ),
    COMBO(combo_de      ,JP_DE ),
    COMBO(combo_do      ,JP_DO ),
    COMBO(combo_da_k    ,JP_DA ),
    COMBO(combo_di_k    ,JP_DI ),
    COMBO(combo_du_k    ,JP_DU ),
    COMBO(combo_de_k    ,JP_DE ),
    COMBO(combo_do_k    ,JP_DO ),
    COMBO(combo_ba      ,JP_BA ),
    COMBO(combo_bi      ,JP_BI ),
    COMBO(combo_bu      ,JP_BU ),
    COMBO(combo_be      ,JP_BE ),
    COMBO(combo_bo      ,JP_BO ),
    COMBO(combo_ba_k    ,JP_BA ),
    COMBO(combo_bi_k    ,JP_BI ),
    COMBO(combo_bu_k    ,JP_BU ),
    COMBO(combo_be_k    ,JP_BE ),
    COMBO(combo_bo_k    ,JP_BO ),
    COMBO(combo_pa      ,JP_PA ),
    COMBO(combo_pi      ,JP_PI ),
    COMBO(combo_pu      ,JP_PU ),
    COMBO(combo_pe      ,JP_PE ),
    COMBO(combo_po      ,JP_PO ),
    COMBO(combo_pa_k    ,JP_PA ),
    COMBO(combo_pi_k    ,JP_PI ),
    COMBO(combo_pu_k    ,JP_PU ),
    COMBO(combo_pe_k    ,JP_PE ),
    COMBO(combo_po_k    ,JP_PO ),
    COMBO(combo_kya     ,JP_KYA ),
    COMBO(combo_kyu     ,JP_KYU ),
    COMBO(combo_kyo     ,JP_KYO ),
    COMBO(combo_gya     ,JP_GYA ),
    COMBO(combo_gyu     ,JP_GYU ),
    COMBO(combo_gyo     ,JP_GYO ),
    COMBO(combo_gya_k   ,JP_GYA ),
    COMBO(combo_gyu_k   ,JP_GYU ),
    COMBO(combo_gyo_k   ,JP_GYO ),
    COMBO(combo_sya     ,JP_SYA ),
    COMBO(combo_syu     ,JP_SYU ),
    COMBO(combo_syo     ,JP_SYO ),
    COMBO(combo_ja      ,JP_JA ),
    COMBO(combo_ju      ,JP_JU ),
    COMBO(combo_jo      ,JP_JO ),
    COMBO(combo_ja_k    ,JP_JA ),
    COMBO(combo_ju_k    ,JP_JU ),
    COMBO(combo_jo_k    ,JP_JO ),
    COMBO(combo_tya     ,JP_TYA ),
    COMBO(combo_tyu     ,JP_TYU ),
    COMBO(combo_tyo     ,JP_TYO ),
    COMBO(combo_tya_l   ,JP_TYA ),
    COMBO(combo_tyu_l   ,JP_TYU ),
    COMBO(combo_tyo_l   ,JP_TYO ),
    COMBO(combo_dya     ,JP_DYA ),
    COMBO(combo_dyu     ,JP_DYU ),
    COMBO(combo_dyo     ,JP_DYO ),
    COMBO(combo_dya_k   ,JP_DYA ),
    COMBO(combo_dyu_k   ,JP_DYU ),
    COMBO(combo_dyo_k   ,JP_DYO ),
    COMBO(combo_nya     ,JP_NYA ),
    COMBO(combo_nyu     ,JP_NYU ),
    COMBO(combo_nyo     ,JP_NYO ),
    COMBO(combo_nya_t   ,JP_NYA ),
    COMBO(combo_nyu_t   ,JP_NYU ),
    COMBO(combo_nyo_t   ,JP_NYO ),
    COMBO(combo_mya     ,JP_MYA ),
    COMBO(combo_myu     ,JP_MYU ),
    COMBO(combo_myo     ,JP_MYO ),
    COMBO(combo_mya_k   ,JP_MYA ),
    COMBO(combo_myu_k   ,JP_MYU ),
    COMBO(combo_myo_k   ,JP_MYO ),
    COMBO(combo_hya     ,JP_HYA ),
    COMBO(combo_hyu     ,JP_HYU ),
    COMBO(combo_hyo     ,JP_HYO ),
    COMBO(combo_bya     ,JP_BYA ),
    COMBO(combo_byu     ,JP_BYU ),
    COMBO(combo_byo     ,JP_BYO ),
    COMBO(combo_bya_k   ,JP_BYA ),
    COMBO(combo_byu_k   ,JP_BYU ),
    COMBO(combo_byo_k   ,JP_BYO ),
    COMBO(combo_pya     ,JP_PYA ),
    COMBO(combo_pyu     ,JP_PYU ),
    COMBO(combo_pyo     ,JP_PYO ),
    COMBO(combo_pya_k   ,JP_PYA ),
    COMBO(combo_pyu_k   ,JP_PYU ),
    COMBO(combo_pyo_k   ,JP_PYO ),
    COMBO(combo_rya     ,JP_RYA ),
    COMBO(combo_ryu     ,JP_RYU ),
    COMBO(combo_ryo     ,JP_RYO ),
    COMBO(combo_rya_t   ,JP_RYA ),
    COMBO(combo_ryu_t   ,JP_RYU ),
    COMBO(combo_ryo_t   ,JP_RYO ),
    COMBO(combo_teli_na ,JP_TELI ),
    COMBO(combo_teli_ko ,JP_TELI ),
    COMBO(combo_deli_ka ,JP_DELI ),
    COMBO(combo_deli_a  ,JP_DELI ),
    COMBO(combo_tolu_na ,JP_TOLU ),
    COMBO(combo_tolu_ko ,JP_TOLU ),
    COMBO(combo_dolu_ka ,JP_DOLU ),
    COMBO(combo_dolu_a  ,JP_DOLU ),
    COMBO(combo_telyu_na,JP_TELYU ),
    COMBO(combo_telyu_ko,JP_TELYU ),
    COMBO(combo_delyu_ka,JP_DELYU ),
    COMBO(combo_delyu_a ,JP_DELYU ),
    COMBO(combo_she_na  ,JP_SHE ),
    COMBO(combo_she_ko  ,JP_SHE ),
    COMBO(combo_je_ka   ,JP_JE ),
    COMBO(combo_je_a    ,JP_JE ),
    COMBO(combo_che_na  ,JP_CHE ),
    COMBO(combo_che_ko  ,JP_CHE ),
    COMBO(combo_dile_ka ,JP_DILE ),
    COMBO(combo_dile_a  ,JP_DILE ),
    COMBO(combo_vu      ,JP_VU ),
    COMBO(combo_va_na   ,JP_VA ),
    COMBO(combo_va_ko   ,JP_VA ),
    COMBO(combo_va_ka   ,JP_VA ),
    COMBO(combo_va_a    ,JP_VA ),
    COMBO(combo_uli_na  ,JP_ULI ),
    COMBO(combo_uli_ko  ,JP_ULI ),
    COMBO(combo_vuli_ka ,JP_VI ),
    COMBO(combo_vuli_a  ,JP_VI ),
    COMBO(combo_ule_na  ,JP_ULE ),
    COMBO(combo_ule_ko  ,JP_ULE ),
    COMBO(combo_vule_ka ,JP_VULE ),
    COMBO(combo_vule_a  ,JP_VULE ),
    COMBO(combo_ulo_na  ,JP_ULO ),
    COMBO(combo_ulo_ko  ,JP_ULO ),
    COMBO(combo_vulo_ka ,JP_VULO ),
    COMBO(combo_vulo_a  ,JP_VULO ),
    COMBO(combo_vulyu_na,JP_VULYU ),
    COMBO(combo_vulyu_ko,JP_VULYU ),
    COMBO(combo_vulyu_ka,JP_VULYU ),
    COMBO(combo_vulyu_a ,JP_VULYU ),
    COMBO(combo_ile_na  ,JP_ILE ),
    COMBO(combo_ile_ko  ,JP_ILE ),
    COMBO(combo_ile_ka  ,JP_ILE ),
    COMBO(combo_ile_a   ,JP_ILE ),
    COMBO(combo_tula_na ,JP_TULA ),
    COMBO(combo_tula_ko ,JP_TULA ),
    COMBO(combo_tula_ka ,JP_TULA ),
    COMBO(combo_tula_a  ,JP_TULA ),
    COMBO(combo_fa_na   ,JP_FA ),
    COMBO(combo_fa_ko   ,JP_FA ),
    COMBO(combo_fa_ka   ,JP_FA ),
    COMBO(combo_fa_a    ,JP_FA ),
    COMBO(combo_fi_na   ,JP_FI ),
    COMBO(combo_fi_ko   ,JP_FI ),
    COMBO(combo_fi_ka   ,JP_FI ),
    COMBO(combo_fi_a    ,JP_FI ),
    COMBO(combo_fe_na   ,JP_FE ),
    COMBO(combo_fe_ko   ,JP_FE ),
    COMBO(combo_fe_ka   ,JP_FE ),
    COMBO(combo_fe_a    ,JP_FE ),
    COMBO(combo_fo_na   ,JP_FO ),
    COMBO(combo_fo_ko   ,JP_FO ),
    COMBO(combo_fo_ka   ,JP_FO ),
    COMBO(combo_fo_a    ,JP_FO ),
    COMBO(combo_fulyu_na,JP_FLYU ),
    COMBO(combo_fulyu_ko,JP_FLYU ),
    COMBO(combo_fulyu_ka,JP_FLYU ),
    COMBO(combo_fulyu_a ,JP_FLYU ),
    COMBO(combo_kula_na ,JP_KULA ),
    COMBO(combo_kula_ko ,JP_KULA ),
    COMBO(combo_gula_ka ,JP_GULA ),
    COMBO(combo_gula_a  ,JP_GULA ),
    COMBO(combo_kuli_na ,JP_KULI ),
    COMBO(combo_kuli_ko ,JP_KULI ),
    COMBO(combo_guli_ka ,JP_GULI ),
    COMBO(combo_guli_a  ,JP_GULI ),
    COMBO(combo_kule_na ,JP_KULE ),
    COMBO(combo_kule_ko ,JP_KULE ),
    COMBO(combo_gule_ka ,JP_GULE ),
    COMBO(combo_gule_a  ,JP_GULE ),
    COMBO(combo_kulo_na ,JP_KULO ),
    COMBO(combo_kulo_ko ,JP_KULO ),
    COMBO(combo_gulo_ka ,JP_GULO ),
    COMBO(combo_gulo_a  ,JP_GULO ),
    COMBO(combo_kulwa_na,JP_KULWA ),
    COMBO(combo_kulwa_ko,JP_KULWA ),
    COMBO(combo_gulwa_ka,JP_GULWA ),
    COMBO(combo_gulwa_a ,JP_GULWA ),
    
};

bool is_alt_tab_active = false;    // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0; 

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {               // This will do most of the grunt work with the keycodes.
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        } 
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    // case TRNSLT:  // Types ../ to go up a directory on the shell.
    //   if (record->event.pressed) {
    //     // on keydown
    //     register_code(KC_LSFT);
    //     register_code(KC_F10);
    //     tap_code_delay(KC_RSFT, 100);
    //     register_code(KC_T);
    //     unregister_code(KC_T);
    //     unregister_code(KC_F10);
    //     unregister_code(KC_LSFT);
    // }
    // break;
    // break;
    case TRNSLT:  // Types ../ to go up a directory on the shell.
      if (record->event.pressed) {
        // on keydown
        register_code(MS_BTN2);
        for (uint16_t i = 100; i > 0; i--) {
        wait_ms(1);
        }
        register_code(KC_T);
        unregister_code(KC_T);
        unregister_code(MS_BTN2);
    }
    break;
    case CLST:  // Types ../ to go up a directory on the shell.
      if (record->event.pressed) {
        // on keydown
        register_code(KC_LCTL);
        register_code(KC_W);
        unregister_code(KC_W);
        unregister_code(KC_LCTL);
    }
    break;
    case SRCH:  // Types ../ to go up a directory on the shell.
      if (record->event.pressed) {
        // on keydown
        register_code(KC_LSFT);
        register_code(KC_F10);
        tap_code_delay(KC_RSFT, 100);
        register_code(KC_S);
        unregister_code(KC_S);
        unregister_code(KC_F10);
        unregister_code(KC_LSFT);
    }
    break;
  }
    // 押下時以外は何もしない
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {

        case JP_KUTEN : tap_code(KC_DOT); return false;
        case JP_TOUTEN: tap_code(KC_COMM); return false; 
        // 母音
        case JP_A: tap_code(KC_A); return false;
        case JP_I: tap_code(KC_I); return false;
        case JP_U: tap_code(KC_U); return false;
        case JP_E: tap_code(KC_E); return false;
        case JP_O: tap_code(KC_O); return false;

        case JP_KA: tap_code(KC_K); tap_code(KC_A); return false;
        case JP_KI: tap_code(KC_K); tap_code(KC_I); return false;
        case JP_KU: tap_code(KC_K); tap_code(KC_U); return false;
        case JP_KE: tap_code(KC_K); tap_code(KC_E); return false;
        case JP_KO: tap_code(KC_K); tap_code(KC_O); return false;

        case JP_SA: tap_code(KC_S); tap_code(KC_A); return false;
        case JP_SI: tap_code(KC_S); tap_code(KC_I); return false;
        case JP_SU: tap_code(KC_S); tap_code(KC_U); return false;
        case JP_SE: tap_code(KC_S); tap_code(KC_E); return false;
        case JP_SO: tap_code(KC_S); tap_code(KC_O); return false;

        case JP_TA: tap_code(KC_T); tap_code(KC_A); return false;
        case JP_TI: tap_code(KC_T); tap_code(KC_I); return false;
        case JP_TU: tap_code(KC_T); tap_code(KC_U); return false;
        case JP_TE: tap_code(KC_T); tap_code(KC_E); return false;
        case JP_TO: tap_code(KC_T); tap_code(KC_O); return false;

        case JP_NA: tap_code(KC_N); tap_code(KC_A); return false;
        case JP_NI: tap_code(KC_N); tap_code(KC_I); return false;
        case JP_NU: tap_code(KC_N); tap_code(KC_U); return false;
        case JP_NE: tap_code(KC_N); tap_code(KC_E); return false;
        case JP_NO: tap_code(KC_N); tap_code(KC_O); return false;

        case JP_HA: tap_code(KC_H); tap_code(KC_A); return false;
        case JP_HI: tap_code(KC_H); tap_code(KC_I); return false;
        case JP_HU: tap_code(KC_H); tap_code(KC_U); return false;
        case JP_HE: tap_code(KC_H); tap_code(KC_E); return false;
        case JP_HO: tap_code(KC_H); tap_code(KC_O); return false;

        case JP_MA: tap_code(KC_M); tap_code(KC_A); return false;
        case JP_MI: tap_code(KC_M); tap_code(KC_I); return false;
        case JP_MU: tap_code(KC_M); tap_code(KC_U); return false;
        case JP_ME: tap_code(KC_M); tap_code(KC_E); return false;
        case JP_MO: tap_code(KC_M); tap_code(KC_O); return false;

        case JP_YA: tap_code(KC_Y); tap_code(KC_A); return false;
        case JP_YI: tap_code(KC_Y); tap_code(KC_I); return false;
        case JP_YU: tap_code(KC_Y); tap_code(KC_U); return false;
        case JP_YE: tap_code(KC_Y); tap_code(KC_E); return false;
        case JP_YO: tap_code(KC_Y); tap_code(KC_O); return false;

        case JP_RA: tap_code(KC_R); tap_code(KC_A); return false;
        case JP_RI: tap_code(KC_R); tap_code(KC_I); return false;
        case JP_RU: tap_code(KC_R); tap_code(KC_U); return false;
        case JP_RE: tap_code(KC_R); tap_code(KC_E); return false;
        case JP_RO: tap_code(KC_R); tap_code(KC_O); return false;

        case JP_WA: tap_code(KC_W); tap_code(KC_A); return false;
        case JP_WI: tap_code(KC_W); tap_code(KC_I); return false;
        case JP_WU: tap_code(KC_W); tap_code(KC_U); return false;
        case JP_WE: tap_code(KC_W); tap_code(KC_E); return false;
        case JP_WO: tap_code(KC_W); tap_code(KC_O); return false;

        case JP_NN: tap_code(KC_N); tap_code(KC_N); return false;

        case JP_GA: tap_code(KC_G); tap_code(KC_A); return false;
        case JP_GI: tap_code(KC_G); tap_code(KC_I); return false;
        case JP_GU: tap_code(KC_G); tap_code(KC_U); return false;
        case JP_GE: tap_code(KC_G); tap_code(KC_E); return false;
        case JP_GO: tap_code(KC_G); tap_code(KC_O); return false;

        case JP_ZA: tap_code(KC_Z); tap_code(KC_A); return false;
        case JP_ZI: tap_code(KC_Z); tap_code(KC_I); return false;
        case JP_ZU: tap_code(KC_Z); tap_code(KC_U); return false;
        case JP_ZE: tap_code(KC_Z); tap_code(KC_E); return false;
        case JP_ZO: tap_code(KC_Z); tap_code(KC_O); return false;

        case JP_DA: tap_code(KC_D); tap_code(KC_A); return false;
        case JP_DI: tap_code(KC_D); tap_code(KC_I); return false;
        case JP_DU: tap_code(KC_D); tap_code(KC_U); return false;
        case JP_DE: tap_code(KC_D); tap_code(KC_E); return false;
        case JP_DO: tap_code(KC_D); tap_code(KC_O); return false;

        case JP_BA: tap_code(KC_B); tap_code(KC_A); return false;
        case JP_BI: tap_code(KC_B); tap_code(KC_I); return false;
        case JP_BU: tap_code(KC_B); tap_code(KC_U); return false;
        case JP_BE: tap_code(KC_B); tap_code(KC_E); return false;
        case JP_BO: tap_code(KC_B); tap_code(KC_O); return false;

        case JP_PA: tap_code(KC_P); tap_code(KC_A); return false;
        case JP_PI: tap_code(KC_P); tap_code(KC_I); return false;
        case JP_PU: tap_code(KC_P); tap_code(KC_U); return false;
        case JP_PE: tap_code(KC_P); tap_code(KC_E); return false;
        case JP_PO: tap_code(KC_P); tap_code(KC_O); return false;

        case JP_KYA: tap_code(KC_K); tap_code(KC_Y); tap_code(KC_A); return false;
        case JP_KYU: tap_code(KC_K); tap_code(KC_Y); tap_code(KC_U); return false;
        case JP_KYO: tap_code(KC_K); tap_code(KC_Y); tap_code(KC_O); return false;

        case JP_GYA: tap_code(KC_G); tap_code(KC_Y); tap_code(KC_A); return false;
        case JP_GYU: tap_code(KC_G); tap_code(KC_Y); tap_code(KC_U); return false;
        case JP_GYO: tap_code(KC_G); tap_code(KC_Y); tap_code(KC_O); return false;

        case JP_SYA: tap_code(KC_S); tap_code(KC_Y); tap_code(KC_A); return false;
        case JP_SYU: tap_code(KC_S); tap_code(KC_Y); tap_code(KC_U); return false;
        case JP_SYO: tap_code(KC_S); tap_code(KC_Y); tap_code(KC_O); return false;

        case JP_JA: tap_code(KC_J); tap_code(KC_A); return false;
        case JP_JU: tap_code(KC_J); tap_code(KC_U); return false;
        case JP_JO: tap_code(KC_J); tap_code(KC_O); return false;

        case JP_TYA: tap_code(KC_T); tap_code(KC_Y); tap_code(KC_A); return false;
        case JP_TYU: tap_code(KC_T); tap_code(KC_Y); tap_code(KC_U); return false;
        case JP_TYO: tap_code(KC_T); tap_code(KC_Y); tap_code(KC_O); return false;

        case JP_NYA: tap_code(KC_N); tap_code(KC_Y); tap_code(KC_A); return false;
        case JP_NYU: tap_code(KC_N); tap_code(KC_Y); tap_code(KC_U); return false;
        case JP_NYO: tap_code(KC_N); tap_code(KC_Y); tap_code(KC_O); return false;

        case JP_HYA: tap_code(KC_H); tap_code(KC_Y); tap_code(KC_A); return false;
        case JP_HYU: tap_code(KC_H); tap_code(KC_Y); tap_code(KC_U); return false;
        case JP_HYO: tap_code(KC_H); tap_code(KC_Y); tap_code(KC_O); return false;

        case JP_BYA: tap_code(KC_B); tap_code(KC_Y); tap_code(KC_A); return false;
        case JP_BYU: tap_code(KC_B); tap_code(KC_Y); tap_code(KC_U); return false;
        case JP_BYO: tap_code(KC_B); tap_code(KC_Y); tap_code(KC_O); return false;

        case JP_PYA: tap_code(KC_P); tap_code(KC_Y); tap_code(KC_A); return false;
        case JP_PYU: tap_code(KC_P); tap_code(KC_Y); tap_code(KC_U); return false;
        case JP_PYO: tap_code(KC_P); tap_code(KC_Y); tap_code(KC_O); return false;

        case JP_MYA: tap_code(KC_M); tap_code(KC_Y); tap_code(KC_A); return false;
        case JP_MYU: tap_code(KC_M); tap_code(KC_Y); tap_code(KC_U); return false;
        case JP_MYO: tap_code(KC_M); tap_code(KC_Y); tap_code(KC_O); return false;

        case JP_RYA: tap_code(KC_R); tap_code(KC_Y); tap_code(KC_A); return false;
        case JP_RYU: tap_code(KC_R); tap_code(KC_Y); tap_code(KC_U); return false;
        case JP_RYO: tap_code(KC_R); tap_code(KC_Y); tap_code(KC_O); return false;

        case JP_VA: tap_code(KC_V); tap_code(KC_A); return false;
        case JP_VI: tap_code(KC_V); tap_code(KC_I); return false;
        case JP_VU: tap_code(KC_V); tap_code(KC_U); return false;
        case JP_VE: tap_code(KC_V); tap_code(KC_E); return false;
        case JP_VO: tap_code(KC_V); tap_code(KC_O); return false;

        case JP_LA: tap_code(KC_L); tap_code(KC_A); return false;
        case JP_LI: tap_code(KC_L); tap_code(KC_I); return false;
        case JP_LU: tap_code(KC_L); tap_code(KC_U); return false;
        case JP_LE: tap_code(KC_L); tap_code(KC_E); return false;
        case JP_LO: tap_code(KC_L); tap_code(KC_O); return false;
        case JP_LWA: tap_code(KC_L); tap_code(KC_W); tap_code(KC_A); return false;

        case JP_LTU: tap_code(KC_L); tap_code(KC_T); tap_code(KC_U); return false;
        case JP_LYA: tap_code(KC_L); tap_code(KC_Y); tap_code(KC_A); return false;
        case JP_LYU: tap_code(KC_L); tap_code(KC_Y); tap_code(KC_U); return false;
        case JP_LYO: tap_code(KC_L); tap_code(KC_Y); tap_code(KC_O); return false;

        case JP_DYA: tap_code(KC_D); tap_code(KC_Y); tap_code(KC_A); return false;
        case JP_DYU: tap_code(KC_D); tap_code(KC_Y); tap_code(KC_U); return false;
        case JP_DYO: tap_code(KC_D); tap_code(KC_Y); tap_code(KC_O); return false;

        case JP_TELI: tap_code(KC_T); tap_code(KC_E); tap_code(KC_L); tap_code(KC_I); return false;
        case JP_DELI: tap_code(KC_D); tap_code(KC_E); tap_code(KC_L); tap_code(KC_I); return false;

        case JP_TOLU: tap_code(KC_T); tap_code(KC_O); tap_code(KC_L); tap_code(KC_U); return false;
        case JP_DOLU: tap_code(KC_D); tap_code(KC_O); tap_code(KC_L); tap_code(KC_U); return false;

        case JP_TELYU: tap_code(KC_T); tap_code(KC_E); tap_code(KC_L); tap_code(KC_Y); tap_code(KC_U); return false;
        case JP_DELYU: tap_code(KC_D); tap_code(KC_E); tap_code(KC_L); tap_code(KC_Y); tap_code(KC_U); return false;

        case JP_SHE: tap_code(KC_S); tap_code(KC_H); tap_code(KC_E); return false;
        case JP_JE: tap_code(KC_J); tap_code(KC_E); return false;

        case JP_CHE: tap_code(KC_C); tap_code(KC_H); tap_code(KC_E); return false;
        case JP_DILE: tap_code(KC_D); tap_code(KC_I); tap_code(KC_L); tap_code(KC_E); return false;

        case JP_ULI: tap_code(KC_U); tap_code(KC_L); tap_code(KC_I); return false;
        case JP_VLI: tap_code(KC_V); tap_code(KC_L); tap_code(KC_I); return false;

        case JP_ULE: tap_code(KC_U); tap_code(KC_L); tap_code(KC_E); return false;
        case JP_VULE: tap_code(KC_V); tap_code(KC_U); tap_code(KC_L); tap_code(KC_E); return false;

        case JP_ULO: tap_code(KC_U); tap_code(KC_L); tap_code(KC_O); return false;
        case JP_VULO: tap_code(KC_V); tap_code(KC_U); tap_code(KC_L); tap_code(KC_O); return false;
        case JP_VULYU: tap_code(KC_V); tap_code(KC_U); tap_code(KC_L); tap_code(KC_Y); tap_code(KC_U); return false;

        case JP_ILE: tap_code(KC_I); tap_code(KC_L); tap_code(KC_E); return false;

        case JP_TULA: tap_code(KC_T); tap_code(KC_U); tap_code(KC_L); tap_code(KC_A); return false;

        case JP_FA: tap_code(KC_F); tap_code(KC_A); return false;
        case JP_FI: tap_code(KC_F); tap_code(KC_I); return false;
        case JP_FE: tap_code(KC_F); tap_code(KC_E); return false;
        case JP_FO: tap_code(KC_F); tap_code(KC_O); return false;
        case JP_FLYU: tap_code(KC_F); tap_code(KC_U); tap_code(KC_L); tap_code(KC_Y); tap_code(KC_U); return false;

        case JP_KULA: tap_code(KC_K); tap_code(KC_U); tap_code(KC_L); tap_code(KC_A); return false;
        case JP_GULA: tap_code(KC_G); tap_code(KC_U); tap_code(KC_L); tap_code(KC_A); return false;
        case JP_KULI: tap_code(KC_K); tap_code(KC_U); tap_code(KC_L); tap_code(KC_I); return false;
        case JP_GULI: tap_code(KC_G); tap_code(KC_U); tap_code(KC_L); tap_code(KC_I); return false;
        case JP_KULE: tap_code(KC_K); tap_code(KC_U); tap_code(KC_L); tap_code(KC_E); return false;
        case JP_GULE: tap_code(KC_G); tap_code(KC_U); tap_code(KC_L); tap_code(KC_E); return false;
        case JP_KULO: tap_code(KC_K); tap_code(KC_U); tap_code(KC_L); tap_code(KC_O); return false;
        case JP_GULO: tap_code(KC_G); tap_code(KC_U); tap_code(KC_L); tap_code(KC_O); return false;
        case JP_KULWA: tap_code(KC_K); tap_code(KC_U); tap_code(KC_L); tap_code(KC_W); tap_code(KC_A); return false;
        case JP_GULWA: tap_code(KC_G); tap_code(KC_U); tap_code(KC_L); tap_code(KC_W); tap_code(KC_A); return false;
    }

  return true;

}

void matrix_scan_user(void) {     // The very important timer. 
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}


// static bool scrolling_mode = false;

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//         // case _RAISE:  // If we're on the _RAISE layer enable scrolling mode
//         //     scrolling_mode = true;
//         //     pointing_device_set_cpi(2000);
//         //     break;
//         default:
//             if (scrolling_mode) {  // check if we were scrolling before and set disable if so
//                 scrolling_mode = false;
//                 pointing_device_set_cpi(8000);
//             }
//             break;
//     }
//     return state;
// }

// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     if (scrolling_mode) {
//         mouse_report.h = mouse_report.x;
//         mouse_report.v = mouse_report.y;
//         mouse_report.x = 0;
//         mouse_report.y = 0;
//     }
//     return mouse_report;
// }

// void keyboard_post_init_user(void) {
//   // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   //debug_keyboard=true;
//   debug_mouse=true;
// }