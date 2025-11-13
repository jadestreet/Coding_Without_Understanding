#include <stdio.h>
#define TRIMLEN 80
char *trimline(char *str, char **saveptr);
int main(int argc, char **argv)
{
	size_t n = 0;
	char *line = NULL;
	char *trimmed = NULL;
	char *saveptr = NULL;
	while (getline(&line, &n, stdin) > -1) {
		trimmed = trimline(line, &saveptr);
		while ((trimmed = trimline(NULL, &saveptr)))
			printf("%s\n", trimmed);
	}
	return 0;
}
char *trimline(char *str, char **saveptr)
{
	if (!saveptr)
		return NULL;
	if (str) {
		*saveptr = str;
		return str;
	}
	if (!(*saveptr))
		return NULL;
	size_t i;
	char *temp = NULL;
	for (i = 0; i < TRIMLEN; ++i) {
		if ((*saveptr)[i] == '\n' || (*saveptr)[i] == '\0') {
			(*saveptr)[i] = '\0';
			temp = *saveptr;
			*saveptr = NULL;
			return temp;
		}
	}
	for (i = i; (*saveptr)[i] != ' '; --i);
	(*saveptr)[i] = '\0';
	temp = *saveptr;
	*saveptr = (*saveptr)+(i+1);
	return temp;
}