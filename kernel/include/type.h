// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef TYPE_H
#define TYPE_H

#include "kernel/type.h"
#include "system/type.h"
#include "memory/type.h"
#include "cpu/type.h"
#include "drivers/type.h"

#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif
#ifndef NULL
#define NULL ((void *)0)
#endif
#ifndef EOF
#define EOF (-1)
#endif

/*
* Return code
*/
enum
{
    RETURN_OK = 1,
    RETURN_NOT_DEFINED = -1,
    RETURN_ERROR_MEMORY = -2,
    RETURN_PARAM_NULL = -3,
    RETURN_ERROR_PARAM = -4,
    RETURN_FAILURE = -128
};

// This works in 32 and 64 bit mode
typedef struct
{
    u16 limit;
    void *base;
} __attribute__((packed)) idt_register_t;

#endif