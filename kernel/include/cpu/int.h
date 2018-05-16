// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef CPU_INT_H
#define CPU_INT_H

#include "type.h"

/*
 * Returns a true boolean value if irq are enabled for the CPU.
 */
static inline u8 are_interrupts_enabled();

/*
 * Define a new interrupt table.
 */
static inline void lidt(void *base, u16 size);

#endif