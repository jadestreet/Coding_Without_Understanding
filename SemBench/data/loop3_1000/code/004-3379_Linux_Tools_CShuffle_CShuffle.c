#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
char *cProgramName;
void PrintStr(char *cString)
{
  char cSlash;
  cSlash = '\\';
  int i;
  i = 0;
  putchar('\'');
  while (cString[i]) 
  {
    putchar(cString[i]);
    i++;
  }
  putchar('\'');
  putchar(0x20);
}
void PrintArray(const int argc, char **argv)
{ 
  if (argc > 1)
  {
    for (int i = 0; i < argc; i++)
      if ((strcmp("./shuffle", argv[i]) & strcmp("shuffle", argv[i])) != 0)     
      { PrintStr(argv[i]); }
  }
}
void Shuffle(const int argc, char **argv)
{
  char *cArray[argc];
  int iArray[argc];
  int iRandom;
  char b;
  for (int i = 0; i < argc; i++)
  {
Random:
    b = 1;
    int iRandom;
    iRandom = (rand() % (argc));
    for (int j = 0; j < i; j++)
    {
      if (iArray[j] == iRandom)
        goto Random; 
    }
    iArray[i] = iRandom;
  }
  for (int i = 0; i < argc; i++)
    cArray[i] = argv[iArray[i]];
  PrintArray(argc, cArray); 
}
int main(int argc, char **argv)
{
  cProgramName = "./shuffle";
  srand(time(NULL));
  Shuffle(argc, argv);
  return 0;
}