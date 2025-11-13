#include <stdio.h>
int findMinNumberInRotatedArray(int *array, int low, int high){
    if(array == NULL || low < 0 || high <= 0 || high <= low ){
        return -1;
    }
    if(high - low == 1){
        return high;
    }
    int medium = (low + high)/2;
    int position;
    if(array[medium] >= array[low]){
        position = findMinNumberInRotatedArray(array, medium, high);
    }else if(array[medium] <= array[low]){
        position = findMinNumberInRotatedArray(array, low, medium);
    }
    return position;
}
int findMinNumberInRotatedArray_loop(int *array, int low, int high){
    if(array == NULL || low < 0 || high < 0 || high < low ){
        return -1;
    }
    int medium;
    while(high - low > 1){
        medium = (high + low)/2;
        if(array[medium] >= array[low]){
            low = medium;
        }else if(array[medium] <= array[low]){
            high = medium;
        }
    }
    return high;
}
int findMinNumberInRotatedArray_improved(int *array, int length){
    int low = 0;
    int high = length - 1;
    int medium = low; 
    while(array[low] >= array[high]){ 
        medium = (low + high)/2;
        if(high - low == 1){
            medium = high;
            break;
        }
        if(array[low] == array[high] && array[low] == array[medium]){
            int min = array[low];
            for(int i = low; i <= high; ++i){
                if(array[i]<min){
                    min = array[i];
                }
            }
            return min;
        }
        if(array[medium] >= array[low]){
            low = medium;
        }else if(array[medium] <= array[low]){
            high = medium;
        }
    }
    return medium;
}
int main(int argc, const char *argv[])
{
    int array[] = {1,1,1,0,1};
    int position = findMinNumberInRotatedArray_improved(array, 5);
    printf("%d\n", position);
    return 0;
}