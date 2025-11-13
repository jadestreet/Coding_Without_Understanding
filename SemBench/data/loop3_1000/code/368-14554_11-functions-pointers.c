#include <stdlib.h>
#include <stdio.h>
int compare_ascend(int one, int other) {
  return other - one;
}
int compare_descend(int one, int other) {
  return one - other;
}
void sort(int *array, int size, int (*comparison)(int, int)) {
  for (int i = 0; i < size; i++) {
    int least = i;
    for (int j = i + 1; j < size; j++) {
      if ((*comparison)(array[least], array[j]) < 0) {
        least = j;
      }
    }
    if (least != i) {
      int aux = array[i];
      array[i] = array[least];
      array[least] = aux;
    }
  }
}
void print_array(int *array, int size, char *format) {
  printf("[ ");
  for (int i = 0; i < (size - 1); i++) {
    printf(format, array[i]);
    printf(", ");
  }
  printf(format, array[size - 1]);
  printf(" ]");
}
int main(int argc, char const *argv[]) {
  printf("================================\n");
  printf("FUNCTION POINTERS\n");
  printf("================================\n\n");
  const int max = 10;
  int a[max], b[max];
  int (*comparisons[])(int, int) = {compare_ascend, compare_descend};
  for (int i = 0; i < max; i++) {
    int j = max - i - 1;
    a[j] = i;
    b[i] = i;
  }
  printf("Original: A = ");
  print_array(a, max, "%i");
  printf("\n          B = ");
  print_array(b, max, "%i");
  printf("\n");
  sort(a, max, comparisons[0]);
  sort(b, max, comparisons[1]);
  printf("Sorted:   A = ");
  print_array(a, max, "%i");
  printf("\n          B = ");
  print_array(b, max, "%i");
  printf("\n\n");
  return EXIT_SUCCESS;
}