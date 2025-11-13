#include<stdio.h>
#include<stdlib.h>
typedef struct coord_struct {
int x;
int y;
}coord_struct;
typedef struct distance {
   int count;
}distance;
coord_struct toFindTheOptimalDistance (int N, int M, coord_struct input[])
{
    coord_struct z ;
    z.x=0;
    z.y=0;
    int i,j;
    distance * array_dist;
    array_dist = (distance*)(malloc(sizeof(distance)*M));
    for(i=0;i<M;i++)
    {
        array_dist[i].count =0;
    }
    for(i=0;i<N;i++)
    {
        array_dist[input[i].x].count +=1;
        printf("%d and %d\n",input[i].x,array_dist[input[i].x].count);
    }
    j=0;
    for(i=0;i<=N/2;)
    {
       printf("%d\n",i);
       if(array_dist[j].count !=0)
          i+=array_dist[j].count;
       j++;
    }
   printf("x coordinate = %d",j-1);
   int x= j-1;
   for(i=0;i<M;i++)
       array_dist[i].count =0;
    for(i=0;i<N;i++)
    {
       array_dist[input[i].y].count +=1;
    }
    j=0;
    for(i=0;i<N/2;)
    {
       if(array_dist[j].count !=0)
          i+=array_dist[j].count;
       j++;
    }
    int y =j-1;
    printf("y coordinate = %d",j-1);
    z.x=x;
    z.y =y;
    return z; 
}
int main()
{
coord_struct input[5];
 input[0].x =1;
 input[0].y =2;
 input[1].x =3;
 input[1].y =1;
 input[2].x =4;
 input[2].y =1;
 input[3].x = 5;
 input[3].y = 2;
 input[4].x = 5;
 input[4].y = 3;
for(int i=0; i<10;i++)
{
}
coord_struct x = toFindTheOptimalDistance(5,6,input);
} 