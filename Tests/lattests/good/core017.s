.data
_CSL0:	.string "apa"
_CSL1:	.string "true"
_CSL2:	.string "false"
_CSL3:	.string ""
.text
.globl main

main:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $4, %esp
	push $4
	pop %eax
	movl %eax, -4(%ebp)
	push $3
	push -4(%ebp)
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jle _lab4
	jmp _lab2
_lab4:  # mid
	push $4
	push $2
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jne _lab11
	jmp _lab2
_lab11:  # mid
	jmp _lab1
_lab1:
	jmp _lab19
_lab19:   #lt
	push $1
	jmp _lab21
_lab20:   #lf
	push $0
_lab21:   #ln
	call printBool
	add $4, %esp
_lab18:   # expr
	jmp _lab3
_lab2:
	push $_CSL0
	call printString
	add $4, %esp
_lab22:   # expr
_lab3:
	jmp _lab28
_lab28:   #lt
	push $1
	jmp _lab30
_lab29:   #lf
	push $0
_lab30:   #ln
	jmp _lab31
_lab31:   #lt
	push $1
	jmp _lab33
_lab32:   #lf
	push $0
_lab33:   #ln
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	je _lab24
	jmp _lab27
_lab27: # or mid
	push $1
	call dontCallMe
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
	push $4
	push $5
	pop %ecx
	neg %ecx
	push %ecx
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	jl _lab38
	jmp _lab36
_lab38:  # mid
	push $2
	call dontCallMe
	add $4, %esp
	test %eax, %eax
	jz _lab36
	jmp _lab35
_lab35:   #lt
	push $1
	jmp _lab37
_lab36:   #lf
	push $0
_lab37:   #ln
	call printBool
	add $4, %esp
_lab34:   # expr
	push $4
	push -4(%ebp)
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	je _lab49
	jmp _lab47
_lab49:  # mid
	jmp _lab57
_lab57:   #lt
	push $1
	jmp _lab59
_lab58:   #lf
	push $0
_lab59:   #ln
	jmp _lab60
_lab60:   #lt
	push $1
	jmp _lab62
_lab61:   #lf
	push $0
_lab62:   #ln
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	je _lab56
	jmp _lab47
_lab56:  # mid
	jmp _lab46
_lab46:   #lt
	push $1
	jmp _lab48
_lab47:   #lf
	push $0
_lab48:   #ln
	call printBool
	add $4, %esp
_lab45:   # expr
	jmp _lab68
_lab67:   #lt
	push $1
	jmp _lab69
_lab68:   #lf
	push $0
_lab69:   #ln
	jmp _lab71
_lab70:   #lt
	push $1
	jmp _lab72
_lab71:   #lf
	push $0
_lab72:   #ln
	call implies
	add $8, %esp
	test %eax, %eax
	jz _lab65
	jmp _lab64
_lab64:   #lt
	push $1
	jmp _lab66
_lab65:   #lf
	push $0
_lab66:   #ln
	call printBool
	add $4, %esp
_lab63:   # expr
	jmp _lab77
_lab77:   #lt
	push $1
	jmp _lab79
_lab78:   #lf
	push $0
_lab79:   #ln
	jmp _lab81
_lab80:   #lt
	push $1
	jmp _lab82
_lab81:   #lf
	push $0
_lab82:   #ln
	call implies
	add $8, %esp
	test %eax, %eax
	jz _lab75
	jmp _lab74
_lab74:   #lt
	push $1
	jmp _lab76
_lab75:   #lf
	push $0
_lab76:   #ln
	call printBool
	add $4, %esp
_lab73:   # expr
	jmp _lab88
_lab87:   #lt
	push $1
	jmp _lab89
_lab88:   #lf
	push $0
_lab89:   #ln
	jmp _lab90
_lab90:   #lt
	push $1
	jmp _lab92
_lab91:   #lf
	push $0
_lab92:   #ln
	call implies
	add $8, %esp
	test %eax, %eax
	jz _lab85
	jmp _lab84
_lab84:   #lt
	push $1
	jmp _lab86
_lab85:   #lf
	push $0
_lab86:   #ln
	call printBool
	add $4, %esp
_lab83:   # expr
	jmp _lab97
_lab97:   #lt
	push $1
	jmp _lab99
_lab98:   #lf
	push $0
_lab99:   #ln
	jmp _lab100
_lab100:   #lt
	push $1
	jmp _lab102
_lab101:   #lf
	push $0
_lab102:   #ln
	call implies
	add $8, %esp
	test %eax, %eax
	jz _lab95
	jmp _lab94
_lab94:   #lt
	push $1
	jmp _lab96
_lab95:   #lf
	push $0
_lab96:   #ln
	call printBool
	add $4, %esp
_lab93:   # expr
	push $0
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret
dontCallMe:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	push 8(%ebp)
	call printInt
	add $4, %esp
_lab103:   # expr
	jmp _lab104
_lab104:   #lt
	push $1
	jmp _lab106
_lab105:   #lf
	push $0
_lab106:   #ln
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
	jz _lab108
	jmp _lab107
_lab107:
	push $_CSL1
	call printString
	add $4, %esp
_lab110:   # expr
	jmp _lab109
_lab108:
	push $_CSL2
	call printString
	add $4, %esp
_lab111:   # expr
_lab109:
	movl %ebp, %esp
	pop %ebp
	ret
implies:  #funkcja
	push %ebp
	movl %esp, %ebp
	sub $0, %esp
	movl 8(%ebp), %eax
	test %eax, %eax
	jz _lab112
	jmp _lab115
_lab115: # or mid
	movl 8(%ebp), %eax
	test %eax, %eax
	jz _lab117
	jmp _lab116
_lab116:   #lt
	push $1
	jmp _lab118
_lab117:   #lf
	push $0
_lab118:   #ln
	movl 12(%ebp), %eax
	test %eax, %eax
	jz _lab120
	jmp _lab119
_lab119:   #lt
	push $1
	jmp _lab121
_lab120:   #lf
	push $0
_lab121:   #ln
	pop %ecx
	pop %eax
	cmpl %ecx, %eax
	je _lab112
	jmp _lab113
_lab112:   #lt
	push $1
	jmp _lab114
_lab113:   #lf
	push $0
_lab114:   #ln
	pop %eax
	movl %ebp, %esp
	pop %ebp
	ret

