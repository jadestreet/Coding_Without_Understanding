#include <stdio.h>
int main() {
  int i, j, k, n = 3, count = 0, breakIt = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      for (k = 0; k < n; k++) {
        if (i == 1 && j == 1 && k == 1) {
          breakIt = 1;
          break;
        }
        count++;
      }
      if (breakIt)
        break;
    }
    if (breakIt)
      break;
  }
  printf("Count = %d\n\n", count);
  return 0;
}