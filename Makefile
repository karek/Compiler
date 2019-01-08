all:
	make latte_x86

latte_x86:
	cd Code && make Main && cp Main ../latte_x86

clean:
	rm -f latte_x86
	cd Code && make clean
 
