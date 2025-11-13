#include <stdio.h>
int main() {
  int i, j;
  for ( i = 0; i < 5; i++) {
    for (size_t k = 0; k < i; k++) {
      printf(" ");
    }
    for ( j = i; j < 5; j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}