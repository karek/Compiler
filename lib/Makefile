# Notice: if ld does not work, instead of -l:./libc.a
#         try -L. -l:libc.a

all: runtime.o


runtime.o: runtime.c
	gcc -c -m32 -o runtime.o runtime.c


hello-nasm-syscalls: hello-nasm-syscalls.o
	ld -s -o $@ -melf_i386 $^

hello-nasm-printf: hello-nasm-printf.o crti.o crt1.o crtn.o
	ld -s -o $@ -melf_i386 $^ -L. -l:libc.a

hello-as-printf: hello-as-printf.o crti.o crt1.o crtn.o
	ld -s -o $@ -melf_i386 $^ -L. -l:libc.a

%.o: %.asm
	nasm -f elf32 -o $@ $<
	
b: b.o crti.o crt1.o crtn.o
	ld -s -o $@ -melf_i386 $^ -L. -l:libc.a

a: a.o runtime.o
	gcc -s -o 
	
a: a.o crti.o crt1.o crtn.o runtime.o 
	ld -s -o $@ -melf_i386 $^ -L. -l:libc.a 


# g++ -m32 -ggdb runtime.o a.s -o a

# gcc -s runtime.o a.o -o a      
# gcc -s -m32 runtime.o a.o -o a   
# a: a.o crti.o crt1.o crtn.o runtime.o 
# 	gcc -s -o $@ -melf_i386 $^ -L. -l:libc.a


%.o: %.s
	gcc -c -o $@ -m32 $<

clean:
	rm -f runtime.o a.o a

