#include <stdio.h>
#include <time.h>
#define CAR  (13)
#define POS  (9)
#define MAXBLOCK  (3)
#define TRUE (1)
#define FALSE (0)
long long sum = 0;
long long sumOK = 0;
void element(int first_row)
{
	int cell[POS];
	int ended = FALSE;
	int l,k,j,e;
	for(l=0; l<POS-1;l++) cell[l]=0;
	cell[POS-1] = first_row;
		do {	
			sum++;
			int numOK = TRUE;
			for(k=0; (numOK) && (k<POS-MAXBLOCK);k++)
			{
				numOK = FALSE;
				for(e = k + 1; (!numOK) && (e < k+MAXBLOCK+1); e++)
				{
					if(cell[k]!=cell[e])
					{
						numOK = TRUE;
					}
				}
			}
			if(numOK)
			{
				sumOK++;
			}
			cell[0]++;
			int i=0;
			while(cell[i]>=CAR)
			{
				cell[i]=0;
				i++;
				if(i<POS-1)
				{
					cell[i]++;
				}
				else
				{
					ended = TRUE;
					break;
				}
			}
		} while(!ended);
}
int main(int argc, char** argv)
{
	printf("Version %ld, CAR %d, POS %d, MAXBLOCK %d\n",sizeof(int)*8,CAR,POS,MAXBLOCK);		
	clock_t begin = clock();
	int iTh;	
	for(iTh = 0; iTh < CAR; iTh++)
	{
		element(iTh);
	}		
	clock_t end = clock();
	printf("Sum   %lld \n",sum);
	printf("SumOK %lld \n",sumOK);
	printf("Time: %ld \n",((end-begin)*1000)/CLOCKS_PER_SEC);
	return 0;
}