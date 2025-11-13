#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int brute_force(char *string) {
  for (int i = 0; 0 != string[i]; i++) {
    for (int j = i + 1; 0 != string[j]; j++) {
      if (string[i] == string[j]) {
	return 0;
      }
    }
  }
  return 1;
}
int hashmap(char * string) {
  char hashmap[512];
  memset(hashmap, 0, 512);
  for (int c = 0; 0 != string[c]; c++) {
    int index = (int) string[c];
    if (hashmap[index] != 0)
      return 0;
    hashmap[index] = 1;
  }
  return 1;
}
int compare(const void *a, const void *b) {
  return (*(char *)a - *(char *)b);
}
int sort(char *string) {
  size_t len = strnlen(string, sizeof string);
  qsort(string, len, sizeof(char), compare);
  for (int i = 1; 0 != string[i]; i++) {
    if (string[i] == string[i - 1]) {
      return 0;
    }
  }
  return 1;
}
void debug_execution(int (*function)(char*), char *string, char *debug_message) {
  clock_t begin, end;
  double time_spent;
  begin = clock();
  int res = (*function)(string);
  end = clock();
  time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
  printf("%s %s%f\n", res ? "YES" : "NO", debug_message, time_spent);
}
int main(int argc, char **argv) {
  assert(argc == 2);
  char *string = argv[1];
  printf("is \"%s\" unique?\n\n", string);
  debug_execution(brute_force, string, "O(n^2): ");
  debug_execution(hashmap, string, "O(n) espacio: O(n): ");
  debug_execution(sort, string, "O(n log n): ");
  return 0;
}