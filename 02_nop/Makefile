nop: Makefile nop.c
	gcc -S nop.c									# Compiler output (assembly langauge)
	gcc -Wall -Wextra -o nop \
		-nostdlib			 \
		nop.c										# Note -nostdlib.  Binary will segfault
	objdump --disassemble nop > nop.objdump  2>&1	# Disassembles binary to assembly language
	readelf --wide --all  nop > nop.readelf  2>&1	# Parse ELF information
	xxd -c32 nop > nop.xxd							# Binary dump for hex editing

clean:
	rm -f nop nop.objdump nop.readelf nop.s nop.xxd

