#include <assert.h>

#include "registers.h"

int main(void) {
    assert(parse_register("x0") == 0);
    assert(parse_register("x5") == 5);
    assert(parse_register("x31") == 31);
    assert(parse_register("x32") == -1);
    assert(parse_register("a0") == -1);
    assert(parse_register("x") == -1);
    return 0;
}
