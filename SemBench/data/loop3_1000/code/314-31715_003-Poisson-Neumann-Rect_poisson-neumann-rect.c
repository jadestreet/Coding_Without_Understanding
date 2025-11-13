#include <stdio.h>
#include <math.h>
#define N (200)
#define h (1.0 / N)
#define n ((N-1)*(N-1))
#define TOLERANCE (1.0e-10)
#define MAXITER (25000)
#define CULL (5)
double uh[n]; 
double uh_new[n]; 
double Fh[n]; 
int get_index(int i, int j) {
	return (N - 1) * (i - 1) + (j - 1);
}
double f(double x, double y) {
    return 0;
}
int main(int argc, char * argv[]) {
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			int m = get_index(i, j);
			Fh[m] = f(i * h, j * h);
		}
	}
	for (int m = 0; m < n; ++m) {
		uh[m] = Fh[m] / (4 * N * N);
	}
	for (int k = 0; k < MAXITER; ++k) {
		for (int i = 1; i < N; ++i) {
			for (int j = 1; j < N; ++j) {
				int m = get_index(i, j);
				uh_new[m] = Fh[m] / (4 * N * N); 
				if (i > 1) {
					uh_new[m] += uh[get_index(i - 1, j)] / 4.0;
				}
				if (i < N - 1) {
					uh_new[m] += uh[get_index(i + 1, j)] / 4.0;
				}
				if (j > 1) {
					uh_new[m] += uh[get_index(i, j - 1)] / 4.0;
				}
                else{
                    uh_new[m] = uh[get_index(i,0)];
                }
				if (j < N - 1) {
					uh_new[m] += uh[get_index(i, j + 1)] / 4.0;
				}
			}
		}
		double uh_norm = 0.0;
		double res = 0.0;
		for (int i = 1; i < N; ++i) {
			for (int j = 1; j < N; ++j) {
				int m = get_index(i, j);
				res += (uh[m] - uh_new[m]) * (uh[m] - uh_new[m]);
				uh_norm += uh[m] * uh[m];
				uh[m] = uh_new[m];
			}
		}
		res /= uh_norm;
		if (res < TOLERANCE || k == MAXITER - 1) {
			fprintf(stderr, "[%d] res = %e\n", k, res);
			break;
		}
	}
	for (int i = 0; i <= N; i += CULL) {
		for (int j = 0; j <= N; j += CULL) {
			if (i == 0 || i == N || j == 0 || j == N) {
				printf("%f %f %f\n", i * h, j * h, 0.0);
			} else {
				int m = get_index(i, j);
				printf("%f %f %f\n", i * h, j * h, uh[m]);
			}
		}
	}
	return 0;
}