// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef MEM_MEM_H
#define MEM_MEM_H

#include "type.h"

/*
 * Read a 8/16/32-bit value at a given memory location using another segment
 * than the default C data segment. Unfortunately there is no constraint for
 * manipulating segment registers directly, so issuing the mov <reg>, <segmentreg>
 * manually is required.
 */
static inline u32 farpeekl(u16 sel, void *off);

/*
 * Write a 8/16/32-bit value to a segment:offset address too. Note that much
 * like in farpeek, this version of farpoke saves and restore the segment register
 * used for the access.
 */
static inline void farpokeb(u16 sel, void *off, u8 v);

#endif