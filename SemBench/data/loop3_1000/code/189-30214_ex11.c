#include <stdio.h>
int main(int argc, char *argv[])
{
	int i =0;
	while (i < argc) {
	 printf ("arg %d: %s\n", i, argv[i]);
	 i++;
  }
  char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
	int num_states = 4;
	i = 0; 
	while (i < num_states) {
		printf("state %d: %s\n", i, states[i]);
		i++;
	}
	int j =0;
	while (j < argc) {
		states[j] = argv[j];
	 	j++;
  }
	int k = 0;
	while (k < argc) {
		printf("states[%i] is %s\n", k, states[k]);
	 	k++;
 }
	return 0;
}