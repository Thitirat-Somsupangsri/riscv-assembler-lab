#include <assert.h>

#include "symbols.h"

int main(void) {
    SymbolTable table;
    int address = -1;

    symbols_init(&table);
    assert(symbols_add(&table, "start", 0) == 0);
    assert(symbols_add(&table, "loop", 12) == 0);
    assert(symbols_add(&table, "loop", 16) == -1);
    assert(symbols_find(&table, "loop", &address) == 0);
    assert(address == 12);
    assert(symbols_find(&table, "missing", &address) == -1);
    return 0;
}
