.data
_CSL0:	.string "="
_CSL1:	.string "hello */"
_CSL2:	.string "/* world"
_CSL3:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $12, %esp
	push $10
	call fac
	add $4, %esp
	push %eax
	call printInt
	add $4, %esp
_lab1:   # expr
	push $10
	call rfac
	add $4, %esp
	push %eax
	call printInt
	add $4, %esp
_lab2:   # expr
	push $10
	call mfac
	add $4, %esp
	push %eax
	call printInt
	add $4, %esp
_lab3:   # expr
	push $10
	call ifac
	add $4, %esp
	push %eax
	call printInt
	add $4, %esp
_lab4:   # expr
	movl $_CSL3, -4(%ebp)
	push $10
	pop %eax
	movl %eax, -8(%ebp)
	push $1
	pop %eax
	movl %eax, -12(%ebp)
_lab5:  #loop condition
	push -8(%ebp)
	push $0
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jg _lab6
	jmp _lab7
_lab6:  #loop body
	push -12(%ebp)
	push -8(%ebp)
	pop %ecx
	pop %eax
	imul %ecx, %eax
	push %eax
	pop %ecx
	lea -12(, %ebp, 1), %eax
	movl %ecx, (%eax)
	lea -8(, %ebp, 1), %eax
	decl (%eax)
	jmp _lab5
_lab7:  # End while
	push -12(%ebp)
	call printInt
	add $4, %esp
_lab14:   # expr
	push $60
	push $_CSL0
	call repStr
	add $8, %esp
	push %eax
	call printString
	add $4, %esp
_lab15:   # expr
	push $_CSL1
	call printString
	add $4, %esp
_lab16:   # expr
	push $_CSL2
	call printString
	add $4, %esp
_lab17:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
fac:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $8, %esp
	movl $0, -4(%ebp)
	movl $0, -8(%ebp)
	push $1
	pop %ecx
	lea -4(, %ebp, 1), %eax
	movl %ecx, (%eax)
	push 8(%ebp)
	pop %ecx
	lea -8(, %ebp, 1), %eax
	movl %ecx, (%eax)
_lab18:  #loop condition
	push -8(%ebp)
	push $0
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jg _lab19
	jmp _lab20
_lab19:  #loop body
	push -4(%ebp)
	push -8(%ebp)
	pop %ecx
	pop %eax
	imul %ecx, %eax
	push %eax
	pop %ecx
	lea -4(, %ebp, 1), %eax
	movl %ecx, (%eax)
	push -8(%ebp)
	push $1
	pop %ecx
	pop %eax
	sub %ecx, %eax
	push %eax
	pop %ecx
	lea -8(, %ebp, 1), %eax
	movl %ecx, (%eax)
	jmp _lab18
_lab20:  # End while
	push -4(%ebp)
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
rfac:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	push 8(%ebp)
	push $0
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	je _lab27
	jmp _lab28
_lab27:
	push $1
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
	jmp _lab29
_lab28:
	push 8(%ebp)
	push 8(%ebp)
	push $1
	pop %ecx
	pop %eax
	sub %ecx, %eax
	push %eax
	call rfac
	add $4, %esp
	push %eax
	pop %ecx
	pop %eax
	imul %ecx, %eax
	push %eax
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
_lab29:
mfac:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	push 8(%ebp)
	push $0
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	je _lab36
	jmp _lab37
_lab36:
	push $1
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
	jmp _lab38
_lab37:
	push 8(%ebp)
	push 8(%ebp)
	push $1
	pop %ecx
	pop %eax
	sub %ecx, %eax
	push %eax
	call nfac
	add $4, %esp
	push %eax
	pop %ecx
	pop %eax
	imul %ecx, %eax
	push %eax
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
_lab38:
nfac:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	push 8(%ebp)
	push $0
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jne _lab45
	jmp _lab46
_lab45:
	push 8(%ebp)
	push $1
	pop %ecx
	pop %eax
	sub %ecx, %eax
	push %eax
	call mfac
	add $4, %esp
	push %eax
	push 8(%ebp)
	pop %ecx
	pop %eax
	imul %ecx, %eax
	push %eax
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
	jmp _lab47
_lab46:
	push $1
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
_lab47:
ifac:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	push 8(%ebp)
	push $1
	call ifac2f
	add $8, %esp
	push %eax
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
ifac2f:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $4, %esp
	push 8(%ebp)
	push 12(%ebp)
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	je _lab54
	jmp _lab55
_lab54:
	push 8(%ebp)
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
_lab55:
	push 8(%ebp)
	push 12(%ebp)
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jg _lab62
	jmp _lab63
_lab62:
	push $1
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
_lab63:
	movl $0, -4(%ebp)
	push 8(%ebp)
	push 12(%ebp)
	pop %ecx
	pop %eax
	add %ecx, %eax
	push %eax
	push $2
	pop %ecx
	pop %eax
	cdq
	idiv %ecx
	push %eax
	pop %ecx
	lea -4(, %ebp, 1), %eax
	movl %ecx, (%eax)
	push -4(%ebp)
	push 8(%ebp)
	call ifac2f
	add $8, %esp
	push %eax
	push 12(%ebp)
	push -4(%ebp)
	push $1
	pop %ecx
	pop %eax
	add %ecx, %eax
	push %eax
	call ifac2f
	add $8, %esp
	push %eax
	pop %ecx
	pop %eax
	imul %ecx, %eax
	push %eax
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
repStr:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $8, %esp
	push $_CSL3
	pop %eax
	movl %eax, -4(%ebp)
	push $0
	pop %eax
	movl %eax, -8(%ebp)
_lab70:  #loop condition
	push -8(%ebp)
	push 12(%ebp)
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jl _lab71
	jmp _lab72
_lab71:  #loop body
	push -4(%ebp)
	push 8(%ebp)
	pop %ecx
	pop %eax
	push %ecx
	push %eax
	call __concatStrings
	add $8, %esp
	push %eax
	pop %ecx
	lea -4(, %ebp, 1), %eax
	movl %ecx, (%eax)
	lea -8(, %ebp, 1), %eax
	incl (%eax)
	jmp _lab70
_lab72:  # End while
	push -4(%ebp)
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret

