#include <stdio.h>
inline static int is_digit(char c) {
    return '0' <= c && c <= '9';
}
static long long unsigned int fparse_lluint() {
    long long unsigned int v = 0;
    char c = getc(stdin);
    do {
        v = 10*v + (c - '0');
        c = getc(stdin);
    } while (c != EOF && is_digit(c));
    ungetc(c, stdin);
    return v;
}
int main(int argc, char** argv) {
    char c;
    while ((c = getc(stdin)) != EOF) {
        ungetc(c, stdin);
        long long unsigned int x = fparse_lluint();
        getc(stdin); 
        printf("%llu\n", x);
    }
    return 0;
}