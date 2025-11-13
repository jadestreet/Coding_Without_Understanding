#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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
void free_anything(Node **head) {
  Node *current = *head;
  Node *p;
  Node *next;
  for(p=current; NULL != p; p = next) {
      next = p->next;
      free(p);
  }
}
void print_list(Node *head) {
    Node *current = head;
    printf("%s", "[");
    while (current != NULL) {
        printf("%d, ", current->val);
        current = current->next;
    }
    printf("%s\n", "]");
}
int pop(Node **head) {
    int retval;
    Node *next_node = *head;
    if ((*head) == NULL) {
        return -1;
    } else{
          *head = next_node->next;
          retval = next_node->val;
          free(next_node);
          return retval;
    }
}
void push(Node **head, int val) {
    Node *new_node = make_node(val, *head);
    *head = new_node;
}
int remove_by_value(Node **head, int val) {
    Node *node = *head;
    Node *victim;
    if (node == NULL) {
      	return 0;
    }
    if (node->val == val) {
      	pop(head);
      	return 1;
    }
    for(; node->next != NULL; node = node->next) {
      	if (node->next->val == val) {
      	    victim = node->next;
      	    node->next = victim->next;
            free(victim);
      	    return 1;
      	}
    }
    return 0;
}
void reverse(Node **head) {
    Node *node = *head;
    Node *next, *temp;
    if (node == NULL || node->next == NULL) {
      	return;
    }
    next = node->next;
    node->next = NULL;
    while (next != NULL) {
      	temp = next->next;
      	next->next = node;
      	node = next;
      	next = temp;
    }
    *head = node;
}
int insert_by_index(Node **head, int val, int index) {
    int i;
    Node *node = *head;
    if (index == 0) {
      	push(head, val);
      	return 0;
    }
    for (i=0; i<index-1; i++) {
      	if (node == NULL) return -1;
      	node = node->next;
    }
    if (node == NULL) return -1;
    node->next = make_node(val, node->next);
    return 0;
}
Node *make_something() {
    Node *node1 = make_node(1, NULL);
    Node *node2 = make_node(2, NULL);
    Node *node3 = make_node(3, NULL);
    int val = pop(&node1);
    push(&node2, val);
    node3->next = node2;
    return node3;
}
int main() {
    Node *test_list = make_node(2, NULL);
    test_list->next = make_node(4, NULL);
    test_list->next->next = make_node(6, NULL);
    insert_by_index(&test_list, 1, 0);
    insert_by_index(&test_list, 3, 2);
    insert_by_index(&test_list, 5, 4);
    insert_by_index(&test_list, 7, 6);
    int res = insert_by_index(&test_list, 9, 8);
    assert(res == -1);
    printf("test_list ");
    print_list(test_list);
    printf("empty ");
    Node *empty = NULL;
    Node *something = make_something();
    free_anything(&something);
    insert_by_index(&empty, 1, 0);
    print_list(empty);
    free_anything(&test_list);
    free_anything(&empty);
    return 0;
}