%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "lex.yy.c"
	#include "arr.h" 
	int yylex(void);
	void yyerror(char *);
	int evaltree(node *);
	int m;
	int o;
	int i=0;
	int j=0;
%}

%token DIGIT
%token ID
%token Write
%token equal
%token Read
%token semicolon
%left '+' '-'
%left '*' '/'
%token If
%token then
%token endif
%token While
%token Do
%token endwhile
%token '@'
%%

slist	:	slist stmt'\n'  	{$2->left = $1;
                                         exectree($2);
                                         exit(1);}
		|slist stmt             {$2->left = $1;
		                         $$ = $2;} 	
            	|stmt                   {$$ = $1;}
		|stmt'\n'  	        {$$ = $1;
                                         exectree($2);
                                         exit(1);}
                |;                         

stmt    :       ID equal expr semicolon         {$2->left = $1;
                                                 $2->right = $3;
                                                 $4->right = $2;
                                                 $$ = $4;}

                |Write'(' expr ')' semicolon    {$1->left = $3;
                                                 $5->right = $1;
                                                 $$ = $5;}
                
                |Read'(' ID ')' semicolon       {$1->left = $3;
                                                 $5->right = $1;
                                                 $$ = $5;}
                 
                |If'(' expr ')' then slist endif semicolon { $1->left = $3;
                                                             $1->right = $6;
                                                             $8->right = $1;
                                                             $$ = $8;   
                                                            }
                
                |While'(' expr ')' Do slist endwhile semicolon  { $1->left = $3;
                                                                  $1->right = $6;
                                                                  $8->right = $1;
                                                                  $$ = $8;
                                                                }                                            
                                                 
                
                |
                ;                  
 
expr	:	DIGIT 		{$$=$1;}

                | ID            {$$ = $1;}
                              
		| '(' expr ')' 		{$$=$2;}

		| expr '+' expr 	{$2->left=$1;
					 $2->right=$3;
					 $$=$2;}
 
		| expr '-' expr 	{$2->left=$1;
					 $2->right=$3;
					 $$=$2;}

		| expr '*' expr 	{$2->left=$1;
					 $2->right=$3;
					 $$=$2;}

		| expr '/' expr 	{$2->left=$1;
					 $2->right=$3;
					 $$=$2;}

                | expr '<' expr          {$2->left=$1;
                                         $2->right=$3;
                                         $$=$2;}
                                         
                | expr '>' expr          {$2->left=$1;
                                          $2->right=$3;
                                          $$=$2;}
                
                | expr '@' expr          {$2->left=$1;
                                          $2->right=$3;
                                          $$=$2;}                                                                              		
		;

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}	

int main(void) {
	yyparse();
	return 0;
}
