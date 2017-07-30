%{

#include"lex.yy.c"
#include<stdio.h>
#include<string>
#include"symbol.cpp"
#include"exptree.cpp"
void yyerror(const char *);
using namespace std;
int idval;
%}

%union{
int ival;

struct xtree *nptr;
char* chid;
};

%token <ival> NUM
%token <ival> COND
%token <ival> INT
%token <ival> BOOL
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
%token <nptr> ANDY
%token <nptr> ORY
%token <nptr> NOTY
%token <nptr> DECL
%token <nptr> ENDDECL
%type <nptr> expr
%type <nptr> stmt
%type <nptr> slist
%left '+' '-'
%left '*' '/'
%left '<' '>'
%left EQQ ANDY ORY NOTY

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
	|BOOL {vartype=1;}
     ;
idlist: ID '[' NUM ']' ',' idlist 	{is_exists($1); ginstall($1,vartype,$3);}
	 | ID '[' NUM ']'				{is_exists($1); ginstall($1,vartype,$3);}
	 | ID ',' idlist				{is_exists($1); ginstall($1,vartype,1);}
      | ID							{is_exists($1); ginstall($1,vartype,1);}
      | 
     ;
slist: stmt slist{$$=mkopnode(SLST, $1, $2);}
     | stmt {$$=$1;}
     ;
stmt : ID '=' expr ';'   {
                              struct gsymbol *temp = lookup($1);
                              if(temp==NULL)
                              {
                                   printf("Identifier with name %s does not exist",$1);
                                   exit(1);
                              }
                              $$=mkopnode(EQ, mkleafnodeid(IDD, $1,temp->type), $3);
                         }
	| ID '[' expr ']' '=' expr ';'	{
     									struct gsymbol *temp = lookup($1);
										if(temp==NULL)
										{
											printf("Identifier with name %s does not exist",$1);
											exit(1);
										}
										$$=mkopnode(EQ,mkleafnodeidarray(IDD,$1,$3,temp->type),$6);
									}
	|READ'('ID')'';'    {
                              struct gsymbol *temp = lookup($3);
                              if(temp==NULL)
                              {
                                   printf("Identifier with name '%s' does not exist\n",$3);
                                   exit(1);
                              }
                              $$=mkopnode(REED, mkleafnodeid(IDD, $3,temp->type), NULL);
                         }

	|READ '(' ID '[' expr ']' ')' ';' 
     					{
                            struct gsymbol *temp = lookup($3);
							if(temp==NULL)
							{
								printf("Identifier with name %s does not exist",$3);
								exit(1);
							}
                            $$=mkopnode(REED, mkleafnodeidarray(IDD,$3,$5,temp->type),NULL);
     					}  

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
	| expr ANDY expr {$$=mkopnode(AND,  $1, $3);}
	| expr ORY expr {$$=mkopnode(OR,  $1, $3);}
	| NOTY expr {$$=mkopnode(NOT,  $1, NULL);}
	|'('expr')' {$$=$2;}
	|ID '[' expr ']'	{
							struct gsymbol *temp = lookup($1);
							if(temp==NULL)
							{
								printf("Identifier with name %s does not exist",$1);
								exit(1);
							}
							$$=mkleafnodeidarray(IDD,$1,$3,temp->type);
                        }
	|ID	{
			struct gsymbol *temp = lookup($1);
			if(temp==NULL)
			{
				printf("Identifier with name '%s' does not exist\n",$1);
				exit(1);
			}
			$$=mkleafnodeid(IDD, $1,temp->type);
		}
	;
expr :	NUM {$$=mkleafnode(NUM1, $1, 0);}
	|	COND {$$=mkleafnode(NUM1, $1, 1);}
	;
%%
void yyerror(const char* a)
{
printf("error\n");
return;
}

main()
{
	yyparse();
}