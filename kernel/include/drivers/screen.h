// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef DRIVER_SCREEN_H
#define DRIVER_SCREEN_H

#include "type.h"

#define panic(...)                                                                                      \
    {                                                                                                   \
        kprintf("***KERNEL PANIC*** in %s at line %d in function: %s\n", __FILE__, __LINE__, __func__); \
        kprintf(__VA_ARGS__);                                                                           \
        for (;;)                                                                                        \
            ;                                                                                           \
    }
#if 1
#define MODULE(name) static char *__MODULE_NAME = name;
#define mprint(...) __mprintf(__MODULE_NAME, __VA_ARGS__);
#else
#define MODULE(name)
#define mprint(...) \
    {               \
        ;           \
    }
#endif
#define kerror(...)                     \
    {                                   \
        kprintf("***KERNEL OOPS***: "); \
        kprintf(__VA_ARGS__);           \
    }
#define pidprint(...) kprintf(__VA_ARGS__);
#define BUG(...)                            \
    {                                       \
        kprintf("\n\n*** KERNEL BUG***: "); \
        kprintf(__VA_ARGS__);               \
        while (1)                           \
            ;                               \
    }

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0f
#define RED_ON_WHITE 0xf4

#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

void clear_screen();
int kprint_at(char *message, int col, int row);
int kprint(char *message);
int kprintChar(char ch);
int kprintInt(int integer);
void kprintln(char *message);
void kprint_backspace();

void __mprintf(char *m, ...);
int kprintf(const char *str, ...);

#endif