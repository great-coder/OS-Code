/**
 * Copyright (c) 2018 M D
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "drivers/keyboard.h"
#include "cpu/ports.h"
#include "cpu/idt.h"
#include "drivers/screen.h"
#include "string.h"
#include "system/function.h"
#include "kernel/terminal.h"
#include "../type.h"

MODULE("KEY");

/*
PS/2 keyboard code.
Dependencies:
inb function and scancode table.
*/
char getScancode()
{
    char c = 0;
    do
    {
        if (inb(0x60) != c)
        {
            c = inb(0x60);
            if (c > 0)
                return c;
        }
    } while (1);
}

char getchar()
{
    return scancode[getScancode() + 1];
}

static void keyboard_callback(registers_t *regs)
{
    char key = getchar();
    if ((key - 1) == BACKSPACE)
    {
        if (strlen(key_buffer) != 0)
        {
            kprint_backspace();
        }
        backspace(key_buffer);
    }
    else if ((key - 1) == ENTER)
    {
        kprint("\n");
        __cmdline__(key_buffer);
        key_buffer[0] = '\0';
    }
    else
    {
        char str[2] = {key, '\0'};
        append(key_buffer, key);
        kprint(str);
    }
    UNUSEDFUN(regs);
}

void init_keyboard()
{
    mprint("Keyboard init sequence activated ...\n");
    register_interrupt_handler(IRQ1, keyboard_callback);
}
