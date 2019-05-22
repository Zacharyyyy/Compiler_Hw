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
extern int new_scope;
extern int scope_line;

/* Symbol table function - you can add new function if needed. */
int lookup_symbol();
void create_symbol();
void insert_symbol();
void dump_symbol();
void increase_scope();

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
int where_in_table[t_size] = {0};
int dec_flag = 0; /* if current line is a declare line, '1'*/
int uflag;

char dec_name[20] = {0};/* declared name*/

#line 44 "compiler_hw2.y"
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
#line 71 "y.tab.c"

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    7,    7,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    1,    1,    6,    6,    5,
    5,   18,   18,   18,   18,   18,   17,   17,   17,   16,
   16,   16,   16,   14,   14,   12,   12,   12,   12,   12,
   12,    2,   13,    4,    4,   20,   20,   20,   21,   21,
   21,   21,   21,   21,    9,    9,   10,   10,   23,   23,
   24,   24,   25,   25,   27,   29,   29,   29,   28,   28,
   28,   28,   28,   28,   28,   28,   22,   22,   22,   22,
   22,   22,   30,   30,   26,   26,   26,   11,   11,   15,
   19,   19,   19,   19,   19,   19,    3,    3,    3,    3,
    3,
};
static const YYINT yylen[] = {                            2,
    2,    0,    2,    0,    1,    1,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    3,    5,    1,    3,    1,
    3,    1,    1,    1,    1,    1,    4,    4,    4,    3,
    2,    3,    3,    7,   11,    9,    8,    9,    8,    8,
    7,    6,    5,    4,    2,    2,    3,    0,    1,    1,
    1,    1,    1,    1,    2,    3,    3,    1,    3,    1,
    1,    1,    3,    1,    2,    2,    2,    0,    3,    1,
    1,    1,    1,    2,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    5,    5,    7,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,
};
static const YYINT yydefred[] = {                         2,
    4,    0,    0,    0,    0,    0,    0,    0,    0,   72,
   73,   71,   97,  100,   98,   99,  101,    0,    5,   10,
    0,    3,    6,    0,    8,    9,   11,   12,   13,   14,
   15,    0,    0,   64,   68,    0,    0,    0,   74,   75,
   70,    0,   55,    0,   31,    0,    0,    0,   48,   91,
   92,   93,   94,   95,   96,    0,    0,   18,    0,   77,
   78,   79,   80,   81,   82,    7,    0,   61,   62,    0,
   85,   86,   87,    0,    0,    0,    0,    0,    0,   69,
   56,   32,   33,   30,    0,   25,   26,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   16,    0,    0,    0,
   63,   66,   67,    0,    0,    0,    0,    0,    0,   53,
   54,   50,   51,   52,   49,   46,   28,   29,   27,    0,
    0,    0,    0,   21,    0,   19,   88,   89,    4,    0,
   43,   47,    0,    0,    0,   17,    0,    0,    0,    0,
    0,    0,    0,    0,   42,   22,   23,   24,    0,   90,
    0,    0,   41,   44,    0,    0,    0,    0,   40,   39,
    0,    0,   37,    4,   38,   36,    0,   35,
};
static const YYINT yydgoto[] = {                          1,
   19,   20,   21,  122,   58,   59,    2,   22,   23,   24,
   25,   26,   27,   28,   29,   30,   31,  124,   56,   85,
  116,   67,   32,   70,   33,   74,   34,   35,   75,    0,
};
static const YYINT yysindex[] = {                         0,
    0, -120, -264, -240, -236, -283, -260, -274, -182,    0,
    0,    0,    0,    0,    0,    0,    0,    5,    0,    0,
 -247,    0,    0,  218,    0,    0,    0,    0,    0,    0,
    0, -218, -118,    0,    0, -286, -260, -260,    0,    0,
    0, -139,    0, -227,    0, -219, -215,  224,    0,    0,
    0,    0,    0,    0,    0, -251, -266,    0, -224,    0,
    0,    0,    0,    0,    0,    0, -260,    0,    0, -260,
    0,    0,    0, -260, -183, -184, -181,  271,  281,    0,
    0,    0,    0,    0, -271,    0,    0,    0,    0,    0,
 -186,  238, -172, -151, -207, -192,    0,   61, -218, -118,
    0,    0,    0, -169, -167, -160, -159, -153,  -83,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -130,
 -166, -123,  244,    0, -126,    0,    0,    0,    0, -120,
    0,    0, -270, -119, -258,    0,  263, -197, -108, -120,
 -134, -107,   50, -270,    0,    0,    0,    0,  -85,    0,
 -104, -103,    0,    0, -120, -134,  -91,  -87,    0,    0,
  -86,  -84,    0,    0,    0,    0, -135,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,  195,    0,    0,    0,    0,    0,  -70,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  118,    0,    0,
    0,    0,    0,  302,    0,    0,    0,    0,    0,    0,
    0,  185,  149,    0,    0,    0,    0,    0,    0,    0,
    0,  302,    0,    0,    0,    0,    0,  302,    0,    0,
    0,    0,    0,    0,    0,    0, -193,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  132,    0,    0,  302,  302,    0,
    0,    0,    0,    0,    0,    0,    0,   55,   76,   97,
  265,  302,    0,    0,    0,    0,    0,  -13,  204,  166,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  302,    0, -193,    0,    0,    0,    0,    0,
    0,    0,   10,  -76,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   10,    0,    0,    0,    0,    1,    0,
  -58,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -58,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  -89,   63,  108,    0,   -8,   78, -125,   -5,
    0,    0,    0,    0,    0,   57,    0,  158,    0,    0,
  109,    0,  153,    0,  152,    0,  150,    0,    0,    0,
};
#define YYTABLESIZE 570
static const YYINT yytable[] = {                         44,
   34,   42,    6,   48,  121,   43,  108,  141,    8,  109,
   94,    6,   36,   76,   39,   40,    7,   95,  156,   77,
  144,  110,  111,  145,    9,    7,  112,  113,  114,    3,
    4,   78,   79,    5,  115,    6,   37,   10,   11,   12,
   38,   86,   87,   68,   69,   41,   88,   89,   90,    7,
   92,    8,   81,  121,   91,    6,   96,   97,   57,    3,
    4,   98,   82,    5,   98,    6,   83,    9,   98,    7,
   10,   11,   12,   13,   14,   15,   16,   17,   18,    7,
    6,    8,  149,  102,  103,   86,   87,   20,   20,  123,
   88,   89,   90,  104,    7,  117,  105,    9,   41,   45,
   10,   11,   12,   13,   14,   15,   16,   17,   18,  119,
   46,   47,  127,  125,  128,   10,   11,   12,  129,  130,
  138,    3,    4,   41,  140,    5,  120,    6,  131,   60,
   61,   62,   63,   64,   65,  155,    3,    4,   80,  134,
    5,    7,    6,    8,  168,   71,   72,   73,  133,   13,
   14,   15,   16,   17,  135,  167,    7,  137,    8,    9,
    9,  143,   10,   11,   12,   13,   14,   15,   16,   17,
   18,  150,  153,  158,    9,  159,  160,   10,   11,   12,
   13,   14,   15,   16,   17,   18,    4,    4,  163,  142,
    4,  164,    4,  165,    1,  166,  151,  152,   14,   14,
  157,   45,   14,  126,   14,  154,    4,  139,    4,  110,
  111,  161,  162,   93,  112,  113,  114,  132,   14,   99,
   14,  100,  115,  101,    4,    0,    0,    4,    4,    4,
    4,    4,    4,    4,    4,    4,   14,    0,    0,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   76,   76,
   76,   76,   76,   76,   76,    0,    0,   34,   34,    0,
    0,   34,    0,   34,   76,    0,    4,    4,   76,    0,
    4,    0,    4,    0,    0,    0,    0,   34,    0,   34,
   34,   49,    0,    0,    0,    0,    4,    0,   50,   51,
   52,   53,   54,   55,    0,   34,    0,    0,   34,   34,
   34,   34,   34,   34,   34,   34,   34,    4,    4,    4,
    4,    4,    4,    4,    4,    4,   72,   72,   72,   72,
   72,   72,   72,   72,   72,   72,   72,   72,   72,   60,
   61,   62,   63,   64,   65,   22,   22,   73,   73,   73,
   73,   73,   73,   73,   73,   73,   73,   73,   73,   73,
   13,   14,   15,   16,   17,    0,   23,   23,   71,   71,
   71,   71,   71,   71,   71,   71,   71,   71,   71,   71,
   71,    0,    0,    0,    0,    0,    0,   24,   24,   70,
   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
   70,   70,    0,   65,   65,   65,   65,   65,    0,   70,
   65,   65,   65,   65,   65,   65,    0,    0,    0,   65,
   60,   60,    0,   65,    0,   60,   60,   60,   60,   60,
   60,   60,   60,    0,    0,    0,   60,   59,   59,    0,
   60,    0,   59,   59,   59,   59,   59,   59,   59,   59,
    0,    0,    0,   59,    0,    0,    0,   59,   58,   58,
   58,   58,   58,   58,   58,   58,   58,   58,   58,    0,
    0,    0,   58,    0,    0,    0,   58,   57,   57,   57,
   57,   57,   57,   57,   57,   57,   57,   57,    0,    0,
    0,   57,    0,    0,    0,   57,   60,   61,   62,   63,
   64,   65,   60,   61,   62,   63,   64,   65,    0,   66,
    0,    0,    0,    0,    0,   84,   60,   61,   62,   63,
   64,   65,   60,   61,   62,   63,   64,   65,    0,  118,
    0,    0,    0,    0,    0,  136,   70,   70,   70,   70,
   70,   70,   70,   70,   70,   70,   70,   70,   70,   60,
   61,   62,   63,   64,   65,    0,    0,    0,  106,   60,
   61,   62,   63,   64,   65,   86,   87,    0,  107,    0,
  146,  147,  148,   76,   76,   76,   76,   76,   76,   76,
};
static const YYINT yycheck[] = {                          8,
    0,    7,  263,    9,   94,  280,  278,  133,  279,  281,
  277,  263,  277,  300,  298,  299,  277,  284,  144,  306,
  279,  293,  294,  282,  295,  277,  298,  299,  300,  257,
  258,   37,   38,  261,  306,  263,  277,  298,  299,  300,
  277,  293,  294,  262,  263,  306,  298,  299,  300,  277,
   56,  279,  280,  143,  306,  263,  281,  282,  306,  257,
  258,   67,  282,  261,   70,  263,  282,  295,   74,  277,
  298,  299,  300,  301,  302,  303,  304,  305,  306,  277,
  263,  279,  280,  267,  268,  293,  294,  281,  282,   95,
  298,  299,  300,  278,  277,  282,  278,  295,  306,  282,
  298,  299,  300,  301,  302,  303,  304,  305,  306,  282,
  293,  294,  282,  306,  282,  298,  299,  300,  279,  279,
  129,  257,  258,  306,  133,  261,  278,  263,  282,  269,
  270,  271,  272,  273,  274,  144,  257,  258,  278,  306,
  261,  277,  263,  279,  280,  264,  265,  266,  279,  301,
  302,  303,  304,  305,  278,  164,  277,  284,  279,  295,
  295,  281,  298,  299,  300,  301,  302,  303,  304,  305,
  306,  280,  280,  259,  295,  280,  280,  298,  299,  300,
  301,  302,  303,  304,  305,  306,  257,  258,  280,  133,
  261,  279,  263,  280,    0,  280,  140,  141,  257,  258,
  144,  278,  261,   96,  263,  143,  277,  130,  279,  293,
  294,  155,  156,   56,  298,  299,  300,  109,  277,   67,
  279,   70,  306,   74,  295,   -1,   -1,  298,  299,  300,
  301,  302,  303,  304,  305,  306,  295,   -1,   -1,  298,
  299,  300,  301,  302,  303,  304,  305,  306,  262,  263,
  264,  265,  266,  267,  268,   -1,   -1,  257,  258,   -1,
   -1,  261,   -1,  263,  278,   -1,  257,  258,  282,   -1,
  261,   -1,  263,   -1,   -1,   -1,   -1,  277,   -1,  279,
  280,  277,   -1,   -1,   -1,   -1,  277,   -1,  284,  285,
  286,  287,  288,  289,   -1,  295,   -1,   -1,  298,  299,
  300,  301,  302,  303,  304,  305,  306,  298,  299,  300,
  301,  302,  303,  304,  305,  306,  262,  263,  264,  265,
  266,  267,  268,  269,  270,  271,  272,  273,  274,  269,
  270,  271,  272,  273,  274,  281,  282,  262,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,
  301,  302,  303,  304,  305,   -1,  281,  282,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,   -1,   -1,   -1,   -1,   -1,   -1,  281,  282,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  274,   -1,  262,  263,  264,  265,  266,   -1,  282,
  269,  270,  271,  272,  273,  274,   -1,   -1,   -1,  278,
  262,  263,   -1,  282,   -1,  267,  268,  269,  270,  271,
  272,  273,  274,   -1,   -1,   -1,  278,  262,  263,   -1,
  282,   -1,  267,  268,  269,  270,  271,  272,  273,  274,
   -1,   -1,   -1,  278,   -1,   -1,   -1,  282,  264,  265,
  266,  267,  268,  269,  270,  271,  272,  273,  274,   -1,
   -1,   -1,  278,   -1,   -1,   -1,  282,  264,  265,  266,
  267,  268,  269,  270,  271,  272,  273,  274,   -1,   -1,
   -1,  278,   -1,   -1,   -1,  282,  269,  270,  271,  272,
  273,  274,  269,  270,  271,  272,  273,  274,   -1,  282,
   -1,   -1,   -1,   -1,   -1,  282,  269,  270,  271,  272,
  273,  274,  269,  270,  271,  272,  273,  274,   -1,  282,
   -1,   -1,   -1,   -1,   -1,  282,  262,  263,  264,  265,
  266,  267,  268,  269,  270,  271,  272,  273,  274,  269,
  270,  271,  272,  273,  274,   -1,   -1,   -1,  278,  269,
  270,  271,  272,  273,  274,  293,  294,   -1,  278,   -1,
  298,  299,  300,  262,  263,  264,  265,  266,  267,  268,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 307
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
"ADD","SUB","MUL","DIV","MOD","INC","DEC","MT","LT","MTE","LTE","EQ","NE","LSB",
"RSB","LB","RB","LCB","RCB","COMMA","SEMICOLON","QUOTA","ASGN","ADDASGN",
"SUBASGN","MULASGN","DIVASGN","MODASGN","AND","OR","NOT","TRUE","FALSE","RET",
"CONT","BREAK","I_CONST","F_CONST","STR_CONST","INT","STRING","FLOAT","BOOL",
"VOID","ID","para_declaration",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"illegal-symbol",
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
"init_declarator : Type ID ASGN exp SEMICOLON",
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
"func_def : Type ID LB RB LCB compound_stat return_state RCB",
"func_def : Type ID LB RB LCB stat_list return_state RCB",
"func_def : Type ID LB RB LCB return_state RCB",
"func_declaration : Type ID LB para_list RB SEMICOLON",
"func_usage : ID LB aug_list RB SEMICOLON",
"para_list : Type ID COMMA para_list",
"para_list : Type ID",
"aug_list : aug_list aug",
"aug_list : aug_list COMMA aug",
"aug_list :",
"aug : ID",
"aug : I_CONST",
"aug : F_CONST",
"aug : STR_CONST",
"aug : TRUE",
"aug : FALSE",
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
#line 294 "compiler_hw2.y"

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;

    create_symbol();
    yyparse();
    dump_symbol();
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
    for(int i = 0; i < t_size; ++i){
        memset(sym_tab[i].name, 0, strlen(sym_tab[i].name));
        memset(sym_tab[i].kind, 0, strlen(sym_tab[i].kind));
        memset(sym_tab[i].attribute, 0, strlen(sym_tab[i].attribute));
        sym_tab[i].scope = -1;
        sym_tab[i].flag = 0;
    }

    for(int i = 0; i < t_size; ++i){
        where_in_table[i] = 100;
    }
}

void insert_symbol(int kind, char name[], char type[], char attr[],  int s) {
    //kind: 0=func, 1=var, 2=para
    
    // function
    if(kind == 0){
        sprintf(sym_tab[sym_tab_idx].name, "%s", name);
        sprintf(sym_tab[sym_tab_idx].type, "%s", type);
        sprintf(sym_tab[sym_tab_idx].kind, "%s", "function");
        sym_tab[sym_tab_idx].scope = s;
        sprintf(sym_tab[sym_tab_idx].attribute, "%s", attr);
    }
    // variable
    else if(kind == 1){
        sprintf(sym_tab[sym_tab_idx].name, "%s", name);
        sprintf(sym_tab[sym_tab_idx].type, "%s", type);
        sprintf(sym_tab[sym_tab_idx].kind, "%s", "variable");
        sym_tab[sym_tab_idx].scope = s;
    }
    // else
    else{
        sprintf(sym_tab[sym_tab_idx].name, "%s", name);
        sprintf(sym_tab[sym_tab_idx].type, "%s", type);
        sprintf(sym_tab[sym_tab_idx].kind, "%s", "parameter");
        sym_tab[sym_tab_idx].scope = s;
    }
    ++sym_tab_idx;
}

int lookup_symbol() {}

void search_scope(){
    int where = 0;
    int i;
    for(i = 0; i < t_size; ++i){
        //printf("%s %d,%s %d\n", "scope =", sym_tab[i].scope,"Scope =", Scope);
        if(sym_tab[i].scope == Scope){
            where_in_table[where] = i;
            ++where;
        }
    }
}

void dump_symbol() {
    int i;
    int Index = 0;

    search_scope();

    if(where_in_table[0] != 100){
        printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
            "Index", "Name", "Kind", "Type", "Scope", "Attribute");
    }
    /*
    for(i = 0; i < t_size; ++i)
        printf("%d ", where_in_table[i]);
    */
    for(i = 0; i < t_size; ++i){
        if(where_in_table[i] == 100)
            break;
        if(where_in_table[i] != 100){
            //printf("%d\n", where_in_table[i]);

            printf("%-10d%-10s%-12s%-10s%-10d%-10s\n\n",
            Index, 
            sym_tab[where_in_table[i]].name, 
            sym_tab[where_in_table[i]].kind,
            sym_tab[where_in_table[i]].type, 
            sym_tab[where_in_table[i]].scope, 
            sym_tab[where_in_table[i]].attribute);
            ++Index;

            memset(sym_tab[where_in_table[i]].name, 0, strlen(sym_tab[i].name));
            memset(sym_tab[where_in_table[i]].kind, 0, strlen(sym_tab[i].kind));
            memset(sym_tab[where_in_table[i]].attribute, 0, strlen(sym_tab[i].attribute));
            sym_tab[where_in_table[i]].scope = -1;
            sym_tab[where_in_table[i]].flag = 0;
        }
    }


    for(i = 0; i < t_size; ++i)
        where_in_table[i] = 100;
    --Scope;
}

void increase_scope(){
    ++Scope;
}
#line 659 "y.tab.c"

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
case 16:
#line 113 "compiler_hw2.y"
	{insert_symbol(1, yystack.l_mark[-1].string, yystack.l_mark[-2].string, "", Scope);}
break;
case 17:
#line 114 "compiler_hw2.y"
	{ insert_symbol(0, yystack.l_mark[-3].string, yystack.l_mark[-4].string, "", Scope);}
break;
case 18:
#line 118 "compiler_hw2.y"
	{yyval.string = yystack.l_mark[0].string;}
break;
case 20:
#line 123 "compiler_hw2.y"
	{yyval.string = yystack.l_mark[0].string;}
break;
case 21:
#line 124 "compiler_hw2.y"
	{yyval.string = yystack.l_mark[-2].string;}
break;
case 36:
#line 158 "compiler_hw2.y"
	{ insert_symbol(0, yystack.l_mark[-7].string, yystack.l_mark[-8].string, yystack.l_mark[-5].string, Scope); dec_flag = 1;}
break;
case 37:
#line 159 "compiler_hw2.y"
	{ insert_symbol(0, yystack.l_mark[-6].string, yystack.l_mark[-7].string, yystack.l_mark[-4].string, Scope); dec_flag = 1;}
break;
case 38:
#line 160 "compiler_hw2.y"
	{ insert_symbol(0, yystack.l_mark[-7].string, yystack.l_mark[-8].string, yystack.l_mark[-5].string, Scope); dec_flag = 1;}
break;
case 39:
#line 161 "compiler_hw2.y"
	{insert_symbol(0, yystack.l_mark[-6].string, yystack.l_mark[-7].string, "", Scope);}
break;
case 40:
#line 162 "compiler_hw2.y"
	{insert_symbol(0, yystack.l_mark[-6].string, yystack.l_mark[-7].string, "", Scope);}
break;
case 41:
#line 163 "compiler_hw2.y"
	{insert_symbol(0, yystack.l_mark[-5].string, yystack.l_mark[-6].string, "", Scope);}
break;
case 42:
#line 167 "compiler_hw2.y"
	{ insert_symbol(0, yystack.l_mark[-4].string, yystack.l_mark[-5].string, yystack.l_mark[-2].string, Scope); dec_flag = 1;}
break;
case 44:
#line 175 "compiler_hw2.y"
	{ sprintf(yyval.string, "%s, %s", yystack.l_mark[-3].string, yystack.l_mark[0].string);
                                insert_symbol(2, yystack.l_mark[-2].string, yystack.l_mark[-3].string, "", Scope+1);
                            }
break;
case 45:
#line 178 "compiler_hw2.y"
	{ insert_symbol(2, yystack.l_mark[0].string, yystack.l_mark[-1].string, "", Scope+1);
                  sprintf(yyval.string, "%s", yystack.l_mark[-1].string);
                }
break;
case 70:
#line 236 "compiler_hw2.y"
	{}
break;
case 97:
#line 285 "compiler_hw2.y"
	{yyval.string=yystack.l_mark[0].string;}
break;
case 98:
#line 286 "compiler_hw2.y"
	{yyval.string=yystack.l_mark[0].string;}
break;
case 99:
#line 287 "compiler_hw2.y"
	{yyval.string=yystack.l_mark[0].string;}
break;
case 100:
#line 288 "compiler_hw2.y"
	{yyval.string=yystack.l_mark[0].string;}
break;
case 101:
#line 289 "compiler_hw2.y"
	{yyval.string=yystack.l_mark[0].string;}
break;
#line 945 "y.tab.c"
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
