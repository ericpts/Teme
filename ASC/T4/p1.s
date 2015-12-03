.data

.text

main:

li $t0, 0

li $t6, 7

beq $t1, $t6, found
beq $t2, $t6, found
beq $t3, $t6, found
beq $t4, $t6, found
beq $t5, $t6, found

b fin

found:
li $t0, 1

fin:

move $a0, $t0
li $v0, 1
syscall
li $v0, 10
syscall
