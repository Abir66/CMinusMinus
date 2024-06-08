/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "1905066.y"

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include"symbol-table/1905066_symbolTable.h"
#include"1905066_parser_helper.h"
#include"1905066_ICG_helper.h"

using namespace std;



#line 85 "y.tab.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    DO = 262,
    BREAK = 263,
    RETURN = 264,
    SWITCH = 265,
    CASE = 266,
    DEFAULT = 267,
    CONTINUE = 268,
    LPAREN = 269,
    RPAREN = 270,
    LCURL = 271,
    RCURL = 272,
    LTHIRD = 273,
    RTHIRD = 274,
    COMMA = 275,
    SEMICOLON = 276,
    PRINTLN = 277,
    PRINT = 278,
    INCOP = 279,
    DECOP = 280,
    ASSIGNOP = 281,
    NOT = 282,
    ID = 283,
    INT = 284,
    FLOAT = 285,
    DOUBLE = 286,
    CONST_INT = 287,
    CONST_FLOAT = 288,
    CHAR = 289,
    VOID = 290,
    ADDOP = 291,
    MULOP = 292,
    RELOP = 293,
    LOGICOP = 294,
    BITOP = 295,
    CONST_STRING = 296,
    SCANINT = 297,
    LOWER_THAN_ELSE = 298
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define RETURN 264
#define SWITCH 265
#define CASE 266
#define DEFAULT 267
#define CONTINUE 268
#define LPAREN 269
#define RPAREN 270
#define LCURL 271
#define RCURL 272
#define LTHIRD 273
#define RTHIRD 274
#define COMMA 275
#define SEMICOLON 276
#define PRINTLN 277
#define PRINT 278
#define INCOP 279
#define DECOP 280
#define ASSIGNOP 281
#define NOT 282
#define ID 283
#define INT 284
#define FLOAT 285
#define DOUBLE 286
#define CONST_INT 287
#define CONST_FLOAT 288
#define CHAR 289
#define VOID 290
#define ADDOP 291
#define MULOP 292
#define RELOP 293
#define LOGICOP 294
#define BITOP 295
#define CONST_STRING 296
#define SCANINT 297
#define LOWER_THAN_ELSE 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "1905066.y"

    SymbolInfo* symbolInfo; 

#line 227 "y.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

#define YYUNDEFTOK  2
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    35,    35,    41,    46,    53,    58,    64,    72,    81,
      91,    91,   109,   109,   128,   140,   149,   158,   169,   169,
     184,   184,   193,   218,   224,   230,   238,   245,   253,   261,
     272,   272,   283,   283,   294,   299,   325,   333,   333,   333,
     356,   366,   385,   385,   419,   424,   429,   439,   446,   454,
     462,   470,   474,   479,   489,   508,   542,   549,   562,   568,
     621,   627,   664,   671,   705,   712,   734,   742,   796,   817,
     848,   859,   872,   934,   944,   956,   963,   979,   998,  1004,
    1010,  1017
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DO",
  "BREAK", "RETURN", "SWITCH", "CASE", "DEFAULT", "CONTINUE", "LPAREN",
  "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON",
  "PRINTLN", "PRINT", "INCOP", "DECOP", "ASSIGNOP", "NOT", "ID", "INT",
  "FLOAT", "DOUBLE", "CONST_INT", "CONST_FLOAT", "CHAR", "VOID", "ADDOP",
  "MULOP", "RELOP", "LOGICOP", "BITOP", "CONST_STRING", "SCANINT",
  "LOWER_THAN_ELSE", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "$@1", "$@2", "parameter_list",
  "compound_statement", "$@3", "$@4", "var_declaration", "type_specifier",
  "declaration_list", "statements", "$@5", "$@6", "statement", "$@7",
  "$@8", "$@9", "P", "expression_statement", "variable", "N", "M",
  "expression", "logic_expression", "rel_expression", "simple_expression",
  "term", "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF (-79)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,   -79,   -79,   -79,     9,   -24,   -79,   -79,   -79,   -79,
     -16,   -79,   -79,    21,    23,    11,   -13,    27,   -79,    35,
      -7,    41,    54,    62,   -79,    68,    65,   -24,   -79,   -79,
      55,    78,   -79,   -79,    68,    69,    79,   -79,    87,   -79,
     -79,   -79,    88,    85,   -79,   -79,   -79,    95,    96,   -79,
     102,   114,   -79,    97,   105,   114,    50,   -79,   -79,   114,
     108,   -79,   -79,    74,   -79,   -79,    37,   103,   -79,    86,
      47,    94,   -79,   -79,    85,   114,   112,   118,   -79,   115,
     122,    -4,    38,    51,   -79,   114,   114,   -79,   121,   125,
     -79,   -79,   114,   -79,   -79,   114,   114,   114,   -79,   -79,
     -79,   114,   -79,   -79,   136,   137,   138,   139,   -79,   140,
     141,   143,   142,   144,   -79,   114,    94,   120,   -79,   148,
     112,   -79,   145,   146,   147,   149,   -79,   114,   -79,   150,
     -79,   -79,   -79,   154,   -79,   -79,   -79,   -79,   -79,   -79,
      85,   -79,   -79,   153,   114,    85,   -79,   -79,   -79,   -79,
     157,    85,   -79,   -79,    85,   -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,     0,     0,     0,    22,    12,
       0,    17,     0,    26,     9,     0,    10,     0,    16,    29,
       0,    18,    13,     8,     0,    15,     0,    30,     0,    11,
      14,    27,    57,     0,    21,    19,    32,     0,     0,    57,
       0,     0,    52,     0,     0,     0,    54,    74,    75,     0,
       0,    36,    34,     0,    31,    35,    71,     0,    58,    60,
      62,    64,    66,    70,     0,     0,     0,     0,    47,     0,
       0,     0,     0,    71,    69,    79,     0,    68,     0,    28,
      76,    77,     0,    53,    57,     0,     0,     0,    33,    51,
      57,     0,    46,    73,     0,     0,     0,     0,    81,     0,
      78,     0,    54,     0,    59,     0,    65,    63,    67,     0,
       0,    42,     0,     0,     0,     0,    72,     0,    55,     0,
      61,    57,    37,     0,    48,    44,    49,    45,    80,    50,
       0,    57,    57,    40,     0,     0,    56,    38,    43,    57,
       0,     0,    57,    41,     0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   -79,   159,   -79,   -79,   -79,   -79,   -79,    -9,
     -79,   -79,    31,    15,   -79,   -79,   -79,   -79,   -73,   -79,
     -79,   -79,   -79,   -72,   -38,   -79,   -49,   -48,   -78,    43,
      77,    70,   -37,   -79,   -79,   -79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    34,    25,    20,    61,
      37,    38,    62,    63,    14,    42,    43,    74,    64,   141,
     150,   133,   119,    65,    66,   149,    46,    67,    68,    69,
      70,    71,    72,    73,   109,   110
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    98,    79,    80,   100,     1,     2,   108,    26,    11,
      51,     3,    13,    27,   114,    10,    32,    83,    84,    22,
      10,    83,    87,    55,    56,    39,    19,    99,    57,    58,
      21,     9,    59,   105,   107,    15,     9,   104,   111,    16,
       1,     2,    35,    17,    18,   115,     3,    83,   132,   138,
     113,   120,    51,   121,    83,    23,    24,    83,    83,    83,
     118,    90,    91,    92,    85,    55,    56,   143,    86,    28,
      57,    58,   148,    29,    59,    90,    91,    83,   153,   106,
      30,   155,   140,    95,    31,    96,    33,    36,    47,    83,
      48,    49,   144,   145,    50,   -20,   147,    40,    41,    51,
     151,    31,    89,   154,    44,    45,    52,    53,    54,    75,
      76,    81,    55,    56,     1,     2,    51,    57,    58,    82,
       3,    59,    88,    78,    93,    94,    51,    60,    51,    55,
      56,    97,   101,    52,    57,    58,   102,   103,    59,    55,
      56,    55,    56,    16,    57,    58,    57,    58,    59,   112,
      59,   122,   123,   124,   125,   126,    95,   146,   130,   129,
      86,   127,   128,   131,    12,   116,   134,   135,   136,   142,
     137,   139,   152,   117
};

static const yytype_uint8 yycheck[] =
{
      49,    74,    50,    51,    76,    29,    30,    85,    15,     0,
      14,    35,    28,    20,    92,     0,    25,    55,    55,    32,
       5,    59,    59,    27,    28,    34,    15,    75,    32,    33,
      15,     0,    36,    81,    82,    14,     5,    41,    86,    18,
      29,    30,    27,    20,    21,    94,    35,    85,   120,   127,
      88,   100,    14,   101,    92,    28,    21,    95,    96,    97,
      97,    24,    25,    26,    14,    27,    28,   140,    18,    28,
      32,    33,   145,    19,    36,    24,    25,   115,   151,    41,
      18,   154,   131,    36,    16,    38,    21,    32,     3,   127,
       5,     6,   141,   142,     9,    17,   144,    28,    19,    14,
     149,    16,    28,   152,    17,    17,    21,    22,    23,    14,
      14,    14,    27,    28,    29,    30,    14,    32,    33,    14,
      35,    36,    14,    21,    21,    39,    14,    42,    14,    27,
      28,    37,    14,    21,    32,    33,    21,    15,    36,    27,
      28,    27,    28,    18,    32,    33,    32,    33,    36,    28,
      36,    15,    15,    15,    15,    15,    36,     4,   115,    15,
      18,    20,    19,    15,     5,    95,    21,    21,    21,    15,
      21,    21,    15,    96
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    30,    35,    45,    46,    47,    48,    49,    56,
      57,     0,    47,    28,    58,    14,    18,    20,    21,    15,
      52,    57,    32,    28,    21,    51,    15,    20,    28,    19,
      18,    16,    53,    21,    50,    57,    32,    54,    55,    53,
      28,    19,    59,    60,    17,    17,    70,     3,     5,     6,
       9,    14,    21,    22,    23,    27,    28,    32,    33,    36,
      42,    53,    56,    57,    62,    67,    68,    71,    72,    73,
      74,    75,    76,    77,    61,    14,    14,    70,    21,    71,
      71,    14,    14,    68,    76,    14,    18,    76,    14,    28,
      24,    25,    26,    21,    39,    36,    38,    37,    62,    71,
      67,    14,    21,    15,    41,    71,    41,    71,    72,    78,
      79,    71,    28,    68,    72,    70,    75,    74,    76,    66,
      70,    71,    15,    15,    15,    15,    15,    20,    19,    15,
      73,    15,    67,    65,    21,    21,    21,    21,    72,    21,
      70,    63,    15,    62,    70,    70,     4,    71,    62,    69,
      64,    70,    15,    62,    70,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    48,    48,
      50,    49,    51,    49,    52,    52,    52,    52,    54,    53,
      55,    53,    56,    57,    57,    57,    58,    58,    58,    58,
      60,    59,    61,    59,    62,    62,    62,    63,    64,    62,
      62,    62,    65,    62,    62,    62,    62,    62,    62,    62,
      62,    66,    67,    67,    68,    68,    69,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    78,    78,
      79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     0,     4,
       0,     3,     3,     1,     1,     1,     3,     6,     1,     4,
       0,     2,     0,     4,     1,     1,     1,     0,     0,    12,
       7,    11,     0,     8,     5,     5,     3,     2,     5,     5,
       5,     0,     1,     2,     1,     4,     0,     0,     1,     3,
       1,     4,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     1,     4,     3,     1,     1,     2,     2,     1,     0,
       3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
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
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 35 "1905066.y"
                {
		(yyval.symbolInfo) = new SymbolInfo("start", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		finishParsing((yyval.symbolInfo));
	}
#line 1521 "y.tab.cpp"
    break;

  case 3:
#line 41 "1905066.y"
                       {
		printLog("program : program unit");
		(yyval.symbolInfo) = new SymbolInfo("program", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo),(yyvsp[0].symbolInfo)});
	}
#line 1531 "y.tab.cpp"
    break;

  case 4:
#line 46 "1905066.y"
              {
		printLog("program : unit");
		(yyval.symbolInfo) = new SymbolInfo("program", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1541 "y.tab.cpp"
    break;

  case 5:
#line 53 "1905066.y"
                       {
		printLog("unit : var_declaration");
		(yyval.symbolInfo) = new SymbolInfo("unit", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1551 "y.tab.cpp"
    break;

  case 6:
#line 59 "1905066.y"
        {
		printLog("unit : func_declaration");
		(yyval.symbolInfo) = new SymbolInfo("unit", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1561 "y.tab.cpp"
    break;

  case 7:
#line 65 "1905066.y"
        {
		printLog("unit : func_definition");
		(yyval.symbolInfo) = new SymbolInfo("unit", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1571 "y.tab.cpp"
    break;

  case 8:
#line 72 "1905066.y"
                                                                            {
		printLog("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("func_declaration", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[-5].symbolInfo)->getDataType());

		addFunction((yyvsp[-4].symbolInfo), (yyvsp[-5].symbolInfo)->getDataType());

		(yyval.symbolInfo)->addChildren({(yyvsp[-5].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
	}
#line 1585 "y.tab.cpp"
    break;

  case 9:
#line 81 "1905066.y"
                                                    {
		printLog("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("func_declaration", (yyvsp[-4].symbolInfo)->getType());
		(yyval.symbolInfo)->setDataType((yyvsp[-4].symbolInfo)->getDataType());

		addFunction((yyvsp[-3].symbolInfo), (yyvsp[-4].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren({(yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
	}
#line 1598 "y.tab.cpp"
    break;

  case 10:
#line 91 "1905066.y"
                                                                 { 
		addFunction((yyvsp[-3].symbolInfo), (yyvsp[-4].symbolInfo)->getDataType(), true);
		inGlobalScope = false;
		genFunctioninitCode((yyvsp[-3].symbolInfo)->getName());
	}
#line 1608 "y.tab.cpp"
    break;

  case 11:
#line 95 "1905066.y"
                             {
		printLog("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
		(yyval.symbolInfo) = new SymbolInfo("func_definition", "non-terminal");

		(yyval.symbolInfo)->addChildren({(yyvsp[-6].symbolInfo), (yyvsp[-5].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)});
		
		//------------------code generation------------------
		auto func = symbolTable->lookup((yyvsp[-5].symbolInfo)->getName());
		if((yyvsp[0].symbolInfo)->getNextList().size() > 0){
			for(auto line : (yyvsp[0].symbolInfo)->getNextList()) function_return_lines.push_back(line);
		}
		genFunctionEndingCode(func);
	
	}
#line 1627 "y.tab.cpp"
    break;

  case 12:
#line 109 "1905066.y"
                                          { 
		addFunction((yyvsp[-2].symbolInfo), (yyvsp[-3].symbolInfo)->getDataType(), true); 
		inGlobalScope = false;
		genFunctioninitCode((yyvsp[-2].symbolInfo)->getName());
	}
#line 1637 "y.tab.cpp"
    break;

  case 13:
#line 113 "1905066.y"
                             {
		printLog("func_definition : type_specifier ID LPAREN RPAREN compound_statement");
		(yyval.symbolInfo) = new SymbolInfo("func_definition", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-5].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)});
		
		//------------------code generation------------------
		auto func = symbolTable->lookup((yyvsp[-4].symbolInfo)->getName());
		if((yyvsp[0].symbolInfo)->getNextList().size() > 0){
			for(auto line : (yyvsp[0].symbolInfo)->getNextList()) function_return_lines.push_back(line);
		}
		genFunctionEndingCode(func);

	}
#line 1655 "y.tab.cpp"
    break;

  case 14:
#line 128 "1905066.y"
                                                        {
		printLog("parameter_list : parameter_list COMMA type_specifier ID");
		(yyval.symbolInfo) = new SymbolInfo("parameter_list", (yyvsp[-3].symbolInfo)->getType());

		(yyvsp[0].symbolInfo)->setDataType((yyvsp[-1].symbolInfo)->getDataType());

		if(!checkParamRedeclaration((yyvsp[0].symbolInfo))) params.push_back((yyvsp[0].symbolInfo));
		
		
		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

	}
#line 1672 "y.tab.cpp"
    break;

  case 15:
#line 140 "1905066.y"
                                              {
		printLog("parameter_list : parameter_list COMMA type_specifier");
		(yyval.symbolInfo) = new SymbolInfo("parameter_list", (yyvsp[-2].symbolInfo)->getType());

		SymbolInfo* id = new SymbolInfo("", "ID", (yyvsp[0].symbolInfo)->getDataType());
		params.push_back(id);

		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
	}
#line 1686 "y.tab.cpp"
    break;

  case 16:
#line 149 "1905066.y"
                            {
		printLog("parameter_list : type_specifier ID");
		(yyval.symbolInfo) = new SymbolInfo("parameter_list", "non-terminal");

		(yyvsp[0].symbolInfo)->setDataType((yyvsp[-1].symbolInfo)->getDataType());
		if(!checkParamRedeclaration((yyvsp[0].symbolInfo))) params.push_back((yyvsp[0].symbolInfo));
		
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
	}
#line 1700 "y.tab.cpp"
    break;

  case 17:
#line 158 "1905066.y"
                         {
		printLog("parameter_list : type_specifier");
		(yyval.symbolInfo) = new SymbolInfo("parameter_list", "non-terminal");

		SymbolInfo* id = new SymbolInfo("", "ID", (yyvsp[0].symbolInfo)->getDataType());
		params.push_back(id);

		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1714 "y.tab.cpp"
    break;

  case 18:
#line 169 "1905066.y"
                           {symbolTable->enterScope(); addParamsToScope();}
#line 1720 "y.tab.cpp"
    break;

  case 19:
#line 169 "1905066.y"
                                                                                             {
		printLog("compound_statement : LCURL statements RCURL");
		(yyval.symbolInfo) = new SymbolInfo("compound_statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
		symbolTable->printAllScopeTable();
		symbolTable->exitScope();

		// ------------------code generation------------------
		// if($3->getNextList().size() > 0){
		// 	for(auto line : $3->getNextList()) function_return_lines.push_back(line);
		// }

		(yyval.symbolInfo)->setNextList((yyvsp[-1].symbolInfo)->getNextList());
		
	}
#line 1740 "y.tab.cpp"
    break;

  case 20:
#line 184 "1905066.y"
                {symbolTable->enterScope(); addParamsToScope();}
#line 1746 "y.tab.cpp"
    break;

  case 21:
#line 184 "1905066.y"
                                                                       {
		printLog("compound_statement : LCURL RCURL");
		(yyval.symbolInfo) = new SymbolInfo("compound_statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)});
		symbolTable->printAllScopeTable();
		symbolTable->exitScope();
	}
#line 1758 "y.tab.cpp"
    break;

  case 22:
#line 193 "1905066.y"
                                                            {
		printLog("var_declaration : type_specifier declaration_list SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("var_declaration", "non-terminal");
		setVarsDataType((yyvsp[-2].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		genVarDeclarationCode();

		// insert in symbol table
		for(auto var : vars){
			bool success = symbolTable->insert(var);
			if(!success){
				std::string error_message = "Redeclaration of variable '" + var->getName() + "'";
				semanticError(var->getStartLine(), error_message);
			}

			if((yyvsp[-2].symbolInfo)->getDataType() == "VOID"){
				std::string error_message = "Variable or field '" + var->getName() + "' declared void";
				semanticError(var->getStartLine(), error_message);
			}
		}

	}
#line 1786 "y.tab.cpp"
    break;

  case 23:
#line 218 "1905066.y"
                     {
		printLog("type_specifier : INT");
		(yyval.symbolInfo) = new SymbolInfo("type_specifier", "INT", (yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		
	}
#line 1797 "y.tab.cpp"
    break;

  case 24:
#line 224 "1905066.y"
                {
		printLog("type_specifier : FLOAT");
		(yyval.symbolInfo) = new SymbolInfo("type_specifier", "FLOAT", (yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		
	}
#line 1808 "y.tab.cpp"
    break;

  case 25:
#line 230 "1905066.y"
               {
		printLog("type_specifier : VOID");
		(yyval.symbolInfo) = new SymbolInfo("type_specifier", "VOID", (yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		
	}
#line 1819 "y.tab.cpp"
    break;

  case 26:
#line 238 "1905066.y"
                                             {
		printLog("declaration_list : declaration_list COMMA ID");
		(yyval.symbolInfo) = new SymbolInfo("declaration_list", "non-terminal");
		vars.push_back((yyvsp[0].symbolInfo));

		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo),(yyvsp[-1].symbolInfo),(yyvsp[0].symbolInfo)});
	}
#line 1831 "y.tab.cpp"
    break;

  case 27:
#line 245 "1905066.y"
                                                            {
		printLog("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
		(yyval.symbolInfo) = new SymbolInfo("declaration_list", "non-terminal");
		(yyvsp[-3].symbolInfo)->setArray(true, std::stoi((yyvsp[-1].symbolInfo)->getName()));
		vars.push_back((yyvsp[-3].symbolInfo));

		(yyval.symbolInfo)->addChildren({(yyvsp[-5].symbolInfo),(yyvsp[-4].symbolInfo),(yyvsp[-3].symbolInfo),(yyvsp[-2].symbolInfo),(yyvsp[-1].symbolInfo),(yyvsp[0].symbolInfo)});
	}
#line 1844 "y.tab.cpp"
    break;

  case 28:
#line 253 "1905066.y"
             {
		printLog("declaration_list : ID");
		vars.clear();
		(yyval.symbolInfo) = new SymbolInfo("declaration_list", "non-terminal");
		vars.push_back((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		
	}
#line 1857 "y.tab.cpp"
    break;

  case 29:
#line 261 "1905066.y"
                                     {
		printLog("declaration_list : ID LTHIRD CONST_INT RTHIRD");
		vars.clear();
		(yyval.symbolInfo) = new SymbolInfo("declaration_list", "non-terminal");
		(yyvsp[-3].symbolInfo)->setArray(true, std::stoi((yyvsp[-1].symbolInfo)->getName()));
		vars.push_back((yyvsp[-3].symbolInfo));

		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo),(yyvsp[-2].symbolInfo),(yyvsp[-1].symbolInfo),(yyvsp[0].symbolInfo)});
	}
#line 1871 "y.tab.cpp"
    break;

  case 30:
#line 272 "1905066.y"
             {genComment("------------------ Line " + to_string(line_count) + " ------------------");}
#line 1877 "y.tab.cpp"
    break;

  case 31:
#line 272 "1905066.y"
                                                                                                                 {
		printLog("statements : statement");
		(yyval.symbolInfo) = new SymbolInfo("statements", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		// ------------------ code generation ------------------
		(yyval.symbolInfo)->setNextList((yyvsp[0].symbolInfo)->getNextList());
		
		// std::cout<<"here - "<<$2->getLabel()<<std::endl;
		// backpatch($1->getNextList(), $2->getLabel());
	}
#line 1893 "y.tab.cpp"
    break;

  case 32:
#line 283 "1905066.y"
                       {genComment("------------------ Line " + to_string(line_count) + " ------------------");}
#line 1899 "y.tab.cpp"
    break;

  case 33:
#line 283 "1905066.y"
                                                                                                                           {
		printLog("statements : statements statement");
		(yyval.symbolInfo) = new SymbolInfo("statements", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[0].symbolInfo)});

		// ------------------ code generation ------------------
		backpatch((yyvsp[-3].symbolInfo)->getNextList(), (yyvsp[-2].symbolInfo)->getLabel());
		(yyval.symbolInfo)->setNextList((yyvsp[0].symbolInfo)->getNextList());
	}
#line 1913 "y.tab.cpp"
    break;

  case 34:
#line 294 "1905066.y"
                            {
		printLog("statement : var_declaration");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 1923 "y.tab.cpp"
    break;

  case 35:
#line 299 "1905066.y"
                               {
		printLog("statement : expression statement");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));

		if(!(yyvsp[0].symbolInfo)->getTrueList().empty()){
			std::string label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 1");
			(yyval.symbolInfo)->addToNextList(temp_asm_line_count);
			genCode("\tJMP ");
			backpatch((yyvsp[0].symbolInfo)->getTrueList(), label);

			label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 0");
			backpatch((yyvsp[0].symbolInfo)->getFalseList(), label);

			// label = new_label();
			// genCode(label + ":");
			// backpatch($$->getNextList(), label);			
		}

		
	}
#line 1954 "y.tab.cpp"
    break;

  case 36:
#line 325 "1905066.y"
                             {
		printLog("statement : compound_statement");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		// ------------------ code generation ------------------
		(yyval.symbolInfo)->setNextList((yyvsp[0].symbolInfo)->getNextList());
	}
#line 1967 "y.tab.cpp"
    break;

  case 37:
#line 333 "1905066.y"
                                                                 { normal_expression_to_logic((yyvsp[0].symbolInfo), false); }
#line 1973 "y.tab.cpp"
    break;

  case 38:
#line 333 "1905066.y"
                                                                                                                         {genCode("\tPOP AX"); genCode("\tJMP " + (yyvsp[-4].symbolInfo)->getLabel());}
#line 1979 "y.tab.cpp"
    break;

  case 39:
#line 333 "1905066.y"
                                                                                                                                                                                                       {
		printLog("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-11].symbolInfo), (yyvsp[-10].symbolInfo), (yyvsp[-9].symbolInfo), (yyvsp[-7].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)});

		//------------------code generation------------------
		auto S1 = (yyvsp[-9].symbolInfo);
		auto B = (yyvsp[-7].symbolInfo);
		auto S2 = (yyvsp[-4].symbolInfo);
		auto S3 = (yyvsp[0].symbolInfo);
		auto M1 = (yyvsp[-8].symbolInfo);
		auto M2 = (yyvsp[-5].symbolInfo);
		auto M3 = (yyvsp[-1].symbolInfo);

		normal_expression_to_logic(B);

		backpatch(B->getTrueList(), M3->getLabel());
		backpatch(S3->getNextList(), M2->getLabel());
		// $$->setNextList(merge(B->getFalseList(), S3->getNextList()));
		(yyval.symbolInfo)->setNextList(B->getFalseList());
		genCode("\tJMP " + M2->getLabel());

	}
#line 2007 "y.tab.cpp"
    break;

  case 40:
#line 356 "1905066.y"
                                                                          {
		printLog("statement : IF LPAREN expression RPAREN statement");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-6].symbolInfo), (yyvsp[-5].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)});

		//------------------code generation------------------
		backpatch((yyvsp[-4].symbolInfo)->getTrueList(), (yyvsp[-1].symbolInfo)->getLabel());
		(yyval.symbolInfo)->setNextList(merge((yyvsp[-4].symbolInfo)->getFalseList(), (yyvsp[0].symbolInfo)->getNextList()));

	}
#line 2022 "y.tab.cpp"
    break;

  case 41:
#line 366 "1905066.y"
                                                                       {
		printLog("statement : IF LPAREN expression RPAREN statement ELSE statement");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-10].symbolInfo), (yyvsp[-9].symbolInfo), (yyvsp[-8].symbolInfo), (yyvsp[-6].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[0].symbolInfo)});

		//------------------code generation------------------
		auto B = (yyvsp[-8].symbolInfo);
		auto M1 = (yyvsp[-5].symbolInfo);
		auto M2 = (yyvsp[-1].symbolInfo);
		auto N = (yyvsp[-2].symbolInfo);
		auto S1 = (yyvsp[-4].symbolInfo);
		auto S2 = (yyvsp[0].symbolInfo);

		backpatch(B->getTrueList(), M1->getLabel());
		backpatch(B->getFalseList(), M2->getLabel());
		auto temp = merge(S1->getNextList(), N->getNextList());
		(yyval.symbolInfo)->setNextList(merge(temp, S2->getNextList()));

	}
#line 2046 "y.tab.cpp"
    break;

  case 42:
#line 385 "1905066.y"
                                    { normal_expression_to_logic((yyvsp[0].symbolInfo)); }
#line 2052 "y.tab.cpp"
    break;

  case 43:
#line 385 "1905066.y"
                                                                                           {
		printLog("statement : WHILE LPAREN expression RPAREN statement");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-7].symbolInfo), (yyvsp[-5].symbolInfo), (yyvsp[-4].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo)});

		//------------------code generation------------------
		auto M1 = (yyvsp[-6].symbolInfo);
		auto B = (yyvsp[-4].symbolInfo);
		auto M2 = (yyvsp[-1].symbolInfo);
		auto S1 = (yyvsp[-2].symbolInfo);

		backpatch(S1->getNextList(), M1->getLabel());
		backpatch(B->getTrueList(), M2->getLabel());
		(yyval.symbolInfo)->setNextList(B->getFalseList());
		genCode("\tJMP " + M1->getLabel());
	}
#line 2073 "y.tab.cpp"
    break;

  case 44:
#line 419 "1905066.y"
                                                      {
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
		printExpression((yyvsp[-2].symbolInfo), true);
	}
#line 2083 "y.tab.cpp"
    break;

  case 45:
#line 424 "1905066.y"
                                                   {
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
		printExpression((yyvsp[-2].symbolInfo), false);
	}
#line 2093 "y.tab.cpp"
    break;

  case 46:
#line 429 "1905066.y"
                                      {
		printLog("statement : RETURN expression SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		//------------------code generation------------------
		genCode("\tPOP AX");
		function_return_lines.push_back(temp_asm_line_count);
		genCode("\tJMP ");
	}
#line 2108 "y.tab.cpp"
    break;

  case 47:
#line 439 "1905066.y"
                          {
		printLog("statement : RETURN SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
		function_return_lines.push_back(temp_asm_line_count);
		genCode("\tJMP ");
	}
#line 2120 "y.tab.cpp"
    break;

  case 48:
#line 446 "1905066.y"
                                                       {
		printLog("statement : PRINTLN LPAREN RPAREN SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		//------------------code generation------------------
		printString((yyvsp[-2].symbolInfo), true);
	}
#line 2133 "y.tab.cpp"
    break;

  case 49:
#line 454 "1905066.y"
                                                     {
		printLog("statement : PRINTLN LPAREN RPAREN SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("statement", "non-terminal");
		(yyval.symbolInfo)->addChildren({(yyvsp[-4].symbolInfo), (yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		//------------------code generation------------------
		printString((yyvsp[-2].symbolInfo), false);
	}
#line 2146 "y.tab.cpp"
    break;

  case 50:
#line 462 "1905066.y"
                                                  {
		genCode("\tCALL int_intput");
		genCode("\tMOV AX, INT_");
		if((yyvsp[-4].symbolInfo)->isArray() && !(yyvsp[-4].symbolInfo)->isGlobalVar()) genCode("\tPOP BX");
		genCode("\tMOV " + (yyvsp[-2].symbolInfo)->getAsmName() + ", AX");
	}
#line 2157 "y.tab.cpp"
    break;

  case 51:
#line 470 "1905066.y"
    {	
		normal_expression_to_logic((yyvsp[0].symbolInfo)); 
	}
#line 2165 "y.tab.cpp"
    break;

  case 52:
#line 474 "1905066.y"
                                 {
		printLog("expression_statement : SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("expression_statement", "non-terminal");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2175 "y.tab.cpp"
    break;

  case 53:
#line 479 "1905066.y"
                               {
		printLog("expression_statement : expression SEMICOLON");
		(yyval.symbolInfo) = new SymbolInfo("expression_statement", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[-1].symbolInfo));
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
		//------------------code generation------------------
		genCode("\tPOP AX");
	}
#line 2188 "y.tab.cpp"
    break;

  case 54:
#line 489 "1905066.y"
              {
		printLog("variable : ID");
		
		auto symbol = checkValidVar((yyvsp[0].symbolInfo));
		
		if(symbol) (yyval.symbolInfo) = new SymbolInfo(symbol);
		else (yyval.symbolInfo) = new SymbolInfo((yyvsp[0].symbolInfo));
		
		(yyval.symbolInfo)->setName("variable");
		(yyval.symbolInfo)->setType("non-terminal");

		
		if(symbol) (yyval.symbolInfo)->setDataType(symbol->getDataType());
		else (yyval.symbolInfo)->setDataType("ERROR");
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		// ------------------code generation------------------
		// asmName is set in copy constructor
	}
#line 2212 "y.tab.cpp"
    break;

  case 55:
#line 508 "1905066.y"
                                      {
		printLog("variable : ID LTHIRD expression RTHIRD");

		(yyvsp[-3].symbolInfo)->setArray();

		auto symbol = checkValidVar((yyvsp[-3].symbolInfo), true);
		if(symbol) (yyval.symbolInfo) = new SymbolInfo(symbol);
		else (yyval.symbolInfo) = new SymbolInfo((yyvsp[-3].symbolInfo));
		
		(yyval.symbolInfo)->setName("variable");
		(yyval.symbolInfo)->setType("non-terminal");

		
		if(symbol) (yyval.symbolInfo)->setDataType(symbol->getDataType());
		else (yyval.symbolInfo)->setDataType("ERROR");
		
		if((yyvsp[-1].symbolInfo)->getDataType() != "INT"){
			// index must be integer
			std::string error_message = "Array subscript is not an integer";
			semanticError((yyvsp[-1].symbolInfo)->getStartLine(), error_message);
		}
		
		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ------------------code generation------------------
		genCode("\tPOP AX");							// get the value of index from expression(stack)
		genCode("\tSHL AX, 1"); 						// multiply by 2
		genCode("\tLEA BX, " + symbol->getAsmName()); 	// get the address of array[0]
		genCode("\tSUB BX, AX"); 						// get the address of array[index]
		genCode("\tPUSH BX"); 							// push the address of array[index] to stack
		(yyval.symbolInfo)->setAsmName("[BX]"); 
	}
#line 2249 "y.tab.cpp"
    break;

  case 56:
#line 542 "1905066.y"
    {
		(yyval.symbolInfo) = new SymbolInfo();
		(yyval.symbolInfo)->addToNextList(temp_asm_line_count);
		genCode("\tJMP ");
	}
#line 2259 "y.tab.cpp"
    break;

  case 57:
#line 549 "1905066.y"
    {
		std::string label = new_label();
		(yyval.symbolInfo) = new SymbolInfo();
		(yyval.symbolInfo)->setLabel(label);

		//------------------code generation------------------
		genCode(label + ":");
	}
#line 2272 "y.tab.cpp"
    break;

  case 58:
#line 562 "1905066.y"
                              {
		printLog("expression : logic_expression");
		(yyval.symbolInfo) = new SymbolInfo("expression", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2283 "y.tab.cpp"
    break;

  case 59:
#line 568 "1905066.y"
                                             {
		printLog("expression : variable ASSIGNOP logic_expression");
		(yyval.symbolInfo) = new SymbolInfo("expression", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[-2].symbolInfo)->getDataType());
		if((yyvsp[0].symbolInfo)->getDataType() == "VOID"){
			// can't assign  void
			(yyval.symbolInfo)->setDataType("VOID");
			std::string error_message = "Void cannot be used in expression ";
			semanticError((yyvsp[0].symbolInfo)->getStartLine(), error_message);
		}

		else if((yyvsp[-2].symbolInfo)->getDataType() == "VOID"){
			// can't assign to  void
			(yyval.symbolInfo)->setDataType("VOID");
			std::string error_message = "Void cannot be used in expression ";
			semanticError((yyvsp[-2].symbolInfo)->getStartLine(), error_message);
		}

		if((yyvsp[-2].symbolInfo)->getDataType() == "INT" && (yyvsp[0].symbolInfo)->getDataType() == "FLOAT"){
			std::string error_message = "Warning: possible loss of data in assignment of FLOAT to INT";
			semanticError((yyvsp[-2].symbolInfo)->getStartLine(), error_message);
		}

		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ------------------code generation------------------

		(yyval.symbolInfo)->clearNextList();
		if(!(yyvsp[0].symbolInfo)->getTrueList().empty()){
			std::string label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 1");
			(yyval.symbolInfo)->addToNextList(temp_asm_line_count);
			genCode("\tJMP ");
			backpatch((yyvsp[0].symbolInfo)->getTrueList(), label);

			label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 0");
			backpatch((yyvsp[0].symbolInfo)->getFalseList(), label);

			label = new_label();
			genCode(label + ":");
			backpatch((yyval.symbolInfo)->getNextList(), label);			
		}
		genCode("\tPOP AX");
		if((yyvsp[-2].symbolInfo)->isArray() && !(yyvsp[-2].symbolInfo)->isGlobalVar()) genCode("\tPOP BX");
		genCode("\tMOV " + (yyvsp[-2].symbolInfo)->getAsmName() + ", AX");
		genCode("\tPUSH AX");
		(yyval.symbolInfo)->clearNextList();
	}
#line 2339 "y.tab.cpp"
    break;

  case 60:
#line 621 "1905066.y"
                                  {
		printLog("logic_expression : rel_expression");
		(yyval.symbolInfo) = new SymbolInfo("logic_expression", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2350 "y.tab.cpp"
    break;

  case 61:
#line 627 "1905066.y"
                                                  {
		printLog("logic_expression : rel_expression LOGICOP rel_expression");
		(yyval.symbolInfo) = new SymbolInfo("logic_expression", "non-terminal");
		(yyval.symbolInfo)->setDataType("INT");

		if((yyvsp[-3].symbolInfo)->getDataType() == "VOID" || (yyvsp[-1].symbolInfo)->getDataType() == "VOID"){
			(yyval.symbolInfo)->setDataType("VOID");
			// std::string error_message = "Can't do logic operations void";
			// semanticError($3->getStartLine(), error_message);
		}

		(yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo)});

		// ------------------code generation------------------
		// short circuit code and backpatching
		SymbolInfo* B = (yyval.symbolInfo);
		SymbolInfo* B1 = (yyvsp[-3].symbolInfo);
		SymbolInfo* B2 = (yyvsp[0].symbolInfo);

		// careful with the order
		normal_expression_to_logic(B2);
		normal_expression_to_logic(B1);

		if((yyvsp[-2].symbolInfo)->getName() == "&&"){
			backpatch(B1->getTrueList(), (yyvsp[-1].symbolInfo)->getLabel());
			B->setTrueList(B2->getTrueList());
			B->setFalseList(merge(B1->getFalseList(), B2->getFalseList()));
		}
		else if((yyvsp[-2].symbolInfo)->getName() == "||"){
			backpatch(B1->getFalseList(), (yyvsp[-1].symbolInfo)->getLabel());
			B->setFalseList(B2->getFalseList());
			B->setTrueList(merge(B1->getTrueList(), B2->getTrueList()));
		}
		genCode("\tPUSH AX");
	}
#line 2390 "y.tab.cpp"
    break;

  case 62:
#line 664 "1905066.y"
                                   {
		printLog("rel_expression : simple_expression");
		(yyval.symbolInfo) = new SymbolInfo("rel_expression", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2402 "y.tab.cpp"
    break;

  case 63:
#line 671 "1905066.y"
                                                    {
		printLog("rel_expression : simple_expression RELOP simple_expression");
		(yyval.symbolInfo) = new SymbolInfo("rel_expression", "non-terminal");
		(yyval.symbolInfo)->setDataType("INT");

		if((yyvsp[-2].symbolInfo)->getDataType() == "VOID" || (yyvsp[0].symbolInfo)->getDataType() == "VOID"){
			// can't compare void
			(yyval.symbolInfo)->setDataType("VOID");
			// std::string error_message = "Can't compare void";
			// semanticError($3->getStartLine(), error_message);
		}

		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ------------------code generation------------------
		genCode("\tPOP BX");
		genCode("\tPOP AX");
		genCode("\tCMP AX, BX");

		(yyval.symbolInfo)->addToTrueList(temp_asm_line_count);
		(yyval.symbolInfo)->addToFalseList(temp_asm_line_count + 1);

		string op = (yyvsp[-1].symbolInfo)->getName();
		if(op == "<") genCode("\tJL ");
		else if(op == ">") genCode("\tJG ");
		else if(op == "<=") genCode("\tJLE ");
		else if(op == ">=") genCode("\tJGE ");
		else if(op == "==") genCode("\tJE ");
		else if(op == "!=") genCode("\tJNE ");
		
		genCode("\tJMP ");
	}
#line 2439 "y.tab.cpp"
    break;

  case 64:
#line 705 "1905066.y"
                         {
		printLog("simple_expression : term");
		(yyval.symbolInfo) = new SymbolInfo("simple_expression", "non-terminal");
		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2451 "y.tab.cpp"
    break;

  case 65:
#line 712 "1905066.y"
                                       {
		printLog("simple_expression : simple_expression ADDOP term");
		(yyval.symbolInfo) = new SymbolInfo("simple_expression", "non-terminal");
		(yyval.symbolInfo)->setDataType(typecast((yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)));

		if((yyvsp[0].symbolInfo)->getDataType() == "VOID"){
			std::string error_message = "Can't add void";
			semanticError((yyvsp[0].symbolInfo)->getStartLine(), error_message);
			(yyval.symbolInfo)->setDataType("VOID");
		}

		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		genCode("\tPOP BX");
		genCode("\tPOP AX");
		if((yyvsp[-1].symbolInfo)->getName() == "+") genCode("\tADD AX, BX");
		else genCode("\tSUB AX, BX");
		genCode("\tPUSH AX");
	}
#line 2476 "y.tab.cpp"
    break;

  case 66:
#line 734 "1905066.y"
                        {
		printLog("term : unary_expression");
		(yyval.symbolInfo) = new SymbolInfo("term", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
	}
#line 2489 "y.tab.cpp"
    break;

  case 67:
#line 742 "1905066.y"
                                      {
		printLog("term : term MULOP unary_expression");
		(yyval.symbolInfo) = new SymbolInfo("term", "non-terminal");
		(yyval.symbolInfo)->setDataType(typecast((yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)));

		if((yyvsp[0].symbolInfo)->getDataType() == "VOID"){
			// unary expression can't be void
			(yyval.symbolInfo)->setDataType("VOID");
			// std::string error_message = "unary expression can't be void";
			// semanticError($3->getStartLine(), error_message);
		}

		if((yyvsp[-1].symbolInfo)->getName() == "%" && ((yyvsp[-2].symbolInfo)->getDataType() != "INT" || (yyvsp[0].symbolInfo)->getDataType() != "INT")){
			// not int in modulus
			(yyval.symbolInfo)->setDataType("INT");
			std::string error_message = "Operands of modulus must be integers ";
			semanticError((yyvsp[0].symbolInfo)->getStartLine(), error_message);
		}

		else if(((yyvsp[-1].symbolInfo)->getName() == "/" || (yyvsp[-1].symbolInfo)->getName() == "%") && (yyvsp[0].symbolInfo)->getValue() == "0"){
			// division by zero
			std::string error_message = "Warning: division by zero";
			semanticError((yyvsp[0].symbolInfo)->getStartLine(), error_message);
		}

		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		genCode("\tPOP BX");
		genCode("\tPOP AX");
		//genCode("\tXOR DX, DX");
		genCode("\tCWD");
		if((yyvsp[-1].symbolInfo)->getName() == "*") genCode("\tIMUL BX");
		else genCode("\tIDIV BX");

		if((yyvsp[-1].symbolInfo)->getName() != "%") genCode("\tPUSH AX");
		else genCode("\tPUSH DX");

		/*	multiply A x B
			code : IMUL source
				A: source
				B: ax
				Product (ms 16 bits): dx 
				Product (ls 16 bits): ax

			division
			code : IDIV source
				Divisor: source; Dividend: dx:ax 
				Quotient: ax; Remainder: dx
		*/
		
	}
#line 2546 "y.tab.cpp"
    break;

  case 68:
#line 796 "1905066.y"
                                          {
		printLog("unary_expression : ADDOP unary_expression");
		(yyval.symbolInfo) = new SymbolInfo("unary_expression", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());

		if((yyvsp[0].symbolInfo)->getDataType() == "VOID"){
			// unary expression can't be void
			(yyval.symbolInfo)->setDataType("VOID");
			// std::string error_message = "unary expression can't be void";
			// semanticError($2->getStartLine(), error_message);
		}

		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		if((yyvsp[-1].symbolInfo)->getName() == "-"){
			genCode("\tPOP AX");
			genCode("\tNEG AX");
			genCode("\tPUSH AX");
		}
	}
#line 2572 "y.tab.cpp"
    break;

  case 69:
#line 817 "1905066.y"
                               {
		printLog("unary_expression : NOT unary_expression");
		(yyval.symbolInfo) = new SymbolInfo("unary_expression", "non-terminal");
		(yyval.symbolInfo)->setDataType("INT");

		if((yyvsp[0].symbolInfo)->getDataType() == "VOID"){
			// unary expression can't be void
			(yyval.symbolInfo)->setDataType("VOID");
			// std::string error_message = "unary expression can't be void";
			// semanticError($2->getStartLine(), error_message);
		}
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		// genCode("\tPOP AX");
		// genCode("\tCMP AX, 0");

		// string label1 = "LL0";
		// string label2 = "LL1";

		// genCode("\tJNE " + label1);
		// genCode("\tPUSH 1");
		// genCode("\tJMP " + label2);
		// genCode(label1 + ":");
		// genCode("\tPUSH 0");
		// genCode(label2 + ":");

		(yyval.symbolInfo)->setTrueList((yyvsp[0].symbolInfo)->getFalseList());
		(yyval.symbolInfo)->setFalseList((yyvsp[0].symbolInfo)->getTrueList());

	}
#line 2608 "y.tab.cpp"
    break;

  case 70:
#line 848 "1905066.y"
                 {
		printLog("unary_expression : factor");
		(yyval.symbolInfo) = new SymbolInfo("unary_expression", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->setValue((yyvsp[0].symbolInfo)->getValue());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		(yyval.symbolInfo)->copyICGData((yyvsp[0].symbolInfo));
	}
#line 2622 "y.tab.cpp"
    break;

  case 71:
#line 859 "1905066.y"
                  {
		printLog("factor : variable");
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[0].symbolInfo)->getDataType());
		(yyval.symbolInfo)->setArray((yyvsp[0].symbolInfo)->isArray());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		// ---------------------Code generation---------------------
		if((yyvsp[0].symbolInfo)->isArray() && !(yyvsp[0].symbolInfo)->isGlobalVar()) genCode("\tPOP BX");
		genCode("\tMOV AX, " + (yyvsp[0].symbolInfo)->getAsmName());
		genCode("\tPUSH AX");

	}
#line 2640 "y.tab.cpp"
    break;

  case 72:
#line 872 "1905066.y"
                                         {
		printLog("factor : ID LPAREN argument_list RPAREN");
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");
		(yyval.symbolInfo)->setDataType("");

		SymbolInfo *symbol= symbolTable->lookup((yyvsp[-3].symbolInfo)->getName());

		if(!symbol){
			std::string error_message = "Undeclared function '" + (yyvsp[-3].symbolInfo)->getName() + "'";
			semanticError((yyvsp[-3].symbolInfo)->getStartLine(), error_message);
			(yyval.symbolInfo)->setDataType("ERROR");
		}
		
		else{
			
			(yyval.symbolInfo)->setDataType(symbol->getDataType());
			// if not function
			if(!symbol->isFunction()){
				std::string error_message = (yyvsp[-3].symbolInfo)->getName() + " is not a function";
				semanticError((yyvsp[-3].symbolInfo)->getStartLine(), error_message);
			}

			// else if paramater size not equal
			else if(symbol->getParamCount() > (yyvsp[-1].symbolInfo)->getParamCount()){
				std::string error_message = "Too few arguments to function '" + (yyvsp[-3].symbolInfo)->getName() + "'";
				semanticError((yyvsp[-3].symbolInfo)->getStartLine(), error_message);
			}

			else if(symbol->getParamCount() < (yyvsp[-1].symbolInfo)->getParamCount()){
				std::string error_message = "Too many arguments to function '" + (yyvsp[-3].symbolInfo)->getName() + "'";
				semanticError((yyvsp[-3].symbolInfo)->getStartLine(), error_message);
			}

			// else if parameter type mismatch
			else{
				vector<SymbolInfo*> params = symbol->getParams();
				vector<SymbolInfo*> args = (yyvsp[-1].symbolInfo)->getParams();

				for(int i=0; i<params.size(); i++){

					if(params[i]->getDataType() != args[i]->getDataType()){
						
						// typecast?
						if(!(params[i]->getDataType() == "INT" || params[i]->getDataType() == "FLOAT") && (args[i]->getDataType() == "INT" || args[i]->getDataType() == "FLOAT"))
						{
							std::string error_message = "Parameter type mismatch ( For " + std::to_string(i+1) +"th parameter ) in function " + symbol->getName() + " at line " + std::to_string(symbol->getStartLine());
							semanticError((yyvsp[-3].symbolInfo)->getStartLine(), error_message);
						}
					}
				}
			} 
		}

		if((yyvsp[-1].symbolInfo)->getChildrenSize() == 0) (yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[0].symbolInfo)});
		else (yyval.symbolInfo)->addChildren({(yyvsp[-3].symbolInfo), (yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});


		// ---------------------Code generation---------------------
		genCode("\tCALL " + (yyvsp[-3].symbolInfo)->getName());
		if((yyval.symbolInfo)->getDataType() != "VOID") genCode("\tPUSH AX");
		else genCode("\tPUSH 0");
	}
#line 2707 "y.tab.cpp"
    break;

  case 73:
#line 934 "1905066.y"
                                   {
		printLog("factor : LPAREN expression RPAREN");
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");
		(yyval.symbolInfo)->setDataType((yyvsp[-1].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		(yyval.symbolInfo)->setTrueList((yyvsp[-1].symbolInfo)->getTrueList());
		(yyval.symbolInfo)->setFalseList((yyvsp[-1].symbolInfo)->getFalseList());
	}
#line 2722 "y.tab.cpp"
    break;

  case 74:
#line 944 "1905066.y"
                    {
		printLog("factor : CONST_INT");
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");
		(yyval.symbolInfo)->setDataType("INT");
		(yyval.symbolInfo)->setValue((yyvsp[0].symbolInfo)->getName());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));

		// ---------------------Code generation---------------------
		// genCode("\tMOV AX, " + $1->getName());
		// genCode("\tPUSH AX");
		genCode("\tPUSH " + (yyvsp[0].symbolInfo)->getName());
	}
#line 2739 "y.tab.cpp"
    break;

  case 75:
#line 956 "1905066.y"
                      {
		printLog("factor : CONST_FLOAT");
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");
		(yyval.symbolInfo)->setDataType("FLOAT");
		(yyval.symbolInfo)->setValue((yyvsp[0].symbolInfo)->getName());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2751 "y.tab.cpp"
    break;

  case 76:
#line 963 "1905066.y"
                         {
		printLog("factor: variable INCOP");
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");

		if((yyvsp[-1].symbolInfo)->isArray()){
			// array can't be incremented
			std::string error_message = "Array can't be incremented";
			semanticError((yyvsp[-1].symbolInfo)->getStartLine(), error_message);
		}

		(yyval.symbolInfo)->setDataType((yyvsp[-1].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		genINC_DEC((yyvsp[-1].symbolInfo), "++");
	}
#line 2772 "y.tab.cpp"
    break;

  case 77:
#line 979 "1905066.y"
                         {
		printLog("factor: variable DECOP");
		
		(yyval.symbolInfo) = new SymbolInfo("factor", "non-terminal");

		if((yyvsp[-1].symbolInfo)->isArray()){
			// array can't be decremented
			std::string error_message = "Array can't be decremented";
			semanticError((yyvsp[-1].symbolInfo)->getStartLine(), error_message);
		}

		(yyval.symbolInfo)->setDataType((yyvsp[-1].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addChildren({(yyvsp[-1].symbolInfo),(yyvsp[0].symbolInfo)});

		// ---------------------Code generation---------------------
		genINC_DEC((yyvsp[-1].symbolInfo), "--");
	}
#line 2794 "y.tab.cpp"
    break;

  case 78:
#line 998 "1905066.y"
                          {
		printLog("argument_list : arguments");
		(yyval.symbolInfo) = new SymbolInfo("argument_list", "non-terminal");
		(yyval.symbolInfo)->setParams((yyvsp[0].symbolInfo)->getParams());
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2805 "y.tab.cpp"
    break;

  case 79:
#line 1004 "1905066.y"
          {
		printLog("argument_list : ");
		(yyval.symbolInfo) = new SymbolInfo("argument_list", "non-terminal");
	}
#line 2814 "y.tab.cpp"
    break;

  case 80:
#line 1010 "1905066.y"
                                             {
		printLog("arguments : arguments COMMA logic_expression");
		(yyval.symbolInfo) = new SymbolInfo("arguments", "non-terminal");
		(yyval.symbolInfo)->setParams((yyvsp[-2].symbolInfo)->getParams());
		(yyval.symbolInfo)->addParam((yyvsp[0].symbolInfo));					 
		(yyval.symbolInfo)->addChildren({(yyvsp[-2].symbolInfo), (yyvsp[-1].symbolInfo), (yyvsp[0].symbolInfo)});
	}
#line 2826 "y.tab.cpp"
    break;

  case 81:
#line 1017 "1905066.y"
                           {
		printLog("arguments : logic_expression");
		(yyval.symbolInfo) = new SymbolInfo("arguments", "non-terminal");
		(yyval.symbolInfo)->addParam((yyvsp[0].symbolInfo));
		(yyval.symbolInfo)->addChildren((yyvsp[0].symbolInfo));
	}
#line 2837 "y.tab.cpp"
    break;


#line 2841 "y.tab.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1025 "1905066.y"

extern "C" {
int main()
{
	printf("starting. Hello World\n");


	init_count();

	
	FILE* fp;
	fp=fopen("files/input.c","r");

	yyin=fp;
	errorOut.open("files/error.txt");
	logout.open("files/log.txt");
	parseTreeOut.open("files/parseTree.txt");
	
	
	asmInit();
	
	yyparse();
	yylex_destroy();

	generate_asm_file();
	generate_Optimize_Code();
	closeAsmFiles();
	
	errorOut.close();
	logout.close();
	parseTreeOut.close();

	fclose(fp);
	

	return 0;
}
}

