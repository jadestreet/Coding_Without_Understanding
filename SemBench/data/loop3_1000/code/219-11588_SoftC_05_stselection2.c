#include <stdio.h>
#include <string.h>
#define N 10
struct no{
  char  *stuno;
  char  *hostno;
};
int main()
{
  struct no stho[N] = {{"0312010014", "iswni400"}, {"0312010023", "iswni300"}, 
                       {"0312010031", "iswni800"}, {"0312010034", "iswni600"}, 
                       {"0312010037", "iswni200"}, {"0312010055", "iswni100"}, 
                       {"0312010074", "iswni700"}, {"0312010082", "iswni500"}, 
                       {"0312010142", "iswni900"}, {"0312010160", "iswni150"}};
  int i, j, k;
  struct no temp;
  int key  = 0;
  int data = 0;
  for (i = 0; i < N; i++)
    printf("%s : %s\n", stho[i].hostno, stho[i].stuno);
  for (i = 0; i < N - 1; i++) {
    k = i;
    for (j = i + 1; j < N; j++){
      if ((strcmp(stho[k].hostno, stho[j].hostno)) > 0){
        k = j;
      }
      key++;
    }
    data++;
    temp    = stho[i];  
    stho[i] = stho[k];  
    stho[k] = temp;
  }
  printf("\n");
  for (j = 0; j < N; j++)
    printf("%s : %s\n", stho[j].hostno, stho[j].stuno);
  printf("key : %d\ndata : %d\n", key, data);
 }