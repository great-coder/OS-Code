/**
 * Copyright (c) 2018 M D
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "cpu/isr.h"
#include "cpu/idt.h"
#include "kernel/terminal.h"
#include "drivers/screen.h"
#include "config.h"

MODULE("MAIN");

void kernel_main(void)
{
    isr_install();
    irq_install();

    kprintf("System Specification:\n");
    kprintf("OS name: %s\n", OS_NAME);
    kprintf("Kernel name: %s\n", KERNEL_NAME);
    kprintf("Kernel version: %s\n", KERNEL_VERSION);
    kprintf("Kernel development ring: %s\n", KERNEL_RELEASE_RING);
    kprintf("Kernel release date: %s\n", KERNEL_DATE);
    kprintf("Kernel release time: %s\n", KERNEL_TIME);
    kprintf("Kernel target platform: %s\n", KERNEL_PROCESSOR_IDENTIFIER);
    kprintf("Kernel license: %s\n", KERNEL_LICENCE);

    if (are_interrupts_enabled() == 1)
    {
        kprint("Interrupts are successfully ENABLED! ...\n");
        asm("int $2");
        asm("int $3");
        terminal_init();
        kprintf("\n%s:~$", KERNEL_MACHINENAME);
    }
    else
    {
        kerror("Interrupts are not enable!\nEnable them first...\n");
    }
}

void __cmdline__(char *input)
{
    // callCommand(__parse__(input));
    kprintf("\nYou have typed: %s", input);
    kprintf("\n%s:~$", KERNEL_MACHINENAME);
}
