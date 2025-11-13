#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node * ptrdiff;
};
struct node * xor(struct node *a, struct node *b);
void insert(int key,struct node **head);
void forwardtraverse(struct node **head);
void backwardtraverse(struct node **head);
void delete(int data, struct node **head);
struct node * xor(struct node *a, struct node *b){
return (struct node*)((unsigned int)a ^ (unsigned int)b) ;
}
void insert(int key,struct node **head){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->ptrdiff = xor(NULL,*head);
	if(*head == NULL){
		*head = temp;
		return;
	}
	(*head)->ptrdiff = xor(temp,(*head)->ptrdiff);
	*head = temp;
}
void forwardtraverse(struct node **head){
struct node *temp1,*temp2,*previous;
temp1 = *head;
if(temp1 == NULL){
	printf("List Empty");
	return;
}
previous = NULL;
while(temp1!=NULL){
	temp2 = temp1;
	printf(" %d-> ",temp1->data);
	temp1 = xor(previous,temp1->ptrdiff);
	previous = temp2;
}
printf("\n");
}
void backwardtraverse(struct node **head){
	struct node *current,*previous,*temp;
	current = *head;
	if(current == NULL){
		printf("List empty");
	}
	previous = NULL;
	while(current != NULL){
		temp = current;
		current = xor(previous,current->ptrdiff);
		previous = temp;
	}
	current = previous;
	previous = NULL;
	while(current != NULL){
		temp = current;
		printf(" %d-> ",current->data);
		current = xor(current->ptrdiff,previous);
		previous = temp;
	}
	printf("\n");
}
void delete(int data,struct node **head){
struct node *previous,*current,*temp;
current = *head;
if(current == NULL){
	puts("LIst is already empty");
	return;
}
previous = NULL;
while(current!=NULL && current->data!=data){
temp = current;
current = xor(previous,current->ptrdiff);
previous = temp;
}
if(current==NULL){
	puts("Element does not exists");
	return;
}
if(previous!=NULL)
previous->ptrdiff = xor(xor(previous->ptrdiff,current),xor(previous,current->ptrdiff));
temp = xor(current->ptrdiff,previous);
if(temp!=NULL)
temp->ptrdiff = xor(xor(temp->ptrdiff,current),previous);
if(previous == NULL){
	*head = current->ptrdiff;
}
printf("Deleted %d \n",current->data);
free(current);
}
int main(void){
	struct node *head = NULL;
	insert(1,&head);
	insert(2,&head);
	insert(3,&head);
	insert(4,&head);
	insert(5,&head);
	insert(6,&head);
	insert(7,&head);
	forwardtraverse(&head);
	backwardtraverse(&head);
	delete(99,&head);
	forwardtraverse(&head);
	backwardtraverse(&head);
	delete(1,&head);
	forwardtraverse(&head);
	backwardtraverse(&head);
	delete(4,&head);
	forwardtraverse(&head);
	backwardtraverse(&head);
	delete(7,&head);
	forwardtraverse(&head);
	backwardtraverse(&head);
	delete(2,&head);
	forwardtraverse(&head);
	backwardtraverse(&head);
	return 0;
}