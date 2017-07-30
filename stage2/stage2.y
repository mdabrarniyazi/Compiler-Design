%{
#include"lex.yy.c"
#include<stdio.h>
#include"exptree.cpp"
void yyerror(char*);
%}

%union{
float fval;
struct xtree *nptr;
};

%token <fval> NUM
%token ID
%type <nptr> expr
%left '+' '-'
%left '*' '/'

%%
pgm  :expr '\n' {printf("%f\n", eval($1)); exit(0);}
     ;
expr : expr '+' expr {$$=mkopnode('+', $1, $3);}
     | expr '-' expr {$$=mkopnode('-',$1, $3);}
     | expr '*' expr {$$=mkopnode('*',$1, $3);}
     | expr '/' expr {$$=mkopnode('/',$1, $3);}
     ;
expr : NUM {$$=mkleafnode($1);}
     ;
%%
void yyerror(char* a)
{
printf("error");
return;
}

int  main()
{
yyparse();
}


    
