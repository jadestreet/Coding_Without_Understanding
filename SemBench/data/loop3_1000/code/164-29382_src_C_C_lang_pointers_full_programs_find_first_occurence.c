#include <stdio.h>
#include <stdlib.h>
char *find_occurence(char *source, char *str);
int main(void) {
    char *buf = "Get up Stand up, Stand up for your rights, Bob Marley";
    char *str = "BCD";
    char *temp = find_occurence(buf, str);
    printf("Find the first occurence of: \'%s\'\n"                  \
           "          within the string: \"%s\"\n"                  \
           "              The result is: \'%s\'\n", str, buf, temp);
    return(EXIT_SUCCESS);
}
char *find_occurence(char *source, char *str) {
    char *tmp;
    if (source != NULL && str != NULL)
        for ( ; *source != '\0'; source++)
            for (tmp = str; *tmp != '\0'; tmp++)
                if (*source == *tmp)
                    return source;
    return NULL;
}