// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef X86_TYPE_H
#define X86_TYPE_H

#include "include/type.h"

#define low_16(address) (u16)((address)&0xFFFF)
#define high_16(address) (u16)(((address) >> 16) & 0xFFFF)

typedef struct
{
    u32 ds;
    u32 edi, esi, ebp, useless, ebx, edx, ecx, eax;
    u32 int_no, err_code;
    u32 eip, cs, eflags, esp, ss;
} registers_t;

typedef struct
{
    u16 low_offset;
    u16 sel;
    u8 always0;
    u8 flags;
    u16 high_offset;
} __attribute__((packed)) idt_gate_t;

typedef struct
{
    u16 limit;
    u32 base;
} __attribute__((packed)) idt_register_t;

typedef struct
{
    u16 offset_0_15;
    u16 selector;
    u8 zero;
    u8 type_attr;
    u16 offset_16_31;
} __attribute__((packed)) idt_descriptor;

#endif