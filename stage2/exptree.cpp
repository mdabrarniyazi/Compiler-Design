#include<iostream>
struct xtree {
float  data;
char opr;
struct xtree *left;
struct xtree *right;
} *root=NULL;

struct xtree *mkleafnode(float val)
{
root = new xtree;
root->data = val;
root->left = NULL;
root->right = NULL;
return root;
}

struct xtree *mkopnode(char op, struct xtree *val1, struct xtree * val2)
{
root = new xtree;
root->opr = op;
root->left = val1;
root->right = val2;
return root;
}

float eval(struct xtree *root)
{
if(root->opr=='+') return eval(root->left) + eval(root->right);
else if(root->opr=='-') return eval(root->left) - eval(root->right);
else if(root->opr=='*') return eval(root->left) * eval(root->right);
else if(root->opr=='/') return eval(root->left) / eval(root->right);
else if(root->left==NULL && root->right==NULL) return root->data;
}
