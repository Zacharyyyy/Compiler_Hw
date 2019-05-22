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

#line 3 "compiler_hw2.y"
#include <stdio.h>
#include <string.h>
#define t_size 64

extern int yylineno;
extern int yylex();
extern char* yytext;   /* Get current token from lex*/
extern char buf[256];  /* Get current code line from lex*/

/* Symbol table function - you can add new function if needed. */
int lookup_symbol();
void create_symbol();
void insert_symbol();
void dump_symbol();

struct Table{
    int flag;
    char name[20];
    char kind[20];
    char type[20];
    int scope;
    char attribute[30];
};

struct Table sym_tab[t_size];
int sym_tab_idx = 0;
int Scope = 0;
int dec_flag = 0; /* if current line is a declare line, '1'*/
int uflag;

char dec_name[20] = {0};/* declared name*/

#line 40 "compiler_hw2.y"
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
#line 67 "y.tab.c"

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    5,    5,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    1,    1,   16,   16,   17,
   17,   18,   18,   18,   18,   18,   15,   15,   15,   14,
   14,   14,   14,   12,   12,   10,   10,   10,    2,   11,
   20,   20,   21,   21,   21,   22,   22,   22,   22,   22,
   22,    3,    3,    7,    7,    8,    8,   24,   24,   25,
   25,   26,   26,   28,   30,   30,   30,   29,   29,   29,
   29,   29,   29,   29,   29,   23,   23,   23,   23,   23,
   23,   31,   31,   27,   27,   27,    9,    9,   13,   19,
   19,   19,   19,   19,   19,    4,    4,    4,    4,    4,
};
static const YYINT yylen[] = {                            2,
    2,    0,    2,    0,    1,    1,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    3,    3,    1,    3,    1,
    3,    1,    1,    1,    1,    1,    4,    4,    4,    3,
    2,    3,    3,    7,   11,    9,    8,    9,    6,    5,
    2,    0,    2,    3,    0,    1,    1,    1,    1,    1,
    1,    2,    3,    2,    3,    3,    1,    3,    1,    1,
    1,    3,    1,    2,    2,    2,    0,    3,    1,    1,
    1,    1,    2,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    5,    5,    7,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         2,
    4,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   71,   72,   70,   96,   99,   97,   98,  100,    5,   10,
    0,    3,    6,    0,    8,    9,   11,   12,   13,   14,
   15,    0,    0,   63,   67,    0,    0,    0,   45,   90,
   91,   92,   93,   94,   95,    0,   73,   74,   69,    0,
   54,    0,   31,    0,    0,    0,    0,    0,    0,   18,
   76,   77,   78,   79,   80,   81,    7,    0,   60,   61,
    0,   84,   85,   86,    0,    0,    0,    0,    0,    0,
    0,    0,   25,   26,    0,    0,    0,    0,    0,   68,
   55,   32,   33,   30,   42,    0,   17,    0,   16,    0,
    0,    0,   62,   65,   66,    0,    0,    0,    0,   46,
    0,    0,   50,   51,   47,   48,   49,   43,   28,   29,
   27,    0,   22,   23,   24,   21,    0,   19,   88,   87,
    4,    0,   40,   44,    0,   41,    0,    0,    0,    0,
   39,    0,    0,   89,    0,    0,    0,   53,    0,    0,
    0,   37,    4,   38,   36,    0,   35,
};
static const YYINT yydgoto[] = {                          1,
   19,   20,  136,   21,    2,   22,   23,   24,   25,   26,
   27,   28,   29,   30,   31,   59,   60,   89,   46,  122,
   81,  118,   68,   32,   71,   33,   75,   34,   35,   76,
    0,
};
static const YYINT yysindex[] = {                         0,
    0, -164, -253, -251, -248,  -46, -254,  -31, -270,   16,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   13,    0,    0,   15,    0,    0,    0,    0,    0,    0,
    0, -189, -206,    0,    0, -259,  -31,  -31,    0,    0,
    0,    0,    0,    0,    0, -174,    0,    0,    0,  286,
    0, -252,    0, -247, -240,  239, -271,  245, -187,    0,
    0,    0,    0,    0,    0,    0,    0,  -31,    0,    0,
  -31,    0,    0,    0,  -31, -151, -190, -180,  296,  306,
  -65, -227,    0,    0,    0,    0,    0,  259, -198,    0,
    0,    0,    0,    0,    0, -119,    0, -170,    0,   61,
 -189, -206,    0,    0,    0, -182, -168, -177, -167,    0,
 -140, -171,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -132,    0,    0,    0,    0, -166,    0,    0,    0,
    0, -164,    0,    0, -267,    0, -114, -223, -130, -272,
    0, -129, -105,    0, -164, -141, -123,    0, -121, -117,
 -116,    0,    0,    0,    0, -194,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,  162,    0,    0,    0,   76,    0,    0, -112,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   89,    0,    0,    0,    0,    0,    0,
    0,  206,  170,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   89,
    0,    0,    0,    0,    0,   89,   55,   89,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  153,    0,    0,   89,   89,
    0,  280,    0,    0,   97,  118,  139,   89,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -246,
  225,  187,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -149,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -51,
    0,  -83,    1,    0,    0,    0,    0,    0,    0, -101,
    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,   45,   -9,   37,   38,   -6,    0,    0,
    0,    0,    0,  -74,    0,    0,   85,   90,    0,    0,
    0,   73,    0,  140,    0,  138,    0,  137,    0,    0,
    0,
};
#define YYTABLESIZE 585
static const YYINT yytable[] = {                         52,
   34,   50,   77,   56,    3,    4,   95,    9,    5,    6,
   51,    7,  140,   96,   58,  141,   75,   75,   75,   75,
   75,   75,   75,   10,   36,    8,   37,    9,   91,   38,
   79,   80,   75,    3,    4,   92,   75,    5,    6,   88,
    7,   78,   93,   10,   47,   48,   11,   12,   13,   14,
   15,   16,   17,   18,    8,  119,    9,  143,   72,   73,
   74,  100,    3,    4,  100,  147,    5,    6,  100,    7,
  150,  151,   10,   69,   70,   11,   12,   13,   14,   15,
   16,   17,   18,    8,  121,    9,  157,   82,  106,    7,
  110,  127,    3,    4,   98,   99,    5,    6,  107,    7,
  129,   10,  131,    8,   11,   12,   13,   14,   15,   16,
   17,   18,  132,    8,  130,    9,  104,  105,   96,   83,
   84,  138,  113,  114,   85,   86,   87,  115,  116,  117,
  145,   10,   20,   20,   11,   12,   13,   14,   15,   16,
   17,   18,  133,  156,    4,    4,  135,  142,    4,    4,
  144,    4,  148,  149,   10,   14,   14,  152,  153,   14,
   14,    1,   14,  154,  155,    4,  137,    4,  139,   14,
   15,   16,   17,   18,   83,   84,   14,  146,   14,  123,
  124,  125,  128,    4,  134,  126,    4,    4,    4,    4,
    4,    4,    4,    4,   14,   52,  110,   14,   14,   14,
   14,   14,   14,   14,   14,    4,    4,  101,  102,    4,
    4,  103,    4,  111,    0,    0,  112,    0,   52,   52,
   52,   52,   52,    0,    0,    0,    4,    0,  113,  114,
   49,   39,    7,  115,  116,  117,    0,    0,   40,   41,
   42,   43,   44,   45,    0,    0,    8,    4,    4,    4,
    4,    4,    4,    4,    4,    0,    0,   34,   34,    0,
    0,   34,   34,    0,   34,    0,    0,   11,   12,   13,
    0,    0,    0,    0,   57,    0,    7,   49,   34,    7,
   34,   34,    0,    0,   61,   62,   63,   64,   65,   66,
    8,    0,    0,    8,    0,    0,   34,   67,   53,   34,
   34,   34,   34,   34,   34,   34,   34,    0,    0,   54,
   55,   11,   12,   13,   11,   12,   13,   69,   69,   69,
   69,   69,   69,   69,   69,   69,   69,   69,   69,   69,
   61,   62,   63,   64,   65,   66,   20,   20,   69,   69,
   69,   69,   69,   69,   69,   69,   69,   69,   69,   69,
   69,   75,   75,   75,   75,   75,   75,   75,   69,   71,
   71,   71,   71,   71,   71,   71,   71,   71,   71,   71,
   71,   71,    0,    0,    0,    0,    0,    0,    0,   22,
   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
   72,   72,   72,    0,    0,    0,    0,    0,    0,    0,
   23,   70,   70,   70,   70,   70,   70,   70,   70,   70,
   70,   70,   70,   70,    0,   64,   64,   64,   64,   64,
    0,   24,   64,   64,   64,   64,   64,   64,    0,    0,
    0,   64,   59,   59,    0,   64,    0,   59,   59,   59,
   59,   59,   59,   59,   59,    0,    0,    0,   59,   58,
   58,    0,   59,    0,   58,   58,   58,   58,   58,   58,
   58,   58,    0,    0,    0,   58,    0,    0,    0,   58,
   57,   57,   57,   57,   57,   57,   57,   57,   57,   57,
   57,    0,    0,    0,   57,    0,    0,    0,   57,   56,
   56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
    0,    0,    0,   56,    0,    0,    0,   56,   61,   62,
   63,   64,   65,   66,   61,   62,   63,   64,   65,   66,
    0,   94,    0,    0,    0,    0,    0,   97,   61,   62,
   63,   64,   65,   66,    0,    0,    0,    0,    0,    0,
    0,  120,   69,   69,   69,   69,   69,   69,   69,   69,
   69,   69,   69,   69,   69,   61,   62,   63,   64,   65,
   66,    0,    0,    0,   90,   61,   62,   63,   64,   65,
   66,    0,    0,    0,  108,   61,   62,   63,   64,   65,
   66,    0,    0,    0,  109,
};
static const YYINT yycheck[] = {                          9,
    0,    8,  262,   10,  257,  258,  278,  280,  261,  262,
  281,  264,  280,  285,   21,  283,  263,  264,  265,  266,
  267,  268,  269,  296,  278,  278,  278,  280,  281,  278,
   37,   38,  279,  257,  258,  283,  283,  261,  262,   46,
  264,  301,  283,  296,  299,  300,  299,  300,  301,  302,
  303,  304,  305,  306,  278,  283,  280,  281,  265,  266,
  267,   68,  257,  258,   71,  140,  261,  262,   75,  264,
  145,  146,  296,  263,  264,  299,  300,  301,  302,  303,
  304,  305,  306,  278,  283,  280,  281,  262,  279,  264,
  262,  262,  257,  258,  282,  283,  261,  262,  279,  264,
  283,  296,  280,  278,  299,  300,  301,  302,  303,  304,
  305,  306,  280,  278,  283,  280,  268,  269,  285,  294,
  295,  131,  294,  295,  299,  300,  301,  299,  300,  301,
  140,  296,  282,  283,  299,  300,  301,  302,  303,  304,
  305,  306,  283,  153,  257,  258,  279,  262,  261,  262,
  281,  264,  282,  259,  296,  257,  258,  281,  280,  261,
  262,    0,  264,  281,  281,  278,  122,  280,  132,  302,
  303,  304,  305,  306,  294,  295,  278,  140,  280,  299,
  300,  301,   98,  296,  112,   96,  299,  300,  301,  302,
  303,  304,  305,  306,  296,  279,  262,  299,  300,  301,
  302,  303,  304,  305,  306,  257,  258,   68,   71,  261,
  262,   75,  264,  279,   -1,   -1,  282,   -1,  302,  303,
  304,  305,  306,   -1,   -1,   -1,  278,   -1,  294,  295,
  262,  278,  264,  299,  300,  301,   -1,   -1,  285,  286,
  287,  288,  289,  290,   -1,   -1,  278,  299,  300,  301,
  302,  303,  304,  305,  306,   -1,   -1,  257,  258,   -1,
   -1,  261,  262,   -1,  264,   -1,   -1,  299,  300,  301,
   -1,   -1,   -1,   -1,  262,   -1,  264,  262,  278,  264,
  280,  281,   -1,   -1,  270,  271,  272,  273,  274,  275,
  278,   -1,   -1,  278,   -1,   -1,  296,  283,  283,  299,
  300,  301,  302,  303,  304,  305,  306,   -1,   -1,  294,
  295,  299,  300,  301,  299,  300,  301,  263,  264,  265,
  266,  267,  268,  269,  270,  271,  272,  273,  274,  275,
  270,  271,  272,  273,  274,  275,  282,  283,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,
  275,  263,  264,  265,  266,  267,  268,  269,  283,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  283,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  283,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  273,  274,  275,   -1,  263,  264,  265,  266,  267,
   -1,  283,  270,  271,  272,  273,  274,  275,   -1,   -1,
   -1,  279,  263,  264,   -1,  283,   -1,  268,  269,  270,
  271,  272,  273,  274,  275,   -1,   -1,   -1,  279,  263,
  264,   -1,  283,   -1,  268,  269,  270,  271,  272,  273,
  274,  275,   -1,   -1,   -1,  279,   -1,   -1,   -1,  283,
  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,
  275,   -1,   -1,   -1,  279,   -1,   -1,   -1,  283,  265,
  266,  267,  268,  269,  270,  271,  272,  273,  274,  275,
   -1,   -1,   -1,  279,   -1,   -1,   -1,  283,  270,  271,
  272,  273,  274,  275,  270,  271,  272,  273,  274,  275,
   -1,  283,   -1,   -1,   -1,   -1,   -1,  283,  270,  271,
  272,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  283,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  273,  274,  275,  270,  271,  272,  273,  274,
  275,   -1,   -1,   -1,  279,  270,  271,  272,  273,  274,
  275,   -1,   -1,   -1,  279,  270,  271,  272,  273,  274,
  275,   -1,   -1,   -1,  279,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 306
#define YYUNDFTOKEN 340
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"PRINT","IF","ELSE","FOR","WHILE",
"ID","ADD","SUB","MUL","DIV","MOD","INC","DEC","MT","LT","MTE","LTE","EQ","NE",
"LSB","RSB","LB","RB","LCB","RCB","COMMA","SEMICOLON","QUOTA","ASGN","ADDASGN",
"SUBASGN","MULASGN","DIVASGN","MODASGN","AND","OR","NOT","TRUE","FALSE","RET",
"CONT","BREAK","I_CONST","F_CONST","STR_CONST","INT","STRING","FLOAT","BOOL",
"VOID",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : program stat_list",
"program :",
"stat_list : stat_list stat",
"stat_list :",
"stat : init_declarator",
"stat : compound_stat",
"stat : exp SEMICOLON",
"stat : print_func",
"stat : func_def",
"stat : func_declaration",
"stat : func_usage",
"stat : selection_stat",
"stat : iteration_stat",
"stat : return_state",
"stat : asign_state",
"init_declarator : Type init_declarator_list SEMICOLON",
"init_declarator : Type exp SEMICOLON",
"init_declarator_list : vars",
"init_declarator_list : init_declarator_list COMMA vars",
"vars : ID",
"vars : ID ASGN initializer",
"initializer : I_CONST",
"initializer : F_CONST",
"initializer : STR_CONST",
"initializer : TRUE",
"initializer : FALSE",
"asign_state : ID asgn_type initializer SEMICOLON",
"asign_state : ID asgn_type ID SEMICOLON",
"asign_state : ID asgn_type exp SEMICOLON",
"return_state : RET exp SEMICOLON",
"return_state : RET SEMICOLON",
"return_state : RET TRUE SEMICOLON",
"return_state : RET FALSE SEMICOLON",
"selection_stat : IF LB exp RB LCB stat_list RCB",
"selection_stat : IF LB exp RB LCB stat_list RCB ELSE LCB stat_list RCB",
"func_def : Type ID LB para_list RB LCB compound_stat return_state RCB",
"func_def : Type ID LB para_list RB LCB return_state RCB",
"func_def : Type ID LB para_list RB LCB stat_list return_state RCB",
"func_declaration : Type ID LB para_list RB SEMICOLON",
"func_usage : ID LB aug_list RB SEMICOLON",
"para_list : para_list para_declaration",
"para_list :",
"aug_list : aug_list aug",
"aug_list : aug_list COMMA aug",
"aug_list :",
"aug : ID",
"aug : I_CONST",
"aug : F_CONST",
"aug : STR_CONST",
"aug : TRUE",
"aug : FALSE",
"para_declaration : Type ID",
"para_declaration : Type ID COMMA",
"compound_stat : LCB RCB",
"compound_stat : LCB stat_list RCB",
"exp : exp comparison ad_exp",
"exp : ad_exp",
"ad_exp : ad_exp addition mul_exp",
"ad_exp : mul_exp",
"addition : ADD",
"addition : SUB",
"mul_exp : mul_exp multiplication postfix_exp",
"mul_exp : postfix_exp",
"postfix_exp : term postfix",
"postfix : postfix INC",
"postfix : postfix DEC",
"postfix :",
"term : LB exp RB",
"term : ID",
"term : STR_CONST",
"term : I_CONST",
"term : F_CONST",
"term : SUB I_CONST",
"term : SUB F_CONST",
"term : exp",
"comparison : MT",
"comparison : LT",
"comparison : MTE",
"comparison : LTE",
"comparison : EQ",
"comparison : NE",
"operation : addition",
"operation : multiplication",
"multiplication : MUL",
"multiplication : DIV",
"multiplication : MOD",
"print_func : PRINT LB STR_CONST RB SEMICOLON",
"print_func : PRINT LB ID RB SEMICOLON",
"iteration_stat : WHILE LB exp RB LCB stat RCB",
"asgn_type : ASGN",
"asgn_type : ADDASGN",
"asgn_type : SUBASGN",
"asgn_type : MULASGN",
"asgn_type : DIVASGN",
"asgn_type : MODASGN",
"Type : INT",
"Type : FLOAT",
"Type : BOOL",
"Type : STRING",
"Type : VOID",

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
#line 292 "compiler_hw2.y"

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;

    create_symbol();
    yyparse();
	printf("\nTotal lines: %d \n",yylineno);

    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol() {
    //initailize the symbal table
    for(int i; i < t_size; ++i){
        memset(sym_tab[i].name, 0, strlen(sym_tab[i].name));
        memset(sym_tab[i].kind, 0, strlen(sym_tab[i].kind));
        memset(sym_tab[i].kind, 0, strlen(sym_tab[i].kind));
        memset(sym_tab[i].attribute, 0, strlen(sym_tab[i].attribute));
        sym_tab[i].scope = 0;
        sym_tab[i].flag = 0;
    }
}

void insert_symbol(int kind, char name_type[], int s) {
    //kind: 0=func, 1=var, 2=para
    char name[20] = {0};
    char type[20] = {0};

    // function
    if(!strcmp(type , "0")){
        char attr[30] = {0};
        sscanf(name_type, "%s %s", type, name);
        int sn = 0, i = 0;
        while(sn , 2){
            if(name_type[i] == ' ')
                ++sn;
            ++i;
        }
        strncpy(attr, name_type, strlen(name_type));
        sprintf(sym_tab[sym_tab_idx].name, "%s", name);
        sprintf(sym_tab[sym_tab_idx].type, "%s", type);
        sprintf(sym_tab[sym_tab_idx].kind, "%s", "function");
        sym_tab[sym_tab_idx].scope = s;
        sprintf(sym_tab[sym_tab_idx].attribute, "%s", attr);
    }
    // variable
    else if(!strcmp(type, "1")){
        sscanf(name_type, "%s %s", type, name);
        sprintf(sym_tab[sym_tab_idx].name, "%s", name);
        sprintf(sym_tab[sym_tab_idx].type, "%s", type);
        sprintf(sym_tab[sym_tab_idx].kind, "%s", "variable");
        sym_tab[sym_tab_idx].scope = s;
    }
    // else
    else{
        sscanf(name_type, "%s %s", type, name);
        sprintf(sym_tab[sym_tab_idx].name, "%s", name);
        sprintf(sym_tab[sym_tab_idx].type, "%s", type);
        sprintf(sym_tab[sym_tab_idx].kind, "%s", "parameter");
        sym_tab[sym_tab_idx].scope = s;
    }

    ++sym_tab_idx;
}

int lookup_symbol() {}
void dump_symbol() {
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
}

#line 610 "y.tab.c"

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
case 5:
#line 92 "compiler_hw2.y"
	{ insert_symbol(1, yystack.l_mark[0].string, Scope);
                        dec_flag = 1;
                    }
break;
case 10:
#line 99 "compiler_hw2.y"
	{ insert_symbol(0, yystack.l_mark[0].string, Scope);
                        dec_flag = 1;
                    }
break;
case 52:
#line 190 "compiler_hw2.y"
	{ insert_symbol(2, yystack.l_mark[-1].string, Scope+1);
                }
break;
case 53:
#line 192 "compiler_hw2.y"
	{ insert_symbol(2, yystack.l_mark[-2].string, Scope+1);

    }
break;
case 96:
#line 283 "compiler_hw2.y"
	{yyval.string=yystack.l_mark[0].string;}
break;
case 97:
#line 284 "compiler_hw2.y"
	{yyval.string=yystack.l_mark[0].string;}
break;
case 98:
#line 285 "compiler_hw2.y"
	{yyval.string=yystack.l_mark[0].string;}
break;
case 99:
#line 286 "compiler_hw2.y"
	{yyval.string=yystack.l_mark[0].string;}
break;
case 100:
#line 287 "compiler_hw2.y"
	{yyval.string=yystack.l_mark[0].string;}
break;
#line 855 "y.tab.c"
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
