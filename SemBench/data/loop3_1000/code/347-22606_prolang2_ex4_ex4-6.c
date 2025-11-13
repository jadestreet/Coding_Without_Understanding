#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int a[], int n, int i, int j) {
    int s = a[i];
    int left = i;
    int right = j+1;
    int temp;
    do{
        do{
            left++;
        }while(left<n&&a[left]<s);
        do{
            right--;
        }while(a[right]>s);
        if(left<right){
            temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }while(left<right);
    a[i] = a[right];
    a[right] = s;
    return right;
}
void quick_sort(int a[], int n, int i, int j) {
    int m;
    if ( i < j ) {
        m = partition( a, n, i, j );
        quick_sort( a, n, i, m-1 );
        quick_sort( a, n, m+1, j );
    }
}
void check( int a[], int n ){
    int i;
    for ( i = 0; i < (n-1); i++ ){
        if ( a[i] > a[i+1] ){
            printf("NG: この配列は昇順に並んでいません\n");
            return; 
        }
    }
    printf("OK: この配列は昇順に並んでいます\n");
}
int main(int argc, char* argv[]){
  int i, n;
  int* a;
  clock_t start, end;
  float time;
  if ( argc < 2 ){
    printf("*** エラー: コマンドライン引数に配列の長さを指定して下さい\n");
    return 1;
  }
  n = atoi(argv[1]);
  printf("配列の長さ = %d\n", n);
  a = calloc( n, sizeof(int) );
  if ( a == NULL ){
    printf("配列のメモリ確保に失敗しました\n");
    return 1;
  }
  for ( i = 0; i < n; i++ ){
    a[i] = n-i;
  }
  start = clock();
  quick_sort(a,n,0,n-1);
  end = clock();
  time = (float)(end - start)/CLOCKS_PER_SEC;
  printf("ソーティングにかかった時間 = %7.3f 秒\n", time);
  free(a);
  return 0;
}