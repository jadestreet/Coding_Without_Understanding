#include<stdio.h>
int maxArea(int* height, int heightSize) {
    int i = 0, j = heightSize - 1, max = 0, cur;
    int ip;
    while (i < j) {
        if (height[i] < height[j]) {
            cur = height[i] * (j - i);
            if (cur > max)
                max = cur;
            ip = height[i];
            do {
                i++;
            } while (height[i] < ip);
        } else {
            cur = height[j] * (j - i);
            if (cur > max)
                max = cur;
            ip = height[j];
            do {
                j--;
            } while (height[j] < ip);
        }
    }
    return max;
}
int main() {
    int h[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("%d\n", maxArea(h, 10));
    return 0;
}