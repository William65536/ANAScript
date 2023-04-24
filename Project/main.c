#include <stdio.h>

#include "Lexer\TokenList.h"
#include "Lexer\Scanner.h"

int main(void)
{
    const char *input = "(1 + 1)";

    Scanner *scanner = Scanner_new(input);

    Scanner_lex(scanner);

    TokenList_println(Scanner_tokens(scanner));

    Scanner_delete(&scanner);

    return 0;
}
