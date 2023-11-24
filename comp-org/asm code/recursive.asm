main: 
	addi a0, x0, 2
	addi a1, x0, 3
	jal ra, multiply
	j terminate

multiply: 
	addi sp, sp, -8
	sw ra, sp(0)
	sw t0, sp(4)
	addi t0, a0, 0
	addi t1, a1, 0
	if: bge x0, t1, else
		addi a0, t0, 0
		addi a1, t1, -1
		jal ra, multiply
		# a0 = a + a0 returned
		add a0, t0, a0
		j endif
	else: 
		add a0, x0, x0
	endif: 
		lw ra, sp(0)
		lw t0, sp(4)
		addi sp, sp, 8
		jr ra

terminate: 