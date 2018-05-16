# Copyright (c) 2018 M D
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

ARCH = x86

run:
	@echo "Building libraries objects"
	$(MAKE) -C ./lib
	@echo "Building "$(ARCH)" architecture kernel"
	$(MAKE) -C ./arch/$(ARCH)
# 	vos.bin

# vos.bin: ./arch/$(ARCH)/boot/bootsect.bin ./arch/$(ARCH)/kernel.bin
# 	cat $^ > vos.bin

clean:
	$(MAKE) -C ./lib clean
	$(MAKE) -C ./arch/$(ARCH) clean
	rm -rf vos.bin