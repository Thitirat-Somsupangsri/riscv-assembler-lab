start:
addi x1, x0, 5
add x30, x2, x0
addi x2, x0, 12
addi x3, x0, 2
block1:
add x4, x1, x2
sub x5, x4, x3
and x6, x4, x5
or x7, x6, x2
xor x8, x7, x1
sll x9, x3, x1
srl x10, x2, x3
sra x11, x5, x3
slt x12, x1, x2
sltu x13, x1, x2
addi x14, x14, 1
andi x15, x14, 7
ori x16, x15, 4
xori x17, x16, 3
slli x18, x17, 1
srli x19, x18, 1
srai x20, x19, 1
slti x21, x1, 8
sltiu x22, x1, 8
sw x4, 0(x30)
sh x5, 8(x30)
sb x6, 16(x30)
lw x23, 0(x30)
lh x24, 8(x30)
lb x25, 16(x30)
lhu x26, 8(x30)
lbu x27, 16(x30)
beq x1, x2, block1_beq
bne x1, x2, block1_bne
block1_beq:
add x28, x0, x0
block1_bne:
blt x1, x2, block1_blt
add x28, x28, x0
block1_blt:
bge x2, x1, block1_bge
add x28, x28, x0
block1_bge:
bltu x1, x2, block1_bltu
add x28, x28, x0
block1_bltu:
bgeu x2, x1, block1_bgeu
add x28, x28, x0
block1_bgeu:
addi x1, x1, 1
block2:
add x4, x1, x2
sub x5, x4, x3
and x6, x4, x5
or x7, x6, x2
xor x8, x7, x1
sll x9, x3, x1
srl x10, x2, x3
sra x11, x5, x3
slt x12, x1, x2
sltu x13, x1, x2
addi x14, x14, 1
andi x15, x14, 7
ori x16, x15, 4
xori x17, x16, 3
slli x18, x17, 1
srli x19, x18, 1
srai x20, x19, 1
slti x21, x1, 8
sltiu x22, x1, 8
sw x4, 4(x30)
sh x5, 12(x30)
sb x6, 20(x30)
lw x23, 4(x30)
lh x24, 12(x30)
lb x25, 20(x30)
lhu x26, 12(x30)
lbu x27, 20(x30)
beq x1, x2, block2_beq
bne x1, x2, block2_bne
block2_beq:
add x28, x0, x0
block2_bne:
blt x1, x2, block2_blt
add x28, x28, x0
block2_blt:
bge x2, x1, block2_bge
add x28, x28, x0
block2_bge:
bltu x1, x2, block2_bltu
add x28, x28, x0
block2_bltu:
bgeu x2, x1, block2_bgeu
add x28, x28, x0
block2_bgeu:
jal x29, helper1
after_helper1:
add x5, x23, x24
addi x10, x0, 10
beq x0, x0, end1
helper1:
add x6, x25, x26
jalr x0, x29, 0
end1:
ecall
