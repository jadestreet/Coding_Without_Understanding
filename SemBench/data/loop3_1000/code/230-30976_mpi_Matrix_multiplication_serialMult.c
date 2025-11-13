#include <stdio.h>
#include <stdlib.h>
#define NRA 62 			
#define NCA 15			
#define NCB 7   		
int main(int argc, char *argv[])
{
int    i, j, k;			
double a[NRA][NCA], 		
       b[NCA][NCB],      	
       c[NRA][NCB];		
printf("Starting serial matrix multiple example...\n");
printf("Using matrix sizes a[%d][%d], b[%d][%d], c[%d][%d]\n",
        NRA,NCA,NCA,NCB,NRA,NCB);
printf("Initializing matrices...\n");
for (i=0; i<NRA; i++)
   for (j=0; j<NCA; j++)
      a[i][j]= i+j;
for (i=0; i<NCA; i++)
   for (j=0; j<NCB; j++)
      b[i][j]= i*j;
for(i=0;i<NRA;i++)
   for(j=0;j<NCB;j++)
      c[i][j] = 0.0;
printf("Performing matrix multiply...\n");
for(i=0;i<NRA;i++)
   for(j=0;j<NCB;j++)
      for(k=0;k<NCA;k++)
         c[i][j]+= a[i][k] * b[k][j];
printf("Here is the result matrix:");
for (i=0; i<NRA; i++) { 
   printf("\n"); 
   for (j=0; j<NCB; j++) 
      printf("%6.2f   ", c[i][j]);
   }
printf ("\nDone.\n");
}