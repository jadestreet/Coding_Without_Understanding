#include <stdio.h>
int strend(char *s, char *t);
int main(int argc, char *argv[]) {
  int res;
  if (argc != 3) {
    printf("Usage: strend str1 str2\n");
    return 1;
  }
  res = strend(argv[1], argv[2]);
  printf("Does {%s} end with {%s}: %d\n", argv[1], argv[2], res);
}
int strend(char *s, char *t) {
  int i, j;
  for (i = 0; s[i] != '\0'; i++)
    ;
  for (j = 0; t[j] != '\0'; j++)
    ;
  while ((i > 0 && j > 0) && s[--i] == t[--j])
    ;
  return (j == 0 && s[i] == t[j]) ? 1 : 0;
}