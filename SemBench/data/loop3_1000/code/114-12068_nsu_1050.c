#include <stdio.h>
#define START 95859
#define MEDIAN 6
int is_sym_num(int n) {
    int i, j, flag=1, a[MEDIAN];
    for (i = 0; i < MEDIAN; i++) {a[i] = -1;}
    i = 0;
    while (n != 0) {
        a[i] = n % 10;
        n = (n - a[i]) / 10;
        i++;
    }
    j = 0;
    for (i--; i > j; i--) {
        if (a[i] != a[j]) {
            flag = 0;
            break;
        }
        j++;
    }
    return flag;
}
int main(int argc, const char *argv[])
{
    int i;
    for (i = START + 1; !is_sym_num(i); i++) {}
    printf("%d\n", i);
    return 0;
}