#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<limits.h>
char* longestCommonPrefix(char** strs, int len)
{
    int index;
    int min_len, common_prefix_index;
    char* common_prefix = NULL;
    if (!strs || (len <= 0)) {
        return(NULL);
    }
    min_len = INT_MAX;
    for (index = 0; index < len; ++index) {
        if (!strs[index]) {
            min_len = 0;
        } else {
            if (min_len > strlen(strs[index])) {
                min_len = strlen(strs[index]);
            }
        }
    }
    if (min_len == 0) {
        return(NULL);
    }
    common_prefix = (char*)malloc(sizeof(char) * (min_len + 1));
    if (!common_prefix) {
        return(NULL);
    }
    memset(common_prefix, 0, sizeof(char) * (min_len + 1));
    for (common_prefix_index = 0; common_prefix_index < min_len;
         ++common_prefix_index) {
        for (index = 1; index < len; ++index) {
            if (strs[index - 1][common_prefix_index] !=
                strs[index][common_prefix_index]) {
                    break;
            }
        }
        if (index < len) {
            break;
        } else {
            common_prefix[common_prefix_index] =
                        strs[0][common_prefix_index];
        }
    }
    if (!common_prefix_index) {
        free(common_prefix);
        return(NULL);
    }
    return(common_prefix);
}
int main ()
{
    char* list0[] = {};
    int len0 = sizeof(list0)/sizeof(char*);
    assert(NULL == longestCommonPrefix(list0, len0));
    char* list1[] = {"abc"};
    int len1 = sizeof(list1)/sizeof(char*);
    assert(strcmp("abc", longestCommonPrefix(list1, len1)) == 0);
    char* list2[] = {"abc", "abcd", "abef", "abdc"};
    int len2 = sizeof(list2)/sizeof(char*);
    assert(strcmp("ab", longestCommonPrefix(list2, len2)) == 0);
    char* list3[] = {"bc", "bcd", "abef", "abdc"};
    int len3 = sizeof(list3)/sizeof(char*);
    assert(NULL == longestCommonPrefix(list3, len3));
    char* list4[] = {"abcd", "abcd", "abcd", "abcd", "abcd", "abcd"};
    int len4 = sizeof(list4)/sizeof(char*);
    assert(strcmp(list4[0], longestCommonPrefix(list4, len4)) == 0);
    char* list5[] = {"bc", NULL, "abef", "abdc"};
    int len5 = sizeof(list5)/sizeof(char*);
    assert(NULL == longestCommonPrefix(list5, len5));
    char* list6[] = {"bc", "", "abef", "abdc"};
    int len6 = sizeof(list6)/sizeof(char*);
    assert(NULL == longestCommonPrefix(list6, len6));
    return(0);
}