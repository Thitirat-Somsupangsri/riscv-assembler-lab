CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Isrc

SRC = src/main.c src/assembler.c src/parser.c src/registers.c src/instr_table.c src/symbols.c src/encode.c
TEST_COMMON = src/assembler.c src/parser.c src/registers.c src/instr_table.c src/symbols.c src/encode.c

all: assembler

assembler: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o assembler

test_registers: tests/test_registers.c src/registers.c src/registers.h
	$(CC) $(CFLAGS) tests/test_registers.c src/registers.c -o test_registers

test_parser: tests/test_parser.c src/parser.c src/parser.h
	$(CC) $(CFLAGS) tests/test_parser.c src/parser.c -o test_parser

test_instr_table: tests/test_instr_table.c src/instr_table.c src/instr_table.h
	$(CC) $(CFLAGS) tests/test_instr_table.c src/instr_table.c -o test_instr_table

test_symbols: tests/test_symbols.c src/symbols.c src/symbols.h
	$(CC) $(CFLAGS) tests/test_symbols.c src/symbols.c -o test_symbols

test_encode: tests/test_encode.c src/encode.c src/encode.h
	$(CC) $(CFLAGS) tests/test_encode.c src/encode.c -o test_encode

test_assembler: tests/test_assembler.c $(TEST_COMMON)
	$(CC) $(CFLAGS) tests/test_assembler.c $(TEST_COMMON) -o test_assembler

test: test_registers test_parser test_instr_table test_symbols test_encode test_assembler
	./test_registers
	./test_parser
	./test_instr_table
	./test_symbols
	./test_encode
	./test_assembler

clean:
	rm -f assembler test_registers test_parser test_instr_table test_symbols test_encode test_assembler
