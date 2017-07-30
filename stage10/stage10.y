%{
#include"lex.yy.c"
#include<stdio.h>
#include<string>

#include"symbol.cpp"
#include"exptree.cpp"
#include "machinecode.h"
void yyerror(const char *);
using namespace std;
char *name;
char *func_name;
int global_type=-1;  // 0 for integer and 1 for boolean
int local_type=-1;
%}

%union{
int ival;
struct xtree *nptr;
char* chid;
struct argstruct *alist;
};

%token <ival> NUM
%type <alist> Arglist
%type <ival> type
%token <ival> COND
%token <ival> INT
%token <ival> BOOL
%token <chid> ID
%token <nptr> READ
%token <nptr> WRITE
%token <nptr> IF
%token <nptr> THEN
%token <nptr> BEGINP
%token <nptr> END
%token <nptr> RETURN
%token <nptr> ENDPRG
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
%token <nptr> MAIN
%type <nptr> expr
%type <nptr> stmt
%type <nptr> slist
%type <nptr> Retstmt

%type <nptr> exprlist
%left '+' '-'
%left '*' '/'
%left '<' '>'
%left EQQ ANDY ORY NOTY

%%

Prog: {cout<<"-------------------------\n";} GDefblock Fdeflist Mainblock 		{cout<<"\n";}

GDefblock : DECL GDefList ENDDECL			
			{
				fprintf(fp,"START\n");
				fprintf(fp,"MOV BP ,0\n");
				fprintf(fp,"MOV SP ,%d\n",main_mem-1);
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"CALL main\n");	
				fprintf(fp,"HALT\n");
				

			}
		|	{}
		;

GDefList : 									{}
		| GDecl GDefList						
		;

GDecl : type {global_type=$1;} GIdList ';'					
		;

GIdList : GId								{}
		| GIdList ',' GId
		;

GId : ID 		
		{
			is_exists_global($1);
			ginstall($1,global_type,1,NULL);
		}

	| ID '(' Arglist ')'	
		{
			is_exists_global($1);
			
			ginstall($1,global_type,1,$3);
			
			free_arglist();
			
		}
	| ID '[' NUM ']'
		{
			is_exists_global($1);
			ginstall($1,global_type,$3,NULL);
		}
		;


Fdeflist :{}
		| Fdeflist Fdef
		;

Fdef : type ID '(' Arglist ')' 
			{
				$4=get_arghead();
				struct gsymbol *identry=global_lookup($2);
				if(identry==NULL)
				{
					printf("function name is not declared \n error in lineno %d\n",line_no);
					exit(0);
				}
				else
				{
					if($1!=(identry->type))
					{
						printf("function declaration and function definition return type is not matching in line %d\n",line_no);
						exit(0);
					}
					if(is_equal_arglist((identry->arglist),$4))
					{
						arg_install();
						free_arglist();
					}
					else
					{
						printf("type or name mismatchinig\n");
						exit(0);
					}
					fprintf(fp,"%s:\n",$2);
					fprintf(fp,"%s\n","PUSH BP");
					fprintf(fp,"%s\n","MOV BP ,SP");
				}
			}
		'{' LDefblock	
			{
				struct lsymbol *temp=localhead;
				while(temp!=NULL && (temp->bind > 0))
				{
					fprintf(fp,"%s\n","PUSH R0");
					temp=temp->next;
				}
			}
		Body '}'
			{
				localhead=NULL;
			}
			;


Arglist  :							{cout<<"n";$$=NULL;}
		| Arglist ';' type {local_type=$3;} alist {$$=arghead;}
		| type {local_type=$1;} alist		{$$=arghead;}	
		;

alist :	ID
			{
				
				arglookup($1);
				add_arg($1,local_type,0);
				
			}
		|'&' ID
			{
				arglookup($2);
				add_arg($2,local_type,1);
			}
		|alist ',' ID
			{
				
				arglookup($3);
				
				add_arg($3,local_type,0);
				
			}
		|alist ',' '&' ID
			{
				arglookup($4);
				add_arg($4,local_type,1);
			}
		;





LDefblock : DECL LDefList ENDDECL	{}
		|							{}
		;

LDefList : LDefList type LIDlist ';' {local_type=$2;}
	|
	;
LIDlist: LIDlist ',' ID
		{  
			struct lsymbol *ltentry=local_lookup($3);
			if(ltentry==NULL)  
				linstall(local_type,$3,0);
			else
			{
				printf("variable of line %d already declared locally \n",line_no);
				exit(0);
			}
		}

	|ID
		{
			struct lsymbol *ltentry=local_lookup($1);
			if(ltentry==NULL)
				linstall(local_type,$1,0);
			else
			{
				printf("variable of line %d already declared locally \n",line_no);
				exit(0);
			}
		}
	;


Mainblock : INT MAIN '(' ')'
				{
					lbind=1;
					fprintf(fp,"%s\n","main:");
					fprintf(fp,"%s\n","PUSH BP");
					fprintf(fp,"%s\n","MOV BP ,SP");
				}
				'{' LDefblock 			
				{
					
					struct lsymbol *temp=localhead;		
					while(temp!=NULL && (temp->bind>0))
					{
						fprintf(fp,"%s\n","PUSH R0");
						temp=temp->next;
					}
				}
				Body '}'
				;

Body : BEGINP slist Retstmt END
	{
		
		codgen($2);
		fprintf(fp, "//---\n" );
		int r1=codgen($3);
		int r2=get_reg();
		fprintf(fp,"MOV R%d BP\n",r2);
		int r3=get_reg();
		fprintf(fp,"MOV R%d -2\n",r3);
		fprintf(fp,"ADD R%d ,R%d\n",r2,r3);
		free_reg();
		fprintf(fp,"MOV [R%d] R%d\n",r2,r1);
		free_reg();
		free_reg();
		struct lsymbol *le=localhead;
		int count=0;
		while(le!=NULL)
		{
			if(le->bind > 0)
			{
				count++;
			}  
			le=le->next;
		}
		while(count>=1)	
		{
			fprintf(fp,"%s\n","POP R0");
			count=count-1;
		}
		fprintf(fp,"%s\n","POP BP");
		fprintf(fp,"%s\n","RET");
		
	}
	|
	;
type :INT {$$=0;}
	|BOOL {$$=1;}
	;

slist: stmt slist{$$=mkopnode(SLST, $1, $2);}
	| stmt {$$=$1;}
	;

stmt : ID '=' expr ';'	{
							struct lsymbol *local_temp = local_lookup($1);
							if(local_temp==NULL)
							{
								struct gsymbol *global_temp = global_lookup($1);
								if(global_temp==NULL)
								{
									printf("Identifier with name %s does not exist",$1);
									exit(1);
								}
								else
								{
		
									struct xtree *newnode = mkleafnodeid(IDD, $1, global_temp->type);
									newnode->gentry = global_temp;
									$$=mkopnode(EQ, newnode, $3);
						//			$$->gentry=global_temp;	
								}
							}

							else
							{	
								struct xtree *newnode = mkleafnodeid(IDD, $1, local_temp->type);
								newnode->lentry = local_temp;
								$$=mkopnode(EQ, newnode, $3);
					//			$$->lentry=local_temp;
							}
						}
	| ID '[' expr ']' '=' expr ';'	{
										struct gsymbol *global_temp = global_lookup($1);
										if(global_temp==NULL)
										{
											printf("Identifier with name %s does not exist",$1);
											exit(1);
										}
										struct xtree *newnode = mkleafnodeidarray(IDD, $1,$3, global_temp->type);
										newnode->gentry = global_temp;
										$$=mkopnode(EQ, newnode, $6);
										$$->gentry=global_temp;
									}
	|READ'('ID')'';'	{
							struct lsymbol *local_temp = local_lookup($3);
							if(local_temp==NULL)		
							{
								struct gsymbol *global_temp = global_lookup($3);
								if(global_temp==NULL)
								{
									printf("Identifier with name '%s' does not exist\n",$3);
									exit(1);
								}
								else
								{
									struct xtree *newnode = mkleafnodeid(IDD, $3, global_temp->type);
									newnode->gentry = global_temp;
									$$=mkopnode(REED, newnode, NULL);
									$$->gentry=global_temp;
								}
							}
							else
							{
								struct xtree *newnode = mkleafnodeid(IDD, $3, local_temp->type);
								newnode->lentry = local_temp;
								$$=mkopnode(REED, newnode, NULL);
								$$->lentry=local_temp;

							}
						}

	|READ '(' ID '[' expr ']' ')' ';' 
						{
							struct gsymbol *global_temp = global_lookup($3);
							if(global_temp==NULL)
							{
								printf("Identifier with name %s does not exist",$3);
								exit(1);
							}

							struct xtree *newnode = mkleafnodeidarray(IDD, $3,$5, global_temp->type);
							newnode->gentry = global_temp;
							$$=mkopnode(REED, newnode, NULL);
							$$->gentry=global_temp;
						}

	| WRITE'('expr')'';' {$$=mkopnode(RITE, $3, NULL);}
	| IF'('expr')' THEN slist ENDIF ';' {$$=mkopnode(IFF, $3, $6);}
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
	| NOTY expr {$$=mkopnode(NOT,  $2, NULL);}
	|'('expr')' {$$=$2;}
	|ID '[' expr ']'	{
							struct gsymbol *global_temp = global_lookup($1);
							if(global_temp==NULL)
							{
								printf("Identifier with name %s does not exist",$1);
								exit(1);
							}
							

							$$=mkleafnodeidarray(IDD,$1,$3,global_temp->type);
							$$->is_function=0;
							$$->gentry=global_temp;
						}
	|ID	{
			struct lsymbol *local_temp = local_lookup($1);
			if(local_temp==NULL)
			{
				struct gsymbol *global_temp = global_lookup($1);
				if(global_temp==NULL)
				{
					printf("Identifier with name '%s' does not exist\n",$1);
					exit(1);
				}
				else
				{
					$$=mkleafnodeid(IDD, $1,global_temp->type);
					$$->gentry=global_temp;
				}
			}
			else
			{
				$$=mkleafnodeid(IDD, $1,local_temp->type);
				$$->lentry=local_temp;
			}	
			$$->is_function=0;
		}

	
	|	NUM {$$=mkleafnode(NUM1, $1, 0);}
	

	|	COND {$$=mkleafnode(NUM1, $1, 1);}
	

	| ID '(' exprlist ')'	

		{
			struct gsymbol *global_temp = global_lookup($1);
			if(global_temp==NULL)
			{
				printf("Identifier with name '%s' does not exist\n",$1);
				exit(1);
			}
			else
			{
				$$=mkleafnodeid(IDD, $1,global_temp->type);
				$$->gentry=global_temp;
			}
		
		
			//check if argument in declaration and in parameter are same
			if(check_arg(global_temp->arglist,$3))
			{
				//mkfuncnode(nodeType,return_type,NameOfFunc,Arguments)
				
				$$=mkfuncnode(IDD,global_temp->type,$1,$3);
				
				$$->gentry=global_temp;
				$$->is_function=1;
				$$->left=$3;
		
			}
			else
			{
				printf("PARAMETER  MISMATCH IN LINE %d\n",line_no);
				exit(0);
			}
		}
		;
	
exprlist : exprlist ',' expr    {
				    struct xtree *hd;
				    hd=$1;
				    while(hd->next!=NULL)
				    	hd=hd->next;
				    hd->next=$3;
				    $$=$1;
				}   
				    
	   |expr                {$$=$1;}
	   |			{$$=NULL;}
	   ;

Retstmt :  RETURN expr ';'			{$$=$2;}

%%
void yyerror(const char* a)
{
printf("error\n");
return;
}

main()
{
	fp=fopen("out.txt","w");
	char fname[10];
	printf("Enter Filename ::\n");
	cin>>fname;
	yyin=fopen(fname,"r");
	if(!yyin)
	{
		cout<<"INVALID FILE\n";
		exit(1);
	}
	/*return*/yyparse();
	fclose(yyin);	
}