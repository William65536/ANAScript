#ifndef TOKEN_H
#define TOKEN_H

#include <stddef.h>
#include <stdint.h>

typedef struct Position {
    size_t ln, col;
} Position;

typedef struct Token {
    enum Type {
        TYPE_LIT_INT,
        TYPE_LIT_FLOAT,

        TYPE_OP_PLUS,
        TYPE_OP_MINUS,
        TYPE_OP_TIMES,
        TYPE_OP_DIV,

        TYPE_LPAREN,
        TYPE_RPAREN,

        TYPE_EOF
    } type;
    union {
        int64_t lit_int;
        double lit_float;
    };
    Position pos;
} Token;

#endif
