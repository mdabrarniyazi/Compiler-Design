%option noyywrap
%{
#include "y.tab.h"
#include<stdlib.h>
#include<math.h>
extern YYSTYPE yylval;
%}

digit [0-9]

%%
{digit}+\.{digit}* {yylval.fval = atof(yytext); return NUM;}
[*+/\n-] {return *yytext;}
.        {}
%%

