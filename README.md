# RISC-V Assembler Lab

This project implements a simple two-pass assembler for a subset of the RV32I instruction set. It reads a RISC-V assembly source file, resolves labels in the first pass, encodes instructions in the second pass, and prints one 32-bit machine-code word per line in hexadecimal.

## Supported Instructions

- R-type: `add`, `sub`, `and`, `or`, `xor`, `sll`, `srl`, `sra`, `slt`, `sltu`
- I-type: `addi`, `andi`, `ori`, `xori`, `slli`, `srli`, `srai`, `slti`, `sltiu`, `lb`, `lbu`, `lh`, `lhu`, `lw`, `jalr`
- S-type: `sb`, `sh`, `sw`
- B-type: `beq`, `bne`, `blt`, `bge`, `bltu`, `bgeu`
- J-type: `jal`
- System: `ecall`

## Features

- Two-pass assembly with label resolution
- Register parsing for `x0` to `x31`
- Immediate validation for each instruction format
- Branch and jump offset encoding
- Load and store parsing with `offset(base)` syntax

## Build

Compile the assembler:

```bash
make assembler
```

## Usage

Run the assembler on an input file:

```bash
./assembler examples/test_case_1.s
```

The output is written to standard output as 8-digit hexadecimal values, one instruction per line:

```text
00500093
00a00113
...
```

## Testing

Run all unit tests:

```bash
make test
```

The test suite covers the parser, register handling, instruction table, symbol table, encoding logic, and end-to-end assembly flow.

## Example Files

- `examples/test_case_1.s`: compact functional test program
- `examples/test_case_2.s`: medium-size block-based test program
- `examples/test_case_3.s`: larger block-based stress test
- `examples/test_report.txt`: local verification note

## Project Structure

- `src/`: assembler implementation
- `tests/`: unit and integration tests
- `examples/`: sample input programs
- `Makefile`: build and test commands
