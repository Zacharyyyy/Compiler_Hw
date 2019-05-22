#define PRINT 257
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define ID 262
#define ADD 263
#define SUB 264
#define MUL 265
#define DIV 266
#define MOD 267
#define INC 268
#define DEC 269
#define MT 270
#define LT 271
#define MTE 272
#define LTE 273
#define EQ 274
#define NE 275
#define LSB 276
#define RSB 277
#define LB 278
#define RB 279
#define LCB 280
#define RCB 281
#define COMMA 282
#define SEMICOLON 283
#define QUOTA 284
#define ASGN 285
#define ADDASGN 286
#define SUBASGN 287
#define MULASGN 288
#define DIVASGN 289
#define MODASGN 290
#define AND 291
#define OR 292
#define NOT 293
#define TRUE 294
#define FALSE 295
#define RET 296
#define CONT 297
#define BREAK 298
#define I_CONST 299
#define F_CONST 300
#define STR_CONST 301
#define INT 302
#define STRING 303
#define FLOAT 304
#define BOOL 305
#define VOID 306
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int i_val;
    double f_val;
    char* string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
