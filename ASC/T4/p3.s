.data

sir:.asciiz "word"

.text

main:

li $t0, 0

loop:

la $t2, sir
add $t2, $t2, $t0
lb $t1, 0($t2)
beqz $t1, fin
addi $t0, $t0, 1
j loop

fin:
move $a0, $t0
li $v0, 1
syscall

li $v0, 10
syscall
