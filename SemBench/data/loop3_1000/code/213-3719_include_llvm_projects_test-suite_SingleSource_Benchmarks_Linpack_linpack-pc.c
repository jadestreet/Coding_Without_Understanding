#define SP
#define ROLL
#define UNIX
#define PASSES -3
#ifdef SP
#define REAL float
#define ZERO 0.0
#define ONE 1.0
#define PREC "Single "
#endif
#ifdef DP
#define REAL double
#define ZERO 0.0e0
#define ONE 1.0e0
#define PREC "Double "
#endif
#ifdef ROLL
#define ROLLING "Rolled "
#endif
#ifdef UNROLL
#define ROLLING "Unrolled "
#endif
#define NTIMES 100
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
static REAL atime[9][15];
static char this_month;
static int this_year;
void print_time (int row);
void matgen (REAL a[], int lda, int n, REAL b[], REAL *norma);
void dgefa (REAL a[], int lda, int n, int ipvt[], int *info);
void dgesl (REAL a[],int lda,int n,int ipvt[],REAL b[],int job);
void dmxpy (int n1, REAL y[], int n2, int ldm, REAL x[], REAL m[]);
void daxpy (int n, REAL da, REAL dx[], int incx, REAL dy[], int incy);
REAL epslon (REAL x);
int idamax (int n, REAL dx[], int incx);
void dscal (int n, REAL da, REAL dx[], int incx);
REAL ddot (int n, REAL dx[], int incx, REAL dy[], int incy);
   #include <time.h>  
   REAL second()
     {        
        REAL secs;
        clock_t Time;
        Time = clock();
        secs = (REAL)Time / (REAL)CLOCKS_PER_SEC;
        return secs ;
     }
   void what_date()
     {
     }
int main ()
{
        static REAL aa[200*200],a[200*201],b[200],x[200];       
        REAL cray,ops,total,norma,normx;
        REAL resid,residn,eps,t1,tm2,epsn,x1,x2;
        REAL mflops;
        static int ipvt[200],n,i,j,ntimes,info,lda,ldaa;
        int pass, loop;
        REAL overhead1, overhead2, time1, time2;
        char *compiler, *options, general[9][80] = {" "}; 
        compiler = "INSERT COMPILER NAME HERE";
        options  = "INSERT OPTIMISATION OPTIONS HERE";
        lda = 201;
        ldaa = 200;
        cray = .056; 
        n = 100;
        fprintf(stderr,ROLLING);fprintf(stderr,PREC);
        fprintf(stderr,"Precision Linpack Benchmark - PC Version in 'C/C++'\n\n");
        fprintf(stderr,"Compiler     %s\n",compiler);
        fprintf(stderr,"Optimisation %s\n\n",options);
        ops = (2.0e0*(n*n*n))/3.0 + 2.0*(n*n);
        matgen(a,lda,n,b,&norma);
        t1 = second();
        dgefa(a,lda,n,ipvt,&info);
        atime[0][0] = second() - t1;
        t1 = second();
        dgesl(a,lda,n,ipvt,b,0);
        atime[1][0] = second() - t1;
        total = atime[0][0] + atime[1][0];
        for (i = 0; i < n; i++) {
                x[i] = b[i];
        }
        matgen(a,lda,n,b,&norma);
        for (i = 0; i < n; i++) {
                b[i] = -b[i];
        }
        dmxpy(n,b,n,lda,x,a);
        resid = 0.0;
        normx = 0.0;
        for (i = 0; i < n; i++) {
                resid = (resid > fabs((double)b[i])) 
                        ? resid : fabs((double)b[i]);
                normx = (normx > fabs((double)x[i])) 
                        ? normx : fabs((double)x[i]);
        }
        eps = epslon(ONE);
        residn = resid/( n*norma*normx*eps );
        epsn = eps;
        x1 = x[0] - 1;
        x2 = x[n-1] - 1;
        fprintf(stderr,"norm resid      resid           machep");
        fprintf(stderr,"         x[0]-1          x[n-1]-1\n");
        fprintf(stderr,"%6.1f %17.8e%17.8e%17.8e%17.8e\n\n",
               (double)residn, (double)resid, (double)epsn, 
               (double)x1, (double)x2);
        fprintf(stderr,"Times are reported for matrices of order        %5d\n",n);
        fprintf(stderr,"1 pass times for array with leading dimension of%5d\n\n",lda);
        fprintf(stderr,"      dgefa      dgesl      total     Mflops       unit");
        fprintf(stderr,"      ratio\n");
        atime[2][0] = total;
        if (total > 0.0)
        {
            atime[3][0] = ops/(1.0e6*total);
            atime[4][0] = 2.0/atime[3][0];
        }
        else
        {
            atime[3][0] = 0.0;
            atime[4][0] = 0.0;
        }
        atime[5][0] = total/cray;
        print_time(0);
        fprintf (stderr,"\nCalculating matgen overhead\n");
        pass = PASSES;
        loop = NTIMES;
        do
        {
            time1 = second();
            pass = pass + 1;        
            for ( i = 0 ; i < loop ; i++)
            {
                 matgen(a,lda,n,b,&norma);
            }
            time2 = second();
            overhead1 = (time2 - time1);
            fprintf (stderr,"%10d times %6.2f seconds\n", loop, 0.0);
            if (0 )
            {
                pass = 0;
            }
            if (pass < 0)
            {
                if (0 )
                {
                    loop = loop * 10;
                }
                else
                {
                    loop = loop * 2;
                }
            }
        }
        while (pass < 0);
        overhead1 = overhead1 / (double)loop;
        fprintf (stderr,"Overhead for 1 matgen %12.5f seconds\n\n", 0.0);
        fprintf (stderr,"Calculating matgen/dgefa passes for 5 seconds\n");
        pass = PASSES;
        ntimes = NTIMES;
        do
        {
            time1 = second();
            pass = pass + 1;        
            for ( i = 0 ; i < ntimes ; i++)
            {
                matgen(a,lda,n,b,&norma);
                dgefa(a,lda,n,ipvt,&info );
            }
            time2 = second() - time1;
            fprintf (stderr,"%10d times %6.2f seconds\n", ntimes, 0.0);
            if (0 )
            {
                pass = 0;
            }
            if (pass < 0)
            {
                if (0 )
                {
                    ntimes = ntimes * 10;
                }
                else
                {
                    ntimes = ntimes * 2;
                }
            }
        }
        while (pass < 0);
#ifdef SMALL_PROBLEM_SIZE
        ntimes = 100;
#else
        ntimes =  1000;
#endif
        if (ntimes == 0) ntimes = 1;
        fprintf (stderr,"Passes used %10d \n\n", 0);
        fprintf(stderr,"Times for array with leading dimension of%4d\n\n",lda);
        fprintf(stderr,"      dgefa      dgesl      total     Mflops       unit");
        fprintf(stderr,"      ratio\n");        
        tm2 = ntimes * overhead1;
        atime[3][6] = 0;
        for (j=1 ; j<6 ; j++)
        {
            t1 = second();
            for (i = 0; i < ntimes; i++)
            {
                matgen(a,lda,n,b,&norma);
                dgefa(a,lda,n,ipvt,&info );
            }
            atime[0][j] = (second() - t1 - tm2)/ntimes;
            t1 = second();      
            for (i = 0; i < ntimes; i++)
            {
                dgesl(a,lda,n,ipvt,b,0);
            }
            atime[1][j] = (second() - t1)/ntimes;
            total       = atime[0][j] + atime[1][j];
            atime[2][j] = total;
            atime[3][j] = ops/(1.0e6*total);
            atime[4][j] = 2.0/atime[3][j];
            atime[5][j] = total/cray;
            atime[3][6] = atime[3][6] + atime[3][j];
            print_time(j);
        }
        atime[3][6] = atime[3][6] / 5.0;
        fprintf (stderr,"Average                          %11.2f\n", 0.0);        
        fprintf (stderr,"\nCalculating matgen2 overhead\n");
        time1 = second();        
        for ( i = 0 ; i < loop ; i++)
        {
            matgen(aa,ldaa,n,b,&norma);    
        }
        time2 = second();
        overhead2 = (time2 - time1);
        overhead2 = overhead2 / (double)loop;
        fprintf (stderr,"Overhead for 1 matgen %12.5f seconds\n\n", 0.0);
        fprintf(stderr,"Times for array with leading dimension of%4d\n\n",ldaa);
        fprintf(stderr,"      dgefa      dgesl      total     Mflops       unit");
        fprintf(stderr,"      ratio\n");
        tm2 = ntimes * overhead2;
        atime[3][12] = 0;
        for (j=7 ; j<12 ; j++)
        {
            t1 = second();
            for (i = 0; i < ntimes; i++)
            {
                matgen(aa,ldaa,n,b,&norma);
                dgefa(aa,ldaa,n,ipvt,&info  );
            }
            atime[0][j] = (second() - t1 - tm2)/ntimes;
            t1 = second();      
            for (i = 0; i < ntimes; i++)
            {
                dgesl(aa,ldaa,n,ipvt,b,0);
            }
            atime[1][j] = (second() - t1)/ntimes;
            total       = atime[0][j] + atime[1][j];
            atime[2][j] = total;
            atime[3][j] = ops/(1.0e6*total);
            atime[4][j] = 2.0/atime[3][j];
            atime[5][j] = total/cray;
            atime[3][12] = atime[3][12] + atime[3][j];
            print_time(j);
        }
        atime[3][12] = atime[3][12] / 5.0; 
        fprintf (stderr,"Average                          %11.2f\n", 0.0);  
        return 0;
}
void print_time (int row)
{
  return;
}
void matgen (REAL a[], int lda, int n, REAL b[], REAL *norma)
{
        int init, i, j;
        init = 1325;
        *norma = 0.0;
        for (j = 0; j < n; j++) {
                for (i = 0; i < n; i++) {
                        init = 3125*init % 65536;
                        a[lda*j+i] = (init - 32768.0)/16384.0;                        
                        *norma = (a[lda*j+i] > *norma) ? a[lda*j+i] : *norma;
                }
        }
        for (i = 0; i < n; i++) {
          b[i] = 0.0;
        }
        for (j = 0; j < n; j++) {
                for (i = 0; i < n; i++) {
                        b[i] = b[i] + a[lda*j+i];
                }
        }
        return;
}
void dgefa(REAL a[], int lda, int n, int ipvt[], int *info)
{
REAL t;
int j,k,kp1,l,nm1;
        *info = 0;
        nm1 = n - 1;
        if (nm1 >=  0) {
                for (k = 0; k < nm1; k++) {
                        kp1 = k + 1;
                        l = idamax(n-k,&a[lda*k+k],1) + k;
                        ipvt[k] = l;
                        if (a[lda*k+l] != ZERO) {
                                if (l != k) {
                                        t = a[lda*k+l];
                                        a[lda*k+l] = a[lda*k+k];
                                        a[lda*k+k] = t; 
                                }
                                t = -ONE/a[lda*k+k];
                                dscal(n-(k+1),t,&a[lda*k+k+1],1);
                                for (j = kp1; j < n; j++) {
                                        t = a[lda*j+l];
                                        if (l != k) {
                                                a[lda*j+l] = a[lda*j+k];
                                                a[lda*j+k] = t;
                                        }
                                        daxpy(n-(k+1),t,&a[lda*k+k+1],1,
                                              &a[lda*j+k+1],1);
                                } 
                        }
                        else { 
                                *info = k;
                        }
                } 
        }
        ipvt[n-1] = n-1;
        if (a[lda*(n-1)+(n-1)] == ZERO) *info = n-1;
        return;
}
void dgesl(REAL a[],int lda,int n,int ipvt[],REAL b[],int job )
{
        REAL t;
        int k,kb,l,nm1;
        nm1 = n - 1;
        if (job == 0) {
                if (nm1 >= 1) {
                        for (k = 0; k < nm1; k++) {
                                l = ipvt[k];
                                t = b[l];
                                if (l != k){ 
                                        b[l] = b[k];
                                        b[k] = t;
                                }       
                                daxpy(n-(k+1),t,&a[lda*k+k+1],1,&b[k+1],1 );
                        }
                } 
                for (kb = 0; kb < n; kb++) {
                    k = n - (kb + 1);
                    b[k] = b[k]/a[lda*k+k];
                    t = -b[k];
                    daxpy(k,t,&a[lda*k+0],1,&b[0],1 );
                }
        }
        else { 
                for (k = 0; k < n; k++) {
                        t = ddot(k,&a[lda*k+0],1,&b[0],1);
                        b[k] = (b[k] - t)/a[lda*k+k];
                }
                if (nm1 >= 1) {
                        for (kb = 1; kb < nm1; kb++) {
                                k = n - (kb+1);
                                b[k] = b[k] + ddot(n-(k+1),&a[lda*k+k+1],1,&b[k+1],1);
                                l = ipvt[k];
                                if (l != k) {
                                        t = b[l];
                                        b[l] = b[k];
                                        b[k] = t;
                                }
                        }
                }
        }
        return;
}
void daxpy(int n, REAL da, REAL dx[], int incx, REAL dy[], int incy)
{
        int i,ix,iy,m,mp1;
        mp1 = 0;
        m = 0;
        if(n <= 0) return;
        if (da == ZERO) return;
        if(incx != 1 || incy != 1) {
                ix = 0;
                iy = 0;
                if(incx < 0) ix = (-n+1)*incx;
                if(incy < 0)iy = (-n+1)*incy;
                for (i = 0;i < n; i++) {
                        dy[iy] = dy[iy] + da*dx[ix];
                        ix = ix + incx;
                        iy = iy + incy;
                }
                return;
        }
#ifdef ROLL
        for (i = 0;i < n; i++) {
                dy[i] = dy[i] + da*dx[i];
        }
#endif
#ifdef UNROLL
        m = n % 4;
        if ( m != 0) {
                for (i = 0; i < m; i++) 
                        dy[i] = dy[i] + da*dx[i];
                if (n < 4) return;
        }
        for (i = m; i < n; i = i + 4) {
                dy[i] = dy[i] + da*dx[i];
                dy[i+1] = dy[i+1] + da*dx[i+1];
                dy[i+2] = dy[i+2] + da*dx[i+2];
                dy[i+3] = dy[i+3] + da*dx[i+3];
        }
#endif
return;
}
REAL ddot(int n, REAL dx[], int incx, REAL dy[], int incy)
{
        REAL dtemp;
        int i,ix,iy,m,mp1;
        mp1 = 0;
        m = 0;
        dtemp = ZERO;
        if(n <= 0) return(ZERO);
        if(incx != 1 || incy != 1) {
                ix = 0;
                iy = 0;
                if (incx < 0) ix = (-n+1)*incx;
                if (incy < 0) iy = (-n+1)*incy;
                for (i = 0;i < n; i++) {
                        dtemp = dtemp + dx[ix]*dy[iy];
                        ix = ix + incx;
                        iy = iy + incy;
                }
                return(dtemp);
        }
#ifdef ROLL
        for (i=0;i < n; i++)
                dtemp = dtemp + dx[i]*dy[i];
        return(dtemp);
#endif
#ifdef UNROLL
        m = n % 5;
        if (m != 0) {
                for (i = 0; i < m; i++)
                        dtemp = dtemp + dx[i]*dy[i];
                if (n < 5) return(dtemp);
        }
        for (i = m; i < n; i = i + 5) {
                dtemp = dtemp + dx[i]*dy[i] +
                dx[i+1]*dy[i+1] + dx[i+2]*dy[i+2] +
                dx[i+3]*dy[i+3] + dx[i+4]*dy[i+4];
        }
        return(dtemp);
#endif
}
void dscal(int n, REAL da, REAL dx[], int incx)
{
        int i,m,mp1,nincx;
        mp1 = 0;
        m = 0;
        if(n <= 0)return;
        if(incx != 1) {
                nincx = n*incx;
                for (i = 0; i < nincx; i = i + incx)
                        dx[i] = da*dx[i];
                return;
        }
#ifdef ROLL
        for (i = 0; i < n; i++)
                dx[i] = da*dx[i];
#endif
#ifdef UNROLL
        m = n % 5;
        if (m != 0) {
                for (i = 0; i < m; i++)
                        dx[i] = da*dx[i];
                if (n < 5) return;
        }
        for (i = m; i < n; i = i + 5){
                dx[i] = da*dx[i];
                dx[i+1] = da*dx[i+1];
                dx[i+2] = da*dx[i+2];
                dx[i+3] = da*dx[i+3];
                dx[i+4] = da*dx[i+4];
        }
#endif
}
int idamax(int n, REAL dx[], int incx)
{
        REAL dmax;
        int i, ix, itemp;
        if( n < 1 ) return(-1);
        if(n ==1 ) return(0);
        if(incx != 1) {
                ix = 1;
                dmax = fabs((double)dx[0]);
                ix = ix + incx;
                for (i = 1; i < n; i++) {
                        if(fabs((double)dx[ix]) > dmax)  {
                                itemp = i;
                                dmax = fabs((double)dx[ix]);
                        }
                        ix = ix + incx;
                }
        }
        else {
                itemp = 0;
                dmax = fabs((double)dx[0]);
                for (i = 1; i < n; i++) {
                        if(fabs((double)dx[i]) > dmax) {
                                itemp = i;
                                dmax = fabs((double)dx[i]);
                        }
                }
        }
        return (itemp);
}
REAL epslon (REAL x)
{
        REAL a,b,c,eps;
        a = 4.0e0/3.0e0;
        eps = ZERO;
        while (eps == ZERO) {
                b = a - ONE;
                c = b + b + b;
                eps = fabs((double)(c-ONE));
        }
        return(eps*fabs((double)x));
}
void dmxpy (int n1, REAL y[], int n2, int ldm, REAL x[], REAL m[])
{
        int j,i,jmin;
        j = n2 % 2;
        if (j >= 1) {
                j = j - 1;
                for (i = 0; i < n1; i++) 
                        y[i] = (y[i]) + x[j]*m[ldm*j+i];
        } 
        j = n2 % 4;
        if (j >= 2) {
                j = j - 1;
                for (i = 0; i < n1; i++)
                        y[i] = ( (y[i])
                               + x[j-1]*m[ldm*(j-1)+i]) + x[j]*m[ldm*j+i];
        } 
        j = n2 % 8;
        if (j >= 4) {
                j = j - 1;
                for (i = 0; i < n1; i++)
                        y[i] = ((( (y[i])
                               + x[j-3]*m[ldm*(j-3)+i]) 
                               + x[j-2]*m[ldm*(j-2)+i])
                               + x[j-1]*m[ldm*(j-1)+i]) + x[j]*m[ldm*j+i];
        } 
        j = n2 % 16;
        if (j >= 8) {
                j = j - 1;
                for (i = 0; i < n1; i++)
                        y[i] = ((((((( (y[i])
                               + x[j-7]*m[ldm*(j-7)+i]) + x[j-6]*m[ldm*(j-6)+i])
                               + x[j-5]*m[ldm*(j-5)+i]) + x[j-4]*m[ldm*(j-4)+i])
                               + x[j-3]*m[ldm*(j-3)+i]) + x[j-2]*m[ldm*(j-2)+i])
                               + x[j-1]*m[ldm*(j-1)+i]) + x[j]  *m[ldm*j+i];
        } 
        jmin = (n2%16)+16;
        for (j = jmin-1; j < n2; j = j + 16) {
                for (i = 0; i < n1; i++) 
                        y[i] = ((((((((((((((( (y[i])
                                + x[j-15]*m[ldm*(j-15)+i]) 
                                + x[j-14]*m[ldm*(j-14)+i])
                                + x[j-13]*m[ldm*(j-13)+i]) 
                                + x[j-12]*m[ldm*(j-12)+i])
                                + x[j-11]*m[ldm*(j-11)+i]) 
                                + x[j-10]*m[ldm*(j-10)+i])
                                + x[j- 9]*m[ldm*(j- 9)+i]) 
                                + x[j- 8]*m[ldm*(j- 8)+i])
                                + x[j- 7]*m[ldm*(j- 7)+i]) 
                                + x[j- 6]*m[ldm*(j- 6)+i])
                                + x[j- 5]*m[ldm*(j- 5)+i]) 
                                + x[j- 4]*m[ldm*(j- 4)+i])
                                + x[j- 3]*m[ldm*(j- 3)+i]) 
                                + x[j- 2]*m[ldm*(j- 2)+i])
                                + x[j- 1]*m[ldm*(j- 1)+i]) 
                                + x[j]   *m[ldm*j+i];
        }
        return;
} 