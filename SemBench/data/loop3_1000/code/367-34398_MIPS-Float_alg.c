#include <stdio.h>
#define EXPONENT_MASK   0x7F800000
#define EXP_SHIFT       23
#define SIGN_MASK       0x80000000
#define MAGNITUDE_MASK  0x007FFFFF
#define numA			0.3
#define numB			-4.3
int absolute(int x) {
   if (x < 0)
	  return -x;
   return x;
}
float packFloat(int exponent, int magnitude) {
   if (magnitude == 0)
	   return 0;
   int res = ((magnitude < 0) ? 1 : 0) << 31;
   res |= ((exponent + 127) << EXP_SHIFT) & EXPONENT_MASK;
   res |= absolute(magnitude) & MAGNITUDE_MASK;
   return *((float *) ((void *) &res)); 
}
void unpackFloat(float aV, int *exponent, int *magnitude) {
   int a = *((int *) ((void *) &aV));
   *exponent = ((((int) a) & EXPONENT_MASK) >> EXP_SHIFT) - 127;
   *magnitude = (a & MAGNITUDE_MASK) + (MAGNITUDE_MASK + 1);
   if (a & SIGN_MASK)
	   *magnitude = -*magnitude;
}
void normalizeFloat(int *exponent, int *magnitude) {
   if (*magnitude == 0) {
	  *exponent = 0;
	  return;
   }
   int sign = 0;
   if (*magnitude < 0) {
	  sign = 1;
	  *magnitude = -*magnitude;
   }
   while ((*magnitude & ~MAGNITUDE_MASK) == 0) {
      *magnitude <<= 1;
      (*exponent)--;
   }
   while (*magnitude & (~MAGNITUDE_MASK << 1)) {
      *magnitude >>= 1;
      (*exponent)++;
   }
   if (sign) {
	  *magnitude = -*magnitude;
   }
}
float fSum(float a, float b) {
   int aExp, aMag;
   int bExp, bMag;
   unpackFloat(a, &aExp, &aMag);
   unpackFloat(b, &bExp, &bMag);
   while (aExp < bExp) {
	  aExp++;
	  aMag >>= 1;
   }
   while (bExp < aExp) {
      bExp++;
      bMag >>= 1;
   }
   int cExp = bExp, cMag = aMag + bMag;
   normalizeFloat(&cExp, &cMag);
   return packFloat(cExp, cMag);
}
float fDiff(float a, float b) {
   return fSum(a, -b);
}
float fProd(float a, float b) {
   int aExp, aMag;
   int bExp, bMag;
   unpackFloat(a, &aExp, &aMag);
   unpackFloat(b, &bExp, &bMag);
   long lcMag = (long) aMag * (long) bMag;
   lcMag >>= 23;
   int icMag = (int) lcMag;
   int cExp = aExp + bExp;
   normalizeFloat(&cExp, &icMag);
   return packFloat(cExp, icMag);
}
int main(void) {
   float a = numA, b = numB;
   float sum = fSum(a, b);
   float diff = fDiff(a, b);
   float prod = fProd(a, b);
   return 0;
}