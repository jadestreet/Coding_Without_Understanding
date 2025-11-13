#include <stdio.h>
#define ARRAY_LENGTH 20
typedef int (*compare_cb)(int a, int b);
void troca(int *v, int i, int j) {
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
int empurra_maior(int *v, int n) {
  if (n <= 1) return 0;
  if (v[0] > v[1]) {
    troca(v, 0, 1);
    empurra_maior(v+1, n-1);
    return 1;
  }
  return empurra_maior(v+1, n-1);
}
void bubble_r( int *v, int n) {
  if (n <= 1) return;
  if (empurra_maior(v, n)) bubble_r(v, n-1);
}
void bubble_sort(int *numbers, int count, compare_cb cmp) {
  int temp, i, j;
  for(i = 0; i < count; i++) {
    for(j = 0; j < count - 1; j++) {
      if(cmp(numbers[j], numbers[j+1]) > 0) {
        temp = numbers[j+1];
        numbers[j+1] = numbers[j];
        numbers[j] = temp;
      }
    }
  }
}
void enhanced_bubble_sort(int *numbers, int count, compare_cb cmp) {
  int temp, i, j, swapped;
  for(i = 0; i < count; i++) {
    swapped = 0;
    for(j = 0; j < count - 1; j++) {
      if(cmp(numbers[j], numbers[j+1]) > 0) {
        temp = numbers[j+1];
        numbers[j+1] = numbers[j];
        numbers[j] = temp;
        swapped++;
      }
    }
    if (!swapped) break;
  }
}
int sorted_order(int a, int b) { return a - b; }
int reverse_order(int a, int b) { return b - a; }
int strange_order(int a, int b) { return (a == 0 || b == 0) ? 0 : a % b; }
void test_sorting(int *numbers, int count, compare_cb cmp) {
  int i;
  enhanced_bubble_sort(numbers, count, cmp);
  for(i = 0; i < count; i++) { printf("%d ", numbers[i]); }
  printf("\n");
}
int main(int argc, char *argv[]) {
  int array[ARRAY_LENGTH] = { 19, 18, 17, 16, 15, 14, 13, 12, 11, 20 ,1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int array2[ARRAY_LENGTH] = { 19, 18, 17, 16, 15, 14, 13, 12, 11, 20 ,1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int array3[ARRAY_LENGTH] = { 19, 18, 17, 16, 15, 14, 13, 12, 11, 20 ,1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int i;
  for(i = 0; i < ARRAY_LENGTH; i++) { printf("%d ", array3[i]); }
  bubble_r(array3, ARRAY_LENGTH);
  printf("\n");
  for(i = 0; i < ARRAY_LENGTH; i++) { printf("%d ", array3[i]); }
  return 0;
}