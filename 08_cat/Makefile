c2bin: Makefile nop.c
	gcc -o nop -nostdlib nop.c

bin2xxc:
	xxd -c4 nop > target.xxc

xxc2bin: Makefile target.xxc
	sed "/^#/d" target.xxc > target.xxd					# Remove comments from binary dump
	xxd -c4 -r target.xxd target						# Creates binary from binary dump
	objdump --disassemble target > target.objdump 2>&1	# Nice sanity check
	readelf --all --wide target > target.readelf 2>&1	# readelf output
	chmod 700 target									# Makes binary executable
	ls -l ./target*

clean:
	rm -f nop target.xxd target target.objdump target.readelf target

