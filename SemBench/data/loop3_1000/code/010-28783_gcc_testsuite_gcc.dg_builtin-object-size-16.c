static int nfails;
#define TEST_FAILURE(line, obj, type, expect, result)		\
  __builtin_printf ("FAIL: line %i: __builtin_object_size("	\
		    #obj ", %i) == %zu, got %zu\n",		\
		    line, type, expect, result), ++nfails
#define bos(obj, type) __builtin_object_size (obj, type)
#define size(obj, n) ((size_t)n == X ? sizeof *obj : (size_t)n)
#define test(expect, type, obj)						\
  do {									\
    if (bos (obj, type)	!= size (obj, expect))				\
      TEST_FAILURE (__LINE__, obj, type, size (obj, expect), bos (obj, type)); \
  } while (0)
#define T(r0, r1, r2, r3, obj)			\
  do {						\
    test (r0, 0, obj);				\
    test (r1, 1, obj);				\
    test (r2, 2, obj);				\
    test (r3, 3, obj);				\
  } while (0)
#define X  (size_t)0xdeadbeef
#if __OPTIMIZE__
#  define F0(n)    n
#  define F1(n)    n
#  define F2(n)    n
#  define F3(n)    n
#else
#  define F0(n)   -1
#  define F1(n)   -1
#  define F2(n)    0
#  define F3(n)    0
#endif
typedef __SIZE_TYPE__ size_t;
extern char ax[];
char ax2[];               
extern char a0[0];
static char a1[1];
static char a2[2];
static char a9[9];
#if __SIZEOF_SHORT__ == 4
extern short ia0[0];
static short ia1[1];
static short ia9[9];
#elif __SIZEOF_INT__ == 4
extern int ia0[0];
static int ia1[1];
static int ia9[9];
#elif __SIZEOF_LONG__ == 4
extern long ia0[0];
static long ia1[1];
static long ia9[9];
#endif
static char a2x2[2][2];
static char a3x5[3][5];
struct Sx { char n, a[]; } sx;
struct S0 { char n, a[0]; } s0;
struct S1 { char n, a[1]; } s1;
struct S2 { char n, a[2]; } s2;
struct S9 { char n, a[9]; } s9;
struct S2x2 { char n, a[2][2]; } s2x2;
struct S3x5 { char n, a[3][5]; } s3x5;
static __attribute__ ((noclone, noinline)) void
test_arrays ()
{
  T (    -1,      -1,       0,       0,   ax);
  T (     0,       0,       0,       0,   a0);
  T (     1,       1,       1,       1,   ax2);
  T (     1,       1,       1,       1,   a1);
  T (     2,       2,       2,       2,   a2);
  T (     9,       9,       9,       9,   a9);
  T (     0,       0,       0,       0,   a0);
  T (     1,       1,       1,       1,   ax2);
  T (     0,       0,       0,       0,   ia0);
  T (     4,       4,       4,       4,   ia1);
  T (    36,      36,      36,      36,   ia9);
  T (     4,       4,       4,       4,   a2x2);
  T (     4,       4,       4,       4,   &a2x2[0]);
  T (     4,       2,       4,       2,   &a2x2[0][0]);
  T (     0,  F1  (0),      0,       0,   &a2x2 + 1);
  T (     2,  F1 ( 2),      2,  F3 ( 2),  &a2x2[0] + 1);
  T (     3,  F1 ( 1),      3,  F3 ( 3),  &a2x2[0][0] + 1);
  T (    15,      15,      15,      15,   a3x5);
  T (    15,       5,      15,       5,   &a3x5[0][0] + 0);
  T (    14,  F1 ( 4),     14,  F3 (14),  &a3x5[0][0] + 1);
  T (     1,       1,       1,       1,   a1 + 0);
  T (     0,  F1  (0),      0,       0,   a1 + 1);
  T (     0,  F1 ( 0),      0,       0,   &a1 + 1);
  T (     0,  F1  (0),      0,       0,   a1 + 2);
  T (     2,       2,       2,       2,   a2 + 0);
  T (     1,  F1 ( 1),      1, F3 ( 1),   a2 + 1);
  T (     0,  F1 ( 0),      0,       0,   a2 + 2);
}
static __attribute__ ((noclone, noinline)) void
test_structs (struct Sx *psx, struct S0 *ps0, struct S1 *ps1, struct S9 *ps9)
{
  T (     X,       X,       X,       X,   &sx);
  T (    -1,      -1,       0,       0,   psx);
  T (     0,       0,       0,       0,   sx.a);
  T (    -1,      -1,       0,       0,   psx->a);
  T (     X,       X,       X,       X,   &s0);
  T (    -1,      -1,       0,       0,   ps0);
  T (     0,       0,       0,       0,   s0.a);
  T (    -1,      -1,       0,       0,   ps0->a);
  T (     X,       X,       X,       X,   &s1);
  T (     1,       1,       1,       1,   s1.a);
  T (     0,  F1 (0),       0,       0,   s1.a + 1);
  T (    -1,      -1,       0,       0,   ps1);
  T (    -1,      -1,       0,       0,   ps1->a);
  T (    -1,      -1,       0,       0,   ps1->a + 1);
  T (     X,       X,       X,       X,   &s9);
  T (     9,       9,       9,       9,   s9.a);
  T (     9,       9,       9,       9,   s9.a + 0);
  T (     8,  F1 ( 8),      8, F3 (  8),  s9.a + 1);
  T (     7,  F1 ( 7),      7, F3 (  7),  s9.a + 2);
  T (     0,  F1 ( 0),      0, F3 (  0),  s9.a + 9);
  T (    -1,      -1,       0,       0,   ps9);
  T (    -1,      -1,       0,       0,   ps9->a);
  T (    -1,      -1,       0,       0,   ps9->a + 1);
}
int
main()
{
  test_arrays ();
  test_structs (&sx, &s0, &s1, &s9);
  if (nfails)
    __builtin_abort ();
  return 0;
}