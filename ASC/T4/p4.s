.data

array: .word 10,20,-10,-20,-5,5,1,5,-1
length: .word 9

.text

main:

li $t1, 0
li $t2, 0
lw $t7, length

loop:

beq $t2, $t7, fin
la $t0, array
mul $t2, $t2, 4
add $t0, $t0, $t2
div $t2, $t2, 4
lw $t0, 0($t0)
abs $t5, $t0
add $t0, $t5, $t0
div $t0, $t0, 2
add $t1, $t1, $t0
addi $t2, $t2, 1
b loop



fin:

li $v0, 1
move $a0, $t1
syscall

li $v0, 10
syscall
