%{
#include "y.tab.h"
#include<iostream>
#include <stdlib.h>
extern YYSTYPE yylval;
using namespace std;
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
"BOOLEAN"			{return BOOL;}

"TRUE"				{yylval.ival=1;return COND;}
"FALSE"				{yylval.ival=0;return COND;}
{digit}*[.]{digit}+	{cout<<"float unexpected\n";exit(0);}
{ID}+				{yylval.chid = strdup(yytext);return ID;}
{digit}+			{yylval.ival = atoi(yytext);return NUM;}
[,*+/=()\[\];<>\n-]	{return *yytext;}


.	{}
%%

int yywrap()
{
	return 1;
}