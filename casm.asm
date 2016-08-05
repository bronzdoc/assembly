;; Build
;; nasm -f elf64 -o casm.o casm.asm
;; gcc casm.o casm.c -o casm
section .data
	WRITE_SYS_CALL equ 1
	STDOUT equ 1


section .text
global printFromAsm
printFromAsm:
	;; Arg1
	mov r10, rdi
	;; Arg2
	mov r11, rsi
	mov rax, WRITE_SYS_CALL
	mov rdi, STDOUT
	mov rsi, r10
	mov rdx, r11
	syscall
	ret

