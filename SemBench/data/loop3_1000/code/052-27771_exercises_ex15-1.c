#include <stdio.h>
int main(int argc, char *argv[])
{
	int ages[] = {22, 36, 27, 23, 2};
	char *names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};
	int count = sizeof(ages)/sizeof(int);
	int i = count - 1;
	for(; i > -1 ; i--) {
		printf("%s is %d years old\n", names[i], ages[i]);
	}
	printf("---\n");
	i = count - 1;
	int *cur_age = &ages[i];
	char **cur_name = &names[i];
	int q = 0;
	for(; q < count; q++) {
		printf("%s is %d years alive\n", *(cur_name - q), *(cur_age-q));
	 }
	printf("---\n");
	for(i=0; i > -1*count; i--) {
		printf("%s has lived %d years\n", cur_name[i], cur_age[i]);
	}
	printf("---\n");
	for(; (cur_age - ages) > -1; cur_age--) {
		printf("%s's age is %d\n", *cur_name, *cur_age);
	}
	return 0;
}