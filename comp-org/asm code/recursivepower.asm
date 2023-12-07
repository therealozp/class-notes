.data


.text
	main: 
		addi a0, x0, 3
		addi a1, x0, 5
		jal ra, power
		j terminate
		
	power: 
		addi sp, sp, -8
		sw ra, 0(sp)
		sw t0, 4(sp)
		
		# preload arguments and free up a0, a1
		add t0, x0, a0
		add t1, x0, a1
		
		if: bge x0, a1, else
			addi a1, a1, -1
			jal ra, power
			# use t6 as temp variable, and t5 as the current index
			add t5, x0, x0
			add t6, x0, x0
			# assuming that return value goes into a0
			for: 
				if2: bge t5, a0, endloop
					add t6, t6, t0 # t6 = t6 + n
					addi t5, t5, 1 # t5++
					j for
			endloop: 
				# prep a0 for return
				add a0, t6, x0	
			j endif
		else: 
			addi a0, x0, 1
		endif: 
			lw t0, 4(sp)
			lw ra, 0(sp)
			addi sp, sp, 8
			jr ra
	
	terminate: 