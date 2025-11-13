#include<stdio.h>
#include<stdlib.h>
struct Node {
	int d;			
	struct Node* next;	
};
struct Node* getNewNode(int data) {
	struct Node *nw_node;
	nw_node = (struct Node*) malloc(sizeof(struct Node));	
	if (nw_node == NULL) {
		return NULL;
	}
	nw_node->d = data;
	nw_node->next = NULL;
	return nw_node;
}
int addAtPos(struct Node **start, struct Node* nw_node, int pos) {
	struct Node* temp;		
	if (*start == NULL) {
		*start = nw_node;
		return 1;
	} else {
		int i = 0;
		temp = *start;
		while (temp->next != NULL && i < pos-1) {	
			temp = temp->next;
			i++;
		}
		if (i != pos-1 && pos != 0) {
			return 0;
		} else if (pos == 0) {
			nw_node->next = *start;
			*start = nw_node;
			return 1;
		}
		else {
			nw_node->next = temp->next;		
			temp->next = nw_node;		
			return 1;
		}
	}
}
int addFront(struct Node **start, struct Node* nw_node) {
	return addAtPos(start, nw_node, 0);
}
int addLast(struct Node **start, struct Node* nw_node) {
	struct Node* temp;		
	if (*start == NULL) {
		return addAtPos(start, nw_node, 0);
	} else {
		int pos = 0;
		temp = *start;
		while (temp->next != NULL) {	
			temp = temp->next;
			pos++;
		}
		return addAtPos(start, nw_node, pos+1);
	}
}
struct Node* deleteAtPos(struct Node **start, int pos) {
	if (*start == NULL) {
		return NULL;
	} else {
		struct Node* temp = *start;		
		if((*start)->next == NULL) {
			if(pos == 0) {
				*start = NULL;
				return temp;
			}
		} else {
			int i = 0;
			while (temp->next->next != NULL && i < pos-1) {	
				temp = temp->next;
				i++;
			}
			if (i != pos-1 && pos != 0) {
				return NULL;
			} else if (pos == 0) {
				*start = (*start)->next;
				return temp;
			} else {
				struct Node* tmp = temp->next;
				temp->next = temp->next->next;	
				return tmp;
			}
		}
	}
}
struct Node* deleteFirst(struct Node **start) {
	return deleteAtPos(start, 0);
}
struct Node* deleteLast(struct Node **start) {
	if (*start == NULL) {
		return NULL;
	} else {
		struct Node* temp = *start;		
		if((*start)->next == NULL) {
			return 	deleteAtPos(start, 0);
		}
		int pos = 0;
		while (temp->next->next != NULL) {
			temp = temp->next;
			pos++;
		}
		return deleteAtPos(start, pos+1);
	}
}
void traverse(struct Node *start) {
	printf("Linked List\n");
	if(start == NULL) {
		printf("Linked List is Empty");
	} else {
		struct Node* temp = start;		
		while (temp->next != NULL) {
			printf(" %d ->", temp->d);
			temp = temp->next;
		}
		printf(" %d", temp->d);
	}
	printf("\n\n");
}
int search(struct Node *start, int data) {
	struct Node* temp = start;
	int found = 0, i = 0;
	while (temp != NULL) {
		if(temp->d == data) {
			found = 1;
			break;
		}
		i++;
		temp = temp->next;
	}
	if (found != 0) {
		return i;
	} else {
		return -1;
	}
}
void searchResult(int d, int pos) {
	if(pos == -1) {
		printf("Element %d is not in list\n", d);
	} else {
		printf("Element %d is found at index %d\n", d, pos);
	}
	printf("\n");
}
void deleteResult(struct Node** node) {
	if(*node == NULL) {
		printf("Deletion is unsuccessfull\n");
	} else {
		printf("Node %d is deleted\n", (*node)->d);
		free(*node);
	}
	printf("\n");
}
void insertResult(int res, int d) {
	if(res == 0) {
		printf("Invalid Index\n");
	} else {
		printf("Element %d is inserted\n", d);
	}
	printf("\n");
}
int main() {
	struct Node *start = NULL;
	struct Node *newNode, *freeNode;
	int res;
	newNode = getNewNode(23);
	if (newNode != NULL) {
		res = addFront(&start, newNode);
		insertResult(res, 23);
	}
	traverse(start);
	newNode = getNewNode(25);
	if (newNode != NULL) {
		res = addLast(&start, newNode);
		insertResult(res, 25);
	}
	newNode = getNewNode(46);
	if (newNode != NULL) {
		res = addLast(&start, newNode);
		insertResult(res, 46);
	}
	traverse(start);
	newNode = getNewNode(12);
	if (newNode != NULL) {
		res = addFront(&start, newNode);
		insertResult(res, 12);
	}
	newNode = getNewNode(11);
	if (newNode != NULL) {
		res = addFront(&start, newNode);
		insertResult(res, 11);
	}
	traverse(start);
	newNode = getNewNode(14);
	if (newNode != NULL) {
		res = addAtPos(&start, newNode, 3);
		insertResult(res, 14);
	}
	traverse(start);
	freeNode = deleteFirst(&start);
	deleteResult(&freeNode);
	traverse(start);
	res = search(start, 14);
	searchResult(14, res);
	res = search(start, 12);
	searchResult(12, res);
	traverse(start);
	freeNode = deleteLast(&start);
	deleteResult(&freeNode);
	traverse(start);
	freeNode = deleteAtPos(&start, 1);
	deleteResult(&freeNode);
	traverse(start);
	printf("\n");
	return 0;
}