#include <stdio.h>
#include <stdlib.h>

#include "assembler.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input.s>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (assemble_file(argv[1]) != 0) {
        fprintf(stderr, "Assembly failed for '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
