#include <time.h>
#include <stdio.h>
#include <stdlib.h>
void f_delay(int);
unsigned char random_inport( void);
void printport( int);
struct s1 {
    unsigned char fourthbit : 1;
} s;
int main(){
    int nr=0;
    unsigned char port;
    srand(time(0));
    unsigned int k = 0;
    port = 3;
    s.fourthbit = port>>3;
    printf("Inbit 4 is %d ", s.fourthbit);
    printport(port);
    f_delay(5);
    while(nr == 0){
        port = random_inport();
        printport( port);
        f_delay(5);
    }
}
void f_delay( int tenth_sec){
    clock_t start_t, end_t;
    long int i;
    start_t = clock();
    do{
        for(i=0; i< 10000000; i++);
        end_t = clock();
    }while ((end_t - start_t) < (tenth_sec*CLOCKS_PER_SEC)/2);
    return;
}
unsigned char random_inport( void){
    unsigned int inport = 0;
    unsigned int k = 0;
    inport=  rand() % 256;
    s.fourthbit = inport>> 3;
    printf("Inbit 4 is %d ", s.fourthbit);
    if(s.fourthbit == 1){
        k = inport<<1;
        return (k);
    }
    return (inport);
}
void printport( int portvalue){
    int binchar[8], rest,j, i=0;
    rest = portvalue;
    while(rest!=0){
        binchar[i++]= rest % 2;
        rest = rest / 2;
    }
    while( i<8){
        binchar[i++]=0;
    }
    for(j =i-1 ;j > -1;j--)
        printf("  %d",binchar[j]);
    printf(" --------Porten value = %d  \n", portvalue);
    return ;
}