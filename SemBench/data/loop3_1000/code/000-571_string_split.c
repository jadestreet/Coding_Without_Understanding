#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char** split(char *str, char *delimitators);
int main(void)
{
	char** result;
	char str[] = "1-0:0.0.1(132412515)\n1-0:0.2.3.4(654236517)\n";
	result = split(str, "()\n");
	for(size_t index = 0; *(result + index); index++) 
	{
		printf("%s\n",*(result + index));
	}
	free(result);
	return 0;
}
char** split(char *str, char* delimitators)
{
	int count = 0;
	size_t index = 0;
	char **parse;
	char *tmp = str;
	char *token;
	char *last_delimitator;
	while(*tmp)
	{
		if(strchr(delimitators, *tmp) != NULL)
		{
			count++;
			last_delimitator = tmp;
		}
		tmp++;
	}
	count += last_delimitator < (str + strlen(str) - 1);
	count++;
	parse = malloc(sizeof(char*) * count);
	token = strtok(str, delimitators);
	while(token != NULL)
	{
		*(parse + index++) = token;
		token = strtok(NULL, delimitators);
	}
	*(parse + index) = 0;
	return parse; 
}