
all: runtime.o


runtime.o: runtime.c
	gcc -c -m32 -nostdlib runtime.c -o runtime.o    

	
# b: b.o crti.o crt1.o crtn.o
# 	ld -s -o $@ -melf_i386 $^ -L. -l:libc.a

# a: a.o runtime.o crti.o crt1.o crtn.o
# 	gcc -s -m32 runtime.o a.o -o a
	
a: a.o crti.o crt1.o crtn.o runtime.o 
	ld -s -o $@ -melf_i386 $^ -L. -l:libc.a 

%.o: %.s
	gcc -c -o $@ -m32 $<

clean:
	rm -f a.o a

