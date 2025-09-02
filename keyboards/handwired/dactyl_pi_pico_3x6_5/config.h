// Copyright 2023 Gustaw.xyz (@Gustaw.xyz)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP9
#define SERIAL_USART_RX_PIN GP8
// #define AZOTEQ_IQS5XX_TPS43
// #define SPLIT_POINTING_ENABLE
// #define POINTING_DEVICE_RIGHT true
// #define AZOTEQ_IQS5XX_SWIPE_X_ENABLE true
// #define AZOTEQ_IQS5XX_SWIPE_Y_ENABLE true
// #define AZOTEQ_IQS5XX_ZOOM_ENABLE true
// #define POINTING_DEVICE_DEBUG

// #define I2C0_SDA_PIN GP0
// #define I2C0_SCL_PIN GP1
// #define I2C_DRIVER I2CD1
// #define I2C1_SDA_PIN GP2
// #define I2C1_SCL_PIN GP3
// #define I2C1_CLOCK_SPEED 100000

// 既定アドレス（次に 0x45 / 0x74 44も試す）
// #define AZOTEQ_IQS5XX_ADDRESS 0x74
// （RDYを配線したなら任意で）
// #define AZOTEQ_IQS5XX_INT_PIN GP4
// もし NRST をGPIOへ配線したなら：
// #define AZOTEQ_IQS5XX_RST_PIN GP5
// Azoteq 割込みピン（配線したGPIOに合わせて）
// #define AZOTEQ_IQS5XX_INT_PIN GP4
// 必要ならデフォルトアドレス（未指定なら既定を使用）
// #define AZOTEQ_IQS5XX_ADDRESS 0x44
