%option noyywrap
%{
#include "y.tab.h"
#include <stdlib.h>
extern YYSTYPE yylval;
%}

digit [0-9]
ID [a-z]

%%
{ID}  {yylval.chid = *yytext; return ID;}
{digit}+ {yylval.ival = atoi(yytext); return NUM;}
[*+/\n-=();] {return *yytext;}
"read"   {return READ;}
"write"  {return WRITE;}
.        {}
%%


