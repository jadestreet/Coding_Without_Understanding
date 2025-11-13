#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10
#define INFEASIBLE -1
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct LNode{
  ElemType data;
  int freq;
  struct LNode *next;
  struct LNode *prior;
}LNode,*LinkList;
void print(LinkList list);
LinkList create(){
  LinkList head=(LinkList)malloc(sizeof(LNode));
  head->next=head;
  head->prior=head;
  return head;
}
Status insert(LinkList list,int i,ElemType x){
	LinkList pre=list,p=pre->next;
	int k=1;
	while(p!=list&k<i){
     pre=p;p=p->next;k++;
	}
	if(k!=i)return INFEASIBLE;
	LinkList newptr=(LinkList)malloc(sizeof(LNode));
	newptr->freq=0;
	newptr->data=x;
	newptr->next=pre->next;
	newptr->prior=pre;
    pre->next=newptr;
    p->prior=newptr;
}
void print(LinkList list){
	if(!list)return;
	LinkList p=list->next;
	while(p!=list){
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n");
}
int locate(LinkList list,ElemType x){
	LinkList pre=list,p=list->next;
	int k=1;
	while(p!=list&&p->data!=x){
     pre=p; p=p->next;k++;
	}
	if(p==list)return 0;
	p->freq++;
	pre->next=p->next;
	p->next->prior=pre;
	while(pre!=list&&pre->freq<p->freq){
		pre=pre->prior;k--;
	}
	p->prior=pre;
	p->next=pre->next;
	p->prior->next=p;
	p->next->prior=p;
return k;
}
ElemType get(LinkList list,int i){
	if(!list)return ERROR;
	LinkList p=list->next;
	int k=1;
	while(p!=list&&k<i){
		p=p->next;k++;
	}
	if(p!=list)
		return p->data;
	else
		return ERROR;
}
int main(){
  LinkList list =create();
  for(int i=1;i<=20;i++){
  	insert(list,i,i);
  }
print(list);
int k=locate(list,8);
printf("调整后位置%d 值为:%d\n",k,get(list,k));
print(list);
	return 0;
}