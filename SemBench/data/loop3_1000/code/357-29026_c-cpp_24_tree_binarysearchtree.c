#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef char ElemType;
typedef struct node {
    ElemType data;
    struct node *lchild, *rchild;
} BTree, *BTreePtr;
Status Insert(BTreePtr *T, ElemType e) {
    BTreePtr p;
    if (*T == NULL) {
        *T = (BTreePtr)malloc(sizeof(BTree));
        (*T)->data = e;
        return TRUE;
    } else {
        p = *T;
        while ( p != NULL) {
            if (e > p->data) {
                if (p->rchild == NULL) {
                    p->rchild = (BTreePtr) malloc (sizeof(BTree));
                    p->rchild->data = e;
                    return TRUE;
                }
                p = p->rchild;
            } else {
                if (p->lchild == NULL)
                {
                    p->lchild = (BTreePtr) malloc (sizeof(BTree));
                    p->lchild->data = e;
                    return TRUE;
                }
                p = p->lchild;
            }
        }
    }
    return FALSE;
}
Status Delete(BTreePtr T, ElemType e) {
    BTreePtr p, pp, minP, minPP, child;
    child = NULL;
    p = T;
    pp = NULL;
    while ( (p != NULL) && (p->data != e) ) {
        pp = p;
        if (e > p->data) {
            p = p->rchild;
        } else {
            p = p->lchild;
        }
    }
    if (p == NULL) return FALSE;
    if ((p->lchild != NULL) && (p->rchild != NULL))
    {
        minPP = p;
        minP = p->rchild;
        while (minP->lchild != NULL) {
            minPP = minP;
            minP = minP->lchild;
        }
        p->data = minP->data;
        minPP->lchild = minP->rchild;
        free(minP);
        return TRUE;
    }
    if ((p->lchild != NULL) || (p->rchild != NULL)) { 
        if (p->lchild) {
            child = p->lchild;
        } else {
           child = p->rchild;
        }
        if(pp->data>p->data)
        {
            pp->lchild=child;
        } else
        {
            pp->rchild=child;
        }
        free(p);
        return TRUE;
    }
    if (pp->lchild == p) {
        pp->lchild = child;
    } else {
        pp->rchild = child;
    }
    return TRUE;
}
Status Find(BTreePtr T, ElemType e) {
    if (T == NULL) return FALSE;
    while ((T != NULL) && (T->data != e)) {
        if (e > T->data) {
            T = T->rchild;
        } else {
            T = T->lchild;
        }
    }
    if (T) {
        return TRUE;
    } else {
        return FALSE;
    }
}
ElemType FindMax(BTreePtr T) {
    ElemType max;
    while(T != NULL) {
        max = T->data;
        T = T->rchild;
    }
    return max;
}
ElemType FindMin(BTreePtr T) {
    ElemType min;
    while(T != NULL) {
        min = T->data;
        T = T->lchild;
    }
    return min;
}
void PreOrderTraverse(BTreePtr T)
{
    if (T == NULL) return;
    if(T)
    {
        printf("%d ",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void DestroyTree(BTreePtr T) {
    if (T)
    {
        if (T->lchild)
        {
            DestroyTree(T->lchild);
        }
        if(T->rchild)
        {
            DestroyTree(T->rchild);
        }
        free(T);
        T = NULL;
    }
}
int main(int argc, char const *argv[])
{
    BTreePtr T;
    T = NULL;
    int a[] = {33, 16, 50, 13, 18, 34, 58, 15, 17, 25, 51, 66, 19, 27, 55};
    int i;
    for (i = 0; i < 15; i++) {
        Insert(&T, a[i]);
    }
    printf("Max is %d\n", FindMax(T));
    printf("Min is %d\n", FindMin(T));
    Delete(T, 18);
    Delete(T, 13);
    PreOrderTraverse(T);
    DestroyTree(T);
    return 0;
}