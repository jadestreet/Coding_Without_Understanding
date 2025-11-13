#include <stdio.h>
int main (int argc, char *argv[]) {
  int i = 0;
  char *chars[] = {"aaa", "bbb"};
  while (i < 2) {
    printf("%s\n", chars[i]);
    int j = 0;
    while(chars[i][j]) {
      printf("%c\n", chars[i][j]);
      j++;
    }
    i++;
  } 
  i = 0;
  while (i < 25) {
    printf("%d", i);
    i++;
  } 
  return 0;
} 