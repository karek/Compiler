.data
_CSL0:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	jmp _lab3
_lab3:   #lt
	push $1
	jmp _lab5
_lab4:   #lf
	push $0
_lab5:   #ln
	jmp _lab6
_lab6:   #lt
	push $1
	jmp _lab8
_lab7:   #lf
	push $0
_lab8:   #ln
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	je _lab1
	jmp _lab2
_lab1:
	push $42
	call printInt
	add $4, %esp
_lab9:   # expr
_lab2:
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret

