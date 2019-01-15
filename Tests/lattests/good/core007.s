.data
_CSL0:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $4, %esp
	push $7
	pop %eax
	movl %eax, -4(%ebp)
	push -4(%ebp)
	call printInt
	add $4, %esp
_lab1:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret

