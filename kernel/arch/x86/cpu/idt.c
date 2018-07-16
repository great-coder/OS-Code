/**
 * Copyright (c) 2018 M D
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "cpu/idt.h"
#include "../type.h"

#define KERNEL_CS 0x08
#define IDT_ENTRIES 256

idt_descriptor_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

// Enabled?
u8 are_interrupts_enabled()
{
    unsigned long flags;
    asm volatile("pushf\n\t"
                 "pop %0"
                 : "=g"(flags));
    return flags & (1 << 9);
}

void set_idt_gate(u8 i, u32 callback)
{
    idt[i].low_offset = low_16(callback);
    idt[i].selector = KERNEL_CS;
    idt[i].zero = 0;
    idt[i].type_attr = 0x8E;
    idt[i].high_offset = high_16(callback);
}

// LIDT
void lidt()
{
    // This function works in 32 and 64bit mode
    idt_reg.base = (u32)&idt; // For 64bit change this to u64
    idt_reg.limit = IDT_ENTRIES * sizeof(idt_descriptor_t) - 1;
    asm("lidt %0"
        :
        : "m"(idt_reg)); // let the compiler choose an addressing mode
}
