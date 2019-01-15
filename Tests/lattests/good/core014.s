.data
_CSL0:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $12, %esp
	movl $0, -4(%ebp)
	movl $0, -8(%ebp)
	movl $0, -12(%ebp)
	push $1
	pop %ecx
	lea -4(, %ebp, 1), %eax
	movl %ecx, (%eax)
	push -4(%ebp)
	pop %ecx
	lea -8(, %ebp, 1), %eax
	movl %ecx, (%eax)
	push $5000000
	pop %ecx
	lea -12(, %ebp, 1), %eax
	movl %ecx, (%eax)
	push -4(%ebp)
	call printInt
	add $4, %esp
_lab1:   # expr
_lab2:  #loop condition
	push -8(%ebp)
	push -12(%ebp)
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jl _lab3
	jmp _lab4
_lab3:  #loop body
	push -8(%ebp)
	call printInt
	add $4, %esp
_lab11:   # expr
	push -4(%ebp)
	push -8(%ebp)
	pop %ecx
	pop %eax
	add %ecx, %eax
	push %eax
	pop %ecx
	lea -8(, %ebp, 1), %eax
	movl %ecx, (%eax)
	push -8(%ebp)
	push -4(%ebp)
	pop %ecx
	pop %eax
	sub %ecx, %eax
	push %eax
	pop %ecx
	lea -4(, %ebp, 1), %eax
	movl %ecx, (%eax)
	jmp _lab2
_lab4:  # End while
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret

