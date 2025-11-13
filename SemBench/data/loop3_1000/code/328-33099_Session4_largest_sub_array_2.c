#include <stdio.h>
#include <stdlib.h>
int indices[2] = {0};
int find_max_sub_array(int *arr,int len){
    int start = 0;
    int last = 0;
    int flag = 1;
    int max = 0;
    int sum = 0;
    while(start < (len)){
        printf("\n");
        while(arr[start] < 0){
            start++;
        }
        last = start;
        if(start < len){
            printf("%d->",arr[last]);
            sum = arr[start];
            while((last+1) < len){
                printf("\"In while\"");
                if((sum+arr[last+1]) > 0){
                    sum += arr[last + 1];
                    last++;
                }
                else{
                    if(sum > max){
                        indices[0] = start;
                        indices[1] = last;
                        max = sum;
                    }
                    start = last + 1;
                    break;
                }
            }
        }
    }
}
int main(){
    int arr[] = {-2,2,6,5,-6,8,12,-22,14};
    int len = 9;
    int i;
    find_max_sub_array(arr,len);
    for(i = indices[0] ; i <= indices[1] ; i++){
        printf("%d->",arr[i]);
    }
}