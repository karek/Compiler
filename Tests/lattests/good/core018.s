.data
_CSL0:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $12, %esp
	call readInt
	add $0, %esp
	push %eax
	pop %eax
	movl %eax, -4(%ebp)
	call readString
	add $0, %esp
	push %eax
	pop %eax
	movl %eax, -8(%ebp)
	call readString
	add $0, %esp
	push %eax
	pop %eax
	movl %eax, -12(%ebp)
	push -4(%ebp)
	push $5
	pop %ecx
	pop %eax
	sub %ecx, %eax
	push %eax
	call printInt
	add $4, %esp
_lab1:   # expr
	push -8(%ebp)
	push -12(%ebp)
	pop %ecx
	pop %eax
	push %ecx
	push %eax
	call __concatStrings
	add $8, %esp
	push %eax
	call printString
	add $4, %esp
_lab2:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret

