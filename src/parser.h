#ifndef PARSER_H
#define PARSER_H

#define MAX_LABEL_LEN 63
#define MAX_MNEMONIC_LEN 15
#define MAX_OPERANDS 4
#define MAX_OPERAND_LEN 63

typedef struct {
    int has_label;
    int has_instruction;
    char label[MAX_LABEL_LEN + 1];
    char mnemonic[MAX_MNEMONIC_LEN + 1];
    int operand_count;
    char operands[MAX_OPERANDS][MAX_OPERAND_LEN + 1];
} ParsedLine;

int parse_line(const char *line, ParsedLine *parsed);

#endif
