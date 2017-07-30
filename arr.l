%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "arr.h"
void yyerror(char *);
#include "y.tab.h"
int value;
char var;
char optr;
%}

%%

[0-9]+ 		{value=atoi(yytext);
		 yylval = numnode(value);
		 return DIGIT;}
		 
[a-z]           {
                 var = *yytext;
                 yylval = charnode(var);
                 return ID;
                }

"Write"         {yylval = cmdnode(yytext);
                 return Write;
                }

"Read"          {yylval = cmdnode(yytext);
                 return Read;}

"If"            {yylval = cmdnode(yytext);
                 return If;}
"then"          {return then;}
"endif"         {return endif;}

"While"          {yylval = cmdnode(yytext);
                 return While;}
"Do"             {return Do;}
"endwhile"       {return endwhile;}
                
";"             {optr = *yytext;
                 yylval = opnode(optr);
         	 return semicolon;}

"="             {
                 optr = *yytext;
                 yylval = opnode(optr);
         	 return equal;}
"=="            {optr = '@';
			*yytext = '@';
                 yylval = opnode(optr);
         	 return *yytext;}
         	 
[-+*/<>] 	{
                 optr = *yytext;
                 yylval = opnode(optr);
         	 return *yytext;}

[()] 		return *yytext;

\n 		return *yytext;

[ \t] 		;			/* skip whitespace */

.  yyerror("invalid");

%%

int yywrap(void) {
return 1;
}
