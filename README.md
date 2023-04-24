# ANAScript

## Types

| Type    | Byte(s) |
| ------- | ------- |
| `bool`  | 1       |
| `char`  | 1       | <!-- Support unicode later -->
| `float` | 8       |
| `int`   | [8, ∞)  |
| `word`  | 8       |
| `byte`  | 1       |

<!-- List types, sum types, product types, function types, union types, reference types, object types -->

## Operators

### Precedence Table

| Precedence | Arity | Symbol              | Names                                         | Associativity | 
| ---------- | ----- | ------------------- | --------------------------------------------- | ------------- |
| 1          | 1     | `+`, `-`            | Unary minus, plus                             | Right-to-left |
| 1          | 1     | `!`                 | Logical NOT                                   | Right-to-left |
| 2          | 2     | `**`                | Exponentiation                                | Right-to-left |
| 3          | 2     | `*`, `/`, `//`, `%` | Multiplication, division, quotient, remainder | Left-to-right |
| 4          | 2     | `+`, `-`            | Addition, subtraction                         | Left-to-right |
| 5          | 2     | `<`, `<=`           | Less than, less than or equal to              | Left-to-right |
| 5          | 2     | `>`, `>=`           | Greater than, greater than or equal to        | Left-to-right |
| 6          | 2     | `==`, `!=`          | Equals to, not equals, to                     | Left-to-right |
| 7          | 2     | `&&`                | Logical AND                                   | Left-to-right |
| 8          | 2     | `\|\|`              | Logical OR                                    | Left-to-right |
| 9          | 2     | `=>`, `<=`, `<=>`   | Logical IMP, logical IF, logical IFF          | Right-to-left |
| 10         | 3     | `? :`               | If-then-else                                  | Right-to-left |

### Descriptions

<!-- - `-`, `+`: Operate on numerical types, return numerical types
- `**`: Operates on numerical types, returns numerical type
- `*`, `/`, `//`, `%`: Operate on numerical types
- `+`, `-`: Operate on numerical types
 -->

## Grammar

<!-- Should I express type constraints as syntactical ones? -->

```
expression = implication-expression
implication-expression = unary-expression "=>" implication-expression


unary-numerical-expression = ( "+" | "-" | "!" ) unary-numerical-expression | primary-numerical-expression
primary-numerical-expression = LIT-FLOAT | LIT-INT | "(" numerical-expression ")"

boolean-expression = logical-imp-expression
logical-imp-expression = logical-or-expression "=>" logical-imp-expression | logical-or-expression
logical-or-expression = logical-and-expression { "||" logical-and-expression }*
logical-and-expression = primary-boolean-expression { "&&" primary-boolean-expression }*
logical-not-expression = "!" logical-not-expression | primary-boolean-expression <!-- This is incorrect! -->
primary-boolean-expression = LIT-BOOL | "(" boolean-expression ")" | inequality-expression | equality-expression
```
