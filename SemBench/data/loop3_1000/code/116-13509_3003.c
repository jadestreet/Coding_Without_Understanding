#include <stdio.h>
int main(void) {
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < 3; k++){
				printf("%d * %d * %d = %d\n", i, j, k, (i * j * k));
			}
		}
	}
	return 0;
}