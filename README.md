# ANAScript

## Types

| Type   | Bytes |
| ------ | --- |
| `bool` |

## Operators

| Precedence | Symbol        | Names                 | Associativity | 
| ---------- | ------------- | --------------------- | ------------- |
| 1          | `-`, `+`      | Unary minus, plus     | Right-to-left |
| 2          | `-`, `+`      | Addition, subtraction | Left-to-right |
| 3          | `*`, `/`, `%` | 

## Grammar

```
expression = unary-expression
unary-expression = ( "-" | "+" ) unary-expression | primary-expression
primary-expression = LIT-FLOAT | LIT-INT | "(" expression ")"
```
