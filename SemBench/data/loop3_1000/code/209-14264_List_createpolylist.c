#include <stdio.h>
#include <stdlib.h>
struct plist   
{	
	int coef;   
	int exp;    
	struct plist *next;    
};
typedef struct plist pnode;    
typedef pnode *plink;   
int printpoly(plink poly)
{
	plink ptr;
	ptr = poly->next;  
	while(poly != ptr)   
	{
		printf("%dX^%d",ptr->coef,ptr->exp);
		ptr = ptr->next;   
		if(poly != ptr)
			printf("+");
	}
	printf("\n");
	return 0;
}
plink createpoly(int *array,int len)
{
	plink head;    
	plink before;    
	plink new_node;   
	int i;
	head = (plink) malloc(sizeof(pnode));
   	if(!head)	  
	{
		return NULL;
	}
	head->exp = -1;  
	before = head;    
	for(i = len-1; i >= 0; i--)
	{
		if(array[i] != 0)
		{
			new_node = (plink) malloc(sizeof(pnode));
			if(!new_node)  
				return NULL;
			new_node->coef = array[i];   
			new_node->exp = i;  
			new_node->next = NULL;   
			before->next = new_node;    
			before = new_node;   
		}
	}
	new_node->next = head;   
	return head;    
}
plink polyadd(plink poly1,plink poly2)
{
	plink head1;   
	plink head2;    
	plink result;   
	plink before;   
	plink new_node;   
	head1 = poly1->next;   
	head2 = poly2->next;   
	result = (plink)malloc(sizeof(pnode));
	if(!result)
		return NULL;
	result->exp = -1;   
	before = result;    
	while(poly1 != head1 || poly2 != head2)
	{
		new_node = (plink)malloc(sizeof(pnode));
		if(!new_node)
			return NULL;
		if(head1->exp < head2->exp)  
		{
			new_node->coef = head2->coef;  
			new_node->exp = head2->exp;   
			head2 = head2->next;   
		}
		else
		{	if(head1->exp > head2->exp)   
			{
				new_node->coef = head1->coef;   
				new_node->exp = head1->exp;   
				head1 = head1->next;   
			}
			else   
			{
				new_node->coef = head1->coef + head2->coef;
				new_node->exp = head1->exp;  
				head1 = head1->next;  
				head2 = head2->next;   
			}
		}
		before->next = new_node;   
		before = new_node;      
	}
	new_node->next = result;   
	return result;   
}
int main()
{
	plink poly1;   
	plink poly2;   
	plink result;   
	int list1[6] = {4,0,3,0,7,0};  
	int list2[6] = {9,7,1,0,5,6};  
	poly1 = createpoly(list1,6); 
	printf("多项式1内容：");
	printpoly(poly1);  
	poly2 = createpoly(list2,6);  
	printf("多项式2内容：");
	printpoly(poly2);   
	result = polyadd(poly1,poly2);  
	printf("多项式相加结果：");
	printpoly(result);  
	return 0;
}