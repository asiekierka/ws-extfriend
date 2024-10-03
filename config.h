/**
 * Copyright (c) 2022 Adrian Siekierka
 *
 * ExtFriend is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * ExtFriend is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with ExtFriend. If not, see <https://www.gnu.org/licenses/>. 
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "boards/pico.h"

// #define MEMPHIS_DEBUG
#define MEMPHIS_DEBUG_UART_TX_PIN 8
#define MEMPHIS_DEBUG_UART_RX_PIN 9
#define MEMPHIS_LED_PIN PICO_DEFAULT_LED_PIN

#define MEMPHIS_WS_UART_TX_PIN 0
#define MEMPHIS_WS_UART_RX_PIN 1
#define MEMPHIS_WS_HDPN_DETECT_PIN 2
#define MEMPHIS_WS_HDPN_DATA_PIN 3
#define MEMPHIS_WS_HDPN_CLK_PIN 4
#define MEMPHIS_WS_HDPN_FCLK_PIN 5

#define MEMPHIS_WS_HEADPHONE_BUFFER_FRAMES 24
#define MEMPHIS_WS_HEADPHONE_BUFFER_ENTRIES 8
#define MEMPHIS_WS_HEADPHONE_BUFFER_SAMPLES (MEMPHIS_WS_HEADPHONE_BUFFER_FRAMES * 2)

#endif /* __CONFIG_H__ */
