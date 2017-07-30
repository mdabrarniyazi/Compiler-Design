#ifndef MACHINECODE_H
#define MACHINECODE_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "eval.h"
#include "stage6_symbol.h"

int count=-1;
int label=-1;

FILE *fp;


int get_reg()
{
	count++;
/*	if(count >= 8)
	{
		printf("number of register exceeded"); exit(1);
	}*/

	return count;
}

void free_reg()
{
	count--;
/*	if(count < -1)
	{
		printf("in valid register");		
		exit(1);
	}*/
}

int get_lebel()
{
	label++;
	return label;
}

/*int get_bind(char *name)
{
	struct gsymbol *temp=lookup(name);
	return *(temp->bind);
}*/



int codgen(struct node *nd)
{
	if(nd!=NULL)
	{
		switch(nd->type)
		{
			case SEMI_TYPE:		
				codgen(nd->left);
				codgen(nd->right);
				break;

			case INT_TYPE:
				switch(nd->nodetype)
				{
					case TNODE_PLUS:
					{ 
						printf("plus\n");	
						int r1=codgen(nd->left);
						int r2=codgen(nd->right);
						fprintf(fp,"%s R%d ,R%d\n","ADD",r1,r2);
						free_reg();
						return r1;
					}

					case TNODE_MINUS:
					{
						int r1=codgen(nd->left);
						int r2=codgen(nd->right);
						fprintf(fp,"%s R%d ,R%d\n","SUB",r1,r2);
						free_reg();
						return r1;
					}

					case TNODE_MUL:
					{
						int r1=codgen(nd->left);
						int r2=codgen(nd->right);
						fprintf(fp,"%s R%d ,R%d\n","MUL",r1,r2);
						free_reg();
						return r1;
					}

					case TNODE_DIV:
					{
						int r1=codgen(nd->left);
						int r2=codgen(nd->right);
						fprintf(fp,"%s R%d ,R%d\n","DIV",r1,r2);
						free_reg();
						return r1;
					}
					case TNODE_NUM:
					{
						int r1=get_reg();
						fprintf(fp,"%s R%d ,%d\n","MOV",r1,nd->value);
						return r1;
					}

					case TNODE_ID:  //Fetch value from variable----variable values are stored at
					                //[get_bind_add_from_sym_table]   eg- [0],[15]
					{
						//check node in local symbol table
						//If node is in local symbol table that means it is local variable NOT FUNCTION
						if(nd->lentry!=NULL)
						{
							
							if(nd->lentry->flag==0) // local entry has flag as 0 means id is normal not pointer
							{
							int r1=get_reg();
	/*r1=BP                    */			fprintf(fp,"MOV R%d ,BP\n",r1);
	/*r2=bind_add_rel_to_BP    */			int r2=get_reg();
	/*r1=r1+r2                 */			fprintf(fp,"MOV R%d %d\n",r2,nd->lentry->bind);
	/*r1=[r1]		   */			fprintf(fp,"ADD R%d ,R%d\n",r1,r2);
							free_reg();
							fprintf(fp,"MOV R%d ,[R%d]\n",r1,r1);
							return r1;
							}
							else     //means id is pointer
							{
							int r1=get_reg();
	/*r1=BP                    */			fprintf(fp,"MOV R%d ,BP\n",r1);
	/*r2=bind_add_rel_to_BP    */			int r2=get_reg();
	/*r1=r1+r2                 */			fprintf(fp,"MOV R%d %d\n",r2,nd->lentry->bind);
	/*r1=[r1]		   */			fprintf(fp,"ADD R%d ,R%d\n",r1,r2);
	/*r1=[r1]		   */			free_reg();
							fprintf(fp,"MOV R%d ,[R%d]\n",r1,r1);
							fprintf(fp,"MOV R%d ,[R%d]\n",r1,r1); // 
							return r1;
							}
						}
						
						//else check node in global symbol table and IS A NOT A FUNCTION
						else if((nd->gentry!=NULL) && (nd->is_function==0))
						{
							//means its not an array
							int r1=get_reg();
							if(nd->left==NULL)
							{
	/*r1=[bind_add]   Here we are        */			fprintf(fp,"MOV R%d ,[%d]\n",r1,nd->gentry->bind);
	/*not adding BP because it's Global  */			return r1;
	/*variable and we keep direct add in bind */	}
							//means it is an array
							else
							{
	/*r2=index               */				int r2=codgen(nd->left);
	/*r1=bind_add (base add) */				fprintf(fp,"MOV R%d ,%d\n",r1,nd->gentry->bind); 
	/*r1=r1+r2               */				fprintf(fp,"ADD R%d ,R%d\n",r1,r2);
	/*r1=[r1]                */ 				free_reg();    //free reg is done to free reg returned by codgen(nd->left)
								fprintf(fp,"MOV R%d ,[R%d]\n",r1,r1);	
								return r1;
							}
						}
						//else check node in global symbol table and IS A FUNCTION
						else if((nd->gentry!=NULL) && (nd->is_function==1))
						{
						   //On seeing a CALL statement
				      /*Actions done by the CALLER on a call statement,
					1) It pushes the registers in use
					2) and also the actual arguments of the function call.
					3) It reserves space for RETURN Value (manual)and RETURN Address 
					  (this is done by the CALL Statement)   */
							
							int get_reg_count=count;  //get_reg_count stores get_regcount before setting it to 0
							while(count >= 0)
							{
								fprintf(fp,"PUSH R%d\n",count);
								count=count-1;
							}
							
							//function node's argulist is stored at node's left
							struct node *argulist=nd->left;
							struct argstruct *arg=nd->gentry->arglist; 
							while(argulist!=NULL)
							{
								
								if(arg->flag==0)  //means node is a FUNCTION with call by value
								{	
								printf("inside If\n");							
								int r1=codgen(argulist); //if arg is expr then have to eval that first
								fprintf(fp,"PUSH R%d\n",r1);
								free_reg();
								}
								
								else    //node is a function with call by reference
								{
	 								struct lsymbol *lentry=llookup(argulist->name);
									if(lentry!=NULL)  //in lsymbol table
									{	
										int r1=get_reg();
										int r2=get_reg();
		/*r1=BP                    */					
		/*r2=bind_add_rel_to_BP    */					fprintf(fp,"MOV R%d ,BP\n",r1);
		/*r1=r1+r2                 */					fprintf(fp,"MOV R%d %d\n",r2,lentry->bind);
		/*r1=[r1]		   */					fprintf(fp,"ADD R%d ,R%d\n",r1,r2);;
										
				                                                if(lentry->flag==0) 				
	/*PUSH blank space	   */							fprintf(fp,"\nPUSH R%d\n",r1);
										else  //pointer variable
										{
											fprintf(fp,"MOV R%d [R%d]\n",r1,r1);
		/*push add of variable [BP+1] */					fprintf(fp,"\nPUSH R%d\n",r1);
										}
	
										free_reg();
										free_reg();

									}
									else     //in gsymbol table
									{
								   
										if(argulist->left==NULL)
										{
										int r2=get_reg();
										fprintf(fp,"MOV R%d %d\n",r2,argulist->gentry->bind);
										fprintf(fp,"PUSH R%d\n",r2);
										free_reg();

										}
										else
										{
										int r2=get_reg();
										int r3=codgen(argulist->left);
										fprintf(fp,"MOV R%d %d\n",r2,argulist->gentry->bind);
										fprintf(fp,"ADD R%d R%d\n",r2,r3);
										fprintf(fp,"PUSH R%d\n",r2);			
										free_reg();
										free_reg();
										}
									}	
									
							        }
							argulist=argulist->next;
							arg=arg->next;
						}
							
							fprintf(fp,"PUSH R%d\n",0);       //space for return value

							fprintf(fp,"CALL %s\n",nd->name);
				      /* Actions done by a CALLER on Return,
				      1) Obtains the return value
				      2) Pops off the arguments but only after a check for reference type. 
				      If so, the current BP is used to restore the values.
				      3) Now restore the register values, be careful of the order.
				      4) While restoring don't lose the Return value which was
					Obtained in a different register. */
							fprintf(fp,"POP R%d\n",get_reg_count+1);
							argulist=nd->left;
							while(argulist!=NULL)
							{
								fprintf(fp,"POP R%d\n",get_reg_count+2);
								argulist=argulist->next;
							}
							
							count=get_reg_count+1;
							int i;
							for(i=0;i<count;i++)
								fprintf(fp,"POP R%d\n",i);

							
							return count;
						}
						
					}

				break;
				}
			case BOOL_TYPE:
				
				switch(nd->nodetype)
				{
					case TNODE_LT: 
					{
						
						int r1=codgen(nd->left);
						int r2=codgen(nd->right);
						fprintf(fp,"%s R%d ,R%d\n","LT",r1,r2);
						free_reg();
						return r1;

					}
					case TNODE_GT:
					{
						int r1=codgen(nd->left);
						int r2=codgen(nd->right);
						fprintf(fp,"%s R%d ,R%d\n","GT",r1,r2);
						free_reg();
						return r1;

					}
		
					case TNODE_EQ:
					{
						int r1=codgen(nd->left);
						int r2=codgen(nd->right);
						fprintf(fp,"%s R%d ,R%d\n","EQ",r1,r2);
						free_reg();
						return r1;

					}
					case TNODE_LE:
					{
						int r1=codgen(nd->left);
						int r2=codgen(nd->right);
						fprintf(fp,"%s R%d ,R%d\n","LE",r1,r2);
						free_reg();
						return r1;

					}
					case TNODE_GE:
					{
						int r1=codgen(nd->left);
						int r2=codgen(nd->right);
						fprintf(fp,"%s R%d ,R%d\n","GE",r1,r2);
						free_reg();
						return r1;

					}
					case TNODE_NE:				
					{
						int r1=codgen(nd->left);
						int r2=codgen(nd->right);
						fprintf(fp,"%s R%d ,R%d\n","NE",r1,r2);
						free_reg();
						return r1;

					}
					/*
					case TNODE_ID:
					{
						int r1=get_reg();
						if(nd->left==NULL)		
						{
							
							fprintf(fp,"MOV R%d ,[%d]\n",r1,get_bind(nd->name));
							return r1;
						}
						else
						{
							
							int r2=codgen(nd->left);
							fprintf(fp,"MOV R%d ,%d\n",r1,get_bind(nd->name));
							fprintf(fp,"ADD R%d ,R%d\n",r1,r2);
							free_reg();
							fprintf(fp,"MOV R%d ,[R%d]\n",r1,r1);	
							return r1;
						}
						
					}*/
					case TNODE_NUM:
					{
						int r1=get_reg();
						fprintf(fp,"%s R%d ,%d\n","MOV",r1,nd->value);
						return r1;
					}
					case TNODE_AND:
					{
					 	int r1=codgen(nd->left);
			    			int r2=codgen(nd->right);
			    			fprintf(fp, "MUL R%d, R%d\n",r1,r2 );
			    			free_reg();
			    			return r1;
			    		}
			    		case TNODE_OR:
			    		{
			    			int r1=codgen(nd->left);
			    			int r2=codgen(nd->right);
			    			fprintf(fp, "ADD R%d, R%d\n",r1,r2);
			    			int l1=get_lebel();
	/*JZ R1,L1    */			fprintf(fp, "JZ R%d, L%d\n",r1,l1);
	/*R1=1        */			fprintf(fp, "MOV R%d,%d\n",r1,1);
	/*L1:	      */  			fprintf(fp, "L%d:\n",l1);
	/*return R1   */	 		free_reg();
			    			return r1;
			    		}
			    		case TNODE_NOT:
			    		{
			    			int r1=codgen(nd->left);
			    			int l1=get_lebel();
			    			int l2=get_lebel();
	/*JNZ R1,L1    */			fprintf(fp, "JNZ R%d, L%d\n",r1,l1);
	/*R1=1        */    			fprintf(fp, "MOV R%d,%d\n",r1,1);
						fprintf(fp, "JMP L%d\n",l2);
	/*L1:	      */    			fprintf(fp, "L%d:\n",l1);
	/*R1=0		*/			fprintf(fp, "MOV R%d,%d\n",r1,0);
	/*L2:		*/			fprintf(fp, "L%d:\n",l2);
	/*return R1   */    	
			    			return r1;
			    			
					}
	
				}
			case VOID_TYPE:
				switch(nd->nodetype)
				{
					case  TNODE_WRITE:
							{
								int r1=codgen(nd->left);			
								fprintf(fp,"%s R%d\n","OUT",r1);
								free_reg();
								break;
	
							}
					case TNODE_ASS:
							{      //IF in LOCAL SYM TABLE
								if(nd->left->lentry!=NULL)
								{	
									int r1=codgen(nd->right); //node right has expr to be assigned
									int r2=get_reg();
									fprintf(fp,"MOV R%d ,BP\n" ,r2);
		/*r2=BP      */						int r3=get_reg();
		/*r3=bind_add relative to BP */				fprintf(fp,"MOV R%d %d\n",r3,nd->left->lentry->bind);
		/*r2=r2+r3		     */				fprintf(fp,"ADD R%d ,R%d\n",r2,r3);
									free_reg();
									if(nd->left->lentry->flag==0)	
		/*[r2]=r1;                   */					fprintf(fp,"MOV [R%d] ,R%d\n",r2,r1);
									else
									{
										fprintf(fp,"MOV R%d ,[R%d]\n",r2,r2);
		/*[[r2]]=r1		     */					fprintf(fp,"MOV [R%d] ,R%d\n",r2,r1);
									}
										
									free_reg();						
									free_reg();

								}
								//IF in GLOBAL SYM TABLE
								else
								{
									if(nd->left->left==NULL)				
									{
										int r1=codgen(nd->right);
										fprintf(fp,"MOV [%d] ,R%d\n",nd->left->gentry->bind,r1);
										free_reg();
									}
									else				
									{
										int r1=get_reg();
										fprintf(fp,"MOV R%d ,%d\n",r1,nd->left->gentry->bind);
										int r2=codgen(nd->left->left);
										fprintf(fp,"ADD R%d ,R%d\n",r1,r2);
										r2=codgen(nd->right);
										fprintf(fp,"MOV [R%d] ,R%d\n",r1,r2);
										free_reg();		
										free_reg();
									}
								}
								break;
							}	
								
					case TNODE_IF:
						{
							int r1=codgen(nd->left);
							int l1=get_lebel();
							int l2=get_lebel();

	/* r1= check_condition   */			fprintf(fp,"%s R%d, L%d\n","JNZ",r1,l1);
	/* JNZ R1,L1       	*/			free_reg();
	/* SLIST FALSE            */			codgen(nd->middle);
	/* JMP L2		*/			fprintf(fp,"JMP L%d\n",l2);
	/* L1:			*/			fprintf(fp,"L%d:\n",l1);
	/* SLIST TRUE		*/			codgen(nd->right);
	/* L2:			*/			fprintf(fp,"L%d:\n",l2);
	/* BREAK;		*/			break;
						}
					case TNODE_WHILE:
					{
						fprintf(fp,"%s\n","//--------");
						int l1=get_lebel();
						fprintf(fp,"L%d:\n",l1);
						int r1=codgen(nd->left);
						int l2=get_lebel();
						fprintf(fp,"JZ R%d L%d\n",r1,l2);
						free_reg();
						codgen(nd->right);
						fprintf(fp,"JMP L%d\n",l1);
						fprintf(fp,"%s\n","//------");
						fprintf(fp,"L%d:\n",l2);
						
						break;
					}
					case TNODE_READ:
					{
						int r1=get_reg();
						fprintf(fp,"IN R%d\n",r1);
						//CHECK IN LOCAL SYM TABLE
						if(nd->left->lentry!=NULL)
						{
							int r2=get_reg();	
							fprintf(fp,"MOV R%d ,BP\n",r2);
							int r3=get_reg();
							fprintf(fp,"MOV R%d %d\n",r3,nd->left->lentry->bind);
							fprintf(fp,"ADD R%d ,R%d\n",r2,r3);
							free_reg();
							fprintf(fp,"MOV [R%d] ,R%d\n",r2,r1);
							free_reg();
							free_reg();
						}
						//CHECK IN GLOBAL SYM TABLE
						else
						{
							if(nd->left->left==NULL)
							{
								fprintf(fp,"MOV [%d] ,R%d\n",nd->left->gentry->bind,r1);
								free_reg();
							}
							else
							{
								int r2=get_reg();
								fprintf(fp,"MOV R%d %d\n",r2,nd->left->gentry->bind);
								int r3=codgen(nd->left->left);
								fprintf(fp,"ADD R%d R%d\n",r2,r3);
								free_reg();

								fprintf(fp,"MOV [R%d] ,R%d\n",r2,r1);
								free_reg();
								free_reg();
							}
						}
						break;

					}



				}

		}

	}
}

#endif
