#include <stdio.h>
#include <stdlib.h>
struct Element{
    int value;
    struct Element * next;
    struct Element * previous;
};
struct Element *head = NULL, *tail = NULL;
void enqueue(int val){
    if(tail == NULL){
        tail = malloc(sizeof(struct Element));
        tail->value = val;
        tail->next=NULL;
        head = tail;
        return;
    }
    tail->next = malloc(sizeof(struct Element));
    tail = tail->next;
    tail->value = val;
    tail->next = NULL;
}
int dequeue(int * val){
    if(head == NULL){
        return 0;
    }
    struct Element * temp;
    temp = head;
    head = head->next;
    *val = temp->value;
    free(temp);
    return 1;
}
int main()
{
    int i,j;
    for(i=0;i<=3;i++){
        enqueue(i);
    }
    for(j=0;j<=1;j++){
        dequeue(&j);
        printf("Dequed value = %d \n",j);
    }for(i=4;i<=8;i++){
        enqueue(i);
    }
    while(dequeue(&j)){
         printf("Dequed value = %d \n",j);
    }
    return 0;
}