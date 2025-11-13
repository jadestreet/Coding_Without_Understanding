#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include <dirent.h>
struct A {
    int a;
    int b;
};
struct B {
    int c;
    int d;
};
struct C
{
    struct A a;
    struct B b;
    short  s;
    char x;
    char szbuf[256];
};
struct D
{
    struct A a;
    short  s;
    struct B b;
    char x;
    char szbuf[256];
};
void show_mem(const void * s, int iSize) {
    int i = 0;
    unsigned const char * p = (unsigned const char *)s;
    int ilen = 16;
    int g = iSize / ilen + (iSize % ilen > 0);
    for(i = 0; i < g; i++) {
        printf("%3d ~ %3d : ", i * ilen, (i * ilen + ilen - 1) >= iSize ? iSize - 1 : (i * ilen + ilen - 1));
        int k = i * ilen;
        for(; k < i * ilen + ilen ; k++){
            if(k >= iSize) {
                printf("   ");
                continue;
            }
            printf("%02X ", p[k]);
        }
        for(k = i * ilen; k < i * ilen + ilen; k++){
            if(k >= iSize) {
                printf("   ");
                continue;
            }
            if(isprint(p[k])) {
                printf("%c", p[k]);
            } else if ('\0' == p[k]) {
                printf("%c", '.');
            } else {
                printf("?");
            }
        }
        printf("\n");
    }
}
void show_struct(struct C * c) {
    printf("sizeof(struct C) = [%lu]\n", sizeof(struct C));
    printf("address start : [%lu]\n", (unsigned long)c);
    printf("address a     : [%lu]\n", (unsigned long)&c -> a);
    printf("address b     : [%lu]\n", (unsigned long)&c -> b);
    printf("address s     : [%lu]\n", (unsigned long)&c -> s);
    printf("address x     : [%lu]\n", (unsigned long)&c -> x);
    printf("address szbuf : [%lu]\n", (unsigned long)&c -> szbuf);
}
void show_struct_D(struct D * c) {
    printf("sizeof(struct D) = [%lu]\n", sizeof(struct C));
    printf("address start : [%lu]\n", (unsigned long)c);
    printf("address a     : [%lu]\n", (unsigned long)&c -> a);
    printf("address b     : [%lu]\n", (unsigned long)&c -> b);
    printf("address s     : [%lu]\n", (unsigned long)&c -> s);
    printf("address x     : [%lu]\n", (unsigned long)&c -> x);
    printf("address szbuf : [%lu]\n", (unsigned long)&c -> szbuf);
}
void show_dir_struct(struct dirent * x) {
    printf("sizeof(struct dirent) = [%lu]\n", sizeof(struct dirent));
    printf("address start    : [%lu]\n", (unsigned long)x);
    printf("address d_ino    : [%lu]\n", (unsigned long)&x -> d_ino);
    printf("address d_off    : [%lu]\n", (unsigned long)&x -> d_off);
    printf("address d_reclen : [%lu]\n", (unsigned long)&x -> d_reclen);
    printf("address d_type   : [%lu]\n", (unsigned long)&x -> d_type);
    printf("address d_name   : [%lu]\n", (unsigned long)&x -> d_name);
}
int main(void ) {
    struct C c;
    bzero(&c, sizeof(c));
    c.a.a = 1;
    c.a.b = 2;
    c.b.c = 3;
    c.b.d = 4;
    c.x = 5;
    snprintf(c.szbuf, sizeof(c.szbuf) - 1, "%s", "hello, world");
    show_mem(&c, sizeof(c));
    show_struct(&c);
    show_struct(NULL);
    show_struct_D(NULL);
    show_dir_struct(NULL);
    return 0;
}