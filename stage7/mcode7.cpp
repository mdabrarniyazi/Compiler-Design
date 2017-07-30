#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "exptree.cpp"
//#include "symbol.cpp"

int count=-1;
int label=-1;

//FILE *fp;
//fp=fopen("output.txt","w");


int get_reg()
{
	count++;
	if(count >= 8)
	{
		printf("no of register exceeded"); exit(1);
	}

	return count;
}

void free_reg()
{
	count--;
	if(count < -1)
	{
		printf("in valid register");		
		exit(1);
	}
}

int get_lebel()
{
	label++;
	return label;
}

int get_bind(char *name)
{
	struct gsymbol *temp=lookup(name);
	return temp->bind;
}



int codgen(struct xtree *root)
{
	if(root!=NULL)
	{
		switch(root->nodeop)
		{
					case SLST:
					{		
						codgen(root->left);
						codgen(root->right);
						break;
					}

					case ADD:
					{ 
						int r1=codgen(root->left);
						int r2=codgen(root->right);
						fprintf(fp,"%s R%d ,R%d\n","ADD",r1,r2);
						free_reg();
						return r1;
					}

					case SUB:
					{
						int r1=codgen(root->left);
						int r2=codgen(root->right);
						fprintf(fp,"%s R%d ,R%d\n","SUB",r1,r2);
						free_reg();
						return r1;
					}

					case MUL:
					{
						int r1=codgen(root->left);
						int r2=codgen(root->right);
						fprintf(fp,"%s R%d ,R%d\n","MUL",r1,r2);
						free_reg();
						return r1;
					}

					case DIV:
					{
						int r1=codgen(root->left);
						int r2=codgen(root->right);
						fprintf(fp,"%s R%d ,R%d\n","DIV",r1,r2);
						free_reg();
						return r1;
					}
					case NUM1:
					{
						int r1=get_reg();
						fprintf(fp,"%s R%d ,%d\n","MOV",r1,root->data);
						return r1;
					}

					case IDD:
					{
						int r1=get_reg();
						if(root->left==NULL)		
						{
							
							fprintf(fp,"MOV R%d [%d]\n",r1,get_bind(root->name));
							return r1;
						}
						else
						{
							
							int r2=codgen(root->left);
							fprintf(fp,"MOV R%d ,%d\n",r1,get_bind(root->name));
							fprintf(fp,"ADD R%d ,R%d\n",r1,r2);

							free_reg();
							fprintf(fp,"MOV R%d ,[R%d]\n",r1,r1);	
							return r1;
						}
					}
				
					case LT: 
					{
						
						int r1=codgen(root->left);
						int r2=codgen(root->right);
						fprintf(fp,"%s R%d ,R%d\n","LT",r1,r2);
						free_reg();
						return r1;

					}
					case GT:
					{
						int r1=codgen(root->left);
						int r2=codgen(root->right);
						fprintf(fp,"%s R%d ,R%d\n","GT",r1,r2);
						free_reg();
						return r1;

					}
		
					case EE:
					{
						int r1=codgen(root->left);
						int r2=codgen(root->right);
						fprintf(fp,"%s R%d ,R%d\n","EQ",r1,r2);
						free_reg();
						return r1;

					}
					/*case LE:
					{
						int r1=codgen(root->left);
						int r2=codgen(root->right);
						fprintf(fp,"%s R%d ,R%d\n","LE",r1,r2);
						free_reg();
						return r1;

					}
					case GE:
					{
						int r1=codgen(root->left);
						int r2=codgen(root->right);
						fprintf(fp,"%s R%d ,R%d\n","GE",r1,r2);
						free_reg();
						return r1;

					}*/
				
					case RITE:
							{
								int r1=codgen(root->left);						
								fprintf(fp,"%s R%d\n","OUT",r1);
								free_reg();
								break;
	
							}
					case EQ:
							{
								
								if(root->left->left==NULL)
								{
									int r1=codgen(root->right);
									fprintf(fp,"MOV [%d] ,R%d \n",((lookup(root->left->name))->bind),r1);
									
									free_reg();
								}
								else
								{
									
									int r3=get_reg();
									int r2=codgen(root->left->left);
									
									fprintf(fp,"MOV R%d ,%d\n",r3,get_bind(root->left->name));
									fprintf(fp,"ADD R%d ,R%d\n",r3,r2);
									free_reg();
									int r1=codgen(root->right);
									fprintf(fp,"MOV [R%d] ,R%d\n",r3,r1);  										free_reg();
									free_reg();

								}

								break;
							}	
	
					case IFF:
						{
							int r1=codgen(root->left);
							int l1=get_lebel();
							int l2=get_lebel();

							fprintf(fp,"%s R%d, L%d\n","JNZ",r1,l1);
							free_reg();
							//codgen(ptr->middle);
							fprintf(fp,"JMP L%d\n",l2);
							fprintf(fp,"L%d:\n",l1);
							codgen(root->right);
														fprintf(fp,"L%d:\n",l2);
							break;
						}
					case WILE:

					{
						fprintf(fp,"%s\n","//--------");
						int l1=get_lebel();
						fprintf(fp,"L%d:\n",l1);
						int r1=codgen(root->left);
						int l2=get_lebel();
						fprintf(fp,"JZ R%d L%d\n",r1,l2);
						free_reg();
						codgen(root->right);
						fprintf(fp,"JMP L%d\n",l1);
						fprintf(fp,"%s\n","//------");
						fprintf(fp,"L%d:\n",l2);
						
						break;
					}
					case REED:
					{
						int r1=get_reg();
						fprintf(fp,"IN R%d\n",r1);
						if(root->left->left==NULL)
						{
							fprintf(fp,"MOV [%d] ,R%d\n",get_bind(root->left->name),r1); 	
							free_reg();
						}
						else
						{
							int r2=get_reg();							
							int r3=codgen(root->left->left);
							fprintf(fp,"MOV R%d ,%d\n",r2,get_bind(root->left->name));
							fprintf(fp,"ADD R%d ,R%d\n",r2,r3);
							free_reg();
							fprintf(fp,"MOV [R%d] ,R%d\n",r2,r1);
							free_reg();
							free_reg();
						}
						break;

					}



				

		}

	}
}

