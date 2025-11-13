#include<stdio.h>
#include <string.h>
#include <assert.h>
#define DEBUG 
int _get_last_index(char *str, int j) {
    assert(str);
    int str_len = strlen(str);
    int i=0;
    char ch = str[j];
    int ind = j;
    assert( !(ind < 0 || ind >= str_len));
    for (i = j+1; i < str_len; i++) {
        if (str[i] == ch) {
            ind = i;
        }
    }
    return ind;
}
void print_combination(char *str, int i, int ind, int j){
    int p,q;
    printf("str combination:\n");
    for (p=0; p<strlen(str); ) {
        if (p == 0) {
            if (i != 0) {
                for (q = 0; q < i; q++) {
                    printf("%c", str[q]);
                }
            }
            if (i != j) {
                for (q = i; q < j; q++) {
                    printf("%c", str[q]);
                }
            }
            printf("%c %d %c", str[j], (ind - j - 1), str[ind]);
            p = ind+1;
        } else {
            printf("%c", str[p]);
            p++;
        }
    }
    printf("\n");
}
int main() {
    int i = 0, j = 0, ind = 0;
    char *str = "careercup";
    int str_len = strlen(str);
    printf("\n%s\n", str);
    for (i = 0; i < str_len; i++) {
        for (j=i; j< str_len; j++) {
            ind = 0;
            ind = _get_last_index(str, j);
#if defined(DEBUG)
            printf("\nind  = %d, j = %d, i = %d\n", ind, j, i);
#endif
            if (j != ind) {
                print_combination(str, i, ind, j);
            } else {
            }
        }
    }
}