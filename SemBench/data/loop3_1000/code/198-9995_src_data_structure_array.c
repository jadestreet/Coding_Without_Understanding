#include <stdio.h>
const char NEW_LINE = '\n';
void indexIterator(int num[], int size) {
    printf("一、使用索引遍历一维数组%c", NEW_LINE);
    for (int i = 0; i < size; ++i) {
        printf("num[%d] = %d%c", i, num[i], NEW_LINE);
    }
}
void pointerIterator(int num[], int size) {
    printf("二、使用指针遍历一维数组%c", NEW_LINE);
    for (int i = 0; i < size; ++i) {
        printf("*(num + %d) = %d%c", i, *(num + i), NEW_LINE);
    }
}
void mdArray() {
    printf("三、二组数组%c", NEW_LINE);
    int rowCount = 3;
    int colCount = 3;
    int num[3][3] = {
            { 99, 34, 10 },
            { 9, 6, 3 },
            { 10, 9, 100 }
    };
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            printf("num[%d][%d] = %d%c", i, j, num[i][j], NEW_LINE);
        }
    }
}
int main(int argc, char **argv) {
    printf("数组操作：%c", NEW_LINE);
    int num[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int size = 10;
    indexIterator(num, size);
    pointerIterator(num, size);
    mdArray();
    return 0;
}