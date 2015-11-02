.data
.text
main:
li $t0, 0x12345678
ror $t2, $t0, 5
move $a0, $t2
li $v0, 1
syscall
li $v0, 10
syscall
