#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    int i;
    srand((unsigned) 1);
    printf("Start\n");
    double * xy = (double *) malloc(sizeof(double) * (1000000 * 2));
    for (i = 0; i < 2000000; i+=2) {
        xy[i] = (double) rand() / RAND_MAX;
        xy[i+1] = (double) rand() / RAND_MAX;
    }
    printf("Numbers\n");
    clock_t start, end;
    double centerX = 0.0;
    double centerY = 0.0;
    printf("Average\n");
    start = clock();
    for (i = 0; i < 2000000; i+=2) {
        centerX += xy[i];
    }
    for (i = 1; i < 2000000; i+=2) {
        centerY += xy[i];
    }
    centerX *= 0.000001;
    centerY *= 0.000001;
    end = clock();
    printf("Done\n");
    printf("%f %f\n", centerX, centerY);
    printf("%d\n", end - start);
}