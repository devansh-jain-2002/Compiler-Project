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
# define YYDEBUG 1
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
    INTEGER = 258,                 /* INTEGER  */
    FLOATNUMBER = 259,             /* FLOATNUMBER  */
    NUMBER = 260,                  /* NUMBER  */
    STRING = 261,                  /* STRING  */
    SHORT_STRING = 262,            /* SHORT_STRING  */
    LONG_STRING = 263,             /* LONG_STRING  */
    PLUS = 264,                    /* PLUS  */
    MINUS = 265,                   /* MINUS  */
    MULTIPLY = 266,                /* MULTIPLY  */
    EXP = 267,                     /* EXP  */
    SLASH = 268,                   /* SLASH  */
    DOUBLESLASH = 269,             /* DOUBLESLASH  */
    DIVIDE = 270,                  /* DIVIDE  */
    DIVIDEDIVIDE = 271,            /* DIVIDEDIVIDE  */
    MOD = 272,                     /* MOD  */
    AT = 273,                      /* AT  */
    RIGHTSHIFT = 274,              /* RIGHTSHIFT  */
    LEFTSHIFT = 275,               /* LEFTSHIFT  */
    AMPERSAND = 276,               /* AMPERSAND  */
    EQUAL = 277,                   /* EQUAL  */
    NOTEQUAL = 278,                /* NOTEQUAL  */
    GREATER = 279,                 /* GREATER  */
    LESS = 280,                    /* LESS  */
    GREATEREQ = 281,               /* GREATEREQ  */
    LESSEQ = 282,                  /* LESSEQ  */
    BITOR = 283,                   /* BITOR  */
    BITXOR = 284,                  /* BITXOR  */
    BITNOT = 285,                  /* BITNOT  */
    ASSIGN = 286,                  /* ASSIGN  */
    PLUSEQUAL = 287,               /* PLUSEQUAL  */
    MINUSEQUAL = 288,              /* MINUSEQUAL  */
    MULTIPLYEQUAL = 289,           /* MULTIPLYEQUAL  */
    DIVIDEEQUAL = 290,             /* DIVIDEEQUAL  */
    PERCENTEQUAL = 291,            /* PERCENTEQUAL  */
    EXPONENTEQUAL = 292,           /* EXPONENTEQUAL  */
    ANDEQUAL = 293,                /* ANDEQUAL  */
    OREQUAL = 294,                 /* OREQUAL  */
    XOREQUAL = 295,                /* XOREQUAL  */
    LEFTSHIFTEQUAL = 296,          /* LEFTSHIFTEQUAL  */
    RIGHTSHIFTEQUAL = 297,         /* RIGHTSHIFTEQUAL  */
    COLONEQUAL = 298,              /* COLONEQUAL  */
    LEFTBRACKET = 299,             /* LEFTBRACKET  */
    RIGHTBRACKET = 300,            /* RIGHTBRACKET  */
    LEFTSQUAREBRACKET = 301,       /* LEFTSQUAREBRACKET  */
    RIGHTSQUAREBRACKET = 302,      /* RIGHTSQUAREBRACKET  */
    LEFTCURLYBRACKET = 303,        /* LEFTCURLYBRACKET  */
    RIGHTCURLYBRACKET = 304,       /* RIGHTCURLYBRACKET  */
    COMMA = 305,                   /* COMMA  */
    COLON = 306,                   /* COLON  */
    SEMICOLON = 307,               /* SEMICOLON  */
    DOT = 308,                     /* DOT  */
    ARROW = 309,                   /* ARROW  */
    DIVIDEDIVIDEEQUAL = 310,       /* DIVIDEDIVIDEEQUAL  */
    ATEQUAL = 311,                 /* ATEQUAL  */
    NAME_DUNDER = 312,             /* NAME_DUNDER  */
    MAIN_DUNDER = 313,             /* MAIN_DUNDER  */
    INIT_DUNDER = 314,             /* INIT_DUNDER  */
    SPECIAL_CHAR = 315,            /* SPECIAL_CHAR  */
    UNDERSCORE = 316,              /* UNDERSCORE  */
    DOUBLE_QUOTE = 317,            /* DOUBLE_QUOTE  */
    SINGLE_QUOTE = 318,            /* SINGLE_QUOTE  */
    BACKSLASH = 319,               /* BACKSLASH  */
    SPACE = 320,                   /* SPACE  */
    FALSE = 321,                   /* FALSE  */
    AWAIT = 322,                   /* AWAIT  */
    ELSE = 323,                    /* ELSE  */
    IMPORT = 324,                  /* IMPORT  */
    PASS = 325,                    /* PASS  */
    NONE = 326,                    /* NONE  */
    BREAK = 327,                   /* BREAK  */
    EXCEPT = 328,                  /* EXCEPT  */
    IN = 329,                      /* IN  */
    RAISE = 330,                   /* RAISE  */
    TRUE = 331,                    /* TRUE  */
    CLASS = 332,                   /* CLASS  */
    FINALLY = 333,                 /* FINALLY  */
    IS = 334,                      /* IS  */
    RETURN = 335,                  /* RETURN  */
    AND = 336,                     /* AND  */
    CONTINUE = 337,                /* CONTINUE  */
    FOR = 338,                     /* FOR  */
    LAMBDA = 339,                  /* LAMBDA  */
    TRY = 340,                     /* TRY  */
    AS = 341,                      /* AS  */
    DEF = 342,                     /* DEF  */
    FROM = 343,                    /* FROM  */
    NONLOCAL = 344,                /* NONLOCAL  */
    WHILE = 345,                   /* WHILE  */
    ASSERT = 346,                  /* ASSERT  */
    DEL = 347,                     /* DEL  */
    GLOBAL = 348,                  /* GLOBAL  */
    NOT = 349,                     /* NOT  */
    WITH = 350,                    /* WITH  */
    ASYNC = 351,                   /* ASYNC  */
    ELIF = 352,                    /* ELIF  */
    IF = 353,                      /* IF  */
    OR = 354,                      /* OR  */
    YIELD = 355,                   /* YIELD  */
    NAME = 356,                    /* NAME  */
    COMMENT = 357,                 /* COMMENT  */
    NEWLINE = 358,                 /* NEWLINE  */
    INDENT = 359,                  /* INDENT  */
    DEDENT = 360,                  /* DEDENT  */
    ELLIPSIS = 361                 /* ELLIPSIS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "parser.y"

    int num;
    char str[1000];
    struct {
        int n;
        char lex[1000];
    } tok;

#line 179 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
