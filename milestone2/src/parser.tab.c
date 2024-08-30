/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include "helper.hpp"
    #include<bits/stdc++.h>
    using namespace std;
    void yyerror(const char * s);
    int yylex();
    extern int yylineno;
    extern FILE* yyin;
    #define YYERROR_VERBOSE 1
    int nodes = 0;
    map<int, string> node_map;
    map<int, string> node_shape;
    map<string, ST*> cls_ST;
    vector<pair<int,string> > baap, betaa;
    extern stack<int> indent_cnt;    
    string s;
    extern char* yytext;
    Type None_type = {"None",0};
    Type Int_type = {"int",0};
    Type Bool_type = {"bool",0};
    Type Float_type = {"float",0};
    Type Str_type = {"str",0};
    stack <string> s_label;
    stack <string> e_label;
    ST* CurrST;
    int offset = 0;
    string res;

#line 100 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_SHORT_STRING = 6,               /* SHORT_STRING  */
  YYSYMBOL_LONG_STRING = 7,                /* LONG_STRING  */
  YYSYMBOL_PLUS = 8,                       /* PLUS  */
  YYSYMBOL_MINUS = 9,                      /* MINUS  */
  YYSYMBOL_MULTIPLY = 10,                  /* MULTIPLY  */
  YYSYMBOL_EXP = 11,                       /* EXP  */
  YYSYMBOL_SLASH = 12,                     /* SLASH  */
  YYSYMBOL_DOUBLESLASH = 13,               /* DOUBLESLASH  */
  YYSYMBOL_DIVIDE = 14,                    /* DIVIDE  */
  YYSYMBOL_DIVIDEDIVIDE = 15,              /* DIVIDEDIVIDE  */
  YYSYMBOL_MOD = 16,                       /* MOD  */
  YYSYMBOL_AT = 17,                        /* AT  */
  YYSYMBOL_RIGHTSHIFT = 18,                /* RIGHTSHIFT  */
  YYSYMBOL_LEFTSHIFT = 19,                 /* LEFTSHIFT  */
  YYSYMBOL_AMPERSAND = 20,                 /* AMPERSAND  */
  YYSYMBOL_EQUAL = 21,                     /* EQUAL  */
  YYSYMBOL_NOTEQUAL = 22,                  /* NOTEQUAL  */
  YYSYMBOL_GREATER = 23,                   /* GREATER  */
  YYSYMBOL_LESS = 24,                      /* LESS  */
  YYSYMBOL_GREATEREQ = 25,                 /* GREATEREQ  */
  YYSYMBOL_LESSEQ = 26,                    /* LESSEQ  */
  YYSYMBOL_BITOR = 27,                     /* BITOR  */
  YYSYMBOL_BITXOR = 28,                    /* BITXOR  */
  YYSYMBOL_BITNOT = 29,                    /* BITNOT  */
  YYSYMBOL_ASSIGN = 30,                    /* ASSIGN  */
  YYSYMBOL_PLUSEQUAL = 31,                 /* PLUSEQUAL  */
  YYSYMBOL_MINUSEQUAL = 32,                /* MINUSEQUAL  */
  YYSYMBOL_MULTIPLYEQUAL = 33,             /* MULTIPLYEQUAL  */
  YYSYMBOL_DIVIDEEQUAL = 34,               /* DIVIDEEQUAL  */
  YYSYMBOL_MODEQUAL = 35,                  /* MODEQUAL  */
  YYSYMBOL_EXPONENTEQUAL = 36,             /* EXPONENTEQUAL  */
  YYSYMBOL_ANDEQUAL = 37,                  /* ANDEQUAL  */
  YYSYMBOL_OREQUAL = 38,                   /* OREQUAL  */
  YYSYMBOL_XOREQUAL = 39,                  /* XOREQUAL  */
  YYSYMBOL_LEFTSHIFTEQUAL = 40,            /* LEFTSHIFTEQUAL  */
  YYSYMBOL_RIGHTSHIFTEQUAL = 41,           /* RIGHTSHIFTEQUAL  */
  YYSYMBOL_COLONEQUAL = 42,                /* COLONEQUAL  */
  YYSYMBOL_LEFTBRACKET = 43,               /* LEFTBRACKET  */
  YYSYMBOL_RIGHTBRACKET = 44,              /* RIGHTBRACKET  */
  YYSYMBOL_LEFTSQUAREBRACKET = 45,         /* LEFTSQUAREBRACKET  */
  YYSYMBOL_RIGHTSQUAREBRACKET = 46,        /* RIGHTSQUAREBRACKET  */
  YYSYMBOL_LEFTCURLYBRACKET = 47,          /* LEFTCURLYBRACKET  */
  YYSYMBOL_RIGHTCURLYBRACKET = 48,         /* RIGHTCURLYBRACKET  */
  YYSYMBOL_COMMA = 49,                     /* COMMA  */
  YYSYMBOL_COLON = 50,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 51,                 /* SEMICOLON  */
  YYSYMBOL_DOT = 52,                       /* DOT  */
  YYSYMBOL_ARROW = 53,                     /* ARROW  */
  YYSYMBOL_DIVIDEDIVIDEEQUAL = 54,         /* DIVIDEDIVIDEEQUAL  */
  YYSYMBOL_ATEQUAL = 55,                   /* ATEQUAL  */
  YYSYMBOL_NAME_DUNDER = 56,               /* NAME_DUNDER  */
  YYSYMBOL_MAIN_DUNDER = 57,               /* MAIN_DUNDER  */
  YYSYMBOL_INIT_DUNDER = 58,               /* INIT_DUNDER  */
  YYSYMBOL_SPECIAL_CHAR = 59,              /* SPECIAL_CHAR  */
  YYSYMBOL_UNDERSCORE = 60,                /* UNDERSCORE  */
  YYSYMBOL_DOUBLE_QUOTE = 61,              /* DOUBLE_QUOTE  */
  YYSYMBOL_SINGLE_QUOTE = 62,              /* SINGLE_QUOTE  */
  YYSYMBOL_BACKSLASH = 63,                 /* BACKSLASH  */
  YYSYMBOL_SPACE = 64,                     /* SPACE  */
  YYSYMBOL_FALSE = 65,                     /* FALSE  */
  YYSYMBOL_AWAIT = 66,                     /* AWAIT  */
  YYSYMBOL_ELSE = 67,                      /* ELSE  */
  YYSYMBOL_IMPORT = 68,                    /* IMPORT  */
  YYSYMBOL_PASS = 69,                      /* PASS  */
  YYSYMBOL_NONE = 70,                      /* NONE  */
  YYSYMBOL_BREAK = 71,                     /* BREAK  */
  YYSYMBOL_EXCEPT = 72,                    /* EXCEPT  */
  YYSYMBOL_IN = 73,                        /* IN  */
  YYSYMBOL_RAISE = 74,                     /* RAISE  */
  YYSYMBOL_TRUE = 75,                      /* TRUE  */
  YYSYMBOL_CLASS = 76,                     /* CLASS  */
  YYSYMBOL_FINALLY = 77,                   /* FINALLY  */
  YYSYMBOL_RANGE = 78,                     /* RANGE  */
  YYSYMBOL_IS = 79,                        /* IS  */
  YYSYMBOL_RETURN = 80,                    /* RETURN  */
  YYSYMBOL_AND = 81,                       /* AND  */
  YYSYMBOL_CONTINUE = 82,                  /* CONTINUE  */
  YYSYMBOL_FOR = 83,                       /* FOR  */
  YYSYMBOL_LAMBDA = 84,                    /* LAMBDA  */
  YYSYMBOL_TRY = 85,                       /* TRY  */
  YYSYMBOL_AS = 86,                        /* AS  */
  YYSYMBOL_DEF = 87,                       /* DEF  */
  YYSYMBOL_FROM = 88,                      /* FROM  */
  YYSYMBOL_NONLOCAL = 89,                  /* NONLOCAL  */
  YYSYMBOL_WHILE = 90,                     /* WHILE  */
  YYSYMBOL_ASSERT = 91,                    /* ASSERT  */
  YYSYMBOL_DEL = 92,                       /* DEL  */
  YYSYMBOL_GLOBAL = 93,                    /* GLOBAL  */
  YYSYMBOL_NOT = 94,                       /* NOT  */
  YYSYMBOL_WITH = 95,                      /* WITH  */
  YYSYMBOL_ASYNC = 96,                     /* ASYNC  */
  YYSYMBOL_ELIF = 97,                      /* ELIF  */
  YYSYMBOL_IF = 98,                        /* IF  */
  YYSYMBOL_OR = 99,                        /* OR  */
  YYSYMBOL_YIELD = 100,                    /* YIELD  */
  YYSYMBOL_NAME = 101,                     /* NAME  */
  YYSYMBOL_COMMENT = 102,                  /* COMMENT  */
  YYSYMBOL_NEWLINE = 103,                  /* NEWLINE  */
  YYSYMBOL_INDENT = 104,                   /* INDENT  */
  YYSYMBOL_DEDENT = 105,                   /* DEDENT  */
  YYSYMBOL_ELLIPSIS = 106,                 /* ELLIPSIS  */
  YYSYMBOL_PRINT = 107,                    /* PRINT  */
  YYSYMBOL_YYACCEPT = 108,                 /* $accept  */
  YYSYMBOL_module = 109,                   /* module  */
  YYSYMBOL_file_input = 110,               /* file_input  */
  YYSYMBOL_func_action = 111,              /* func_action  */
  YYSYMBOL_funcdef = 112,                  /* funcdef  */
  YYSYMBOL_113_1 = 113,                    /* $@1  */
  YYSYMBOL_114_2 = 114,                    /* $@2  */
  YYSYMBOL_parameters = 115,               /* parameters  */
  YYSYMBOL_typedargslist = 116,            /* typedargslist  */
  YYSYMBOL_argument1 = 117,                /* argument1  */
  YYSYMBOL_tfpdef = 118,                   /* tfpdef  */
  YYSYMBOL_stmt = 119,                     /* stmt  */
  YYSYMBOL_simple_stmt = 120,              /* simple_stmt  */
  YYSYMBOL_small_stmt_help = 121,          /* small_stmt_help  */
  YYSYMBOL_small_stmt = 122,               /* small_stmt  */
  YYSYMBOL_print_stmt = 123,               /* print_stmt  */
  YYSYMBOL_expr_stmt = 124,                /* expr_stmt  */
  YYSYMBOL_type_name = 125,                /* type_name  */
  YYSYMBOL_augassign = 126,                /* augassign  */
  YYSYMBOL_flow_stmt = 127,                /* flow_stmt  */
  YYSYMBOL_break_stmt = 128,               /* break_stmt  */
  YYSYMBOL_continue_stmt = 129,            /* continue_stmt  */
  YYSYMBOL_return_stmt = 130,              /* return_stmt  */
  YYSYMBOL_global_stmt = 131,              /* global_stmt  */
  YYSYMBOL_assert_stmt = 132,              /* assert_stmt  */
  YYSYMBOL_compound_stmt = 133,            /* compound_stmt  */
  YYSYMBOL_dummy_if = 134,                 /* dummy_if  */
  YYSYMBOL_if_stmt = 135,                  /* if_stmt  */
  YYSYMBOL_dummy_elif = 136,               /* dummy_elif  */
  YYSYMBOL_if_stmt_help = 137,             /* if_stmt_help  */
  YYSYMBOL_if_stmt_help_1 = 138,           /* if_stmt_help_1  */
  YYSYMBOL_loop_action = 139,              /* loop_action  */
  YYSYMBOL_while_stmt = 140,               /* while_stmt  */
  YYSYMBOL_for_stmt = 141,                 /* for_stmt  */
  YYSYMBOL_ranges = 142,                   /* ranges  */
  YYSYMBOL_suite = 143,                    /* suite  */
  YYSYMBOL_stmt_help = 144,                /* stmt_help  */
  YYSYMBOL_test = 145,                     /* test  */
  YYSYMBOL_and_test = 146,                 /* and_test  */
  YYSYMBOL_not_test = 147,                 /* not_test  */
  YYSYMBOL_comparison = 148,               /* comparison  */
  YYSYMBOL_comp_op = 149,                  /* comp_op  */
  YYSYMBOL_expr = 150,                     /* expr  */
  YYSYMBOL_xor_expr = 151,                 /* xor_expr  */
  YYSYMBOL_and_expr = 152,                 /* and_expr  */
  YYSYMBOL_shift_expr = 153,               /* shift_expr  */
  YYSYMBOL_arith_expr = 154,               /* arith_expr  */
  YYSYMBOL_term = 155,                     /* term  */
  YYSYMBOL_factor = 156,                   /* factor  */
  YYSYMBOL_power = 157,                    /* power  */
  YYSYMBOL_atom_expr = 158,                /* atom_expr  */
  YYSYMBOL_lvalue = 159,                   /* lvalue  */
  YYSYMBOL_atom = 160,                     /* atom  */
  YYSYMBOL_call_trailer = 161,             /* call_trailer  */
  YYSYMBOL_index_trailer = 162,            /* index_trailer  */
  YYSYMBOL_dot_trailer = 163,              /* dot_trailer  */
  YYSYMBOL_testlist = 164,                 /* testlist  */
  YYSYMBOL_testlist_list = 165,            /* testlist_list  */
  YYSYMBOL_classdef = 166,                 /* classdef  */
  YYSYMBOL_167_3 = 167,                    /* $@3  */
  YYSYMBOL_168_4 = 168,                    /* $@4  */
  YYSYMBOL_169_5 = 169,                    /* $@5  */
  YYSYMBOL_arglist = 170,                  /* arglist  */
  YYSYMBOL_arglist_help = 171,             /* arglist_help  */
  YYSYMBOL_argument = 172                  /* argument  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  84
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   635

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  164
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  267

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   362


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   212,   212,   216,   219,   222,   225,   230,   239,   239,
     274,   274,   310,   313,   316,   320,   326,   330,   339,   355,
     365,   368,   374,   377,   381,   384,   388,   391,   394,   397,
     400,   404,   416,   433,   468,   482,   550,   555,   564,   577,
     580,   584,   588,   591,   594,   597,   600,   603,   607,   611,
     614,   617,   622,   625,   628,   632,   636,   640,   654,   665,
     668,   673,   676,   679,   682,   685,   688,   693,   697,   702,
     707,   711,   715,   719,   724,   727,   732,   736,   741,   747,
     754,   763,   780,   796,   801,   807,   811,   815,   818,   824,
     827,   842,   846,   862,   872,   876,   880,   896,   899,   902,
     905,   908,   911,   914,   918,   921,   924,   928,   932,   948,
     952,   968,   972,   989,   993,  1008,  1025,  1029,  1048,  1069,
    1073,  1093,  1113,  1132,  1153,  1157,  1167,  1179,  1192,  1196,
    1219,  1222,  1267,  1289,  1429,  1433,  1465,  1468,  1488,  1491,
    1499,  1507,  1516,  1519,  1523,  1529,  1533,  1538,  1548,  1568,
    1571,  1575,  1580,  1590,  1589,  1616,  1615,  1639,  1639,  1668,
    1671,  1675,  1679,  1685,  1695
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "FLOAT",
  "STRING", "SHORT_STRING", "LONG_STRING", "PLUS", "MINUS", "MULTIPLY",
  "EXP", "SLASH", "DOUBLESLASH", "DIVIDE", "DIVIDEDIVIDE", "MOD", "AT",
  "RIGHTSHIFT", "LEFTSHIFT", "AMPERSAND", "EQUAL", "NOTEQUAL", "GREATER",
  "LESS", "GREATEREQ", "LESSEQ", "BITOR", "BITXOR", "BITNOT", "ASSIGN",
  "PLUSEQUAL", "MINUSEQUAL", "MULTIPLYEQUAL", "DIVIDEEQUAL", "MODEQUAL",
  "EXPONENTEQUAL", "ANDEQUAL", "OREQUAL", "XOREQUAL", "LEFTSHIFTEQUAL",
  "RIGHTSHIFTEQUAL", "COLONEQUAL", "LEFTBRACKET", "RIGHTBRACKET",
  "LEFTSQUAREBRACKET", "RIGHTSQUAREBRACKET", "LEFTCURLYBRACKET",
  "RIGHTCURLYBRACKET", "COMMA", "COLON", "SEMICOLON", "DOT", "ARROW",
  "DIVIDEDIVIDEEQUAL", "ATEQUAL", "NAME_DUNDER", "MAIN_DUNDER",
  "INIT_DUNDER", "SPECIAL_CHAR", "UNDERSCORE", "DOUBLE_QUOTE",
  "SINGLE_QUOTE", "BACKSLASH", "SPACE", "FALSE", "AWAIT", "ELSE", "IMPORT",
  "PASS", "NONE", "BREAK", "EXCEPT", "IN", "RAISE", "TRUE", "CLASS",
  "FINALLY", "RANGE", "IS", "RETURN", "AND", "CONTINUE", "FOR", "LAMBDA",
  "TRY", "AS", "DEF", "FROM", "NONLOCAL", "WHILE", "ASSERT", "DEL",
  "GLOBAL", "NOT", "WITH", "ASYNC", "ELIF", "IF", "OR", "YIELD", "NAME",
  "COMMENT", "NEWLINE", "INDENT", "DEDENT", "ELLIPSIS", "PRINT", "$accept",
  "module", "file_input", "func_action", "funcdef", "$@1", "$@2",
  "parameters", "typedargslist", "argument1", "tfpdef", "stmt",
  "simple_stmt", "small_stmt_help", "small_stmt", "print_stmt",
  "expr_stmt", "type_name", "augassign", "flow_stmt", "break_stmt",
  "continue_stmt", "return_stmt", "global_stmt", "assert_stmt",
  "compound_stmt", "dummy_if", "if_stmt", "dummy_elif", "if_stmt_help",
  "if_stmt_help_1", "loop_action", "while_stmt", "for_stmt", "ranges",
  "suite", "stmt_help", "test", "and_test", "not_test", "comparison",
  "comp_op", "expr", "xor_expr", "and_expr", "shift_expr", "arith_expr",
  "term", "factor", "power", "atom_expr", "lvalue", "atom", "call_trailer",
  "index_trailer", "dot_trailer", "testlist", "testlist_list", "classdef",
  "$@3", "$@4", "$@5", "arglist", "arglist_help", "argument", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-182)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     208,  -182,  -182,  -182,    61,    61,    61,   534,   506,  -182,
    -182,  -182,  -182,   -69,   534,  -182,   -60,   -53,   534,   534,
     -50,   534,   534,     6,  -182,    40,    94,   267,  -182,  -182,
    -182,   -43,  -182,  -182,  -182,  -182,  -182,  -182,  -182,    47,
    -182,  -182,   378,  -182,  -182,  -182,    16,    24,  -182,    50,
      92,    97,   102,    90,    93,    83,  -182,  -182,   134,    -6,
    -182,  -182,  -182,   119,    46,  -182,  -182,   -32,  -182,    16,
      86,    88,    -3,    16,    65,  -182,   -17,   -19,  -182,  -182,
     -15,    38,  -182,   534,  -182,  -182,  -182,   425,  -182,    39,
      42,  -182,   -44,   534,   534,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,    48,    70,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,   534,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
     534,   433,   534,   -55,  -182,  -182,  -182,  -182,   534,   -38,
    -182,    71,   105,  -182,   534,  -182,  -182,   -20,  -182,  -182,
    -182,   319,   100,   534,   378,  -182,  -182,    24,  -182,  -182,
    -182,    92,    97,   102,    90,    93,    93,    83,    83,  -182,
    -182,  -182,  -182,  -182,    16,    16,  -182,    49,    16,   113,
     110,  -182,   -37,  -182,   115,   131,    16,   126,  -182,   378,
     120,   127,   -24,   -34,   378,    16,  -182,   319,    73,   378,
     -14,   -36,   319,  -182,   534,  -182,    78,   534,  -182,   136,
    -182,   534,  -182,  -182,   132,     8,  -182,   151,  -182,   -55,
     116,  -182,  -182,  -182,  -182,   135,  -182,  -182,    79,  -182,
     140,    16,   378,   137,   -31,   378,   -55,  -182,    91,   534,
     378,  -182,   141,   378,  -182,  -182,  -182,   378,  -182,   534,
     129,  -182,  -182,    16,  -182,   143,   378,  -182,  -182,   -18,
     155,   378,  -182,  -182,   378,  -182,  -182
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   139,   140,   141,     0,     0,     0,     0,     0,   144,
     142,    55,   143,     0,    58,    56,     0,     0,     0,     0,
       0,     0,     0,   134,     5,     0,     0,     2,    66,     6,
      20,     0,    24,    30,    26,    27,    52,    53,    54,    28,
      29,    21,     0,    63,    64,    65,    36,    89,    91,    94,
      95,   107,   109,   111,   113,   116,   119,   124,   128,   132,
     130,    67,   125,   128,   132,   126,   127,     0,   138,   151,
       0,   150,     0,    57,     0,     7,     0,    62,    59,    93,
       0,     0,   135,     0,     1,     3,     4,     0,    23,     0,
       0,    85,    72,     0,     0,    97,   102,    99,    98,   100,
     101,   105,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    40,    41,
      42,    43,    44,    50,    45,    46,    47,    48,    49,    51,
       0,     0,     0,     0,   133,   131,   136,   137,   149,     0,
     153,     0,     0,    78,     0,    68,   148,     0,    22,    25,
      60,     0,     0,     0,     0,    70,    69,    90,    92,   104,
     106,    96,   108,   110,   112,   115,   114,   117,   118,   120,
     121,   123,   122,   129,    34,    35,   145,     0,   164,     0,
     159,   161,     0,    39,    37,    32,   152,     0,   157,     0,
       0,     0,     0,     0,     0,    61,    31,    87,     0,     0,
       0,    74,     0,   146,   160,   147,     0,     0,   155,     0,
     154,     0,    78,    13,    18,     0,    14,    16,    10,     0,
      79,    88,    86,    71,    73,     0,    75,    77,     0,   162,
       0,    33,     0,     0,     0,     0,     0,    12,     0,     0,
       0,     8,     0,     0,   163,    38,   156,     0,    84,     0,
      82,    19,    15,    17,    11,     0,     0,    76,   158,     0,
       0,     0,    80,    83,     0,     9,    81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,   -30,
    -182,    29,     7,  -182,   114,  -182,  -182,  -181,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,     5,
      14,    10,  -182,  -182,  -182,  -140,  -152,     3,   125,   -16,
    -182,  -182,   117,   118,   121,   112,     9,    17,    -2,  -182,
       0,     1,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    26,    27,   142,    28,   255,   240,   193,   215,   216,
     217,   197,    91,    31,    32,    33,    34,   185,   130,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   154,   155,
     156,   194,    44,    45,   191,    92,   198,    46,    47,    48,
      49,   104,    50,    51,    52,    53,    54,    55,    56,    57,
      63,    64,    60,   134,   135,    82,    70,    71,    61,   189,
     232,   209,   179,   180,   181
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    59,    62,    65,    66,    79,   187,    30,    87,   205,
      67,    69,   136,   248,   201,   183,   218,    73,   249,   219,
     213,    76,    77,   152,   196,    80,   263,    58,    59,    29,
     144,   225,    72,   143,    30,   145,   224,   131,   241,   132,
     139,    74,    58,    59,   133,   221,   184,   140,    75,   210,
     228,    78,   237,   153,   220,   251,    86,   238,    81,   223,
      88,   153,    93,   188,     1,     2,     3,    93,    93,     4,
       5,    95,    96,    97,    98,    99,   100,   214,   158,    93,
      93,    93,    93,    83,    93,    93,   147,    58,    59,   131,
       6,   132,   246,   112,    84,   250,    89,   113,   114,   115,
     254,   110,   111,   257,     7,    94,     8,   258,   108,   109,
     169,   170,   171,   172,   173,    93,   262,   165,   166,   105,
     174,   265,   107,   101,   266,   106,     9,   167,   168,   102,
     116,    10,   137,   175,   178,   182,    12,   138,   141,   146,
     150,   186,   159,   160,   103,   116,   151,   195,   192,   190,
     199,    58,    59,   202,    58,    59,   200,   203,    30,   204,
     206,   207,    23,   211,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   208,   212,   222,   230,
     233,   239,   236,   242,   244,   243,   245,   247,   129,    58,
      59,   256,   214,   261,    58,    59,   260,    58,    59,    58,
      59,   149,    58,    59,    30,   264,   226,   178,   252,    30,
     231,     1,     2,     3,   234,   227,     4,     5,   157,   164,
       0,   161,   235,   162,   229,     0,     0,   163,     0,     0,
       0,     0,    58,    59,     0,    58,    59,     6,     0,     0,
      58,    59,   253,    58,    59,     0,     0,    58,    59,     0,
       0,     7,   259,     8,     0,     0,    58,    59,     0,     0,
       0,    58,    59,     0,    58,    59,     0,     0,     0,     0,
       1,     2,     3,     9,     0,     4,     5,     0,    10,    11,
       0,     0,     0,    12,    13,     0,     0,     0,    14,     0,
      15,    16,     0,     0,     0,    17,     6,     0,    18,    19,
       0,    20,    21,     0,     0,     0,    22,     0,     0,    23,
       7,    24,     8,     0,     0,    25,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     0,     0,     4,     5,     0,
       0,     0,     9,     0,     0,     0,     0,    10,    11,     0,
       0,     0,    12,    13,     0,     0,     0,    14,     6,    15,
      16,     0,     0,     0,    17,     0,     0,    18,    19,     0,
      20,    21,     7,     0,     8,    22,     0,     0,    23,     0,
      85,     0,     0,     0,    25,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     9,     0,     4,     5,     0,    10,
      11,     0,     0,     0,    12,    13,     0,     0,     0,    14,
       0,    15,    16,     0,     0,     0,    17,     6,     0,    18,
      19,     0,    20,    21,     0,     0,     0,    22,     0,     0,
      23,     7,     0,     8,     0,     0,    25,     0,     1,     2,
       3,     0,     0,     4,     5,     0,     1,     2,     3,     0,
       0,     4,     5,     9,     0,     0,     0,     0,    10,    11,
       0,     0,     0,    12,     6,     0,     0,     0,    14,     0,
      15,     0,     6,     0,     0,     0,     0,     0,     7,    19,
       8,    20,    21,     0,     0,     0,     7,   176,     8,    23,
       0,    90,     0,     0,     0,    25,     0,     0,     0,     0,
       9,     0,     0,     0,     0,    10,    11,     0,     9,     0,
      12,     0,     0,    10,     0,    14,     0,    15,    12,     1,
       2,     3,     0,     0,     4,     5,    19,     0,    20,    21,
       0,     0,     0,     0,     0,     0,    23,    21,   148,     0,
       0,     0,    25,     0,    23,     6,   177,     1,     2,     3,
       0,     0,     4,     5,     0,     0,     0,     0,     0,     7,
       0,     8,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     0,     0,     0,     0,     0,     0,
       0,     9,     0,     0,     0,     0,    10,     7,     0,     8,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      21,     0,     0,     0,    10,     0,     0,    23,     0,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,    23
};

static const yytype_int16 yycheck[] =
{
       0,     0,     4,     5,     6,    21,    44,     0,    51,    46,
       7,     8,    44,    44,   154,    70,    50,    14,    49,    53,
      44,    18,    19,    67,    44,    22,    44,    27,    27,     0,
      49,    67,   101,    50,    27,    50,    50,    43,   219,    45,
      43,   101,    42,    42,    50,   197,   101,    50,   101,   189,
     202,   101,    44,    97,   194,   236,    27,    49,    52,   199,
     103,    97,    99,   101,     3,     4,     5,    99,    99,     8,
       9,    21,    22,    23,    24,    25,    26,   101,    94,    99,
      99,    99,    99,    43,    99,    99,    83,    87,    87,    43,
      29,    45,   232,    10,     0,   235,    49,    14,    15,    16,
     240,     8,     9,   243,    43,    81,    45,   247,    18,    19,
     112,   113,   114,   115,   116,    99,   256,   108,   109,    27,
     117,   261,    20,    73,   264,    28,    65,   110,   111,    79,
      11,    70,    46,   130,   131,   132,    75,    49,    73,   101,
     101,   138,    94,    73,    94,    11,   104,   144,    43,    78,
      50,   151,   151,   104,   154,   154,   153,    44,   151,    49,
      45,    30,   101,    43,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    50,    50,   105,   101,
      44,    30,    50,    67,   105,    50,    46,    50,    54,   189,
     189,    50,   101,    50,   194,   194,    67,   197,   197,   199,
     199,    87,   202,   202,   197,    50,   201,   204,   238,   202,
     207,     3,     4,     5,   211,   201,     8,     9,    93,   107,
      -1,   104,   212,   105,   204,    -1,    -1,   106,    -1,    -1,
      -1,    -1,   232,   232,    -1,   235,   235,    29,    -1,    -1,
     240,   240,   239,   243,   243,    -1,    -1,   247,   247,    -1,
      -1,    43,   249,    45,    -1,    -1,   256,   256,    -1,    -1,
      -1,   261,   261,    -1,   264,   264,    -1,    -1,    -1,    -1,
       3,     4,     5,    65,    -1,     8,     9,    -1,    70,    71,
      -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    80,    -1,
      82,    83,    -1,    -1,    -1,    87,    29,    -1,    90,    91,
      -1,    93,    94,    -1,    -1,    -1,    98,    -1,    -1,   101,
      43,   103,    45,    -1,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,     8,     9,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    70,    71,    -1,
      -1,    -1,    75,    76,    -1,    -1,    -1,    80,    29,    82,
      83,    -1,    -1,    -1,    87,    -1,    -1,    90,    91,    -1,
      93,    94,    43,    -1,    45,    98,    -1,    -1,   101,    -1,
     103,    -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    65,    -1,     8,     9,    -1,    70,
      71,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    80,
      -1,    82,    83,    -1,    -1,    -1,    87,    29,    -1,    90,
      91,    -1,    93,    94,    -1,    -1,    -1,    98,    -1,    -1,
     101,    43,    -1,    45,    -1,    -1,   107,    -1,     3,     4,
       5,    -1,    -1,     8,     9,    -1,     3,     4,     5,    -1,
      -1,     8,     9,    65,    -1,    -1,    -1,    -1,    70,    71,
      -1,    -1,    -1,    75,    29,    -1,    -1,    -1,    80,    -1,
      82,    -1,    29,    -1,    -1,    -1,    -1,    -1,    43,    91,
      45,    93,    94,    -1,    -1,    -1,    43,    44,    45,   101,
      -1,   103,    -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    70,    71,    -1,    65,    -1,
      75,    -1,    -1,    70,    -1,    80,    -1,    82,    75,     3,
       4,     5,    -1,    -1,     8,     9,    91,    -1,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    94,   103,    -1,
      -1,    -1,   107,    -1,   101,    29,   103,     3,     4,     5,
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    70,    43,    -1,    45,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      94,    -1,    -1,    -1,    70,    -1,    -1,   101,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    -1,   101
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     8,     9,    29,    43,    45,    65,
      70,    71,    75,    76,    80,    82,    83,    87,    90,    91,
      93,    94,    98,   101,   103,   107,   109,   110,   112,   119,
     120,   121,   122,   123,   124,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   140,   141,   145,   146,   147,   148,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   166,   156,   158,   159,   156,   156,   145,    46,   145,
     164,   165,   101,   145,   101,   101,   145,   145,   101,   147,
     145,    52,   163,    43,     0,   103,   119,    51,   103,    49,
     103,   120,   143,    99,    81,    21,    22,    23,    24,    25,
      26,    73,    79,    94,   149,    27,    28,    20,    18,    19,
       8,     9,    10,    14,    15,    16,    11,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    54,
     126,    43,    45,    50,   161,   162,    44,    46,    49,    43,
      50,    73,   111,    50,    49,    50,   101,   145,   103,   122,
     101,   104,    67,    97,   136,   137,   138,   146,   147,    94,
      73,   150,   151,   152,   153,   154,   154,   155,   155,   156,
     156,   156,   156,   156,   145,   145,    44,   103,   145,   170,
     171,   172,   145,    70,   101,   125,   145,    44,   101,   167,
      78,   142,    43,   115,   139,   145,    44,   119,   144,    50,
     145,   143,   104,    44,    49,    46,    45,    30,    50,   169,
     143,    43,    50,    44,   101,   116,   117,   118,    50,    53,
     143,   144,   105,   143,    50,    67,   137,   138,   144,   172,
     101,   145,   168,    44,   145,   139,    50,    44,    49,    30,
     114,   125,    67,    50,   105,    46,   143,    50,    44,    49,
     143,   125,   117,   145,   143,   113,    50,   143,   143,   145,
      67,    50,   143,    44,    50,   143,   143
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   110,   110,   110,   110,   111,   113,   112,
     114,   112,   115,   115,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   122,
     122,   123,   124,   124,   124,   124,   124,   125,   125,   125,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   127,   127,   127,   128,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   133,   133,   133,   134,   135,
     135,   135,   135,   136,   137,   137,   138,   138,   139,   140,
     140,   141,   141,   142,   142,   143,   143,   144,   144,   145,
     145,   146,   146,   147,   147,   148,   148,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   150,   150,   151,
     151,   152,   152,   153,   153,   153,   154,   154,   154,   155,
     155,   155,   155,   155,   156,   156,   156,   156,   157,   157,
     158,   158,   158,   158,   159,   159,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   161,   161,   162,   163,   164,
     164,   165,   165,   167,   166,   168,   166,   169,   166,   170,
     170,   171,   171,   171,   172
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     0,     0,     9,
       0,     7,     3,     2,     1,     3,     1,     3,     1,     3,
       1,     1,     3,     2,     1,     3,     1,     1,     1,     1,
       1,     4,     3,     5,     3,     3,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       3,     4,     2,     1,     1,     1,     1,     1,     3,     3,
       3,     5,     2,     3,     2,     3,     5,     3,     0,     5,
       8,    10,     7,     6,     4,     1,     4,     1,     2,     1,
       3,     1,     3,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     2,     2,     2,     1,     3,
       1,     2,     1,     2,     1,     2,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     2,     2,
       1,     1,     3,     0,     5,     0,     7,     0,     8,     1,
       2,     1,     3,     4,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* module: file_input  */
#line 212 "parser.y"
                   {
    res += (yyvsp[0])._3AC;
}
#line 1820 "parser.tab.c"
    break;

  case 3: /* file_input: file_input NEWLINE  */
#line 216 "parser.y"
                                {
    yyval = yyvsp[-1];
}
#line 1828 "parser.tab.c"
    break;

  case 4: /* file_input: file_input stmt  */
#line 219 "parser.y"
                  {
    (yyval)._3AC = (yyvsp[-1])._3AC + (yyvsp[0])._3AC;
}
#line 1836 "parser.tab.c"
    break;

  case 5: /* file_input: NEWLINE  */
#line 222 "parser.y"
          {
    
}
#line 1844 "parser.tab.c"
    break;

  case 6: /* file_input: stmt  */
#line 225 "parser.y"
       {
    yyval = yyvsp[0];
}
#line 1852 "parser.tab.c"
    break;

  case 7: /* func_action: %empty  */
#line 230 "parser.y"
              {
    ST *newST = new ST;
    newST->parentST = CurrST;
    newST->type = FUNCTION_ST;
    CurrST = newST;
}
#line 1863 "parser.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 239 "parser.y"
                                                         {
    CurrST->return_type = (yyvsp[0]).type;
    ST* parentST = CurrST->parentST;
    auto fun = new Function;
    fun->return_type = (yyvsp[0]).type;
    fun->args = (yyvsp[-2]).args;
    fun->funcST = CurrST;
    auto entry = new STEntry;
    if(parentST->type == CLASS_ST){
        entry->lex = CurrST->current_Class->name + "." + (yyvsp[-4]).lex;
    }
    else{
        entry->lex = (yyvsp[-4]).lex;
    }
    entry->func = fun;
    entry->lineno = (yyvsp[-5]).lineno;
    entry->func = fun;
    entry->lineno = (yyvsp[-5]).lineno;
    parentST->insert((yyvsp[-4]).lex, entry);

}
#line 1889 "parser.tab.c"
    break;

  case 9: /* funcdef: DEF NAME func_action parameters ARROW type_name $@1 COLON suite  */
#line 260 "parser.y"
{
    ST* oldST = CurrST;
    CurrST = CurrST->parentST;
    string lex;
    if(CurrST->type == CLASS_ST){
        // cout << "Class function" << endl;
        lex = CurrST->current_Class->name + "." + (yyvsp[-7]).lex;
    }
    else{
        lex = (yyvsp[-7]).lex;
    }
    (yyval)._3AC = "@beginfunc " + lex + ":\n" + "ra = popparam\n" + (yyvsp[-5])._3AC + (yyvsp[0])._3AC + "goto ra\n" "@endfunc\n";

}
#line 1908 "parser.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 274 "parser.y"
                                        {
    CurrST->return_type = None_type;
    ST* parentST = CurrST->parentST;
    auto fun = new Function;
    fun->return_type = None_type;
    fun->args = (yyvsp[-1]).args;
    fun->funcST = CurrST;
    auto entry = new STEntry;
    if(parentST->type == CLASS_ST){
        entry->lex = CurrST->current_Class->name + "." + (yyvsp[-3]).lex;
    }
    else{
        entry->lex = (yyvsp[-3]).lex;
    }
    entry->func = fun;
    entry->lineno = (yyvsp[-4]).lineno;
    entry->func = fun;
    entry->lineno = (yyvsp[-4]).lineno;
    parentST->insert((yyvsp[-3]).lex, entry);

}
#line 1934 "parser.tab.c"
    break;

  case 11: /* funcdef: DEF NAME func_action parameters COLON $@2 suite  */
#line 294 "parser.y"
       {
    ST* oldST = CurrST;
    CurrST = CurrST->parentST;
    string lex;
    if(CurrST->type == CLASS_ST){
        // cout << "Class function" << endl;
        lex = CurrST->current_Class->name + "." + (yyvsp[-5]).lex;
    }
    else{
        // cout << "Global function" << endl;
        lex = (yyvsp[-5]).lex;
    }
    (yyval)._3AC = "@beginfunc " + lex + ":\n" + "ra = popparam\n"+ (yyvsp[-3])._3AC +  (yyvsp[0])._3AC  + "goto ra\n"  + "@endfunc\n";
}
#line 1953 "parser.tab.c"
    break;

  case 12: /* parameters: LEFTBRACKET typedargslist RIGHTBRACKET  */
#line 310 "parser.y"
                                                   {
    yyval = yyvsp[-1];
}
#line 1961 "parser.tab.c"
    break;

  case 13: /* parameters: LEFTBRACKET RIGHTBRACKET  */
#line 313 "parser.y"
                           {
}
#line 1968 "parser.tab.c"
    break;

  case 14: /* typedargslist: argument1  */
#line 316 "parser.y"
                          {
    yyval = yyvsp[0];
    (yyval).args.push_back((yyvsp[0]).type);
}
#line 1977 "parser.tab.c"
    break;

  case 15: /* typedargslist: typedargslist COMMA argument1  */
#line 320 "parser.y"
                                {
    yyval = yyvsp[-2];
    (yyval).args.push_back((yyvsp[0]).type);
    yyval._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC;
}
#line 1987 "parser.tab.c"
    break;

  case 16: /* argument1: tfpdef  */
#line 326 "parser.y"
                   {
    yyval = yyvsp[0];
    yyval._3AC = (yyvsp[0]).lex + " = popparam\n";
}
#line 1996 "parser.tab.c"
    break;

  case 17: /* argument1: tfpdef ASSIGN test  */
#line 330 "parser.y"
                     {
    (yyval).type = (yyvsp[-2]).type;
    if((yyvsp[-2]).type!=(yyvsp[0]).type){
        cerr <<"Error! Types on both the sides of assignment do not match in Line number: "<<yylineno<<endl;;
        exit(1);
    }
    (yyval)._3AC = (yyvsp[0])._3AC + (yyvsp[-2]).lex + " = " + (yyvsp[0]).lex + "\n";
}
#line 2009 "parser.tab.c"
    break;

  case 18: /* tfpdef: NAME  */
#line 339 "parser.y"
             {
    if (yyval.lex != "self"){
        cerr << "Error! Type of argument not defined at line no. " << yylineno << endl;
        exit(1);
    }
    if (CurrST->parentST->type != CLASS_ST){
        cerr << "Error! self expression used outside class in Line number: "<< yylineno << endl;
        exit(1);
    }
    auto curr = new STEntry;
    curr->lex = (yyvsp[0]).lex;
    curr->type = {CurrST->parentST->current_Class->name, 0};
    (yyval).type = curr->type;
    curr->lineno = (yyvsp[0]).lineno;
    CurrST->insert((yyvsp[0]).lex, curr);
}
#line 2030 "parser.tab.c"
    break;

  case 19: /* tfpdef: NAME COLON type_name  */
#line 355 "parser.y"
                       {
    auto curr = new STEntry;

    (yyval).type = (yyvsp[0]).type;
    curr->lex = (yyvsp[-2]).lex;
    curr->lineno = (yyvsp[-2]).lineno;
    curr->type = (yyvsp[0]).type;
    CurrST->insert((yyvsp[-2]).lex, curr);
}
#line 2044 "parser.tab.c"
    break;

  case 20: /* stmt: simple_stmt  */
#line 365 "parser.y"
                  {
    yyval = yyvsp[0];
}
#line 2052 "parser.tab.c"
    break;

  case 21: /* stmt: compound_stmt  */
#line 368 "parser.y"
                {
    yyval = yyvsp[0];
}
#line 2060 "parser.tab.c"
    break;

  case 22: /* simple_stmt: small_stmt_help SEMICOLON NEWLINE  */
#line 374 "parser.y"
                                                {
    yyval = yyvsp[-2];
}
#line 2068 "parser.tab.c"
    break;

  case 23: /* simple_stmt: small_stmt_help NEWLINE  */
#line 377 "parser.y"
                          {
    yyval = yyvsp[-1];
}
#line 2076 "parser.tab.c"
    break;

  case 24: /* small_stmt_help: small_stmt  */
#line 381 "parser.y"
                             {
    yyval = yyvsp[0];
}
#line 2084 "parser.tab.c"
    break;

  case 25: /* small_stmt_help: small_stmt_help SEMICOLON small_stmt  */
#line 384 "parser.y"
                                       {
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC;
}
#line 2092 "parser.tab.c"
    break;

  case 26: /* small_stmt: expr_stmt  */
#line 388 "parser.y"
                      {
    yyval = yyvsp[0];
}
#line 2100 "parser.tab.c"
    break;

  case 27: /* small_stmt: flow_stmt  */
#line 391 "parser.y"
            {
    yyval = yyvsp[0];
}
#line 2108 "parser.tab.c"
    break;

  case 28: /* small_stmt: global_stmt  */
#line 394 "parser.y"
              {
    yyval = yyvsp[0];
}
#line 2116 "parser.tab.c"
    break;

  case 29: /* small_stmt: assert_stmt  */
#line 397 "parser.y"
              {
    yyval = yyvsp[0];
}
#line 2124 "parser.tab.c"
    break;

  case 30: /* small_stmt: print_stmt  */
#line 400 "parser.y"
             {
    yyval = yyvsp[0];
}
#line 2132 "parser.tab.c"
    break;

  case 31: /* print_stmt: PRINT LEFTBRACKET test RIGHTBRACKET  */
#line 404 "parser.y"
                                                 {
    (yyval)._3AC = (yyvsp[-1])._3AC;
    (yyval)._3AC += "param " + (yyvsp[-1]).lex + "\n";
    (yyval)._3AC += "call print 1\n";
}
#line 2142 "parser.tab.c"
    break;

  case 32: /* expr_stmt: lvalue COLON type_name  */
#line 416 "parser.y"
                                  {
    if (CurrST->type == FUNCTION_ST && CurrST->parentST->type == CLASS_ST && (yyvsp[-2]).is_attr){
        auto entry = new STEntry;
        entry->lex = (yyvsp[-2]).attr_name;
        entry->type = (yyvsp[0]).type;
        entry->lineno = (yyvsp[-1]).lineno;
        CurrST->parentST->insert((yyvsp[-2]).attr_name, entry);
    }
    else{
        auto entry = new STEntry;
        entry->lex = (yyvsp[-2]).lex;
        entry->type = (yyvsp[0]).type;
        entry->lineno = (yyvsp[-1]).lineno;
        (yyval)._3AC += "stackpointer +xxx\n";
        CurrST->insert((yyvsp[-2]).lex, entry);
    }
}
#line 2164 "parser.tab.c"
    break;

  case 33: /* expr_stmt: lvalue COLON type_name ASSIGN test  */
#line 434 "parser.y"
{
    if ((yyvsp[-2]).type != (yyvsp[0]).type){
        if ((yyvsp[-2]).type == Float_type && (yyvsp[0]).type == Int_type){
            (yyvsp[0]).type = Float_type;
        }
        else if ((yyvsp[-2]).type == Int_type && (yyvsp[0]).type == Float_type){
            (yyvsp[0]).type = Int_type;
        }
        else{
            cerr << "Error! Type mismatch in assignment at line number: " << yylineno << endl;
            cerr << "Expected: " << (yyvsp[-2]).type.s << " Got: " << (yyvsp[0]).type.s << endl;
            exit(1);
        }
    }
    if (CurrST->type == FUNCTION_ST && CurrST->parentST->type == CLASS_ST && (yyvsp[-4]).is_attr){
        auto entry = new STEntry;
        entry->lex = (yyvsp[-4]).attr_name;
        entry->type = (yyvsp[-2]).type;
        entry->lineno = (yyvsp[-3]).lineno;
        CurrST->parentST->insert((yyvsp[-4]).attr_name, entry);
        offset = CurrST->parentST->lookup((yyvsp[-4]).attr_name)->offset;
        (yyval)._3AC = (yyvsp[0])._3AC + (yyvsp[-4]).lex + "[" + to_string(offset) + "] = " + (yyvsp[0]).lex + "\n";
    }
    else{
        auto entry = new STEntry;
        entry->lex = (yyvsp[-4]).lex;
        entry->type = (yyvsp[-2]).type;
        entry->lineno = (yyvsp[-3]).lineno;
        // cout << "Here inserting " << ($1).lex << " at line number: " << ($2).lineno << endl;
        (yyval)._3AC += "stackpointer +xxx\n";
        CurrST->insert((yyvsp[-4]).lex, entry);
        (yyval)._3AC = (yyvsp[0])._3AC + (yyvsp[-4]).lex + " = " + (yyvsp[0]).lex + "\n";
    }
}
#line 2203 "parser.tab.c"
    break;

  case 34: /* expr_stmt: atom_expr ASSIGN test  */
#line 468 "parser.y"
                        {
    if ((yyvsp[-2]).is_assign == 0){
        cerr << "Error! Lvalue required in assignment at line number: " << yylineno << endl;
        exit(1);
    }
    if (!(yyvsp[-2]).is_attr && !(yyvsp[-2]).is_idx){ 
        auto entry = CurrST->lookup((yyvsp[-2]).lex);
        if (entry->type != (yyvsp[0]).type){
            cerr << "Error! Type mismatch in Line number: " << yylineno << endl;
            exit(1);
        }
    }
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + (yyvsp[-2]).lex + " = " + (yyvsp[0]).lex + "\n";
}
#line 2222 "parser.tab.c"
    break;

  case 35: /* expr_stmt: atom_expr augassign test  */
#line 482 "parser.y"
                           {
    if ((yyvsp[-2]).is_assign == 0){
        cerr << "Error! Lvalue required in assignment at line number: " << yylineno << endl;
        exit(1);
    }
    Type t;
    if (!(yyvsp[-2]).is_attr){
        auto entry = CurrST->lookup((yyvsp[-2]).lex);
        if (entry->type != (yyvsp[0]).type){
            // cerr << "Error! Type mismatch in Line number: " << yylineno << endl;
            // exit(1);
            if (entry->type == Float_type && (yyvsp[0]).type == Int_type){
                (yyvsp[0]).type = Float_type;
            }
            if (entry->type != (yyvsp[0]).type){
                cerr << "Error! Type mismatch in Line number: " << yylineno << endl;
                exit(1);
            }
        }
        t = entry->type;
    }
    else {
        t = (yyvsp[-2]).type;
    }
    if((yyvsp[-1]).lex=="PLUSEQUAL" || (yyvsp[-1]).lex=="MINUSEQUAL" || (yyvsp[-1]).lex=="MULTIPLYEQUAL" ||  (yyvsp[-1]).lex=="DIVIDEEQUAL" || (yyvsp[-1]).lex=="MODEQUAL" ||  (yyvsp[-1]).lex=="EXPONENTEQUAL" ){
        if(t != Int_type && t !=Float_type){
            cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
            exit(1);
        }
        if (t == Float_type && (yyvsp[0]).type == Int_type){
            (yyvsp[0]).type = Float_type;
        }
        if (t != (yyvsp[0]).type){
            cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
            exit(1);
        }
        (yyval).type=t;
    }
    else if((yyvsp[-1]).lex=="RIGHTSHIFTEQUAL" || (yyvsp[-1]).lex=="LEFTSHIFTEQUAL" || (yyvsp[-1]).lex=="ANDEQUAL" ||  (yyvsp[-1]).lex=="OREQUAL" || (yyvsp[-1]).lex=="XOREQUAL"){
        if(t != Int_type){
            cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
            exit(1);
        }
        if (t != (yyvsp[0]).type){
            cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
            exit(1);
        } 
        (yyval).type=t;   
    }
    else if((yyvsp[-1]).lex=="DIVIDEDIVIDEEQUAL"){
        if(t != Int_type && t !=Float_type){
            cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
            exit(1);
        }
        if (t != (yyvsp[0]).type){
            cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
            exit(1);
        }
        (yyval).type=Int_type;        
    }
    
    string str = (yyvsp[-1]).lex;
    str.pop_back();
    string tmpp = newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC;
    (yyval)._3AC = (yyvsp[0])._3AC + tmpp + " = " + (yyvsp[-2]).lex + " " + str + " " + (yyvsp[0]).lex + "\n";
    (yyval)._3AC = (yyval)._3AC + (yyvsp[-2]).lex + " = " + tmpp + "\n";
}
#line 2295 "parser.tab.c"
    break;

  case 36: /* expr_stmt: test  */
#line 550 "parser.y"
       {
    yyval = yyvsp[0];
}
#line 2303 "parser.tab.c"
    break;

  case 37: /* type_name: NAME  */
#line 555 "parser.y"
                 { 
    if (sz.find((yyvsp[0]).lex) == sz.end())
    {
        cerr << "ERROR! Type not defined in line no. " << yylineno << endl;
        exit(1);
    }
    (yyval).type.s = (yyvsp[0]).lex;
    (yyval).type.is_list = false;
}
#line 2317 "parser.tab.c"
    break;

  case 38: /* type_name: NAME LEFTSQUAREBRACKET NAME RIGHTSQUAREBRACKET  */
#line 564 "parser.y"
                                                 {
    if(string((yyvsp[-3]).lex) != "list") {
        cerr << "Error! syntax error in list declaration in Line number: " << yylineno << endl;
        exit(1);
        
    }
    if (sz.find((yyvsp[-1]).lex)==sz.end()){
         cerr << "Error! Type not defined in line no. : " << yylineno << endl;
         exit(1);
    }
    (yyval).type.s = (yyvsp[-1]).lex;
    (yyval).type.is_list = true;
}
#line 2335 "parser.tab.c"
    break;

  case 39: /* type_name: NONE  */
#line 577 "parser.y"
       {
    (yyval).type = None_type;
}
#line 2343 "parser.tab.c"
    break;

  case 40: /* augassign: PLUSEQUAL  */
#line 580 "parser.y"
                     {
    (yyval).lex = "+=";

}
#line 2352 "parser.tab.c"
    break;

  case 41: /* augassign: MINUSEQUAL  */
#line 584 "parser.y"
             {
    (yyval).lex = "-=";

}
#line 2361 "parser.tab.c"
    break;

  case 42: /* augassign: MULTIPLYEQUAL  */
#line 588 "parser.y"
                {
    (yyval).lex = "*=";
}
#line 2369 "parser.tab.c"
    break;

  case 43: /* augassign: DIVIDEEQUAL  */
#line 591 "parser.y"
              {
    (yyval).lex = "/=";
}
#line 2377 "parser.tab.c"
    break;

  case 44: /* augassign: MODEQUAL  */
#line 594 "parser.y"
           {
    (yyval).lex = "%=";
}
#line 2385 "parser.tab.c"
    break;

  case 45: /* augassign: ANDEQUAL  */
#line 597 "parser.y"
           {
    (yyval).lex = "&=";
}
#line 2393 "parser.tab.c"
    break;

  case 46: /* augassign: OREQUAL  */
#line 600 "parser.y"
          {
    (yyval).lex = "|=";
}
#line 2401 "parser.tab.c"
    break;

  case 47: /* augassign: XOREQUAL  */
#line 603 "parser.y"
           {
    (yyval).lex = "^=";

}
#line 2410 "parser.tab.c"
    break;

  case 48: /* augassign: LEFTSHIFTEQUAL  */
#line 607 "parser.y"
                 {
    (yyval).lex = "<<=";

}
#line 2419 "parser.tab.c"
    break;

  case 49: /* augassign: RIGHTSHIFTEQUAL  */
#line 611 "parser.y"
                  {
    (yyval).lex = ">>=";
}
#line 2427 "parser.tab.c"
    break;

  case 50: /* augassign: EXPONENTEQUAL  */
#line 614 "parser.y"
                {
    (yyval).lex = "**=";
}
#line 2435 "parser.tab.c"
    break;

  case 51: /* augassign: DIVIDEDIVIDEEQUAL  */
#line 617 "parser.y"
                    {
    (yyval).lex = "//=";
}
#line 2443 "parser.tab.c"
    break;

  case 52: /* flow_stmt: break_stmt  */
#line 622 "parser.y"
                      {
    yyval=yyvsp[0];
}
#line 2451 "parser.tab.c"
    break;

  case 53: /* flow_stmt: continue_stmt  */
#line 625 "parser.y"
                {
    yyval=yyvsp[0];
}
#line 2459 "parser.tab.c"
    break;

  case 54: /* flow_stmt: return_stmt  */
#line 628 "parser.y"
              {
    yyval=yyvsp[0];
}
#line 2467 "parser.tab.c"
    break;

  case 55: /* break_stmt: BREAK  */
#line 632 "parser.y"
                  {
    (yyval)._3AC = "goto " + e_label.top() + "\n";
}
#line 2475 "parser.tab.c"
    break;

  case 56: /* continue_stmt: CONTINUE  */
#line 636 "parser.y"
                        {
    (yyval)._3AC = "goto " + s_label.top() + "\n";
}
#line 2483 "parser.tab.c"
    break;

  case 57: /* return_stmt: RETURN test  */
#line 640 "parser.y"
                         {
    // should occur only in a function
    if(CurrST->type != FUNCTION_ST) {
        cerr << "Error! Return Statement can only occur within function at line no. "<<yylineno<<endl;
        exit(1);
    }
    // the type of test should match the function type
    if ((yyvsp[0]).type != CurrST->return_type){
        // cout << "$2:" << ($2).type.s << ": " << CurrST->return_type.s << endl;
        cerr << "Error! Type mismatch in Return Statement at line no. "<<yylineno<<endl;
        exit(1);
    }
    yyval._3AC = (yyvsp[0])._3AC + "push " + (yyvsp[0]).lex + "\n";
}
#line 2502 "parser.tab.c"
    break;

  case 58: /* return_stmt: RETURN  */
#line 654 "parser.y"
         {
    if(CurrST->type != FUNCTION_ST) {
        cerr << "Error! Return Statement can only occur within function at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (CurrST->return_type != None_type){
        cout << "Error! No value recieved in Return Statement at line no. "<<yylineno<<endl;
        exit(1);
    }
}
#line 2517 "parser.tab.c"
    break;

  case 59: /* global_stmt: GLOBAL NAME  */
#line 665 "parser.y"
                         {
    is_global[(yyvsp[0]).lex] = true;
}
#line 2525 "parser.tab.c"
    break;

  case 60: /* global_stmt: global_stmt COMMA NAME  */
#line 668 "parser.y"
                          {
    is_global[(yyvsp[0]).lex] = true;
}
#line 2533 "parser.tab.c"
    break;

  case 61: /* assert_stmt: ASSERT test COMMA test  */
#line 673 "parser.y"
                                    {

}
#line 2541 "parser.tab.c"
    break;

  case 62: /* assert_stmt: ASSERT test  */
#line 676 "parser.y"
              {
}
#line 2548 "parser.tab.c"
    break;

  case 63: /* compound_stmt: if_stmt  */
#line 679 "parser.y"
                       {
    yyval=yyvsp[0];
}
#line 2556 "parser.tab.c"
    break;

  case 64: /* compound_stmt: while_stmt  */
#line 682 "parser.y"
             {
    yyval=yyvsp[0];
}
#line 2564 "parser.tab.c"
    break;

  case 65: /* compound_stmt: for_stmt  */
#line 685 "parser.y"
           {
    yyval=yyvsp[0];
}
#line 2572 "parser.tab.c"
    break;

  case 66: /* compound_stmt: funcdef  */
#line 688 "parser.y"
          {
    // $$=$1;
    (yyval)._3AC = "";
    res += (yyvsp[0])._3AC;
}
#line 2582 "parser.tab.c"
    break;

  case 67: /* compound_stmt: classdef  */
#line 693 "parser.y"
           {
    yyval=yyvsp[0];
}
#line 2590 "parser.tab.c"
    break;

  case 68: /* dummy_if: IF test COLON  */
#line 697 "parser.y"
                         {
    (yyval).next = newLabel();
    (yyval)._3AC = (yyvsp[-1])._3AC + "ifz " + (yyvsp[-1]).lex + " goto " + (yyval).next + "\n";
}
#line 2599 "parser.tab.c"
    break;

  case 69: /* if_stmt: dummy_if suite if_stmt_help_1  */
#line 702 "parser.y"
                                       {
    auto s = newLabel();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[-1])._3AC + "goto " + s + "\n" + "@label " + (yyvsp[-2]).next + ":\n" + (yyvsp[0])._3AC + "@label " + s + "\n";
}
#line 2608 "parser.tab.c"
    break;

  case 70: /* if_stmt: dummy_if suite if_stmt_help  */
#line 707 "parser.y"
                              {
    auto s = newLabel();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[-1])._3AC + "goto " + s + "\n" + "@label " + (yyvsp[-2]).next + ":\n" + (yyvsp[0])._3AC + "@label " + s + "\n";
}
#line 2617 "parser.tab.c"
    break;

  case 71: /* if_stmt: dummy_if suite ELSE COLON suite  */
#line 711 "parser.y"
                                  {
    auto s = newLabel();
    (yyval)._3AC = (yyvsp[-4])._3AC + (yyvsp[-3])._3AC + "goto " + s + "\n" + "@label " + (yyvsp[-4]).next + ":\n" + (yyvsp[0])._3AC + "@label " + s + "\n";
}
#line 2626 "parser.tab.c"
    break;

  case 72: /* if_stmt: dummy_if suite  */
#line 715 "parser.y"
                 {
    (yyval)._3AC = (yyvsp[-1])._3AC + (yyvsp[0])._3AC + "@label " + (yyvsp[-1]).next + ":\n";
}
#line 2634 "parser.tab.c"
    break;

  case 73: /* dummy_elif: ELIF test COLON  */
#line 719 "parser.y"
                             {
    (yyval).next = newLabel();
    (yyval)._3AC = (yyvsp[-1])._3AC + "ifz " + (yyvsp[-1]).lex + " goto " + (yyval).next + "\n";
}
#line 2643 "parser.tab.c"
    break;

  case 74: /* if_stmt_help: dummy_elif suite  */
#line 724 "parser.y"
                                {
    (yyval)._3AC = (yyvsp[-1])._3AC + (yyvsp[0])._3AC + "@label " + (yyvsp[-1]).next + ":\n";
}
#line 2651 "parser.tab.c"
    break;

  case 75: /* if_stmt_help: dummy_elif suite if_stmt_help  */
#line 727 "parser.y"
                                {
    auto s = newLabel();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[-1])._3AC + "goto " + s + "\n" + "@label " + (yyvsp[-2]).next + ":\n" + (yyvsp[0])._3AC + "@label " + s + ":\n";
}
#line 2660 "parser.tab.c"
    break;

  case 76: /* if_stmt_help_1: dummy_elif suite ELSE COLON suite  */
#line 732 "parser.y"
                                                    {
    auto s = newLabel();
    (yyval)._3AC = (yyvsp[-4])._3AC + (yyvsp[-3])._3AC + "goto " + s + "\n" + "@label " + (yyvsp[-4]).next + ":\n" + (yyvsp[0])._3AC + "@label " + s + ":\n";
}
#line 2669 "parser.tab.c"
    break;

  case 77: /* if_stmt_help_1: dummy_elif suite if_stmt_help_1  */
#line 736 "parser.y"
                                  {
    auto s = newLabel();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[-1])._3AC + "goto " + s + "\n" + "@label " + (yyvsp[-2]).next + ":\n" + (yyvsp[0])._3AC + "@label " + s + ":\n";
}
#line 2678 "parser.tab.c"
    break;

  case 78: /* loop_action: %empty  */
#line 741 "parser.y"
              {
    auto s = newLabel();
    auto e = newLabel();
    s_label.push(s);
    e_label.push(e);
}
#line 2689 "parser.tab.c"
    break;

  case 79: /* while_stmt: WHILE test COLON loop_action suite  */
#line 747 "parser.y"
                                               {
    auto s = s_label.top();
    auto e = e_label.top();
    (yyval)._3AC = "@label " + s + ":\n" + (yyvsp[-3])._3AC + "ifz " + (yyvsp[-3]).lex + " goto " + e + ":\n" + (yyvsp[0])._3AC + "goto " + s + "\n" + "@label " + e + ":\n";
    s_label.pop();
    e_label.pop();
}
#line 2701 "parser.tab.c"
    break;

  case 80: /* while_stmt: WHILE test COLON loop_action suite ELSE COLON suite  */
#line 754 "parser.y"
                                                     {
    auto s = s_label.top();
    auto e = newLabel();
    auto f = e_label.top();
    (yyval)._3AC = "@label " + s + ":\n" + (yyvsp[-6])._3AC + "ifz " + (yyvsp[-6]).lex + " goto " + e + "\n" + (yyvsp[-3])._3AC + "goto " + s + "\n" + "@label " + e + ":\n" + (yyvsp[0])._3AC + "@label " + f + ":\n";
    s_label.pop();
    e_label.pop();
}
#line 2714 "parser.tab.c"
    break;

  case 81: /* for_stmt: FOR NAME IN ranges COLON loop_action suite ELSE COLON suite  */
#line 763 "parser.y"
                                                                      {
    (yyval)._3AC += (yyvsp[-6])._3AC;
    auto st = CurrST->lookup((yyvsp[-8]).lex);
    (yyval)._3AC += (yyvsp[-8]).lex + " = " + (yyvsp[-6]).rng_start + "\n";

    auto s = s_label.top();
    auto e = newLabel();
    auto f = e_label.top();
    auto temp = newTemp();
    (yyval)._3AC += "@label " + s + ":\n";
    (yyval)._3AC += temp +  "=" + (yyvsp[-8]).lex + " < " + (yyvsp[-6]).rng_end + ":\n";
    auto temp2 = newTemp();
    string incr = temp2 + " = " + (yyvsp[-8]).lex + "\n" + (yyvsp[-8]).lex + " = " + temp2 + " + 1\n";
    (yyval)._3AC += "@label " + s + ":\n" + "ifz " + temp + " goto " + e + "\n" + (yyvsp[-3])._3AC + incr + "goto " + s + "\n" + "@label " + e + ":\n" + (yyvsp[0])._3AC + "@label " + f + ":\n";
    s_label.pop();
    e_label.pop();
}
#line 2736 "parser.tab.c"
    break;

  case 82: /* for_stmt: FOR NAME IN ranges COLON loop_action suite  */
#line 780 "parser.y"
                                             {
    (yyval)._3AC += (yyvsp[-3])._3AC;
    auto st = CurrST->lookup((yyvsp[-5]).lex);
    (yyval)._3AC += (yyvsp[-5]).lex + " = " + (yyvsp[-3]).rng_start + "\n";
    auto s = s_label.top();
    auto e = e_label.top();
    auto temp = newTemp();
    (yyval)._3AC += "@label " + s + ":\n";
    (yyval)._3AC += temp +  " = " + (yyvsp[-5]).lex + " < " + (yyvsp[-3]).rng_end + "\n";
    auto temp2 = newTemp();
    string incr = temp2 + " = " + (yyvsp[-5]).lex + "\n" + (yyvsp[-5]).lex + " = " + temp2 + " + 1\n";
    (yyval)._3AC += "ifz " + temp + " goto " + e + "\n" + (yyvsp[0])._3AC + incr + "goto " + s + "\n" + "@label " + e + ":\n";
    s_label.pop();
    e_label.pop();
}
#line 2756 "parser.tab.c"
    break;

  case 83: /* ranges: RANGE LEFTBRACKET test COMMA test RIGHTBRACKET  */
#line 796 "parser.y"
                                                         {
    (yyval).rng_start = (yyvsp[-3]).lex;
    (yyval).rng_end = (yyvsp[-1]).lex;
    (yyval)._3AC = (yyvsp[-3])._3AC + (yyvsp[-1])._3AC;
}
#line 2766 "parser.tab.c"
    break;

  case 84: /* ranges: RANGE LEFTBRACKET test RIGHTBRACKET  */
#line 801 "parser.y"
                                      {
    (yyval).rng_start = "0";
    (yyval).rng_end = (yyvsp[-1]).lex;
    (yyval)._3AC = (yyvsp[-1])._3AC;
}
#line 2776 "parser.tab.c"
    break;

  case 85: /* suite: simple_stmt  */
#line 807 "parser.y"
                   {
    yyval = yyvsp[0];
}
#line 2784 "parser.tab.c"
    break;

  case 86: /* suite: NEWLINE INDENT stmt_help DEDENT  */
#line 811 "parser.y"
                                  {
    yyval = yyvsp[-1];
}
#line 2792 "parser.tab.c"
    break;

  case 87: /* stmt_help: stmt  */
#line 815 "parser.y"
                {
    yyval = yyvsp[0];
}
#line 2800 "parser.tab.c"
    break;

  case 88: /* stmt_help: stmt stmt_help  */
#line 818 "parser.y"
                 {
//     ($1).next = newLabel();
//     ($2).next = ()
    (yyval)._3AC = (yyvsp[-1])._3AC + (yyvsp[0])._3AC;
}
#line 2810 "parser.tab.c"
    break;

  case 89: /* test: and_test  */
#line 824 "parser.y"
                {
    yyval = yyvsp[0];
}
#line 2818 "parser.tab.c"
    break;

  case 90: /* test: test OR and_test  */
#line 827 "parser.y"
                   {
    if ((yyvsp[-2]).type != Bool_type && (yyvsp[-2]).type != Int_type){
        cerr << "Error! Type can only be integer or Boolean at line no. " <<yylineno<<endl;
        exit(1);    \
    }
    if ((yyvsp[0]).type != Bool_type && (yyvsp[0]).type != Int_type){
        cerr << "Error! Type can only be integer or Boolean at line no. " <<yylineno<<endl;
        exit(1);
    }
    (yyval).type = Bool_type;
    (yyval).lex = newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + (yyval.lex + " = " + (yyvsp[-2]).lex + " || " + (yyvsp[0]).lex + "\n");
}
#line 2836 "parser.tab.c"
    break;

  case 91: /* and_test: not_test  */
#line 842 "parser.y"
                    {
    yyval = yyvsp[0];
}
#line 2844 "parser.tab.c"
    break;

  case 92: /* and_test: and_test AND not_test  */
#line 846 "parser.y"
                        {
    if ((yyvsp[-2]).type != Bool_type && (yyvsp[-2]).type != Int_type){
        cerr << "Error! Type can only be integer or Boolean at line no. " <<yylineno<<endl;
        exit(1);
    }
    if ((yyvsp[0]).type != Bool_type && (yyvsp[0]).type != Int_type){
        cerr << "Error! Type can only be integer or Boolean at line no. " <<yylineno<<endl;
        exit(1);
    }
    (yyval).type = Bool_type;
    (yyval).lex = newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + (yyval.lex + " = " + (yyvsp[-2]).lex + " && " + (yyvsp[0]).lex + "\n");
}
#line 2862 "parser.tab.c"
    break;

  case 93: /* not_test: NOT not_test  */
#line 862 "parser.y"
                        {
    if ((yyvsp[0]).type != Bool_type && (yyvsp[0]).type != Int_type){
        cerr << "Error! Type can only be integer or Boolean at line no. " <<yylineno<<endl;
        exit(1);
    }
    (yyval).type = Bool_type;
    (yyval).lex = newTemp();
    (yyval)._3AC = (yyvsp[0])._3AC + (yyval.lex + " = " + "!" + (yyvsp[0]).lex + "\n");
}
#line 2876 "parser.tab.c"
    break;

  case 94: /* not_test: comparison  */
#line 872 "parser.y"
             {
    yyval = yyvsp[0];
}
#line 2884 "parser.tab.c"
    break;

  case 95: /* comparison: expr  */
#line 876 "parser.y"
                  {
    yyval = yyvsp[0];
}
#line 2892 "parser.tab.c"
    break;

  case 96: /* comparison: comparison comp_op expr  */
#line 880 "parser.y"
                          {  
    bool string_comp = false;
    string_comp = (yyvsp[-2]).type == Str_type || (yyvsp[0]).type == Str_type;
    if (!string_comp && (yyvsp[-2]).type != Bool_type && (yyvsp[-2]).type != Int_type && (yyvsp[-2]).type != Float_type ){
        cerr << "Error! Type can only be integer, Boolean or Float at line no. " <<yylineno<<endl;
        exit(1);
    }
    if (!string_comp && (yyvsp[0]).type != Bool_type && (yyvsp[0]).type != Int_type  && (yyvsp[0]).type != Float_type){
        cerr << "Error! Type can only be integer, Boolean or Float at line no. " <<yylineno<<endl;
        exit(1);
    }
    
    (yyval).type = Bool_type;
    (yyval).lex = newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + (yyval.lex + " = " + (yyvsp[-2]).lex + " " + (yyvsp[-1]).lex + " " + (yyvsp[0]).lex + "\n");
}
#line 2913 "parser.tab.c"
    break;

  case 97: /* comp_op: EQUAL  */
#line 896 "parser.y"
                {
    (yyval).lex = "==";
}
#line 2921 "parser.tab.c"
    break;

  case 98: /* comp_op: LESS  */
#line 899 "parser.y"
       {
    (yyval).lex = "<";
}
#line 2929 "parser.tab.c"
    break;

  case 99: /* comp_op: GREATER  */
#line 902 "parser.y"
          {
    (yyval).lex = ">";
}
#line 2937 "parser.tab.c"
    break;

  case 100: /* comp_op: GREATEREQ  */
#line 905 "parser.y"
            {
    (yyval).lex = ">=";
}
#line 2945 "parser.tab.c"
    break;

  case 101: /* comp_op: LESSEQ  */
#line 908 "parser.y"
         {
    (yyval).lex = "<=";
}
#line 2953 "parser.tab.c"
    break;

  case 102: /* comp_op: NOTEQUAL  */
#line 911 "parser.y"
           {
    (yyval).lex = "!=";
}
#line 2961 "parser.tab.c"
    break;

  case 103: /* comp_op: IS  */
#line 914 "parser.y"
     {
    (yyval).lex = "is";

}
#line 2970 "parser.tab.c"
    break;

  case 104: /* comp_op: IS NOT  */
#line 918 "parser.y"
         {
    (yyval).lex = "is not";  // not defined anywhere
}
#line 2978 "parser.tab.c"
    break;

  case 105: /* comp_op: IN  */
#line 921 "parser.y"
     {
    (yyval).lex = "in";
}
#line 2986 "parser.tab.c"
    break;

  case 106: /* comp_op: NOT IN  */
#line 924 "parser.y"
         {
    (yyval).lex = "not in"; // not defined anywhere
}
#line 2994 "parser.tab.c"
    break;

  case 107: /* expr: xor_expr  */
#line 928 "parser.y"
                {
    yyval = yyvsp[0];
}
#line 3002 "parser.tab.c"
    break;

  case 108: /* expr: expr BITOR xor_expr  */
#line 932 "parser.y"
                      {
    //error expression
    if((yyvsp[-2]).type != Int_type){
        cerr << "Error! Type can only be integer at line no." <<yylineno<<endl;
        exit(1);
    }
    if ((yyvsp[0]).type != Int_type){
        cerr << "Error! Type can only be integer at line no. " <<yylineno<<endl;
        exit(1);
    }  
    (yyval).type=(yyvsp[-2]).type;
    (yyval).lex=newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + ((yyval).lex + " = " + (yyvsp[-2]).lex + " | " + (yyvsp[0]).lex + "\n");

}
#line 3022 "parser.tab.c"
    break;

  case 109: /* xor_expr: and_expr  */
#line 948 "parser.y"
                   {
    yyval = yyvsp[0];
}
#line 3030 "parser.tab.c"
    break;

  case 110: /* xor_expr: xor_expr BITXOR and_expr  */
#line 952 "parser.y"
                           {
    //error expression
    if((yyvsp[-2]).type != Int_type){
        cerr << "Error! Type can only be integer at line no." <<yylineno<<endl;
        exit(1);
    }
    if ((yyvsp[0]).type != Int_type){
        cerr << "Error! Type can only be integer at line no. " <<yylineno<<endl;
        exit(1);
    }  
    (yyval).type=(yyvsp[-2]).type;
    (yyval).lex=newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + ((yyval).lex + " = " + (yyvsp[-2]).lex + " ^ " + (yyvsp[0]).lex + "\n");

}
#line 3050 "parser.tab.c"
    break;

  case 111: /* and_expr: shift_expr  */
#line 968 "parser.y"
                      {
    yyval = yyvsp[0];
}
#line 3058 "parser.tab.c"
    break;

  case 112: /* and_expr: and_expr AMPERSAND shift_expr  */
#line 972 "parser.y"
                                {
    //error expression
    if((yyvsp[-2]).type != Int_type){
        cerr << "Error! Type can only be integer at line no." <<yylineno<<endl;
        exit(1);
    }
    if ((yyvsp[0]).type != Int_type){
        cerr << "Error! Type can only be integer at line no. " <<yylineno<<endl;
        exit(1);
    }
    (yyval).type=(yyvsp[-2]).type;
    (yyval).lex=newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + ((yyval).lex + " = " + (yyvsp[-2]).lex + " & " + (yyvsp[0]).lex + "\n");

}
#line 3078 "parser.tab.c"
    break;

  case 113: /* shift_expr: arith_expr  */
#line 989 "parser.y"
                        {
    yyval = yyvsp[0];
}
#line 3086 "parser.tab.c"
    break;

  case 114: /* shift_expr: shift_expr LEFTSHIFT arith_expr  */
#line 993 "parser.y"
                                  {    
    if((yyvsp[-2]).type != Int_type){
        cerr << "Error! Type can only be integer at line no." <<yylineno<<endl;
        exit(1);
    }
    if ((yyvsp[0]).type != Int_type){
        cerr << "Error! Type can only be integer at line no. " <<yylineno<<endl;
        exit(1);
    }
    (yyval).type=(yyvsp[-2]).type;
    (yyval).lex=newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + ((yyval).lex + " = " + (yyvsp[-2]).lex + " << " + (yyvsp[0]).lex + "\n");

}
#line 3105 "parser.tab.c"
    break;

  case 115: /* shift_expr: shift_expr RIGHTSHIFT arith_expr  */
#line 1008 "parser.y"
                                   {
    //error statement
    if((yyvsp[-2]).type != Int_type){
        cerr << "Error! Type can only be integer at line no." <<yylineno<<endl;
        exit(1);
    }
    if ((yyvsp[0]).type != Int_type){
        cerr << "Error! Type can only be integer at line no. " <<yylineno<<endl;
        exit(1);
    }
    (yyval).type=(yyvsp[-2]).type;
    (yyval).lex=newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + ((yyval).lex + " = " + (yyvsp[-2]).lex + " >> " + (yyvsp[0]).lex + "\n");

}
#line 3125 "parser.tab.c"
    break;

  case 116: /* arith_expr: term  */
#line 1025 "parser.y"
                 {
    yyval = yyvsp[0];
}
#line 3133 "parser.tab.c"
    break;

  case 117: /* arith_expr: arith_expr PLUS term  */
#line 1029 "parser.y"
                       {
    if((yyvsp[-2]).type==Float_type && (yyvsp[0]).type==Int_type){
        (yyvsp[0]).type=Float_type;
    }
    if((yyvsp[0]).type==Float_type && (yyvsp[-2]).type==Int_type){
        (yyvsp[-2]).type=Float_type;
    }
    if((yyvsp[-2]).type != Int_type && (yyvsp[-2]).type !=Float_type){
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if ((yyvsp[-2]).type != (yyvsp[0]).type){
        cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
        exit(1);
    }
    (yyval).type = (yyvsp[-2]).type;
    (yyval).lex = newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + ((yyval).lex + " = " + (yyvsp[-2]).lex + " + " + (yyvsp[0]).lex + "\n");
}
#line 3157 "parser.tab.c"
    break;

  case 118: /* arith_expr: arith_expr MINUS term  */
#line 1048 "parser.y"
                        {
    
    if((yyvsp[-2]).type==Float_type && (yyvsp[0]).type==Int_type){
        (yyvsp[0]).type=Float_type;
    }
    if((yyvsp[0]).type==Float_type && (yyvsp[-2]).type==Int_type){
        (yyvsp[-2]).type=Float_type;
    }
    if((yyvsp[-2]).type != Int_type && (yyvsp[-2]).type !=Float_type){
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if ((yyvsp[-2]).type != (yyvsp[0]).type){
        cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
        exit(1);
    }
    (yyval).type = (yyvsp[-2]).type;
    (yyval).lex = newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + ((yyval).lex + " = " + (yyvsp[-2]).lex + " - " + (yyvsp[0]).lex + "\n");
}
#line 3182 "parser.tab.c"
    break;

  case 119: /* term: factor  */
#line 1069 "parser.y"
              {
    yyval=yyvsp[0];
}
#line 3190 "parser.tab.c"
    break;

  case 120: /* term: term MULTIPLY factor  */
#line 1073 "parser.y"
                       {
    if((yyvsp[-2]).type==Float_type && (yyvsp[0]).type==Int_type){
        (yyvsp[0]).type=Float_type;
    }
    if((yyvsp[0]).type==Float_type && (yyvsp[-2]).type==Int_type){
        (yyvsp[-2]).type=Float_type;
    }
    if((yyvsp[-2]).type != Int_type && (yyvsp[-2]).type !=Float_type){
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if ((yyvsp[-2]).type != (yyvsp[0]).type){
        cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
        exit(1);
    }
    (yyval).type = (yyvsp[-2]).type;
    (yyval).lex = newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + ((yyval).lex + " = " + (yyvsp[-2]).lex + " * " + (yyvsp[0]).lex + "\n");
}
#line 3214 "parser.tab.c"
    break;

  case 121: /* term: term DIVIDE factor  */
#line 1093 "parser.y"
                     {
    if((yyvsp[-2]).type==Float_type && (yyvsp[0]).type==Int_type){
        (yyvsp[0]).type=Float_type;
    }
    if((yyvsp[0]).type==Float_type && (yyvsp[-2]).type==Int_type){
        (yyvsp[-2]).type=Float_type;
    }
    if((yyvsp[-2]).type != Int_type && (yyvsp[-2]).type !=Float_type){
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if ((yyvsp[-2]).type != (yyvsp[0]).type){
        cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
        exit(1);
    }
    (yyval).type = (yyvsp[-2]).type;
    (yyval).lex = newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + ((yyval).lex + " = " + (yyvsp[-2]).lex + " / " + (yyvsp[0]).lex + "\n");

}
#line 3239 "parser.tab.c"
    break;

  case 122: /* term: term MOD factor  */
#line 1113 "parser.y"
                  {
    if((yyvsp[-2]).type==Float_type && (yyvsp[0]).type==Int_type){
        (yyvsp[0]).type=Float_type;
    }
    if((yyvsp[0]).type==Float_type && (yyvsp[-2]).type==Int_type){
        (yyvsp[-2]).type=Float_type;
    }
    if((yyvsp[-2]).type != Int_type && (yyvsp[-2]).type !=Float_type){
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if ((yyvsp[-2]).type != (yyvsp[0]).type){
        cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
        exit(1);
    }
    (yyval).type = (yyvsp[-2]).type;
    (yyval).lex = newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + ((yyval).lex + " = " + (yyvsp[-2]).lex + " \% " + (yyvsp[0]).lex + "\n"); //%%
}
#line 3263 "parser.tab.c"
    break;

  case 123: /* term: term DIVIDEDIVIDE factor  */
#line 1132 "parser.y"
                           {
    if((yyvsp[-2]).type==Float_type && (yyvsp[0]).type==Int_type){
        (yyvsp[0]).type=Float_type;
    }
    if((yyvsp[0]).type==Float_type && (yyvsp[-2]).type==Int_type){
        (yyvsp[-2]).type=Float_type;
    }
    if((yyvsp[-2]).type != Int_type && (yyvsp[-2]).type !=Float_type){
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if ((yyvsp[-2]).type != (yyvsp[0]).type){
        cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
        exit(1);
    }
    (yyval).type = Int_type;
    (yyval).lex = newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + ((yyval).lex + " = " + (yyvsp[-2]).lex + " // " + (yyvsp[0]).lex + "\n");

}
#line 3288 "parser.tab.c"
    break;

  case 124: /* factor: power  */
#line 1153 "parser.y"
               {
    yyval=yyvsp[0];
}
#line 3296 "parser.tab.c"
    break;

  case 125: /* factor: PLUS factor  */
#line 1157 "parser.y"
              {
    if((yyvsp[0]).type != Int_type && (yyvsp[0]).type !=Float_type && (yyvsp[0]).type !=Bool_type){  // Boolean Typecasting
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if((yyvsp[0]).type==Bool_type){
        (yyvsp[0]).type==Int_type;  // Boolean Typecasting
    }
    (yyval) = (yyvsp[0]);
}
#line 3311 "parser.tab.c"
    break;

  case 126: /* factor: MINUS factor  */
#line 1167 "parser.y"
               {
    if((yyvsp[0]).type != Int_type && (yyvsp[0]).type !=Float_type && (yyvsp[0]).type !=Bool_type){  // Boolean Typecasting
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if((yyvsp[0]).type==Bool_type){
        (yyvsp[0]).type==Int_type;  // Boolean Typecasting
    }
    (yyval).type =(yyvsp[0]).type;
    (yyval).lex=newTemp();
    (yyval)._3AC = (yyvsp[0])._3AC + ((yyval).lex + " = " + " -" + (yyvsp[0]).lex + "\n");
}
#line 3328 "parser.tab.c"
    break;

  case 127: /* factor: BITNOT factor  */
#line 1179 "parser.y"
                {
    if((yyvsp[0]).type != Int_type && (yyvsp[0]).type !=Float_type && (yyvsp[0]).type !=Bool_type){  // Boolean Typecasting
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if((yyvsp[0]).type==Bool_type){
        (yyvsp[0]).type==Int_type;  // Boolean Typecasting
    }
    (yyval).type =(yyvsp[0]).type;
    (yyval).lex=newTemp();
    (yyval)._3AC = (yyvsp[0])._3AC + ((yyval).lex + " = " + " ~" + (yyvsp[0]).lex + "\n");
}
#line 3345 "parser.tab.c"
    break;

  case 128: /* power: atom_expr  */
#line 1192 "parser.y"
                  {
    yyval=yyvsp[0];   
}
#line 3353 "parser.tab.c"
    break;

  case 129: /* power: atom_expr EXP factor  */
#line 1196 "parser.y"
                       {
    if((yyvsp[-2]).type==Float_type && (yyvsp[0]).type==Int_type){
        (yyvsp[-1]).type=Float_type;
    }
    if((yyvsp[-1]).type==Float_type && (yyvsp[0]).type==Int_type){
        (yyvsp[-2]).type=Float_type;
    }
    if((yyvsp[-2]).type != Int_type && (yyvsp[-2]).type !=Float_type){
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if ((yyvsp[-2]).type != (yyvsp[0]).type){
        cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
        exit(1);
    }
    
    (yyval).type = (yyvsp[-2]).type;
    (yyval).lex = newTemp();
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC + ((yyval).lex + " = " + (yyvsp[-2]).lex + " ** " + (yyvsp[0]).lex + "\n");

}
#line 3379 "parser.tab.c"
    break;

  case 130: /* atom_expr: atom  */
#line 1219 "parser.y"
                {
    yyval=yyvsp[0];
}
#line 3387 "parser.tab.c"
    break;

  case 131: /* atom_expr: lvalue index_trailer  */
#line 1223 "parser.y"
{
    if (!(yyvsp[-1]).is_attr){
        auto STEntry = CurrST->lookup((yyvsp[-1]).lex);
        
        if (STEntry->type.is_list == 0){
            cerr << "Error! Only List Type accepted in [] at line no. "<<yylineno<<endl;
            exit(1);
        }
        if ((yyvsp[0]).type != Int_type){
            cerr << "Error! Only Integer Type accepted in [] at line no. "<<yylineno<<endl;
            exit(1);
        }
        (yyval).type = STEntry->type;
        (yyval).type.is_list = 0;
        (yyval).is_idx = 1;
        (yyval).is_assign = 1;
        (yyval)._3AC = (yyvsp[0])._3AC;
        auto temp = newTemp();
        (yyval)._3AC = temp + " = " + (yyvsp[0]).lex + " * " + to_string(sz[STEntry->type.s]) + "\n";
        (yyval).lex = (yyvsp[-1]).lex + "[" + temp + "]";
    }
    else {
        auto cls = cls_ST[CurrST->lookup((yyvsp[-1]).lex)->type.s]->current_Class;
        auto attr = cls->classST->lookupClassAttr((yyvsp[-1]).attr_name);
        if (attr->type.is_list == 0){
            cerr << "Error! Only List Type accepted in [] at line no. "<<yylineno<<endl;
            exit(1);
        }
        if ((yyvsp[0]).type != Int_type){
            cerr << "Error! Only Integer Type accepted in [] at line no. "<<yylineno<<endl;
            exit(1);
        }
        (yyval).type = attr->type;
        (yyval).type.is_list = 0;
        (yyval).is_idx = 1;
        (yyval).is_assign = 1;
        (yyval)._3AC = (yyvsp[0])._3AC;
        auto temp = newTemp();
        (yyval)._3AC = temp + " = " + (yyvsp[0]).lex + " * " + to_string(sz[attr->type.s]) + "\n";
        auto temp2 = newTemp();
        (yyval)._3AC += temp2 + " = " + (yyvsp[-1]).lex + "[" + to_string(attr->offset) + "]\n";
        (yyval).lex = temp2 + "[" + temp + "]";
    }
}
#line 3436 "parser.tab.c"
    break;

  case 132: /* atom_expr: lvalue  */
#line 1268 "parser.y"
{
    (yyval).is_assign = 1;
    if ((yyvsp[0]).is_attr) {
        yyval = yyvsp[0];
        // cout << "here\n";
        auto entry = CurrST->lookup((yyvsp[0]).lex);
        auto cls = cls_ST[entry->type.s]->current_Class;
        // cout << ($1).attr_name << "\n";
        auto attr = cls->classST->lookupClassAttr((yyvsp[0]).attr_name);
        (yyval).type = attr->type;
        // cout << "here\n";
        (yyval).lex = (yyvsp[0]).lex + "[" + to_string(attr->offset) + "]";
    }
    else {
        auto entry = CurrST->lookup((yyvsp[0]).lex);
        (yyval).type = entry->type;
        (yyval).func = entry->func;
        (yyval).cls = entry->cls;
        (yyval).lex = (yyvsp[0]).lex;
    }
}
#line 3462 "parser.tab.c"
    break;

  case 133: /* atom_expr: lvalue call_trailer  */
#line 1290 "parser.y"
{
    if ((yyvsp[-1]).lex == "len"){
        if ((yyvsp[0]).args_list.size() != 1){
            cerr << "Error! len() takes exactly 1 argument at line no. "<<yylineno<<endl;
            exit(1);
        }
        if ((yyvsp[0]).args_list[0].second.is_list == 0){
            cerr << "Error! Only List Type accepted in len() at line no. "<<yylineno<<endl;
            exit(1);
        }
        (yyval).type = Int_type;
        (yyval).lex = newTemp();
        (yyval)._3AC += "param " + (yyvsp[0]).args_list[0].first + "\n";
        (yyval)._3AC += "stackpointer +xxx\n";
        (yyval)._3AC += "call len 1\n";
        (yyval)._3AC += "stackpointer -yyy\n";
        (yyval)._3AC += (yyval.lex + " = " + "popparam\n");
    }
    else {
    auto entry = CurrST->lookup((yyvsp[-1]).lex);
    if ((yyvsp[-1]).is_class) // its the class calling a method
    {
        auto cls = cls_ST[(yyvsp[-1]).lex]->current_Class;
        auto mthd = cls->classST->lookupClassAttr((yyvsp[-1]).attr_name);
        if (mthd == NULL){
            cerr << "Error! Method not found at line no. "<<yylineno<<endl;
            exit(1);
        }
        if (mthd->func == NULL){
            cerr << "Error! Method not found at line no. "<<yylineno<<endl;
        }
        if (mthd->func->args.size() != (yyvsp[0]).args_list.size()){
            cerr << "Error! Number of arguments mismatch at line no. "<<yylineno<<endl;
            exit(1);
        }
        for (int i = 1; i < mthd->func->args.size(); i++){
            if (mthd->func->args[i] != (yyvsp[0]).args_list[i].second){
                cerr << "Error! Type mismatch at line no. "<<yylineno<<endl;
                exit(1);
            }
        }
        (yyval).type = mthd->func->return_type;
        (yyval)._3AC = (yyvsp[0])._3AC;
        for (int i = (yyvsp[0]).args_list.size() - 1; i >= 0 ; i--){
            (yyval)._3AC += "param " + (yyvsp[0]).args_list[i].first + "\n";
        }
        (yyval)._3AC += "stackpointer +xxx\n";
        (yyval)._3AC += "call " + mthd->lex + " " + to_string((yyvsp[0]).args_list.size()) + "\n";
        (yyval)._3AC += "stackpointer -yyy\n";
        if (mthd->func->return_type != None_type){
            (yyval).lex = newTemp();
            (yyval)._3AC += (yyval.lex + " = " + "popparam\n");
        }
    }
    else if (entry->cls){ // it's a constructor
        auto ctor = entry->cls->classST->lookup("__init__")->func;
        if (ctor->args.size() != (yyvsp[0]).args_list.size() + 1) {
            cout << "Error number of arguments do not match at line no. " << yylineno << endl;
        } 
        for (int i = 0; i < ctor->args.size() - 1; i++){
            if (ctor->args[i+1] != (yyvsp[0]).args_list[i].second){
                    cout << "Error! Type of arguments do not match at line no. "<< yylineno << endl;
            }
        }
        (yyval).type = {(yyvsp[-1]).lex,0};
        (yyval)._3AC += "param " + to_string(entry->cls->classST->offset) + "\n";
        (yyval)._3AC += "call memalloc 1\n";
        auto temp = newTemp();
        (yyval)._3AC += "popparam " + temp + "\n"; 
        for (int i = (yyvsp[0]).args_list.size() - 1 ; i >= 0 ; i--){
            (yyval)._3AC += "param " + (yyvsp[0]).args_list[i].first + "\n";
        }
        (yyval)._3AC += "param " + temp + "\n"; 
        (yyval)._3AC += "stackpointer +xxx\n";
        (yyval)._3AC += "call " + (yyvsp[-1]).lex + ".__init__ " + to_string(ctor->args.size()) + "\n";
        (yyval)._3AC += "stackpointer -yyy\n";
        (yyval).lex = temp;
    }
    else if ((yyvsp[-1]).is_attr) {
        auto cls = CurrST->lookup(entry->type.s)->cls;
        auto mthd_S = cls->classST->lookupClassAttr((yyvsp[-1]).attr_name);
        auto mthd = mthd_S->func;
        if (mthd->args.size() != (yyvsp[0]).args_list.size() + 1) {
            cout << "Error number of arguments do not match at line no. " << yylineno << endl;;
        } 
        for (int i = 0; i < mthd->args.size() - 1; i++){
            if (mthd->args[i+1] != (yyvsp[0]).args_list[i].second){
                    cout << "Error! Type of arguments do not match at line no. "<< yylineno << endl;
            }
        }
        (yyval).type = mthd->return_type;
        (yyval)._3AC = (yyvsp[0])._3AC;
        for (int i = (yyvsp[0]).args_list.size() - 1 ; i >= 0 ; i--){
            (yyval)._3AC += "param " + (yyvsp[0]).args_list[i].first + "\n";
        }
        (yyval)._3AC += "param " + (yyvsp[-1]).lex + "\n";
        (yyval)._3AC += "stackpointer +xxx\n";
        (yyval)._3AC += "call " + mthd_S->lex + " " + to_string(mthd->args.size()) + "\n";
        (yyval)._3AC += "stackpointer -yyy\n";
        if (mthd->return_type != None_type){
                (yyval).lex = newTemp();
                (yyval)._3AC += (yyval.lex + " = " + "popparam\n");
        }
    }
    else if (!(yyvsp[-1]).is_attr){
        if (entry->func == NULL){
            cerr << "Error! Function not found at line no. "<<yylineno<<endl;
            exit(1);
        }
        (yyvsp[-1]).func = entry->func;
        if ((yyvsp[-1]).func){
            if ((yyvsp[0]).trailer_type != FUNCTION_CALL){
                cout << "Error! Not a function call at line no:" << yylineno << endl;
            }
            if ((yyvsp[-1]).func->args.size() != (yyvsp[0]).args_list.size()){
                cout << "Error! number of arguments do not match at line no. "<< yylineno << endl;
            }
            for (int i = 0; i < (yyvsp[-1]).func->args.size(); i++){
                if ((yyvsp[-1]).func->args[i] != (yyvsp[0]).args_list[i].second){
                    cout << "Error! Type of arguments do not match at line no. "<< yylineno << endl;
                }
            }
            (yyval).type = (yyvsp[-1]).func->return_type;
            (yyval)._3AC = (yyvsp[0])._3AC;
            for (int i = (yyvsp[0]).args_list.size() - 1 ; i >= 0 ; i--){
                (yyval)._3AC += "param " + (yyvsp[0]).args_list[i].first + "\n";
            }
            (yyval)._3AC += "stackpointer +xxx\n";
            (yyval)._3AC += "call " + (yyvsp[-1]).lex + " " + to_string((yyvsp[0]).args_list.size()) + "\n";
            (yyval)._3AC += "stackpointer -yyy\n";
            if ((yyvsp[-1]).func->return_type != None_type){
                (yyval).lex = newTemp();
                (yyval)._3AC += (yyval.lex + " = " + "popparam\n");
            }
        }
    }
    }
}
#line 3605 "parser.tab.c"
    break;

  case 134: /* lvalue: NAME  */
#line 1429 "parser.y"
              {
    yyval = yyvsp[0];
    // cout << "Here again\n";
}
#line 3614 "parser.tab.c"
    break;

  case 135: /* lvalue: NAME dot_trailer  */
#line 1433 "parser.y"
                   {
    yyval.is_attr = true;
    yyval.attr_name = (yyvsp[0]).lex;
    yyval.is_assign = 1;
    if ((yyvsp[-1]).lex != "self"){
        auto entry = CurrST->lookup((yyvsp[-1]).lex);
        // cout << "Here\n";
        Class *cls;
        if (entry->cls){ // its a class name using a method outside
            (yyval).is_class = true;
            cls = entry->cls;
        }
        else {
            cls = CurrST->lookup(entry->type.s)->cls;
        }
        // cout << "Here\n";
        // auto attr = cls->classST->lookup(($2).lex);
        // // cout << "Here\n";
        // if (attr == NULL){
        //     cerr << "Error! Attribute / Method not found at line no. "<<yylineno<<endl;
        //     exit(1);
        // }

        auto attr = cls->classST->lookupClassAttr((yyvsp[0]).lex);

        (yyval).type = attr->type;
        (yyval).is_attr = true;
        (yyval).attr_name = (yyvsp[0]).lex;
        (yyval).lex = (yyvsp[-1]).lex;
    }
}
#line 3650 "parser.tab.c"
    break;

  case 136: /* atom: LEFTBRACKET test RIGHTBRACKET  */
#line 1465 "parser.y"
                                     {
    yyval = yyvsp[-1];
}
#line 3658 "parser.tab.c"
    break;

  case 137: /* atom: LEFTSQUAREBRACKET testlist RIGHTSQUAREBRACKET  */
#line 1468 "parser.y"
                                                {
    if ((yyvsp[-1]).type.is_list){
        cerr << "Error in list declaration at line no. "<<yylineno<<endl;
    }
    (yyval).type = (yyvsp[-1]).type;
    (yyval).type.is_list = true;
    (yyval)._3AC = (yyvsp[-1])._3AC;
    auto temp = newTemp();
    (yyval)._3AC += temp + " = " + to_string((yyvsp[-1]).args_list.size()) + " * " + to_string(sz[(yyvsp[-1]).type.s]) + "\n";
    (yyval)._3AC += "param " + temp + "\n";
    (yyval)._3AC += "call memalloc 1\n";
    auto temp2 = newTemp();
    (yyval)._3AC += "popparam " + temp2 + "\n";
    for (int i = 0; i < (yyvsp[-1]).args_list.size(); i++){
        (yyval)._3AC += temp2 + "[" + to_string(sz[(yyvsp[-1]).type.s]*i) + "]" + " = " + (yyvsp[-1]).args_list[i].first + "\n";
    }
    (yyval).lex = temp2;
    (yyval).sz = (yyvsp[-1]).args_list.size();
}
#line 3682 "parser.tab.c"
    break;

  case 138: /* atom: LEFTSQUAREBRACKET RIGHTSQUAREBRACKET  */
#line 1488 "parser.y"
                                       {
    (yyval).type.is_list = 1;
}
#line 3690 "parser.tab.c"
    break;

  case 139: /* atom: INTEGER  */
#line 1491 "parser.y"
          {
    // auto temp = newTemp();
    // ($$).type= Int_type;
    // ($$).lex = temp;
    // ($$)._3AC = temp + " = " + ($1).lex + "\n";
    (yyval).type= Int_type;
    (yyval).lex = (yyvsp[0]).lex;
}
#line 3703 "parser.tab.c"
    break;

  case 140: /* atom: FLOAT  */
#line 1499 "parser.y"
        {
    // auto temp = newTemp();
    // ($$).type= Float_type;
    // ($$).lex = temp;
    // ($$)._3AC = temp + " = " + ($1).lex + "\n";
    (yyval).type= Float_type;
    (yyval).lex = (yyvsp[0]).lex;
}
#line 3716 "parser.tab.c"
    break;

  case 141: /* atom: STRING  */
#line 1507 "parser.y"
         {
    // auto temp = newTemp();
    // ($$).type= Str_type;
    // ($$).lex = temp;
    // ($$)._3AC = temp + " = " + ($1).lex + "\n";
    (yyval).type= Str_type;
    (yyval).lex = (yyvsp[0]).lex;
}
#line 3729 "parser.tab.c"
    break;

  case 142: /* atom: NONE  */
#line 1516 "parser.y"
       {
    (yyval).type = None_type;
}
#line 3737 "parser.tab.c"
    break;

  case 143: /* atom: TRUE  */
#line 1519 "parser.y"
       {
    (yyval).type= Bool_type;
    (yyval).lex = "1";
}
#line 3746 "parser.tab.c"
    break;

  case 144: /* atom: FALSE  */
#line 1523 "parser.y"
        {
    (yyval).type = Bool_type;
    (yyval).lex = "0";
    // ($$)._3AC = "goto " + ($$).false;
}
#line 3756 "parser.tab.c"
    break;

  case 145: /* call_trailer: LEFTBRACKET RIGHTBRACKET  */
#line 1529 "parser.y"
                                       {
    (yyval).trailer_type = FUNCTION_CALL;
    (yyval).sz = 0;
}
#line 3765 "parser.tab.c"
    break;

  case 146: /* call_trailer: LEFTBRACKET arglist RIGHTBRACKET  */
#line 1533 "parser.y"
                                   {
    yyval = yyvsp[-1];
    (yyval).trailer_type = FUNCTION_CALL;
}
#line 3774 "parser.tab.c"
    break;

  case 147: /* index_trailer: LEFTSQUAREBRACKET test RIGHTSQUAREBRACKET  */
#line 1538 "parser.y"
                                                          {
    yyval = yyvsp[-1];
    yyval.trailer_type = LIST_ACCESS;
    if ((yyvsp[-1]).type != Int_type){
        cerr << "Error! Only Integer Type acceped in [] at line no. "<<yylineno<<endl;
        exit(1);
    }
    
}
#line 3788 "parser.tab.c"
    break;

  case 148: /* dot_trailer: DOT NAME  */
#line 1548 "parser.y"
                       {
    yyval = yyvsp[0];
}
#line 3796 "parser.tab.c"
    break;

  case 149: /* testlist: testlist_list COMMA  */
#line 1568 "parser.y"
                              {
    yyval = yyvsp[-1];
}
#line 3804 "parser.tab.c"
    break;

  case 150: /* testlist: testlist_list  */
#line 1571 "parser.y"
                {    
    yyval = yyvsp[0];
}
#line 3812 "parser.tab.c"
    break;

  case 151: /* testlist_list: test  */
#line 1575 "parser.y"
                     {
    yyval = yyvsp[0];
    (yyval).args_list.push_back({(yyvsp[0]).lex, (yyvsp[0]).type});
}
#line 3821 "parser.tab.c"
    break;

  case 152: /* testlist_list: testlist_list COMMA test  */
#line 1580 "parser.y"
                           {
    if ((yyvsp[-2]).type != (yyvsp[0]).type){
        cerr << "Error! Type mismatch at line no: "<<yylineno<<"\n";
    }
    (yyval)._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC;
    (yyval).type = (yyvsp[-2]).type;
    (yyval).args_list.push_back({(yyvsp[0]).lex, (yyvsp[0]).type});
}
#line 3834 "parser.tab.c"
    break;

  case 153: /* $@3: %empty  */
#line 1590 "parser.y"
{
    ST *newST = new ST;
    newST->parentST = CurrST;
    newST->type = CLASS_ST;
    CurrST = newST;
    CurrST->current_Class = new Class;
    CurrST->current_Class->name = (yyvsp[-1]).lex; 
    CurrST->current_Class->classST = CurrST;
    cls_ST[(yyvsp[-1]).lex] = CurrST;
}
#line 3849 "parser.tab.c"
    break;

  case 154: /* classdef: CLASS NAME COLON $@3 suite  */
#line 1600 "parser.y"
      {
    ST* oldST = CurrST;
    auto cls = CurrST->current_Class;
    CurrST = CurrST->parentST;
    sz[(yyvsp[-3]).lex] = cls->classST->offset;
    cls->parent = NULL;
    auto entry = new STEntry;
    entry->lex = (yyvsp[-3]).lex;
    entry->cls = cls;
    entry->lineno = (yyvsp[-4]).lineno;
    entry->func = NULL;
    CurrST->insert((yyvsp[-3]).lex, entry);
    (yyval)._3AC = (yyvsp[0])._3AC;

}
#line 3869 "parser.tab.c"
    break;

  case 155: /* $@4: %empty  */
#line 1616 "parser.y"
{
    ST *newST = new ST;
    newST->parentST = CurrST;
    newST->type = CLASS_ST;
    CurrST = newST;
    CurrST->current_Class = new Class;
    CurrST->current_Class->name = (yyvsp[-3]).lex; 
    CurrST->current_Class->classST = CurrST;
    cls_ST[(yyvsp[-3]).lex] = CurrST;
}
#line 3884 "parser.tab.c"
    break;

  case 156: /* classdef: CLASS NAME LEFTBRACKET RIGHTBRACKET COLON $@4 suite  */
#line 1626 "parser.y"
      {
    ST* oldST = CurrST;
    CurrST = CurrST->parentST;
    auto cls = oldST->current_Class;
    cls->parent = NULL;
    cls->classST = oldST;
    auto entry = new STEntry;
    entry->lex = (yyvsp[-5]).lex;
    entry->cls = cls;
    entry->lineno = (yyvsp[-6]).lineno;
    CurrST->insert((yyvsp[-5]).lex, entry);
}
#line 3901 "parser.tab.c"
    break;

  case 157: /* $@5: %empty  */
#line 1639 "parser.y"
                              {

    ST *newST = new ST;
    newST->parentST = CurrST;
    newST->type = CLASS_ST;
    CurrST = newST;
    CurrST->current_Class = new Class;
    CurrST->current_Class->name = (yyvsp[-2]).lex; 
    CurrST->current_Class->classST = CurrST;
    cls_ST[(yyvsp[-2]).lex] = CurrST;
    auto STentry = CurrST->lookup((yyvsp[0]).lex);
    CurrST->current_Class->parent = STentry->cls;
    CurrST->offset = STentry->cls->classST->offset;

}
#line 3921 "parser.tab.c"
    break;

  case 158: /* classdef: CLASS NAME LEFTBRACKET NAME $@5 RIGHTBRACKET COLON suite  */
#line 1653 "parser.y"
                           {
    ST* oldST = CurrST;
    auto cls = CurrST->current_Class;
    CurrST = CurrST->parentST;
    sz[(yyvsp[-6]).lex] = cls->classST->offset;
    cls->parent = NULL;
    auto entry = new STEntry;
    entry->lex = (yyvsp[-6]).lex;
    entry->cls = cls;
    entry->lineno = (yyvsp[-7]).lineno;
    entry->func = NULL;
    CurrST->insert((yyvsp[-6]).lex, entry);
    (yyval)._3AC = (yyvsp[0])._3AC;
}
#line 3940 "parser.tab.c"
    break;

  case 159: /* arglist: arglist_help  */
#line 1668 "parser.y"
                      {
    yyval = yyvsp[0];
}
#line 3948 "parser.tab.c"
    break;

  case 160: /* arglist: arglist_help COMMA  */
#line 1671 "parser.y"
                     {
   yyval = yyvsp[-1];
}
#line 3956 "parser.tab.c"
    break;

  case 161: /* arglist_help: argument  */
#line 1675 "parser.y"
                       {
    yyval = yyvsp[0];
    yyval.args_list.push_back({(yyvsp[0]).lex, (yyvsp[0]).type});
}
#line 3965 "parser.tab.c"
    break;

  case 162: /* arglist_help: arglist_help COMMA argument  */
#line 1679 "parser.y"
                              {
    yyval = yyvsp[-2];
    (yyval).args_list.push_back({(yyvsp[0]).lex, (yyvsp[0]).type});
    yyval._3AC = (yyvsp[-2])._3AC + (yyvsp[0])._3AC;
}
#line 3975 "parser.tab.c"
    break;

  case 163: /* arglist_help: NEWLINE INDENT stmt_help DEDENT  */
#line 1685 "parser.y"
                                  {
    // cout << "Hello\n";
    // cout << ($3)._3AC;
    // cout << CurrST->type << endl;
    yyval = yyvsp[-1];
    // cout << "suite\n";
    // cout << ($$)._3AC;
    // cout << "end\n";
}
#line 3989 "parser.tab.c"
    break;

  case 164: /* argument: test  */
#line 1695 "parser.y"
               {
    yyval = yyvsp[0];
}
#line 3997 "parser.tab.c"
    break;


#line 4001 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1731 "parser.y"

void yyerror(const char *s)
{
    cout<< "Error found at line number: "<< yylineno<< " " << "at token " << yytext << " " << s << endl;
    exit(1);
}

int main(int argc, char **argv)
{
  indent_cnt.push(0);
  auto GlobalST = new ST;
  GlobalST->parentST = NULL;
  CurrST = GlobalST;
  STEntry* name = new STEntry;
  name->lex = "__name__";
  name->type = {"str", 0};
  GlobalST->insert("__name__", name);
  yyparse();
  freopen("Global.csv", "w", stdout);
  GlobalST->print();
  freopen("3AC.txt", "w", stdout);
  string final_res = "0\t";
  res += '@';
  int num_line = 1;
  if (res[0] == '@'){
    final_res = "";
    num_line = 0;
  }
  for (int i = 0; i < res.size(); i++){
    if (res[i] == '@') {
        continue;
    }
      if (res[i] == '\n' && res [i+1] == '@'){
        final_res += "\n";
      }
      else if (res[i] == '\n'){
        final_res += "\n" + to_string(num_line) + "\t";
        num_line += 1;
      }
      else {
        final_res += res[i];
      }
  }
  cout << final_res;
  return 0;
}
