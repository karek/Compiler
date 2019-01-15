.data
_CSL0:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	call p
	add $0, %esp
_lab1:   # expr
	push $1
	call printInt
	add $4, %esp
_lab2:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
p:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	movl %ebp, %esp
	pop %ebp
	ret

