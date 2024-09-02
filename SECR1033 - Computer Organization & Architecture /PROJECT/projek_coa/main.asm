TITLE Project COA
; Author: Group 6
; Date: 14 / 7 / 2024


include Irvine32.inc

.data
capture_msec DWORD ?
N DWORD ?
sum DWORD ?
coef1 DWORD 9
coef2 DWORD 10
coef3 DWORD 12
coef4 DWORD 28

cyn BYTE ?
cY db 'y'
strbye BYTE "Thank you ... BYE!!", 0dh, 0ah, 0

str1 BYTE "Welcome to CPU Benchmark Program", 0
str2 BYTE "Benchmark CPU time Using Equation y = 9*x^3 + 10*x^2 + 12*x + 28", 0
str3 BYTE "			(with delay coef1, coef2, coef3, coef4 = 12,9,10,28 msec)" ,0
str4 BYTE "Enter Number of looping (N) = ", 0
str5 BYTE "CPU time Stress Test in Progress...", 0
str6 BYTE "Result: ", 0
str7 BYTE "First Capture Execution time in milisecond: ", 0
str8 BYTE "Second Capture Execution time in milisecond: ", 0
str9 BYTE "Different Execution time in milisecond: ", 0
str10 BYTE "Value of Sum from the Stress Test (polynomial) = ", 0
str11 BYTE "Press 'y' to continue or 'n' to exit the benchmark : ", 0

.code

main proc

main_p :
call Clrscr
mov EDX, OFFSET str1
call WriteString
call Crlf
call Crlf

mov EDX, OFFSET str2
call WriteString
call Crlf

mov EDX, OFFSET str3
call WriteString
call Crlf
call Crlf

mov EDX, OFFSET str4
call WriteString
call ReadDec
mov N, EAX
call Crlf

mov EDX, OFFSET str5
call WriteString
call Crlf
call Crlf

mov EDX, OFFSET str6
call WriteString
call Crlf
call Crlf

mov EDX, OFFSET str7
call WriteString
call GetMseconds; Get elapse before before math loop
mov  capture_msec, eax; save the capture time in msec
call WriteDec; display msec in decimal
call Crlf

mov ECX, N
mov EBX, N
mov sum, 0
math_loop :	mov EAX, coef1
call Delay
mul EBX
mul EBX
mul EBX
ADD sum, EAX

mov EAX, coef2
call Delay
mul EBX
mul EBX
ADD sum, EAX

mov EAX, coef3
call Delay
mul EBX
ADD sum, EAX

mov EAX, coef4; calc coef4
ADD sum, EAX
LOOP math_LOOP

mov EDX, OFFSET str8
call WriteString
call GetMseconds; Get elapse before after math loop
call WriteDec; display msec in decimal
call Crlf

mov EDX, OFFSET str9
call WriteString
mov EBX, capture_msec
SUB EAX, EBX
call WriteDec
call Crlf

mov EDX, OFFSET str10
call WriteString
mov EAX, sum
call WriteDec
call Crlf
call Crlf

mov EDX, OFFSET str11
call WriteString
call ReadChar
mov cyn, AL
call WriteChar
mov BL, cY
CMP BL, cyn
JE main_p
call Crlf
call Crlf
mov edx, OFFSET strbye
call WriteString

exit

main ENDP

END main