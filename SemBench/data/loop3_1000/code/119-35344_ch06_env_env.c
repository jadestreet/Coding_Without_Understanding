#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int setenv(const char *name, const char *value, int overwrite) {
    errno = 0;
    char *prev = getenv(name);
    if (errno != 0) {
        return -1;
    }
    if (prev != NULL && !overwrite) {
        return 0;
    }
    size_t len = 0;
    len += strlen(name);
    len += 1;
    len += strlen(value);
    len += 1;
    char *buf = (char *) malloc(len);
    if (buf == NULL) {
        return -1;
    }
    snprintf(buf, len, "%s=%s", name, value);
    return putenv(buf);
}
extern char **environ;
int unsetenv(const char *name) {
    if (name == NULL) {
        errno = EINVAL;
        return -1;
    }
    size_t len = strlen(name);
    if (len == 0) {
        errno = EINVAL;
        return -1;
    }
    for (int i = 0; i < len; i++) {
        if (name[i] == '=') {
            errno = EINVAL;
            return -1;
        }
    }
    char **p = environ;
    while (*p != NULL) {
        if (strncmp(*p, name, len) == 0 && (*p)[len] == '=') {
            char **q = p;
            while (*q != NULL) {
                *q = *(q + 1);
                q++;
            }
        }
        p++;
    }
    return 0;
}
int main(int argc, char **argv) {
    printf("Initially, FOO = %s\n", getenv("FOO"));
    if (setenv("FOO", "one", 0) == -1) {
        fprintf(stderr, "setenv: %s\n", strerror(errno));
        return 1;
    }
    printf("After update without overwrite, FOO = %s\n", getenv("FOO"));
    if (setenv("FOO", "two", 1) == -1) {
        fprintf(stderr, "setenv: %s\n", strerror(errno));
        return 1;
    }
    printf("After update with overwrite, FOO = %s\n", getenv("FOO"));
    if (unsetenv("FOO") == -1) {
        fprintf(stderr, "unsetenv: %s\n", strerror(errno));
        return 1;
    }
    printf("After unset, FOO = %s\n", getenv("FOO"));
    return 0;
}