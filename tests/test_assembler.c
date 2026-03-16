#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assembler.h"

int main(void) {
    const char *program =
        "start:\n"
        "addi x1, x0, 5\n"
        "addi x2, x0, 10\n"
        "loop: add x3, x1, x2\n"
        "beq x3, x0, done\n"
        "jal x0, loop\n"
        "done: sw x3, 0(x0)\n";
    const char *expected =
        "00500093\n"
        "00a00113\n"
        "002081b3\n"
        "00018463\n"
        "ff9ff06f\n"
        "00302023\n";
    FILE *input = tmpfile();
    FILE *output = tmpfile();
    char buffer[512];
    size_t size;

    assert(input != NULL);
    assert(output != NULL);
    fputs(program, input);
    rewind(input);

    assert(assemble_stream(input, output) == 0);
    rewind(output);
    size = fread(buffer, 1, sizeof(buffer) - 1, output);
    buffer[size] = '\0';
    assert(strcmp(buffer, expected) == 0);

    fclose(input);
    fclose(output);
    return 0;
}
