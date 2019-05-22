/* Definition section */
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"

	extern YYSTYPE yylval; //YYSTYPE
	char buf[256];

	void print_out_lines();

	#define CONCAT { strncat(buf, yytext, 256 - strlen(buf) - 1); }

	// int lineCount = 0;
	// int commentLineCount = 0;
	// void plusCommentAndTotalLineCount();
	// void printStrAndQuotas();
%}


%option yylineno
/* Define regular expression label */
letter [a-zA-Z]
digit [0-9]
id {letter}+({letter}|{digit})*
number {digit}+
integer {digit}+
float {digit}*"."{number}
comment "/*"([^*]|\*+[^*/])*\*+"/"
plus_comment "//".*
str \"(.+)\"
/* Rules section */
%%

"+" 		{ CONCAT; return ADD;}
"-"			{ CONCAT; return SUB;}
" "			{ CONCAT; }
"*"			{ CONCAT; return MUL;}
"/"			{ CONCAT; return DIV;}
"%"			{ CONCAT; return MOD;}
"++"		{ CONCAT; return INC;}
"--"		{ CONCAT; return DEC;}
">"			{ CONCAT; return MT;}
"<"			{ CONCAT; return LT;}
">="		{ CONCAT; return MTE;}
"<="		{ CONCAT; return LTE;}
"=="		{ CONCAT; return EQ;}
"!="		{ CONCAT; return NE;}
"["			{ CONCAT; return LSB;}
"]"			{ CONCAT; return RSB;}
","			{ CONCAT; return COMMA;}
";"			{ CONCAT; return SEMICOLON;}
"\""		{ CONCAT; return QUOTA;}
"print"		{ CONCAT; return PRINT;}
"if"		{ CONCAT; return IF;}
"else"		{ CONCAT; return ELSE;}
"for"		{ CONCAT; return FOR;}
"while"		{ CONCAT; return WHILE;}
"string"	{ CONCAT; return STRING;}
"int"		{ yylval.string = strdup(yytext); CONCAT; return INT;}
"float"		{ yylval.string = strdup(yytext); CONCAT; return FLOAT;}
"="			{ CONCAT; return ASGN;}
"+="		{ CONCAT; return ADDASGN;}
"-="		{ CONCAT; return SUBASGN;}
"*="		{ CONCAT; return MULASGN;}
"/="		{ CONCAT; return DIVASGN;}
"%="		{ CONCAT; return MODASGN;}
"&&"		{ CONCAT; return AND;}
"||"		{ CONCAT; return OR;}
"!"		  	{ CONCAT; return NOT;}
"("		  	{ CONCAT; return LB;}
")"		  	{ CONCAT; return RB;}
"{"		  	{ CONCAT; return LCB;}
"}"		  	{ CONCAT; return RCB;}
"void"		{ yylval.string = strdup(yytext); CONCAT; return VOID;}
"bool"		{ yylval.string = strdup(yytext); CONCAT; return BOOL;}
"true"		{ CONCAT; return TRUE;}
"false"		{ CONCAT; return FALSE;}
"return"	{ CONCAT; return RET;}
"continue"	{ CONCAT; return CONT;}
"break"		{ CONCAT; return BREAK;}

"\n"		{ print_out_lines();}

{integer}	{ CONCAT; return I_CONST;}
{float} { CONCAT; return F_CONST;}
{id}		{ CONCAT; return ID;}

{comment}	{ CONCAT; }
{plus_comment} { CONCAT; }
{str}	{ CONCAT; return STR_CONST;}





%%

void print_out_lines()
{   
    printf("%d ", yylineno);
    printf("%s\n", buf);
    memset(buf, 0, 255);
}


int yywrap(void)
{
    return 1;
}

// int main(int argc,char *argv[])
// {
// 	yyin = fopen(argv[1],"r");
// 	yylex();
// 	printf("\nParse over, the line number is %d.\n\n", lineCount);
// 	printf("comment: %d lines\n\n", commentLineCount);

// 	return 0;
// }

