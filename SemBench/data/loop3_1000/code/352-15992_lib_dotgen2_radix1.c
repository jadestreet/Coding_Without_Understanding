#include <stdlib.h>
#include <assert.h>
#define ByteOf(x) (*(uchar *) (x))
typedef unsigned long ulong;
typedef unsigned char uchar;
typedef struct rec_s {
	ulong		key;
} rec;
static void radix (short byteOffset, ulong N,  rec *source, rec *dest)
{
        ulong count[256];
        ulong *cp, s, c, i;
        uchar *bp;
		rec   *sp;
        cp = count;
        for (i = 256; i > 0; --i, ++cp)
                *cp = 0;
        bp = ((uchar *) source) + byteOffset;
        for (i = N; i > 0; --i, bp += sizeof(rec)) {
                cp = count + *bp;
                ++(*cp);
        }
        s = 0;
        cp = count;
        for (i = 256; i > 0; --i, ++cp) {
                c = *cp;
                *cp = s;
                s += c;
        }
        bp = ((uchar *) source) + byteOffset;
        sp = source;
        for (i = N; i > 0; --i, bp += sizeof(rec), ++sp) {
                cp = count + *bp;
                dest[*cp] = *sp;
                ++(*cp);
        }
}
static void radix_sort (rec *source, ulong N)
{
        rec *temp = (rec *) malloc (N * sizeof (rec));
        assert (temp != NULL);
        radix (3, N, source, temp);
        radix (2, N, temp, source);
        radix (1, N, source, temp);
        radix (0, N, temp, source);
        free (temp);
}
static void make_random (rec *data, ulong N)
{
        for ( ; N > 0; --N, ++data)
                data->key = rand () | (rand () << 16);
}
static void check_order (rec *data, ulong N)
{
        --N;
        for ( ; N > 0; --N, ++data)
                assert (data[0].key <= data[1].key);
}
static void test_radix (ulong N)
{
        rec *data = (rec *) malloc (N * sizeof (rec));
        assert (data != NULL);
        make_random (data, N);
        radix_sort (data, N);
        check_order (data, N);
        free (data);
}
int main (int argc, const char ** argv)
{
        test_radix (5000000);
}