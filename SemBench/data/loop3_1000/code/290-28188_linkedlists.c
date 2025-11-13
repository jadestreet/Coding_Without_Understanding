#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct node 
{
    int val;
    struct node * next;
}node_t;
void print_list(node_t * head)
{
    node_t * current = head;
    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}
void node_append(node_t * head, int val)
{
    node_t * current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}
void push(node_t ** head, int val)
{
    node_t * new_node;
    new_node = malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}
int pop(node_t ** head)
{
    int val = -1;
    node_t * new_head = NULL;
    if(*head == NULL)
    {
        return -1;
    }
    new_head = (*head)->next;
    val = (*head)->val;
    free(*head);
    *head = new_head;
    return val;
}
int remove_last(node_t * head)
{
    int val = 0;
    if (head->next == NULL)
    {
        val = head->val;
        free(head);
        return val;
    }
    node_t * current =  head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    val = current->next->val;
    free(current->next);
    current->next = NULL;
    return val;
}
int remove_by_index(node_t ** head, int n)
{
    int val = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;
    if (n == 0)
    {
        return pop(head);
    }
    for (int i = n; i > 0; i--)
    {
        if (current->next == NULL)
        {
            return -1;
        }
        current = current->next;
    }
    temp_node = current->next;
    val = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);
    return val;
}
int remove_by_value(node_t ** head, int n)
{
    node_t * current = *head;
    node_t * temp_node = NULL;
    int val;
    if (current->val == n)
    {
        return pop(head);
    }
    while (current->next->val != n)
    {
        if (current->next == NULL)
        {
            return -1;
        }
        current = current->next;
    }
    temp_node = current->next;
    val = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);
    return val;
}
int linked_list_len(node_t * list)
{
    int i = 0;
    node_t * current = list;
    if (current == NULL)
    {
        return i;
    }
    i++;
    while (current->next != NULL)
    {
        current = current->next;
        i++;
    }
    return i;
}
int compare_lists (node_t * list1, node_t * list2)
{
    if (linked_list_len(list1) != linked_list_len(list2))
    {
        return 0;
    }
    else if ((linked_list_len(list1) == 0) && (linked_list_len(list2) == 0))
    {
        return 1;
    }
    node_t * current1 = list1;
    node_t * current2 = list2;
    while(current1->next != NULL)
    {
        if (current1->val != current2->val)
        {
            return 0;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return 1;
}
node_t * array_to_list(int arry[], size_t size)
{
    node_t * retlist = NULL;
    retlist = malloc(sizeof(node_t));
    retlist->next = NULL;
    retlist->val = 0;
    node_t * current = retlist;
    for (int i = 0; i < size; i++)
    {
       current->val = arry[i];
       if (!(i + 1 < size))
       {
           current->next = NULL;
       }
       else
       {
           current->next = malloc(sizeof(node_t));
           current = current->next;
       }
    }
    return retlist;
}
int main()
{
    node_t * test_list;
    test_list = malloc(sizeof(node_t));
    test_list->val = 98;
    test_list->next = malloc (sizeof(node_t));
    test_list->next->val = 37;
    test_list->next->next = malloc (sizeof(node_t));
    test_list->next->next->val = 42;
    test_list->next->next->next = malloc (sizeof(node_t));
    test_list->next->next->next->val = 2;
    test_list->next->next->next->next = malloc (sizeof(node_t));
    test_list->next->next->next->next->val = 5;
    test_list->next->next->next->next->next = NULL;
    int test_array [5] = {98, 37, 42, 2, 5};
    assert(linked_list_len(test_list) == 5);
    assert(compare_lists(test_list, test_list));
    node_t * list_copy = test_list;
    node_t * list_copy1 = test_list;
    assert(compare_lists(list_copy, list_copy1));
    push(&list_copy, 5);
    pop(&list_copy);
    assert(compare_lists(list_copy, list_copy1));
    node_append(list_copy, 5);
    remove_last(list_copy);
    assert(compare_lists(list_copy, list_copy1));
    assert(compare_lists(test_list, (array_to_list(test_array, (size_t)(sizeof(test_array) / sizeof(test_array[0]))))));
    return 0;
}