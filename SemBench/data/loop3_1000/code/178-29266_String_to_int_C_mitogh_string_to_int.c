#include <stdio.h>
#define N 6
int length(char *string){
    int count  = 0; 
    while(string[count++] != '\0'); 
    return --count;
}
int exponentiation(int base, int exp){
    if(!exp){
        return 1;
    }
    int total = base;
    int i = 1;
    while(i++ < exp){
        total *= base;
    }
    return total;
}
int parse(char *number){
    int size = length(number);
    int exp = size - 1;
    int total = 0;
    int i;
    for(i = 0; i < size; i++){
        if(number[i] >= '0' && number[i] <= '9'){
            total += (number[i] - 48) * exponentiation(10, exp--);
        }
    }
    return total;
}
int main(){
    char a[N] = "12345";
    char b[N] = "32442";
    printf("%d\n", 12345 == parse(a));
    printf("%d\n", 32442 == parse(b));
    return 0;
}