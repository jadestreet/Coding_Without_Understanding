#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insertQuotes(int begin, int end, char* str, int n) {
	int k;
	for(k = n+2; k>end; k--) {
		str[k] = str[k - 2];
	}
	for(k = end + 1; k > begin; k--) {
		str[k] = str[k - 1];
	}
	str[begin] = '"';
	str[end] = '"';
}
void quotes(char *str, int n) {
	int i,j;
	for(i = 0; i < n; i++) {
		if(str[i]!=' ') {
			for(j = i; j<n+1; j++) {
				if(str[j]==' '||str[j]=='\0') {
					insertQuotes(i,j,str, n);
					n+=2;
					i = j+2;
					break;
				}
			}
		}
	}
}
int main() {
	char str[200] = "fskdjf sdsdf sd    dsf sf sdf";
	puts("begin");
	puts(str);
	puts("result");
	quotes(str, strlen(str));
	puts(str);
	return 0;
}