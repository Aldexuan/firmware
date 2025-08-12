/*
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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

/* Handedness. */
//#define MASTER_RIGHT

// To use the handedness pin, resistors need to be installed on the adapter PCB.
// If so, uncomment the following code, and undefine MASTER_RIGHT above.
 #define SPLIT_HAND_PIN GP15
 #define SPLIT_HAND_PIN_LOW_IS_LEFT  // High -> right, Low -> left.

/* VBUS detection. */
#define USB_VBUS_PIN GP19

/* SPI & PMW3360 settings. */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP23
#define PMW33XX_CS_PIN GP16

/* Reset. */
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP1
#define SERIAL_USART_RX_PIN GP0
//TX主半部必须与RX从半部的引脚相连，RX主半部必须与TX从半部的引脚相连
//这个配置可以在内部直接交换，不需要在物理pcb交换
#define SERIAL_USART_PIN_SWAP

#define TAP_CODE_DELAY 10

#ifdef OLED_ENABLE
/* 使用 QMK 提供的分割传输时，确保当前层状态在从站上可用。 */
#define SPLIT_LAYER_STATE_ENABLE
/* 确保使用 QMK 提供的拆分传输时，当前主机指示器状态 (caps/num/scroll) 在从属设备上可用 */
#define SPLIT_LED_STATE_ENABLE
/* 使用 QMK 提供的分割传输时，确保当前修改器状态（正常、弱和单次）在从属设备上可用 */
#define SPLIT_MODS_ENABLE
/* 同步两半之间 OLED 的开/关状态。 */
#define SPLIT_OLED_ENABLE
/* 使用 QMK 提供的分割传输时，确保当前 WPM 在从属设备上可用 */
#define SPLIT_WPM_ENABLE
#define OLED_FONT_H "keyboards/trackballseries/39_ctc/keymaps/vial/glcdfont.c"
#define OLED_TIMEOUT 50000
#endif

//解决从机休眠后无法唤醒问题
//#define FORCED_SYNC_THROTTLE_MS 100
#define CHARYBDIS_CONFIG_SYNC
