/**
 * Copyright (c) 2018 M D
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "cpu/int.h"

// Enabled?
static inline u8 are_interrupts_enabled()
{
    unsigned long flags;
    asm volatile("pushf\n\t"
                 "pop %0"
                 : "=g"(flags));
    return flags & (1 << 9);
}

// LIDT
static inline void lidt(void *base, u16 size)
{
    // This function works in 32 and 64bit mode
    struct
    {
        uint16_t length;
        void *base;
    } __attribute__((packed)) IDTR = {size, base};

    asm("lidt %0"
        :
        : "m"(IDTR)); // let the compiler choose an addressing mode
}
