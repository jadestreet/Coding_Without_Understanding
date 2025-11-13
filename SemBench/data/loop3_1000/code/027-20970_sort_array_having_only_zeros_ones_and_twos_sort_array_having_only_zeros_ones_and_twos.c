#include<stdio.h>
#include<string.h>
#include<assert.h>
void sort_array_of_zeros_ones_and_twos_ver1 (int *array, int len)
{
    int ones = 0;
    int zeros = 0;
    int twos = 0;
    int i = 0;
    if (!array || (len <= 0)) {
        return;
    }
    for (i = 0; i < len; ++i) {
        if (array[i] == 0) {
            zeros++;
        }
        if (array[i] == 1) {
            ones++;
        }
        if (array[i] == 2) {
            twos++;
        }
    }
    for (i = 0; i < zeros; ++i) {
        array[i] = 0;
    }
    for (i = 0; i < ones; ++i) {
        array[i + zeros] = 1;
    }
    for (i = 0; i < twos; ++i) {
        array[i + zeros + ones] = 2;
    }
}
void sort_array_of_zeros_ones_and_twos_ver2 (int *array, int len)
{
    int low, high, mid, temp;
    if (!array || (len <= 0)) {
        return;
    }
    low = mid = 0;
    high = len - 1;
    while (mid <= high) {
        if (array[mid] == 2) {
            temp = array[mid];
            array[mid] = array[high];
            array[high] = temp;
            --high;
        } else if (array[mid] == 1) {
            ++mid;
        } else {
            temp = array[low];
            array[low] = array[mid];
            array[mid] = temp;
            ++low;
            ++mid;
        }
    }
}
int main()
{
    int array_test_ver1_1[] = {2,2,2,2,1,1,1,1,0,0,0,0,0,0};
    int array_expect_ver1_1[] = {0,0,0,0,0,0,1,1,1,1,2,2,2,2};
    sort_array_of_zeros_ones_and_twos_ver1(
                    array_test_ver1_1,
                    sizeof(array_test_ver1_1)/sizeof(int));
    assert(memcmp(array_test_ver1_1, array_expect_ver1_1,
                  sizeof(array_test_ver1_1)) == 0);
    int array_test_ver2_1[] = {2,2,2,2,1,1,1,1,0,0,0,0,0,0};
    int array_expect_ver2_1[] = {0,0,0,0,0,0,1,1,1,1,2,2,2,2};
    sort_array_of_zeros_ones_and_twos_ver2(
                    array_test_ver2_1,
                    sizeof(array_test_ver2_1)/sizeof(int));
    assert(memcmp(array_test_ver2_1, array_expect_ver2_1,
                  sizeof(array_test_ver2_1)) == 0);
    return(0);
}