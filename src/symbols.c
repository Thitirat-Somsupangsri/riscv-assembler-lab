#include "symbols.h"

#include <string.h>

void symbols_init(SymbolTable *table) {
    if (table != NULL) {
        table->count = 0;
    }
}

int symbols_find(const SymbolTable *table, const char *name, int *address) {
    int i;

    if (table == NULL || name == NULL) {
        return -1;
    }

    for (i = 0; i < table->count; ++i) {
        if (strcmp(table->entries[i].name, name) == 0) {
            if (address != NULL) {
                *address = table->entries[i].address;
            }
            return 0;
        }
    }

    return -1;
}

int symbols_add(SymbolTable *table, const char *name, int address) {
    if (table == NULL || name == NULL || name[0] == '\0') {
        return -1;
    }
    if (table->count >= MAX_SYMBOLS) {
        return -1;
    }
    if (symbols_find(table, name, NULL) == 0) {
        return -1;
    }
    if (strlen(name) > MAX_SYMBOL_NAME) {
        return -1;
    }

    strcpy(table->entries[table->count].name, name);
    table->entries[table->count].address = address;
    ++table->count;
    return 0;
}
