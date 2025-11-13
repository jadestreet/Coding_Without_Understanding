#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int val;
    struct node *next;
} Node;
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}
void print_list(Node **list) {
    Node *current = *list;
    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}
int pop(Node **list) {
    Node* head = *list; 
    if (head==NULL){    
	return -1;
    }
    *list = head->next;  
    return head->val;    
}
void push(Node** list, int val) {
    Node* head = *list;  
    Node* newElement = make_node(val, head);   
    *list = newElement;	
}
int remove_by_value(Node **list, int val) {
    Node* current = *list;	
    Node* previous = NULL;	
    while (current != NULL) {	
        if (current->val == val){	
          if (previous == NULL){	
            pop(&current);
          } else {
            previous->next = current->next;
            free(current);
          }
        }
        previous = current;
        current = current->next;
    }
return 0;    
}
void reverse(Node **list) {
    Node* current = *list;
    Node* previous = NULL;
    while (current != NULL) {		
	Node* index=current->next;	
        current->next = previous;	
        previous = current;		
        current = index;		
    }
    *list = previous;		
}
int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);
    Node **list = &head;
    print_list(list);
    int retval = pop(list);
    print_list(list);
    push(list, retval+10);
    print_list(list);
    remove_by_value(list, 3);
    print_list(list);
    remove_by_value(list, 7);
    print_list(list);
    reverse(list);
    print_list(list);
}