#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int vartype = -1;

struct gsymbol
{
	char *name;
	int type;
	int size;
	int *bind;
	struct gsymbol *next;
} *head=NULL;

void ginstall(char *name,int type,int size)
{
	struct gsymbol *node;
	node = new gsymbol;
	node->type=type;
	node->name=name;
	node->size=size;

	int *p = new int;  
	node->bind=p;
	node->next=NULL;

	if(head==NULL)
	{
		head=node;
	}
	else
	{
		node->next=head;
		head=node;
	}
}

struct gsymbol *lookup(char *name)
{
	struct gsymbol *temp;
	temp=head;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,name)==0)
			break;
		temp=temp->next;

	}
	return temp;
}

void is_exists(char *name)
{
	struct gsymbol *temp=lookup(name);
	if(temp!=NULL)
	{
		printf("redclaration");
		exit(5);
	}
}