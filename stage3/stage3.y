%{
#include"lex.yy.c"
#include<stdio.h>
#include"exptree.cpp"
void yyerror(char*);
int A[26];
%}

%union{
int ival;
struct xtree *nptr;
char chid;
};

%token <ival> NUM
%token <chid> ID
%token <ival> READ
%token <ival> WRITE
%type <nptr> expr
%left '+' '-'
%left '*' '/'

%%
pgm  :slist '\n' {exit(0);}
     ;
slist: slist stmt 
     | stmt
     ;
stmt : ID '=' expr ';' {A[$1-'a']=eval($3);}
     |READ'('ID')'';' {scanf("%d",&A[$3-'a']);}
     |WRITE'('expr')'';' { printf("%d\n",eval($3));}
     ;
expr : expr '+' expr {$$=mkopnode('+', $1, $3);}
     | expr '-' expr {$$=mkopnode('-',$1, $3);}
     | expr '*' expr {$$=mkopnode('*',$1, $3);}
     | expr '/' expr {$$=mkopnode('/',$1, $3);}
     |'('expr')' {$$=$2;}
     |ID {$$=mkleafnode(A[$1-'a']);}
     ;
expr : NUM {$$=mkleafnode($1);}
     ;
%%
void yyerror(char* a)
{
printf("error\n");
return;
}

main()
{
yyparse();
}
