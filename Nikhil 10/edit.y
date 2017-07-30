%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <malloc.h>
	#include "lex.yy.c"
	#include "eval.h"
	#include "stage6_symbol.h"
	#include "machinecode.h"
	int type_keeper = -1; // 0 for integer and 1 for boolean
	int gtype=-1;  // 0 for integer and 1 for boolean
	int ltype=-1;
%}

%union {

	int integer;
	char character;
	char *string;
	struct node * tnode;
	struct argstruct *alist;
};

// SYNTAX : %token token_data_type token_name
%token <tnode> READ WRITE SEMICOLON ASSIGN IF THEN ELSE ENDIF WHILE DO ENDWHILE BEGINP END DECL ENDDECL GT GE LT LE EQ NE INT MAIN RETURN 
%token <integer> NUMBER BOOLNUM BOOL
%token <string> ID

// NON TERMINAL in grammer should also be declared as token
%type <tnode> expr slist stmt exprlist RetStmt
%type <alist> Arglist
%type <integer> Type
%left GT LT GE LE EQ NE AND OR NOT
%left '+''-'   
%left '*''/''%'   
%%

Prog : GDefblock FDefblock Mainblock {printf("OVERALL DONE\n");};
GDefblock : DECL GDefList ENDDECL {   
  					//Actions to be done before jumping to main
  				  /*when the Program starts all the global Variables are pushed on 
  				  to the stack Starting from memory location 0 */
					fprintf(fp,"START\n");
					fprintf(fp,"MOV BP ,0\n");
				/*MOV SP 1 will set SP to 1 i.e we have allocated space for two variables
				 as 0 and 1.Hence if we want space for 'N' Variables we will set SP to 'N-1'*/
					fprintf(fp,"MOV SP ,%d\n",main_mem-1);
                               /* It reserves space for RETURN Value (manual) and 
				 RETURN Address (this is done by the CALLStatement). */
					fprintf(fp,"PUSH R0\n");
					fprintf(fp,"CALL main\n");	
					fprintf(fp,"HALT\n");
				        printf("GDEF BLOCK Done\n");  
				             }
		|		{printf("EMPTY");}
		;
GDefList: GDefList GDecl
		|
		;
GDecl: Type {gtype=$1;} GIDlist SEMICOLON        	
	;

Type: INT	{$$=1;}
	| BOOL 	{$$=2;}
	;

GIDlist: GIDlist ',' GID		
		| GID
		;
GID:	ID		{  
				   
				  	is_gexists($1); 
				       	ginstall($1,gtype,1,NULL);
					}
		| ID '['NUMBER']'       {  
				  
				   	is_gexists($1); 
				       		ginstall($1,gtype,$3,NULL);	
					}
					
		|ID '(' Arglist ')'     {  
				  
				   	is_gexists($1); 
				   		$3=get_arghead();
				       		ginstall($1,gtype,0,$3);
				       		printf("GINSTALL DONE\n");
				       	free_arglist();	
					} 

		
		;
Arglist :  Arglist SEMICOLON Type {ltype=$3;} alist  {}
	  |Type {ltype=$1;} alist		     {}
	  |                                          {printf("FUNCTION ARG NULL\n");$$=NULL;}
	  ;

alist : 	 ID		      {arglookup($1);add_to_arglist($1,ltype,0);}
		|'&' ID 	      {arglookup($2);add_to_arglist($2,ltype,1);}
		|alist ',' ID	      {arglookup($3);add_to_arglist($3,ltype,0);}
		|alist ',' '&' ID     {arglookup($4);add_to_arglist($4,ltype,1);}
		;

FDefblock : FDefblock  Fdef {printf("FDEFBLOCK DONE\n");}
	|
	;
	
Fdef : Type ID '(' Arglist ')' {$4=get_arghead();
 				struct gsymbol *gtentry=glookup($2);
				if(gtentry==NULL)
				{
					printf("Function used in line %d is not declared\n",line);
					exit(0);
				}
				else
				{	
					
		 			if($1!=(gtentry->type))
					{			
						printf("Function declared with different return type in line %d ::TYPE MISMATCH\n",line);
						exit(0);
					}
					
					if(is_equal(gtentry->arglist,$4))
					{ 
						
						arginstall();	
						free_arglist();
						
					}
					else
					{
						
						printf("ARGUMENT LIST in line %d is not same in Declare and Definition\n",line);
						exit(0);
					}
					fprintf(fp,"%s:\n",$2); 	             
										     //Actions Done by CALLEE
										     //On entry,	          
		 			fprintf(fp,"PUSH BP\n");      		     //1.Saves context (pushes BP) And resets BP to SP
					fprintf(fp,"MOV BP ,SP\n");          	     //2.Pushes the local variables L1,L2,..etc.	
	 			}
	 		       }
	 		     	
      '{' LDefblock           {
      				//find the first local table entry with +ve BINDING i.e. LOCAL VARIABLES
	  			struct lsymbol *le=lhead;
				/*while(le!=NULL)
				{
					if(le->bind > 0)
					break;
					le=le->next;
				}	
				*/
				//2.PUSHES THE LOCAL VARIABLES 		
				while(le!=NULL && (le->bind > 0))
				{
					fprintf(fp,"%s\n","PUSH R0");//PUSH R0 will increase SP and put value of R0 in new allocates place
					le=le->next;
				}
      			      }
      	Body '}'              {
      	      				free_ltable();
      			      }
	
       ;
        
LDefblock : DECL LDefList ENDDECL {   }
		|		{printf("EMPTY LDEFBLOCK\n");}
		;
LDefList : LDefList Type {ltype=$2;} LIDlist SEMICOLON {}
	|
	;
LIDlist: LIDlist ',' ID     {  
				
				struct lsymbol *ltentry=llookup($3);
				if(ltentry==NULL)   //means variable not present in local symbol table
					linstall(ltype,$3,0);
				else
				{
					printf("variable of line %d already declared locally \n",line);
					exit(0);
				}
		             }
	  
	  |ID		     {  
	  			struct lsymbol *ltentry=llookup($1);
				if(ltentry==NULL)   //means variable not present in local symbol table
					linstall(ltype,$1,0);
				else
				{
					printf("variable of line %d already declared locally \n",line);
					exit(0);	
		             	}
		             }
	;
Body : BEGINP slist RetStmt END {
					codgen($2);                    //To generate machine code for body of func
					
				/* Actions done by CALLEE on encountering a return,
				1) Sets the RETURN VALUE at (BP-2).
				2) It clears the stack content, ie
				   It pops off local variables.
				3) BP of the caller is also obtained.
				4) Print the code for the function.
				5) IP is set to return address on the RET command.  */
					int r1=codgen($3);             //To calculate return value and store in r1
	 /*r1=return_value    */	int r2=get_reg();					
	 /*r2=BP              */	fprintf(fp,"MOV R%d BP\n",r2);
	 /*r3=-2	      */	int r3=get_reg();
	/*r2=r2+r3	      */	fprintf(fp,"MOV R%d -2\n",r3);
	 /*[BP-2]=return_value */	fprintf(fp,"ADD R%d ,R%d\n",r2,r3);
					free_reg();
					fprintf(fp,"MOV [R%d] R%d\n",r2,r1);
					free_reg();
					free_reg();
					
					//COUNT number of Local variables 
					struct lsymbol *le=lhead;
					int count=0;
					while(le!=NULL)
					{
						if(le->bind > 0)
						{  printf("Popped %s \n",le->name);
						   count++;
						}  
						le=le->next;
					}
					
					//NOW POP ALL LOCAL VARIABLES
					while(count>=1)	
					{
						fprintf(fp,"%s\n","POP R0");
						count=count-1;
					}
					fprintf(fp,"%s\n","POP BP"); //"SYNTAX: POP Register" top of stack is popped and stored in reg
					fprintf(fp,"%s\n","RET");
				}
	|
	;
RetStmt : RETURN expr SEMICOLON {$$=$2;}
;

Mainblock : INT MAIN '('')' {
				fprintf(fp,"main:\n");               //ON SEEING THE CALL STATEMENT
								     //Actions Done by CALLEE
								     //On entry,	          
		 		fprintf(fp,"PUSH BP\n");             //1.Saves context (pushes BP) And resets BP to SP
				fprintf(fp,"MOV BP ,SP\n"); 
				lbind=1;         //2.Pushes the local variables L1,L2,..etc.
		            }
	  '{' LDefblock     {  
	  			//find the first local table entry with +ve BINDING i.e. LOCAL VARIABLES
	  			struct lsymbol *le=lhead;
				/*while(le!=NULL)
				{
					if(le->bind > 0)
					break;
					le=le->next;
				}	
				*/
				//2.PUSHES THE LOCAL VARIABLES 		
				while(le!=NULL && (le->bind>0))
				{
					printf("Pushed %s\n",le->name);
					fprintf(fp,"%s\n","PUSH R0");//PUSH R0 will increase SP and put value of R0 in new allocates place
					le=le->next;
				}
				
		           }
	  
	   Body '}'     {printf("MAINBLOCK DONE\n");}
	   ;

	//always "-THE ONE YOU WANT TO BE EXECUTED FIRST-" in the left of node for INORDER TRAVERSAL
slist : slist stmt    { 
			$$=treecreate(SEMI_TYPE,TNODE_SEMI,-1,NULL,NULL,NULL,NULL,NULL);
			$$->left=$1;  //since slist will be executed first so in the left
			$$->right=$2;
		      }
	|stmt         {$$=$1;} 
        ;
stmt :  WHILE '('expr')' DO slist ENDWHILE SEMICOLON  
	{  
		if($3->type==BOOL_TYPE)
		{
			$$=treecreate(VOID_TYPE,TNODE_WHILE,-1,NULL,NULL,NULL,NULL,NULL);
			$$->left=$3;
			$$->right=$6;
		}
		else
			{printf("EXPECTED BOOLEAN TYPE EXPR IN WHILE IN LINE %d \n",line); exit(0);}

	 }

	|IF '('expr')' THEN slist ENDIF SEMICOLON 
  	{
		if($3->type==BOOL_TYPE)
		{
			$$=treecreate(VOID_TYPE,TNODE_IF,-1,NULL,NULL,NULL,NULL,NULL);
			$$->left=$3;
			$$->right=$6;
		}
		else
			{printf("EXPECTED BOOLEAN TYPE EXPR IN IF IN LINE %d \n",line); exit(0);}
	} 		

	|IF '('expr')' THEN slist ELSE slist ENDIF SEMICOLON
  	{
		if($3->type==BOOL_TYPE)
		{
			$$=treecreate(VOID_TYPE,TNODE_IF,-1,NULL,NULL,NULL,NULL,NULL);
			$$->left=$3;
			$$->right=$6;
			$$->middle=$8;
		}
		else
			{printf("EXPECTED BOOLEAN TYPE EXPR IN IF IN LINE %d \n",line); exit(0);}
	}    

  
	 | ID ASSIGN expr SEMICOLON 	
	 {
	 	struct node *nd;
	 	nd = create_idnode($1);
	 	if(nd==NULL)
	 	{	
	 		printf("ID OF LINE %d IS NOT DECLARED\n",line);
	 		exit(0);
	 	}
	 	
	 	//type checking of ID and EXPR
	 	if(nd->type==$3->type)
	 	{
	 		$$=treecreate(VOID_TYPE,TNODE_ASS,-1,NULL,NULL,NULL,NULL,NULL);
	 		$$->left=nd;
	 		$$->right=$3;
	 	}
	 	else
	 		{printf("TYPE MISMATCH OF ID AND EXPR IN LINE %d \n",line);exit(0);}
	 }	
	 		
	 	
	 	
	| ID '['expr ']' ASSIGN expr SEMICOLON
	 {
	 	if($3->type==BOOL_TYPE)
	 	{
	 		printf("EXPECTED INTEGER TYPE BOUND IN LINE %d\n ",line);
	 		exit(0);
	 	}
	 	
	 	struct node *nd;
	 	nd = create_idnode($1);
	 	if(nd==NULL)
	 	{	
	 		printf("ID OF LINE %d IS NOT DECLARED\n",line);
	 		exit(0);
	 	}
	 	
	 	//type checking of ID and EXPR
	 	if(nd->type==$3->type)
	 	{
	 		$$=treecreate(VOID_TYPE,TNODE_ASS,-1,NULL,NULL,NULL,NULL,NULL);
	 		$$->left=nd;
	 		$$->right=$6;
	 		$$->left->left=$3;
	 	}
	 	else
	 		{printf("TYPE MISMATCH OF ID AND EXPR IN LINE %d \n",line);exit(0);}
	 }		


	 | WRITE '(' expr ')' SEMICOLON
	 {
	 	if($3->type==INT_TYPE)
		{
			$$=treecreate(VOID_TYPE,TNODE_WRITE,-1,NULL,NULL,NULL,NULL,NULL);
             		$$->left=$3;
		}
		else
		{
			printf("BOOL TYPE GIVEN IN EXPR IN WRITE IN LINE %d\n",line);
			exit(0);
		}
	 }
	 | READ '(' ID ')' SEMICOLON
	{
	
		struct node *nd=create_idnode($3);
		if(nd==NULL)
		{
	 		printf("ID OF LINE %d IS NOT DECLARED\n",line);
	 		exit(0);
		}
		
		if(nd->type==INT_TYPE)		
		{
			$$=treecreate(VOID_TYPE,TNODE_READ,-1,NULL,NULL,NULL,NULL,NULL);
			$$->left=nd;
		}
		else
			{printf("READING OF BOOL VAL IN LINE %d NOT ALLOWED \n",line);exit(0);}		


		

	}	 
	|READ '(' ID '['expr']' ')' SEMICOLON 
	{
	 	if($5->type==BOOL_TYPE)
	 	{
	 		printf("EXPECTED INTEGER TYPE BOUND IN LINE %d\n ",line);
	 		exit(0);
	 	}
	
		struct node *nd=create_idnode($3);
		if(nd==NULL)
		{
	 		printf("ID OF LINE %d IS NOT DECLARED\n",line);
	 		exit(0);
		}
		
		//check whether ID is declared as array
		//if(nd->left->left==NULL)
		//	{printf("ID NOT DECLARED AS ARRAY TYPE IN LINE %d\n",line);exit(0);}
		
		
		if(nd->type==INT_TYPE)		
		{
			$$=treecreate(VOID_TYPE,TNODE_READ,-1,NULL,NULL,NULL,NULL,NULL);
			$$->left=nd;
			$$->left->left=$5;
		}
		else
			{printf("READING OF BOOL VAL IN LINE %d NOT ALLOWED \n",line);exit(0);} 
	  }      

	 ;
expr : expr '+' expr            {
					if(($1->type==INT_TYPE) && ($3->type==INT_TYPE))
					{
						//printf("---------------------");
						$$=treecreate(INT_TYPE,TNODE_PLUS,-1,NULL,NULL,NULL,NULL,NULL);
						$$->left=$1;
						printf("\n%d %d\n",$1->type,$3->type);
						$$->right=$3;
					}
					
				}
	 | expr '-' expr        {
	 				if(($1->type==INT_TYPE) && ($3->type==INT_TYPE))
					{
						$$=treecreate(INT_TYPE,TNODE_MINUS,-1,NULL,NULL,NULL,NULL,NULL);
						$$->left=$1;
						$$->right=$3;
					}
	 				
	 			}
	 | expr '/' expr        {
	 				if(($1->type==INT_TYPE) && ($3->type==INT_TYPE))
					{
						$$=treecreate(INT_TYPE,TNODE_DIV,-1,NULL,NULL,NULL,NULL,NULL);
						$$->left=$1;
						$$->right=$3;
					}
	 				
	 			}
	 | expr '%' expr        {
	 				if(($1->type==INT_TYPE) && ($3->type==INT_TYPE))
					{
						$$=treecreate(INT_TYPE,TNODE_MOD,-1,NULL,NULL,NULL,NULL,NULL);
						$$->left=$1;
						$$->right=$3;
					}
	 				
	 			}
	 | expr '*' expr        {
	 				if(($1->type==INT_TYPE) && ($3->type==INT_TYPE))
					{
						$$=treecreate(INT_TYPE,TNODE_MUL,-1,NULL,NULL,NULL,NULL,NULL);
						$$->left=$1;
						$$->right=$3;
					}
	 				
	 			}
	 | expr LT expr         {
	 				if(($1->type==INT_TYPE) && ($3->type==INT_TYPE))
					{
						$$=treecreate(BOOL_TYPE,TNODE_LT,-1,NULL,NULL,NULL,NULL,NULL);
						$$->left=$1;
						$$->right=$3;
					}
	 				
	 			}  	
	 | expr GT expr         {
	 				if(($1->type==INT_TYPE) && ($3->type==INT_TYPE))
					{
						$$=treecreate(BOOL_TYPE,TNODE_GT,-1,NULL,NULL,NULL,NULL,NULL);
						$$->left=$1;
						$$->right=$3;
					}
	 				
	 		        }
	 | expr EQ expr        {
	 				if(($1->type==INT_TYPE) && ($3->type==INT_TYPE))
					{
						$$=treecreate(BOOL_TYPE,TNODE_EQ,-1,NULL,NULL,NULL,NULL,NULL);
						$$->left=$1;
						$$->right=$3;
					}
	 				
	 		       }
	 | expr GE expr        {
	 				if(($1->type==INT_TYPE) && ($3->type==INT_TYPE))
					{
						$$=treecreate(BOOL_TYPE,TNODE_GE,-1,NULL,NULL,NULL,NULL,NULL);
						$$->left=$1;
						$$->right=$3;
					}
	 				
	 			}	
         | expr LE expr         {
	 				if(($1->type==INT_TYPE) && ($3->type==INT_TYPE))
					{
						$$=treecreate(BOOL_TYPE,TNODE_LE,-1,NULL,NULL,NULL,NULL,NULL);
						$$->left=$1;
						$$->right=$3;
					}
	 				
	 			}
         | expr NE expr         {
	 				if(($1->type==INT_TYPE) && ($3->type==INT_TYPE))
					{
						$$=treecreate(BOOL_TYPE,TNODE_NE,-1,NULL,NULL,NULL,NULL,NULL);
						$$->left=$1;
						$$->right=$3;
					}
	 				
	 			}
	 | expr AND expr        {
	 				if(($1->type==BOOL_TYPE) && ($3->type==BOOL_TYPE))
					{
						$$=treecreate(BOOL_TYPE,TNODE_AND,-1,NULL,NULL,NULL,NULL,NULL);
						$$->left=$1;
						$$->right=$3;
					}
	 				
	 			}
	 | expr OR expr	        {
	 				if(($1->type==BOOL_TYPE) && ($3->type==BOOL_TYPE))
					{
						$$=treecreate(BOOL_TYPE,TNODE_OR,-1,NULL,NULL,NULL,NULL,NULL);
						$$->left=$1;
						$$->right=$3;
					}
	 				
	 			}
	 | NOT expr             {
	 				if($2->type==BOOL_TYPE)
					{
						$$=treecreate(INT_TYPE,TNODE_NOT,-1,NULL,NULL,NULL,NULL,NULL);
						$$->left=$2;
					}
	 				
	 			}
	 | NUMBER               {
	                          
	 				$$=treecreate(INT_TYPE,TNODE_NUM,$1,NULL,NULL,NULL,NULL,NULL);
	 			}
	 
	 | '('expr')'          {$$=$2;} 
	 
	 |ID                   {
	 			struct node *nd;
	 			nd=create_idnode($1);
				if(nd==NULL)
				{
					printf("ID NAME OF LINE %d IS NOT PRESENT IN SYMBOL TABLE\n",line);
					exit(0);
				}
				else
					$$=nd;	
				}
	 
	|ID '['expr']' 		{
				if($3->type == BOOL_TYPE)
				{
					printf("INTEGER TYPE EXPECTED IN LINE NO %d ",line);
					exit(0);
				}
				struct node *nd;
				nd=create_idnode($1);
				if(nd==NULL)
				{
					printf("ID NAME OF LINE %d IS NOT PRESENT IN SYMBOL TABLE\n",line);
					exit(0);
				}
				else
					$$=nd;
				$$->left=$3;
				}
	|ID '(' exprlist ')'    {
				//check if function defined or not
				struct gsymbol *ge=glookup($1);
				if(ge==NULL)
				{	
					printf("FUNCTION USED IN LINE %d IS NOT DECLARED\n",line);
					exit(0);
				}
				
				//check if argument in declaration and in parameter are same
				if(check_arg(ge->arglist,$3))
				{
					
					if(ge->type==1)
						$$=treecreate(INT_TYPE,TNODE_ID,-1,$1,$3,NULL,NULL,NULL);
					else
						$$=treecreate(BOOL_TYPE,TNODE_ID,-1,$1,$3,NULL,NULL,NULL);
						
					$$->gentry=ge;
					$$->is_function=1;
					$$->left=$3;
				}
				else
				{
					printf("PARAMETER  MISMATCH IN LINE %d\n",line);
					exit(0);
				}
				}
	 ;
	 
exprlist : exprlist ',' expr    {
				    struct node *hd;
				    hd=$1;
				    while(hd->next!=NULL)
				    	hd=hd->next;
				    hd->next=$3;
				    $$=$1;
				}   
				    
	   |expr                {$$=$1;}
	   |			{$$=NULL;}
	   ;
	   
	   
%%

yyerror()
{
	printf("Error in line no. %d\n",line);
}

main()
{
	fp=fopen("out.txt","w");
	char fname[10];
	printf("Enter Filename ::\n");
	gets(fname);
	yyin=fopen(fname,"r");
	/*return*/yyparse();
	fclose(yyin);	
}
