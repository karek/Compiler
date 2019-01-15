.data
_CSL0:	.string "foo"
_CSL1:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $16, %esp
	push $78
	pop %eax
	movl %eax, -4(%ebp)
	push $1
	pop %eax
	movl %eax, -8(%ebp)
	push -8(%ebp)
	call printInt
	add $4, %esp
_lab1:   # expr
	push -4(%ebp)
	call printInt
	add $4, %esp
_lab2:   # expr
_lab3:  #loop condition
	push -4(%ebp)
	push $76
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jg _lab4
	jmp _lab5
_lab4:  #loop body
	lea -4(, %ebp, 1), %eax
	decl (%eax)
	push -4(%ebp)
	call printInt
	add $4, %esp
_lab12:   # expr
	push -4(%ebp)
	push $7
	pop %ecx
	pop %eax
	add %ecx, %eax
	push %eax
	pop %eax
	movl %eax, -12(%ebp)
	push -12(%ebp)
	call printInt
	add $4, %esp
_lab13:   # expr
	jmp _lab3
_lab5:  # End while
	push -4(%ebp)
	call printInt
	add $4, %esp
_lab14:   # expr
	push -4(%ebp)
	push $4
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jg _lab15
	jmp _lab16
_lab15:
	push $4
	pop %eax
	movl %eax, -16(%ebp)
	push -16(%ebp)
	call printInt
	add $4, %esp
_lab24:   # expr
	jmp _lab17
_lab16:
	push $_CSL0
	call printString
	add $4, %esp
_lab25:   # expr
_lab17:
	push -4(%ebp)
	call printInt
	add $4, %esp
_lab26:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret

