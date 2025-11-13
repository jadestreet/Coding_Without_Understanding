#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	char *hi = "Howdy, World!";
	system("clear");
	for (int i = 0; i < strlen(hi); i++) {
		for (int j = 0; j < (80-i)/2; j++) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			printf("%c", hi[j]);
		}
		fflush(stdout);
		sleep(1);
		printf("\r");
	}
	printf("\n");
}