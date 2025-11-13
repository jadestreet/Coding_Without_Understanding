#include<stdio.h>
int main(){
	int divi =0;
	int div = 0;
	int t1 = 0;
	int t2 = 0;
	int i = 0;
	for(divi = 2, div = 2, t1 = 3; i<10; t1 += 2) 
	{                                             
		divi = 2;                             
		while(t1 % divi != 0)
		{
			divi++;
		}
		if(t1 == divi)
		{
			t2 = t1 + 2;
			div = 2;
			while(t2 % div != 0)
			{
				div++;
			}
			if(t2 == div)
			{
				i++;
				printf("(%d, %d)\n",t1,t2);
			}
		}
	}
	return 0;
}