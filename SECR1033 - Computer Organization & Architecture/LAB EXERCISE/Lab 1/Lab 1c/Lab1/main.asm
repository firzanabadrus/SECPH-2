TITLE Addand Subtract, Version 3

; This program addsand subtracts 8 and 16 bit
; unsigned integersand stores the sum in a variable.
; Authors: Nur Firzana Binti Badrus Hisham
; Date: 23/04/2024
; Revision: Lab 1 c

INCLUDE Irvine32.inc

.data
valw1 WORD 1000h
valw2 WORD 4000h
valw3 WORD 2000h
finalValw WORD ?

valb1 BYTE 10h
valb2 BYTE 40h
valb3 BYTE 20h
finalValb BYTE ?

.code
main PROC
mov ax, valw1 ; start with 10000h
add ax, valw2 ; add 40000h
sub ax, valw3 ; subtract 20000h
mov finalValw, ax ; store the result(30000h)
call DumpRegs  ; display the registers

mov ah, valb1 ; start with 10000h
add ah, valb2 ; add 40000h
sub ah, valb3 ; subtract 20000h
mov finalValb, ah ; store the result(30000h)
call DumpRegs; display the registers

exit
main ENDP
END main