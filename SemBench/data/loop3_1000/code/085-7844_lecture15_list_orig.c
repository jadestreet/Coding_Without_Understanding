#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int val;
    struct node * next;
} Node;
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}
int pop(Node **head) {
    int retval;
    Node *next_node;
    if (*head == NULL) {
        return -1;
    }
    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;
    return retval;
}
void push(Node **head, int val) {
    if (*head == NULL) {
        return;
    }
    Node *first_node = make_node(val, *head);
    *head = first_node;
}
int remove_by_value(Node **head, int val) {
    Node *current = *head;
    Node *victim;
    if (current == NULL) {
        return 0;
    }
    while (current != NULL){
        if(current->next->val == val){
            current->next = current->next->next;
            free(current->next);
            return 1;
        }
        current = current->next;
    }
    return 0;
}
void reverse(Node **head) {
    Node *current = *head;
    Node *next, *temp;
    if (current == NULL || current->next == NULL){
        return;
    }
    next = current->next;
    current->next = NULL;
    while (next != NULL){
        temp = next->next;
        next->next = current;
        current = next;
        next = temp;
    }
    *head = current;
}
int main() {
    Node *test_list = make_node(1, NULL);
    test_list->next = make_node(2, NULL);
    test_list->next->next = make_node(3, NULL);
    test_list->next->next->next = make_node(4, NULL);
    int retval = pop(&test_list);
    push(&test_list, retval+10);
    remove_by_value(&test_list, 3);
    reverse(&test_list);
    print_list(test_list);
}