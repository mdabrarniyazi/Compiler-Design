%{

#include"lex.yy.c"
#include<stdio.h>
#include"exptree.cpp"
void yyerror(char*);

%}

%union{
int ival;
struct xtree *nptr;
char chid;
};

%token <ival> NUM
%token <chid> ID
%token <nptr> READ
%token <nptr> WRITE
%token <nptr> IF
%token <nptr> THEN
%token <nptr> ENDIF
%token <nptr> WHILE
%token <nptr> DO
%token <nptr> ENDWHILE
%token <nptr> EQQ
%type <nptr> expr
%type <nptr> stmt
%type <nptr> slist
%left '+' '-'
%left '*' '/'
%left '<' '>'
%left EQQ


%%
pgm  :slist '\n' {eval($1); exit(0);}
     ;
slist: stmt slist{$$=mkopnode(SLST, $1, $2);}
     | stmt {$$=$1;}
     ;
stmt : ID '=' expr ';' {$$=mkopnode(EQ, mkleafnodeid(IDD, $1), $3); }
     |READ'('ID')'';' {$$=mkopnode(REED, mkleafnodeid(IDD, $3), NULL);}
     |WRITE'('expr')'';' {$$=mkopnode(RITE, $3, NULL);}
     |IF'('expr')' THEN slist ENDIF ';' {$$=mkopnode(IFF, $3, $6);}
     | WHILE'('expr')' DO slist ENDWHILE';' {$$=mkopnode(WILE, $3, $6);}
     ;
expr : expr '+' expr {$$=mkopnode(ADD, $1, $3);}
     | expr '-' expr {$$=mkopnode(SUB, $1, $3);}
     | expr '*' expr {$$=mkopnode(MUL, $1, $3);}
     | expr '/' expr {$$=mkopnode(DIV, $1, $3);}
     | expr '<' expr {$$=mkopnode(LT,  $1, $3);}
     | expr '>' expr {$$=mkopnode(GT,  $1, $3);}
     | expr EQQ expr {$$=mkopnode(EE,  $1, $3);}
     |'('expr')' {$$=$2;}
     |ID {$$=mkleafnodeid(IDD, $1); }
     ;
expr : NUM {$$=mkleafnode(NUM1, $1);}
     ;
%%
void yyerror(char* a)
{
printf("error\n");
return;
}

main()
{
     fp = fopen("mout.txt", "w");
     char fname[20];
     gets(fname);
     yyin = fopen(fname, "r");
     yyparse();
     fclose(yyin);
     fclose(fp);

}
