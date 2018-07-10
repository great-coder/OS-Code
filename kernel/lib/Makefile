# Copyright (c) 2018 M D
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

INC_DIR = ../include
HEADERS = $(wildcard $(INC_DIR)/*.h $(INC_DIR)/memory/*.h $(INC_DIR)/kernel/*.h $(INC_DIR)/system/*.h $(INC_DIR)/drivers/*.h $(INC_DIR)/cpu/*.h)
C_SOURCES = $(wildcard *.c memory/*.c system/*.c)

CFLAGS = -g -ffreestanding -Wall -I$(INC_DIR) -Wextra -fno-exceptions -m32
OBJS = ${C_SOURCES:.c=.o}
CC = gcc

run: $(OBJS)

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf *.bin *.o
	rm -rf memory/*.o system/*.o