#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int vartype = -1;
int lbind=1;
int main_mem=0;

struct argstruct
{
	char *name;					//name of argument
	int type;					//type of argument
	int flag;
	struct argstruct *next;		//pointer to next argument
} *arghead=NULL,*argend=NULL;


struct gsymbol
{
	char *name;
	int type;
	int size;
	int bind;
	struct argstruct *arglist;
	struct gsymbol *next;

} *head=NULL;


void ginstall(char *name,int type,int size,struct argstruct *arglist)
{
	for(int i=0;i<size;i++)
	{
		struct gsymbol *node;
		node = new gsymbol;
		node->type=type;
		node->name=name;
		node->size=i;
		node->arglist=arglist;

	//	int *p = new int;
		node->bind=main_mem;
		if(i==size-1)
			main_mem=main_mem+size;
		node->next=NULL;
		if(head==NULL)
			head=node;
		else
		{
			node->next=head;
			head=node;
		}
	}
}

struct gsymbol *global_lookup(char *name)
{
	struct gsymbol *global_temp;
	global_temp=head;
	while(global_temp!=NULL)
	{
		if(strcmp(global_temp->name,name)==0)
			break;
		global_temp=global_temp->next;

	}
	return global_temp;
}

struct gsymbol *global_lookup_array(char *name,int size)
{
	struct gsymbol *global_temp;
	global_temp=head;
	while(global_temp!=NULL)
	{
		if(strcmp(global_temp->name,name)==0)
			if(global_temp->size == size)	
			{
				return global_temp;
			}
		global_temp=global_temp->next;
	}
	cout<<"undefined variable "<<name<<"["<<size<<"]\n";
	exit(1);
}

void is_exists_global(char *name)
{
	struct gsymbol *global_temp=global_lookup(name);
	if(global_temp!=NULL)
	{
		printf("redclaration");
		exit(5);
	}
}

void add_arg(char *name,int type,int flag)
{
	struct argstruct *node;
	node = new argstruct;
	node->type=type;
	node->name=name;

	node->next=NULL;
	if(arghead==NULL)
	{	
		arghead=node;
		argend=node;
	}
	else
	{
		argend->next=node;
		argend=node;
	}
}

int is_equal_arglist(struct argstruct *ptr1,struct argstruct *ptr2)
{
	while(1)
	{
		if((ptr1==NULL) && (ptr2==NULL)) 
			return 1;
		else if((ptr1!=NULL) && (ptr2!=NULL) && ((ptr1->type)==(ptr2->type)) && (strcmp((ptr1->name),(ptr2->name))==0))
		{
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else
			return 0;
	}
}

int arglookup(char *name)
{
	struct argstruct *temp=arghead;
	while(temp!=NULL)
	{
		cout<<temp->name<<"\n";

		if(strcmp((temp->name),name)==0)
		{
			printf("local variable in arg list declared again\n");		
			return 1;
		}
		temp=temp->next;
	}
	return 0;

}

void free_arglist()
{
	arghead=NULL;
	argend=NULL;
}

struct lsymbol
{
	char *name;
	int type;
	int bind;
	int flag;
	struct lsymbol *next;

} *localhead=NULL;



void linstall(int type, char *name, int flag)
{
		struct lsymbol *node;
		node = new lsymbol;
		node->type=type;
		node->name=name;
		node->bind=lbind;
		lbind=lbind+1;

		node->next=NULL;
		if(localhead==NULL)
			localhead=node;
		else
		{
			node->next=localhead;
			localhead=node;
		}
}




void arg_install()  //adds ids used in argument to local symbol table
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
}


struct lsymbol *local_lookup(char *name)
{
	struct lsymbol *local_temp;
	local_temp=localhead;
	while(local_temp!=NULL)
	{
		if(strcmp(local_temp->name,name)==0)
			break;
		local_temp=local_temp->next;

	}
	return local_temp;
}


void is_exists_local(char *funcname, char *name)
{
	struct lsymbol *local_temp=local_lookup(name);
	if(local_temp!=NULL)
	{
		printf("redclaration");
		exit(5);
	}
}

struct argstruct *get_arghead()
{
return arghead;
}