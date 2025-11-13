#include <stdio.h>
#include <string.h>
int main(){
  int i = 0;
  int arr1[10] = {1,2,3,4,5};
 for (i = 0; i < 10; i++){ 
    printf("Am Index %d liegt der Wert %d\n",i, arr1[i] );
 }
  int arr[10] = {0,1,2,3,4,5,12,13,42,10};
  int sum =0;
  for (i = 0; i < 10; i++){
    sum = sum + arr[i];
  }
  printf("Durchschnitt: %f\n", sum/10.0);
  char arr3[] = {'d', 'u', 'r', ' ', 't','t'};
  for (i = 0; i < strlen(arr3);i++){
    printf("%c",arr3[i]); 
  }
  return 0;
}