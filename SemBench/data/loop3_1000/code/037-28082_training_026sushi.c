#include <stdio.h>
int level[] = {7, 9, 10, 12, 20, 1};
int cost[] = {25, 30, 40, 50, 100, 150};
int max(int a, int b){
	return a > b ? a : b;
}
int cache[201];
int sushi(int budget, int n){
	int* result = &cache[budget];
	if(*result != -1){
		return *result;
	}
	int i = 0;
	*result = 0;
	for(;i<n;i++){
		if(budget >= cost[i]){
			*result = max(sushi(budget - cost[i], n) + level[i], *result);
		}
	}
	return *result;
}
int sushi2(int m, int n){
	int result = 0;
	int budget=0, j=0;
	int cand = 0;
	cache[0] = 0;
	for(budget=1;budget<=m;budget++){
		cand = 0;
		for(j=0;j<n;j++){
			if(budget >= cost[j]){
				cand = max(cand, cache[(budget - cost[j]) % 201] + level[j]);
			}
		}
		cache[budget % 201] = cand;
		result = max(cand, result);
	}
	return result;
}
int main(int argc, char const *argv[])
{
	printf("%d\n", sushi2(100, 6));
	return 0;
}