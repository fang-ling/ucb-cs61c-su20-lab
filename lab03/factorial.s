.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    # var i = n
    # var result = 1
    # while i > 0 {
    #     result *= i
    #     i -= 1
    # }

    add t0, x0, a0  # t0 = n (var i)
    addi t1, x0, 1  # t1 = 1 (var result)

    j Test
Loop:
    mul t1, t1, t0   # t1 *= t0 (result *= i)
    addi t0, t0, -1  # t0 -= 1  (i -= 1)
Test:
    # BLT take the branch if rs1 is less than rs2 (signed)
    blt x0, t0, Loop

    add a0, x0, t1
    jr ra
