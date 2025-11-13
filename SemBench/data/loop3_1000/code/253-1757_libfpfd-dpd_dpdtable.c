#include <stdio.h>
typedef unsigned char bool;
void unpack10(bool dest[10], unsigned int src) {
  unsigned int i;
  for (i = 0; i < 10; ++i) {
    dest[i] = src >> 9;
    src -= ((src >> 9) << 9);
    src <<= 1;
  }
}
void unpack12(bool dest[12], unsigned int src) {
  unsigned int i;
  for (i = 0; i < 12; ++i) {
    dest[i] = src >> 11;
    src -= ((src >> 11) << 11);
    src <<= 1;
  }
}
void bcd2dpd(bool dest[10], bool src[12]) {
  dest[0] = src[1] | (src[0] & src[9]) | (src[0] & src[5] & src[8]);
  dest[1] = src[2] | (src[0] & src[10]) | (src[0] & src[6] & src[8]);
  dest[2] = src[3];
  dest[3] = (src[5] & (~src[0] | ~src[8])) | (~src[0] & src[4] & src[9]) |
    (src[4] & src[8]);
  dest[4] = src[6] | (~src[0] & src[4] & src[10]) | (src[0] & src[8]);
  dest[5] = src[7];
  dest[6] = src[0] | src[4] | src[8];
  dest[7] = src[0] | (src[4] & src[8]) | (~src[4] & src[9]);
  dest[8] = src[4] | (src[0] & src[8]) | (~src[0] & src[10]);
  dest[9] = src[11];
}
void dpd2bcd(bool dest[12], bool src[10]) {
  dest[0] = (src[6] & src[7]) & (~src[3] | src[4] | ~src[8]);
  dest[1] = src[0] & (~src[6] | ~src[7] | (src[3] & ~src[4] & src[8]));
  dest[2] = src[1] & (~src[6] | ~src[7] | (src[3] & ~src[4] & src[8]));
  dest[3] = src[2];
  dest[4] = src[6] &
    ((~src[7] & src[8]) | (~src[4] & src[8]) | (src[3] & src[8]));
  dest[5] = (src[3] & (~src[6] | ~src[8])) |
    (src[0] & ~src[3] & src[4] & src[6] & src[7] & src[8]);
  dest[6] = (src[4] & (~src[6] | ~src[8])) |
    (src[0] & ~src[3] & src[4] & src[7]);
  dest[7] = src[5];
  dest[8] = src[6] &
    ((~src[7] & ~src[8]) | (src[7] & src[8] & (src[3] | src[4])));
  dest[9] = (~src[6] & src[7]) |
    (src[3] & src[6] & ~src[7] & src[8]) |
    (src[0] & src[7] & (~src[8] | (~src[3] & ~src[4])));
  dest[10] = (~src[6] & src[8]) |
    (src[4] & ~src[7] & src[8]) |
    (src[1] & src[6] & src[7] & (~src[8] | (~src[3] & ~src[4])));
  dest[11] = src[9];
}
int main() {
  bool bcd[12], dpd[10];
  unsigned int i, j;
  printf("\n"
         "\n"
         "        .section .rodata\n"
         ".globl fpfd_bcd2dpd\n"
         "        .align 32\n"
         "        .type fpfd_bcd2dpd, @object\n"
         "        .size fpfd_bcd2dpd, 4914\n"
         "fpfd_bcd2dpd:\n");
  for (i = 0; i <= 0x999; ++i) {
    unpack12(bcd, i);
    bcd2dpd(dpd, bcd);
    printf("        .value 0b000000");
    for (j = 0; j < 10; ++j) {
      printf("%u", dpd[j]);
    }
    printf("\n");
  }
  printf("\n"
         ".globl fpfd_dpd2bcd\n"
         "        .align 32\n"
         "        .type fpfd_dpd2bcd, @object\n"
         "        .size fpfd_dpd2bcd, 2046\n"
         "fpfd_dpd2bcd:\n");
  for (i = 0; i <= 0x3FF; ++i) {
    unpack10(dpd, i);
    dpd2bcd(bcd, dpd);
    printf("        .value 0b0000");
    for (j = 0; j < 12; ++j) {
      printf("%u", bcd[j]);
    }
    printf("\n");
  }
  return 0;
}