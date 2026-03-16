start:
addi x1, x0, 5
addi x2, x0, 10
addi x30, x0, 256
add x3, x1, x2
sub x4, x3, x1
and x5, x3, x4
or x6, x4, x2
xor x7, x5, x6
sll x8, x1, x0
srl x9, x2, x0
sra x10, x4, x0
slt x11, x1, x2
sltu x12, x1, x2
addi x13, x0, 1
andi x14, x13, 1
ori x15, x14, 2
xori x16, x15, 3
slli x17, x16, 1
srli x18, x17, 1
srai x19, x18, 1
slti x20, x1, 6
sltiu x21, x1, 6
sw x3, 0(x30)
sh x4, 4(x30)
sb x5, 8(x30)
lw x22, 0(x30)
lh x23, 4(x30)
lb x24, 8(x30)
lhu x25, 4(x30)
lbu x26, 8(x30)
beq x1, x2, skip_beq
bne x1, x2, take_bne
skip_beq:
add x29, x0, x0
take_bne:
blt x1, x2, take_blt
add x29, x29, x0
take_blt:
bge x2, x1, take_bge
add x29, x29, x0
take_bge:
bltu x1, x2, take_bltu
add x29, x29, x0
take_bltu:
bgeu x2, x1, take_bgeu
add x29, x29, x0
take_bgeu:
jal x27, helper1
after_helper1:
add x29, x22, x23
beq x0, x0, end1
helper1:
add x28, x24, x25
jalr x0, x27, 0
end1:
beq x0, x0, end1
