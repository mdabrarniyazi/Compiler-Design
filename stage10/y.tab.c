/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "stage10.y" /* yacc.c:339  */

#include"lex.yy.c"
#include<stdio.h>
#include<string>

#include"symbol.cpp"
#include"exptree.cpp"
#include "machinecode.h"
void yyerror(const char *);
using namespace std;
char *name;
char *func_name;
int global_type=-1;  // 0 for integer and 1 for boolean
int local_type=-1;

#line 82 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    NUM = 258,
    COND = 259,
    INT = 260,
    BOOL = 261,
    ID = 262,
    READ = 263,
    WRITE = 264,
    IF = 265,
    THEN = 266,
    BEGINP = 267,
    END = 268,
    RETURN = 269,
    ENDPRG = 270,
    ENDIF = 271,
    WHILE = 272,
    DO = 273,
    ENDWHILE = 274,
    EQQ = 275,
    ANDY = 276,
    ORY = 277,
    NOTY = 278,
    DECL = 279,
    ENDDECL = 280,
    MAIN = 281
  };
#endif
/* Tokens.  */
#define NUM 258
#define COND 259
#define INT 260
#define BOOL 261
#define ID 262
#define READ 263
#define WRITE 264
#define IF 265
#define THEN 266
#define BEGINP 267
#define END 268
#define RETURN 269
#define ENDPRG 270
#define ENDIF 271
#define WHILE 272
#define DO 273
#define ENDWHILE 274
#define EQQ 275
#define ANDY 276
#define ORY 277
#define NOTY 278
#define DECL 279
#define ENDDECL 280
#define MAIN 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 17 "stage10.y" /* yacc.c:355  */

int ival;
struct xtree *nptr;
char* chid;
struct argstruct *alist;

#line 181 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 196 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,     2,
      35,    36,    29,    27,    34,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
      31,    42,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    63,    65,    76,    79,    80,    83,    83,
      86,    87,    90,    96,   105,   113,   114,   118,   149,   117,
     164,   165,   165,   166,   166,   169,   176,   181,   189,   200,
     201,   204,   205,   207,   219,   234,   241,   233,   253,   287,
     289,   290,   293,   294,   297,   325,   337,   365,   380,   381,
     382,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   409,   434,   437,   440,   476,   485,   486,
     489
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "COND", "INT", "BOOL", "ID",
  "READ", "WRITE", "IF", "THEN", "BEGINP", "END", "RETURN", "ENDPRG",
  "ENDIF", "WHILE", "DO", "ENDWHILE", "EQQ", "ANDY", "ORY", "NOTY", "DECL",
  "ENDDECL", "MAIN", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'", "';'",
  "','", "'('", "')'", "'['", "']'", "'{'", "'}'", "'&'", "'='", "$accept",
  "Prog", "$@1", "GDefblock", "GDefList", "GDecl", "$@2", "GIdList", "GId",
  "Fdeflist", "Fdef", "$@3", "$@4", "Arglist", "$@5", "$@6", "alist",
  "LDefblock", "LDefList", "LIDlist", "Mainblock", "$@7", "$@8", "Body",
  "type", "slist", "stmt", "expr", "exprlist", "Retstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    43,    45,    42,
      47,    60,    62,    59,    44,    40,    41,    91,    93,   123,
     125,    38,    61
};
# endif

#define YYPACT_NINF -80

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -80,     2,    -4,   -80,     4,   -80,   -80,   -80,    13,     4,
     -80,   106,   -80,   -80,    20,    21,   -80,   -80,    43,    26,
      92,   -80,    22,    25,     4,    63,   -80,    20,    78,     4,
     -17,   -80,    47,   -80,   -80,    23,     4,   -80,     0,   -80,
      59,   -80,   -80,   -80,   120,   119,   116,   125,     0,   -80,
       1,   -80,   -80,   116,   119,   -80,   158,    40,   165,   -80,
     -80,   -80,   159,    45,   138,   165,   -80,   105,     6,   144,
     145,   156,   157,   179,    45,   -80,   180,   -80,   187,    14,
      14,   198,    14,    14,    14,    14,   206,   -80,   -80,   -80,
     -80,   -80,    51,    14,    14,    49,   140,   115,    88,   101,
     114,   154,   -80,    14,    14,   -80,   127,    14,    14,    14,
      14,    14,    14,    14,    14,    14,   181,   -80,   188,    14,
     189,   213,   207,   -80,   182,    65,    62,   -80,   -80,   -80,
     -80,   186,   186,    -9,    -9,    53,    53,    14,   -80,    75,
     -80,    45,    45,    14,   -80,   -80,   168,   190,   211,   209,
     182,   -80,   196,   197,   199,   -80,   -80,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,     6,    15,    40,    41,     0,     6,
       8,     0,     4,     7,     0,    40,    16,     3,     0,    12,
       0,    10,     0,     0,    20,     0,     9,     0,     0,    20,
       0,    23,     0,    11,    35,     0,     0,    13,     0,    14,
       0,    17,    21,    25,     0,    24,    30,     0,     0,    26,
       0,    32,    36,    30,    22,    27,     0,     0,    39,    18,
      28,    29,     0,     0,     0,    39,    34,     0,     0,     0,
       0,     0,     0,     0,    43,    37,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    19,    33,
      64,    65,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    69,     0,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,    70,    68,     0,     0,    61,    57,    58,
      59,    51,    52,    53,    54,    55,    56,     0,    46,     0,
      48,     0,     0,     0,    66,    62,     0,     0,     0,     0,
      67,    45,     0,     0,     0,    47,    49,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   -80,   222,   -80,   -80,   -80,   208,   -80,
     -80,   -80,   -80,   204,   -80,   -80,   191,   183,   -80,   -80,
     -80,   -80,   -80,   169,    15,   -74,   -80,   -79,   -80,   -80
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,     8,     9,    14,    20,    21,    11,
      16,    47,    65,    30,    48,    38,    45,    52,    57,    67,
      17,    40,    58,    64,    10,    73,    74,    95,   125,    86
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      87,    96,     3,    98,    99,   100,   101,    43,    55,     6,
       7,   107,   108,   109,   105,   106,    36,    90,    91,    37,
       4,    92,   114,   115,   124,   126,    18,    19,   128,   129,
     130,   131,   132,   133,   134,   135,   136,    93,    12,    31,
     139,    44,    56,    79,    31,     6,     7,    22,    80,    94,
      23,    42,    68,    69,    70,    71,    36,    28,   146,    41,
      29,    24,    72,    25,   150,    61,    32,   148,   149,   107,
     108,   109,    62,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   107,   108,   109,    39,   103,   116,   104,   110,
     111,   112,   113,   114,   115,   107,   108,   109,    46,   143,
     145,   144,   110,   111,   112,   113,   114,   115,   107,   108,
     109,    15,     7,   147,    34,   110,   111,   112,   113,   114,
     115,   107,   108,   109,   120,    26,    27,    49,   110,   111,
     112,   113,   114,   115,   107,   108,   109,   121,    77,    78,
      51,   110,   111,   112,   113,   114,   115,   107,   108,   109,
     122,   118,   119,    50,   110,   111,   112,   113,   114,   115,
     107,   108,   109,   127,    53,    60,    66,   110,   111,   112,
     113,   114,   115,   117,   107,   108,   109,    63,    75,    81,
      82,   110,   111,   112,   113,   114,   115,   123,   107,   108,
     109,    83,    84,    85,    89,   110,   111,   112,   113,   114,
     115,   151,   107,   108,   109,    97,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   112,   113,   114,   115,   102,
      88,   138,   140,   137,   141,   142,   152,   153,   154,   155,
     156,    13,   157,    35,    76,    33,    59,     0,     0,    54
};

static const yytype_int16 yycheck[] =
{
      74,    80,     0,    82,    83,    84,    85,     7,     7,     5,
       6,    20,    21,    22,    93,    94,    33,     3,     4,    36,
      24,     7,    31,    32,   103,   104,    11,     7,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    23,    25,    24,
     119,    41,    41,    37,    29,     5,     6,    26,    42,    35,
       7,    36,     7,     8,     9,    10,    33,    35,   137,    36,
      35,    35,    17,    37,   143,    25,     3,   141,   142,    20,
      21,    22,    57,    20,    21,    22,    27,    28,    29,    30,
      31,    32,    20,    21,    22,    38,    35,    38,    37,    27,
      28,    29,    30,    31,    32,    20,    21,    22,    39,    34,
      38,    36,    27,    28,    29,    30,    31,    32,    20,    21,
      22,     5,     6,    38,    36,    27,    28,    29,    30,    31,
      32,    20,    21,    22,    36,    33,    34,     7,    27,    28,
      29,    30,    31,    32,    20,    21,    22,    36,    33,    34,
      24,    27,    28,    29,    30,    31,    32,    20,    21,    22,
      36,    36,    37,    34,    27,    28,    29,    30,    31,    32,
      20,    21,    22,    36,    39,     7,     7,    27,    28,    29,
      30,    31,    32,    33,    20,    21,    22,    12,    40,    35,
      35,    27,    28,    29,    30,    31,    32,    33,    20,    21,
      22,    35,    35,    14,     7,    27,    28,    29,    30,    31,
      32,    33,    20,    21,    22,     7,    20,    21,    22,    27,
      28,    29,    30,    31,    32,    29,    30,    31,    32,    13,
      40,    33,    33,    42,    11,    18,    36,    16,    19,    33,
      33,     9,    33,    29,    65,    27,    53,    -1,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    45,     0,    24,    46,     5,     6,    47,    48,
      67,    52,    25,    47,    49,     5,    53,    63,    67,     7,
      50,    51,    26,     7,    35,    37,    33,    34,    35,    35,
      56,    67,     3,    51,    36,    56,    33,    36,    58,    38,
      64,    36,    67,     7,    41,    59,    39,    54,    57,     7,
      34,    24,    60,    39,    59,     7,    41,    61,    65,    60,
       7,    25,    67,    12,    66,    55,     7,    62,     7,     8,
       9,    10,    17,    68,    69,    40,    66,    33,    34,    37,
      42,    35,    35,    35,    35,    14,    72,    68,    40,     7,
       3,     4,     7,    23,    35,    70,    70,     7,    70,    70,
      70,    70,    13,    35,    37,    70,    70,    20,    21,    22,
      27,    28,    29,    30,    31,    32,    38,    33,    36,    37,
      36,    36,    36,    33,    70,    71,    70,    36,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    42,    33,    70,
      33,    11,    18,    34,    36,    38,    70,    38,    68,    68,
      70,    33,    36,    16,    19,    33,    33,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    45,    44,    46,    46,    47,    47,    49,    48,
      50,    50,    51,    51,    51,    52,    52,    54,    55,    53,
      56,    57,    56,    58,    56,    59,    59,    59,    59,    60,
      60,    61,    61,    62,    62,    64,    65,    63,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     3,     0,     0,     2,     0,     4,
       1,     3,     1,     4,     4,     0,     2,     0,     0,    11,
       0,     0,     5,     0,     3,     1,     2,     3,     4,     3,
       0,     4,     0,     3,     1,     0,     0,    10,     4,     0,
       1,     1,     2,     1,     4,     7,     5,     8,     5,     8,
       8,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     4,     1,     1,     1,     4,     3,     1,     0,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 63 "stage10.y" /* yacc.c:1646  */
    {cout<<"-------------------------\n";}
#line 1391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 63 "stage10.y" /* yacc.c:1646  */
    {cout<<"\n";}
#line 1397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 66 "stage10.y" /* yacc.c:1646  */
    {
				fprintf(fp,"START\n");
				fprintf(fp,"MOV BP ,0\n");
				fprintf(fp,"MOV SP ,%d\n",main_mem-1);
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"CALL main\n");	
				fprintf(fp,"HALT\n");
				

			}
#line 1412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "stage10.y" /* yacc.c:1646  */
    {}
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 79 "stage10.y" /* yacc.c:1646  */
    {}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 83 "stage10.y" /* yacc.c:1646  */
    {global_type=(yyvsp[0].ival);}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 86 "stage10.y" /* yacc.c:1646  */
    {}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 91 "stage10.y" /* yacc.c:1646  */
    {
			is_exists_global((yyvsp[0].chid));
			ginstall((yyvsp[0].chid),global_type,1,NULL);
		}
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 97 "stage10.y" /* yacc.c:1646  */
    {
			is_exists_global((yyvsp[-3].chid));
			
			ginstall((yyvsp[-3].chid),global_type,1,(yyvsp[-1].alist));
			
			free_arglist();
			
		}
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 106 "stage10.y" /* yacc.c:1646  */
    {
			is_exists_global((yyvsp[-3].chid));
			ginstall((yyvsp[-3].chid),global_type,(yyvsp[-1].ival),NULL);
		}
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 113 "stage10.y" /* yacc.c:1646  */
    {}
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 118 "stage10.y" /* yacc.c:1646  */
    {
				(yyvsp[-1].alist)=get_arghead();
				struct gsymbol *identry=global_lookup((yyvsp[-3].chid));
				if(identry==NULL)
				{
					printf("function name is not declared \n error in lineno %d\n",line_no);
					exit(0);
				}
				else
				{
					if((yyvsp[-4].ival)!=(identry->type))
					{
						printf("function declaration and function definition return type is not matching in line %d\n",line_no);
						exit(0);
					}
					if(is_equal_arglist((identry->arglist),(yyvsp[-1].alist)))
					{
						arg_install();
						free_arglist();
					}
					else
					{
						printf("type or name mismatchinig\n");
						exit(0);
					}
					fprintf(fp,"%s:\n",(yyvsp[-3].chid));
					fprintf(fp,"%s\n","PUSH BP");
					fprintf(fp,"%s\n","MOV BP ,SP");
				}
			}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 149 "stage10.y" /* yacc.c:1646  */
    {
				struct lsymbol *temp=localhead;
				while(temp!=NULL && (temp->bind > 0))
				{
					fprintf(fp,"%s\n","PUSH R0");
					temp=temp->next;
				}
			}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 158 "stage10.y" /* yacc.c:1646  */
    {
				localhead=NULL;
			}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 164 "stage10.y" /* yacc.c:1646  */
    {cout<<"n";(yyval.alist)=NULL;}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 165 "stage10.y" /* yacc.c:1646  */
    {local_type=(yyvsp[0].ival);}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 165 "stage10.y" /* yacc.c:1646  */
    {(yyval.alist)=arghead;}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 166 "stage10.y" /* yacc.c:1646  */
    {local_type=(yyvsp[0].ival);}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 166 "stage10.y" /* yacc.c:1646  */
    {(yyval.alist)=arghead;}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 170 "stage10.y" /* yacc.c:1646  */
    {
				
				arglookup((yyvsp[0].chid));
				add_arg((yyvsp[0].chid),local_type,0);
				
			}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 177 "stage10.y" /* yacc.c:1646  */
    {
				arglookup((yyvsp[0].chid));
				add_arg((yyvsp[0].chid),local_type,1);
			}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 182 "stage10.y" /* yacc.c:1646  */
    {
				
				arglookup((yyvsp[0].chid));
				
				add_arg((yyvsp[0].chid),local_type,0);
				
			}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 190 "stage10.y" /* yacc.c:1646  */
    {
				arglookup((yyvsp[0].chid));
				add_arg((yyvsp[0].chid),local_type,1);
			}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 200 "stage10.y" /* yacc.c:1646  */
    {}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 201 "stage10.y" /* yacc.c:1646  */
    {}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 204 "stage10.y" /* yacc.c:1646  */
    {local_type=(yyvsp[-2].ival);}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 208 "stage10.y" /* yacc.c:1646  */
    {  
			struct lsymbol *ltentry=local_lookup((yyvsp[0].chid));
			if(ltentry==NULL)  
				linstall(local_type,(yyvsp[0].chid),0);
			else
			{
				printf("variable of line %d already declared locally \n",line_no);
				exit(0);
			}
		}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 220 "stage10.y" /* yacc.c:1646  */
    {
			struct lsymbol *ltentry=local_lookup((yyvsp[0].chid));
			if(ltentry==NULL)
				linstall(local_type,(yyvsp[0].chid),0);
			else
			{
				printf("variable of line %d already declared locally \n",line_no);
				exit(0);
			}
		}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 234 "stage10.y" /* yacc.c:1646  */
    {
					lbind=1;
					fprintf(fp,"%s\n","main:");
					fprintf(fp,"%s\n","PUSH BP");
					fprintf(fp,"%s\n","MOV BP ,SP");
				}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 241 "stage10.y" /* yacc.c:1646  */
    {
					
					struct lsymbol *temp=localhead;		
					while(temp!=NULL && (temp->bind>0))
					{
						fprintf(fp,"%s\n","PUSH R0");
						temp=temp->next;
					}
				}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 254 "stage10.y" /* yacc.c:1646  */
    {
		
		codgen((yyvsp[-2].nptr));
		fprintf(fp, "//---\n" );
		int r1=codgen((yyvsp[-1].nptr));
		int r2=get_reg();
		fprintf(fp,"MOV R%d BP\n",r2);
		int r3=get_reg();
		fprintf(fp,"MOV R%d -2\n",r3);
		fprintf(fp,"ADD R%d ,R%d\n",r2,r3);
		free_reg();
		fprintf(fp,"MOV [R%d] R%d\n",r2,r1);
		free_reg();
		free_reg();
		struct lsymbol *le=localhead;
		int count=0;
		while(le!=NULL)
		{
			if(le->bind > 0)
			{
				count++;
			}  
			le=le->next;
		}
		while(count>=1)	
		{
			fprintf(fp,"%s\n","POP R0");
			count=count-1;
		}
		fprintf(fp,"%s\n","POP BP");
		fprintf(fp,"%s\n","RET");
		
	}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 289 "stage10.y" /* yacc.c:1646  */
    {(yyval.ival)=0;}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 290 "stage10.y" /* yacc.c:1646  */
    {(yyval.ival)=1;}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 293 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkopnode(SLST, (yyvsp[-1].nptr), (yyvsp[0].nptr));}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 294 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[0].nptr);}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 297 "stage10.y" /* yacc.c:1646  */
    {
							struct lsymbol *local_temp = local_lookup((yyvsp[-3].chid));
							if(local_temp==NULL)
							{
								struct gsymbol *global_temp = global_lookup((yyvsp[-3].chid));
								if(global_temp==NULL)
								{
									printf("Identifier with name %s does not exist",(yyvsp[-3].chid));
									exit(1);
								}
								else
								{
		
									struct xtree *newnode = mkleafnodeid(IDD, (yyvsp[-3].chid), global_temp->type);
									newnode->gentry = global_temp;
									(yyval.nptr)=mkopnode(EQ, newnode, (yyvsp[-1].nptr));
						//			$$->gentry=global_temp;	
								}
							}

							else
							{	
								struct xtree *newnode = mkleafnodeid(IDD, (yyvsp[-3].chid), local_temp->type);
								newnode->lentry = local_temp;
								(yyval.nptr)=mkopnode(EQ, newnode, (yyvsp[-1].nptr));
					//			$$->lentry=local_temp;
							}
						}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 325 "stage10.y" /* yacc.c:1646  */
    {
										struct gsymbol *global_temp = global_lookup((yyvsp[-6].chid));
										if(global_temp==NULL)
										{
											printf("Identifier with name %s does not exist",(yyvsp[-6].chid));
											exit(1);
										}
										struct xtree *newnode = mkleafnodeidarray(IDD, (yyvsp[-6].chid),(yyvsp[-4].nptr), global_temp->type);
										newnode->gentry = global_temp;
										(yyval.nptr)=mkopnode(EQ, newnode, (yyvsp[-1].nptr));
										(yyval.nptr)->gentry=global_temp;
									}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 337 "stage10.y" /* yacc.c:1646  */
    {
							struct lsymbol *local_temp = local_lookup((yyvsp[-2].chid));
							if(local_temp==NULL)		
							{
								struct gsymbol *global_temp = global_lookup((yyvsp[-2].chid));
								if(global_temp==NULL)
								{
									printf("Identifier with name '%s' does not exist\n",(yyvsp[-2].chid));
									exit(1);
								}
								else
								{
									struct xtree *newnode = mkleafnodeid(IDD, (yyvsp[-2].chid), global_temp->type);
									newnode->gentry = global_temp;
									(yyval.nptr)=mkopnode(REED, newnode, NULL);
									(yyval.nptr)->gentry=global_temp;
								}
							}
							else
							{
								struct xtree *newnode = mkleafnodeid(IDD, (yyvsp[-2].chid), local_temp->type);
								newnode->lentry = local_temp;
								(yyval.nptr)=mkopnode(REED, newnode, NULL);
								(yyval.nptr)->lentry=local_temp;

							}
						}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 366 "stage10.y" /* yacc.c:1646  */
    {
							struct gsymbol *global_temp = global_lookup((yyvsp[-5].chid));
							if(global_temp==NULL)
							{
								printf("Identifier with name %s does not exist",(yyvsp[-5].chid));
								exit(1);
							}

							struct xtree *newnode = mkleafnodeidarray(IDD, (yyvsp[-5].chid),(yyvsp[-3].nptr), global_temp->type);
							newnode->gentry = global_temp;
							(yyval.nptr)=mkopnode(REED, newnode, NULL);
							(yyval.nptr)->gentry=global_temp;
						}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 380 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkopnode(RITE, (yyvsp[-2].nptr), NULL);}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 381 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkopnode(IFF, (yyvsp[-5].nptr), (yyvsp[-2].nptr));}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 382 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkopnode(WILE, (yyvsp[-5].nptr), (yyvsp[-2].nptr));}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 385 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkopnode(ADD, (yyvsp[-2].nptr), (yyvsp[0].nptr));}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 386 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkopnode(SUB, (yyvsp[-2].nptr), (yyvsp[0].nptr));}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 387 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkopnode(MUL, (yyvsp[-2].nptr), (yyvsp[0].nptr));}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 388 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkopnode(DIV, (yyvsp[-2].nptr), (yyvsp[0].nptr));}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 389 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkopnode(LT,  (yyvsp[-2].nptr), (yyvsp[0].nptr));}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 390 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkopnode(GT,  (yyvsp[-2].nptr), (yyvsp[0].nptr));}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 391 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkopnode(EE,  (yyvsp[-2].nptr), (yyvsp[0].nptr));}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 392 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkopnode(AND,  (yyvsp[-2].nptr), (yyvsp[0].nptr));}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 393 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkopnode(OR,  (yyvsp[-2].nptr), (yyvsp[0].nptr));}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 394 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkopnode(NOT,  (yyvsp[0].nptr), NULL);}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 395 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[-1].nptr);}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 396 "stage10.y" /* yacc.c:1646  */
    {
							struct gsymbol *global_temp = global_lookup((yyvsp[-3].chid));
							if(global_temp==NULL)
							{
								printf("Identifier with name %s does not exist",(yyvsp[-3].chid));
								exit(1);
							}
							

							(yyval.nptr)=mkleafnodeidarray(IDD,(yyvsp[-3].chid),(yyvsp[-1].nptr),global_temp->type);
							(yyval.nptr)->is_function=0;
							(yyval.nptr)->gentry=global_temp;
						}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 409 "stage10.y" /* yacc.c:1646  */
    {
			struct lsymbol *local_temp = local_lookup((yyvsp[0].chid));
			if(local_temp==NULL)
			{
				struct gsymbol *global_temp = global_lookup((yyvsp[0].chid));
				if(global_temp==NULL)
				{
					printf("Identifier with name '%s' does not exist\n",(yyvsp[0].chid));
					exit(1);
				}
				else
				{
					(yyval.nptr)=mkleafnodeid(IDD, (yyvsp[0].chid),global_temp->type);
					(yyval.nptr)->gentry=global_temp;
				}
			}
			else
			{
				(yyval.nptr)=mkleafnodeid(IDD, (yyvsp[0].chid),local_temp->type);
				(yyval.nptr)->lentry=local_temp;
			}	
			(yyval.nptr)->is_function=0;
		}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 434 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkleafnode(NUM1, (yyvsp[0].ival), 0);}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 437 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkleafnode(NUM1, (yyvsp[0].ival), 1);}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 442 "stage10.y" /* yacc.c:1646  */
    {
			struct gsymbol *global_temp = global_lookup((yyvsp[-3].chid));
			if(global_temp==NULL)
			{
				printf("Identifier with name '%s' does not exist\n",(yyvsp[-3].chid));
				exit(1);
			}
			else
			{
				(yyval.nptr)=mkleafnodeid(IDD, (yyvsp[-3].chid),global_temp->type);
				(yyval.nptr)->gentry=global_temp;
			}
		
		
			//check if argument in declaration and in parameter are same
			if(check_arg(global_temp->arglist,(yyvsp[-1].nptr)))
			{
				//mkfuncnode(nodeType,return_type,NameOfFunc,Arguments)
				
				(yyval.nptr)=mkfuncnode(IDD,global_temp->type,(yyvsp[-3].chid),(yyvsp[-1].nptr));
				
				(yyval.nptr)->gentry=global_temp;
				(yyval.nptr)->is_function=1;
				(yyval.nptr)->left=(yyvsp[-1].nptr);
		
			}
			else
			{
				printf("PARAMETER  MISMATCH IN LINE %d\n",line_no);
				exit(0);
			}
		}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 476 "stage10.y" /* yacc.c:1646  */
    {
				    struct xtree *hd;
				    hd=(yyvsp[-2].nptr);
				    while(hd->next!=NULL)
				    	hd=hd->next;
				    hd->next=(yyvsp[0].nptr);
				    (yyval.nptr)=(yyvsp[-2].nptr);
				}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 485 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[0].nptr);}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 486 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=NULL;}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 489 "stage10.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[-1].nptr);}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2049 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 491 "stage10.y" /* yacc.c:1906  */

void yyerror(const char* a)
{
printf("error\n");
return;
}

main()
{
	fp=fopen("out.txt","w");
	char fname[10];
	printf("Enter Filename ::\n");
	cin>>fname;
	yyin=fopen(fname,"r");
	if(!yyin)
	{
		cout<<"INVALID FILE\n";
		exit(1);
	}
	/*return*/yyparse();
	fclose(yyin);	
}
