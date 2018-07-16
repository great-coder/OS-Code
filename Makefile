# Copyright (c) 2018 M D
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

PLATFORMS= `ls kernel/arch/ | sort`

help:
	@echo
	@echo "Makefile for Building VOS Operating System"
	@echo "Please see LICENSE for licensing information"
	@echo "Currently supported platforms:"
	@echo $(PLATFORMS)
	@echo "Usage: make [ vos | clean | help ] "
	@echo "  vos command will compile files and make an output file (like iso, bin, ...)"
	@echo "  clean command will delete all generated files during compile"
	@echo "You can change target architecture by changing the ARCH value in kernel/Makfile, default is x86 platform"
	@echo

vos:
	$(MAKE) -C ./kernel
	iso

iso:
	@cp ./kernel/vos.bin ./isodir/boot/vos.bin
	@grub-mkrescue -o vos.iso isodir

clean:
	$(MAKE) -C ./kernel clean
	rm -rf isodir/boot/vos.bin
	rm -rf isodir/vos.iso