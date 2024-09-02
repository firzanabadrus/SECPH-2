TITLE Lab 2 Question 5

; name: firzana and haani

include irvine32.inc


.code
main proc
		; Code Snippet 1 (MUL CX)
		MOV DX, 0		; Clear DX
		MOV AX, 1000h	; Load 1000h into AX
		MOV CX, 25h		; Load 25h into CX
		MUL CX			; Multiply AX by CX, storing the result in DX : AX
		call DumpRegs
		exit

main endp
end main

