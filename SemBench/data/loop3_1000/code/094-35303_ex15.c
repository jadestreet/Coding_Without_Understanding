#include <stdio.h>
int main(int argc, char *argv[])
{
	int ages[] = {23, 43, 12, 90, 2};
	char *names[] = {
		"Alan", "Frank", 
		"Mary", "John", "Lisa"
	};
	int count = sizeof(ages) / sizeof(int);
	int i = 0;
	for (i = 0; i < count; i++)
	{
		printf("%s has %d years alive.\n",
			    names[i], ages[i] );
	}
	printf("---\n");
	int *cur_ages = ages;
	char **cur_names = names; 
	for (i = 0; i < count; i++)
	{
		printf("%s is %d years old\n",
		        cur_names[i], cur_ages[i] );
	}
	printf("---\n");
	for (i = 0; i < count; i++)
	{
		printf("%s is %d years old\n",
		        *(cur_names+i), *(cur_ages+i) );
	}
	printf("---\n");
	for (cur_names = names, cur_ages = ages; 
		     (cur_ages - ages) < count;
		     cur_names++, cur_ages++)
	{
		printf("%s is %d years old\n",
		        *cur_names, *cur_ages );
	}
	return 0;
}