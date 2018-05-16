// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef DEV_TYPE_H
#define DEV_TYPE_H

#include "../type.h"

typedef int pid_t;
typedef s64 ino_t;
typedef s64 off_t;
typedef int dev_t;
typedef int mode_t;
typedef int nlink_t;
typedef int uid_t;
typedef int gid_t;
typedef int blksize_t;
typedef s64 blkcnt_t;

#define time_t s64

struct stat_fs
{
    dev_t st_dev;
    ino_t st_ino;
    mode_t st_mode;
    nlink_t st_nlink;
    uid_t st_uid;
    gid_t st_gid;
    dev_t st_rdev;
    off_t st_size;
    blksize_t st_blksize;
    blkcnt_t st_blocks;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
};

typedef struct
{
    u32 bgcol;
    u32 fgcol;
    u32 cx;
    u32 cy;
} CONSOLE;

typedef void (*cmd_handler)(char **);

typedef struct
{
    char *argc;
    char **argv;
    cmd_handler handler;
} cmd_t;

/*
 *	Interruption handler
 */
typedef void (*int_handler)(void);

#endif