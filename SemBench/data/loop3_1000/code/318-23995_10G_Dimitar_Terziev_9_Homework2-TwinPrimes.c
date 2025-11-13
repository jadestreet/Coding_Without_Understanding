#include<stdio.h>
int main () {
	int broqch_dvoiki=0, delitel=0, broqch=1, prosto=1, proverka=1;
	while (broqch_dvoiki<10){
		while (delitel<broqch){
			delitel++;
			if (broqch%delitel==0 && delitel!=broqch && delitel!=1) {
				proverka=0;
				break;
			}
		}
		if (proverka==1) {
			prosto=broqch;		
			delitel=0;
			while (delitel<(broqch+2)){
				delitel++;
				if ((broqch+2) % delitel == 0 && delitel!=(broqch+2) && delitel!=1) {
					proverka=0;
					break;
				}
			}
			if (proverka==1) {
				printf ("(%d,%d)\n", prosto, prosto+2);
				broqch_dvoiki++;
				prosto=prosto+2;
			}
		}
		broqch++; 
		delitel=0;
		proverka=1;
	}
return 0;
}