/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INT_LITERAL = 259,             /* INT_LITERAL  */
    CHAR_LITERAL = 260,            /* CHAR_LITERAL  */
    REAL_LITERAL = 261,            /* REAL_LITERAL  */
    HEX_LITERAL = 262,             /* HEX_LITERAL  */
    ADDOP = 263,                   /* ADDOP  */
    MULOP = 264,                   /* MULOP  */
    ANDOP = 265,                   /* ANDOP  */
    RELOP = 266,                   /* RELOP  */
    ARROW = 267,                   /* ARROW  */
    MODOP = 268,                   /* MODOP  */
    EXPOP = 269,                   /* EXPOP  */
    OROP = 270,                    /* OROP  */
    NOTOP = 271,                   /* NOTOP  */
    REMOP = 272,                   /* REMOP  */
    NEGOP = 273,                   /* NEGOP  */
    BEGIN_ = 274,                  /* BEGIN_  */
    CASE = 275,                    /* CASE  */
    CHARACTER = 276,               /* CHARACTER  */
    ELSE = 277,                    /* ELSE  */
    END = 278,                     /* END  */
    ENDSWITCH = 279,               /* ENDSWITCH  */
    FUNCTION = 280,                /* FUNCTION  */
    INTEGER = 281,                 /* INTEGER  */
    IS = 282,                      /* IS  */
    LIST = 283,                    /* LIST  */
    OF = 284,                      /* OF  */
    OTHERS = 285,                  /* OTHERS  */
    RETURNS = 286,                 /* RETURNS  */
    SWITCH = 287,                  /* SWITCH  */
    WHEN = 288,                    /* WHEN  */
    REAL = 289,                    /* REAL  */
    IF = 290,                      /* IF  */
    THEN = 291,                    /* THEN  */
    ELSIF = 292,                   /* ELSIF  */
    ENDIF = 293,                   /* ENDIF  */
    FOLD = 294,                    /* FOLD  */
    ENDFOLD = 295,                 /* ENDFOLD  */
    LEFT = 296,                    /* LEFT  */
    RIGHT = 297                    /* RIGHT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
