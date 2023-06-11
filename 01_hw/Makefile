hw: Makefile hw.c
	gcc --version > gcc.version 2>&1			# Record the version of the gcc compiler
	gcc -E hw.c   > hw.preprocessor				# Preprocessor output
	gcc -S hw.c									# Compiler output (assembly langauge)
	gcc -c hw.c									# Assembler ouput (object file)
	gcc -Wall -Wextra --verbose -o hw hw.c \
		> gcc.verbose 2>&1						# "Regular" output (including linker)
	objdump --disassemble hw > hw.objdump  2>&1	# Disassembles binary to assembly language
	readelf --wide --all hw  > hw.readelf  2>&1	# Parse ELF information
	xxd -c32 hw > hw.xxd						# Binary dump for hex editing

clean:
	rm -f gcc.verbose gcc.version hw hw.o hw.objdump hw.preprocessor hw.readelf hw.s hw.xxd

