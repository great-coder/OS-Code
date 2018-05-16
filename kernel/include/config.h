// Copyright (c) 2018 M D
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef CONFIG_H
#define CONFIG_H

#define KERNEL_NAME "eXtreme"
#define KERNEL_VERSION "0.0.1"
#define KERNEL_RELEASE_RING "ALPHA"
#define KERNEL_DATE __DATE__
#define KERNEL_TIME __TIME__
#define KERNEL_LICENCE "MIT"
#define KERNEL_MACHINENAME "root"
#define OS_NAME "VOS"

#ifdef __x86__
#define KERNEL_PROCESSOR_IDENTIFIER "x86"
#else
#define KERNEL_PROCESSOR_IDENTIFIER "NULL"
#endif

#define CONFIG_MAX_FILE 32

#endif