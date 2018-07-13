// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef CPU_IDT_H
#define CPU_IDT_H

#include "type.h"

/*
 * Returns a true boolean value if irq are enabled for the CPU.
 */
static inline u8 are_interrupts_enabled();

/*
 * Puts an interrupt in table
 */
void set_idt_gate(u8 i, u32 callback);

/*
 * Defines a new interrupt table.
 */
static inline void lidt();

#endif