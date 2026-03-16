start:
addi x1, x0, 1
add x30, x2, x0
addi x2, x0, 64
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
addi x14, x14, 2
andi x15, x14, 31
ori x16, x15, 4
xori x17, x16, 9
slli x18, x17, 1
srli x19, x18, 1
srai x20, x19, 1
slti x21, x1, 40
sltiu x22, x1, 40
sw x4, 0(x30)
sh x5, 24(x30)
sb x6, 48(x30)
lw x23, 0(x30)
lh x24, 24(x30)
lb x25, 48(x30)
lhu x26, 24(x30)
lbu x27, 48(x30)
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
addi x14, x14, 2
andi x15, x14, 31
ori x16, x15, 4
xori x17, x16, 9
slli x18, x17, 1
srli x19, x18, 1
srai x20, x19, 1
slti x21, x1, 40
sltiu x22, x1, 40
sw x4, 4(x30)
sh x5, 28(x30)
sb x6, 52(x30)
lw x23, 4(x30)
lh x24, 28(x30)
lb x25, 52(x30)
lhu x26, 28(x30)
lbu x27, 52(x30)
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
addi x1, x1, 1
block3:
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
addi x14, x14, 2
andi x15, x14, 31
ori x16, x15, 4
xori x17, x16, 9
slli x18, x17, 1
srli x19, x18, 1
srai x20, x19, 1
slti x21, x1, 40
sltiu x22, x1, 40
sw x4, 8(x30)
sh x5, 32(x30)
sb x6, 56(x30)
lw x23, 8(x30)
lh x24, 32(x30)
lb x25, 56(x30)
lhu x26, 32(x30)
lbu x27, 56(x30)
beq x1, x2, block3_beq
bne x1, x2, block3_bne
block3_beq:
add x28, x0, x0
block3_bne:
blt x1, x2, block3_blt
add x28, x28, x0
block3_blt:
bge x2, x1, block3_bge
add x28, x28, x0
block3_bge:
bltu x1, x2, block3_bltu
add x28, x28, x0
block3_bltu:
bgeu x2, x1, block3_bgeu
add x28, x28, x0
block3_bgeu:
addi x1, x1, 1
block4:
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
addi x14, x14, 2
andi x15, x14, 31
ori x16, x15, 4
xori x17, x16, 9
slli x18, x17, 1
srli x19, x18, 1
srai x20, x19, 1
slti x21, x1, 40
sltiu x22, x1, 40
sw x4, 12(x30)
sh x5, 36(x30)
sb x6, 60(x30)
lw x23, 12(x30)
lh x24, 36(x30)
lb x25, 60(x30)
lhu x26, 36(x30)
lbu x27, 60(x30)
beq x1, x2, block4_beq
bne x1, x2, block4_bne
block4_beq:
add x28, x0, x0
block4_bne:
blt x1, x2, block4_blt
add x28, x28, x0
block4_blt:
bge x2, x1, block4_bge
add x28, x28, x0
block4_bge:
bltu x1, x2, block4_bltu
add x28, x28, x0
block4_bltu:
bgeu x2, x1, block4_bgeu
add x28, x28, x0
block4_bgeu:
addi x1, x1, 1
block5:
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
addi x14, x14, 2
andi x15, x14, 31
ori x16, x15, 4
xori x17, x16, 9
slli x18, x17, 1
srli x19, x18, 1
srai x20, x19, 1
slti x21, x1, 40
sltiu x22, x1, 40
sw x4, 16(x30)
sh x5, 40(x30)
sb x6, 64(x30)
lw x23, 16(x30)
lh x24, 40(x30)
lb x25, 64(x30)
lhu x26, 40(x30)
lbu x27, 64(x30)
beq x1, x2, block5_beq
bne x1, x2, block5_bne
block5_beq:
add x28, x0, x0
block5_bne:
blt x1, x2, block5_blt
add x28, x28, x0
block5_blt:
bge x2, x1, block5_bge
add x28, x28, x0
block5_bge:
bltu x1, x2, block5_bltu
add x28, x28, x0
block5_bltu:
bgeu x2, x1, block5_bgeu
add x28, x28, x0
block5_bgeu:
addi x1, x1, 1
block6:
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
addi x14, x14, 2
andi x15, x14, 31
ori x16, x15, 4
xori x17, x16, 9
slli x18, x17, 1
srli x19, x18, 1
srai x20, x19, 1
slti x21, x1, 40
sltiu x22, x1, 40
sw x4, 20(x30)
sh x5, 44(x30)
sb x6, 68(x30)
lw x23, 20(x30)
lh x24, 44(x30)
lb x25, 68(x30)
lhu x26, 44(x30)
lbu x27, 68(x30)
beq x1, x2, block6_beq
bne x1, x2, block6_bne
block6_beq:
add x28, x0, x0
block6_bne:
blt x1, x2, block6_blt
add x28, x28, x0
block6_blt:
bge x2, x1, block6_bge
add x28, x28, x0
block6_bge:
bltu x1, x2, block6_bltu
add x28, x28, x0
block6_bltu:
bgeu x2, x1, block6_bgeu
add x28, x28, x0
block6_bgeu:
jal x29, helper3
after_helper3:
add x5, x23, x24
addi x10, x0, 10
beq x0, x0, end3
helper3:
add x6, x25, x26
jalr x0, x29, 0
end3:
ecall
