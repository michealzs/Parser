%{
#include <string>
using namespace std;

#include "listing.h"

int yylex();
void yyerror(const char* message);

%}

%token IDENTIFIER INT_LITERAL REAL_LITERAL CHAR_LITERAL
%token ADDOP MULOP MODOP EXPOP ANDOP OROP NOTOP
%token BEGIN_ END FUNCTION RETURNS INTEGER REAL CHARACTER LIST OF WHEN CASE ELSE SWITCH ENDSWITCH IF THEN ELSIF ENDIF FOLD ENDFOLD LEFT RIGHT

%%

/* Main Grammar Rules */

function: 
    function_header optional_variables body ;

function_header: 
    FUNCTION IDENTIFIER optional_parameters RETURNS type ';' ;

optional_parameters:
    parameters | %empty ;

parameters:
    parameter more_parameters ;

more_parameters:
    ',' parameter more_parameters | %empty ;

parameter:
    IDENTIFIER ':' type ;

type:
    INTEGER | REAL | CHARACTER ;

optional_variables:
    variables | %empty ;

variables:
    variable more_variables ;

more_variables:
    variable more_variables | %empty ;

variable:
    IDENTIFIER ':' type IS statement ';' | 
    IDENTIFIER ':' LIST OF type IS list ';' ;

list:
    '(' expressions ')' ;

expressions:
    expression more_expressions ;

more_expressions:
    ',' expression more_expressions | %empty ;

body:
    BEGIN_ statements END ';' | BEGIN_ error ';' ;

statements:
    statement statements | statement ;

statement:
    expression ';' |
    WHEN condition ',' expression ':' expression ';' |
    SWITCH expression IS cases OTHERS ARROW statement ';' ENDSWITCH ';' |
    IF condition THEN statements optional_else ENDIF ';' |
    FOLD direction operator list_choice ENDFOLD ';' |
    error ';' ;

optional_else:
    ELSE statements | %empty ;

cases:
    case cases | case ;

case:
    CASE INT_LITERAL ARROW statement ';' ;

direction:
    LEFT | RIGHT ;

operator:
    ADDOP | MULOP ;

list_choice:
    list | IDENTIFIER ;

condition:
    logical_expr ;

logical_expr:
    logical_term logical_or ;

logical_or:
    '|' logical_term logical_or | %empty ;

logical_term:
    logical_factor logical_and ;

logical_and:
    '&' logical_factor logical_and | %empty ;

logical_factor:
    '!' logical_factor | relational_expr ;

relational_expr:
    expression RELOP expression | expression ;

expression:
    term addop_terms ;

addop_terms:
    ADDOP term addop_terms | %empty ;

term:
    factor mulop_factors ;

mulop_factors:
    MULOP factor mulop_factors | %empty ;

factor:
    '~' factor | primary ;

primary:
    '(' expression ')' |
    INT_LITERAL | REAL_LITERAL | CHAR_LITERAL |
    IDENTIFIER '(' expression ')' |
    IDENTIFIER ;

%%

void yyerror(const char* message) {
    appendError(SYNTAX, message);
}

int main(int argc, char *argv[]) {
    firstLine();
    yyparse();
    lastLine();
    return 0;
}

