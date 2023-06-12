ubfm: Makefile test.c
	gcc -DDEBUG_ME test.c -o test
	./test > test.output
	gcc -c -O0 test.c -o test_O0.o
	gcc -c -O3 test.c -o test_O3.o
	gcc -c -Oz test.c -o test_Oz.o
	objdump --disassemble test_O0.o > test_O0.objdump
	objdump --disassemble test_O3.o > test_O3.objdump
	objdump --disassemble test_Oz.o > test_Oz.objdump

clean:
	rm -f test test.output test_*.o test_*.objdump

