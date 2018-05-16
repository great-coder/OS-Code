// Copyright (c) 2018 M D
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef SYS_CMD_H
#define SYS_CMD_H

#include "type.h"

void cmd_init();
void addCommand(cmd_t c);
void callCommand(cmd_t c);

#endif