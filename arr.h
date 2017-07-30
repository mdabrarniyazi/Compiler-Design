#ifndef EXPRTREE_H
# define EXPRTREE_H
#include <string.h>
int arr[26];
char str[20]="Write";
typedef struct tnode{
		int int_flag;
		int char_flag;
		int cmd_flag;
		int op_flag;
		int int_val;
            	char op;
            	char char_val;
            	char cmd[20];
		struct tnode *right;
		struct tnode *left;
}node;

node *numnode(int value)
{
  node *ptr = (node *)malloc(sizeof(node));
  ptr->int_val = value; 
  ptr->int_flag = 1;
  ptr->char_flag = 0;
  ptr->cmd_flag = 0;
  ptr->op_flag = 0;
  ptr->left = NULL;
  ptr->right = NULL;
  return ptr;
};

node *opnode(char oprtr)
{
  node *ptr = (node *)malloc(sizeof(node));
  ptr->op = oprtr; 
  ptr->op_flag = 1;
  ptr->int_flag = 0;
  ptr->char_flag = 0;
  ptr->cmd_flag = 0;
  ptr->left = NULL;
  ptr->right = NULL;
  return ptr;
};

node *charnode(char chartr)
{
  node *ptr = (node *)malloc(sizeof(node));
  ptr->char_val = chartr; 
  ptr->op_flag = 0;
  ptr->int_flag = 0;
  ptr->char_flag = 1;
  ptr->cmd_flag = 0;
  ptr->left = NULL;
  ptr->right = NULL;
  return ptr;
};

node *cmdnode(char *cmmd)
{
  node *ptr = (node *)malloc(sizeof(node));
  strcpy(ptr->cmd,cmmd); 
  ptr->op_flag = 0;
  ptr->int_flag = 0;
  ptr->char_flag = 0;
  ptr->cmd_flag = 1;
  ptr->left = NULL;
  ptr->right = NULL;
  return ptr;
};

int evaltree(node *nd){
	if(nd->int_flag==1){
		return nd->int_val;
	}
	else if(nd->char_flag == 1)
	{
	  return arr[nd->char_val - 97];
	}
	else{
		if(nd->op=='+')
			return (evaltree(nd->left)+evaltree(nd->right));
		else if(nd->op=='-')
			return (evaltree(nd->left) - evaltree(nd->right));
		else if(nd->op== '*')
			return (evaltree(nd->left) * evaltree(nd->right));
		else if(nd->op=='/')
			return (evaltree(nd->left) / evaltree(nd->right));
		else if(nd->op == '<')
		        {
		          int n;
		          n = evaltree(nd->right) - evaltree(nd->left);
		          if(n > 0)
		            return 1;
		          else
		            return 0;   
		        }
		else if(nd->op == '>')
		        {
		          int n;
		          n = evaltree(nd->left) - evaltree(nd->right);
		          if(n > 0)
		            return 1;
		          else
		            return 0;   
		        }
		else if(nd->op == '@')                        
		        {
		          int n;
		          n = evaltree(nd->left) - evaltree(nd->right);
		          if(n == 0)
		            return 1;
		          else
		            return 0;   
		        }	
	}
}

void exectree(node *nd)
{
  if(nd != NULL)
  {
    if(nd->op_flag == 1)
    {
      if(nd->op == ';')
      {
        exectree(nd->left);
  
        exectree(nd->right);
      }
      else if(nd->op == '=')
      {
        arr[nd->left->char_val -97] = evaltree(nd->right);
      }
    }
    else if(nd->cmd_flag == 1)
    {
    	int nmt = strcmp(nd->cmd,"Write");
    	
      if(strcmp(nd->cmd,"If") == 0)
      {
        if(evaltree(nd->left) != 0)
        {
          exectree(nd->right);
        }
        else
          printf("wrong cond.");
      }
      else if(nmt == 0)
      {
        int n;
        n = evaltree(nd->left);
        printf("Ans. is:%d\n",n);
      }
      else if(strcmp(nd->cmd,"While") == 0)
      {
        if(evaltree(nd->left) != 0)
        {
          exectree(nd->right);
          exectree(nd);
        }  
      }
      else if(strcmp(nd->cmd,"Read") == 0)
      {
        int n,m;
        printf("enter value:");
        scanf("%d",&n);
        m = nd->left->char_val;
        arr[m -97] = n;
      } 
    }
  }
}

#define YYSTYPE node *

#endif
