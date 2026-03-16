entry:
addi x1, x0, 1
addi x2, x0, 64
addi x3, x0, 2
addi x30, x0, 512
section1:
add x4, x1, x2
sub x5, x2, x1
and x6, x4, x5
or x7, x6, x3
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
sh x5, 32(x30)
sb x6, 64(x30)
lw x23, 0(x30)
lh x24, 32(x30)
lb x25, 64(x30)
lhu x26, 32(x30)
lbu x27, 64(x30)
beq x1, x2, section1_beq
bne x1, x2, section1_bne
section1_beq:
add x28, x0, x0
section1_bne:
blt x1, x2, section1_blt
add x28, x28, x0
section1_blt:
bge x2, x1, section1_bge
add x28, x28, x0
section1_bge:
bltu x1, x2, section1_bltu
add x28, x28, x0
section1_bltu:
bgeu x2, x1, section1_bgeu
add x28, x28, x0
section1_bgeu:
addi x1, x1, 1
section2:
add x4, x1, x2
sub x5, x2, x1
and x6, x4, x5
or x7, x6, x3
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
sh x5, 36(x30)
sb x6, 68(x30)
lw x23, 4(x30)
lh x24, 36(x30)
lb x25, 68(x30)
lhu x26, 36(x30)
lbu x27, 68(x30)
beq x1, x2, section2_beq
bne x1, x2, section2_bne
section2_beq:
add x28, x0, x0
section2_bne:
blt x1, x2, section2_blt
add x28, x28, x0
section2_blt:
bge x2, x1, section2_bge
add x28, x28, x0
section2_bge:
bltu x1, x2, section2_bltu
add x28, x28, x0
section2_bltu:
bgeu x2, x1, section2_bgeu
add x28, x28, x0
section2_bgeu:
addi x1, x1, 1
section3:
add x4, x1, x2
sub x5, x2, x1
and x6, x4, x5
or x7, x6, x3
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
sh x5, 40(x30)
sb x6, 72(x30)
lw x23, 8(x30)
lh x24, 40(x30)
lb x25, 72(x30)
lhu x26, 40(x30)
lbu x27, 72(x30)
beq x1, x2, section3_beq
bne x1, x2, section3_bne
section3_beq:
add x28, x0, x0
section3_bne:
blt x1, x2, section3_blt
add x28, x28, x0
section3_blt:
bge x2, x1, section3_bge
add x28, x28, x0
section3_bge:
bltu x1, x2, section3_bltu
add x28, x28, x0
section3_bltu:
bgeu x2, x1, section3_bgeu
add x28, x28, x0
section3_bgeu:
addi x1, x1, 1
section4:
add x4, x1, x2
sub x5, x2, x1
and x6, x4, x5
or x7, x6, x3
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
sh x5, 44(x30)
sb x6, 76(x30)
lw x23, 12(x30)
lh x24, 44(x30)
lb x25, 76(x30)
lhu x26, 44(x30)
lbu x27, 76(x30)
beq x1, x2, section4_beq
bne x1, x2, section4_bne
section4_beq:
add x28, x0, x0
section4_bne:
blt x1, x2, section4_blt
add x28, x28, x0
section4_blt:
bge x2, x1, section4_bge
add x28, x28, x0
section4_bge:
bltu x1, x2, section4_bltu
add x28, x28, x0
section4_bltu:
bgeu x2, x1, section4_bgeu
add x28, x28, x0
section4_bgeu:
addi x1, x1, 1
section5:
add x4, x1, x2
sub x5, x2, x1
and x6, x4, x5
or x7, x6, x3
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
sh x5, 48(x30)
sb x6, 80(x30)
lw x23, 16(x30)
lh x24, 48(x30)
lb x25, 80(x30)
lhu x26, 48(x30)
lbu x27, 80(x30)
beq x1, x2, section5_beq
bne x1, x2, section5_bne
section5_beq:
add x28, x0, x0
section5_bne:
blt x1, x2, section5_blt
add x28, x28, x0
section5_blt:
bge x2, x1, section5_bge
add x28, x28, x0
section5_bge:
bltu x1, x2, section5_bltu
add x28, x28, x0
section5_bltu:
bgeu x2, x1, section5_bgeu
add x28, x28, x0
section5_bgeu:
addi x1, x1, 1
section6:
add x4, x1, x2
sub x5, x2, x1
and x6, x4, x5
or x7, x6, x3
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
sh x5, 52(x30)
sb x6, 84(x30)
lw x23, 20(x30)
lh x24, 52(x30)
lb x25, 84(x30)
lhu x26, 52(x30)
lbu x27, 84(x30)
beq x1, x2, section6_beq
bne x1, x2, section6_bne
section6_beq:
add x28, x0, x0
section6_bne:
blt x1, x2, section6_blt
add x28, x28, x0
section6_blt:
bge x2, x1, section6_bge
add x28, x28, x0
section6_bge:
bltu x1, x2, section6_bltu
add x28, x28, x0
section6_bltu:
bgeu x2, x1, section6_bgeu
add x28, x28, x0
section6_bgeu:
addi x1, x1, 1
section7:
add x4, x1, x2
sub x5, x2, x1
and x6, x4, x5
or x7, x6, x3
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
sh x5, 32(x30)
sb x6, 64(x30)
lw x23, 0(x30)
lh x24, 32(x30)
lb x25, 64(x30)
lhu x26, 32(x30)
lbu x27, 64(x30)
beq x1, x2, section7_beq
bne x1, x2, section7_bne
section7_beq:
add x28, x0, x0
section7_bne:
blt x1, x2, section7_blt
add x28, x28, x0
section7_blt:
bge x2, x1, section7_bge
add x28, x28, x0
section7_bge:
bltu x1, x2, section7_bltu
add x28, x28, x0
section7_bltu:
bgeu x2, x1, section7_bgeu
add x28, x28, x0
section7_bgeu:
addi x1, x1, 1
section8:
add x4, x1, x2
sub x5, x2, x1
and x6, x4, x5
or x7, x6, x3
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
sh x5, 36(x30)
sb x6, 68(x30)
lw x23, 4(x30)
lh x24, 36(x30)
lb x25, 68(x30)
lhu x26, 36(x30)
lbu x27, 68(x30)
beq x1, x2, section8_beq
bne x1, x2, section8_bne
section8_beq:
add x28, x0, x0
section8_bne:
blt x1, x2, section8_blt
add x28, x28, x0
section8_blt:
bge x2, x1, section8_bge
add x28, x28, x0
section8_bge:
bltu x1, x2, section8_bltu
add x28, x28, x0
section8_bltu:
bgeu x2, x1, section8_bgeu
add x28, x28, x0
section8_bgeu:
addi x1, x1, 1
jal x29, helper3
after_helper3:
add x5, x23, x24
add x6, x25, x26
beq x0, x0, end3
helper3:
add x7, x27, x22
jalr x0, x29, 0
end3:
beq x0, x0, end3
