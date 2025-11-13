#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node{
	ElemType data;
struct node* link;
}LNode,*LinkList;
LinkList create(int n)
{
	LinkList p,r,list = NULL;
	ElemType a;
	int i;
	for(i=1;i<=n;++i){
	   p = (LinkList)malloc(sizeof(LNode));
	   p->data = i;
		p->link= NULL;
		if(NULL == list)
			list=p; 
		else
			r->link = p; 
		r=p;
	}
	return list;
}
void print_list(LinkList L)
{
	if(!L) return;
	while(L!= NULL)
	{ 
		printf("%d ",L->data);
		L=L->link;
	}
	printf("\n");
}
LinkList swap_node(LinkList L)
{
   LinkList h = L,p,r,temp,prior;
	if(!L) return (LinkList)0;
	p=L->link;
	r = p->link;
  while(!p && !r)
	{ 
        temp= r->link;
		if(p== h)
		{ r->link = p;h = r;}
		else { prior->link = r; p->link = temp;r->link = p;}
		prior = p;
		p->link = temp;
		p = temp;
		r = temp->link;
   }
 return h;
}
LinkList LinkListReverse(LinkList L)
{
	 if(!L) return (LinkList)-1; 
	 LinkList pcur,ptemp;
	 pcur=L->link;
	 L->link=NULL; 
	 while(pcur != NULL )
	 {
	 	ptemp = pcur->link; 
	 	pcur->link = L; 
	 	L = pcur; 
	 	pcur = ptemp; 
	  } 
	 return L;  
}
int main(void)
{
	LinkList L;
    L =	create(4);
	print_list( L);
	L = swap_node(L);
print_list( L);
		L = LinkListReverse(L);
		print_list( L);
	return 0;
}