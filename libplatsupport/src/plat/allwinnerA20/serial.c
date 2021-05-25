/*
 * Copyright 2017, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "../../chardev.h"
#include <string.h>
#include <stdlib.h>

#define UART_DLL             0x000
#define UART_RBR             0x000
#define UART_THR             0x000

#define UART_LSR             0x014
#define UART_LSR_DR          (1<<0)
#define UART_LSR_OE          (1<<1)
#define UART_LSR_PE          (1<<2)
#define UART_LSR_FE          (1<<3)
#define UART_LSR_BI          (1<<4)
#define UART_LSR_THRE        (1<<5)
#define UART_LSR_TEMT        (1<<6)
#define UART_LSR_FIFOERR     (1<<7)


#define REG_PTR(base, offset)  ((volatile uint32_t *)((char*)(base) + (offset)))

int uart_getchar(ps_chardevice_t* d)
{
    if (*REG_PTR(d->vaddr, UART_LSR) & UART_LSR_FIFOERR) {
        return *REG_PTR(d->vaddr, UART_RBR);
    } else {
        return -1;
    }
}

int uart_putchar(ps_chardevice_t* d, int c)
{
    if (*REG_PTR(d->vaddr, UART_LSR) & UART_LSR_TEMT) {
        *REG_PTR(d->vaddr, UART_THR) = c;
        return c;
    } else {
        return -1;
    }
}

static void uart_handle_irq(ps_chardevice_t* d)
{
    /* TODO */
}

int
uart_init(const struct dev_defn* defn,
          const ps_io_ops_t* ops,
          ps_chardevice_t* dev)
{
    void* vaddr = chardev_map(defn, ops);
    memset(dev, 0, sizeof(*dev));
    if (vaddr == NULL) {
        return -1;
    }
    dev->id         = defn->id;
    dev->vaddr      = vaddr;
    dev->read       = &uart_read;
    dev->write      = &uart_write;
    dev->handle_irq = &uart_handle_irq;
    dev->irqs       = defn->irqs;
    dev->ioops      = *ops;

    return 0;
}
