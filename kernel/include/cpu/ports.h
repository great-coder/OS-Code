// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef CPU_PORTS_H
#define CPU_PORTS_H

#include "type.h"

/*
 * Sends a 8/16/32-bit value on a I/O location. Traditional names are outb,
 * outw and outl respectively. The a modifier enforces val to be placed in
 * the eax register before the asm command is issued and Nd allows for one-byte
 * constant values to be assembled as constants, freeing the edx register for
 * other cases.
 */
static inline void outb(u16 port, u8 val);
static inline void outw(u16 port, u16 val);
static inline void outd(u16 port, u32 val);

/*
 * Receives a 8/16/32-bit value from an I/O location. Traditional names are inb,
 * inw and inl respectively.
 */
static inline u8 inb(u16 port);
static inline u16 inw(u16 port);
static inline u32 ind(u16 port);

/*
 * Forces the CPU to wait for an I/O operation to complete. only use this when
 * there's nothing like a status register or an IRQ to tell you the info has
 * been received.
 */
static inline void io_wait(void);

/*
 * Alternatively, you may use another I/O cycle on an 'unused' port (which has the
 * nice property of being CPU-speed independent):
 */
static inline void io_wait(void);

#endif