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

<!-- List types, sum types, product types, function types, union types, reference types, object types, rational types, data type types, quotations, symbols -->

<!-- How should memory management work? -->

<!-- Lazy evaluation - add a strict evaluation operator -->

<!-- Should combinators be separate from functions? -->

<!-- Should procedures be separate from pure functions? -->

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
| 9          | 2     | `=>`, `=<`, `<=>`   | Logical IMP, logical IF, logical IFF          | Right-to-left |
| 10         | 3     | `? :`               | If-then-else                                  | Right-to-left | <!-- Maybe introduce an alternative to this -->

### Descriptions

<!-- - `-`, `+`: Operate on numerical types, return numerical types
- `**`: Operates on numerical types, returns numerical type
- `*`, `/`, `//`, `%`: Operate on numerical types
- `+`, `-`: Operate on numerical types
 -->
 
| Type A  | Type B  | Type Out   |
| ------- | ------- | ---------- |
| `float` | `float` | `float`    |
| `float` | `int`   | `float`    |
| `int`   | `float` | `float`    |
| `int`   | `int`   | `rational` |
 

## Grammar

<!-- Should I express type constraints as syntactical ones? -->

```


expression = ternary-expression
if-then-else-expression =
logical-imp-expression =
logical-or-expression =
logical-and-expression =
equality-expression =
inequality-expression =
addition-expression =
multiplication-expression =
exponentiation-expression =
unary-expression =
primary-expression = LIT-BOOL | LIT-INT | LIT-FLOAT | "(" expression ")"
```
