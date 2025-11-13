#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
void push(struct node** head, int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->next = *head;
    newNode->data = data;
    *head = newNode;
}
void print_link_list(struct node* head) {
    while (head) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("END\n");
}
void insert_at_end(struct node** head, int data) {
    if (*head == NULL) {
        push(head, data);
        return ;
    }
    struct node* last = *head;
    while (last->next) {
        last = last->next;
    }
    last->next = (struct node*)malloc(sizeof(struct node));
    last->next->data = data;
    last->next->next = NULL;
}
void insert_after(struct node* node, int data) {
    if (!node) {
        printf("\nEnter valid prev node ");
    }
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = (node)->next;
    (node)->next = newNode;
}
void swap(struct node* head, int vald1, int vald2) {
    struct node* val1 = NULL;
    struct node* val2 = NULL;
    short valb1, valb2;
    valb1 = valb2 = 0;
    while (head) {
        if (head->data == vald1) {
            valb1 = 1;
            val1 = head;
        } else if (head->data == vald2) {
            valb2 = 1;
            val2 = head;
        }
        head = head->next;
    }
    if (valb1 && valb2) {
        int temp = val1->data;
        val1->data = val2->data;
        val2-> data = temp;
    } else {
        printf("No given val present for swapping\n");
    }
}
int main() {
    struct node* head = NULL;
    push(&head, 5);
    push(&head, 10);
    insert_at_end(&head, 25);
    insert_after(head->next, 15);
    print_link_list(head);
    swap(head, 55, 10);
    print_link_list(head);
    return 0;
}