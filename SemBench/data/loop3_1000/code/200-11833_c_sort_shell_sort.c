#include <stdio.h>
#define LENGTH 10
void shell_sort(int a[], int n){
	int gap = n / 2;
	int temp, i;
	int flag = 0;
	while(gap >= 1){
		do{
			flag = 0;
			for(i = 0; i < n - gap; ++i){
				if(a[i] > a[i + gap]){
					temp = a[i];
					a[i] = a[i + gap];
					a[i + gap] = temp;
					flag = 1;
				}
			}
		} while(flag != 0);
		gap = gap / 2;
	}
}
int main(){
	int a[] = {9,8,7,6,5,4,3,2,1,0};
	int i = 0;
	shell_sort(a, LENGTH);
	while(i < LENGTH){
		printf("%d", a[i]);
		printf(",");
		i++;
	}
	return 0;
}