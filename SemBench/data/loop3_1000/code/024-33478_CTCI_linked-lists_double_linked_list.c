#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
	struct node *prev;
};
int main(){
	struct node *root;
	root = (struct node *) malloc(sizeof(struct node));
	root->next = NULL;
	root->data = 4;
	struct node *t = root;
	struct node *end;
	int i;
	for (i = 0; i < 10; i++){
		t->next = (struct node *) malloc(sizeof(struct node));
		t->next->prev = t;
		t = t->next;
		t->data = i;
	} 
	t = root;
	while(t != NULL){
		printf("%d\n", t->data);
		if(t->next == NULL){
			end = t;
		}
		t = t->next;
	}
	printf("End reached, lets go backwards!\n");
	t = end;
	while(t != NULL){
		if(t->next != NULL){
			free(t->next);
		}
		printf("%d\n", t->data);
		t = t->prev;
	}
	free(root);
}