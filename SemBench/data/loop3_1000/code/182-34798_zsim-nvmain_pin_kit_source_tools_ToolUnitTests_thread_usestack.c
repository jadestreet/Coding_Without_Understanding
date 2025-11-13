#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <memory.h>
#include <string.h>
#define ARRAY_SIZE 10000
#define BUCKET 100000
static int total_compares = 0;
int compare_int(const void *p, const void *q)
{
    const int *pi = (const int *)p;
    const int *qi = (const int *)q;
    total_compares++;
    return ((*pi) - (*qi));
}
void stacksort(int *array, size_t nelem, int (*compar)(const void *, const void *))
{
    int left[ARRAY_SIZE];
    int right[ARRAY_SIZE];
    int i, nleft, nright, il, ir;
    if (nelem == 1)
        return;
    if (nelem == 2)
    {
        if (compar(&array[0], &array[1]) > 0)
        {
            int t = array[0];
            array[0] = array[1];
            array[1] = t;
        }
        return;
    }
    for (i = 0; i < nelem/2; i++)
    {
        left[i] = array[2 * i];
        right[i] = array[2 * i + 1];
    }
    nleft = nright = nelem/2;
    if (nelem % 2)
    {
        left[nleft++] = array[nelem - 1];
    }
    stacksort(left, nleft, compar);
    stacksort(right, nright, compar);
    for (il = ir = i = 0; i < nelem; i++)
    {
        if (il == nleft)
        {
            array[i] = right[ir++];
            continue;
        }
        if (ir == nright)
        {
            array[i] = left[il++];
            continue;
        }
        if (compar(&left[il], &right[ir]) > 0)
            array[i] = right[ir++];
        else
            array[i] = left[il++];
    }
}
void use_array(int *arr)
{
    int i = 0, b[ARRAY_SIZE];
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        b[i] = arr[i] = random() % BUCKET;
    }
    qsort(b, ARRAY_SIZE, sizeof(int), compare_int);
    printf("Total number of compares for qsort = %d\n", total_compares);
    total_compares = 0;
    stacksort(arr, ARRAY_SIZE, compare_int);
    printf("Total number of compares for mergesort = %d\n", total_compares);
    total_compares = 0;
}
void* thread(void *dummy)
{
    int a[ARRAY_SIZE];
    use_array(a);
    return 0;
}
int main(int argc, char* argv[])
{
    pthread_t l;
    fprintf(stderr,"Start\n");
    pthread_create(&l,0,thread,0);
    pthread_join(l, 0);
    return 0;
}