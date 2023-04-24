#include <stdio.h> /* For deubgging purposes */
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "Token.h"

typedef struct TokenList {
    size_t size, cap;
    Token data[];
} TokenList;

TokenList *TokenList_new(size_t initcap)
{
    assert(initcap > 0);

    TokenList *ret = malloc(sizeof *ret + initcap * sizeof *ret->data);

    if (ret == NULL)
        return NULL;

    ret->cap = initcap;
    ret->size = 0;

    return ret;
}

void TokenList_delete(TokenList **self)
{
    assert(self != NULL && *self != NULL);

    free(*self);
    *self = NULL;
}

size_t TokenList_size(const TokenList *self)
{
    assert(self != NULL);

    return self->size;
}

static bool TokenList_resize(TokenList **self)
{
    assert(self != NULL && *self != NULL);
    assert((*self)->cap > 0);

    TokenList *temp = realloc(*self, sizeof **self + (*self)->cap * 2 * sizeof *(*self)->data);

    if (temp == NULL)
        return false;

    *self = temp;
    (*self)->cap *= 2;

    return true;
}

bool TokenList_push(TokenList **self, Token token)
{
    assert(self != NULL && *self != NULL);

    if ((*self)->size + 1 > (*self)->cap)
        if (!TokenList_resize(self))
            return false;

    (*self)->data[(*self)->size] = token;
    (*self)->size++;

    return true;
}

void Token_print(Token self)
{
    switch (self.type) {
        case TOKEN_TYPE_LIT_INT:
            fputs("<LIT_INT ", stdout);
            printf("%lld", self.lit_int);
            putchar('>');
            break;
        case TOKEN_TYPE_LIT_FLOAT:
            fputs("<LIT_FLOAT ", stdout);
            printf("%g", self.lit_float);
            putchar('>');
            break;
        case TOKEN_TYPE_OP_PLUS:
            fputs("<OP_PLUS>", stdout);
            break;
        case TOKEN_TYPE_OP_MINUS:
            fputs("<OP_MINUS>", stdout);
            break;
        case TOKEN_TYPE_OP_TIMES:
            fputs("<OP_TIMES>", stdout);
            break;
        case TOKEN_TYPE_OP_DIV:
            fputs("<OP_DIV>", stdout);
            break;
        case TOKEN_TYPE_LPAREN:
            fputs("<OP_LPAREN>", stdout);
            break;
        case TOKEN_TYPE_RPAREN:
            fputs("<OP_RPAREN>", stdout);
            break;
        case TOKEN_TYPE_EOF:
            fputs("<OP_EOF>", stdout);
            break;
        default:
            assert(0 && "Unreachable");
    }
}

void TokenList_println(const TokenList *self)
{
    assert(self != NULL);

    fputs("[ ", stdout);

    for (size_t i = 0; i < self->size; i++) {
        Token_print(self->data[i]);
        putchar(' ');
    }

    putchar(']');

    puts("");
}
