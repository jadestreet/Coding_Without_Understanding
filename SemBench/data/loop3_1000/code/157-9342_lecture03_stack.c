#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int *foo() {
    int i;
    int array[SIZE];
    int array1[SIZE];
    printf("%p\n", array);
    printf("%p\n", array1);
    for (i=0; i<SIZE; i++) {
	array[i] = 17;
    }
    return array;
}
void bar() {
    int i;
    int array[SIZE];
    int array1[SIZE];
    printf("%p\n", array);
    printf("%p\n", array1);
    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}
int main()
{
    int i;
    int *array = foo();
    bar();
    for (i=0; i<SIZE; i++) {
	printf("%d\n", array[i]);
    }
    return 0;
}