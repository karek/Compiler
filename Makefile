all:
	rm latc latc_x86
	make latc_x86 latc

latc_x86:
	cd src && make Main
	cp src/Main latc_x86

latc: latc_x86
	cp latc_x86 latc

clean:
	rm -f latc_x86 latc

clean_all:
	make clean
	cd src && make clean
 
