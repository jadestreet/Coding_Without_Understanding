#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
double myatof(char *s){
	double val, power;
	int i, sign;
	for(i = 0; isspace(s[i]);i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '-' || s[i] == '+'){
		i++;
	}
	for(val = 0.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.'){
		i++;
	}
	for(power = 1.0; isdigit(s[i]);i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if(s[i] == '\0') return val/power;
	if(s[++i] == '-'){
		double power2 = 1.0;
		int k = s[i+1] - '0';
		printf("%d\n", k);
		for (int j = 0; j < k; j++){
			power2 *= 10;
		}
		printf("%f\n", power2);
		return val/(power*power2);
	}
	double power2 = 1.0;
	int	k = s[i] - '0';
	for(int j = 0; j < k; j++){
		power2 *= 10;	
		return (val/power)*power2;
	}
	return -1;
}
int main(){
	char *s = "-1213.223e-3";
	printf("%f\n", myatof(s));
	return 0;
}