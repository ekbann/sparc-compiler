/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ILLEGAL = 258,
     AND = 259,
     OR = 260,
     CCON = 261,
     FCON = 262,
     ICON = 263,
     SCON = 264,
     INC = 265,
     DEC = 266,
     MOD = 267,
     EQUAL = 268,
     NOT_EQUAL = 269,
     LT = 270,
     LE = 271,
     GT = 272,
     GE = 273,
     SHIFTL = 274,
     SHIFTR = 275,
     STRCTPTR = 276,
     CHAR = 277,
     DO = 278,
     DOUBLE = 279,
     ELSE = 280,
     EXTERN = 281,
     FLOAT = 282,
     FOR = 283,
     ID = 284,
     IF = 285,
     INT = 286,
     REGISTER = 287,
     RETURN = 288,
     SIZEOF = 289,
     STATIC = 290,
     STRUCT = 291,
     VOID = 292,
     WHILE = 293,
     END_IF = 294,
     STATEMENT = 295,
     ITOF = 296,
     FTOI = 297,
     DEF = 298,
     X4 = 299,
     CALL = 300,
     PARAMETER = 301,
     ARRAY = 302,
     LEAF = 303,
     LVAL = 304,
     RVAL = 305,
     POSTFIX = 306,
     PREFIX = 307
   };
#endif
/* Tokens.  */
#define ILLEGAL 258
#define AND 259
#define OR 260
#define CCON 261
#define FCON 262
#define ICON 263
#define SCON 264
#define INC 265
#define DEC 266
#define MOD 267
#define EQUAL 268
#define NOT_EQUAL 269
#define LT 270
#define LE 271
#define GT 272
#define GE 273
#define SHIFTL 274
#define SHIFTR 275
#define STRCTPTR 276
#define CHAR 277
#define DO 278
#define DOUBLE 279
#define ELSE 280
#define EXTERN 281
#define FLOAT 282
#define FOR 283
#define ID 284
#define IF 285
#define INT 286
#define REGISTER 287
#define RETURN 288
#define SIZEOF 289
#define STATIC 290
#define STRUCT 291
#define VOID 292
#define WHILE 293
#define END_IF 294
#define STATEMENT 295
#define ITOF 296
#define FTOI 297
#define DEF 298
#define X4 299
#define CALL 300
#define PARAMETER 301
#define ARRAY 302
#define LEAF 303
#define LVAL 304
#define RVAL 305
#define POSTFIX 306
#define PREFIX 307




/* Copy the first part of user declarations.  */
#line 1 "CC.y"


#include "globals.h"

int linenum=1, token_listing=0, context_level=0, num_entry=0, num_id=0;
int num_float=0, num_int=0, num_char=0, num_string=0, num_illegal=0;
int num_lookup=0, num_searched=0, last_sym=0, statement_dump=0, node_dump=0;
int flag_modifier, flag_external, comment=0;

FILE *fp;					/* 'fp' points to a FILE */
struct entry *fn_p = NULL;	/* initialize function pointer */

struct entry *syntax_tree;
struct entry *hashtbl[PRIME];
struct entry *context[MAX_CONTEXT_LEVELS];

int yylex();
void yyerror(const char *s);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 24 "CC.y"
{
  char *lexeme;				/* lexeme				*/
  struct entry *symp;		/* symbol table pointer */
  int token;				/* tokens				*/
}
/* Line 193 of yacc.c.  */
#line 227 "CC.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 240 "CC.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   296

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  178

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,     2,    45,    68,     2,
      64,    65,    43,    41,    61,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    60,
       2,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,     2,    67,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    12,    17,    21,    23,
      25,    27,    29,    31,    33,    35,    39,    41,    43,    46,
      51,    53,    58,    59,    65,    72,    78,    83,    85,    86,
      88,    92,    95,    99,   102,   105,   106,   109,   110,   112,
     114,   117,   119,   121,   123,   125,   127,   128,   134,   140,
     148,   158,   164,   172,   176,   179,   183,   185,   189,   193,
     197,   201,   205,   209,   213,   217,   221,   225,   229,   233,
     237,   239,   242,   244,   246,   248,   250,   252,   254,   256,
     258,   263,   268,   272,   275,   278,   280,   282,   284,   288,
     290,   292,   294,   296,   300
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      70,     0,    -1,    -1,    71,    72,    -1,    73,    72,    -1,
      80,    -1,    74,    75,    76,    60,    -1,    75,    76,    60,
      -1,    26,    -1,    32,    -1,    37,    -1,    31,    -1,    22,
      -1,    27,    -1,    77,    -1,    76,    61,    77,    -1,    79,
      -1,    78,    -1,    43,    79,    -1,    29,    62,     8,    63,
      -1,    29,    -1,    29,    64,    83,    65,    -1,    -1,    82,
      66,    81,    86,    67,    -1,    75,    43,    29,    64,    83,
      65,    -1,    75,    29,    64,    83,    65,    -1,    29,    64,
      83,    65,    -1,    84,    -1,    -1,    85,    -1,    84,    61,
      85,    -1,    75,    29,    -1,    75,    43,    29,    -1,    87,
      88,    -1,    73,    87,    -1,    -1,    89,    88,    -1,    -1,
      90,    -1,    60,    -1,    97,    60,    -1,    92,    -1,    93,
      -1,    94,    -1,    95,    -1,    96,    -1,    -1,    91,    66,
      87,    88,    67,    -1,    30,    64,    97,    65,    89,    -1,
      30,    64,    97,    65,    89,    25,    89,    -1,    28,    64,
      97,    60,    97,    60,    97,    65,    89,    -1,    38,    64,
      97,    65,    89,    -1,    23,    89,    38,    64,    97,    65,
      60,    -1,    33,    97,    60,    -1,    33,    60,    -1,    99,
      40,    97,    -1,    98,    -1,    98,     5,    98,    -1,    98,
       4,    98,    -1,    98,    41,    98,    -1,    98,    42,    98,
      -1,    98,    43,    98,    -1,    98,    44,    98,    -1,    98,
      45,    98,    -1,    98,    13,    98,    -1,    98,    14,    98,
      -1,    98,    15,    98,    -1,    98,    16,    98,    -1,    98,
      17,    98,    -1,    98,    18,    98,    -1,    99,    -1,   100,
      99,    -1,   101,    -1,    46,    -1,    41,    -1,    42,    -1,
      10,    -1,    11,    -1,    68,    -1,    43,    -1,   101,    62,
      97,    63,    -1,    29,    64,   104,    65,    -1,    29,    64,
      65,    -1,   101,    10,    -1,   101,    11,    -1,   102,    -1,
      29,    -1,   103,    -1,    64,    97,    65,    -1,     8,    -1,
       6,    -1,     9,    -1,     7,    -1,    97,    61,   104,    -1,
      97,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    90,    93,    94,    97,   101,   104,   105,
     108,   109,   110,   111,   114,   166,   223,   227,   231,   237,
     251,   258,   274,   274,   277,   290,   304,   319,   320,   323,
     326,   335,   356,   368,   375,   376,   379,   382,   385,   386,
     387,   388,   389,   390,   391,   392,   395,   395,   400,   403,
     408,   418,   423,   428,   429,   432,   435,   438,   441,   444,
     447,   450,   453,   456,   459,   462,   465,   468,   471,   474,
     477,   480,   484,   487,   488,   489,   490,   491,   492,   493,
     496,   499,   506,   513,   517,   521,   524,   529,   533,   536,
     540,   544,   553,   559,   562
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ILLEGAL", "AND", "OR", "CCON", "FCON",
  "ICON", "SCON", "INC", "DEC", "MOD", "EQUAL", "NOT_EQUAL", "LT", "LE",
  "GT", "GE", "SHIFTL", "SHIFTR", "STRCTPTR", "CHAR", "DO", "DOUBLE",
  "ELSE", "EXTERN", "FLOAT", "FOR", "ID", "IF", "INT", "REGISTER",
  "RETURN", "SIZEOF", "STATIC", "STRUCT", "VOID", "WHILE", "END_IF", "'='",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "STATEMENT", "ITOF", "FTOI",
  "DEF", "X4", "CALL", "PARAMETER", "ARRAY", "LEAF", "LVAL", "RVAL",
  "POSTFIX", "PREFIX", "';'", "','", "'['", "']'", "'('", "')'", "'{'",
  "'}'", "'&'", "$accept", "program", "@1", "external_decls",
  "declaration", "modifier", "type_name", "var_list", "var_item",
  "array_var", "scalar_var", "function_def", "@2", "function_hdr",
  "parm_type_list", "parm_list", "parm_decl", "function_body",
  "internal_decls", "statement_list", "statement", "compound_stmt", "@3",
  "if_stmt", "for_stmt", "while_stmt", "dowhile_stmt", "return_stmt",
  "expression", "binary_expr", "unary_expr", "unary_op", "postfix_expr",
  "primary_expr", "constant", "argument_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      61,    43,    45,    42,    47,    37,    33,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      59,    44,    91,    93,    40,    41,   123,   125,    38
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    71,    70,    72,    72,    73,    73,    74,    74,
      75,    75,    75,    75,    76,    76,    77,    77,    77,    78,
      79,    79,    81,    80,    82,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    87,    87,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    91,    90,    92,    92,
      93,    94,    95,    96,    96,    97,    97,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   103,
     103,   103,   103,   104,   104
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     2,     4,
       1,     4,     0,     5,     6,     5,     4,     1,     0,     1,
       3,     2,     3,     2,     2,     0,     2,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     0,     5,     5,     7,
       9,     5,     7,     3,     2,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     3,     2,     2,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,    12,     8,    13,     0,    11,     9,
      10,     3,     0,     0,     0,     5,     0,    28,     4,     0,
      20,     0,     0,    14,    17,    16,    22,     0,     0,    27,
      29,    20,     0,     0,     0,    28,    20,    18,     7,     0,
      35,    31,     0,    26,     0,    28,    20,     6,     0,     0,
      28,    15,    35,     0,     0,    37,    32,    30,     0,    19,
      21,     0,    34,    23,    90,    92,    89,    91,    76,    77,
      46,     0,    86,     0,     0,     0,    74,    75,    79,    73,
      39,     0,    78,    33,    37,    38,     0,    41,    42,    43,
      44,    45,     0,    56,    70,     0,    72,    85,    87,    21,
      21,     0,     0,     0,     0,    54,     0,     0,     0,    36,
      35,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    83,    84,     0,
       0,     0,    82,    94,     0,     0,    53,     0,    88,    37,
      58,    70,    57,    64,    65,    66,    67,    68,    69,    59,
      60,    61,    62,    63,    55,     0,     0,     0,     0,    81,
      46,    46,     0,    80,     0,     0,    93,    48,    51,    47,
       0,     0,    46,    52,     0,    49,    46,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    11,    52,    13,    27,    22,    23,    24,
      25,    15,    40,    16,    28,    29,    30,    54,    55,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   134
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
     -80,     8,   127,   -80,   -80,   -80,   -80,   -60,   -80,   -80,
     -80,   -80,   127,   246,   -16,   -80,   -54,   246,   -80,   -14,
     -25,    16,   -44,   -80,   -80,   -80,   -80,    -3,   -13,     2,
     -80,     0,    45,    11,    67,   246,    12,   -80,   -80,   -14,
     244,   -80,    49,   -80,   246,   246,    18,   -80,    17,    22,
     246,   -80,   244,   -14,    23,    13,   -80,   -80,    24,   -80,
      38,    41,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
      87,    19,    47,    48,    59,    50,   -80,   -80,   -80,   -80,
     -80,   134,   -80,   -80,    13,   -80,    43,   -80,   -80,   -80,
     -80,   -80,    53,   168,    78,   134,    -4,   -80,   -80,   -80,
      55,    84,   134,   128,   134,   -80,    64,   134,    61,   -80,
     244,   -80,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   -80,   -80,   -80,   134,
      68,    71,   -80,    85,    83,    95,   -80,    96,   -80,    13,
     201,   -80,   190,   206,   206,   146,   146,   146,   146,     4,
       4,   -80,   -80,   -80,   -80,    89,   134,   134,   134,   -80,
      87,    87,    98,   -80,    97,    90,   -80,   142,   -80,   -80,
     106,   134,    87,   -80,   103,   -80,    87,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   166,    32,   -80,    -2,   160,   156,   -80,
      -7,   -80,   -80,   -80,   -17,   -80,   153,   -80,   -49,   -79,
     -69,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -72,   172,
     141,   -80,   -80,   -80,   -80,    42
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -47
static const yytype_int16 yytable[] =
{
      14,   101,   106,    62,    17,   109,   127,   128,     3,   108,
      14,    19,    26,    20,    37,    31,    38,    39,    49,    64,
      65,    66,    67,    68,    69,    37,    41,    21,    58,    32,
     131,   133,   135,    61,    12,   137,    70,    34,    53,    35,
      42,    71,    72,    73,    12,    36,    74,   122,   123,   124,
      53,    75,    43,   154,    76,    77,    78,   155,   129,    79,
     162,   139,    34,    44,    45,    64,    65,    66,    67,    68,
      69,    47,    39,    80,    46,    48,    50,    81,    56,   -46,
      59,    82,    45,   102,   164,   165,   133,    60,    72,    99,
      63,   167,   168,    64,    65,    66,    67,    68,    69,   174,
      76,    77,    78,   175,   -25,    79,   100,   177,    53,   110,
      70,   103,   104,   111,   107,    71,    72,    73,   125,   105,
      74,   -24,   130,    81,   136,    75,   138,    82,    76,    77,
      78,   157,   156,    79,    64,    65,    66,    67,    68,    69,
      64,    65,    66,    67,    68,    69,   158,    80,   159,     4,
     171,    81,   163,     5,     6,    82,     7,    72,     8,     9,
     160,   161,   170,    72,    10,   169,   173,   172,   176,    76,
      77,    78,   112,   113,    79,    76,    77,    78,    18,    33,
      79,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    81,   132,   112,    51,    82,    57,    81,     0,
     166,     0,    82,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   114,   115,   116,   117,   118,   119,
       0,   116,   117,   118,   119,     0,     0,     0,     0,     0,
       0,   120,   121,   122,   123,   124,   126,     0,     0,     0,
       0,     0,   120,   121,   122,   123,   124,   120,   121,   122,
     123,   124,     0,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,     4,     0,     4,     0,
       5,     6,     0,     6,     0,     8,     9,     8,     0,     0,
       0,    10,     0,    10,   140,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153
};

static const yytype_int16 yycheck[] =
{
       2,    70,    74,    52,    64,    84,    10,    11,     0,    81,
      12,    13,    66,    29,    21,    29,    60,    61,    35,     6,
       7,     8,     9,    10,    11,    32,    29,    43,    45,    43,
     102,   103,   104,    50,     2,   107,    23,    62,    40,    64,
      43,    28,    29,    30,    12,    29,    33,    43,    44,    45,
      52,    38,    65,   125,    41,    42,    43,   129,    62,    46,
     139,   110,    62,    61,    64,     6,     7,     8,     9,    10,
      11,    60,    61,    60,    29,     8,    64,    64,    29,    66,
      63,    68,    64,    64,   156,   157,   158,    65,    29,    65,
      67,   160,   161,     6,     7,     8,     9,    10,    11,   171,
      41,    42,    43,   172,    66,    46,    65,   176,   110,    66,
      23,    64,    64,    60,    64,    28,    29,    30,    40,    60,
      33,    66,    38,    64,    60,    38,    65,    68,    41,    42,
      43,    60,    64,    46,     6,     7,     8,     9,    10,    11,
       6,     7,     8,     9,    10,    11,    61,    60,    65,    22,
      60,    64,    63,    26,    27,    68,    29,    29,    31,    32,
      65,    65,    65,    29,    37,    67,    60,    25,    65,    41,
      42,    43,     4,     5,    46,    41,    42,    43,    12,    19,
      46,    13,    14,    15,    16,    17,    18,    41,    42,    43,
      44,    45,    64,    65,     4,    39,    68,    44,    64,    -1,
     158,    -1,    68,    13,    14,    15,    16,    17,    18,    41,
      42,    43,    44,    45,    13,    14,    15,    16,    17,    18,
      -1,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    95,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    41,    42,    43,
      44,    45,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    22,    -1,    22,    -1,
      26,    27,    -1,    27,    -1,    31,    32,    31,    -1,    -1,
      -1,    37,    -1,    37,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,    71,     0,    22,    26,    27,    29,    31,    32,
      37,    72,    73,    74,    75,    80,    82,    64,    72,    75,
      29,    43,    76,    77,    78,    79,    66,    75,    83,    84,
      85,    29,    43,    76,    62,    64,    29,    79,    60,    61,
      81,    29,    43,    65,    61,    64,    29,    60,     8,    83,
      64,    77,    73,    75,    86,    87,    29,    85,    83,    63,
      65,    83,    87,    67,     6,     7,     8,     9,    10,    11,
      23,    28,    29,    30,    33,    38,    41,    42,    43,    46,
      60,    64,    68,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    65,
      65,    89,    64,    64,    64,    60,    97,    64,    97,    88,
      66,    60,     4,     5,    13,    14,    15,    16,    17,    18,
      41,    42,    43,    44,    45,    40,    99,    10,    11,    62,
      38,    97,    65,    97,   104,    97,    60,    97,    65,    87,
      98,    99,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    97,    97,    64,    60,    61,    65,
      65,    65,    88,    63,    97,    97,   104,    89,    89,    67,
      65,    60,    25,    60,    97,    89,    65,    89
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 90 "CC.y"
    {flag_external = TRUE;;}
    break;

  case 6:
#line 97 "CC.y"
    {
					flag_modifier = FALSE;
					(yyval.symp) = (yyvsp[(3) - (4)].symp);
					;}
    break;

  case 7:
#line 101 "CC.y"
    {(yyval.symp) = (yyvsp[(2) - (3)].symp);;}
    break;

  case 8:
#line 104 "CC.y"
    {flag_modifier = m_extern; (yyval.token) = m_extern;;}
    break;

  case 9:
#line 105 "CC.y"
    {flag_modifier = m_register; (yyval.token) = m_register;;}
    break;

  case 10:
#line 108 "CC.y"
    {(yyval.token) = t_void;;}
    break;

  case 11:
#line 109 "CC.y"
    {(yyval.token) = t_int;;}
    break;

  case 12:
#line 110 "CC.y"
    {(yyval.token) = t_char;;}
    break;

  case 13:
#line 111 "CC.y"
    {(yyval.token) = t_float;;}
    break;

  case 14:
#line 114 "CC.y"
    {
					  int r;           /* used for get_reg() */
					  int size, width; /* used for offset calculations */
					  (yyvsp[(1) - (1)].symp)->t_type = (yyvsp[(0) - (1)].token);
					  if ((yyvsp[(1) - (1)].symp)->e_type == e_var) {
						switch ((yyvsp[(1) - (1)].symp)->t_type) {
						case t_char:
						  (yyvsp[(1) - (1)].symp)->type.var.width = 1;
						  break;
						case t_float:
						case t_int:
						  (yyvsp[(1) - (1)].symp)->type.var.width = 4;
						  break;
						default:
						  (yyvsp[(1) - (1)].symp)->type.var.width = 0;
						  break;
						}
						if ((yyvsp[(1) - (1)].symp)->c_type == c_pointer)
						  (yyvsp[(1) - (1)].symp)->type.var.width = 4;
						if (flag_external || (flag_modifier == m_extern)) {
						  (yyvsp[(1) - (1)].symp)->type.var.m_type = m_extern;
						  fprintf(fp, "\t.common %s, %d, %d\n", (yyvsp[(1) - (1)].symp)->lexeme,
								  (yyvsp[(1) - (1)].symp)->c_type == c_array
									  ? (yyvsp[(1) - (1)].symp)->type.var.width * atoi((yyvsp[(1) - (1)].symp)->type.var.array_length)
									  : (yyvsp[(1) - (1)].symp)->type.var.width,
								  (yyvsp[(1) - (1)].symp)->type.var.width);
						} else {
						  if ((yyvsp[(1) - (1)].symp)->c_type == c_array) {	/* offset of array */
							size = atoi((yyvsp[(1) - (1)].symp)->type.var.array_length);
							width = (yyvsp[(1) - (1)].symp)->type.var.width;
							(yyvsp[(1) - (1)].symp)->type.var.offset = align(size * width, width);
						  } else {						/* offset of scalar */
							width = (yyvsp[(1) - (1)].symp)->type.var.width;
							(yyvsp[(1) - (1)].symp)->type.var.offset = align(width, width);
						  }
						}
						if (flag_modifier) {	/* if modifier was specified */
						  if (flag_modifier == m_register) {
							if ((r = get_local((yyvsp[(1) - (1)].symp)))) {
							  (yyvsp[(1) - (1)].symp)->type.var.m_type = m_register;
							  printf("e_var '%s' is assigned ", (yyvsp[(1) - (1)].symp)->lexeme);
							  printf("register: %s\n", print_reg(r));
							  (yyvsp[(1) - (1)].symp)->type.var.reg = r;
							  (yyvsp[(1) - (1)].symp)->where = r;
							} else		/* no more local register available */
							  (yyvsp[(1) - (1)].symp)->type.var.m_type = m_none;
						  }
						}
					  }
					  if ((yyvsp[(1) - (1)].symp)->e_type == e_fn && flag_external)
						fprintf(fp, "\t.global %s\n", (yyvsp[(1) - (1)].symp)->lexeme);
					;}
    break;

  case 15:
#line 166 "CC.y"
    {
					  int r;			/* used for get_reg() */
					  int size,
						  width;		/* used for offset calculations */
					  (yyvsp[(3) - (3)].symp)->t_type = (yyvsp[(0) - (3)].token);
					  if ((yyvsp[(3) - (3)].symp)->e_type == e_var) {
						switch ((yyvsp[(3) - (3)].symp)->t_type) {
						case t_char:
						  (yyvsp[(3) - (3)].symp)->type.var.width = 1;
						  break;
						case t_float:
						case t_int:
						  (yyvsp[(3) - (3)].symp)->type.var.width = 4;
						  break;
						default:
						  (yyvsp[(3) - (3)].symp)->type.var.width = 0;
						  break;
						}
						if ((yyvsp[(3) - (3)].symp)->c_type == c_pointer)
						  (yyvsp[(3) - (3)].symp)->type.var.width = 4;
						if (flag_external || (flag_modifier == m_extern)) {
						  (yyvsp[(3) - (3)].symp)->type.var.m_type = m_extern;
						  fprintf(fp, "\t.common %s, %d, %d\n",
								  (yyvsp[(3) - (3)].symp)->lexeme,
								  (yyvsp[(3) - (3)].symp)->c_type == c_array
									  ? (yyvsp[(3) - (3)].symp)->type.var.width *
											atoi((yyvsp[(3) - (3)].symp)->type.var.array_length)
									  : (yyvsp[(3) - (3)].symp)->type.var.width,
								  (yyvsp[(3) - (3)].symp)->type.var.width);
						} else {
						  if ((yyvsp[(3) - (3)].symp)->c_type == c_array) {	/* offset of array */
							size = atoi((yyvsp[(3) - (3)].symp)->type.var.array_length);
							width = (yyvsp[(3) - (3)].symp)->type.var.width;
							(yyvsp[(3) - (3)].symp)->type.var.offset = align(size * width, width);
						  } else {						/* offset of scalar */
							width = (yyvsp[(3) - (3)].symp)->type.var.width;
							(yyvsp[(3) - (3)].symp)->type.var.offset = align(width, width);
						  }
						}
						if (flag_modifier) {	/* if modifier was specified */
						  if (flag_modifier == m_register) {
							if ((r = get_local((yyvsp[(3) - (3)].symp)))) {
							  (yyvsp[(3) - (3)].symp)->type.var.m_type = m_register;
							  printf("e_var '%s' is assigned ", (yyvsp[(3) - (3)].symp)->lexeme);
							  printf("register: %s\n", print_reg(r));
							  (yyvsp[(3) - (3)].symp)->type.var.reg = r;
							  (yyvsp[(3) - (3)].symp)->where = r;
							} else		/* no more local register available */
							  (yyvsp[(3) - (3)].symp)->type.var.m_type = m_none;
						  }
						}
					  }
					  if ((yyvsp[(3) - (3)].symp)->e_type == e_fn && flag_external)
						fprintf(fp, "\t.global %s\n", (yyvsp[(3) - (3)].symp)->lexeme);
					;}
    break;

  case 16:
#line 223 "CC.y"
    {
					  (yyvsp[(1) - (1)].symp)->c_type = c_scalar;
					  (yyval.symp) = (yyvsp[(1) - (1)].symp);
					;}
    break;

  case 17:
#line 227 "CC.y"
    {
					  (yyvsp[(1) - (1)].symp)->c_type = c_array;
					  (yyval.symp) = (yyvsp[(1) - (1)].symp);
					;}
    break;

  case 18:
#line 231 "CC.y"
    {
					  (yyvsp[(2) - (2)].symp)->c_type = c_pointer;
					  (yyval.symp) = (yyvsp[(2) - (2)].symp);
					;}
    break;

  case 19:
#line 237 "CC.y"
    {
					  if (!((yyval.symp) = lookup((yyvsp[(3) - (4)].lexeme))))     /* if ICON doesn't exist */
						(yyval.symp) = insert(ICON, (yyvsp[(3) - (4)].lexeme), 0); /* create one */
					  if (((yyval.symp) = lookup((yyvsp[(1) - (4)].lexeme))) && ((yyval.symp)->scope == context_level))
						yyerror("multiply defined identifier");
					  if ((yyval.symp))
						(yyval.symp)->references--; /* see 121.t page 1 */
					  (yyval.symp) = insert(ID, (yyvsp[(1) - (4)].lexeme), context_level);
					  (yyval.symp)->e_type = e_var;
					  (yyval.symp)->c_type = c_array;
					  (yyval.symp)->type.var.array_length = (yyvsp[(3) - (4)].lexeme);
					;}
    break;

  case 20:
#line 251 "CC.y"
    {
					  if (((yyval.symp) = lookup((yyvsp[(1) - (1)].lexeme))) && ((yyval.symp)->scope == context_level))
						yyerror("multiply defined identifier");
					  if ((yyval.symp))
						(yyval.symp)->references--; /* see 121.t page 1 */
					  (yyval.symp) = insert(ID, (yyvsp[(1) - (1)].lexeme), context_level);
					;}
    break;

  case 21:
#line 258 "CC.y"
    {
					  if (((yyval.symp) = lookup((yyvsp[(1) - (4)].lexeme))) && ((yyval.symp)->scope == context_level))
						yyerror("multiply defined identifier");
					  if ((yyval.symp))
						(yyval.symp)->references--; /* see 121.t page 1 */
					  (yyval.symp) = insert(ID, (yyvsp[(1) - (4)].lexeme), context_level);
					  (yyval.symp)->e_type = e_fn;
					  /* we must connect the fn_parms liked list to ID */
					  (yyval.symp)->type.fn.parameters = (yyvsp[(3) - (4)].symp);
					  /* we must erase the function's context_level vars */
					  /* because it has no function body (prototype?)	   */
					  context_level++;
					  delete_level();
					;}
    break;

  case 22:
#line 274 "CC.y"
    {context_level++; flag_external = FALSE;;}
    break;

  case 23:
#line 274 "CC.y"
    {delete_level();;}
    break;

  case 24:
#line 277 "CC.y"
    {
					  if (((yyval.symp) = lookup((yyvsp[(3) - (6)].lexeme))) && ((yyval.symp)->scope == context_level))
						yyerror("multiply defined identifier");
					  if ((yyval.symp))
						(yyval.symp)->references--; /* see 121.t page 1 */
					  (yyval.symp) = insert(ID, (yyvsp[(3) - (6)].lexeme), context_level);
					  fn_p = (yyval.symp); /* for RETURN type verification */
					  (yyval.symp)->e_type = e_fn;
					  (yyval.symp)->t_type = (yyvsp[(1) - (6)].token);
					  (yyval.symp)->c_type = c_pointer;
					  /* we must connect the fn_parms liked list to ID */
					  (yyval.symp)->type.fn.parameters = (yyvsp[(5) - (6)].symp);
                    ;}
    break;

  case 25:
#line 290 "CC.y"
    {
					  if (((yyval.symp) = lookup((yyvsp[(2) - (5)].lexeme))) &&
						  ((yyval.symp)->scope == context_level))
						yyerror("multiply defined identifier");
					  if ((yyval.symp))
						(yyval.symp)->references--; /* see 121.t page 1 */
					  (yyval.symp) = insert(ID, (yyvsp[(2) - (5)].lexeme), context_level);
					  fn_p = (yyval.symp); /* for RETURN type verification */
					  (yyval.symp)->e_type = e_fn;
					  (yyval.symp)->t_type = (yyvsp[(1) - (5)].token);
					  (yyval.symp)->c_type = c_scalar;
					  /* we must connect the fn_parms liked list to ID */
					  (yyval.symp)->type.fn.parameters = (yyvsp[(4) - (5)].symp);
                    ;}
    break;

  case 26:
#line 304 "CC.y"
    {
					  if (((yyval.symp) = lookup((yyvsp[(1) - (4)].lexeme))) &&
						  ((yyval.symp)->scope == context_level))
						yyerror("multiply defined identifier");
					  if ((yyval.symp))
						(yyval.symp)->references--; /* see 121.t page 1 */
					  (yyval.symp) = insert(ID, (yyvsp[(1) - (4)].lexeme), context_level);
					  fn_p = (yyval.symp); /* for RETURN type verification */
					  (yyval.symp)->e_type = e_fn;
					  (yyval.symp)->t_type = t_void; /* c_type = ??? */
					  /* we must connect the fn_parms liked list to ID */
					  (yyval.symp)->type.fn.parameters = (yyvsp[(3) - (4)].symp);
                    ;}
    break;

  case 28:
#line 320 "CC.y"
    {(yyval.symp) = NULL;;}
    break;

  case 29:
#line 323 "CC.y"
    {
					  (yyvsp[(1) - (1)].symp)->fn_parms = NULL;	/* the last fn_parm in list */
					;}
    break;

  case 30:
#line 326 "CC.y"
    {
					  struct entry *p = (yyvsp[(1) - (3)].symp); /* make list of all fn_parms */
					  while (p->fn_parms)
						p = p->fn_parms;
					  p->fn_parms = (yyvsp[(3) - (3)].symp);
					  (yyvsp[(3) - (3)].symp)->fn_parms = NULL;
                    ;}
    break;

  case 31:
#line 335 "CC.y"
    {
					  if (((yyval.symp) = lookup((yyvsp[(2) - (2)].lexeme))) && ((yyval.symp)->scope == context_level + 1))
						yyerror("multiply defined identifier");
					  if ((yyval.symp))
						(yyval.symp)->references--; /* see 121.t page 1 */
					  (yyval.symp) = insert(ID, (yyvsp[(2) - (2)].lexeme), context_level + 1);
					  (yyval.symp)->t_type = (yyvsp[(1) - (2)].token);
					  (yyval.symp)->c_type = c_scalar;
					  switch ((yyval.symp)->t_type) {
					  case t_char:
						(yyval.symp)->type.var.width = 1;
						break;
					  case t_float:
					  case t_int:
						(yyval.symp)->type.var.width = 4;
						break;
					  default:
						(yyval.symp)->type.var.width = 0;
						break;
					  }
					;}
    break;

  case 32:
#line 356 "CC.y"
    {
					  if (((yyval.symp) = lookup((yyvsp[(3) - (3)].lexeme))) && ((yyval.symp)->scope == context_level + 1))
						yyerror("multiply defined identifier");
					  if ((yyval.symp))
						(yyval.symp)->references--; /* see 121.t page 1 */
					  (yyval.symp) = insert(ID, (yyvsp[(3) - (3)].lexeme), context_level + 1);
					  (yyval.symp)->t_type = (yyvsp[(1) - (3)].token);
					  (yyval.symp)->c_type = c_pointer;
					  (yyval.symp)->type.var.width = 4; /* pointer is always 4 bytes */
					;}
    break;

  case 33:
#line 368 "CC.y"
    {
					  if (node_dump)
						printf("\nsyntax tree root = [%p]\n", (yyvsp[(2) - (2)].symp));
					  syntax_tree = (yyvsp[(2) - (2)].symp);
					;}
    break;

  case 35:
#line 376 "CC.y"
    {(yyval.symp) = NULL;;}
    break;

  case 36:
#line 379 "CC.y"
    {
					  (yyval.symp) = make_node (STATEMENT, (yyvsp[(1) - (2)].symp), (yyvsp[(2) - (2)].symp));
					;}
    break;

  case 37:
#line 382 "CC.y"
    {(yyval.symp) = NULL;;}
    break;

  case 38:
#line 385 "CC.y"
    {delete_level(); (yyval.symp) = (yyvsp[(1) - (1)].symp);;}
    break;

  case 39:
#line 386 "CC.y"
    {(yyval.symp) = NULL;;}
    break;

  case 46:
#line 395 "CC.y"
    {context_level++;;}
    break;

  case 47:
#line 395 "CC.y"
    {
					  (yyval.symp) = (yyvsp[(4) - (5)].symp); /* $4 not $3 because of embedded actions */
					;}
    break;

  case 48:
#line 400 "CC.y"
    {
						(yyval.symp) = make_node(IF, (yyvsp[(3) - (5)].symp), (yyvsp[(5) - (5)].symp));
					;}
    break;

  case 49:
#line 403 "CC.y"
    {
						(yyval.symp) = make_node (IF, (yyvsp[(3) - (7)].symp), make_node (ELSE, (yyvsp[(5) - (7)].symp), (yyvsp[(7) - (7)].symp)));
					;}
    break;

  case 50:
#line 408 "CC.y"
    {
					  (yyval.symp) = make_node(STATEMENT, (yyvsp[(3) - (9)].symp),
								make_node(STATEMENT,
									make_node(WHILE, (yyvsp[(5) - (9)].symp),
										make_node(STATEMENT, (yyvsp[(9) - (9)].symp),
											make_node(STATEMENT, (yyvsp[(7) - (9)].symp), NULL))),
									NULL));
					;}
    break;

  case 51:
#line 418 "CC.y"
    {
						(yyval.symp) = make_node(WHILE, (yyvsp[(3) - (5)].symp), (yyvsp[(5) - (5)].symp));
					;}
    break;

  case 52:
#line 423 "CC.y"
    {
						(yyval.symp) = make_node(DO, make_node(STATEMENT, (yyvsp[(2) - (7)].symp), NULL), (yyvsp[(5) - (7)].symp));
					;}
    break;

  case 53:
#line 428 "CC.y"
    {(yyval.symp) = make_node (RETURN, (yyvsp[(2) - (3)].symp), NULL);;}
    break;

  case 54:
#line 429 "CC.y"
    {(yyval.symp) = make_node(RETURN, NULL, NULL);;}
    break;

  case 55:
#line 432 "CC.y"
    {
						(yyval.symp) = make_node('=', (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 57:
#line 438 "CC.y"
    {
					(yyval.symp) = make_node(OR, (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 58:
#line 441 "CC.y"
    {
					(yyval.symp) = make_node(AND, (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 59:
#line 444 "CC.y"
    {
					(yyval.symp) = make_node('+', (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 60:
#line 447 "CC.y"
    {
					(yyval.symp) = make_node('-', (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 61:
#line 450 "CC.y"
    {
					(yyval.symp) = make_node('*', (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 62:
#line 453 "CC.y"
    {
					(yyval.symp) = make_node('/', (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 63:
#line 456 "CC.y"
    {
					(yyval.symp) = make_node('%', (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 64:
#line 459 "CC.y"
    {
					(yyval.symp) = make_node(EQUAL, (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 65:
#line 462 "CC.y"
    {
					(yyval.symp) = make_node(NOT_EQUAL, (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 66:
#line 465 "CC.y"
    {
					(yyval.symp) = make_node(LT, (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 67:
#line 468 "CC.y"
    {
					(yyval.symp) = make_node(LE, (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 68:
#line 471 "CC.y"
    {
					(yyval.symp) = make_node(GT, (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 69:
#line 474 "CC.y"
    {
					(yyval.symp) = make_node(GE, (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 71:
#line 480 "CC.y"
    {
						(yyval.symp) = make_node ((yyvsp[(1) - (2)].token), (yyvsp[(2) - (2)].symp), NULL);
						(yyval.symp)->node_class = PREFIX;
					;}
    break;

  case 73:
#line 487 "CC.y"
    {(yyval.token) = '!';;}
    break;

  case 74:
#line 488 "CC.y"
    {(yyval.token) = '+';;}
    break;

  case 75:
#line 489 "CC.y"
    {(yyval.token) = '-';;}
    break;

  case 76:
#line 490 "CC.y"
    {(yyval.token) = INC;;}
    break;

  case 77:
#line 491 "CC.y"
    {(yyval.token) = DEC;;}
    break;

  case 78:
#line 492 "CC.y"
    {(yyval.token) = '&';;}
    break;

  case 79:
#line 493 "CC.y"
    {(yyval.token) = '*';;}
    break;

  case 80:
#line 496 "CC.y"
    {
					(yyval.symp) = make_node(DEF, make_node(ARRAY, (yyvsp[(1) - (4)].symp), (yyvsp[(3) - (4)].symp)), NULL);
					;}
    break;

  case 81:
#line 499 "CC.y"
    {
					struct entry *fn;
					if (!(fn = lookup((yyvsp[(1) - (4)].lexeme))))	/* is function defined? */
					  yyerror("undefined function");
					fn->node_type = LEAF;
					(yyval.symp) = make_node(CALL, fn, (yyvsp[(3) - (4)].symp));
					;}
    break;

  case 82:
#line 506 "CC.y"
    {
					struct entry *fn;
					if (!(fn = lookup((yyvsp[(1) - (3)].lexeme)))) /* is function defined? */
					  yyerror("undefined function");
					fn->node_type = LEAF;
					(yyval.symp) = make_node(CALL, fn, NULL);
					;}
    break;

  case 83:
#line 513 "CC.y"
    {
					(yyval.symp) = make_node(INC, (yyvsp[(1) - (2)].symp), NULL);
					(yyval.symp)->node_class = POSTFIX;
					;}
    break;

  case 84:
#line 517 "CC.y"
    {
					(yyval.symp) = make_node(DEC, (yyvsp[(1) - (2)].symp), NULL);
					(yyval.symp)->node_class = POSTFIX;
					;}
    break;

  case 86:
#line 524 "CC.y"
    {
					if (!((yyval.symp) = lookup((yyvsp[(1) - (1)].lexeme))))	  /* is variable defined? */
					  yyerror("undefined variable");
					(yyval.symp)->node_type = LEAF;
					;}
    break;

  case 87:
#line 529 "CC.y"
    {
					(yyvsp[(1) - (1)].symp)->node_type = LEAF;
					(yyval.symp) = (yyvsp[(1) - (1)].symp);
					;}
    break;

  case 88:
#line 533 "CC.y"
    {(yyval.symp) = (yyvsp[(2) - (3)].symp);;}
    break;

  case 89:
#line 536 "CC.y"
    {
					if (!((yyval.symp) = lookup((yyvsp[(1) - (1)].lexeme))))	    /* if ICON doesn't exist */
					  (yyval.symp) = insert(ICON, (yyvsp[(1) - (1)].lexeme), 0);	/* create one */
					;}
    break;

  case 90:
#line 540 "CC.y"
    {
					if (!((yyval.symp) = lookup((yyvsp[(1) - (1)].lexeme))))	    /* if CCON doesn't exist */
					  (yyval.symp) = insert(CCON, (yyvsp[(1) - (1)].lexeme), 0);	/* create one */
					;}
    break;

  case 91:
#line 544 "CC.y"
    {
						char l[6];
						if (!((yyval.symp) = lookup((yyvsp[(1) - (1)].lexeme)))) {	/* if SCON doesn't exist */
						  (yyval.symp) = insert(SCON, (yyvsp[(1) - (1)].lexeme), 0); /* create one */
						  fprintf(fp, "%s:\t.asciz\t%s\n",
								  newlabel(l, 'C'), (yyval.symp)->lexeme);
						  strcpy((yyval.symp)->type.con.label, l);
						}
					;}
    break;

  case 92:
#line 553 "CC.y"
    {
					if (!((yyval.symp) = lookup((yyvsp[(1) - (1)].lexeme))))			/* if FCON doesn't exist */
					  (yyval.symp) = insert(FCON, (yyvsp[(1) - (1)].lexeme), 0);		/* create one */
					;}
    break;

  case 93:
#line 559 "CC.y"
    {
					(yyval.symp) = make_node(PARAMETER, (yyvsp[(1) - (3)].symp), (yyvsp[(3) - (3)].symp));
					;}
    break;

  case 94:
#line 562 "CC.y"
    {(yyval.symp) = make_node(PARAMETER, (yyvsp[(1) - (1)].symp), NULL);;}
    break;


/* Line 1267 of yacc.c.  */
#line 2336 "CC.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 565 "CC.y"


int main(void) {
  if ((fp = fopen("output.s", "w")) == NULL) {
	printf("CC: can't open 'output.s'\n");
	exit(1);
  }
  init_reg_tbl();
  yyparse();
  check(syntax_tree);
  if (statement_dump) {
	printf("\n*** STATEMENT DUMP\n");
	syntax_tree_dump(syntax_tree);
  }
  /* output function header & save stack space */
  fprintf(fp, "\t.align\t4\n");
  fprintf(fp, "\t.global\t%s\n", fn_p->lexeme);
  fprintf(fp, "%s:\tsave\t%%sp, STACK_SPACE, %%sp\n", fn_p->lexeme);
  fn_args();							/* assign fn_p args to IN registers */
  code(syntax_tree);					/* code function body */
  if (!fn_p->t_type)					/* if function returns 'void' */
	fprintf(fp, "\tret\n\trestore\n");	/* then just 'ret' & 'restore' */
  fprintf(fp, "\tSTACK_SPACE = %d\n", align(92, 8));
  fclose(fp);
}

