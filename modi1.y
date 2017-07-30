%code requires
{
#define YYSTYPE double
}
%{
#include <stdio.h>
#include"lex.yy.c"
void yyerror(char *s);
extern char *yytext;
extern int yylineno;
%} 

%token NUMBER

%left '+' '-'
%left '*' '/'

%%

program: program expr '\n' { printf("%g\n", $2); }
       | program '\n'
       |
       ;
expr: expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { $$ = $1 / $3; }
    | NUMBER { $$ = $1; }
    ;

%%

void yyerror(char *s)
{
  printf("error\n");
  return;
}

int main(int argc, char *argv[])
{
  yylex();
  yyparse();

}