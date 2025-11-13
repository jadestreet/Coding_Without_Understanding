#include <stdio.h>
void expand(char in[], char out[]);
void zeroout(char a[]);
int main(void)
{
  char testout[200];
  zeroout(testout);
  expand("a-z0-9", testout);
}
void expand(char in[], char out[])
{
  char c, i, o, start, end;
  i = o = 0;
  while ((c = in[i++]) != '\0') {
    if (c == '-') {
      start = in[i - 2]; 
      end = in[i];
      if (start <= ' ') 
        continue;
      while (start < (end - 1)) 
        out[o++] = ++start;
    } else {
      out[o++] = c;
    }
  }
  printf("In: %s  Out: %s\n", in, out);
}
void zeroout(char a[])
{
  int i = 0;
  while (a[i] != '\0')
    a[i++] = 0;
}