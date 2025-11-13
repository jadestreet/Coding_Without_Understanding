#include <stdio.h>
int main() {
    int i, j;
    for (i = 1; i <= 5; i++) {
        if (i == 1 || i == 5) {
            for (j = 1; j <= 3; j++) printf("%d ", j);
            for (j = 2; j >= 1; j--) printf("%d ", j);
        } else {
            for (j = 1; j <= 5; j++) {
                if (j == 1 || j == 5)
                    printf("1 ");
                else
                    printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}