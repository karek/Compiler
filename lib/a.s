
.data
a: .long 5
fmt: .string "Hello world!\nLet me give you some values: a=%d, eax=%d\n"
.text






.globl main
main:
	push %ebp
	mov %esp, %ebp
	sub $4, %esp
	mov a, %ecx
	add $2, %ecx
	push %ecx
	push $31
	call printInt
	pop %ecx
	movl $17, -4(%ebp)
	# pop %edx
	push -4(%ebp)
 	call printInt
 	push %ecx
 	# push $fmt
	 # call printInt
	# push $6
	call readString
	push %eax
	call printString
	call readString 
	movl %eax, -4(%ebp)
	push %eax
	call printString

	call __concatStrings

	push %eax

	call printString

	mov $13, %eax
	push %eax
	call printInt

	push -4(%ebp)
	# call printInt
	call printString
	#push $fmt
	 
	 
	
	#call printf
	mov $0, %eax
	leave
	ret

 
