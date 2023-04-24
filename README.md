# ANAScript

## Operators

| Precedence | Symbol   | Associativity | 
| ---------- | -------  | ------------- |
| 1          | `-`, `+` | Right-to-left |

## Grammar

```
expression = unary-expression
unary-expression = ( "-" | "+" ) unary-expression | primary-expression
primary-expression = LIT-FLOAT | LIT-INT | "(" expression ")"
```