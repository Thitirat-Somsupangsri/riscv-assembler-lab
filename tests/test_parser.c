#include <assert.h>
#include <string.h>

#include "parser.h"

int main(void) {
    ParsedLine parsed;

    assert(parse_line("loop: add x1, x2, x3", &parsed) == 0);
    assert(parsed.has_label == 1);
    assert(strcmp(parsed.label, "loop") == 0);
    assert(parsed.has_instruction == 1);
    assert(strcmp(parsed.mnemonic, "add") == 0);
    assert(parsed.operand_count == 3);
    assert(strcmp(parsed.operands[0], "x1") == 0);
    assert(strcmp(parsed.operands[1], "x2") == 0);
    assert(strcmp(parsed.operands[2], "x3") == 0);

    assert(parse_line("lw x5, 8(x6) # comment", &parsed) == 0);
    assert(parsed.has_label == 0);
    assert(strcmp(parsed.mnemonic, "lw") == 0);
    assert(parsed.operand_count == 3);
    assert(strcmp(parsed.operands[0], "x5") == 0);
    assert(strcmp(parsed.operands[1], "8") == 0);
    assert(strcmp(parsed.operands[2], "x6") == 0);

    assert(parse_line("only_label:", &parsed) == 0);
    assert(parsed.has_label == 1);
    assert(parsed.has_instruction == 0);

    return 0;
}
