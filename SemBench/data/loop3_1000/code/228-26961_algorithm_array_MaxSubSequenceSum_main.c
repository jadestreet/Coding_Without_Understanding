#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int MaxSubSequenceSum1(const int A[], int N) {
  int ThisSum, MaxSum, i, j, k;
  MaxSum = 0;
  for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
      ThisSum = 0;
      for (k = i; k <= j; k++) {
        ThisSum += A[k];
      }
      if (ThisSum > MaxSum) {
        MaxSum = ThisSum;
      }
    }
  }
  return MaxSum;
}
int MaxSubSequenceSum2(const int A[], int N) {
  int ThisSum, MaxSum, i, j;
  MaxSum = 0;
  for (i = 0; i < N; i++) {
    ThisSum = 0;
    for (j = i; j < N; j++) {
      ThisSum += A[j];
      if (ThisSum > MaxSum) MaxSum = ThisSum;
    }
  }
  return MaxSum;
}
int max(int a, int b) { return a > b ? a : b; }
int Max3(int a, int b, int c) { return max(max(a, b), c); }
static int MaxSubSum(const int A[], int Left, int Right) {
  int MaxLeftSum, MaxRightSum;
  int MaxLeftBorderSum, MaxRightBorderSum;
  int LeftBorderSum, RightBorderSum;
  int Center, i;
  if (Left == Right) {
    if (A[Left] > 0)
      return A[Left];
    else
      return 0;
  }
  Center = (Left + Right) / 2;
  MaxLeftSum = MaxSubSum(A, Left, Center);
  MaxRightSum = MaxSubSum(A, Center + 1, Right);
  MaxLeftBorderSum = 0;
  LeftBorderSum = 0;
  for (i = Center; i >= Left; i--) {
    LeftBorderSum += A[i];
    if (LeftBorderSum > MaxLeftBorderSum) MaxLeftBorderSum = LeftBorderSum;
  }
  MaxRightBorderSum = 0;
  RightBorderSum = 0;
  for (i = Center + 1; i <= Right; i++) {
    RightBorderSum += A[i];
    if (RightBorderSum > MaxRightBorderSum) MaxRightBorderSum = RightBorderSum;
  }
  return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}
int MaxSubSequenceSum3(const int A[], int N) { return MaxSubSum(A, 0, N - 1); }
int MaxSubSequenceSum4(const int A[], int N) {
  int ThisSum, MaxSum, j;
  ThisSum = MaxSum = 0;
  for (j = 0; j < N; j++) {
    ThisSum += A[j];
    if (ThisSum > MaxSum)
      MaxSum = ThisSum;
    else if (ThisSum < 0)
      ThisSum = 0;
  }
  return MaxSum;
}
int main(int argc, char *argv[]) {
  int A[] = {4, -3, 5, -2, -1, 2, 6, -2};
  int R = MaxSubSequenceSum1(A, 8);
  printf("%d\n", R);
  R = MaxSubSequenceSum2(A, 8);
  printf("%d\n", R);
  R = MaxSubSequenceSum3(A, 8);
  printf("%d\n", R);
  R = MaxSubSequenceSum4(A, 8);
  printf("%d\n", R);
  int B[1000] = {0};
  srand((unsigned int)time(NULL));
  for (int i = 0; i < 1000; ++i) {
    B[i] = rand() % 90 + 10;  
  }
  printf("%d\n", rand() % 90 + 10);
  return 0;
}