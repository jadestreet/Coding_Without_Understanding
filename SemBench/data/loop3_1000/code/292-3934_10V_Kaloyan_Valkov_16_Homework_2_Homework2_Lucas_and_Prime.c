#include <stdio.h>
int lucas(int f);
int primes(int f);
int main()
{
	printf("Nomerata na Lucas:\n");
	lucas(100);
	printf("\nDvoini Nechetni:\n");
	primes(10);
	return 0;
}
int lucas(int f)
{
	unsigned long prepre=2,pre=1,curr;
	int i;
	printf("No.1=2\n");
	printf("No.2=1\n");
	for (i=3;i<=f;i++)
	{
		curr=prepre+pre;
		printf("No.%d=%lu\n",i,curr);
		prepre=pre;
		pre=curr;
	}	
}
int primes(int f) 
{
	int del,printed_twin_primes=1,prime=3,twin_prime=3,flag_prime;
	while (printed_twin_primes<=f)
	{
		flag_prime=1;
		for (del=2;del<=prime/2;del++)
		{
			if (prime % del==0)
			{
				flag_prime=0;
				break;
			}
		}
	if (flag_prime==1)
	{
		if (prime==twin_prime+2)
		{
			printf("(%d,%d)\n",twin_prime,prime);
			printed_twin_primes++;
		}
		twin_prime=prime;
	}
	prime++;	
	}
}