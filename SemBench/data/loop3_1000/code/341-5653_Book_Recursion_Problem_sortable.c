#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int findIndex(int * arr, int first, int last, int maxmin)
{
  int ind;
  int  answer = first;
  for (ind = first + 1; ind <= last; ind ++)
    {
      if (((maxmin == 1) && (arr[answer] < arr[ind])) ||
	  ((maxmin == 0) && (arr[answer] > arr[ind])))
	{
	  answer = ind;
	}
    }
  return answer;
}
int findMaxIndex(int * arr, int first, int last)
{
  return findIndex(arr, first, last, 1);
}
int findMinIndex(int * arr, int first, int last)
{
  return findIndex(arr, first, last, 0);
}
int isStackSortable(int * arr, int first, int last)
{
  if (first >= last) 
    {
      return 1;
    }
  int maxIndex = findMaxIndex(arr, first, last);
  if (first == maxIndex)
    {
      return isStackSortable(arr, first + 1, last);
    }
  if (maxIndex == last)
    {
      return isStackSortable(arr, first, last - 1);
    }
  int maxAIndex = findMaxIndex(arr, first, maxIndex - 1);
  int minBIndex = findMinIndex(arr, maxIndex + 1, last);
  if (arr[maxAIndex] > arr[minBIndex])
    {
      return 0; 
    }
  int sortA = isStackSortable(arr, first, maxIndex - 1);
  int sortB = isStackSortable(arr, maxIndex + 1, last);
  return (sortA && sortB); 
}
void printArray(int * arr, int length)
{
  if (isStackSortable(arr, 0, length - 1) == 0)
    {
      return;
    }
  int ind;
  for (ind = 0; ind < length - 1; ind ++)
    {
      printf("%d", arr[ind]);
    }
  printf("%d\n", arr[length - 1]);
}
void swap(int * a, int * b)
{
  int s = * a;
  * a = * b;
  * b = s;
}
void permuteHelp(int * arr, int ind, int num)
{
  if (ind == num)
    {
      printArray(arr, ind);
      return;
    }
  int loc; 
  for (loc = ind; loc < num; loc ++)
    {
      swap(& arr[ind], & arr[loc]);
      permuteHelp(arr, ind + 1, num);
      swap(& arr[ind], & arr[loc]); 
    }
}
void permute(int * arr, int num)
{
  permuteHelp(arr, 0, num);
}
int main(int argc, char * argv[])
{
  if (argc != 2) 
    {
      return EXIT_FAILURE;
    }
  int num = (int) strtol(argv[1], NULL, 10);
  if (num <= 0) 
    {
      return EXIT_FAILURE;      
    }
  int * arr;
  arr = malloc(sizeof(int) * num);
  int ind;
  for (ind = 0; ind < num; ind ++)
    {
      arr[ind] = ind + 1;
    }
  permute(arr, num);
  free (arr);
  return EXIT_SUCCESS;
}