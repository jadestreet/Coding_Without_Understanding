#define _POSIX_SOURCE
#include <locale.h>
#include <stdio.h>
#define USAGE "usage: basename string [suffix]\n"
int main(int argc, char **argv)
{
    char *str, *head, *tail, *newtail, *sfx, *sfxtail;
    setlocale (LC_ALL, "");
    if (argc < 2 || argc > 3)
    {
        fprintf(stderr, USAGE);
        return(1);
    }
    tail = str = argv[1];
    while (*tail)
        tail++;
    while (tail > str && tail[-1] == '/')
        tail--;
    head = tail;
    while (head > str && head[-1] != '/')
        head--;
    if (argc == 3)
    {
        newtail = tail;
        sfxtail = sfx = argv[2];
        while (*sfxtail)
            sfxtail++;
        while (newtail > (head + 1) && sfxtail > sfx && newtail[-1] == sfxtail[-1])
        {
            newtail--;
            sfxtail--;
        }
        if (sfxtail == sfx)
            tail = newtail;
    }
    printf("%.*s\n", (tail - head), head);
    return(0);
}