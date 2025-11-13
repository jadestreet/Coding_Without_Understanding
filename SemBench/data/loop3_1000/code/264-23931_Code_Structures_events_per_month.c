#include <stdio.h>
#include <stdlib.h>
struct calendar_t{
		 int events_count[52];	
		}; 
struct bug_fix_t{
	int months[13];
};
struct bug_fix_t events_per_month(struct calendar_t cal_t ){
	int sum = 0;
	int i = 0,c = 0, b = 0;
	struct bug_fix_t bug_fix; 
	for(;c<13;c++){	
		sum = 0;
		int d = 0;
		for(i += d; i+d<=4; i++){
			sum += cal_t.events_count[i];	
		}
		d += 4;
		bug_fix.months[b] = sum;
		b++;
	}
	return bug_fix;
}
int main(){
	struct calendar_t calendar_t;
	for(int i = 0; i < 53;i++){
		calendar_t.events_count[i] = i;
	}
	struct bug_fix_t buggy;
	buggy =  events_per_month(calendar_t);
	for(int i = 0; i<=13; i++){
		printf("%d\n", buggy.months[i]);
	}
	return 0;
}