#include "registers.h"

#include <ctype.h>
#include <stdlib.h>

int parse_register(const char *name) {
    char *end = NULL;
    long value;

    if (name == NULL || name[0] != 'x' || name[1] == '\0') {
        return -1;
    }

    for (const char *p = name + 1; *p != '\0'; ++p) {
        if (!isdigit((unsigned char)*p)) {
            return -1;
        }
    }

    value = strtol(name + 1, &end, 10);
    if (end == NULL || *end != '\0' || value < 0 || value > 31) {
        return -1;
    }

    return (int)value;
}
