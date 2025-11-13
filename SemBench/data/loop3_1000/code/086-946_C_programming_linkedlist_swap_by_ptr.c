#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node* head;
void swapNodes(struct node*x, struct node*y)
{
	struct node* temp,*pre1,*pre2,*curr1,*curr2;
	pre1 = pre2 = NULL;
	curr1 = curr2 = head;
	if (x == y) return;
	while (curr1!= x)
	{
		pre1 = curr1;
		curr1 = curr1->next;
	}
	while (curr2!= y)
	{
		pre2 = curr2;
		curr2 = curr2->next;
	}
	if (curr1 == NULL || curr2 == NULL)
		return;
	if (pre1 != NULL)
		pre1->next = curr2;
	else
		head = curr2; 
	if (pre2 != NULL)
		pre2->next = curr1;
	else 
		head = curr1;
	temp = curr2->next;
	curr2->next = curr1->next;
	curr1->next = temp;
}
struct node* create(int data1)
{
	struct node* temp;
	temp = (struct node*) malloc(sizeof(struct node));
      temp->data = data1;
      temp->next = head;
     head = temp;
 return temp;    
}
void printList()
{
	 struct node * node1;
	 node1 = head;
while(node1!=NULL)
	{
		printf("%d\t",node1->data);
		node1 = node1->next;
	}
printf("\n");
}
int main()
{
     struct node* a,*b,*c,*d,*e;
     a = create(15);
     b = create(12);
     c = create(1);
     d = create(0);
     e = create(50);
	printf("\n Linked list before calling swapNodes() ");
	printList();
	swapNodes(d,c);
	printf("\n Linked list after calling swapNodes() ");
	printList();
	return 0;
}