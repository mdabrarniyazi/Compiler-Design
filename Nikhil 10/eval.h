#ifndef EVAL_H
#define EVAL_H
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "stage6_symbol.h"
#define INT_TYPE 25
#define VOID_TYPE 1
#define SEMI_TYPE 2
#define BOOL_TYPE 3
#define DUMMY_TYPE 4
#define TNODE_IF 4
#define TNODE_READ 5
#define TNODE_WRITE 6
#define TNODE_WHILE 7
#define TNODE_PLUS 8
#define TNODE_MINUS 9
#define TNODE_MUL 10
#define TNODE_DIV 11
#define TNODE_MOD 12
#define TNODE_ID 13
#define TNODE_ASS 14
#define TNODE_LT 15
#define TNODE_EQ 16
#define TNODE_GT 17
#define TNODE_LE 20
#define TNODE_GE 21
#define TNODE_NE 22
#define TNODE_NUM 18
#define TNODE_SEMI 19
#define TNODE_ID1 13
#define TNODE_AND 31
#define TNODE_OR 32
#define TNODE_NOT 33
#define TNODE_DUMMY 34

FILE *fp;
struct node 
{
	int type;       //basically return type (boolean,integer,semicolon,void type)
	int nodetype;   // while,if,read,write,plus,minus
	int value;	//value in case of integer node
	char *name;     //name of node
	 struct node *left,*middle,*right;
	 struct gsymbol *gentry;
	struct lsymbol *lentry;
	struct node *arglist;  //arglist in case of function node 
	int is_function;      //if function then 1 else 0
	struct node *next;
};

struct gsymbol *temp1;
struct node *treecreate(int type,int nodetype,int value,char *name,struct node *arglist, struct node *left,struct node *right,struct node *middle)
{
	struct node *ptr;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->type=type;
	ptr->nodetype=nodetype;
	ptr->value=value;
	ptr->name=name;
	ptr->left=left;
	ptr->right=right;
	ptr->middle=middle;
	ptr->arglist=arglist;
	ptr->is_function=0;
	ptr->gentry=NULL;
	ptr->lentry=NULL;
	ptr->next=NULL;
	return ptr;
}


//CREATES NODE IN CASE OF "ID" OR "ID[expr]" AND RETURN NULL IN CASE ID NOT DEFINED
struct node * create_idnode(char *name)
{
	struct node *nd=NULL;
	
	//First we will look into local scope i.e. local symbol table
	struct lsymbol *le=llookup(name);
	struct gsymbol *ge=glookup(name);
	
	if(le!=NULL)        //IF FOUND IN LOCAL THEN CREATE NODE
	{
		if((le->type)==1)
			nd=treecreate(INT_TYPE,TNODE_ID,-1,name,NULL,NULL,NULL,NULL);
		else
			nd=treecreate(BOOL_TYPE,TNODE_ID,-1,name,NULL,NULL,NULL,NULL);
		 
		nd->lentry=le;        //set local sym table entry in NODE OF ID	
		return nd;	
	}
	
	else if(ge!=NULL)    //ELSE IF FOUND IN GLOBAL THEN CREATE NODE
	{
		if((ge->type)==1)
			nd=treecreate(INT_TYPE,TNODE_ID,-1,name,NULL,NULL,NULL,NULL);
		else
			nd=treecreate(BOOL_TYPE,TNODE_ID,-1,name,NULL,NULL,NULL,NULL);
		
		nd->gentry=ge;       //set global sym table entry in NODE OF ID	
		return nd;	
	}
	
	else                //ELSE "ID" IS NOT AVAILABLE IN ANY SYMBOL TABLE SO RETURN NULL
		return NULL; 
	
}

//check if argument in declaration and in parameter are same
int check_arg(struct argstruct *arglist,struct node *paramtr)
{
	while(1)
	{
		if(arglist==NULL && paramtr==NULL)
			return 1;
                if(((arglist!=NULL) && (paramtr!=NULL)) &&(((arglist->type==1) && (paramtr->type==INT_TYPE))||((arglist->type==2) &&(paramtr->type==BOOL_TYPE))))
		{
			
			arglist=arglist->next;
			paramtr=paramtr->next;
			return 1;
		}
		else
			{return 0;}
		

	}
}






/*

void is_bool(struct node *ptr1)
{
	 if(ptr1!=NULL && ptr1->type==BOOL_TYPE)
	{
		printf("boolean type expression so read not allowed\n");
		exit(1);
	}
	

}
void is_defined(struct node *ptr)
{
	struct gsymbol *temp=lookup(ptr->name);
	if(temp==NULL)
	{
		printf("%s is undefined variable\n",ptr->name);
		exit(1);
	}
}


void is_int(struct node *ptr1)
{
	 if(ptr1!=NULL && ptr1->type==INT_TYPE)
	{
		printf("operator incompatible\n");
		exit(1);
	}
	

}

/*void is_correct(struct node *ptr1,struct node *ptr2)
{
	if(ptr1->type!=BOOL_TYPE || ptr2->type!=BOOL_TYPE) 
	{
		printf("boolean type needed");
		exit(1);
	}	

}
void is_same(struct node *ptr1,struct node *ptr2)
{
	if(ptr1->type!=ptr2->type)
	{
		printf("type mismatch\n");
		exit(0);
	}

}
void checksize(struct node *ptr)
{
	//struct gsymbol *temp1=lookup(ptr->name);
	temp1=lookup(ptr->name);
	if(temp1->size == 1)
	 {
	 printf("ID not defined as array type\n");
	 exit (0);
	 }
}
void set_type(struct node *ptr)
{
	struct gsymbol *temp=lookup(ptr->name);
	if(temp->type==0)
		ptr->type=INT_TYPE;
	else
		ptr->type=BOOL_TYPE;	

}
int evaltree(struct node *ptr)
{
	if(ptr!=NULL)
	{
	
	switch(ptr->type)
	{
		case SEMI_TYPE:
				
				evaltree(ptr->left);
				evaltree(ptr->right);
				break;
		case BOOL_TYPE: //incase of less than,greater than,and,or,not,boolean id
				switch(ptr->nodetype)
				{
					case TNODE_LT: return (evaltree(ptr->left) < evaltree(ptr->right));
					case TNODE_GT: return (evaltree(ptr->left) > evaltree(ptr->right));
					case TNODE_EQ: return (evaltree(ptr->left) == evaltree(ptr->right));		
					case TNODE_LE: return (evaltree(ptr->left) <= evaltree(ptr->right));
					case TNODE_GE: return (evaltree(ptr->left) >= evaltree(ptr->right));
					case TNODE_NE: return (evaltree(ptr->left) != evaltree(ptr->right));
					case TNODE_AND: return (evaltree(ptr->left) && evaltree(ptr->right));
					case TNODE_OR: return (evaltree(ptr->left) || evaltree(ptr->right));
					case TNODE_NOT: return (!evaltree(ptr->left));
					case TNODE_NUM: return (ptr->value);  //incase of bool variable containing either 0 or 1
					case TNODE_ID: //fetch value of boolean varible from binding location
							temp1=lookup(ptr->name);
							if(temp1==NULL)
							{
								printf("unbounded variable");
								exit(2);
							}
							else
							{
								if(ptr->left==NULL)  //normal variable
									{
									//printf("good");
									return(*(temp1->bind));
									}
								else		    // array variable
									{
									
									return (*((temp1->bind)+evaltree(ptr->left)));
									}
							}
				}
				break;
		case INT_TYPE:  //in case of plus,minus,multi,divide,assign
				switch(ptr->nodetype)
				{
					case TNODE_NUM:
						 return(ptr->value);
					case TNODE_PLUS:
						return (evaltree(ptr->left) + evaltree(ptr->right));
					case TNODE_MINUS:
						return (evaltree(ptr->left) - evaltree(ptr->right));
					case TNODE_MUL:
						return (evaltree(ptr->left) * evaltree(ptr->right));
					case TNODE_ASS: //assign the value in the binding location
							temp1=lookup(ptr->left->name);
							if(ptr->left->left==NULL)   //means only variable no array
							*(temp1->value)=evaltree(ptr->right);
							else    //means it is an array
							{
								*(temp1->value + evaltree(ptr->left->left))=evaltree(ptr->right);
							}	
																
				
							break;
					case TNODE_ID:  //fetch the value from binding location
							temp1=lookup(ptr->name);
							if(temp1==NULL)
							{
								printf("unbounded variable");
								exit(2);
							}
							else
							{
								if(ptr->left==NULL)  //normal variable
									{
									return(*(temp1->value));
									}
								else              //array variable
									{
									
									return (*(temp1->value+ evaltree(ptr->left)));
									}
							}
 			}
		case VOID_TYPE: //incase of while,read,write,if
				switch(ptr->nodetype)
				{
					case TNODE_WHILE:
						while(evaltree(ptr->left))
							evaltree(ptr->right);
						break;

					case  TNODE_WRITE:
							printf("%d",evaltree(ptr->left));
						
							
						break;

					case TNODE_READ:
						 temp1=lookup(ptr->left->name);
						if(temp1==NULL)
						{
							printf("undefine variable");
							exit(1);	
						}
						else
						{
							if(ptr->left->left==NULL)
							   {    printf("Enter value");
								scanf("%d",temp1->value);}
							else
							   {    printf("Enter value for array");
								scanf("%d",temp1->value+evaltree(ptr->left->left));}
						}

						break;

					case TNODE_IF:
								
								if(evaltree(ptr->left))
									evaltree(ptr->right);
								else
									evaltree(ptr->middle);

						}
	
				}		
	}
	
}

#define YYSTYPE struct node *            */

#endif
