#include <stdio.h>
#define SIZE 200
#define MAX 2000000
#define rdtsc(low,high) __asm__ __volatile__ ("rdtsc" : "=a" (low), "=d" (high))
typedef struct {int lo,hi;} longpair;
typedef union { longpair ll; long long t; } timestamp;
typedef float v4sf __attribute__ ((vector_size(16)));
union f4vector {
    v4sf v;
    float f[4];
};
typedef int v4si __attribute__ ((vector_size(16)));
union i4vector {
    v4si v;
    int i[4];
};
int main() {
	float f;
	int cnt, factor, thresh[SIZE];
    int done;
	timestamp a, b, c, d;
  	rdtsc(a.ll.lo,a.ll.hi);
  	for (factor = 2; factor < SIZE; factor++) {
        thresh[factor]=0;
   		cnt = 2;
		done = 0;
		while (!done && (cnt < MAX)) {
			f = (float) cnt * factor;
			f = f / factor;
			if (f != (float) cnt) {
				done = 1;
				thresh[factor] = cnt;
				break;
			}
			cnt++;
		}
  	}
  	rdtsc(b.ll.lo,b.ll.hi);
  	c.t = b.t-a.t;
    printf("\n\n\nVECTOR\n\n\n");
    union f4vector vectorCheck;
    union i4vector vectorCount;
  	rdtsc(a.ll.lo, a.ll.hi);
  	for (factor = 2; factor < SIZE; factor++) {
        float flFactor = (float) factor;
        thresh[factor] = 0;
   		cnt = 2;
        done = 0;
        vectorCount.i[0] = 2;
        vectorCount.i[1] = 3;
        vectorCount.i[2] = 4;
        vectorCount.i[3] = 5;
		while (!done && vectorCount.i[0] < MAX) {
            vectorCheck.f[0] = vectorCount.i[0];
            vectorCheck.f[1] = vectorCount.i[1];
            vectorCheck.f[2] = vectorCount.i[2];
            vectorCheck.f[3] = vectorCount.i[3];
            vectorCheck.v = vectorCheck.v * flFactor;
            vectorCheck.v = vectorCheck.v / flFactor;
            if (vectorCheck.f[0] != vectorCount.i[0]) {
                done = 1;
                thresh[factor] = vectorCount.i[0];
                break;
            }
            if (vectorCheck.f[1] != vectorCount.i[1]) {
                done = 1;
                thresh[factor] = vectorCount.i[1];
                break;
            }
            if (vectorCheck.f[2] != vectorCount.i[2]) {
                done = 1;
                thresh[factor] = vectorCount.i[2];
                break;
            }
            if (vectorCheck.f[3] != vectorCount.i[3]) {
                done = 1;
                thresh[factor] = vectorCount.i[3];
                break;
            }
            vectorCount.v += 4;
		}
  	}
  	rdtsc(b.ll.lo, b.ll.hi);
    d.t = b.t - a.t;
    printf("Cycles elapsed for scalar implementation: t=%llu \n", c.t);
    printf("Cycles elapsed for vector implementation: t=%llu \n", d.t);
	return 0;
}