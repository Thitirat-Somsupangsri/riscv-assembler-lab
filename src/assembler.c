#include "assembler.h"

#include "encode.h"
#include "instr_table.h"
#include "parser.h"
#include "registers.h"
#include "symbols.h"

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SOURCE_LINES 1024
#define MAX_LINE_LEN 256

typedef struct {
    char *lines[MAX_SOURCE_LINES];
    int count;
} SourceFile;

static void free_source(SourceFile *source) {
    int i;
    for (i = 0; i < source->count; ++i) {
        free(source->lines[i]);
    }
    source->count = 0;
}

static char *dup_line(const char *line) {
    size_t len = strlen(line);
    char *copy = (char *)malloc(len + 1);
    if (copy != NULL) {
        memcpy(copy, line, len + 1);
    }
    return copy;
}

static int read_source(FILE *input, SourceFile *source) {
    char buffer[MAX_LINE_LEN];

    source->count = 0;
    while (fgets(buffer, sizeof(buffer), input) != NULL) {
        if (source->count >= MAX_SOURCE_LINES) {
            return -1;
        }
        source->lines[source->count] = dup_line(buffer);
        if (source->lines[source->count] == NULL) {
            return -1;
        }
        ++source->count;
    }

    return ferror(input) ? -1 : 0;
}

static int parse_immediate(const char *text, int *value) {
    char *end = NULL;
    long parsed;

    if (text == NULL || value == NULL || text[0] == '\0') {
        return -1;
    }

    errno = 0;
    parsed = strtol(text, &end, 0);
    if (errno != 0 || end == NULL || *end != '\0') {
        return -1;
    }

    *value = (int)parsed;
    return 0;
}

static int parse_reg_operand(const char *text, int *value) {
    int reg = parse_register(text);
    if (reg < 0) {
        return -1;
    }
    *value = reg;
    return 0;
}

static int resolve_immediate(const ParsedLine *parsed, int operand_index,
                             const SymbolTable *symbols, int pc, int *value) {
    if (parse_immediate(parsed->operands[operand_index], value) == 0) {
        return 0;
    }
    if (symbols_find(symbols, parsed->operands[operand_index], value) == 0) {
        *value -= pc;
        return 0;
    }
    return -1;
}

static int is_shift_imm(const InstrSpec *spec) {
    return spec != NULL &&
           (!strcmp(spec->name, "slli") || !strcmp(spec->name, "srli") || !strcmp(spec->name, "srai"));
}

static int first_pass(const SourceFile *source, SymbolTable *symbols) {
    int pc = 0;
    int i;

    symbols_init(symbols);
    for (i = 0; i < source->count; ++i) {
        ParsedLine parsed;
        if (parse_line(source->lines[i], &parsed) != 0) {
            fprintf(stderr, "Parse error on line %d\n", i + 1);
            return -1;
        }
        if (parsed.has_label && symbols_add(symbols, parsed.label, pc) != 0) {
            fprintf(stderr, "Duplicate or invalid label on line %d\n", i + 1);
            return -1;
        }
        if (parsed.has_instruction) {
            pc += 4;
        }
    }

    return 0;
}

static int encode_instruction(const ParsedLine *parsed, const SymbolTable *symbols,
                              int pc, uint32_t *word) {
    const InstrSpec *spec = find_instruction(parsed->mnemonic);
    int rd, rs1, rs2, imm;

    if (spec == NULL) {
        return -1;
    }

    switch (spec->format) {
        case FMT_R:
            if (parsed->operand_count != 3 ||
                parse_reg_operand(parsed->operands[0], &rd) != 0 ||
                parse_reg_operand(parsed->operands[1], &rs1) != 0 ||
                parse_reg_operand(parsed->operands[2], &rs2) != 0) {
                return -1;
            }
            *word = encode_r(spec->opcode, spec->funct3, spec->funct7, rd, rs1, rs2);
            return 0;

        case FMT_I:
            if (!strcmp(spec->name, "jalr")) {
                if (parsed->operand_count != 3 ||
                    parse_reg_operand(parsed->operands[0], &rd) != 0 ||
                    parse_reg_operand(parsed->operands[1], &rs1) != 0 ||
                    parse_immediate(parsed->operands[2], &imm) != 0 ||
                    !imm_fits_signed(imm, 12)) {
                    return -1;
                }
                *word = encode_i(spec->opcode, spec->funct3, rd, rs1, imm);
                return 0;
            }
            if (!strcmp(spec->name, "lb") || !strcmp(spec->name, "lbu") ||
                !strcmp(spec->name, "lh") || !strcmp(spec->name, "lhu") ||
                !strcmp(spec->name, "lw")) {
                if (parsed->operand_count != 3 ||
                    parse_reg_operand(parsed->operands[0], &rd) != 0 ||
                    parse_immediate(parsed->operands[1], &imm) != 0 ||
                    parse_reg_operand(parsed->operands[2], &rs1) != 0 ||
                    !imm_fits_signed(imm, 12)) {
                    return -1;
                }
                *word = encode_i(spec->opcode, spec->funct3, rd, rs1, imm);
                return 0;
            }
            if (is_shift_imm(spec)) {
                if (parsed->operand_count != 3 ||
                    parse_reg_operand(parsed->operands[0], &rd) != 0 ||
                    parse_reg_operand(parsed->operands[1], &rs1) != 0 ||
                    parse_immediate(parsed->operands[2], &imm) != 0 ||
                    imm < 0 || imm > 31) {
                    return -1;
                }
                *word = encode_shift_i(spec->opcode, spec->funct3, spec->funct7, rd, rs1,
                                       (unsigned)imm);
                return 0;
            }
            if (parsed->operand_count != 3 ||
                parse_reg_operand(parsed->operands[0], &rd) != 0 ||
                parse_reg_operand(parsed->operands[1], &rs1) != 0 ||
                parse_immediate(parsed->operands[2], &imm) != 0 ||
                !imm_fits_signed(imm, 12)) {
                return -1;
            }
            *word = encode_i(spec->opcode, spec->funct3, rd, rs1, imm);
            return 0;

        case FMT_S:
            if (parsed->operand_count != 3 ||
                parse_reg_operand(parsed->operands[0], &rs2) != 0 ||
                parse_immediate(parsed->operands[1], &imm) != 0 ||
                parse_reg_operand(parsed->operands[2], &rs1) != 0 ||
                !imm_fits_signed(imm, 12)) {
                return -1;
            }
            *word = encode_s(spec->opcode, spec->funct3, rs1, rs2, imm);
            return 0;

        case FMT_B:
            if (parsed->operand_count != 3 ||
                parse_reg_operand(parsed->operands[0], &rs1) != 0 ||
                parse_reg_operand(parsed->operands[1], &rs2) != 0 ||
                resolve_immediate(parsed, 2, symbols, pc, &imm) != 0 ||
                !imm_fits_signed(imm, 13) || !imm_is_aligned(imm, 2)) {
                return -1;
            }
            *word = encode_b(spec->opcode, spec->funct3, rs1, rs2, imm);
            return 0;

        case FMT_J:
            if (parsed->operand_count == 1) {
                rd = 1;
                if (resolve_immediate(parsed, 0, symbols, pc, &imm) != 0 ||
                    !imm_fits_signed(imm, 21) || !imm_is_aligned(imm, 2)) {
                    return -1;
                }
            } else if (parsed->operand_count == 2 &&
                       parse_reg_operand(parsed->operands[0], &rd) == 0 &&
                       resolve_immediate(parsed, 1, symbols, pc, &imm) == 0 &&
                       imm_fits_signed(imm, 21) && imm_is_aligned(imm, 2)) {
                /* use parsed values */
            } else {
                return -1;
            }
            *word = encode_j(spec->opcode, rd, imm);
            return 0;

        case FMT_SYS:
            if (parsed->operand_count != 0) {
                return -1;
            }
            *word = 0x00000073u;
            return 0;
    }

    return -1;
}

static int second_pass(const SourceFile *source, const SymbolTable *symbols, FILE *output) {
    int pc = 0;
    int i;

    for (i = 0; i < source->count; ++i) {
        ParsedLine parsed;
        uint32_t word;

        if (parse_line(source->lines[i], &parsed) != 0) {
            fprintf(stderr, "Parse error on line %d\n", i + 1);
            return -1;
        }
        if (!parsed.has_instruction) {
            continue;
        }
        if (encode_instruction(&parsed, symbols, pc, &word) != 0) {
            fprintf(stderr, "Assembly error on line %d: %s\n", i + 1, parsed.mnemonic);
            return -1;
        }
        fprintf(output, "%08x\n", word);
        pc += 4;
    }

    return 0;
}

int assemble_stream(FILE *input, FILE *output) {
    SourceFile source;
    SymbolTable symbols;
    int status;

    if (input == NULL || output == NULL) {
        return -1;
    }

    source.count = 0;
    if (read_source(input, &source) != 0) {
        free_source(&source);
        return -1;
    }

    status = first_pass(&source, &symbols);
    if (status == 0) {
        status = second_pass(&source, &symbols, output);
    }

    free_source(&source);
    return status;
}

int assemble_file(const char *input_path) {
    FILE *input;
    int status;

    if (input_path == NULL) {
        return -1;
    }

    input = fopen(input_path, "r");
    if (input == NULL) {
        perror("fopen");
        return -1;
    }

    status = assemble_stream(input, stdout);
    fclose(input);
    return status;
}
