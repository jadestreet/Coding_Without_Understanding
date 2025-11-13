#include <stdio.h>
#define NUM 5
void reverse_array( int *p,int size);
int main()
{
	int array[NUM] = {1,2,3,4,5};
	int i;
	for ( i = 0; i < NUM; i++ )
		printf("%3d",array[i]);
	printf("\n");
	reverse_array(array,NUM);
	for ( i = 0; i < NUM; i++ )
		printf("%3d",array[i]);
	printf("\n");
	return 0;
}
void reverse_array( int *p,int size)
{
	int *start = p;
	int *end = p+(size-1);
	int temp;
	while( start != end )
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	return ;
}