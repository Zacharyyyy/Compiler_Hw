/*	Definition section */
%{
#include <stdio.h>
#include <string.h>
#define t_size 64

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
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
int dec_flag = 0; // if current line is a declare line, '1'
int uflag;

char dec_name[20] = {0};// declared name

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* string;
}

/* Token without return */
%token PRINT 
%token IF ELSE FOR WHILE 
%token ADD SUB MUL DIV MOD
%token INC DEC
%token MT LT MTE LTE EQ NE
%token LSB RSB LB RB LCB RCB COMMA SEMICOLON QUOTA 
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN 
%token AND OR NOT
%token TRUE FALSE
%token RET
%token CONT BREAK



/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STR_CONST
%token <string> INT STRING FLOAT BOOL VOID ID

/* Nonterminal with return, which need to sepcify type */
//%type <f_val> stat
%type <string> init_declarator
%type <string> func_declaration
%type <string> para_declaration
%type <string> Type
%type <string> para_list
%type <string> vars
%type <string> init_declarator_list

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program stat_list
    |
;

stat_list
    : stat_list stat
    |
;

stat
    : init_declarator
    | compound_stat
    | exp SEMICOLON
    | print_func
    | func_def
    | func_declaration
    | func_usage
    | selection_stat
    | iteration_stat
    | return_state
    | asign_state
;

/*initailize variable*/
init_declarator
    : Type init_declarator_list SEMICOLON {insert_symbol(1, $2, $1, "", Scope);}
    | Type ID ASGN exp SEMICOLON { insert_symbol(0, $2, $1, "", Scope);} 
;

init_declarator_list
    : vars {$$ = $1;}
    | init_declarator_list COMMA vars
;

vars
    : ID {$$ = $1;}
    | ID ASGN initializer {$$ = $1;}
;

initializer
    : I_CONST
    | F_CONST
    | STR_CONST
    | TRUE
    | FALSE
;

/*assigning value*/
asign_state
    : ID asgn_type initializer SEMICOLON
    | ID asgn_type ID SEMICOLON
    | ID asgn_type exp SEMICOLON
;

/*returning*/
return_state
    : RET exp SEMICOLON
    | RET SEMICOLON
    | RET TRUE SEMICOLON
    | RET FALSE SEMICOLON
;

/* if-else */
selection_stat
    : IF LB exp RB LCB stat_list RCB
    | IF LB exp RB LCB stat_list RCB ELSE LCB stat_list RCB
;

/*function part*/
func_def
    : Type ID LB para_list RB LCB compound_stat  return_state RCB{ insert_symbol(0, $2, $1, $4, Scope); dec_flag = 1;}
    | Type ID LB para_list RB LCB return_state RCB { insert_symbol(0, $2, $1, $4, Scope); dec_flag = 1;}
    | Type ID LB para_list RB LCB  stat_list return_state RCB { insert_symbol(0, $2, $1, $4, Scope); dec_flag = 1;}
    | Type ID LB RB LCB compound_stat  return_state RCB {insert_symbol(0, $2, $1, "", Scope);}
    | Type ID LB RB LCB  stat_list return_state RCB {insert_symbol(0, $2, $1, "", Scope);}
    | Type ID LB RB LCB return_state RCB  {insert_symbol(0, $2, $1, "", Scope);}
;

func_declaration
    : Type ID LB para_list RB SEMICOLON { insert_symbol(0, $2, $1, $4, Scope); dec_flag = 1;}

;
func_usage
    : ID LB aug_list RB SEMICOLON
;

para_list
    : Type ID COMMA para_list { sprintf($$, "%s, %s", $1, $4);
                                insert_symbol(2, $2, $1, "", Scope+1);
                            }
    | Type ID   { insert_symbol(2, $2, $1, "", Scope+1);
                  sprintf($$, "%s", $1);
                }
;

aug_list
    : aug_list aug
    | aug_list COMMA aug
    |
;

aug
    : ID
    | I_CONST
    | F_CONST
    | STR_CONST
    | TRUE
    | FALSE
;


compound_stat
    : LCB RCB
    | LCB stat_list RCB
;

exp
    : exp comparison ad_exp
    | ad_exp
;

ad_exp
    : ad_exp addition mul_exp
    | mul_exp
;

addition
    : ADD
    | SUB
;

mul_exp
    : mul_exp multiplication postfix_exp
    | postfix_exp
;

postfix_exp
    : term postfix
;

postfix
    : postfix INC
    | postfix DEC
    |
;

term
    : LB exp RB
    | ID {}
    | STR_CONST
    | I_CONST
    | F_CONST
    | SUB I_CONST
    | SUB F_CONST
    | exp
;

comparison
    : MT
    | LT
    | MTE
    | LTE
    | EQ
    | NE
;

operation
    : addition
    | multiplication
;

multiplication
    : MUL
    | DIV
    | MOD
;

print_func
    : PRINT LB STR_CONST RB SEMICOLON
    | PRINT LB ID RB SEMICOLON
;

iteration_stat
    : WHILE LB exp RB LCB stat RCB
;

asgn_type
    : ASGN
    | ADDASGN
    | SUBASGN
    | MULASGN
    | DIVASGN
    | MODASGN 
;

/* actions can be taken when meet the token or rule */
Type
    : INT {$$=$1;}
    | FLOAT {$$=$1;}
    | BOOL  {$$=$1;}
    | STRING {$$=$1;}
    | VOID {$$=$1;}
;


%%

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