#include "parser.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void trim_whitespace(char *text) {
    char *start = text;
    char *end;

    while (*start != '\0' && isspace((unsigned char)*start)) {
        ++start;
    }

    if (start != text) {
        memmove(text, start, strlen(start) + 1);
    }

    end = text + strlen(text);
    while (end > text && isspace((unsigned char)end[-1])) {
        --end;
    }
    *end = '\0';
}

static int is_ident_char(int c) {
    return isalnum(c) || c == '_';
}

static int copy_token(char *dst, size_t dst_size, const char *src, size_t len) {
    if (len == 0 || len >= dst_size) {
        return -1;
    }
    memcpy(dst, src, len);
    dst[len] = '\0';
    return 0;
}

int parse_line(const char *line, ParsedLine *parsed) {
    char buffer[256];
    char *cursor;
    char *colon;

    if (line == NULL || parsed == NULL) {
        return -1;
    }

    memset(parsed, 0, sizeof(*parsed));

    if (strlen(line) >= sizeof(buffer)) {
        return -1;
    }

    strcpy(buffer, line);
    cursor = strchr(buffer, '#');
    if (cursor != NULL) {
        *cursor = '\0';
    }
    trim_whitespace(buffer);
    if (buffer[0] == '\0') {
        return 0;
    }

    colon = strchr(buffer, ':');
    if (colon != NULL) {
        size_t label_len = (size_t)(colon - buffer);
        for (size_t i = 0; i < label_len; ++i) {
            if (!is_ident_char((unsigned char)buffer[i])) {
                return -1;
            }
        }
        if (copy_token(parsed->label, sizeof(parsed->label), buffer, label_len) != 0) {
            return -1;
        }
        parsed->has_label = 1;
        cursor = colon + 1;
        trim_whitespace(cursor);
    } else {
        cursor = buffer;
    }

    if (*cursor == '\0') {
        return 0;
    }

    {
        char *mnemonic_end = cursor;
        while (*mnemonic_end != '\0' && !isspace((unsigned char)*mnemonic_end) && *mnemonic_end != ',') {
            ++mnemonic_end;
        }
        if (copy_token(parsed->mnemonic, sizeof(parsed->mnemonic), cursor,
                       (size_t)(mnemonic_end - cursor)) != 0) {
            return -1;
        }
        parsed->has_instruction = 1;
        cursor = mnemonic_end;
    }

    while (*cursor != '\0') {
        char token[MAX_OPERAND_LEN + 1];
        size_t length = 0;

        while (*cursor != '\0' && (isspace((unsigned char)*cursor) || *cursor == ',')) {
            ++cursor;
        }
        if (*cursor == '\0') {
            break;
        }
        if (parsed->operand_count >= MAX_OPERANDS) {
            return -1;
        }

        while (*cursor != '\0' && !isspace((unsigned char)*cursor) &&
               *cursor != ',' && *cursor != '(' && *cursor != ')') {
            if (length >= MAX_OPERAND_LEN) {
                return -1;
            }
            token[length++] = *cursor++;
        }
        token[length] = '\0';
        if (length == 0) {
            if (*cursor == '(' || *cursor == ')') {
                ++cursor;
            }
            continue;
        }

        strcpy(parsed->operands[parsed->operand_count], token);
        ++parsed->operand_count;
    }

    return 0;
}
