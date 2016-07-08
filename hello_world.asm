section .data
    string: db 'hello, world', 0Ah ; Output string
    length: equ 13                 ; Length of string
section .text
    global _start

_start:
	mov eax, 4            ; System call id sys_write
	mov ebx, 1            ; File descriptor for standard output
	mov ecx, string       ; String address
	mov edx, length       ; String length
	int 80h               ; System call

	mov eax, 1            ; System call for sys_exit
	mov ebx, 0            ; Exit code 0: no error
	int 80h               ; System call
