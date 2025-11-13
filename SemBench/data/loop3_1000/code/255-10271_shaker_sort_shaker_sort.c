#include <stdio.h>
void shakerSort(int array[],int length) {
int isSwaped ;
int i;
do {
    isSwaped=0;
    for ( i = length-1; i>=0 ; i--) {
    if (array[i+1]<array[i]) {
      int temp;
      temp=array[i+1];
      array[i+1]=array[i];
      array[i]=temp;
      isSwaped=1;
    }
  }
  for ( i = 0; i < length; i++) {
    if (array[i+1]<array[i]) {
      int temp;
      temp=array[i+1];
      array[i+1]=array[i];
      array[i]=temp;
      isSwaped=1;
    }
}
} while(isSwaped);
  printf("sorted array is ");
for ( i = 0; i<=length; i++) {
  printf("%i ",array[i]);
}
}
int main() {
  int numberOfElements=6;
  int arr[]={2,7,8,1,4,1};
  shakerSort(arr,numberOfElements-1);
  return 0;
}