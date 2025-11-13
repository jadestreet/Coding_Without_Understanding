#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int value;
	struct node *next;
} node;
node *start, *temp;
void insert(int val) 
{
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode -> value = val;
	newNode -> next = NULL;
	if (start == NULL)
	{
		start = newNode;
	}
	else
	{
		temp = start;
		while (temp -> next)
		{
			temp = temp -> next;
		}
		temp -> next = newNode;
	}
}
void display() 
{
	temp = start;
	while (temp)
	{
		printf("%d\t", temp -> value );
		temp = temp -> next;
	}
	printf("\n");
}
void selectionSort()
{
	node *beg = start, *current;
	node *minimum = start;
	int t;
	while (beg -> next != NULL)
	{
		minimum = beg;
		current  = beg -> next;
		while (current)
		{
			if (current -> value < minimum -> value)
			{
				minimum = current;
			}
			current = current -> next;
		}
        t = beg -> value;
        beg -> value = minimum -> value;
        minimum -> value = t;
		beg = beg -> next;
	}
}
int main()
{
	insert(4);
	insert(6);
	insert(19);
	insert(2);
	insert(10);
	insert(3);
	printf("Before sorting : ");
	display();
	selectionSort();
	printf("After Sorting : ");
	display();
	return 0;
}