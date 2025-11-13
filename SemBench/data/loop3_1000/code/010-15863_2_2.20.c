#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10
#define INFEASIBLE -1
#define ERROR 0
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
  list=list->next;
  int i=1;
  while(list){
    printf("%d %d\n",i,list->data);
    list=list->next;
    i++;
  }
}
void Deletemintomax(LinkList list,ElemType mink,ElemType maxk){
  LinkList pre=list,p=list->next,q=NULL,tmp=NULL;
  while(p&&p->data<=mink){pre=p;p=p->next;}
  if(!p)return ;
  q=p;
  while(q&&q->data<maxk){tmp=q;q=q->next;free(tmp);}
  pre->next=q;
}
void Deletext1(LinkList list){
  LinkList pre=list,p=list->next,tmp=NULL;
 while(p){
  if(pre!=list&&pre->data==p->data)
  {pre->next=p->next;free(p);p=pre->next;}
  else 
     {pre=p;p=p->next;}
 }
}
Status Deletext(LinkList list){
	if(!list||!list->next)return ERROR;
  LinkList pre=list->next,p=pre->next,tmp=NULL;
 if(!p)return ERROR;
 while(p){
  if(pre->data==p->data)
  {pre->next=p->next;free(p);p=pre->next;}
  else 
     {pre=p;p=p->next;}
 }
}
int main(){
  srand(time(NULL));
  LinkList list=createLinklist();
  for(int i=0;i<20;i++)
  {
    InsertUp(list,rand()%10);
  }
print(list);
Deletext(list);
printf("after Deletext(list)\n" );
print(list);
  return 0;
}