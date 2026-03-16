#include <assert.h>
#include <string.h>

#include "instr_table.h"

int main(void) {
    const InstrSpec *add = find_instruction("add");
    const InstrSpec *beq = find_instruction("beq");
    const InstrSpec *jal = find_instruction("jal");
    const InstrSpec *ecall = find_instruction("ecall");

    assert(add != NULL);
    assert(strcmp(add->name, "add") == 0);
    assert(add->format == FMT_R);
    assert(add->opcode == 0x33);

    assert(beq != NULL);
    assert(beq->format == FMT_B);
    assert(beq->funct3 == 0x0);

    assert(jal != NULL);
    assert(jal->format == FMT_J);
    assert(ecall != NULL);
    assert(ecall->format == FMT_SYS);
    assert(find_instruction("mul") == NULL);
    return 0;
}
