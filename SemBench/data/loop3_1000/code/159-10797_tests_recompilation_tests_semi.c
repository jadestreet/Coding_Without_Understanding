#include <stdio.h>
int main(int argc) {
    int x = 1;                      
    if (argc > 2) {
        do {
            x = 2;                  
            if (argc > 2) goto nine;
            x = 3;                  
            if (argc > 3) {
                x = 4;              
                if (argc > 4) {
                    five:
                    x = 5;          
                    printf("5");
                } else
                    x = 8;          
            }
            else {
                nine:
                x = 9;              
                printf("9");
                x = 10;             
                goto five;
            }
            x = 6;                  
        } while (argc < 6);
    } else {
        do {
            x = 11;                 
            if (argc == 11) goto thirteen;
            x = 12;
        } while (argc < 12);
        thirteen:
        x = 13;                     
    }
    x = 7;                          
    return x;
}