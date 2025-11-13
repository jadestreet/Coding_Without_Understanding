#include <stdio.h>
int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Use -h for help\n");
		return 0;
	}
	char flag = argv[1][1];
	switch(flag)
	{
		case 'h':
			printf("Use:\n\t-h for help\n\t-a for saying hello\n\t-B for saying goodbye\n");
			return 0;
		case 'a':		
			printf("Hello world!\n");
			return 0;
		case 'B':		
			printf("Goodbye world!\n");
			return 0;
		default:
			printf("Use:\n\t-h for help\n\t-a for saying hello\n\t-B for saying goodbye\n");
			return 0;
	}
}