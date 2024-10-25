# some test data to verify that the program actually runs
.data
	arr: .word 89, 1, 34, 5, 2, 7, 6, 3
	size: .word 8
.text
main: 
	# load address of arr into a3
	la a0, arr
	lw a1, size
	jal ra, selection_sort
	# jump to end so that it won't run a second time
	j termine

swap:
	# uses t0, t1
	# assuming that it is using a0, a1 as the two arguments
	# stores and saves without using temp because registers don't need them
	lw t0, 0(a0)
	lw t1, 0(a1)
	sw t1, 0(a0)
	sw t0, 0(a1)
	jr ra
	
findMinimum: 
	# uses t4, t5
	# backing everything up with stack pointers
	addi sp, sp, -12
	sw s3, 0(sp)
	sw s4, 4(sp)
	sw ra, 8(sp)
	# in the selection_sort function, array and N is passed in using a0 and a1. so we are just using the same thing here
	# we will just store it in these s registers and never touch a0 and a1 again as the accessing registers
	add s3, x0, a0
	add s4, x0, a1
	# decalare min_index variable in t5 and loop index in t4
	addi t5, x0, 0
	addi t4, x0, 0
	loop: 
		bge t4, s4, endloop
		# get array element, store it in t2
		slli t6, t4, 2
		add t6, s3, t6
		lw t2, 0(t6) 
		
		# get array[min_idx], store it in t3
		slli t3, t5, 2
		add t3, s3, t3
		lw t3, 0(t3)
		
		if: bge t2, t3, endif
			# if arr[i] >= arr[min_idx], skip to end
			# else, set min_index to i
			add t5, x0, t4 
		endif: 
			addi t4, t4, 1
			j loop
	endloop:
		# deallocate all used memory 
		lw ra, 8(sp)
		lw s4, 4(sp)
		lw s3, 0(sp)
		addi sp, sp, 12
		# set return value a0 = min_index
		add a0, x0, t5
		jr ra

selection_sort: 
	# using s0, s1, s3, s4
	addi sp, sp, -24
	sw s3, 0(sp)
	sw s4, 4(sp)
	sw s5, 8(sp)
	sw s0, 12(sp)
	sw s1, 16(sp)
	sw ra, 20(sp)
	# assuming that, by convention, array, length is passed in using a0, a1
	# we will use s3 and s4 to back it up and avoid using a0 and a1 directly
	add s3, x0, a0
	addi s4, a1, 0
	# using s5 to get the n - 1 value
	addi s5, a1, -1
	# decalare min_index variable in s1 and loop index in s0
	addi s0, x0, 0
	addi s1, x0, 0
	loop2: bge s0, s5, endloop2
		# prepare function arguments
		slli t2, s0, 2
		add a0, s3, t2
		sub a1, s4, s0
		# jump to minimum
		jal ra, findMinimum
		add s1, x0, a0  # return value of minimum
		
		if2: beq s1, x0, endif2
			# prepare function arguments for swap
			# &arr[min_idx + i], where arr is in s3, return value min_idx in s1, i is s0
			add a0, s1, s0
			slli a0, a0, 2
			add a0, a0, s3 # stored address in a0
			# &arr[i]
			add a1, x0, s0
			slli a1, a1, 2
			add a1, a1, s3 # stored arr[i] in a1
			jal ra swap
		endif2: 
			addi s0, s0, 1
			j loop2
	endloop2: 
		# re-load all variables, including ra, and return
		lw ra, 20(sp)
		lw s1, 16(sp)
		lw s0, 12(sp)
		lw s5, 8(sp)
		lw s4, 4(sp)
		lw s3, 0(sp)
		# deallocate the sp
		addi sp, sp, 24
		jr ra
	
termine:
