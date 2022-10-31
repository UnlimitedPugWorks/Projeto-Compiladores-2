/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "minor.y"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "node.h"
#include "tabid.h"
#include "minor.h"

int yylex(), yyparse(), yyerror(const char*), evaluate(Node*); /* parsers */
static int isId(char*,Node*,int*), isInt(Node*,char*), isAddSub(Node*,char*);
static int isCmp(Node*,char*), isUniInt(Node*,char*), isAddr(Node*);
static int isAssign(Node *n), isCall(char*,Node*,Node*);
static void isFunc(char*,int), isAlloc(Node*,Node*), isRet(Node*), isStr(Node*);
static void isCte(Node*), isFwd(char*,int,Node*), isDim(char*,int,Node*);
static void isPrint(Node*), isCycle();
static char *func;
static int ret, cycle;
#line 20 "minor.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int i; char *s; Node *n; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 47 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INT 257
#define CHAR 258
#define ID 259
#define STR 260
#define PROGRAM 261
#define MODULE 262
#define END 263
#define PUBLIC 264
#define FORWARD 265
#define STRING 266
#define NUMBER 267
#define ARRAY 268
#define FUNCTION 269
#define VOID 270
#define CONST 271
#define IF 272
#define THEN 273
#define FI 274
#define ELIF 275
#define ELSE 276
#define RETURN 277
#define START 278
#define FOR 279
#define UNTIL 280
#define STEP 281
#define DO 282
#define DONE 283
#define REPEAT 284
#define STOP 285
#define FARGS 286
#define CHARS 287
#define INTS 288
#define ADDR 289
#define VAR 290
#define ARGS 291
#define DECL 292
#define NIL 293
#define EQ 294
#define NE 295
#define GE 296
#define LE 297
#define uminus 298
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
   31,    0,    0,    2,    2,    3,    3,    4,   32,   33,
    4,   34,    4,    4,    6,    6,    6,    7,    7,    5,
    5,    5,   12,   12,    8,    8,    8,    9,    9,   10,
   10,   10,   11,   11,   13,   13,   13,   14,   14,   15,
   15,   16,   16,   16,   17,   17,   18,   18,   18,   18,
   19,   19,   30,   30,   20,   20,   21,   21,   21,   22,
   22,   22,   29,   23,   23,   24,   35,   24,   24,   24,
   24,   25,   25,   26,   26,    1,    1,   27,   27,   27,
   27,   27,   27,   27,   27,   27,   27,   27,   27,   27,
   27,   27,   27,   27,   27,   27,   27,   27,   27,   27,
   28,   28,
};
static const YYINT yylen[] = {                            2,
    0,    6,    3,    0,    1,    3,    1,    3,    0,    0,
    8,    0,    6,    1,    2,    2,    3,    1,    3,    3,
    3,    4,    3,    0,    1,    1,    0,    1,    0,    1,
    1,    1,    1,    1,    0,    2,    3,    0,    2,    1,
    2,    1,    1,    1,    0,    2,    1,    2,    3,    4,
    1,    2,    3,    1,    4,    2,    1,    2,    0,    1,
    1,    1,    2,    0,    2,    7,    0,   10,    2,    2,
    4,    0,    5,    0,    2,    1,    4,    1,    1,    1,
    2,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    2,    3,    4,
    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   14,   25,   26,    0,    0,    0,    7,
    0,    0,    0,    1,    0,   28,    0,    3,   31,   30,
   32,   34,   33,    0,    0,    6,    0,    0,    0,    8,
    0,    0,    0,    0,   18,    0,    0,    0,    0,    0,
    0,    0,    0,   16,   15,    0,    0,   42,   43,    0,
   44,    0,    0,    0,    0,    0,   80,    0,    0,    0,
   40,   65,    0,    2,    0,   21,    0,   20,    0,    0,
    0,    0,   51,   13,   17,   19,    0,    0,    0,    0,
    0,    0,    0,   81,    0,   98,    0,    0,    0,   41,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   70,   69,    0,   36,    0,    0,
    0,   22,    0,    0,    0,   52,    0,    0,    0,    0,
   64,    0,   82,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   37,
   23,   47,    0,    0,   11,    0,    0,   56,   77,    0,
  100,    0,   72,    0,   71,   48,    0,    0,    0,    0,
   61,   62,   60,   63,    0,    0,   49,    0,   55,    0,
   64,    0,    0,   50,    0,   75,   66,   67,   64,   64,
   73,    0,   68,
};
static const YYINT yydgoto[] = {                          3,
   80,    8,    9,   10,   30,   35,   36,   11,   17,   23,
   24,   70,   68,   66,   60,   61,  112,  144,   74,  116,
  148,  164,  152,   62,  165,  172,   63,  120,  153,   38,
   25,   42,  114,   43,  180,
};
static const YYINT yysindex[] = {                      -147,
 -231, -231,    0,    0,    0,    0,  -84, -272,  -16,    0,
 -236, -212,  -95,    0, -231,    0, -143,    0,    0,    0,
    0,    0,    0, -184, -113,    0, -174, -172, -170,    0,
    0, -128, -114, -101,    0,  101, 1151,  -87, -132, -107,
  113, -113,  -76,    0,    0,  113, -113,    0,    0,  -23,
    0,   66,   66,  -50,   66,   66,    0,   66,  -34,  -63,
    0,    0,  579,    0,  -63,    0,  -29,    0,  -61,  -78,
  164, -113,    0,    0,    0,    0, 1151,   66,   66,  -69,
  491,  914,  144,    0,  610,    0,  958,   66,   66,    0,
   66,   66,   66,   66,   66,   66,   66,   66,   66,   66,
   66,   66,   66,   66,    0,    0,  -63,    0,  -13,  153,
  -26,    0, -113,  -76,  192,    0,  637,  979, 1122,   -2,
    0,   66,    0, 1122, 1046,  539,  610,  347,  347,  114,
  114,  114,  114,   32,   32,  158,  158,  158,  158,    0,
    0,    0,   10,  225,    0, -113,   66,    0,    0,   66,
    0, 1089,    0, 1057,    0,    0,  -24,  637, 1122, 1122,
    0,    0,    0,    0,  -21,   66,    0,   23,    0,   66,
    0,    8, 1083,    0, 1094,    0,    0,    0,    0,    0,
    0,    5,    0,
};
static const YYINT yyrindex[] = {                         0,
   26,   96,    0,    0,    0,    0,  -77,    0, -248,    0,
   62,    0,    0,    0, -127,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  808,    0,    0,    0,    0,    0,
 -173,    0,    0,    0,    0,    0,   28,    0,  -46,  -10,
   -7,    0,    0,    0,    0,  -56,  808,    0,    0,  -33,
    0,    0,    0,    0,    0,    0,    0,    0,  903,    3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   -6,
  -70, 1256,    0,    0,    0,    0,   40,    0,    0,   39,
    0,    0,   75,    0, 1164,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   -5,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   -4,    0,   29,    0,
    0,    0,    0, 1223,    0, 1200, 1186,  709,  780,  534,
  569,  604,  647,  463,  499,  105,  141,  177,  438,    0,
    0,    0,    0,   12,    0, 1256,   33,    0,    0,    0,
    0, -217,    0,    0,    0,    0,    0,   -4,   69,   61,
    0,    0,    0,    0,   15,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   53,  293,    0,  290,    0,  -25,  -35,  299,    0,    0,
    0,  264,    0,    0,  253,  -40,    0,    0,  213,    0,
 -134,    0,   31,    0,    0,    0, 1465,    0, -148,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1635
static const YYINT yytable[] = {                         76,
   89,   76,   24,   76,   76,   14,   71,   76,   76,   76,
   76,   76,   38,   76,    5,  109,   79,  163,  143,   90,
  168,   76,  176,  169,    4,   76,   76,   76,   76,    5,
  181,  182,    5,    6,   16,   78,  115,    7,  151,   78,
   78,  150,   15,   78,   78,   78,   78,   78,   35,   78,
   18,   24,   45,   39,   59,   37,   59,   59,   59,   76,
   76,   78,   78,   78,   78,   59,   90,   78,  103,  101,
   46,   79,  101,  101,   31,   79,   79,   77,  102,   79,
   79,   79,   79,   79,   39,   79,   40,   76,   41,   59,
   76,   57,    9,    9,    9,   78,   78,   79,   79,   79,
   79,  102,  117,   54,  102,   58,   84,   76,   12,   12,
   56,   76,   76,    1,    2,   76,   76,   76,   76,   76,
   76,   76,   27,   28,   29,  104,   78,   58,   57,   59,
   44,   79,   79,   76,   76,   76,   76,   85,   27,   27,
   27,   85,   85,   27,   45,   85,   85,   85,   85,   85,
  103,   85,   32,   33,   34,  101,   99,   46,  100,   47,
  102,   65,   79,   85,   85,   85,   85,   76,   76,   59,
   19,   20,   21,   86,   22,   64,  158,   86,   86,    5,
    6,   86,   86,   86,   86,   86,   67,   86,   27,   27,
   27,   55,   27,   48,   49,  110,   51,   85,   76,   86,
   86,   86,   86,   69,   59,   72,   73,  104,   83,   87,
   59,   10,   10,   87,   87,  111,   38,   87,   87,   87,
   87,   87,  113,   87,   88,   24,   24,  108,   85,   76,
  142,   38,  167,   86,   78,   87,   87,   87,   87,   76,
   76,   76,   76,  140,   76,  141,   76,   76,   76,   76,
  146,  104,   35,  170,  171,   24,   45,   39,   59,   88,
   76,   76,   76,   76,   86,   78,  156,   35,  157,   87,
   24,   45,   39,   59,   46,   78,   78,   78,   78,  174,
   78,  177,   78,   78,   78,   78,   24,  183,   74,   46,
   54,   27,   27,   27,   12,   57,   27,   78,   78,   78,
   87,   79,   53,    4,   26,   13,   57,   57,   57,   75,
   57,   79,   79,   79,   79,   57,   79,  107,   79,   79,
   79,   79,   48,   49,   50,   51,  145,   29,   29,   29,
    0,   58,    0,   79,   79,   79,    0,   76,    0,    0,
    0,    0,   58,   58,   58,    0,   58,   76,   76,   76,
   76,   58,   76,    0,   76,   76,   76,   76,    4,    0,
    0,   27,   27,   27,    0,    0,   27,   85,    0,   76,
   76,   76,    0,    0,    0,    0,    0,   85,   85,   85,
   85,    0,   85,  103,   85,   85,   85,   85,  101,   99,
    0,  100,    0,  102,    0,    0,    0,    0,    0,   85,
   85,   85,    0,   86,    0,    0,   95,    0,   96,    0,
    0,    0,    0,   86,   86,   86,   86,    0,   86,    0,
   86,   86,   86,   86,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   86,   86,   86,    0,   87,
  104,    0,    0,    0,    0,    0,    0,    0,    0,   87,
   87,   87,   87,    0,   87,    0,   87,   87,   87,   87,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   88,   87,   87,   87,   88,   88,    0,    0,   88,   88,
   88,   88,   88,    0,   88,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   83,   88,   88,   88,   88,
   83,    0,    0,   83,    0,   83,   83,   83,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   83,   83,   83,   83,    0,    0,  103,   92,    0,
   88,   84,  101,   99,    0,  100,   84,  102,    0,   84,
    0,   84,   84,   84,    0,    0,    0,    0,    0,    0,
   95,   93,   96,    0,    0,   83,    0,   84,   84,   84,
   84,   88,    0,    0,    0,    0,   93,    0,    0,    0,
    0,   93,    0,    0,   93,  103,   92,   93,    0,    0,
  101,   99,    0,  100,  104,  102,   83,    0,    0,    0,
    0,   84,   93,   93,   93,   93,    0,    0,   95,   93,
   96,   94,    0,    0,    0,    0,   94,    0,    0,   94,
    0,  106,   94,    0,   91,  103,   92,    0,    0,    0,
  101,   99,   84,  100,    0,  102,   93,   94,   94,   94,
   94,    0,  104,    0,    0,    0,   91,  105,   95,   93,
   96,   91,   97,   98,   91,    0,  103,   91,    0,    0,
    0,  101,   99,    0,  100,    0,  102,   93,    0,    0,
    0,   94,   91,   91,   91,   91,    0,    0,    0,   95,
   93,   96,  104,    0,   54,    0,   58,    0,    0,   92,
    0,   56,    0,    0,   92,    0,    0,   92,    0,    0,
   92,    0,   94,    0,    0,    0,   91,    0,    0,   57,
   88,    0,   91,  104,    0,   92,   92,   92,   92,    0,
   88,   88,   88,   88,    0,   88,    0,   88,   88,   88,
   88,    0,    0,    0,    0,   83,    0,   91,    0,    0,
    0,    0,   88,   88,   88,   83,   83,   83,   83,   92,
   83,   89,   83,   83,   83,   83,   89,    0,    0,   89,
    0,    0,   89,    0,    0,    0,    0,   83,   83,   83,
    0,   84,   55,  121,    0,    0,    0,   89,    0,   89,
   92,   84,   84,   84,   84,    0,   84,    0,   84,   84,
   84,   84,    0,    0,    0,   94,   97,   98,    0,    0,
    0,    0,    0,   84,   84,   84,   93,    0,    0,    0,
    0,   89,    0,    0,    0,    0,   93,   93,   93,   93,
    0,   93,   90,   93,   93,   93,   93,   90,    0,    0,
   90,    0,    0,   90,    0,    0,    0,    0,   93,   93,
   93,   94,   89,   94,   97,   98,    0,    0,   90,    0,
   90,   94,   94,   94,   94,   64,   94,   64,   94,   94,
   94,   94,   64,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   94,   94,   94,   91,    0,    0,    0,
   64,    0,   90,   94,   97,   98,   91,   91,   91,   91,
    0,   91,    0,   91,   91,   91,   91,    0,    0,    0,
    0,    0,    0,   48,   49,   50,   51,    0,   91,   91,
   91,    0,    0,   90,   94,   97,   98,    0,   52,   92,
    0,    0,    0,  147,    0,   53,    0,    0,    0,   92,
   92,   92,   92,    0,   92,    0,   92,   92,   92,   92,
    0,    0,    0,   64,    0,   79,    0,    0,    0,   79,
   79,   92,   92,   92,   79,   79,    0,   79,    0,   79,
  103,   92,    0,    0,    0,  101,   99,    0,  100,    0,
  102,   79,   79,   79,   79,    0,    0,    0,    0,    0,
    0,   89,    0,   95,   93,   96,    0,    0,    0,    0,
    0,   89,   89,   89,   89,    0,   89,    0,   89,   89,
   89,   89,    0,    0,  103,   92,   79,    0,  123,  101,
   99,    0,  100,   89,  102,    0,    0,  104,    0,    0,
    0,    0,    0,    0,    0,  103,   92,   95,   93,   96,
  101,   99,    0,  100,    0,  102,   79,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   91,   95,   93,
   96,    0,   90,    0,    0,    0,    0,    0,    0,    0,
    0,  104,   90,   90,   90,   90,    0,   90,    0,   90,
   90,   90,   90,    0,   64,   64,   64,   64,    0,    0,
   64,  149,  104,    0,   90,    0,    0,    0,    0,   64,
    0,   91,  103,   92,    0,    0,   64,  101,   99,    0,
  100,    0,  102,  103,   92,    0,    0,    0,  101,   99,
    0,  100,   91,  102,  155,   95,   93,   96,    0,    0,
    0,    0,    0,    0,    0,    0,   95,   93,   96,  103,
   92,    0,    0,    0,  101,   99,   54,  100,   58,  102,
  103,   92,    0,   56,    0,  101,   99,    0,  100,  104,
  102,    0,   95,   93,   96,    0,    0,    0,    0,    0,
  104,   57,    0,   95,   93,   96,    0,    0,  103,   92,
    0,    0,    0,  101,   99,    0,  100,    0,  102,   91,
    0,    0,    0,    0,    0,    0,  104,    0,    0,    0,
   91,   95,   93,   96,    0,    0,    0,  104,   54,    0,
   58,    0,    0,  122,    0,   56,   97,   79,   79,   79,
    0,   97,    0,    0,   97,    0,   91,   97,   94,   97,
   98,    0,    0,   57,   55,  104,    0,   91,   95,    0,
    0,    0,   97,   95,    0,    0,   95,    0,    0,   95,
    0,    0,   96,    0,    0,    0,    0,    0,    0,    0,
   96,    0,    0,   96,   95,   91,    0,    0,    0,    0,
    0,    0,   94,   97,   98,   99,   97,    0,   96,    0,
    0,    0,    0,   99,    0,    0,   99,    0,    0,    0,
    0,    0,    0,   94,   97,   98,   55,    0,   95,    0,
    0,   99,    0,    0,    0,    0,    0,   97,    0,    0,
    0,    0,   96,   64,    0,   64,    0,    0,    0,    0,
   64,    0,    0,    0,    0,    0,    0,    0,    0,   95,
    0,    0,    0,    0,   64,   99,    0,    0,   64,    0,
    0,    0,    0,   96,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  166,    0,    0,
   94,   97,   98,    0,    0,   48,   49,   50,   51,    0,
    0,   94,   97,   98,    0,    0,    0,    0,    0,    0,
   52,    0,    0,    0,  178,  147,  179,   53,    0,    0,
    0,    0,  161,  162,    0,    0,    0,   94,   97,   98,
    0,   64,    0,    0,    0,    0,    0,    0,   94,   97,
   98,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   48,   49,   50,
   51,    0,    0,    0,    0,    0,   94,   97,   98,    0,
    0,    0,   52,    0,    0,    0,   97,    0,    0,   53,
    0,    0,    0,    0,    0,    0,   97,   97,   97,   97,
    0,   97,    0,   97,   97,   97,   97,    0,   95,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   95,   95,
   95,   95,   96,   95,    0,   95,   95,   95,   95,    0,
    0,    0,   96,   96,   96,   96,    0,   96,    0,   96,
   96,   96,   96,    0,    0,   99,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   99,   99,   99,   99,    0,
   99,    0,   99,   99,   99,   99,    0,    0,    0,    0,
    0,    0,   64,   64,   64,   64,   81,   82,   64,   85,
   86,    0,   87,    0,    0,    0,    0,   64,    0,    0,
    0,    0,   64,   64,   64,    0,    0,    0,    0,    0,
    0,    0,  118,  119,    0,    0,    0,    0,    0,    0,
    0,    0,  124,  125,    0,  126,  127,  128,  129,  130,
  131,  132,  133,  134,  135,  136,  137,  138,  139,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  154,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  159,    0,    0,  160,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  173,    0,    0,    0,  175,
};
static const YYINT yycheck[] = {                         33,
   35,   35,   59,   37,   38,  278,   42,   41,   42,   43,
   44,   45,   59,   47,  263,   45,   40,  152,   45,   60,
   45,   47,  171,  158,  256,   59,   60,   61,   62,  278,
  179,  180,  264,  265,  271,   33,   72,  269,   41,   37,
   38,   44,   59,   41,   42,   43,   44,   45,   59,   47,
  263,   59,   59,   59,   59,   25,  274,  275,  276,   93,
   94,   59,   60,   61,   62,  283,  107,   91,   37,   41,
   59,   33,   44,   42,  259,   37,   38,   47,   47,   41,
   42,   43,   44,   45,  259,   47,  259,  113,  259,   37,
  124,   59,  266,  267,  268,   93,   94,   59,   60,   61,
   62,   41,   72,   38,   44,   40,   54,   33,  282,  283,
   45,   37,   38,  261,  262,   41,   42,   43,   44,   45,
  146,   47,  266,  267,  268,   94,  124,   59,   63,   77,
  259,   93,   94,   59,   60,   61,   62,   33,  266,  267,
  268,   37,   38,  271,  259,   41,   42,   43,   44,   45,
   37,   47,  266,  267,  268,   42,   43,  259,   45,   59,
   47,  294,  124,   59,   60,   61,   62,   93,   94,  117,
  266,  267,  268,   33,  270,  263,  146,   37,   38,  264,
  265,   41,   42,   43,   44,   45,  294,   47,  266,  267,
  268,  126,  270,  257,  258,  257,  260,   93,  124,   59,
   60,   61,   62,   91,  152,  282,  283,   94,  259,   33,
  158,  282,  283,   37,   38,  294,  263,   41,   42,   43,
   44,   45,   59,   47,  294,  282,  283,  257,  124,  263,
  257,  278,  257,   93,   91,   59,   60,   61,   62,  273,
  274,  275,  276,  257,  278,   93,  280,  281,  282,  283,
   59,   94,  263,  275,  276,  263,  263,  263,  263,  294,
  294,  295,  296,  297,  124,  263,  257,  278,   44,   93,
  278,  278,  278,  278,  263,  273,  274,  275,  276,  257,
  278,  274,  280,  281,  282,  283,  294,  283,  274,  278,
  263,  266,  267,  268,    2,  263,  271,  295,  296,  297,
  124,  263,  263,  278,   15,    7,  274,  275,  276,   46,
  278,  273,  274,  275,  276,  283,  278,   65,  280,  281,
  282,  283,  257,  258,  259,  260,  114,  266,  267,  268,
   -1,  263,   -1,  295,  296,  297,   -1,  263,   -1,   -1,
   -1,   -1,  274,  275,  276,   -1,  278,  273,  274,  275,
  276,  283,  278,   -1,  280,  281,  282,  283,  263,   -1,
   -1,  266,  267,  268,   -1,   -1,  271,  263,   -1,  295,
  296,  297,   -1,   -1,   -1,   -1,   -1,  273,  274,  275,
  276,   -1,  278,   37,  280,  281,  282,  283,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,  295,
  296,  297,   -1,  263,   -1,   -1,   60,   -1,   62,   -1,
   -1,   -1,   -1,  273,  274,  275,  276,   -1,  278,   -1,
  280,  281,  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  295,  296,  297,   -1,  263,
   94,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  273,
  274,  275,  276,   -1,  278,   -1,  280,  281,  282,  283,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   33,  295,  296,  297,   37,   38,   -1,   -1,   41,   42,
   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   33,   59,   60,   61,   62,
   38,   -1,   -1,   41,   -1,   43,   44,   45,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,   60,   61,   62,   -1,   -1,   37,   38,   -1,
   93,   33,   42,   43,   -1,   45,   38,   47,   -1,   41,
   -1,   43,   44,   45,   -1,   -1,   -1,   -1,   -1,   -1,
   60,   61,   62,   -1,   -1,   93,   -1,   59,   60,   61,
   62,  124,   -1,   -1,   -1,   -1,   33,   -1,   -1,   -1,
   -1,   38,   -1,   -1,   41,   37,   38,   44,   -1,   -1,
   42,   43,   -1,   45,   94,   47,  124,   -1,   -1,   -1,
   -1,   93,   59,   60,   61,   62,   -1,   -1,   60,   61,
   62,   33,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,
   -1,   33,   44,   -1,  124,   37,   38,   -1,   -1,   -1,
   42,   43,  124,   45,   -1,   47,   93,   59,   60,   61,
   62,   -1,   94,   -1,   -1,   -1,   33,   59,   60,   61,
   62,   38,  296,  297,   41,   -1,   37,   44,   -1,   -1,
   -1,   42,   43,   -1,   45,   -1,   47,  124,   -1,   -1,
   -1,   93,   59,   60,   61,   62,   -1,   -1,   -1,   60,
   61,   62,   94,   -1,   38,   -1,   40,   -1,   -1,   33,
   -1,   45,   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,
   44,   -1,  124,   -1,   -1,   -1,   93,   -1,   -1,   63,
  263,   -1,  124,   94,   -1,   59,   60,   61,   62,   -1,
  273,  274,  275,  276,   -1,  278,   -1,  280,  281,  282,
  283,   -1,   -1,   -1,   -1,  263,   -1,  124,   -1,   -1,
   -1,   -1,  295,  296,  297,  273,  274,  275,  276,   93,
  278,   33,  280,  281,  282,  283,   38,   -1,   -1,   41,
   -1,   -1,   44,   -1,   -1,   -1,   -1,  295,  296,  297,
   -1,  263,  126,  273,   -1,   -1,   -1,   59,   -1,   61,
  124,  273,  274,  275,  276,   -1,  278,   -1,  280,  281,
  282,  283,   -1,   -1,   -1,  295,  296,  297,   -1,   -1,
   -1,   -1,   -1,  295,  296,  297,  263,   -1,   -1,   -1,
   -1,   93,   -1,   -1,   -1,   -1,  273,  274,  275,  276,
   -1,  278,   33,  280,  281,  282,  283,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,  295,  296,
  297,  263,  124,  295,  296,  297,   -1,   -1,   59,   -1,
   61,  273,  274,  275,  276,   38,  278,   40,  280,  281,
  282,  283,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  295,  296,  297,  263,   -1,   -1,   -1,
   63,   -1,   93,  295,  296,  297,  273,  274,  275,  276,
   -1,  278,   -1,  280,  281,  282,  283,   -1,   -1,   -1,
   -1,   -1,   -1,  257,  258,  259,  260,   -1,  295,  296,
  297,   -1,   -1,  124,  295,  296,  297,   -1,  272,  263,
   -1,   -1,   -1,  277,   -1,  279,   -1,   -1,   -1,  273,
  274,  275,  276,   -1,  278,   -1,  280,  281,  282,  283,
   -1,   -1,   -1,  126,   -1,   33,   -1,   -1,   -1,   37,
   38,  295,  296,  297,   42,   43,   -1,   45,   -1,   47,
   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,   59,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,
   -1,  263,   -1,   60,   61,   62,   -1,   -1,   -1,   -1,
   -1,  273,  274,  275,  276,   -1,  278,   -1,  280,  281,
  282,  283,   -1,   -1,   37,   38,   94,   -1,   41,   42,
   43,   -1,   45,  295,   47,   -1,   -1,   94,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   37,   38,   60,   61,   62,
   42,   43,   -1,   45,   -1,   47,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   60,   61,
   62,   -1,  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   94,  273,  274,  275,  276,   -1,  278,   -1,  280,
  281,  282,  283,   -1,  257,  258,  259,  260,   -1,   -1,
  263,   93,   94,   -1,  295,   -1,   -1,   -1,   -1,  272,
   -1,  124,   37,   38,   -1,   -1,  279,   42,   43,   -1,
   45,   -1,   47,   37,   38,   -1,   -1,   -1,   42,   43,
   -1,   45,  124,   47,   59,   60,   61,   62,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   60,   61,   62,   37,
   38,   -1,   -1,   -1,   42,   43,   38,   45,   40,   47,
   37,   38,   -1,   45,   -1,   42,   43,   -1,   45,   94,
   47,   -1,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,
   94,   63,   -1,   60,   61,   62,   -1,   -1,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,  124,
   -1,   -1,   -1,   -1,   -1,   -1,   94,   -1,   -1,   -1,
  124,   60,   61,   62,   -1,   -1,   -1,   94,   38,   -1,
   40,   -1,   -1,  280,   -1,   45,   33,  295,  296,  297,
   -1,   38,   -1,   -1,   41,   -1,  124,   44,  295,  296,
  297,   -1,   -1,   63,  126,   94,   -1,  124,   33,   -1,
   -1,   -1,   59,   38,   -1,   -1,   41,   -1,   -1,   44,
   -1,   -1,   33,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   41,   -1,   -1,   44,   59,  124,   -1,   -1,   -1,   -1,
   -1,   -1,  295,  296,  297,   33,   93,   -1,   59,   -1,
   -1,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,  295,  296,  297,  126,   -1,   93,   -1,
   -1,   59,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,
   -1,   -1,   93,   38,   -1,   40,   -1,   -1,   -1,   -1,
   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,
   -1,   -1,   -1,   -1,   59,   93,   -1,   -1,   63,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,   -1,   -1,
  295,  296,  297,   -1,   -1,  257,  258,  259,  260,   -1,
   -1,  295,  296,  297,   -1,   -1,   -1,   -1,   -1,   -1,
  272,   -1,   -1,   -1,  282,  277,  273,  279,   -1,   -1,
   -1,   -1,  284,  285,   -1,   -1,   -1,  295,  296,  297,
   -1,  126,   -1,   -1,   -1,   -1,   -1,   -1,  295,  296,
  297,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,   -1,   -1,   -1,   -1,   -1,  295,  296,  297,   -1,
   -1,   -1,  272,   -1,   -1,   -1,  263,   -1,   -1,  279,
   -1,   -1,   -1,   -1,   -1,   -1,  273,  274,  275,  276,
   -1,  278,   -1,  280,  281,  282,  283,   -1,  263,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  273,  274,
  275,  276,  263,  278,   -1,  280,  281,  282,  283,   -1,
   -1,   -1,  273,  274,  275,  276,   -1,  278,   -1,  280,
  281,  282,  283,   -1,   -1,  263,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  273,  274,  275,  276,   -1,
  278,   -1,  280,  281,  282,  283,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,   52,   53,  263,   55,
   56,   -1,   58,   -1,   -1,   -1,   -1,  272,   -1,   -1,
   -1,   -1,  277,  278,  279,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   78,   79,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   88,   89,   -1,   91,   92,   93,   94,   95,
   96,   97,   98,   99,  100,  101,  102,  103,  104,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  122,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  147,   -1,   -1,  150,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  166,   -1,   -1,   -1,  170,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 298
#define YYUNDFTOKEN 336
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'|'",0,"'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","CHAR","ID","STR",
"PROGRAM","MODULE","END","PUBLIC","FORWARD","STRING","NUMBER","ARRAY",
"FUNCTION","VOID","CONST","IF","THEN","FI","ELIF","ELSE","RETURN","START","FOR",
"UNTIL","STEP","DO","DONE","REPEAT","STOP","FARGS","CHARS","INTS","ADDR","VAR",
"ARGS","DECL","NIL","EQ","NE","GE","LE","uminus",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"$$1 :",
"file : PROGRAM decls START $$1 main END",
"file : MODULE decls END",
"decls :",
"decls : gdecls",
"gdecls : gdecls ';' decl",
"gdecls : decl",
"decl : qualif const vardecl",
"$$2 :",
"$$3 :",
"decl : FUNCTION qualif ftype ID $$2 fvars $$3 eqbody",
"$$4 :",
"decl : FUNCTION qualif ftype ID $$4 eqbody",
"decl : error",
"fvar : NUMBER ID",
"fvar : STRING ID",
"fvar : ARRAY ID vdim",
"fvars : fvar",
"fvars : fvars ';' fvar",
"vardecl : NUMBER ID eqint",
"vardecl : STRING ID eqstr",
"vardecl : ARRAY ID vdim eqvec",
"vdim : '[' INT ']'",
"vdim :",
"qualif : PUBLIC",
"qualif : FORWARD",
"qualif :",
"const : CONST",
"const :",
"type : NUMBER",
"type : STRING",
"type : ARRAY",
"ftype : type",
"ftype : VOID",
"eqint :",
"eqint : EQ INT",
"eqint : EQ '-' INT",
"eqstr :",
"eqstr : EQ chars",
"chars : char",
"chars : chars char",
"char : INT",
"char : CHAR",
"char : STR",
"eqvec :",
"eqvec : EQ ints",
"ints : INT",
"ints : '-' INT",
"ints : ints ',' INT",
"ints : ints ',' '-' INT",
"eqbody : DONE",
"eqbody : DO body",
"main : fvars ';' instrs",
"main : instrs",
"body : fvars ';' instrs ret",
"body : instrs ret",
"ret : RETURN",
"ret : RETURN expr",
"ret :",
"loop : ret",
"loop : REPEAT",
"loop : STOP",
"block : instrs loop",
"instrs :",
"instrs : instrs instr",
"instr : IF expr THEN block elifs else FI",
"$$5 :",
"instr : FOR expr UNTIL expr STEP expr DO $$5 block DONE",
"instr : expr '!'",
"instr : expr ';'",
"instr : lval '#' expr ';'",
"elifs :",
"elifs : elifs ELIF expr THEN block",
"else :",
"else : ELSE block",
"lval : ID",
"lval : ID '[' expr ']'",
"expr : chars",
"expr : lval",
"expr : '?'",
"expr : '&' lval",
"expr : '(' expr ')'",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '^' expr",
"expr : expr '=' expr",
"expr : expr NE expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : '~' expr",
"expr : '-' expr",
"expr : lval EQ expr",
"expr : ID '(' exprs ')'",
"exprs : expr",
"exprs : exprs ',' expr",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 205 "minor.y"
char **yynames =
#ifdef YYDEBUG
(char**)yyname;
#else
 0;
#endif

#define tSUB(n,i) tTYPE(n->SUB(i)->info)
static char errstr[200];
static char *types[] = { "void", "number", "string", "array", 0 };

static void isFwd(char *name, int type, Node *n) {
	int attrib = n->attrib;
	if (attrib != NIL && tTYPE(type) == tVEC) attrib = n->SUB(1)->attrib;
	if ((type & tFWD) && attrib != NIL) {
		sprintf(errstr, "forward declarations can not be initialized for '%s'", name);
		yyerror(errstr);
	}
}

static void isCte(Node *n) {
	char *name = n->SUB(0)->SUB(0)->value.s;
	int type = n->info;
	Node *init = n->SUB(0)->SUB(1);
	IDnew(type, name, init);
	n->SUB(0)->SUB(0)->info = type;
	if ((type & tCNST) && (type & tFWD) == 0 && init->attrib == NIL) {
		sprintf(errstr, "constant values must be initialized for '%s'", name);
		yyerror(errstr);
	}
	isFwd(name, type, init);
}

static void isFunc(char *id, int type) {
	void *arg;
	if (IDfind(id, (void**)IDtest) >= 0 && (IDfind(id, &arg) & (tFUNC | tFWD)) == (tFUNC | tFWD))
		/* name exists and is function forward declaration */
		IDreplace(type, id, arg);
	else
		IDnew(type, id, nilNode(NIL));
}

static int isId(char *id, Node *off, int *base) {
	Node *args;
	int type = IDfind(id, (void**)&args);
	if (type < 0) return tVOID;
	if (!off) {
		if ((type & tFUNC)) {
			while (args->attrib != NIL && args->SUB(1)->SUB(1)->attrib != NIL)
				args = args->SUB(0); /* optional argument */
			if (args->attrib != NIL) {
				sprintf(errstr, "function '%s' requires arguments", id);
				yyerror(errstr);
			}
		}
		return type;
	}
	if (tTYPE(type) != tSTR && tTYPE(type) != tVEC) {
		sprintf(errstr, "can not index '%s', not a string or array", id);
		yyerror(errstr);
		return tVOID;
	}
	if (tTYPE(off->info) != tINT) {
		sprintf(errstr, "offset for '%s' indexing must be a number", id);
		yyerror(errstr);
		return tVOID;
	}
	if (base) *base = type;
	return (type & ~(tSTR | tVEC)) | tINT;
}

static int isInt(Node *n, char *op) {
	if (tSUB(n,0) == tINT && tSUB(n,1) == tINT)
		return tINT;
	sprintf(errstr, "invalid arguments for '%s', not numbers", op);
	yyerror(errstr);
	return tVOID;
}

static int isAddSub(Node *n, char *op) {
	if (tSUB(n,0) == tINT && tSUB(n,1) == tINT)
		return tINT;
	if (tSUB(n,0) == tINT && tSUB(n,1) == tVEC)
		return tVEC;
	if (tSUB(n,0) == tVEC && tSUB(n,1) == tINT)
		return tVEC;
	if (!strcmp(op, "-") && tSUB(n,0) == tVEC && tSUB(n,1) == tVEC)
		return tINT;
	sprintf(errstr, "invalid arguments for '%s', incompatible types", op);
	yyerror(errstr);
	return tVOID;
}

static int isCmp(Node *n, char *op) {
	if (tSUB(n,0) == tINT && tSUB(n,1) == tINT)
		return tINT;
	if (tSUB(n,0) == tSTR && tSUB(n,1) == tSTR)
		return tINT;
	if (tSUB(n,0) == tVEC && tSUB(n,1) == tVEC)
		return tINT;
	if (tSUB(n,0) == tINT && n->SUB(0)->attrib == CHARS && n->SUB(0)->SUB(1)->value.i == 0)
		return tINT;
	if (tSUB(n,1) == tINT && n->SUB(1)->attrib == CHARS && n->SUB(1)->SUB(1)->value.i == 0)
		return tINT;
	sprintf(errstr, "invalid arguments for '%s', not of the same type", op);
	yyerror(errstr);
	return tVOID;
}

static int isUniInt(Node *n, char *op) {
	if (tSUB(n,0) == tINT)
		return tINT;
	sprintf(errstr, "invalid argument for '%s', not a number", op);
	yyerror(errstr);
	return tVOID;
}

static int isAddr(Node *n) {
	if (tSUB(n,0) != tINT) {
		sprintf(errstr, "can not take address '&' of non-number");
		yyerror(errstr);
		return tVOID;
	}
	if (n->SUB(0)->attrib == '[') return IDfind(n->SUB(0)->SUB(1)->value.s,0);
	return tVEC;
}

static int isAssign(Node *n) {
	if (n->SUB(1)->info & tCNST) {
		sprintf(errstr, "constant value for ':='");
		yyerror(errstr);
	}
	if (n->SUB(1)->info & tFUNC) {
		sprintf(errstr, "function for ':='");
		yyerror(errstr);
	}
	if (tSUB(n,0) == tINT && n->SUB(0)->attrib == CHARS && n->SUB(0)->SUB(1)->value.i == 0)
		return tSUB(n,0);
	if (tSUB(n,0) == tINT && tSUB(n,1) == tINT)
		return tINT;
	if (tSUB(n,0) == tSTR && tSUB(n,1) == tSTR)
		return tSTR;
	if (tSUB(n,0) == tVEC && tSUB(n,1) == tVEC)
		return tVEC;
	sprintf(errstr, "invalid argument for ':=', espression is %s while variable is %s", types[tSUB(n,0)], types[tSUB(n,1)]);
	yyerror(errstr);
	return tVOID;
}

static int isCall(char *name, Node *fargs, Node *eargs) {
	if (fargs->attrib != NIL && eargs->attrib != NIL) {
		int pos = isCall(name, fargs->SUB(0), eargs->SUB(1)) + 1;
		if (!pos) return -1;
		if (tSUB(eargs,0) == tINT &&
		    eargs->SUB(0)->attrib == CHARS &&
		    eargs->SUB(0)->SUB(1)->value.i == 0)
			return pos;
		if (tSUB(fargs, 1) != tSUB(eargs, 0)) {
			sprintf(errstr, "invalid argument %d for '%s': expected %s, got %s", pos, name, types[tSUB(fargs, 1)], types[tSUB(eargs, 0)]);
			yyerror(errstr);
		}
		return pos;
	} else if (fargs->attrib != NIL) {
		sprintf(errstr, "missing arguments for '%s'", name);
		yyerror(errstr);
		return -1;
	} else if (eargs->attrib != NIL) {
		sprintf(errstr, "too many arguments for '%s'", name);
		yyerror(errstr);
		return -1;
	}
	return 0;
}

static void isDim(char *name, int dim, Node *init) {
	int cnt;
	if (!name) {
		if (!dim) yyerror("array dimension must be positive");
		return;
	}
	if (!dim) return; /* [] not specified */
	for (cnt = init->attrib != NIL; init->attrib == INTS; cnt++)
		init = init->SUB(0);
	if (cnt > dim) {
		sprintf(errstr, "too many initializers '%d' for '%s[%d]'", cnt, name, dim);
		yyerror(errstr);
	}
}

static void isPrint(Node *n) {
	if (tTYPE(n->info) == tVOID) yyerror("can not print void expression");
}

static void isCycle() {
	if (!cycle) yyerror("'repeat' or 'stop' outside 'for' block");
}

static void isStr(Node *n) {
	if (n->info != tSTR) yyerror("invalid string initializer");
}

static void isRet(Node *n) {
	if (!n) {
		if (tTYPE(ret) != tVOID) {
			sprintf(errstr, "invalid expression in return for void function '%s'", func);
			yyerror(errstr);
		}
	} else if (tTYPE(n->info) != tTYPE(ret)) {
		sprintf(errstr, "invalid return type (%s) for '%s' (%s)",
			types[tTYPE(n->info)], func, types[tTYPE(ret)]);
		yyerror(errstr);
	}
}

static void isAlloc(Node *lval, Node *expr) {
	if (lval->info & tCNST) {
		sprintf(errstr, "constant value for '#'\n");
		yyerror(errstr);
	}
	if (tTYPE(lval->info) == tINT || tTYPE(expr->info) != tINT) {
		sprintf(errstr, "invalid arguments for '#', use array or string and number");
		yyerror(errstr);
	}
}
#line 948 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 46 "minor.y"
	{ func="main"; ret=tPUB + tINT + tFUNC; IDpush(); }
break;
case 2:
#line 46 "minor.y"
	{ IDpop(); evaluate(binNode(PROGRAM, yystack.l_mark[-4].n, binNode(FUNCTION, binNode(END, TID(func), TINT(ret)), binNode(FARGS, nilNode(NIL), yystack.l_mark[-1].n)))); }
break;
case 3:
#line 47 "minor.y"
	{ evaluate(uniNode(MODULE, yystack.l_mark[-1].n)); }
break;
case 4:
#line 50 "minor.y"
	{ yyval.n = nilNode(NIL); }
break;
case 5:
#line 51 "minor.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 6:
#line 54 "minor.y"
	{ yyval.n = binNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 7:
#line 55 "minor.y"
	{ yyval.n = binNode(DECL, nilNode(NIL), yystack.l_mark[0].n); }
break;
case 8:
#line 58 "minor.y"
	{ yyval.n = uniNode(VAR, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[-2].i+yystack.l_mark[-1].i+yystack.l_mark[0].n->info; isCte(yyval.n); }
break;
case 9:
#line 59 "minor.y"
	{ isFunc(func = yystack.l_mark[0].s, ret = yystack.l_mark[-2].i+yystack.l_mark[-1].i+tFUNC); IDpush(); }
break;
case 10:
#line 59 "minor.y"
	{ IDchange(ret, yystack.l_mark[-2].s, yystack.l_mark[0].n, 1); }
break;
case 11:
#line 59 "minor.y"
	{ yyval.n = binNode(FUNCTION, binNode(END, TID(yystack.l_mark[-4].s), TINT(ret)), binNode(FARGS, yystack.l_mark[-2].n, yystack.l_mark[0].n)); IDpop(); isFwd(func, ret, yystack.l_mark[0].n); }
break;
case 12:
#line 60 "minor.y"
	{ isFunc( func = yystack.l_mark[0].s, ret = yystack.l_mark[-2].i+yystack.l_mark[-1].i+tFUNC); IDpush(); }
break;
case 13:
#line 60 "minor.y"
	{ yyval.n = binNode(FUNCTION, binNode(END, TID(yystack.l_mark[-2].s), TINT(ret)), binNode(FARGS, nilNode(NIL), yystack.l_mark[0].n)); IDpop(); isFwd(func, ret, yystack.l_mark[0].n); }
break;
case 14:
#line 61 "minor.y"
	{ yyval.n = nilNode(NIL); }
break;
case 15:
#line 64 "minor.y"
	{ yyval.n = binNode(NUMBER, TID(yystack.l_mark[0].s), nilNode(NIL)); yyval.n->info = tINT; }
break;
case 16:
#line 65 "minor.y"
	{ yyval.n = binNode(STRING, TID(yystack.l_mark[0].s), nilNode(NIL)); yyval.n->info = tSTR; }
break;
case 17:
#line 66 "minor.y"
	{ yyval.n = binNode(ARRAY, TID(yystack.l_mark[-1].s), binNode(INTS, TINT(yystack.l_mark[0].i), nilNode(NIL))); yyval.n->info = tVEC; }
break;
case 18:
#line 69 "minor.y"
	{ yyval.n = binNode(ARGS, nilNode(NIL), yystack.l_mark[0].n);IDnew(yystack.l_mark[0].n->info, yystack.l_mark[0].n->SUB(0)->value.s, yystack.l_mark[0].n->SUB(1)); }
break;
case 19:
#line 70 "minor.y"
	{ yyval.n = binNode(ARGS, yystack.l_mark[-2].n, yystack.l_mark[0].n);IDnew(yystack.l_mark[0].n->info, yystack.l_mark[0].n->SUB(0)->value.s, yystack.l_mark[0].n->SUB(1)); }
break;
case 20:
#line 73 "minor.y"
	{ yyval.n = binNode(NUMBER, TID(yystack.l_mark[-1].s), yystack.l_mark[0].n); yyval.n->info = tINT; }
break;
case 21:
#line 74 "minor.y"
	{ yyval.n = binNode(STRING, TID(yystack.l_mark[-1].s), yystack.l_mark[0].n); yyval.n->info = tSTR; }
break;
case 22:
#line 75 "minor.y"
	{ yyval.n = binNode(ARRAY, TID(yystack.l_mark[-2].s), binNode(INTS, TINT(yystack.l_mark[-1].i), yystack.l_mark[0].n)); yyval.n->info = tVEC; isDim(yystack.l_mark[-2].s, yystack.l_mark[-1].i, yystack.l_mark[0].n); }
break;
case 23:
#line 78 "minor.y"
	{ yyval.i = yystack.l_mark[-1].i; isDim(0, yystack.l_mark[-1].i, 0); }
break;
case 24:
#line 79 "minor.y"
	{ yyval.i = 0; }
break;
case 25:
#line 82 "minor.y"
	{ yyval.i = tPUB; }
break;
case 26:
#line 83 "minor.y"
	{ yyval.i = tFWD; }
break;
case 27:
#line 84 "minor.y"
	{ yyval.i = 0; }
break;
case 28:
#line 87 "minor.y"
	{ yyval.i = tCNST; }
break;
case 29:
#line 88 "minor.y"
	{ yyval.i = 0; }
break;
case 30:
#line 91 "minor.y"
	{ yyval.i = tINT; }
break;
case 31:
#line 92 "minor.y"
	{ yyval.i = tSTR; }
break;
case 32:
#line 93 "minor.y"
	{ yyval.i = tVEC; }
break;
case 33:
#line 96 "minor.y"
	{ yyval.i = yystack.l_mark[0].i; }
break;
case 34:
#line 97 "minor.y"
	{ yyval.i = tVOID; }
break;
case 35:
#line 100 "minor.y"
	{ yyval.n = nilNode(NIL); }
break;
case 36:
#line 101 "minor.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); }
break;
case 37:
#line 102 "minor.y"
	{ yyval.n = intNode(INT, -yystack.l_mark[0].i); }
break;
case 38:
#line 105 "minor.y"
	{ yyval.n = nilNode(NIL); }
break;
case 39:
#line 106 "minor.y"
	{ isStr(yyval.n = yystack.l_mark[0].n); }
break;
case 40:
#line 109 "minor.y"
	{ yyval.n = binNode(CHARS, nilNode(NIL), yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 41:
#line 110 "minor.y"
	{ yyval.n = binNode(CHARS, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = tSTR; }
break;
case 42:
#line 113 "minor.y"
	{ yyval.n = TINT(yystack.l_mark[0].i); yyval.n->info = tINT; }
break;
case 43:
#line 114 "minor.y"
	{ yyval.n = intNode(CHAR, yystack.l_mark[0].i); yyval.n->info = tINT; }
break;
case 44:
#line 115 "minor.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); yyval.n->info = tSTR; }
break;
case 45:
#line 118 "minor.y"
	{ yyval.n = nilNode(NIL); }
break;
case 46:
#line 119 "minor.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 47:
#line 122 "minor.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); }
break;
case 48:
#line 123 "minor.y"
	{ yyval.n = intNode(INT, -yystack.l_mark[0].i); }
break;
case 49:
#line 124 "minor.y"
	{ yyval.n = binNode(INTS, yystack.l_mark[-2].n, intNode(INT, yystack.l_mark[0].i)); }
break;
case 50:
#line 125 "minor.y"
	{ yyval.n = binNode(INTS, yystack.l_mark[-3].n, intNode(INT, -yystack.l_mark[0].i)); }
break;
case 51:
#line 128 "minor.y"
	{ yyval.n = nilNode(NIL); }
break;
case 52:
#line 129 "minor.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 53:
#line 132 "minor.y"
	{ yyval.n = binNode(START, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 54:
#line 133 "minor.y"
	{ yyval.n = binNode(START, nilNode(NIL), yystack.l_mark[0].n); }
break;
case 55:
#line 136 "minor.y"
	{ yyval.n = binNode(START, yystack.l_mark[-3].n, binNode(';', yystack.l_mark[-1].n, yystack.l_mark[0].n)); }
break;
case 56:
#line 137 "minor.y"
	{ yyval.n = binNode(START, nilNode(NIL), binNode(';', yystack.l_mark[-1].n, yystack.l_mark[0].n)); }
break;
case 57:
#line 140 "minor.y"
	{ yyval.n = uniNode(RETURN, nilNode(NIL)); isRet(0); }
break;
case 58:
#line 141 "minor.y"
	{ yyval.n = uniNode(RETURN, yystack.l_mark[0].n); isRet(yystack.l_mark[0].n); }
break;
case 59:
#line 142 "minor.y"
	{ yyval.n = nilNode(NIL); }
break;
case 60:
#line 145 "minor.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 61:
#line 146 "minor.y"
	{ yyval.n = intNode(REPEAT, 1); isCycle(); }
break;
case 62:
#line 147 "minor.y"
	{ yyval.n = intNode(STOP, 1); isCycle(); }
break;
case 63:
#line 150 "minor.y"
	{ yyval.n = binNode(';', yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 64:
#line 153 "minor.y"
	{ yyval.n = nilNode(NIL); }
break;
case 65:
#line 154 "minor.y"
	{ yyval.n = binNode(';', yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 66:
#line 157 "minor.y"
	{ yyval.n = binNode(FI, binNode(THEN, binNode(IF, yystack.l_mark[-5].n, yystack.l_mark[-3].n), yystack.l_mark[-2].n), yystack.l_mark[-1].n); }
break;
case 67:
#line 158 "minor.y"
	{ cycle++; }
break;
case 68:
#line 158 "minor.y"
	{ yyval.n = binNode(FOR, binNode(UNTIL, yystack.l_mark[-8].n, yystack.l_mark[-6].n), binNode(STEP, yystack.l_mark[-1].n, yystack.l_mark[-4].n)); cycle--; }
break;
case 69:
#line 159 "minor.y"
	{ yyval.n = uniNode('!', yystack.l_mark[-1].n); isPrint(yystack.l_mark[-1].n); }
break;
case 70:
#line 160 "minor.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 71:
#line 161 "minor.y"
	{ yyval.n = binNode('#', yystack.l_mark[-1].n, yystack.l_mark[-3].n); isAlloc(yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 72:
#line 164 "minor.y"
	{ yyval.n = nilNode(NIL); }
break;
case 73:
#line 165 "minor.y"
	{ yyval.n = binNode(ELIF, yystack.l_mark[-4].n, binNode(IF, yystack.l_mark[-2].n, yystack.l_mark[0].n)); }
break;
case 74:
#line 168 "minor.y"
	{ yyval.n = nilNode(NIL); }
break;
case 75:
#line 169 "minor.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 76:
#line 172 "minor.y"
	{ yyval.n = TID(yystack.l_mark[0].s); yyval.n->info = isId(yystack.l_mark[0].s, 0, 0); }
break;
case 77:
#line 173 "minor.y"
	{ yyval.n = binNode('[', yystack.l_mark[-1].n, TID(yystack.l_mark[-3].s)); yyval.n->info = isId(yystack.l_mark[-3].s, yystack.l_mark[-1].n, &yyval.n->SUB(1)->info); }
break;
case 78:
#line 176 "minor.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 79:
#line 177 "minor.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 80:
#line 178 "minor.y"
	{ yyval.n = nilNode('?'); yyval.n->info = tINT; }
break;
case 81:
#line 179 "minor.y"
	{ yyval.n = uniNode(ADDR, yystack.l_mark[0].n); yyval.n->info = isAddr(yyval.n); }
break;
case 82:
#line 180 "minor.y"
	{ yyval.n = yystack.l_mark[-1].n; yyval.n->info = yystack.l_mark[-1].n->info; }
break;
case 83:
#line 181 "minor.y"
	{ yyval.n = binNode('+', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = isAddSub(yyval.n, "+"); }
break;
case 84:
#line 182 "minor.y"
	{ yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = isAddSub(yyval.n, "-"); }
break;
case 85:
#line 183 "minor.y"
	{ yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = isInt(yyval.n, "*"); }
break;
case 86:
#line 184 "minor.y"
	{ yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = isInt(yyval.n, "/"); }
break;
case 87:
#line 185 "minor.y"
	{ yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = isInt(yyval.n, "%"); }
break;
case 88:
#line 186 "minor.y"
	{ yyval.n = binNode('^', yystack.l_mark[0].n, yystack.l_mark[-2].n); yyval.n->info = isInt(yyval.n, "^"); }
break;
case 89:
#line 187 "minor.y"
	{ yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = isCmp(yyval.n, "="); }
break;
case 90:
#line 188 "minor.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = isCmp(yyval.n, "~="); }
break;
case 91:
#line 189 "minor.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = isCmp(yyval.n, ">="); }
break;
case 92:
#line 190 "minor.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = isCmp(yyval.n, "<="); }
break;
case 93:
#line 191 "minor.y"
	{ yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = isCmp(yyval.n, "<"); }
break;
case 94:
#line 192 "minor.y"
	{ yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = isCmp(yyval.n, ">"); }
break;
case 95:
#line 193 "minor.y"
	{ yyval.n = binNode('&', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = isInt(yyval.n, "&"); }
break;
case 96:
#line 194 "minor.y"
	{ yyval.n = binNode('|', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = isInt(yyval.n, "|"); }
break;
case 97:
#line 195 "minor.y"
	{ yyval.n = uniNode('~', yystack.l_mark[0].n); yyval.n->info = isUniInt(yyval.n, "~"); }
break;
case 98:
#line 196 "minor.y"
	{ yyval.n = uniNode(uminus, yystack.l_mark[0].n); yyval.n->info = isUniInt(yyval.n, "-"); }
break;
case 99:
#line 197 "minor.y"
	{ yyval.n = binNode(EQ, yystack.l_mark[0].n, yystack.l_mark[-2].n); yyval.n->info = isAssign(yyval.n); }
break;
case 100:
#line 198 "minor.y"
	{ Node *n; int t = IDfind(yystack.l_mark[-3].s, (void**)&n); yyval.n = binNode('(', TID(yystack.l_mark[-3].s), yystack.l_mark[-1].n); yyval.n->user = n; yyval.n->info = yyval.n->SUB(0)->info = t; isCall(yystack.l_mark[-3].s, n, yystack.l_mark[-1].n); }
break;
case 101:
#line 201 "minor.y"
	{ yyval.n = binNode(',', yystack.l_mark[0].n, nilNode(NIL)); }
break;
case 102:
#line 202 "minor.y"
	{ yyval.n = binNode(',', yystack.l_mark[0].n, yystack.l_mark[-2].n); }
break;
#line 1558 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
