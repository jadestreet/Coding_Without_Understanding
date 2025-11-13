#include <stdio.h>
#include <math.h>
#include <string.h>
int is_palindrome (unsigned int n);
int main () {
  is_palindrome(9008);
  long unsigned int largest  = 0;
  long unsigned int result   = 0;
  for (int m=100; m < 1000; m++) {
    for (int n=100; n <= m; n++) {
      result = m * n;
      if (result > largest && is_palindrome(result)) {
        largest = result;
      }
    }
  }
  printf("%lu\n", largest);
  return 0;
}
int is_palindrome (unsigned int n) {
  char str[90];
  sprintf(str, "%u", n);
  int len = strlen(str);
  for (int i=0; i < len/2; i++) {
    if (str[i] != str[len-i-1]) {
      return 0;
    }
  }
  return 1;
}