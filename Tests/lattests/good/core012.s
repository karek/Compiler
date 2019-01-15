.data
_CSL0:	.string "string"
_CSL1:	.string " "
_CSL2:	.string "concatenation"
_CSL3:	.string "true"
_CSL4:	.string "false"
_CSL5:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $8, %esp
	push $56
	pop %eax
	movl %eax, -4(%ebp)
	push $23
	pop %ecx
	neg %ecx
	push %ecx
	pop %eax
	movl %eax, -8(%ebp)
	push -4(%ebp)
	push -8(%ebp)
	pop %ecx
	pop %eax
	add %ecx, %eax
	push %eax
	call printInt
	add $4, %esp
_lab1:   # expr
	push -4(%ebp)
	push -8(%ebp)
	pop %ecx
	pop %eax
	sub %ecx, %eax
	push %eax
	call printInt
	add $4, %esp
_lab2:   # expr
	push -4(%ebp)
	push -8(%ebp)
	pop %ecx
	pop %eax
	imul %ecx, %eax
	push %eax
	call printInt
	add $4, %esp
_lab3:   # expr
	push $45
	push $2
	pop %ecx
	pop %eax
	cdq
	idiv %ecx
	push %eax
	call printInt
	add $4, %esp
_lab4:   # expr
	push $78
	push $3
	pop %ecx
	pop %eax
	cdq
	idiv %ecx
	push %edx
	call printInt
	add $4, %esp
_lab5:   # expr
	push -4(%ebp)
	push -8(%ebp)
	pop %ecx
	pop %eax
	sub %ecx, %eax
	push %eax
	push -4(%ebp)
	push -8(%ebp)
	pop %ecx
	pop %eax
	add %ecx, %eax
	push %eax
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jg _lab7
	jmp _lab8
_lab7:   #lt
	push $1
	jmp _lab9
_lab8:   #lf
	push $0
_lab9:   #ln
	call printBool
	add $4, %esp
_lab6:   # expr
	push -4(%ebp)
	push -8(%ebp)
	pop %ecx
	pop %eax
	cdq
	idiv %ecx
	push %eax
	push -4(%ebp)
	push -8(%ebp)
	pop %ecx
	pop %eax
	imul %ecx, %eax
	push %eax
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jle _lab17
	jmp _lab18
_lab17:   #lt
	push $1
	jmp _lab19
_lab18:   #lf
	push $0
_lab19:   #ln
	call printBool
	add $4, %esp
_lab16:   # expr
	push $_CSL0
	push $_CSL1
	pop %ecx
	pop %eax
	push %ecx
	push %eax
	call __concatStrings
	add $8, %esp
	push %eax
	push $_CSL2
	pop %ecx
	pop %eax
	push %ecx
	push %eax
	call __concatStrings
	add $8, %esp
	push %eax
	call printString
	add $4, %esp
_lab26:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
printBool:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	movl 8(%ebp), %eax
	test %eax, %eax
	jz _lab28
	jmp _lab27
_lab27:
	push $_CSL3
	call printString
	add $4, %esp
_lab30:   # expr
	movl %ebp, %esp
	pop %ebp
	ret
	jmp _lab29
_lab28:
	push $_CSL4
	call printString
	add $4, %esp
_lab31:   # expr
	movl %ebp, %esp
	pop %ebp
	ret
_lab29:

