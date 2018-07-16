/**
 * Copyright (c) 2018 M D
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "cpu/ports.h"

// OUTx
void outb(u16 port, u8 val)
{
    asm volatile("outb %0, %1"
                 :
                 : "a"(val), "Nd"(port));
    /* There's an outb %al, $imm8  encoding, for compile-time constant port
     * numbers that fit in 8b.  (N constraint).
     * Wider immediate constants would be truncated at assemble-time
     * (e.g. "i" constraint).
     * The  outb  %al, %dx  encoding is the only option for all other cases.
     * %1 expands to %dx because  port  is a u16.
     * %w1 could be used if we had the port number a wider C type
     */
}

void outw(u16 port, u16 val)
{
    asm volatile("out %%ax, %%dx"
                 :
                 : "a"(val), "d"(port));
}

void outd(u16 port, u32 val)
{
    asm volatile("outl %%eax, %%dx"
                 :
                 : "d"(port), "a"(val));
}

// INx
u8 inb(u16 port)
{
    u16 ret;
    asm volatile("inb %1, %0"
                 : "=a"(ret)
                 : "Nd"(port));
    return ret;
}

u16 inw(u16 port)
{
    u16 ret;
    asm("in %%dx, %%ax"
        : "=a"(ret)
        : "d"(port));
    return ret;
}

u32 ind(u16 port)
{
    u32 ret;
    asm volatile("inl %%dx, %%eax"
                 : "=a"(ret)
                 : "d"(port));
    return ret;
}

// IO_WAIT
void io_wait(void)
{
    /* Port 0x80 is used for 'checkpoints' during POST. */
    /* The Linux kernel seems to think it is free for use :-/ */
    asm volatile("outb %%al, $0x80"
                 :
                 : "a"(0));
    /* %%al instead of %0 makes no difference.
     * TODO: does the register need to be zeroed?
     */
}
