#ifndef STAGE6_SYMBOL_H
#define STAGE6_SYMBOL_H
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
int main_mem=0;
int lbind=1;


//------------------------------------LOCAL SYMBOL STABLE--------------------------------
struct lsymbol
{
	char *name;
	int type;
	int bind;
	int flag;       //will be used during call by reference
	struct lsymbol *next;
};

struct lsymbol *lhead=NULL;

void linstall(int type,char *name,int flag)
{
	struct lsymbol *le;
	le=(struct lsymbol *)malloc(sizeof(struct lsymbol));
	le->type=type;
	le->name=name;
	le->bind=lbind;
	le->flag=flag;
	printf("MEM LOC FOR LSYM TABLE :%d\n ",lbind);
	lbind=lbind+1;
	le->next=NULL;
	if(lhead==NULL)
	{
		lhead=le;
	}
	else
	{	
		le->next=lhead;
		lhead=le;
	}
}

struct lsymbol *llookup(char *name)
{
	struct lsymbol *temp;
	temp=lhead;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,name)==0)
			break;
		temp=temp->next;	
	}
	return temp;
}

void is_lexists(char *name)
{
	struct lsymbol *temp=llookup(name);
	if(temp!=NULL)
	{
		printf("redclaration in local symbol table");
		exit(0);
	}
}

void free_ltable()
{
printf("TABLE IS FREED\n");
lhead=NULL;

}


//-----------------------------------------------------------------------------------
struct gsymbol
{
	char *name;
	int type;
	int size;
	int bind;
	struct argstruct *arglist;
	struct gsymbol *next;
};

struct gsymbol *head=NULL;

void ginstall(char *name,int type,int size,struct argstruct *arglist)
{
	struct gsymbol *te;
	te=(struct gsymbol *)malloc(1*sizeof (struct gsymbol));
	te->type=type;
	te->name=name;
	te->size=size;
        te->arglist = arglist;
	te->bind=main_mem;
	printf("MEM LOC %d\n",main_mem);
	main_mem=main_mem+size;
	te->next=NULL;
	if(head==NULL)
	{
		head=te;
		
	}
	else
	{
		te->next=head;
		head=te;
	}
}	

struct gsymbol *glookup(char *name)
{
	struct gsymbol *temp;
	temp=head;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,name)==0)
			{break;}
		temp=temp->next;

	}
	return temp;
}

/*int global_var_space()
{
	return (main_mem-1);
}*/

void is_gexists(char *name)
{
	struct gsymbol *temp=glookup(name);
	if(temp!=NULL)
	{
		printf("redclaration of global variable\n");
		exit(0);
	}
}
//--------------------------------------------------ARGUEMENT LINKED LIST-----------------------
struct argstruct 
{
	int type;
	char *name;
	int flag;            //To check if call by value {0} or call by reference {1} 
	struct argstruct *next;
};
struct argstruct *arghead=NULL;
struct argstruct *argend=NULL;

void arginstall()  //adds ids used in argument to local symbol table
{
	int count=0;
	struct argstruct *temp;
	temp=arghead;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	lbind=-count-2;    //lbind will be used in linstall
	
	temp=arghead;
	while(temp!=NULL)
	{
		linstall(temp->type,temp->name,temp->flag);
		temp=temp->next;
	}
	lbind=1;   //so that next local variable gets stored from location 1
	printf("ARGINSTALL DONE\n");
}


void add_to_arglist(char *name,int type,int flag) // flag=0 for call by value ; flag=1 for call by reference
{
	struct argstruct *argentry=(struct argstruct *)malloc(sizeof(struct argstruct));
	argentry->type=type;
	argentry->name=name;
	argentry->flag=flag;
	
	if(arghead==NULL)
	{
		arghead=argentry;
		argend=argentry;
	}	
	else
	{
		argend->next=argentry;
		argend=argentry;
	}
}

void free_arglist()
{
	arghead=NULL;
	argend=NULL;
}




//arglookup takes name of var and check if that is present in arg link list 
void arglookup(char *name)
{
	struct argstruct *temp;
	temp=arghead;
	while(temp!=NULL)
	{
		if(strcmp((temp->name),name)==0)
		{
			printf("variable name already present in argument\n");		
			exit(0);
		}
		temp=temp->next;
	}
	printf("ARGLOOKUP DONE\n");
}
//is_eq_arglist RETURNS 1 IF BOTH ARE EQUAL ELSE 0
int is_equal(struct argstruct *ptr1,struct argstruct *ptr2)
{
	while(1)
	{
	//printf("PTR1 TYPE:: %d ||||| PTR2 TYPE::  ",ptr1->type);
		if((ptr1==NULL) && (ptr2==NULL)) 
			return 1;
		else if((ptr1!=NULL) && (ptr2!=NULL) && ((ptr1->type)==(ptr2->type)) && (strcmp((ptr1->name),(ptr2->name))==0))
		{
			printf("INSIDE IS_Equal else if part\n");
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else
			return 0;
	}
	//printf("HAHA\n");
}
struct argstruct *get_arghead()
{
return arghead;
}
#endif	
