# Copyright (c) 2018 M D
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

INC_DIR = ../../include
HEADERS = $(wildcard *.h $(INC_DIR)/*.h $(INC_DIR)/memory/*.h $(INC_DIR)/kernel/*.h $(INC_DIR)/system/*.h $(INC_DIR)/drivers/*.h $(INC_DIR)/cpu/*.h)
C_SOURCES = $(wildcard kernel/*.c cpu/*.c drivers/*.c memory/*.c)

OBJ = ${C_SOURCES:.c=.o}

CC = gcc
GDB = gdb

CFLAGS = -g -ffreestanding -Wall -I$(INC_DIR) -Wextra -fno-exceptions -m32

vos.bin: boot/bootsect.bin kernel.bin
	cat $^ > ../../vos.bin

kernel.bin: boot/kernel_entry.o ${OBJ}
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

kernel.elf: boot/kernel_entry.o ${OBJ}
	ld -m elf_i386 -o $@ -T linker.ld $^ 

run: vos.bin
# 	qemu-system-i386 -fda vos.bin

#run: boot/boot.o kernel.bin

debug: os-image.bin kernel.elf
	qemu-system-i386 -s -fda os-image.bin -d guest_errors,int &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

%.o: %.asm
	nasm $< -f elf32 -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf *.bin *.dis *.o *.elf
	rm -rf boot/*.bin boot/*.o cpu/*.bin cpu/*.o drivers/*.o kernel/*.o memory/*.o