.data
_CSL0:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	jmp _lab1
_lab1:
	push $1
	call printInt
	add $4, %esp
_lab3:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
_lab2:

