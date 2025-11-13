#include <stdio.h>
#include <limits.h>
#define NEG_ONE (-1ll)
#define SIZEOF_POINTER sizeof(void *)
#define SIZEOF_CHAR sizeof(char)
#define SIZEOF_SHORT sizeof(short)
#define SIZEOF_INT sizeof(int)
#define SIZEOF_LONG sizeof(long)
#define SIZEOF_LONGLONG sizeof(long long)
#define SIZEOF_SIZE_T sizeof(size_t)
#define NIBBLE_BIT 4
#define BYTE_BIT 8
#ifndef CHAR_BIT
#define CHAR_BIT BYTE_BIT    
#endif
#define POINTER_BIT (int)(SIZEOF_POINTER * BYTE_BIT)
#define SPRINTF_FORMAT "%llx"
int main(void)
{
  char hexpointer[SIZEOF_POINTER * 2 + 1],
      hexchar[SIZEOF_CHAR * 2 + 1],
      hexshort[SIZEOF_SHORT * 2 + 1],
      hexint[SIZEOF_INT * 2 + 1],
      hexlong[SIZEOF_LONG * 2 + 1],
      hexlonglong[SIZEOF_LONGLONG * 2 + 1],
      hexsize_t[SIZEOF_LONGLONG * 2 + 1];
  int pointer_bits, char_bits, short_bits, int_bits, long_bits, longlong_bits, size_t_bits;
  pointer_bits = sprintf(hexpointer, SPRINTF_FORMAT, (long long unsigned int)(void*)NEG_ONE) * NIBBLE_BIT;
  char_bits = sprintf(hexchar, SPRINTF_FORMAT, (long long unsigned int)(unsigned char)NEG_ONE) * NIBBLE_BIT;
  short_bits = sprintf(hexshort, SPRINTF_FORMAT, (long long unsigned int)(unsigned short)NEG_ONE) * NIBBLE_BIT;
  int_bits = sprintf(hexint, SPRINTF_FORMAT, (long long unsigned int)(unsigned int)NEG_ONE) * NIBBLE_BIT;
  long_bits = sprintf(hexlong, SPRINTF_FORMAT, (long long unsigned int)(unsigned long)NEG_ONE) * NIBBLE_BIT;
  longlong_bits = sprintf(hexlonglong, SPRINTF_FORMAT, (long long unsigned int)NEG_ONE) * NIBBLE_BIT;
  size_t_bits = sprintf(hexsize_t, SPRINTF_FORMAT, (long long unsigned int)(size_t)NEG_ONE) * NIBBLE_BIT;
  if (pointer_bits == SIZEOF_POINTER * BYTE_BIT) {
    printf("an %dbit machine (%ld byte)\n", pointer_bits, SIZEOF_POINTER);
  } else {
    printf("cannot determine bits of this machine: it seems to be %d bits but %ld bytes\n", pointer_bits, SIZEOF_POINTER);
  }
  if (char_bits == SIZEOF_CHAR * BYTE_BIT) {
    printf("uses %dbit (%ld byte) for (char) types\n", char_bits, SIZEOF_CHAR);
  } else {
    printf("cannot determine bits of (char) type: it seems to be %d bits but %ld bytes\n", char_bits, SIZEOF_CHAR);
  }
  if (short_bits == SIZEOF_SHORT * BYTE_BIT) {
    printf("uses %dbit (%ld byte) for (short) types\n", short_bits, SIZEOF_SHORT);
  } else {
    printf("cannot determine bits of (short) type: it seems to be %d bits but %ld bytes\n", short_bits, SIZEOF_CHAR);
  }
  if (int_bits == SIZEOF_INT * BYTE_BIT) {
    printf("uses %dbit (%ld byte) for (int) types\n", int_bits, SIZEOF_INT);
  } else {
    printf("cannot determine bits of (int) type: it seems to be %d bits but %ld bytes\n", int_bits, SIZEOF_INT);
  }
  if (long_bits == SIZEOF_LONG * BYTE_BIT) {
    printf("uses %dbit (%ld byte) for (long) types\n", long_bits, SIZEOF_LONG);
  } else {
    printf("cannot determine bits of (long) type: it seems to be %d bits but %ld bytes\n", long_bits, SIZEOF_LONG);
  }
  if (longlong_bits == SIZEOF_LONGLONG * BYTE_BIT) {
    printf("uses %dbit (%ld byte) for (long long) types\n", longlong_bits, SIZEOF_LONGLONG);
  } else {
    printf("cannot determine bits of (long long) type: it seems to be %d bits but %ld bytes\n", longlong_bits, SIZEOF_LONGLONG);
  }
  if (size_t_bits == SIZEOF_SIZE_T * BYTE_BIT) {
    printf("uses %dbit (%ld byte) for (size_t) types\n", size_t_bits, SIZEOF_SIZE_T);
  } else {
    printf("cannot determine bits of (size_t) type: it seems to be %d bits but %ld bytes\n", size_t_bits, SIZEOF_SIZE_T);
  }
   if (pointer_bits == SIZEOF_POINTER * BYTE_BIT) {
    printf("uses %dbit (%ld byte) for (void*) types\n", pointer_bits, SIZEOF_POINTER);
  } else {
    printf("cannot determine bits of this machine: it seems to be %d bits but %ld bytes\n", pointer_bits, SIZEOF_POINTER);
  }
 return 0;
}