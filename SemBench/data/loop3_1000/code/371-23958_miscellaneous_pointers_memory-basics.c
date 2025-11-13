#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *int_pointer = malloc(sizeof(int));
    printf("Garbage value in *int_pointer: %d\n", *int_pointer);
    *int_pointer = 50;
    printf("After assigning 50 to *int_pointer, this is its value: %d\n\n", *int_pointer);
    free(int_pointer);
    int *int_array = malloc(3 * sizeof(int));
    int_array[0] = 10;
    int_array[1] = 20;
    int_array[2] = 30;
    for (size_t i = 0; i < 3; i++) {
        printf("int_array[%d] = %d\n", i, int_array[i]);
    }
    printf("\nAnother way of printing the array: \n");
    printf("*int_array = %d\n", *int_array);
    printf("*(int_array + 1) = %d\n", *(int_array + 1));
    printf("*(int_array + 2) = %d\n", *(int_array + 2));
    int_array = calloc(5, sizeof(int));
    int_array[0] = 100;
    int_array[1] = 200;
    for (size_t i = 0; i < 10; i++) {
        printf("int_array[%d] = %d\n", i, int_array[i]);
    }
    int_array = realloc(int_array, 5 * sizeof(int));
    int_array[4] = 500;
    for (size_t i = 0; i < 5; i++) {
        printf("int_array[%d] = %d\n", i, int_array[i]);
    }
    free(int_array);
    return 0;
}