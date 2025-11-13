#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char* strncpyx(char* s1, const char* s2, size_t n)
{
  size_t x = strlen(s2);
  if (n < x)
    x = n;
  memcpy(s1, s2, x);
  if (x != n)
    *(s1 + x) = '\0';
  return s1;
}
char* strncpyy(char* s1, const char* s2, size_t n)
{
  register char* endp = s1 + n;
  register char* s = s1;
  while (s < endp && (*s++ = *s2++))
    ;
  return s1;
}
#define COUNT1 100000
#define COUNT2 1000000
#define BIG    4096
#define SMALL  52
#define HOSTLEN 63
#define NICKLEN 9
char buf[BIG + 1];
const char* const test_data = "abcdefghijklmnopqrstuvwxyz0123456789";
const char* nick_data = "aClient";
const char* host_data = "scorched.blackened.com";
void strncpy_mixed(void)
{
  register int i;
  for (i = 0; i < COUNT1; ++i) {
    strncpy(buf, test_data, BIG);
    buf[BIG] = '\0';
    strncpy(buf, test_data, SMALL);
    buf[SMALL] = '\0';
  }
}
void memcpy_mixed(void)
{
  register int i;
  for (i = 0; i < COUNT1; ++i) {
    strncpyx(buf, test_data, BIG);
    buf[BIG] = '\0';
    strncpyx(buf, test_data, SMALL);
    buf[SMALL] = '\0';
  }
}
void while_mixed(void)
{
  register int i;
  for (i = 0; i < COUNT1; ++i) {
    strncpyy(buf, test_data, BIG);
    buf[BIG] = '\0';
    strncpyy(buf, test_data, SMALL);
    buf[SMALL] = '\0';
  }
}
void strncpy_irc(void)
{
  register int i;
  for (i = 0; i < COUNT2; ++i) {
    strncpy(buf, host_data, HOSTLEN);
    buf[HOSTLEN] = '\0';
    strncpy(buf, nick_data, NICKLEN);
    buf[NICKLEN] = '\0';
  }
}
void memcpy_irc(void)
{
  register int i;
  for (i = 0; i < COUNT2; ++i) {
    strncpyx(buf, host_data, HOSTLEN);
    buf[HOSTLEN] = '\0';
    strncpyx(buf, nick_data, NICKLEN);
    buf[NICKLEN] = '\0';
  }
}
void while_irc(void)
{
  register int i;
  for (i = 0; i < COUNT2; ++i) {
    strncpyy(buf, host_data, HOSTLEN);
    buf[HOSTLEN] = '\0';
    strncpyy(buf, nick_data, NICKLEN);
    buf[NICKLEN] = '\0';
  }
}
void test_strncpy(void)
{
  size_t len;
  printf("Test length: 0\n");
  printf("%s\n", strncpy(buf, test_data, 0));
  printf("%s\n", strncpyx(buf, test_data, 0));
  printf("%s\n", strncpyy(buf, test_data, 0));
  printf("Test length: 1\n");
  printf("%s\n", strncpy(buf, test_data, 1));
  printf("%s\n", strncpyx(buf, test_data, 1));
  printf("%s\n", strncpyy(buf, test_data, 1));
  printf("Test length: 2\n");
  printf("%s\n", strncpy(buf, test_data, 2));
  printf("%s\n", strncpyx(buf, test_data, 2));
  printf("%s\n", strncpyy(buf, test_data, 2));
  buf[0] = '\0';
  printf("Test empty string length: 0\n");
  printf("%s\n", strncpy(buf, "", 0));
  printf("%s\n", strncpyx(buf, "", 0));
  printf("%s\n", strncpyy(buf, "", 0));
  printf("Test empty string length: 1\n");
  printf("%s\n", strncpy(buf, "", 1));
  printf("%s\n", strncpyx(buf, "", 1));
  printf("%s\n", strncpyy(buf, "", 1));
  printf("Test empty string length: 2\n");
  printf("%s\n", strncpy(buf, "", 2));
  printf("%s\n", strncpyx(buf, "", 2));
  printf("%s\n", strncpyy(buf, "", 2));
  len = strlen(test_data);
  printf("Test length: data_length: %d\n", len);
  buf[len - 1] = '*';
  buf[len]     = '*';
  buf[len + 1] = '*';
  buf[len + 2] = '*';
  buf[len + 3] = '\0';
  printf("%s\n", strncpy(buf,  test_data, len));
  buf[len - 1] = '*';
  buf[len]     = '*';
  buf[len + 1] = '*';
  buf[len + 2] = '*';
  buf[len + 3] = '\0';
  printf("%s\n", strncpyx(buf, test_data, len));
  buf[len - 1] = '*';
  buf[len]     = '*';
  buf[len + 1] = '*';
  buf[len + 2] = '*';
  buf[len + 3] = '\0';
  printf("%s\n", strncpyy(buf, test_data, len));
  ++len;
  printf("Test length: data_length + 1: %d\n", len);
  buf[len - 1] = '*';
  buf[len]     = '*';
  buf[len + 1] = '*';
  buf[len + 2] = '*';
  buf[len + 3] = '\0';
  printf("%s\n", strncpy(buf,  test_data, len));
  buf[len - 1] = '*';
  buf[len]     = '*';
  buf[len + 1] = '*';
  buf[len + 2] = '*';
  buf[len + 3] = '\0';
  printf("%s\n", strncpyx(buf, test_data, len));
  buf[len - 1] = '*';
  buf[len]     = '*';
  buf[len + 1] = '*';
  buf[len + 2] = '*';
  buf[len + 3] = '\0';
  printf("%s\n", strncpyy(buf, test_data, len));
}
int main(int argc, char** argv)
{
  int which = 0;
  if (argc > 1)
    which = atoi(argv[1]);
  switch (which) {
  case 0:
    test_strncpy();
    break;
  case 1:
    strncpy_mixed();
    break;
  case 2:
    memcpy_mixed();
    break;
  case 3:
    while_mixed();
    break;
  case 4:
    strncpy_irc();
    break;
  case 5:
    memcpy_irc();
    break;
  case 6:
    while_irc();
  default:
    break;
  }
  return 0;
}