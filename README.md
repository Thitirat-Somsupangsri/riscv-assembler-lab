# RISC-V Assembler Lab

This project implements a simple two-pass assembler for a subset of RV32I.

Supported instructions:
- R-type: add, sub, and, or, xor, sll, srl, sra, slt, sltu
- I-type: addi, andi, ori, xori, slli, srli, srai, slti, sltiu, lb, lbu, lh, lhu, lw, jalr
- S-type: sb, sh, sw
- B-type: beq, bne, blt, bge, bltu, bgeu
- J-type: jal

Build:
- `make assembler`

Run:
- `./assembler examples/test_case_1.s`

Test:
- `make test`
