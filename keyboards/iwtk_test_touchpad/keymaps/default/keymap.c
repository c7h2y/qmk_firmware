// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "drivers/sensors/azoteq_iqs5xx.h"

/* ---- 最小キーマップ（ダミー） ---- */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( KC_NO )
};

/* ポインタ初期化: 反転/パームリジェクト等をセット（必要なければ削除） */
void pointing_device_init_user(void) {
    // flip_x, flip_y, switch_xy, palm_reject, end_session
    azoteq_iqs5xx_set_xy_config(false, false, false, true, true);
    // レポートレート(ms)変更例: アクティブ時 10ms
    azoteq_iqs5xx_set_report_rate(10, AZOTEQ_IQS5XX_ACTIVE, true);
}

/* マウスレポートを少しだけ調整（移動速度やスクロール量） */
#define CURSOR_SCALE_PERCENT 100   // 100=等倍。大きくすると速くなる
#define SCROLL_SCALE_PERCENT  30   // 2本指スクロールが強すぎる場合は小さめ推奨

static int32_t agg_h = 0;
static int32_t agg_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t r) {
    // カーソル速度スケール
    r.x = (r.x * CURSOR_SCALE_PERCENT) / 100;
    r.y = (r.y * CURSOR_SCALE_PERCENT) / 100;

    // スクロールは加算して 1/100 単位で出力（ガタつき防止）
    agg_h += r.h * SCROLL_SCALE_PERCENT;
    agg_v += r.v * SCROLL_SCALE_PERCENT;
    int8_t out_h = agg_h / 100;
    int8_t out_v = agg_v / 100;
    agg_h -= out_h * 100;
    agg_v -= out_v * 100;
    r.h = out_h;
    r.v = out_v;

    return r;
}
