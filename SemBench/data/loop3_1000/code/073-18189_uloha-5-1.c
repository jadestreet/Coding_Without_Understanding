#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_VALUE	16384
#define HASH(KEY)   KEY % HASH_VALUE
int hashTable[HASH_VALUE] = {-1};
void insert(int key)
{
  int probe;
  int code = HASH(key);
  if(hashTable[code] == -1){
    hashTable[code] = key;
    probe = -1;
  }
  else{
    if(code == HASH_VALUE-1)
      probe = 0;
    else 
      probe = code + 1;   
  }
  while((probe != -1) && (probe != code)){
    if(hashTable[probe] == -1){
      hashTable[probe] = key;
      probe = -1;
    }
    else{
      if(probe == HASH_VALUE-1)
        probe = 0;
      else
        probe++;
    }
  }
}
int search(int key)
{
  int probe;
  int code = HASH(key);
  if(hashTable[code] == -1){
    return 0;
  }
  else if(hashTable[code] == key)
    return 1;
  else{
    if(code == HASH_VALUE-1)
      probe = 0;
    else
      probe = code + 1;
  }
  while((probe != -1) && (probe != code)){
    if(hashTable[probe] == -1)
      return 0;
    else if(hashTable[probe] == key)
      return 1;
    else{
      if(probe == HASH_VALUE-1)
        probe = 0;
      else
        probe++;
    }
  }
  return 0;
}
int is_subset(int s[], int n, int t[], int m)
{
  memset(hashTable, -1 , sizeof(hashTable));
  int i;
  for(i = 0; i<m; i++){
    insert(t[i]);
  }
  for(i = 0; i<n; i++){
    if(!search(s[i]))
      return 0;
  }
  return 1;
}
int main(void)
{
  int a[] = {10, 20, 30};
  int b[] = {30, 10, 10};
	if (is_subset(b, 3, a, 3))
    printf("B je podmnozina A (spravne)\n");
   else
    printf("B nie je podmnozina A (nespravne)\n");
  return 0;
}