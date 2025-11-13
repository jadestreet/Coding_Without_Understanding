#include <stdio.h>
#include <unistd.h>
int isPrimer(int a){
	int i = 2;
	for( ; i < a ; i ++){
		if(a % i == 0){
			return 1;	
		}
	}
	return 0;
}
int main(){
	int* p = (int*)sbrk(0);
	int* r = p;
	int i = 2; 
	for(; i < 100 ; i ++){
		if(!isPrimer(i)){
			brk(r+1);
			*r = i;
			r = sbrk(0);
		}
	}
	r = p;
	while(r != sbrk(0)){
		printf("%d\n",*r++);	
	}
	brk(p);
	return 0;
}