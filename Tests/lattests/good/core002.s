.data
_CSL0:	.string "foo"
_CSL1:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	call foo
	add $0, %esp
_lab1:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
foo:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	push $_CSL0
	call printString
	add $4, %esp
_lab2:   # expr
	movl %ebp, %esp
	pop %ebp
	ret

