#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int pstrcmp(const void *a, const void *b) {
    return strcmp((const char *)*(char **)a, (const char *)*(char **)b);
}
int lcp(char *a, char *b) {
    int len1, len2;
    int i;
    len1 = strlen(a);
    len2 = strlen(b);
    for (i = 0; (i < len1) && (i < len2); ++i) {
        if (a[i] != b[i]) break;
    }
    return i;
}
int main(int argc, char **argv) {
    int i;
    char **ap;      
    int len1, len2;
    char *cstr;
    int lcslen = 0, lcplen, lcssufpos = -1;
    len1 = strlen(argv[1]);
    len2 = strlen(argv[2]);
    ap = (char**)malloc((len1+len2)*sizeof(char*));
    cstr = (char*)malloc((len1+len2)*sizeof(char));
    cstr = strcat(argv[1], argv[2]);
    for (i = 0; i < len1+len2; ++i) {
        ap[i] = &(cstr[i]);
    }
    for (i = 0; i < len1+len2; ++i) {
        printf("%s\n", ap[i]);
    }
    printf("sort the suffices\n");
    qsort(ap, len1+len2, sizeof(char *), pstrcmp);
    for (i = 0; i < len1+len2; ++i) {
        printf("%s\n", ap[i]);
    }
    printf("finding the lcs\n");
    for (i = 0; i < len1 + len2 - 1; ++i) {
        if ((ap[i] - cstr >= len1) && (ap[i+1] - cstr >= len1)) {
            continue;
        } else if ((ap[i] - cstr < len1) && (ap[i+1] - cstr < len1)) {
            continue;
        } else {
            lcplen = lcp(ap[i], ap[i+1]);
            if (lcplen > lcslen) {
                lcslen = lcplen;
                lcssufpos = i;
            }
        }
    }
    if (lcssufpos == -1) {
        printf("no lcs\n");
    } else {
        printf("%.*s\n", lcslen, ap[lcssufpos]);
    }
}