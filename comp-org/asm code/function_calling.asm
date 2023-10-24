.data
		a: .word 8, 1, 6, 5, 3, 4, 2, 7
		n: .word 8

.text
	la a0, a
	lw a1, n
	
j bubblesort_sp
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
		sub t4, s4, s0 # initialize second loop limit n - 1 - i 
		
		for2: bge s1, t4, exit2
			# address j in t1
			slli t5, s1, 2
			# a0 is already added to s3
			add t5, s3, t5
			lw t2, 0(t5)
			lw t3, 4(t5)
			
			# if arr[j+1) >= arr[j]
			if: bge t3, t2, endif
				# preparing arguments
				add a0, t5, x0
				addi a1, t5, 4
				# boolean = 1
				addi s5, s5, 1
				# jr ra swap
				jal ra, swap				
			endif: 
				addi s1, s1, 1
				j for2
		exit2: addi s1, s1, 1
		
		# break statement
		if_outer: beq s5, x0, exit1
		addi s0, s0, 1
		j for1
	exit1: addi s0, s0, 1
	
bubblesort_sp: 
	add s3, a0, x0 # store array address
	addi s4, a1, -1 # store array length, zero indexed (n - 1)
	add s0, x0, x0 # initialize first loop variable i
	
	for1_sp: bge s0, s4, exit1_sp
		add s5, x0, x0 # setup boolean variable swapped to false
		add s1, x0, x0 # initialize second loop variable j
		sub t0, s4, s0 # initialize second loop limit n - 1 - i 
		
		for2_sp: bge s1, t0, exit2_sp
			# address j in t0
			slli t1, s1, 2
			# a0 is already added to s3
			add t1, s3, t1
			lw t2, 0(t1)
			lw t3, 4(t1)
			
			# if arr[j+1) >= arr[j]
			if_sp: bge t3, t2, endif_sp
				# preparing arguments
				add a0, t1, x0
				addi a1, t1, 4
				# boolean = 1
				addi s5, s5, 1
				#storing t1 and t0
				addi sp, sp, -8 
				sw t0, 0(sp)
				sw t1, 4(sp)
				# jr ra swap
				jal ra, swap
				
				# reload t0, t1
				lw t0, 0(sp)
				lw t1, 4(sp)
				addi sp, sp, 8
								
			endif_sp: 
				addi s1, s1, 1
				j for2_sp
		exit2_sp: addi s1, s1, 1
		
		# break statement
		if_outer_sp: beq s5, x0, exit1_sp
		addi s0, s0, 1
		j for1_sp
	exit1_sp: addi s0, s0, 1	

	
