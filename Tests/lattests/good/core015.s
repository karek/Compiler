.data
_CSL0:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	push $17
	call ev
	add $4, %esp
	push %eax
	call printInt
	add $4, %esp
_lab1:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
ev:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	push 8(%ebp)
	push $0
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jg _lab2
	jmp _lab3
_lab2:
	push 8(%ebp)
	push $2
	pop %ecx
	pop %eax
	sub %ecx, %eax
	push %eax
	call ev
	add $4, %esp
	push %eax
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
	jmp _lab4
_lab3:
	push 8(%ebp)
	push $0
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jl _lab11
	jmp _lab12
_lab11:
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
	jmp _lab13
_lab12:
	push $1
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
_lab13:
_lab4:

