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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int i; char *s; Node *n; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
