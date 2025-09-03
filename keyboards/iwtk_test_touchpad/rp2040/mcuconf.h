// keyboards/<your_kb>/rp2040/mcuconf.h
#pragma once
#include_next <mcuconf.h>   // 既定のRP2040用 mcuconf.h をまず取り込む

// ---- ここから差分だけ上書き（I2C1を使う） ----
#undef  RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 FALSE
#undef  RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE

// （保険）既定が拾えなかった場合でもビルドが止まらないよう軽いフォールバック
#ifndef RP2040_MCUCONF
#define RP2040_MCUCONF
#endif
#ifndef RP_IRQ_USB0_PRIORITY
#define RP_IRQ_USB0_PRIORITY 2
#endif
