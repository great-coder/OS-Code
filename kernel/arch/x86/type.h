// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef X86_TYPE_H
#define X86_TYPE_H

#include "../../include/type.h"

typedef struct
{
    u32 ds;
    u32 edi, esi, ebp, useless, ebx, edx, ecx, eax;
    u32 int_no, err_code;
    u32 eip, cs, eflags, esp, ss;
} registers_t;

// This works in 32 and 64 bit mode
typedef struct
{
    u16 limit;
    void* base;
} __attribute__((packed)) idt_register_t;

typedef struct
{
    u16 low_offset;
    u16 selector;
    u8 zero;
    u8 type_attr;
    u16 high_offset;
} __attribute__((packed)) idt_descriptor_t;

#endif