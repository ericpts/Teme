.data

citire_n: .asciiz "Nr. el. vector\n"
citire_v: .asciiz "El. vector\n"
meniu:    .asciiz "Introduceti o tasta:\n"
opt1:     .asciiz "1. Suma elementelor;\n"
opt2:     .asciiz "2. Ultimul element;\n"
opt3:     .asciiz "3. Elementele mai mari decat n;\n"
opt4:     .asciiz "4. Exit;\n"
space:    .asciiz " "


n: .word 0
v: .space 100

.text 

main:


citire:


citireN:
li $v0, 4
la $a0, citire_n
syscall

li $v0, 5
syscall
sw $v0, n

citireV:

li $v0, 4
la $a0, citire_v
syscall

li $t0, 0
lw $t1, n
la $t2, v

loop:

beq $t0, $t1, finLoop

li $v0, 5
syscall
sw $v0, ($t2)

addi $t0, 1
addi $t2, 4

b loop
finLoop:

meniuAfis:

li $v0, 4
la $a0, meniu
syscall

item1:

li $v0, 4
la $a0, opt1
syscall

item2:

li $v0, 4
la $a0, opt2
syscall

item3:

li $v0, 4
la $a0, opt3
syscall

item4:
li $v0, 4
la $a0, opt4
syscall


li $v0, 5
syscall
move $t0, $v0


li $t1, 1
beq $t0, $t1, suma

li $t2, 2
beq $t0, $t2, ultimul

li $t2, 3
beq $t0, $t2, greater

li $t2, 4
beq $t0, $t2, exit


suma:

li $t0, 0
lw $t1, n
li $t2, 0

loopSuma:

beq $t0, $t1, afisSuma
la $t3, v
mul $t0, $t0, 4
add $t3, $t3, $t0
div $t0, $t0, 4

lw $t3, 0($t3)
add $t2, $t2, $t3
addi $t0, 1

b loopSuma


afisSuma:

li $v0, 1
move $a0, $t2
syscall
b exit

ultimul:

la $t0, v
lw $t1, n

beqz $t1, exit
addi $t1, -1

mul $t1, $t1, 4

add $t0, $t0, $t1

lw $t0, 0($t0)
li $v0, 1
move $a0, $t0
syscall


b exit
greater:

li $t0, 0
lw $t1, n

loopGreater:
beq $t0, $t1, exitGreater

la $t2, v
mul $t0, $t0, 4
add $t2, $t2, $t0
div $t0, $t0, 4

addi $t0, 1

lw $t2, 0($t2)
ble $t2, $t1, loopGreater

li $v0, 1
move $a0, $t2
syscall

li $v0, 4
la $a0, space
syscall
b loopGreater


exitGreater:
b exit


exit:
li $v0, 10
syscall
