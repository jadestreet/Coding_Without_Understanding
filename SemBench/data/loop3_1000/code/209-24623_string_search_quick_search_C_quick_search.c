#include <stdio.h>
#include <string.h>
#define ALPHABET_SIZE 256
#define FOUND(pos) { printf("Found at position %d\n", pos); }
#define TEST(T, P) {\
    printf("TEXT: '%s'\n", T);\
    printf("PATTERN: '%s'\n", P);\
    quick_search(T, P);\
    puts("");\
}
void quick_search(const char* T, const char* P) {
    int n = strlen(T), m = strlen(P);
    int shift[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; ++i)
        shift[i] = m + 1;
    for (int i = 0; i < m; ++i)
        shift[P[i]] = m - i;
    int pos = m - 1;
    while (pos < n) {
        int i = 0;
        while (i < m && P[m - i - 1] == T[pos - i])
            ++i;
        if (i >= m)
            FOUND(pos - m + 1);
        pos += shift[T[pos+1]];
    }
}
int main() {
    char P[] = "abc";
    TEST("abcgaaabbbabbbc", P);
    TEST("accgaaabbbabbabc", P);
    TEST("accgaaabcbbabbab", P);
    TEST("abcgaaabcabcbababc", P);
}