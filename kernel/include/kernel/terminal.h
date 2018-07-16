// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef KER_TER_H
#define KER_TER_H

#include "type.h"

/* Hardware text mode color constants. */
enum vga_color
{
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15,
};

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

u8 vga_entry_color(enum vga_color fg, enum vga_color bg);
u16 vga_entry(unsigned char, u8);
void terminal_init(void);
void terminal_setcolor(u8);
void terminal_putentryat(char, u8, size_t x, size_t y);
void terminal_putchar(char);
void terminal_write(const char *, size_t);
void terminal_writestring(const char *);

cmd_t __parse__(char *);
void __cmdline__(char *);

#endif