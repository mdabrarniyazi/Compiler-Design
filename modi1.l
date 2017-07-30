%{
#include "y.tab.h"
#include <stdlib.h>

void yyerror(char *s);
%}

digit [0-9]
integer {digit}+
real ({digit}+[.]{digit}*)|({digit}*[.]{digit}+)
exp ({integer}|{real})[eE]-?{integer}

%%

({integer}|{real}|{exp}) { yylval = atof(yytext); return NUMBER; }
[-+*/\n]                 { return *yytext; }
[ \t\v\f\r]              { }
.                        { yyerror("Unknown Character"); }

%%

int yywrap(void)
{
  return 1;
}