#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char** argv)
{
#define CAR  (13)
#define POS  (9)
#define MAXBLOCK  (3)
#define TRUE (1)
#define FALSE (0)
		long long sum = 0;
		long long sumOK = 0;
		int ended = FALSE;
		int l,k,j,e;
		int car = CAR;
		int pos = POS;
		int maxblock = MAXBLOCK;
		if(argc == 4)
		{
			car = atoi(argv[1]);
			pos = atoi(argv[2]);
			maxblock = atoi(argv[3]);
		}
		int *cell = calloc(pos,sizeof(int));	
		printf("Version %ld, CAR %d, POS %d, MAXBLOCK %d\n",
				sizeof(int)*8,car,pos,maxblock);
		clock_t begin = clock();
		do {	
			sum++;
			int numOK = TRUE;
            int rep = maxblock;			
            for(k=0; k<pos-1;k++)
			{
                if(cell[k]!=cell[k+1])
                {
                    rep = maxblock;
                }
                else
                {   
                    if (--rep)
                    {
                        continue;
                    }
                    else
                    {
                        numOK = FALSE;
                        break;
                    }
                }
            }    
			if(numOK)
			{
				sumOK++;
			}
		    cell[0]++;
		    int i=0;
			while(cell[i]>=car)
			{
				cell[i]=0;
				i++;
				if(i<pos)
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
		free(cell);	
		clock_t end = clock();
		printf("Sum   %lld \n",sum);
		printf("SumOK %lld \n",sumOK);
		printf("Time: %ld \n",((end-begin)*1000)/CLOCKS_PER_SEC);
	return 0;
}