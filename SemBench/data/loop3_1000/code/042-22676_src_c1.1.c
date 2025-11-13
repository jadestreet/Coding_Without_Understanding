#include <stdio.h>
int mystrlen(char* inp){
    int len = 0;
    char* cur = inp;
    if (inp==NULL || !(*inp)){
        return -1;
    }
    while (*cur++ != '\0'){
        len++;
    }
    return len;
}
int reverse_str(char* inp){
    char tmp;
    char* cur = inp;
    int len = mystrlen(inp);
    if (inp == NULL || !(*inp)){
        return -1;
    }
    for (int pos = 0; pos < len/2; pos++){
        tmp = inp[pos];
        inp[pos] = inp[len-pos-1];
        inp[len-pos-1] = tmp;
    }
    return 0;
}
int main(int argc, char** argv){
    char *to_reverse;
    for (int i=1; i < argc; i++){
        to_reverse = argv[i];
        printf("%s reversed is ", to_reverse);
        reverse_str(to_reverse);
        printf("%s\n", to_reverse);
    }
    return 0;
}