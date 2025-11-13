# include <assert.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <stddef.h>
# ifndef __cplusplus
# define bool int
# define true 1
# define false 0
# endif
double det_of_minor(
	const double*        a  ,
	size_t               m  ,
	size_t               n  ,
	size_t*              r  ,
	size_t*              c  )
{	size_t R0, Cj, Cj1, j;
	double detM, M0j, detS;
	int s;
	R0 = r[m]; 
	Cj = c[m]; 
	Cj1 = m;   
	if( n == 1 ) return a[ R0 * m + Cj ];
	detM = 0.;
	s = 1;
	r[m] = r[R0];
	for(j = 0; j < n; j++)
	{	
		M0j = a[ R0 * m + Cj ];
		c[Cj1] = c[Cj];
		detS = det_of_minor(a, m, n - 1, r, c);
		c[Cj1] = Cj;
		if( s > 0 )
			detM = detM + M0j * detS;
		else	detM = detM - M0j * detS;
		Cj1 = Cj;
		Cj  = c[Cj];
		s   = - s;
	}
	r[m] = R0;
	return detM;
}
double det_by_minor(double* a, size_t m)
{	size_t *r, *c, i;
	double value;
	r = (size_t*) malloc( (m+1) * sizeof(size_t) );
	c = (size_t*) malloc( (m+1) * sizeof(size_t) );
	assert(m <= 100);
	for(i = 0; i < m; i++)
	{	r[i] = i+1;
		c[i] = i+1;
	}
	r[m] = 0;
	c[m] = 0;
	value = det_of_minor(a, m, m, r, c);
	free(r);
	free(c);
	return value;
}
void random_seed(size_t seed)
{	srand(seed); }
void uniform_01(unsigned n, double* a)
{	static double factor = 1. / (double) RAND_MAX;
	while(n--)
		a[n] = rand() * factor;
}
bool correct_det_by_minor(void)
{	double a[9], det, check;
	random_seed(123);
	uniform_01(9, a);
	det = det_by_minor(a, 3);
	check = 0.;
	check += a[0] * ( a[4] * a[8] - a[5] * a[7] );
	check -= a[1] * ( a[3] * a[8] - a[5] * a[6] );
	check += a[2] * ( a[3] * a[7] - a[4] * a[6] );
	if( fabs(det / check - 1.0) < 1e-10 )
		return true;
	return false;
}
void repeat_det_by_minor(size_t repeat, size_t size)
{	double *a;
	a = (double*) malloc( (size * size) * sizeof(double) );
	while(repeat--)
	{	uniform_01(size * size, a);
		det_by_minor(a, size);
	}
	free(a);
	return;
}
# if _MSC_VER
# include <windows.h>
# include <cassert>
double elapsed_seconds(void)
{	static bool       first_  = true;
	static SYSTEMTIME st_;
	double hour, minute, second, milli, diff;
	SYSTEMTIME st;
	if( first_ )
	{	GetSystemTime(&st_);
		first_ = false;
		return 0.;
	}
	GetSystemTime(&st);
	hour   = (double) st.wHour         - (double) st_.wHour;
	minute = (double) st.wMinute       - (double) st_.wMinute;
	second = (double) st.wSecond       - (double) st_.wSecond;
	milli  = (double) st.wMilliseconds - (double) st_.wMilliseconds;
	diff   = 1e-3*milli + second + 60.*minute + 3600.*hour;
	if( diff < 0. )
		diff += 3600.*24.;
	assert( 0 <= diff && diff < 3600.*24. );
	return diff;
}
# else
# include <sys/time.h>
double elapsed_seconds(void)
{	double sec, usec, diff;
	static bool first_ = true;
	static struct timeval tv_first;
	struct timeval        tv;
	if( first_ )
	{	gettimeofday(&tv_first, NULL);
		first_ = false;
		return 0.;
	}
	gettimeofday(&tv, NULL);
	assert( tv.tv_sec >= tv_first.tv_sec );
	sec  = (double)(tv.tv_sec -  tv_first.tv_sec);
	usec = (double)tv.tv_usec - (double)tv_first.tv_usec;
	diff = sec + 1e-6*usec;
	return diff;
}
# endif
double time_det_by_minor(size_t size, double time_min)
{	size_t repeat;
	double s0, s1, time;
	repeat = 0;
	s0     = elapsed_seconds();
	s1     = s0;
	while( s1 - s0 < time_min )
	{	if( repeat == 0 )
			repeat = 1;
		else	repeat = 2 * repeat;
		s0     = elapsed_seconds();
		repeat_det_by_minor(repeat, size);
		s1     = elapsed_seconds();
	}
	time = (s1 - s0) / (double) repeat;
	return time;
}
int main(void)
{	bool flag;
	size_t i;
	random_seed(123);
	printf("correct_det_by_minor: ");
	flag = correct_det_by_minor();
	if( flag )
		printf("OK\n");
	else	printf("Error\n");
	for(i = 0; i < 5; i++)
	{	double time_min = 1.0;
		size_t size     = 2 + i * 2;
		int   i_size    = (int) size;
		printf("time_det_minor for %d x %d matrix = ", i_size, i_size);
		printf("%g\n", time_det_by_minor(size, time_min) );
	}
	if( flag )
		return 0;
	return 1;
}