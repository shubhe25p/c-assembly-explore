    .data
array:  .word 1, 2, 3, 4, 5      # Sample array
array_size: .word 5                # Size of the array

sum:    .word 0                    # Variable to store the sum

    .text
    .globl main

main:
    # Load array address and size
    la $t0, array                   # Load base address of array
    lw $t1, array_size              # Load size of array

    # Initialize sum to 0
    add $t2, $t2, $0                       # Initialize sum to 0

    # Loop to sum the elements
    loop:
        lw $t3, 0($t0)              # Load array element into $t3
        add $t2, $t2, $t3           # Add array element to sum
        addi $t0, $t0, 4            # Move to next array element
        addi $t1, $t1, -1           # Decrement array size counter
        bne $t1, $zero, loop              # Repeat loop if size counter != 0

    # Store the sum in memory
    sw $t2, sum

    # Exit program
    li $v0, 10                      # Exit syscall
    syscall
