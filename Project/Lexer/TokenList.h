#ifndef TOKEN_LIST_H
#define TOKEN_LIST_H

#include <stddef.h>
#include <stdbool.h>
#include "Token.h"

typedef struct TokenList TokenList;

TokenList *TokenList_new(size_t initcap);

void TokenList_delete(TokenList **self);

size_t TokenList_size(const TokenList *self);

bool TokenList_push(TokenList **self, Token token);

void Token_print(Token self);

void TokenList_println(const TokenList *self);

#endif
