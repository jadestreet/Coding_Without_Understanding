#include "stdio.h"
void	Merge(int *head, int lowIndex, int midd ,int hiIndex){
	int temp [hiIndex-lowIndex+1];
	int i = lowIndex;
	int j = midd +1;
	int k=0;
	int interator = 0;
	int lenTemp = hiIndex-lowIndex+1;
	while (i<=midd && j<=hiIndex){
		if (head[i]<=head[j])
			temp[k++] = head[i++];
		else if (head[j]<=head[i])
			temp[k++] = head[j++];
		}
		while (i<=midd){
				temp[k++] = head[i++];
		}
		while (j<=hiIndex){
			temp[k++] = head[j++];
		}
			for (k=0, i=lowIndex; i<=hiIndex;++i,++k)
				head[i]=temp[k];
}
void	MergeSort(int *head, int lowIndex, int hiIndex){
	int midd = (lowIndex+hiIndex)/2;
	if (lowIndex<hiIndex){
	MergeSort(head, lowIndex, midd);
	MergeSort(head, midd+1, hiIndex);
	Merge   (head, lowIndex,  midd , hiIndex);
	}
}
int main(){
	int array[]={9,8,7,6,5,4,3,2,1};
	int len = sizeof(array)/sizeof(int);
	MergeSort(array,0,sizeof(array)/sizeof(int)-1);
	for (int i=0;i<len;i++)
		printf("%d-",array[i]);
	printf("=========\n");
	return 0;
};