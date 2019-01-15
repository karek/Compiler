.data
_CSL0:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $4, %esp
	push $17
	pop %eax
	movl %eax, -4(%ebp)
_lab1:  #loop condition
	push -4(%ebp)
	push $0
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jg _lab2
	jmp _lab3
_lab2:  #loop body
	push -4(%ebp)
	push $2
	pop %ecx
	pop %eax
	sub %ecx, %eax
	push %eax
	pop %ecx
	lea -4(, %ebp, 1), %eax
	movl %ecx, (%eax)
	jmp _lab1
_lab3:  # End while
	push -4(%ebp)
	push $0
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jl _lab10
	jmp _lab11
_lab10:
	push $0
	call printInt
	add $4, %esp
_lab19:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
	jmp _lab12
_lab11:
	push $1
	call printInt
	add $4, %esp
_lab20:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
_lab12:

