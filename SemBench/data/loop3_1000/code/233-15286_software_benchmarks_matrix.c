#ifdef SHORT_BENCH
#define X 40 
#define Y 40 
#define Z 40 
#else
#define X 150 
#define Y 150 
#define Z 150 
#endif
int matrix_pin_down(int A[], int B[], int C[])
{
  int i ;
  for (i = 0 ; i < X*Y; i++)
      A[i] = 1 ;
  for (i = 0 ; i < Y*Z ; i++)
      B[i] = 1 ;
  for (i = 0 ; i < X*Z ; i++)
      C[i] = 0 ;
  return((int)0) ;
}
int main()
{
  static  int A[X*Y] ;
  static  int B[Y*Z] ;
  static  int C[X*Z] ;
  int *p_a = &A[0] ;
  int *p_b = &B[0] ;
  int *p_c = &C[0] ;
  int f,i,k ;
  matrix_pin_down(&A[0], &B[0], &C[0]) ;
  for (k = 0 ; k < Z ; k++)
    {
      p_a = &A[0] ;                  
      for (i = 0 ; i < X; i++)
    {
      p_b = &B[k*Y] ;            
      *p_c =  0 ;
      for (f = 0 ; f < Y; f++) 
        *p_c += *p_a++ * *p_b++ ;
      *p_c++  ;
    }
    }
  matrix_pin_down(&A[0], &B[0], &C[0]) ;
  return 0;
}