#define N 1024
int main() {
  #pragma omp task
  {
    int i;
    #pragma omp parallel for
    for (i = 0; i < N; i++)
      (void)0;
  }
  #pragma omp task
  {
    int i;
    #pragma omp parallel for
    for (i = 0; i < N; ++i)
      (void)0;
  }
  #pragma omp taskwait
  return 0;
}