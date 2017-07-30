%{

#include"lex.yy.c"
#include<stdio.h>
#include"symbol.cpp"
#include"exptree.cpp"
void yyerror(char*);

%}

%union{
int ival;
struct xtree *nptr;
char* chid;
};

%token <ival> NUM
%token <ival> INT
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
%token <nptr> DECL
%token <nptr> ENDDECL
%type <nptr> expr
%type <nptr> stmt
%type <nptr> slist
%left '+' '-'
%left '*' '/'
%left '<' '>'
%left EQQ


%%
pgm  :gdecl slist '\n' {eval($2); exit(0);}
     ;
gdecl: DECL declist ENDDECL
     ;
declist:decll declist
     | decll
     ;
decll:type idlist ';'
     ;
type :INT {vartype=0;}
     ;
idlist: ID ',' idlist {is_exists($1); ginstall($1,vartype,1);}
     | ID     {is_exists($1); ginstall($1,vartype,1);}
     ;
slist: stmt slist{$$=mkopnode(SLST, $1, $2);}
     | stmt {$$=$1;}
     ;
stmt : ID '=' expr ';' {struct gsymbol *temp = lookup($1);
                         if(temp==NULL){
                              printf("Identifier with name %s does not exists",$1);
                              exit(1);} $$=mkopnode(EQ, mkleafnodeid(IDD, $1), $3); }
     |READ'('ID')'';' {struct gsymbol *temp = lookup($3);
                         if(temp==NULL){
                              printf("Identifier with name %s does not exists",$3);
                              exit(1);}$$=mkopnode(REED, mkleafnodeid(IDD, $3), NULL);}
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
     |ID {struct gsymbol *temp = lookup($1);
                         if(temp==NULL){
                              printf("Identifier with name %s does not exists",$1);
                              exit(1);}
                              $$=mkleafnodeid(IDD, $1); }
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
yyparse();
}
