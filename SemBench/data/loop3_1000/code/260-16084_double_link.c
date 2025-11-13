#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* previous;
    struct node* next;
}node;
node* createDoubleLink()
{
    node* pstHead = NULL;
    pstHead = malloc(sizeof(node));
    if(pstHead != NULL)
    {
        pstHead->data = 0;
        pstHead->previous = NULL;
        pstHead->next = NULL;
    }
    return pstHead;
}
int insertToTail(node* pstHead, int data)
{
    node* pstRight = NULL;
    node* pstNew = NULL;
    pstRight = pstHead;
    pstNew = malloc(sizeof(node));
    if(NULL == pstNew)
    {
        return -1;
    }
    else
    {
        pstNew->data = data;
        pstNew->previous = NULL;
        pstNew->next = NULL;
    }
    while(pstRight->next != NULL)
    {
        pstRight = pstRight->next;
    }
    pstRight->next = pstNew;
    pstNew->previous = pstRight;
    return 0;
}
int insertToHead(node* pstHead, int data)
{
    node* pstNew = NULL;
    pstNew = malloc(sizeof(node));
    if(NULL == pstNew)
    {
        return -1;
    }
    else
    {
        pstNew->data = data;
        pstNew->previous = NULL;
        pstNew->next = NULL;
    }
    if(NULL == pstHead->next)
    {
        pstHead->next = pstNew;
        pstNew->previous = pstHead;
    }
    else
    {
        pstNew->next = pstHead->next;
        pstNew->previous= pstHead; 
        pstHead->next->previous = pstNew;
        pstHead->next = pstNew;
    }
    return 0;
}
int insertByAscend(node* pstHead, int data)
{
    node* pstLeft = NULL;
    node* pstRight = NULL;
    node* pstNew = NULL;
    pstLeft = pstRight = pstHead;
    pstNew = malloc(sizeof(node));
    if(NULL == pstNew)
    {
        return -1;
    }
    else
    {
        pstNew->data = data;
        pstNew->previous = NULL;
        pstNew->next = NULL;
    }
    while((pstRight != NULL) && (data > pstRight->data))
    {
       pstLeft = pstRight;
       pstRight = pstRight->next;
    }
    pstLeft->next = pstNew;
    pstNew->previous = pstLeft;
    if(pstRight != NULL)
    {
        pstNew->next = pstRight;
        pstRight->previous = pstNew;
    }
    return 0;
}
int delete(node* pstHead, int data)
{
    node* pstLeft = NULL;
    node* pstRight = NULL;
    pstLeft = pstRight = pstHead;
    while((pstRight != NULL) && pstRight->data != data)
    {
        pstLeft = pstRight;
        pstRight = pstRight->next;
    }
    if(pstRight->data == data)
    {
        pstLeft->next = pstRight->next;
        if(pstRight->next != NULL)
        {
            pstRight->next->previous = pstLeft;
        }
        free(pstRight);
        return 0;
    }
    else
    {
        return -1;
    }
}
int linkInfo(node* pstHead)
{
    unsigned int uiLength = 0;
    unsigned int tmp = 0;
    node* pstRight = pstHead->next;
    node* pstLeft = NULL;
    printf("\nPrint the double link node in the sequence:\n");
    while(pstRight != NULL)
    {
        printf("\tLink data = %d\n", pstRight->data);
        pstLeft = pstRight;
        pstRight = pstRight->next;
        uiLength++;
    }
    tmp = uiLength;
    printf("\nPrint the double link node in the reverse sequence:\n");
    while(pstLeft != NULL && tmp--)
    {
        printf("\tReverse Link data = %d\n", pstLeft->data);
        pstLeft = pstLeft->previous;
    }
    printf("Total length = %d\n", uiLength);
    return uiLength;
}
void destroy(node* pstHead)
{
    node* pstLeft = NULL;
    node* pstRight = NULL;
    pstLeft = pstRight = pstHead;
    while(pstRight != NULL)
    {
        pstLeft = pstRight;
        pstRight = pstRight->next;
        free(pstLeft);
    }
    printf("\nDestroyed the double Link!\n");
    return;
}
int main()
{
    node* pstDoubleLink = NULL;
    pstDoubleLink = createDoubleLink();
    printf("\ninsert 5, 4, 3, 2, 1 in the head.\n");
    insertToHead(pstDoubleLink, 5);
    insertToHead(pstDoubleLink, 4);
    insertToHead(pstDoubleLink, 3);
    insertToHead(pstDoubleLink, 2);
    insertToHead(pstDoubleLink, 1);
    linkInfo(pstDoubleLink);
    printf("\ninsert 7, 9 in the tail.\n");
    insertToTail(pstDoubleLink, 7);
    insertToTail(pstDoubleLink, 9);
    linkInfo(pstDoubleLink);
    printf("\ninsert 6, 10 in the ascend order.\n");
    insertByAscend(pstDoubleLink, 6);
    insertByAscend(pstDoubleLink, 10);
    linkInfo(pstDoubleLink);
    printf("\nDelete 1, 5, 10, see the result.\n");
    delete(pstDoubleLink, 1);
    delete(pstDoubleLink, 5);
    delete(pstDoubleLink, 10);
    linkInfo(pstDoubleLink);
    destroy(pstDoubleLink);
    return 0;
}