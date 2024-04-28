    .data
n: .word 5                        
fact: .word 0
    .text
    .globl main

main:

    lw $t1, n              # Load size of array

    
    add $t2, $t2, $0
    addi $t2, $t2, 1                      

    loop:
        mul $t2, $t2, $t1
        addi $t1, $t1, -1
        bne $t1, $zero, loop              


    sw $t2, fact

    # Exit program
    li $v0, 10                      # Exit syscall
    syscall
