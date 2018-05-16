// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef SYS_MTX_H
#define SYS_MTX_H

#include "type.h"

typedef struct
{
    u8 locked;
} mutex;

#define DEFINE_MUTEX(name) static mutex name = {.locked = 0};

extern void mutex_lock(mutex *m);
extern void mutex_unlock(mutex *m);

#endif