.data
_CSL0:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $8, %esp
	movl $0, -4(%ebp)
	movl $0, -8(%ebp)
	push $45
	pop %ecx
	lea -4(, %ebp, 1), %eax
	movl %ecx, (%eax)
	push $36
	pop %ecx
	neg %ecx
	push %ecx
	pop %ecx
	lea -8(, %ebp, 1), %eax
	movl %ecx, (%eax)
	push -4(%ebp)
	call printInt
	add $4, %esp
_lab1:   # expr
	push -8(%ebp)
	call printInt
	add $4, %esp
_lab2:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret

