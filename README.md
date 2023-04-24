# ANAScript

## Types

| Type    | Byte(s) |
| ------- | ------- |
| `bool`  | 1       |
| `float` | 8       |
| `int`   | 8       |

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
| 8          | 2     | `||`                | Logical OR                                    | Left-to-right |
| 9          | 2     | `=>`                | Logical IMP                                   | Right-to-left |

### Descriptions

<!-- - `-`, `+`: Operate on numerical types, return numerical types
- `**`: Operates on numerical types, returns numerical type
- `*`, `/`, `//`, `%`: Operate on numerical types
- `+`, `-`: Operate on numerical types
 -->

## Grammar

```
expression = unary-expression
unary-expression = ( "+" | "-" ) unary-expression | primary-expression
primary-expression = LIT-FLOAT | LIT-INT | "(" expression ")"
```
