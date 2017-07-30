%option noyywrap
%{
#include "y.tab.h"
#include <stdlib.h>
extern int yylval;
%}

digit [0-9]

%%
{digit}+ {yylval = atoi(yytext); return NUM;}
[*+/\n-] {return *yytext;}
.        {}
%%


