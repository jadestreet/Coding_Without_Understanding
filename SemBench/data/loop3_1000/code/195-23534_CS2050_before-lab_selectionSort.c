#include <stdio.h>
void selectionSort(int array[],int length);
int main(){
	int array[]={3,2,8,6,9,4,1,7,5,0};
	int i;
	selectionSort(array,10);
	for(i=0;i<10;i++){
		printf("%d\n",array[i]);
	}
	return 0;
}
void selectionSort(int array[],int length){
	int i,j,temp,min,minIndex;
	for(i=0;i<length;i++){
		min=array[i];
		minIndex=i;
		for(j=i+1;j<length;j++){
			if(array[j]<min){
				min=array[j];
				minIndex=j;
			}
		}
		if(minIndex!=i){
			temp=array[i];
			array[i]=array[minIndex];
			array[minIndex]=temp;
		}
	}
}