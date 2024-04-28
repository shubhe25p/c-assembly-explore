    .data

n: .word 5                

sum:    .word 0                    # Variable to store the sum

    .text
    .globl main

main:
    lw $t0, n
    li $t1, 0
    
    loop:
    move $a1, $t1
    move $a0, $t0
    jal add
    move $t1, $v0
    addi $t0, $t0, -1
    bne $t0, $0, loop
    
    sw $t1, sum

    # Exit program
    li $v0, 10                      # Exit syscall
    syscall

add:
     add $v0, $a0, $a1
     jr $ra
     