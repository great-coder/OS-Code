/**
 * Copyright (c) 2018 M D
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "gdt.h"

void create_descriptor(u32 base, u32 limit, u16 flag)
{
    u64 descriptor;

    // Create the high 32 bit segment
    descriptor = limit & 0x000F0000;         // set limit bits 19:16
    descriptor |= (flag << 8) & 0x00F0FF00;  // set type, p, dpl, s, g, d/b, l and avl fields
    descriptor |= (base >> 16) & 0x000000FF; // set base bits 23:16
    descriptor |= base & 0xFF000000;         // set base bits 31:24

    // Shift by 32 to allow for low part of segment
    descriptor <<= 32;

    // Create the low 32 bit segment
    descriptor |= base << 16;         // set base bits 15:0
    descriptor |= limit & 0x0000FFFF; // set limit bits 15:0

    printf("0x%.16llX\n", descriptor);
}

int gdt_init()
{
    create_descriptor(0, 0, 0);
    create_descriptor(0, 0x000FFFFF, (GDT_CODE_PL0));
    create_descriptor(0, 0x000FFFFF, (GDT_DATA_PL0));
    create_descriptor(0, 0x000FFFFF, (GDT_CODE_PL3));
    create_descriptor(0, 0x000FFFFF, (GDT_DATA_PL3));
    return 0;
}