#include<iostream>
using namespace std;
extern FILE *fp;
int A[26];

enum node_type {
	ADD,
	SUB,
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
char* name;
enum node_type  nodeop;
struct xtree *left;
struct xtree *right;
} *root=NULL;

struct gsymbol *temp1;

struct xtree *mkleafnode(enum node_type nodeop, int val)
{
root = new xtree; 
root->data = val;
root->nodeop = nodeop;
root->left = NULL;
root->right = NULL;
return root;
}
struct xtree *mkleafnodeid(enum node_type nodeop, char *idname)
{
root = new xtree; 
root->name = idname;
root->nodeop = nodeop;
root->left = NULL;
root->right = NULL;
return root;
}

struct xtree *mkleafnodeidarray(enum node_type nodeop, char *idname, struct xtree *val)
{
root = new xtree; 
root->name = idname;
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
/*
int eval(struct xtree *root)
{
if(root->nodeop==SLST) {eval(root->left); eval(root->right); return 0;}
else if(root->nodeop==EQ) 
					{
						if(root->left->left!=NULL)
						{
					//		cout<<eval(root->left->left);
							temp1=lookup_array(root->left->name,eval(root->left->left));
						}
						else
							temp1=lookup(root->left->name);
						if(temp1==NULL)	
						{
							printf("undefined variable");
							exit(4);			
						}
						else
						{
					//		if(root->left->left==NULL)
								*(temp1->bind)=eval(root->right);
						}
					}
else if(root->nodeop==IDD) 
					{
						if(root->left==NULL)
						{
							temp1=lookup(root->name);
							if(temp1==NULL)
							{
								printf("unbounded variable");
								exit(2);
							}
						}
						else
						{
	//						cout<<"Looking For "<<root->name<<"["<<eval(root->left)<<"]\n";
							temp1=lookup_array(root->name,eval(root->left));
	//						cout<<"Found "<<temp1->name<<"["<<temp1->size<<"]\n";
						}
						return(*temp1->bind);
					}

else if(root->nodeop==REED)
					{
						if(root->left->left!=NULL)
						{
					//		cout<<eval(root->left->left);
							temp1=lookup_array(root->left->name,eval(root->left->left));
						}
						else
							temp1=lookup(root->left->name);
						if(temp1==NULL)
						{
							printf("undefine variable");
							exit(1);	
						}
						else
						{
					//		if(root->left->left==NULL)
							
							cin>>*(temp1->bind);
							if (cin.fail())
							{
    							cout<<"Not Int\n";
    							exit(0);
							}
					//			cout<<"\n"<<temp1->name<<"\t";
					//		cout<<temp1->type<<"\t";
					//		cout<<temp1->size<<"\t";
					//		cout<<*temp1->bind<<"\n";
							//else
							//	scanf("%d",(temp1->bind +eval(root->left->left)));
						}
					}

else if(root->nodeop==RITE) {printf("%d\n", eval(root->left));}
else if(root->nodeop==ADD) return eval(root->left) + eval(root->right); 
else if(root->nodeop==SUB) return eval(root->left) - eval(root->right);
else if(root->nodeop==MUL) return eval(root->left) * eval(root->right);
else if(root->nodeop==DIV) return eval(root->left) / eval(root->right);
else if(root->nodeop==LT) return (eval(root->left) < eval(root->right));
else if(root->nodeop==GT) return (eval(root->left) > eval(root->right));
else if(root->nodeop==EE) return (root->left->data == root->right->data);
else if(root->nodeop==IFF && eval(root->left)) return eval(root->right);
else if(root->nodeop==WILE) {while (eval(root->left)) int result = eval(root->right);}
else if(root->nodeop==NUM1) return root->data;
}
*/