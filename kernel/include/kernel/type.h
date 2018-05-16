// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef KER_TYPE_H
#define KER_TYPE_H

#include <stdint.h>
#include "../type.h"

/*
 *	General C-Types
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

typedef unsigned char u_char;

typedef unsigned int size_t;

/*
 *	Asm Macro
 */
#define asm __asm__
#define asmv __asm__ __volatile__

#endif