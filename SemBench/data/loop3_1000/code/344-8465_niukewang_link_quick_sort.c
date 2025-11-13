#include<stdio.h>
#include<math.h>
void print_array(int a[],int n);
void quick_s(int a[],int s,int e)
{
	int i = s,j = e; 
	int key = a[s]; 
    int temp;
	if( s > e || !a ) return;
	while(i < j){ 
		while( i < j && a[j] >= key) 
			j--;
		while( i < j && a[i] <= key) 
			i++;
		temp = a[j];
		a[j] = a[i];
		a[i] = temp;
	}
	a[s] = a[i]; 
	a[i] = key;  
   print_array(a,e-s+1);
	quick_s(a,s,i-1);
	quick_s(a,j+1,e);
}
void print_array(int a[],int n)
{
	int i;
	for(i = 0;i < n;++i)
		printf("%d ",a[i]);
	printf("\n");
}
int main()
{
	int a[] = {20,15,30,25,50,10,40};
	quick_s(a,0,6);
  unsigned int c= 0x12345678;
 unsigned char b = *(unsigned char*)&c;
printf("0x%x\n",b);
printf("%d\n",pow(2,1));
	return 0;
}