TITLE Lab3 Part1 Prog2
; Author: Firzana and Haani sec 03
; Date: 29 Jun 2024

include Irvine32.inc


.data
str1 BYTE "Calculate SUM (unsign INT) index (ODD or EVEN) in Array Hello[6] : ", 0
str2 BYTE "Integer Input : ", 0
str3 BYTE "Result Sum HELLO[index] : ", 0
str4 BYTE "Sum HELLO[Even] index location : ", 0
str5 BYTE "Sum HELLO[Odd] index location : ", 0
HELLO DWORD 6 dup (0h)
totalEven DWORD ?
totalOdd DWORD ?


.code
main proc

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

exit

main ENDP

END main