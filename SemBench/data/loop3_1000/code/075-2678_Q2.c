#include<stdio.h>
int main(){
int i,j,repeticoes;
for(i=1;i<=9;i++){
    if(i!=3){
        for(j=1;j<=6;j++){
            printf("oi");
            repeticoes=repeticoes++;
        }
    }
}
printf("\nO trecho do pseudocodigo se repetiu %d vezes",repeticoes);
return 0;
}