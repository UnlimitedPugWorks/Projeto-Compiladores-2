/*
generated at Fri May 22 15:34:07 2020
by $Id: pburg.c,v 2.5 2017/11/16 09:41:42 prs Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.5"
#define MAX_COST 0x7fff
#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#else
#define YYCONST
#endif

#line 1 "minor.brg"

/*
 * selecção de instruções com postfix
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "postfix.h"
#include "y.tab.h"
#include "minor.h"
#include "tabid.h"

#ifndef U_
#define U_ "_"
#endif

#define TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost);

#define PLUS 1
#define MINUS -1

extern FILE *yyout;
static char *mklbl(int n) {
	static char buf[20];
	sprintf(buf, "%cL%d", n < 0 ? '.' : '_', n);
	return strcpy(malloc(strlen(buf)+1),buf);
}
static char *mkfunc(char *s) {
	static char buf[80];
	strcpy(buf, "_");
	strcat(buf, s);
	return buf;
}
static void outstr(char *s) {
  while (*s)fprintf(yyout, pfCHAR, (unsigned char)*s++);
  fprintf(yyout, pfCHAR, 0);
}

static void outstrnoend(char *s){
	  while (*s)fprintf(yyout, pfCHAR, (unsigned char)*s++);
}

static int isInt(Node *n)  {int i = (tTYPE(n->info) == tINT)?1:10000; /*printf("Como int deu %d\n", i);*/ return i;}
static int isSTR(Node *n)  {int i = (tTYPE(n->info) == tSTR)?1:10000; /*printf("Como Str deu %d\n", i);*/ return i;}
static int isArray(Node *n){int i = (tTYPE(n->info) == tVEC)?1:10000; /*printf("Como Array deu %d\n", i);*/ return i;}
static int sameVar(Node* p) {return strcmp(RIGHT_CHILD(p)->value.s, LEFT_CHILD(LEFT_CHILD(p))->value.s) ? 0x7fff : 2;}
static int sameVar2(Node* p) {return strcmp(RIGHT_CHILD(p)->value.s, RIGHT_CHILD(LEFT_CHILD(p))->value.s) ? 0x7fff : 2;}


void putIntIDinStack(char*);
void saveIDfromStack(char*);
void putVecIDinStack(char*);
void putSTRIDinStack(char*);
void publicInitialization(char*, int);
void vectorSaveElement(char*);
void vectorLoadElement(char*);
void constInitialization(int);
void createVecWithLength(char*, int, int);
void manageExterns(char*);
void externs();
void printNode2(Node*);
void allocVECSTR(char*);
void incrementOptimization(char*, int, int);
void showAddress(char*);
void VectorInit(int, int);

int lbl = 0;
int depth = -1;
int elifdepth = -1;
int localpos = 0;
int argspos = 8;
static long eliflbl[20];
static long brklbl[20];
static long steplbl[20];
static char *extrns[100]; /* emit externs at the end only */
static int extcnt;

#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
#define yyfile_NT 1
#define yyenddecls_NT 2
#define yymain_NT 3
#define yymoduledecls_NT 4
#define yystart_NT 5
#define yymainfuncdecls_NT 6
#define yyinsts_NT 7
#define yymainfuncvars_NT 8
#define yymainfuncvar_NT 9
#define yyinst_NT 10
#define yyexpr_NT 11
#define yysexpr_NT 12
#define yyloop_NT 13
#define yyret_NT 14
#define yyblock_NT 15
#define yyifinst_NT 16
#define yycond_NT 17
#define yyif_NT 18
#define yyelseinst_NT 19
#define yyelifif_NT 20
#define yyelifinst_NT 21
#define yyelifelse_NT 22
#define yyelif_NT 23
#define yyuntil_NT 24
#define yystep_NT 25
#define yyforinit_NT 26
#define yyuntilinit_NT 27
#define yydoinit_NT 28
#define yystepinit_NT 29
#define yygdecls_NT 30
#define yydecls_NT 31
#define yydecl_NT 32
#define yycharsdecl_NT 33
#define yyarraydecl_NT 34
#define yyintlist_NT 35
#define yyfuncend_NT 36
#define yyfuncfargs_NT 37
#define yyfvardecl_NT 38
#define yyfuncbody_NT 39
#define yyfvars_NT 40
#define yyfvar_NT 41
#define yyfuncdecls_NT 42
#define yyfuncinsts_NT 43
#define yyfuncvars_NT 44
#define yyfuncvar_NT 45
#define yychars_NT 46
#define yychar_NT 47
#define yyexprs_NT 48
#define yyvexpr_NT 49
#define yyand_NT 50
#define yyor_NT 51

static YYCONST char *yyntname[] = {
	0,
	"file",
	"enddecls",
	"main",
	"moduledecls",
	"start",
	"mainfuncdecls",
	"insts",
	"mainfuncvars",
	"mainfuncvar",
	"inst",
	"expr",
	"sexpr",
	"loop",
	"ret",
	"block",
	"ifinst",
	"cond",
	"if",
	"elseinst",
	"elifif",
	"elifinst",
	"elifelse",
	"elif",
	"until",
	"step",
	"forinit",
	"untilinit",
	"doinit",
	"stepinit",
	"gdecls",
	"decls",
	"decl",
	"charsdecl",
	"arraydecl",
	"intlist",
	"funcend",
	"funcfargs",
	"fvardecl",
	"funcbody",
	"fvars",
	"fvar",
	"funcdecls",
	"funcinsts",
	"funcvars",
	"funcvar",
	"chars",
	"char",
	"exprs",
	"vexpr",
	"and",
	"or",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "",
	/* 34 */ "PRINT",
 "",
	/* 36 */ "ALLOC",
 "",
	/* 38 */ "MOD",
	/* 39 */ "AND",
 "",
	/* 41 */ "FUNCALL",
 "",
	/* 43 */ "MUL",
	/* 44 */ "ADD",
	/* 45 */ "ARGSLIST",
	/* 46 */ "SUB",
 "",
	/* 48 */ "DIV",
 "", "", "", "", "", "", "", "", "", "", "",
	/* 60 */ "STMT",
	/* 61 */ "LESS",
	/* 62 */ "EQUALS",
	/* 63 */ "GREATER",
	/* 64 */ "READ",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "",
	/* 92 */ "VECTOR",
 "", "",
	/* 95 */ "POW",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "",
	/* 125 */ "OR",
 "",
	/* 127 */ "NOT",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "",
	/* 258 */ "INT",
	/* 259 */ "CHAR",
	/* 260 */ "ID",
	/* 261 */ "STR",
	/* 262 */ "PROGRAM",
	/* 263 */ "MODULE",
	/* 264 */ "END",
	/* 265 */ "PUBLIC",
	/* 266 */ "FORWARD",
	/* 267 */ "STRING",
	/* 268 */ "NUMBER",
	/* 269 */ "ARRAY",
	/* 270 */ "FUNCTION",
	/* 271 */ "VOID",
	/* 272 */ "CONST",
	/* 273 */ "IF",
	/* 274 */ "THEN",
	/* 275 */ "FI",
	/* 276 */ "ELIF",
	/* 277 */ "ELSE",
	/* 278 */ "RETURN",
	/* 279 */ "START",
	/* 280 */ "FOR",
	/* 281 */ "UNTIL",
	/* 282 */ "STEP",
	/* 283 */ "DO",
	/* 284 */ "DONE",
	/* 285 */ "REPEAT",
	/* 286 */ "STOP",
	/* 287 */ "FARGS",
	/* 288 */ "CHARS",
	/* 289 */ "INTS",
	/* 290 */ "ADDR",
	/* 291 */ "VAR",
	/* 292 */ "ARGS",
	/* 293 */ "DECL",
	/* 294 */ "NIL",
	/* 295 */ "EQ",
	/* 296 */ "NE",
	/* 297 */ "GE",
	/* 298 */ "LE",
	/* 299 */ "uminus",
	""
};

struct yystate {
	short cost[52];
	struct {
		unsigned int yyfile:2;
		unsigned int yyenddecls:1;
		unsigned int yymain:1;
		unsigned int yymoduledecls:1;
		unsigned int yystart:1;
		unsigned int yymainfuncdecls:2;
		unsigned int yyinsts:2;
		unsigned int yymainfuncvars:2;
		unsigned int yymainfuncvar:2;
		unsigned int yyinst:4;
		unsigned int yyexpr:6;
		unsigned int yysexpr:2;
		unsigned int yyloop:2;
		unsigned int yyret:2;
		unsigned int yyblock:1;
		unsigned int yyifinst:1;
		unsigned int yycond:1;
		unsigned int yyif:1;
		unsigned int yyelseinst:1;
		unsigned int yyelifif:1;
		unsigned int yyelifinst:2;
		unsigned int yyelifelse:2;
		unsigned int yyelif:1;
		unsigned int yyuntil:1;
		unsigned int yystep:1;
		unsigned int yyforinit:1;
		unsigned int yyuntilinit:1;
		unsigned int yydoinit:1;
		unsigned int yystepinit:1;
		unsigned int yygdecls:2;
		unsigned int yydecls:2;
		unsigned int yydecl:3;
		unsigned int yycharsdecl:2;
		unsigned int yyarraydecl:1;
		unsigned int yyintlist:2;
		unsigned int yyfuncend:1;
		unsigned int yyfuncfargs:2;
		unsigned int yyfvardecl:1;
		unsigned int yyfuncbody:2;
		unsigned int yyfvars:2;
		unsigned int yyfvar:2;
		unsigned int yyfuncdecls:2;
		unsigned int yyfuncinsts:2;
		unsigned int yyfuncvars:2;
		unsigned int yyfuncvar:2;
		unsigned int yychars:2;
		unsigned int yychar:2;
		unsigned int yyexprs:2;
		unsigned int yyvexpr:3;
		unsigned int yyand:1;
		unsigned int yyor:1;
	} rule;
};

static short yynts_0[] = { yyenddecls_NT, yymain_NT, 0 };
static short yynts_1[] = { yymoduledecls_NT, 0 };
static short yynts_2[] = { yystart_NT, 0 };
static short yynts_3[] = { yymainfuncdecls_NT, yyinsts_NT, 0 };
static short yynts_4[] = { 0 };
static short yynts_5[] = { yymainfuncvars_NT, 0 };
static short yynts_6[] = { yymainfuncvar_NT, 0 };
static short yynts_7[] = { yymainfuncvars_NT, yymainfuncvar_NT, 0 };
static short yynts_8[] = { yyinsts_NT, yyinst_NT, 0 };
static short yynts_9[] = { yyexpr_NT, 0 };
static short yynts_10[] = { yysexpr_NT, 0 };
static short yynts_11[] = { yyret_NT, 0 };
static short yynts_12[] = { yyinsts_NT, yyloop_NT, 0 };
static short yynts_13[] = { yyifinst_NT, 0 };
static short yynts_14[] = { yycond_NT, yyblock_NT, 0 };
static short yynts_15[] = { yyif_NT, yyelseinst_NT, 0 };
static short yynts_16[] = { yyblock_NT, 0 };
static short yynts_17[] = { yyelifif_NT, yyelifinst_NT, yyelifelse_NT, 0 };
static short yynts_18[] = { yyelifinst_NT, yyelif_NT, 0 };
static short yynts_19[] = { yyuntil_NT, yystep_NT, 0 };
static short yynts_20[] = { yyforinit_NT, yyuntilinit_NT, 0 };
static short yynts_21[] = { yydoinit_NT, yystepinit_NT, 0 };
static short yynts_22[] = { yygdecls_NT, 0 };
static short yynts_23[] = { yydecls_NT, 0 };
static short yynts_24[] = { yydecl_NT, 0 };
static short yynts_25[] = { yydecls_NT, yydecl_NT, 0 };
static short yynts_26[] = { yycharsdecl_NT, 0 };
static short yynts_27[] = { yyarraydecl_NT, 0 };
static short yynts_28[] = { yyintlist_NT, 0 };
static short yynts_29[] = { yyfuncend_NT, yyfuncfargs_NT, 0 };
static short yynts_30[] = { yyfvardecl_NT, yyfuncbody_NT, 0 };
static short yynts_31[] = { yyfuncbody_NT, 0 };
static short yynts_32[] = { yyfvars_NT, 0 };
static short yynts_33[] = { yyfvar_NT, 0 };
static short yynts_34[] = { yyfvars_NT, yyfvar_NT, 0 };
static short yynts_35[] = { yyfuncdecls_NT, yyfuncinsts_NT, 0 };
static short yynts_36[] = { yyfuncvars_NT, 0 };
static short yynts_37[] = { yyfuncvar_NT, 0 };
static short yynts_38[] = { yyfuncvars_NT, yyfuncvar_NT, 0 };
static short yynts_39[] = { yyinsts_NT, yyret_NT, 0 };
static short yynts_40[] = { yychars_NT, yychar_NT, 0 };
static short yynts_41[] = { yycharsdecl_NT, yychar_NT, 0 };
static short yynts_42[] = { yyexpr_NT, yyexprs_NT, 0 };
static short yynts_43[] = { yyexprs_NT, 0 };
static short yynts_44[] = { yyvexpr_NT, 0 };
static short yynts_45[] = { yyexpr_NT, yyexpr_NT, 0 };
static short yynts_46[] = { yyexpr_NT, yyvexpr_NT, 0 };
static short yynts_47[] = { yyvexpr_NT, yyexpr_NT, 0 };
static short yynts_48[] = { yyand_NT, yyexpr_NT, 0 };
static short yynts_49[] = { yyor_NT, yyexpr_NT, 0 };
static short yynts_50[] = { yysexpr_NT, yysexpr_NT, 0 };
static short yynts_51[] = { yyexpr_NT, yyexpr_NT, yysexpr_NT, 0 };
static short yynts_52[] = { yyexpr_NT, yysexpr_NT, 0 };
static short yynts_53[] = { yyexpr_NT, yyexpr_NT, yyvexpr_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_3,	/* 4 */
	yynts_4,	/* 5 */
	yynts_5,	/* 6 */
	yynts_6,	/* 7 */
	yynts_7,	/* 8 */
	yynts_4,	/* 9 */
	yynts_4,	/* 10 */
	yynts_4,	/* 11 */
	yynts_4,	/* 12 */
	yynts_8,	/* 13 */
	yynts_9,	/* 14 */
	yynts_10,	/* 15 */
	yynts_9,	/* 16 */
	yynts_9,	/* 17 */
	yynts_4,	/* 18 */
	yynts_4,	/* 19 */
	yynts_11,	/* 20 */
	yynts_4,	/* 21 */
	yynts_9,	/* 22 */
	yynts_4,	/* 23 */
	yynts_12,	/* 24 */
	yynts_13,	/* 25 */
	yynts_14,	/* 26 */
	yynts_9,	/* 27 */
	yynts_15,	/* 28 */
	yynts_14,	/* 29 */
	yynts_16,	/* 30 */
	yynts_17,	/* 31 */
	yynts_14,	/* 32 */
	yynts_18,	/* 33 */
	yynts_14,	/* 34 */
	yynts_4,	/* 35 */
	yynts_16,	/* 36 */
	yynts_4,	/* 37 */
	yynts_19,	/* 38 */
	yynts_20,	/* 39 */
	yynts_9,	/* 40 */
	yynts_9,	/* 41 */
	yynts_21,	/* 42 */
	yynts_9,	/* 43 */
	yynts_16,	/* 44 */
	yynts_22,	/* 45 */
	yynts_22,	/* 46 */
	yynts_4,	/* 47 */
	yynts_23,	/* 48 */
	yynts_24,	/* 49 */
	yynts_25,	/* 50 */
	yynts_4,	/* 51 */
	yynts_4,	/* 52 */
	yynts_26,	/* 53 */
	yynts_4,	/* 54 */
	yynts_27,	/* 55 */
	yynts_4,	/* 56 */
	yynts_28,	/* 57 */
	yynts_4,	/* 58 */
	yynts_28,	/* 59 */
	yynts_29,	/* 60 */
	yynts_4,	/* 61 */
	yynts_30,	/* 62 */
	yynts_31,	/* 63 */
	yynts_32,	/* 64 */
	yynts_33,	/* 65 */
	yynts_34,	/* 66 */
	yynts_4,	/* 67 */
	yynts_4,	/* 68 */
	yynts_4,	/* 69 */
	yynts_4,	/* 70 */
	yynts_35,	/* 71 */
	yynts_4,	/* 72 */
	yynts_36,	/* 73 */
	yynts_37,	/* 74 */
	yynts_38,	/* 75 */
	yynts_4,	/* 76 */
	yynts_4,	/* 77 */
	yynts_4,	/* 78 */
	yynts_4,	/* 79 */
	yynts_39,	/* 80 */
	yynts_40,	/* 81 */
	yynts_4,	/* 82 */
	yynts_4,	/* 83 */
	yynts_4,	/* 84 */
	yynts_4,	/* 85 */
	yynts_41,	/* 86 */
	yynts_4,	/* 87 */
	yynts_9,	/* 88 */
	yynts_42,	/* 89 */
	yynts_43,	/* 90 */
	yynts_10,	/* 91 */
	yynts_44,	/* 92 */
	yynts_9,	/* 93 */
	yynts_4,	/* 94 */
	yynts_4,	/* 95 */
	yynts_4,	/* 96 */
	yynts_4,	/* 97 */
	yynts_4,	/* 98 */
	yynts_4,	/* 99 */
	yynts_45,	/* 100 */
	yynts_45,	/* 101 */
	yynts_46,	/* 102 */
	yynts_47,	/* 103 */
	yynts_46,	/* 104 */
	yynts_47,	/* 105 */
	yynts_4,	/* 106 */
	yynts_4,	/* 107 */
	yynts_4,	/* 108 */
	yynts_4,	/* 109 */
	yynts_45,	/* 110 */
	yynts_45,	/* 111 */
	yynts_48,	/* 112 */
	yynts_9,	/* 113 */
	yynts_49,	/* 114 */
	yynts_9,	/* 115 */
	yynts_9,	/* 116 */
	yynts_45,	/* 117 */
	yynts_45,	/* 118 */
	yynts_50,	/* 119 */
	yynts_45,	/* 120 */
	yynts_50,	/* 121 */
	yynts_45,	/* 122 */
	yynts_50,	/* 123 */
	yynts_45,	/* 124 */
	yynts_50,	/* 125 */
	yynts_45,	/* 126 */
	yynts_50,	/* 127 */
	yynts_45,	/* 128 */
	yynts_50,	/* 129 */
	yynts_9,	/* 130 */
	yynts_45,	/* 131 */
	yynts_4,	/* 132 */
	yynts_4,	/* 133 */
	yynts_40,	/* 134 */
	yynts_4,	/* 135 */
	yynts_51,	/* 136 */
	yynts_52,	/* 137 */
	yynts_46,	/* 138 */
	yynts_53,	/* 139 */
	yynts_4,	/* 140 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"file: PROGRAM(enddecls,main)",
/* 2 */	"file: MODULE(moduledecls)",
/* 3 */	"main: FUNCTION(END(ID,INT),FARGS(NIL,start))",
/* 4 */	"start: START(mainfuncdecls,insts)",
/* 5 */	"mainfuncdecls: NIL",
/* 6 */	"mainfuncdecls: mainfuncvars",
/* 7 */	"mainfuncvars: ARGS(NIL,mainfuncvar)",
/* 8 */	"mainfuncvars: ARGS(mainfuncvars,mainfuncvar)",
/* 9 */	"mainfuncvar: NUMBER(ID,NIL)",
/* 10 */	"mainfuncvar: STRING(ID,NIL)",
/* 11 */	"mainfuncvar: ARRAY(ID,INTS(INT,NIL))",
/* 12 */	"insts: NIL",
/* 13 */	"insts: STMT(insts,inst)",
/* 14 */	"inst: PRINT(expr)",
/* 15 */	"inst: PRINT(sexpr)",
/* 16 */	"inst: expr",
/* 17 */	"inst: ALLOC(expr,ID)",
/* 18 */	"loop: REPEAT",
/* 19 */	"loop: STOP",
/* 20 */	"loop: ret",
/* 21 */	"ret: RETURN(NIL)",
/* 22 */	"ret: RETURN(expr)",
/* 23 */	"ret: NIL",
/* 24 */	"block: STMT(insts,loop)",
/* 25 */	"inst: FI(THEN(ifinst,NIL),NIL)",
/* 26 */	"ifinst: IF(cond,block)",
/* 27 */	"cond: expr",
/* 28 */	"inst: FI(THEN(if,NIL),elseinst)",
/* 29 */	"if: IF(cond,block)",
/* 30 */	"elseinst: block",
/* 31 */	"inst: FI(THEN(elifif,elifinst),elifelse)",
/* 32 */	"elifif: IF(cond,block)",
/* 33 */	"elifinst: ELIF(elifinst,elif)",
/* 34 */	"elif: IF(cond,block)",
/* 35 */	"elifinst: NIL",
/* 36 */	"elifelse: block",
/* 37 */	"elifelse: NIL",
/* 38 */	"inst: FOR(until,step)",
/* 39 */	"until: UNTIL(forinit,untilinit)",
/* 40 */	"forinit: expr",
/* 41 */	"untilinit: expr",
/* 42 */	"step: STEP(doinit,stepinit)",
/* 43 */	"stepinit: expr",
/* 44 */	"doinit: block",
/* 45 */	"enddecls: gdecls",
/* 46 */	"moduledecls: gdecls",
/* 47 */	"gdecls: NIL",
/* 48 */	"gdecls: decls",
/* 49 */	"decls: DECL(NIL,decl)",
/* 50 */	"decls: DECL(decls,decl)",
/* 51 */	"decl: VAR(NUMBER(ID,INT))",
/* 52 */	"decl: VAR(NUMBER(ID,NIL))",
/* 53 */	"decl: VAR(STRING(ID,charsdecl))",
/* 54 */	"decl: VAR(STRING(ID,NIL))",
/* 55 */	"decl: VAR(ARRAY(ID,INTS(INT,arraydecl)))",
/* 56 */	"decl: VAR(ARRAY(ID,INTS(INT,NIL)))",
/* 57 */	"arraydecl: intlist",
/* 58 */	"intlist: INT",
/* 59 */	"intlist: INTS(intlist,INT)",
/* 60 */	"decl: FUNCTION(funcend,funcfargs)",
/* 61 */	"funcend: END(ID,INT)",
/* 62 */	"funcfargs: FARGS(fvardecl,funcbody)",
/* 63 */	"funcfargs: FARGS(NIL,funcbody)",
/* 64 */	"fvardecl: fvars",
/* 65 */	"fvars: ARGS(NIL,fvar)",
/* 66 */	"fvars: ARGS(fvars,fvar)",
/* 67 */	"fvar: NUMBER(ID,NIL)",
/* 68 */	"fvar: STRING(ID,NIL)",
/* 69 */	"fvar: ARRAY(ID,INTS(INT,NIL))",
/* 70 */	"funcbody: NIL",
/* 71 */	"funcbody: START(funcdecls,funcinsts)",
/* 72 */	"funcdecls: NIL",
/* 73 */	"funcdecls: funcvars",
/* 74 */	"funcvars: ARGS(NIL,funcvar)",
/* 75 */	"funcvars: ARGS(funcvars,funcvar)",
/* 76 */	"funcvar: NUMBER(ID,NIL)",
/* 77 */	"funcvar: STRING(ID,NIL)",
/* 78 */	"funcvar: ARRAY(ID,INTS(INT,NIL))",
/* 79 */	"funcinsts: NIL",
/* 80 */	"funcinsts: STMT(insts,ret)",
/* 81 */	"chars: CHARS(chars,char)",
/* 82 */	"chars: NIL",
/* 83 */	"char: INT",
/* 84 */	"char: STR",
/* 85 */	"char: CHAR",
/* 86 */	"charsdecl: CHARS(charsdecl,char)",
/* 87 */	"charsdecl: NIL",
/* 88 */	"exprs: ARGSLIST(expr,NIL)",
/* 89 */	"exprs: ARGSLIST(expr,exprs)",
/* 90 */	"expr: FUNCALL(ID,exprs)",
/* 91 */	"expr: sexpr",
/* 92 */	"expr: vexpr",
/* 93 */	"expr: EQ(expr,ID)",
/* 94 */	"expr: EQ(ADD(ID,CHARS(NIL,INT)),ID)",
/* 95 */	"expr: EQ(ADD(CHARS(NIL,INT),ID),ID)",
/* 96 */	"expr: EQ(SUB(ID,CHARS(NIL,INT)),ID)",
/* 97 */	"expr: READ",
/* 98 */	"expr: ID",
/* 99 */	"expr: ADDR(ID)",
/* 100 */	"expr: SUB(expr,expr)",
/* 101 */	"expr: ADD(expr,expr)",
/* 102 */	"vexpr: ADD(expr,vexpr)",
/* 103 */	"vexpr: ADD(vexpr,expr)",
/* 104 */	"vexpr: SUB(expr,vexpr)",
/* 105 */	"vexpr: SUB(vexpr,expr)",
/* 106 */	"expr: ADD(CHARS(NIL,INT),CHARS(NIL,INT))",
/* 107 */	"expr: SUB(CHARS(NIL,INT),CHARS(NIL,INT))",
/* 108 */	"expr: MUL(CHARS(NIL,INT),CHARS(NIL,INT))",
/* 109 */	"expr: DIV(CHARS(NIL,INT),CHARS(NIL,INT))",
/* 110 */	"expr: MUL(expr,expr)",
/* 111 */	"expr: DIV(expr,expr)",
/* 112 */	"expr: AND(and,expr)",
/* 113 */	"and: expr",
/* 114 */	"expr: OR(or,expr)",
/* 115 */	"or: expr",
/* 116 */	"expr: NOT(expr)",
/* 117 */	"expr: MOD(expr,expr)",
/* 118 */	"expr: GREATER(expr,expr)",
/* 119 */	"expr: GREATER(sexpr,sexpr)",
/* 120 */	"expr: LESS(expr,expr)",
/* 121 */	"expr: LESS(sexpr,sexpr)",
/* 122 */	"expr: EQUALS(expr,expr)",
/* 123 */	"expr: EQUALS(sexpr,sexpr)",
/* 124 */	"expr: GE(expr,expr)",
/* 125 */	"expr: GE(sexpr,sexpr)",
/* 126 */	"expr: LE(expr,expr)",
/* 127 */	"expr: LE(sexpr,sexpr)",
/* 128 */	"expr: NE(expr,expr)",
/* 129 */	"expr: NE(sexpr,sexpr)",
/* 130 */	"expr: uminus(expr)",
/* 131 */	"expr: POW(expr,expr)",
/* 132 */	"expr: CHARS(NIL,INT)",
/* 133 */	"expr: CHARS(NIL,CHAR)",
/* 134 */	"sexpr: CHARS(chars,char)",
/* 135 */	"sexpr: ID",
/* 136 */	"expr: EQ(expr,VECTOR(expr,sexpr))",
/* 137 */	"expr: VECTOR(expr,sexpr)",
/* 138 */	"expr: VECTOR(expr,vexpr)",
/* 139 */	"expr: EQ(expr,VECTOR(expr,vexpr))",
/* 140 */	"vexpr: ID",
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static short yydecode_file[] = {
	0,
	1,
	2,
};

static short yydecode_enddecls[] = {
	0,
	45,
};

static short yydecode_main[] = {
	0,
	3,
};

static short yydecode_moduledecls[] = {
	0,
	46,
};

static short yydecode_start[] = {
	0,
	4,
};

static short yydecode_mainfuncdecls[] = {
	0,
	5,
	6,
};

static short yydecode_insts[] = {
	0,
	12,
	13,
};

static short yydecode_mainfuncvars[] = {
	0,
	7,
	8,
};

static short yydecode_mainfuncvar[] = {
	0,
	9,
	10,
	11,
};

static short yydecode_inst[] = {
	0,
	14,
	15,
	16,
	17,
	25,
	28,
	31,
	38,
};

static short yydecode_expr[] = {
	0,
	90,
	91,
	92,
	93,
	94,
	95,
	96,
	97,
	98,
	99,
	100,
	101,
	106,
	107,
	108,
	109,
	110,
	111,
	112,
	114,
	116,
	117,
	118,
	119,
	120,
	121,
	122,
	123,
	124,
	125,
	126,
	127,
	128,
	129,
	130,
	131,
	132,
	133,
	136,
	137,
	138,
	139,
};

static short yydecode_sexpr[] = {
	0,
	134,
	135,
};

static short yydecode_loop[] = {
	0,
	18,
	19,
	20,
};

static short yydecode_ret[] = {
	0,
	21,
	22,
	23,
};

static short yydecode_block[] = {
	0,
	24,
};

static short yydecode_ifinst[] = {
	0,
	26,
};

static short yydecode_cond[] = {
	0,
	27,
};

static short yydecode_if[] = {
	0,
	29,
};

static short yydecode_elseinst[] = {
	0,
	30,
};

static short yydecode_elifif[] = {
	0,
	32,
};

static short yydecode_elifinst[] = {
	0,
	33,
	35,
};

static short yydecode_elifelse[] = {
	0,
	36,
	37,
};

static short yydecode_elif[] = {
	0,
	34,
};

static short yydecode_until[] = {
	0,
	39,
};

static short yydecode_step[] = {
	0,
	42,
};

static short yydecode_forinit[] = {
	0,
	40,
};

static short yydecode_untilinit[] = {
	0,
	41,
};

static short yydecode_doinit[] = {
	0,
	44,
};

static short yydecode_stepinit[] = {
	0,
	43,
};

static short yydecode_gdecls[] = {
	0,
	47,
	48,
};

static short yydecode_decls[] = {
	0,
	49,
	50,
};

static short yydecode_decl[] = {
	0,
	51,
	52,
	53,
	54,
	55,
	56,
	60,
};

static short yydecode_charsdecl[] = {
	0,
	86,
	87,
};

static short yydecode_arraydecl[] = {
	0,
	57,
};

static short yydecode_intlist[] = {
	0,
	58,
	59,
};

static short yydecode_funcend[] = {
	0,
	61,
};

static short yydecode_funcfargs[] = {
	0,
	62,
	63,
};

static short yydecode_fvardecl[] = {
	0,
	64,
};

static short yydecode_funcbody[] = {
	0,
	70,
	71,
};

static short yydecode_fvars[] = {
	0,
	65,
	66,
};

static short yydecode_fvar[] = {
	0,
	67,
	68,
	69,
};

static short yydecode_funcdecls[] = {
	0,
	72,
	73,
};

static short yydecode_funcinsts[] = {
	0,
	79,
	80,
};

static short yydecode_funcvars[] = {
	0,
	74,
	75,
};

static short yydecode_funcvar[] = {
	0,
	76,
	77,
	78,
};

static short yydecode_chars[] = {
	0,
	81,
	82,
};

static short yydecode_char[] = {
	0,
	83,
	84,
	85,
};

static short yydecode_exprs[] = {
	0,
	88,
	89,
};

static short yydecode_vexpr[] = {
	0,
	102,
	103,
	104,
	105,
	140,
};

static short yydecode_and[] = {
	0,
	113,
};

static short yydecode_or[] = {
	0,
	115,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 51)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yyfile_NT:	return yydecode_file[((struct yystate *)state)->rule.yyfile];
	case yyenddecls_NT:	return yydecode_enddecls[((struct yystate *)state)->rule.yyenddecls];
	case yymain_NT:	return yydecode_main[((struct yystate *)state)->rule.yymain];
	case yymoduledecls_NT:	return yydecode_moduledecls[((struct yystate *)state)->rule.yymoduledecls];
	case yystart_NT:	return yydecode_start[((struct yystate *)state)->rule.yystart];
	case yymainfuncdecls_NT:	return yydecode_mainfuncdecls[((struct yystate *)state)->rule.yymainfuncdecls];
	case yyinsts_NT:	return yydecode_insts[((struct yystate *)state)->rule.yyinsts];
	case yymainfuncvars_NT:	return yydecode_mainfuncvars[((struct yystate *)state)->rule.yymainfuncvars];
	case yymainfuncvar_NT:	return yydecode_mainfuncvar[((struct yystate *)state)->rule.yymainfuncvar];
	case yyinst_NT:	return yydecode_inst[((struct yystate *)state)->rule.yyinst];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	case yysexpr_NT:	return yydecode_sexpr[((struct yystate *)state)->rule.yysexpr];
	case yyloop_NT:	return yydecode_loop[((struct yystate *)state)->rule.yyloop];
	case yyret_NT:	return yydecode_ret[((struct yystate *)state)->rule.yyret];
	case yyblock_NT:	return yydecode_block[((struct yystate *)state)->rule.yyblock];
	case yyifinst_NT:	return yydecode_ifinst[((struct yystate *)state)->rule.yyifinst];
	case yycond_NT:	return yydecode_cond[((struct yystate *)state)->rule.yycond];
	case yyif_NT:	return yydecode_if[((struct yystate *)state)->rule.yyif];
	case yyelseinst_NT:	return yydecode_elseinst[((struct yystate *)state)->rule.yyelseinst];
	case yyelifif_NT:	return yydecode_elifif[((struct yystate *)state)->rule.yyelifif];
	case yyelifinst_NT:	return yydecode_elifinst[((struct yystate *)state)->rule.yyelifinst];
	case yyelifelse_NT:	return yydecode_elifelse[((struct yystate *)state)->rule.yyelifelse];
	case yyelif_NT:	return yydecode_elif[((struct yystate *)state)->rule.yyelif];
	case yyuntil_NT:	return yydecode_until[((struct yystate *)state)->rule.yyuntil];
	case yystep_NT:	return yydecode_step[((struct yystate *)state)->rule.yystep];
	case yyforinit_NT:	return yydecode_forinit[((struct yystate *)state)->rule.yyforinit];
	case yyuntilinit_NT:	return yydecode_untilinit[((struct yystate *)state)->rule.yyuntilinit];
	case yydoinit_NT:	return yydecode_doinit[((struct yystate *)state)->rule.yydoinit];
	case yystepinit_NT:	return yydecode_stepinit[((struct yystate *)state)->rule.yystepinit];
	case yygdecls_NT:	return yydecode_gdecls[((struct yystate *)state)->rule.yygdecls];
	case yydecls_NT:	return yydecode_decls[((struct yystate *)state)->rule.yydecls];
	case yydecl_NT:	return yydecode_decl[((struct yystate *)state)->rule.yydecl];
	case yycharsdecl_NT:	return yydecode_charsdecl[((struct yystate *)state)->rule.yycharsdecl];
	case yyarraydecl_NT:	return yydecode_arraydecl[((struct yystate *)state)->rule.yyarraydecl];
	case yyintlist_NT:	return yydecode_intlist[((struct yystate *)state)->rule.yyintlist];
	case yyfuncend_NT:	return yydecode_funcend[((struct yystate *)state)->rule.yyfuncend];
	case yyfuncfargs_NT:	return yydecode_funcfargs[((struct yystate *)state)->rule.yyfuncfargs];
	case yyfvardecl_NT:	return yydecode_fvardecl[((struct yystate *)state)->rule.yyfvardecl];
	case yyfuncbody_NT:	return yydecode_funcbody[((struct yystate *)state)->rule.yyfuncbody];
	case yyfvars_NT:	return yydecode_fvars[((struct yystate *)state)->rule.yyfvars];
	case yyfvar_NT:	return yydecode_fvar[((struct yystate *)state)->rule.yyfvar];
	case yyfuncdecls_NT:	return yydecode_funcdecls[((struct yystate *)state)->rule.yyfuncdecls];
	case yyfuncinsts_NT:	return yydecode_funcinsts[((struct yystate *)state)->rule.yyfuncinsts];
	case yyfuncvars_NT:	return yydecode_funcvars[((struct yystate *)state)->rule.yyfuncvars];
	case yyfuncvar_NT:	return yydecode_funcvar[((struct yystate *)state)->rule.yyfuncvar];
	case yychars_NT:	return yydecode_chars[((struct yystate *)state)->rule.yychars];
	case yychar_NT:	return yydecode_char[((struct yystate *)state)->rule.yychar];
	case yyexprs_NT:	return yydecode_exprs[((struct yystate *)state)->rule.yyexprs];
	case yyvexpr_NT:	return yydecode_vexpr[((struct yystate *)state)->rule.yyvexpr];
	case yyand_NT:	return yydecode_and[((struct yystate *)state)->rule.yyand];
	case yyor_NT:	return yydecode_or[((struct yystate *)state)->rule.yyor];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_mainfuncvars(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);
static void yyclosure_sexpr(NODEPTR_TYPE, int);
static void yyclosure_ret(NODEPTR_TYPE, int);
static void yyclosure_block(NODEPTR_TYPE, int);
static void yyclosure_gdecls(NODEPTR_TYPE, int);
static void yyclosure_decls(NODEPTR_TYPE, int);
static void yyclosure_intlist(NODEPTR_TYPE, int);
static void yyclosure_fvars(NODEPTR_TYPE, int);
static void yyclosure_funcvars(NODEPTR_TYPE, int);
static void yyclosure_vexpr(NODEPTR_TYPE, int);

static void yyclosure_mainfuncvars(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 6, c + 1, p->cost[yymainfuncdecls_NT]);
	if (c + 1 < p->cost[yymainfuncdecls_NT]) {
		p->cost[yymainfuncdecls_NT] = c + 1;
		p->rule.yymainfuncdecls = 2;
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 115, c + 1, p->cost[yyor_NT]);
	if (c + 1 < p->cost[yyor_NT]) {
		p->cost[yyor_NT] = c + 1;
		p->rule.yyor = 1;
	}
	yytrace(a, 113, c + 1, p->cost[yyand_NT]);
	if (c + 1 < p->cost[yyand_NT]) {
		p->cost[yyand_NT] = c + 1;
		p->rule.yyand = 1;
	}
	yytrace(a, 43, c + 1, p->cost[yystepinit_NT]);
	if (c + 1 < p->cost[yystepinit_NT]) {
		p->cost[yystepinit_NT] = c + 1;
		p->rule.yystepinit = 1;
	}
	yytrace(a, 41, c + 1, p->cost[yyuntilinit_NT]);
	if (c + 1 < p->cost[yyuntilinit_NT]) {
		p->cost[yyuntilinit_NT] = c + 1;
		p->rule.yyuntilinit = 1;
	}
	yytrace(a, 40, c + 1, p->cost[yyforinit_NT]);
	if (c + 1 < p->cost[yyforinit_NT]) {
		p->cost[yyforinit_NT] = c + 1;
		p->rule.yyforinit = 1;
	}
	yytrace(a, 27, c + 1, p->cost[yycond_NT]);
	if (c + 1 < p->cost[yycond_NT]) {
		p->cost[yycond_NT] = c + 1;
		p->rule.yycond = 1;
	}
	yytrace(a, 16, c + 1, p->cost[yyinst_NT]);
	if (c + 1 < p->cost[yyinst_NT]) {
		p->cost[yyinst_NT] = c + 1;
		p->rule.yyinst = 3;
	}
}

static void yyclosure_sexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 91, c + 1, p->cost[yyexpr_NT]);
	if (c + 1 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 1;
		p->rule.yyexpr = 2;
		yyclosure_expr(a, c + 1);
	}
}

static void yyclosure_ret(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 20, c + 1, p->cost[yyloop_NT]);
	if (c + 1 < p->cost[yyloop_NT]) {
		p->cost[yyloop_NT] = c + 1;
		p->rule.yyloop = 3;
	}
}

static void yyclosure_block(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 44, c + 1, p->cost[yydoinit_NT]);
	if (c + 1 < p->cost[yydoinit_NT]) {
		p->cost[yydoinit_NT] = c + 1;
		p->rule.yydoinit = 1;
	}
	yytrace(a, 36, c + 1, p->cost[yyelifelse_NT]);
	if (c + 1 < p->cost[yyelifelse_NT]) {
		p->cost[yyelifelse_NT] = c + 1;
		p->rule.yyelifelse = 1;
	}
	yytrace(a, 30, c + 1, p->cost[yyelseinst_NT]);
	if (c + 1 < p->cost[yyelseinst_NT]) {
		p->cost[yyelseinst_NT] = c + 1;
		p->rule.yyelseinst = 1;
	}
}

static void yyclosure_gdecls(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 46, c + 1, p->cost[yymoduledecls_NT]);
	if (c + 1 < p->cost[yymoduledecls_NT]) {
		p->cost[yymoduledecls_NT] = c + 1;
		p->rule.yymoduledecls = 1;
	}
	yytrace(a, 45, c + 1, p->cost[yyenddecls_NT]);
	if (c + 1 < p->cost[yyenddecls_NT]) {
		p->cost[yyenddecls_NT] = c + 1;
		p->rule.yyenddecls = 1;
	}
}

static void yyclosure_decls(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 48, c + 1, p->cost[yygdecls_NT]);
	if (c + 1 < p->cost[yygdecls_NT]) {
		p->cost[yygdecls_NT] = c + 1;
		p->rule.yygdecls = 2;
		yyclosure_gdecls(a, c + 1);
	}
}

static void yyclosure_intlist(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 57, c + 1, p->cost[yyarraydecl_NT]);
	if (c + 1 < p->cost[yyarraydecl_NT]) {
		p->cost[yyarraydecl_NT] = c + 1;
		p->rule.yyarraydecl = 1;
	}
}

static void yyclosure_fvars(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 64, c + 1, p->cost[yyfvardecl_NT]);
	if (c + 1 < p->cost[yyfvardecl_NT]) {
		p->cost[yyfvardecl_NT] = c + 1;
		p->rule.yyfvardecl = 1;
	}
}

static void yyclosure_funcvars(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 73, c + 1, p->cost[yyfuncdecls_NT]);
	if (c + 1 < p->cost[yyfuncdecls_NT]) {
		p->cost[yyfuncdecls_NT] = c + 1;
		p->rule.yyfuncdecls = 2;
	}
}

static void yyclosure_vexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 92, c + 1, p->cost[yyexpr_NT]);
	if (c + 1 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 1;
		p->rule.yyexpr = 3;
		yyclosure_expr(a, c + 1);
	}
}

static void yylabel(NODEPTR_TYPE a, NODEPTR_TYPE u) {
	int c;
	struct yystate *p;

	if (!a)
		PANIC("yylabel", "Null tree in", OP_LABEL(u));
	STATE_LABEL(a) = p = (struct yystate *)malloc(sizeof *p);
	memset(p, 0, sizeof *p);
	p->cost[1] =
	p->cost[2] =
	p->cost[3] =
	p->cost[4] =
	p->cost[5] =
	p->cost[6] =
	p->cost[7] =
	p->cost[8] =
	p->cost[9] =
	p->cost[10] =
	p->cost[11] =
	p->cost[12] =
	p->cost[13] =
	p->cost[14] =
	p->cost[15] =
	p->cost[16] =
	p->cost[17] =
	p->cost[18] =
	p->cost[19] =
	p->cost[20] =
	p->cost[21] =
	p->cost[22] =
	p->cost[23] =
	p->cost[24] =
	p->cost[25] =
	p->cost[26] =
	p->cost[27] =
	p->cost[28] =
	p->cost[29] =
	p->cost[30] =
	p->cost[31] =
	p->cost[32] =
	p->cost[33] =
	p->cost[34] =
	p->cost[35] =
	p->cost[36] =
	p->cost[37] =
	p->cost[38] =
	p->cost[39] =
	p->cost[40] =
	p->cost[41] =
	p->cost[42] =
	p->cost[43] =
	p->cost[44] =
	p->cost[45] =
	p->cost[46] =
	p->cost[47] =
	p->cost[48] =
	p->cost[49] =
	p->cost[50] =
	p->cost[51] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* PRINT */
		yylabel(LEFT_CHILD(a),a);
		/* inst: PRINT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 14, c + 0, p->cost[yyinst_NT]);
		if (c + 0 < p->cost[yyinst_NT]) {
			p->cost[yyinst_NT] = c + 0;
			p->rule.yyinst = 1;
		}
		/* inst: PRINT(sexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysexpr_NT] + 1;
		yytrace(a, 15, c + 0, p->cost[yyinst_NT]);
		if (c + 0 < p->cost[yyinst_NT]) {
			p->cost[yyinst_NT] = c + 0;
			p->rule.yyinst = 2;
		}
		break;
	case 35: /* ALLOC */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* inst: ALLOC(expr,ID) */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
			yytrace(a, 17, c + 0, p->cost[yyinst_NT]);
			if (c + 0 < p->cost[yyinst_NT]) {
				p->cost[yyinst_NT] = c + 0;
				p->rule.yyinst = 4;
			}
		}
		break;
	case 37: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: MOD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 117, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 22;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 38: /* AND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: AND(and,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyand_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 112, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 19;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 40: /* FUNCALL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: FUNCALL(ID,exprs) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexprs_NT] + 1;
			yytrace(a, 90, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 1;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 42: /* MUL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: MUL(CHARS(NIL,INT),CHARS(NIL,INT)) */
			OP_LABEL(LEFT_CHILD(a)) == 287 && /* CHARS */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 287 && /* CHARS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 257 /* INT */
		) {
			c = 1;
			yytrace(a, 108, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 15;
				yyclosure_expr(a, c + 0);
			}
		}
		/* expr: MUL(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 110, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 17;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 43: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: ADD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isInt(a));
		yytrace(a, 101, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 12;
			yyclosure_expr(a, c + 0);
		}
		/* vexpr: ADD(expr,vexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyvexpr_NT] + (isArray(a));
		yytrace(a, 102, c + 0, p->cost[yyvexpr_NT]);
		if (c + 0 < p->cost[yyvexpr_NT]) {
			p->cost[yyvexpr_NT] = c + 0;
			p->rule.yyvexpr = 1;
			yyclosure_vexpr(a, c + 0);
		}
		/* vexpr: ADD(vexpr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyvexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isArray(a));
		yytrace(a, 103, c + 0, p->cost[yyvexpr_NT]);
		if (c + 0 < p->cost[yyvexpr_NT]) {
			p->cost[yyvexpr_NT] = c + 0;
			p->rule.yyvexpr = 2;
			yyclosure_vexpr(a, c + 0);
		}
		if (	/* expr: ADD(CHARS(NIL,INT),CHARS(NIL,INT)) */
			OP_LABEL(LEFT_CHILD(a)) == 287 && /* CHARS */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 287 && /* CHARS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 257 /* INT */
		) {
			c = 1;
			yytrace(a, 106, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 13;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 44: /* ARGSLIST */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* exprs: ARGSLIST(expr,NIL) */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
			yytrace(a, 88, c + 0, p->cost[yyexprs_NT]);
			if (c + 0 < p->cost[yyexprs_NT]) {
				p->cost[yyexprs_NT] = c + 0;
				p->rule.yyexprs = 1;
			}
		}
		/* exprs: ARGSLIST(expr,exprs) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexprs_NT] + 1;
		yytrace(a, 89, c + 0, p->cost[yyexprs_NT]);
		if (c + 0 < p->cost[yyexprs_NT]) {
			p->cost[yyexprs_NT] = c + 0;
			p->rule.yyexprs = 2;
		}
		break;
	case 45: /* SUB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: SUB(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isInt(a));
		yytrace(a, 100, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 11;
			yyclosure_expr(a, c + 0);
		}
		/* vexpr: SUB(expr,vexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyvexpr_NT] + (isArray(a));
		yytrace(a, 104, c + 0, p->cost[yyvexpr_NT]);
		if (c + 0 < p->cost[yyvexpr_NT]) {
			p->cost[yyvexpr_NT] = c + 0;
			p->rule.yyvexpr = 3;
			yyclosure_vexpr(a, c + 0);
		}
		/* vexpr: SUB(vexpr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyvexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + (isArray(a));
		yytrace(a, 105, c + 0, p->cost[yyvexpr_NT]);
		if (c + 0 < p->cost[yyvexpr_NT]) {
			p->cost[yyvexpr_NT] = c + 0;
			p->rule.yyvexpr = 4;
			yyclosure_vexpr(a, c + 0);
		}
		if (	/* expr: SUB(CHARS(NIL,INT),CHARS(NIL,INT)) */
			OP_LABEL(LEFT_CHILD(a)) == 287 && /* CHARS */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 287 && /* CHARS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 257 /* INT */
		) {
			c = 1;
			yytrace(a, 107, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 14;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 47: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: DIV(CHARS(NIL,INT),CHARS(NIL,INT)) */
			OP_LABEL(LEFT_CHILD(a)) == 287 && /* CHARS */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 287 && /* CHARS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 257 /* INT */
		) {
			c = 1;
			yytrace(a, 109, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 16;
				yyclosure_expr(a, c + 0);
			}
		}
		/* expr: DIV(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 111, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 18;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 59: /* STMT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* insts: STMT(insts,inst) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinsts_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinst_NT] + 1;
		yytrace(a, 13, c + 0, p->cost[yyinsts_NT]);
		if (c + 0 < p->cost[yyinsts_NT]) {
			p->cost[yyinsts_NT] = c + 0;
			p->rule.yyinsts = 2;
		}
		/* block: STMT(insts,loop) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinsts_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyloop_NT] + 1;
		yytrace(a, 24, c + 0, p->cost[yyblock_NT]);
		if (c + 0 < p->cost[yyblock_NT]) {
			p->cost[yyblock_NT] = c + 0;
			p->rule.yyblock = 1;
			yyclosure_block(a, c + 0);
		}
		/* funcinsts: STMT(insts,ret) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinsts_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyret_NT] + 1;
		yytrace(a, 80, c + 0, p->cost[yyfuncinsts_NT]);
		if (c + 0 < p->cost[yyfuncinsts_NT]) {
			p->cost[yyfuncinsts_NT] = c + 0;
			p->rule.yyfuncinsts = 2;
		}
		break;
	case 60: /* LESS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LESS(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 120, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 25;
			yyclosure_expr(a, c + 0);
		}
		/* expr: LESS(sexpr,sexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yysexpr_NT] + 1;
		yytrace(a, 121, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 26;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 61: /* EQUALS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: EQUALS(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 122, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 27;
			yyclosure_expr(a, c + 0);
		}
		/* expr: EQUALS(sexpr,sexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yysexpr_NT] + 1;
		yytrace(a, 123, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 28;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 62: /* GREATER */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GREATER(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 118, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 23;
			yyclosure_expr(a, c + 0);
		}
		/* expr: GREATER(sexpr,sexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yysexpr_NT] + 1;
		yytrace(a, 119, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 24;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 63: /* READ */
		/* expr: READ */
		yytrace(a, 97, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 8;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 91: /* VECTOR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: VECTOR(expr,sexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yysexpr_NT] + 1;
		yytrace(a, 137, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 40;
			yyclosure_expr(a, c + 0);
		}
		/* expr: VECTOR(expr,vexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyvexpr_NT] + 1;
		yytrace(a, 138, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 41;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 94: /* POW */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: POW(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 131, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 36;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 124: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: OR(or,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyor_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 114, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 20;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 126: /* NOT */
		yylabel(LEFT_CHILD(a),a);
		/* expr: NOT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 116, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 21;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 257: /* INT */
		/* intlist: INT */
		yytrace(a, 58, 1 + 0, p->cost[yyintlist_NT]);
		if (1 + 0 < p->cost[yyintlist_NT]) {
			p->cost[yyintlist_NT] = 1 + 0;
			p->rule.yyintlist = 1;
			yyclosure_intlist(a, 1 + 0);
		}
		/* char: INT */
		yytrace(a, 83, 1 + 0, p->cost[yychar_NT]);
		if (1 + 0 < p->cost[yychar_NT]) {
			p->cost[yychar_NT] = 1 + 0;
			p->rule.yychar = 1;
		}
		break;
	case 258: /* CHAR */
		/* char: CHAR */
		yytrace(a, 85, 1 + 0, p->cost[yychar_NT]);
		if (1 + 0 < p->cost[yychar_NT]) {
			p->cost[yychar_NT] = 1 + 0;
			p->rule.yychar = 3;
		}
		break;
	case 259: /* ID */
		/* expr: ID */
		c = (isInt(a));
		yytrace(a, 98, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 9;
			yyclosure_expr(a, c + 0);
		}
		/* sexpr: ID */
		c = (isSTR(a));
		yytrace(a, 135, c + 0, p->cost[yysexpr_NT]);
		if (c + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = c + 0;
			p->rule.yysexpr = 2;
			yyclosure_sexpr(a, c + 0);
		}
		/* vexpr: ID */
		c = (isArray(a));
		yytrace(a, 140, c + 0, p->cost[yyvexpr_NT]);
		if (c + 0 < p->cost[yyvexpr_NT]) {
			p->cost[yyvexpr_NT] = c + 0;
			p->rule.yyvexpr = 5;
			yyclosure_vexpr(a, c + 0);
		}
		break;
	case 260: /* STR */
		/* char: STR */
		yytrace(a, 84, 1 + 0, p->cost[yychar_NT]);
		if (1 + 0 < p->cost[yychar_NT]) {
			p->cost[yychar_NT] = 1 + 0;
			p->rule.yychar = 2;
		}
		break;
	case 261: /* PROGRAM */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* file: PROGRAM(enddecls,main) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyenddecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yymain_NT] + 1;
		yytrace(a, 1, c + 0, p->cost[yyfile_NT]);
		if (c + 0 < p->cost[yyfile_NT]) {
			p->cost[yyfile_NT] = c + 0;
			p->rule.yyfile = 1;
		}
		break;
	case 262: /* MODULE */
		yylabel(LEFT_CHILD(a),a);
		/* file: MODULE(moduledecls) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yymoduledecls_NT] + 1;
		yytrace(a, 2, c + 0, p->cost[yyfile_NT]);
		if (c + 0 < p->cost[yyfile_NT]) {
			p->cost[yyfile_NT] = c + 0;
			p->rule.yyfile = 2;
		}
		break;
	case 263: /* END */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* funcend: END(ID,INT) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 257 /* INT */
		) {
			c = 1;
			yytrace(a, 61, c + 0, p->cost[yyfuncend_NT]);
			if (c + 0 < p->cost[yyfuncend_NT]) {
				p->cost[yyfuncend_NT] = c + 0;
				p->rule.yyfuncend = 1;
			}
		}
		break;
	case 264: /* PUBLIC */
		return;
	case 265: /* FORWARD */
		return;
	case 266: /* STRING */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* mainfuncvar: STRING(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 10, c + 0, p->cost[yymainfuncvar_NT]);
			if (c + 0 < p->cost[yymainfuncvar_NT]) {
				p->cost[yymainfuncvar_NT] = c + 0;
				p->rule.yymainfuncvar = 2;
			}
		}
		if (	/* fvar: STRING(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 68, c + 0, p->cost[yyfvar_NT]);
			if (c + 0 < p->cost[yyfvar_NT]) {
				p->cost[yyfvar_NT] = c + 0;
				p->rule.yyfvar = 2;
			}
		}
		if (	/* funcvar: STRING(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 77, c + 0, p->cost[yyfuncvar_NT]);
			if (c + 0 < p->cost[yyfuncvar_NT]) {
				p->cost[yyfuncvar_NT] = c + 0;
				p->rule.yyfuncvar = 2;
			}
		}
		break;
	case 267: /* NUMBER */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* mainfuncvar: NUMBER(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 9, c + 0, p->cost[yymainfuncvar_NT]);
			if (c + 0 < p->cost[yymainfuncvar_NT]) {
				p->cost[yymainfuncvar_NT] = c + 0;
				p->rule.yymainfuncvar = 1;
			}
		}
		if (	/* fvar: NUMBER(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 67, c + 0, p->cost[yyfvar_NT]);
			if (c + 0 < p->cost[yyfvar_NT]) {
				p->cost[yyfvar_NT] = c + 0;
				p->rule.yyfvar = 1;
			}
		}
		if (	/* funcvar: NUMBER(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 76, c + 0, p->cost[yyfuncvar_NT]);
			if (c + 0 < p->cost[yyfuncvar_NT]) {
				p->cost[yyfuncvar_NT] = c + 0;
				p->rule.yyfuncvar = 1;
			}
		}
		break;
	case 268: /* ARRAY */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* mainfuncvar: ARRAY(ID,INTS(INT,NIL)) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 288 && /* INTS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 11, c + 0, p->cost[yymainfuncvar_NT]);
			if (c + 0 < p->cost[yymainfuncvar_NT]) {
				p->cost[yymainfuncvar_NT] = c + 0;
				p->rule.yymainfuncvar = 3;
			}
		}
		if (	/* fvar: ARRAY(ID,INTS(INT,NIL)) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 288 && /* INTS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 69, c + 0, p->cost[yyfvar_NT]);
			if (c + 0 < p->cost[yyfvar_NT]) {
				p->cost[yyfvar_NT] = c + 0;
				p->rule.yyfvar = 3;
			}
		}
		if (	/* funcvar: ARRAY(ID,INTS(INT,NIL)) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 288 && /* INTS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 78, c + 0, p->cost[yyfuncvar_NT]);
			if (c + 0 < p->cost[yyfuncvar_NT]) {
				p->cost[yyfuncvar_NT] = c + 0;
				p->rule.yyfuncvar = 3;
			}
		}
		break;
	case 269: /* FUNCTION */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* main: FUNCTION(END(ID,INT),FARGS(NIL,start)) */
			OP_LABEL(LEFT_CHILD(a)) == 263 && /* END */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 286 && /* FARGS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yystart_NT] + 1;
			yytrace(a, 3, c + 0, p->cost[yymain_NT]);
			if (c + 0 < p->cost[yymain_NT]) {
				p->cost[yymain_NT] = c + 0;
				p->rule.yymain = 1;
			}
		}
		/* decl: FUNCTION(funcend,funcfargs) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfuncend_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfuncfargs_NT] + 1;
		yytrace(a, 60, c + 0, p->cost[yydecl_NT]);
		if (c + 0 < p->cost[yydecl_NT]) {
			p->cost[yydecl_NT] = c + 0;
			p->rule.yydecl = 7;
		}
		break;
	case 270: /* VOID */
		return;
	case 271: /* CONST */
		return;
	case 272: /* IF */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* ifinst: IF(cond,block) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyblock_NT] + 1;
		yytrace(a, 26, c + 0, p->cost[yyifinst_NT]);
		if (c + 0 < p->cost[yyifinst_NT]) {
			p->cost[yyifinst_NT] = c + 0;
			p->rule.yyifinst = 1;
		}
		/* if: IF(cond,block) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyblock_NT] + 1;
		yytrace(a, 29, c + 0, p->cost[yyif_NT]);
		if (c + 0 < p->cost[yyif_NT]) {
			p->cost[yyif_NT] = c + 0;
			p->rule.yyif = 1;
		}
		/* elifif: IF(cond,block) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyblock_NT] + 1;
		yytrace(a, 32, c + 0, p->cost[yyelifif_NT]);
		if (c + 0 < p->cost[yyelifif_NT]) {
			p->cost[yyelifif_NT] = c + 0;
			p->rule.yyelifif = 1;
		}
		/* elif: IF(cond,block) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyblock_NT] + 1;
		yytrace(a, 34, c + 0, p->cost[yyelif_NT]);
		if (c + 0 < p->cost[yyelif_NT]) {
			p->cost[yyelif_NT] = c + 0;
			p->rule.yyelif = 1;
		}
		break;
	case 273: /* THEN */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		return;
	case 274: /* FI */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* inst: FI(THEN(ifinst,NIL),NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 273 && /* THEN */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyifinst_NT] + 1;
			yytrace(a, 25, c + 0, p->cost[yyinst_NT]);
			if (c + 0 < p->cost[yyinst_NT]) {
				p->cost[yyinst_NT] = c + 0;
				p->rule.yyinst = 5;
			}
		}
		if (	/* inst: FI(THEN(if,NIL),elseinst) */
			OP_LABEL(LEFT_CHILD(a)) == 273 && /* THEN */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyif_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyelseinst_NT] + 1;
			yytrace(a, 28, c + 0, p->cost[yyinst_NT]);
			if (c + 0 < p->cost[yyinst_NT]) {
				p->cost[yyinst_NT] = c + 0;
				p->rule.yyinst = 6;
			}
		}
		if (	/* inst: FI(THEN(elifif,elifinst),elifelse) */
			OP_LABEL(LEFT_CHILD(a)) == 273 /* THEN */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyelifif_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyelifinst_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyelifelse_NT] + 1;
			yytrace(a, 31, c + 0, p->cost[yyinst_NT]);
			if (c + 0 < p->cost[yyinst_NT]) {
				p->cost[yyinst_NT] = c + 0;
				p->rule.yyinst = 7;
			}
		}
		break;
	case 275: /* ELIF */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* elifinst: ELIF(elifinst,elif) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyelifinst_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyelif_NT] + 1;
		yytrace(a, 33, c + 0, p->cost[yyelifinst_NT]);
		if (c + 0 < p->cost[yyelifinst_NT]) {
			p->cost[yyelifinst_NT] = c + 0;
			p->rule.yyelifinst = 1;
		}
		break;
	case 276: /* ELSE */
		return;
	case 277: /* RETURN */
		yylabel(LEFT_CHILD(a),a);
		if (	/* ret: RETURN(NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 21, c + 0, p->cost[yyret_NT]);
			if (c + 0 < p->cost[yyret_NT]) {
				p->cost[yyret_NT] = c + 0;
				p->rule.yyret = 1;
				yyclosure_ret(a, c + 0);
			}
		}
		/* ret: RETURN(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 22, c + 0, p->cost[yyret_NT]);
		if (c + 0 < p->cost[yyret_NT]) {
			p->cost[yyret_NT] = c + 0;
			p->rule.yyret = 2;
			yyclosure_ret(a, c + 0);
		}
		break;
	case 278: /* START */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* start: START(mainfuncdecls,insts) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yymainfuncdecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinsts_NT] + 1;
		yytrace(a, 4, c + 0, p->cost[yystart_NT]);
		if (c + 0 < p->cost[yystart_NT]) {
			p->cost[yystart_NT] = c + 0;
			p->rule.yystart = 1;
		}
		/* funcbody: START(funcdecls,funcinsts) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfuncdecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfuncinsts_NT] + 1;
		yytrace(a, 71, c + 0, p->cost[yyfuncbody_NT]);
		if (c + 0 < p->cost[yyfuncbody_NT]) {
			p->cost[yyfuncbody_NT] = c + 0;
			p->rule.yyfuncbody = 2;
		}
		break;
	case 279: /* FOR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* inst: FOR(until,step) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyuntil_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystep_NT] + 1;
		yytrace(a, 38, c + 0, p->cost[yyinst_NT]);
		if (c + 0 < p->cost[yyinst_NT]) {
			p->cost[yyinst_NT] = c + 0;
			p->rule.yyinst = 8;
		}
		break;
	case 280: /* UNTIL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* until: UNTIL(forinit,untilinit) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyforinit_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyuntilinit_NT] + 1;
		yytrace(a, 39, c + 0, p->cost[yyuntil_NT]);
		if (c + 0 < p->cost[yyuntil_NT]) {
			p->cost[yyuntil_NT] = c + 0;
			p->rule.yyuntil = 1;
		}
		break;
	case 281: /* STEP */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* step: STEP(doinit,stepinit) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydoinit_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystepinit_NT] + 1;
		yytrace(a, 42, c + 0, p->cost[yystep_NT]);
		if (c + 0 < p->cost[yystep_NT]) {
			p->cost[yystep_NT] = c + 0;
			p->rule.yystep = 1;
		}
		break;
	case 282: /* DO */
		return;
	case 283: /* DONE */
		return;
	case 284: /* REPEAT */
		/* loop: REPEAT */
		yytrace(a, 18, 1 + 0, p->cost[yyloop_NT]);
		if (1 + 0 < p->cost[yyloop_NT]) {
			p->cost[yyloop_NT] = 1 + 0;
			p->rule.yyloop = 1;
		}
		break;
	case 285: /* STOP */
		/* loop: STOP */
		yytrace(a, 19, 1 + 0, p->cost[yyloop_NT]);
		if (1 + 0 < p->cost[yyloop_NT]) {
			p->cost[yyloop_NT] = 1 + 0;
			p->rule.yyloop = 2;
		}
		break;
	case 286: /* FARGS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* funcfargs: FARGS(fvardecl,funcbody) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfvardecl_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfuncbody_NT] + 1;
		yytrace(a, 62, c + 0, p->cost[yyfuncfargs_NT]);
		if (c + 0 < p->cost[yyfuncfargs_NT]) {
			p->cost[yyfuncfargs_NT] = c + 0;
			p->rule.yyfuncfargs = 1;
		}
		if (	/* funcfargs: FARGS(NIL,funcbody) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfuncbody_NT] + 1;
			yytrace(a, 63, c + 0, p->cost[yyfuncfargs_NT]);
			if (c + 0 < p->cost[yyfuncfargs_NT]) {
				p->cost[yyfuncfargs_NT] = c + 0;
				p->rule.yyfuncfargs = 2;
			}
		}
		break;
	case 287: /* CHARS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* chars: CHARS(chars,char) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yychars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychar_NT] + 1;
		yytrace(a, 81, c + 0, p->cost[yychars_NT]);
		if (c + 0 < p->cost[yychars_NT]) {
			p->cost[yychars_NT] = c + 0;
			p->rule.yychars = 1;
		}
		/* charsdecl: CHARS(charsdecl,char) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycharsdecl_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychar_NT] + 1;
		yytrace(a, 86, c + 0, p->cost[yycharsdecl_NT]);
		if (c + 0 < p->cost[yycharsdecl_NT]) {
			p->cost[yycharsdecl_NT] = c + 0;
			p->rule.yycharsdecl = 1;
		}
		if (	/* expr: CHARS(NIL,INT) */
			OP_LABEL(LEFT_CHILD(a)) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 257 /* INT */
		) {
			c = (isInt(a));
			yytrace(a, 132, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 37;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: CHARS(NIL,CHAR) */
			OP_LABEL(LEFT_CHILD(a)) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 258 /* CHAR */
		) {
			c = (isInt(a));
			yytrace(a, 133, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 38;
				yyclosure_expr(a, c + 0);
			}
		}
		/* sexpr: CHARS(chars,char) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yychars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychar_NT] + (isSTR(a));
		yytrace(a, 134, c + 0, p->cost[yysexpr_NT]);
		if (c + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = c + 0;
			p->rule.yysexpr = 1;
			yyclosure_sexpr(a, c + 0);
		}
		break;
	case 288: /* INTS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* intlist: INTS(intlist,INT) */
			OP_LABEL(RIGHT_CHILD(a)) == 257 /* INT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyintlist_NT] + 1;
			yytrace(a, 59, c + 0, p->cost[yyintlist_NT]);
			if (c + 0 < p->cost[yyintlist_NT]) {
				p->cost[yyintlist_NT] = c + 0;
				p->rule.yyintlist = 2;
				yyclosure_intlist(a, c + 0);
			}
		}
		break;
	case 289: /* ADDR */
		yylabel(LEFT_CHILD(a),a);
		if (	/* expr: ADDR(ID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = 1;
			yytrace(a, 99, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 10;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 290: /* VAR */
		yylabel(LEFT_CHILD(a),a);
		if (	/* decl: VAR(NUMBER(ID,INT)) */
			OP_LABEL(LEFT_CHILD(a)) == 267 && /* NUMBER */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 /* INT */
		) {
			c = 1;
			yytrace(a, 51, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 1;
			}
		}
		if (	/* decl: VAR(NUMBER(ID,NIL)) */
			OP_LABEL(LEFT_CHILD(a)) == 267 && /* NUMBER */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 52, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 2;
			}
		}
		if (	/* decl: VAR(STRING(ID,charsdecl)) */
			OP_LABEL(LEFT_CHILD(a)) == 266 && /* STRING */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yycharsdecl_NT] + 1;
			yytrace(a, 53, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 3;
			}
		}
		if (	/* decl: VAR(STRING(ID,NIL)) */
			OP_LABEL(LEFT_CHILD(a)) == 266 && /* STRING */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 54, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 4;
			}
		}
		if (	/* decl: VAR(ARRAY(ID,INTS(INT,arraydecl))) */
			OP_LABEL(LEFT_CHILD(a)) == 268 && /* ARRAY */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 288 && /* INTS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(LEFT_CHILD(a)))) == 257 /* INT */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(LEFT_CHILD(a)))))->cost[yyarraydecl_NT] + 1;
			yytrace(a, 55, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 5;
			}
		}
		if (	/* decl: VAR(ARRAY(ID,INTS(INT,NIL))) */
			OP_LABEL(LEFT_CHILD(a)) == 268 && /* ARRAY */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 288 && /* INTS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(LEFT_CHILD(a)))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(LEFT_CHILD(a)))) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 56, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 6;
			}
		}
		break;
	case 291: /* ARGS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* mainfuncvars: ARGS(NIL,mainfuncvar) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yymainfuncvar_NT] + 1;
			yytrace(a, 7, c + 0, p->cost[yymainfuncvars_NT]);
			if (c + 0 < p->cost[yymainfuncvars_NT]) {
				p->cost[yymainfuncvars_NT] = c + 0;
				p->rule.yymainfuncvars = 1;
				yyclosure_mainfuncvars(a, c + 0);
			}
		}
		/* mainfuncvars: ARGS(mainfuncvars,mainfuncvar) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yymainfuncvars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yymainfuncvar_NT] + 1;
		yytrace(a, 8, c + 0, p->cost[yymainfuncvars_NT]);
		if (c + 0 < p->cost[yymainfuncvars_NT]) {
			p->cost[yymainfuncvars_NT] = c + 0;
			p->rule.yymainfuncvars = 2;
			yyclosure_mainfuncvars(a, c + 0);
		}
		if (	/* fvars: ARGS(NIL,fvar) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfvar_NT] + 1;
			yytrace(a, 65, c + 0, p->cost[yyfvars_NT]);
			if (c + 0 < p->cost[yyfvars_NT]) {
				p->cost[yyfvars_NT] = c + 0;
				p->rule.yyfvars = 1;
				yyclosure_fvars(a, c + 0);
			}
		}
		/* fvars: ARGS(fvars,fvar) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfvars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfvar_NT] + 1;
		yytrace(a, 66, c + 0, p->cost[yyfvars_NT]);
		if (c + 0 < p->cost[yyfvars_NT]) {
			p->cost[yyfvars_NT] = c + 0;
			p->rule.yyfvars = 2;
			yyclosure_fvars(a, c + 0);
		}
		if (	/* funcvars: ARGS(NIL,funcvar) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfuncvar_NT] + 1;
			yytrace(a, 74, c + 0, p->cost[yyfuncvars_NT]);
			if (c + 0 < p->cost[yyfuncvars_NT]) {
				p->cost[yyfuncvars_NT] = c + 0;
				p->rule.yyfuncvars = 1;
				yyclosure_funcvars(a, c + 0);
			}
		}
		/* funcvars: ARGS(funcvars,funcvar) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfuncvars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfuncvar_NT] + 1;
		yytrace(a, 75, c + 0, p->cost[yyfuncvars_NT]);
		if (c + 0 < p->cost[yyfuncvars_NT]) {
			p->cost[yyfuncvars_NT] = c + 0;
			p->rule.yyfuncvars = 2;
			yyclosure_funcvars(a, c + 0);
		}
		break;
	case 292: /* DECL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* decls: DECL(NIL,decl) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecl_NT] + 1;
			yytrace(a, 49, c + 0, p->cost[yydecls_NT]);
			if (c + 0 < p->cost[yydecls_NT]) {
				p->cost[yydecls_NT] = c + 0;
				p->rule.yydecls = 1;
				yyclosure_decls(a, c + 0);
			}
		}
		/* decls: DECL(decls,decl) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecl_NT] + 1;
		yytrace(a, 50, c + 0, p->cost[yydecls_NT]);
		if (c + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = c + 0;
			p->rule.yydecls = 2;
			yyclosure_decls(a, c + 0);
		}
		break;
	case 293: /* NIL */
		/* mainfuncdecls: NIL */
		yytrace(a, 5, 1 + 0, p->cost[yymainfuncdecls_NT]);
		if (1 + 0 < p->cost[yymainfuncdecls_NT]) {
			p->cost[yymainfuncdecls_NT] = 1 + 0;
			p->rule.yymainfuncdecls = 1;
		}
		/* insts: NIL */
		yytrace(a, 12, 1 + 0, p->cost[yyinsts_NT]);
		if (1 + 0 < p->cost[yyinsts_NT]) {
			p->cost[yyinsts_NT] = 1 + 0;
			p->rule.yyinsts = 1;
		}
		/* ret: NIL */
		yytrace(a, 23, 1 + 0, p->cost[yyret_NT]);
		if (1 + 0 < p->cost[yyret_NT]) {
			p->cost[yyret_NT] = 1 + 0;
			p->rule.yyret = 3;
			yyclosure_ret(a, 1 + 0);
		}
		/* elifinst: NIL */
		yytrace(a, 35, 1 + 0, p->cost[yyelifinst_NT]);
		if (1 + 0 < p->cost[yyelifinst_NT]) {
			p->cost[yyelifinst_NT] = 1 + 0;
			p->rule.yyelifinst = 2;
		}
		/* elifelse: NIL */
		yytrace(a, 37, 1 + 0, p->cost[yyelifelse_NT]);
		if (1 + 0 < p->cost[yyelifelse_NT]) {
			p->cost[yyelifelse_NT] = 1 + 0;
			p->rule.yyelifelse = 2;
		}
		/* gdecls: NIL */
		yytrace(a, 47, 1 + 0, p->cost[yygdecls_NT]);
		if (1 + 0 < p->cost[yygdecls_NT]) {
			p->cost[yygdecls_NT] = 1 + 0;
			p->rule.yygdecls = 1;
			yyclosure_gdecls(a, 1 + 0);
		}
		/* funcbody: NIL */
		yytrace(a, 70, 1 + 0, p->cost[yyfuncbody_NT]);
		if (1 + 0 < p->cost[yyfuncbody_NT]) {
			p->cost[yyfuncbody_NT] = 1 + 0;
			p->rule.yyfuncbody = 1;
		}
		/* funcdecls: NIL */
		yytrace(a, 72, 1 + 0, p->cost[yyfuncdecls_NT]);
		if (1 + 0 < p->cost[yyfuncdecls_NT]) {
			p->cost[yyfuncdecls_NT] = 1 + 0;
			p->rule.yyfuncdecls = 1;
		}
		/* funcinsts: NIL */
		yytrace(a, 79, 1 + 0, p->cost[yyfuncinsts_NT]);
		if (1 + 0 < p->cost[yyfuncinsts_NT]) {
			p->cost[yyfuncinsts_NT] = 1 + 0;
			p->rule.yyfuncinsts = 1;
		}
		/* chars: NIL */
		yytrace(a, 82, 1 + 0, p->cost[yychars_NT]);
		if (1 + 0 < p->cost[yychars_NT]) {
			p->cost[yychars_NT] = 1 + 0;
			p->rule.yychars = 2;
		}
		/* charsdecl: NIL */
		yytrace(a, 87, 1 + 0, p->cost[yycharsdecl_NT]);
		if (1 + 0 < p->cost[yycharsdecl_NT]) {
			p->cost[yycharsdecl_NT] = 1 + 0;
			p->rule.yycharsdecl = 2;
		}
		break;
	case 294: /* EQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: EQ(expr,ID) */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
			yytrace(a, 93, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 4;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: EQ(ADD(ID,CHARS(NIL,INT)),ID) */
			OP_LABEL(LEFT_CHILD(a)) == 43 && /* ADD */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 287 && /* CHARS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(LEFT_CHILD(a)))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(LEFT_CHILD(a)))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = (sameVar(a));
			yytrace(a, 94, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 5;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: EQ(ADD(CHARS(NIL,INT),ID),ID) */
			OP_LABEL(LEFT_CHILD(a)) == 43 && /* ADD */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 287 && /* CHARS */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(LEFT_CHILD(a)))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(LEFT_CHILD(a)))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = (sameVar2(a));
			yytrace(a, 95, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 6;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: EQ(SUB(ID,CHARS(NIL,INT)),ID) */
			OP_LABEL(LEFT_CHILD(a)) == 45 && /* SUB */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 287 && /* CHARS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(LEFT_CHILD(a)))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(LEFT_CHILD(a)))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = (sameVar(a));
			yytrace(a, 96, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 7;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: EQ(expr,VECTOR(expr,sexpr)) */
			OP_LABEL(RIGHT_CHILD(a)) == 91 /* VECTOR */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yysexpr_NT] + 1;
			yytrace(a, 136, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 39;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: EQ(expr,VECTOR(expr,vexpr)) */
			OP_LABEL(RIGHT_CHILD(a)) == 91 /* VECTOR */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyvexpr_NT] + 1;
			yytrace(a, 139, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 42;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 295: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: NE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 128, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 33;
			yyclosure_expr(a, c + 0);
		}
		/* expr: NE(sexpr,sexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yysexpr_NT] + 1;
		yytrace(a, 129, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 34;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 296: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 124, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 29;
			yyclosure_expr(a, c + 0);
		}
		/* expr: GE(sexpr,sexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yysexpr_NT] + 1;
		yytrace(a, 125, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 30;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 297: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 126, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 31;
			yyclosure_expr(a, c + 0);
		}
		/* expr: LE(sexpr,sexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yysexpr_NT] + 1;
		yytrace(a, 127, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 32;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 298: /* uminus */
		yylabel(LEFT_CHILD(a),a);
		/* expr: uminus(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 130, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 35;
			yyclosure_expr(a, c + 0);
		}
		break;
	default:
		PANIC("yylabel", "Bad terminal", OP_LABEL(a));
	}
}

static void yykids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	if (!p)
		PANIC("yykids", "Null tree in rule", eruleno);
	if (!kids)
		PANIC("yykids", "Null kids in", OP_LABEL(p));
	switch (eruleno) {
	case 138: /* expr: VECTOR(expr,vexpr) */
	case 137: /* expr: VECTOR(expr,sexpr) */
	case 134: /* sexpr: CHARS(chars,char) */
	case 131: /* expr: POW(expr,expr) */
	case 129: /* expr: NE(sexpr,sexpr) */
	case 128: /* expr: NE(expr,expr) */
	case 127: /* expr: LE(sexpr,sexpr) */
	case 126: /* expr: LE(expr,expr) */
	case 125: /* expr: GE(sexpr,sexpr) */
	case 124: /* expr: GE(expr,expr) */
	case 123: /* expr: EQUALS(sexpr,sexpr) */
	case 122: /* expr: EQUALS(expr,expr) */
	case 121: /* expr: LESS(sexpr,sexpr) */
	case 120: /* expr: LESS(expr,expr) */
	case 119: /* expr: GREATER(sexpr,sexpr) */
	case 118: /* expr: GREATER(expr,expr) */
	case 117: /* expr: MOD(expr,expr) */
	case 114: /* expr: OR(or,expr) */
	case 112: /* expr: AND(and,expr) */
	case 111: /* expr: DIV(expr,expr) */
	case 110: /* expr: MUL(expr,expr) */
	case 105: /* vexpr: SUB(vexpr,expr) */
	case 104: /* vexpr: SUB(expr,vexpr) */
	case 103: /* vexpr: ADD(vexpr,expr) */
	case 102: /* vexpr: ADD(expr,vexpr) */
	case 101: /* expr: ADD(expr,expr) */
	case 100: /* expr: SUB(expr,expr) */
	case 89: /* exprs: ARGSLIST(expr,exprs) */
	case 86: /* charsdecl: CHARS(charsdecl,char) */
	case 81: /* chars: CHARS(chars,char) */
	case 80: /* funcinsts: STMT(insts,ret) */
	case 75: /* funcvars: ARGS(funcvars,funcvar) */
	case 71: /* funcbody: START(funcdecls,funcinsts) */
	case 66: /* fvars: ARGS(fvars,fvar) */
	case 62: /* funcfargs: FARGS(fvardecl,funcbody) */
	case 60: /* decl: FUNCTION(funcend,funcfargs) */
	case 50: /* decls: DECL(decls,decl) */
	case 42: /* step: STEP(doinit,stepinit) */
	case 39: /* until: UNTIL(forinit,untilinit) */
	case 38: /* inst: FOR(until,step) */
	case 34: /* elif: IF(cond,block) */
	case 33: /* elifinst: ELIF(elifinst,elif) */
	case 32: /* elifif: IF(cond,block) */
	case 29: /* if: IF(cond,block) */
	case 26: /* ifinst: IF(cond,block) */
	case 24: /* block: STMT(insts,loop) */
	case 13: /* insts: STMT(insts,inst) */
	case 8: /* mainfuncvars: ARGS(mainfuncvars,mainfuncvar) */
	case 4: /* start: START(mainfuncdecls,insts) */
	case 1: /* file: PROGRAM(enddecls,main) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 130: /* expr: uminus(expr) */
	case 116: /* expr: NOT(expr) */
	case 93: /* expr: EQ(expr,ID) */
	case 88: /* exprs: ARGSLIST(expr,NIL) */
	case 59: /* intlist: INTS(intlist,INT) */
	case 22: /* ret: RETURN(expr) */
	case 17: /* inst: ALLOC(expr,ID) */
	case 15: /* inst: PRINT(sexpr) */
	case 14: /* inst: PRINT(expr) */
	case 2: /* file: MODULE(moduledecls) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 3: /* main: FUNCTION(END(ID,INT),FARGS(NIL,start)) */
		kids[0] = RIGHT_CHILD(RIGHT_CHILD(p));
		break;
	case 140: /* vexpr: ID */
	case 135: /* sexpr: ID */
	case 133: /* expr: CHARS(NIL,CHAR) */
	case 132: /* expr: CHARS(NIL,INT) */
	case 109: /* expr: DIV(CHARS(NIL,INT),CHARS(NIL,INT)) */
	case 108: /* expr: MUL(CHARS(NIL,INT),CHARS(NIL,INT)) */
	case 107: /* expr: SUB(CHARS(NIL,INT),CHARS(NIL,INT)) */
	case 106: /* expr: ADD(CHARS(NIL,INT),CHARS(NIL,INT)) */
	case 99: /* expr: ADDR(ID) */
	case 98: /* expr: ID */
	case 97: /* expr: READ */
	case 96: /* expr: EQ(SUB(ID,CHARS(NIL,INT)),ID) */
	case 95: /* expr: EQ(ADD(CHARS(NIL,INT),ID),ID) */
	case 94: /* expr: EQ(ADD(ID,CHARS(NIL,INT)),ID) */
	case 87: /* charsdecl: NIL */
	case 85: /* char: CHAR */
	case 84: /* char: STR */
	case 83: /* char: INT */
	case 82: /* chars: NIL */
	case 79: /* funcinsts: NIL */
	case 78: /* funcvar: ARRAY(ID,INTS(INT,NIL)) */
	case 77: /* funcvar: STRING(ID,NIL) */
	case 76: /* funcvar: NUMBER(ID,NIL) */
	case 72: /* funcdecls: NIL */
	case 70: /* funcbody: NIL */
	case 69: /* fvar: ARRAY(ID,INTS(INT,NIL)) */
	case 68: /* fvar: STRING(ID,NIL) */
	case 67: /* fvar: NUMBER(ID,NIL) */
	case 61: /* funcend: END(ID,INT) */
	case 58: /* intlist: INT */
	case 56: /* decl: VAR(ARRAY(ID,INTS(INT,NIL))) */
	case 54: /* decl: VAR(STRING(ID,NIL)) */
	case 52: /* decl: VAR(NUMBER(ID,NIL)) */
	case 51: /* decl: VAR(NUMBER(ID,INT)) */
	case 47: /* gdecls: NIL */
	case 37: /* elifelse: NIL */
	case 35: /* elifinst: NIL */
	case 23: /* ret: NIL */
	case 21: /* ret: RETURN(NIL) */
	case 19: /* loop: STOP */
	case 18: /* loop: REPEAT */
	case 12: /* insts: NIL */
	case 11: /* mainfuncvar: ARRAY(ID,INTS(INT,NIL)) */
	case 10: /* mainfuncvar: STRING(ID,NIL) */
	case 9: /* mainfuncvar: NUMBER(ID,NIL) */
	case 5: /* mainfuncdecls: NIL */
		break;
	case 115: /* or: expr */
	case 113: /* and: expr */
	case 92: /* expr: vexpr */
	case 91: /* expr: sexpr */
	case 73: /* funcdecls: funcvars */
	case 64: /* fvardecl: fvars */
	case 57: /* arraydecl: intlist */
	case 48: /* gdecls: decls */
	case 46: /* moduledecls: gdecls */
	case 45: /* enddecls: gdecls */
	case 44: /* doinit: block */
	case 43: /* stepinit: expr */
	case 41: /* untilinit: expr */
	case 40: /* forinit: expr */
	case 36: /* elifelse: block */
	case 30: /* elseinst: block */
	case 27: /* cond: expr */
	case 20: /* loop: ret */
	case 16: /* inst: expr */
	case 6: /* mainfuncdecls: mainfuncvars */
		kids[0] = p;
		break;
	case 90: /* expr: FUNCALL(ID,exprs) */
	case 74: /* funcvars: ARGS(NIL,funcvar) */
	case 65: /* fvars: ARGS(NIL,fvar) */
	case 63: /* funcfargs: FARGS(NIL,funcbody) */
	case 49: /* decls: DECL(NIL,decl) */
	case 7: /* mainfuncvars: ARGS(NIL,mainfuncvar) */
		kids[0] = RIGHT_CHILD(p);
		break;
	case 25: /* inst: FI(THEN(ifinst,NIL),NIL) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		break;
	case 28: /* inst: FI(THEN(if,NIL),elseinst) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(p);
		break;
	case 31: /* inst: FI(THEN(elifif,elifinst),elifelse) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(LEFT_CHILD(p));
		kids[2] = RIGHT_CHILD(p);
		break;
	case 53: /* decl: VAR(STRING(ID,charsdecl)) */
		kids[0] = RIGHT_CHILD(LEFT_CHILD(p));
		break;
	case 55: /* decl: VAR(ARRAY(ID,INTS(INT,arraydecl))) */
		kids[0] = RIGHT_CHILD(RIGHT_CHILD(LEFT_CHILD(p)));
		break;
	case 139: /* expr: EQ(expr,VECTOR(expr,vexpr)) */
	case 136: /* expr: EQ(expr,VECTOR(expr,sexpr)) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = LEFT_CHILD(RIGHT_CHILD(p));
		kids[2] = RIGHT_CHILD(RIGHT_CHILD(p));
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[3];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* file: PROGRAM(enddecls,main) */
		fprintf(stderr, "0x%lx: line 90: file: PROGRAM(enddecls,main)\n",(long)p);
#line 90 "minor.brg"
{fprintf(yyout, pfIMM pfPOP pfLEAVE pfRET pfLEAVE pfRET, 0);}
		break;
	case 2: /* file: MODULE(moduledecls) */
		fprintf(stderr, "0x%lx: line 91: file: MODULE(moduledecls)\n",(long)p);
#line 91 "minor.brg"
{}
		break;
	case 3: /* main: FUNCTION(END(ID,INT),FARGS(NIL,start)) */
		fprintf(stderr, "0x%lx: line 92: main: FUNCTION(END(ID,INT),FARGS(NIL,start))\n",(long)p);
#line 92 "minor.brg"
{}
		break;
	case 4: /* start: START(mainfuncdecls,insts) */
		fprintf(stderr, "0x%lx: line 93: start: START(mainfuncdecls,insts)\n",(long)p);
#line 93 "minor.brg"
{IDpop();}
		break;
	case 5: /* mainfuncdecls: NIL */
		fprintf(stderr, "0x%lx: line 94: mainfuncdecls: NIL\n",(long)p);
#line 94 "minor.brg"
{fprintf(yyout, pfENTER, 0); localpos = 0;}
		break;
	case 6: /* mainfuncdecls: mainfuncvars */
		fprintf(stderr, "0x%lx: line 95: mainfuncdecls: mainfuncvars\n",(long)p);
#line 95 "minor.brg"
{printf("o local é %d\n",localpos); fprintf(yyout, pfENTER, -localpos); localpos = 0;}
		break;
	case 7: /* mainfuncvars: ARGS(NIL,mainfuncvar) */
		fprintf(stderr, "0x%lx: line 96: mainfuncvars: ARGS(NIL,mainfuncvar)\n",(long)p);
#line 96 "minor.brg"
{}
		break;
	case 8: /* mainfuncvars: ARGS(mainfuncvars,mainfuncvar) */
		fprintf(stderr, "0x%lx: line 97: mainfuncvars: ARGS(mainfuncvars,mainfuncvar)\n",(long)p);
#line 97 "minor.brg"
{}
		break;
	case 9: /* mainfuncvar: NUMBER(ID,NIL) */
		fprintf(stderr, "0x%lx: line 98: mainfuncvar: NUMBER(ID,NIL)\n",(long)p);
#line 98 "minor.brg"
{localpos-=4; int* ptr = (int*)malloc(sizeof(int)); *ptr = localpos; IDnew(tINT+tLOCAL, LEFT_CHILD(p)->value.s, (void*)ptr); }
		break;
	case 10: /* mainfuncvar: STRING(ID,NIL) */
		fprintf(stderr, "0x%lx: line 99: mainfuncvar: STRING(ID,NIL)\n",(long)p);
#line 99 "minor.brg"
{localpos-=4; int* ptr = (int*)malloc(sizeof(int)); *ptr = localpos; IDnew(tSTR+tLOCAL, LEFT_CHILD(p)->value.s, (void*)ptr); }
		break;
	case 11: /* mainfuncvar: ARRAY(ID,INTS(INT,NIL)) */
		fprintf(stderr, "0x%lx: line 100: mainfuncvar: ARRAY(ID,INTS(INT,NIL))\n",(long)p);
#line 100 "minor.brg"
{localpos-=4; int* ptr = (int*)malloc(sizeof(int)); *ptr = localpos; IDnew(tVEC+tLOCAL, LEFT_CHILD(p)->value.s, (void*)ptr); }
		break;
	case 12: /* insts: NIL */
		fprintf(stderr, "0x%lx: line 103: insts: NIL\n",(long)p);
#line 103 "minor.brg"
{}
		break;
	case 13: /* insts: STMT(insts,inst) */
		fprintf(stderr, "0x%lx: line 104: insts: STMT(insts,inst)\n",(long)p);
#line 104 "minor.brg"
{}
		break;
	case 14: /* inst: PRINT(expr) */
		fprintf(stderr, "0x%lx: line 105: inst: PRINT(expr)\n",(long)p);
#line 105 "minor.brg"
{fprintf(yyout, pfCALL pfTRASH, "_printi", pfWORD);}
		break;
	case 15: /* inst: PRINT(sexpr) */
		fprintf(stderr, "0x%lx: line 106: inst: PRINT(sexpr)\n",(long)p);
#line 106 "minor.brg"
{fprintf(yyout, pfCALL pfTRASH, "_prints", pfWORD);}
		break;
	case 16: /* inst: expr */
		fprintf(stderr, "0x%lx: line 107: inst: expr\n",(long)p);
#line 107 "minor.brg"
{}
		break;
	case 17: /* inst: ALLOC(expr,ID) */
		fprintf(stderr, "0x%lx: line 108: inst: ALLOC(expr,ID)\n",(long)p);
#line 108 "minor.brg"
{allocVECSTR(RIGHT_CHILD(p)->value.s);}
		break;
	case 18: /* loop: REPEAT */
		fprintf(stderr, "0x%lx: line 112: loop: REPEAT\n",(long)p);
#line 112 "minor.brg"
{fprintf(yyout, pfJMP, mklbl(steplbl[depth]));}
		break;
	case 19: /* loop: STOP */
		fprintf(stderr, "0x%lx: line 113: loop: STOP\n",(long)p);
#line 113 "minor.brg"
{fprintf(yyout, pfJMP, mklbl(brklbl[depth]));}
		break;
	case 20: /* loop: ret */
		fprintf(stderr, "0x%lx: line 114: loop: ret\n",(long)p);
#line 114 "minor.brg"
{}
		break;
	case 21: /* ret: RETURN(NIL) */
		fprintf(stderr, "0x%lx: line 115: ret: RETURN(NIL)\n",(long)p);
#line 115 "minor.brg"
{fprintf(yyout, pfLEAVE pfRET);}
		break;
	case 22: /* ret: RETURN(expr) */
		fprintf(stderr, "0x%lx: line 116: ret: RETURN(expr)\n",(long)p);
#line 116 "minor.brg"
{fprintf(yyout, pfPOP pfLEAVE pfRET);}
		break;
	case 23: /* ret: NIL */
		fprintf(stderr, "0x%lx: line 117: ret: NIL\n",(long)p);
#line 117 "minor.brg"
{}
		break;
	case 24: /* block: STMT(insts,loop) */
		fprintf(stderr, "0x%lx: line 119: block: STMT(insts,loop)\n",(long)p);
#line 119 "minor.brg"
{}
		break;
	case 25: /* inst: FI(THEN(ifinst,NIL),NIL) */
		fprintf(stderr, "0x%lx: line 125: inst: FI(THEN(ifinst,NIL),NIL)\n",(long)p);
#line 125 "minor.brg"
{}
		break;
	case 26: /* ifinst: IF(cond,block) */
		fprintf(stderr, "0x%lx: line 126: ifinst: IF(cond,block)\n",(long)p);
#line 126 "minor.brg"
{fprintf(yyout, pfLABEL, mklbl(LEFT_CHILD(p)->place));}
		break;
	case 27: /* cond: expr */
		fprintf(stderr, "0x%lx: line 127: cond: expr\n",(long)p);
#line 127 "minor.brg"
{p->place = ++lbl; fprintf(yyout, pfJZ, mklbl(p->place));}
		break;
	case 28: /* inst: FI(THEN(if,NIL),elseinst) */
		fprintf(stderr, "0x%lx: line 130: inst: FI(THEN(if,NIL),elseinst)\n",(long)p);
#line 130 "minor.brg"
{fprintf(yyout, pfLABEL, mklbl(LEFT_CHILD(LEFT_CHILD(p))->place));}
		break;
	case 29: /* if: IF(cond,block) */
		fprintf(stderr, "0x%lx: line 131: if: IF(cond,block)\n",(long)p);
#line 131 "minor.brg"
{p->place = ++lbl; fprintf(yyout, pfJMP pfLABEL,mklbl(p->place), mklbl(LEFT_CHILD(p)->place));}
		break;
	case 30: /* elseinst: block */
		fprintf(stderr, "0x%lx: line 132: elseinst: block\n",(long)p);
#line 132 "minor.brg"
{}
		break;
	case 31: /* inst: FI(THEN(elifif,elifinst),elifelse) */
		fprintf(stderr, "0x%lx: line 135: inst: FI(THEN(elifif,elifinst),elifelse)\n",(long)p);
#line 135 "minor.brg"
{fprintf(yyout, pfLABEL, mklbl(eliflbl[elifdepth])); elifdepth--;}
		break;
	case 32: /* elifif: IF(cond,block) */
		fprintf(stderr, "0x%lx: line 136: elifif: IF(cond,block)\n",(long)p);
#line 136 "minor.brg"
{elifdepth++; p->place = ++lbl; eliflbl[elifdepth] = p->place; fprintf(yyout, pfJMP pfLABEL,mklbl(eliflbl[elifdepth]), mklbl(LEFT_CHILD(p)->place));}
		break;
	case 33: /* elifinst: ELIF(elifinst,elif) */
		fprintf(stderr, "0x%lx: line 137: elifinst: ELIF(elifinst,elif)\n",(long)p);
#line 137 "minor.brg"
{}
		break;
	case 34: /* elif: IF(cond,block) */
		fprintf(stderr, "0x%lx: line 138: elif: IF(cond,block)\n",(long)p);
#line 138 "minor.brg"
{fprintf(yyout, pfJMP pfLABEL,mklbl(eliflbl[elifdepth]), mklbl(LEFT_CHILD(p)->place));}
		break;
	case 35: /* elifinst: NIL */
		fprintf(stderr, "0x%lx: line 139: elifinst: NIL\n",(long)p);
#line 139 "minor.brg"
{}
		break;
	case 36: /* elifelse: block */
		fprintf(stderr, "0x%lx: line 140: elifelse: block\n",(long)p);
#line 140 "minor.brg"
{}
		break;
	case 37: /* elifelse: NIL */
		fprintf(stderr, "0x%lx: line 141: elifelse: NIL\n",(long)p);
#line 141 "minor.brg"
{}
		break;
	case 38: /* inst: FOR(until,step) */
		fprintf(stderr, "0x%lx: line 144: inst: FOR(until,step)\n",(long)p);
#line 144 "minor.brg"
{fprintf(yyout,pfJMP pfLABEL, mklbl(LEFT_CHILD(p)->place),mklbl(brklbl[depth])); depth--;}
		break;
	case 39: /* until: UNTIL(forinit,untilinit) */
		fprintf(stderr, "0x%lx: line 145: until: UNTIL(forinit,untilinit)\n",(long)p);
#line 145 "minor.brg"
{p->place = LEFT_CHILD(p)->place;}
		break;
	case 40: /* forinit: expr */
		fprintf(stderr, "0x%lx: line 146: forinit: expr\n",(long)p);
#line 146 "minor.brg"
{lbl++; fprintf(yyout, pfLABEL, mklbl(lbl)); p->place = lbl; depth++;}
		break;
	case 41: /* untilinit: expr */
		fprintf(stderr, "0x%lx: line 147: untilinit: expr\n",(long)p);
#line 147 "minor.brg"
{lbl++; brklbl[depth] = lbl; fprintf(yyout, pfJNZ, mklbl(lbl)); lbl++; steplbl[depth] = lbl;}
		break;
	case 42: /* step: STEP(doinit,stepinit) */
		fprintf(stderr, "0x%lx: line 148: step: STEP(doinit,stepinit)\n",(long)p);
#line 148 "minor.brg"
{}
		break;
	case 43: /* stepinit: expr */
		fprintf(stderr, "0x%lx: line 149: stepinit: expr\n",(long)p);
#line 149 "minor.brg"
{}
		break;
	case 44: /* doinit: block */
		fprintf(stderr, "0x%lx: line 150: doinit: block\n",(long)p);
#line 150 "minor.brg"
{fprintf(yyout, pfLABEL, mklbl(steplbl[depth]));}
		break;
	case 45: /* enddecls: gdecls */
		fprintf(stderr, "0x%lx: line 154: enddecls: gdecls\n",(long)p);
#line 154 "minor.brg"
{fprintf(yyout, pfTEXT pfALIGN pfGLOBL pfLABEL, mkfunc("main"), pfFUNC, mkfunc("main"));IDpush();}
		break;
	case 46: /* moduledecls: gdecls */
		fprintf(stderr, "0x%lx: line 155: moduledecls: gdecls\n",(long)p);
#line 155 "minor.brg"
{}
		break;
	case 47: /* gdecls: NIL */
		fprintf(stderr, "0x%lx: line 156: gdecls: NIL\n",(long)p);
#line 156 "minor.brg"
{}
		break;
	case 48: /* gdecls: decls */
		fprintf(stderr, "0x%lx: line 157: gdecls: decls\n",(long)p);
#line 157 "minor.brg"
{}
		break;
	case 49: /* decls: DECL(NIL,decl) */
		fprintf(stderr, "0x%lx: line 158: decls: DECL(NIL,decl)\n",(long)p);
#line 158 "minor.brg"
{}
		break;
	case 50: /* decls: DECL(decls,decl) */
		fprintf(stderr, "0x%lx: line 159: decls: DECL(decls,decl)\n",(long)p);
#line 159 "minor.brg"
{}
		break;
	case 51: /* decl: VAR(NUMBER(ID,INT)) */
		fprintf(stderr, "0x%lx: line 160: decl: VAR(NUMBER(ID,INT))\n",(long)p);
#line 160 "minor.brg"
{constInitialization(p->info); publicInitialization(LEFT_CHILD(LEFT_CHILD(p))->value.s, p->info); fprintf(yyout, pfINTEGER, RIGHT_CHILD(LEFT_CHILD(p))->value.i); manageExterns(LEFT_CHILD(LEFT_CHILD(p))->value.s);}
		break;
	case 52: /* decl: VAR(NUMBER(ID,NIL)) */
		fprintf(stderr, "0x%lx: line 161: decl: VAR(NUMBER(ID,NIL))\n",(long)p);
#line 161 "minor.brg"
{if(!(p->info&tFWD)){fprintf(yyout, pfBSS pfALIGN);  publicInitialization(LEFT_CHILD(LEFT_CHILD(p))->value.s, p->info); fprintf(yyout, pfBYTE pfTEXT, pfWORD);}else{extrns[extcnt++] = strdup(LEFT_CHILD(LEFT_CHILD(p))->value.s);}}
		break;
	case 53: /* decl: VAR(STRING(ID,charsdecl)) */
		fprintf(stderr, "0x%lx: line 162: decl: VAR(STRING(ID,charsdecl))\n",(long)p);
#line 162 "minor.brg"
{fprintf(yyout, pfCHAR,0); constInitialization(p->info); publicInitialization(LEFT_CHILD(LEFT_CHILD(p))->value.s, p->info); fprintf(yyout, pfID pfTEXT, mklbl(lbl));manageExterns(LEFT_CHILD(LEFT_CHILD(p))->value.s);}
		break;
	case 54: /* decl: VAR(STRING(ID,NIL)) */
		fprintf(stderr, "0x%lx: line 163: decl: VAR(STRING(ID,NIL))\n",(long)p);
#line 163 "minor.brg"
{if(!(p->info&tFWD)){fprintf(yyout, pfBSS  pfALIGN); publicInitialization(LEFT_CHILD(LEFT_CHILD(p))->value.s, p->info); fprintf(yyout, pfBYTE pfTEXT, pfWORD);}else{extrns[extcnt++] = strdup(LEFT_CHILD(LEFT_CHILD(p))->value.s);}}
		break;
	case 55: /* decl: VAR(ARRAY(ID,INTS(INT,arraydecl))) */
		fprintf(stderr, "0x%lx: line 164: decl: VAR(ARRAY(ID,INTS(INT,arraydecl)))\n",(long)p);
#line 164 "minor.brg"
{VectorInit(LEFT_CHILD(RIGHT_CHILD(LEFT_CHILD(p)))->value.i,RIGHT_CHILD(RIGHT_CHILD(LEFT_CHILD(p)))->place) ;constInitialization(p->info); publicInitialization(LEFT_CHILD(LEFT_CHILD(p))->value.s, p->info); fprintf(yyout, pfID pfTEXT, mklbl(lbl)); lbl++; manageExterns(LEFT_CHILD(LEFT_CHILD(p))->value.s);}
		break;
	case 56: /* decl: VAR(ARRAY(ID,INTS(INT,NIL))) */
		fprintf(stderr, "0x%lx: line 166: decl: VAR(ARRAY(ID,INTS(INT,NIL)))\n",(long)p);
#line 166 "minor.brg"
{createVecWithLength(LEFT_CHILD(LEFT_CHILD(p))->value.s, LEFT_CHILD(RIGHT_CHILD(LEFT_CHILD(p)))->value.i, p->info);}
		break;
	case 57: /* arraydecl: intlist */
		fprintf(stderr, "0x%lx: line 169: arraydecl: intlist\n",(long)p);
#line 169 "minor.brg"
{}
		break;
	case 58: /* intlist: INT */
		fprintf(stderr, "0x%lx: line 170: intlist: INT\n",(long)p);
#line 170 "minor.brg"
{p->place = 1; fprintf(yyout, pfDATA pfLABEL pfINTEGER, mklbl(lbl), p->value.i);}
		break;
	case 59: /* intlist: INTS(intlist,INT) */
		fprintf(stderr, "0x%lx: line 171: intlist: INTS(intlist,INT)\n",(long)p);
#line 171 "minor.brg"
{fprintf(yyout, pfINTEGER, RIGHT_CHILD(p)->value.i); p->place = LEFT_CHILD(p)->place + 1;}
		break;
	case 60: /* decl: FUNCTION(funcend,funcfargs) */
		fprintf(stderr, "0x%lx: line 174: decl: FUNCTION(funcend,funcfargs)\n",(long)p);
#line 174 "minor.brg"
{printf("O nome da funcao é %s e o meu tipo é %d\n",LEFT_CHILD(LEFT_CHILD(p))->value.s,RIGHT_CHILD(LEFT_CHILD(p))->value.i);long type = RIGHT_CHILD(LEFT_CHILD(p))->value.i; if(!(type&tFWD)){printf("Vou entrar aqui\n");fprintf(yyout, pfLEAVE pfRET);}IDpop();}
		break;
	case 61: /* funcend: END(ID,INT) */
		fprintf(stderr, "0x%lx: line 175: funcend: END(ID,INT)\n",(long)p);
#line 175 "minor.brg"
{if(!(RIGHT_CHILD(p)->value.i&tFWD)){fprintf(yyout, pfTEXT pfALIGN pfGLOBL pfLABEL, mkfunc(LEFT_CHILD(p)->value.s), pfFUNC, mkfunc(LEFT_CHILD(p)->value.s)); manageExterns(mkfunc(LEFT_CHILD(p)->value.s));}else{extrns[extcnt++] = strdup(mkfunc(LEFT_CHILD(p)->value.s));} p->place = RIGHT_CHILD(p)->value.i; IDpush();}
		break;
	case 62: /* funcfargs: FARGS(fvardecl,funcbody) */
		fprintf(stderr, "0x%lx: line 176: funcfargs: FARGS(fvardecl,funcbody)\n",(long)p);
#line 176 "minor.brg"
{}
		break;
	case 63: /* funcfargs: FARGS(NIL,funcbody) */
		fprintf(stderr, "0x%lx: line 177: funcfargs: FARGS(NIL,funcbody)\n",(long)p);
#line 177 "minor.brg"
{}
		break;
	case 64: /* fvardecl: fvars */
		fprintf(stderr, "0x%lx: line 180: fvardecl: fvars\n",(long)p);
#line 180 "minor.brg"
{argspos = 8;}
		break;
	case 65: /* fvars: ARGS(NIL,fvar) */
		fprintf(stderr, "0x%lx: line 181: fvars: ARGS(NIL,fvar)\n",(long)p);
#line 181 "minor.brg"
{}
		break;
	case 66: /* fvars: ARGS(fvars,fvar) */
		fprintf(stderr, "0x%lx: line 182: fvars: ARGS(fvars,fvar)\n",(long)p);
#line 182 "minor.brg"
{}
		break;
	case 67: /* fvar: NUMBER(ID,NIL) */
		fprintf(stderr, "0x%lx: line 183: fvar: NUMBER(ID,NIL)\n",(long)p);
#line 183 "minor.brg"
{int* ptr = (int*)malloc(sizeof(int)); *ptr = argspos; IDnew(tLOCAL+tINT, LEFT_CHILD(p)->value.s, (void*)ptr); argspos+=4;}
		break;
	case 68: /* fvar: STRING(ID,NIL) */
		fprintf(stderr, "0x%lx: line 184: fvar: STRING(ID,NIL)\n",(long)p);
#line 184 "minor.brg"
{int* ptr = (int*)malloc(sizeof(int)); *ptr = argspos; IDnew(tLOCAL+tSTR, LEFT_CHILD(p)->value.s, (void*)ptr); argspos+=4;}
		break;
	case 69: /* fvar: ARRAY(ID,INTS(INT,NIL)) */
		fprintf(stderr, "0x%lx: line 185: fvar: ARRAY(ID,INTS(INT,NIL))\n",(long)p);
#line 185 "minor.brg"
{int* ptr = (int*)malloc(sizeof(int)); *ptr = argspos; IDnew(tLOCAL+tVEC, LEFT_CHILD(p)->value.s, (void*)ptr); argspos+=4;}
		break;
	case 70: /* funcbody: NIL */
		fprintf(stderr, "0x%lx: line 189: funcbody: NIL\n",(long)p);
#line 189 "minor.brg"
{}
		break;
	case 71: /* funcbody: START(funcdecls,funcinsts) */
		fprintf(stderr, "0x%lx: line 190: funcbody: START(funcdecls,funcinsts)\n",(long)p);
#line 190 "minor.brg"
{}
		break;
	case 72: /* funcdecls: NIL */
		fprintf(stderr, "0x%lx: line 191: funcdecls: NIL\n",(long)p);
#line 191 "minor.brg"
{fprintf(yyout, pfENTER, 0); localpos = 0;}
		break;
	case 73: /* funcdecls: funcvars */
		fprintf(stderr, "0x%lx: line 192: funcdecls: funcvars\n",(long)p);
#line 192 "minor.brg"
{fprintf(yyout, pfENTER, -localpos); localpos = 0;}
		break;
	case 74: /* funcvars: ARGS(NIL,funcvar) */
		fprintf(stderr, "0x%lx: line 193: funcvars: ARGS(NIL,funcvar)\n",(long)p);
#line 193 "minor.brg"
{}
		break;
	case 75: /* funcvars: ARGS(funcvars,funcvar) */
		fprintf(stderr, "0x%lx: line 194: funcvars: ARGS(funcvars,funcvar)\n",(long)p);
#line 194 "minor.brg"
{}
		break;
	case 76: /* funcvar: NUMBER(ID,NIL) */
		fprintf(stderr, "0x%lx: line 195: funcvar: NUMBER(ID,NIL)\n",(long)p);
#line 195 "minor.brg"
{localpos-=4;int* ptr = (int*)malloc(sizeof(int)); *ptr = localpos; IDnew(tLOCAL+tINT, LEFT_CHILD(p)->value.s, (void*)ptr);}
		break;
	case 77: /* funcvar: STRING(ID,NIL) */
		fprintf(stderr, "0x%lx: line 196: funcvar: STRING(ID,NIL)\n",(long)p);
#line 196 "minor.brg"
{localpos-=4;int* ptr = (int*)malloc(sizeof(int)); *ptr = localpos; IDnew(tLOCAL+tSTR, LEFT_CHILD(p)->value.s, (void*)ptr);}
		break;
	case 78: /* funcvar: ARRAY(ID,INTS(INT,NIL)) */
		fprintf(stderr, "0x%lx: line 197: funcvar: ARRAY(ID,INTS(INT,NIL))\n",(long)p);
#line 197 "minor.brg"
{localpos-=4;int* ptr = (int*)malloc(sizeof(int)); *ptr = localpos; IDnew(tLOCAL+tVEC, LEFT_CHILD(p)->value.s, (void*)ptr);}
		break;
	case 79: /* funcinsts: NIL */
		fprintf(stderr, "0x%lx: line 198: funcinsts: NIL\n",(long)p);
#line 198 "minor.brg"
{}
		break;
	case 80: /* funcinsts: STMT(insts,ret) */
		fprintf(stderr, "0x%lx: line 199: funcinsts: STMT(insts,ret)\n",(long)p);
#line 199 "minor.brg"
{}
		break;
	case 81: /* chars: CHARS(chars,char) */
		fprintf(stderr, "0x%lx: line 202: chars: CHARS(chars,char)\n",(long)p);
#line 202 "minor.brg"
{p->place = LEFT_CHILD(p)->place;}
		break;
	case 82: /* chars: NIL */
		fprintf(stderr, "0x%lx: line 203: chars: NIL\n",(long)p);
#line 203 "minor.brg"
{char* strlbl = mklbl(++lbl); fprintf(yyout, pfRODATA pfALIGN pfLABEL, strlbl);p->place = lbl;}
		break;
	case 83: /* char: INT */
		fprintf(stderr, "0x%lx: line 204: char: INT\n",(long)p);
#line 204 "minor.brg"
{fprintf(yyout, pfCHAR, p->value.i);}
		break;
	case 84: /* char: STR */
		fprintf(stderr, "0x%lx: line 205: char: STR\n",(long)p);
#line 205 "minor.brg"
{outstrnoend(p->value.s);}
		break;
	case 85: /* char: CHAR */
		fprintf(stderr, "0x%lx: line 206: char: CHAR\n",(long)p);
#line 206 "minor.brg"
{fprintf(yyout, pfCHAR, p->value.i);}
		break;
	case 86: /* charsdecl: CHARS(charsdecl,char) */
		fprintf(stderr, "0x%lx: line 209: charsdecl: CHARS(charsdecl,char)\n",(long)p);
#line 209 "minor.brg"
{p->place = LEFT_CHILD(p)->place;}
		break;
	case 87: /* charsdecl: NIL */
		fprintf(stderr, "0x%lx: line 210: charsdecl: NIL\n",(long)p);
#line 210 "minor.brg"
{lbl++; fprintf(yyout, pfDATA pfALIGN pfLABEL, mklbl(lbl)); p->place = lbl;}
		break;
	case 88: /* exprs: ARGSLIST(expr,NIL) */
		fprintf(stderr, "0x%lx: line 212: exprs: ARGSLIST(expr,NIL)\n",(long)p);
#line 212 "minor.brg"
{p->place = 1;}
		break;
	case 89: /* exprs: ARGSLIST(expr,exprs) */
		fprintf(stderr, "0x%lx: line 213: exprs: ARGSLIST(expr,exprs)\n",(long)p);
#line 213 "minor.brg"
{p->place = 1 + RIGHT_CHILD(p)->place;}
		break;
	case 90: /* expr: FUNCALL(ID,exprs) */
		fprintf(stderr, "0x%lx: line 216: expr: FUNCALL(ID,exprs)\n",(long)p);
#line 216 "minor.brg"
{fprintf(yyout, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s),(int)(pfWORD*(RIGHT_CHILD(p)->place)));}
		break;
	case 91: /* expr: sexpr */
		fprintf(stderr, "0x%lx: line 217: expr: sexpr\n",(long)p);
#line 217 "minor.brg"
{}
		break;
	case 92: /* expr: vexpr */
		fprintf(stderr, "0x%lx: line 218: expr: vexpr\n",(long)p);
#line 218 "minor.brg"
{}
		break;
	case 93: /* expr: EQ(expr,ID) */
		fprintf(stderr, "0x%lx: line 219: expr: EQ(expr,ID)\n",(long)p);
#line 219 "minor.brg"
{saveIDfromStack(RIGHT_CHILD(p)->value.s);}
		break;
	case 94: /* expr: EQ(ADD(ID,CHARS(NIL,INT)),ID) */
		fprintf(stderr, "0x%lx: line 220: expr: EQ(ADD(ID,CHARS(NIL,INT)),ID)\n",(long)p);
#line 220 "minor.brg"
{incrementOptimization(RIGHT_CHILD(p)->value.s,RIGHT_CHILD(RIGHT_CHILD(LEFT_CHILD(p)))->value.i, PLUS);}
		break;
	case 95: /* expr: EQ(ADD(CHARS(NIL,INT),ID),ID) */
		fprintf(stderr, "0x%lx: line 221: expr: EQ(ADD(CHARS(NIL,INT),ID),ID)\n",(long)p);
#line 221 "minor.brg"
{incrementOptimization(RIGHT_CHILD(p)->value.s,RIGHT_CHILD(LEFT_CHILD(LEFT_CHILD(p)))->value.i, PLUS);}
		break;
	case 96: /* expr: EQ(SUB(ID,CHARS(NIL,INT)),ID) */
		fprintf(stderr, "0x%lx: line 222: expr: EQ(SUB(ID,CHARS(NIL,INT)),ID)\n",(long)p);
#line 222 "minor.brg"
{incrementOptimization(RIGHT_CHILD(p)->value.s,RIGHT_CHILD(RIGHT_CHILD(LEFT_CHILD(p)))->value.i, MINUS);}
		break;
	case 97: /* expr: READ */
		fprintf(stderr, "0x%lx: line 223: expr: READ\n",(long)p);
#line 223 "minor.brg"
{fprintf(yyout, pfCALL pfPUSH, "_readi");}
		break;
	case 98: /* expr: ID */
		fprintf(stderr, "0x%lx: line 224: expr: ID\n",(long)p);
#line 224 "minor.brg"
{putIntIDinStack(p->value.s);}
		break;
	case 99: /* expr: ADDR(ID) */
		fprintf(stderr, "0x%lx: line 225: expr: ADDR(ID)\n",(long)p);
#line 225 "minor.brg"
{showAddress(LEFT_CHILD(p)->value.s);}
		break;
	case 100: /* expr: SUB(expr,expr) */
		fprintf(stderr, "0x%lx: line 226: expr: SUB(expr,expr)\n",(long)p);
#line 226 "minor.brg"
{fprintf(yyout, pfSUB);}
		break;
	case 101: /* expr: ADD(expr,expr) */
		fprintf(stderr, "0x%lx: line 227: expr: ADD(expr,expr)\n",(long)p);
#line 227 "minor.brg"
{fprintf(yyout, pfADD);}
		break;
	case 102: /* vexpr: ADD(expr,vexpr) */
		fprintf(stderr, "0x%lx: line 228: vexpr: ADD(expr,vexpr)\n",(long)p);
#line 228 "minor.brg"
{fprintf(yyout, pfSWAP pfIMM pfMUL pfADD, 4);}
		break;
	case 103: /* vexpr: ADD(vexpr,expr) */
		fprintf(stderr, "0x%lx: line 229: vexpr: ADD(vexpr,expr)\n",(long)p);
#line 229 "minor.brg"
{fprintf(yyout, pfIMM pfMUL pfADD, 4);}
		break;
	case 104: /* vexpr: SUB(expr,vexpr) */
		fprintf(stderr, "0x%lx: line 230: vexpr: SUB(expr,vexpr)\n",(long)p);
#line 230 "minor.brg"
{fprintf(yyout, pfSWAP pfIMM pfMUL pfSUB, 4);}
		break;
	case 105: /* vexpr: SUB(vexpr,expr) */
		fprintf(stderr, "0x%lx: line 231: vexpr: SUB(vexpr,expr)\n",(long)p);
#line 231 "minor.brg"
{fprintf(yyout, pfIMM pfMUL pfSUB, 4);}
		break;
	case 106: /* expr: ADD(CHARS(NIL,INT),CHARS(NIL,INT)) */
		fprintf(stderr, "0x%lx: line 232: expr: ADD(CHARS(NIL,INT),CHARS(NIL,INT))\n",(long)p);
#line 232 "minor.brg"
{fprintf(yyout,pfIMM,RIGHT_CHILD(LEFT_CHILD(p))->value.i + RIGHT_CHILD(RIGHT_CHILD(p))->value.i);}
		break;
	case 107: /* expr: SUB(CHARS(NIL,INT),CHARS(NIL,INT)) */
		fprintf(stderr, "0x%lx: line 233: expr: SUB(CHARS(NIL,INT),CHARS(NIL,INT))\n",(long)p);
#line 233 "minor.brg"
{fprintf(yyout,pfIMM,RIGHT_CHILD(LEFT_CHILD(p))->value.i - RIGHT_CHILD(RIGHT_CHILD(p))->value.i);}
		break;
	case 108: /* expr: MUL(CHARS(NIL,INT),CHARS(NIL,INT)) */
		fprintf(stderr, "0x%lx: line 234: expr: MUL(CHARS(NIL,INT),CHARS(NIL,INT))\n",(long)p);
#line 234 "minor.brg"
{fprintf(yyout,pfIMM,RIGHT_CHILD(LEFT_CHILD(p))->value.i * RIGHT_CHILD(RIGHT_CHILD(p))->value.i);}
		break;
	case 109: /* expr: DIV(CHARS(NIL,INT),CHARS(NIL,INT)) */
		fprintf(stderr, "0x%lx: line 235: expr: DIV(CHARS(NIL,INT),CHARS(NIL,INT))\n",(long)p);
#line 235 "minor.brg"
{fprintf(yyout,pfIMM,RIGHT_CHILD(LEFT_CHILD(p))->value.i / RIGHT_CHILD(RIGHT_CHILD(p))->value.i);}
		break;
	case 110: /* expr: MUL(expr,expr) */
		fprintf(stderr, "0x%lx: line 236: expr: MUL(expr,expr)\n",(long)p);
#line 236 "minor.brg"
{fprintf(yyout, pfMUL);}
		break;
	case 111: /* expr: DIV(expr,expr) */
		fprintf(stderr, "0x%lx: line 237: expr: DIV(expr,expr)\n",(long)p);
#line 237 "minor.brg"
{fprintf(yyout, pfDIV);}
		break;
	case 112: /* expr: AND(and,expr) */
		fprintf(stderr, "0x%lx: line 238: expr: AND(and,expr)\n",(long)p);
#line 238 "minor.brg"
{ fprintf(yyout, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 113: /* and: expr */
		fprintf(stderr, "0x%lx: line 239: and: expr\n",(long)p);
#line 239 "minor.brg"
{ p->place = ++lbl; fprintf(yyout, pfDUP pfJZ pfTRASH, mklbl(p->place), pfWORD); }
		break;
	case 114: /* expr: OR(or,expr) */
		fprintf(stderr, "0x%lx: line 240: expr: OR(or,expr)\n",(long)p);
#line 240 "minor.brg"
{ fprintf(yyout, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 115: /* or: expr */
		fprintf(stderr, "0x%lx: line 241: or: expr\n",(long)p);
#line 241 "minor.brg"
{ p->place = ++lbl; fprintf(yyout, pfDUP pfJNZ pfTRASH, mklbl(p->place), pfWORD); }
		break;
	case 116: /* expr: NOT(expr) */
		fprintf(stderr, "0x%lx: line 242: expr: NOT(expr)\n",(long)p);
#line 242 "minor.brg"
{fprintf(yyout, pfIMM pfEQ, 0);}
		break;
	case 117: /* expr: MOD(expr,expr) */
		fprintf(stderr, "0x%lx: line 243: expr: MOD(expr,expr)\n",(long)p);
#line 243 "minor.brg"
{fprintf(yyout, pfMOD);}
		break;
	case 118: /* expr: GREATER(expr,expr) */
		fprintf(stderr, "0x%lx: line 244: expr: GREATER(expr,expr)\n",(long)p);
#line 244 "minor.brg"
{fprintf(yyout, pfGT);}
		break;
	case 119: /* expr: GREATER(sexpr,sexpr) */
		fprintf(stderr, "0x%lx: line 245: expr: GREATER(sexpr,sexpr)\n",(long)p);
#line 245 "minor.brg"
{fprintf(yyout, pfCALL pfTRASH pfPUSH pfIMM pfGT, "_strcmp", 8, 0);}
		break;
	case 120: /* expr: LESS(expr,expr) */
		fprintf(stderr, "0x%lx: line 246: expr: LESS(expr,expr)\n",(long)p);
#line 246 "minor.brg"
{fprintf(yyout, pfLT);}
		break;
	case 121: /* expr: LESS(sexpr,sexpr) */
		fprintf(stderr, "0x%lx: line 247: expr: LESS(sexpr,sexpr)\n",(long)p);
#line 247 "minor.brg"
{fprintf(yyout, pfCALL pfTRASH pfPUSH pfIMM pfLT, "_strcmp", 8, 0);}
		break;
	case 122: /* expr: EQUALS(expr,expr) */
		fprintf(stderr, "0x%lx: line 248: expr: EQUALS(expr,expr)\n",(long)p);
#line 248 "minor.brg"
{fprintf(yyout, pfEQ);}
		break;
	case 123: /* expr: EQUALS(sexpr,sexpr) */
		fprintf(stderr, "0x%lx: line 249: expr: EQUALS(sexpr,sexpr)\n",(long)p);
#line 249 "minor.brg"
{fprintf(yyout, pfCALL pfTRASH pfPUSH pfIMM pfEQ, "_strcmp", 8, 0);}
		break;
	case 124: /* expr: GE(expr,expr) */
		fprintf(stderr, "0x%lx: line 250: expr: GE(expr,expr)\n",(long)p);
#line 250 "minor.brg"
{fprintf(yyout, pfGE);}
		break;
	case 125: /* expr: GE(sexpr,sexpr) */
		fprintf(stderr, "0x%lx: line 251: expr: GE(sexpr,sexpr)\n",(long)p);
#line 251 "minor.brg"
{fprintf(yyout, pfCALL pfTRASH pfPUSH pfIMM pfGE, "_strcmp", 8, 0);}
		break;
	case 126: /* expr: LE(expr,expr) */
		fprintf(stderr, "0x%lx: line 252: expr: LE(expr,expr)\n",(long)p);
#line 252 "minor.brg"
{fprintf(yyout, pfLE);}
		break;
	case 127: /* expr: LE(sexpr,sexpr) */
		fprintf(stderr, "0x%lx: line 253: expr: LE(sexpr,sexpr)\n",(long)p);
#line 253 "minor.brg"
{fprintf(yyout, pfCALL pfTRASH pfPUSH pfIMM pfLE, "_strcmp", 8, 0);}
		break;
	case 128: /* expr: NE(expr,expr) */
		fprintf(stderr, "0x%lx: line 254: expr: NE(expr,expr)\n",(long)p);
#line 254 "minor.brg"
{fprintf(yyout, pfNE);}
		break;
	case 129: /* expr: NE(sexpr,sexpr) */
		fprintf(stderr, "0x%lx: line 255: expr: NE(sexpr,sexpr)\n",(long)p);
#line 255 "minor.brg"
{fprintf(yyout, pfCALL pfTRASH pfPUSH pfIMM pfNE, "_strcmp", 8, 0);}
		break;
	case 130: /* expr: uminus(expr) */
		fprintf(stderr, "0x%lx: line 256: expr: uminus(expr)\n",(long)p);
#line 256 "minor.brg"
{fprintf(yyout, pfNEG);}
		break;
	case 131: /* expr: POW(expr,expr) */
		fprintf(stderr, "0x%lx: line 257: expr: POW(expr,expr)\n",(long)p);
#line 257 "minor.brg"
{fprintf(yyout, pfCALL pfTRASH pfPUSH, "_power", 8);}
		break;
	case 132: /* expr: CHARS(NIL,INT) */
		fprintf(stderr, "0x%lx: line 258: expr: CHARS(NIL,INT)\n",(long)p);
#line 258 "minor.brg"
{fprintf(yyout, pfIMM, (RIGHT_CHILD(p)->value.i));}
		break;
	case 133: /* expr: CHARS(NIL,CHAR) */
		fprintf(stderr, "0x%lx: line 259: expr: CHARS(NIL,CHAR)\n",(long)p);
#line 259 "minor.brg"
{fprintf(yyout, pfIMM, (char)(RIGHT_CHILD(p)->value.i));}
		break;
	case 134: /* sexpr: CHARS(chars,char) */
		fprintf(stderr, "0x%lx: line 260: sexpr: CHARS(chars,char)\n",(long)p);
#line 260 "minor.brg"
{lbl++; fprintf(yyout, pfCHAR pfTEXT pfADDR, 0, mklbl(LEFT_CHILD(p)->place));}
		break;
	case 135: /* sexpr: ID */
		fprintf(stderr, "0x%lx: line 261: sexpr: ID\n",(long)p);
#line 261 "minor.brg"
{putSTRIDinStack(p->value.s);}
		break;
	case 136: /* expr: EQ(expr,VECTOR(expr,sexpr)) */
		fprintf(stderr, "0x%lx: line 262: expr: EQ(expr,VECTOR(expr,sexpr))\n",(long)p);
#line 262 "minor.brg"
{fprintf(yyout, pfADD pfSTCHR);}
		break;
	case 137: /* expr: VECTOR(expr,sexpr) */
		fprintf(stderr, "0x%lx: line 263: expr: VECTOR(expr,sexpr)\n",(long)p);
#line 263 "minor.brg"
{fprintf(yyout, pfADD pfLDCHR);}
		break;
	case 138: /* expr: VECTOR(expr,vexpr) */
		fprintf(stderr, "0x%lx: line 264: expr: VECTOR(expr,vexpr)\n",(long)p);
#line 264 "minor.brg"
{fprintf(yyout, pfSWAP pfIMM pfMUL pfADD pfLOAD, 4);}
		break;
	case 139: /* expr: EQ(expr,VECTOR(expr,vexpr)) */
		fprintf(stderr, "0x%lx: line 265: expr: EQ(expr,VECTOR(expr,vexpr))\n",(long)p);
#line 265 "minor.brg"
{fprintf(yyout, pfSWAP pfIMM pfMUL pfADD pfSTORE, 4);}
		break;
	case 140: /* vexpr: ID */
		fprintf(stderr, "0x%lx: line 266: vexpr: ID\n",(long)p);
#line 266 "minor.brg"
{putVecIDinStack(p->value.s);}
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yyfile == 0) {
		fprintf(stderr, "No match for start symbol (%s).\n", yyntname[1]);
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 267 "minor.brg"


/*%! expr:POW(expr,expr)                 1 {lbl++; char* powlbl = mklbl(lbl);lbl++; char* startlbl = mklbl(lbl); lbl++; char* endlbl = mklbl(lbl); fprintf(yyout,pfBSS pfALIGN pfLABEL pfTEXT pfADDRA,powlbl,powlbl); fprintf(yyout,pfIMM pfSWAP pfIMM pfADD pfSWAP pfTEXT pfLABEL pfSWAP pfIMM pfSUB pfDUP pfJZ pfSWAP pfADDRV pfMUL pfJMP pfLABEL pfTRASH,1,1, startlbl, 1, endlbl, powlbl, startlbl, endlbl,pfWORD);}
*/

extern char **yynames;
extern int trace, errors, debugNode;


void printNode2(Node *p){
	printNode(p,0,yynames);
}

void externs(){
  int i;
  
  for (i = 0; i < extcnt; i++)
    if (extrns[i])
      fprintf(yyout, pfEXTRN, extrns[i]);
}

void manageExterns(char* name){
	int i;
	for(i = 0; i < extcnt; i++){
			if (extrns[i] && strcmp(extrns[i], name) == 0) extrns[i] = 0;
		}
	}


void evaluate(Node *p) {
	if (errors) return;
	/* if (trace) */ printNode(p, stdout, yynames);
	/*printNode2(p);*/
	if (!yyselect(p) && trace) printf("selection successful\n");
	/*printNode2(p);*/
	fprintf(yyout, pfEXTRN pfEXTRN pfEXTRN pfEXTRN, "_prints", "_println", "_printi", "_readi");
	fprintf(yyout, pfEXTRN, "_power");
	fprintf(yyout, pfEXTRN, "_strcmp");
	externs();
}

void putIntIDinStack(char* name){
	printf("O ID que vai ser carregado é %s\n", name);
	int* ptr;
	/*void** ptr*/
	int local;
	/*IDprint(0,2);*/
	int info = 0;
	/*info = IDfind(name,ptr);*/
	info = IDfind(name,(void**)&ptr);
	if(info&tFUNC){
		fprintf(yyout, pfCALL pfPUSH, mkfunc(name));
	}
	else if(info&tLOCAL){
		/*local = *((int*)ptr[0]);*/
		local = *ptr;
		printf("No load a variavel %s tem %d\n",name, local);
		fprintf(yyout, pfLOCV,  local);
	}
	else{
		printf("No load a variavel %s é global\n",name);
		fprintf(yyout, pfADDR pfLOAD, name);
	}
}

void saveIDfromStack(char* name){
    printf("O ID que vai ser guardado é %s\n", name);
	/*void** ptr;*/
	int* ptr;
	int local;
	int info;
	/*info = IDfind(name,ptr);*/
	info = IDfind(name,(void**)&ptr);
	IDprint(0,2);
  fprintf(yyout,pfDUP);
	if(info&tLOCAL){
		/*local = *((int*)ptr[0]);*/
		local = *ptr;
		printf("No save a variavel %s tem %d\n",name, local);
		fprintf(yyout, pfLOCA, local);
	}
	else{
		printf("No save a variavel %s é global\n",name);
		fprintf(yyout, pfADDRA, name);
	}
}

void VectorInit(int length, int place){
  int i;
  if(length > place){
    for(i = place; i < length; i++){
      fprintf(yyout, pfINTEGER, 0);
    }
  }
  fprintf(yyout, pfDATA pfTEXT);
}



void putVecIDinStack(char* name){
	/*void** ptr;*/
	int* ptr;
	int local;
	/*int info = IDfind(name,ptr);*/
	int info = IDfind(name,(void**)&ptr);
	if(info&tFUNC){
		fprintf(yyout, pfCALL pfPUSH, name);
	}
	else if(info&tLOCAL){
		local = *ptr;
		/*local = *((int*)ptr[0]);*/
		printf("A variavel %s tem %d\n",name, local);
		fprintf(yyout, pfLOCV,  local);
	}
	else{
		fprintf(yyout, pfADDRV, name);
	}
}

void putSTRIDinStack(char* name){
	/*void** ptr;*/
	int* ptr;
	int local;
	/*int info = IDfind(name,ptr);*/
	int info = IDfind(name, (void**)&ptr);
	if(info&tFUNC){
		fprintf(yyout, pfCALL pfPUSH, name);
	}
	else if(info&tLOCAL){
		/*local = *((int*)ptr[0]);*/
		local = *ptr;
		printf("A variavel %s tem %d\n",name, local);
		fprintf(yyout, pfLOCV,  local);
	}
	else{
		fprintf(yyout, pfADDRV, name);
	}
}

void createVecWithLength(char* name, int length, int info){
	if(!(info&tFWD)){
		if(length != 0){
			lbl++;
			fprintf(yyout,pfBSS pfLABEL pfBYTE, mklbl(lbl), 4*length);
			fprintf(yyout,pfDATA);
			publicInitialization(name,info);
			fprintf(yyout, pfID pfTEXT, mklbl(lbl));
		}
		else{
			fprintf(yyout, pfBSS  pfALIGN);
			publicInitialization(name, info);
			fprintf(yyout, pfBYTE pfTEXT, pfWORD);
		}
	}
	else{
		extrns[extcnt++] = strdup(name);
	}
}


void incrementOptimization(char* name, int value, int sign){
  int* ptr;
  int local;
  int info = IDfind(name, (void**)&ptr);
  int inc = value;
  printf("O tipo do variavel é %d\n",info);
  printf("O value é value %d\n",value);
  if(info&tLOCAL){
    local = *ptr;
    fprintf(yyout, pfLOCAL, local);
  }
  else{
    fprintf(yyout, pfADDR, name);
  }
  if(tTYPE(info)==tVEC){
    printf("Entra aqui");
    inc = 4*inc;
  }
  fprintf(yyout,pfDUP);
  (sign == PLUS)?fprintf(yyout, pfINCR, inc):fprintf(yyout, pfDECR, inc);
   if(info&tLOCAL){
    local = *ptr;
    fprintf(yyout, pfLOCV, local);
  }
  else{
    fprintf(yyout, pfADDRV, name);
  }
}


void showAddress(char* name){
  int* ptr;
  int  local;
  int info = IDfind(name,(void**)&ptr);
  if(info&tLOCAL){
    local = *ptr;
    fprintf(yyout, pfLOCAL, local);
  }
  else{
    fprintf(yyout, pfADDR, name);
  }
}


void allocVECSTR(char* name){
	int* ptr;
	int local;
	int info = IDfind(name, (void**)&ptr);
	if(info&tLOCAL){
		local = *ptr;
		if(tTYPE(info)&tVEC){
			fprintf(yyout, pfIMM pfMUL pfALLOC pfSP,4);
		}
		else{
			fprintf(yyout, pfALLOC pfSP);
		}
		fprintf(yyout, pfLOCAL pfSTORE, local);
	}
	else{
		if(tTYPE(info)&tVEC){
			fprintf(yyout, pfIMM pfMUL pfALLOC pfSP,4);
		}
		else{
			fprintf(yyout, pfALLOC pfSP);
		}
		fprintf(yyout, pfADDR pfSTORE, name);
	}
}

/*void vectorSaveElement(char* name){
	void** ptr;
	int local;
	int info = IDfind(name,ptr);
	if(info&tLOCAL){
		local = *((int*)ptr[0]);
		if(tTYPE(info)==tVEC){
			fprintf(yyout,pfIMM pfMUL pfLOCAL pfLOAD pfSTORE,pfWORD, local);
		}
		else if(tTYPE(info)==tSTR){
			fprintf(yyout, pfLOCAL pfLOAD pfADD pfSTCHR, local );
		}
	}
	else{
		if(tTYPE(info)==tVEC){
			fprintf(yyout, pfIMM pfMUL pfADDR pfLOAD pfADD pfSTORE,pfWORD,name);
		}
		else if(tTYPE(info)==tSTR){
			fprintf(yyout, pfADDR pfLOAD pfADD pfSTCHR, name);
		}
	}
}

void vectorLoadElement(char* name){

	void** ptr;
	int local;
	int info = IDfind(name,ptr);
	if(info&tLOCAL){
		local = *((int*)ptr[0]);
		if(tTYPE(info)==tVEC){
			fprintf(yyout,pfIMM pfMUL pfLOCAL pfLOAD pfLOAD,pfWORD, local);
		}
		else if(tTYPE(info)==tSTR){
			fprintf(yyout, pfLOCAL pfLOAD pfADD pfLDCHR, local);
		}
	}
	else{
		if(tTYPE(info)==tVEC){
			fprintf(yyout, pfIMM pfMUL pfADDR pfLOAD pfADD pfLOAD,pfWORD,name);
		}
		else if(tTYPE(info)==tSTR){
			fprintf(yyout, pfADDR pfLOAD pfADD pfLDCHR, name);
		}
	}
}*/




void publicInitialization(char* name, int info){
	if(info&tPUB){
		fprintf(yyout,pfGLOBL, name, pfOBJ);
	}
	fprintf(yyout,pfLABEL,name);
}

void constInitialization(int info){
	if(info&tCNST){
		fprintf(yyout, pfRODATA pfALIGN);
	}
	else{
		fprintf(yyout, pfDATA pfALIGN);
	}
}


/*void function(char *name, int enter, Node *stmt)
{
  int i;
  extern int errors, trace;
  extern char **yynames;
  if (errors) return;
  if (trace) printNode(stmt, 0, yynames);
  fflush(stdout);
  fprintf(yyout, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, mkfunc(name), pfFUNC, mkfunc(name), enter * (pfWORD/4));
  yyselect(stmt);
  fprintf(yyout, pfLEAVE pfRET);
  freeNode(stmt);
  for (i = 0; i < extcnt; i++)
    if (extrns[i] && strcmp(extrns[i], mkfunc(name)) == 0) extrns[i] = 0;
}*/


#ifndef NOTRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	if (debugNode) fprintf(stderr, "0x%p:%s matched %s with cost %d vs. %d\n", p, tname, yystring[eruleno], cost, bestcost);
	if (cost >= MAX_COST && bestcost >= MAX_COST) {
		fprintf(stderr, "0x%p:%s NO MATCH %s with cost %d vs. %d\n", p, tname, yystring[eruleno], cost, bestcost);
		printNode(p, stderr, yynames);
	}
}
#endif
