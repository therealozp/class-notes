.data
	a: .word 9, 4, 6, 2, 5, 3, 8, 1
	n: .word 8
.text

la a0, a
lw a1, n
j bubblesort

swap: 
	lw t0, 0(a0)
	lw t1, 0(a1)
	sw t0, 0(a1)
	sw t1, 0(a0)
	jr ra

bubblesort: 
	add s3, a0, x0 # store array address
	addi s4, a1, -1 # store array length, zero indexed (n - 1)
	add s0, x0, x0 # initialize first loop variable i
	for1: bge s0, s4, exit1
		add s5, x0, x0 # setup boolean variable swapped to false
		add s1, x0, x0 # initialize second loop variable j
		sub t0, s4, s0 # initialize second loop limit n - 1 - i 
		addi t0, t0, -1
		for2: bge s1, t0, exit2
			# address j in t1
			slli t1, s1, 2
			# a0 is already added to s3
			add t1, s3, t1
			lw t2, 0(t1)
			lw t3, 4(t1)
			
			# if arr[j+1) >= arr[j]
			if: bge t3, t2, endif
				# preparing arguments
				add a0, t1, x0
				addi a1, t1, 4
				# boolean = 1
				addi s5, s5, 1
				# jr ra swap
				jal ra, swap				
			endif: 
				addi s1, s1, 1
				j for2
		exit2: addi s1, s1, 1
		addi s0, s0, 1
		# break statement
		if_outer: beq s5, x0, exit1
	exit1: addi s0, s0, 1
	
