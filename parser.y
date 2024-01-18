/* CMSC 430 Compiler Theory and Design
   Project 2 Skeleton
   UMGC CITE
   Summer 2023 

   Project 2 Parser */

%{

#include <string>

using namespace std;

#include "listing.h"

int yylex();
void yyerror(const char* message);

%}

%define parse.error verbose

%token IDENTIFIER INT_LITERAL CHAR_LITERAL REAL_LITERAL HEX_LITERAL

%token ADDOP MULOP ANDOP RELOP ARROW MODOP EXPOP OROP NOTOP REMOP NEGOP

%token BEGIN_ CASE CHARACTER ELSE END ENDSWITCH FUNCTION INTEGER IS LIST OF OTHERS RETURNS SWITCH WHEN REAL IF THEN ELSIF ENDIF FOLD ENDFOLD LEFT RIGHT

%%

function:	
	function_header optional_variable body ;

function_header:	
	FUNCTION IDENTIFIER optional_parameters RETURNS type ';'  ;

parameters:
    parameter more_parameters ;

more_parameters:
    ',' parameter more_parameters | %empty ;

parameter:
    IDENTIFIER ':' type ;

optional_parameters:
    parameters | %empty ;

type:
	INTEGER |
	REAL |
	CHARACTER ; 

optional_variable :
	variable |
	%empty ;
    
variable:	
	IDENTIFIER ':' type IS statement ';' |
	IDENTIFIER ':' LIST OF type IS list ';' ;

list:
	'(' expressions ')' ;

expressions:
	expressions ',' expression| 
	expression ;

body:
	BEGIN_ statement_ END ';' ;

statement_:
	statement ';' |
	error ';' ;
    
statement:
	expression |
	WHEN condition ',' expression ':' expression |
	SWITCH expression IS cases OTHERS ARROW statement ';' ENDSWITCH | if_statement ;

if_statement:
    IF condition THEN statement_ elsif_clauses ENDIF |
    IF condition THEN statement_ elsif_clauses ELSE statement_ ENDIF;

elsif_clauses:
    %empty |  
    ELSIF condition THEN statement_ elsif_clauses ;

cases:
	cases case |
	%empty ;
	
case:
	CASE INT_LITERAL ARROW statement ';' ; 

condition:
	condition ANDOP relation |
	relation ;

relation:
	'(' condition ')' |
	expression RELOP expression ;

expression:
	expression ADDOP term |
	term ;
      
term:
	term MULOP primary |
	primary ;

primary:
	'(' expression ')' |
	INT_LITERAL |
	CHAR_LITERAL |
	REAL_LITERAL | 
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
