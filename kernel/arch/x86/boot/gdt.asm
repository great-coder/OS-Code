; Copyright (c) 2018 M D
; 
; This software is released under the MIT License.
; https://opensource.org/licenses/MIT

gdt_start:
    dd 0x0
    dd 0x0

sd_code: 
    dw 0xffff
    dw 0x0
    db 0x0
    db 10011010b
    db 11001111b
    db 0x0

sd_data:
	dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0

gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

CODE_SEG equ sd_code - gdt_start
DATA_SEG equ sd_data - gdt_start