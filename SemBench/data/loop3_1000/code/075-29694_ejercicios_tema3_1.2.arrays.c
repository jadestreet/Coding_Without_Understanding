#include <stdio.h>
void print_array(int arr[], int count)
{
	for (int i = 0; i < count; i++)
		printf("%d, ", arr[i]);
	printf("\n\n");
}
int main(void)
{
	int my_array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (int i = 0; i < 10; i++)
		printf("%d, ", my_array[i]);
	printf("\n\n");
	for (int i = 9; i >= 0; i -= 2)
		printf("%d, ", my_array[i]);
	printf("\n\n");
	int temp = my_array[0];
	for (int i = 0; i < 9; i++)
		my_array[i] = my_array[i + 1];
	my_array[9] = temp;
	print_array(my_array, 10);
	temp = my_array[9];
	for (int i = 9; i > 0; i--)
		my_array[i] = my_array[i - 1];
	my_array[0] = temp;
	print_array(my_array, 10);
	for (int i = 0; i < 10 / 2; i++)
		my_array[i] = my_array[9 - i];
	print_array(my_array, 10);
	return 0;
}