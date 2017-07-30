#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exptree.cpp"

int count = -1;
int label = -1;

int getreg()
{
	count++;
	if(count>=8)
		{printf("no of registers exceeded");
		exit(1);
		}
}

int freereg()
{
	count--;
	if(count<=-1)
	{
		printf("invalid register\n");
		exit(1);
	}
}

int getlabel()
{
	lebel++;
	return label;
}

int codegen(struct xtree *root)
{
	if(root!=NULL)
	{
		switch(root->nodeop)
		{
			case SLST:
				codegen(root->left);
				codegen(root->right);
				break;

			case ADD:
				{
					int r1=codgen(ptr->left);
					int r2=codgen(ptr->right);
					fprintf(fp,"%s R%d ,R%d\n","ADD",r1,r2);
					freereg();
					return r1;
				}

			case SUB:
				{
					int r1=codgen(ptr->left);
					int r2=codgen(ptr->right);
					fprintf(fp,"%s R%d ,R%d\n","SUB",r1,r2);
					freereg();
					return r1;
				}

			case MUL:
				{
					int r1=codgen(ptr->left);
					int r2=codgen(ptr->right);
					fprintf(fp,"%s R%d ,R%d\n","MUL",r1,r2);
					freereg();
					return r1;
				}

			case DIV:
				{
					int r1=codgen(ptr->left);
					int r2=codgen(ptr->right);
					fprintf(fp,"%s R%d ,R%d\n","DIV",r1,r2);
					freereg();
					return r1;
				}

			case NUM1:
				{
					int r1=get_reg();
					printf(fp,"%s R%d ,%d\n","MOV",r1,root->data);
					return r1;
				}

			case IDD:
				{
					int r1=get_reg();
						if(ptr->left==NULL)		
						{
							
							fprintf(fp,"MOV R%d [%d]\n",r1,root->cdata-'a'));
							return r1;
						}
						else
						{
							
							int r2=codgen(ptr->left);
							fprintf(fp,"MOV R%d ,%d\n",r1,root->cdata-'a');
							fprintf(fp,"ADD R%d ,R%d\n",r1,r2);
							free_reg();
							fprintf(fp,"MOV R%d ,[R%d]\n",r1,r1);	
							return r1;
						}
				}


		}
	}
}