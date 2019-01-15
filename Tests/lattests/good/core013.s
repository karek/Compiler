.data
_CSL0:	.string "&&"
_CSL1:	.string "||"
_CSL2:	.string "!"
_CSL3:	.string "false"
_CSL4:	.string "true"
_CSL5:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	push $_CSL0
	call printString
	add $4, %esp
_lab1:   # expr
	push $1
	pop %ecx
	neg %ecx
	push %ecx
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab4
	jmp _lab6
_lab6:  # mid
	push $0
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab4
	jmp _lab3
_lab3:   #lt
	push $1
	jmp _lab5
_lab4:   #lf
	push $0
_lab5:   #ln
	call printBool
	add $4, %esp
_lab2:   # expr
	push $2
	pop %ecx
	neg %ecx
	push %ecx
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab9
	jmp _lab11
_lab11:  # mid
	push $1
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab9
	jmp _lab8
_lab8:   #lt
	push $1
	jmp _lab10
_lab9:   #lf
	push $0
_lab10:   #ln
	call printBool
	add $4, %esp
_lab7:   # expr
	push $3
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab14
	jmp _lab16
_lab16:  # mid
	push $5
	pop %ecx
	neg %ecx
	push %ecx
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab14
	jmp _lab13
_lab13:   #lt
	push $1
	jmp _lab15
_lab14:   #lf
	push $0
_lab15:   #ln
	call printBool
	add $4, %esp
_lab12:   # expr
	push $234234
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab19
	jmp _lab21
_lab21:  # mid
	push $21321
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab19
	jmp _lab18
_lab18:   #lt
	push $1
	jmp _lab20
_lab19:   #lf
	push $0
_lab20:   #ln
	call printBool
	add $4, %esp
_lab17:   # expr
	push $_CSL1
	call printString
	add $4, %esp
_lab22:   # expr
	push $1
	pop %ecx
	neg %ecx
	push %ecx
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab27
	jmp _lab24
_lab27: # or mid
	push $0
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab25
	jmp _lab24
_lab24:   #lt
	push $1
	jmp _lab26
_lab25:   #lf
	push $0
_lab26:   #ln
	call printBool
	add $4, %esp
_lab23:   # expr
	push $2
	pop %ecx
	neg %ecx
	push %ecx
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab32
	jmp _lab29
_lab32: # or mid
	push $1
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab30
	jmp _lab29
_lab29:   #lt
	push $1
	jmp _lab31
_lab30:   #lf
	push $0
_lab31:   #ln
	call printBool
	add $4, %esp
_lab28:   # expr
	push $3
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab37
	jmp _lab34
_lab37: # or mid
	push $5
	pop %ecx
	neg %ecx
	push %ecx
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab35
	jmp _lab34
_lab34:   #lt
	push $1
	jmp _lab36
_lab35:   #lf
	push $0
_lab36:   #ln
	call printBool
	add $4, %esp
_lab33:   # expr
	push $234234
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab42
	jmp _lab39
_lab42: # or mid
	push $21321
	call test
	add $4, %esp
	test %eax, %eax
	jz _lab40
	jmp _lab39
_lab39:   #lt
	push $1
	jmp _lab41
_lab40:   #lf
	push $0
_lab41:   #ln
	call printBool
	add $4, %esp
_lab38:   # expr
	push $_CSL2
	call printString
	add $4, %esp
_lab43:   # expr
	jmp _lab45
_lab45:   #lt
	push $1
	jmp _lab47
_lab46:   #lf
	push $0
_lab47:   #ln
	call printBool
	add $4, %esp
_lab44:   # expr
	jmp _lab50
_lab49:   #lt
	push $1
	jmp _lab51
_lab50:   #lf
	push $0
_lab51:   #ln
	call printBool
	add $4, %esp
_lab48:   # expr
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
	jz _lab52
	jmp _lab53
_lab52:
	push $_CSL3
	call printString
	add $4, %esp
_lab55:   # expr
	jmp _lab54
_lab53:
	push $_CSL4
	call printString
	add $4, %esp
_lab56:   # expr
_lab54:
	movl %ebp, %esp
	pop %ebp
	ret
test:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	push 8(%ebp)
	call printInt
	add $4, %esp
_lab57:   # expr
	push 8(%ebp)
	push $0
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jg _lab58
	jmp _lab59
_lab58:   #lt
	push $1
	jmp _lab60
_lab59:   #lf
	push $0
_lab60:   #ln
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret

