#include "encode.h"

uint32_t encode_r(unsigned opcode, unsigned funct3, unsigned funct7,
                  unsigned rd, unsigned rs1, unsigned rs2) {
    return ((funct7 & 0x7F) << 25) |
           ((rs2 & 0x1F) << 20) |
           ((rs1 & 0x1F) << 15) |
           ((funct3 & 0x7) << 12) |
           ((rd & 0x1F) << 7) |
           (opcode & 0x7F);
}

uint32_t encode_i(unsigned opcode, unsigned funct3, unsigned rd,
                  unsigned rs1, int imm) {
    return (((uint32_t)imm & 0xFFF) << 20) |
           ((rs1 & 0x1F) << 15) |
           ((funct3 & 0x7) << 12) |
           ((rd & 0x1F) << 7) |
           (opcode & 0x7F);
}

uint32_t encode_shift_i(unsigned opcode, unsigned funct3, unsigned funct7,
                        unsigned rd, unsigned rs1, unsigned shamt) {
    return ((funct7 & 0x7F) << 25) |
           ((shamt & 0x1F) << 20) |
           ((rs1 & 0x1F) << 15) |
           ((funct3 & 0x7) << 12) |
           ((rd & 0x1F) << 7) |
           (opcode & 0x7F);
}

uint32_t encode_s(unsigned opcode, unsigned funct3, unsigned rs1,
                  unsigned rs2, int imm) {
    uint32_t uimm = (uint32_t)imm & 0xFFF;
    return (((uimm >> 5) & 0x7F) << 25) |
           ((rs2 & 0x1F) << 20) |
           ((rs1 & 0x1F) << 15) |
           ((funct3 & 0x7) << 12) |
           ((uimm & 0x1F) << 7) |
           (opcode & 0x7F);
}

uint32_t encode_b(unsigned opcode, unsigned funct3, unsigned rs1,
                  unsigned rs2, int imm) {
    uint32_t uimm = (uint32_t)imm & 0x1FFF;
    return (((uimm >> 12) & 0x1) << 31) |
           (((uimm >> 5) & 0x3F) << 25) |
           ((rs2 & 0x1F) << 20) |
           ((rs1 & 0x1F) << 15) |
           ((funct3 & 0x7) << 12) |
           (((uimm >> 1) & 0xF) << 8) |
           (((uimm >> 11) & 0x1) << 7) |
           (opcode & 0x7F);
}

uint32_t encode_j(unsigned opcode, unsigned rd, int imm) {
    uint32_t uimm = (uint32_t)imm & 0x1FFFFF;
    return (((uimm >> 20) & 0x1) << 31) |
           (((uimm >> 1) & 0x3FF) << 21) |
           (((uimm >> 11) & 0x1) << 20) |
           (((uimm >> 12) & 0xFF) << 12) |
           ((rd & 0x1F) << 7) |
           (opcode & 0x7F);
}

int imm_fits_signed(int imm, int bits) {
    int min = -(1 << (bits - 1));
    int max = (1 << (bits - 1)) - 1;
    return imm >= min && imm <= max;
}

int imm_is_aligned(int imm, int alignment) {
    return alignment > 0 && imm % alignment == 0;
}
