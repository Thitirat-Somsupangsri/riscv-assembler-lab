#ifndef INSTR_TABLE_H
#define INSTR_TABLE_H

typedef enum {
    FMT_R,
    FMT_I,
    FMT_S,
    FMT_B,
    FMT_J,
    FMT_SYS
} InstrFormat;

typedef struct {
    const char *name;
    InstrFormat format;
    unsigned opcode;
    unsigned funct3;
    unsigned funct7;
} InstrSpec;

const InstrSpec *find_instruction(const char *mnemonic);

#endif
