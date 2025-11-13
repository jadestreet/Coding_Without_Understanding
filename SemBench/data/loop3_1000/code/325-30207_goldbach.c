#include <stdio.h>
#define TRUE 1
#define FALSE 0
void generatePrimesUpTo(int limit, int listPrimes[]);
int findGoldbach1 (int target, int list[]);  
int main (void)
{ 
	int listPrimes[60]; 
	for (int i = 0; i < 20; i++)
		listPrimes[i] = 0; 
	generatePrimesUpTo(250, listPrimes); 
	int goldbach1[100]; 
	int goldbach2[100];
	for (int i = 0; i < 100; i++){
		goldbach2[i] = 0; 
		goldbach2[i] = 0; 
	}
	for (int i = 20; i < 25; i += 1) 
	{
		goldbach1[i] = findGoldbach1(4+(i*2), listPrimes); 
		goldbach2[i] = ((4+(2*i)) - goldbach1[i]);
		int k = (4+2*i); 
		printf ("%d is the sum of the two primes %d and %d '\n'", k, goldbach1[i], goldbach2[i]);  
	}
}
void generatePrimesUpTo (int limit, int listPrimes[1000])
{	
	int c = 0; 
	int state; 	
	for (int i = 2; i < limit; i++) {
		state = TRUE; 
		for (int j = 2; j < i; j++){
			if (i % j == 0)
				state = FALSE; 
		}
		if(state == TRUE){	
			listPrimes[c] = i; 
			c++; 
		}
	}
}
int findGoldbach1 (int target, int list[1000]) 
{ 
	int value1;
	int state; 
	value1 = 0;
	int i = 0; 
	state = FALSE;   
	while (list[i] != 0 && state == FALSE) {
		int j; 
		j = 0; 
		while(list[j] != 0 && state == FALSE)  {
			if	(list[i] + list[j] == target){
				value1 = list[i]; 
				state = TRUE;  
			}
			j++; 
		}
		i++;  
	}
	return value1; 
}