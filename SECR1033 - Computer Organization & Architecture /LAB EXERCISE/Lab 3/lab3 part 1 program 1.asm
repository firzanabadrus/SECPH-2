TITLE Program 1 Calculate Perimeter Hexagon

; Author: Nur Firzana Binti Badrus Hisham
; Date: 28 June 2024

INCLUDE Irvine32.inc

.data

	; define variable
	sideHex1 DWORD ?
	sideHex2 DWORD ?
	Perimeter_Hexagon1 DWORD ?
	Perimeter_Hexagon2 DWORD ?
	TotalPerimeter DWORD ?

	title1 BYTE "Calculate Perimeter 2-Hexagon (LOOP and ADD instructions) :  ", 0
	message0 BYTE "Input Hexagon 1 (side length) : ", 0
	message1 BYTE "Input Hexagon 2 (side length) : ", 0
	message2 BYTE "Result of Perimeter Hexagon 1 and 2: ", 0
	message3 BYTE "Total Perimeter Hexagon 1 and 2 : ", 0


.code
	main proc

startProg :

	mov EDX, OFFSET title1
	call WriteString
	call crlf
	call crlf

	mov EDX, offset message0
	call WriteString
	call ReadDec
	jnc input_hex1

input_hex1:
	mov sideHex1, EAX
	mov ECX, 5  ;hexagon->6

loop_hex1:
	add EAX, sideHex1
	loop loop_hex1
	mov Perimeter_Hexagon1, EAX



	mov EDX, OFFSET message1
	call WriteString
	call ReadDec
	jnc input_hex2

input_hex2:
	mov sideHex2, EAX
	mov ECX, 5

loop_hex2:
	add EAX, sideHex2
	loop loop_hex2
	mov Perimeter_Hexagon2, EAX


	;display perimeter hex1 and hex2
	call crlf
	mov EDX, OFFSET message2
	call WriteString
	call crlf
	mov EAX, Perimeter_Hexagon1
	call WriteDec
	call crlf
	mov EAX, Perimeter_Hexagon2
	call WriteDec
	call crlf


	mov EAX, Perimeter_Hexagon1
	add EAX, Perimeter_Hexagon2
	
	; store result 2 hexagon
	mov TotalPerimeter, EAX


	; display result
	call crlf
	mov edx, offset message3
	call WriteString
	mov eax, TotalPerimeter
	call WriteDec
	call crlf
	call crlf


exit

main ENDP

END main