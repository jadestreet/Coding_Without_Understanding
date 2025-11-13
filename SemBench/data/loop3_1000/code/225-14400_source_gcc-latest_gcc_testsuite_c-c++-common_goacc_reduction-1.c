#define n 1000
int
main(void)
{
  int i;
  int result, array[n];
  int lresult;
#pragma acc parallel
#pragma acc loop gang worker vector reduction (+:result)
  for (i = 0; i < n; i++)
    result += array[i];
#pragma acc parallel
#pragma acc loop gang worker vector reduction (*:result)
  for (i = 0; i < n; i++)
    result *= array[i];
#pragma acc parallel
#pragma acc loop gang worker vector reduction (max:result)
  for (i = 0; i < n; i++)
    result = result > array[i] ? result : array[i];
#pragma acc parallel
#pragma acc loop gang worker vector reduction (min:result)
  for (i = 0; i < n; i++)
    result = result < array[i] ? result : array[i];
#pragma acc parallel
#pragma acc loop gang worker vector reduction (&:result)
  for (i = 0; i < n; i++)
    result &= array[i];
#pragma acc parallel
#pragma acc loop gang worker vector reduction (|:result)
  for (i = 0; i < n; i++)
    result |= array[i];
#pragma acc parallel
#pragma acc loop gang worker vector reduction (^:result)
  for (i = 0; i < n; i++)
    result ^= array[i];
#pragma acc parallel
#pragma acc loop gang worker vector reduction (&&:lresult)
  for (i = 0; i < n; i++)
    lresult = lresult && (result > array[i]);
#pragma acc parallel
#pragma acc loop gang worker vector reduction (||:lresult)
  for (i = 0; i < n; i++)
    lresult = lresult || (result > array[i]);
  return 0;
}