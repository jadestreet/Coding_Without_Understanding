#include <stdio.h>
#include <assert.h>
char *myStrcpy(char *strDes, const char *strSrc) {
    assert((strDes != NULL) && (strSrc != NULL));
    char *address = strDes;
    while (*strSrc != '\0') {
        *strDes++ = *strSrc++;
    }
    *strDes = '\0';
    return address;
}
char *myStrncpy(char *strDes, const char *strSrc, int n) {
    assert((strDes != NULL) && (strSrc != NULL));
    char *address = strDes;
    while (n-- > 0) {
        *strDes++ = *strSrc++;
    }
    return address;
}
int myStrlen(const char *str) {
    assert(str != NULL);
    int strlen = 0;
    while (*str++ != '\0') {
        strlen++;
    }
    return strlen;
}
int myStrcmp(const char *str1, const char *str2) {
    assert((str1 != NULL) && (str2 != NULL));
    while (*str1 && *str2 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}
char *myStrcat(char *strDes, const char *strSrc) {
    assert((strDes != NULL) && (strSrc != NULL));
    char *address = strDes;
    while (*strDes != '\0') {
        strDes++;
    }
    while ((*strDes++ = *strSrc++) != '\0') {
        NULL;
    }
    return address;
}
int main(int argc, const char *argv[]) {
    const char *src = "Hello world!";
    const char *src2 = "Hello World!";
    char des[30];
    printf("[strncpy] %s\n", myStrncpy(des, src, 2));
    printf("[strcpy] %s\n", myStrcpy(des, src));
    printf("[strlen] %d\n", myStrlen(src));
    printf("[strcmp] %d\n", myStrcmp(src, src2));
    printf("[strcat] %s\n", myStrcat(des, src2));
    return 0;
}