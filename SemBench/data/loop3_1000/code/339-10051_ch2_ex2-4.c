#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NUM_ARGS 2
#define TEST_LEN 10
void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
void quicksort(int v[], int n)
{
    int i, last;
    if (n <= 1) 
        return;
    swap(v, 0, rand() % n);     
    last = 0;
    for (i = 1; i < n; ++i)     
        if (v[i] < v[0])
            swap(v, ++last, i);
    swap(v, 0, last);           
    quicksort(v, last);         
    quicksort(v+last+1, n-last-1);
}
void nicksort(int v[], int n)
{
    if (n <= 1) 
        return;
    int i, j, right;
    right = 1;
    for (i = 0; i < n-1; ++i)
    {
        for (j = right; j < n; ++j)
        {
            if (v[j] < v[i]) {
                swap(v, i, j);
            }
        }
        ++right;
    }
}
void usage(char *prog_name)
{
    printf("Usage:\n\t%s <num_elements_to_sort> <num_times_to_sort>",
            prog_name);
}
void print_array(int arr[], int n)
{
    int i;
    printf("%d", arr[0]);
    for (i = 1; i < n; ++i)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}
int main(int argc, char **argv)
{
    if (argc < NUM_ARGS+1) {
        usage(argv[0]);
        return 1;
    }
    int num_elements = atoi(argv[1]);
    int num_attempts = atoi(argv[2]);
    int i, j;
    clock_t begin, end;
    int q_test_array[TEST_LEN], n_test_array[TEST_LEN];
    int q_array[num_elements], n_array[num_elements];
    double q_total_time, n_total_time, q_avg_time, n_avg_time;
    printf("Beginning sanity check:\n");
    srand(clock());
    for (i = 0; i < TEST_LEN; ++i)
    {
        q_test_array[i] = n_test_array[i] = rand() % TEST_LEN;
    }
    printf("\tTest array: ");
    print_array(q_test_array, TEST_LEN);
    quicksort(q_test_array, TEST_LEN);
    printf("\tQuicksort:  ");
    print_array(q_test_array, TEST_LEN);
    nicksort(n_test_array, TEST_LEN);
    printf("\tNicksort:   ");
    print_array(n_test_array, TEST_LEN);
    for (i = 0; i < num_attempts; ++i)
    {
        srand(clock());
        for (j = 0; j < num_elements; ++j)
        {
            q_array[j] = n_array[j] = rand() % num_elements;
        }
        begin = clock();
        quicksort(q_array, num_elements);
        end = clock();
        q_total_time += ((double)end - (double)begin) / CLOCKS_PER_SEC;
        begin = clock();
        nicksort(n_array, num_elements);
        end = clock();
        n_total_time += ((double)end - (double)begin) / CLOCKS_PER_SEC;
    }
    q_avg_time = q_total_time / num_attempts;
    n_avg_time = n_total_time / num_attempts;
    printf("Testing finished, statistics (in seconds):\n");
    printf("\tQuicksort total time:   %f\n", q_total_time);
    printf("\tQuicksort average time: %f\n", q_avg_time);
    printf("\tNicksort total time:    %f\n", n_total_time);
    printf("\tNicksort average time:  %f\n", n_avg_time);
    return 0;
}