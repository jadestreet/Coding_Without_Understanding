#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10
#define INFEASIBLE -1
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
void InsertEnd(LinkList list,ElemType x){
	while(list->next){
		list=list->next;
	}
	LinkList newptr=(LinkList)malloc(sizeof(LNode));
	newptr->data=x;
	newptr->next=list->next;
	list->next=newptr;
}
Status fun3_30(LinkList la,LinkList lb,LinkList lc){
   LinkList qa=la,a=la->next,b=lb->next,c=lc->next;
   while(a&&b&&c){
        if(b->data<c->data)
          b=b->next;
        else if(b->data>c->data)
          c=c->next;
        else{
          while(a&&a->data<b->data)
            {qa=a;a=a->next;}
          while(a&&a->data==b->data)
            {qa->next=a->next;free(a);a=qa->next;}
          b=b->next;c=c->next;
        }
   }
}
int main(){
  srand(time(NULL));
LinkList a=createLinklist();
LinkList b=createLinklist();
LinkList c=createLinklist();
for(int i=0;i<10;i++){
  InsertUp(a,rand()%10);
}
print(a);
for(int i=0;i<10;i++){
  InsertUp(b,rand()%10);
}
printf("\n");
print(b);
for(int i=0;i<10;i++){
  InsertUp(c,rand()%10);
}
printf("\n");
print(c);
fun3_30(a,b,c);
printf("after fun3_30(a,b,c) \n");
 print(a);
    return 0;
}