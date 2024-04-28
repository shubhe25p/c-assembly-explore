    .data

array: .word 1, 2, 3, 4, 5
asize: .word 5


    .text 
     .globl main
       

main: 
	la $a0, array
	lw $a1, asize
	jal computeSum
	li $v0, 1  # required by syscall for printing integer out
	move $a0, $v1 # move return value to a0 which will be printed out
	syscall
	li $v0, 10 #exit
	syscall

computeSum:
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	
	add $s0, $a0, $0 #store base address
	add $s1, $a1, $0 #store size of array
	add $s2, $s2, $0 # sum=0
	
	loop:
		
		lw $t3,0($s0) # load value in t3
		andi $t4, $t3, 1 # even num will have 0 in LSB and odd will have 1 in LSB
		move $a0, $t3
		beq $t4, $0, findSq # if even branch to callSq
		jal findCu # normal jump without change to $ra as it is already changed
		continueLoop: add $s2, $s2, $v0
		addi $s0, $s0, 4            # Move to next array element
        	addi $s1, $s1, -1           # Decrement array size counter
        	bne $s1, $zero, loop              # Repeat loop if size counter != 
        
        lw $ra, 0($sp) # load old ra back
        move $v1, $s2 # return sum
	jr $ra
	
findSq:
	mul $v0, $a0, $a0
	j continueLoop

findCu:
	mul $v0, $a0, $a0
	mul $v0, $v0, $a0
	jr $ra
