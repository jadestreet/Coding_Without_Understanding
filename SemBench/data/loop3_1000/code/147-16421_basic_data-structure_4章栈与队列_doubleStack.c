#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
typedef struct shareStack {
    int data[MAXSIZE];
    int top1;
    int top2;
} shareStack;
void createStack(shareStack *ss, int n, int m);
void showStack(shareStack *ss);
int Push(shareStack *ss, int num, int flag);
int Pop(shareStack *ss, int flag);
int main() {
    shareStack *ss = (shareStack *) malloc(sizeof(shareStack));
    createStack(ss, 3, 4);
    showStack(ss);
    if (Push(ss, 6, 1))
        showStack(ss);
    if (Push(ss, 4, 2))
        showStack(ss);
    int n;
    n = Pop(ss, 1);
    if (n >= 0)
        printf("the pop num is:%d\n", n);
    n = Pop(ss, 2);
    if (n >= 0)
        printf("the pop num is:%d\n", n);
    n = Pop(ss, 1);
    if (n >= 0)
        printf("the pop num is:%d\n", n);
    n = Pop(ss, 1);
    if (n >= 0)
        printf("the pop num is:%d\n", n);
    n = Pop(ss, 1);
    if (n >= 0)
        printf("the pop num is:%d\n", n);
    n = Pop(ss, 1);
    if (n >= 0)
        printf("the pop num is:%d\n", n);
    n = Pop(ss, 1);
    if (n >= 0)
        printf("the pop num is:%d\n", n);
    showStack(ss);
    return 0;
}
void createStack(shareStack *ss, int n, int m) {
    int i;
    ss->top1 = -1;
    ss->top2 = MAXSIZE;
    for (i = 0; i < n; i++) {
        ss->top1++;
        ss->data[ss->top1] = 2 * i + 1;
    }
    for (i = 0; i < m; i++) {
        ss->top2--;
        ss->data[ss->top2] = 2 * i + 1;
    }
}
void showStack(shareStack *ss) {
    int i;
    for (i = 0; i < ss->top1 + 1; i++) {
        printf("%d->", ss->data[i]);
    }
    printf("top1-----top2");
    for (i = ss->top2; i < MAXSIZE; i++) {
        printf("<-%d", ss->data[i]);
    }
    printf("\n");
}
int Push(shareStack *ss, int num, int flag) {
    if (ss->top1 + 1 == ss->top2)
        return 0;
    if (flag == 1) {
        ss->data[++ss->top1] = num;
        return 1;
    } else if (flag == 2) {
        ss->data[--ss->top2] = num;
        return 1;
    }
    return 0;
}
int Pop(shareStack *ss, int flag) {
    if (flag == 1) {
        if (ss->top1 == -1)
            return -1;
        return ss->data[ss->top1--];
    } else if (flag == 2) {
        if (ss->top2 == MAXSIZE)
            return -1;
        return ss->data[ss->top2++];
    }
    return -1;
}