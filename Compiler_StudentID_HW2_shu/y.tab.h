#define PRINT 257
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define ADD 262
#define SUB 263
#define MUL 264
#define DIV 265
#define MOD 266
#define INC 267
#define DEC 268
#define MT 269
#define LT 270
#define MTE 271
#define LTE 272
#define EQ 273
#define NE 274
#define LSB 275
#define RSB 276
#define LB 277
#define RB 278
#define LCB 279
#define RCB 280
#define COMMA 281
#define SEMICOLON 282
#define QUOTA 283
#define ASGN 284
#define ADDASGN 285
#define SUBASGN 286
#define MULASGN 287
#define DIVASGN 288
#define MODASGN 289
#define AND 290
#define OR 291
#define NOT 292
#define TRUE 293
#define FALSE 294
#define RET 295
#define CONT 296
#define BREAK 297
#define I_CONST 298
#define F_CONST 299
#define STR_CONST 300
#define INT 301
#define STRING 302
#define FLOAT 303
#define BOOL 304
#define VOID 305
#define ID 306
#define para_declaration 307
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
