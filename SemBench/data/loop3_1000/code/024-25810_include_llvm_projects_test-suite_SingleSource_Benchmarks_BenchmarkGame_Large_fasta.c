#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#define WIDTH 60
#define MIN(a,b) ((a) <= (b) ? (a) : (b))
#define NELEMENTS(x) (sizeof (x) / sizeof ((x)[0]))
typedef struct {
    float p;
    char c;
} aminoacid_t;
static inline float myrandom (float max) {
    unsigned long const IM = 139968;
    unsigned long const IA = 3877;
    unsigned long const IC = 29573;
    static unsigned long last = 42;
    last = (last * IA + IC) % IM;
    return max * (long) last / IM;
}
static inline void accumulate_probabilities (aminoacid_t *genelist, size_t len) {
    float cp = 0.0;
    size_t i;
    for (i = 0; i < len; i++) {
        cp += genelist[i].p;
        genelist[i].p = cp;
    }
}
static void repeat_fasta (char const *s, size_t count) {
    size_t pos = 0;
    size_t len = strlen (s);
    char *s2 = malloc (len + WIDTH);
    memcpy (s2, s, len);
    memcpy (s2 + len, s, WIDTH);
    do {
     	size_t line = MIN(WIDTH, count);
     	fwrite (s2 + pos,1,line,stdout);
     	putchar ('\n');
     	pos += line;
     	if (pos >= len) pos -= len;
     	count -= line;
    } while (count);
    free (s2);
}
static void random_fasta (aminoacid_t const *genelist, size_t count) {
    do {
	size_t line = MIN(WIDTH, count);
	size_t pos = 0;
	char buf[WIDTH + 1];
	do {
	    float r = myrandom (1.0);
	    size_t i = 0;
	    while (genelist[i].p < r)
		++i; 
	    buf[pos++] = genelist[i].c;
	} while (pos < line);
	buf[line] = '\n';
	fwrite (buf, 1, line + 1, stdout);
	count -= line;
    } while (count);
}
int main (int argc, char **argv) {
 	size_t n = 5000000;
    static aminoacid_t iub[] = {
	{ 0.27, 'a' },
	{ 0.12, 'c' },
	{ 0.12, 'g' },
	{ 0.27, 't' },
	{ 0.02, 'B' },
	{ 0.02, 'D' },
	{ 0.02, 'H' },
	{ 0.02, 'K' },
	{ 0.02, 'M' },
	{ 0.02, 'N' },
	{ 0.02, 'R' },
	{ 0.02, 'S' },
	{ 0.02, 'V' },
	{ 0.02, 'W' },
	{ 0.02, 'Y' }};
    static aminoacid_t homosapiens[] = {
	{ 0.3029549426680, 'a' },
	{ 0.1979883004921, 'c' },
	{ 0.1975473066391, 'g' },
	{ 0.3015094502008, 't' }};
    accumulate_probabilities (iub, NELEMENTS(iub));
    accumulate_probabilities (homosapiens, NELEMENTS(homosapiens));
    static char const *const alu ="\
GGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGG\
GAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGA\
CCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAAT\
ACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCA\
GCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGG\
AGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCC\
AGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAA";
    fputs (">ONE Homo sapiens alu\n", stdout);
    repeat_fasta (alu, 2 * n);
    fputs (">TWO IUB ambiguity codes\n", stdout);
    random_fasta (iub, 3 * n);
    fputs (">THREE Homo sapiens frequency\n", stdout);
    random_fasta (homosapiens, 5 * n);
    return 0;
}