#include <stdio.h>
#define NUM 5
int main(void)
{
	int  array[NUM] = {1,2,3,4,5};
	int  i,temp ;
	for( i = 0; i < NUM; i++)
	{
		printf("array[%d]=%d\n",i,array[i]);
	}
	temp = array[0];
	printf("\nafter shift:\n");
	for( i = 0; i < NUM-1; i++)
	{
		array[i] = array[i+1];
	}
	array[NUM-1] = temp;
	for( i = 0; i < NUM; i++)
	{
		printf("array[%d]=%d\n",i,array[i]);
	}
	return 0;
}