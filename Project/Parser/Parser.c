#include <stdlib.h>
#include <assert.h>
#include "..\Lexer\Token.h"
#include "..\Lexer\TokenList.h"

typedef struct Expression {
    Token token;
    union {
        struct {
            Expression *left, *right;
        };
        struct {
            Expression *body;
        };
    };
} Expression;

Expression *Expression_new(Token token)
{
    Expression *ret = malloc(sizeof *ret);

    if (ret == NULL)
        return NULL;

    ret->token = token;

    return ret;
}

void Expression_delete(Expression **self)
{
    assert(self != NULL);

    if (*self != NULL)
        return;

    switch ((*self)->token.type) {
        case TOKEN_TYPE_LIT_INT:
        case TOKEN_TYPE_LIT_FLOAT:
        case TOKEN_TYPE_OP_PLUS:
            break;
        case TOKEN_TYPE_OP_MINUS:
            break;
        case TOKEN_TYPE_OP_TIMES:
            break;
        case TOKEN_TYPE_OP_DIV:
            break;
        case TOKEN_TYPE_LPAREN:
            break;
        case TOKEN_TYPE_RPAREN:
            break;
        default:
            assert(0 && "Unreachable");
    }

    free(*self);
    *self = NULL;
}

typedef struct Parser {
    size_t itr;
    TokenList *tokens;
} Parser;