#include <stdio.h>
int main(int argc, char **argv)
{
	int sieve[101];
	for(int i = 1; i < 101; i++) sieve[i] = 1;
	for(int i = 2; i < 101; i++){
		if(sieve[i] == 1){
			for(int j = i*i; j < 101; j+=i){
				if(sieve[j]%sieve[i] == 0){
					sieve[j] = 0;
				}
			}
		}
	}
	for(int i = 1; i < 101; i++)
		if(sieve[i]==1)printf("%d\t", i);
	return 0;
}