#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 0
#define ERROR -1
typedef struct Node {
	int key;
	char string[1024];
	struct Node *next;  
} Node;
typedef struct LinkedList {
	struct Node *first;
	struct Node *last;
	int size;
} LinkedList;
LinkedList* init_list();
void insert_end(LinkedList *list, int key, char string[]);
void insert_beginning(LinkedList *list, int key, char string[]);
int remove_end(LinkedList *list);
int remove_beginning(LinkedList *list);
int print_list(LinkedList *list);
void free_list(LinkedList *list);
char * get_string(LinkedList *list, int key);
LinkedList * init_list() {
	printf("initializing list...\n");
	LinkedList *list = (LinkedList*) malloc(sizeof(LinkedList));
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return list;
}
void insert_end(LinkedList *list, int key, char string[]) {
	printf("----------------------\n");
	list->size++;                    
	Node* newN = (Node*) malloc(sizeof(Node));
	newN->key = key;
	strcpy(newN->string, string);
	newN->next = NULL;
	Node* oldLast = list->last;      
	oldLast->next = newN;          
	list->last = newN;              
	printf("new Node(%p) at end: %d '%s' %p \n", newN, newN->key, newN->string,newN->next);
}
void insert_beginning(LinkedList *list, int key, char string[]) {
	printf("----------------------\n");
	list->size++;                    
	Node* oldFirst = list->first;    
	Node* newN = (Node*) malloc(sizeof(Node));
	newN->key = key;
	strcpy(newN->string, string);
	newN->next = oldFirst;
	list->first = newN;              
	if (list->size == 1)
		list->last = newN;
	printf("new Node(%p) at beginning: %d '%s' %p \n", newN, newN->key,newN->string, newN->next);
}
int remove_beginning(LinkedList *list) {
	printf("----------------------\n");
	if (list->size <= 0)
		return ERROR;
	list->size--;
	Node * oldFirst = list->first;
	printf("delete Node(%p) at beginning: '%d' '%s' '%p' \n", oldFirst,oldFirst->key, oldFirst->string, oldFirst->next);
	free(list->first); 			
	list->first = oldFirst->next;
	oldFirst = NULL;
	return OK;
}
int remove_end(LinkedList *list) {
	printf("----------------------\n");
	if (list->size <= 0)
		return ERROR;
	if (list->size == 1) {
		free(list->first);
		list->first = NULL;
		list->last = NULL;
		return OK;
	}
	printf("delete Node(%p) at end: '%d' '%s' '%p' \n", list->last,list->last->key, list->last->string, list->last->next);
	list->size--;           
	Node * startNode = list->first;
	Node * newLast = startNode;
	while (newLast->next->next != NULL) {
		newLast = newLast->next;
	}
	free(newLast->next); 	
	newLast->next = NULL;  	
	list->last = newLast; 	
	return OK;
}
int print_list(LinkedList *list) {
	printf("----------------------\n");
	if (list->size <= 0)
		return ERROR;
	printf("List.size = %d \n", list->size);
	Node *startN = list->first;  
	do {
		printf("Node#%d.string = '%s', .next = '%p' \n", startN->key,startN->string, startN->next);
		startN = startN->next;
	} while (startN != NULL);
	return OK;
}
void free_list(LinkedList *list) {
	printf("----------------------\n");
	printf("freeing list...\n");
	if (list != NULL && list->size > 0) {
		Node * startN = list->first;
		Node * temp = list->first;
		do {
			free(temp);
			startN = startN->next;
			temp = startN;
		} while (startN != NULL);
		free(list);
	}
}
char * get_string(LinkedList *list, int key) {
	printf("----------------------\n");
	Node *startN = list->first;  
	if(list->size == 1)
		return startN->string;
	while (startN->next != NULL) {
		if (startN->key == key)
			return startN->string;
		else
			startN = startN->next;
	}
	return NULL;
}
int main(void) {
	LinkedList *list = init_list();
	insert_beginning(list, 1, "im the first");
	insert_end(list, 2, "im the second");
	insert_end(list, 3, "im the third");
	insert_end(list, 4, "forth here");
	print_list(list);
	remove_end(list);
	print_list(list);
	remove_beginning(list);
	print_list(list);
	remove_end(list);
	print_list(list);
	printf("string at node with key %d = '%s' \n",2,get_string(list, 2));
	free_list(list);
	return OK;
}