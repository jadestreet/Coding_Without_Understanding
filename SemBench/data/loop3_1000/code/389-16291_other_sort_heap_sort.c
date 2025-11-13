#include <stdio.h>
void heap_adjust(int *a, int low, int high)
{
    int r = a[low];     
    for (int i=2*low + 1; i<=high; i=2*i+1)
    {
        if (i<high && a[i] < a[i+1])
            ++i;
        if (r >= a[i])
            break;
        a[low] = a[i];
        low = i;
    }
    a[low] = r;
}
void heap_sort(int a[], int a_len)
{
    for (int i=(a_len-1)/2; i>=0; i--)
    {
        heap_adjust(a, i, a_len-1);
    }
    for (int i=a_len-1; i>0; i--)
    {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        heap_adjust(a, 0, i-1);
    }
}
int main(void)
{
    int a[] = {9, 7, 3, 4, 6, 2, 0, 11, 5, 10, 1};
    heap_sort(a, 11);
    for (int i= 0; i<11; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}