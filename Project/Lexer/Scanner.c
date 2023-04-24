#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#include "Scanner.h"
#include "Token.h"
#include "TokenList.h"

struct Scanner {
    const char *input, *itr;
    Position pos;
    TokenList *tokens;
};

Scanner *Scanner_new(const char *input)
{
    assert(input != NULL);

    Scanner *ret = malloc(sizeof *ret);

    if (ret == NULL)
        return NULL;

    ret->input = input;
    ret->itr = ret->input;
    ret->pos = (Position) { .ln = 0, .col = 0 };

    ret->tokens = TokenList_new(10); /* TODO: The argument should be dependent on `input` */

    if (ret->tokens == NULL) {
        free(ret);
        return NULL;
    }

    return ret;
}

void Scanner_delete(Scanner **self)
{
    assert(self != NULL && *self != NULL);

    TokenList_delete(&(*self)->tokens);
    free(*self);
    *self = NULL;
}

TokenList *Scanner_tokens(const Scanner *self)
{
    assert(self != NULL);
    assert(self->tokens != NULL);

    return self->tokens;
}

void Scanner_incr(Scanner *self, char c)
{
    assert(self != NULL);
    
    if (c == '\n') {
        self->pos.col = 0;
        self->pos.ln++;
    } else if (c != '\r' && c != '\0') {
        self->pos.col++;
    }

    if (c != '\0')
        self->itr++;
}

static inline bool iswhite(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void Scanner_skipwhite(Scanner *self)
{
    assert(self != NULL);
    assert(self->itr != NULL);

    for (; iswhite(*self->itr); Scanner_incr(self, *self->itr));
}

static inline bool isdigit(char c)
{
    return '0' <= c && c <= '9';
}

ScannerException Scanner_lex_lit_int(Scanner *self)
{
    assert(self != NULL);
    assert(self->itr != NULL);
    assert(self->tokens != NULL);

    Token token = { .type = TYPE_LIT_INT, .pos = self->pos, .lit_int = 0 };

    if (!isdigit(*self->itr))
        return SCANNER_EXCEPT_FAILED_SCAN;

    token.lit_int = 0;

    for (; isdigit(*self->itr); Scanner_incr(self, *self->itr))
        token.lit_int = token.lit_int * 10 + *self->itr - '0';

    if (!TokenList_push(&self->tokens, token))
        return SCANNER_EXCEPT_FAILED_ALLOCATION;

    return SCANNER_EXCEPT_NONE;
}

ScannerException Scanner_lex_op(Scanner *self)
{
    assert(self != NULL);
    assert(self->itr != NULL);
    assert(self->tokens != NULL);

    Token token = { .pos = self->pos };

    switch (*self->itr) {
        case '+':
            token.type = TYPE_OP_PLUS;
            break;
        case '-':
            token.type = TYPE_OP_MINUS;
            break;
        case '*':
            token.type = TYPE_OP_TIMES;
            break;
        case '/':
            token.type = TYPE_OP_DIV;
            break;
        default:
            return SCANNER_EXCEPT_FAILED_SCAN;
    }

    Scanner_incr(self, *self->itr);

    if (!TokenList_push(&self->tokens, token))
        return SCANNER_EXCEPT_FAILED_ALLOCATION;

    return SCANNER_EXCEPT_NONE;
}

ScannerException Scanner_lex_paren(Scanner *self)
{
    assert(self != NULL);
    assert(self->itr != NULL);
    assert(self->tokens != NULL);

    Token token = { .pos = self->pos };

    switch (*self->itr) {
        case '(':
            token.type = TYPE_LPAREN;
            break;
        case ')':
            token.type = TYPE_RPAREN;
            break;
        default:
            return SCANNER_EXCEPT_FAILED_SCAN;

    }

    Scanner_incr(self, *self->itr);

    if (!TokenList_push(&self->tokens, token))
        return SCANNER_EXCEPT_FAILED_ALLOCATION;

    return SCANNER_EXCEPT_NONE;
}

ScannerException Scanner_lex_eof(Scanner *self)
{
    assert(self != NULL);
    assert(self->itr != NULL);
    assert(self->tokens != NULL);

    if (*self->itr != '\0')
        return SCANNER_EXCEPT_FAILED_SCAN;

    Scanner_incr(self, *self->itr);

    if (!TokenList_push(&self->tokens, (Token) { .type = TYPE_EOF, .pos = self->pos }))
        return SCANNER_EXCEPT_FAILED_ALLOCATION;

    return SCANNER_EXCEPT_NONE;
}

ScannerException Scanner_lex(Scanner *self)
{
    assert(self != NULL);

    while (true) {
        Scanner_skipwhite(self);

        switch (Scanner_lex_lit_int(self)) {
            case SCANNER_EXCEPT_NONE:
                continue;
            case SCANNER_EXCEPT_FAILED_ALLOCATION:
                return SCANNER_EXCEPT_FAILED_ALLOCATION;
            case SCANNER_EXCEPT_FAILED_SCAN:
                break;
        }

        switch (Scanner_lex_op(self)) {
            case SCANNER_EXCEPT_NONE:
                continue;
            case SCANNER_EXCEPT_FAILED_ALLOCATION:
                return SCANNER_EXCEPT_FAILED_ALLOCATION;
            case SCANNER_EXCEPT_FAILED_SCAN:
                break;
        }

        switch (Scanner_lex_paren(self)) {
            case SCANNER_EXCEPT_NONE:
                continue;
            case SCANNER_EXCEPT_FAILED_ALLOCATION:
                return SCANNER_EXCEPT_FAILED_ALLOCATION;
            case SCANNER_EXCEPT_FAILED_SCAN:
                break;
        }

        switch (Scanner_lex_eof(self)) {
            case SCANNER_EXCEPT_NONE:
                goto end;
            case SCANNER_EXCEPT_FAILED_ALLOCATION:
                return SCANNER_EXCEPT_FAILED_ALLOCATION;
            case SCANNER_EXCEPT_FAILED_SCAN:
                break;
        }

        return SCANNER_EXCEPT_FAILED_SCAN; /* TODO: Implemenet an error recovery system s*/
    }

    end:

    return SCANNER_EXCEPT_NONE;
}
