/**
 * Copyright (c) 2018 M D
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "drivers/screen.h"
#include <stddef.h>
#include <stdarg.h>
#include "cpu/ports.h"
#include "string.h"

int get_cursor_offset();
void set_cursor_offset(int offset);
int print_char(char c, int col, int row, char attr);
int get_offset(int col, int row);
int get_offset_row(int offset);
int get_offset_col(int offset);

int kprint_at(char *message, int col, int row)
{
    int offset;
    if (col >= 0 && row >= 0)
        offset = get_offset(col, row);
    else
    {
        offset = get_cursor_offset();
        row = get_offset_row(offset);
        col = get_offset_col(offset);
    }
    int i = 0;
    while (message[i] != 0)
    {
        offset = print_char(message[i++], col, row, WHITE_ON_BLACK);
        row = get_offset_row(offset);
        col = get_offset_col(offset);
    }
    return get_offset(col, row);
}

int kprint(char *message)
{
    return kprint_at(message, -1, -1);
}

int kprintChar(char ch)
{
    char *msg = NULL;
    msg[0] = ch;
    msg[1] = '\0';
    return kprint(msg);
}

int kprintInt(int integer)
{
    char *msg = NULL;
    int_to_ascii(integer, msg);
    return kprint(msg);
}

void kprintln(char *message)
{
    kprint("\n");
    kprint(message);
}

void kprint_backspace()
{
    int offset = get_cursor_offset() - 2;
    int row = get_offset_row(offset);
    int col = get_offset_col(offset);
    print_char(0x08, col, row, WHITE_ON_BLACK);
}

int print_char(char c, int col, int row, char attr)
{
    u8 *vidmem = (u8 *)VIDEO_ADDRESS;
    if (!attr)
        attr = WHITE_ON_BLACK;

    if (col >= MAX_COLS || row >= MAX_ROWS)
    {
        vidmem[2 * (MAX_COLS) * (MAX_ROWS)-2] = 'E';
        vidmem[2 * (MAX_COLS) * (MAX_ROWS)-1] = RED_ON_WHITE;
        return get_offset(col, row);
    }

    int offset;
    if (col >= 0 && row >= 0)
        offset = get_offset(col, row);
    else
        offset = get_cursor_offset();

    if (c == '\n')
    {
        row = get_offset_row(offset);
        offset = get_offset(0, row + 1);
    }
    else if (c == 0x08)
    {
        vidmem[offset] = ' ';
        vidmem[offset + 1] = attr;
    }
    else
    {
        vidmem[offset] = c;
        vidmem[offset + 1] = attr;
        offset += 2;
    }

    if (offset >= MAX_ROWS * MAX_COLS * 2)
    {
        int i;
        for (i = 1; i < MAX_ROWS; i++)
            memcpy((u8 *)(get_offset(0, i - 1) + VIDEO_ADDRESS),
                   (u8 *)(get_offset(0, i) + VIDEO_ADDRESS),
                   MAX_COLS * 2);

        char *last_line = (char *)(get_offset(0, MAX_ROWS - 1) + (u8 *)VIDEO_ADDRESS);
        for (i = 0; i < MAX_COLS * 2; i++)
            last_line[i] = 0;

        offset -= 2 * MAX_COLS;
    }

    set_cursor_offset(offset);
    return offset;
}

int get_cursor_offset()
{
    outb(REG_SCREEN_CTRL, 14);
    int offset = inb(REG_SCREEN_DATA) << 8;
    outb(REG_SCREEN_CTRL, 15);
    offset += inb(REG_SCREEN_DATA);
    return offset * 2;
}

void set_cursor_offset(int offset)
{
    offset /= 2;
    outb(REG_SCREEN_CTRL, 14);
    outb(REG_SCREEN_DATA, (u8)(offset >> 8));
    outb(REG_SCREEN_CTRL, 15);
    outb(REG_SCREEN_DATA, (u8)(offset & 0xff));
}

void clear_screen()
{
    int screen_size = MAX_COLS * MAX_ROWS;
    int i;
    u8 *screen = (u8 *)VIDEO_ADDRESS;

    for (i = 0; i < screen_size; i++)
    {
        screen[i * 2] = ' ';
        screen[i * 2 + 1] = WHITE_ON_BLACK;
    }
    set_cursor_offset(get_offset(0, 0));
}

int get_offset(int col, int row) { return 2 * (row * MAX_COLS + col); }
int get_offset_row(int offset) { return offset / (2 * MAX_COLS); }
int get_offset_col(int offset) { return (offset - (get_offset_row(offset) * 2 * MAX_COLS)) / 2; }

char tbuf[32];
char bchars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void __itoa(u32 i, unsigned base, char *buf)
{
    int pos = 0;
    int opos = 0;
    int top = 0;

    if (i == 0 || base > 16)
    {
        buf[0] = '0';
        buf[1] = '\0';
        return;
    }

    while (i != 0)
    {
        tbuf[pos] = bchars[i % base];
        pos++;
        i /= base;
    }
    top = pos--;
    for (opos = 0; opos < top; pos--, opos++)
        buf[opos] = tbuf[pos];
    buf[opos] = 0;
}

void __itoa_s(u32 i, unsigned base, char *buf)
{
    if (base > 16)
        return;
    if (i < 0)
    {
        *buf++ = '-';
        i *= -1;
    }
    __itoa(i, base, buf);
}

void __mprintf(char *m, ...)
{
    va_list ap;
    va_start(ap, m);
    kprintf("[%s]: ", m);
    char *fmt = va_arg(ap, char *);
    __kprintf_va_list(fmt, ap);
}

/* abstraction methods */
int kprintf(const char *str, ...)
{
    if (!str)
        return 0;
    va_list ap;
    va_start(ap, str);
    __kprintf_va_list((char *)str, ap);
    return 1;
}

void __kprintf_va_list(char *str, va_list ap)
{
    char *s = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '%')
        {
            switch (str[i + 1])
            {
            /** string **/
            case 's':
                s = va_arg(ap, char *);
                kprint(s);
                i++;
                continue;
            /** decimal **/
            case 'd':
            {
                u32 c = va_arg(ap, u32);
                char str[32] = {0};
                __itoa_s(c, 10, str);
                kprint(str);
                i++;
                continue;
            }
            case 'x':
            {
                u32 c = va_arg(ap, u32);
                char str[32] = {0};
                __itoa(c, 16, str);
                kprint(str);
                i++;
                continue;
            }
            /** character **/
            case 'c':
            {
                // char gets promoted to int for va_arg!
                // clean it.
                char c = (char)(va_arg(ap, int) & ~0xFFFFFF00);
                kprintChar(c);
                i++;
                continue;
            }
            default:
                break;
            }
        }
        else
        {
            kprintChar(str[i]);
        }
    }
    va_end(ap);
}