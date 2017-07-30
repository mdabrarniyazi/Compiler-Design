#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int vartype = -1;

struct gsymbol
{
	char *name;
	int type;
	int size;
	int bind;
	struct gsymbol *next;
} *head=NULL;
int addr=0;
void ginstall(char *name,int type,int size)
{
	
	for(int i=0;i<size;i++)
	{
		struct gsymbol *node;
		node = new gsymbol;
		node->type=type;
		node->name=name;
		node->size=i;

		int p = addr;
		addr=addr+size;
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

struct gsymbol *lookup_array(char *name,int size)
{
//	cout<<"Looking For "<<name<<"["<<size<<"]\n";
	struct gsymbol *temp;
	temp=head;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,name)==0)
			if(temp->size == size)	
			{
//				cout<<"Found "<<temp->name<<"["<<temp->size<<"]\n";
				return temp;
			}
//		cout<<*(temp->name)<<"["<<temp->size<<"]";
		temp=temp->next;
	}
	cout<<"undefined variable "<<name<<"["<<size<<"]\n";
	exit(1);
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
