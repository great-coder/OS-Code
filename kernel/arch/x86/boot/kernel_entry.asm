; Copyright (c) 2018 M D
; 
; This software is released under the MIT License.
; https://opensource.org/licenses/MIT

global _start
[bits 32]

_start:
    [extern kernel_main]
    call kernel_main
    jmp $