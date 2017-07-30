%{
#include "y.tab.h"
#include<iostream>
#include <stdlib.h>
extern YYSTYPE yylval;
using namespace std;
int line_no=1;
%}

digit	[0-9]
ID		[a-z]

%%
"read"				{return READ;}
"write"				{return WRITE;}
"if"				{return IF;}
"then"				{return THEN;}
"endif"				{return ENDIF;}
"while"				{return WHILE;}
"do"				{return DO;}
"AND"				{return ANDY;}
"OR"				{return ORY;}
"NOT"				{return NOTY;}
"endwhile"			{return ENDWHILE;}
"=="				{return EQQ;}
"decl"				{return DECL;}
"enddecl"			{return ENDDECL;}
"INTEGER"			{return INT;}
"integer"			{return INT;}
"MAIN"				{return MAIN;}
"main"				{return MAIN;}
"return"			{return RETURN;}
"BOOLEAN"			{return BOOL;}
"boolean"			{return BOOL;}
"ENDPRG"			{return ENDPRG;}
"endprg"			{return ENDPRG;}
"end"				{return END;}
"begin"				{return BEGINP;}
"TRUE"				{yylval.ival=1;return COND;}
"FALSE"				{yylval.ival=0;return COND;}
{digit}*[.]{digit}+	{cout<<"float unexpected\n";exit(0);}
{ID}+				{yylval.chid = strdup(yytext);return ID;}
{digit}+			{yylval.ival = atoi(yytext);return NUM;}
[-,*+/=()\[\];<>\{\}]	{return *yytext;}
[ \n]				{line_no++;}

.	{}
%%

int yywrap()
{
	return 1;
}