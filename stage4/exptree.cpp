#include<iostream>
int A[26];
enum node_type {
	ADD,
	SUB,
	MUL,
	DIV,
	EQ,
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
char cdata;
enum node_type  nodeop;
struct xtree *left;
struct xtree *right;
} *root=NULL;


struct xtree *mkleafnode(enum node_type nodeop, int val)
{
root = new xtree; 
root->data = val;
root->nodeop = nodeop;
root->left = NULL;
root->right = NULL;
return root;
}
struct xtree *mkleafnodeid(enum node_type nodeop, char cval)
{
root = new xtree; 
root->cdata = cval;
root->nodeop = nodeop;
root->left = NULL;
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

int eval(struct xtree *root)
{
if(root->nodeop==SLST) {eval(root->left); eval(root->right); return 0;}
else if(root->nodeop==EQ) {A[root->left->cdata-'a'] = eval(root->right);}
else if(root->nodeop==IDD) return A[root->cdata-'a'];
else if(root->nodeop==REED) {scanf("%d", &A[root->left->cdata-'a']);}
else if(root->nodeop==RITE) {printf("%d\n", eval(root->left));}
else if(root->nodeop==ADD) return eval(root->left) + eval(root->right); 
else if(root->nodeop==SUB) return eval(root->left) - eval(root->right);
else if(root->nodeop==MUL) return eval(root->left) * eval(root->right);
else if(root->nodeop==DIV) return eval(root->left) / eval(root->right);
else if(root->nodeop==LT) return (root->left->data < root->right->data);
else if(root->nodeop==GT) return (root->left->data > root->right->data);
else if(root->nodeop==EE) return (root->left->data == root->right->data);
else if(root->nodeop==IFF && eval(root->left)) return eval(root->right);
else if(root->nodeop==WILE) {while (eval(root->left)) int result = eval(root->right);}
else if(root->nodeop==NUM1) return root->data;
}

