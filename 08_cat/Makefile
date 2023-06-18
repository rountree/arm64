c2bin: Makefile nop.c
	gcc -o nop -nostdlib nop.c

bin2xxc:
	xxd -c4 nop > target.xxc

xxc2bin: Makefile loop.xxc
	sed "/^#/d" target.xxc > target.xxd					# Remove comments from binary dump
	xxd -c4 -r target.xxd target						# Creates binary from binary dump
	objdump --disassemble target > target.objdump 2>&1	# Nice sanity check
	chmod 700 loop										# Makes binary executable

clean:
	rm target.xxd target target.objump nop

