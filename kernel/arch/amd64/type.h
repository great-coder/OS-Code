// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef X64_TYPE_H
#define X64_TYPE_H

#include "../../include/type.h"

typedef struct
{
    u16 low_offset; // offset bits 0..15
    u16 selector; // a code segment selector in GDT or LDT
    u8 ist;       // bits 0..2 holds Interrupt Stack Table offset, rest of bits zero.
    u8 type_attr; // type and attributes
    u16 mid_offset; // offset bits 16..31
    u32 high_offset; // offset bits 32..63
    u32 zero;     // reserved
} __attribute__((packed)) idt_descriptor_t;

#endif