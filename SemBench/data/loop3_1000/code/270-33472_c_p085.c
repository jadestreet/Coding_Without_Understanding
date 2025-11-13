#include <stdio.h>
#include <stdlib.h>
int count(const int width, const int height);
int main(int argc, char** argv) {
    int best_delta = 10000000;
    int best_width = 0;
    int best_height = 0;
    for (int w = 1; w < 100; ++w) {
        for (int h = w; h < 100; ++h) {
            const int rects = count(w, h);
            const int delta = abs(2000000 - rects);
            if (rects > 2000000 + best_delta) {
                break;
            }
            if (delta < best_delta) {
                best_delta = delta;
                best_width = w;
                best_height = h;
            }
        }
    }
    printf("%d\n", best_width * best_height);
    return EXIT_SUCCESS;
}
int count(const int width, const int height) {
    int count = 0;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            count += (width - x) * (height - y);
        }
    }
    return count;
}