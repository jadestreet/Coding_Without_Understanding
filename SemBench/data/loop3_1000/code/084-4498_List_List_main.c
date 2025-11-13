#include <stdio.h>
#define MAXSIZE 50
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#pragma mark - SequenceList
typedef int Status;
typedef int Element;
typedef struct
{
    Element data[MAXSIZE];
    int length;
}SequenceList;
void initList(SequenceList *L)
{
    L->length = 0;
}
Status listEmpty(SequenceList L)
{
    if(L.length == 0)
        return TRUE;
    return FALSE;
}
void clearList(SequenceList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = 0;
    }
    L->length = 0;
}
Status getElem(SequenceList L, int i, Element *e)
{
    if (i < 1 || i > L.length || L.length == 0)
        printf("\n查找失败\n");
        return ERROR;
    *e = L.data[i - 1];
    return OK;
}
Status locateElem(SequenceList L,Element e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }
    return FALSE;
}
Status listInsert(SequenceList *L, int i, Element e)
{
    if (i > L->length + 1 || i < 1 || L->length == MAXSIZE)
        return ERROR;
    if (i <= L->length)
    {
        for (int j = L->length - 1; j >= i - 1; j--)
        {
            L->data[j+1] = L->data[j];
        }
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}
Status listDelete(SequenceList *L, int i, Element *e)
{
    if (i > L->length || i < 1 || L->length == 0)
        return ERROR;
    *e = L->data[i-1];
    for (int j = i; j < L->length; j++)
    {
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return OK;
}
int listLength(SequenceList L)
{
    return L.length;
}
void travelList(SequenceList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ",L->data[i]);
    }
    printf("\n打印完毕\n");
}
int main(int argc, const char * argv[])
{
    SequenceList L;
    initList(&L);
    int origin = 40;
    while(origin)
    {
        listInsert(&L, 1, origin);
        origin--;
    }
    listInsert(&L , 2, 100);
    travelList(&L);
    int i = 0;
    int *p = &i;
    listDelete(&L, 2, p);
    printf("%d\n",*p);
    printf("%d\n",listLength(L));
    travelList(&L);
    return 0;
}