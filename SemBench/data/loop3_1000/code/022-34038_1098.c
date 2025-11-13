#include<stdio.h>
int main()
{
    int i;
    float I=0,J=1;
    for(i=1;i<=3;i++){
        printf("I=%0.0f J=%0.0f\n",I,J);
        J++;
    }
    for(i=1;i<=3;i++){
        printf("I=%0.1f J=%0.1f\n",I+0.2,J-2.8);
        J++;
    }
    for(i=1;i<=3;i++){
        printf("I=%0.1f J=%0.1f\n",I+0.4,J-5.6);
        J++;
    }
    for(i=1;i<=3;i++){
        printf("I=%0.1f J=%0.1f\n",I+0.6,J-8.4);
        J++;
    }
    for(i=1;i<=3;i++){
        printf("I=%0.1f J=%0.1f\n",I+0.8,J-11.2);
        J++;
    }
    for(i=1;i<=3;i++){
        printf("I=%0.0f J=%0.0f\n",I+1,J-14);
        J++;
    }
    for(i=1;i<=3;i++){
        printf("I=%0.1f J=%0.1f\n",I+1.2,J-16.8);
        J++;
    }
    for(i=1;i<=3;i++){
        printf("I=%0.1f J=%0.1f\n",I+1.4,J-19.6);
        J++;
    }
    for(i=1;i<=3;i++){
        printf("I=%0.1f J=%0.1f\n",I+1.6,J-22.4);
        J++;
    }
    for(i=1;i<=3;i++){
        printf("I=%0.1f J=%0.1f\n",I+1.8,J-25.2);
        J++;
    }
    for(i=1;i<=3;i++){
        printf("I=%0.0f J=%0.0f\n",I+2,J-28);
        J++;
    }
    return 0;
}