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
int used;
int used_func;
int func_idx;
int pre_declare;
int dumping;
int syn_error;
int sem_error;
int syn_error_type;
char last_buf[256];

/* Symbol table function - you can add new function if needed. */
int lookup_symbol();
void create_symbol();
void insert_symbol();
void dump_symbol();
void increase_scope();
void if_undeclare();
void print_out_line();

struct Table{
    int flag;
    char name[20];
    char kind[20];
    char type[20];
    int scope;
    char attribute[30];
    int pre_declare;
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
%type <string> Type
%type <string> para_list
%type <string> vars
%type <string> init_declarator_list
%type <string> func_usage
%type <string> asign_state
%type <string> term

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
    | selection_stat
    | iteration_stat
    | return_state
    | asign_state
;

/*initailize variable*/
init_declarator
    //: Type init_declarator_list SEMICOLON { insert_symbol(1, $2, $1, "", Scope);}
    : Type ID ASGN exp SEMICOLON { insert_symbol(1, $2, $1, "", Scope);}
    | Type ID SEMICOLON {insert_symbol(1, $2, $1, "", Scope);}
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
    : ID asgn_type initializer SEMICOLON { if_undeclare($1, 1);}
    | ID asgn_type ID SEMICOLON { if_undeclare($1, 1);}
    | ID asgn_type exp SEMICOLON { if_undeclare($1, 1);}
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
    : Type ID LB para_list RB LCB compound_stat  return_state RCB{ insert_symbol(0, $2, $1, $4, Scope-1); dec_flag = 1;}
    | Type ID LB para_list RB LCB return_state RCB { insert_symbol(0, $2, $1, $4, Scope-1); dec_flag = 1;}
    | Type ID LB para_list RB LCB  stat_list return_state RCB { insert_symbol(0, $2, $1, $4, Scope-1); dec_flag = 1;}
    | Type ID LB RB LCB compound_stat  return_state RCB {insert_symbol(0, $2, $1, "", Scope-1);}
    | Type ID LB RB LCB  stat_list return_state RCB {insert_symbol(0, $2, $1, "", Scope-1);}
    | Type ID LB RB LCB return_state RCB  {insert_symbol(0, $2, $1, "", Scope-1);}
    | Type ID LB RB LCB compound_stat  RCB {insert_symbol(0, $2, $1, "", Scope-1);}
    | Type ID LB RB LCB  stat_list RCB {insert_symbol(0, $2, $1, "", Scope-1);}
    | Type ID LB RB LCB RCB  {insert_symbol(0, $2, $1, "", Scope-1);}

;

func_declaration
    : Type ID LB para_list RB SEMICOLON { insert_symbol(0, $2, $1, $4, Scope-1); dec_flag = 1;}
    | Type ID LB RB SEMICOLON {insert_symbol(0, $2, $1, "", Scope-1); dec_flag = 1;}
;
func_usage
    : ID LB aug_list RB { if_undeclare($1, 0);} 
;

para_list
    : para_list COMMA Type ID { sprintf($$, "%s, %s", $1, $3);
                                insert_symbol(2, $4, $3, "", Scope+1);
                            }
    | Type ID   { insert_symbol(2, $2, $1, "", Scope+1);
                  sprintf($$, "%s", $1);
                }
;

aug_list
    : exp COMMA aug_list
    | exp
    |
;

aug
    : ID { if_undeclare($1, 1); syn_error_type = 0;}
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
    | ID { if_undeclare($1, 1);}
    | STR_CONST
    | I_CONST
    | F_CONST
    | func_usage
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
    | PRINT LB ID RB SEMICOLON { if_undeclare($3, 1); }
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
    used = 0;
    dumping = -1;
    sem_error = 0;

    create_symbol();
    yyparse();
    if(syn_error == 0){
        dumping = 0;
        dump_symbol();
	    printf("\nTotal lines: %d \n",yylineno);
    }
    return 0;
}

void yyerror(char *s)
{   
    //printf("%d: %s%s\n", yylineno+1, last_buf, buf);

    //sementic error

    

    if(strcmp("syntax error", s) == 0)
        syn_error = 1;
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s%s\n", yylineno + 1, last_buf, buf);
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
        sym_tab[i].pre_declare = 0;
    }

    for(int i = 0; i < t_size; ++i){
        where_in_table[i] = 100;
    }
}

void insert_symbol(int kind, char name[], char type[], char attr[],  int s) {
    // see if the name has already been used in the same scope;
    int last_idx = sym_tab_idx;
    if(kind == 0){
        lookup_symbol(name, 1, attr, s);

        if(pre_declare == 1){
            // declare twice
            if(dec_flag == 1){
                print_out_line();
                sem_error = 1;

                char a[50] = "Redeclared function ";
                strcat(a, name);
                printf("\n|-----------------------------------------------|\n");
                printf("| Error found in line %d: %s\n", yylineno + 1, buf);
                printf("| %s", a);
                printf("\n|-----------------------------------------------|\n\n");
                dec_flag = 0;
                memset(last_buf, 0, 255);
                strcpy(last_buf, buf);
                memset(buf, 0, 255);
            }
            sym_tab_idx = func_idx;
            pre_declare = 0;
        }
        if(used == 1){
            print_out_line();
            sem_error = 1;

            char a[50] = "Redeclared function ";
            strcat(a, name);
            printf("\n|-----------------------------------------------|\n");
            printf("| Error found in line %d: %s\n", yylineno + 1, buf);
            printf("| %s", a);
            printf("\n|-----------------------------------------------|\n\n");
            used = 0;
            memset(last_buf, 0, 255);
            strcpy(last_buf, buf);
            memset(buf, 0, 255);
            return;
        }
    }
    else if (kind == 1){
        lookup_symbol(name, 0, "", s);
        if(used == 1){
            // redefine errer
            //yyerror(strcat("Redeclared variable ", name));
            print_out_line();
            sem_error = 1;

            char a[50] = "Redeclared variable ";
            strcat(a, name);
            printf("\n|-----------------------------------------------|\n");
            printf("| Error found in line %d: %s\n", yylineno + 1, buf);
            printf("| %s", a);
            printf("\n|-----------------------------------------------|\n\n");
            used = 0;
            memset(last_buf, 0, 255);
            strcpy(last_buf, buf);
            memset(buf, 0, 255);
            return;
        }
    }
    else{
        lookup_symbol(name, 0, "", s);
        if(used == 1){
            // redefine errer
            //yyerror(strcat("Redeclared parameter ", name));
            print_out_line();
            sem_error = 1;

            char a[50] = "Redeclared parameter ";
            strcat(a, name);
            printf("\n|-----------------------------------------------|\n");
            printf("| Error found in line %d: %s\n", yylineno + 1, buf);
            printf("| %s", a);
            printf("\n|-----------------------------------------------|\n\n");
            used = 0;
            memset(last_buf, 0, 255);
            strcpy(last_buf, buf);
            memset(buf, 0, 255);
            return;
        }
    }

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
    sym_tab_idx = last_idx;
    ++sym_tab_idx;
}

int lookup_symbol(char searching[], int is_func, char para[], int s) {
    int i;

    // if_undeclare_function
    if(is_func == 2){
        for(i = 0; i < t_size; ++i){
            if(sym_tab[i].scope <= s && sym_tab[i].scope > -1){
                if(strcmp(sym_tab[i].name, searching) == 0 && strcmp(sym_tab[i].kind, "function") == 0){
                    used = 1;
                    return 0;
                }
                else{
                    used = 0;
                }
            }
        }
    }
    // if_undeclare_variable
    else if(is_func == 3){
        for(i = 0; i < t_size; ++i){
            if(sym_tab[i].scope <= s && sym_tab[i].scope > -1){
                if(strcmp(sym_tab[i].name, searching) == 0 && strcmp(sym_tab[i].kind, "function") != 0){
                    used = 1;
                    return 0;
                }
                else{
                    //printf("%s%s\n", "can't find ", searching);
                    //printf("%s, %s\n", sym_tab[i].name, searching);
                    used = 0;
                }
            }
        }
    }
    else{
        for(i = 0; i < t_size; ++i){
            //printf("%s, %d, %s, %d\n", sym_tab[i].name, sym_tab[i].scope, searching, s);
            if(sym_tab[i].scope <= s && sym_tab[i].scope > -1){
                // if name been used
                //printf("%s, %s\n", sym_tab[i].name, searching);
                if(strcmp(sym_tab[i].name, searching) == 0){
                    // see if the parameters are the same, "pre-declare"
                    if(strcmp(sym_tab[i].attribute, para) == 0 && is_func == 1){
                        pre_declare = 1;
                        func_idx = i;
                        //printf("%s\n", "para the same");
                        used = 0;
                    }  
                    else{
                        //printf("%s\n", "used");
                        used = 1;
                    }
                }
            }
        }
    }
}

void if_undeclare( char name[], int kind){
    // undeclare function
    if(kind == 0){
        lookup_symbol(name, 2, "", Scope);
        //printf("%s\n", "in if undeclare");
        if(used == 0){
            print_out_line();
            sem_error = 1;

            char a[50] = "Undeclared function ";
            strcat(a, name);
            printf("\n|-----------------------------------------------|\n");
            printf("| Error found in line %d: %s\n", yylineno + 1, buf);
            printf("| %s", a);
            printf("\n|-----------------------------------------------|\n\n");
            used = 0;
            memset(last_buf, 0, 255);
            strcpy(last_buf, buf);
            memset(buf, 0, 255);
        }
        used = 0;
    }
    else{
        lookup_symbol(name, 3, "", Scope);
        if(used == 0){
            print_out_line();
            sem_error = 1;

            char a[50] = "Undeclared variable ";
            strcat(a, name);
            printf("\n|-----------------------------------------------|\n");
            printf("| Error found in line %d: %s\n", yylineno + 1, buf);
            printf("| %s", a);
            printf("\n|-----------------------------------------------|\n\n");
            used = 0;
            memset(last_buf, 0, 255);
            strcpy(last_buf, buf);
            memset(buf, 0, 255);
        }
        used = 0;
    }
}

void search_scope(){
    int where = 0;
    int i;
    for(i = 0; i < t_size; ++i){
        //printf("%s %d,%s %d\n", "scope =", sym_tab[i].scope,"Scope =", Scope);
        //printf("%s\n", sym_tab[i].name);
        if(sym_tab[i].scope == Scope){
            where_in_table[where] = i;
            ++where;
        }
    }
}

void dump_symbol() {
    int i;
    int Index = 0;
    int dumped = 0;
    //search_scope();
    int where = 0;
    for(i = 0; i < t_size; ++i){
        if(sym_tab[i].scope == dumping){
            where_in_table[where] = i;
            ++where;
        }
    }
    dumping = -1;

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
            dumped = 1;

            printf("%-10d%-10s%-12s%-10s%-10d%s\n",
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
    if(dumped){
        printf("\n");
        dumped = 0;
    }
    
    for(i = 0; i < t_size; ++i)
        where_in_table[i] = 100;
    --Scope;
}

void increase_scope(){
    ++Scope;
}

void print_out_line(){
    printf("%d", yylineno + 1);
	if(strlen(buf) > 0){
		printf(": ");
	}
	else{
		printf(":");
	}
    printf("%s\n", buf);
    //memset(buf, 0, 255);
}