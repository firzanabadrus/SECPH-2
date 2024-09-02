TITLE lab3
; Author: Firzana and Haani sec 03
; Date: 29 June 2024

include Irvine32.inc


.data
main1 BYTE "Welcome to Simple Math Activities : ", 0
main2 BYTE "Main Menu : ", 0
main3 BYTE "1. To Calculate Perimeter 2-Hexagon (LOOP and ADD instructions) :  ", 0
main4 BYTE "2. To Calculate SUM (unsign INT) index (ODD or EVEN) in Array Hello[6] : ", 0
main5 BYTE "Select Your Input : ", 0

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

str1 BYTE "Calculate SUM (unsign INT) index (ODD or EVEN) in Array Hello[6] : ", 0
str2 BYTE "Integer Input : ", 0
str3 BYTE "Result Sum HELLO[index] : ", 0
str4 BYTE "Sum HELLO[Even] index location : ", 0
str5 BYTE "Sum HELLO[Odd] index location : ", 0
HELLO DWORD 6 dup(0h)
totalEven DWORD ?
totalOdd DWORD ?

stryn BYTE "Press 'y' to Main Menu or 'n' to Exit the benchmark : ", 0
charIn BYTE ?
charY db 'y'
strbye BYTE "Thank you ... BYE!!", 0dh, 0ah, 0

.code

main proc

main_menu :
call Clrscr
mov edx, OFFSET main1
call WriteString
call Crlf
call Crlf
mov edx, OFFSET main2
call WriteString
call Crlf
call Crlf
mov edx, OFFSET main3
call WriteString
call Crlf
mov edx, OFFSET main4
call WriteString
call Crlf
call Crlf
mov edx, OFFSET main5
call WriteString

call ReadDec
CMP eax, 1
JE periHex_LoopAdd
JNE calSum_OddEven
; CMP eax, 2
; JE calSum_OddEven


periHex_LoopAdd :
call Clrscr
mov EDX, OFFSET title1
call WriteString
call crlf
call crlf

mov EDX, offset message0
call WriteString
call ReadDec
jnc input_hex1

input_hex1 :
mov sideHex1, EAX
mov ECX, 5; hexagon->6

loop_hex1:
add EAX, sideHex1
loop loop_hex1
mov Perimeter_Hexagon1, EAX



mov EDX, OFFSET message1
call WriteString
call ReadDec
jnc input_hex2

input_hex2 :
mov sideHex2, EAX
mov ECX, 5

loop_hex2 :
	add EAX, sideHex2
	loop loop_hex2
	mov Perimeter_Hexagon2, EAX


	; display perimeter hex1and hex2
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
	JMP yn_question


calSum_OddEven :
call Clrscr
mov edx, OFFSET str1
call WriteString
call Crlf
call Crlf
call Crlf

mov ecx, 6
mov ebx, 0
L1	:	mov edx, OFFSET str2
		call WriteString
		call ReadDec
		mov HELLO[ebx], eax
		add ebx, 4
		loop L1

mov ecx, 3
mov ebx, 0
mov totalOdd, 0
countODD :	mov eax, HELLO[ebx]
			add totalOdd, eax
			add ebx, 8
			loop countODD
mov ecx, 3
mov ebx, 4
mov totalEven, 0
countEVEN :	mov eax, HELLO[ebx]
			add totalEven, eax
			add ebx, 8
			loop countEVEN
call Crlf
call Crlf
mov edx, OFFSET str3
call WriteString
call Crlf
call Crlf
mov edx, OFFSET str4
call WriteString
mov eax, totalEven
call WriteDec
call Crlf
mov edx, OFFSET str5
call WriteString
mov eax, totalOdd
call WriteDec
call Crlf
call Crlf
JMP yn_question

yn_question :
mov edx, OFFSET stryn
call WriteString
call ReadChar
mov charIn, AL
call WriteChar
mov BL, charY
CMP BL, charIn
JE main_menu
call Crlf
call Crlf
mov edx, OFFSET strbye
call WriteString


exit

main ENDP

END main