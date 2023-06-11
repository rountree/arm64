nop: Makefile nop.c
	gcc -S nop.c									# Compiler output (assembly langauge)
	gcc -Wall -Wextra -o nop \
		-nostdlib			 \
		nop.c										# Note -nostdlib.  Binary will segfault
	objdump --disassemble nop > nop.objdump  2>&1	# Disassembles binary to assembly language
	readelf --wide --all  nop > nop.readelf  2>&1	# Parse ELF information
	xxd -c32 nop > nop.xxd							# Binary dump for hex editing
	#cp nop.xxd exit.xxc							# Commented out to prevent accidental overwriting

exit: Makefile exit.xxc
	sed "/^#/d" exit.xxc > exit.xxd					# Remove comments from binary dump
	xxd -c32 -r exit.xxd exit						# Creates binary from binary dump
	objdump --disassemble exit > exit.objdump 2>&1	# Nice sanity check
	chmod 700 exit									# Makes binary executable

clean:
	rm -f nop nop.objdump nop.readelf nop.s nop.xxd exit.xxd exit.objdump exit

