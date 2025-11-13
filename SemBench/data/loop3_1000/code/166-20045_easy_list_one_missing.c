#include <stdio.h>
int find_brute(int array[], int size) {
    int temp[size];
    for (int i = 0; i < size; i++) {
        temp[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) temp[array[i] - 1] = 1;
    }
    for (int i = 0; i < size; i++) {
        if (temp[i] != 1) return i + 1;
    }
    return 0;
}
int find(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return size * (size + 1) / 2 - sum;
}
int test_not_missing() {
    int array_odd[] = {6, 3, 9, 1, 5, 4, 7, 8, 2};
    int array_even[] = {6, 3, 1, 5, 4, 7, 8, 2};
    return 0 == find_brute(array_odd, 9) &&
           0 == find(array_odd, 9) &&
           0 == find_brute(array_even, 8) &&
           0 == find(array_even, 8);
}
int test_missing() {
    int array_odd[] = {6, 0, 9, 5, 4, 1, 7, 8, 2};
    int array_even[] = {6, 0, 5, 4, 1, 7, 8, 2};
    return 3 == find_brute(array_odd, 9) &&
           3 == find(array_odd, 9) &&
           3 == find_brute(array_even, 8) &&
           3 == find(array_even, 8);
}
int main() {
    int counter = 0;
    if (!test_not_missing()) {
        printf("Not missing test failed!\n");
        counter++;
    }
    if (!test_missing()) {
        printf("Missing test failed!\n");
        counter++;
    }
    printf("%d tests failed.\n", counter);
}