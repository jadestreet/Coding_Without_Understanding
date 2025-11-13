#include <stdio.h>
float strToFloat(char string[]){
	int i, j = 0, intValue, isMinus = 0, isFloat = 0;
	float result;
	if(string[0] == '-'){
		isMinus = 1;
		i = 1;
	}
	for(; (string[i] >= '0' && string[i] <= '9'); ++i){
		intValue = string[i] - '0';
		result = result * 10 + intValue;
	}
	if(string[i] == '.'){
		isFloat = 1;
		for(++i; (string[i] >= '0' && string[i] <= '9'); ++i){
			intValue = string[i] - '0';
			result = result * 10 + intValue;
			++j;
		}
	}
	if(isFloat){
		for(; j > 0; --j)
			result = result / 10;
	}
	if(isMinus){
		result = -1 * result;
	}
	return result;
}
int main(void){
	float strToFloat(char string[]);
	printf("%f\n", strToFloat("-867.6921"));
	return 0;
}