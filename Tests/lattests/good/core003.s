.data
_CSL0:	.string ""
.text
.globl main

f:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	jmp _lab1
_lab1:
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
	jmp _lab3
_lab2:
_lab3:
g:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	jmp _lab5
_lab4:
	jmp _lab6
_lab5:
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
_lab6:
p:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	movl %ebp, %esp
	pop %ebp
	ret
main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	call p
	add $0, %esp
_lab7:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret

