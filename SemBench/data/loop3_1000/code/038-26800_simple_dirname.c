#include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
  char *p;
  char *path;
  if (argc != 2) {
	fprintf(stderr, "Usage: %s path\n", argv[0]);
	return(1);
  }
  path = argv[1];
  p = path + strlen(path);
  while (p > path && p[-1] == '/') p--;	
  while (p > path && p[-1] != '/') p--;	
  while (p > path && p[-1] == '/') p--;	
  if (p == path) {
	printf(path[0] == '/' ? "/\n" : ".\n");
  } else {
	printf("%.*s\n", (int) (p - path), path);
  }
  return(0);
}