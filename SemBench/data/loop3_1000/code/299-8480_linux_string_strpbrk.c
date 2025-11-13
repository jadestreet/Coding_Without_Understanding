#include <stdio.h>
#include <string.h>
int main() {
    int i = 0;
    const char str1[] = "abcde2fghi3jk4l";
    const char str2[] = "34";
    const char *str3 = "Life is short,I use C";
    char *ret;
    ret = strpbrk(str1, str2);
    if (ret) {
        printf("Number one is : %c\n", *ret);
    } else {
        printf("No");
    }
    ret = strpbrk(str1, str3);
    if (ret) {
        printf("Number one is : %c\n", *ret);
    } else {
        printf("No");
    }
    printf("\n");
    size_t len = strlen(str1);
    char *ch = 0;
    int index = 0;
    char all[20] = {0};
    for (; i < len; ++i) {
        ret = strpbrk((str1 + sizeof(char) * (index + 1)), str3);
        if (ret) {
            ch = strrchr(str1, *ret);
            index = (int) (ch - str1);
            printf("Number one is : %c\n", *ret);
            all[i] = *ret;
        } else {
            printf("No");
        }
    }
    printf("\n");
    for (i = 0; i < 20; ++i) {
        if (all[i] == 0)
            break;
        printf("%c ", all[i]); 
    }
    printf("\n");
    const char *str = "hello world, friend of mine!";
    const char *sep = " ,!";
    unsigned int cnt = 0;
    do {
        str = strpbrk(str, sep); 
        if (str) {
            str += strspn(str, sep); 
            printf("%s\n", str);
        }
        ++cnt; 
    } while (str && *str);
    printf("There are %d words\n", cnt); 
    return 0;
}