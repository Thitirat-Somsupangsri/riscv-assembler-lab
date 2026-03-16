#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdio.h>

int assemble_file(const char *input_path);
int assemble_stream(FILE *input, FILE *output);

#endif
