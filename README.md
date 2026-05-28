# Parser

A compiler parser and lexer implementation using YACC/Bison and Lex/Flex.

## Overview

This project implements a custom programming language parser with support for:

- Function definitions with typed parameters
- Variable declarations with type inference
- Expression parsing (arithmetic, logical, relational)
- Control flow statements (IF/ELSE, SWITCH/CASE, FOLD)
- List operations and manipulations

## Language Features

### Types
- `INTEGER` - Integer numbers
- `REAL` - Floating-point numbers
- `CHARACTER` - Single characters
- `LIST OF <type>` - Typed lists

### Control Structures

**IF Statement:**
```
IF condition THEN
    statements
ELSIF condition THEN
    statements
ELSE
    statements
ENDIF;
```

**SWITCH Statement:**
```
SWITCH expression IS
    CASE 0 => statement;
    CASE 1 => statement;
OTHERS => statement;
ENDSWITCH;
```

**FOLD Operation:**
```
FOLD LEFT ADDOP (1, 2, 3, 4);
FOLD RIGHT MULOP (1, 2, 3, 4);
```

### Function Definition
```
FUNCTION name(param1: INTEGER, param2: REAL) RETURNS INTEGER;
```

## Tech Stack

- **Parser Generator**: YACC/Bison
- **Lexer Generator**: Lex/Flex
- **Language**: C

## Building

### Prerequisites

- Bison (YACC)
- Flex (Lex)
- GCC

### Compilation

```bash
# Generate parser
bison -d parser.y

# Generate lexer
flex scanner.l

# Compile
gcc -o parser parser.tab.c lex.yy.c -lfl
```

Or simply:
```bash
make
```

## Files

- `parser.y` - YACC grammar file
- `scanner.l` - Lex lexer file
- `listing.h` - Header for output generation
- `listing.cc` - Output generation implementation
- `makefile` - Build configuration

## Usage

```bash
./parser < input.file
```

## Example Input

```
FUNCTION factorial(n: INTEGER) RETURNS INTEGER;
BEGIN
    IF n <= 1 THEN
        RETURN 1;
    ELSE
        RETURN n * factorial(n - 1);
    ENDIF;
END;
```

## License

MIT
