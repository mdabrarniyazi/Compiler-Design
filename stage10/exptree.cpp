#include<iostream>
using namespace std;
int A[26];

FILE *fp;

enum node_type {
	ADD,
	SUB,
	AND,
	OR,
	NOT,
	MUL,
	DIV,
	EQ,
	EQA,
	LT,
	LE,
	GT,
	GE,
	EE,
	IFF,
	WILE,
	NUM1,
	IDD,
	REED,
	RITE,
	SLST

};
struct xtree {
int  data;
int type;
char* name;
enum node_type  nodeop;
struct gsymbol *gentry;
struct lsymbol *lentry;
int is_function;
struct xtree *arglist;
struct xtree *left;
struct xtree *right;
struct xtree *next;
} *root=NULL;

struct gsymbol *temp1;

struct xtree *mkleafnode(enum node_type nodeop, int val, int type)
{
root = new xtree; 
root->data = val;
root->type = type;
root->nodeop = nodeop;
root->left = NULL;
root->right = NULL;
return root;
}
struct xtree *mkleafnodeid(enum node_type nodeop, char *idname, int type)
{
root = new xtree; 
root->name = idname;
root->type = type;
root->nodeop = nodeop;
root->left = NULL;
root->right = NULL;
return root;
}

struct xtree *mkleafnodeidarray(enum node_type nodeop, char *idname, struct xtree *val, int type)
{
root = new xtree;
root->name = idname;
root->type = type;
root->nodeop = nodeop;
root->left = val;
root->right = NULL;
return root;
}

struct xtree *mkopnode(enum node_type nodeop, struct xtree *val1, struct xtree * val2)
{
root = new xtree;
root->nodeop = nodeop ;
root->left = val1;
root->right = val2;
return root;
}

struct xtree *mkfuncnode(enum node_type nodeop,int type, char *name,struct xtree *arglist)
{
root = new xtree;
root->nodeop = nodeop ;
root->type=type;
root->name=name;
root->arglist=arglist;
return root;
}

int check (struct xtree *a)
{
	if(a->left!=NULL && a->right!=NULL)
	{
		if(check(a->left)==check(a->right))
			return check(a->left);
		else
		{
			cout<<"Type Mismatch\n";
		}
	}		
	else if(a->left==NULL && a->right!=NULL)
	{	if(a->type==check(a->right))
			return(a->type);
		else
		{
			cout<<"Type Mismatch\n";
		}
	}
	else if(a->left!=NULL && a->right==NULL)
	{
		if(a->type==check(a->left))
			return (a->type);
		else
		{
			cout<<"Type Mismatch\n";
		}
	}
	else 
		return (a->type);
}

/*

int eval(struct xtree *root)
{
	if(root->nodeop==SLST)
	{	
		eval(root->left);	eval(root->right);	return 0;
	}

	
	else if(root->nodeop==EQ) 
	{
		if(root->left->left!=NULL)
		{
			temp1=global_lookup_array(root->left->name,eval(root->left->left));
		}
		else
			temp1=global_lookup(root->left->name);
		if(temp1==NULL)	
		{
			printf("undefined variable");
			exit(4);			
		}
		else
		{
			*(temp1->bind)=(eval(root->right));
		}
	}


	else if(root->nodeop==IDD) 
	{
		if(root->left==NULL)
		{
			temp1=global_lookup(root->name);
			if(temp1==NULL)
			{
				printf("unbounded variable");
				exit(2);
			}
		}
		else
		{
			temp1=global_lookup_array(root->name,eval(root->left));
		}
		return(*temp1->bind);
	}


	else if(root->nodeop==REED)
	{
		if(root->left->left!=NULL)
		{
			temp1=global_lookup_array(root->left->name,eval(root->left->left));
		}
		else
			temp1=global_lookup(root->left->name);
		if(temp1==NULL)
		{
			printf("undefine variable");
			exit(1);	
		}
		else
		{							
			float f ;
			cin >> f;
			*(temp1->bind) = static_cast<int>(f) ;
			if(cin.fail() || static_cast<float>(*(temp1->bind)) != f )
			{
				cout<<"Not Int\n";
				exit(0);
			}
			if(temp1->type==1 && *(temp1->bind)!=0 && *(temp1->bind)!=1)
			{
				cout<<"Not Bool\n";
				exit(0);
			}	
		}
	}

	else if(root->nodeop==RITE)	{printf("%d\n", eval(root->left));}
	else if(root->nodeop==ADD)	{if(check(root->left)==0 && check(root->right)==0) return (eval(root->left) + eval(root->right)); 
								else {cout<<"Mismatch\n";exit(0);}} 
	else if(root->nodeop==SUB)	{if(check(root->left)==0 && check(root->right)==0) return (eval(root->left) - eval(root->right));
								else {cout<<"Mismatch\n";exit(0);}}
	else if(root->nodeop==MUL)	{if(check(root->left)==0 && check(root->right)==0) return (eval(root->left) * eval(root->right));
								else {cout<<"Mismatch\n";exit(0);}}
	else if(root->nodeop==DIV)	{if(check(root->left)==0 && check(root->right)==0) return (eval(root->left) / eval(root->right));
								else {cout<<"Mismatch\n";exit(0);}}
	else if(root->nodeop==LT)	{if(check(root->left)==0 && check(root->right)==0) return (eval(root->left) < eval(root->right));
								else {cout<<"Mismatch\n";exit(0);}}
	else if(root->nodeop==GT)	{if(check(root->left)==0 && check(root->right)==0) return (eval(root->left) > eval(root->right));
								else {cout<<"Mismatch\n";exit(0);}}
	else if(root->nodeop==EE)	{if(check(root->left)== check(root->right)) return (eval(root->left) ==eval(root->right));
								else {cout<<"Mismatch\n";exit(0);}}
	else if(root->nodeop==AND)	{if(check(root->left)==1 && check(root->right)==1)
									if((eval(root->left)!=0 && eval(root->right)!=0)) 
										return 1;
									else
										return 0;
								else {cout<<"Mismatch\n";exit(0);}}
	else if(root->nodeop==OR)	{if(check(root->left)==1 && check(root->right)==1)
									if((eval(root->left)!=0 || eval(root->right)!=0)) 
	
										return 1;
									else
										return 0;
								else {cout<<"Mismatch\n";exit(0);}}
	else if(root->nodeop==NOT)	{
								if(check(root->left)==1)
									if((eval(root->left)!=0))
										return 0;
									else
										return 1;
								else {cout<<"Mismatch\n";exit(0);}}
	else if((root->nodeop==IFF) && eval(root->left))	return eval(root->right);
	else if(root->nodeop==WILE)	{while (eval(root->left)) int result = eval(root->right);}
	else if(root->nodeop==NUM1)	return root->data;
}
*/
int check_arg(struct argstruct *arglist,struct xtree *paramtr)
{
	while(1)
	{
		if(arglist==NULL && paramtr==NULL)
			return 1;
                if(((arglist!=NULL) && (paramtr!=NULL)) &&(((arglist->type==1) && (paramtr->type==1))||((arglist->type==0) &&(paramtr->type==0))))
		{
			
			arglist=arglist->next;
			paramtr=paramtr->next;
			return 1;
		}
		else
			{return 0;}
		

	}
}

//lex stage10.l; yacc -d stage10.y; g++ y.tab.c; ./a.out