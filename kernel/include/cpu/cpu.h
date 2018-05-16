// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef CPU_CPU_H
#define CPU_CPU_H

#include "type.h"
#include <cpuid.h>

/*
 * Request for CPU identification
 */
static inline void cpuid(int code, u32 *a, u32 *d);

/*
 * Read the current value of the CPU's time-stamp counter and store
 * into EDX:EAX. The time-stamp counter contains the amount of clock
 * ticks that have elapsed since the last CPU reset. The value is stored
 * in a 64-bit MSR and is incremented after each clock cycle.
 */
static inline u64 rdtsc();

/*
 * Read the value in a control register
 */
static inline unsigned long read_cr0(void);

/*
 * Invalidates the TLB (Translation Lookaside Buffer) for one specific
 * virtual address. The next memory reference for the page will be forced
 * to re-read PDE and PTE from main memory. Must be issued every time you
 * update one of those tables. The m pointer points to a logical address,
 * not a physical or virtual one: an offset for your ds segment.
 */
static inline void invlpg(void *m);

/*
 * Write a 64-bit value to a MSR. The A constraint stands for concatenation
 * of registers EAX and EDX.
 */
inline void wrmsr(u32 msr_id, u64 msr_value);

/*
 * Read a 64-bit value from a MSR. The A constraint stands for concatenation
 * of registers EAX and EDX.
 */
inline u64 rdmsr(u32 msr_id);

#endif