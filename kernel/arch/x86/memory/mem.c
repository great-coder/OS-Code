/**
 * Copyright (c) 2018 M D
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "memory/mem.h"

// FAR_PEEKx
static inline u32 farpeekl(u16 sel, void *off)
{
    u32 ret;
    asm("push %%fs\n\t"
        "mov  %1, %%fs\n\t"
        "mov  %%fs:(%2), %0\n\t"
        "pop  %%fs"
        : "=r"(ret)
        : "g"(sel), "r"(off));
    return ret;
}

// FAR_POKEx
static inline void farpokeb(u16 sel, void *off, u8 v)
{
    asm("push %%fs\n\t"
        "mov  %0, %%fs\n\t"
        "movb %2, %%fs:(%1)\n\t"
        "pop %%fs"
        :
        : "g"(sel), "r"(off), "r"(v));
    /* TODO: Should "memory" be in the clobber list here? */
}
