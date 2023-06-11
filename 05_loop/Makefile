loop: Makefile loop.xxc
	sed "/^#/d" loop.xxc > loop.xxd					# Remove comments from binary dump
	xxd -c32 -r loop.xxd loop						# Creates binary from binary dump
	objdump --disassemble loop > loop.objdump 2>&1	# Nice sanity check
	chmod 700 loop									# Makes binary executable

clean:
	rm loop.objdump loop.xxd loop

