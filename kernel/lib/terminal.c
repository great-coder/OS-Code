/**
 * Copyright (c) 2018 M D
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

/*
 * Simple command-line parser for early boot.
 * Writen by Mohammad Dehghan
 */

#include "kernel/terminal.h"
#include "string.h"

static inline u8 vga_entry_color(enum vga_color fg, enum vga_color bg)
{
    return fg | bg << 4;
}

static inline u16 vga_entry(unsigned char uc, u8 color)
{
    return (u16)uc | (u16)color << 8;
}

size_t terminal_row;
size_t terminal_column;
u8 terminal_color;
u16 *terminal_buffer;

void terminal_init(void)
{
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    terminal_buffer = (u16 *)0xB8000;
    for (size_t y = 0; y < VGA_HEIGHT; y++)
    {
        for (size_t x = 0; x < VGA_WIDTH; x++)
        {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }
}

void terminal_setcolor(u8 color)
{
    terminal_color = color;
}

void terminal_putentryat(char c, u8 color, size_t x, size_t y)
{
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c)
{
    terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
    if (++terminal_column == VGA_WIDTH)
    {
        terminal_column = 0;
        if (++terminal_row == VGA_HEIGHT)
            terminal_row = 0;
    }
}

void terminal_write(const char *data, size_t size)
{
    for (size_t i = 0; i < size; i++)
        terminal_putchar(data[i]);
}

void terminal_writestring(const char *data)
{
    terminal_write(data, strlen(data));
}

void tokenizer(char *input, char **output)
{
    int j = 0, k = 0, l = 1;
    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        if (input[i] == ' ')
        {
            if (l == 0)
            {
                k = 0;
                ++j;
                l = 1;
            }
        }
        else
        {
            output[j][k++] = input[i];
            l = 0;
        }
    }
}

/*
 * <input>
 * input: char *
 * <return>
 * c : cmd_t
 * 
 * <example>
 * input:
 * "shutdown h now"
 * output:
 * c.argc = "shutdown",
 * c.argv[0] = "h",
 * c.argv[1] = "now"
 * c.handler = NULL
 */
cmd_t __parse__(char *input)
{
    cmd_t c;
    if (strlen(input) == 0)
    {
        c.argc = NULL;
        c.argv = NULL;
        return c;
    }
    char **output;
    tokenizer(input, output);
    c.argc = output[0];
    if (output[1] != NULL)
    {
        c.argv = &output[1];
    }
    else
    {
        c.argv = NULL;
    }
    return c;
}
