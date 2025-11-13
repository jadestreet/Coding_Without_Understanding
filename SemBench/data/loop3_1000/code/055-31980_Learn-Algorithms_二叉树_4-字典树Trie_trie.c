#include <stdio.h>
#include <stdlib.h>
#define  ALPHABET_SIZE 26 
typedef int  bool;
#define YES 1
#define NO 0
typedef struct node
{
  int count;  
  char value; 
  struct node * subtries[ALPHABET_SIZE]; 
} Trie;
Trie *trie_create(Trie **trie){
	if (NULL==*trie)
	{
		*trie = (Trie *)malloc(sizeof(struct node));
		if (NULL==*trie)
		{
			printf("malloc failure...\n");
		}
		for (int i = 0; i < ALPHABET_SIZE; ++i)
		{
			(*trie)->subtries[i]=NULL;
		}
	}
	return *trie;
}
int trie_insert(Trie *trie,char *c){
	if (trie==NULL || c==NULL) 
	{
		return -1;
	}
	char *p = c;
	Trie *temp = trie;
	while(*p != '\0'){
		if (temp->subtries==NULL)
		{
			if (temp->subtries==NULL)
			{
				return -1;
			}
		}
		if (temp->subtries[*p-'a']==NULL)
		{
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			if (!newNode)
			{
				printf("create new node fail \n");
				return -1;
			}
			newNode->value = *p;
			temp->subtries[*p-'a'] = newNode;
		}
		temp = temp->subtries[*p-'a'];
		p++;
	}
	return 0;
}
bool trie_query(Trie *trie,char *c){
	if (trie==NULL )
	{
		return NO;
	}
	char *p = c;
	Trie *temp = trie;
	bool ret=NO;
	if (temp->subtries == NULL)
	{
		return NO;
	}
	while (*p!='\0')
	{
		if (temp->subtries[*p-'a']!=NULL && temp->subtries[*p-'a']->value==*p)
		{
			temp = temp->subtries[*p-'a'];
			p++;
			continue;
		}
		break;
	}
	if (*p =='\0')
	{
		ret = YES;
	}
	return ret;
}
void trie_remove(){}
int main(){
	Trie *trie = NULL;
	if (!trie_create(&trie))
	{
		printf("trie init fail...\n");
	}
	char *dict[10]={"int","integer","float","char","nonstriater","weibo"};
	for (int i = 0; i < 6; ++i)
	{
		if (trie_insert(trie,dict[i])<0)
		{
			printf("%s 插入失败\n", dict[i]);
		}
	}
	printf("查询cha \n");
	if (trie_query(trie,"cha"))
	{
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	printf("查询char \n");
	if (trie_query(trie,"char"))
	{
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	printf("查询hello \n");
	if (trie_query(trie,"hello"))
	{
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;	
}