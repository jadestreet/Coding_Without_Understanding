#include <stdio.h>
int main(int argc, char *argv[])
{
    int i = (argc - 1);
    while (i >= 0) {
        printf("arg: %d: %s\n", i, argv[i]);
        i--;
    }
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    int num_states = 4;
    i = 0;
    while (i < num_states) {
        printf("state: %d: %s\n", i, states[i]);
        i++;
    };
    for (i = 0; i < argc; i++) {
        states[i] = argv[i];
    };
    char *newarray[4] = {};
    for (i = 0; i < num_states; i++) {
        printf("state: %d: %s\n", i, states[i]);
        newarray[i] = states[i];
    };
    for (i = 0; i < num_states; i++) {
        printf("newarray: %d: %s\n", i, newarray[i]);
    };
    states[1] = "I HAVE CHANGED!";
    for (i = 0; i < num_states; i++) {
        printf("newarray: %d: %s\n", i, newarray[i]);
    };
    return 0;
}