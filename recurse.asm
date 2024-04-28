    .data

nsize: .word 5

    .text 
     .globl main
       

main: 
	lw $a0, nsize
    jal factorial
    move $a0, $v0
    li $v0, 1
    syscall
    li $v0, 10
    syscall

factorial:
    addi $sp, $sp, -8
    sw $ra, 0($sp)
    sw $a0, 4($sp)

    add $t0, $a0, $0
    addi $t1, $0, 1
    beq $t0, $t1, return
    addi $t0, $t0, -1
    add $a0, $t0, $0
    jal factorial

    continue:
        lw $t0, 4($sp)
        mul $v0, $v0, $t0
        lw $ra, 0($sp)
        addi $sp, $sp, 8
        jr $ra 

return:
    add $v0, $v0, 1
    j continue
