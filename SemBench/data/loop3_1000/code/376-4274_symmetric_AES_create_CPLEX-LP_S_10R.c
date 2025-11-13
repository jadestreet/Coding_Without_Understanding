#include <stdio.h>
int i,j,r;
const int ROUNDS = 10; 
int next = 0; 
int dummy = 0; 
void ShiftRows(int a[4][4]) {
	int tmp[4];
	for(i=1; i < 4; i++) {
		for(j = 0; j < 4; j++) tmp[j] = a[i][(j + i) % 4];
		for(j = 0; j < 4; j++) a[i][j] = tmp[j];
	}
}
void MixColumn(int a[4][4]) {
	for(j = 0; j < 4; j++) {
		for (i = 0; i < 4; i++) printf("x%i + ",a[i][j]);
		for (i = 0; i < 3; i++) printf("x%i + ",next+i);
		printf("x%i - 5 d%i >= 0\n",next+3,dummy);
		for(i = 0; i < 4; i++)
			printf("d%i - x%i >= 0\n",dummy,a[i][j]);
		for(i = 0; i < 4; i++)
			printf("d%i - x%i >= 0\n",dummy,a[i][j]=next++);
		dummy++;
	}
}
int main() {
	int a[4][4]; 
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			a[i][j] = next++; 
	printf("Minimize\n"); 
	for (i = 0; i < ROUNDS*16-1; i++) printf("x%i + ",i);
	printf("x%i\n\n",ROUNDS*16-1);
	printf("Subject To\n"); 
	for (r = 0; r<ROUNDS; r++) {
		ShiftRows(a);
		MixColumn(a);
	}
	for (i = 0; i < ROUNDS*16-1; i++) printf("x%i + ",i);
	printf("x%i >= 1\n\n",ROUNDS*16-1);
	printf("Binary\n"); 
	for (i = 0; i < 16; i++) printf("x%i\n",i);
	for (i = 0; i < dummy; i++) printf("d%i\n",i);
	printf ("End\n");
	return 0;
}