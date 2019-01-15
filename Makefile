all:
	make latc_x86 latc

latc_x86:
	cd Code && make Main
	cp Code/Main latc_x86

latc: latc_x86
	cp latc_x86 latc

clean:
	rm -f latc_x86 latc

clean_all:
	make clean
	cd Code && make clean
 
