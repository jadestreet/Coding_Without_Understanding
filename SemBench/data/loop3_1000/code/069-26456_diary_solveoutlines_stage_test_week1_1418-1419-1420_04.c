#include <stdio.h>
#include <string.h>
#define NUM 1024
void  reverseWord(char *str);
int main()
{
    char str[NUM]="we are the world!";
    reverseWord(str);
    puts(str);
    return 0;
}
void  reverseWord(char *str)
{
    char *p =str;
    int length=(int)strlen(str);
    int i,j,k=0;
    char q[length];
    for ( i = length-1; i >= 0 ; i-- )
    {
        if(' ' == p[i] )
        {
            j=i+1;
            while(p[j] != ' ' && p[j] != '\0' )
            {
                q[k]=p[j];
                j++;
                k++;
            }
            q[k++]=' ';
        }
        else if(i == 0)
        {
            j = i;
            while(p[j]!=' ')
            {
                q[k]=p[j];
                j++;
                k++;
            }
            q[k]='\0';
        }
    }
    for (i=0; i < length;i++) {
        str[i]=q[i];
    }
    str[i]='\0';
}