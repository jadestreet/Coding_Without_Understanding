#include<stdio.h>
#define MAXNUM 10000
void display(int[], int);
void merge_sort(int[], int, int);
void merge(int[], int, int, int);
int main(){
	int n = 7;
	int a[] = {22,1,65,33,78,33,90};
	display(a,n);
	merge_sort(a,0,n-1);
	display(a,n);
	return 0;
}
void merge_sort(int a[],int p, int r){
	int q;
	if(p<r){
		q = (p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}
void merge(int a[], int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[50], R[50];
	int i, j, k;
	for(i = 0; i < n1; i++){
		L[i] = a[p+i];
	}
	for(j = 0; j < n2; j++){
		R[j] = a[q+j+1];
	}
	L[n1] = MAXNUM;
	R[n2] = MAXNUM;
	i = j = 0;
	for(k = p; k <= r; k++){
		if(L[i] <= R[j]){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}
	}
}
void display(int a[],int n){
	int i;
	printf("\n");
	for(i = 0;i<n;i++){
		printf("%d\t",a[i]);
	}
}