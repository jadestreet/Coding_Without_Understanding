#include <stdio.h>
#include <stdlib.h>
typedef struct node_struct
{
    int num;
    struct node_struct *next;
}
node;
node *NewNode(int value);
void ShowLinkedList(node *linked_list);
void InsertNode(node *node_to_insert, node **pointer_to_list);
node *FindNode(node *linked_list, int node_value);
int main ()
{
    node *numberList = NULL;
    for (int i = 1; i <= 5; i++)
        InsertNode(NewNode(i), &numberList); 
    ShowLinkedList(numberList);
    free(numberList);
}
node *NewNode(int value)
{
    node *tmp = malloc(sizeof(node));
    tmp->num = value;
    tmp->next = NULL;
    return tmp;
}
void InsertNode(node *node_to_insert, node **pointer_to_list) 
{
    node_to_insert->next = *pointer_to_list;
    *pointer_to_list = node_to_insert;
}
void ShowLinkedList(node *linked_list)
{
    node *tmp = linked_list;
    while (tmp != NULL)
    {
        printf("%i\n", tmp->num);
        tmp = tmp->next;
    }
}
node *FindNode(node *linked_list, int node_value)
{
    node *tmp = NULL;
    tmp = linked_list;
    while (tmp != NULL)
    {
        if (tmp->num == node_value)
            return tmp;
        tmp = tmp->next;
    }
    return tmp;
}