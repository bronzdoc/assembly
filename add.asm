;File add.asm

%include "linux-ex/asm_io.inc"

;Initialized data
segment .data
	prompt1 db "type a number", 0
	prompt2 db "type another number", 0
	outmsg1 db "you typed ", 0
	outmsg2 db " and ", 0
	outmsg3 db ", the result is: ", 0

;Unitialized data
segment .bss
	input1 resd 1
	input2 resd 1

;Source code segment
segment .text
	global _asm_main

_asm_main:
		enter 0, 0              ;setup routine
		pusha

		mov   eax, prompt1      ;print the output
		call  print_string

		call  read_int          ;read an integer
		mov   [input1], eax     ;read_int will store the value in eax

		mov  eax, prompt2       ;print second prompt
		call print_string

		call read_int           ;read an integer
		mov [input2], eax       ;store read_int value in input2

		mov eax, [input1]
		add eax, [input2]       ;add and store the result in eax

		mov ebx, eax            ;ebx == eax

		dump_regs 1             ;print register values
		dump_mem 2, outmsg1, 1 ;print memory

		; Print results

		mov eax, outmsg1        ;print first message
		call print_string

		mov eax, [input1]       ;print input1
		call print_int

		mov eax, outmsg2        ;print second message
		call print_string

		mov eax, [input2]       ;print input 2
		call print_int

		mov eax, outmsg3        ;print third message
		call print_string

		mov eax, ebx            ;print the add result(ebx)
		call print_int

		call print_nl           ;print a new line

		popa
		mov eax, 0              ; return to c
		leave
		ret

