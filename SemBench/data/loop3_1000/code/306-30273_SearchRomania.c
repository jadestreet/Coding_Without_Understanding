#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
void initAdjMat();	
void printAdjMat();	
void addRoute(int,int);	
void map();	
void DFS(int,int);	
void push(int);		
int pop();		
void BFS();		
void addQ(int);		
int delQ();		
int emptyQ();		
int getCityId(char *);	
int visited[26];	
int adjMat[26][26];	
node *head;		
node *front,*rear;	
char **cities = (char* []){"Arad","Bucharest","Craiova","Dobreta",
			"Eforie","Fagaras","Giurgiu","Hirsova",
			"Iasi","","","Lugoj","Mehadia","Nearnt",
			"Oradea","Pitesti","","Rimnieu_Vilcea",
			"Sibiu","Timisoara","Urziceni","Vaslui","",
			"","","Zerind"};
int main(int argc, char **argv)
{
	if(argc < 4)	
	{
		printf("\nInsufficient Arguments!!\n\n");
		printf("Correct Input form is:\n");
		printf("\t./[EXECUTABLE] [SEARCH_TYPE] [SOURCE_CITY] [DESTINATION_CITY]\n\n");
	}
	else
	{
		int srcC,destC;
		printf("\nSearch Type: %s\n",argv[1]);
		srcC = getCityId(argv[2]);	
		if (srcC < 0)
		{
			printf("City %s NOT found!\n\n",argv[2]);
			return 0;
		}
		printf("Source City: %s\t",argv[2]);
		destC = getCityId(argv[3]);	
		if (destC < 0)
		{
			printf("\nCity %s NOT found!\n\n",argv[3]);
			return 0;
		}
		printf("Destination City: %s\n",argv[3]);
		initAdjMat();
		map();
		if (srcC == destC)
		{
			printf("Source City is same as Destination City\n\n");
		}
                else if ( strcmp("DFS",argv[1]) == 0 )	
                {
                        head = NULL;	
	                DFS(srcC,destC);
                }
                else if( strcmp("BFS",argv[1]) == 0)
                {
                        front = rear = NULL;	
	                BFS(srcC,destC);
                }
                else
                {
                        printf("\nInvalid Search Type\n");
			printf("Search Type can be DFS/BFS\n\n");
                }
	}
	return 0;
}
int getCityId(char *city)	
{				
	int ret;
	int i;
	ret = -1;
	for(i=0;i<26;i++)
	{
		if( strcmp(city,cities[i]) == 0 )
		{
			ret = i;
			break;
		}
	}
        if(ret == -1)
        {
                printf("City %s NOT found\n",city);
        }
	return ret;
}
void initAdjMat()	
{
	int i,j;
	for (i=0; i<26; i++)
	{
		for(j=0; j<26; j++)
		{
			if(i==j)	
			{
				adjMat[i][j]=1;
			}
			else
			{
			adjMat[i][j]=0;
			}
		}
		visited[i] = 0;
	}
}
void printAdjMat()
{
	int i,j;
	for (i=0; i<26; i++)
	{
		for(j=0; j<26; j++)
		{
			printf(" %d",adjMat[i][j]);
		}
		printf("\n");
	}
}
void addRoute(int src, int dest)	
{					
	adjMat[src][dest] =  adjMat[dest][src] = 1;
}
void map()	
{		
	addRoute(getCityId("Oradea"),getCityId("Zerind"));
	addRoute(getCityId("Oradea"),getCityId("Sibiu"));
	addRoute(getCityId("Zerind"),getCityId("Arad"));
	addRoute(getCityId("Sibiu"),getCityId("Fagaras"));
	addRoute(getCityId("Sibiu"),getCityId("Rimnieu_Vilcea"));
	addRoute(getCityId("Arad"),getCityId("Sibiu"));
	addRoute(getCityId("Arad"),getCityId("Timisoara"));
	addRoute(getCityId("Fagaras"),getCityId("Bucharest"));
	addRoute(getCityId("Rimnieu_Vilcea"),getCityId("Pitesti"));
	addRoute(getCityId("Rimnieu_Vilcea"),getCityId("Craiova"));
	addRoute(getCityId("Pitesti"),getCityId("Craiova"));
	addRoute(getCityId("Timisoara"),getCityId("Lugoj"));
	addRoute(getCityId("Lugoj"),getCityId("Mehadia"));
	addRoute(getCityId("Mehadia"),getCityId("Dobreta"));
	addRoute(getCityId("Dobreta"),getCityId("Craiova"));
	addRoute(getCityId("Bucharest"),getCityId("Giurgiu"));
	addRoute(getCityId("Bucharest"),getCityId("Urziceni"));
	addRoute(getCityId("Urziceni"),getCityId("Hirsova"));
	addRoute(getCityId("Hirsova"),getCityId("Eforie"));
	addRoute(getCityId("Urziceni"),getCityId("Vaslui"));
	addRoute(getCityId("Vaslui"),getCityId("Iasi"));
	addRoute(getCityId("Iasi"),getCityId("Nearnt"));
}
void DFS(int src,int dest)
{
        printf("\n-----Depth First Serach---\n\n");
	push(src);
	int success = 0;
	while(!success)
	{
		int beg = pop();	
		visited[beg] = 1;	
		int i;
		printf("%s -> ",cities[beg]);
		for(i=0; i<26; i++)
		{
			if(adjMat[beg][i] == 1 && visited[i] != 1)
			{
				if ( i == dest )	
				{
					printf("%s",cities[i]);
					printf("\n\nRoute Found!!\n\n");
					success=1;
				}	
				push(i);	
			}
		}
		if(head == NULL)	
		{			
			printf("Can NOT reach Destination\n");
			break;
		}
	}
}
void push(int a)
{
	node *temp;
	temp=malloc(sizeof(node));	
	temp->data = a;
	if (head != NULL )
	{
		temp->next = head;	
	}
	head = temp;
}
int pop()
{
	int ret;
	if (head != NULL)
	{
		ret = head->data;	
		head = head->next;	
		return ret;
	}
	else
	{
		printf("Stack is empty");
		return 0;
	}
}
void BFS(int src,int dest)
{
        printf("\n-----Breadth First Serach---\n\n");
	addQ(src);
	int success = 0;
	while(!success)
	{
		int beg = delQ();
		visited[beg] = 1;	
		int i;
		printf("%s -> ",cities[beg]);
		for(i=0; i<26; i++)
		{
			if(adjMat[beg][i] == 1 && visited[i] != 1)
			{
				if ( i == dest )	
				{
					printf("%s",cities[i]);
					printf("\n\nRoute Found!!\n\n");
					success=1;
				}	
				addQ(i);	
			}
		}
		if( emptyQ() )
		{
			printf("No items in Queue\n");
			break;
		}
	}
}
void addQ(int a)
{
	node *temp;
	temp = malloc(sizeof(node));	
	temp->data = a;
	if( emptyQ() )		
	{
		front = rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
}
int delQ()
{
	int ret;
	ret = front->data;	
	front = front->next;	
	return ret;
}
int emptyQ()	
{
	if ( front == NULL || rear == NULL )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}