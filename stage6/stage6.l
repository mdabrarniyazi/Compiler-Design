%{
#include "y.tab.h"
#include <stdlib.h>
extern YYSTYPE yylval;
%}

digit [0-9]
ID [a-z]

%%
"read"   {return READ;}
"write"  {return WRITE;}
"if"	 {return IF;}
"then"   {return THEN;}
"endif"  {return ENDIF;}
"while"  {return WHILE;}
"do"     {return DO;}
"endwhile" {return ENDWHILE;}
"=="     {return EQQ;}
"decl"	 {return DECL;}
"enddecl" {return ENDDECL;}
"INTEGER" {return INT;}
{ID}+ {yylval.chid = strdup(yytext); return ID;}
{digit}+ {yylval.ival = atoi(yytext); return NUM;}
[,*+/=();<>\n-] {return *yytext;}


.        {}
%%

int yywrap()
{
	return 1;
}