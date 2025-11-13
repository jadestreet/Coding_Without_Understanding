#include <unistd.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define NUM_DUMPED_WORDS 20
volatile int done;
int codePC[] = {
    0x4300e119, 0x4284aa7a, 0xf927f7b7, 0x40112268,
    0x419da7f8, 0x00002000, 0x01000100, 0x00080000,
    0x4191debc, 0x01010000, 0x4284aa74, 0x68b00054,
    0x045cf205, 0xcc016468, 0x0718f2a5, 0xd0102800,
    0x4c13c701, 0xa20aa108, 0xefb0f775, 0xe008e010,
};
int codeLR[] = {
    0x42e19e58, 0xf2050050, 0xcc01045c, 0x0718f2a5,
    0xd00f2800, 0x4c13c701, 0xa20aa108, 0xefe4f775,
    0xe007e010, 0x29006bf8, 0x6e77dc01, 0xa10347b8,
    0xef60f775, 0x6db1480b, 0x1c2d4788, 0x4300e119,
    0x4284aa7a, 0xf927f7b7, 0x40112268, 0x419da7f8,
};
#define START_PC_PAGE_OFFSET 0x1e4
#define START_LR_PAGE_OFFSET 0x1a8
char *codePCCache, *codeLRCache;
void dumpCode(int *pc, int *lr)
{
    unsigned int i;
    for (i = 0; i < NUM_DUMPED_WORDS; i++) {
        printf("%p codePC[%d]: %#010x\n", pc + i, i, pc[i]);
    }
    for (i = 0; i < NUM_DUMPED_WORDS; i++) {
        printf("%p codeLR[%d]: %#010x\n", lr + i, i, lr[i]);
    }
}
int main()
{
    codePCCache = memalign(4096, 8192);
    codeLRCache = memalign(4096, 8192);
    memcpy(codePCCache + START_PC_PAGE_OFFSET, codePC, 4 * NUM_DUMPED_WORDS);
    memcpy(codeLRCache + START_LR_PAGE_OFFSET, codeLR, 4 * NUM_DUMPED_WORDS);
    dumpCode((int *) (codePCCache + START_PC_PAGE_OFFSET),
             (int *) (codeLRCache + START_LR_PAGE_OFFSET));
    while (!done) {
        sleep(1000);
    }
    return 0;
}