.data

.text

main:

li $t2, 1

abs $t3, $t1

bne $t1, $t3, fin

li $t2, 0

fin:

move $a0, $t2
li $v0, 1
syscall
li $v0, 10
syscall
