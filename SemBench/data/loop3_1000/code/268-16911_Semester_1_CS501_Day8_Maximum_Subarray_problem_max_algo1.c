#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	int size = sizeof(a)/sizeof(a[0]);
	int maxSum = INT_MIN, length;
	for(int i = 0; i < size ; i++){
		for (int j = i; j < size; ++j){
			int sum = 0;
			for(int k = i; k < j+1; k++){
				sum += a[k];
				if(sum > maxSum){
					maxSum = sum;
					length = j - i + 1;
				}
			}
		}
	}
	printf("The maxSum is %d\n", maxSum);
	printf("Its length is %d\n", length);
	return 0;
}