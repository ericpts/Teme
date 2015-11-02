.data
.text
main:
li $t0, 0x1234
sll $t2, $t0, 3
li $v0, 1
move $a0, $t2
syscall
li $v0, 10
syscall
