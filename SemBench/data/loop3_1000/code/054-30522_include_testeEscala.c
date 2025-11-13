#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main() {
int *result_x = malloc(55 * sizeof(int));
int *result_y = malloc(55 * sizeof(int));
	int maiorY = 330,menorY = 60,maiorX = 330,menorX = 60,rangeY,rangeX,tick = 10; 
		if(menorY == maiorY) {
			menorY-=10;
			maiorY+=10;
		}
		if(menorX == maiorX) {
			menorX-=10;
			maiorX+=10;
		}
		rangeY = maiorY - menorY;
		rangeX = maiorX - menorY;
		if(tick < 2) {
			tick = 2;
		} else if(tick > 2) {
			tick -= 2;
		}
		double tempStepX = rangeX/tick,tempStepY = rangeY/tick;
		double mag_x = floor(log10(tempStepX)),mag_y = floor(log10(tempStepY));
		double mag_x_pow = pow(mag_x,10), mag_y_pow = pow(mag_y,10);
		double magMsd_x = tempStepX/(mag_x_pow + 0.5),magMsd_y = tempStepY/(mag_y_pow + 0.5);
		double stepSize_x = magMsd_x*mag_x_pow,stepSize_y = magMsd_y*mag_y_pow;
		double lb_y = stepSize_y * floor(menorY/stepSize_y);
		double ub_y = stepSize_y * ceil((maiorY/stepSize_y));
		double lb_x = stepSize_x * floor(menorX/stepSize_x);
		double ub_x = stepSize_x * ceil((maiorX/stepSize_x));
		int val_x = lb_x, val_y = lb_y;
		int loop = 0;
		while(1 && loop < 55) {
			printf("%d %d %0.2lf\n",loop,val_x,stepSize_x);
			result_x[loop] = val_x;
			val_x += stepSize_x;
			loop++;
			if(val_x > ub_x) {
				break;
			}	
		}
		int loop_y = 0;
		while(1 && loop_y < 55) {
			int desprezo = val_y;
			result_y[loop_y] = desprezo;
			val_y += stepSize_y;
			loop_y++;
			if(val_y > ub_y) {
				break;
			}
		}
		printf("x: ");
		for(int aux = 0; aux < loop; aux++) {
			printf(":%d: %d ",aux,result_x[aux]);
		}
		printf("\n");
		printf("y: ");
		for(int aux = 0; aux < loop_y; aux++) {
			printf("%d ",result_y[aux]);
		}
		free(result_x);
		free(result_y);
		printf("\n");
		return 0;
	}