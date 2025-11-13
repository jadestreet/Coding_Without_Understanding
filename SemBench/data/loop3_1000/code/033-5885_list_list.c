#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode{
    char name[16];
    char gender;
    int  age;
    struct ListNode * next;
};
typedef struct ListNode* Node;
Node list_create_node(const char * name, char gender, int age){
    Node node = (Node) malloc(sizeof(struct ListNode));
    strcpy(node->name, name);
    node->gender = gender;
    node->age = age;
    return node;
}
void list_append(Node rootNode, Node node){
    Node item = rootNode;
    while(item->next != NULL){
        item = item->next;
    }
    item->next = node;
    node->next = NULL;
}
void list_prepend(Node rootNode, Node node){
    node->next = rootNode->next;
    rootNode->next = node;
}
Node list_find(Node rootNode, const char * name){
    Node node = rootNode;
    while(node != NULL){
        if( ! strcmp(node->name, name)){
            return node;
        }
        node = node->next;
    }
    return NULL;
}
Node list_delete(Node rootNode, Node node){
    Node previous = NULL, current = rootNode;
    while(current != NULL){
        if(current == node){
            if(previous == NULL){
                rootNode = current->next;
            }else{
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
    return rootNode;
}
Node list_delete_by_name(Node rootNode, const char * name){
    Node node = list_find(rootNode, name);
    if(node != NULL){
        rootNode = list_delete(rootNode, node);
    }
    return rootNode;
}
void list_display(Node rootNode){
    Node item = rootNode;
    printf("+----------------+--+----+\n");
    while(item != NULL){
        printf("|%16s|%2c|%4d|\n", item->name, item->gender, item->age);
        item = item->next;
    }
    printf("+----------------+--+----+\n");
}
void list_destroy(Node rootNode){
    Node nextNode = NULL;
    while(rootNode != NULL){
        nextNode = rootNode->next;
        free(rootNode);
        rootNode = nextNode;
        if(nextNode != NULL){
            nextNode = nextNode->next;
        }
    }
}
int main(void){
    Node root = list_create_node("Duan Zhiyan", 'M', 27);
    list_display(root);
    Node node = list_create_node("Xie Jun", 'F', 28);
    printf("Append Xie Jun\n");
    list_append(root, node);
    list_display(root);
    printf("Prepend Mr. Smart\n");
    list_prepend(root, list_create_node("Mr. Smart", 'M', 36));
    list_display(root);
    node = list_find(root, "Mr. Smart");
    printf("Searching for: Mr. Smart\n");
    printf("Node found: %s, %c, %d\n", node->name, node->gender, node->age);
    printf("Delete Mr. Smart\n");
    root = list_delete(root, node);
    list_display(root);
    printf("Delete Duan Zhiyan\n");
    root = list_delete_by_name(root, "Duan Zhiyan");
    list_display(root);
    list_destroy(root);
    return 0;
}