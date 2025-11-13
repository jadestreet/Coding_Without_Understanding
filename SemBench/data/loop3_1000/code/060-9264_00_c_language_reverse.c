#include <stdio.h>
#include <string.h>
#define SWAP(a,b)\
do{\
a ^= b;\
b ^= a;\
a ^= b;\
}while(0)
void reverse( char* pS )
{
    char* pStart 	= pS;
    char* pEnd 		= pS + (strlen(pS)-1)*sizeof(char);
    while(pStart < pEnd)
    {
        SWAP(*pStart, *pEnd);
        pStart += sizeof(char);
        pEnd   -= sizeof(char);
    }
}
int main(int argc, char* argv[])
{
    char* pInput 	= NULL;
    int   idx 		= 0;
    if ( argc <= 1 )
    {
        printf("[error] no input argument\n");
        return 0;
    }
    for(idx=1; idx<argc; idx++)
    {
        pInput = argv[idx];
        printf("[info] original input 	= %s\n", pInput);
        reverse(pInput);
        printf("[info] reverse input 	= %s\n", pInput);
    }
    return 0;
}