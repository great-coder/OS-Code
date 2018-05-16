/**
 * Copyright (c) 2018 M D
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "../cpu/gdt.h"
#include "kernel/terminal.h"

int kernel_main(void)
{
    gdt_init();
    terminal_init();
    terminal_writestring("Hello, kernel World!\n");

    return 0;
}
