#include <stdio.h>
void itob(int n, char s[], int b);
void reverse(char s[], int n);
int main() {
  int n;
  char string[1000];
  n = 2803;
  printf("%d decimal represented in hex", n);
  itob(n, string, 16);
  printf(" is %s\n", string);
}
void itob(int n, char s[], int b) {
  int i, sign;
  if ((sign = n) < 0) {
    n = -n;
  }
  i = 0;
  int temp;
  do {
    temp = n % b;
    if (temp >= 0 && temp <= 9) {
      s[i++] = temp + '0';
    } else {
      s[i++] = (temp - 10) + 'A';
    }
  } while ((n /= b) > 0);
  if (sign < 0) {
    s[i++] = '-';
  } 
  s[i] = '\0';
  reverse(s, i);
}
void reverse(char s[], int n) {
  for (int temp, l = 0, r = n - 1; l < r; l++, r--) {
    temp = s[l];
    s[l] = s[r];
    s[r] = temp;
  }
}