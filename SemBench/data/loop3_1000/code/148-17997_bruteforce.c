#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
  int Nk0 = 1;
  int Nk1 = 1;
  int Na0 = 10;
  int Na1 = 10;
  int Nn0 = 10;
  int Nn1 = 10;
  int k0; int k1; int a0; int a1; int n0; int n1;
  for(k0 = 1; k0 <= Nk0; k0++)
    for(k1 = 1; k1<= Nk1; k1++)
      for(a0 = 1; a0<=Na0; a0++)
        for(a1 = 1; a1<=Na1; a1++)
         for(n0 = 1; n0<=Nn0; n0++)
           for(n1 = 1; n1<=Nn1; n1++)
            if(k0*(n0*n0 + 2*n0*a0 - 2*a0 - 1) == k1*(n1*n1 + 2*n1*a1 - 2*a1 - 1) 
             && !(a0 == a1 && n0 == n1) && !(n0 == 1 && n1 == 1))
              printf("%d, %d, %d, %d, %d, %d, %d, %d\n",
                k0, k1, a0, a1, n0, n1, n0*n0 + 2*n0*a0 - 2*a0 - 1, n1*n1 + 2*n1*a1 - 2*a1 - 1);
            return 0;
          }