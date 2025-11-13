#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct Point2D {
    int x;
    int y;
} ElemType;      
typedef struct {
    ElemType **rear;    
    ElemType *front;    
    int len;            
    int size;           
} ArrQueue;      
ArrQueue *CreateQueue(int nLen);          
void DestroyQueue(ArrQueue *pQueue);      
void ClearQueue(ArrQueue *pQueue);        
int GetLength(ArrQueue *pQueue);          
int GetSize(ArrQueue *pQueue);            
int IsEmpty(ArrQueue *pQueue);            
int GetHead(ArrQueue *pQueue, ElemType **pe);      
int EnQueue(ArrQueue *pQueue, ElemType *pe);       
int DeQueue(ArrQueue *pQueue, ElemType **pe);      
void ForEachQueue(ArrQueue *pQueue, void (*func)(ElemType *pe));      
ArrQueue *CreateQueue(int nLen) {
    ArrQueue *pQueue = (ArrQueue *) malloc(sizeof(ArrQueue));
    pQueue->rear = (ElemType **) calloc(nLen, sizeof(ElemType **));
    pQueue->front = pQueue->rear[0];
    pQueue->len = 0;
    pQueue->size = nLen;
    return pQueue;
}
void DestroyQueue(ArrQueue *pQueue) {
    free(pQueue->rear);
    free(pQueue);
    pQueue = NULL;
}
void ClearQueue(ArrQueue *pQueue) {
    pQueue->front = pQueue->rear[0];
    pQueue->len = 0;
}
int GetLength(ArrQueue *pQueue) {
    return pQueue->len;
}
int GetSize(ArrQueue *pQueue) {
    return pQueue->size;
}
int IsEmpty(ArrQueue *pQueue) {
    return pQueue->len == 0 ? TRUE : FALSE;
}
int GetHead(ArrQueue *pQueue, ElemType **pe) {
    if (pQueue->len == 0) {
        *pe = NULL;
        return -1;
    }
    *pe = pQueue->rear[pQueue->len - 1];
    return pQueue->len - 1;
}
int EnQueue(ArrQueue *pQueue, ElemType *pe) {
    if (pQueue->len == pQueue->size) {   
        pQueue->rear = realloc(pQueue->rear, 2 * pQueue->size * sizeof(ElemType *));
        pQueue->size = 2 * pQueue->size;
    }
    int i = 0;
    for (i = pQueue->len; i > 0; --i) {
        pQueue->rear[i] = pQueue->rear[i - 1];
    }
    pQueue->rear[0] = pe;
    pQueue->front = pQueue->rear[pQueue->len];
    return ++pQueue->len;
}
int DeQueue(ArrQueue *pQueue, ElemType **pe) {
    if (pQueue->len == 0) {
        *pe = NULL;
        return -1;
    }
    *pe = pQueue->front;
    --pQueue->len;
    pQueue->front = pQueue->rear[pQueue->len - 1];
    return pQueue->len;
}
void ForEachQueue(ArrQueue *pQueue, void (*func)(ElemType *pe)) {
    int i = 0;
    for (i = 0; i < pQueue->len; ++i) {
        func(pQueue->rear[i]);
    }
}
void display(ElemType *pe) {
    printf("(%d,%d) ", pe->x, pe->y);
}
int main() {
    ElemType t1 = {10, 20};
    ElemType t2 = {30, 40};
    ElemType t3 = {50, 60};
    ElemType t4 = {70, 80};
    ElemType t5 = {99, 99};
    ElemType t6 = {99, 99};
    ElemType t7 = {99, 939};
    ElemType t8 = {99, 99};
    ElemType t9 = {919, 99};
    ElemType t10 = {99, 99};
    ElemType t11 = {99, 99};
    ElemType t12 = {959, 949};
    ElemType t13 = {939, 929};
    ElemType t14 = {919, 199};
    ArrQueue *pque = CreateQueue(3);
    EnQueue(pque, &t1);
    EnQueue(pque, &t2);
    EnQueue(pque, &t3);
    EnQueue(pque, &t4);
    EnQueue(pque, &t5);
    EnQueue(pque, &t6);
    EnQueue(pque, &t7);
    EnQueue(pque, &t8);
    EnQueue(pque, &t9);
    EnQueue(pque, &t10);
    EnQueue(pque, &t11);
    EnQueue(pque, &t12);
    EnQueue(pque, &t13);
    EnQueue(pque, &t14);
    ForEachQueue(pque, display);
    if (IsEmpty(pque) != TRUE)
        printf("\n队列总容量:%d, 当前长度:%d\n", GetSize(pque), GetLength(pque));
    ElemType *p;
    DeQueue(pque, &p);
    printf("当前出队:(%d,%d), 剩余队列长为:%d\n", p->x, p->y, GetLength(pque));
    DeQueue(pque, &p);
    printf("当前出队:(%d,%d), 剩余队列长为:%d\n", p->x, p->y, GetLength(pque));
    DeQueue(pque, &p);
    printf("当前出队:(%d,%d), 剩余队列长为:%d\n", p->x, p->y, GetLength(pque));
    printf("\n测试全部出队:\n");
    while (DeQueue(pque, &p) != -1) {
        printf("当前出队:(%d,%d), 剩余队列长为:%d\n", p->x, p->y, GetLength(pque));
    }
    printf("\n再次入队2元素..\n");
    EnQueue(pque, &t1);
    EnQueue(pque, &t2);
    ForEachQueue(pque, display);
    printf("\n清空队列..\n");
    ClearQueue(pque);
    printf("队列总容量:%d, 当前长度:%d\n", GetSize(pque), GetLength(pque));
    printf("\n再次入队2元素..\n");
    EnQueue(pque, &t1);
    EnQueue(pque, &t2);
    ForEachQueue(pque, display);
    GetHead(pque, &p);
    printf("\n获取队头元素:(%d,%d)\n", p->x, p->y);
    printf("队列总容量:%d, 当前长度:%d\n", GetSize(pque), GetLength(pque));
    DestroyQueue(pque);
    return 0;
}