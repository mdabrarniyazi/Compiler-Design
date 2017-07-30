%{
#include "lex.yy.c"
%}

%token NUM
%left '+'
%left '-'
%left '*'
%left '/'

%%
pgm  : expr '\n' {printf("%d\n", $1); exit(0);}
     ;
expr : expr '+' expr {$$=$1+$3;}
     | expr '-' expr {$$=$1-$3;}
     | expr '*' expr {$$=$1*$3;}
     | expr '/' expr {if($3!=0) $$=$1/$3; else {printf("$3 cannot be zero");}}
     ;
expr : NUM {$$=$1;}
%%

yyerror()
{
printf("error");
return;
}

main()
{
yyparse();
}

