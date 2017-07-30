%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "y.tab.h"
#include "stage6_symbol.h"
int line=1;  //To keep track of error in line number
int value;
%}




%%
"decl"  {return DECL;}
"enddecl" {return ENDDECL;} 
"read"  {  return READ;} 
"write"  { return WRITE;}
"="     {return ASSIGN;} 
";"     {return SEMICOLON ;}
"while" { return WHILE;}
"do"    {return DO;}
"main"  {return MAIN;}
"return" {return RETURN;}
"endwhile" {return ENDWHILE;}
"true" { return NUMBER;}
"false" { return NUMBER;}
"+"    { printf("plus token found\n"); return *yytext;}
"-"    {return *yytext;}
"*"    { return *yytext;}
"/"    { return *yytext;}
"if"   { return IF;}
"else" {return ELSE;}
"then" {return THEN;}
"endif" {return ENDIF;}
"==" { return EQ;}
"<" { return LT;}
">" { return GT;}
">=" { return GE;}
"<=" { return LE;}
"!"  { return NE;}
"AND" { return AND;}
"OR" { return OR;}
"NOT" { return NOT;}
"&"   {return *yytext;}
"end"  {return END;}
"begin" {return BEGINP;}
"integer" {return INT;}
"boolean" {return BOOL;}
[()}{,] 			{return *yytext;}
"["				{return *yytext;}
"]"             {return *yytext;}
[ \t]			{}
[\n]                    {line++;printf("LINE %d executed\n",line);}
[0-9]+   {value=atoi(yytext); yylval.integer=value; return NUMBER;}
[a-zA-Z][a-zA-Z0-9]* 	        {char *x = strdup(yytext);yylval.string=x; return ID;}
.	 			{yyerror();}

%%
yywrap()
	{
		return 1;
	}
