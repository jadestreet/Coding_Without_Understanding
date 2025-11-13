# include <stdlib.h>
# include <stdio.h>
typedef struct node{
	int value;
	struct node *next;
} *link;
void freeNode(link);
void freeList(link);
link insertBegin(link, int);
link insertEnd(link, int);
link removeBegin(link);
void printList(link);
void freeNode(link n){
	free(n);
}
void freeList(link head){
	link t;
	while (head != NULL) {
		t= head->next;
		freeNode(head);
		head= t;
	}
}
link insertBegin(link head, int value){
	link res= (link) malloc( sizeof(struct node) );
	res->value=value;
	res->next=head;
	return res;
}
link insertEnd(link head, int value){
	link t;
	link res= (link) malloc( sizeof(struct node) );
	res->value= value;
	res->next= NULL;
	if (head==NULL) return res;
	for(t=head; t->next!=NULL; t=t->next);
	t->next=res;
	return head;
}
link removeBegin(link head){
	link res=NULL;
	if (head!=NULL) {
		res= head->next;
		freeNode(head);
	}
	return res;
}
void printList(link head){
	link t;
	for (t=head; t !=NULL; t= t->next )
		printf("%d\n", t->value);
}
int main(){
	link head=NULL;
	head=insertBegin(head, 1);
	head=insertBegin(head, 2);
	head=insertEnd(head, 3);
	head=removeBegin(head);
	printList(head);
	freeList(head);
	return 0;
}