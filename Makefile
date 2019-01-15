all:
	make latc_x86 latc

latc_x86:
	cd Code && make Main && cp Main ../latc_x86

latc: latc_x86
	cp latc_x86 latc

clean:
	rm -f latc_x86 latc
	cd Code && make clean
 
