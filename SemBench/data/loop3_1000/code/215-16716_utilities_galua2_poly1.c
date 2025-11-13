#include <stdio.h>
#define N 16
#define P ((1<<N)-1)
int poly (int *mem, int tap, int in)
{
	int rez = *mem >> (N-1) & 1;
	*mem = *mem<<1 ^ rez << tap ^ rez ^ in;
	return rez;
}
void seqprint (unsigned char *s, int len)
{
	int i;
	for (i=0; i<len; ++s, ++i)
		putchar (*s ? '1' : '0');
	putchar ('\n');
}
void hexprint (unsigned char *s, int len)
{
	int n, i;
	unsigned char byte;
	for (n=0; n<len; ++n) {
		byte = 0;
		for (i=0; i<8; ++i)
			byte |= s [(n*8+i)%len] << i;
		printf ("0x%02x,", byte);
	}
	putchar ('\n');
}
void makeseq (int tap, int len)
{
	unsigned char seq [2*P];
	int mem, i;
	mem = 0;
	for (i=0; i<P; ++i)
		poly (&mem, tap, 1);
	for (i=0; i<2*P; ++i)
		seq [i] = poly (&mem, tap, 1);
	printf ("\nx^%d + x^%d + 1 =\n", N, tap);
	seqprint (seq, len);
	for (i=0; i<2*P; ++i)
		seq [i] ^= 1;
	seqprint (seq, len);
}
int main ()
{
	int i;
	for (i=1; i<N; ++i)
		makeseq (i, 2*P);
	return 0;
}