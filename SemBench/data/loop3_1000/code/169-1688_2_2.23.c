#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10
#define ERROR 0
#define INFEASIBLE -1
#define VOERFLOW -2
#define OK 1
typedef int ElemType;
typedef int Status;
typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode,*LinkList;
LinkList createLinklist(){
  LinkList head=(LinkList)malloc(sizeof(LNode));
  head->next=NULL;
  return head;
}
void InsertUp(LinkList list,ElemType x){
  LinkList pre=list,p=list->next;
  while(p&&x>p->data){pre=p;p=p->next;}
   LinkList newptrnode=(LinkList)malloc(sizeof(LNode));
   newptrnode->data=x;
   newptrnode->next=pre->next;
   pre->next=newptrnode;
}
void print(LinkList list){
 if(!list)return;
  list=list->next;
  int i=1;
  while(list){
    printf("%d %d\n",i,list->data);
    list=list->next;
    i++;
  }
}
Status ListMerge(LinkList A,LinkList B,LinkList C){
   LinkList p=A->next,q=B->next,tmpanext,tmpbnext,qre;
   while(p&&q){
    tmpanext=p->next;
    qre=q;
    tmpbnext=q->next;
    q->next=p->next;
    p->next=q;
      p=tmpanext;
      q=tmpbnext;
   }
   if(q)
   	qre->next=q;
    B->next=NULL;
    C->next=A->next;
    A->next=NULL;
    return OK;
}
int main(){
  srand(time(NULL));
  LinkList lista=createLinklist();
  LinkList listb=createLinklist();
  LinkList listc=createLinklist();
  for(int i=0;i<rand()%20;i++)
  {
    InsertUp(lista,rand()%10);
  }
  for(int i=0;i<rand()%20;i++)
  {
    InsertUp(listb,rand()%10);
  }
print(lista);
printf("\n");
print(listb);
ListMerge(lista,listb,listc);
printf("after ListMerge(lista,listb,listc)\n" );
print(listc);
  return 0;
}