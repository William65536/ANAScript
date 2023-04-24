#ifndef SCANNER_H
#define SCANNER_H

#include "TokenList.h"

typedef enum ScannerException {
    SCANNER_EXCEPT_NONE,
    SCANNER_EXCEPT_FAILED_ALLOCATION,
    SCANNER_EXCEPT_FAILED_SCAN
} ScannerException;

typedef struct Scanner Scanner;

Scanner *Scanner_new(const char *input);

void Scanner_delete(Scanner **self);

TokenList *Scanner_tokens(const Scanner *self);

ScannerException Scanner_lex(Scanner *self);

#endif
