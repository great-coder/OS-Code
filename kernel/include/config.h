// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef CONFIG_H
#define CONFIG_H

#define KERNEL_NAME "eXtreme"
#define KERNEL_VERSION "0.0.2"
#define KERNEL_RELEASE_RING "alpha"
#define KERNEL_DATE __DATE__
#define KERNEL_TIME __TIME__
#define KERNEL_LICENCE "MIT"
#define KERNEL_MACHINENAME "root"
#define OS_NAME "VOS"

// #ifndef __x86__
// #define __x86__
// #else
// #define KERNEL_PROCESSOR_IDENTIFIER "NULL"
// #endif

#define KERNEL_PROCESSOR_IDENTIFIER "x86"

#define CONFIG_MAX_FILE 32

#endif