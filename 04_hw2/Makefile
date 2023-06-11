hw2: Makefile hw2.xxc
	sed "/^#/d" hw2.xxc > hw2.xxd					# Remove comments from binary dump
	xxd -c32 -r hw2.xxd hw2							# Creates binary from binary dump
	objdump --disassemble hw2 > hw2.objdump 2>&1	# Nice sanity check
	chmod 700 hw2									# Makes binary executable

clean:
	rm -rf hw2 hw2.objdump hw2.xxd

