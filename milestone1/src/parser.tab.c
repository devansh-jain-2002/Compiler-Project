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

    #include<bits/stdc++.h>
    #include <fstream>

    using namespace std;
    
    void yyerror(const char * s);
    int yylex();
    extern int yylineno;
    extern FILE* yyin;
    #define YYERROR_VERBOSE 1
    int nodes = 0;
    map<int, string> node_map;
    map<int, string> node_shape;
    vector<pair<int,string> > baap, betaa;
    extern stack<int> indent_cnt;    
    string s;
    extern char* yytext;

#line 91 "parser.tab.c"

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
  YYSYMBOL_FLOATNUMBER = 4,                /* FLOATNUMBER  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_SHORT_STRING = 7,               /* SHORT_STRING  */
  YYSYMBOL_LONG_STRING = 8,                /* LONG_STRING  */
  YYSYMBOL_PLUS = 9,                       /* PLUS  */
  YYSYMBOL_MINUS = 10,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 11,                  /* MULTIPLY  */
  YYSYMBOL_EXP = 12,                       /* EXP  */
  YYSYMBOL_SLASH = 13,                     /* SLASH  */
  YYSYMBOL_DOUBLESLASH = 14,               /* DOUBLESLASH  */
  YYSYMBOL_DIVIDE = 15,                    /* DIVIDE  */
  YYSYMBOL_DIVIDEDIVIDE = 16,              /* DIVIDEDIVIDE  */
  YYSYMBOL_MOD = 17,                       /* MOD  */
  YYSYMBOL_AT = 18,                        /* AT  */
  YYSYMBOL_RIGHTSHIFT = 19,                /* RIGHTSHIFT  */
  YYSYMBOL_LEFTSHIFT = 20,                 /* LEFTSHIFT  */
  YYSYMBOL_AMPERSAND = 21,                 /* AMPERSAND  */
  YYSYMBOL_EQUAL = 22,                     /* EQUAL  */
  YYSYMBOL_NOTEQUAL = 23,                  /* NOTEQUAL  */
  YYSYMBOL_GREATER = 24,                   /* GREATER  */
  YYSYMBOL_LESS = 25,                      /* LESS  */
  YYSYMBOL_GREATEREQ = 26,                 /* GREATEREQ  */
  YYSYMBOL_LESSEQ = 27,                    /* LESSEQ  */
  YYSYMBOL_BITOR = 28,                     /* BITOR  */
  YYSYMBOL_BITXOR = 29,                    /* BITXOR  */
  YYSYMBOL_BITNOT = 30,                    /* BITNOT  */
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_PLUSEQUAL = 32,                 /* PLUSEQUAL  */
  YYSYMBOL_MINUSEQUAL = 33,                /* MINUSEQUAL  */
  YYSYMBOL_MULTIPLYEQUAL = 34,             /* MULTIPLYEQUAL  */
  YYSYMBOL_DIVIDEEQUAL = 35,               /* DIVIDEEQUAL  */
  YYSYMBOL_PERCENTEQUAL = 36,              /* PERCENTEQUAL  */
  YYSYMBOL_EXPONENTEQUAL = 37,             /* EXPONENTEQUAL  */
  YYSYMBOL_ANDEQUAL = 38,                  /* ANDEQUAL  */
  YYSYMBOL_OREQUAL = 39,                   /* OREQUAL  */
  YYSYMBOL_XOREQUAL = 40,                  /* XOREQUAL  */
  YYSYMBOL_LEFTSHIFTEQUAL = 41,            /* LEFTSHIFTEQUAL  */
  YYSYMBOL_RIGHTSHIFTEQUAL = 42,           /* RIGHTSHIFTEQUAL  */
  YYSYMBOL_COLONEQUAL = 43,                /* COLONEQUAL  */
  YYSYMBOL_LEFTBRACKET = 44,               /* LEFTBRACKET  */
  YYSYMBOL_RIGHTBRACKET = 45,              /* RIGHTBRACKET  */
  YYSYMBOL_LEFTSQUAREBRACKET = 46,         /* LEFTSQUAREBRACKET  */
  YYSYMBOL_RIGHTSQUAREBRACKET = 47,        /* RIGHTSQUAREBRACKET  */
  YYSYMBOL_LEFTCURLYBRACKET = 48,          /* LEFTCURLYBRACKET  */
  YYSYMBOL_RIGHTCURLYBRACKET = 49,         /* RIGHTCURLYBRACKET  */
  YYSYMBOL_COMMA = 50,                     /* COMMA  */
  YYSYMBOL_COLON = 51,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 52,                 /* SEMICOLON  */
  YYSYMBOL_DOT = 53,                       /* DOT  */
  YYSYMBOL_ARROW = 54,                     /* ARROW  */
  YYSYMBOL_DIVIDEDIVIDEEQUAL = 55,         /* DIVIDEDIVIDEEQUAL  */
  YYSYMBOL_ATEQUAL = 56,                   /* ATEQUAL  */
  YYSYMBOL_NAME_DUNDER = 57,               /* NAME_DUNDER  */
  YYSYMBOL_MAIN_DUNDER = 58,               /* MAIN_DUNDER  */
  YYSYMBOL_INIT_DUNDER = 59,               /* INIT_DUNDER  */
  YYSYMBOL_SPECIAL_CHAR = 60,              /* SPECIAL_CHAR  */
  YYSYMBOL_UNDERSCORE = 61,                /* UNDERSCORE  */
  YYSYMBOL_DOUBLE_QUOTE = 62,              /* DOUBLE_QUOTE  */
  YYSYMBOL_SINGLE_QUOTE = 63,              /* SINGLE_QUOTE  */
  YYSYMBOL_BACKSLASH = 64,                 /* BACKSLASH  */
  YYSYMBOL_SPACE = 65,                     /* SPACE  */
  YYSYMBOL_FALSE = 66,                     /* FALSE  */
  YYSYMBOL_AWAIT = 67,                     /* AWAIT  */
  YYSYMBOL_ELSE = 68,                      /* ELSE  */
  YYSYMBOL_IMPORT = 69,                    /* IMPORT  */
  YYSYMBOL_PASS = 70,                      /* PASS  */
  YYSYMBOL_NONE = 71,                      /* NONE  */
  YYSYMBOL_BREAK = 72,                     /* BREAK  */
  YYSYMBOL_EXCEPT = 73,                    /* EXCEPT  */
  YYSYMBOL_IN = 74,                        /* IN  */
  YYSYMBOL_RAISE = 75,                     /* RAISE  */
  YYSYMBOL_TRUE = 76,                      /* TRUE  */
  YYSYMBOL_CLASS = 77,                     /* CLASS  */
  YYSYMBOL_FINALLY = 78,                   /* FINALLY  */
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
  YYSYMBOL_YYACCEPT = 107,                 /* $accept  */
  YYSYMBOL_module = 108,                   /* module  */
  YYSYMBOL_file_input = 109,               /* file_input  */
  YYSYMBOL_funcdef = 110,                  /* funcdef  */
  YYSYMBOL_parameters = 111,               /* parameters  */
  YYSYMBOL_typedargslist = 112,            /* typedargslist  */
  YYSYMBOL_argument1 = 113,                /* argument1  */
  YYSYMBOL_tfpdef = 114,                   /* tfpdef  */
  YYSYMBOL_stmt = 115,                     /* stmt  */
  YYSYMBOL_simple_stmt = 116,              /* simple_stmt  */
  YYSYMBOL_small_stmt_help = 117,          /* small_stmt_help  */
  YYSYMBOL_small_stmt = 118,               /* small_stmt  */
  YYSYMBOL_expr_stmt = 119,                /* expr_stmt  */
  YYSYMBOL_assign_help = 120,              /* assign_help  */
  YYSYMBOL_augassign = 121,                /* augassign  */
  YYSYMBOL_flow_stmt = 122,                /* flow_stmt  */
  YYSYMBOL_break_stmt = 123,               /* break_stmt  */
  YYSYMBOL_continue_stmt = 124,            /* continue_stmt  */
  YYSYMBOL_return_stmt = 125,              /* return_stmt  */
  YYSYMBOL_global_stmt = 126,              /* global_stmt  */
  YYSYMBOL_assert_stmt = 127,              /* assert_stmt  */
  YYSYMBOL_compound_stmt = 128,            /* compound_stmt  */
  YYSYMBOL_if_stmt = 129,                  /* if_stmt  */
  YYSYMBOL_if_stmt_help = 130,             /* if_stmt_help  */
  YYSYMBOL_while_stmt = 131,               /* while_stmt  */
  YYSYMBOL_for_stmt = 132,                 /* for_stmt  */
  YYSYMBOL_suite = 133,                    /* suite  */
  YYSYMBOL_stmt_help = 134,                /* stmt_help  */
  YYSYMBOL_test = 135,                     /* test  */
  YYSYMBOL_or_test = 136,                  /* or_test  */
  YYSYMBOL_and_test = 137,                 /* and_test  */
  YYSYMBOL_not_test = 138,                 /* not_test  */
  YYSYMBOL_comparison = 139,               /* comparison  */
  YYSYMBOL_comp_op = 140,                  /* comp_op  */
  YYSYMBOL_expr = 141,                     /* expr  */
  YYSYMBOL_xor_expr = 142,                 /* xor_expr  */
  YYSYMBOL_and_expr = 143,                 /* and_expr  */
  YYSYMBOL_shift_expr = 144,               /* shift_expr  */
  YYSYMBOL_arith_expr = 145,               /* arith_expr  */
  YYSYMBOL_term = 146,                     /* term  */
  YYSYMBOL_factor = 147,                   /* factor  */
  YYSYMBOL_power = 148,                    /* power  */
  YYSYMBOL_atom_expr = 149,                /* atom_expr  */
  YYSYMBOL_atom = 150,                     /* atom  */
  YYSYMBOL_string_help = 151,              /* string_help  */
  YYSYMBOL_trailer = 152,                  /* trailer  */
  YYSYMBOL_exprlist = 153,                 /* exprlist  */
  YYSYMBOL_exprlist_help = 154,            /* exprlist_help  */
  YYSYMBOL_testlist = 155,                 /* testlist  */
  YYSYMBOL_testlist_list = 156,            /* testlist_list  */
  YYSYMBOL_classdef = 157,                 /* classdef  */
  YYSYMBOL_arglist = 158,                  /* arglist  */
  YYSYMBOL_arglist_help = 159,             /* arglist_help  */
  YYSYMBOL_func_body_suite = 160,          /* func_body_suite  */
  YYSYMBOL_argument = 161,                 /* argument  */
  YYSYMBOL_comp_iter = 162,                /* comp_iter  */
  YYSYMBOL_comp_for = 163,                 /* comp_for  */
  YYSYMBOL_comp_if = 164                   /* comp_if  */
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
#define YYFINAL  81
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   639

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  266

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   361


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
     105,   106
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   206,   206,   214,   217,   226,   229,   234,   265,   292,
     309,   325,   328,   345,   348,   358,   367,   386,   389,   395,
     409,   413,   416,   431,   434,   437,   440,   444,   458,   481,
     491,   494,   504,   507,   517,   525,   532,   539,   546,   554,
     561,   568,   575,   582,   590,   598,   605,   614,   617,   620,
     624,   633,   641,   653,   660,   676,   697,   717,   730,   733,
     736,   739,   742,   747,   780,   800,   832,   851,   871,   894,
     913,   947,   986,  1014,  1018,  1022,  1025,  1035,  1038,  1060,
    1063,  1079,  1083,  1098,  1111,  1115,  1119,  1127,  1134,  1140,
    1146,  1152,  1159,  1165,  1171,  1186,  1192,  1208,  1212,  1222,
    1226,  1236,  1240,  1255,  1259,  1270,  1281,  1285,  1293,  1302,
    1306,  1314,  1323,  1332,  1341,  1351,  1355,  1362,  1369,  1377,
    1381,  1391,  1395,  1406,  1424,  1440,  1457,  1472,  1487,  1496,
    1504,  1508,  1514,  1520,  1527,  1540,  1548,  1564,  1582,  1600,
    1617,  1620,  1633,  1636,  1652,  1664,  1668,  1672,  1690,  1713,
    1746,  1784,  1787,  1802,  1805,  1820,  1823,  1839,  1844,  1853,
    1862,  1865,  1869,  1889,  1910,  1923
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
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER",
  "FLOATNUMBER", "NUMBER", "STRING", "SHORT_STRING", "LONG_STRING", "PLUS",
  "MINUS", "MULTIPLY", "EXP", "SLASH", "DOUBLESLASH", "DIVIDE",
  "DIVIDEDIVIDE", "MOD", "AT", "RIGHTSHIFT", "LEFTSHIFT", "AMPERSAND",
  "EQUAL", "NOTEQUAL", "GREATER", "LESS", "GREATEREQ", "LESSEQ", "BITOR",
  "BITXOR", "BITNOT", "ASSIGN", "PLUSEQUAL", "MINUSEQUAL", "MULTIPLYEQUAL",
  "DIVIDEEQUAL", "PERCENTEQUAL", "EXPONENTEQUAL", "ANDEQUAL", "OREQUAL",
  "XOREQUAL", "LEFTSHIFTEQUAL", "RIGHTSHIFTEQUAL", "COLONEQUAL",
  "LEFTBRACKET", "RIGHTBRACKET", "LEFTSQUAREBRACKET", "RIGHTSQUAREBRACKET",
  "LEFTCURLYBRACKET", "RIGHTCURLYBRACKET", "COMMA", "COLON", "SEMICOLON",
  "DOT", "ARROW", "DIVIDEDIVIDEEQUAL", "ATEQUAL", "NAME_DUNDER",
  "MAIN_DUNDER", "INIT_DUNDER", "SPECIAL_CHAR", "UNDERSCORE",
  "DOUBLE_QUOTE", "SINGLE_QUOTE", "BACKSLASH", "SPACE", "FALSE", "AWAIT",
  "ELSE", "IMPORT", "PASS", "NONE", "BREAK", "EXCEPT", "IN", "RAISE",
  "TRUE", "CLASS", "FINALLY", "IS", "RETURN", "AND", "CONTINUE", "FOR",
  "LAMBDA", "TRY", "AS", "DEF", "FROM", "NONLOCAL", "WHILE", "ASSERT",
  "DEL", "GLOBAL", "NOT", "WITH", "ASYNC", "ELIF", "IF", "OR", "YIELD",
  "NAME", "COMMENT", "NEWLINE", "INDENT", "DEDENT", "ELLIPSIS", "$accept",
  "module", "file_input", "funcdef", "parameters", "typedargslist",
  "argument1", "tfpdef", "stmt", "simple_stmt", "small_stmt_help",
  "small_stmt", "expr_stmt", "assign_help", "augassign", "flow_stmt",
  "break_stmt", "continue_stmt", "return_stmt", "global_stmt",
  "assert_stmt", "compound_stmt", "if_stmt", "if_stmt_help", "while_stmt",
  "for_stmt", "suite", "stmt_help", "test", "or_test", "and_test",
  "not_test", "comparison", "comp_op", "expr", "xor_expr", "and_expr",
  "shift_expr", "arith_expr", "term", "factor", "power", "atom_expr",
  "atom", "string_help", "trailer", "exprlist", "exprlist_help",
  "testlist", "testlist_list", "classdef", "arglist", "arglist_help",
  "func_body_suite", "argument", "comp_iter", "comp_for", "comp_if", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-191)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     169,  -191,  -191,    18,    18,    18,   138,   449,   -30,  -191,
    -191,  -191,  -191,   -69,   512,  -191,    18,   -51,   512,   512,
     -49,   512,   512,  -191,  -191,    54,   238,  -191,  -191,  -191,
     -40,  -191,  -191,  -191,  -191,  -191,  -191,     8,  -191,  -191,
    -191,  -191,  -191,  -191,   -68,   -20,  -191,   131,    44,    52,
      64,    23,    58,   117,  -191,  -191,    27,  -191,    80,   583,
      38,  -191,  -191,  -191,  -191,  -191,    47,  -191,    48,  -191,
     -15,  -191,    44,    24,    50,    57,    55,    53,  -191,  -191,
      56,  -191,  -191,  -191,    11,  -191,     9,   512,   512,   512,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,    17,    42,    18,
      18,    18,    18,    18,    18,    18,    18,    18,    18,    18,
      18,    18,    18,   460,   512,    22,  -191,  -191,   512,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,
     512,  -191,  -191,   512,   512,  -191,  -191,   493,   289,   512,
      18,   -36,     2,   289,   512,   289,  -191,  -191,  -191,   -54,
     -20,  -191,  -191,  -191,    44,    52,    64,    23,    58,    58,
     117,   117,  -191,  -191,  -191,  -191,  -191,  -191,  -191,   -23,
      73,    75,  -191,    79,  -191,  -191,    98,   114,  -191,  -191,
      95,   104,    46,  -191,  -191,   100,    44,  -191,   101,    -1,
    -191,   128,   340,   512,    92,  -191,   -50,   512,   512,    18,
    -191,  -191,   512,  -191,   512,   512,   289,   111,   391,   289,
     512,  -191,    62,   512,    60,  -191,  -191,   115,   116,   118,
     512,    97,  -191,  -191,    96,  -191,  -191,  -191,  -191,   289,
     391,    66,   105,  -191,  -191,  -191,   391,   340,   289,   289,
     121,   136,   512,  -191,  -191,  -191,   137,    84,  -191,  -191,
    -191,   289,   289,   -61,   289,  -191,    94,  -191,   512,  -191,
    -191,  -191,  -191,  -191,   -61,  -191
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   129,   135,     0,     0,     0,     0,     0,     0,   133,
     131,    50,   132,     0,    53,    51,     0,     0,     0,     0,
       0,     0,     0,   128,     5,     0,     2,    61,     6,    17,
       0,    21,    23,    24,    47,    48,    49,    25,    26,    18,
      58,    59,    60,   146,    77,    79,    81,    84,    85,    97,
      99,   101,   103,   106,   109,   115,   119,   121,   130,    30,
     145,    62,   116,   117,   118,   124,     0,   126,     0,   127,
       0,    52,   142,     0,   140,     0,     0,    57,    54,    83,
       0,     1,     3,     4,     0,    20,     0,     0,     0,     0,
      87,    92,    89,    88,    90,    91,    95,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,   134,     0,    34,
      35,    36,    38,    39,    45,    40,    41,    42,    43,    44,
       0,    46,    37,     0,   144,   123,   125,     0,     0,     0,
     141,     0,     0,     0,     0,     0,    19,    22,    55,     0,
      80,    82,    94,    96,    86,    98,   100,   102,   105,   104,
     107,   108,   110,   112,   114,   113,   111,   120,   136,   157,
       0,   151,   153,     0,   139,    31,    32,    27,    29,   147,
       0,     0,     0,    73,   148,     0,   143,    10,    15,     0,
      11,    13,     0,     0,    69,    56,    66,     0,     0,     0,
     159,   137,   152,   138,     0,     0,     0,     0,     0,     0,
       0,     9,     0,     0,     0,   155,     8,     0,     0,     0,
       0,    64,    78,   158,     0,   154,    33,    28,   149,     0,
      75,     0,    72,    16,    12,    14,     0,     0,     0,     0,
       0,     0,     0,   150,    76,    74,     0,     0,     7,    70,
      65,     0,     0,   162,     0,   156,    67,    63,     0,   163,
     160,   161,    71,    68,   164,   165
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -191,  -191,  -191,  -191,  -191,  -191,   -18,  -191,    25,     0,
    -191,   113,  -191,    -6,  -191,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,   -56,  -191,  -191,  -130,  -190,   -17,   -81,
     107,   -11,  -191,  -191,    -9,   106,   110,   119,   -34,   -31,
      30,  -191,  -191,  -191,  -191,  -191,    13,  -191,    -3,  -191,
    -191,    70,  -191,   -21,    16,   -45,    51,  -191
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    25,    26,    27,   142,   189,   190,   191,   230,   183,
      30,    31,    32,   175,   133,    33,    34,    35,    36,    37,
      38,    39,    40,   221,    41,    42,   184,   231,    43,    44,
      45,    46,    47,    99,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   116,    73,    74,    59,    60,
      61,   170,   171,   216,   172,   259,   260,   261
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    76,    77,    66,    68,    80,   149,    72,   198,   187,
      79,    71,    84,   194,   197,   196,     1,     2,   219,    69,
       3,     4,   199,     1,     2,    28,    29,     3,     4,   137,
      87,    88,    70,    62,    63,    64,   138,   258,    88,   112,
     244,     5,   103,   104,   211,    88,   247,   220,     5,   212,
      75,    83,    78,   192,    81,     6,   193,     7,    86,     8,
     199,    89,     6,    85,     7,   188,     8,   105,   106,   158,
     159,   113,   100,   114,   160,   161,   228,     9,   151,   232,
     115,   101,    10,    11,     9,   102,   117,    12,   134,    10,
     154,    14,   135,    15,    12,   136,   169,   173,   139,   243,
     140,   141,    19,   144,    20,    21,   143,   145,   249,   250,
     148,   152,    23,   177,   146,   176,   153,   179,   201,    23,
     169,   256,   257,   174,   262,   202,   203,   195,   107,   204,
     178,   186,   108,   109,   110,   111,   185,   162,   163,   164,
     165,   166,   167,     1,     2,   205,   206,     3,     4,   207,
     208,   209,   210,    90,    91,    92,    93,    94,    95,   213,
     218,   253,   229,   188,   236,   241,   237,   238,     5,   239,
     242,   245,   251,   246,     1,     2,   217,   264,     3,     4,
     222,   223,     6,    65,     7,   169,     8,   252,   254,   255,
      72,   220,   215,   233,   234,   150,   235,   147,   226,     5,
     263,   176,   227,   240,     9,    96,   155,   181,    29,    10,
      97,   156,   224,     6,    12,     7,   248,     8,   225,   265,
     200,   157,     0,     0,     0,    98,     0,     0,     0,     0,
      29,     0,    21,     0,     0,     9,    29,   215,     0,    23,
      10,    11,     0,     1,     2,    12,    13,     3,     4,    14,
       0,    15,    16,     0,     0,     0,    17,     0,     0,    18,
      19,     0,    20,    21,     0,     0,     0,    22,     5,     0,
      23,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     0,     7,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,     0,     3,     4,
       0,     0,     0,     0,     9,     0,     0,     0,     0,    10,
      11,     0,     0,     0,    12,    13,     0,     0,    14,     5,
      15,    16,     0,     0,     0,    17,     0,     0,    18,    19,
       0,    20,    21,     6,     0,     7,    22,     8,     0,    23,
       0,    82,     0,     0,     0,     1,     2,     0,     0,     3,
       4,     0,     0,     0,     0,     9,     0,     0,     0,     0,
      10,    11,     0,     0,     0,    12,     0,     0,     0,    14,
       5,    15,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,    20,    21,     6,     0,     7,     0,     8,     0,
      23,     0,   182,     0,     0,     0,     1,     2,     0,     0,
       3,     4,     0,     0,     0,     0,     9,     0,     0,     0,
       0,    10,    11,     0,     0,     0,    12,     0,     0,     0,
      14,     5,    15,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,    20,    21,     6,     0,     7,     0,     8,
       0,    23,     0,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,     9,     3,     4,
       0,     0,    10,    11,     0,     1,     2,    12,    13,     3,
       4,    14,     0,    15,    16,     0,     0,     0,    17,     5,
       0,    18,    19,     0,    20,    21,     0,     0,     0,    22,
       5,     0,    23,     6,     0,     7,    67,     8,     1,     2,
       0,     0,     3,     4,     6,   168,     7,     0,     8,     0,
       0,     0,     0,     0,     0,     9,     0,     1,     2,     0,
      10,     3,     4,     5,     0,    12,     9,     0,     0,     0,
       0,    10,     0,     0,     0,     0,    12,     6,   180,     7,
       0,     8,     5,    21,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,    21,     0,     6,     0,     7,     9,
       8,    23,     0,     0,    10,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     9,     0,
       0,     0,     0,    10,     0,     0,     0,    21,    12,     0,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,    23,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,   130,     0,     0,     0,   131,   132
};

static const yytype_int16 yycheck[] =
{
       0,    18,    19,     6,     7,    22,    87,    16,    31,    45,
      21,    14,    52,   143,    68,   145,     5,     6,    68,    49,
       9,    10,    83,     5,     6,     0,    26,     9,    10,    44,
      98,    99,   101,     3,     4,     5,    51,    98,    99,    12,
     230,    30,    19,    20,    45,    99,   236,    97,    30,    50,
     101,    26,   101,    51,     0,    44,    54,    46,    50,    48,
      83,    81,    44,   103,    46,   101,    48,     9,    10,   103,
     104,    44,    28,    46,   105,   106,   206,    66,    89,   209,
      53,    29,    71,    72,    66,    21,     6,    76,    50,    71,
      99,    80,    45,    82,    76,    47,   113,   114,    74,   229,
      50,    44,    91,    50,    93,    94,    51,    51,   238,   239,
     101,    94,   101,   130,   103,   118,    74,   134,    45,   101,
     137,   251,   252,   101,   254,    50,    47,   144,    11,    31,
     133,   140,    15,    16,    17,    18,   139,   107,   108,   109,
     110,   111,   112,     5,     6,    31,    51,     9,    10,    45,
     104,    51,    51,    22,    23,    24,    25,    26,    27,    31,
      68,   242,    51,   101,   104,    68,    51,    51,    30,    51,
      74,   105,    51,    68,     5,     6,   193,   258,     9,    10,
     197,   198,    44,    45,    46,   202,    48,    51,    51,   105,
     199,    97,   192,   210,   212,    88,   213,    84,   204,    30,
     256,   204,   205,   220,    66,    74,   100,   137,   208,    71,
      79,   101,   199,    44,    76,    46,   237,    48,   202,   264,
     169,   102,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,
     230,    -1,    94,    -1,    -1,    66,   236,   237,    -1,   101,
      71,    72,    -1,     5,     6,    76,    77,     9,    10,    80,
      -1,    82,    83,    -1,    -1,    -1,    87,    -1,    -1,    90,
      91,    -1,    93,    94,    -1,    -1,    -1,    98,    30,    -1,
     101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    46,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,    -1,    -1,     9,    10,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    -1,    76,    77,    -1,    -1,    80,    30,
      82,    83,    -1,    -1,    -1,    87,    -1,    -1,    90,    91,
      -1,    93,    94,    44,    -1,    46,    98,    48,    -1,   101,
      -1,   103,    -1,    -1,    -1,     5,     6,    -1,    -1,     9,
      10,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,
      30,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    93,    94,    44,    -1,    46,    -1,    48,    -1,
     101,    -1,   103,    -1,    -1,    -1,     5,     6,    -1,    -1,
       9,    10,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    30,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    93,    94,    44,    -1,    46,    -1,    48,
      -1,   101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,    -1,    66,     9,    10,
      -1,    -1,    71,    72,    -1,     5,     6,    76,    77,     9,
      10,    80,    -1,    82,    83,    -1,    -1,    -1,    87,    30,
      -1,    90,    91,    -1,    93,    94,    -1,    -1,    -1,    98,
      30,    -1,   101,    44,    -1,    46,    47,    48,     5,     6,
      -1,    -1,     9,    10,    44,    45,    46,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    -1,     5,     6,    -1,
      71,     9,    10,    30,    -1,    76,    66,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    76,    44,    45,    46,
      -1,    48,    30,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    -1,    94,    -1,    44,    -1,    46,    66,
      48,   101,    -1,    -1,    71,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    94,    76,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,    56
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     9,    10,    30,    44,    46,    48,    66,
      71,    72,    76,    77,    80,    82,    83,    87,    90,    91,
      93,    94,    98,   101,   103,   108,   109,   110,   115,   116,
     117,   118,   119,   122,   123,   124,   125,   126,   127,   128,
     129,   131,   132,   135,   136,   137,   138,   139,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   155,
     156,   157,   147,   147,   147,    45,   155,    47,   155,    49,
     101,   155,   141,   153,   154,   101,   135,   135,   101,   138,
     135,     0,   103,   115,    52,   103,    50,    98,    99,    81,
      22,    23,    24,    25,    26,    27,    74,    79,    94,   140,
      28,    29,    21,    19,    20,     9,    10,    11,    15,    16,
      17,    18,    12,    44,    46,    53,   152,     6,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      51,    55,    56,   121,    50,    45,    47,    44,    51,    74,
      50,    44,   111,    51,    50,    51,   103,   118,   101,   136,
     137,   138,    94,    74,   141,   142,   143,   144,   145,   145,
     146,   146,   147,   147,   147,   147,   147,   147,    45,   135,
     158,   159,   161,   135,   101,   120,   155,   135,   155,   135,
      45,   158,   103,   116,   133,   155,   141,    45,   101,   112,
     113,   114,    51,    54,   133,   135,   133,    68,    31,    83,
     163,    45,    50,    47,    31,    31,    51,    45,   104,    51,
      51,    45,    50,    31,   103,   116,   160,   135,    68,    68,
      97,   130,   135,   135,   153,   161,   120,   155,   133,    51,
     115,   134,   133,   135,   113,   135,   104,    51,    51,    51,
     135,    68,    74,   133,   134,   105,    68,   134,   160,   133,
     133,    51,    51,   136,    51,   105,   133,   133,    98,   162,
     163,   164,   133,   130,   136,   162
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   109,   109,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   118,   118,   119,   119,   119,
     119,   119,   120,   120,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   122,   122,   122,
     123,   124,   125,   125,   126,   126,   127,   127,   128,   128,
     128,   128,   128,   129,   129,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   134,   134,   135,   135,   136,
     136,   137,   137,   138,   138,   139,   139,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   141,   141,   142,
     142,   143,   143,   144,   144,   144,   145,   145,   145,   146,
     146,   146,   146,   146,   146,   147,   147,   147,   147,   148,
     148,   149,   149,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   151,   151,   152,   152,   152,   152,
     153,   153,   154,   154,   155,   155,   156,   156,   157,   157,
     157,   158,   158,   159,   159,   160,   160,   161,   161,   161,
     162,   162,   163,   163,   164,   164
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     7,     5,     3,
       2,     1,     3,     1,     3,     1,     3,     1,     1,     3,
       2,     1,     3,     1,     1,     1,     1,     3,     5,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     3,     4,     2,     1,     1,
       1,     1,     1,     8,     5,     7,     4,     4,     5,     4,
       7,     9,     6,     1,     4,     1,     2,     1,     5,     1,
       3,     1,     3,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     3,     1,     2,     2,     2,     1,
       3,     1,     2,     3,     2,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     3,     3,     2,
       1,     2,     1,     3,     2,     1,     1,     3,     4,     6,
       7,     1,     2,     1,     3,     1,     4,     1,     3,     2,
       1,     1,     4,     5,     2,     3
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
#line 206 "parser.y"
                   {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "INPUT";
    node_shape[(yyval.num)] = "oval";

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
}
#line 1804 "parser.tab.c"
    break;

  case 3: /* file_input: file_input NEWLINE  */
#line 214 "parser.y"
                                {
    (yyval.num) = (yyvsp[-1].num);
}
#line 1812 "parser.tab.c"
    break;

  case 4: /* file_input: file_input stmt  */
#line 217 "parser.y"
                  {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "Statements";
    node_shape[(yyval.num)] = "oval";

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 1826 "parser.tab.c"
    break;

  case 5: /* file_input: NEWLINE  */
#line 226 "parser.y"
          {
    
}
#line 1834 "parser.tab.c"
    break;

  case 6: /* file_input: stmt  */
#line 229 "parser.y"
       {
    (yyval.num) = (yyvsp[0].num);
}
#line 1842 "parser.tab.c"
    break;

  case 7: /* funcdef: DEF NAME parameters ARROW test COLON func_body_suite  */
#line 234 "parser.y"
                                                              {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "funcdef";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-6].tok)).n = nodes++;
    node_map[((yyvsp[-6].tok)).n] = "KEYWORD(def)";
    node_shape[((yyvsp[-6].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-6].tok)).n,node_map[((yyvsp[-6].tok)).n]));

    ((yyvsp[-5].tok)).n = nodes++;
    string s = "NAME (" + string(((yyvsp[-5].tok)).lex) + ")";
    node_map[((yyvsp[-5].tok)).n] = s;
    node_shape[((yyvsp[-5].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)]));betaa.push_back(make_pair(((yyvsp[-5].tok)).n,node_map[((yyvsp[-5].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-4].num),node_map[(yyvsp[-4].num)]));

    ((yyvsp[-3].tok)).n = nodes++;
    node_map[((yyvsp[-3].tok)).n] = "DELIMITER(->)";
    node_shape[((yyvsp[-3].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-3].tok)).n,node_map[((yyvsp[-3].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num),node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 1878 "parser.tab.c"
    break;

  case 8: /* funcdef: DEF NAME parameters COLON func_body_suite  */
#line 265 "parser.y"
                                            {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "funcdef";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-4].tok)).n = nodes++;
    node_map[((yyvsp[-4].tok)).n] = "KEYWORD(def)";
    node_shape[((yyvsp[-4].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-4].tok)).n,node_map[((yyvsp[-4].tok)).n]));

    ((yyvsp[-3].tok)).n = nodes++;
    string s = "NAME (" + string(((yyvsp[-3].tok)).lex) + ")";
    node_map[((yyvsp[-3].tok)).n] = s;
    node_shape[((yyvsp[-3].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)]));betaa.push_back(make_pair(((yyvsp[-3].tok)).n,node_map[((yyvsp[-3].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num),node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));

}
#line 1908 "parser.tab.c"
    break;

  case 9: /* parameters: LEFTBRACKET typedargslist RIGHTBRACKET  */
#line 292 "parser.y"
                                                   {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "parameters";
    node_shape[(yyval.num)] = "oval";
    
    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "DELIMITER(()";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n,node_map[((yyvsp[-2].tok)).n]));
      
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num),node_map[(yyvsp[-1].num)]));  
    
    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "DELIMITER())";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));
}
#line 1930 "parser.tab.c"
    break;

  case 10: /* parameters: LEFTBRACKET RIGHTBRACKET  */
#line 309 "parser.y"
                           {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "parameters";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(()";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));
    
    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "DELIMITER())";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));
}
#line 1950 "parser.tab.c"
    break;

  case 11: /* typedargslist: argument1  */
#line 325 "parser.y"
                          {
    (yyval.num) = (yyvsp[0].num);
}
#line 1958 "parser.tab.c"
    break;

  case 12: /* typedargslist: typedargslist COMMA argument1  */
#line 328 "parser.y"
                                {

    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "typedargslist";
    node_shape[(yyval.num)] = "oval";
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(,)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));

}
#line 1979 "parser.tab.c"
    break;

  case 13: /* argument1: tfpdef  */
#line 345 "parser.y"
                   {
    (yyval.num) = (yyvsp[0].num);
}
#line 1987 "parser.tab.c"
    break;

  case 14: /* argument1: tfpdef ASSIGN test  */
#line 348 "parser.y"
                     {
    
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(=)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 2001 "parser.tab.c"
    break;

  case 15: /* tfpdef: NAME  */
#line 358 "parser.y"
             {

    ((yyvsp[0].tok)).n = nodes++;
    string s = "NAME (" + string(((yyvsp[0].tok)).lex) + ")";
    node_map[((yyvsp[0].tok)).n] = s;
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;

}
#line 2015 "parser.tab.c"
    break;

  case 16: /* tfpdef: NAME COLON test  */
#line 367 "parser.y"
                  {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "atom";
    node_shape[(yyval.num)] = "oval";
    
    ((yyvsp[-2].tok)).n = nodes++;
    string s = "NAME (" + string(((yyvsp[-2].tok)).lex) + ")";
    node_map[((yyvsp[-2].tok)).n] = s;
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n,node_map[((yyvsp[-2].tok)).n]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 2038 "parser.tab.c"
    break;

  case 17: /* stmt: simple_stmt  */
#line 386 "parser.y"
                  {
    (yyval.num) = (yyvsp[0].num);
}
#line 2046 "parser.tab.c"
    break;

  case 18: /* stmt: compound_stmt  */
#line 389 "parser.y"
                {
    (yyval.num) = (yyvsp[0].num);;
}
#line 2054 "parser.tab.c"
    break;

  case 19: /* simple_stmt: small_stmt_help SEMICOLON NEWLINE  */
#line 395 "parser.y"
                                                {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "stmt";
    node_shape[(yyval.num)] = "oval";
    

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(;)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));

}
#line 2073 "parser.tab.c"
    break;

  case 20: /* simple_stmt: small_stmt_help NEWLINE  */
#line 409 "parser.y"
                          {
    (yyval.num) = (yyvsp[-1].num);
}
#line 2081 "parser.tab.c"
    break;

  case 21: /* small_stmt_help: small_stmt  */
#line 413 "parser.y"
                             {
    (yyval.num) = (yyvsp[0].num);
}
#line 2089 "parser.tab.c"
    break;

  case 22: /* small_stmt_help: small_stmt_help SEMICOLON small_stmt  */
#line 416 "parser.y"
                                       {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "stmt_block";
    node_shape[(yyval.num)] = "oval";
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(;)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 2108 "parser.tab.c"
    break;

  case 23: /* small_stmt: expr_stmt  */
#line 431 "parser.y"
                      {
    (yyval.num) = (yyvsp[0].num);
}
#line 2116 "parser.tab.c"
    break;

  case 24: /* small_stmt: flow_stmt  */
#line 434 "parser.y"
            {
    (yyval.num) = (yyvsp[0].num);
}
#line 2124 "parser.tab.c"
    break;

  case 25: /* small_stmt: global_stmt  */
#line 437 "parser.y"
              {
    (yyval.num) = (yyvsp[0].num);
}
#line 2132 "parser.tab.c"
    break;

  case 26: /* small_stmt: assert_stmt  */
#line 440 "parser.y"
              {
    (yyval.num) = (yyvsp[0].num);
}
#line 2140 "parser.tab.c"
    break;

  case 27: /* expr_stmt: testlist COLON test  */
#line 444 "parser.y"
                               {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "expr_stmt";
    node_shape[(yyval.num)] = "oval";
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 2159 "parser.tab.c"
    break;

  case 28: /* expr_stmt: testlist COLON test ASSIGN testlist  */
#line 459 "parser.y"
{
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "expr_stmt";
    node_shape[(yyval.num)] = "oval";
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-4].num), node_map[(yyvsp[-4].num)]));

    ((yyvsp[-3].tok)).n = nodes++;
    node_map[((yyvsp[-3].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-3].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-3].tok)).n,node_map[((yyvsp[-3].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num),node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(=)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
    
}
#line 2186 "parser.tab.c"
    break;

  case 29: /* expr_stmt: testlist augassign testlist  */
#line 481 "parser.y"
                              {
    (yyval.num) = (yyvsp[-1].num);
    node_map[(yyval.num)] = node_map[(yyvsp[-1].num)];
    node_shape[(yyval.num)] = node_shape[(yyvsp[-1].num)];
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
    
}
#line 2201 "parser.tab.c"
    break;

  case 30: /* expr_stmt: testlist  */
#line 491 "parser.y"
           {
    (yyval.num) = (yyvsp[0].num);
}
#line 2209 "parser.tab.c"
    break;

  case 31: /* expr_stmt: testlist ASSIGN assign_help  */
#line 494 "parser.y"
                              {
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(=)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 2223 "parser.tab.c"
    break;

  case 32: /* assign_help: testlist  */
#line 504 "parser.y"
                        {
    (yyval.num) = (yyvsp[0].num);
}
#line 2231 "parser.tab.c"
    break;

  case 33: /* assign_help: testlist ASSIGN assign_help  */
#line 507 "parser.y"
                              {
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(=)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 2245 "parser.tab.c"
    break;

  case 34: /* augassign: PLUSEQUAL  */
#line 517 "parser.y"
                     {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(+=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
    
}
#line 2258 "parser.tab.c"
    break;

  case 35: /* augassign: MINUSEQUAL  */
#line 525 "parser.y"
             {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(-=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 2270 "parser.tab.c"
    break;

  case 36: /* augassign: MULTIPLYEQUAL  */
#line 532 "parser.y"
                {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(*=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 2282 "parser.tab.c"
    break;

  case 37: /* augassign: ATEQUAL  */
#line 539 "parser.y"
          {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "DELIMTER(@=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 2294 "parser.tab.c"
    break;

  case 38: /* augassign: DIVIDEEQUAL  */
#line 546 "parser.y"
              {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(/=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
    
}
#line 2307 "parser.tab.c"
    break;

  case 39: /* augassign: PERCENTEQUAL  */
#line 554 "parser.y"
               {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(%=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 2319 "parser.tab.c"
    break;

  case 40: /* augassign: ANDEQUAL  */
#line 561 "parser.y"
           {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(&=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 2331 "parser.tab.c"
    break;

  case 41: /* augassign: OREQUAL  */
#line 568 "parser.y"
          {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(|=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 2343 "parser.tab.c"
    break;

  case 42: /* augassign: XOREQUAL  */
#line 575 "parser.y"
           {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(^=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 2355 "parser.tab.c"
    break;

  case 43: /* augassign: LEFTSHIFTEQUAL  */
#line 582 "parser.y"
                 {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(<<=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;

}
#line 2368 "parser.tab.c"
    break;

  case 44: /* augassign: RIGHTSHIFTEQUAL  */
#line 590 "parser.y"
                  {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(>>=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;

}
#line 2381 "parser.tab.c"
    break;

  case 45: /* augassign: EXPONENTEQUAL  */
#line 598 "parser.y"
                {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(**=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 2393 "parser.tab.c"
    break;

  case 46: /* augassign: DIVIDEDIVIDEEQUAL  */
#line 605 "parser.y"
                    {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(//=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 2405 "parser.tab.c"
    break;

  case 47: /* flow_stmt: break_stmt  */
#line 614 "parser.y"
                      {
    (yyval.num) = (yyvsp[0].num);
}
#line 2413 "parser.tab.c"
    break;

  case 48: /* flow_stmt: continue_stmt  */
#line 617 "parser.y"
                {
    (yyval.num) = (yyvsp[0].num);
}
#line 2421 "parser.tab.c"
    break;

  case 49: /* flow_stmt: return_stmt  */
#line 620 "parser.y"
              {
    (yyval.num) = (yyvsp[0].num);
}
#line 2429 "parser.tab.c"
    break;

  case 50: /* break_stmt: BREAK  */
#line 624 "parser.y"
                  {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "KEYWORD(break)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;

}
#line 2442 "parser.tab.c"
    break;

  case 51: /* continue_stmt: CONTINUE  */
#line 633 "parser.y"
                        {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "KEYWORD(continue)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 2454 "parser.tab.c"
    break;

  case 52: /* return_stmt: RETURN testlist  */
#line 641 "parser.y"
                             {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "return_stmt";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "KEYWORD(return)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n])); 
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 2471 "parser.tab.c"
    break;

  case 53: /* return_stmt: RETURN  */
#line 653 "parser.y"
         {
    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "KEYWORD(return)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 2482 "parser.tab.c"
    break;

  case 54: /* global_stmt: GLOBAL NAME  */
#line 660 "parser.y"
                         {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "global_stmt";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "KEYWORD(global)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));

    ((yyvsp[0].tok)).n = nodes++;
    string s = "NAME (" + string(((yyvsp[0].tok)).lex) + ")";
    node_map[((yyvsp[0].tok)).n] = s;
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));
}
#line 2503 "parser.tab.c"
    break;

  case 55: /* global_stmt: global_stmt COMMA NAME  */
#line 676 "parser.y"
                          {
     (yyval.num) = nodes++;
    node_map[(yyval.num)] = "global_stmt";
    node_shape[(yyval.num)] = "oval";

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num),node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(,)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));
    
    ((yyvsp[0].tok)).n = nodes++;
    string s = "NAME (" + string(((yyvsp[0].tok)).lex) + ")";
    node_map[((yyvsp[0].tok)).n] = s;
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));

}
#line 2527 "parser.tab.c"
    break;

  case 56: /* assert_stmt: ASSERT test COMMA test  */
#line 697 "parser.y"
                                    {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "assert_stmt";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-3].tok)).n = nodes++;
    node_map[((yyvsp[-3].tok)).n] = "KEYWORD(assert)";
    node_shape[((yyvsp[-3].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-3].tok)).n, node_map[((yyvsp[-3].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num),node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(,)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));

}
#line 2552 "parser.tab.c"
    break;

  case 57: /* assert_stmt: ASSERT test  */
#line 717 "parser.y"
              {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "assert_stmt";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "KEYWORD(assert)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 2569 "parser.tab.c"
    break;

  case 58: /* compound_stmt: if_stmt  */
#line 730 "parser.y"
                       {
    (yyval.num) = (yyvsp[0].num);
}
#line 2577 "parser.tab.c"
    break;

  case 59: /* compound_stmt: while_stmt  */
#line 733 "parser.y"
             {
    (yyval.num) = (yyvsp[0].num);
}
#line 2585 "parser.tab.c"
    break;

  case 60: /* compound_stmt: for_stmt  */
#line 736 "parser.y"
           {
    (yyval.num) = (yyvsp[0].num);
}
#line 2593 "parser.tab.c"
    break;

  case 61: /* compound_stmt: funcdef  */
#line 739 "parser.y"
          {
    (yyval.num) = (yyvsp[0].num);
}
#line 2601 "parser.tab.c"
    break;

  case 62: /* compound_stmt: classdef  */
#line 742 "parser.y"
           {
    (yyval.num) = (yyvsp[0].num);
}
#line 2609 "parser.tab.c"
    break;

  case 63: /* if_stmt: IF test COLON suite if_stmt_help ELSE COLON suite  */
#line 747 "parser.y"
                                                           {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "if_stmt";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-7].tok)).n = nodes++;
    node_map[((yyvsp[-7].tok)).n] = "KEYWORD(if)";
    node_shape[((yyvsp[-7].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-7].tok)).n, node_map[((yyvsp[-7].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-6].num), node_map[(yyvsp[-6].num)]));

    ((yyvsp[-5].tok)).n = nodes++;
    node_map[((yyvsp[-5].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-5].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-5].tok)).n, node_map[((yyvsp[-5].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-4].num), node_map[(yyvsp[-4].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-3].num), node_map[(yyvsp[-3].num)]));

    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "KEYWORD(else)";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n, node_map[((yyvsp[-2].tok)).n]));
    
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));

}
#line 2647 "parser.tab.c"
    break;

  case 64: /* if_stmt: IF test COLON suite if_stmt_help  */
#line 780 "parser.y"
                                  {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "if_stmt";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-4].tok)).n = nodes++;
    node_map[((yyvsp[-4].tok)).n] = "KEYWORD(if)";
    node_shape[((yyvsp[-4].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-4].tok)).n, node_map[((yyvsp[-4].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-3].num), node_map[(yyvsp[-3].num)]));

    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n, node_map[((yyvsp[-2].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
}
#line 2672 "parser.tab.c"
    break;

  case 65: /* if_stmt: IF test COLON suite ELSE COLON suite  */
#line 800 "parser.y"
                                       {
     (yyval.num) = nodes++;
    node_map[(yyval.num)] = "if_stmt";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-6].tok)).n = nodes++;
    node_map[((yyvsp[-6].tok)).n] = "KEYWORD(if)";
    node_shape[((yyvsp[-6].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-6].tok)).n, node_map[((yyvsp[-6].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-5].num), node_map[(yyvsp[-5].num)]));

    ((yyvsp[-4].tok)).n = nodes++;
    node_map[((yyvsp[-4].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-4].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-4].tok)).n, node_map[((yyvsp[-4].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-3].num), node_map[(yyvsp[-3].num)]));

    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "KEYWORD(else)";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n, node_map[((yyvsp[-2].tok)).n]));
    
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));

}
#line 2709 "parser.tab.c"
    break;

  case 66: /* if_stmt: IF test COLON suite  */
#line 832 "parser.y"
                      {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "if_stmt";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-3].tok)).n = nodes++;
    node_map[((yyvsp[-3].tok)).n] = "KEYWORD(if)";
    node_shape[((yyvsp[-3].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-3].tok)).n, node_map[((yyvsp[-3].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
}
#line 2733 "parser.tab.c"
    break;

  case 67: /* if_stmt_help: ELIF test COLON suite  */
#line 851 "parser.y"
                                     {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "elif_block";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-3].tok)).n = nodes++;
    node_map[((yyvsp[-3].tok)).n] = "KEYWORD(elif)";
    node_shape[((yyvsp[-3].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-3].tok)).n, node_map[((yyvsp[-3].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));

}
#line 2758 "parser.tab.c"
    break;

  case 68: /* if_stmt_help: ELIF test COLON suite if_stmt_help  */
#line 871 "parser.y"
                                     {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "elif_block";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-4].tok)).n = nodes++;
    node_map[((yyvsp[-4].tok)).n] = "KEYWORD(elif)";
    node_shape[((yyvsp[-4].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-4].tok)).n, node_map[((yyvsp[-4].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-3].num), node_map[(yyvsp[-3].num)]));

    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n, node_map[((yyvsp[-2].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
    
}
#line 2785 "parser.tab.c"
    break;

  case 69: /* while_stmt: WHILE test COLON suite  */
#line 894 "parser.y"
                                   {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "while_stmt";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-3].tok)).n = nodes++;
    node_map[((yyvsp[-3].tok)).n] = "KEYWORD(while)";
    node_shape[((yyvsp[-3].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-3].tok)).n, node_map[((yyvsp[-3].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
}
#line 2809 "parser.tab.c"
    break;

  case 70: /* while_stmt: WHILE test COLON suite ELSE COLON suite  */
#line 913 "parser.y"
                                         {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "while_stmt";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-6].tok)).n = nodes++;
    node_map[((yyvsp[-6].tok)).n] = "KEYWORD(while)";
    node_shape[((yyvsp[-6].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-6].tok)).n, node_map[((yyvsp[-6].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-5].num), node_map[(yyvsp[-5].num)]));

    ((yyvsp[-4].tok)).n = nodes++;
    node_map[((yyvsp[-4].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-4].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-4].tok)).n, node_map[((yyvsp[-4].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-3].num), node_map[(yyvsp[-3].num)]));

    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "KEYWORD(else)";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n, node_map[((yyvsp[-2].tok)).n]));    
    
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
    
    
}
#line 2847 "parser.tab.c"
    break;

  case 71: /* for_stmt: FOR exprlist IN testlist COLON suite ELSE COLON suite  */
#line 947 "parser.y"
                                                                {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "for_stmt";
    node_shape[(yyval.num)] = "oval";
    
    ((yyvsp[-8].tok)).n = nodes++;
    node_map[((yyvsp[-8].tok)).n] = "KEYWORD(for)";
    node_shape[((yyvsp[-8].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-8].tok)).n, node_map[((yyvsp[-8].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-7].num), node_map[(yyvsp[-7].num)]));
    
    ((yyvsp[-6].tok)).n = nodes++;
    node_map[((yyvsp[-6].tok)).n] = "KEYWORD(in)";
    node_shape[((yyvsp[-6].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-6].tok)).n, node_map[((yyvsp[-6].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-5].num), node_map[(yyvsp[-5].num)]));
        
    ((yyvsp[-4].tok)).n = nodes++;
    node_map[((yyvsp[-4].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-4].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-4].tok)).n, node_map[((yyvsp[-4].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-3].num), node_map[(yyvsp[-3].num)]));

    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "KEYWORD(else)";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n, node_map[((yyvsp[-2].tok)).n]));
    
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));

}
#line 2891 "parser.tab.c"
    break;

  case 72: /* for_stmt: FOR exprlist IN testlist COLON suite  */
#line 986 "parser.y"
                                       {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "for_stmt";
    node_shape[(yyval.num)] = "oval";
    
    ((yyvsp[-5].tok)).n = nodes++;
    node_map[((yyvsp[-5].tok)).n] = "KEYWORD(for)";
    node_shape[((yyvsp[-5].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-5].tok)).n, node_map[((yyvsp[-5].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-4].num), node_map[(yyvsp[-4].num)]));
    
    ((yyvsp[-3].tok)).n = nodes++;
    node_map[((yyvsp[-3].tok)).n] = "KEYWORD(in)";
    node_shape[((yyvsp[-3].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-3].tok)).n, node_map[((yyvsp[-3].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
        
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));

}
#line 2923 "parser.tab.c"
    break;

  case 73: /* suite: simple_stmt  */
#line 1014 "parser.y"
                   {
    (yyval.num) = (yyvsp[0].num);
}
#line 2931 "parser.tab.c"
    break;

  case 74: /* suite: NEWLINE INDENT stmt_help DEDENT  */
#line 1018 "parser.y"
                                  {
    (yyval.num) = (yyvsp[-1].num);
}
#line 2939 "parser.tab.c"
    break;

  case 75: /* stmt_help: stmt  */
#line 1022 "parser.y"
                {
    (yyval.num) = (yyvsp[0].num);
}
#line 2947 "parser.tab.c"
    break;

  case 76: /* stmt_help: stmt stmt_help  */
#line 1025 "parser.y"
                 {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "stmt_block";
    node_shape[(yyval.num)] = "oval";
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));

}
#line 2961 "parser.tab.c"
    break;

  case 77: /* test: or_test  */
#line 1035 "parser.y"
               {
    (yyval.num) = (yyvsp[0].num);
}
#line 2969 "parser.tab.c"
    break;

  case 78: /* test: or_test IF or_test ELSE test  */
#line 1038 "parser.y"
                               {

    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "test";
    node_shape[(yyval.num)] = "oval";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-4].num), node_map[(yyvsp[-4].num)]));

    ((yyvsp[-3].tok)).n = nodes++;
    node_map[((yyvsp[-3].tok)).n] = "KEYWORD(if)";
    node_shape[((yyvsp[-3].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-3].tok)).n,node_map[((yyvsp[-3].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num),node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "KEYWORD(else)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 2995 "parser.tab.c"
    break;

  case 79: /* or_test: and_test  */
#line 1060 "parser.y"
                   {
    (yyval.num) = (yyvsp[0].num);
}
#line 3003 "parser.tab.c"
    break;

  case 80: /* or_test: or_test OR and_test  */
#line 1063 "parser.y"
                      {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "or_test";
    node_shape[(yyval.num)] = "oval";
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "KEYWORD(or)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3022 "parser.tab.c"
    break;

  case 81: /* and_test: not_test  */
#line 1079 "parser.y"
                    {
    (yyval.num) = (yyvsp[0].num);
}
#line 3030 "parser.tab.c"
    break;

  case 82: /* and_test: and_test AND not_test  */
#line 1083 "parser.y"
                        {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "and_test";
    node_shape[(yyval.num)] = "oval";
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "KEYWORD(and)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3049 "parser.tab.c"
    break;

  case 83: /* not_test: NOT not_test  */
#line 1098 "parser.y"
                        {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "not_test";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "KEYWORD(not)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3066 "parser.tab.c"
    break;

  case 84: /* not_test: comparison  */
#line 1111 "parser.y"
             {
    (yyval.num) = (yyvsp[0].num);
}
#line 3074 "parser.tab.c"
    break;

  case 85: /* comparison: expr  */
#line 1115 "parser.y"
                  {
    (yyval.num) = (yyvsp[0].num);
}
#line 3082 "parser.tab.c"
    break;

  case 86: /* comparison: comparison comp_op expr  */
#line 1119 "parser.y"
                          {
    (yyval.num) = (yyvsp[-1].num);
    node_map[(yyval.num)] = node_map[(yyvsp[-1].num)];
    node_shape[(yyval.num)] = node_shape[(yyvsp[-1].num)];
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num),node_map[(yyvsp[-2].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3094 "parser.tab.c"
    break;

  case 87: /* comp_op: EQUAL  */
#line 1127 "parser.y"
                {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 3106 "parser.tab.c"
    break;

  case 88: /* comp_op: LESS  */
#line 1134 "parser.y"
       {
    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(<)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num)=((yyvsp[0].tok)).n;
}
#line 3117 "parser.tab.c"
    break;

  case 89: /* comp_op: GREATER  */
#line 1140 "parser.y"
         {
    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(>)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num)=((yyvsp[0].tok)).n;
}
#line 3128 "parser.tab.c"
    break;

  case 90: /* comp_op: GREATEREQ  */
#line 1146 "parser.y"
           {
    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(>=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num)=((yyvsp[0].tok)).n;
}
#line 3139 "parser.tab.c"
    break;

  case 91: /* comp_op: LESSEQ  */
#line 1152 "parser.y"
        {

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(<=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num)=((yyvsp[0].tok)).n;
}
#line 3151 "parser.tab.c"
    break;

  case 92: /* comp_op: NOTEQUAL  */
#line 1159 "parser.y"
          {
    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "OPERATOR(!=)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 3162 "parser.tab.c"
    break;

  case 93: /* comp_op: IS  */
#line 1165 "parser.y"
    {
    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "KEYWORD(is)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 3173 "parser.tab.c"
    break;

  case 94: /* comp_op: IS NOT  */
#line 1171 "parser.y"
        {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "comp_op";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "KEYWORD(is)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "KEYWORD(not)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n, node_map[((yyvsp[0].tok)).n]));
}
#line 3193 "parser.tab.c"
    break;

  case 95: /* comp_op: IN  */
#line 1186 "parser.y"
    {
    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "KEYWORD(in)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 3204 "parser.tab.c"
    break;

  case 96: /* comp_op: NOT IN  */
#line 1192 "parser.y"
         {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "comp_op";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "KEYWORD(not)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n, node_map[((yyvsp[-1].tok)).n]));

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "KEYWORD(in)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n, node_map[((yyvsp[0].tok)).n]));
}
#line 3224 "parser.tab.c"
    break;

  case 97: /* expr: xor_expr  */
#line 1208 "parser.y"
                {
    (yyval.num) = (yyvsp[0].num);
}
#line 3232 "parser.tab.c"
    break;

  case 98: /* expr: expr BITOR xor_expr  */
#line 1212 "parser.y"
                      {

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(|)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3246 "parser.tab.c"
    break;

  case 99: /* xor_expr: and_expr  */
#line 1222 "parser.y"
                   {
    (yyval.num) = (yyvsp[0].num);
}
#line 3254 "parser.tab.c"
    break;

  case 100: /* xor_expr: xor_expr BITXOR and_expr  */
#line 1226 "parser.y"
                           {

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(^)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3268 "parser.tab.c"
    break;

  case 101: /* and_expr: shift_expr  */
#line 1236 "parser.y"
                      {
    (yyval.num) = (yyvsp[0].num);
}
#line 3276 "parser.tab.c"
    break;

  case 102: /* and_expr: and_expr AMPERSAND shift_expr  */
#line 1240 "parser.y"
                                {
   
    

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(&)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    
    (yyval.num) = ((yyvsp[-1].tok)).n;    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3294 "parser.tab.c"
    break;

  case 103: /* shift_expr: arith_expr  */
#line 1255 "parser.y"
                        {
    (yyval.num)=(yyvsp[0].num);
}
#line 3302 "parser.tab.c"
    break;

  case 104: /* shift_expr: shift_expr LEFTSHIFT arith_expr  */
#line 1259 "parser.y"
                                  {
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(<<)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3317 "parser.tab.c"
    break;

  case 105: /* shift_expr: shift_expr RIGHTSHIFT arith_expr  */
#line 1270 "parser.y"
                                   {

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(>>)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3331 "parser.tab.c"
    break;

  case 106: /* arith_expr: term  */
#line 1281 "parser.y"
                 {
    (yyval.num)=(yyvsp[0].num);
}
#line 3339 "parser.tab.c"
    break;

  case 107: /* arith_expr: arith_expr PLUS term  */
#line 1285 "parser.y"
                       {
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(+)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3352 "parser.tab.c"
    break;

  case 108: /* arith_expr: arith_expr MINUS term  */
#line 1293 "parser.y"
                        {
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(-)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3365 "parser.tab.c"
    break;

  case 109: /* term: factor  */
#line 1302 "parser.y"
              {
    (yyval.num)=(yyvsp[0].num);
}
#line 3373 "parser.tab.c"
    break;

  case 110: /* term: term MULTIPLY factor  */
#line 1306 "parser.y"
                       {
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(*)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3386 "parser.tab.c"
    break;

  case 111: /* term: term AT factor  */
#line 1314 "parser.y"
                 {
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(@)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
    
}
#line 3400 "parser.tab.c"
    break;

  case 112: /* term: term DIVIDE factor  */
#line 1323 "parser.y"
                     {
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(/)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));

}
#line 3414 "parser.tab.c"
    break;

  case 113: /* term: term MOD factor  */
#line 1332 "parser.y"
                  {
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(%)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));

}
#line 3428 "parser.tab.c"
    break;

  case 114: /* term: term DIVIDEDIVIDE factor  */
#line 1341 "parser.y"
                           {
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(//)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));

}
#line 3442 "parser.tab.c"
    break;

  case 115: /* factor: power  */
#line 1351 "parser.y"
               {
    (yyval.num) = (yyvsp[0].num);
}
#line 3450 "parser.tab.c"
    break;

  case 116: /* factor: PLUS factor  */
#line 1355 "parser.y"
              {
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPEARTOR(+)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3462 "parser.tab.c"
    break;

  case 117: /* factor: MINUS factor  */
#line 1362 "parser.y"
               {
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(-)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3474 "parser.tab.c"
    break;

  case 118: /* factor: BITNOT factor  */
#line 1369 "parser.y"
                {
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(~)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3486 "parser.tab.c"
    break;

  case 119: /* power: atom_expr  */
#line 1377 "parser.y"
                  {
    (yyval.num)=(yyvsp[0].num);
}
#line 3494 "parser.tab.c"
    break;

  case 120: /* power: atom_expr EXP factor  */
#line 1381 "parser.y"
                       {
    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(**)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num),node_map[(yyvsp[0].num)]));
}
#line 3507 "parser.tab.c"
    break;

  case 121: /* atom_expr: atom  */
#line 1391 "parser.y"
                {
    (yyval.num)=(yyvsp[0].num);
}
#line 3515 "parser.tab.c"
    break;

  case 122: /* atom_expr: atom_expr trailer  */
#line 1396 "parser.y"
{
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "atom_expr";
    node_shape[(yyval.num)] = "oval";

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
}
#line 3528 "parser.tab.c"
    break;

  case 123: /* atom: LEFTBRACKET testlist RIGHTBRACKET  */
#line 1406 "parser.y"
                                         {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "atom";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "DELIMITER(()";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n,node_map[((yyvsp[-2].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "DELIMITER())";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));

}
#line 3551 "parser.tab.c"
    break;

  case 124: /* atom: LEFTBRACKET RIGHTBRACKET  */
#line 1424 "parser.y"
                           {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "atom";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(()";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));


    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "DELIMITER())";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));
}
#line 3572 "parser.tab.c"
    break;

  case 125: /* atom: LEFTSQUAREBRACKET testlist RIGHTSQUAREBRACKET  */
#line 1440 "parser.y"
                                                {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "atom";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "DELIMITER([)";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n,node_map[((yyvsp[-2].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "DELIMITER(])";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));
}
#line 3594 "parser.tab.c"
    break;

  case 126: /* atom: LEFTSQUAREBRACKET RIGHTSQUAREBRACKET  */
#line 1457 "parser.y"
                                       {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "atom";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER([)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "DELIMITER(])";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));
}
#line 3614 "parser.tab.c"
    break;

  case 127: /* atom: LEFTCURLYBRACKET RIGHTCURLYBRACKET  */
#line 1472 "parser.y"
                                     {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "atom";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER({)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "DELIMITER(})";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));
}
#line 3634 "parser.tab.c"
    break;

  case 128: /* atom: NAME  */
#line 1487 "parser.y"
       {

    ((yyvsp[0].tok)).n = nodes++;
    string s = "NAME (" + string(((yyvsp[0].tok)).lex) + ")";
    node_map[((yyvsp[0].tok)).n] = s;
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 3647 "parser.tab.c"
    break;

  case 129: /* atom: NUMBER  */
#line 1496 "parser.y"
         {
    
    ((yyvsp[0].tok)).n = nodes++;
    string s = "NUMBER (" + string(((yyvsp[0].tok)).lex) + ")";
    node_map[((yyvsp[0].tok)).n] = s;
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 3660 "parser.tab.c"
    break;

  case 130: /* atom: string_help  */
#line 1504 "parser.y"
              {
    (yyval.num) = (yyvsp[0].num);
}
#line 3668 "parser.tab.c"
    break;

  case 131: /* atom: NONE  */
#line 1508 "parser.y"
       {
    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "KEYWORD(None)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 3679 "parser.tab.c"
    break;

  case 132: /* atom: TRUE  */
#line 1514 "parser.y"
       {
    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "KEYWORD(True)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 3690 "parser.tab.c"
    break;

  case 133: /* atom: FALSE  */
#line 1520 "parser.y"
        {
    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "KEYWORD(False)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 3701 "parser.tab.c"
    break;

  case 134: /* string_help: string_help STRING  */
#line 1527 "parser.y"
                                 {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "string_help";
    node_shape[(yyval.num)] = "oval";

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num),node_map[(yyvsp[-1].num)]));

    ((yyvsp[0].tok)).n = nodes++;
    s = string(((yyvsp[0].tok)).lex);
    node_map[((yyvsp[0].tok)).n] = "STRING(" + s + ")";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));
}
#line 3719 "parser.tab.c"
    break;

  case 135: /* string_help: STRING  */
#line 1540 "parser.y"
         {
    ((yyvsp[0].tok)).n = nodes++;
    s = string(((yyvsp[0].tok)).lex);
    node_map[((yyvsp[0].tok)).n] = "STRING(" + s + ")";
    node_shape[((yyvsp[0].tok)).n] = "box";
    (yyval.num) = ((yyvsp[0].tok)).n;
}
#line 3731 "parser.tab.c"
    break;

  case 136: /* trailer: LEFTBRACKET RIGHTBRACKET  */
#line 1548 "parser.y"
                                  {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "trailer";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(()";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "DELIMITER())";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));
    
}
#line 3752 "parser.tab.c"
    break;

  case 137: /* trailer: LEFTBRACKET arglist RIGHTBRACKET  */
#line 1564 "parser.y"
                                   {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "trailer";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "DELIMITER(()";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n,node_map[((yyvsp[-2].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "DELIMITER())";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));
    
}
#line 3775 "parser.tab.c"
    break;

  case 138: /* trailer: LEFTSQUAREBRACKET test RIGHTSQUAREBRACKET  */
#line 1582 "parser.y"
                                            {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "trailer";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "DELIMITER([)";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n,node_map[((yyvsp[-2].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "DELIMITER(])";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));
    
}
#line 3798 "parser.tab.c"
    break;

  case 139: /* trailer: DOT NAME  */
#line 1600 "parser.y"
           {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "trailer";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(.)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    ((yyvsp[0].tok)).n = nodes++;
    string s = "NAME (" + string(((yyvsp[0].tok)).lex) + ")";
    node_map[((yyvsp[0].tok)).n] = s;
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)]));betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));
}
#line 3819 "parser.tab.c"
    break;

  case 140: /* exprlist: exprlist_help  */
#line 1617 "parser.y"
                        {
    (yyval.num)=(yyvsp[0].num);
}
#line 3827 "parser.tab.c"
    break;

  case 141: /* exprlist: exprlist_help COMMA  */
#line 1620 "parser.y"
                     {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "exprlist";
    node_shape[(yyval.num)] = "oval";

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "DELIMITER(,)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));
}
#line 3844 "parser.tab.c"
    break;

  case 142: /* exprlist_help: expr  */
#line 1633 "parser.y"
                   {
    (yyval.num)=(yyvsp[0].num);
}
#line 3852 "parser.tab.c"
    break;

  case 143: /* exprlist_help: exprlist_help COMMA expr  */
#line 1636 "parser.y"
                           {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "exprlist";
    node_shape[(yyval.num)] = "oval";

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(,)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
}
#line 3871 "parser.tab.c"
    break;

  case 144: /* testlist: testlist_list COMMA  */
#line 1652 "parser.y"
                              {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "testlist";
    node_shape[(yyval.num)] = "oval";

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));
    
    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "DELIMITER(,)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));
}
#line 3888 "parser.tab.c"
    break;

  case 145: /* testlist: testlist_list  */
#line 1664 "parser.y"
                {
    (yyval.num) = (yyvsp[0].num);    
}
#line 3896 "parser.tab.c"
    break;

  case 146: /* testlist_list: test  */
#line 1668 "parser.y"
                     {
    (yyval.num)=(yyvsp[0].num);
}
#line 3904 "parser.tab.c"
    break;

  case 147: /* testlist_list: testlist_list COMMA test  */
#line 1672 "parser.y"
                           {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "testlist_list";
    node_shape[(yyval.num)] = "oval";

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(,)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
    
}
#line 3924 "parser.tab.c"
    break;

  case 148: /* classdef: CLASS NAME COLON suite  */
#line 1690 "parser.y"
                                 {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "classdef";
    node_shape[(yyval.num)] = "oval";
    
    ((yyvsp[-3].tok)).n = nodes++;
    node_map[((yyvsp[-3].tok)).n] = "KEYWORD(class)";
    node_shape[((yyvsp[-3].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-3].tok)).n,node_map[((yyvsp[-3].tok)).n]));

    ((yyvsp[-2].tok)).n = nodes++;
    string s = "NAME (" + string(((yyvsp[-2].tok)).lex) + ")";
    node_map[((yyvsp[-2].tok)).n] = s;
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)]));betaa.push_back(make_pair(((yyvsp[-2].tok)).n,node_map[((yyvsp[-2].tok)).n]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
}
#line 3952 "parser.tab.c"
    break;

  case 149: /* classdef: CLASS NAME LEFTBRACKET RIGHTBRACKET COLON suite  */
#line 1713 "parser.y"
                                                  {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "classdef";
    node_shape[(yyval.num)] = "oval";
    
    ((yyvsp[-5].tok)).n = nodes++;
    node_map[((yyvsp[-5].tok)).n] = "KEYWORD(class)";
    node_shape[((yyvsp[-5].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-5].tok)).n,node_map[((yyvsp[-5].tok)).n]));

    ((yyvsp[-4].tok)).n = nodes++;
    string s = "NAME (" + string(((yyvsp[-4].tok)).lex) + ")";
    node_map[((yyvsp[-4].tok)).n] = s;
    node_shape[((yyvsp[-4].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)]));betaa.push_back(make_pair(((yyvsp[-4].tok)).n,node_map[((yyvsp[-4].tok)).n]));

    ((yyvsp[-3].tok)).n = nodes++;
    node_map[((yyvsp[-3].tok)).n] = "DELIMITER(()";
    node_shape[((yyvsp[-3].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-3].tok)).n,node_map[((yyvsp[-3].tok)).n]));

    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "DELIMITER())";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-3].tok)).n,node_map[((yyvsp[-3].tok)).n]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
}
#line 3990 "parser.tab.c"
    break;

  case 150: /* classdef: CLASS NAME LEFTBRACKET arglist RIGHTBRACKET COLON suite  */
#line 1746 "parser.y"
                                                          {

    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "classdef";
    node_shape[(yyval.num)] = "oval";
    
    ((yyvsp[-6].tok)).n = nodes++;
    node_map[((yyvsp[-6].tok)).n] = "KEYWORD(class)";
    node_shape[((yyvsp[-6].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-6].tok)).n,node_map[((yyvsp[-6].tok)).n]));
    
    ((yyvsp[-5].tok)).n = nodes++;
    string s = "NAME (" + string(((yyvsp[-5].tok)).lex) + ")";
    node_map[((yyvsp[-5].tok)).n] = s;
    node_shape[((yyvsp[-5].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)]));betaa.push_back(make_pair(((yyvsp[-5].tok)).n,node_map[((yyvsp[-5].tok)).n]));

    ((yyvsp[-4].tok)).n = nodes++;
    node_map[((yyvsp[-4].tok)).n] = "DELIMITER(()";
    node_shape[((yyvsp[-4].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-4].tok)).n,node_map[((yyvsp[-4].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-3].num), node_map[(yyvsp[-3].num)]));

    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "DELIMITER())";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n,node_map[((yyvsp[-2].tok)).n]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(:)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
    
}
#line 4032 "parser.tab.c"
    break;

  case 151: /* arglist: arglist_help  */
#line 1784 "parser.y"
                      {
    (yyval.num) = (yyvsp[0].num);
}
#line 4040 "parser.tab.c"
    break;

  case 152: /* arglist: arglist_help COMMA  */
#line 1787 "parser.y"
                     {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "arglist";
    node_shape[(yyval.num)] = "oval";
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));

    ((yyvsp[0].tok)).n = nodes++;
    node_map[((yyvsp[0].tok)).n] = "DELIMITER(,)";
    node_shape[((yyvsp[0].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[0].tok)).n,node_map[((yyvsp[0].tok)).n]));


}
#line 4059 "parser.tab.c"
    break;

  case 153: /* arglist_help: argument  */
#line 1802 "parser.y"
                       {
    (yyval.num) = (yyvsp[0].num);
}
#line 4067 "parser.tab.c"
    break;

  case 154: /* arglist_help: arglist_help COMMA argument  */
#line 1805 "parser.y"
                              {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "arglist";
    node_shape[(yyval.num)] = "oval";
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "DELIMITER(,)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
}
#line 4086 "parser.tab.c"
    break;

  case 155: /* func_body_suite: simple_stmt  */
#line 1820 "parser.y"
                             {
    (yyval.num) = (yyvsp[0].num);
}
#line 4094 "parser.tab.c"
    break;

  case 156: /* func_body_suite: NEWLINE INDENT stmt_help DEDENT  */
#line 1823 "parser.y"
                                  {
    (yyval.num) = (yyvsp[-1].num);
}
#line 4102 "parser.tab.c"
    break;

  case 157: /* argument: test  */
#line 1839 "parser.y"
               {

    (yyval.num) = (yyvsp[0].num);
}
#line 4111 "parser.tab.c"
    break;

  case 158: /* argument: test ASSIGN test  */
#line 1844 "parser.y"
                   {

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "OPERATOR(=)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    (yyval.num) = ((yyvsp[-1].tok)).n;
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
}
#line 4125 "parser.tab.c"
    break;

  case 159: /* argument: test comp_for  */
#line 1853 "parser.y"
                {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "arglist";
    node_shape[(yyval.num)] = "oval";
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
}
#line 4138 "parser.tab.c"
    break;

  case 160: /* comp_iter: comp_for  */
#line 1862 "parser.y"
                    {
 (yyval.num) = (yyvsp[0].num);
}
#line 4146 "parser.tab.c"
    break;

  case 161: /* comp_iter: comp_if  */
#line 1865 "parser.y"
          {
    (yyval.num) = (yyvsp[0].num);
}
#line 4154 "parser.tab.c"
    break;

  case 162: /* comp_for: FOR exprlist IN or_test  */
#line 1869 "parser.y"
                                  {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "comp_for";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-3].tok)).n = nodes++;
    node_map[((yyvsp[-3].tok)).n] = "KEYWORD(For)";
    node_shape[((yyvsp[-3].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-3].tok)).n,node_map[((yyvsp[-3].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-2].num), node_map[(yyvsp[-2].num)]));

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "KEYWORD(In)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));

}
#line 4179 "parser.tab.c"
    break;

  case 163: /* comp_for: FOR exprlist IN or_test comp_iter  */
#line 1889 "parser.y"
                                    {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "comp_for";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-4].tok)).n = nodes++;
    node_map[((yyvsp[-4].tok)).n] = "KEYWORD(For)";
    node_shape[((yyvsp[-4].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-4].tok)).n,node_map[((yyvsp[-4].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-3].num), node_map[(yyvsp[-3].num)]));

    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "KEYWORD(In)";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n,node_map[((yyvsp[-2].tok)).n]));
    
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
}
#line 4204 "parser.tab.c"
    break;

  case 164: /* comp_if: IF or_test  */
#line 1910 "parser.y"
                    {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "comp_if";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-1].tok)).n = nodes++;
    node_map[((yyvsp[-1].tok)).n] = "KEYWORD(For)";
    node_shape[((yyvsp[-1].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-1].tok)).n,node_map[((yyvsp[-1].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));

}
#line 4222 "parser.tab.c"
    break;

  case 165: /* comp_if: IF or_test comp_iter  */
#line 1923 "parser.y"
                       {
    (yyval.num) = nodes++;
    node_map[(yyval.num)] = "comp_if";
    node_shape[(yyval.num)] = "oval";

    ((yyvsp[-2].tok)).n = nodes++;
    node_map[((yyvsp[-2].tok)).n] = "KEYWORD(If)";
    node_shape[((yyvsp[-2].tok)).n] = "box";
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair(((yyvsp[-2].tok)).n,node_map[((yyvsp[-2].tok)).n]));

    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[-1].num), node_map[(yyvsp[-1].num)]));
    baap.push_back(make_pair((yyval.num),node_map[(yyval.num)])); betaa.push_back(make_pair((yyvsp[0].num), node_map[(yyvsp[0].num)]));
}
#line 4240 "parser.tab.c"
    break;


#line 4244 "parser.tab.c"

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

#line 1938 "parser.y"

void yyerror(const char *s)
{
    cout<< "Error found at line number: "<< yylineno<< " " << "at token " << yytext << " " << s << endl;
 
    exit(1);
}

int main(int argc, char **argv)
{
  string executible_name(argv[0]);
  argc--, argv++;
  if(argc != 2) {
    cerr << executible_name << ": Error: provide arguments correctly\n";
    exit(1);
  }
  char *input_filename = argv[0];
  int verbose = atoi(argv[1]);
  if(verbose) yydebug = 1;
  yyin = fopen(input_filename, "r");
  if(yyin == NULL) {
    cerr << executible_name << ": Error: Input file " << input_filename << " not found.\n";
    exit(1);
  }

  indent_cnt.push(0);


  yyparse();
  ofstream fout("AST.dot");
  fout<<"digraph G {"<<endl;
  fout<<"node [ordering=out]\n";
  for(auto it : node_map){
    string s;
    for (auto x : it.second) {
        if (x == '\"'){
            s += "\\";
            s += "\"";
        }
        else {
            s += x;
        }
    }
    fout<<it.first<<" [label=\"" << s << "\" ,shape= " << node_shape[it.first] << " ]" << endl;
    
  }
  for(int i=0; i<nodes - 1; ++i){
    fout<<baap[i].first<<" -> "<<betaa[i].first<<endl;
  }
  fout<<"}"<<endl;
  return 0;
}



