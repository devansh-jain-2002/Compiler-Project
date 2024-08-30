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
    FLOAT = 259,                   /* FLOAT  */
    STRING = 260,                  /* STRING  */
    SHORT_STRING = 261,            /* SHORT_STRING  */
    LONG_STRING = 262,             /* LONG_STRING  */
    PLUS = 263,                    /* PLUS  */
    MINUS = 264,                   /* MINUS  */
    MULTIPLY = 265,                /* MULTIPLY  */
    EXP = 266,                     /* EXP  */
    SLASH = 267,                   /* SLASH  */
    DOUBLESLASH = 268,             /* DOUBLESLASH  */
    DIVIDE = 269,                  /* DIVIDE  */
    DIVIDEDIVIDE = 270,            /* DIVIDEDIVIDE  */
    MOD = 271,                     /* MOD  */
    AT = 272,                      /* AT  */
    RIGHTSHIFT = 273,              /* RIGHTSHIFT  */
    LEFTSHIFT = 274,               /* LEFTSHIFT  */
    AMPERSAND = 275,               /* AMPERSAND  */
    EQUAL = 276,                   /* EQUAL  */
    NOTEQUAL = 277,                /* NOTEQUAL  */
    GREATER = 278,                 /* GREATER  */
    LESS = 279,                    /* LESS  */
    GREATEREQ = 280,               /* GREATEREQ  */
    LESSEQ = 281,                  /* LESSEQ  */
    BITOR = 282,                   /* BITOR  */
    BITXOR = 283,                  /* BITXOR  */
    BITNOT = 284,                  /* BITNOT  */
    ASSIGN = 285,                  /* ASSIGN  */
    PLUSEQUAL = 286,               /* PLUSEQUAL  */
    MINUSEQUAL = 287,              /* MINUSEQUAL  */
    MULTIPLYEQUAL = 288,           /* MULTIPLYEQUAL  */
    DIVIDEEQUAL = 289,             /* DIVIDEEQUAL  */
    MODEQUAL = 290,                /* MODEQUAL  */
    EXPONENTEQUAL = 291,           /* EXPONENTEQUAL  */
    ANDEQUAL = 292,                /* ANDEQUAL  */
    OREQUAL = 293,                 /* OREQUAL  */
    XOREQUAL = 294,                /* XOREQUAL  */
    LEFTSHIFTEQUAL = 295,          /* LEFTSHIFTEQUAL  */
    RIGHTSHIFTEQUAL = 296,         /* RIGHTSHIFTEQUAL  */
    COLONEQUAL = 297,              /* COLONEQUAL  */
    LEFTBRACKET = 298,             /* LEFTBRACKET  */
    RIGHTBRACKET = 299,            /* RIGHTBRACKET  */
    LEFTSQUAREBRACKET = 300,       /* LEFTSQUAREBRACKET  */
    RIGHTSQUAREBRACKET = 301,      /* RIGHTSQUAREBRACKET  */
    LEFTCURLYBRACKET = 302,        /* LEFTCURLYBRACKET  */
    RIGHTCURLYBRACKET = 303,       /* RIGHTCURLYBRACKET  */
    COMMA = 304,                   /* COMMA  */
    COLON = 305,                   /* COLON  */
    SEMICOLON = 306,               /* SEMICOLON  */
    DOT = 307,                     /* DOT  */
    ARROW = 308,                   /* ARROW  */
    DIVIDEDIVIDEEQUAL = 309,       /* DIVIDEDIVIDEEQUAL  */
    ATEQUAL = 310,                 /* ATEQUAL  */
    NAME_DUNDER = 311,             /* NAME_DUNDER  */
    MAIN_DUNDER = 312,             /* MAIN_DUNDER  */
    INIT_DUNDER = 313,             /* INIT_DUNDER  */
    SPECIAL_CHAR = 314,            /* SPECIAL_CHAR  */
    UNDERSCORE = 315,              /* UNDERSCORE  */
    DOUBLE_QUOTE = 316,            /* DOUBLE_QUOTE  */
    SINGLE_QUOTE = 317,            /* SINGLE_QUOTE  */
    BACKSLASH = 318,               /* BACKSLASH  */
    SPACE = 319,                   /* SPACE  */
    FALSE = 320,                   /* FALSE  */
    AWAIT = 321,                   /* AWAIT  */
    ELSE = 322,                    /* ELSE  */
    IMPORT = 323,                  /* IMPORT  */
    PASS = 324,                    /* PASS  */
    NONE = 325,                    /* NONE  */
    BREAK = 326,                   /* BREAK  */
    EXCEPT = 327,                  /* EXCEPT  */
    IN = 328,                      /* IN  */
    RAISE = 329,                   /* RAISE  */
    TRUE = 330,                    /* TRUE  */
    CLASS = 331,                   /* CLASS  */
    FINALLY = 332,                 /* FINALLY  */
    RANGE = 333,                   /* RANGE  */
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
    ELLIPSIS = 361,                /* ELLIPSIS  */
    PRINT = 362                    /* PRINT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef  struct semantic_value_type  YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
