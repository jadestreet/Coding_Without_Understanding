#include <stdio.h>
#include <stdlib.h>
unsigned int L;
int actualValue = 1;
int LIMIT;
unsigned int x = 0;
unsigned int y = 0;
void pass3(){
    x =(x+((L*2)-1))%L;
    y =(y+1)%L;
}
void pass4(){
    y = (y+((L*2)-1))%L;
    x = (x+2)%L;
}
void printSquare(int square[L][L]){
    int i,j;
    for(i = 0; i<L; i++){
        for(j = 0; j<L; j++){
            printf("%d\t",square[i][j]);
        }
        printf("\n");
    }
}
void clean(int square[L][L]){
    int i,j;
    for(i = 0; i < L; i++ ){
        for(j = 0; j < L; j++){
            square[i][j] = 0;
        }
    }
}
void second(int square[L][L]){
    printf("2. O primeiro número é posicionada no meio da primeira coluna.\n");
    y = (int)(L/2);
    square[x][y] = actualValue++;
    printSquare(square); 
}
void fourth(int square[L][L]){
    if(actualValue == LIMIT) {return;}
    printf("4. Caso já haja um número na nova posição, volta-se a posição antiga\n e apenas descemos linha. A coluna continua a mesma.\n");
    pass4();
    square[x][y] = actualValue++;
    printSquare(square);
}
void third(int square[L][L]){
    pass3();   
    if(square[x][y] != 0){
        fourth(square);
        return;
    }
    printf("3. O próximo número é colocado deslocando uma posição para cima \ne  uma posição para direita. Caso seja alcançada uma das \nbordas do quadrado, a posição é invertida.\n");
    square[x][y] = actualValue++;
    printSquare(square);
}
int main(int argc, char ** argv){
    if(argc !=2){
        printf("Erro de argumentos: passe um numero impar para definir os lados do quadrado\n");
        return 1;
    }else if(atoi(argv[1])%2 != 1) {
        printf("FALHA: violação da regra 1, \n\t1. A matriz sempre terá os lados ímpares.\n");
        return 1;
    }else{
        printf("1. A matriz sempre terá os lados ímpares.\n");
    }
    L = atoi(argv[1]);
    LIMIT = L*L;
    int square[L][L];
    clean(square);
    second(square);
    int i;
    for(i = 1; i<LIMIT; i++){
        third(square);
    }
    return 0;
}