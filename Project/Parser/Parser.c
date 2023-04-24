
#include "..\Lexer\Token.h"

typedef struct Expression Expression;


typedef struct PimaryExpression {
    Token token;
} PimaryExpression;

typedef struct UnaryExpression {
    enum Type type;
    
} UnaryExpression;


// typedef struct Parser {

// } Parser;