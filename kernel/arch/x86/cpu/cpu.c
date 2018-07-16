/**
 * Copyright (c) 2018 M D
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "cpu/cpu.h"

// CPUID
/*
 * TODO: GCC has a <cpuid.h> header you should use instead of this.
 * It has already included in cpu.h
 */
void cpuid(int code, u32 *a, u32 *d)
{
    asm volatile("cpuid"
                 : "=a"(*a), "=d"(*d)
                 : "0"(code)
                 : "ebx", "ecx");
}

// RDTSC
/*
 * This can be used to find out how much time it takes to do certain
 * functions, very useful for testing/benchmarking /etc. Note: This is
 * only an approximation.
 */
u64 rdtsc()
{
    u64 ret;
    asm volatile("rdtsc"
                 : "=A"(ret));
    return ret;
}

// READ_CRx
unsigned long read_cr0(void)
{
    unsigned long val;
    asm volatile("mov %%cr0, %0"
                 : "=r"(val));
    return val;
}

// INVLPG
void invlpg(void *m)
{
    /*
     * Clobber memory to avoid optimizer re-ordering access before invlpg,
     * which may cause nasty bugs.
     */
    asm volatile("invlpg (%0)"
                 :
                 : "b"(m)
                 : "memory");
}

// WRMSR
void wrmsr(u32 msr_id, u64 msr_value)
{
    asm volatile("wrmsr"
                 :
                 : "c"(msr_id), "A"(msr_value));
}

// RDMSR
u64 rdmsr(u32 msr_id)
{
    u64 msr_value;
    asm volatile("rdmsr"
                 : "=A"(msr_value)
                 : "c"(msr_id));
    return msr_value;
}
