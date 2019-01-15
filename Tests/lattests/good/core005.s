.data
_CSL0:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $8, %esp
	movl $0, -4(%ebp)
	push $56
	pop %eax
	movl %eax, -8(%ebp)
	push -8(%ebp)
	push $45
	pop %ecx
	pop %eax
	add %ecx, %eax
	push %eax
	push $2
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jle _lab1
	jmp _lab2
_lab1:
	push $1
	pop %ecx
	lea -4(, %ebp, 1), %eax
	movl %ecx, (%eax)
	jmp _lab3
_lab2:
	push $2
	pop %ecx
	lea -4(, %ebp, 1), %eax
	movl %ecx, (%eax)
_lab3:
	push -4(%ebp)
	call printInt
	add $4, %esp
_lab10:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret

