#include <stdio.h>
#include <stdlib.h>
typedef struct _Node {
    int value;
    struct _Node *next;
}Node;
Node * get_node() {
    Node *p = (Node*)malloc(sizeof(Node));
    if(NULL == p) {
        return NULL;
    }
    p -> value = 0;
    p -> next = NULL;
    return p;
}
void del_node(Node *p) {
    if(NULL != p) {
        printf("%d ", p -> value);
        free(p);
    }
}
Node *get_last_node(Node *list) {
    if(NULL == list) {
        return list;
    }
    Node *p = list;
    for(p = list; p != NULL; p = p -> next) {
        if(NULL == p -> next) {
            return p;
        }
    }
    return NULL;
}
Node *add_node(Node *list, int value) {
    Node *p = get_node();
    if(NULL != p) {
        p -> value = value;
    }
    Node *pLast = get_last_node(list);
    if(NULL == pLast) {
        return p;
    }
    pLast -> next = p;
    return list;
}
Node * make_linked_list(int *pList, int len) {
    if(NULL == pList) {
        return NULL;
    }
    Node *p = NULL;
    printf("add  nodes : ");
    int i = 0;
    for(i = 0; i < len; i++) {
        printf("%d ", pList[i]);
        p = add_node(p, pList[i]);
    }
    printf("\n");
    return p;
}
void show_list(Node *pList) {
    if(NULL == pList) {
        return;
    }
    printf("show notes : ");
    Node *p = pList;
    for(p = pList; p != NULL; p = p -> next) {
        printf("%d ", p -> value);
    }
    printf("\n");
}
void free_list(Node *pList) {
    if(NULL == pList) {
        return;
    }
    free_list(pList -> next);
    if(NULL != pList) {
        del_node(pList);
    }
}
int main() {
    int list[] = {1, 4, 7, 3, 89, 43, 21, 11, 22, 90};
    Node *pList = make_linked_list(list, 10);
    show_list(pList);
    free_list(pList);
    return 0;
}