#include <stdio.h>
#include <stdlib.h>
struct node {
   int value;
   struct node *next;
};
struct node* create_node(int value) {
    struct node *node_d;
    node_d = (struct node*) malloc(sizeof(struct node));
    if (NULL == node_d) {
        return NULL;
    }
    node_d->value = value;
    node_d->next = NULL;
    return node_d;
}
struct node* create_list(struct node *node) {
    struct node *list = NULL;
    if (NULL == node) {
        return NULL;
    }
    list = node;
    return list;
}
void append_node(struct node *list, struct node *node) {
    if (NULL == list || NULL == node) {
        return;
    }
    while (NULL != list->next) {
        list = list->next;
    }
    list->next = node;
}
struct node* remove_node(struct node *list, struct node *node) {
    struct node *prev = NULL;
    if (NULL == list || NULL == node) {
        return NULL;
    }
    while (list != node) {
        prev = list;
        printf("%d %d\n", (int) list, (int) node);
        list = list->next;
    }
    if (NULL != prev) {
        prev->next = node->next;
    }
    else {
        list = node->next;
    }
    free(node);
    node = NULL;
    return list;
}
static void print_list(struct node* list) {
    while (NULL != list) {
        printf("address: %d\n", (int) list);
        printf("next: %d\n", (int) list->next);
        printf("value: %d\n", (int) list->value);
        printf("----------\n\n");
        list = list->next;
    }
}
int main(void) {
    struct node *list = NULL;
    struct node *node_1, *node_2, *node_3;
    int value_1 = 1, value_2 = 2, value_3 = 3;
    node_1 = create_node(value_1);
    if (!node_1) {
        printf("Cannot create node :(\n");
    }
    list = create_list(node_1);
    node_2 = create_node(value_2);
    if (!node_2) {
        printf("Cannot create node :(\n");
    }
    node_3 = create_node(value_3);
    if (!node_3) {
        printf("Cannot create node :(\n");
    }
    append_node(list, node_2);
    append_node(list, node_3);
    printf("After adding two nodes.\n");
    print_list(list);
    list = remove_node(list, node_1);
    printf("After removing one node.\n");
    print_list(list);
    return 0;
}