#include <stdio.h>
void display(int arr[] ,int size){
	printf("------DISPLAY ----\n");
	for (int i = 0; i < size; i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
void merge(int arr[] , int start , int mid , int end ){
	int i,j,temp[50],temp_index;
	i = start; 
	temp_index = start;
	j = mid+1; 
	for( ; i <= mid && j <= end ; temp_index++){
		temp[temp_index] = arr[i]<arr[j] ? arr[i++] : arr[j++];
	}
	for(;i<=mid;i++,temp_index++){
		temp[temp_index] = arr[i];
	}
	for(;j<=end;j++,temp_index++){
		temp[temp_index] = arr[j];
	}
	for(i = 0; i < temp_index ; i++){
		arr[i] = temp[i];
	}
}
void split(int arr[] , int start  , int end , char *type ){
	if(start<end){
		int mid = (start+end)/2;
		printf("------------------------\n");
		printf("MID ----> %d\n",mid );
		printf("TYPE ---> %s\n\n",type );
		printf("------------------------\n\n");
		split(arr,start,mid,"Left Function");
		split(arr,mid+1,end , "Right Function");
		merge(arr , start , mid , end);
	}else
		return;
}
int main(int argc, char const *argv[]){
	int arr[] = {7,3,2,1,8,9,4};
	split(arr,0,6,"Initial Call");
	display(arr,6);
	return 0;
}