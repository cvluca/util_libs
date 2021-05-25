/*
 * Copyright 2017, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#define UART0_PADDR  0x01c28000
#define UART1_PADDR  0x01c28400
#define UART2_PADDR  0x01c28800
#define UART3_PADDR  0x01c28c00
#define UART4_PADDR  0x01c29000
#define UART5_PADDR  0x01c29400
#define UART6_PADDR  0x01c29800
#define UART7_PADDR  0x01c29c00

#define UART0_IRQ    33
#define UART1_IRQ    34
#define UART2_IRQ    35
#define UART3_IRQ    36
#define UART4_IRQ    49
#define UART5_IRQ    50
#define UART6_IRQ    51
#define UART7_IRQ    52

/* official device names */
enum chardev_id {
    /* Aliases */
    PS_SERIAL0,
    PS_SERIAL1,
    PS_SERIAL2,
    PS_SERIAL3,
    PS_SERIAL4,
    PS_SERIAL5,
    PS_SERIAL6,
    PS_SERIAL7,
    /* defaults */
    PS_SERIAL_DEFAULT = PS_SERIAL0
};

#define DEFAULT_SERIAL_PADDR UART0_PADDR
#define DEFAULT_SERIAL_INTERRUPT UART0_IRQ
