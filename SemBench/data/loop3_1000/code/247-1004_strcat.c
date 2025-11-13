#include <stdio.h>
#include <string.h>
static void mystrcat(char *s1, char *s2) {
    while (*s1 != '\0') {
        s1++;
    }
    while (*s2 != '\0') {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}
static void mystrjoin(char *d, char *s1, char *s2) {
    while (*s1 != '\0') {
        *d = *s1;
        s1++;
        d++;
    }
    while (*s2 != '\0') {
        *d = *s2;
        s2++;
        d++;
    }
    *d = '\0';
}
int main(void) {
    char t1[] = "hello";
    char t2[] = " world";
    char t3[50];
    char t4[50];
    int n = strlen(t1);
    printf("%s%s\n", t1, t2);
    mystrjoin(t3, t1, t2);
    printf("%s\n", t3);
    strcpy(t4, t1);
    mystrcat(t1, t2);
    printf("%s\n", t1);
    strcat(t4, t2);
    printf("%s\n", t4);
    strcpy(t1 + n, " and goodbye");
    printf("%s\n", t1);
    return 0;
}