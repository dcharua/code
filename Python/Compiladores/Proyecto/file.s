	li $s0 0
	sw $s0,0($sp)
	addi $sp,$sp,-4
next:
	addi $sp,$sp
	jr $ra
main:
	li $s0 0
	sw $s0,0($sp)
	addi $sp,$sp,-4
	li $s0 0
	sw $s0,0($sp)
	addi $sp,$sp,-4
	li $s0 0
	sw $s0,0($sp)
	addi $sp,$sp,-4
	li $a0, 0
	li $a0, 0
	li $a0, 1
	li $a0, 1
	li $a0, 2
start-while0:
	sw $a0 0($sp)
	addi $sp,$sp,-4
	li $a0, 10
	lw $t1 4($sp)
	addi $sp,$sp,4
	j end-while0
while0:
	li $t1, 0
	add $sp,$sp,$t1
	move $a0, $sp
	sub $sp,$sp,$t1
	addi $sp,$sp,-0
	sw $a0,0($sp)
	addi $sp,$sp, 0
	addi $sp,$sp,-4
	jal next
	addi $sp,$sp,4
	j start-while0
end-while0:
	li $a0, 0
start-while1:
	sw $a0 0($sp)
	addi $sp,$sp,-4
	li $a0, 10
	lw $t1 4($sp)
	addi $sp,$sp,4
	j end-while1
while1:
	li $v0, 1
	syscall
	move $t8, $a0
	addi $a0, $0, 0xA
	addi $v0, $0, 0xB
	syscall
	move $a0, $t8
	li $t1, 0
	add $sp,$sp,$t1
	move $a0, $sp
	sub $sp,$sp,$t1
	addi $sp,$sp,-0
	sw $a0,0($sp)
	addi $sp,$sp, 0
	addi $sp,$sp,-4
	jal next
	addi $sp,$sp,4
	j start-while1
end-while1:
