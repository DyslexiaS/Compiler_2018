/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "common.h"
extern int yylineno;
extern int yylex();
int yyerror(char* msg);
#define get_data(Val)   ( Val.type == I_CONST ? Val.data.idata : Val.data.fdata )
#define operation(left, op, right)  if((left.type == I_CONST) && (right.type == I_CONST)){  \
                                        ret.type = I_CONST;                                 \
                                        ret.data.idata = get_data(left) op get_data(right); \
                                    }                                                       \
                                    else{                                                   \
                                        ret.type = F_CONST;                                 \
                                        ret.data.fdata = get_data(left) op get_data(right); \
                                    }                                                       
#define print_rel($$)   printf("%s\n",get_data($$) ? " true" : " false");
#define print_type(type)    type == I_CONST ? fprintf(fp, "\ti") : fprintf(fp, "\tf")
#define def_type_trans(left, right)     if((left.type == I_CONST)&&(right.type == F_CONST))    fprintf(fp, "\tf2i\n"); \
                                        if((left.type == F_CONST)&&(right.type == I_CONST))    fprintf(fp, "\ti2f\n");


/* Symbol table function - you can add new function if need. */
Variable* lookup_symbol(struct Table*, char* id);
void create_symbol(struct Table** table);
void insert_symbol(struct Table** table, char* id, int type, INT_FLOAT Var);

INT_FLOAT val_assign(int type, void* value, int index);
INT_FLOAT alu(INT_FLOAT left, int op, INT_FLOAT right);
INT_FLOAT get_id(char* id);
void assign_expr(char* id, INT_FLOAT value);
void assign_id(char* id, int op, INT_FLOAT expr);
bool is_redef(struct Table* table, char* id);
void new_scope();
void delete_scope();
void print_var(char* id);
void print_load(char* id);
void print_store(char* id);
void print_for_start();
void print_jump(int op, char* label_name, int IDX[]);
void print_label(char* label_name, int IDX[]);
void alu_type_trans(INT_FLOAT left, INT_FLOAT right);
void op_assign(INT_FLOAT left, INT_FLOAT right);
int bool_handler(INT_FLOAT left, int op, INT_FLOAT right);
struct Table* CUR_TABLE;
int depth;
int var_idx;
FILE* fp;
int ELSE_IDX[100];
int EXIT_IDX[100];
int FOR_IDX[100];
int BOOL_IDX[100];
int ERROR;
int func_num;
void func_insert_symbol(struct Table** table, char* id, int type);
void func_store(struct Table** table);
int get_func_type(const char* name);
FuncName func_info[10];

#line 129 "y.tab.c" /* yacc.c:339  */

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
    PRINT = 258,
    PRINTLN = 259,
    IF = 260,
    ELSE = 261,
    FOR = 262,
    VAR = 263,
    NEWLINE = 264,
    VOID = 265,
    FUNC = 266,
    RET = 267,
    ADD = 268,
    SUB = 269,
    MUL = 270,
    DIV = 271,
    MOD = 272,
    INC = 273,
    DEC = 274,
    GT = 275,
    LT = 276,
    GE = 277,
    LE = 278,
    EQ = 279,
    NE = 280,
    ASSIGN = 281,
    ADD_ASSIGN = 282,
    SUB_ASSIGN = 283,
    MUL_ASSIGN = 284,
    DIV_ASSIGN = 285,
    MOD_ASSIGN = 286,
    AND = 287,
    OR = 288,
    NOT = 289,
    LB = 290,
    RB = 291,
    LCB = 292,
    RCB = 293,
    I_CONST = 294,
    F_CONST = 295,
    STRING = 296,
    ID = 297,
    F_NAME = 298,
    INT = 299,
    FLOAT = 300
  };
#endif
/* Tokens.  */
#define PRINT 258
#define PRINTLN 259
#define IF 260
#define ELSE 261
#define FOR 262
#define VAR 263
#define NEWLINE 264
#define VOID 265
#define FUNC 266
#define RET 267
#define ADD 268
#define SUB 269
#define MUL 270
#define DIV 271
#define MOD 272
#define INC 273
#define DEC 274
#define GT 275
#define LT 276
#define GE 277
#define LE 278
#define EQ 279
#define NE 280
#define ASSIGN 281
#define ADD_ASSIGN 282
#define SUB_ASSIGN 283
#define MUL_ASSIGN 284
#define DIV_ASSIGN 285
#define MOD_ASSIGN 286
#define AND 287
#define OR 288
#define NOT 289
#define LB 290
#define RB 291
#define LCB 292
#define RCB 293
#define I_CONST 294
#define F_CONST 295
#define STRING 296
#define ID 297
#define F_NAME 298
#define INT 299
#define FLOAT 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 66 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* string;
    INT_FLOAT if_val;

#line 266 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 283 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   240

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   125,   129,   130,   131,   132,   133,   134,
     135,   138,   141,   142,   145,   157,   158,   145,   167,   168,
     169,   172,   175,   176,   177,   181,   182,   186,   187,   188,
     189,   193,   197,   198,   199,   200,   201,   204,   211,   221,
     225,   228,   231,   234,   237,   240,   246,   247,   250,   250,
     251,   252,   253,   254,   251,   258,   261,   262,   263,   266,
     266,   269,   269,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   283,   286,   293,   299,   313,   329,   330,   344,
     345,   346,   347,   348,   349,   353,   354,   355,   359,   360,
     361,   365
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "PRINTLN", "IF", "ELSE", "FOR",
  "VAR", "NEWLINE", "VOID", "FUNC", "RET", "ADD", "SUB", "MUL", "DIV",
  "MOD", "INC", "DEC", "GT", "LT", "GE", "LE", "EQ", "NE", "ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "AND", "OR", "NOT", "LB", "RB", "LCB", "RCB", "I_CONST", "F_CONST",
  "STRING", "ID", "F_NAME", "INT", "FLOAT", "','", "';'", "$accept",
  "program", "stat", "return_stat", "function_stat", "function_declare",
  "$@1", "$@2", "$@3", "argument_get", "function_call", "argument_send",
  "declaration", "type", "initializer", "compound_stat", "incdec_stat",
  "assign_stat", "for_expr", "for_stat", "$@4", "$@5", "$@6", "$@7", "$@8",
  "for_", "if_stat", "if_stat_only", "$@9", "if_else_stat", "$@10",
  "boolean_expr", "block", "lcb", "rcb", "print_func", "print_constent",
  "expression_stat", "operand", "literal", "identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    44,    59
};
# endif

#define YYPACT_NINF -125

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-125)))

#define YYTABLE_NINF -62

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -125,    93,  -125,   -32,   -15,    -9,  -125,    -2,  -125,   -25,
      50,    50,  -125,  -125,  -125,  -125,   186,   -14,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,   192,  -125,
      19,     4,  -125,  -125,  -125,   158,  -125,  -125,  -125,    -9,
      -9,    -9,  -125,  -125,   145,    -6,  -125,   158,    52,  -125,
    -125,   183,    50,    50,    50,    50,    50,    50,   209,    -3,
    -125,    21,  -125,  -125,   103,    50,    50,    50,    50,    50,
    -125,     6,   145,     7,     9,   175,    16,    50,    50,    50,
      50,    50,    50,    50,    50,  -125,  -125,  -125,     2,    22,
    -125,  -125,   158,   158,   158,   158,   158,   158,   -24,   158,
    -125,    16,  -125,  -125,  -125,    -1,    -1,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,   158,   158,   158,   158,   158,   158,
     158,   158,  -125,    50,    12,  -125,    50,    -9,  -125,    47,
     158,    -6,   -17,   158,  -125,  -125,  -125,    -6,    17,    11,
    -125,    -6,  -125,    33,  -125,    29,  -125,   186,  -125,  -125,
    -125,  -125,    16,   144,  -125,  -125
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     0,     0,    55,     0,    10,     0,
       0,     0,    73,    88,    89,    90,    91,     0,     2,     9,
       8,    13,    12,     4,     5,    32,    33,    34,     0,    35,
      56,     0,    36,     3,     7,     6,    79,    85,    86,     0,
       0,     0,    91,    59,     0,    30,    14,    11,     0,    37,
      38,     0,     0,     0,     0,     0,     0,    24,    91,     0,
      48,     0,    58,    57,     0,     0,     0,     0,     0,     0,
      78,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    27,    28,     0,     0,
      87,    45,    39,    40,    41,    42,    43,    44,     0,    23,
      50,     0,    62,    74,    72,    80,    81,    82,    83,    84,
      75,    76,    63,    60,    70,    68,    71,    69,    66,    67,
      64,    65,    26,     0,    20,    21,     0,     0,    49,     0,
      31,    30,     0,    22,    51,    25,    19,    30,     0,     0,
      15,    30,    52,     0,    18,     0,    16,     0,    47,    46,
      53,     3,     0,     0,    54,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -125,   -31,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
      30,  -125,  -125,  -124,  -125,  -125,   -63,   -20,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,    53,  -125,  -125,  -125,
    -125,    -4,   -21,  -125,  -125,  -125,    43,    -5,  -125,  -125,
    -125
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    89,   143,   151,   132,
      22,    98,    23,    88,   129,    24,    25,    26,   150,    27,
     101,   127,   139,   145,   152,    28,    29,    30,    76,    31,
      61,    70,    32,    33,   104,    34,    71,    35,    36,    37,
      38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    43,    64,    39,    85,    47,    48,   136,    59,     5,
      63,   122,   125,   140,    67,    68,    69,   144,    46,   137,
      40,    57,   126,    44,    60,   -61,    41,   102,   123,   138,
      13,    14,    15,    42,    72,    72,    75,    74,    86,    87,
      45,    12,   110,   111,   100,   112,    92,    93,    94,    95,
      96,    97,    99,    12,   131,   113,   135,   124,   142,   141,
     105,   106,   107,   108,   109,    65,    66,    67,    68,    69,
     146,   147,   114,   115,   116,   117,   118,   119,   120,   121,
     128,    91,   148,    73,    62,    11,     0,     0,    90,    13,
      14,    15,    42,     2,     0,     0,     3,     4,     5,     0,
       6,     7,     8,     0,     9,    10,     3,     4,     5,     0,
       6,     7,     8,     0,     9,    10,     0,     0,   130,     0,
     153,   133,    44,   134,     0,   149,     0,     0,    11,     0,
      12,   154,    13,    14,    15,    16,    17,     0,    11,     0,
      12,   103,    13,    14,    15,    16,    17,     3,     4,     5,
       0,     6,     7,     8,     0,     9,    10,     0,    65,    66,
      67,    68,    69,     0,     0,    77,    78,    79,    80,    81,
      82,    65,    66,    67,    68,    69,     0,    83,    84,    11,
       0,    12,   155,    13,    14,    15,    16,    17,    65,    66,
      67,    68,    69,     0,     0,    77,    78,    79,    80,    81,
      82,     0,     0,     0,    49,    50,     0,    83,    84,     0,
       0,    90,    51,    52,    53,    54,    55,    56,    11,     0,
       0,     0,    13,    14,    15,    42,    17,    41,     0,     0,
       0,    13,    14,    15,    58,    51,    52,    53,    54,    55,
      56
};

static const yytype_int16 yycheck[] =
{
       5,     5,    33,    35,    10,    10,    11,   131,    28,     5,
      31,     9,    36,   137,    15,    16,    17,   141,    43,    36,
      35,    35,    46,    28,    28,     6,    35,     6,    26,    46,
      39,    40,    41,    42,    39,    40,    41,    41,    44,    45,
      42,    37,    36,    36,    47,    36,    51,    52,    53,    54,
      55,    56,    57,    37,    42,    76,     9,    35,    47,    42,
      65,    66,    67,    68,    69,    13,    14,    15,    16,    17,
      37,    42,    77,    78,    79,    80,    81,    82,    83,    84,
     101,    51,   145,    40,    31,    35,    -1,    -1,    36,    39,
      40,    41,    42,     0,    -1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    -1,    11,    12,     3,     4,     5,    -1,
       7,     8,     9,    -1,    11,    12,    -1,    -1,   123,    -1,
     151,   126,   127,   127,    -1,   145,    -1,    -1,    35,    -1,
      37,   152,    39,    40,    41,    42,    43,    -1,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,     3,     4,     5,
      -1,     7,     8,     9,    -1,    11,    12,    -1,    13,    14,
      15,    16,    17,    -1,    -1,    20,    21,    22,    23,    24,
      25,    13,    14,    15,    16,    17,    -1,    32,    33,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    13,    14,
      15,    16,    17,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    18,    19,    -1,    32,    33,    -1,
      -1,    36,    26,    27,    28,    29,    30,    31,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    26,    27,    28,    29,    30,
      31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,     0,     3,     4,     5,     7,     8,     9,    11,
      12,    35,    37,    39,    40,    41,    42,    43,    50,    51,
      52,    53,    58,    60,    63,    64,    65,    67,    73,    74,
      75,    77,    80,    81,    83,    85,    86,    87,    88,    35,
      35,    35,    42,    79,    85,    42,    43,    85,    85,    18,
      19,    26,    27,    28,    29,    30,    31,    35,    42,    65,
      79,    78,    74,    80,    49,    13,    14,    15,    16,    17,
      79,    84,    85,    84,    79,    85,    76,    20,    21,    22,
      23,    24,    25,    32,    33,    10,    44,    45,    61,    54,
      36,    58,    85,    85,    85,    85,    85,    85,    59,    85,
      47,    68,     6,    38,    82,    85,    85,    85,    85,    85,
      36,    36,    36,    80,    85,    85,    85,    85,    85,    85,
      85,    85,     9,    26,    35,    36,    46,    69,    80,    62,
      85,    42,    57,    85,    79,     9,    61,    36,    46,    70,
      61,    42,    47,    55,    61,    71,    37,    42,    64,    65,
      66,    56,    72,    49,    80,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    51,    52,    52,    54,    55,    56,    53,    57,    57,
      57,    58,    59,    59,    59,    60,    60,    61,    61,    61,
      61,    62,    63,    63,    63,    63,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    68,    67,
      69,    70,    71,    72,    67,    73,    74,    74,    74,    76,
      75,    78,    77,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    80,    81,    82,    83,    83,    84,    84,    85,
      85,    85,    85,    85,    85,    86,    86,    86,    87,    87,
      87,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     0,     0,     0,    12,     4,     2,
       0,     4,     3,     1,     0,     6,     4,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     0,     4,
       0,     0,     0,     0,    11,     1,     1,     2,     2,     0,
       4,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     4,     4,     1,     1,     1,
       3,     3,     3,     3,     3,     1,     1,     3,     1,     1,
       1,     1
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
        case 4:
#line 129 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 130 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 131 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 132 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 133 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 134 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 138 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 141 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 142 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 145 "compiler_hw3.y" /* yacc.c:1646  */
    {
                    new_scope();
                    fprintf(fp, "FUNC_%s:\n", (yyvsp[0].string)); 
                    if(!strcmp((yyvsp[0].string), "main")){
                        var_idx = 0;
                    }
                    else{
                        strcpy((char*)func_info[func_num].name, (yyvsp[0].string));
                        fprintf(fp, "\tastore %d\n", (++func_num)*STACK_SIZE ); 
                        var_idx = func_num*STACK_SIZE+1;
                    }
                }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 157 "compiler_hw3.y" /* yacc.c:1646  */
    { func_info[func_num-1].type = (yyvsp[0].i_val); }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 158 "compiler_hw3.y" /* yacc.c:1646  */
    { func_store(&CUR_TABLE); }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 159 "compiler_hw3.y" /* yacc.c:1646  */
    {   
        delete_scope();
        if (strcmp((yyvsp[-10].string), "main"))
            fprintf(fp, "\tret %d\n", func_num*STACK_SIZE);
    }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 167 "compiler_hw3.y" /* yacc.c:1646  */
    { func_insert_symbol(&CUR_TABLE, (yyvsp[-1].string), (yyvsp[0].i_val) ); }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 168 "compiler_hw3.y" /* yacc.c:1646  */
    {  func_insert_symbol(&CUR_TABLE, (yyvsp[-1].string), (yyvsp[0].i_val) );  }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 172 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val).type = get_func_type((yyvsp[-3].string)); fprintf(fp, "\tjsr FUNC_%s\n", (yyvsp[-3].string)); }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 181 "compiler_hw3.y" /* yacc.c:1646  */
    { insert_symbol(&CUR_TABLE, (yyvsp[-4].string), (yyvsp[-3].i_val), (yyvsp[-1].if_val));   }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 182 "compiler_hw3.y" /* yacc.c:1646  */
    {  INT_FLOAT n; fprintf(fp, "\tldc 0\n"); insert_symbol(&CUR_TABLE, (yyvsp[-2].string), (yyvsp[-1].i_val), n); }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 186 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = I_CONST;}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 187 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = F_CONST;}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 188 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = VOID;}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 189 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 204 "compiler_hw3.y" /* yacc.c:1646  */
    {
        INT_FLOAT one;
        one.type = I_CONST;
        one.data.idata = 1;
        fprintf(fp, "\tldc 1\n");
        assign_id((yyvsp[-1].string), ADD, one);
    }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 211 "compiler_hw3.y" /* yacc.c:1646  */
    {
        INT_FLOAT one;
        one.type = I_CONST;
        one.data.idata = 1;
        fprintf(fp, "\tldc 1\n");
        assign_id((yyvsp[-1].string), SUB, one);
    }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 221 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        assign_expr((yyvsp[-2].string), (yyvsp[0].if_val));
        print_store((yyvsp[-2].string));
    }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 225 "compiler_hw3.y" /* yacc.c:1646  */
    {
        assign_id((yyvsp[-2].string), ADD, (yyvsp[0].if_val));
    }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 228 "compiler_hw3.y" /* yacc.c:1646  */
    {
        assign_id((yyvsp[-2].string), SUB, (yyvsp[0].if_val));
    }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 231 "compiler_hw3.y" /* yacc.c:1646  */
    {
        assign_id((yyvsp[-2].string), MUL, (yyvsp[0].if_val));
    }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 234 "compiler_hw3.y" /* yacc.c:1646  */
    {
        assign_id((yyvsp[-2].string), DIV, (yyvsp[0].if_val));
    }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 237 "compiler_hw3.y" /* yacc.c:1646  */
    {
        assign_id((yyvsp[-2].string), MOD, (yyvsp[0].if_val));
    }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 240 "compiler_hw3.y" /* yacc.c:1646  */
    {
        assign_expr((yyvsp[-2].string), (yyvsp[0].if_val));
        print_store((yyvsp[-2].string));
    }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 250 "compiler_hw3.y" /* yacc.c:1646  */
    { print_jump((yyvsp[0].i_val), "FOR_EXIT", FOR_IDX );}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 250 "compiler_hw3.y" /* yacc.c:1646  */
    { print_jump(-1,"FOR_START", FOR_IDX); print_label("FOR_EXIT", FOR_IDX);}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 251 "compiler_hw3.y" /* yacc.c:1646  */
    { print_for_start();}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 252 "compiler_hw3.y" /* yacc.c:1646  */
    { print_jump((yyvsp[0].i_val), "FOR_EXIT", FOR_IDX ); print_jump(-1,"FOR_CONTENT", FOR_IDX);}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 253 "compiler_hw3.y" /* yacc.c:1646  */
    {fprintf(fp, "\tFOR_EXPR_%d_%d:\n", CUR_TABLE->depth, FOR_IDX[CUR_TABLE->depth]);}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 254 "compiler_hw3.y" /* yacc.c:1646  */
    { print_jump(-1,"FOR_START", FOR_IDX); fprintf(fp, "\tFOR_CONTENT_%d_%d:\n", CUR_TABLE->depth, FOR_IDX[CUR_TABLE->depth]); }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 255 "compiler_hw3.y" /* yacc.c:1646  */
    { print_jump(-1,"FOR_EXPR", FOR_IDX); print_label("FOR_EXIT", FOR_IDX);}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 258 "compiler_hw3.y" /* yacc.c:1646  */
    { print_for_start();}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 261 "compiler_hw3.y" /* yacc.c:1646  */
    { print_label("ELSE", ELSE_IDX);}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 262 "compiler_hw3.y" /* yacc.c:1646  */
    { print_label("EXIT", EXIT_IDX);}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 263 "compiler_hw3.y" /* yacc.c:1646  */
    { print_label("EXIT", EXIT_IDX);}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 266 "compiler_hw3.y" /* yacc.c:1646  */
    { print_jump((yyvsp[0].i_val), "ELSE", ELSE_IDX); }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 269 "compiler_hw3.y" /* yacc.c:1646  */
    { print_jump(-1, "EXIT", EXIT_IDX); }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 269 "compiler_hw3.y" /* yacc.c:1646  */
    { print_label("ELSE", ELSE_IDX);}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 272 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[-1].i_val); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 273 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), AND, (yyvsp[0].if_val)); }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 274 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), OR, (yyvsp[0].if_val)); }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 275 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), EQ, (yyvsp[0].if_val)); }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 276 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), NE, (yyvsp[0].if_val)); }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 277 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), LT, (yyvsp[0].if_val)); }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 278 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), LE, (yyvsp[0].if_val)); }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 279 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), GT, (yyvsp[0].if_val)); }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 280 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), GE, (yyvsp[0].if_val)); }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 283 "compiler_hw3.y" /* yacc.c:1646  */
    { }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 286 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(CUR_TABLE == NULL)  create_symbol(&CUR_TABLE);
        else    new_scope();
    }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 293 "compiler_hw3.y" /* yacc.c:1646  */
    {
        delete_scope();
    }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 299 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(fp, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n");
        switch((yyvsp[-1].if_val).type){
            case I_CONST:
                fprintf(fp, "\tinvokevirtual java/io/PrintStream/print(I)V\n");
                break;
            case F_CONST:
                fprintf(fp, "\tinvokevirtual java/io/PrintStream/print(F)V\n");
                break;
            case STRING:
                fprintf(fp, "\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                break;
       }    
    }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 313 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(fp, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n");
        switch((yyvsp[-1].if_val).type){
            case I_CONST:
                fprintf(fp, "\tinvokevirtual java/io/PrintStream/println(I)V\n");
                break;
            case F_CONST:
                fprintf(fp, "\tinvokevirtual java/io/PrintStream/println(F)V\n");
                break;
            case STRING:
                fprintf(fp, "\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
                break;
       }    
    }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 329 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = (yyvsp[0].if_val); }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 330 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(CUR_TABLE==NULL)
            create_symbol(&CUR_TABLE);
        (yyval.if_val).type = STRING;
        print_jump((yyvsp[0].i_val), "BOOL_F", BOOL_IDX);
        fprintf(fp,"\tldc \"True\"\n");
        print_jump(-1, "BOOL_T", BOOL_IDX);
        fprintf(fp, "BOOL_F_%d_%d:\n", CUR_TABLE->depth, BOOL_IDX[CUR_TABLE->depth]);
        fprintf(fp,"\tldc \"False\"\n");
        fprintf(fp, "BOOL_T_%d_%d:\n", CUR_TABLE->depth, BOOL_IDX[CUR_TABLE->depth]);
        ++ BOOL_IDX[CUR_TABLE->depth];
        }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 345 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),ADD,(yyvsp[0].if_val)); }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 346 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),SUB,(yyvsp[0].if_val)); }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 347 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),MUL,(yyvsp[0].if_val)); }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 348 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),DIV,(yyvsp[0].if_val)); }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 349 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),MOD,(yyvsp[0].if_val)); }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 355 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = (yyvsp[-1].if_val);}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 359 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = val_assign(I_CONST, &(yyvsp[0].i_val), CONST); fprintf(fp, "\tldc %d\n", (yyvsp[0].i_val)); }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 360 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = val_assign(F_CONST, &(yyvsp[0].f_val), CONST); fprintf(fp, "\tldc %f\n", (yyvsp[0].f_val)); }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 361 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = val_assign(STRING, (yyvsp[0].string), CONST); fprintf(fp, "\tldc \"%s\"\n", (yyvsp[0].string)); }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 365 "compiler_hw3.y" /* yacc.c:1646  */
    { 
            (yyval.if_val) = get_id((yyvsp[0].string));
            print_load((yyvsp[0].string));
    }
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2014 "y.tab.c" /* yacc.c:1646  */
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
#line 371 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */

int main(int argc, char** argv)
{
    fp = fopen("Computer.j","w");
    fprintf(fp, ".class public main\n.super java/lang/Object\n.method public static main([Ljava/lang/String;)V\n.limit stack 100\n.limit locals 100\n");
    fprintf(fp, "\tgoto FUNC_main\n");
    fprintf(fp, "FUNC_main:\n");
    yylineno = 0;
    yyparse();
    printf("\n Total lines: %d\n\n", yylineno);
    fprintf(fp, "\treturn\n.end method\n");
    fclose(fp);
    if(ERROR)
        remove("Computer.j");
    return 0;
}
int yyerror(char* msg){
    fclose(fp);
    remove("Computer.j");
    fprintf(stderr, " Error: %s at line %d\n", msg, yylineno);
}
void create_symbol(struct Table** table) {
    *table = (struct Table*)malloc(sizeof(struct Table));
    assert(*table != NULL);
    memset(*table, 0, sizeof(struct Table));
    printf(" Create symbol table\n");
}
void insert_symbol(struct Table** table, char* id, int type, INT_FLOAT n){
    if(*table == NULL)  create_symbol(table);
    assert(*table != NULL);
    if(is_redef(CUR_TABLE, id)){
        printf(" <ERROR> Re-declaration for variable %s (line %d)\n", id, yylineno);
        ERROR = 1;
        return;
    }
    printf(" Insert symbol: %s\tdeclare in block of depth %d\n", id, (*table)->depth);
    int idx = ++((*table)->index);
    strcpy((*table)->Var[idx].id, id);
    (*table)->Var[idx].Val = n;
    (*table)->Var[idx].Val.type = type;
    (*table)->Var[idx].index = (*table)->Var[idx].Val.index = var_idx++;
    def_type_trans((*table)->Var[idx].Val, n);
    type == I_CONST ? fprintf(fp, "\tistore %d\n", (*table)->Var[idx].index) : fprintf(fp, "\tfstore %d\n", (*table)->Var[idx].index);
}
Variable* lookup_symbol(struct Table* table, char* id) {
    if(table == NULL)   return NULL;
    assert(table != NULL);
    for(int i=1 ;i<=table->index; ++i){
        if(!strcmp(id, table->Var[i].id)){
            depth = table->depth;
            return &(table->Var[i]);
        }
    }
    if(table->prev != NULL)
        return lookup_symbol(table->prev, id);
    return NULL;
}
INT_FLOAT val_assign(int type, void* value, int index){
    INT_FLOAT Val;
    Val.type = type;
    Val.index = index;
    switch(type){                                           
        case I_CONST:
            Val.data.idata = *(int*) value;
            break;
        case F_CONST:
            Val.data.fdata = *(double*) value; 
            break;
        case STRING: 
            strcpy(Val.data.sdata, (char*) value);     
            break;
    }
    return Val;
}
INT_FLOAT alu(INT_FLOAT left, int op, INT_FLOAT right){
    INT_FLOAT ret;
    alu_type_trans(left, right);
    switch(op){    
        case ADD:
            fprintf(fp, "add\n");
            operation(left, +, right);
            break;
        case SUB:
            fprintf(fp, "sub\n");
            operation(left, -, right);
            break;
        case MUL:
            fprintf(fp, "mul\n");
            operation(left, *, right);
            break;
        case DIV:
            //if(((right.type == I_CONST) && (right.data.idata == 0)) || ((right.type == F_CONST) && (right.data.fdata == 0))){
            if((right.index == -1)&&(((right.type == I_CONST) && (right.data.idata == 0)) || ((right.type == F_CONST) && (right.data.fdata == 0)))){
                printf(" <ERROR> The divisor can’t be 0 (line %d)\n", yylineno+1);
                ERROR = 1;
                ret.type = -1;
            }
            else {
                fprintf(fp, "div\n");
                operation(left, /, right);
            }
            break;
        case MOD:
            if((left.type == I_CONST) && (right.type == I_CONST)){
                fprintf(fp, "rem\n");
                ret.type = I_CONST;
                ret.data.idata = left.data.idata % right.data.idata;
            }
            else{
                printf(" <ERROR> MOD type error! (Line %d)\n", yylineno+1);
                ERROR = 1;
                ret.type = -1;
            }
            break;
    }
    return ret;
}
void assign_expr(char* id, INT_FLOAT Val){
     Variable* v = lookup_symbol(CUR_TABLE, id);
     if(v == NULL){
        printf(" <ERROR> Undefine variable %s (Line %d)\n", id, yylineno);
        ERROR = 1;
    }
     else{
        def_type_trans(v->Val, Val);                                    // TODO f2i
        v->Val = val_assign(v->Val.type, &Val.data, v->Val.index);
    }
}
INT_FLOAT get_id(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v == NULL){
        printf(" <ERROR> Undefine ID: %s (Line %d)\n", id, yylineno);
        ERROR = 1;
        INT_FLOAT n = {0};
        return n;
    }
    else
        return v->Val;
}
void assign_id(char* id, int op, INT_FLOAT expr){
    INT_FLOAT left = get_id(id);
    op_assign(left, expr);
    INT_FLOAT Val = alu(left, op, expr);
    assign_expr(id, Val);
    print_var(id);
}
bool is_redef(struct Table* table, char* id){
    for(int i=1; i<=table->index; ++i){
        if(!strcmp(id, table->Var[i].id))
            return true;
    }
    return false;
}
void new_scope(){
    if(CUR_TABLE == NULL)   create_symbol(&CUR_TABLE);
    assert(CUR_TABLE != NULL);
    struct Table* next;
    create_symbol(&next);
    CUR_TABLE->next = next;
    next->prev = CUR_TABLE;
    next->depth = CUR_TABLE->depth + 1;
    CUR_TABLE = next;
}
void delete_scope(){
    assert(CUR_TABLE != NULL);
    CUR_TABLE = CUR_TABLE->prev;
    free(CUR_TABLE->next);
    printf("\n Delete this scope symbol table\n");
}
void print_var(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    assert(v != NULL);
    v->Val.type == I_CONST ? fprintf(fp, "\tistore %d\n", v->index) : fprintf(fp, "\tfstore %d\n", v->index);
}
void print_load(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v == NULL)   return;
    assert(v != NULL);
    print_type(v->Val.type);
    fprintf(fp, "load %d\n", v->index);
}
void print_store(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v == NULL)   return;
    assert(v != NULL);
    print_type(v->Val.type);
    fprintf(fp, "store %d\n", v->index);
}
void alu_type_trans(INT_FLOAT left, INT_FLOAT right){
    if((left.type == F_CONST)&&(right.type == I_CONST))
        fprintf(fp, "\ti2f\n\tf");
    else if((left.type == I_CONST)&&(right.type == F_CONST))
        fprintf(fp, "\tfstore %d\n\ti2f\n\tfload %d\n\tf", var_idx, var_idx);
    else if((left.type == I_CONST)&&(right.type == I_CONST))
        fprintf(fp, "\ti");
    else
        fprintf(fp, "\tf");
}
void op_assign(INT_FLOAT left, INT_FLOAT right){
    print_type(right.type); 
    fprintf(fp, "store %d\n", var_idx);
    print_type(left.type); 
    fprintf(fp, "load %d\n", left.index);
    print_type(right.type); 
    fprintf(fp, "load %d\n", var_idx);
}
int bool_handler(INT_FLOAT left, int op, INT_FLOAT right){
    INT_FLOAT ret;
    if((left.type == F_CONST) || (right.type == F_CONST)){
        alu_type_trans(left, right);
        fprintf(fp, "cmpl\n");
    }
    else{
        alu_type_trans(left, right);
        fprintf(fp, "sub\n");
    }
    return op;
}
void print_for_start(){
    fprintf(fp, "FOR_START_%d_%d:\n", CUR_TABLE->depth, FOR_IDX[CUR_TABLE->depth]);
}
void print_label(char* label_name, int IDX[] ){
    fprintf(fp, "%s_%d_%d:\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
    ++ IDX[CUR_TABLE->depth];
}
void print_jump(int op, char* label_name, int IDX[]){
    switch(op){
        case AND:
            printf(" AND\n");
            break;
        case OR:
            printf(" OR\n");
            break;
        case EQ:
            fprintf(fp, "\tifne %s_%d_%d\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
            break;
        case NE:
            fprintf(fp, "\tifqe %s_%d_%d\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
            break;
        case LT:
            fprintf(fp, "\tifge %s_%d_%d\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
            break;
        case LE:
            fprintf(fp, "\tifgt %s_%d_%d\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
            break;
        case GT:
            fprintf(fp, "\tifle %s_%d_%d\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
            break;
        case GE:
            fprintf(fp, "\tiflt %s_%d_%d\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
            break;
        default:
            fprintf(fp, "\tgoto %s_%d_%d\n", label_name, CUR_TABLE->depth, IDX[CUR_TABLE->depth]);
            break;
    }
}
void func_insert_symbol(struct Table** table, char* id, int type){
    if(*table == NULL)  create_symbol(table);
    assert(*table != NULL);
    if(is_redef(CUR_TABLE, id)){
        printf(" <ERROR> Re-declaration for variable %s (line %d)\n", id, yylineno);
        ERROR = 1;
        return;
    }
    printf(" Insert symbol: %s\tdeclare in block of depth %d\n", id, (*table)->depth);
    int idx = ++((*table)->index);
    strcpy((*table)->Var[idx].id, id);
    (*table)->Var[idx].Val.type = type;
    (*table)->Var[idx].index = (*table)->Var[idx].Val.index = var_idx++;
}
void func_store(struct Table** table){
    for(int i = var_idx-1 ; i > func_num*STACK_SIZE ; --i ){
        INT_FLOAT T = get_id((*table)->Var[i-func_num*STACK_SIZE].id);
        T.type == I_CONST ? fprintf(fp, "\tistore %d\n", i) : fprintf(fp, "\tfstore %d\n", i);
    }    
}
int get_func_type(const char* name){
    for(int i = 0; i<func_num ; ++i){
        if( !strcmp((char*)func_info[i].name, name))
            return func_info[i].type;
    }
}

