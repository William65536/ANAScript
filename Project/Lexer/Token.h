#ifndef TOKEN_H
#define TOKEN_H

#include <stddef.h>
#include <stdint.h>

typedef struct Position {
    size_t ln, col;
} Position;

typedef struct Token {
    enum Type {
        TOKEN_TYPE_LIT_INT,
        TOKEN_TYPE_LIT_FLOAT,

        TOKEN_TYPE_OP_PLUS,
        TOKEN_TYPE_OP_MINUS,
        TOKEN_TYPE_OP_TIMES,
        TOKEN_TYPE_OP_DIV,

        TOKEN_TYPE_LPAREN,
        TOKEN_TYPE_RPAREN,

        TOKEN_TYPE_EOF
    } type;
    union {
        int64_t lit_int;
        double lit_float;
    };
    Position pos;
} Token;

#endif
