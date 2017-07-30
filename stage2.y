%{
#include"lex.yy.c"
#include<stdio.h>
#include"exptree.cpp"
void yyerror(char*);
%}

%union{
int ival;
struct xtree *nptr;
};

%token <ival> NUM
%token ID
%type <nptr> expr
%left '+' '-'
%left '*' '/'

%%
pgm  :ID '=' expr '\n' {printf("%d\n", eval($3));}
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

int main()
{
yyparse();
}


    
