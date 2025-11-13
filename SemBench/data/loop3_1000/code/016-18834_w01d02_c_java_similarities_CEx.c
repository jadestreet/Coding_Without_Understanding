#include <stdio.h>
int main(int argc, char *argv[]) {
  char  c1 = 'a';
  short  s1 = 0;
  int    i1 = 0;
  long   l1 = 0;
  float  f1 = 0;
  double d1 = 0;
  printf("Hi! Number %d\n", 5);
  if(3 < 4) {
    printf("This works.\n");
  }
  if(3 > 4) {
    printf("This works.\n");
  } else {
    printf("This does not work.\n");
  }
  int counter = 0;
  while (counter < 10) {
    printf ("%d ", counter++);
  }
  printf ("\n");
  int x1 = 0;
  do {
    printf ("%d ", x1++);
  } while (x1 < 10);
  printf ("\n");
  for (int x2 = 0; x2 < 10; x2++){
    printf ("%d ", x2);
  }
  printf ("\n");
}
int add_values (int x, int y) {
  return x + y;
}