#ifndef SYMBOLS_H
#define SYMBOLS_H

#define MAX_SYMBOLS 256
#define MAX_SYMBOL_NAME 63

typedef struct {
    char name[MAX_SYMBOL_NAME + 1];
    int address;
} Symbol;

typedef struct {
    Symbol entries[MAX_SYMBOLS];
    int count;
} SymbolTable;

void symbols_init(SymbolTable *table);
int symbols_add(SymbolTable *table, const char *name, int address);
int symbols_find(const SymbolTable *table, const char *name, int *address);

#endif
