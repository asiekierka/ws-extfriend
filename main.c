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

#include <stdio.h>
#include "config.h"
#include "pico/multicore.h"
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/uart.h"
#include "headphone.h"
#include "info.h"
#include "uart.h"
#include "usb.h"

#include "tusb.h"

void core_tud(void) {
    while (true) {
        tud_task();
    }
}

int main() {
    led_init();

#ifdef MEMPHIS_DEBUG
    stdio_uart_init_full(uart1, 921600, MEMPHIS_DEBUG_UART_TX_PIN, MEMPHIS_DEBUG_UART_RX_PIN);
    gpio_set_function(MEMPHIS_DEBUG_UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(MEMPHIS_DEBUG_UART_RX_PIN, GPIO_FUNC_UART);
#endif

    usb_init();

    ws_headphone_init();
    ws_uart_init();

    multicore_launch_core1(core_tud);
    while (true) { __wfi(); }

    return 0;
}
