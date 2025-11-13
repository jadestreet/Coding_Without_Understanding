#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
node* createLink()
{
    node* pstHead = NULL;
    pstHead = malloc(sizeof(node));
    if(NULL != pstHead)
    {
        pstHead->data = 0;
        pstHead->next = NULL;
    }
    return pstHead;
}
int destroyLink(node* pstHead)
{
    node* pstLeft = NULL;
    node* pstRight = pstHead;
    while(pstRight != NULL)
    {
        pstLeft = pstRight;
        pstRight = pstRight->next;
        free(pstLeft);
    }
    printf("\nDestroyed the Link\n");
    return 0;
}
int insertToHead(node* pstHead, int data)
{
    node* pstLeft = NULL;
    node* pstRight = NULL;
    node* pstNewNode = NULL;
    pstLeft = pstHead;
    pstNewNode = malloc(sizeof(node));
    if(NULL == pstNewNode)
    {
        return -1;
    }
    else
    {
        pstNewNode->data = data;
        pstNewNode->next = NULL;
    }
    if(NULL == pstLeft->next)
    {
        pstLeft->next = pstNewNode;
    }
    else
    {
        pstRight = pstLeft->next;
        pstNewNode->next = pstRight;
        pstLeft->next = pstNewNode;
    }
    return 0;
}
int insertToTail(node* pstHead, int data)
{
    node* pstLeft = NULL;
    node* pstRight = NULL;
    node* pstNewNode = NULL;
    pstNewNode = malloc(sizeof(node));
    if(NULL == pstNewNode)
    {
        return -1;
    }
    else
    {
        pstNewNode->data = data;
        pstNewNode->next = NULL;
    }
    pstRight = pstHead;
    while(pstRight->next != NULL)
    {
        pstLeft = pstRight;
        pstRight = pstRight->next;
    }
    pstRight->next = pstNewNode;
    return 0;
}
int insertByAscend(node* pstHead, int data)
{
    node* pstLeft = NULL;
    node* pstRight = NULL;
    node* pstNewNode = NULL;
    pstNewNode = malloc(sizeof(node));
    if(NULL == pstNewNode)
    {
        return -1;
    }
    else
    {
        pstNewNode->data = data;
        pstNewNode->next = NULL;
    }
    pstRight = pstHead;
    while((data > pstRight->data) && (pstRight->next != NULL))
    {
        pstLeft = pstRight;
        pstRight = pstRight->next;
    }
    if(NULL == pstRight->next)
    {
        pstRight->next = pstNewNode;
    }
    else
    {
        pstLeft->next = pstNewNode;
        pstNewNode->next = pstRight;
    }
    return 0;
}
int sortDescend(node* pstHead)
{
    node* pstLeft = NULL;
    node* pstRight = NULL;
    if(NULL == pstHead || NULL == pstHead->next)
    {
        return 0;
    }
    pstLeft = pstHead->next;
    for(; pstLeft != NULL; pstLeft = pstLeft->next)
    {
        for(pstRight = pstLeft->next; pstRight != NULL; pstRight = pstRight->next)
        {
            int temp;
            if(pstRight->data > pstLeft->data)
            {
                temp = pstLeft->data;
                pstLeft->data = pstRight->data;
                pstRight->data = temp;
            }
        }
    }
    return 0;
}
node* reverse(node* pstHead)
{
    node* pstLeft = NULL;
    node* pstMiddle = NULL;
    node* pstRight = NULL;
    if(NULL == pstHead || NULL == pstHead->next)
    {
        return pstHead;
    }
    pstLeft = pstHead->next;
    pstMiddle = pstLeft->next;
    pstLeft->next = NULL;
    while(pstMiddle != NULL)
    {
        pstRight = pstMiddle->next;
        pstMiddle->next = pstLeft;
        pstLeft = pstMiddle;
        pstMiddle = pstRight;
    }
    pstHead->next = pstLeft;
    return pstHead;
}
int delete(node* pstHead, int data)
{
    node* pstLeft = NULL;
    node* pstRight = NULL;
    pstRight= pstHead;
    while(data != pstRight->data && pstRight->next != NULL)
    {
        pstLeft = pstRight;
        pstRight = pstRight->next;
    }
    if(data == pstRight->data)
    {
        pstLeft->next = pstRight->next;
        free(pstRight);
        return 0;
    }
    else
    {
        return -1;
    }
}
int printLinkInfo(node* pstHead)
{
    node* pstP0 = pstHead->next;
    unsigned int uiLength = 0;
    while(NULL != pstP0)
    {
        printf("Link data = %d\n", pstP0->data);
        pstP0 = pstP0->next;
        uiLength++;
    }
    printf("Total length = %d\n", uiLength);
    return uiLength;
}
node* searchMid(node* pstHead)
{
    node* pstLeft = NULL;
    node* pstRight = NULL;
    if(NULL == pstHead || NULL == pstHead->next)
    {
        return NULL;
    }
    pstLeft = pstRight = pstHead;
    while(pstRight != NULL)
    {
        if(pstRight->next != NULL)
        {
            pstRight = pstRight->next->next;
        }
        else
        {
            break;
        }
        pstLeft = pstLeft->next;
    }
    return pstLeft;
}
int main()
{
    int uiRet = 0;
    node* pstLinkHeader = NULL;
    node* pstMidNode = NULL;
    pstLinkHeader = createLink();
    if(pstLinkHeader != NULL)
    {
        printf("Create Single Link Success! Insert element now.\n");
    }
    printf("\nInsert elements at the head.\n");
    uiRet = insertToHead(pstLinkHeader, 5);
    uiRet = insertToHead(pstLinkHeader, 4);
    uiRet = insertToHead(pstLinkHeader, 3);
    uiRet = insertToHead(pstLinkHeader, 2);
    uiRet = insertToHead(pstLinkHeader, 1);
    printLinkInfo(pstLinkHeader);
    printf("\nInsert elements at the tail.\n");
    uiRet = insertToTail(pstLinkHeader, 6);
    uiRet = insertToTail(pstLinkHeader, 8);
    printLinkInfo(pstLinkHeader);
    printf("\nInsert elements by ascend order.\n");
    uiRet = insertByAscend(pstLinkHeader, 10);
    uiRet = insertByAscend(pstLinkHeader, 7);
    printLinkInfo(pstLinkHeader);
    printf("\nDelete 3 & 10\n");
    uiRet = delete(pstLinkHeader, 3);
    uiRet = delete(pstLinkHeader, 10);
    printLinkInfo(pstLinkHeader);
    printf("\nSort the link by descend order.\n");
    uiRet = sortDescend(pstLinkHeader);
    printLinkInfo(pstLinkHeader);
    printf("\nReverse the Link.\n");
    pstLinkHeader = reverse(pstLinkHeader);
    printLinkInfo(pstLinkHeader);
    printf("\nSearch the Middle element of the existing link.\n");
    pstMidNode = searchMid(pstLinkHeader);
    printf("The middle node of current link = %d.\n", pstMidNode->data);
    printf("\nInsert 1 more node & Search the Middle one again.\n");
    uiRet = insertByAscend(pstLinkHeader, 3);
    printLinkInfo(pstLinkHeader);
    pstMidNode = searchMid(pstLinkHeader);
    printf("\nThe middle node of the current link = %d.\n", pstMidNode->data);
    printf("\nleave 2 element in the link.\n");
    uiRet = delete(pstLinkHeader, 3);
    uiRet = delete(pstLinkHeader, 4);
    uiRet = delete(pstLinkHeader, 5);
    uiRet = delete(pstLinkHeader, 6);
    uiRet = delete(pstLinkHeader, 7);
    uiRet = delete(pstLinkHeader, 8);
    printLinkInfo(pstLinkHeader);
    pstMidNode = searchMid(pstLinkHeader);
    printf("\nThe middle node of the current link = %d.\n", pstMidNode->data);
    printf("\nleave 1 element in the link.\n");
    uiRet = delete(pstLinkHeader, 1);
    printLinkInfo(pstLinkHeader);
    pstMidNode = searchMid(pstLinkHeader);
    printf("\nThe middle node of the current link = %d.\n", pstMidNode->data);
    printf("\nAt last, destroy link.\n");
    destroyLink(pstLinkHeader);
    return 0;
}